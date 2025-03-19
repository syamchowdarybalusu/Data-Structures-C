#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum size of the stack

// Defining Stack ADT using struct
typedef struct {
    int arr[MAX];  // Array to store stack elements
    int top;       // Top pointer to track the topmost element
} Stack;

// Function prototypes
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);
void display(Stack *s);

int main() {
    Stack s;
    s.top = -1;  // Initialize the stack as empty

    int choice, value;
    
    while (1) {  // Infinite loop for menu-driven program
        // Displaying menu options
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        // Handling different choices without switch case
        if (choice == 1) {
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(&s, value);  // Call push function
        } else if (choice == 2) {
            int popped = pop(&s);
            if (popped != -1)  // Check if pop was successful
                printf("Popped: %d\n", popped);
        } else if (choice == 3) {
            int topElement = peek(&s);
            if (topElement != -1)  // Check if stack is not empty
                printf("Top element: %d\n", topElement);
        } else if (choice == 4) {
            display(&s);  // Call display function
        } else if (choice == 5) {
            printf("Exiting...\n");
            break;  // Exit the loop and terminate the program
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Function to push an element onto the stack
void push(Stack *s, int value) {
    if (s->top == MAX - 1) {  // Check if stack is full
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    s->arr[++s->top] = value;  // Increment top and insert value
    printf("Pushed %d into stack\n", value);
}

// Function to pop an element from the stack
int pop(Stack *s) {
    if (s->top == -1) {  // Check if stack is empty
        printf("Stack Underflow! Cannot pop\n");
        return -1;  // Return -1 to indicate failure
    }
    return s->arr[s->top--];  // Return top element and decrement top
}

// Function to peek the top element of the stack
int peek(Stack *s) {
    if (s->top == -1) {  // Check if stack is empty
        printf("Stack is empty! No top element\n");
        return -1;
    }
    return s->arr[s->top];  // Return the top element
}

// Function to display the stack elements
void display(Stack *s) {
    if (s->top == -1) {  // Check if stack is empty
        printf("Stack is empty! Nothing to display\n");
        return;
    }
    printf("Stack elements (Top to Bottom): ");
    for (int i = s->top; i >= 0; i--)  // Loop from top to bottom
        printf("%d ", s->arr[i]);
    printf("\n");
}
