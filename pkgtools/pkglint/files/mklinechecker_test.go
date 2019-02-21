package pkglint

import "gopkg.in/check.v1"

func (s *Suite) Test_MkLineChecker_checkVarassignLeft(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("module.mk", 123, "_VARNAME=\tvalue")

	MkLineChecker{mkline}.checkVarassignLeft()

	t.CheckOutputLines(
		"WARN: module.mk:123: Variable names starting with an underscore "+
			"(_VARNAME) are reserved for internal pkgsrc use.",
		"WARN: module.mk:123: _VARNAME is defined but not used.")
}

func (s *Suite) Test_MkLineChecker_Check__url2pkg(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	mkline := t.NewMkLine("filename.mk", 1, "# url2pkg-marker")

	MkLineChecker{mkline}.Check()

	t.CheckOutputLines(
		"ERROR: filename.mk:1: This comment indicates unfinished work (url2pkg).")
}

func (s *Suite) Test_MkLineChecker_Check__buildlink3_include_prefs(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	t.CreateFileLines("mk/bsd.prefs.mk")
	t.CreateFileLines("mk/bsd.fast.prefs.mk")
	mklines := t.SetUpFileMkLines("category/package/buildlink3.mk",
		MkRcsID,
		".include \"../../mk/bsd.prefs.mk\"",
		".include \"../../mk/bsd.fast.prefs.mk\"")

	// If the buildlink3.mk file doesn't actually exist, resolving the
	// relative path fails since that depends on the actual file system,
	// not on syntactical paths; see os.Stat in CheckRelativePath.
	//
	// TODO: Refactor relpath to be independent of a filesystem.

	mklines.Check()

	t.CheckOutputLines(
		"NOTE: ~/category/package/buildlink3.mk:2: For efficiency reasons, " +
			"please include bsd.fast.prefs.mk instead of bsd.prefs.mk.")
}

func (s *Suite) Test_MkLineChecker_checkInclude(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	t.CreateFileLines("pkgtools/x11-links/buildlink3.mk")
	t.CreateFileLines("graphics/jpeg/buildlink3.mk")
	t.CreateFileLines("devel/intltool/buildlink3.mk")
	t.CreateFileLines("devel/intltool/builtin.mk")
	mklines := t.SetUpFileMkLines("category/package/filename.mk",
		MkRcsID,
		"",
		".include \"../../pkgtools/x11-links/buildlink3.mk\"",
		".include \"../../graphics/jpeg/buildlink3.mk\"",
		".include \"../../devel/intltool/buildlink3.mk\"",
		".include \"../../devel/intltool/builtin.mk\"")

	mklines.Check()

	t.CheckOutputLines(
		"ERROR: ~/category/package/filename.mk:3: "+
			"../../pkgtools/x11-links/buildlink3.mk must not be included directly. "+
			"Include \"../../mk/x11.buildlink3.mk\" instead.",
		"ERROR: ~/category/package/filename.mk:4: "+
			"../../graphics/jpeg/buildlink3.mk must not be included directly. "+
			"Include \"../../mk/jpeg.buildlink3.mk\" instead.",
		"WARN: ~/category/package/filename.mk:5: "+
			"Please write \"USE_TOOLS+= intltool\" instead of this line.",
		"ERROR: ~/category/package/filename.mk:6: "+
			"../../devel/intltool/builtin.mk must not be included directly. "+
			"Include \"../../devel/intltool/buildlink3.mk\" instead.")
}

func (s *Suite) Test_MkLineChecker_checkInclude__Makefile(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine(t.File("Makefile"), 2, ".include \"../../other/package/Makefile\"")

	MkLineChecker{mkline}.checkInclude()

	t.CheckOutputLines(
		"ERROR: ~/Makefile:2: Relative path \"../../other/package/Makefile\" does not exist.",
		"ERROR: ~/Makefile:2: Other Makefiles must not be included directly.")
}

func (s *Suite) Test_MkLineChecker_checkInclude__Makefile_exists(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("other/existing/Makefile")
	t.SetUpPackage("category/package",
		".include \"../../other/existing/Makefile\"",
		".include \"../../other/not-found/Makefile\"")

	G.checkdirPackage(t.File("category/package"))

	t.CheckOutputLines(
		"ERROR: ~/category/package/Makefile:20: Cannot read \"../../other/existing/Makefile\".")
}

func (s *Suite) Test_MkLineChecker_checkDirective(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	mklines := t.NewMkLines("category/package/filename.mk",
		MkRcsID,
		"",
		".for",
		".endfor",
		"",
		".if",
		".else don't",
		".endif invalid-arg",
		"",
		".ifdef FNAME_MK",
		".endif",
		".ifndef FNAME_MK",
		".endif",
		"",
		".for var in a b c",
		".endfor",
		".undef var unrelated")

	mklines.Check()

	t.CheckOutputLines(
		"ERROR: category/package/filename.mk:3: \".for\" requires arguments.",
		"ERROR: category/package/filename.mk:6: \".if\" requires arguments.",
		"ERROR: category/package/filename.mk:7: \".else\" does not take arguments. "+
			"If you meant \"else if\", use \".elif\".",
		"ERROR: category/package/filename.mk:8: \".endif\" does not take arguments.",
		"WARN: category/package/filename.mk:10: The \".ifdef\" directive is deprecated. "+
			"Please use \".if defined(FNAME_MK)\" instead.",
		"WARN: category/package/filename.mk:12: The \".ifndef\" directive is deprecated. "+
			"Please use \".if !defined(FNAME_MK)\" instead.",
		"NOTE: category/package/filename.mk:17: Using \".undef\" after a \".for\" loop is unnecessary.")
}

func (s *Suite) Test_MkLineChecker_checkDirective__for_loop_varname(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	mklines := t.NewMkLines("filename.mk",
		MkRcsID,
		"",
		".for VAR in a b c", // Should be lowercase.
		".endfor",
		"",
		".for _var_ in a b c", // Should be written without underscores.
		".endfor",
		"",
		".for .var. in a b c", // Should be written without dots.
		".endfor",
		"",
		".for ${VAR} in a b c", // The variable name really must be an identifier.
		".endfor")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: filename.mk:3: The variable name \"VAR\" in the .for loop should not contain uppercase letters.",
		"WARN: filename.mk:6: Variable names starting with an underscore (_var_) are reserved for internal pkgsrc use.",
		"ERROR: filename.mk:9: Invalid variable name \".var.\".",
		"ERROR: filename.mk:12: Invalid variable name \"${VAR}\".")
}

func (s *Suite) Test_MkLineChecker_checkDirectiveEnd__ending_comments(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("opsys.mk",
		MkRcsID,
		"",
		".for i in 1 2 3 4 5",
		".  if ${OPSYS} == NetBSD",
		".    if ${MACHINE_ARCH} == x86_64",
		".      if ${OS_VERSION:M8.*}",
		".      endif # MACHINE_ARCH", // Wrong, should be OS_VERSION.
		".    endif # OS_VERSION",     // Wrong, should be MACHINE_ARCH.
		".  endif # OPSYS",            // Correct.
		".endfor # j",                 // Wrong, should be i.
		"",
		".if ${PKG_OPTIONS:Moption}",
		".endif # option", // Correct.
		"",
		".if ${PKG_OPTIONS:Moption}",
		".endif # opti", // This typo goes unnoticed since "opti" is a substring of the condition.
		"",
		".if ${OPSYS} == NetBSD",
		".elif ${OPSYS} == FreeBSD",
		".endif # NetBSD", // Wrong, should be FreeBSD from the .elif.
		"",
		".for ii in 1 2",
		".  for jj in 1 2",
		".  endfor # ii", // Note: a simple "i" would not generate a warning because it is found in the word "in".
		".endfor # ii")

	// See MkLineChecker.checkDirective
	mklines.Check()

	t.CheckOutputLines(
		"WARN: opsys.mk:7: Comment \"MACHINE_ARCH\" does not match condition \"${OS_VERSION:M8.*}\".",
		"WARN: opsys.mk:8: Comment \"OS_VERSION\" does not match condition \"${MACHINE_ARCH} == x86_64\".",
		"WARN: opsys.mk:10: Comment \"j\" does not match loop \"i in 1 2 3 4 5\".",
		"WARN: opsys.mk:12: Unknown option \"option\".",
		"WARN: opsys.mk:20: Comment \"NetBSD\" does not match condition \"${OPSYS} == FreeBSD\".",
		"WARN: opsys.mk:24: Comment \"ii\" does not match loop \"jj in 1 2\".")
}

func (s *Suite) Test_MkLineChecker_checkDirectiveFor(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/file.mk",
		MkRcsID,
		".for i = 1 2 3", // The "=" should rather be "in".
		".endfor",
		"",
		".for _i_ in 1 2 3", // Underscores are only allowed in infrastructure files.
		".endfor")

	G.Check(t.File("mk/file.mk"))

	// Pkglint doesn't care about trivial syntax errors, bmake will already catch these.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLineChecker_checkDependencyRule(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	mklines := t.NewMkLines("category/package/filename.mk",
		MkRcsID,
		"",
		".PHONY: target-1",
		"target-2: .PHONY",
		".ORDER: target-1 target-2",
		"target-1:",
		"target-2:",
		"target-3:")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: category/package/filename.mk:8: Undeclared target \"target-3\".")
}

func (s *Suite) Test_MkLineChecker_checkVartype__simple_type(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	// Since COMMENT is defined in vardefs.go its type is certain instead of guessed.
	vartype := G.Pkgsrc.VariableType("COMMENT")

	c.Assert(vartype, check.NotNil)
	c.Check(vartype.basicType.name, equals, "Comment")
	c.Check(vartype.guessed, equals, false)
	c.Check(vartype.kindOfList, equals, lkNone)

	mkline := t.NewMkLine("Makefile", 123, "COMMENT=\tA nice package")
	MkLineChecker{mkline}.checkVartype(mkline.Varname(), mkline.Op(), mkline.Value(), mkline.VarassignComment())

	t.CheckOutputLines(
		"WARN: Makefile:123: COMMENT should not begin with \"A\".")
}

func (s *Suite) Test_MkLineChecker_checkVartype(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mkline := t.NewMkLine("filename", 1, "DISTNAME=gcc-${GCC_VERSION}")

	MkLineChecker{mkline}.checkVartype("DISTNAME", opAssign, "gcc-${GCC_VERSION}", "")

	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLineChecker_checkVartype__append_to_non_list(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("filename.mk",
		MkRcsID,
		"DISTNAME+=\tsuffix",
		"COMMENT=\tComment for",
		"COMMENT+=\tthe package")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: filename.mk:2: The variable DISTNAME may not be appended to "+
			"(only set, or given a default value) in this file.",
		"WARN: filename.mk:2: The \"+=\" operator should only be used with lists, not with DISTNAME.")
}

// Pkglint once interpreted all lists as consisting of shell tokens,
// splitting this URL at the ampersand.
func (s *Suite) Test_MkLineChecker_checkVarassign__URL_with_shell_special_characters(c *check.C) {
	t := s.Init(c)

	G.Pkg = NewPackage(t.File("graphics/gimp-fix-ca"))
	t.SetUpVartypes()
	mkline := t.NewMkLine("filename", 10, "MASTER_SITES=http://registry.gimp.org/file/fix-ca.c?action=download&id=9884&file=")

	MkLineChecker{mkline}.checkVarassign()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLineChecker_checkDirectiveCond(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	test := func(cond string, output ...string) {
		MkLineChecker{t.NewMkLine("filename", 1, cond)}.checkDirectiveCond()
		if len(output) > 0 {
			t.CheckOutputLines(output...)
		} else {
			t.CheckOutputEmpty()
		}
	}

	test(".if !empty(PKGSRC_COMPILER:Mmycc)",
		"WARN: filename:1: The pattern \"mycc\" cannot match any of "+
			"{ ccache ccc clang distcc f2c gcc hp icc ido "+
			"mipspro mipspro-ucode pcc sunpro xlc } for PKGSRC_COMPILER.")

	test(".elif ${A} != ${B}",
		"WARN: filename:1: A is used but not defined.",
		"WARN: filename:1: B is used but not defined.")

	test(".if ${HOMEPAGE} == \"mailto:someone@example.org\"",
		"WARN: filename:1: \"mailto:someone@example.org\" is not a valid URL.",
		"WARN: filename:1: HOMEPAGE should not be evaluated at load time.",
		"WARN: filename:1: HOMEPAGE may not be used in any file; it is a write-only variable.")

	test(".if !empty(PKGSRC_RUN_TEST:M[Y][eE][sS])",
		"WARN: filename:1: PKGSRC_RUN_TEST should be matched "+
			"against \"[yY][eE][sS]\" or \"[nN][oO]\", not \"[Y][eE][sS]\".")

	test(".if !empty(IS_BUILTIN.Xfixes:M[yY][eE][sS])",
		"WARN: filename:1: IS_BUILTIN.Xfixes should not be evaluated at load time.",
		"WARN: filename:1: IS_BUILTIN.Xfixes may not be used in this file; it would be ok in builtin.mk.")

	test(".if !empty(${IS_BUILTIN.Xfixes:M[yY][eE][sS]})",
		"WARN: filename:1: The empty() function takes a variable name as parameter, "+
			"not a variable expression.",
		"WARN: filename:1: IS_BUILTIN.Xfixes should not be evaluated at load time.",
		"WARN: filename:1: IS_BUILTIN.Xfixes may not be used in this file; it would be ok in builtin.mk.")

	test(".if ${PKGSRC_COMPILER} == \"msvc\"",
		"WARN: filename:1: \"msvc\" is not valid for PKGSRC_COMPILER. "+
			"Use one of { ccache ccc clang distcc f2c gcc hp icc ido mipspro mipspro-ucode pcc sunpro xlc } instead.",
		"WARN: filename:1: Use ${PKGSRC_COMPILER:Mmsvc} instead of the == operator.")

	test(".if ${PKG_LIBTOOL:Mlibtool}",
		"NOTE: filename:1: PKG_LIBTOOL should be compared using == instead of matching against \":Mlibtool\".",
		"WARN: filename:1: PKG_LIBTOOL should not be evaluated at load time.",
		"WARN: filename:1: PKG_LIBTOOL may not be used in any file; it is a write-only variable.")

	test(".if ${MACHINE_PLATFORM:MUnknownOS-*-*} || ${MACHINE_ARCH:Mx86}",
		"WARN: filename:1: "+
			"The pattern \"UnknownOS\" cannot match any of "+
			"{ AIX BSDOS Bitrig Cygwin Darwin DragonFly FreeBSD FreeMiNT GNUkFreeBSD HPUX Haiku "+
			"IRIX Interix Linux Minix MirBSD NetBSD OSF1 OpenBSD QNX SCO_SV SunOS UnixWare "+
			"} for the operating system part of MACHINE_PLATFORM.",
		"WARN: filename:1: "+
			"The pattern \"x86\" cannot match any of "+
			"{ aarch64 aarch64eb alpha amd64 arc arm arm26 arm32 cobalt coldfire convex dreamcast earm "+
			"earmeb earmhf earmhfeb earmv4 earmv4eb earmv5 earmv5eb earmv6 earmv6eb earmv6hf earmv6hfeb "+
			"earmv7 earmv7eb earmv7hf earmv7hfeb evbarm hpcmips hpcsh hppa hppa64 i386 i586 i686 ia64 "+
			"m68000 m68k m88k mips mips64 mips64eb mips64el mipseb mipsel mipsn32 mlrisc ns32k pc532 pmax "+
			"powerpc powerpc64 rs6000 s390 sh3eb sh3el sparc sparc64 vax x86_64 "+
			"} for MACHINE_ARCH.",
		"NOTE: filename:1: MACHINE_ARCH should be compared using == instead of matching against \":Mx86\".")

	test(".if ${MASTER_SITES:Mftp://*} == \"ftp://netbsd.org/\"",
		"WARN: filename:1: MASTER_SITES should not be evaluated at load time.",
		"WARN: filename:1: MASTER_SITES may not be used in any file; it is a write-only variable.")

	// The only interesting line from the below tracing output is the one
	// containing "checkCompareVarStr".
	t.EnableTracingToLog()
	test(".if ${VAR:Mpattern1:Mpattern2} == comparison",
		"TRACE: + MkLineChecker.checkDirectiveCond(\"${VAR:Mpattern1:Mpattern2} == comparison\")",
		"TRACE: 1 + (*MkParser).mkCondAtom(\"${VAR:Mpattern1:Mpattern2} == comparison\")",
		"TRACE: 1 - (*MkParser).mkCondAtom(\"${VAR:Mpattern1:Mpattern2} == comparison\")",
		"TRACE: 1   checkCompareVarStr ${VAR:Mpattern1:Mpattern2} == comparison",
		"TRACE: 1 + MkLineChecker.CheckVaruse(filename:1, ${VAR:Mpattern1:Mpattern2}, (no-type time:parse quoting:plain wordpart:false))",
		"TRACE: 1 2 + (*Pkgsrc).VariableType(\"VAR\")",
		"TRACE: 1 2 3   No type definition found for \"VAR\".",
		"TRACE: 1 2 - (*Pkgsrc).VariableType(\"VAR\", \"=>\", (*pkglint.Vartype)(nil))",
		"WARN: filename:1: VAR is used but not defined.",
		"TRACE: 1 2 + MkLineChecker.checkVarusePermissions(\"VAR\", (no-type time:parse quoting:plain wordpart:false))",
		"TRACE: 1 2 3   No type definition found for \"VAR\".",
		"TRACE: 1 2 - MkLineChecker.checkVarusePermissions(\"VAR\", (no-type time:parse quoting:plain wordpart:false))",
		"TRACE: 1 2 + (*MkLineImpl).VariableNeedsQuoting(\"VAR\", (*pkglint.Vartype)(nil), (no-type time:parse quoting:plain wordpart:false))",
		"TRACE: 1 2 - (*MkLineImpl).VariableNeedsQuoting(\"VAR\", (*pkglint.Vartype)(nil), (no-type time:parse quoting:plain wordpart:false), \"=>\", unknown)",
		"TRACE: 1 - MkLineChecker.CheckVaruse(filename:1, ${VAR:Mpattern1:Mpattern2}, (no-type time:parse quoting:plain wordpart:false))",
		"TRACE: - MkLineChecker.checkDirectiveCond(\"${VAR:Mpattern1:Mpattern2} == comparison\")")
	t.EnableSilentTracing()
}

func (s *Suite) Test_MkLineChecker_checkVarassign(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	G.Mk = t.NewMkLines("Makefile",
		MkRcsID,
		"ac_cv_libpari_libs+=\t-L${BUILDLINK_PREFIX.pari}/lib") // From math/clisp-pari/Makefile, rev. 1.8

	MkLineChecker{G.Mk.mklines[1]}.checkVarassign()

	t.CheckOutputLines(
		"WARN: Makefile:2: ac_cv_libpari_libs is defined but not used.")
}

func (s *Suite) Test_MkLineChecker_checkVarassignLeftPermissions(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("awk", "AWK", AtRunTime)
	mklines := t.NewMkLines("options.mk",
		MkRcsID,
		"PKG_DEVELOPER?=\tyes",
		"BUILD_DEFS?=\tVARBASE",
		"USE_TOOLS:=\t${USE_TOOLS:Nunwanted-tool}",
		"USE_TOOLS:=\t${MY_TOOLS}",
		"USE_TOOLS:=\tawk")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: options.mk:2: The variable PKG_DEVELOPER may not be given a default value by any package.",
		"WARN: options.mk:2: Please include \"../../mk/bsd.prefs.mk\" before using \"?=\".",
		"WARN: options.mk:3: The variable BUILD_DEFS may not be given a default value (only appended to) in this file.",
		"WARN: options.mk:5: The variable USE_TOOLS may not be set (only appended to) in this file.",
		"WARN: options.mk:5: MY_TOOLS is used but not defined.",
		"WARN: options.mk:6: The variable USE_TOOLS may not be set (only appended to) in this file.")
}

func (s *Suite) Test_MkLineChecker_checkVarassignLeftPermissions__no_tracing(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.DisableTracing() // Just to reach branch coverage for unknown permissions.
	mklines := t.NewMkLines("options.mk",
		MkRcsID,
		"COMMENT=\tShort package description")

	mklines.Check()
}

// Don't check the permissions for infrastructure files since they have their own rules.
func (s *Suite) Test_MkLineChecker_checkVarassignLeftPermissions__infrastructure(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.CreateFileLines("mk/infra.mk",
		MkRcsID,
		"",
		"PKG_DEVELOPER?=\tyes")
	t.CreateFileLines("mk/bsd.pkg.mk")

	G.Check(t.File("mk/infra.mk"))

	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLineChecker_checkVarassignRightVaruse(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	mkline := t.NewMkLine("module.mk", 123, "PLIST_SUBST+=\tLOCALBASE=${LOCALBASE:Q}")

	MkLineChecker{mkline}.checkVarassignRightVaruse()

	t.CheckOutputLines(
		"WARN: module.mk:123: Please use PREFIX instead of LOCALBASE.",
		"NOTE: module.mk:123: The :Q operator isn't necessary for ${LOCALBASE} here.")
}

func (s *Suite) Test_MkLineChecker_checkVarusePermissions(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("options.mk",
		MkRcsID,
		"COMMENT=\t${GAMES_USER}",
		"COMMENT:=\t${PKGBASE}",
		"PYPKGPREFIX=\t${PKGBASE}")
	G.Pkgsrc.loadDefaultBuildDefs()
	G.Pkgsrc.UserDefinedVars.Define("GAMES_USER", mklines.mklines[0])

	mklines.Check()

	t.CheckOutputLines(
		"WARN: options.mk:3: PKGBASE should not be evaluated at load time.",
		"WARN: options.mk:4: The variable PYPKGPREFIX may not be set in this file; it would be ok in pyversion.mk.",
		"WARN: options.mk:4: PKGBASE should not be evaluated indirectly at load time.")
}

func (s *Suite) Test_MkLineChecker_checkVarusePermissions__explain(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--explain")
	t.SetUpVartypes()
	mklines := t.NewMkLines("options.mk",
		MkRcsID,
		"COMMENT=\t${GAMES_USER}",
		"COMMENT:=\t${PKGBASE}",
		"PYPKGPREFIX=\t${PKGBASE}")
	G.Pkgsrc.loadDefaultBuildDefs()
	G.Pkgsrc.UserDefinedVars.Define("GAMES_USER", mklines.mklines[0])

	mklines.Check()

	t.CheckOutputLines(
		"WARN: options.mk:3: PKGBASE should not be evaluated at load time.",
		"",
		"\tMany variables, especially lists of something, get their values",
		"\tincrementally. Therefore it is generally unsafe to rely on their",
		"\tvalue until it is clear that it will never change again. This point",
		"\tis reached when the whole package Makefile is loaded and execution",
		"\tof the shell commands starts; in some cases earlier.",
		"",
		"\tAdditionally, when using the \":=\" operator, each $$ is replaced with",
		"\ta single $, so variables that have references to shell variables or",
		"\tregular expressions are modified in a subtle way.",
		"",
		"WARN: options.mk:4: The variable PYPKGPREFIX may not be set in this file; it would be ok in pyversion.mk.",
		"",
		"\tThe allowed actions for a variable are determined based on the file",
		"\tname in which the variable is used or defined. The rules for",
		"\tPYPKGPREFIX are:",
		"",
		"\t* in pyversion.mk, it may be set",
		"\t* in any file, it may be used at load time, or used",
		"",
		"\tIf these rules seem to be incorrect, please ask on the",
		"\ttech-pkg@NetBSD.org mailing list.",
		"",
		"WARN: options.mk:4: PKGBASE should not be evaluated indirectly at load time.",
		"",
		"\tThe variable on the left-hand side may be evaluated at load time,",
		"\tbut the variable on the right-hand side may not. Because of the",
		"\tassignment in this line, the variable might be used indirectly at",
		"\tload time, before it is guaranteed to be properly initialized.",
		"")
}

func (s *Suite) Test_MkLineChecker_explainPermissions(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--explain")
	t.SetUpVartypes()

	mkline := t.NewMkLine("buildlink3.mk", 123, "AUTO_MKDIRS=\tyes")

	MkLineChecker{mkline}.Check()

	t.CheckOutputLines(
		"WARN: buildlink3.mk:123: The variable AUTO_MKDIRS may not be set in this file; "+
			"it would be ok in Makefile, Makefile.* or *.mk.",
		"",
		"\tThe allowed actions for a variable are determined based on the file",
		"\tname in which the variable is used or defined. The rules for",
		"\tAUTO_MKDIRS are:",
		"",
		"\t* in Makefile, it may be set, or used",
		"\t* in buildlink3.mk, it may not be accessed at all",
		"\t* in builtin.mk, it may not be accessed at all",
		"\t* in Makefile.*, it may be set, given a default value, or used",
		"\t* in *.mk, it may be set, given a default value, or used",
		"",
		"\tIf these rules seem to be incorrect, please ask on the",
		"\ttech-pkg@NetBSD.org mailing list.",
		"")
}

func (s *Suite) Test_MkLineChecker_checkVarusePermissions__load_time(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("options.mk",
		MkRcsID,
		"WRKSRC:=${.CURDIR}",
		".if ${PKG_SYSCONFDIR.gdm} != \"etc\"",
		".endif")

	mklines.Check()

	// Evaluating PKG_SYSCONFDIR.* at load time is probably ok,
	// though pkglint cannot prove anything here.
	//
	// Evaluating .CURDIR at load time is definitely ok since it is defined from the beginning.
	t.CheckOutputLines(
		"NOTE: options.mk:2: This variable value should be aligned to column 17.")
}

func (s *Suite) Test_MkLineChecker_checkVarusePermissions__load_time_guessed(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("install", "", AtRunTime)
	mklines := t.NewMkLines("install-docfiles.mk",
		MkRcsID,
		"DOCFILES=\ta b c",
		"do-install:",
		".for f in ${DOCFILES}",
		"\tinstall -c ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${f}",
		".endfor")

	mklines.Check()

	// No warning for using DOCFILES at compile-time. Since the variable
	// name is not one of the predefined names from vardefs.go, the
	// variable's type is guessed based on the name (see
	// Pkgsrc.VariableType).
	//
	// These guessed variables are typically defined and used only in
	// a single file, and in this context, mistakes are usually found
	// quickly.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLineChecker_checkVarusePermissions__PKGREVISION(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("any.mk",
		MkRcsID,
		// PKGREVISION may only be set in Makefile, not used at load time; see vardefs.go.
		".if defined(PKGREVISION)",
		".endif")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: any.mk:2: PKGREVISION should not be evaluated at load time.",
		"WARN: any.mk:2: PKGREVISION may not be used in any file; it is a write-only variable.")
}

func (s *Suite) Test_MkLineChecker_checkVarusePermissions__indirectly(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("file.mk",
		MkRcsID,
		"IGNORE_PKG.package=\t${ONLY_FOR_UNPRIVILEGED}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: file.mk:2: IGNORE_PKG.package should be set to YES or yes.",
		"WARN: file.mk:2: ONLY_FOR_UNPRIVILEGED should not be evaluated indirectly at load time.")
}

func (s *Suite) Test_MkLineChecker_warnVaruseToolLoadTime(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("nowhere", "NOWHERE", Nowhere)
	t.SetUpTool("after-prefs", "AFTER_PREFS", AfterPrefsMk)
	t.SetUpTool("at-runtime", "AT_RUNTIME", AtRunTime)
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		".if ${NOWHERE} && ${AFTER_PREFS} && ${AT_RUNTIME} && ${MK_TOOL}",
		".endif",
		"",
		"TOOLS_CREATE+=\t\tmk-tool",
		"_TOOLS_VARNAME.mk-tool=\tMK_TOOL")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:2: To use the tool ${NOWHERE} at load time, "+
			"it has to be added to USE_TOOLS before including bsd.prefs.mk.",
		"WARN: Makefile:2: To use the tool ${AFTER_PREFS} at load time, "+
			"bsd.prefs.mk has to be included before.",
		"WARN: Makefile:2: The tool ${AT_RUNTIME} cannot be used at load time.",
		"WARN: Makefile:2: To use the tool ${MK_TOOL} at load time, "+
			"bsd.prefs.mk has to be included before.",
		"WARN: Makefile:6: Variable names starting with an underscore "+
			"(_TOOLS_VARNAME.mk-tool) are reserved for internal pkgsrc use.",
		"WARN: Makefile:6: _TOOLS_VARNAME.mk-tool is defined but not used.")
}

func (s *Suite) Test_MkLineChecker_Check__warn_varuse_LOCALBASE(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mkline := t.NewMkLine("options.mk", 56, "PKGNAME=${LOCALBASE}")

	MkLineChecker{mkline}.Check()

	t.CheckOutputLines(
		"WARN: options.mk:56: Please use PREFIX instead of LOCALBASE.")
}

func (s *Suite) Test_MkLineChecker_CheckRelativePkgdir(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("other/package/Makefile")
	// Must be in the filesystem because of directory references.
	mklines := t.SetUpFileMkLines("category/package/Makefile",
		"# dummy")
	ck := MkLineChecker{mklines.mklines[0]}

	ck.CheckRelativePkgdir("../pkgbase")
	ck.CheckRelativePkgdir("../../other/package")
	ck.CheckRelativePkgdir("../../other/does-not-exist")

	// FIXME: The diagnostics for does-not-exist are redundant.
	t.CheckOutputLines(
		"ERROR: ~/category/package/Makefile:1: Relative path \"../pkgbase\" does not exist.",
		"WARN: ~/category/package/Makefile:1: \"../pkgbase\" is not a valid relative package directory.",
		"ERROR: ~/category/package/Makefile:1: Relative path \"../../other/does-not-exist\" does not exist.",
		"ERROR: ~/category/package/Makefile:1: There is no package in \"other/does-not-exist\".")
}

// PR pkg/46570, item 2
func (s *Suite) Test_MkLineChecker__unclosed_varuse(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"EGDIRS=\t${EGDIR/apparmor.d ${EGDIR/dbus-1/system.d ${EGDIR/pam.d")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:2: EGDIRS is defined but not used.",
		"WARN: Makefile:2: Unclosed Make variable starting at \"${EGDIR/apparmor.d $...\".",

		// XXX: This warning is redundant because of the "Unclosed" warning above.
		"WARN: Makefile:2: Internal pkglint error in MkLine.Tokenize at "+
			"\"${EGDIR/apparmor.d ${EGDIR/dbus-1/system.d ${EGDIR/pam.d\".")
}

func (s *Suite) Test_MkLineChecker_Check__varuse_modifier_L(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("x11/xkeyboard-config/Makefile",
		"FILES_SUBST+=XKBCOMP_SYMLINK=${${XKBBASE}/xkbcomp:L:Q}",
		"FILES_SUBST+=XKBCOMP_SYMLINK=${${XKBBASE}/xkbcomp:Q}")

	MkLineChecker{mklines.mklines[0]}.Check()
	MkLineChecker{mklines.mklines[1]}.Check()

	// In line 1, don't warn that ${XKBBASE}/xkbcomp is used but not defined.
	// This is because the :L modifier interprets everything before as an expression
	// instead of a variable name.
	//
	// In line 2 the :L modifier is missing, therefore ${XKBBASE}/xkbcomp is the
	// name of another variable, and that variable is not known. Only XKBBASE is known.
	//
	// FIXME: The below warnings are wrong because the MkParser does not recognize the
	//  slash as part of a variable name. Because of that, parsing stops before the $.
	//  The warning "Unclosed Make variable" wrongly assumes that any parse error from
	//  a variable use is because of unclosed braces, which it isn't in this case.
	t.CheckOutputLines(
		"WARN: x11/xkeyboard-config/Makefile:2: Unclosed Make variable starting at \"${${XKBBASE}/xkbcomp...\".",
		"WARN: x11/xkeyboard-config/Makefile:2: Unclosed Make variable starting at \"${${XKBBASE}/xkbcomp...\".")
}

func (s *Suite) Test_MkLineChecker_checkDirectiveCond__comparison_with_shell_command(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("security/openssl/Makefile",
		MkRcsID,
		".if ${PKGSRC_COMPILER} == \"gcc\" && ${CC} == \"cc\"",
		".endif")

	mklines.Check()

	// Don't warn about unknown shell command "cc".
	t.CheckOutputLines(
		"WARN: security/openssl/Makefile:2: Use ${PKGSRC_COMPILER:Mgcc} instead of the == operator.")
}

func (s *Suite) Test_MkLineChecker_checkDirectiveCondEmpty(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mkline := t.NewMkLine("module.mk", 123, ".if ${PKGPATH} == \"category/package\"")
	ck := MkLineChecker{mkline}

	// FIXME: checkDirectiveCondEmpty cannot know whether it is empty(...) or !empty(...).
	//  It must know that to generate the proper diagnostics.

	ck.checkDirectiveCondEmpty(NewMkVarUse("PKGPATH", "Mpattern"))

	// When the pattern contains placeholders, it cannot be converted to == or !=.
	ck.checkDirectiveCondEmpty(NewMkVarUse("PKGPATH", "Mpa*n"))

	ck.checkDirectiveCondEmpty(NewMkVarUse("PKGPATH", "tl", "Mpattern"))

	ck.checkDirectiveCondEmpty(NewMkVarUse("PKGPATH", "Ncategory/package"))

	// ${PKGPATH:None:Ntwo} is a short variant of ${PKGPATH} != "one" && ${PKGPATH} != "two",
	// therefore no note is logged in this case.
	ck.checkDirectiveCondEmpty(NewMkVarUse("PKGPATH", "None", "Ntwo"))

	// Note: this combination doesn't make sense since the patterns "one" and "two" don't overlap.
	ck.checkDirectiveCondEmpty(NewMkVarUse("PKGPATH", "Mone", "Mtwo"))

	t.CheckOutputLines(
		"NOTE: module.mk:123: PKGPATH should be compared using == instead of matching against \":Mpattern\".",
		"NOTE: module.mk:123: PKGPATH should be compared using == instead of matching against \":Mpattern\".",
		"NOTE: module.mk:123: PKGPATH should be compared using != instead of matching against \":Ncategory/package\".",
		"NOTE: module.mk:123: PKGPATH should be compared using == instead of matching against \":Mone\".",
		"NOTE: module.mk:123: PKGPATH should be compared using == instead of matching against \":Mtwo\".")
}

func (s *Suite) Test_MkLineChecker_checkDirectiveCond__comparing_PKGSRC_COMPILER_with_eqeq(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	G.Mk = t.NewMkLines("audio/pulseaudio/Makefile",
		MkRcsID,
		".if ${OPSYS} == \"Darwin\" && ${PKGSRC_COMPILER} == \"clang\"",
		".endif")

	G.Mk.Check()

	t.CheckOutputLines(
		"WARN: audio/pulseaudio/Makefile:2: Use ${PKGSRC_COMPILER:Mclang} instead of the == operator.")
}

func (s *Suite) Test_MkLineChecker_checkVartype__CFLAGS_with_backticks(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	G.Mk = t.NewMkLines("chat/pidgin-icb/Makefile",
		MkRcsID,
		"CFLAGS+=\t`pkg-config pidgin --cflags`")
	mkline := G.Mk.mklines[1]

	words, rest := splitIntoMkWords(mkline.Line, mkline.Value())

	c.Check(words, deepEquals, []string{"`pkg-config pidgin --cflags`"})
	c.Check(rest, equals, "")

	ck := MkLineChecker{G.Mk.mklines[1]}
	ck.checkVartype("CFLAGS", opAssignAppend, "`pkg-config pidgin --cflags`", "")

	// No warning about "`pkg-config" being an unknown CFlag.
	t.CheckOutputEmpty()
}

// See PR 46570, Ctrl+F "4. Shell quoting".
// Pkglint is correct, since the shell sees this definition for
// CPPFLAGS as three words, not one word.
func (s *Suite) Test_MkLineChecker_checkVartype__CFLAGS(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"CPPFLAGS.SunOS+=\t-DPIPECOMMAND=\\\"/usr/sbin/sendmail -bs %s\\\"")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:2: Unknown compiler flag \"-bs\".",
		"WARN: Makefile:2: Compiler flag \"%s\\\\\\\"\" should start with a hyphen.")
}

func (s *Suite) Test_MkLineChecker_checkDirectiveIndentation(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("filename.mk", 123, ".if 0")

	// Calling this method is only useful in the context of a whole file.
	MkLineChecker{mkline}.checkDirectiveIndentation(4)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_MkLineChecker_checkDirectiveIndentation__autofix(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--autofix", "-Wspace")
	lines := t.SetUpFileLines("filename.mk",
		MkRcsID,
		".if defined(A)",
		".for a in ${A}",
		".if defined(C)",
		".endif",
		".endfor",
		".endif")
	mklines := NewMkLines(lines)

	mklines.Check()

	t.CheckOutputLines(
		"AUTOFIX: ~/filename.mk:3: Replacing \".\" with \".  \".",
		"AUTOFIX: ~/filename.mk:4: Replacing \".\" with \".    \".",
		"AUTOFIX: ~/filename.mk:5: Replacing \".\" with \".    \".",
		"AUTOFIX: ~/filename.mk:6: Replacing \".\" with \".  \".")
	t.CheckFileLines("filename.mk",
		"# $"+"NetBSD$",
		".if defined(A)",
		".  for a in ${A}",
		".    if defined(C)",
		".    endif",
		".  endfor",
		".endif")
}

// Up to 2018-01-28, pkglint applied the autofix also to the continuation
// lines, which is incorrect. It replaced the dot in "4.*" with spaces.
func (s *Suite) Test_MkLineChecker_checkDirectiveIndentation__autofix_multiline(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--autofix")
	t.SetUpVartypes()
	mklines := t.SetUpFileMkLines("options.mk",
		MkRcsID,
		".if ${PKGNAME} == pkgname",
		".if \\",
		"   ${PLATFORM:MNetBSD-4.*}",
		".endif",
		".endif")

	mklines.Check()

	t.CheckOutputLines(
		"AUTOFIX: ~/options.mk:3: Replacing \".\" with \".  \".",
		"AUTOFIX: ~/options.mk:5: Replacing \".\" with \".  \".")

	t.CheckFileLines("options.mk",
		MkRcsID,
		".if ${PKGNAME} == pkgname",
		".  if \\",
		"   ${PLATFORM:MNetBSD-4.*}",
		".  endif",
		".endif")
}

func (s *Suite) Test_MkLineChecker_CheckVaruseShellword(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.SetUpFileMkLines("options.mk",
		MkRcsID,
		"GOPATH=\t${WRKDIR}",
		"do-build:",
		"\tcd ${WRKSRC} && GOPATH=${GOPATH} PATH=${PATH} :")

	mklines.Check()

	// For WRKSRC and GOPATH, no quoting is necessary since pkgsrc directories by
	// definition don't contain special characters. Therefore they don't need the
	// :Q, not even when used as part of a shell word.

	// For PATH, the quoting is necessary because it may contain directories outside
	// of pkgsrc, and these may contain special characters.

	t.CheckOutputLines(
		"WARN: ~/options.mk:4: The variable PATH should be quoted as part of a shell word.")
}

func (s *Suite) Test_MkLineChecker_CheckVaruseShellword__mstar(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall,no-space")
	t.SetUpVartypes()
	mklines := t.SetUpFileMkLines("options.mk",
		MkRcsID,
		"CONFIGURE_ARGS+=        ${CFLAGS:Q}",
		"CONFIGURE_ARGS+=        ${CFLAGS:M*:Q}",
		"CONFIGURE_ARGS+=        ${ADA_FLAGS:Q}",
		"CONFIGURE_ARGS+=        ${ADA_FLAGS:M*:Q}",
		"CONFIGURE_ENV+=         ${CFLAGS:Q}",
		"CONFIGURE_ENV+=         ${CFLAGS:M*:Q}",
		"CONFIGURE_ENV+=         ${ADA_FLAGS:Q}",
		"CONFIGURE_ENV+=         ${ADA_FLAGS:M*:Q}")

	mklines.Check()

	// FIXME: There should be some notes and warnings about missing :M*;
	//  these are prevented by the PERL5 case in VariableNeedsQuoting.
	t.CheckOutputLines(
		"WARN: ~/options.mk:4: ADA_FLAGS is used but not defined.")
}

func (s *Suite) Test_MkLineChecker_CheckVaruseShellword__mstar_not_needed(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall,no-space")
	pkg := t.SetUpPackage("category/package",
		"MAKE_FLAGS+=\tCFLAGS=${CFLAGS:M*:Q}",
		"MAKE_FLAGS+=\tLFLAGS=${LDFLAGS:M*:Q}")
	G.Pkgsrc.LoadInfrastructure()
	// FIXME: It is too easy to forget this important call.

	// This package is guaranteed to not use GNU_CONFIGURE.
	// Since the :M* hack is only needed for GNU_CONFIGURE, it is not necessary here.
	G.Check(pkg)

	// FIXME: Duplicate diagnostics.
	t.CheckOutputLines(
		"NOTE: ~/category/package/Makefile:20: The :M* modifier is not needed here.",
		"NOTE: ~/category/package/Makefile:20: The :M* modifier is not needed here.",
		"NOTE: ~/category/package/Makefile:21: The :M* modifier is not needed here.",
		"NOTE: ~/category/package/Makefile:21: The :M* modifier is not needed here.")
}

func (s *Suite) Test_MkLineChecker_CheckVaruseShellword__q_not_needed(c *check.C) {
	t := s.Init(c)

	pkg := t.SetUpPackage("category/package",
		"MASTER_SITES=\t${HOMEPAGE:Q}")
	G.Pkgsrc.LoadInfrastructure()

	G.Check(pkg)

	t.CheckOutputLines(
		"NOTE: ~/category/package/Makefile:6: The :Q operator isn't necessary for ${HOMEPAGE} here.")
}

// The ${VARNAME:=suffix} expression should only be used with lists.
// It typically appears in MASTER_SITE definitions.
func (s *Suite) Test_MkLineChecker_CheckVaruse__eq_nonlist(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpMasterSite("MASTER_SITE_GITHUB", "https://github.com/")
	mklines := t.SetUpFileMkLines("options.mk",
		MkRcsID,
		"WRKSRC=\t\t${WRKDIR:=/subdir}",
		"MASTER_SITES=\t${MASTER_SITE_GITHUB:=organization/}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: ~/options.mk:2: The :from=to modifier should only be used with lists, not with WRKDIR.")
}

func (s *Suite) Test_MkLineChecker_CheckVaruse__for(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpMasterSite("MASTER_SITE_GITHUB", "https://github.com/")
	mklines := t.SetUpFileMkLines("options.mk",
		MkRcsID,
		".for var in a b c",
		"\t: ${var}",
		".endfor")

	mklines.Check()

	t.CheckOutputEmpty()
}

// When a parameterized variable is defined in the pkgsrc infrastructure,
// it does not generate a warning about being "used but not defined".
// Even if the variable parameter differs, like .Linux and .SunOS in this
// case. This pattern is typical for pkgsrc, therefore pkglint doesn't
// check that the variable names match exactly.
func (s *Suite) Test_MkLineChecker_CheckVaruse__varcanon(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpPkgsrc()
	t.CreateFileLines("mk/sys-vars.mk",
		MkRcsID,
		"CPPPATH.Linux=\t/usr/bin/cpp")
	G.Pkgsrc.LoadInfrastructure()

	ck := MkLineChecker{t.NewMkLine("module.mk", 101, "COMMENT=\t${CPPPATH.SunOS}")}

	ck.CheckVaruse(NewMkVarUse("CPPPATH.SunOS"), &VarUseContext{
		vartype: &Vartype{
			kindOfList: lkNone,
			basicType:  BtPathname,
			aclEntries: nil,
			guessed:    true,
		},
		time:       vucTimeRun,
		quoting:    VucQuotPlain,
		IsWordPart: false,
	})

	t.CheckOutputEmpty()
}

// Any variable that is defined in the pkgsrc infrastructure in mk/**/*.mk is
// considered defined, and no "used but not defined" warning is logged for it.
//
// See Pkgsrc.loadUntypedVars.
func (s *Suite) Test_MkLineChecker_CheckVaruse__defined_in_infrastructure(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.SetUpVartypes()
	t.CreateFileLines("mk/deeply/nested/infra.mk",
		MkRcsID,
		"INFRA_VAR?=\tvalue")
	G.Pkgsrc.LoadInfrastructure()
	mklines := t.SetUpFileMkLines("category/package/module.mk",
		MkRcsID,
		"do-fetch:",
		"\t: ${INFRA_VAR} ${UNDEFINED}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: ~/category/package/module.mk:3: UNDEFINED is used but not defined.")
}

func (s *Suite) Test_MkLineChecker_CheckVaruse__build_defs(c *check.C) {
	t := s.Init(c)

	// XXX: This paragraph should not be necessary since VARBASE and X11_TYPE
	// are also defined in vardefs.go.
	t.SetUpPkgsrc()
	t.CreateFileLines("mk/defaults/mk.conf",
		"VARBASE?= /usr/pkg/var")
	G.Pkgsrc.LoadInfrastructure()

	t.SetUpCommandLine("-Wall,no-space")
	t.SetUpVartypes()
	mklines := t.SetUpFileMkLines("options.mk",
		MkRcsID,
		"COMMENT=                ${VARBASE} ${X11_TYPE}",
		"PKG_FAIL_REASON+=       ${VARBASE} ${X11_TYPE}",
		"BUILD_DEFS+=            X11_TYPE")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: ~/options.mk:2: The user-defined variable VARBASE is used but not added to BUILD_DEFS.")
}

// The LOCALBASE variable may be defined and used in the infrastructure.
// It is always equivalent to PREFIX and only exists for historic reasons.
func (s *Suite) Test_MkLineChecker_CheckVaruse__LOCALBASE_in_infrastructure(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/infra.mk",
		MkRcsID,
		"LOCALBASE?=\t${PREFIX}",
		"DEFAULT_PREFIX=\t${LOCALBASE}")
	G.Pkgsrc.LoadInfrastructure()

	G.Check(t.File("mk/infra.mk"))

	// No warnings about LOCALBASE being used; in packages LOCALBASE is deprecated.
	t.CheckOutputLines(
		"WARN: ~/mk/infra.mk:2: PREFIX should not be evaluated indirectly at load time.")
}

func (s *Suite) Test_MkLineChecker_CheckVaruse__user_defined_variable_and_BUILD_DEFS(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/defaults/mk.conf",
		"VARBASE?=\t${PREFIX}/var",
		"PYTHON_VER?=\t36")
	G.Pkgsrc.LoadInfrastructure()
	mklines := t.NewMkLines("file.mk",
		MkRcsID,
		"BUILD_DEFS+=\tPYTHON_VER",
		"\t: ${VARBASE}",
		"\t: ${VARBASE}",
		"\t: ${PYTHON_VER}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: file.mk:3: The user-defined variable VARBASE is used but not added to BUILD_DEFS.")
}

func (s *Suite) Test_MkLineChecker_checkVaruseModifiersSuffix(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("file.mk",
		MkRcsID,
		"\t: ${HOMEPAGE:=subdir/:Q}", // wrong
		"\t: ${BUILD_DIRS:=subdir/}", // correct
		"\t: ${BIN_PROGRAMS:=.exe}")  // unknown since BIN_PROGRAMS doesn't have a type

	mklines.Check()

	t.CheckOutputLines(
		"WARN: file.mk:2: The :from=to modifier should only be used with lists, not with HOMEPAGE.",
		"WARN: file.mk:4: BIN_PROGRAMS is used but not defined.")
}

func (s *Suite) Test_MkLineChecker_checkVaruseModifiersRange(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--show-autofix", "--source")
	t.SetUpVartypes()
	mkline := t.NewMkLine("mk/compiler/gcc.mk", 150,
		"CC:=\t${CC:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}")

	MkLineChecker{mkline}.Check()

	// FIXME: The check is called two times, even though it only produces a single NOTE.
	t.CheckOutputLines(
		"NOTE: mk/compiler/gcc.mk:150: "+
			"The modifier \":C/^/_asdf_/1:M_asdf_*:S/^_asdf_//\" can be written as \":[1]\".",
		"AUTOFIX: mk/compiler/gcc.mk:150: "+
			"Replacing \":C/^/_asdf_/1:M_asdf_*:S/^_asdf_//\" with \":[1]\".",
		"-\tCC:=\t${CC:C/^/_asdf_/1:M_asdf_*:S/^_asdf_//}",
		"+\tCC:=\t${CC:[1]}")

	// Now go through all the "almost" cases, to reach full branch coverage.
	mklines := t.NewMkLines("gcc.mk",
		MkRcsID,
		"\t: ${CC:M1:M2:M3}",
		"\t: ${CC:C/^begin//:M2:M3}",                    // M1 pattern not exactly ^
		"\t: ${CC:C/^/_asdf_/g:M2:M3}",                  // M1 options != "1"
		"\t: ${CC:C/^/....../g:M2:M3}",                  // M1 replacement doesn't match \w+
		"\t: ${CC:C/^/_asdf_/1:O:M3}",                   // M2 is not a match modifier
		"\t: ${CC:C/^/_asdf_/1:N2:M3}",                  // M2 is :N instead of :M
		"\t: ${CC:C/^/_asdf_/1:M_asdf_:M3}",             // M2 pattern is missing the * at the end
		"\t: ${CC:C/^/_asdf_/1:Mother:M3}",              // M2 pattern differs from the M1 pattern
		"\t: ${CC:C/^/_asdf_/1:M_asdf_*:M3}",            // M3 ist not a substitution modifier
		"\t: ${CC:C/^/_asdf_/1:M_asdf_*:S,from,to,}",    // M3 pattern differs from the M1 pattern
		"\t: ${CC:C/^/_asdf_/1:M_asdf_*:S,^_asdf_,to,}", // M3 replacement is not empty
		"\t: ${CC:C/^/_asdf_/1:M_asdf_*:S,^_asdf_,,g}")  // M3 modifier has options

	mklines.Check()
}

func (s *Suite) Test_MkLineChecker_CheckVaruse__deprecated_PKG_DEBUG(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	G.Pkgsrc.initDeprecatedVars()

	mkline := t.NewMkLine("module.mk", 123,
		"\t${_PKG_SILENT}${_PKG_DEBUG} :")

	MkLineChecker{mkline}.Check()

	t.CheckOutputLines(
		"WARN: module.mk:123: Use of _PKG_SILENT and _PKG_DEBUG is deprecated. Use ${RUN} instead.")
}

// PR 46570, item "15. net/uucp/Makefile has a make loop"
func (s *Suite) Test_MkLineChecker_checkVaruseUndefined__indirect_variables(c *check.C) {
	t := s.Init(c)

	t.SetUpTool("echo", "ECHO", AfterPrefsMk)
	mkline := t.NewMkLine("net/uucp/Makefile", 123, "\techo ${UUCP_${var}}")

	MkLineChecker{mkline}.Check()

	// No warning about UUCP_${var} being used but not defined.
	//
	// Normally, parameterized variables use a dot instead of an underscore as separator.
	// This is one of the few other cases. Pkglint doesn't warn about dynamic variable
	// names like UUCP_${var} or SITES_${distfile}.
	//
	// It does warn about simple variable names though, like ${var} in this example.
	t.CheckOutputLines(
		"WARN: net/uucp/Makefile:123: var is used but not defined.")
}

func (s *Suite) Test_MkLineChecker_checkVarassignMisc(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	G.Pkgsrc.LoadInfrastructure()
	t.SetUpCommandLine("-Wall,no-space")
	t.SetUpVartypes()
	mklines := t.SetUpFileMkLines("module.mk",
		MkRcsID,
		"EGDIR=                  ${PREFIX}/etc/rc.d",
		"_TOOLS_VARNAME.sed=     SED",
		"DIST_SUBDIR=            ${PKGNAME}",
		"WRKSRC=                 ${PKGNAME}",
		"SITES_distfile.tar.gz=  ${MASTER_SITE_GITHUB:=user/}",
		// TODO: The first of the below assignments should be flagged as redundant by RedundantScope;
		//  as of January 2019, that check is only implemented for package Makefiles, not for other files.
		"PYTHON_VERSIONS_ACCEPTED= -13",
		"PYTHON_VERSIONS_ACCEPTED= 27 36")

	mklines.Check()

	// TODO: Split this test into several, one for each topic.
	t.CheckOutputLines(
		"WARN: ~/module.mk:2: Please use the RCD_SCRIPTS mechanism to install rc.d scripts automatically to ${RCD_SCRIPTS_EXAMPLEDIR}.",
		"WARN: ~/module.mk:3: Variable names starting with an underscore (_TOOLS_VARNAME.sed) are reserved for internal pkgsrc use.",
		"WARN: ~/module.mk:3: _TOOLS_VARNAME.sed is defined but not used.",
		"WARN: ~/module.mk:4: PKGNAME should not be used in DIST_SUBDIR as it includes the PKGREVISION. Please use PKGNAME_NOREV instead.",
		"WARN: ~/module.mk:5: PKGNAME should not be used in WRKSRC as it includes the PKGREVISION. Please use PKGNAME_NOREV instead.",
		"WARN: ~/module.mk:6: SITES_distfile.tar.gz is defined but not used.",
		"WARN: ~/module.mk:6: SITES_* is deprecated. Please use SITES.* instead.",
		"WARN: ~/module.mk:7: The variable PYTHON_VERSIONS_ACCEPTED may not be set "+
			"(only given a default value, or appended to) in this file; "+
			"it would be ok in Makefile, Makefile.common or options.mk.",
		"WARN: ~/module.mk:7: Invalid version number \"-13\".",
		"ERROR: ~/module.mk:7: All values for PYTHON_VERSIONS_ACCEPTED must be positive integers.",
		"WARN: ~/module.mk:8: The variable PYTHON_VERSIONS_ACCEPTED may not be set "+
			"(only given a default value, or appended to) in this file; "+
			"it would be ok in Makefile, Makefile.common or options.mk.",
		"WARN: ~/module.mk:8: The values for PYTHON_VERSIONS_ACCEPTED should be in decreasing order.")
}

func (s *Suite) Test_MkLineChecker_checkText(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	G.Pkgsrc.LoadInfrastructure()

	t.SetUpCommandLine("-Wall,no-space")
	mklines := t.SetUpFileMkLines("module.mk",
		MkRcsID,
		"CFLAGS+=                -Wl,--rpath,${PREFIX}/lib",
		"PKG_FAIL_REASON+=       \"Group ${GAMEGRP} doesn't exist.\"")

	mklines.Check()

	// FIXME: Duplicate diagnostics.
	t.CheckOutputLines(
		"WARN: ~/module.mk:2: Please use ${COMPILER_RPATH_FLAG} instead of \"-Wl,--rpath,\".",
		"WARN: ~/module.mk:3: Use of \"GAMEGRP\" is deprecated. Use GAMES_GROUP instead.",
		"WARN: ~/module.mk:3: Use of \"GAMEGRP\" is deprecated. Use GAMES_GROUP instead.")
}

func (s *Suite) Test_MkLineChecker_checkText__WRKSRC(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--explain")
	mklines := t.SetUpFileMkLines("module.mk",
		MkRcsID,
		"pre-configure:",
		"\tcd ${WRKSRC}/..")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: ~/module.mk:3: Building the package should take place entirely inside ${WRKSRC}, not \"${WRKSRC}/..\".",
		"",
		"\tWRKSRC should be defined so that there is no need to do anything",
		"\toutside of this directory.",
		"",
		"\tExample:",
		"",
		"\t\tWRKSRC=\t${WRKDIR}",
		"\t\tCONFIGURE_DIRS=\t${WRKSRC}/lib ${WRKSRC}/src",
		"\t\tBUILD_DIRS=\t${WRKSRC}/lib ${WRKSRC}/src ${WRKSRC}/cmd",
		"",
		"\tSee the pkgsrc guide, section \"Directories used during the build",
		"\tprocess\":",
		"\thttps://www.NetBSD.org/docs/pkgsrc/pkgsrc.html#build.builddirs",
		"",
		"WARN: ~/module.mk:3: WRKSRC is used but not defined.")
}

func (s *Suite) Test_MkLineChecker_CheckRelativePath(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	G.Pkgsrc.LoadInfrastructure()
	t.CreateFileLines("wip/package/Makefile")
	t.CreateFileLines("wip/package/module.mk")
	mklines := t.SetUpFileMkLines("category/package/module.mk",
		MkRcsID,
		"DEPENDS+=       wip-package-[0-9]*:../../wip/package",
		".include \"../../wip/package/module.mk\"",
		"",
		"DEPENDS+=       unresolvable-[0-9]*:../../lang/${LATEST_PYTHON}",
		".include \"../../lang/${LATEST_PYTHON}/module.mk\"",
		"",
		".include \"module.mk\"",
		".include \"../../category/../category/package/module.mk\"", // Oops
		".include \"../../mk/bsd.prefs.mk\"",
		".include \"../package/module.mk\"")

	mklines.Check()

	t.CheckOutputLines(
		"ERROR: ~/category/package/module.mk:2: A main pkgsrc package must not depend on a pkgsrc-wip package.",
		"ERROR: ~/category/package/module.mk:3: A main pkgsrc package must not depend on a pkgsrc-wip package.",
		"WARN: ~/category/package/module.mk:5: LATEST_PYTHON is used but not defined.",
		// TODO: This warning is unspecific, there is also a pkglint warning "should be ../../category/package".
		"WARN: ~/category/package/module.mk:11: Invalid relative path \"../package/module.mk\".")
}
