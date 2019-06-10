package pkglint

// Var describes a variable in a Makefile snippet.
//
// It keeps track of all places where the variable is accessed or modified (see
// ReadLocations, WriteLocations) and provides information for further static
// analysis, such as:
//
// * Whether the variable value is constant, and if so, what the constant value
// is (see Constant, ConstantValue).
//
// * What its (approximated) value is, either including values from the pkgsrc
// infrastructure (see ValueInfra) or excluding them (Value).
//
// * On which other variables this variable depends (see Conditional,
// ConditionalVars).
//
// TODO: Decide how to handle OPSYS-specific variables, such as LDFLAGS.SunOS.
//
// TODO: Decide how to handle parameterized variables, such as SUBST_MESSAGE.doc.
type Var struct {
	Name string

	//  0 = neither written nor read
	//  1 = constant
	//  2 = constant and read; further writes will make it non-constant
	//  3 = not constant anymore
	constantState uint8
	constantValue string

	value      string
	valueInfra string

	readLocations  []MkLine
	writeLocations []MkLine

	conditional     bool
	conditionalVars StringSet

	refs StringSet
}

func NewVar(name string) *Var {
	return &Var{name, 0, "", "", "", nil, nil, false, NewStringSet(), NewStringSet()}
}

// Conditional returns whether the variable value depends on other variables.
func (v *Var) Conditional() bool {
	return v.conditional
}

// ConditionalVars returns all variables in conditions on which the value of
// this variable depends.
//
// The returned slice must not be modified.
func (v *Var) ConditionalVars() []string {
	return v.conditionalVars.Elements
}

// Refs returns all variables on which this variable depends. These are:
//
// Variables that are referenced in the value, such as in VAR=${OTHER}.
//
// Variables that are used in conditions that enclose one of the assignments
// to this variable, such as .if ${OPSYS} == NetBSD.
//
// Variables that are used in .for loops in which this variable is assigned
// a value, such as DIRS in:
//  .for dir in ${DIRS}
//  VAR+=${dir}
//  .endfor
func (v *Var) Refs() []string {
	return v.refs.Elements
}

// AddRef marks this variable as being dependent on the given variable name.
// This can be used for the .for loops mentioned in Refs.
func (v *Var) AddRef(varname string) {
	v.refs.Add(varname)
}

// Constant returns whether the variable's value is a constant.
// It may reference other variables since these references are evaluated
// lazily, when the variable value is actually needed.
//
// Multiple assignments (such as VAR=1, VAR+=2, VAR+=3) are considered to
// form a single constant as well, as long as the variable is not read before
// or in-between these assignments. The definition of "read" is very strict
// here since every mention of the variable counts. This may prevent some
// essentially constant values from being detected as such, but these special
// cases may be implemented later.
//
// TODO: Simple .for loops that append to the variable are ok as well.
//  (This needs to be worded more precisely since that part potentially
//  adds a lot of complexity to the whole data structure.)
//
// Variable assignments in the pkgsrc infrastructure are taken into account
// for determining whether a variable is constant.
func (v *Var) Constant() bool {
	return v.constantState == 1 || v.constantState == 2
}

// ConstantValue returns the constant value of the variable.
// It is only allowed when Constant() returns true.
//
// Variable assignments in the pkgsrc infrastructure are taken into account
// for determining the constant value.
func (v *Var) ConstantValue() string {
	assertf(v.Constant(), "Variable must be constant.")
	return v.constantValue
}

// Value returns the (approximated) value of the variable, taking into account
// all variable assignments that happen outside the pkgsrc infrastructure.
//
// For variables that are conditionally assigned (as in .if/.else), the
// returned value is not reliable. It may be the value from either branch, or
// even the combined value of both branches.
//
// See Constant and ConstantValue for more reliable information.
func (v *Var) Value() string {
	return v.value
}

// ValueInfra returns the (approximated) value of the variable, taking into
// account all variable assignments from the package, the user and the pkgsrc
// infrastructure.
//
// For variables that are conditionally assigned (as in .if/.else), the
// returned value is not reliable. It may be the value from either branch, or
// even the combined value of both branches.
//
// See Constant and ConstantValue for more reliable information, but these
// ignore assignments from the infrastructure.
func (v *Var) ValueInfra() string {
	return v.valueInfra
}

// ReadLocations returns the locations where the variable is read, such as
// in ${VAR} or defined(VAR) or empty(VAR).
//
// Uses inside conditionals are included, no matter whether they are actually
// reachable in practice.
//
// Indirect uses through other variables (such as VAR2=${VAR}, VAR3=${VAR2})
// are not listed.
//
// Variable uses in the pkgsrc infrastructure are taken into account.
func (v *Var) ReadLocations() []MkLine {
	return v.readLocations
}

// WriteLocations returns the locations where the variable is modified.
//
// Assignments inside conditionals are included, no matter whether they are actually
// reachable in practice.
//
// Variable assignments in the pkgsrc infrastructure are taken into account.
func (v *Var) WriteLocations() []MkLine {
	return v.writeLocations
}

func (v *Var) Read(mkline MkLine) {
	v.readLocations = append(v.readLocations, mkline)
	v.constantState = [...]uint8{3, 2, 2, 3}[v.constantState]
}

// Write marks the variable as being assigned in the given line.
// Only standard assignments (VAR=value) are handled.
// Side-effect assignments (${VAR::=value}) are not handled here since
// they don't occur in practice.
func (v *Var) Write(mkline MkLine, conditional bool, conditionVarnames ...string) {
	assertf(mkline.Varname() == v.Name, "wrong variable name")

	v.writeLocations = append(v.writeLocations, mkline)

	if conditional {
		v.conditional = true
	}
	v.conditionalVars.AddAll(conditionVarnames)

	mkline.ForEachUsed(func(varUse *MkVarUse, time vucTime) {
		v.refs.Add(varUse.varname)
	})
	v.refs.AddAll(conditionVarnames)

	v.update(mkline, &v.valueInfra)
	if !G.Pkgsrc.IsInfra(mkline.Line.Filename) {
		v.update(mkline, &v.value)
	}

	v.updateConstantValue(mkline)
}

func (v *Var) update(mkline MkLine, update *string) {
	firstWrite := len(v.writeLocations) == 1
	if v.Conditional() && !firstWrite {
		return
	}

	value := mkline.Value()
	switch mkline.Op() {
	case opAssign, opAssignEval:
		*update = value

	case opAssignDefault:
		if firstWrite {
			*update = value
		}

	case opAssignAppend:
		*update += " " + value

	case opAssignShell:
		// Ignore these for now.
		// Later it might be useful to parse the shell commands to
		// evaluate simple commands like "test && echo yes || echo no".
	}
}

func (v *Var) updateConstantValue(mkline MkLine) {
	if v.constantState == 3 {
		return
	}

	// Even if the variable references other variables, this does not
	// influence whether the variable is considered constant. (Except
	// for the := operator.)
	//
	// Strictly speaking, the referenced variables must be still
	// be constant at the end of loading the complete package.
	// (And even after that, because of the ::= modifier. But luckily
	// almost no one knows that modifier.)

	if v.Conditional() {
		v.constantState = 3
		v.constantValue = ""
		return
	}

	value := mkline.Value()
	switch mkline.Op() {
	case opAssign:
		v.constantValue = value

	case opAssignEval:
		if value != mkline.WithoutMakeVariables(value) {
			// To leave the variable in the constant state, the current value
			// of the referenced variables would need to be resolved.
			//
			// This in turn requires the proper scope for resolving variable
			// references. Furthermore, the referenced variables must be
			// constant at this point. Later changes to these variables
			// can be ignored though.
			//
			// Because this sounds complicated to implement, the variable
			// is marked as non-constant for now.
			v.constantState = 3
			v.constantValue = ""
		} else {
			v.constantValue = value
		}

	case opAssignDefault:
		if v.constantState == 0 {
			v.constantValue = value
		}

	case opAssignAppend:
		v.constantValue += " " + value

	case opAssignShell:
		v.constantState = 3
		v.constantValue = ""
	}

	v.constantState = [...]uint8{1, 1, 3, 3}[v.constantState]
}
