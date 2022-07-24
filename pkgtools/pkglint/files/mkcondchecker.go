package pkglint

import (
	"netbsd.org/pkglint/makepat"
	"netbsd.org/pkglint/textproc"
)

// MkCondChecker checks conditions in Makefiles.
// These conditions occur in .if and .elif clauses, as well as the
// :? modifier.
type MkCondChecker struct {
	MkLine  *MkLine
	MkLines *MkLines
}

func NewMkCondChecker(mkLine *MkLine, mkLines *MkLines) *MkCondChecker {
	return &MkCondChecker{MkLine: mkLine, MkLines: mkLines}
}

func (ck *MkCondChecker) Check() {
	mkline := ck.MkLine
	if trace.Tracing {
		defer trace.Call1(mkline.Args())()
	}

	p := NewMkParser(nil, mkline.Args()) // No emitWarnings here, see the code below.
	cond := p.MkCond()
	if !p.EOF() {
		mkline.Warnf("Invalid condition, unrecognized part: %q.", p.Rest())
		return
	}

	checkVarUse := func(varuse *MkVarUse) {
		var vartype *Vartype // TODO: Insert a better type guess here.
		// See Test_MkVarUseChecker_checkAssignable__shell_command_in_exists.
		vuc := VarUseContext{vartype, VucLoadTime, VucQuotPlain, false}
		NewMkVarUseChecker(varuse, ck.MkLines, mkline).Check(&vuc)
	}

	// Skip subconditions that have already been handled as part of the !(...).
	done := make(map[interface{}]bool)

	checkNot := func(not *MkCond) {
		empty := not.Empty
		if empty != nil {
			ck.checkNotEmpty(not)
			ck.checkEmpty(empty, true, true)
			done[empty] = true
		}

		if not.Term != nil && not.Term.Var != nil {
			varUse := not.Term.Var
			ck.checkEmpty(varUse, false, false)
			done[varUse] = true
		}

		ck.checkNotCompare(not)
	}

	checkEmpty := func(empty *MkVarUse) {
		if !done[empty] {
			ck.checkEmpty(empty, true, false)
		}
	}

	checkVar := func(varUse *MkVarUse) {
		if !done[varUse] {
			ck.checkEmpty(varUse, false, true)
		}
	}

	cond.Walk(&MkCondCallback{
		Not:     checkNot,
		Empty:   checkEmpty,
		Var:     checkVar,
		Compare: ck.checkCompare,
		VarUse:  checkVarUse})

	ck.checkContradictions()
}

func (ck *MkCondChecker) checkNotEmpty(not *MkCond) {
	// Consider suggesting ${VAR} instead of !empty(VAR) since it is
	// shorter and avoids unnecessary negation, which makes the
	// expression less confusing.
	//
	// This applies especially to the ${VAR:Mpattern} form.
	//
	// See MkCondChecker.simplify.
	if !hasPrefix(not.Empty.varname, "PKG_BUILD_OPTIONS.") {
		return
	}

	fix := ck.MkLine.Autofix()
	from := sprintf("!empty(%s%s)", not.Empty.varname, not.Empty.Mod())
	to := not.Empty.String()
	fix.Notef("%s can be replaced with %s.", from, to)
	fix.Explain(
		"Besides being simpler to read, the expression will also fail",
		"quickly with a \"Malformed conditional\" error from bmake",
		"if it should ever be undefined at this point.",
		"This catches typos and other programming mistakes.")
	fix.Replace(from, to)
	fix.Apply()
}

// checkEmpty checks a condition of the form empty(VAR),
// empty(VAR:Mpattern) or ${VAR:Mpattern} in an .if directive.
func (ck *MkCondChecker) checkEmpty(varuse *MkVarUse, fromEmpty bool, neg bool) {
	ck.checkEmptyExpr(varuse)
	ck.checkEmptyType(varuse)

	s := MkCondSimplifier{ck.MkLines, ck.MkLine}
	s.SimplifyVarUse(varuse, fromEmpty, neg)
}

func (ck *MkCondChecker) checkEmptyExpr(varuse *MkVarUse) {
	if !matches(varuse.varname, `^\$.*:[MN]`) {
		return
	}

	ck.MkLine.Warnf("The empty() function takes a variable name as parameter, " +
		"not a variable expression.")
	ck.MkLine.Explain(
		"Instead of empty(${VARNAME:Mpattern}), you should write either of the following:",
		"",
		"\tempty(VARNAME:Mpattern)",
		"\t${VARNAME:Mpattern} == \"\"",
		"\t!${VARNAME:Mpattern}",
		"",
		"Instead of !empty(${VARNAME:Mpattern}), you should write either of the following:",
		"",
		"\t!empty(VARNAME:Mpattern)",
		"\t${VARNAME:Mpattern}")
}

func (ck *MkCondChecker) checkEmptyType(varuse *MkVarUse) {
	for _, modifier := range varuse.modifiers {
		ok, _, pattern, _ := modifier.MatchMatch()
		if ok {
			mkLineChecker := NewMkLineChecker(ck.MkLines, ck.MkLine)
			mkLineChecker.checkVartype(varuse.varname, opUseMatch, pattern, "")
			continue
		}

		switch modifier.String() {
		default:
			return
		case "O", "u":
		}
	}
}

// mkCondStringLiteralUnquoted contains a safe subset of the characters
// that may be used without surrounding quotes in a comparison such as
// ${PKGPATH} == category/package.
// TODO: Check whether the ',' really needs to be here.
var mkCondStringLiteralUnquoted = textproc.NewByteSet("-+,./0-9@A-Z_a-z")

// mkCondModifierPatternLiteral contains a safe subset of the characters
// that are interpreted literally in the :M and :N modifiers.
// TODO: Check whether the ',' really needs to be here.
var mkCondModifierPatternLiteral = textproc.NewByteSet("-+,./0-9<=>@A-Z_a-z")

func (ck *MkCondChecker) checkCompare(left *MkCondTerm, op string, right *MkCondTerm) {
	switch {
	case right.Num != "":
		ck.checkCompareVarNum(op, right.Num)
	case left.Var != nil && right.Var == nil:
		ck.checkCompareVarStr(left.Var, op, right.Str)
	}
}

func (ck *MkCondChecker) checkCompareVarStr(varuse *MkVarUse, op string, str string) {
	varname := varuse.varname
	varmods := varuse.modifiers
	switch len(varmods) {
	case 0:
		mkLineChecker := NewMkLineChecker(ck.MkLines, ck.MkLine)
		mkLineChecker.checkVartype(varname, opUseCompare, str, "")

		if varname == "PKGSRC_COMPILER" {
			ck.checkCompareVarStrCompiler(op, str)
		}

	case 1:
		if m, _, pattern, _ := varmods[0].MatchMatch(); m {
			mkLineChecker := NewMkLineChecker(ck.MkLines, ck.MkLine)
			mkLineChecker.checkVartype(varname, opUseMatch, pattern, "")

			// After applying the :M or :N modifier, every expression may end up empty,
			// regardless of its data type. Therefore there's no point in type-checking that case.
			if str != "" {
				mkLineChecker.checkVartype(varname, opUseCompare, str, "")
			}
		}

	default:
		// This case covers ${VAR:Mfilter:O:u} or similar uses in conditions.
		// To check these properly, pkglint first needs to know the most common
		// modifiers and how they interact.
		// As of March 2019, the modifiers are not modeled.
		// The following tracing statement makes it easy to discover these cases,
		// in order to decide whether checking them is worthwhile.
		if trace.Tracing {
			trace.Stepf("checkCompareVarStr ${%s%s} %s %s",
				varuse.varname, varuse.Mod(), op, str)
		}
	}
}

func (ck *MkCondChecker) checkCompareVarNum(op string, num string) {
	if !contains(num, ".") {
		return
	}

	mkline := ck.MkLine
	mkline.Warnf("Numeric comparison %s %s.", op, num)
	mkline.Explain(
		"The numeric comparison of bmake is not suitable for version numbers",
		"since 5.1 == 5.10 == 5.1000000.",
		"",
		"To fix this, either enclose the number in double quotes,",
		"or use pattern matching:",
		"",
		"\t${OS_VERSION} == \"6.5\"",
		"\t${OS_VERSION:M1.[1-9]} || ${OS_VERSION:M1.[1-9].*}",
		"",
		"The second example needs to be split into two parts",
		"since with a single comparison of the form ${OS_VERSION:M1.[1-9]*},",
		"the version number 1.11 would also match, which is not intended.")
}

func (ck *MkCondChecker) checkCompareVarStrCompiler(op string, value string) {
	if !matches(value, `^\w+$`) {
		return
	}

	// It would be nice if original text of the whole comparison expression
	// were available at this point, to avoid guessing how much whitespace
	// the package author really used.

	matchOp := condStr(op == "==", "M", "N")

	fix := ck.MkLine.Autofix()
	fix.Errorf("Use ${PKGSRC_COMPILER:%s%s} instead of the %s operator.", matchOp, value, op)
	fix.Explain(
		"The PKGSRC_COMPILER can be a list of chained compilers, e.g. \"ccache distcc clang\".",
		"Therefore, comparing it using == or != leads to wrong results in these cases.")
	fix.Replace("${PKGSRC_COMPILER} "+op+" "+value, "${PKGSRC_COMPILER:"+matchOp+value+"}")
	fix.Replace("${PKGSRC_COMPILER} "+op+" \""+value+"\"", "${PKGSRC_COMPILER:"+matchOp+value+"}")
	fix.Apply()
}

func (ck *MkCondChecker) checkNotCompare(not *MkCond) {
	if not.Compare == nil {
		return
	}

	ck.MkLine.Warnf("The ! should use parentheses or be merged into the comparison operator.")
}

func (ck *MkCondChecker) checkContradictions() {
	mkline := ck.MkLine

	byVarname := make(map[string][]VarFact)
	levels := ck.MkLines.indentation.levels
	for _, level := range levels[:len(levels)-1] {
		if !level.mkline.NeedsCond() {
			continue
		}
		prevFacts := ck.collectFacts(level.mkline)
		for _, prevFact := range prevFacts {
			varname := prevFact.Varname
			byVarname[varname] = append(byVarname[varname], prevFact)
		}
	}

	facts := ck.collectFacts(mkline)
	for _, curr := range facts {
		varname := curr.Varname
		for _, prev := range byVarname[varname] {
			both := makepat.Intersect(prev.Matches, curr.Matches)
			if !both.CanMatch() {
				if prev.MkLine != mkline {
					mkline.Errorf("The patterns %q from %s and %q cannot match at the same time.",
						prev.Text, mkline.RelMkLine(prev.MkLine), curr.Text)
				} else {
					mkline.Errorf("The patterns %q and %q cannot match at the same time.",
						prev.Text, curr.Text)
				}
			}
		}
		byVarname[varname] = append(byVarname[varname], curr)
	}
}

type VarFact struct {
	MkLine  *MkLine
	Varname string
	Text    string
	Matches *makepat.Pattern
}

func (ck *MkCondChecker) collectFacts(mkline *MkLine) []VarFact {
	var facts []VarFact

	collectUse := func(use *MkVarUse) {
		if use == nil || len(use.modifiers) != 1 {
			return
		}

		ok, positive, pattern, _ := use.modifiers[0].MatchMatch()
		if !ok || !positive || containsVarUse(pattern) {
			return
		}

		vartype := G.Pkgsrc.VariableType(ck.MkLines, use.varname)
		if vartype == nil || vartype.IsList() {
			return
		}

		m, err := makepat.Compile(pattern)
		if err != nil {
			return
		}

		facts = append(facts, VarFact{mkline, use.varname, pattern, m})
	}

	var collectCond func(cond *MkCond)
	collectCond = func(cond *MkCond) {
		if cond.Term != nil {
			collectUse(cond.Term.Var)
		}
		if cond.Not != nil {
			collectUse(cond.Not.Empty)
		}
		for _, cond := range cond.And {
			collectCond(cond)
		}
		if cond.Paren != nil {
			collectCond(cond.Paren)
		}
	}

	collectCond(mkline.Cond())

	return facts
}
