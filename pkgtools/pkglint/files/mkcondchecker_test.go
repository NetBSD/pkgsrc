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

func (s *Suite) Test_MkCondChecker_checkDirectiveCond(c *check.C) {
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
		"NOTE: filename.mk:4: PKG_LIBTOOL "+
			"should be compared using \"${PKG_LIBTOOL:U} == libtool\" "+
			"instead of matching against \":Mlibtool\".",
		"WARN: filename.mk:4: PKG_LIBTOOL should not be used at load time in any file.")

	test(".if ${MACHINE_PLATFORM:MUnknownOS-*-*} || ${MACHINE_ARCH:Mx86}",
		"WARN: filename.mk:4: "+
			"The pattern \"UnknownOS\" cannot match any of "+
			"{ AIX BSDOS Bitrig Cygwin Darwin DragonFly FreeBSD FreeMiNT GNUkFreeBSD HPUX Haiku "+
			"IRIX Interix Linux Minix MirBSD NetBSD OSF1 OpenBSD QNX SCO_SV SunOS UnixWare "+
			"} for the operating system part of MACHINE_PLATFORM.",
		"WARN: filename.mk:4: "+
			"The pattern \"x86\" cannot match any of "+
			"{ aarch64 aarch64eb alpha amd64 arc arm arm26 arm32 cobalt coldfire convex dreamcast earm "+
			"earmeb earmhf earmhfeb earmv4 earmv4eb earmv5 earmv5eb earmv6 earmv6eb earmv6hf earmv6hfeb "+
			"earmv7 earmv7eb earmv7hf earmv7hfeb evbarm hpcmips hpcsh hppa hppa64 i386 i586 i686 ia64 "+
			"m68000 m68k m88k mips mips64 mips64eb mips64el mipseb mipsel mipsn32 mlrisc ns32k pc532 pmax "+
			"powerpc powerpc64 rs6000 s390 sh3eb sh3el sparc sparc64 vax x86_64 "+
			"} for MACHINE_ARCH.",
		"NOTE: filename.mk:4: MACHINE_ARCH "+
			"should be compared using \"${MACHINE_ARCH} == x86\" "+
			"instead of matching against \":Mx86\".")

	// Doesn't occur in practice since it is surprising that the ! applies
	// to the comparison operator, and not to one of its arguments.
	test(".if !${VAR} == value",
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

func (s *Suite) Test_MkCondChecker_checkDirectiveCond__tracing(c *check.C) {
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

func (s *Suite) Test_MkCondChecker_checkDirectiveCond__comparison_with_shell_command(c *check.C) {
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
func (s *Suite) Test_MkCondChecker_checkDirectiveCond__compare_pattern_with_empty(c *check.C) {
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

	// TODO: There should be a warning about "<>" containing invalid
	//  characters for a path. See VartypeCheck.Pathname
	t.CheckOutputLines(
		"WARN: filename.mk:8: The pathname pattern \"<>\" contains the invalid characters \"<>\".",
		"WARN: filename.mk:8: The pathname \"*\" contains the invalid character \"*\".")
}

func (s *Suite) Test_MkCondChecker_checkDirectiveCond__comparing_PKGSRC_COMPILER_with_eqeq(c *check.C) {
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

func (s *Suite) Test_MkCondChecker_checkDirectiveCondEmpty(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.Chdir("category/package")
	t.FinishSetUp()

	// before: the directive before the condition is simplified
	// after: the directive after the condition is simplified
	// diagnostics: the usual ones
	test := func(before, after string, diagnostics ...string) {
		mklines := t.SetUpFileMkLines("filename.mk",
			MkCvsID,
			"",
			before,
			".endif")

		t.ExpectDiagnosticsAutofix(
			mklines.Check,
			diagnostics...)

		afterMklines := LoadMk(t.File("filename.mk"), MustSucceed)
		t.CheckEquals(afterMklines.mklines[2].Text, after)
	}

	test(
		".if !empty(OPSYS:MUnknown)",
		".if ${OPSYS:U} == Unknown",

		"WARN: filename.mk:3: The pattern \"Unknown\" cannot match any of "+
			"{ Cygwin DragonFly FreeBSD Linux NetBSD SunOS } for OPSYS.",
		"NOTE: filename.mk:3: OPSYS should be "+
			"compared using \"${OPSYS:U} == Unknown\" "+
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

func (s *Suite) Test_MkCondChecker_checkDirectiveCondEmptyExpr(c *check.C) {
	t := s.Init(c)

	test := func(use *MkVarUse, diagnostics ...string) {
		mklines := t.NewMkLines("filename.mk",
			"# dummy")
		ck := NewMkCondChecker(mklines.mklines[0], mklines)

		ck.checkDirectiveCondEmptyExpr(use)

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

func (s *Suite) Test_MkCondChecker_checkDirectiveCondEmptyType(c *check.C) {
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
				ck.checkDirectiveCondEmptyType(varUse)
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

func (s *Suite) Test_MkCondChecker_simplifyCondition(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.Chdir("category/package")
	t.FinishSetUp()

	// prefs: whether to include bsd.prefs.mk before
	// before: the directive before the condition is simplified
	// after: the directive after the condition is simplified
	test := func(prefs bool, before, after string, diagnostics ...string) {
		mklines := t.SetUpFileMkLines("filename.mk",
			MkCvsID,
			condStr(prefs, ".include \"../../mk/bsd.prefs.mk\"", ""),
			before,
			".endif")

		// The high-level call MkLines.Check is used here to
		// get MkLines.Tools.SeenPrefs correct, which decides
		// whether the :U modifier is necessary.
		//
		// TODO: Replace MkLines.Check this with a more specific method.

		t.ExpectDiagnosticsAutofix(
			mklines.Check,
			diagnostics...)

		// TODO: Move this assertion above the assertion about the diagnostics.
		afterMklines := LoadMk(t.File("filename.mk"), MustSucceed)
		t.CheckEquals(afterMklines.mklines[2].Text, after)
	}
	testAfterPrefs := func(before, after string, diagnostics ...string) {
		test(true, before, after, diagnostics...)
	}

	test(
		false,
		".if ${PKGPATH:Mpattern}",
		".if ${PKGPATH:U} == pattern",

		"NOTE: filename.mk:3: PKGPATH "+
			"should be compared using \"${PKGPATH:U} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"WARN: filename.mk:3: To use PKGPATH at load time, "+
			".include \"../../mk/bsd.prefs.mk\" first.",
		"AUTOFIX: filename.mk:3: Replacing \"${PKGPATH:Mpattern}\" "+
			"with \"${PKGPATH:U} == pattern\".")

	testAfterPrefs(
		".if ${PKGPATH:Mpattern}",
		".if ${PKGPATH} == pattern",

		"NOTE: filename.mk:3: PKGPATH "+
			"should be compared using \"${PKGPATH} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:3: Replacing \"${PKGPATH:Mpattern}\" "+
			"with \"${PKGPATH} == pattern\".")

	// When the pattern contains placeholders, it cannot be converted to == or !=.
	testAfterPrefs(
		".if ${PKGPATH:Mpa*n}",
		".if ${PKGPATH:Mpa*n}",

		nil...)

	// When deciding whether to replace the expression, only the
	// last modifier is inspected. All the others are copied.
	testAfterPrefs(
		".if ${PKGPATH:tl:Mpattern}",
		".if ${PKGPATH:tl} == pattern",

		"NOTE: filename.mk:3: PKGPATH "+
			"should be compared using \"${PKGPATH:tl} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:3: Replacing \"${PKGPATH:tl:Mpattern}\" "+
			"with \"${PKGPATH:tl} == pattern\".")

	// Negated pattern matches are supported as well,
	// as long as the variable is guaranteed to be nonempty.
	testAfterPrefs(
		".if ${PKGPATH:Ncategory/package}",
		".if ${PKGPATH} != category/package",

		"NOTE: filename.mk:3: PKGPATH "+
			"should be compared using \"${PKGPATH} != category/package\" "+
			"instead of matching against \":Ncategory/package\".",
		"AUTOFIX: filename.mk:3: Replacing \"${PKGPATH:Ncategory/package}\" "+
			"with \"${PKGPATH} != category/package\".")

	// ${PKGPATH:None:Ntwo} is a short variant of ${PKGPATH} != "one" &&
	// ${PKGPATH} != "two". Applying the transformation would make the
	// condition longer than before, therefore nothing is done here.
	testAfterPrefs(
		".if ${PKGPATH:None:Ntwo}",
		".if ${PKGPATH:None:Ntwo}",

		nil...)

	// Note: this combination doesn't make sense since the patterns
	// "one" and "two" don't overlap.
	testAfterPrefs(
		".if ${PKGPATH:Mone:Mtwo}",
		".if ${PKGPATH:Mone} == two",

		"NOTE: filename.mk:3: PKGPATH "+
			"should be compared using \"${PKGPATH:Mone} == two\" "+
			"instead of matching against \":Mtwo\".",
		"AUTOFIX: filename.mk:3: Replacing \"${PKGPATH:Mone:Mtwo}\" "+
			"with \"${PKGPATH:Mone} == two\".")

	testAfterPrefs(
		".if !empty(PKGPATH:Mpattern)",
		".if ${PKGPATH} == pattern",

		"NOTE: filename.mk:3: PKGPATH "+
			"should be compared using \"${PKGPATH} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:3: Replacing \"!empty(PKGPATH:Mpattern)\" "+
			"with \"${PKGPATH} == pattern\".")

	testAfterPrefs(
		".if empty(PKGPATH:Mpattern)",
		".if ${PKGPATH} != pattern",

		"NOTE: filename.mk:3: PKGPATH "+
			"should be compared using \"${PKGPATH} != pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:3: Replacing \"empty(PKGPATH:Mpattern)\" "+
			"with \"${PKGPATH} != pattern\".")

	testAfterPrefs(
		".if !!empty(PKGPATH:Mpattern)",
		// TODO: The ! and == could be combined into a !=.
		//  Luckily the !! pattern doesn't occur in practice.
		".if !${PKGPATH} == pattern",

		// TODO: When taking all the ! into account, this is actually a
		//  test for emptiness, therefore the diagnostics should suggest
		//  the != operator instead of ==.
		"NOTE: filename.mk:3: PKGPATH "+
			"should be compared using \"${PKGPATH} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:3: Replacing \"!empty(PKGPATH:Mpattern)\" "+
			"with \"${PKGPATH} == pattern\".")

	testAfterPrefs(".if empty(PKGPATH:Mpattern) || 0",
		".if ${PKGPATH} != pattern || 0",

		"NOTE: filename.mk:3: PKGPATH "+
			"should be compared using \"${PKGPATH} != pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:3: Replacing \"empty(PKGPATH:Mpattern)\" "+
			"with \"${PKGPATH} != pattern\".")

	// No note in this case since there is no implicit !empty around the varUse.
	testAfterPrefs(
		".if ${PKGPATH:Mpattern} != ${OTHER}",
		".if ${PKGPATH:Mpattern} != ${OTHER}",

		"WARN: filename.mk:3: OTHER is used but not defined.")

	testAfterPrefs(
		".if ${PKGPATH:Mpattern}",
		".if ${PKGPATH} == pattern",

		"NOTE: filename.mk:3: PKGPATH "+
			"should be compared using \"${PKGPATH} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:3: Replacing \"${PKGPATH:Mpattern}\" "+
			"with \"${PKGPATH} == pattern\".")

	testAfterPrefs(
		".if !${PKGPATH:Mpattern}",
		".if ${PKGPATH} != pattern",

		"NOTE: filename.mk:3: PKGPATH "+
			"should be compared using \"${PKGPATH} != pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:3: Replacing \"!${PKGPATH:Mpattern}\" "+
			"with \"${PKGPATH} != pattern\".")

	// TODO: Merge the double negation into the comparison operator.
	testAfterPrefs(
		".if !!${PKGPATH:Mpattern}",
		".if !${PKGPATH} != pattern",

		"NOTE: filename.mk:3: PKGPATH "+
			"should be compared using \"${PKGPATH} != pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:3: Replacing \"!${PKGPATH:Mpattern}\" "+
			"with \"${PKGPATH} != pattern\".")

	// This pattern with spaces doesn't make sense at all in the :M
	// modifier since it can never match.
	// Or can it, if the PKGPATH contains quotes?
	// How exactly does bmake apply the matching here, are both values unquoted?
	testAfterPrefs(
		".if ${PKGPATH:Mpattern with spaces}",
		".if ${PKGPATH:Mpattern with spaces}",

		"WARN: filename.mk:3: The pathname pattern \"pattern with spaces\" "+
			"contains the invalid characters \"  \".")
	// TODO: ".if ${PKGPATH} == \"pattern with spaces\"")

	testAfterPrefs(
		".if ${PKGPATH:M'pattern with spaces'}",
		".if ${PKGPATH:M'pattern with spaces'}",

		"WARN: filename.mk:3: The pathname pattern \"'pattern with spaces'\" "+
			"contains the invalid characters \"'  '\".")
	// TODO: ".if ${PKGPATH} == 'pattern with spaces'")

	testAfterPrefs(
		".if ${PKGPATH:M&&}",
		".if ${PKGPATH:M&&}",

		"WARN: filename.mk:3: The pathname pattern \"&&\" "+
			"contains the invalid characters \"&&\".")
	// TODO: ".if ${PKGPATH} == '&&'")

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
	testAfterPrefs(
		".if ${PKGPATH:Nnegative-pattern}",
		".if ${PKGPATH} != negative-pattern",

		"NOTE: filename.mk:3: PKGPATH "+
			"should be compared using \"${PKGPATH} != negative-pattern\" "+
			"instead of matching against \":Nnegative-pattern\".",
		"AUTOFIX: filename.mk:3: Replacing \"${PKGPATH:Nnegative-pattern}\" "+
			"with \"${PKGPATH} != negative-pattern\".")

	// Since UNKNOWN is not a well-known system-provided variable that is
	// guaranteed to be non-empty (see the previous example), it is not
	// transformed at all.
	test(
		false,
		".if ${UNKNOWN:Nnegative-pattern}",
		".if ${UNKNOWN:Nnegative-pattern}",

		"WARN: filename.mk:3: UNKNOWN is used but not defined.")

	test(
		true,
		".if ${UNKNOWN:Nnegative-pattern}",
		".if ${UNKNOWN:Nnegative-pattern}",

		"WARN: filename.mk:3: UNKNOWN is used but not defined.")

	testAfterPrefs(
		".if ${PKGPATH:Mpath1} || ${PKGPATH:Mpath2}",
		".if ${PKGPATH} == path1 || ${PKGPATH} == path2",

		"NOTE: filename.mk:3: PKGPATH "+
			"should be compared using \"${PKGPATH} == path1\" "+
			"instead of matching against \":Mpath1\".",
		"NOTE: filename.mk:3: PKGPATH "+
			"should be compared using \"${PKGPATH} == path2\" "+
			"instead of matching against \":Mpath2\".",
		"AUTOFIX: filename.mk:3: Replacing \"${PKGPATH:Mpath1}\" "+
			"with \"${PKGPATH} == path1\".",
		"AUTOFIX: filename.mk:3: Replacing \"${PKGPATH:Mpath2}\" "+
			"with \"${PKGPATH} == path2\".")

	testAfterPrefs(
		".if (((((${PKGPATH:Mpath})))))",
		".if (((((${PKGPATH} == path)))))",

		"NOTE: filename.mk:3: PKGPATH "+
			"should be compared using \"${PKGPATH} == path\" "+
			"instead of matching against \":Mpath\".",
		"AUTOFIX: filename.mk:3: Replacing \"${PKGPATH:Mpath}\" "+
			"with \"${PKGPATH} == path\".")

	// MACHINE_ARCH is built-in into bmake and is always available.
	// Therefore it doesn't matter whether bsd.prefs.mk is included or not.
	test(
		false,
		".if ${MACHINE_ARCH:Mx86_64}",
		".if ${MACHINE_ARCH} == x86_64",

		"NOTE: filename.mk:3: MACHINE_ARCH "+
			"should be compared using \"${MACHINE_ARCH} == x86_64\" "+
			"instead of matching against \":Mx86_64\".",
		"AUTOFIX: filename.mk:3: Replacing \"${MACHINE_ARCH:Mx86_64}\" "+
			"with \"${MACHINE_ARCH} == x86_64\".")

	// MACHINE_ARCH is built-in into bmake and is always available.
	// Therefore it doesn't matter whether bsd.prefs.mk is included or not.
	test(
		true,
		".if ${MACHINE_ARCH:Mx86_64}",
		".if ${MACHINE_ARCH} == x86_64",

		"NOTE: filename.mk:3: MACHINE_ARCH "+
			"should be compared using \"${MACHINE_ARCH} == x86_64\" "+
			"instead of matching against \":Mx86_64\".",
		"AUTOFIX: filename.mk:3: Replacing \"${MACHINE_ARCH:Mx86_64}\" "+
			"with \"${MACHINE_ARCH} == x86_64\".")

	test(
		false,
		".if !empty(OPSYS:MUnknown)",
		".if ${OPSYS:U} == Unknown",

		// FIXME: This warning is not the job of simplifyCondition.
		//  Therefore don't test it here.
		"WARN: filename.mk:3: The pattern \"Unknown\" cannot match any of "+
			"{ Cygwin DragonFly FreeBSD Linux NetBSD SunOS } for OPSYS.",
		"NOTE: filename.mk:3: OPSYS should be "+
			"compared using \"${OPSYS:U} == Unknown\" "+
			"instead of matching against \":MUnknown\".",
		"WARN: filename.mk:3: To use OPSYS at load time, "+
			".include \"../../mk/bsd.prefs.mk\" first.",
		"AUTOFIX: filename.mk:3: Replacing \"!empty(OPSYS:MUnknown)\" "+
			"with \"${OPSYS:U} == Unknown\".")

	testAfterPrefs(
		".if !empty(OPSYS:S,NetBSD,ok,:Mok)",
		".if ${OPSYS:S,NetBSD,ok,} == ok",

		"NOTE: filename.mk:3: OPSYS should be "+
			"compared using \"${OPSYS:S,NetBSD,ok,} == ok\" "+
			"instead of matching against \":Mok\".",
		"AUTOFIX: filename.mk:3: Replacing \"!empty(OPSYS:S,NetBSD,ok,:Mok)\" "+
			"with \"${OPSYS:S,NetBSD,ok,} == ok\".")

	testAfterPrefs(
		".if empty(OPSYS:tl:Msunos)",
		".if ${OPSYS:tl} != sunos",

		"NOTE: filename.mk:3: OPSYS should be "+
			"compared using \"${OPSYS:tl} != sunos\" "+
			"instead of matching against \":Msunos\".",
		"AUTOFIX: filename.mk:3: Replacing \"empty(OPSYS:tl:Msunos)\" "+
			"with \"${OPSYS:tl} != sunos\".")

	testAfterPrefs(
		".if !empty(OPSYS:O:MUnknown:S,a,b,)",
		".if !empty(OPSYS:O:MUnknown:S,a,b,)",

		"WARN: filename.mk:3: The pattern \"Unknown\" cannot match any of "+
			"{ Cygwin DragonFly FreeBSD Linux NetBSD SunOS } for OPSYS.")

	// The dot is just an ordinary character.
	// It's only special when used in number literals.
	testAfterPrefs(
		".if !empty(PKGPATH:Mcategory/package1.2)",
		".if ${PKGPATH} == category/package1.2",

		"NOTE: filename.mk:3: PKGPATH should be "+
			"compared using \"${PKGPATH} == category/package1.2\" "+
			"instead of matching against \":Mcategory/package1.2\".",
		"AUTOFIX: filename.mk:3: Replacing \"!empty(PKGPATH:Mcategory/package1.2)\" "+
			"with \"${PKGPATH} == category/package1.2\".")

	// Numbers must be enclosed in quotes, otherwise they are compared
	// as numbers, not as strings. The :M and :N modifiers always compare
	// strings.
	testAfterPrefs(
		".if empty(ABI:U:M64)",
		".if ${ABI:U} != \"64\"",

		"NOTE: filename.mk:3: ABI should be compared using \"${ABI:U} != \"64\"\" "+
			"instead of matching against \":M64\".",
		"AUTOFIX: filename.mk:3: Replacing \"empty(ABI:U:M64)\" "+
			"with \"${ABI:U} != \\\"64\\\"\".")

	// Fractional numbers must also be enclosed in quotes.
	testAfterPrefs(
		".if empty(PKGVERSION_NOREV:U:M19.12)",
		".if ${PKGVERSION_NOREV:U} != \"19.12\"",

		"NOTE: filename.mk:3: PKGVERSION_NOREV should be "+
			"compared using \"${PKGVERSION_NOREV:U} != \"19.12\"\" "+
			"instead of matching against \":M19.12\".",
		"WARN: filename.mk:3: PKGVERSION_NOREV should not be used at load time in any file.",
		"AUTOFIX: filename.mk:3: Replacing \"empty(PKGVERSION_NOREV:U:M19.12)\" "+
			"with \"${PKGVERSION_NOREV:U} != \\\"19.12\\\"\".")

	testAfterPrefs(
		".if !empty(PKG_INFO:Mpkg_info)",
		".if ${PKG_INFO} == pkg_info",

		"NOTE: filename.mk:3: PKG_INFO should be "+
			"compared using \"${PKG_INFO} == pkg_info\" "+
			"instead of matching against \":Mpkg_info\".",
		"AUTOFIX: filename.mk:3: "+
			"Replacing \"!empty(PKG_INFO:Mpkg_info)\" "+
			"with \"${PKG_INFO} == pkg_info\".")

	t.CheckEquals(
		G.Pkgsrc.VariableType(nil, "PKG_LIBTOOL").
			Union().Contains(aclpUseLoadtime),
		false)
	testAfterPrefs(
		".if !empty(PKG_LIBTOOL:Npattern)",
		".if !empty(PKG_LIBTOOL:Npattern)",

		// No diagnostics about the :N modifier yet,
		// see MkLineChecker.simplifyCondition.replace.
		"WARN: filename.mk:3: PKG_LIBTOOL should not be used "+
			"at load time in any file.")

	// TODO: Add a note that the :U is unnecessary, and explain why.
	testAfterPrefs(
		".if ${PKGPATH:U:Mcategory/package}",
		".if ${PKGPATH:U} == category/package",

		"NOTE: filename.mk:3: PKGPATH should be "+
			"compared using \"${PKGPATH:U} == category/package\" "+
			"instead of matching against \":Mcategory/package\".",
		"AUTOFIX: filename.mk:3: "+
			"Replacing \"${PKGPATH:U:Mcategory/package}\" "+
			"with \"${PKGPATH:U} == category/package\".")

	testAfterPrefs(
		".if ${UNKNOWN:Mpattern}",
		".if ${UNKNOWN:Mpattern}",

		"WARN: filename.mk:3: UNKNOWN is used but not defined.")

	// MAKE is AlwaysInScope and DefinedIfInScope and NonemptyIfDefined.
	testAfterPrefs(
		".if ${MAKE:Mpattern}",
		".if ${MAKE} == pattern",

		"NOTE: filename.mk:3: MAKE should be "+
			"compared using \"${MAKE} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:3: "+
			"Replacing \"${MAKE:Mpattern}\" "+
			"with \"${MAKE} == pattern\".")

	// VarUse without any modifiers is skipped.
	testAfterPrefs(
		".if ${MAKE}",
		".if ${MAKE}",

		nil...)

	// Special characters must be enclosed in quotes when they are
	// used in string literals.
	// As of December 2019, strings with special characters are not yet
	// replaced automatically, see mkCondLiteralChars.
	// TODO: Add tests for all characters that are special in string literals or patterns.
	// TODO: Then, extend the set of characters for which the expressions are simplified.
	testAfterPrefs(
		".if ${FETCH_CMD:M&&}",
		".if ${FETCH_CMD:M&&}",

		nil...)

	// The + is contained in mkCondStringLiteralUnquoted.
	// The + is contained in mkCondModifierPatternLiteral.
	testAfterPrefs(
		".if ${PKGPATH:Mcategory/gtk+}",
		".if ${PKGPATH} == category/gtk+",

		"NOTE: filename.mk:3: PKGPATH should be "+
			"compared using \"${PKGPATH} == category/gtk+\" "+
			"instead of matching against \":Mcategory/gtk+\".",
		"AUTOFIX: filename.mk:3: "+
			"Replacing \"${PKGPATH:Mcategory/gtk+}\" "+
			"with \"${PKGPATH} == category/gtk+\".")

	// The characters <=> may be used unescaped in :M and :N patterns
	// but not in .if conditions. There they must be enclosed in quotes.
	testAfterPrefs(
		".if ${PKGPATH:M<=>}",
		".if ${PKGPATH} == \"<=>\"",

		"WARN: filename.mk:3: The pathname pattern \"<=>\" "+
			"contains the invalid characters \"<=>\".",
		"NOTE: filename.mk:3: PKGPATH should be "+
			"compared using \"${PKGPATH} == \"<=>\"\" "+
			"instead of matching against \":M<=>\".",
		"AUTOFIX: filename.mk:3: "+
			"Replacing \"${PKGPATH:M<=>}\" "+
			"with \"${PKGPATH} == \\\"<=>\\\"\".")

	// If pkglint replaces this particular pattern, the resulting string
	// literal must be escaped properly.
	testAfterPrefs(
		".if ${PKGPATH:M\"}",
		".if ${PKGPATH:M\"}",

		// TODO: Find a better variable than PKGPATH,
		//  to get rid of this unrelated warning.
		"WARN: filename.mk:3: The pathname pattern \"\\\"\" "+
			"contains the invalid character \"\\\"\".")
}

func (s *Suite) Test_MkCondChecker_simplifyCondition__defined_in_same_file(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.Chdir("category/package")
	t.FinishSetUp()

	// before: the directive before the condition is simplified
	// after: the directive after the condition is simplified
	test := func(before, after string, diagnostics ...string) {
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
		//
		// TODO: Replace MkLines.Check this with a more specific method.

		t.ExpectDiagnosticsAutofix(
			mklines.Check,
			diagnostics...)

		// TODO: Move this assertion above the assertion about the diagnostics.
		afterMklines := LoadMk(t.File("filename.mk"), MustSucceed)
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

		"NOTE: filename.mk:4: OK_DIR should be "+
			"compared using \"${OK_DIR} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:4: "+
			"Replacing \"${OK_DIR:Mpattern}\" "+
			"with \"${OK_DIR} == pattern\".")

	// LATER_DIR is defined later than the .if condition,
	// therefore at the time of the .if statement, it is still empty.
	test(
		".if ${LATER_DIR:Mpattern}",
		".if ${LATER_DIR} == pattern",

		// FIXME: Warn that LATER_DIR is used before it is defined.
		// FIXME: Add :U modifier since LATER_DIR is not yet defined.
		"NOTE: filename.mk:4: LATER_DIR should be "+
			"compared using \"${LATER_DIR} == pattern\" "+
			"instead of matching against \":Mpattern\".",
		"AUTOFIX: filename.mk:4: "+
			"Replacing \"${LATER_DIR:Mpattern}\" "+
			"with \"${LATER_DIR} == pattern\".")
}

func (s *Suite) Test_MkCondChecker_checkDirectiveCondCompare(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	test := func(cond string, output ...string) {
		mklines := t.NewMkLines("filename.mk",
			cond)
		mklines.ForEach(func(mkline *MkLine) {
			NewMkCondChecker(mkline, mklines).checkDirectiveCond()
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

func (s *Suite) Test_MkCondChecker_checkDirectiveCondCompareVarStr__no_tracing(c *check.C) {
	t := s.Init(c)
	b := NewMkTokenBuilder()

	t.SetUpVartypes()
	mklines := t.NewMkLines("filename.mk",
		".if ${DISTFILES:Mpattern:O:u} == NetBSD")
	t.DisableTracing()

	ck := NewMkCondChecker(mklines.mklines[0], mklines)
	varUse := b.VarUse("DISTFILES", "Mpattern", "O", "u")
	// TODO: mklines.ForEach
	ck.checkDirectiveCondCompareVarStr(varUse, "==", "distfile-1.0.tar.gz")

	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkCondChecker_checkCompareVarStr(c *check.C) {
	t := s.Init(c)

	test := func() {
		// FIXME
		t.CheckEquals(true, true)
	}

	test()
}

func (s *Suite) Test_MkCondChecker_checkCompareVarStrCompiler(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.Chdir("category/package")
	t.FinishSetUp()

	test := func(cond string, diagnostics ...string) {
		mklines := t.SetUpFileMkLines("filename.mk",
			MkCvsID,
			"",
			".include \"../../mk/bsd.fast.prefs.mk\"",
			"",
			".if "+cond,
			".endif")

		t.SetUpCommandLine("-Wall")
		mklines.Check()
		t.SetUpCommandLine("-Wall", "--autofix")
		mklines.Check()

		t.CheckOutput(diagnostics)
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
