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

// Checks whether this tree matches the given pattern, and if so,
// copies the corresponding nodes from the tree to the pattern.
// If the match is partially successful, some or all of the variables
// may have been copied or not.
func (t *Tree) Match(pattern *Tree) bool {
	if G.opts.DebugTrace {
		defer tracecall(t, pattern)()
	}
	if t.name != pattern.name || len(t.args) != len(pattern.args) {
		return false
	}

	for i, targ := range t.args {
		parg := pattern.args[i]
		switch parg := parg.(type) {
		case *Tree:
			if targ, ok := targ.(*Tree); ok {
				if !targ.Match(parg) {
					return false
				}
			} else {
				return false
			}
		case **string:
			if targ, ok := targ.(string); ok {
				if *parg == nil {
					*parg = &targ
				} else if **parg != targ {
					return false
				}
			} else {
				return false
			}
		default:
			return false
		}
	}
	return true
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
		} else {
			s += fmt.Sprintf(" %v", arg)
		}
	}
	return s + ")"
}
