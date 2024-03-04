// Project2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

//represents a course with a number, name, and prerequisites
class Course {
public:
    string courseNumber;
    string name;
    vector<string> prerequisites;

    // Default constructor
    Course() {}

    //Parameterized contructor
    Course(string courseNumber, string name, vector<string> prerequsities)
        : courseNumber(courseNumber), name(name), prerequisites(prerequisites) {}
};

//Function to display the main menu options to the user
void displayMenu() {
    cout << "Welcome to the course planner.\n";
    cout << "1. Load Data Structure.\n";
    cout << "2. Print Course List.\n";
    cout << "3. Print Course.\n";
    cout << "9. Exit\n";
    cout << "What would you like to do? ";
}

//Function to get the user's menu choice
int getUserChoice() {
    int choice;
    cin >> choice;
    return choice;
}

//Function to display a message for invalid option selection
void displayInvalidOption() {
    cout << "That is not a valid option.\n";
}

//Function to load courses from a file into the courses map.
void loadCourses(map<string, Course>& courses) {
    cout << "Enter filename: ";
    string filename;
    cin >> filename;

    ifstream file(filename);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string courseNumber, name, prerequisite;
        getline(ss, courseNumber, ',');
        getline(ss, name, ',');
        vector<string> prerequisites;
        while (getline(ss, prerequisite, ',')) {
            prerequisites.push_back(prerequisite);
        }
        courses[courseNumber] = Course(courseNumber, name, prerequisites);
    }
    cout << "Courses loaded successfully.\n";
}

//Prints all courses
void printCourseList(const map<string, Course>& courses) {
    for (const auto& pair : courses) {
        cout << pair.first << ", " << pair.second.name << '\n';
    }
}

//Function to print details of a specific course
void printCourseDetails(const map<string, Course>& courses) {
    cout << "What course do you want to know about? ";
    string courseNumber;
    cin >> courseNumber;

    auto it = courses.find(courseNumber);
    if (it != courses.end()) {
        const Course& course = it->second;
        cout << course.courseNumber << ", " << course.name << '\n';
        cout << "Prerequisites: ";
        for (const string& prereq : course.prerequisites) {
            cout << prereq << " ";
        }
        cout << '\n';
    } else {
        cout << "Course not found.\n";
        
    }
}


//Function main where program execution starts
int main()
{
    //Map to store courses, keyed by their course number
    map<string, Course> courses;
    bool running = true;

    while (running) {
        displayMenu();
        int choice = getUserChoice();
        switch (choice) {
            case 1:
                loadCourses(courses);
                break;
            case 2:
                printCourseList(courses);
                break;
            case 3:
                printCourseDetails(courses);
                break;
            case 9:
                running = false;
                cout << "Thank you for using the course planner!\n";
                break;
            default:
                displayInvalidOption();
                break;

        }
    }

    return 0;
}



