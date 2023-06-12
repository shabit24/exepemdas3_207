#include <iostream>
using namespace std;

class Flatfield {
private:
    int x; // variable to store input from circle or square

public:
    Flatfield() { // constructor
        x = 0;
    }

    virtual void input() {} // function that accepts input and sends input via setX function to store in x

    virtual float Area(int a) { return 0; } // function to calculate area

    virtual float Circumference(int a) { return 0; } // function to calculate circumference

    void setX(int a) { // function to return/send value to x
        this->x = a;
    }

    int getX() { // function to read/fetch value in x
        return x;
    }
};

class Circle : public Flatfield {
public:
    void input() {
        int radius;
        cout << "Enter the radius of the circle: ";
        cin >> radius;
        setX(radius);
    }

    float Area(int radius) {
        return 3.14159 * radius * radius;
    }

    float Circumference(int radius) {
        return 2 * 3.14159 * radius;
    }
};

class Square : public Flatfield {
public:
    void input() {
        int side;
        cout << "Enter the side length of the square: ";
        cin >> side;
        setX(side);
    }

    float Area(int side) {
        return side * side;
    }

    float Circumference(int side) {
        return 4 * side;
    }
};

int main() {
    Circle circle;
    Square square;

    Flatfield* shape;

    shape = &circle;
    shape->input();
    int radius = shape->getX();
    float circleArea = shape->Area(radius);
    float circleCircumference = shape->Circumference(radius);

    shape = &square;
    shape->input();
    int side = shape->getX();
    float squareArea = shape->Area(side);
    float squareCircumference = shape->Circumference(side);

    cout << "Circle Area: " << circleArea << endl;
    cout << "Circle Circumference: " << circleCircumference << endl;
    cout << "Square Area: " << squareArea << endl;
    cout << "Square Circumference: " << squareCircumference << endl;

    return 0;
}
