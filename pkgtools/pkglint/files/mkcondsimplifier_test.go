package pkglint

import (
	"gopkg.in/check.v1"
	"netbsd.org/pkglint/regex"
)

type MkCondSimplifierTester struct {
	c *check.C
	*Tester
	allowedVariableNames regex.Pattern
}

func NewMkCondSimplifierTester(c *check.C, s *Suite) *MkCondSimplifierTester {
	return &MkCondSimplifierTester{
		c,
		s.Init(c),
		`IN_SCOPE|PREFS|LATER|UNDEFINED`,
	}
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

	// TODO: Test list variables; they differ in that a ':M' modifier
	//  cannot be replaced with '==', as the variable may contain
	//  multiple words.

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
	if !matches(before, t.allowedVariableNames) {
		// Prevent typos in the variable names used in the test.
		t.c.Errorf("Condition %q must include one of the variable names %q.",
			before, t.allowedVariableNames)
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
	t := NewMkCondSimplifierTester(c, s)

	t.setUp()

	t.testBeforeAndAfterPrefs(
		".if ${IN_SCOPE_DEFINED:Mpattern}",
		".if ${IN_SCOPE_DEFINED} == pattern",

		"NOTE: filename.mk:6: IN_SCOPE_DEFINED can be "+
			"compared using the simpler \"${IN_SCOPE_DEFINED} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:6: Replacing \"${IN_SCOPE_DEFINED:Mpattern}\" "+
			"with \"${IN_SCOPE_DEFINED} == pattern\".")

	// From simplifyYesNo.
	t.testBeforeAndAfterPrefs(
		".if !empty(IN_SCOPE_DEFINED:M[Nn][Oo])",
		".if ${IN_SCOPE_DEFINED:tl} == no",

		"NOTE: filename.mk:6: \"!empty(IN_SCOPE_DEFINED:M[Nn][Oo])\" "+
			"can be simplified to \"${IN_SCOPE_DEFINED:tl} == no\".",
		"AUTOFIX: filename.mk:6: "+
			"Replacing \"!empty(IN_SCOPE_DEFINED:M[Nn][Oo])\" "+
			"with \"${IN_SCOPE_DEFINED:tl} == no\".")
}

// Show in which cases the ':U' modifier is needed, and how including
// bsd.prefs.mk influences the resulting conditions.
//
// The ':U' modifier can be omitted if the variable is guaranteed to be
// defined.
func (s *Suite) Test_MkCondSimplifier_simplifyWord__undefined(c *check.C) {
	t := NewMkCondSimplifierTester(c, s)

	// Define the variables that are used in the below tests.
	t.setUp()

	// The variable is guaranteed to be defined,
	// therefore no ':U' modifier is needed.
	t.testBeforeAndAfterPrefs(
		".if ${IN_SCOPE_DEFINED:Mpattern}",
		".if ${IN_SCOPE_DEFINED} == pattern",

		"NOTE: filename.mk:6: IN_SCOPE_DEFINED can be "+
			"compared using the simpler \"${IN_SCOPE_DEFINED} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:6: Replacing \"${IN_SCOPE_DEFINED:Mpattern}\" "+
			"with \"${IN_SCOPE_DEFINED} == pattern\".")

	// The variable may be undefined,
	// therefore the ':U' modifier is needed.
	t.testBeforeAndAfterPrefs(
		".if ${IN_SCOPE:Mpattern}",
		".if ${IN_SCOPE:U} == pattern",

		"NOTE: filename.mk:6: IN_SCOPE can be "+
			"compared using the simpler \"${IN_SCOPE:U} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:6: Replacing \"${IN_SCOPE:Mpattern}\" "+
			"with \"${IN_SCOPE:U} == pattern\".")

	// Even though PREFS_DEFINED is declared as DefinedIfInScope,
	// it is not yet in scope, due to the "BeforePrefs".
	// Therefore, the ':U' modifier is needed.
	// The warning about "at load time" comes from a different part of
	// pkglint.
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

	// Now that bsd.prefs.mk has been included ("AfterPrefs"),
	// the ':U' modifier is not needed anymore.
	t.testAfterPrefs(
		".if ${PREFS_DEFINED:Mpattern}",
		".if ${PREFS_DEFINED} == pattern",

		"NOTE: filename.mk:6: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:6: Replacing \"${PREFS_DEFINED:Mpattern}\" "+
			"with \"${PREFS_DEFINED} == pattern\".")

	// The 'PREFS' variable is probably undefined before bsd.prefs.mk,
	// and after bsd.prefs.mk it _may_ be defined.
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

	// Preferences that may be undefined always need the ':U' modifier,
	// even when they are in scope.
	t.testAfterPrefs(
		".if ${PREFS:Mpattern}",
		".if ${PREFS:U} == pattern",

		"NOTE: filename.mk:6: PREFS can be "+
			"compared using the simpler \"${PREFS:U} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:6: Replacing \"${PREFS:Mpattern}\" "+
			"with \"${PREFS:U} == pattern\".")

	// The variable is declared as being defined later (bsd.pkg.mk),
	// but that point is not yet reached.
	// Therefore, the ':U' modifier is needed,
	// even if the variable is guaranteed to be defined later.
	// It is probably a mistake to use it in conditions at all.
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

	// The variable is declared as being defined later (bsd.pkg.mk),
	// but that point is not yet reached.
	// Therefore, the ':U' modifier is needed.
	// It is probably a mistake to use it in conditions at all.
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

	// The variable is neither defined nor known.
	// Since the replacement only works for single-word variables
	// but not for lists, leave the condition as-is.
	t.testBeforeAndAfterPrefs(
		".if ${UNDEFINED:Mpattern}",
		".if ${UNDEFINED:Mpattern}",

		"WARN: filename.mk:6: UNDEFINED is used but not defined.")
}

// Show how different kinds of ':M'-style patterns are replaced with simpler
// comparisons.
func (s *Suite) Test_MkCondSimplifier_simplifyWord__patterns(c *check.C) {
	t := NewMkCondSimplifierTester(c, s)

	// Define the variables that are used in the below tests.
	t.setUp()

	// When the pattern contains placeholders such as '*',
	// it cannot be converted to == or !=.
	t.testAfterPrefs(
		".if ${PREFS_DEFINED:Mpa*n}",
		".if ${PREFS_DEFINED:Mpa*n}",

		nil...)

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

	// Numbers must be enclosed in quotes, otherwise they are compared
	// as numbers, not as strings.
	// The :M and :N modifiers always compare strings.
	t.testAfterPrefs(
		".if empty(PREFS_DEFINED:M64)",
		".if ${PREFS_DEFINED} != \"64\"",

		"NOTE: filename.mk:6: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} != \"64\"\" "+
			"instead of matching against \":M64\".",
		"AUTOFIX: filename.mk:6: Replacing \"empty(PREFS_DEFINED:M64)\" "+
			"with \"${PREFS_DEFINED} != \\\"64\\\"\".")

	// Fractional numbers must also be enclosed in quotes.
	t.testAfterPrefs(
		".if empty(PREFS_DEFINED:M19.12)",
		".if ${PREFS_DEFINED} != \"19.12\"",

		"NOTE: filename.mk:6: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} != \"19.12\"\" "+
			"instead of matching against \":M19.12\".",
		"AUTOFIX: filename.mk:6: Replacing \"empty(PREFS_DEFINED:M19.12)\" "+
			"with \"${PREFS_DEFINED} != \\\"19.12\\\"\".")

	// The quotes are only needed if the whole pattern is a number,
	// not if the number is surrounded by other text.
	// The dot is just an ordinary character in a pattern.
	t.testAfterPrefs(
		".if !empty(PREFS_DEFINED:Mpackage1.2)",
		".if ${PREFS_DEFINED} == package1.2",

		"NOTE: filename.mk:6: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} == package1.2\" "+
			"instead of matching against \":Mpackage1.2\".",
		"AUTOFIX: filename.mk:6: Replacing \"!empty(PREFS_DEFINED:Mpackage1.2)\" "+
			"with \"${PREFS_DEFINED} == package1.2\".")

	// Special characters must be enclosed in quotes when they are
	// used in string literals.
	// As of December 2019, strings with special characters are not yet
	// replaced automatically, see mkCondLiteralChars.
	// TODO: Add tests for all characters that are special in string literals or patterns.
	// TODO: Then, extend the set of characters for which the expressions are simplified.
	t.testAfterPrefs(
		".if ${PREFS_DEFINED:M&&}",
		".if ${PREFS_DEFINED:M&&}",

		nil...)

	// The '+' is contained in both mkCondStringLiteralUnquoted and
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

	// The characters '<=>' may be used unescaped in ':M' and ':N' patterns
	// but not in '.if' conditions. There, they must be enclosed in quotes.
	t.testAfterPrefs(
		".if ${PREFS_DEFINED:M<=>}",
		".if ${PREFS_DEFINED} == \"<=>\"",

		"NOTE: filename.mk:6: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} == \"<=>\"\" "+
			"instead of matching against \":M<=>\".",
		"AUTOFIX: filename.mk:6: "+
			"Replacing \"${PREFS_DEFINED:M<=>}\" "+
			"with \"${PREFS_DEFINED} == \\\"<=>\\\"\".")

	// When replacing a pattern containing '"', which is unusual,
	// the resulting string literal must be escaped properly.
	t.testBeforeAndAfterPrefs(
		".if ${IN_SCOPE_DEFINED:M\"}",
		".if ${IN_SCOPE_DEFINED:M\"}",

		nil...)

	// Matching for the empty pattern doesn't make sense,
	// as the resulting string is always empty.
	// Nevertheless, pkglint simplifies it.
	// FIXME: This replacement does not preserve the behavior.
	t.testBeforeAndAfterPrefs(
		".if !empty(IN_SCOPE_DEFINED:M)",
		".if ${IN_SCOPE_DEFINED} == \"\"",

		"NOTE: filename.mk:6: IN_SCOPE_DEFINED can be "+
			"compared using the simpler "+"\"${IN_SCOPE_DEFINED} == \"\"\" "+
			"instead of matching against \":M\".",
		"AUTOFIX: filename.mk:6: "+
			"Replacing \"!empty(IN_SCOPE_DEFINED:M)\" "+
			"with \"${IN_SCOPE_DEFINED} == \\\"\\\"\".")
}

// Show in which cases the ':N' modifier is replaced.
// That modifier is used less often than ':M',
// therefore pkglint doesn't do much about it.
func (s *Suite) Test_MkCondSimplifier_simplifyWord__N(c *check.C) {
	t := NewMkCondSimplifierTester(c, s)

	// Define the variables that are used in the below tests.
	t.setUp()

	// Negated pattern matches are supported as well,
	// as long as the variable is guaranteed to be nonempty.
	// TODO: Actually implement the "as long as".
	//  As of December 2019, IsNonemptyIfDefined is not used anywhere,
	//  which means that this replacement wrongly applies in cases where
	//  the variable may be empty.
	t.testAfterPrefs(
		".if ${PREFS_DEFINED:Npattern}",
		".if ${PREFS_DEFINED} != pattern",

		"NOTE: filename.mk:6: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} != pattern\" "+
			"instead of matching against \":Npattern\".",
		"AUTOFIX: filename.mk:6: Replacing \"${PREFS_DEFINED:Npattern}\" "+
			"with \"${PREFS_DEFINED} != pattern\".")

	// There is no '!' before the empty, which is easy to miss.
	// Because there is no '!', the comparison operator is !=.
	t.testAfterPrefs(
		".if empty(PREFS_DEFINED:Mpattern)",
		".if ${PREFS_DEFINED} != pattern",

		"NOTE: filename.mk:6: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} != pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:6: Replacing \"empty(PREFS_DEFINED:Mpattern)\" "+
			"with \"${PREFS_DEFINED} != pattern\".")

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
	t.testBeforeAndAfterPrefs(
		".if ${UNDEFINED:Nnegative-pattern}",
		".if ${UNDEFINED:Nnegative-pattern}",

		"WARN: filename.mk:6: UNDEFINED is used but not defined.")

	t.testAfterPrefs(
		".if !empty(LATER:Npattern)",
		".if !empty(LATER:Npattern)",

		// No diagnostics about the :N modifier yet,
		// see MkCondSimplifier.simplifyWord.replace.
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
}

// Show how the conditions are simplified when the expression contains
// several modifiers.
func (s *Suite) Test_MkCondSimplifier_simplifyWord__modifiers(c *check.C) {
	t := NewMkCondSimplifierTester(c, s)

	// Define the variables that are used in the below tests.
	t.setUp()

	// When deciding whether to replace the expression,
	// only the last modifier is inspected.
	// All the others are copied, as the modifier ':M'
	// does not change whether the expression is defined or not.
	t.testAfterPrefs(
		".if ${PREFS_DEFINED:tl:Mpattern}",
		".if ${PREFS_DEFINED:tl} == pattern",

		"NOTE: filename.mk:6: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED:tl} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:6: Replacing \"${PREFS_DEFINED:tl:Mpattern}\" "+
			"with \"${PREFS_DEFINED:tl} == pattern\".")

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
	// Nevertheless, it is possible and valid to simplify the condition.
	t.testAfterPrefs(
		".if ${PREFS_DEFINED:Mone:Mtwo}",
		".if ${PREFS_DEFINED:Mone} == two",

		"NOTE: filename.mk:6: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED:Mone} == two\" "+
			"instead of matching against \":Mtwo\".",
		"AUTOFIX: filename.mk:6: Replacing \"${PREFS_DEFINED:Mone:Mtwo}\" "+
			"with \"${PREFS_DEFINED:Mone} == two\".")

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
}

// Show how expressions in complex conditions are simplified.
func (s *Suite) Test_MkCondSimplifier_simplifyWord__complex(c *check.C) {
	t := NewMkCondSimplifierTester(c, s)

	// Define the variables that are used in the below tests.
	t.setUp()

	// Conditions without any modifiers cannot be simplified
	// and are therefore skipped.
	t.testBeforeAndAfterPrefs(
		".if ${IN_SCOPE_DEFINED}",
		".if ${IN_SCOPE_DEFINED}",

		nil...)

	// Double negations are not needed in practice,
	// therefore pkglint doesn't care about simplifying them.
	t.testAfterPrefs(
		".if !!empty(PREFS_DEFINED:Mpattern)",
		// The '!' and '==' could be combined into a '!='.
		".if !${PREFS_DEFINED} == pattern",

		// TODO: When taking all the ! into account, this is actually a
		//  test for emptiness, therefore the diagnostics should suggest
		//  '!= pattern' instead of '== pattern'.
		"NOTE: filename.mk:6: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:6: Replacing \"!empty(PREFS_DEFINED:Mpattern)\" "+
			"with \"${PREFS_DEFINED} == pattern\".")

	// Simplifying the condition also works in complex expressions.
	t.testAfterPrefs(
		".if empty(PREFS_DEFINED:Mpattern) || 0",
		".if ${PREFS_DEFINED} != pattern || 0",

		"NOTE: filename.mk:6: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} != pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:6: Replacing \"empty(PREFS_DEFINED:Mpattern)\" "+
			"with \"${PREFS_DEFINED} != pattern\".")

	// If the expression ${VAR:Mpattern} is part of a comparison using the
	// '!=' or '==' operators, there is no implicit '!empty' around the
	// expression.
	// This condition cannot be simplified.
	t.testAfterPrefs(
		".if ${PREFS_DEFINED:Mpattern} != ${OTHER}",
		".if ${PREFS_DEFINED:Mpattern} != ${OTHER}",

		"WARN: filename.mk:6: OTHER is used but not defined.")

	// The condition is also simplified if it doesn't use the '!empty'
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

// Show how patterns like ':M[yY][eE][sS]' are replaced with simpler
// conditions.
func (s *Suite) Test_MkCondSimplifier_simplifyYesNo(c *check.C) {
	t := NewMkCondSimplifierTester(c, s)

	t.setUp()
	t.SetUpVarType("VAR", BtYesNo, AlwaysInScope|DefinedIfInScope,
		"*.mk: use, use-loadtime")
	t.allowedVariableNames = `VAR`

	// The most common pattern for testing YesNo variables lists the
	// lowercase letters before the uppercase letters.
	t.testAfterPrefs(
		".if ${VAR:M[yY][eE][sS]}",
		".if ${VAR:tl} == yes",

		"NOTE: filename.mk:6: "+
			"\"${VAR:M[yY][eE][sS]}\" "+
			"can be simplified to "+
			"\"${VAR:tl} == yes\".",
		"AUTOFIX: filename.mk:6: "+
			"Replacing \"${VAR:M[yY][eE][sS]}\" "+
			"with \"${VAR:tl} == yes\".")

	// The less popular pattern for testing YesNo variables lists the
	// uppercase letters before the lowercase letters.
	t.testAfterPrefs(
		".if ${VAR:M[Yy][Ee][Ss]}",
		".if ${VAR:tl} == yes",

		"NOTE: filename.mk:6: "+
			"\"${VAR:M[Yy][Ee][Ss]}\" "+
			"can be simplified to "+
			"\"${VAR:tl} == yes\".",
		"AUTOFIX: filename.mk:6: "+
			"Replacing \"${VAR:M[Yy][Ee][Ss]}\" "+
			"with \"${VAR:tl} == yes\".")

	// The last letter only has the lowercase form, therefore the pattern
	// does not match the word 'YES'. Therefore, don't replace it with
	// ':tl', as that would match the word 'YES'.
	t.testAfterPrefs(
		".if ${VAR:M[Yy][Ee][s]}",
		".if ${VAR:M[Yy][Ee][s]}",

		"WARN: filename.mk:6: VAR should be matched against "+
			"\"[yY][eE][sS]\" or \"[nN][oO]\", not \"[Yy][Ee][s]\".")
}

func (s *Suite) Test_MkCondSimplifier_simplifyMatch(c *check.C) {
	t := NewMkCondSimplifierTester(c, s)

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

	// From simplifyYesNo.
	t.testBeforeAndAfterPrefs(
		".if !empty(IN_SCOPE_DEFINED:M[Nn][Oo])",
		".if ${IN_SCOPE_DEFINED:tl} == no",

		"NOTE: filename.mk:6: \"!empty(IN_SCOPE_DEFINED:M[Nn][Oo])\" "+
			"can be simplified to \"${IN_SCOPE_DEFINED:tl} == no\".",
		"AUTOFIX: filename.mk:6: "+
			"Replacing \"!empty(IN_SCOPE_DEFINED:M[Nn][Oo])\" "+
			"with \"${IN_SCOPE_DEFINED:tl} == no\".")
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
