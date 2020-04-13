package pkglint

// RedundantScope checks for redundant variable definitions and for variables
// that are accidentally overwritten. It tries to be as correct as possible
// by not flagging anything that is defined conditionally.
//
// There may be some edge cases though like defining PKGNAME, then evaluating
// it using :=, then defining it again. This pattern is so error-prone that
// it should not appear in pkgsrc at all, thus pkglint doesn't even expect it.
// (Well, except for the PKGNAME case, but that's deep in the infrastructure
// and only affects the "nb13" extension.)
//
// TODO: This scope is not only used for detecting redundancies. It also
// provides information about whether the variables are constant or depend on
// other variables. Therefore the name may change soon.
type RedundantScope struct {
	vars        map[string]*redundantScopeVarinfo
	includePath includePath
	IsRelevant  func(mkline *MkLine) bool
}
type redundantScopeVarinfo struct {
	vari         *Var
	includePaths []includePath
	lastAction   uint8 // 0 = none, 1 = read, 2 = write
}

func NewRedundantScope() *RedundantScope {
	return &RedundantScope{make(map[string]*redundantScopeVarinfo), includePath{}, nil}
}

func (s *RedundantScope) Check(mklines *MkLines) {
	mklines.ForEach(func(mkline *MkLine) {
		s.checkLine(mklines, mkline)
	})
}

func (s *RedundantScope) checkLine(mklines *MkLines, mkline *MkLine) {
	s.updateIncludePath(mkline)

	switch {
	case mkline.IsVarassign():
		s.handleVarassign(mkline, mklines.indentation)
	}

	s.handleVarUse(mkline)
}

func (s *RedundantScope) updateIncludePath(mkline *MkLine) {
	if mkline.Location.lineno == 1 {
		s.includePath.push(mkline.Filename())
	} else {
		s.includePath.popUntil(mkline.Filename())
	}
}

func (s *RedundantScope) handleVarassign(mkline *MkLine, ind *Indentation) {
	varname := mkline.Varname()
	info := s.get(varname)

	defer func() {
		info.vari.Write(mkline, ind.Depth("") > 0, ind.Varnames()...)
		info.lastAction = 2
		s.access(varname)
	}()

	// In the very first assignment, no redundancy can occur.
	prevWrites := info.vari.WriteLocations()
	if len(prevWrites) == 0 {
		return
	}

	// TODO: Just being conditional is only half the truth.
	//  To be precise, the "conditional path" must differ between
	//  this variable assignment and the/any? previous one.
	//  See Test_RedundantScope__overwrite_inside_conditional.
	//  Anyway, too few warnings are better than wrong warnings.
	if info.vari.IsConditional() || ind.Depth("") > 0 {
		return
	}

	// When the variable has been read after the previous write,
	// it is not redundant.
	if info.lastAction == 1 {
		return
	}

	effOp := mkline.Op()
	value := mkline.Value()

	if effOp == opAssignEval && value == mkline.WithoutMakeVariables(value) {
		// Maybe add support for VAR:= ${OTHER} later. This involves evaluating
		// the OTHER variable though using the appropriate scope. Oh, wait,
		// there _is_ a scope here. So if OTHER doesn't refer to further
		// variables it's all possible.
		//
		// TODO: The above idea seems possible and useful.
		effOp = opAssign
	}

	// TODO: Skip the whole redundancy check if the value is not known to be constant.
	if effOp == opAssign && info.vari.Value() == value {
		effOp = opAssignDefault
	}

	switch effOp {

	case opAssign: // with a different value than before
		if s.includePath.includedByOrEqualsAll(info.includePaths) {

			// The situation is:
			//
			//   including.mk: VAR= initial value
			//   included.mk:  VAR= overwriting     <-- you are here
			//
			// Because the included files is never wrong (by definition),
			// the including file gets the warning in this case.
			s.onOverwrite(prevWrites[len(prevWrites)-1], mkline)
		}

	case opAssignDefault: // or opAssign with the same value as before
		switch {

		case s.includePath.includesOrEqualsAll(info.includePaths):

			// The situation is:
			//
			//   included.mk:  VAR=  value
			//   including.mk: VAR=  value   <-- you are here
			//   including.mk: VAR?= value   <-- or here
			//
			// After including one or more files, the variable is either
			// overwritten or defaulted with the same value as its
			// guaranteed current value. All previous accesses to the
			// variable were either in this file or in an included file.
			s.onRedundant(mkline, prevWrites[len(prevWrites)-1])

		case s.includePath.includedByOrEqualsAll(info.includePaths):

			// The situation is:
			//
			//   including.mk: VAR=  value
			//   included.mk:  VAR?= value   <-- you are here
			//   included.mk:  VAR=  value   <-- or here
			//
			// A variable has been defined in an including file.
			// The current line either has a default assignment or an
			// unconditional assignment. This is common and fine.
			//
			// Except when this line has the same value as the guaranteed
			// current value of the variable. Then it is redundant.
			if info.vari.IsConstant() && info.vari.ConstantValue() == mkline.Value() {
				s.onRedundant(prevWrites[len(prevWrites)-1], mkline)
			}
		}

	case opAssignAppend:
		s.checkAppendUnique(mkline, info)
	}
}

// checkAppendUnique checks whether a redundant value is appended to a
// variable that doesn't need repeated values, such as CATEGORIES.
func (s *RedundantScope) checkAppendUnique(mkline *MkLine, info *redundantScopeVarinfo) {
	if !info.vari.IsConstant() {
		return
	}

	vartype := G.Pkgsrc.VariableType(nil, info.vari.Name)
	if !(vartype != nil && vartype.IsUnique()) {
		return
	}

	checkRedundantAppend := func(redundant *MkLine, because *MkLine) {
		reds := redundant.ValueFieldsLiteral()
		becs := because.ValueFieldsLiteral()
		for _, red := range reds {
			for _, bec := range becs {
				if red != bec {
					continue
				}
				if redundant == mkline {
					redundant.Notef("Appending %q to %s is redundant because it is already added in %s.",
						red, info.vari.Name, redundant.RelMkLine(because))
				} else {
					redundant.Notef("Adding %q to %s is redundant because it will later be appended in %s.",
						red, info.vari.Name, redundant.RelMkLine(because))
				}
			}
		}
	}

	if s.includePath.includesOrEqualsAll(info.includePaths) {
		for _, prev := range info.vari.WriteLocations() {
			checkRedundantAppend(mkline, prev)
		}
	} else if s.includePath.includedByOrEqualsAll(info.includePaths) {
		for _, prev := range info.vari.WriteLocations() {
			checkRedundantAppend(prev, mkline)
		}
	}
}

func (s *RedundantScope) handleVarUse(mkline *MkLine) {
	switch {
	case mkline.IsVarassign():
		mkline.ForEachUsed(func(varUse *MkVarUse, time VucTime) {
			varname := varUse.varname
			info := s.get(varname)
			info.vari.Read(mkline)
			info.lastAction = 1
			s.access(varname)
		})

	case mkline.IsDirective():
		// TODO: Handle varuse for conditions and loops.
		break

	case mkline.IsInclude(), mkline.IsSysinclude():
		// TODO: Handle VarUse for includes, which may reference variables.
		break

	case mkline.IsDependency():
		// TODO: Handle VarUse for this case.
	}
}

// access returns the info for the given variable, creating it if necessary.
func (s *RedundantScope) get(varname string) *redundantScopeVarinfo {
	info := s.vars[varname]
	if info == nil {
		v := NewVar(varname)
		info = &redundantScopeVarinfo{v, nil, 0}
		s.vars[varname] = info
	}
	return info
}

// access records the current file location, to be used in later inclusion checks.
func (s *RedundantScope) access(varname string) {
	info := s.vars[varname]
	info.includePaths = append(info.includePaths, s.includePath.copy())
}

func (s *RedundantScope) onRedundant(redundant *MkLine, because *MkLine) {
	if s.IsRelevant != nil && !s.IsRelevant(redundant) {
		return
	}
	if redundant.Op() == opAssignDefault {
		redundant.Notef("Default assignment of %s has no effect because of %s.",
			because.Varname(), redundant.RelMkLine(because))
	} else {
		redundant.Notef("Definition of %s is redundant because of %s.",
			because.Varname(), redundant.RelMkLine(because))
	}
}

func (s *RedundantScope) onOverwrite(overwritten *MkLine, by *MkLine) {
	if s.IsRelevant != nil && !s.IsRelevant(overwritten) {
		return
	}
	overwritten.Warnf("Variable %s is overwritten in %s.",
		overwritten.Varname(), overwritten.RelMkLine(by))
	overwritten.Explain(
		"The variable definition in this line does not have an effect since",
		"it is overwritten elsewhere.",
		"This typically happens because of a typo (writing = instead of +=)",
		"or because the line that overwrites",
		"is in another file that is used by several packages.")
}

// includePath remembers the whole sequence of included files,
// such as Makefile includes ../../a/b/buildlink3.mk includes ../../c/d/buildlink3.mk.
//
// This information is used by the RedundantScope to decide whether
// one of two variable assignments is redundant. Two assignments can
// only be redundant if one location includes the other.
type includePath struct {
	files []CurrPath
}

func (p *includePath) push(filename CurrPath) {
	p.files = append(p.files, filename)
}

func (p *includePath) popUntil(filename CurrPath) {
	for p.files[len(p.files)-1] != filename {
		p.files = p.files[:len(p.files)-1]
	}
}

func (p *includePath) includes(other includePath) bool {
	for i, filename := range p.files {
		if i >= len(other.files) || other.files[i] != filename {
			return false
		}
	}
	return len(p.files) < len(other.files)
}

func (p *includePath) includesOrEqualsAll(others []includePath) bool {
	for _, other := range others {
		if !(p.includes(other) || p.equals(other)) {
			return false
		}
	}
	return true
}

func (p *includePath) includedByOrEqualsAll(others []includePath) bool {
	for _, other := range others {
		if !(other.includes(*p) || p.equals(other)) {
			return false
		}
	}
	return true
}

func (p *includePath) equals(other includePath) bool {
	if len(p.files) != len(other.files) {
		return false
	}
	for i, filename := range p.files {
		if other.files[i] != filename {
			return false
		}
	}
	return true
}

func (p *includePath) copy() includePath {
	return includePath{append([]CurrPath(nil), p.files...)}
}
