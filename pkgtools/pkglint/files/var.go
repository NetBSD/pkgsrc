package pkglint

// Var describes a variable in a Makefile snippet.
//
// TODO: Remove this type in June 2019 if it is still a stub.
type Var struct {
	Name string
	Type *Vartype
}

func NewVar(name string) *Var { return &Var{name, nil} }

// Constant returns whether the variable is only ever assigned a single value,
// without being dependent on any other variable.
//
// Multiple assignments (such as VAR=1, VAR+=2, VAR+=3) are considered constant
// as well, as long as the variable is not used in-between these assignments.
// That is, no .include or .if may appear there, and none of the ::= modifiers may
// be involved.
//
// Simple .for loops that append to the variable are ok though.
func (v *Var) Constant() bool { return false }

func (v *Var) ConstantValue() string { return "" }
