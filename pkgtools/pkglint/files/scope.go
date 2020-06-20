package pkglint

import "sort"

// Scope remembers which variables are defined and which are used
// in a certain scope, such as a package or a file.
//
// TODO: Decide whether the scope should consider variable assignments
//  from the pkgsrc infrastructure. For Package.checkGnuConfigureUseLanguages
//  it would be better to ignore them completely.
//
// TODO: Merge this code with Var, which defines essentially the
//  same features.
//
// See also substScope, which already analyzes the possible variable values
// based on the conditional code paths.
//
// See also RedundantScope.
type Scope struct {
	vs    map[string]*scopeVar
	names []string
}

type scopeVar struct {
	firstDef       *MkLine
	lastDef        *MkLine
	value          string
	used           *MkLine
	fallback       string
	usedAtLoadTime bool
	indeterminate  bool
}

func NewScope() Scope {
	return Scope{make(map[string]*scopeVar), nil}
}

func (s *Scope) varnames() []string {
	if len(s.names) == 0 && len(s.vs) > 0 {
		varnames := make([]string, len(s.vs))
		i := 0
		for varname := range s.vs {
			varnames[i] = varname
			i++
		}
		sort.Strings(varnames)
		s.names = varnames
	}
	return s.names
}

func (s *Scope) create(varname string) *scopeVar {
	if v := s.vs[varname]; v != nil {
		return v
	}
	var sv scopeVar
	s.vs[varname] = &sv
	s.names = nil
	return &sv
}

// Define marks the variable and its canonicalized form as defined.
func (s *Scope) Define(varname string, mkline *MkLine) {
	s.def(varname, mkline)
	varcanon := varnameCanon(varname)
	if varcanon != varname {
		s.def(varcanon, mkline)
	}
}

func (s *Scope) def(name string, mkline *MkLine) {
	v := s.create(name)
	if v.firstDef == nil {
		v.firstDef = mkline
		if trace.Tracing {
			trace.Step2("Defining %q for the first time in %s", name, mkline.String())
		}
	} else if trace.Tracing {
		trace.Step2("Defining %q in %s", name, mkline.String())
	}

	v.lastDef = mkline

	// In most cases the defining lines are indeed variable assignments.
	// Exceptions are comments from documentation sections, which still mark
	// the variable as defined so that it doesn't produce the "used but not defined" warning;
	// see MkLines.collectDocumentedVariables.
	if !mkline.IsVarassign() {
		return
	}

	switch mkline.Op() {
	case opAssignAppend:
		value := mkline.Value()
		if trace.Tracing {
			trace.Stepf("Scope.Define.append %s: %s = %q + %q",
				mkline.String(), name, v.value, value)
		}
		v.value += " " + value
	case opAssignDefault:
		if v.value == "" && !v.indeterminate {
			v.value = mkline.Value()
		}
	case opAssignShell:
		v.value = ""
		v.indeterminate = true
	default:
		v.value = mkline.Value()
	}
}

func (s *Scope) Fallback(varname string, value string) {
	s.create(varname).fallback = value
}

// Use marks the variable and its canonicalized form as used.
func (s *Scope) Use(varname string, mkline *MkLine, time VucTime) {
	use := func(name string) {
		v := s.create(name)
		if v.used == nil {
			v.used = mkline
			if trace.Tracing {
				trace.Step2("Using %q in %s", name, mkline.String())
			}
		}
		if time == VucLoadTime {
			v.usedAtLoadTime = true
		}
	}

	use(varname)
	use(varnameCanon(varname))
}

// Mentioned returns the first line in which the variable is either:
//  - defined,
//  - mentioned in a commented variable assignment,
//  - mentioned in a documentation comment.
func (s *Scope) Mentioned(varname string) *MkLine {
	if v := s.vs[varname]; v != nil {
		return v.firstDef
	}
	return nil
}

// IsDefined tests whether the variable is defined.
// It does NOT test the canonicalized variable name.
//
// Even if IsDefined returns true, FirstDefinition doesn't necessarily return true
// since the latter ignores the default definitions from vardefs.go, keyword dummyVardefMkline.
func (s *Scope) IsDefined(varname string) bool {
	mkline := s.Mentioned(varname)
	return mkline != nil && mkline.IsVarassign()
}

// IsDefinedSimilar tests whether the variable or its canonicalized form is defined.
func (s *Scope) IsDefinedSimilar(varname string) bool {
	if s.IsDefined(varname) {
		if trace.Tracing {
			trace.Step1("Variable %q is defined", varname)
		}
		return true
	}

	varcanon := varnameCanon(varname)
	if s.IsDefined(varcanon) {
		if trace.Tracing {
			trace.Step2("Variable %q (similar to %q) is defined", varcanon, varname)
		}
		return true
	}
	return false
}

// IsUsed tests whether the variable is used.
// It does NOT test the canonicalized variable name.
func (s *Scope) IsUsed(varname string) bool {
	return s.FirstUse(varname) != nil
}

// IsUsedSimilar tests whether the variable or its canonicalized form is used.
func (s *Scope) IsUsedSimilar(varname string) bool {
	return s.FirstUse(varname) != nil || s.FirstUse(varnameCanon(varname)) != nil
}

// IsUsedAtLoadTime returns true if the variable is used at load time
// somewhere.
func (s *Scope) IsUsedAtLoadTime(varname string) bool {
	v := s.vs[varname]
	return v != nil && v.usedAtLoadTime
}

// FirstDefinition returns the line in which the variable has been defined first.
//
// Having multiple definitions is typical in the branches of "if" statements.
//
// Another typical case involves two files: the included file defines a default
// value, and the including file later overrides that value. Or the other way
// round: the including file sets a value first, and the included file then
// assigns a default value using ?=.
func (s *Scope) FirstDefinition(varname string) *MkLine {
	v := s.vs[varname]
	if v == nil {
		return nil
	}

	mkline := v.firstDef
	if mkline != nil && mkline.IsVarassign() {
		lastLine := s.LastDefinition(varname)
		if trace.Tracing && lastLine != mkline {
			trace.Stepf("%s: FirstDefinition differs from LastDefinition in %s.",
				mkline.String(), mkline.RelMkLine(lastLine))
		}
		return mkline
	}
	return nil // See NewPackage and G.Pkgsrc.UserDefinedVars
}

// LastDefinition returns the line in which the variable has been defined last.
//
// Having multiple definitions is typical in the branches of "if" statements.
//
// Another typical case involves two files: the included file defines a default
// value, and the including file later overrides that value. Or the other way
// round: the including file sets a value first, and the included file then
// assigns a default value using ?=.
func (s *Scope) LastDefinition(varname string) *MkLine {
	v := s.vs[varname]
	if v == nil {
		return nil
	}

	mkline := v.lastDef
	if mkline != nil && mkline.IsVarassign() {
		return mkline
	}
	return nil // See NewPackage and G.Pkgsrc.UserDefinedVars
}

// Commented returns whether the variable has only been defined in commented
// variable assignments. These are ignored by bmake but used heavily in
// mk/defaults/mk.conf for documentation.
func (s *Scope) Commented(varname string) *MkLine {
	v := s.vs[varname]
	if v == nil {
		return nil
	}

	mklines := make([]*MkLine, 0, 2)
	if v.firstDef != nil {
		mklines = append(mklines, v.firstDef)
	}
	if v.lastDef != nil {
		mklines = append(mklines, v.lastDef)
	}

	for _, mkline := range mklines {
		if mkline.IsVarassign() {
			return nil
		}
	}

	for _, mkline := range mklines {
		if mkline.IsCommentedVarassign() {
			return mkline
		}
	}

	return nil
}

func (s *Scope) FirstUse(varname string) *MkLine {
	v := s.vs[varname]
	if v == nil {
		return nil
	}
	return v.used
}

// LastValue returns the value from the last variable definition.
//
// If an empty string is returned, this can mean either that the
// variable value is indeed the empty string or that the variable
// was not found, or that the variable value cannot be determined
// reliably. To distinguish these cases, call LastValueFound instead.
func (s *Scope) LastValue(varname string) string {
	value, _, _ := s.LastValueFound(varname)
	return value
}

func (s *Scope) LastValueFound(varname string) (value string, found bool, indeterminate bool) {
	v := s.vs[varname]
	if v == nil {
		return
	}

	value = v.value
	found = v.firstDef != nil && v.firstDef.IsVarassign()
	indeterminate = v.indeterminate
	if found {
		return
	}

	return v.fallback, v.fallback != "", v.indeterminate
}

func (s *Scope) DefineAll(other *Scope) {
	for _, varname := range other.varnames() {
		v := other.vs[varname]
		if v.firstDef != nil {
			s.Define(varname, v.firstDef)
			s.Define(varname, v.lastDef)
		}
	}
}

func (s *Scope) forEach(action func(varname string, data *scopeVar)) {
	var keys []string
	for key := range s.vs {
		keys = append(keys, key)
	}
	sort.Strings(keys)
	for _, key := range keys {
		action(key, s.vs[key])
	}
}
