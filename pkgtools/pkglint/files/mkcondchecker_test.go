package pkglint

import "gopkg.in/check.v1"

func (s *Suite) Test_NewMkCondChecker(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		MkCvsID)

	ck := NewMkCondChecker(mklines.mklines[0], mklines)

	t.CheckEquals(ck.MkLine.Text, MkCvsID)
	t.CheckEquals(ck.MkLines, mklines)
}

func (s *Suite) Test_MkCondChecker_Check(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.Chdir("category/package")
	t.FinishSetUp()

	test := func(cond string, output ...string) {
		mklines := t.SetUpFileMkLines("filename.mk",
			MkCvsID,
			".include \"../../mk/bsd.fast.prefs.mk\"",
			"",
			cond,
			".endif")
		mklines.Check()
		t.CheckOutput(output)
	}

	test(
		".if !empty(PKGSRC_COMPILER:Mmycc)",
		"WARN: filename.mk:4: The pattern \"mycc\" cannot match any of "+
			"{ ccache ccc clang distcc f2c gcc hp icc ido "+
			"mipspro mipspro-ucode pcc sunpro xlc } for PKGSRC_COMPILER.")

	test(
		".if ${A} != ${B}",
		"WARN: filename.mk:4: A is used but not defined.",
		"WARN: filename.mk:4: B is used but not defined.")

	test(".if ${HOMEPAGE} == \"mailto:someone@example.org\"",
		"WARN: filename.mk:4: \"mailto:someone@example.org\" is not a valid URL.",
		"WARN: filename.mk:4: HOMEPAGE should not be used at load time in any file.")

	test(".if !empty(PKGSRC_RUN_TEST:M[Y][eE][sS])",
		"WARN: filename.mk:4: PKGSRC_RUN_TEST should be matched "+
			"against \"[yY][eE][sS]\" or \"[nN][oO]\", not \"[Y][eE][sS]\".")

	test(".if !empty(IS_BUILTIN.Xfixes:M[yY][eE][sS])")

	test(".if !empty(${IS_BUILTIN.Xfixes:M[yY][eE][sS]})",
		"WARN: filename.mk:4: The empty() function takes a variable name as parameter, "+
			"not a variable expression.")

	test(".if ${PKGSRC_COMPILER} == \"msvc\"",
		"WARN: filename.mk:4: \"msvc\" is not valid for PKGSRC_COMPILER. "+
			"Use one of { ccache ccc clang distcc f2c gcc hp icc ido mipspro mipspro-ucode pcc sunpro xlc } instead.",
		"ERROR: filename.mk:4: Use ${PKGSRC_COMPILER:Mmsvc} instead of the == operator.")

	// PKG_LIBTOOL is only available after including bsd.pkg.mk,
	// therefore the :U and the subsequent warning.
	test(".if ${PKG_LIBTOOL:U:Mlibtool}",
		"NOTE: filename.mk:4: PKG_LIBTOOL can be "+
			"compared using the simpler \"${PKG_LIBTOOL:U} == libtool\" "+
			"instead of matching against \":Mlibtool\".",
		"WARN: filename.mk:4: PKG_LIBTOOL should not be used at load time in any file.")

	test(".if ${MACHINE_PLATFORM:MUnknownOS-*-*} || ${MACHINE_ARCH:Mx86}",
		"WARN: filename.mk:4: "+
			"The pattern \"UnknownOS\" cannot match any of "+
			"{ Cygwin DragonFly FreeBSD Linux NetBSD SunOS "+
			"} for the operating system part of MACHINE_PLATFORM.",
		"WARN: filename.mk:4: "+
			"The pattern \"x86\" cannot match any of "+
			"{ aarch64 aarch64eb alpha amd64 arc arm arm26 arm32 cobalt coldfire convex dreamcast earm "+
			"earmeb earmhf earmhfeb earmv4 earmv4eb earmv5 earmv5eb earmv6 earmv6eb earmv6hf earmv6hfeb "+
			"earmv7 earmv7eb earmv7hf earmv7hfeb evbarm hpcmips hpcsh hppa hppa64 i386 i586 i686 ia64 "+
			"m68000 m68k m88k mips mips64 mips64eb mips64el mipseb mipsel mipsn32 mlrisc ns32k pc532 pmax "+
			"powerpc powerpc64 rs6000 s390 sh3eb sh3el sparc sparc64 vax x86_64 "+
			"} for MACHINE_ARCH.",
		"NOTE: filename.mk:4: MACHINE_ARCH can be "+
			"compared using the simpler \"${MACHINE_ARCH} == x86\" "+
			"instead of matching against \":Mx86\".")

	// Doesn't occur in practice since it is surprising that the ! applies
	// to the comparison operator, and not to one of its arguments.
	test(".if !${VAR} == value",
		"WARN: filename.mk:4: The ! should use parentheses or be merged into the comparison operator.",
		"WARN: filename.mk:4: VAR is used but not defined.")

	// Doesn't occur in practice since this string can never be empty.
	test(".if !\"${VAR}str\"",
		"WARN: filename.mk:4: VAR is used but not defined.")

	// Doesn't occur in practice since !${VAR} && !${VAR2} is more idiomatic.
	test(".if !\"${VAR}${VAR2}\"",
		"WARN: filename.mk:4: VAR is used but not defined.",
		"WARN: filename.mk:4: VAR2 is used but not defined.")

	// Just for code coverage; always evaluates to true.
	test(".if \"string\"",
		nil...)

	// Code coverage for checkVar.
	test(".if ${OPSYS} || ${MACHINE_ARCH}",
		nil...)

	test(".if ${VAR}",
		"WARN: filename.mk:4: VAR is used but not defined.")

	test(".if ${VAR} == 3",
		"WARN: filename.mk:4: VAR is used but not defined.")

	test(".if \"value\" == ${VAR}",
		"WARN: filename.mk:4: VAR is used but not defined.")

	test(".if ${MASTER_SITES:Mftp://*} == \"ftp://netbsd.org/\"",
		// XXX: duplicate diagnostic, see MkParser.MkCond.
		"WARN: filename.mk:4: Invalid variable modifier \"//*\" for \"MASTER_SITES\".",
		"WARN: filename.mk:4: Invalid variable modifier \"//*\" for \"MASTER_SITES\".",
		"WARN: filename.mk:4: \"ftp\" is not a valid URL.",
		"WARN: filename.mk:4: MASTER_SITES should not be used at load time in any file.")
}

func (s *Suite) Test_MkCondChecker_Check__tracing(c *check.C) {
	t := s.Init(c)

	t.EnableTracingToLog()
	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		".if ${VAR:Mpattern1:Mpattern2} == comparison",
		".endif")

	mklines.Check()

	t.CheckOutputLinesMatching(`^WARN|checkCompare`,
		"TRACE: 1 2   checkCompareVarStr ${VAR:Mpattern1:Mpattern2} == comparison",
		"WARN: filename.mk:2: VAR is used but not defined.")
}

func (s *Suite) Test_MkCondChecker_Check__comparison_with_shell_command(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.Chdir(".")
	t.FinishSetUp()
	mklines := t.SetUpFileMkLines("security/openssl/Makefile",
		MkCvsID,
		"",
		".include \"../../mk/bsd.prefs.mk\"",
		"",
		".if ${PKGSRC_COMPILER} == \"gcc\" && ${CC} == \"cc\"",
		".endif")

	mklines.Check()

	// Don't warn about unknown shell command "cc".
	t.CheckOutputLines(
		"ERROR: security/openssl/Makefile:5: Use ${PKGSRC_COMPILER:Mgcc} instead of the == operator.")
}

// The :N modifier filters unwanted values. After this filter, any variable value
// may be compared with the empty string, regardless of the variable type.
// Effectively, the :N modifier changes the type from T to Option(T).
func (s *Suite) Test_MkCondChecker_Check__compare_pattern_with_empty(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.Chdir("category/package")
	t.FinishSetUp()
	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"",
		".include \"../../mk/bsd.fast.prefs.mk\"",
		"",
		".if ${X11BASE:Npattern} == \"\"",
		".endif",
		"",
		".if ${X11BASE:N<>} == \"*\"",
		".endif",
		"",
		".if !(${OPSYS:M*BSD} != \"\")",
		".endif")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: filename.mk:8: The pathname pattern \"<>\" contains the invalid characters \"<>\".",
		"WARN: filename.mk:8: The pathname \"*\" contains the invalid character \"*\".")
}

func (s *Suite) Test_MkCondChecker_Check__comparing_PKGSRC_COMPILER_with_eqeq(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.Chdir("category/package")
	t.FinishSetUp()
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		".include \"../../mk/bsd.prefs.mk\"",
		"",
		".if ${PKGSRC_COMPILER} == \"clang\"",
		".elif ${PKGSRC_COMPILER} != \"gcc\"",
		".endif")

	mklines.Check()

	t.CheckOutputLines(
		"ERROR: Makefile:5: Use ${PKGSRC_COMPILER:Mclang} instead of the == operator.",
		"ERROR: Makefile:6: Use ${PKGSRC_COMPILER:Ngcc} instead of the != operator.")
}

func (s *Suite) Test_MkCondChecker_checkNotEmpty(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	test := func(cond string, diagnostics ...string) {
		mklines := t.NewMkLines("filename.mk",
			".if "+cond)
		mkline := mklines.mklines[0]
		ck := NewMkCondChecker(mkline, mklines)

		ck.checkNotEmpty(mkline.Cond().Not)

		t.CheckOutput(diagnostics)
	}

	test("!empty(VAR)",

		// Only a few variables are suggested to use the simpler form,
		// because of the side-effect when the variable is undefined.
		// VAR is not one of these variables.
		nil...)

	test(
		"!empty(PKG_BUILD_OPTIONS.package:Moption)",

		"NOTE: filename.mk:1: !empty(PKG_BUILD_OPTIONS.package:Moption) "+
			"can be replaced with ${PKG_BUILD_OPTIONS.package:Moption}.")
}

func (s *Suite) Test_MkCondChecker_checkEmpty(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.Chdir("category/package")
	t.FinishSetUp()

	doTest := func(before string) {
		mklines := t.SetUpFileMkLines("filename.mk",
			MkCvsID,
			"",
			before,
			".endif")

		mklines.Check()
	}

	// before: the directive before the condition is simplified
	// after: the directive after the condition is simplified
	// diagnostics: the usual ones
	test := func(before, after string, diagnostics ...string) {

		t.ExpectDiagnosticsAutofix(
			func(bool) { doTest(before) },
			diagnostics...)

		afterMklines := LoadMk(t.File("filename.mk"), nil, MustSucceed)
		t.CheckEquals(afterMklines.mklines[2].Text, after)
	}

	test(
		".if !empty(OPSYS:MUnknown)",
		".if ${OPSYS:U} == Unknown",

		"WARN: filename.mk:3: The pattern \"Unknown\" cannot match any of "+
			"{ Cygwin DragonFly FreeBSD Linux NetBSD SunOS } for OPSYS.",
		"NOTE: filename.mk:3: OPSYS can be "+
			"compared using the simpler \"${OPSYS:U} == Unknown\" "+
			"instead of matching against \":MUnknown\".",
		// TODO: Turn the bsd.prefs.mk warning into an error,
		//  once pkglint is confident enough to get this check right.
		"WARN: filename.mk:3: To use OPSYS at load time, "+
			".include \"../../mk/bsd.prefs.mk\" first.",
		"AUTOFIX: filename.mk:3: Replacing \"!empty(OPSYS:MUnknown)\" "+
			"with \"${OPSYS:U} == Unknown\".")

	// The condition can only be simplified if the :M or :N modifier is
	// the last one on the chain.
	test(
		".if !empty(OPSYS:O:MUnknown:S,a,b,)",
		".if !empty(OPSYS:O:MUnknown:S,a,b,)",

		"WARN: filename.mk:3: The pattern \"Unknown\" cannot match any of "+
			"{ Cygwin DragonFly FreeBSD Linux NetBSD SunOS } for OPSYS.",
		"WARN: filename.mk:3: To use OPSYS at load time, "+
			".include \"../../mk/bsd.prefs.mk\" first.")
}

func (s *Suite) Test_MkCondChecker_checkEmptyExpr(c *check.C) {
	t := s.Init(c)

	test := func(use *MkVarUse, diagnostics ...string) {
		mklines := t.NewMkLines("filename.mk",
			"# dummy")
		ck := NewMkCondChecker(mklines.mklines[0], mklines)

		ck.checkEmptyExpr(use)

		t.CheckOutput(diagnostics)
	}

	// In some cases it makes sense to use indirection in a !empty(...)
	// expression.
	test(
		NewMkVarUse("${PREFIX}"),

		nil...)

	// Typical examples for indirection are .for loops.
	test(
		NewMkVarUse("${var}"),

		nil...)

	// This one is obvious enough for pkglint.
	test(
		NewMkVarUse("${PREFIX:Mpattern}"),

		"WARN: filename.mk:1: The empty() function takes a variable "+
			"name as parameter, not a variable expression.")
}

func (s *Suite) Test_MkCondChecker_checkEmptyType(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.Chdir("category/package")
	t.FinishSetUp()

	test := func(line string, diagnostics ...string) {
		mklines := t.SetUpFileMkLines("filename.mk",
			MkCvsID,
			"",
			line,
			".endif")

		mklines.ForEach(func(mkline *MkLine) {
			ck := NewMkCondChecker(mkline, mklines)
			mkline.ForEachUsed(func(varUse *MkVarUse, time VucTime) {
				ck.checkEmptyType(varUse)
			})
		})

		t.CheckOutput(diagnostics)
	}

	test(".if !empty(OPSYS:Mok)",
		"WARN: filename.mk:3: The pattern \"ok\" cannot match any of "+
			"{ Cygwin DragonFly FreeBSD Linux NetBSD SunOS } for OPSYS.")

	// As of December 2019, pkglint doesn't analyze the :S modifier in
	// depth and therefore simply skips the type check for the :M
	// modifier.
	test(".if !empty(OPSYS:S,NetBSD,ok,:Mok)",
		nil...)
	test(".if !empty(OPSYS:C,NetBSD,ok,:Mok)",
		nil...)

	// Several other modifiers are ok since they don't modify the
	// individual words.
	test(".if !empty(OPSYS:O:u:Mok)",
		"WARN: filename.mk:3: The pattern \"ok\" cannot match any of "+
			"{ Cygwin DragonFly FreeBSD Linux NetBSD SunOS } for OPSYS.")

	// Other modifiers can modify the words themselves. As long as
	// pkglint doesn't actually evaluate these modifiers, suppress
	// any warnings.
	test(".if !empty(OPSYS:E:Mok)",
		nil...)
	test(".if !empty(OPSYS:H:Mok)",
		nil...)
	test(".if !empty(OPSYS:R:Mok)",
		nil...)
	test(".if !empty(OPSYS:tl:Mok)",
		nil...)
	test(".if !empty(OPSYS:tW:Mok)",
		nil...)
	test(".if !empty(OPSYS:tW:Mok)",
		nil...)
}

func (s *Suite) Test_MkCondChecker_simplify(c *check.C) {
	t := s.Init(c)

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

	t.SetUpType("IN_SCOPE_DEFINED", btAnything, AlwaysInScope|DefinedIfInScope,
		"*.mk: use, use-loadtime")
	t.SetUpType("IN_SCOPE", btAnything, AlwaysInScope,
		"*.mk: use, use-loadtime")
	t.SetUpType("PREFS_DEFINED", btAnything, DefinedIfInScope,
		"*.mk: use, use-loadtime")
	t.SetUpType("PREFS", btAnything, NoVartypeOptions,
		"*.mk: use, use-loadtime")
	t.SetUpType("LATER_DEFINED", btAnything, DefinedIfInScope,
		"*.mk: use")
	t.SetUpType("LATER", btAnything, NoVartypeOptions,
		"*.mk: use")
	// UNDEFINED is also used in the following tests, but is obviously
	// not defined here.

	// prefs: whether to include bsd.prefs.mk before
	// before: the directive before the condition is simplified
	// after: the directive after the condition is simplified
	doTest := func(prefs bool, before, after string, diagnostics ...string) {
		if !matches(before, `IN_SCOPE|PREFS|LATER|UNDEFINED`) {
			c.Errorf("Condition %q must include one of the above variable names.", before)
		}
		mklines := t.SetUpFileMkLines("filename.mk",
			MkCvsID,
			condStr(prefs, ".include \"../../mk/bsd.prefs.mk\"", ""),
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
				t.CheckEquals(afterMklines.mklines[2].Text, after)
			}
		}

		t.ExpectDiagnosticsAutofix(action, diagnostics...)
	}

	testBeforePrefs := func(before, after string, diagnostics ...string) {
		doTest(false, before, after, diagnostics...)
	}
	testAfterPrefs := func(before, after string, diagnostics ...string) {
		doTest(true, before, after, diagnostics...)
	}
	testBeforeAndAfterPrefs := func(before, after string, diagnostics ...string) {
		doTest(false, before, after, diagnostics...)
		doTest(true, before, after, diagnostics...)
	}

	testBeforeAndAfterPrefs(
		".if ${IN_SCOPE_DEFINED:Mpattern}",
		".if ${IN_SCOPE_DEFINED} == pattern",

		"NOTE: filename.mk:3: IN_SCOPE_DEFINED can be "+
			"compared using the simpler \"${IN_SCOPE_DEFINED} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:3: Replacing \"${IN_SCOPE_DEFINED:Mpattern}\" "+
			"with \"${IN_SCOPE_DEFINED} == pattern\".")

	testBeforeAndAfterPrefs(
		".if ${IN_SCOPE:Mpattern}",
		".if ${IN_SCOPE:U} == pattern",

		"NOTE: filename.mk:3: IN_SCOPE can be "+
			"compared using the simpler \"${IN_SCOPE:U} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:3: Replacing \"${IN_SCOPE:Mpattern}\" "+
			"with \"${IN_SCOPE:U} == pattern\".")

	// Even though PREFS_DEFINED is declared as DefinedIfInScope,
	// it is not in scope yet. Therefore it needs the :U modifier.
	// The warning that this variable is not yet in scope comes from
	// a different part of pkglint.
	testBeforePrefs(
		".if ${PREFS_DEFINED:Mpattern}",
		".if ${PREFS_DEFINED:U} == pattern",

		"NOTE: filename.mk:3: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED:U} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"WARN: filename.mk:3: To use PREFS_DEFINED at load time, "+
			".include \"../../mk/bsd.prefs.mk\" first.",
		"AUTOFIX: filename.mk:3: Replacing \"${PREFS_DEFINED:Mpattern}\" "+
			"with \"${PREFS_DEFINED:U} == pattern\".")

	testAfterPrefs(
		".if ${PREFS_DEFINED:Mpattern}",
		".if ${PREFS_DEFINED} == pattern",

		"NOTE: filename.mk:3: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:3: Replacing \"${PREFS_DEFINED:Mpattern}\" "+
			"with \"${PREFS_DEFINED} == pattern\".")

	testBeforePrefs(
		".if ${PREFS:Mpattern}",
		".if ${PREFS:U} == pattern",

		"NOTE: filename.mk:3: PREFS can be "+
			"compared using the simpler \"${PREFS:U} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"WARN: filename.mk:3: To use PREFS at load time, "+
			".include \"../../mk/bsd.prefs.mk\" first.",
		"AUTOFIX: filename.mk:3: Replacing \"${PREFS:Mpattern}\" "+
			"with \"${PREFS:U} == pattern\".")

	// Preferences that may be undefined always need the :U modifier,
	// even when they are in scope.
	testAfterPrefs(
		".if ${PREFS:Mpattern}",
		".if ${PREFS:U} == pattern",

		"NOTE: filename.mk:3: PREFS can be "+
			"compared using the simpler \"${PREFS:U} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:3: Replacing \"${PREFS:Mpattern}\" "+
			"with \"${PREFS:U} == pattern\".")

	// Variables that are defined later always need the :U modifier.
	// It is probably a mistake to use them in conditions at all.
	testBeforeAndAfterPrefs(
		".if ${LATER_DEFINED:Mpattern}",
		".if ${LATER_DEFINED:U} == pattern",

		"NOTE: filename.mk:3: LATER_DEFINED can be "+
			"compared using the simpler \"${LATER_DEFINED:U} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"WARN: filename.mk:3: "+
			"LATER_DEFINED should not be used at load time in any file.",
		"AUTOFIX: filename.mk:3: Replacing \"${LATER_DEFINED:Mpattern}\" "+
			"with \"${LATER_DEFINED:U} == pattern\".")

	// Variables that are defined later always need the :U modifier.
	// It is probably a mistake to use them in conditions at all.
	testBeforeAndAfterPrefs(
		".if ${LATER:Mpattern}",
		".if ${LATER:U} == pattern",

		"NOTE: filename.mk:3: LATER can be "+
			"compared using the simpler \"${LATER:U} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"WARN: filename.mk:3: "+
			"LATER should not be used at load time in any file.",
		"AUTOFIX: filename.mk:3: Replacing \"${LATER:Mpattern}\" "+
			"with \"${LATER:U} == pattern\".")

	testBeforeAndAfterPrefs(
		".if ${UNDEFINED:Mpattern}",
		".if ${UNDEFINED:Mpattern}",

		"WARN: filename.mk:3: UNDEFINED is used but not defined.")

	// When the pattern contains placeholders, it cannot be converted to == or !=.
	testAfterPrefs(
		".if ${PREFS_DEFINED:Mpa*n}",
		".if ${PREFS_DEFINED:Mpa*n}",

		nil...)

	// When deciding whether to replace the expression, only the
	// last modifier is inspected. All the others are copied.
	testAfterPrefs(
		".if ${PREFS_DEFINED:tl:Mpattern}",
		".if ${PREFS_DEFINED:tl} == pattern",

		"NOTE: filename.mk:3: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED:tl} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:3: Replacing \"${PREFS_DEFINED:tl:Mpattern}\" "+
			"with \"${PREFS_DEFINED:tl} == pattern\".")

	// Negated pattern matches are supported as well,
	// as long as the variable is guaranteed to be nonempty.
	// TODO: Actually implement this.
	//  As of December 2019, IsNonemptyIfDefined is not used anywhere.
	testAfterPrefs(
		".if ${PREFS_DEFINED:Npattern}",
		".if ${PREFS_DEFINED} != pattern",

		"NOTE: filename.mk:3: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} != pattern\" "+
			"instead of matching against \":Npattern\".",
		"AUTOFIX: filename.mk:3: Replacing \"${PREFS_DEFINED:Npattern}\" "+
			"with \"${PREFS_DEFINED} != pattern\".")

	// ${PREFS_DEFINED:None:Ntwo} is a short variant of
	// ${PREFS_DEFINED} != "one" && ${PREFS_DEFINED} != "two".
	// Applying the transformation would make the condition longer
	// than before, therefore nothing can be simplified here,
	// even though all patterns are exact matches.
	testAfterPrefs(
		".if ${PREFS_DEFINED:None:Ntwo}",
		".if ${PREFS_DEFINED:None:Ntwo}",

		nil...)

	// Note: this combination doesn't make sense since the patterns
	// "one" and "two" don't overlap.
	// Nevertheless it is possible and valid to simplify the condition.
	testAfterPrefs(
		".if ${PREFS_DEFINED:Mone:Mtwo}",
		".if ${PREFS_DEFINED:Mone} == two",

		"NOTE: filename.mk:3: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED:Mone} == two\" "+
			"instead of matching against \":Mtwo\".",
		"AUTOFIX: filename.mk:3: Replacing \"${PREFS_DEFINED:Mone:Mtwo}\" "+
			"with \"${PREFS_DEFINED:Mone} == two\".")

	// There is no ! before the empty, which is easy to miss.
	// Because of this missing negation, the comparison operator is !=.
	testAfterPrefs(
		".if empty(PREFS_DEFINED:Mpattern)",
		".if ${PREFS_DEFINED} != pattern",

		"NOTE: filename.mk:3: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} != pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:3: Replacing \"empty(PREFS_DEFINED:Mpattern)\" "+
			"with \"${PREFS_DEFINED} != pattern\".")

	testAfterPrefs(
		".if !!empty(PREFS_DEFINED:Mpattern)",
		// TODO: The ! and == could be combined into a !=.
		//  Luckily the !! pattern doesn't occur in practice.
		".if !${PREFS_DEFINED} == pattern",

		// TODO: When taking all the ! into account, this is actually a
		//  test for emptiness, therefore the diagnostics should suggest
		//  the != operator instead of ==.
		"NOTE: filename.mk:3: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:3: Replacing \"!empty(PREFS_DEFINED:Mpattern)\" "+
			"with \"${PREFS_DEFINED} == pattern\".")

	// Simplifying the condition also works in complex expressions.
	testAfterPrefs(".if empty(PREFS_DEFINED:Mpattern) || 0",
		".if ${PREFS_DEFINED} != pattern || 0",

		"NOTE: filename.mk:3: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} != pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:3: Replacing \"empty(PREFS_DEFINED:Mpattern)\" "+
			"with \"${PREFS_DEFINED} != pattern\".")

	// No note in this case since there is no implicit !empty around the varUse.
	// There is no obvious way of writing this expression in a simpler form.
	testAfterPrefs(
		".if ${PREFS_DEFINED:Mpattern} != ${OTHER}",
		".if ${PREFS_DEFINED:Mpattern} != ${OTHER}",

		"WARN: filename.mk:3: OTHER is used but not defined.")

	// The condition is also simplified if it doesn't use the !empty
	// form but the implicit conversion to boolean.
	testAfterPrefs(
		".if ${PREFS_DEFINED:Mpattern}",
		".if ${PREFS_DEFINED} == pattern",

		"NOTE: filename.mk:3: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:3: Replacing \"${PREFS_DEFINED:Mpattern}\" "+
			"with \"${PREFS_DEFINED} == pattern\".")

	// A single negation outside the implicit conversion is taken into
	// account when simplifying the condition.
	testAfterPrefs(
		".if !${PREFS_DEFINED:Mpattern}",
		".if ${PREFS_DEFINED} != pattern",

		"NOTE: filename.mk:3: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} != pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:3: Replacing \"!${PREFS_DEFINED:Mpattern}\" "+
			"with \"${PREFS_DEFINED} != pattern\".")

	// TODO: Merge the double negation into the comparison operator.
	testAfterPrefs(
		".if !!${PREFS_DEFINED:Mpattern}",
		".if !${PREFS_DEFINED} != pattern",

		"NOTE: filename.mk:3: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} != pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:3: Replacing \"!${PREFS_DEFINED:Mpattern}\" "+
			"with \"${PREFS_DEFINED} != pattern\".")

	// This pattern with spaces doesn't make sense at all in the :M
	// modifier since it can never match.
	// Or can it, if the PKGPATH contains quotes?
	// TODO: How exactly does bmake apply the matching here,
	//  are both values unquoted first? Probably not, but who knows.
	testBeforeAndAfterPrefs(
		".if ${IN_SCOPE_DEFINED:Mpattern with spaces}",
		".if ${IN_SCOPE_DEFINED:Mpattern with spaces}",

		nil...)
	// TODO: ".if ${PKGPATH} == \"pattern with spaces\"")

	testBeforeAndAfterPrefs(
		".if ${IN_SCOPE_DEFINED:M'pattern with spaces'}",
		".if ${IN_SCOPE_DEFINED:M'pattern with spaces'}",

		nil...)
	// TODO: ".if ${PKGPATH} == 'pattern with spaces'")

	testBeforeAndAfterPrefs(
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
	testAfterPrefs(
		".if ${PREFS_DEFINED:Nnegative-pattern}",
		".if ${PREFS_DEFINED} != negative-pattern",

		"NOTE: filename.mk:3: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} != negative-pattern\" "+
			"instead of matching against \":Nnegative-pattern\".",
		"AUTOFIX: filename.mk:3: Replacing \"${PREFS_DEFINED:Nnegative-pattern}\" "+
			"with \"${PREFS_DEFINED} != negative-pattern\".")

	// Since UNDEFINED is not a well-known variable that is
	// guaranteed to be non-empty (see the previous example), it is not
	// transformed at all.
	testBeforePrefs(
		".if ${UNDEFINED:Nnegative-pattern}",
		".if ${UNDEFINED:Nnegative-pattern}",

		"WARN: filename.mk:3: UNDEFINED is used but not defined.")

	testAfterPrefs(
		".if ${UNDEFINED:Nnegative-pattern}",
		".if ${UNDEFINED:Nnegative-pattern}",

		"WARN: filename.mk:3: UNDEFINED is used but not defined.")

	// A complex condition may contain several simple conditions
	// that are each simplified independently, in the same go.
	testAfterPrefs(
		".if ${PREFS_DEFINED:Mpath1} || ${PREFS_DEFINED:Mpath2}",
		".if ${PREFS_DEFINED} == path1 || ${PREFS_DEFINED} == path2",

		"NOTE: filename.mk:3: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} == path1\" "+
			"instead of matching against \":Mpath1\".",
		"NOTE: filename.mk:3: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} == path2\" "+
			"instead of matching against \":Mpath2\".",
		"AUTOFIX: filename.mk:3: Replacing \"${PREFS_DEFINED:Mpath1}\" "+
			"with \"${PREFS_DEFINED} == path1\".",
		"AUTOFIX: filename.mk:3: Replacing \"${PREFS_DEFINED:Mpath2}\" "+
			"with \"${PREFS_DEFINED} == path2\".")

	// Removing redundant parentheses may be useful one day but is
	// not urgent.
	// Simplifying the inner expression keeps all parentheses as-is.
	testAfterPrefs(
		".if (((((${PREFS_DEFINED:Mpath})))))",
		".if (((((${PREFS_DEFINED} == path)))))",

		"NOTE: filename.mk:3: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} == path\" "+
			"instead of matching against \":Mpath\".",
		"AUTOFIX: filename.mk:3: Replacing \"${PREFS_DEFINED:Mpath}\" "+
			"with \"${PREFS_DEFINED} == path\".")

	// Several modifiers like :S and :C may change the variable value.
	// Whether the condition can be simplified or not only depends on the
	// last modifier in the chain.
	testAfterPrefs(
		".if !empty(PREFS_DEFINED:S,NetBSD,ok,:Mok)",
		".if ${PREFS_DEFINED:S,NetBSD,ok,} == ok",

		"NOTE: filename.mk:3: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED:S,NetBSD,ok,} == ok\" "+
			"instead of matching against \":Mok\".",
		"AUTOFIX: filename.mk:3: Replacing \"!empty(PREFS_DEFINED:S,NetBSD,ok,:Mok)\" "+
			"with \"${PREFS_DEFINED:S,NetBSD,ok,} == ok\".")

	testAfterPrefs(
		".if empty(PREFS_DEFINED:tl:Msunos)",
		".if ${PREFS_DEFINED:tl} != sunos",

		"NOTE: filename.mk:3: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED:tl} != sunos\" "+
			"instead of matching against \":Msunos\".",
		"AUTOFIX: filename.mk:3: Replacing \"empty(PREFS_DEFINED:tl:Msunos)\" "+
			"with \"${PREFS_DEFINED:tl} != sunos\".")

	// The condition can only be simplified if the :M or :N modifier
	// appears at the end of the chain.
	testAfterPrefs(
		".if !empty(PREFS_DEFINED:O:MUnknown:S,a,b,)",
		".if !empty(PREFS_DEFINED:O:MUnknown:S,a,b,)",

		nil...)

	// The dot is just an ordinary character in a pattern.
	// In comparisons, an unquoted 1.2 is interpreted as a number though.
	testAfterPrefs(
		".if !empty(PREFS_DEFINED:Mpackage1.2)",
		".if ${PREFS_DEFINED} == package1.2",

		"NOTE: filename.mk:3: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} == package1.2\" "+
			"instead of matching against \":Mpackage1.2\".",
		"AUTOFIX: filename.mk:3: Replacing \"!empty(PREFS_DEFINED:Mpackage1.2)\" "+
			"with \"${PREFS_DEFINED} == package1.2\".")

	// Numbers must be enclosed in quotes, otherwise they are compared
	// as numbers, not as strings.
	// The :M and :N modifiers always compare strings.
	testAfterPrefs(
		".if empty(PREFS:U:M64)",
		".if ${PREFS:U} != \"64\"",

		"NOTE: filename.mk:3: PREFS can be "+
			"compared using the simpler \"${PREFS:U} != \"64\"\" "+
			"instead of matching against \":M64\".",
		"AUTOFIX: filename.mk:3: Replacing \"empty(PREFS:U:M64)\" "+
			"with \"${PREFS:U} != \\\"64\\\"\".")

	// Fractional numbers must also be enclosed in quotes.
	testAfterPrefs(
		".if empty(PREFS:U:M19.12)",
		".if ${PREFS:U} != \"19.12\"",

		"NOTE: filename.mk:3: PREFS can be "+
			"compared using the simpler \"${PREFS:U} != \"19.12\"\" "+
			"instead of matching against \":M19.12\".",
		"AUTOFIX: filename.mk:3: Replacing \"empty(PREFS:U:M19.12)\" "+
			"with \"${PREFS:U} != \\\"19.12\\\"\".")

	testAfterPrefs(
		".if !empty(LATER:Npattern)",
		".if !empty(LATER:Npattern)",

		// No diagnostics about the :N modifier yet,
		// see MkCondChecker.simplify.replace.
		"WARN: filename.mk:3: LATER should not be used "+
			"at load time in any file.")

	// TODO: Add a note that the :U is unnecessary, and explain why.
	testAfterPrefs(
		".if ${PREFS_DEFINED:U:Mpattern}",
		".if ${PREFS_DEFINED:U} == pattern",

		"NOTE: filename.mk:3: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED:U} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:3: "+
			"Replacing \"${PREFS_DEFINED:U:Mpattern}\" "+
			"with \"${PREFS_DEFINED:U} == pattern\".")

	// Conditions without any modifiers cannot be simplified
	// and are therefore skipped.
	testBeforeAndAfterPrefs(
		".if ${IN_SCOPE_DEFINED}",
		".if ${IN_SCOPE_DEFINED}",

		nil...)

	// Special characters must be enclosed in quotes when they are
	// used in string literals.
	// As of December 2019, strings with special characters are not yet
	// replaced automatically, see mkCondLiteralChars.
	// TODO: Add tests for all characters that are special in string literals or patterns.
	// TODO: Then, extend the set of characters for which the expressions are simplified.
	testBeforePrefs(
		".if ${PREFS_DEFINED:M&&}",
		".if ${PREFS_DEFINED:M&&}",

		"WARN: filename.mk:3: To use PREFS_DEFINED at load time, .include \"../../mk/bsd.prefs.mk\" first.")
	testAfterPrefs(
		".if ${PREFS_DEFINED:M&&}",
		".if ${PREFS_DEFINED:M&&}",

		nil...)

	testBeforePrefs(
		".if ${PREFS:M&&}",
		".if ${PREFS:M&&}",

		// TODO: Warn that the :U is missing.
		"WARN: filename.mk:3: To use PREFS at load time, .include \"../../mk/bsd.prefs.mk\" first.")
	testAfterPrefs(
		".if ${PREFS:M&&}",
		".if ${PREFS:M&&}",

		// TODO: Warn that the :U is missing.
		nil...)

	// The + is contained in both mkCondStringLiteralUnquoted and
	// mkCondModifierPatternLiteral, therefore it is copied verbatim.
	testAfterPrefs(
		".if ${PREFS_DEFINED:Mcategory/gtk+}",
		".if ${PREFS_DEFINED} == category/gtk+",

		"NOTE: filename.mk:3: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} == category/gtk+\" "+
			"instead of matching against \":Mcategory/gtk+\".",
		"AUTOFIX: filename.mk:3: "+
			"Replacing \"${PREFS_DEFINED:Mcategory/gtk+}\" "+
			"with \"${PREFS_DEFINED} == category/gtk+\".")

	// The characters <=> may be used unescaped in :M and :N patterns
	// but not in .if conditions. There they must be enclosed in quotes.
	testBeforePrefs(
		".if ${PREFS_DEFINED:M<=>}",
		".if ${PREFS_DEFINED:U} == \"<=>\"",

		"NOTE: filename.mk:3: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED:U} == \"<=>\"\" "+
			"instead of matching against \":M<=>\".",
		"WARN: filename.mk:3: To use PREFS_DEFINED at load time, "+
			".include \"../../mk/bsd.prefs.mk\" first.",
		"AUTOFIX: filename.mk:3: "+
			"Replacing \"${PREFS_DEFINED:M<=>}\" "+
			"with \"${PREFS_DEFINED:U} == \\\"<=>\\\"\".")
	testAfterPrefs(
		".if ${PREFS_DEFINED:M<=>}",
		".if ${PREFS_DEFINED} == \"<=>\"",

		"NOTE: filename.mk:3: PREFS_DEFINED can be "+
			"compared using the simpler \"${PREFS_DEFINED} == \"<=>\"\" "+
			"instead of matching against \":M<=>\".",
		"AUTOFIX: filename.mk:3: "+
			"Replacing \"${PREFS_DEFINED:M<=>}\" "+
			"with \"${PREFS_DEFINED} == \\\"<=>\\\"\".")

	// If pkglint replaces this particular pattern, the resulting string
	// literal must be escaped properly.
	testBeforeAndAfterPrefs(
		".if ${IN_SCOPE_DEFINED:M\"}",
		".if ${IN_SCOPE_DEFINED:M\"}",

		nil...)
}

func (s *Suite) Test_MkCondChecker_simplify__defined_in_same_file(c *check.C) {
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

func (s *Suite) Test_MkCondChecker_checkCompare(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	test := func(cond string, output ...string) {
		mklines := t.NewMkLines("filename.mk",
			cond)
		mklines.ForEach(func(mkline *MkLine) {
			NewMkCondChecker(mkline, mklines).Check()
		})
		t.CheckOutput(output)
	}

	// As of July 2019, pkglint doesn't have specific checks for comparing
	// variables to numbers.
	test(".if ${VAR} > 0",
		"WARN: filename.mk:1: VAR is used but not defined.")

	// For string comparisons, the checks from vartypecheck.go are
	// performed.
	test(".if ${DISTNAME} == \"<>\"",
		"WARN: filename.mk:1: The filename \"<>\" contains the invalid characters \"<>\".",
		"WARN: filename.mk:1: DISTNAME should not be used at load time in any file.")

	// This type of comparison doesn't occur in practice since it is
	// overly verbose.
	test(".if \"${BUILD_DIRS}str\" == \"str\"",
		// TODO: why should it not be used? In a .for loop it sounds pretty normal.
		"WARN: filename.mk:1: BUILD_DIRS should not be used at load time in any file.")

	// This is a shorthand for defined(VAR), but it is not used in practice.
	test(".if VAR",
		"WARN: filename.mk:1: Invalid condition, unrecognized part: \"VAR\".")

	// Calling a function with braces instead of parentheses is syntactically
	// invalid. Pkglint is stricter than bmake in this situation.
	//
	// Bmake reads the "empty{VAR}" as a variable name. It then checks whether
	// this variable is defined. It is not, of course, therefore the expression
	// is false. The ! in front of it negates this false, which makes the whole
	// condition true.
	//
	// See https://mail-index.netbsd.org/tech-pkg/2019/07/07/msg021539.html
	test(".if !empty{VAR}",
		"WARN: filename.mk:1: Invalid condition, unrecognized part: \"empty{VAR}\".")
}

func (s *Suite) Test_MkCondChecker_checkCompareVarStr__no_tracing(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	t.SetUpVartypes()
	mklines := t.NewMkLines("filename.mk",
		".if ${DISTFILES:Mpattern:O:u} == NetBSD")
	t.DisableTracing()

	ck := NewMkCondChecker(mklines.mklines[0], mklines)
	varUse := b.VarUse("DISTFILES", "Mpattern", "O", "u")
	// TODO: mklines.ForEach
	ck.checkCompareVarStr(varUse, "==", "distfile-1.0.tar.gz")

	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkCondChecker_checkCompareVarNum(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"",
		"OS_VERSION=\t9.0",
		"",
		".if ${OS_VERSION} > 6.5",
		".endif",
		"",
		".if ${OS_VERSION} == 6.5",
		".endif")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: filename.mk:5: Numeric comparison > 6.5.",
		"WARN: filename.mk:8: Numeric comparison == 6.5.")
}

func (s *Suite) Test_MkCondChecker_checkCompareVarStrCompiler(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.Chdir("category/package")
	t.FinishSetUp()

	doTest := func(cond string) {
		mklines := t.SetUpFileMkLines("filename.mk",
			MkCvsID,
			"",
			".include \"../../mk/bsd.fast.prefs.mk\"",
			"",
			".if "+cond,
			".endif")

		mklines.Check()
	}

	test := func(cond string, diagnostics ...string) {
		t.ExpectDiagnosticsAutofix(
			func(bool) { doTest(cond) },
			diagnostics...)
	}

	test(
		"${PKGSRC_COMPILER} == gcc",

		"ERROR: filename.mk:5: "+
			"Use ${PKGSRC_COMPILER:Mgcc} instead of the == operator.",
		"AUTOFIX: filename.mk:5: "+
			"Replacing \"${PKGSRC_COMPILER} == gcc\" "+
			"with \"${PKGSRC_COMPILER:Mgcc}\".")

	// No autofix because of missing whitespace.
	// TODO: Provide the autofix regardless of the whitespace.
	test(
		"${PKGSRC_COMPILER}==gcc",

		"ERROR: filename.mk:5: "+
			"Use ${PKGSRC_COMPILER:Mgcc} instead of the == operator.")

	// The comparison value can be with or without quotes.
	test(
		"${PKGSRC_COMPILER} == \"gcc\"",

		"ERROR: filename.mk:5: "+
			"Use ${PKGSRC_COMPILER:Mgcc} instead of the == operator.",
		"AUTOFIX: filename.mk:5: "+
			"Replacing \"${PKGSRC_COMPILER} == \\\"gcc\\\"\" "+
			"with \"${PKGSRC_COMPILER:Mgcc}\".")

	// No warning because it is not obvious what is meant here.
	// This case probably doesn't occur in practice.
	test(
		"${PKGSRC_COMPILER} == \"distcc gcc\"",

		nil...)
}

func (s *Suite) Test_MkCondChecker_checkNotCompare(c *check.C) {
	t := s.Init(c)

	test := func(cond string, diagnostics ...string) {
		mklines := t.NewMkLines("filename.mk",
			".if "+cond)
		mkline := mklines.mklines[0]
		ck := NewMkCondChecker(mkline, mklines)

		ck.checkNotCompare(mkline.Cond().Not)

		t.CheckOutput(diagnostics)
	}

	test("!${VAR} == value",
		"WARN: filename.mk:1: The ! should use parentheses "+
			"or be merged into the comparison operator.")

	test("!${VAR} != value",
		"WARN: filename.mk:1: The ! should use parentheses "+
			"or be merged into the comparison operator.")

	test("!(${VAR} == value)",
		nil...)

	test("!${VAR}",
		nil...)
}
