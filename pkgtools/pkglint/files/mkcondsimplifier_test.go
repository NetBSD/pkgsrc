package pkglint

import (
	"gopkg.in/check.v1"
)

type MkCondSimplifierTester struct {
	c *check.C
	*Tester
}

func (t *MkCondSimplifierTester) setUp() {
	t.CreateFileLines("mk/bsd.prefs.mk")
	t.Chdir("category/package")

	// The Anything type suppresses the warnings from type checking.
	// BtUnknown would not work here, see Pkgsrc.VariableType.
	btAnything := &BasicType{"Anything", func(cv *VartypeCheck) {}}

	// For simplifying the expressions, it is necessary to know whether
	// a variable can be undefined. Undefined variables need the
	// :U modifier or must be enclosed in double quotes, otherwise
	// bmake will complain about a "Malformed conditional". That error
	// message is not entirely precise since the expression
	// is syntactically valid, it's just the evaluation that fails.
	//
	// Some variables such as MACHINE_ARCH are in scope from the very
	// beginning.
	//
	// Some variables such as PKGPATH are in scope after bsd.prefs.mk
	// has been included.
	//
	// Some variables such as PREFIX (as of December 2019) are only in
	// scope after bsd.pkg.mk has been included. These cannot be used
	// in .if conditions at all.
	//
	// Even when they are in scope, some variables such as PKGREVISION
	// or MAKE_JOBS may be undefined.

	t.SetUpVarType("IN_SCOPE_DEFINED", btAnything, AlwaysInScope|DefinedIfInScope,
		"*.mk: use, use-loadtime")
	t.SetUpVarType("IN_SCOPE", btAnything, AlwaysInScope,
		"*.mk: use, use-loadtime")
	t.SetUpVarType("PREFS_DEFINED", btAnything, DefinedIfInScope,
		"*.mk: use, use-loadtime")
	t.SetUpVarType("PREFS", btAnything, NoVartypeOptions,
		"*.mk: use, use-loadtime")
	t.SetUpVarType("LATER_DEFINED", btAnything, DefinedIfInScope,
		"*.mk: use")
	t.SetUpVarType("LATER", btAnything, NoVartypeOptions,
		"*.mk: use")
	// UNDEFINED is also used in the following tests, but is obviously
	// not defined here.
}

func (t *MkCondSimplifierTester) testBeforePrefs(before, after string, diagnostics ...string) {
	t.doTest(false, before, after, diagnostics...)
}

func (t *MkCondSimplifierTester) testAfterPrefs(before, after string, diagnostics ...string) {
	t.doTest(true, before, after, diagnostics...)
}
func (t *MkCondSimplifierTester) testBeforeAndAfterPrefs(before, after string, diagnostics ...string) {
	t.doTest(false, before, after, diagnostics...)
	t.doTest(true, before, after, diagnostics...)
}

// prefs: whether to include bsd.prefs.mk before the condition
// before: the directive before the condition is simplified
// after: the directive after the condition is simplified
func (t *MkCondSimplifierTester) doTest(prefs bool, before, after string, diagnostics ...string) {
	if !matches(before, `IN_SCOPE|PREFS|LATER|UNDEFINED`) {
		t.c.Errorf("Condition %q must include one of the above variable names.", before)
	}
	mklines := t.SetUpFileMkLines("filename.mk",
		MkCvsID,
		condStr(prefs, ".include \"../../mk/bsd.prefs.mk\"", ""),
		"", // a few spare lines
		"", // a few spare lines
		"", // a few spare lines
		before,
		".endif")

	action := func(autofix bool) {
		mklines.ForEach(func(mkline *MkLine) {
			// Sets mklines.Tools.SeenPrefs, which decides whether the :U modifier
			// is necessary; see MkLines.checkLine.
			mklines.Tools.ParseToolLine(mklines, mkline, false, false)

			if mkline.IsDirective() && mkline.Directive() != "endif" {
				// TODO: Replace Check with a more
				//  specific method that does not do the type checks.
				NewMkCondChecker(mkline, mklines).Check()
			}
		})

		if autofix {
			afterMklines := LoadMk(t.File("filename.mk"), nil, MustSucceed)
			t.CheckEquals(afterMklines.mklines[5].Text, after)
		}
	}

	t.ExpectDiagnosticsAutofix(action, diagnostics...)
}

func (s *Suite) Test_MkCondSimplifier_SimplifyVarUse(c *check.C) {
	t := MkCondSimplifierTester{c, s.Init(c)}

	t.setUp()

	t.testBeforeAndAfterPrefs(
		".if ${IN_SCOPE_DEFINED:Mpattern}",
		".if ${IN_SCOPE_DEFINED} == pattern",

		"NOTE: filename.mk:6: IN_SCOPE_DEFINED can be "+
			"compared using the simpler \"${IN_SCOPE_DEFINED} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:6: Replacing \"${IN_SCOPE_DEFINED:Mpattern}\" "+
			"with \"${IN_SCOPE_DEFINED} == pattern\".")

	t.testBeforeAndAfterPrefs(
		".if !empty(IN_SCOPE_DEFINED:M[Nn][Oo])",
		".if ${IN_SCOPE_DEFINED:M[Nn][Oo]}",

		"NOTE: filename.mk:6: \"!empty(IN_SCOPE_DEFINED:M[Nn][Oo])\" "+
			"can be simplified to \"${IN_SCOPE_DEFINED:M[Nn][Oo]}\".",
		"AUTOFIX: filename.mk:6: "+
			"Replacing \"!empty(IN_SCOPE_DEFINED:M[Nn][Oo])\" "+
			"with \"${IN_SCOPE_DEFINED:M[Nn][Oo]}\".")
}

func (s *Suite) Test_MkCondSimplifier_simplifyWord(c *check.C) {
	t := MkCondSimplifierTester{c, s.Init(c)}

	t.setUp()

	t.testBeforeAndAfterPrefs(
		".if ${IN_SCOPE_DEFINED:Mpattern}",
		".if ${IN_SCOPE_DEFINED} == pattern",

		"NOTE: filename.mk:6: IN_SCOPE_DEFINED can be "+
			"compared using the simpler \"${IN_SCOPE_DEFINED} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:6: Replacing \"${IN_SCOPE_DEFINED:Mpattern}\" "+
			"with \"${IN_SCOPE_DEFINED} == pattern\".")

	t.testBeforeAndAfterPrefs(
		".if ${IN_SCOPE:Mpattern}",
		".if ${IN_SCOPE:U} == pattern",

		"NOTE: filename.mk:6: IN_SCOPE can be "+
			"compared using the simpler \"${IN_SCOPE:U} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:6: Replacing \"${IN_SCOPE:Mpattern}\" "+
			"with \"${IN_SCOPE:U} == pattern\".")

	// Even though PREFS_DEFINED is declared as DefinedIfInScope,
	// it is not in scope yet. Therefore it needs the :U modifier.
	// The warning that this variable is not yet in scope comes from
	// a different part of pkglint.
	t.testBeforePrefs(
		".if ${PREFS_DEFINED:Mpattern}",
		".if ${PREFS_DEFINED:U} == pattern",

		"NOTE: filename.mk:6: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED:U} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"WARN: filename.mk:6: To use PREFS_DEFINED at load time, "+
			".include \"../../mk/bsd.prefs.mk\" first.",
		"AUTOFIX: filename.mk:6: Replacing \"${PREFS_DEFINED:Mpattern}\" "+
			"with \"${PREFS_DEFINED:U} == pattern\".")

	t.testAfterPrefs(
		".if ${PREFS_DEFINED:Mpattern}",
		".if ${PREFS_DEFINED} == pattern",

		"NOTE: filename.mk:6: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:6: Replacing \"${PREFS_DEFINED:Mpattern}\" "+
			"with \"${PREFS_DEFINED} == pattern\".")

	t.testBeforePrefs(
		".if ${PREFS:Mpattern}",
		".if ${PREFS:U} == pattern",

		"NOTE: filename.mk:6: PREFS can be "+
			"compared using the simpler \"${PREFS:U} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"WARN: filename.mk:6: To use PREFS at load time, "+
			".include \"../../mk/bsd.prefs.mk\" first.",
		"AUTOFIX: filename.mk:6: Replacing \"${PREFS:Mpattern}\" "+
			"with \"${PREFS:U} == pattern\".")

	// Preferences that may be undefined always need the :U modifier,
	// even when they are in scope.
	t.testAfterPrefs(
		".if ${PREFS:Mpattern}",
		".if ${PREFS:U} == pattern",

		"NOTE: filename.mk:6: PREFS can be "+
			"compared using the simpler \"${PREFS:U} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:6: Replacing \"${PREFS:Mpattern}\" "+
			"with \"${PREFS:U} == pattern\".")

	// Variables that are defined later always need the :U modifier.
	// It is probably a mistake to use them in conditions at all.
	t.testBeforeAndAfterPrefs(
		".if ${LATER_DEFINED:Mpattern}",
		".if ${LATER_DEFINED:U} == pattern",

		"NOTE: filename.mk:6: LATER_DEFINED can be "+
			"compared using the simpler \"${LATER_DEFINED:U} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"WARN: filename.mk:6: "+
			"LATER_DEFINED should not be used at load time in any file.",
		"AUTOFIX: filename.mk:6: Replacing \"${LATER_DEFINED:Mpattern}\" "+
			"with \"${LATER_DEFINED:U} == pattern\".")

	// Variables that are defined later always need the :U modifier.
	// It is probably a mistake to use them in conditions at all.
	t.testBeforeAndAfterPrefs(
		".if ${LATER:Mpattern}",
		".if ${LATER:U} == pattern",

		"NOTE: filename.mk:6: LATER can be "+
			"compared using the simpler \"${LATER:U} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"WARN: filename.mk:6: "+
			"LATER should not be used at load time in any file.",
		"AUTOFIX: filename.mk:6: Replacing \"${LATER:Mpattern}\" "+
			"with \"${LATER:U} == pattern\".")

	t.testBeforeAndAfterPrefs(
		".if ${UNDEFINED:Mpattern}",
		".if ${UNDEFINED:Mpattern}",

		"WARN: filename.mk:6: UNDEFINED is used but not defined.")

	// When the pattern contains placeholders, it cannot be converted to == or !=.
	t.testAfterPrefs(
		".if ${PREFS_DEFINED:Mpa*n}",
		".if ${PREFS_DEFINED:Mpa*n}",

		nil...)

	// When deciding whether to replace the expression, only the
	// last modifier is inspected. All the others are copied.
	t.testAfterPrefs(
		".if ${PREFS_DEFINED:tl:Mpattern}",
		".if ${PREFS_DEFINED:tl} == pattern",

		"NOTE: filename.mk:6: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED:tl} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:6: Replacing \"${PREFS_DEFINED:tl:Mpattern}\" "+
			"with \"${PREFS_DEFINED:tl} == pattern\".")

	// Negated pattern matches are supported as well,
	// as long as the variable is guaranteed to be nonempty.
	// TODO: Actually implement this.
	//  As of December 2019, IsNonemptyIfDefined is not used anywhere.
	t.testAfterPrefs(
		".if ${PREFS_DEFINED:Npattern}",
		".if ${PREFS_DEFINED} != pattern",

		"NOTE: filename.mk:6: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} != pattern\" "+
			"instead of matching against \":Npattern\".",
		"AUTOFIX: filename.mk:6: Replacing \"${PREFS_DEFINED:Npattern}\" "+
			"with \"${PREFS_DEFINED} != pattern\".")

	// ${PREFS_DEFINED:None:Ntwo} is a short variant of
	// ${PREFS_DEFINED} != "one" && ${PREFS_DEFINED} != "two".
	// Applying the transformation would make the condition longer
	// than before, therefore nothing can be simplified here,
	// even though all patterns are exact matches.
	t.testAfterPrefs(
		".if ${PREFS_DEFINED:None:Ntwo}",
		".if ${PREFS_DEFINED:None:Ntwo}",

		nil...)

	// Note: this combination doesn't make sense since the patterns
	// "one" and "two" don't overlap.
	// Nevertheless it is possible and valid to simplify the condition.
	t.testAfterPrefs(
		".if ${PREFS_DEFINED:Mone:Mtwo}",
		".if ${PREFS_DEFINED:Mone} == two",

		"NOTE: filename.mk:6: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED:Mone} == two\" "+
			"instead of matching against \":Mtwo\".",
		"AUTOFIX: filename.mk:6: Replacing \"${PREFS_DEFINED:Mone:Mtwo}\" "+
			"with \"${PREFS_DEFINED:Mone} == two\".")

	// There is no ! before the empty, which is easy to miss.
	// Because of this missing negation, the comparison operator is !=.
	t.testAfterPrefs(
		".if empty(PREFS_DEFINED:Mpattern)",
		".if ${PREFS_DEFINED} != pattern",

		"NOTE: filename.mk:6: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} != pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:6: Replacing \"empty(PREFS_DEFINED:Mpattern)\" "+
			"with \"${PREFS_DEFINED} != pattern\".")

	t.testAfterPrefs(
		".if !!empty(PREFS_DEFINED:Mpattern)",
		// TODO: The ! and == could be combined into a !=.
		//  Luckily the !! pattern doesn't occur in practice.
		".if !${PREFS_DEFINED} == pattern",

		// TODO: When taking all the ! into account, this is actually a
		//  test for emptiness, therefore the diagnostics should suggest
		//  the != operator instead of ==.
		"NOTE: filename.mk:6: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:6: Replacing \"!empty(PREFS_DEFINED:Mpattern)\" "+
			"with \"${PREFS_DEFINED} == pattern\".")

	// Simplifying the condition also works in complex expressions.
	t.testAfterPrefs(".if empty(PREFS_DEFINED:Mpattern) || 0",
		".if ${PREFS_DEFINED} != pattern || 0",

		"NOTE: filename.mk:6: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} != pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:6: Replacing \"empty(PREFS_DEFINED:Mpattern)\" "+
			"with \"${PREFS_DEFINED} != pattern\".")

	// No note in this case since there is no implicit !empty around the varUse.
	// There is no obvious way of writing this expression in a simpler form.
	t.testAfterPrefs(
		".if ${PREFS_DEFINED:Mpattern} != ${OTHER}",
		".if ${PREFS_DEFINED:Mpattern} != ${OTHER}",

		"WARN: filename.mk:6: OTHER is used but not defined.")

	// The condition is also simplified if it doesn't use the !empty
	// form but the implicit conversion to boolean.
	t.testAfterPrefs(
		".if ${PREFS_DEFINED:Mpattern}",
		".if ${PREFS_DEFINED} == pattern",

		"NOTE: filename.mk:6: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:6: Replacing \"${PREFS_DEFINED:Mpattern}\" "+
			"with \"${PREFS_DEFINED} == pattern\".")

	// A single negation outside the implicit conversion is taken into
	// account when simplifying the condition.
	t.testAfterPrefs(
		".if !${PREFS_DEFINED:Mpattern}",
		".if ${PREFS_DEFINED} != pattern",

		"NOTE: filename.mk:6: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} != pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:6: Replacing \"!${PREFS_DEFINED:Mpattern}\" "+
			"with \"${PREFS_DEFINED} != pattern\".")

	// TODO: Merge the double negation into the comparison operator.
	t.testAfterPrefs(
		".if !!${PREFS_DEFINED:Mpattern}",
		".if !${PREFS_DEFINED} != pattern",

		"NOTE: filename.mk:6: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} != pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:6: Replacing \"!${PREFS_DEFINED:Mpattern}\" "+
			"with \"${PREFS_DEFINED} != pattern\".")

	// This pattern with spaces doesn't make sense at all in the :M
	// modifier since it can never match.
	// Or can it, if the PKGPATH contains quotes?
	// TODO: How exactly does bmake apply the matching here,
	//  are both values unquoted first? Probably not, but who knows.
	t.testBeforeAndAfterPrefs(
		".if ${IN_SCOPE_DEFINED:Mpattern with spaces}",
		".if ${IN_SCOPE_DEFINED:Mpattern with spaces}",

		nil...)
	// TODO: ".if ${PKGPATH} == \"pattern with spaces\"")

	t.testBeforeAndAfterPrefs(
		".if ${IN_SCOPE_DEFINED:M'pattern with spaces'}",
		".if ${IN_SCOPE_DEFINED:M'pattern with spaces'}",

		nil...)
	// TODO: ".if ${PKGPATH} == 'pattern with spaces'")

	t.testBeforeAndAfterPrefs(
		".if ${IN_SCOPE_DEFINED:M&&}",
		".if ${IN_SCOPE_DEFINED:M&&}",

		nil...)
	// TODO: ".if ${PKGPATH} == '&&'")

	// The :N modifier involves another negation and is therefore more
	// difficult to understand. That's even more reason to use the
	// well-known == and != comparison operators instead.
	//
	// If PKGPATH is "", the condition is false.
	// If PKGPATH is "negative-pattern", the condition is false.
	// In all other cases, the condition is true.
	//
	// Therefore this condition cannot simply be transformed into
	// ${PKGPATH} != negative-pattern, since that would produce a
	// different result in the case where PKGPATH is empty.
	//
	// For system-provided variables that are guaranteed to be non-empty,
	// such as OPSYS or PKGPATH, this replacement is valid.
	// These variables are only guaranteed to be defined after bsd.prefs.mk
	// has been included, like everywhere else.
	//
	// TODO: This is where NonemptyIfDefined comes into play.
	t.testAfterPrefs(
		".if ${PREFS_DEFINED:Nnegative-pattern}",
		".if ${PREFS_DEFINED} != negative-pattern",

		"NOTE: filename.mk:6: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} != negative-pattern\" "+
			"instead of matching against \":Nnegative-pattern\".",
		"AUTOFIX: filename.mk:6: Replacing \"${PREFS_DEFINED:Nnegative-pattern}\" "+
			"with \"${PREFS_DEFINED} != negative-pattern\".")

	// Since UNDEFINED is not a well-known variable that is
	// guaranteed to be non-empty (see the previous example), it is not
	// transformed at all.
	t.testBeforePrefs(
		".if ${UNDEFINED:Nnegative-pattern}",
		".if ${UNDEFINED:Nnegative-pattern}",

		"WARN: filename.mk:6: UNDEFINED is used but not defined.")

	t.testAfterPrefs(
		".if ${UNDEFINED:Nnegative-pattern}",
		".if ${UNDEFINED:Nnegative-pattern}",

		"WARN: filename.mk:6: UNDEFINED is used but not defined.")

	// A complex condition may contain several simple conditions
	// that are each simplified independently, in the same go.
	t.testAfterPrefs(
		".if ${PREFS_DEFINED:Mpath1} || ${PREFS_DEFINED:Mpath2}",
		".if ${PREFS_DEFINED} == path1 || ${PREFS_DEFINED} == path2",

		"NOTE: filename.mk:6: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} == path1\" "+
			"instead of matching against \":Mpath1\".",
		"NOTE: filename.mk:6: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} == path2\" "+
			"instead of matching against \":Mpath2\".",
		"AUTOFIX: filename.mk:6: Replacing \"${PREFS_DEFINED:Mpath1}\" "+
			"with \"${PREFS_DEFINED} == path1\".",
		"AUTOFIX: filename.mk:6: Replacing \"${PREFS_DEFINED:Mpath2}\" "+
			"with \"${PREFS_DEFINED} == path2\".")

	// Removing redundant parentheses may be useful one day but is
	// not urgent.
	// Simplifying the inner expression keeps all parentheses as-is.
	t.testAfterPrefs(
		".if (((((${PREFS_DEFINED:Mpath})))))",
		".if (((((${PREFS_DEFINED} == path)))))",

		"NOTE: filename.mk:6: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} == path\" "+
			"instead of matching against \":Mpath\".",
		"AUTOFIX: filename.mk:6: Replacing \"${PREFS_DEFINED:Mpath}\" "+
			"with \"${PREFS_DEFINED} == path\".")

	// Several modifiers like :S and :C may change the variable value.
	// Whether the condition can be simplified or not only depends on the
	// last modifier in the chain.
	t.testAfterPrefs(
		".if !empty(PREFS_DEFINED:S,NetBSD,ok,:Mok)",
		".if ${PREFS_DEFINED:S,NetBSD,ok,} == ok",

		"NOTE: filename.mk:6: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED:S,NetBSD,ok,} == ok\" "+
			"instead of matching against \":Mok\".",
		"AUTOFIX: filename.mk:6: Replacing \"!empty(PREFS_DEFINED:S,NetBSD,ok,:Mok)\" "+
			"with \"${PREFS_DEFINED:S,NetBSD,ok,} == ok\".")

	t.testAfterPrefs(
		".if empty(PREFS_DEFINED:tl:Msunos)",
		".if ${PREFS_DEFINED:tl} != sunos",

		"NOTE: filename.mk:6: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED:tl} != sunos\" "+
			"instead of matching against \":Msunos\".",
		"AUTOFIX: filename.mk:6: Replacing \"empty(PREFS_DEFINED:tl:Msunos)\" "+
			"with \"${PREFS_DEFINED:tl} != sunos\".")

	// The condition can only be simplified if the :M or :N modifier
	// appears at the end of the chain.
	t.testAfterPrefs(
		".if !empty(PREFS_DEFINED:O:MUnknown:S,a,b,)",
		".if !empty(PREFS_DEFINED:O:MUnknown:S,a,b,)",

		nil...)

	// The dot is just an ordinary character in a pattern.
	// In comparisons, an unquoted 1.2 is interpreted as a number though.
	t.testAfterPrefs(
		".if !empty(PREFS_DEFINED:Mpackage1.2)",
		".if ${PREFS_DEFINED} == package1.2",

		"NOTE: filename.mk:6: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} == package1.2\" "+
			"instead of matching against \":Mpackage1.2\".",
		"AUTOFIX: filename.mk:6: Replacing \"!empty(PREFS_DEFINED:Mpackage1.2)\" "+
			"with \"${PREFS_DEFINED} == package1.2\".")

	// Numbers must be enclosed in quotes, otherwise they are compared
	// as numbers, not as strings.
	// The :M and :N modifiers always compare strings.
	t.testAfterPrefs(
		".if empty(PREFS:U:M64)",
		".if ${PREFS:U} != \"64\"",

		"NOTE: filename.mk:6: PREFS can be "+
			"compared using the simpler \"${PREFS:U} != \"64\"\" "+
			"instead of matching against \":M64\".",
		"AUTOFIX: filename.mk:6: Replacing \"empty(PREFS:U:M64)\" "+
			"with \"${PREFS:U} != \\\"64\\\"\".")

	// Fractional numbers must also be enclosed in quotes.
	t.testAfterPrefs(
		".if empty(PREFS:U:M19.12)",
		".if ${PREFS:U} != \"19.12\"",

		"NOTE: filename.mk:6: PREFS can be "+
			"compared using the simpler \"${PREFS:U} != \"19.12\"\" "+
			"instead of matching against \":M19.12\".",
		"AUTOFIX: filename.mk:6: Replacing \"empty(PREFS:U:M19.12)\" "+
			"with \"${PREFS:U} != \\\"19.12\\\"\".")

	t.testAfterPrefs(
		".if !empty(LATER:Npattern)",
		".if !empty(LATER:Npattern)",

		// No diagnostics about the :N modifier yet,
		// see MkCondChecker.simplify.replace.
		"WARN: filename.mk:6: LATER should not be used "+
			"at load time in any file.")

	// TODO: Add a note that the :U is unnecessary, and explain why.
	t.testAfterPrefs(
		".if ${PREFS_DEFINED:U:Mpattern}",
		".if ${PREFS_DEFINED:U} == pattern",

		"NOTE: filename.mk:6: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED:U} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:6: "+
			"Replacing \"${PREFS_DEFINED:U:Mpattern}\" "+
			"with \"${PREFS_DEFINED:U} == pattern\".")

	// Conditions without any modifiers cannot be simplified
	// and are therefore skipped.
	t.testBeforeAndAfterPrefs(
		".if ${IN_SCOPE_DEFINED}",
		".if ${IN_SCOPE_DEFINED}",

		nil...)

	// Special characters must be enclosed in quotes when they are
	// used in string literals.
	// As of December 2019, strings with special characters are not yet
	// replaced automatically, see mkCondLiteralChars.
	// TODO: Add tests for all characters that are special in string literals or patterns.
	// TODO: Then, extend the set of characters for which the expressions are simplified.
	t.testBeforePrefs(
		".if ${PREFS_DEFINED:M&&}",
		".if ${PREFS_DEFINED:M&&}",

		"WARN: filename.mk:6: To use PREFS_DEFINED at load time, .include \"../../mk/bsd.prefs.mk\" first.")
	t.testAfterPrefs(
		".if ${PREFS_DEFINED:M&&}",
		".if ${PREFS_DEFINED:M&&}",

		nil...)

	t.testBeforePrefs(
		".if ${PREFS:M&&}",
		".if ${PREFS:M&&}",

		// TODO: Warn that the :U is missing.
		"WARN: filename.mk:6: To use PREFS at load time, .include \"../../mk/bsd.prefs.mk\" first.")
	t.testAfterPrefs(
		".if ${PREFS:M&&}",
		".if ${PREFS:M&&}",

		// TODO: Warn that the :U is missing.
		nil...)

	// The + is contained in both mkCondStringLiteralUnquoted and
	// mkCondModifierPatternLiteral, therefore it is copied verbatim.
	t.testAfterPrefs(
		".if ${PREFS_DEFINED:Mcategory/gtk+}",
		".if ${PREFS_DEFINED} == category/gtk+",

		"NOTE: filename.mk:6: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} == category/gtk+\" "+
			"instead of matching against \":Mcategory/gtk+\".",
		"AUTOFIX: filename.mk:6: "+
			"Replacing \"${PREFS_DEFINED:Mcategory/gtk+}\" "+
			"with \"${PREFS_DEFINED} == category/gtk+\".")

	// The characters <=> may be used unescaped in :M and :N patterns
	// but not in .if conditions. There they must be enclosed in quotes.
	t.testBeforePrefs(
		".if ${PREFS_DEFINED:M<=>}",
		".if ${PREFS_DEFINED:U} == \"<=>\"",

		"NOTE: filename.mk:6: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED:U} == \"<=>\"\" "+
			"instead of matching against \":M<=>\".",
		"WARN: filename.mk:6: To use PREFS_DEFINED at load time, "+
			".include \"../../mk/bsd.prefs.mk\" first.",
		"AUTOFIX: filename.mk:6: "+
			"Replacing \"${PREFS_DEFINED:M<=>}\" "+
			"with \"${PREFS_DEFINED:U} == \\\"<=>\\\"\".")
	t.testAfterPrefs(
		".if ${PREFS_DEFINED:M<=>}",
		".if ${PREFS_DEFINED} == \"<=>\"",

		"NOTE: filename.mk:6: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} == \"<=>\"\" "+
			"instead of matching against \":M<=>\".",
		"AUTOFIX: filename.mk:6: "+
			"Replacing \"${PREFS_DEFINED:M<=>}\" "+
			"with \"${PREFS_DEFINED} == \\\"<=>\\\"\".")

	// If pkglint replaces this particular pattern, the resulting string
	// literal must be escaped properly.
	t.testBeforeAndAfterPrefs(
		".if ${IN_SCOPE_DEFINED:M\"}",
		".if ${IN_SCOPE_DEFINED:M\"}",

		nil...)

	t.testBeforeAndAfterPrefs(
		".if !empty(IN_SCOPE_DEFINED:M)",
		".if ${IN_SCOPE_DEFINED} == \"\"",

		"NOTE: filename.mk:6: IN_SCOPE_DEFINED can be "+
			"compared using the simpler "+"\"${IN_SCOPE_DEFINED} == \"\"\" "+
			"instead of matching against \":M\".",
		"AUTOFIX: filename.mk:6: "+
			"Replacing \"!empty(IN_SCOPE_DEFINED:M)\" "+
			"with \"${IN_SCOPE_DEFINED} == \\\"\\\"\".",
	)
}

func (s *Suite) Test_MkCondSimplifier_simplifyWord__defined_in_same_file(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.Chdir("category/package")
	t.FinishSetUp()

	doTest := func(before string) {
		mklines := t.SetUpFileMkLines("filename.mk",
			MkCvsID,
			"OK=\t\tok",
			"OK_DIR=\t\tok", // See Pkgsrc.guessVariableType.
			before,
			"LATER=\t\tlater",
			"LATER_DIR=\tlater", // See Pkgsrc.guessVariableType.
			".endif",
			"USED=\t\t${OK} ${LATER} ${OK_DIR} ${LATER_DIR} ${USED}")

		// The high-level call MkLines.Check is used here to
		// get MkLines.Tools.SeenPrefs correct, which decides
		// whether the :U modifier is necessary.
		mklines.Check()
	}

	// before: the directive before the condition is simplified
	// after: the directive after the condition is simplified
	test := func(before, after string, diagnostics ...string) {

		t.ExpectDiagnosticsAutofix(
			func(bool) { doTest(before) },
			diagnostics...)

		// TODO: Move this assertion above the assertion about the diagnostics.
		afterMklines := LoadMk(t.File("filename.mk"), nil, MustSucceed)
		t.CheckEquals(afterMklines.mklines[3].Text, after)
	}

	// For variables with completely unknown names, the type is nil
	// and the complete check is skipped.
	test(
		".if ${OK:Mpattern}",
		".if ${OK:Mpattern}",

		nil...)

	// For variables with completely unknown names, the type is nil
	// and the complete check is skipped.
	test(
		".if ${LATER:Mpattern}",
		".if ${LATER:Mpattern}",

		nil...)

	// OK_DIR is defined earlier than the .if condition,
	// which is the correct order.
	test(
		".if ${OK_DIR:Mpattern}",
		".if ${OK_DIR} == pattern",

		"NOTE: filename.mk:4: OK_DIR can be "+
			"compared using the simpler \"${OK_DIR} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:4: "+
			"Replacing \"${OK_DIR:Mpattern}\" "+
			"with \"${OK_DIR} == pattern\".")

	// LATER_DIR is defined later than the .if condition,
	// therefore at the time of the .if statement, it is still empty.
	test(
		".if ${LATER_DIR:Mpattern}",
		".if ${LATER_DIR:U} == pattern",

		// TODO: Warn that LATER_DIR is used before it is defined.
		"NOTE: filename.mk:4: LATER_DIR can be "+
			"compared using the simpler \"${LATER_DIR:U} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:4: "+
			"Replacing \"${LATER_DIR:Mpattern}\" "+
			"with \"${LATER_DIR:U} == pattern\".")
}

func (s *Suite) Test_MkCondSimplifier_simplifyMatch(c *check.C) {
	t := MkCondSimplifierTester{c, s.Init(c)}

	t.setUp()

	t.testBeforeAndAfterPrefs(
		".if !empty(IN_SCOPE_DEFINED:M*.c)",
		".if ${IN_SCOPE_DEFINED:M*.c}",

		"NOTE: filename.mk:6: \"!empty(IN_SCOPE_DEFINED:M*.c)\" "+
			"can be simplified to \"${IN_SCOPE_DEFINED:M*.c}\".",
		"AUTOFIX: filename.mk:6: "+
			"Replacing \"!empty(IN_SCOPE_DEFINED:M*.c)\" "+
			"with \"${IN_SCOPE_DEFINED:M*.c}\".")

	t.testBeforeAndAfterPrefs(
		".if empty(IN_SCOPE_DEFINED:M*.c)",
		".if !${IN_SCOPE_DEFINED:M*.c}",

		"NOTE: filename.mk:6: \"empty(IN_SCOPE_DEFINED:M*.c)\" "+
			"can be simplified to \"!${IN_SCOPE_DEFINED:M*.c}\".",
		"AUTOFIX: filename.mk:6: "+
			"Replacing \"empty(IN_SCOPE_DEFINED:M*.c)\" "+
			"with \"!${IN_SCOPE_DEFINED:M*.c}\".")

	t.testBeforeAndAfterPrefs(
		".if !empty(IN_SCOPE_DEFINED:M[Nn][Oo])",
		".if ${IN_SCOPE_DEFINED:M[Nn][Oo]}",

		"NOTE: filename.mk:6: \"!empty(IN_SCOPE_DEFINED:M[Nn][Oo])\" "+
			"can be simplified to \"${IN_SCOPE_DEFINED:M[Nn][Oo]}\".",
		"AUTOFIX: filename.mk:6: "+
			"Replacing \"!empty(IN_SCOPE_DEFINED:M[Nn][Oo])\" "+
			"with \"${IN_SCOPE_DEFINED:M[Nn][Oo]}\".")
}

func (s *Suite) Test_MkCondSimplifier_isDefined(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"DEFINED=\tyes",
		".if defined(UNDEFINED) && defined(DEFINED)",
		".endif")
	// Initialize whether the variables are defined.
	mklines.Check()

	mklines.ForEach(func(mkline *MkLine) {
		if mkline.IsDirective() && mkline.Directive() == "if" {
			mcs := MkCondSimplifier{mklines, mkline}
			vartype := NewVartype(BtMessage, 0, nil...)

			t.AssertEquals(false, mcs.isDefined("UNDEFINED", vartype))
			t.AssertEquals(true, mcs.isDefined("DEFINED", vartype))
		}
	})
	t.CheckOutputLines(
		"WARN: filename.mk:3: UNDEFINED is used but not defined.")
}
