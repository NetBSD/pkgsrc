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

func (s *Suite) Test_MkCondChecker_Check__contradicting_conditions(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.FinishSetUp()

	lines := func(lines ...string) []string { return lines }
	test := func(lines []string, diagnostics ...string) {
		allLines := []string{
			MkCvsID,
			"",
			".include \"../../mk/bsd.prefs.mk\"",
			""}
		mklines := t.NewMkLines("filename.mk",
			append(allLines, lines...)...)

		mklines.Check()

		t.CheckOutput(diagnostics)
	}

	// Seen in lang/rust/Makefile on 2020-06-12.
	// TODO: The MACHINE_PLATFORM conditions make the OPSYS condition redundant.
	test(
		lines(
			".if ${OPSYS} == \"NetBSD\" && "+
				"!empty(MACHINE_PLATFORM:MNetBSD-9.99.*) && "+
				"!empty(MACHINE_PLATFORM:MNetBSD-[1-9][0-9].*)",
			".endif"),
		"ERROR: filename.mk:5: The patterns \"NetBSD-9.99.*\" "+
			"and \"NetBSD-[1-9][0-9].*\" cannot match at the same time.")

	// A syntactical variation of the above condition.
	// TODO: The MACHINE_PLATFORM conditions make the OPSYS condition redundant.
	test(
		lines(
			".if ${OPSYS} == NetBSD && ${MACHINE_PLATFORM:MNetBSD-9.99.*} && ${MACHINE_PLATFORM:MNetBSD-[1-9][0-9].*}",
			".endif"),
		"ERROR: filename.mk:5: The patterns \"NetBSD-9.99.*\" "+
			"and \"NetBSD-[1-9][0-9].*\" cannot match at the same time.")

	// Another variation on the same theme.
	// TODO: The MACHINE_PLATFORM conditions make the OPSYS condition redundant.
	test(
		lines(
			".if ${OPSYS} == NetBSD",
			".  if ${MACHINE_PLATFORM:MNetBSD-9.99.*}",
			".    if ${MACHINE_PLATFORM:MNetBSD-[1-9][0-9].*}",
			".    endif",
			".  endif",
			".endif"),
		"ERROR: filename.mk:7: The patterns \"NetBSD-9.99.*\" from line 6 "+
			"and \"NetBSD-[1-9][0-9].*\" cannot match at the same time.")

	// TODO: Since MACHINE_PLATFORM always starts with OPSYS, these
	//  conditions contradict each other as well.
	test(
		lines(
			".if ${OPSYS} == NetBSD",
			".  if ${MACHINE_PLATFORM:MSunOS-5.*}",
			".  endif",
			".endif"),
		nil...)

	// Since PKG_OPTIONS is a list and contains several words,
	// each of them can match one of the patterns.
	t.SetUpOption("one", "")
	t.SetUpOption("two", "")
	test(
		lines(
			".if ${PKG_OPTIONS:Mone} && ${PKG_OPTIONS:Mtwo}",
			".endif"),
		nil...)

	// For variables that are declared individually by a package,
	// pkglint does not have any type information and thus must
	// not issue an error here.
	test(
		lines(
			"CUSTOM_VAR=\tone two",
			".if ${CUSTOM_VAR:Mone} && ${CUSTOM_VAR:Mtwo}",
			".endif"),
		nil...)

	// In this case, pkglint may infer that CUSTOM_VAR has a
	// constant value and thus cannot match the second pattern.
	// As of June 2020, it doesn't do this though.
	test(
		lines(
			"CUSTOM_VAR=\tone",
			".if ${CUSTOM_VAR:Mone} && ${CUSTOM_VAR:Mtwo}",
			".endif"),
		nil...)

	// If the variable type is guessed based on the variable name (see
	// guessVariableType) and is not a list, the error message is correct.
	test(
		lines(
			"CUSTOM_FILE=\tone",
			".if ${CUSTOM_FILE:Mone} && ${CUSTOM_FILE:Mtwo}",
			".endif"),
		"NOTE: filename.mk:6: CUSTOM_FILE can be compared using the simpler "+
			"\"${CUSTOM_FILE} == one\" instead of matching against \":Mone\".",
		"NOTE: filename.mk:6: CUSTOM_FILE can be compared using the simpler "+
			"\"${CUSTOM_FILE} == two\" instead of matching against \":Mtwo\".",
		"ERROR: filename.mk:6: The patterns \"one\" and \"two\" "+
			"cannot match at the same time.")

	// The conditions from an .if and an .elif don't contradict each other.
	test(
		lines(
			".if ${OPSYS:MNet*}",
			".elif ${OPSYS:MFree*}",
			".endif"),
		nil...)

	// And finally, two conditions that can both match at the same time,
	// just for the code coverage.
	// It's strange that the above tests did not include that case.
	test(
		lines(
			".if ${OPSYS:MNet*} && ${OPSYS:MNetB*}",
			".endif"),
		nil...)

	test(
		lines(
			".if ${OPSYS:M[1} && ${OPSYS:M[2}",
			".endif"),
		"WARN: filename.mk:5: Invalid match pattern \"[1\".",
		"WARN: filename.mk:5: Invalid match pattern \"[2\".")
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

func (s *Suite) Test_MkCondChecker_checkContradictions(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	test := func(cond string, diagnostics ...string) {
		mklines := t.NewMkLines("filename.mk",
			".if "+cond)
		mkline := mklines.mklines[0]
		ck := NewMkCondChecker(mkline, mklines)

		mklines.ForEach(func(mkline *MkLine) { ck.checkContradictions() })

		t.CheckOutput(diagnostics)
	}

	test("!empty(MACHINE_PLATFORM:Mone) && !empty(MACHINE_PLATFORM:Mtwo)",
		"ERROR: filename.mk:1: The patterns \"one\" and \"two\" "+
			"cannot match at the same time.")
}

func (s *Suite) Test_MkCondChecker_collectFacts(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	mklines := t.NewMkLines("filename.mk",
		".if !empty(OPSYS:Mone) && ${OPSYS:Mtwo}",
		".  if ${OS_VERSION:Mthree}",
		".    if ((((${OPSYS:Mfour}))))",
		".      if (${OPSYS:Mor1} || ${OPSYS:Mor2})", // these are ignored
		".        if ${OPSYS:Mfive} && (${OPSYS:Msix} && ${OPSYS:Mseven})",
		".      endif",
		".    endif",
		".  endif",
		".endif")
	var facts []VarFact

	mklines.ForEach(func(mkline *MkLine) {
		ck := NewMkCondChecker(mkline, mklines)
		if mkline.NeedsCond() {
			facts = append(facts, ck.collectFacts(mkline)...)
		}
	})

	for i, _ := range facts {
		facts[i].Matches = nil // these would just complicate the comparison
	}
	t.CheckDeepEquals(facts, []VarFact{
		{mklines.mklines[0], "OPSYS", "one", nil},
		{mklines.mklines[0], "OPSYS", "two", nil},
		{mklines.mklines[1], "OS_VERSION", "three", nil},
		{mklines.mklines[2], "OPSYS", "four", nil},
		{mklines.mklines[4], "OPSYS", "five", nil},
		{mklines.mklines[4], "OPSYS", "six", nil},
		{mklines.mklines[4], "OPSYS", "seven", nil},
	})
}
