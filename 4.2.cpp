#include <iostream>
#include <vector>
using namespace std;
class Student {
public:
    string name;
    int grade;

    Student(const string& n, int g) : name(n), grade(g) {}
};

class StudentList {
private:
    vector<Student> students;

public:
    void addStudent(const Student& student) {
        students.push_back(student);
    }

    Student getStudentWithMaxGrade() const {
        if (students.empty()) {
            // Return a default-constructed Student if the list is empty
            return Student("", 0);
        }

        auto maxGradeStudent = std::max_element(students.begin(), students.end(),
            [](const Student& a, const Student& b) {
                return a.grade < b.grade;
            });

        return *maxGradeStudent;
    }
};

int main() {
    // Example usage:
    // Create some students
    Student student1("Alexandra", 90);
    Student student2("Bogdan", 85);
    Student student3("Florin", 95);

    // Create a StudentList
    StudentList studentList;

    // Add students to the list
    studentList.addStudent(student1);
    studentList.addStudent(student2);
    studentList.addStudent(student3);

    // Get the student with the maximum grade
    Student maxGradeStudent = studentList.getStudentWithMaxGrade();

    // Print the result
    if (maxGradeStudent.name.empty()) {
        cout << "No students in the list." << std::endl;
    }
    else {
        cout << "The student with the maximum grade is " << maxGradeStudent.name
            << " with a grade of " << maxGradeStudent.grade << "." << std::endl;
    }

    return 0;
}
