package main

import (
	"fmt"
)

type Tree struct {
	name string
	args []interface{}
}

func NewTree(name string, args ...interface{}) *Tree {
	return &Tree{name, args}
}

func (t *Tree) String() string {
	s := "(" + t.name
	for _, arg := range t.args {
		if arg, ok := arg.(*Tree); ok {
			s += " " + (*arg).String()
			continue
		}
		if arg, ok := arg.(string); ok {
			s += fmt.Sprintf(" %q", arg)
			continue
		}
		s += fmt.Sprintf(" %v", arg)
	}
	return s + ")"
}

func (t *Tree) Visit(nodename string, action func(t *Tree)) {
	if t.name == nodename {
		action(t)
	}
	for _, arg := range t.args {
		if child, ok := arg.(*Tree); ok {
			child.Visit(nodename, action)
		}
	}
}
