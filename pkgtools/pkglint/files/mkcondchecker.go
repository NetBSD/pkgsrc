package pkglint

import "netbsd.org/pkglint/textproc"

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
		vuc := VarUseContext{vartype, VucLoadTime, VucQuotPlain, false}
		NewMkVarUseChecker(varuse, ck.MkLines, mkline).Check(&vuc)
	}

	// Skip subconditions that have already been handled as part of the !(...).
	done := make(map[interface{}]bool)

	checkNotEmpty := func(not *MkCond) {
		empty := not.Empty
		if empty != nil {
			ck.checkEmpty(empty, true, true)
			done[empty] = true
		}

		if not.Term != nil && not.Term.Var != nil {
			varUse := not.Term.Var
			ck.checkEmpty(varUse, false, false)
			done[varUse] = true
		}
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
		Not:     checkNotEmpty,
		Empty:   checkEmpty,
		Var:     checkVar,
		Compare: ck.checkCompare,
		VarUse:  checkVarUse})
}

// checkEmpty checks a condition of the form empty(VAR),
// empty(VAR:Mpattern) or ${VAR:Mpattern} in an .if directive.
func (ck *MkCondChecker) checkEmpty(varuse *MkVarUse, fromEmpty bool, neg bool) {
	ck.checkEmptyExpr(varuse)
	ck.checkEmptyType(varuse)
	ck.simplify(varuse, fromEmpty, neg)
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

		switch modifier.Text {
		default:
			return
		case "O", "u":
		}
	}
}

// mkCondStringLiteralUnquoted contains a safe subset of the characters
// that may be used without surrounding quotes in a comparison such as
// ${PKGPATH} == category/package.
var mkCondStringLiteralUnquoted = textproc.NewByteSet("+---./0-9@A-Z_a-z")

// mkCondModifierPatternLiteral contains a safe subset of the characters
// that are interpreted literally in the :M and :N modifiers.
var mkCondModifierPatternLiteral = textproc.NewByteSet("+---./0-9<=>@A-Z_a-z")

// simplify replaces an unnecessarily complex condition with
// a simpler condition that's still equivalent.
//
// * fromEmpty is true for the form empty(VAR...), and false for ${VAR...}.
//
// * neg is true for the form !empty(VAR...), and false for empty(VAR...).
// It also applies to the ${VAR} form.
func (ck *MkCondChecker) simplify(varuse *MkVarUse, fromEmpty bool, neg bool) {
	varname := varuse.varname
	mods := varuse.modifiers
	modifiers := mods

	n := len(modifiers)
	if n == 0 {
		return
	}
	modsExceptLast := NewMkVarUse("", mods[:n-1]...).Mod()
	vartype := G.Pkgsrc.VariableType(ck.MkLines, varname)

	isDefined := func() bool {
		if vartype.IsAlwaysInScope() && vartype.IsDefinedIfInScope() {
			return true
		}

		// TODO: Use ck.MkLines.loadVars instead.
		if ck.MkLines.allVars.IsDefined(varname) {
			return true
		}

		return ck.MkLines.Tools.SeenPrefs &&
			vartype.Union().Contains(aclpUseLoadtime) &&
			vartype.IsDefinedIfInScope()
	}

	// replace constructs the state before and after the autofix.
	// The before state is constructed to ensure that only very simple
	// patterns get replaced automatically.
	//
	// Before putting any cases involving special characters into
	// production, there need to be more tests for the edge cases.
	replace := func(positive bool, pattern string) (bool, string, string) {
		defined := isDefined()
		if !defined && !positive {
			// TODO: This is a double negation, maybe even triple.
			//  There is an :N pattern, and the variable may be undefined.
			//  If it is indeed undefined, should the whole condition
			//  evaluate to true or false?
			//  The cases to be distinguished are: undefined, empty, filled.

			// For now, be conservative and don't suggest anything wrong.
			return false, "", ""
		}
		uMod := condStr(!defined && !varuse.HasModifier("U"), ":U", "")

		op := condStr(neg == positive, "==", "!=")

		from := sprintf("%s%s%s%s%s%s%s",
			condStr(neg != fromEmpty, "", "!"),
			condStr(fromEmpty, "empty(", "${"),
			varname,
			modsExceptLast,
			condStr(positive, ":M", ":N"),
			pattern,
			condStr(fromEmpty, ")", "}"))

		needsQuotes := textproc.NewLexer(pattern).NextBytesSet(mkCondStringLiteralUnquoted) != pattern ||
			matches(pattern, `^\d+\.?\d*$`)
		quote := condStr(needsQuotes, "\"", "")

		to := sprintf(
			"${%s%s%s} %s %s%s%s",
			varname, uMod, modsExceptLast, op, quote, pattern, quote)

		return true, from, to
	}

	modifier := modifiers[n-1]
	ok, positive, pattern, exact := modifier.MatchMatch()
	if !ok || !positive && n != 1 {
		return
	}

	switch {
	case !exact,
		vartype == nil,
		vartype.IsList(),
		textproc.NewLexer(pattern).NextBytesSet(mkCondModifierPatternLiteral) != pattern:
		return
	}

	ok, from, to := replace(positive, pattern)
	if !ok {
		return
	}

	fix := ck.MkLine.Autofix()
	fix.Notef("%s can be compared using the simpler \"%s\" "+
		"instead of matching against %q.",
		varname, to, ":"+modifier.Text)
	fix.Explain(
		"This variable has a single value, not a list of values.",
		"Therefore it feels strange to apply list operators like :M and :N onto it.",
		"A more direct approach is to use the == and != operators.",
		"",
		"An entirely different case is when the pattern contains",
		"wildcards like *, ?, [].",
		"In such a case, using the :M or :N modifiers is useful and preferred.")
	fix.Replace(from, to)
	fix.Apply()
}

func (ck *MkCondChecker) checkCompare(left *MkCondTerm, op string, right *MkCondTerm) {
	switch {
	case left.Var != nil && right.Var == nil && right.Num == "":
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
