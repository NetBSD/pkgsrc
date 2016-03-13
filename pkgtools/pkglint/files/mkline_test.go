package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) TestChecklineMkVartype_SimpleType(c *check.C) {
	s.UseCommandLine(c, "-Wtypes", "-Dunchecked")
	G.globalData.InitVartypes()
	mkline := NewMkLine(NewLine("fname", 1, "COMMENT=\tA nice package", nil))

	vartype1 := G.globalData.vartypes["COMMENT"]
	c.Assert(vartype1, check.NotNil)
	c.Check(vartype1.guessed, equals, false)

	vartype := mkline.getVariableType("COMMENT")

	c.Assert(vartype, check.NotNil)
	c.Check(vartype.checker.name, equals, "Comment")
	c.Check(vartype.guessed, equals, false)
	c.Check(vartype.kindOfList, equals, lkNone)

	mkline.CheckVartype("COMMENT", opAssign, "A nice package", "")

	c.Check(s.Stdout(), equals, "WARN: fname:1: COMMENT should not begin with \"A\".\n")
}

func (s *Suite) TestChecklineMkVartype(c *check.C) {
	G.globalData.InitVartypes()
	mkline := NewMkLine(NewLine("fname", 1, "DISTNAME=gcc-${GCC_VERSION}", nil))

	mkline.CheckVartype("DISTNAME", opAssign, "gcc-${GCC_VERSION}", "")
}

func (s *Suite) TestMkLine_CheckVaralign_Autofix(c *check.C) {
	s.UseCommandLine(c, "-Wspace", "-f")
	lines := s.NewLines("file.mk",
		"VAR=   value",    // Indentation 7, fixed to 8.
		"",                //
		"VAR=    value",   // Indentation 8, fixed to 8.
		"",                //
		"VAR=     value",  // Indentation 9, fixed to 8.
		"",                //
		"VAR= \tvalue",    // Mixed indentation 8, fixed to 8.
		"",                //
		"VAR=   \tvalue",  // Mixed indentation 8, fixed to 8.
		"",                //
		"VAR=    \tvalue", // Mixed indentation 16, fixed to 8.
		"",                //
		"VAR=\tvalue")     // Already aligned with tabs only, left unchanged.

	varalign := new(VaralignBlock)
	for _, line := range lines {
		varalign.Check(NewMkLine(line))
	}
	varalign.Finish()

	c.Check(lines[0].changed, equals, true)
	c.Check(lines[0].rawLines()[0].String(), equals, "1:VAR=\tvalue\n")
	c.Check(lines[2].changed, equals, true)
	c.Check(lines[2].rawLines()[0].String(), equals, "3:VAR=\tvalue\n")
	c.Check(lines[4].changed, equals, true)
	c.Check(lines[4].rawLines()[0].String(), equals, "5:VAR=\tvalue\n")
	c.Check(lines[6].changed, equals, true)
	c.Check(lines[6].rawLines()[0].String(), equals, "7:VAR=\tvalue\n")
	c.Check(lines[8].changed, equals, true)
	c.Check(lines[8].rawLines()[0].String(), equals, "9:VAR=\tvalue\n")
	c.Check(lines[10].changed, equals, true)
	c.Check(lines[10].rawLines()[0].String(), equals, "11:VAR=\tvalue\n")
	c.Check(lines[12].changed, equals, false)
	c.Check(lines[12].rawLines()[0].String(), equals, "13:VAR=\tvalue\n")
	c.Check(s.Output(), equals, ""+
		"NOTE: file.mk:1: This variable value should be aligned with tabs, not spaces, to column 9.\n"+
		"AUTOFIX: file.mk:1: Replacing \"VAR=   \" with \"VAR=\\t\".\n"+
		"NOTE: file.mk:3: Variable values should be aligned with tabs, not spaces.\n"+
		"AUTOFIX: file.mk:3: Replacing \"VAR=    \" with \"VAR=\\t\".\n"+
		"NOTE: file.mk:5: This variable value should be aligned with tabs, not spaces, to column 9.\n"+
		"AUTOFIX: file.mk:5: Replacing \"VAR=     \" with \"VAR=\\t\".\n"+
		"NOTE: file.mk:7: Variable values should be aligned with tabs, not spaces.\n"+
		"AUTOFIX: file.mk:7: Replacing \"VAR= \\t\" with \"VAR=\\t\".\n"+
		"NOTE: file.mk:9: Variable values should be aligned with tabs, not spaces.\n"+
		"AUTOFIX: file.mk:9: Replacing \"VAR=   \\t\" with \"VAR=\\t\".\n"+
		"NOTE: file.mk:11: This variable value should be aligned with tabs, not spaces, to column 9.\n"+
		"AUTOFIX: file.mk:11: Replacing \"VAR=    \\t\" with \"VAR=\\t\".\n")
}

func (s *Suite) TestMkLine_CheckVaralign_ReduceIndentation(c *check.C) {
	s.UseCommandLine(c, "-Wspace")
	mklines := s.NewMkLines("file.mk",
		"VAR= \tvalue",
		"VAR=    \tvalue",
		"VAR=\t\t\t\tvalue",
		"",
		"VAR=\t\t\tneedlessly", // Nothing to be fixed here, since it looks good.
		"VAR=\t\t\tdeep",
		"VAR=\t\t\tindentation")

	varalign := new(VaralignBlock)
	for _, mkline := range mklines.mklines {
		varalign.Check(mkline)
	}
	varalign.Finish()

	c.Check(s.Output(), equals, ""+
		"NOTE: file.mk:1: Variable values should be aligned with tabs, not spaces.\n"+
		"NOTE: file.mk:2: This variable value should be aligned with tabs, not spaces, to column 9.\n"+
		"NOTE: file.mk:3: This variable value should be aligned to column 9.\n")
}

func (s *Suite) TestMkLine_CheckVaralign_LongestLineEmptyAlignment(c *check.C) {
	s.UseCommandLine(c, "-Wspace")
	mklines := s.NewMkLines("file.mk",
		"SUBST_CLASSES+= aaaaaaaa",
		"SUBST_STAGE.aaaaaaaa= pre-configure",
		"SUBST_FILES.aaaaaaaa= *.pl",
		"SUBST_FILTER_CMD.aaaaaaaa=cat")

	varalign := new(VaralignBlock)
	for _, mkline := range mklines.mklines {
		varalign.Check(mkline)
	}
	varalign.Finish()

	c.Check(s.Output(), equals, ""+
		"NOTE: file.mk:1: This variable value should be aligned with tabs, not spaces, to column 33.\n"+
		"NOTE: file.mk:2: This variable value should be aligned with tabs, not spaces, to column 33.\n"+
		"NOTE: file.mk:3: This variable value should be aligned with tabs, not spaces, to column 33.\n"+
		"NOTE: file.mk:4: This variable value should be aligned to column 33.\n")
}

func (s *Suite) TestMkLine_CheckVaralign_OnlySpaces(c *check.C) {
	s.UseCommandLine(c, "-Wspace")
	mklines := s.NewMkLines("file.mk",
		"SUBST_CLASSES+= aaaaaaaa",
		"SUBST_STAGE.aaaaaaaa= pre-configure",
		"SUBST_FILES.aaaaaaaa= *.pl",
		"SUBST_FILTER_CMD.aaaaaaaa= cat")

	varalign := new(VaralignBlock)
	for _, mkline := range mklines.mklines {
		varalign.Check(mkline)
	}
	varalign.Finish()

	c.Check(s.Output(), equals, ""+
		"NOTE: file.mk:1: This variable value should be aligned with tabs, not spaces, to column 33.\n"+
		"NOTE: file.mk:2: This variable value should be aligned with tabs, not spaces, to column 33.\n"+
		"NOTE: file.mk:3: This variable value should be aligned with tabs, not spaces, to column 33.\n"+
		"NOTE: file.mk:4: This variable value should be aligned with tabs, not spaces, to column 33.\n")
}

func (s *Suite) TestMkLine_CheckVaralign_Advanced(c *check.C) {
	s.UseCommandLine(c, "-Wspace")
	fname := s.CreateTmpFileLines(c, "Makefile",
		"# $"+"NetBSD$",
		"",
		"VAR= \\", // In continuation lines, indenting with spaces is ok
		"\tvalue",
		"",
		"VAR= indented with one space",   // Exactly one space is ok in general
		"VAR=  indented with two spaces", // Two spaces are uncommon
		"",
		"BLOCK=\tindented with tab",
		"BLOCK_LONGVAR= indented with space", // This is ok, to prevent the block from being indented further
		"",
		"BLOCK=\tshort",
		"BLOCK_LONGVAR=\tlong",
		"",
		"GRP_A= avalue", // The values in a block should be aligned
		"GRP_AA= value",
		"GRP_AAA= value",
		"GRP_AAAA= value",
		"",
		"VAR=\t${VAR}${BLOCK}${BLOCK_LONGVAR} # suppress warnings about unused variables",
		"VAR=\t${GRP_A}${GRP_AA}${GRP_AAA}${GRP_AAAA}")
	mklines := NewMkLines(LoadExistingLines(fname, true))

	mklines.Check()

	c.Check(s.Output(), equals, ""+
		"NOTE: ~/Makefile:6: This variable value should be aligned with tabs, not spaces, to column 9.\n"+
		"NOTE: ~/Makefile:7: This variable value should be aligned with tabs, not spaces, to column 9.\n"+
		"NOTE: ~/Makefile:12: This variable value should be aligned to column 17.\n"+
		"NOTE: ~/Makefile:15: This variable value should be aligned with tabs, not spaces, to column 17.\n"+
		"NOTE: ~/Makefile:16: This variable value should be aligned with tabs, not spaces, to column 17.\n"+
		"NOTE: ~/Makefile:17: This variable value should be aligned with tabs, not spaces, to column 17.\n"+
		"NOTE: ~/Makefile:18: This variable value should be aligned with tabs, not spaces, to column 17.\n")

	s.UseCommandLine(c, "-Wspace", "--autofix")

	mklines.Check()

	c.Check(s.Output(), equals, ""+
		"AUTOFIX: ~/Makefile:6: Replacing \"VAR= \" with \"VAR=\\t\".\n"+
		"AUTOFIX: ~/Makefile:7: Replacing \"VAR=  \" with \"VAR=\\t\".\n"+
		"AUTOFIX: ~/Makefile:12: Replacing \"BLOCK=\\t\" with \"BLOCK=\\t\\t\".\n"+
		"AUTOFIX: ~/Makefile:15: Replacing \"GRP_A= \" with \"GRP_A=\\t\\t\".\n"+
		"AUTOFIX: ~/Makefile:16: Replacing \"GRP_AA= \" with \"GRP_AA=\\t\\t\".\n"+
		"AUTOFIX: ~/Makefile:17: Replacing \"GRP_AAA= \" with \"GRP_AAA=\\t\".\n"+
		"AUTOFIX: ~/Makefile:18: Replacing \"GRP_AAAA= \" with \"GRP_AAAA=\\t\".\n"+
		"AUTOFIX: ~/Makefile: Has been auto-fixed. Please re-run pkglint.\n")
	c.Check(s.LoadTmpFile(c, "Makefile"), equals, ""+
		"# $"+"NetBSD$\n"+
		"\n"+
		"VAR= \\\n"+
		"\tvalue\n"+
		"\n"+
		"VAR=\tindented with one space\n"+
		"VAR=\tindented with two spaces\n"+
		"\n"+
		"BLOCK=\tindented with tab\n"+
		"BLOCK_LONGVAR= indented with space\n"+
		"\n"+
		"BLOCK=\t\tshort\n"+
		"BLOCK_LONGVAR=\tlong\n"+
		"\n"+
		"GRP_A=\t\tavalue\n"+
		"GRP_AA=\t\tvalue\n"+
		"GRP_AAA=\tvalue\n"+
		"GRP_AAAA=\tvalue\n"+
		"\n"+
		"VAR=\t${VAR}${BLOCK}${BLOCK_LONGVAR} # suppress warnings about unused variables\n"+
		"VAR=\t${GRP_A}${GRP_AA}${GRP_AAA}${GRP_AAAA}\n")
}

func (s *Suite) TestMkLine_CheckVaralign_Misc(c *check.C) {
	s.UseCommandLine(c, "-Wspace")
	mklines := s.NewMkLines("Makefile",
		"# $"+"NetBSD$",
		"",
		"VAR=    space",
		"VAR=\ttab ${VAR}")

	mklines.Check()

	c.Check(s.Output(), equals, "NOTE: Makefile:3: Variable values should be aligned with tabs, not spaces.\n")
}

func (s *Suite) TestMkLine_fields(c *check.C) {
	mklines := NewMkLines(s.NewLines("test.mk",
		"VARNAME.param?=value # varassign comment",
		"\tshell command # shell comment",
		"# whole line comment",
		"",
		".  if !empty(PKGNAME:M*-*) # cond comment",
		".include \"../../mk/bsd.prefs.mk\" # include comment",
		".include <subdir.mk> # sysinclude comment",
		"target1 target2: source1 source2",
		"target : source",
		"VARNAME+=value"))
	ln := mklines.mklines

	c.Check(ln[0].IsVarassign(), equals, true)
	c.Check(ln[0].Varname(), equals, "VARNAME.param")
	c.Check(ln[0].Varcanon(), equals, "VARNAME.*")
	c.Check(ln[0].Varparam(), equals, "param")
	c.Check(ln[0].Op(), equals, opAssignDefault)
	c.Check(ln[0].Value(), equals, "value")
	c.Check(ln[0].Comment(), equals, "# varassign comment")

	c.Check(ln[1].IsShellcmd(), equals, true)
	c.Check(ln[1].Shellcmd(), equals, "shell command # shell comment")

	c.Check(ln[2].IsComment(), equals, true)
	c.Check(ln[2].Comment(), equals, " whole line comment")

	c.Check(ln[3].IsEmpty(), equals, true)

	c.Check(ln[4].IsCond(), equals, true)
	c.Check(ln[4].Indent(), equals, "  ")
	c.Check(ln[4].Directive(), equals, "if")
	c.Check(ln[4].Args(), equals, "!empty(PKGNAME:M*-*)")
	c.Check(ln[4].Comment(), equals, "") // Not needed

	c.Check(ln[5].IsInclude(), equals, true)
	c.Check(ln[5].MustExist(), equals, true)
	c.Check(ln[5].Includefile(), equals, "../../mk/bsd.prefs.mk")
	c.Check(ln[5].Comment(), equals, "") // Not needed

	c.Check(ln[6].IsSysinclude(), equals, true)
	c.Check(ln[6].MustExist(), equals, true)
	c.Check(ln[6].Includefile(), equals, "subdir.mk")
	c.Check(ln[6].Comment(), equals, "") // Not needed

	c.Check(ln[7].IsDependency(), equals, true)
	c.Check(ln[7].Targets(), equals, "target1 target2")
	c.Check(ln[7].Sources(), equals, "source1 source2")
	c.Check(ln[7].Comment(), equals, "") // Not needed

	c.Check(ln[9].IsVarassign(), equals, true)
	c.Check(ln[9].Varname(), equals, "VARNAME")
	c.Check(ln[9].Varcanon(), equals, "VARNAME")
	c.Check(ln[9].Varparam(), equals, "")

	c.Check(s.Output(), equals, "WARN: test.mk:9: Space before colon in dependency line.\n")
}

func (s *Suite) TestMkLine_checkVarassign(c *check.C) {
	G.Pkg = NewPackage("graphics/gimp-fix-ca")
	G.globalData.InitVartypes()
	mkline := NewMkLine(NewLine("fname", 10, "MASTER_SITES=http://registry.gimp.org/file/fix-ca.c?action=download&id=9884&file=", nil))

	mkline.CheckVarassign()

	c.Check(s.Output(), equals, "")
}

func (s *Suite) TestChecklineMkCondition(c *check.C) {
	s.UseCommandLine(c, "-Wtypes")
	G.globalData.InitVartypes()

	NewMkLine(NewLine("fname", 1, ".if !empty(PKGSRC_COMPILER:Mmycc)", nil)).CheckCond()

	c.Check(s.Stdout(), equals, "WARN: fname:1: The pattern \"mycc\" cannot match any of "+
		"{ ccache ccc clang distcc f2c gcc hp icc ido "+
		"gcc mipspro mipspro-ucode pcc sunpro xlc } for PKGSRC_COMPILER.\n")

	NewMkLine(NewLine("fname", 1, ".elif ${A} != ${B}", nil)).CheckCond()

	c.Check(s.Stdout(), equals, "")

	NewMkLine(NewLine("fname", 1, ".if ${HOMEPAGE} == \"mailto:someone@example.org\"", nil)).CheckCond()

	c.Check(s.Output(), equals, "WARN: fname:1: \"mailto:someone@example.org\" is not a valid URL.\n")

	NewMkLine(NewLine("fname", 1, ".if !empty(PKGSRC_RUN_TEST:M[Y][eE][sS])", nil)).CheckCond()

	c.Check(s.Output(), equals, "WARN: fname:1: PKGSRC_RUN_TEST should be matched against \"[yY][eE][sS]\" or \"[nN][oO]\", not \"[Y][eE][sS]\".\n")

	NewMkLine(NewLine("fname", 1, ".if !empty(IS_BUILTIN.Xfixes:M[yY][eE][sS])", nil)).CheckCond()

	c.Check(s.Output(), equals, "")

	NewMkLine(NewLine("fname", 1, ".if !empty(${IS_BUILTIN.Xfixes:M[yY][eE][sS]})", nil)).CheckCond()

	c.Check(s.Output(), equals, "WARN: fname:1: The empty() function takes a variable name as parameter, not a variable expression.\n")

	NewMkLine(NewLine("fname", 1, ".if ${EMUL_PLATFORM} == \"linux-x386\"", nil)).CheckCond()

	c.Check(s.Output(), equals, "WARN: fname:1: \"x386\" is not valid for the hardware architecture part of EMUL_PLATFORM. Use one of { alpha amd64 arc arm arm32 cobalt convex dreamcast hpcmips hpcsh hppa i386 ia64 m68k m88k mips mips64 mips64eb mips64el mipseb mipsel mipsn32 ns32k pc532 pmax powerpc rs6000 s390 sh3eb sh3el sparc sparc64 vax x86_64 } instead.\n")

	NewMkLine(NewLine("fname", 1, ".if ${EMUL_PLATFORM:Mlinux-x386}", nil)).CheckCond()

	c.Check(s.Output(), equals, "WARN: fname:1: The pattern \"x386\" cannot match any of { alpha amd64 arc arm arm32 cobalt convex dreamcast hpcmips hpcsh hppa i386 ia64 m68k m88k mips mips64 mips64eb mips64el mipseb mipsel mipsn32 ns32k pc532 pmax powerpc rs6000 s390 sh3eb sh3el sparc sparc64 vax x86_64 } for the hardware architecture part of EMUL_PLATFORM.\n")
}

func (s *Suite) TestMkLine_variableNeedsQuoting(c *check.C) {
	mkline := NewMkLine(NewLine("fname", 1, "PKGNAME := ${UNKNOWN}", nil))
	G.globalData.InitVartypes()
	pkgnameType := G.globalData.vartypes["PKGNAME"]

	vuc := &VarUseContext{pkgnameType, vucTimeParse, vucQuotUnknown, vucExtentUnknown}
	nq := mkline.variableNeedsQuoting("UNKNOWN", vuc)

	c.Check(nq, equals, nqDontKnow)
}

func (s *Suite) TestMkLine_variableNeedsQuoting_Varbase(c *check.C) {
	mkline := NewMkLine(NewLine("fname", 1, "# dummy", nil))
	G.globalData.InitVartypes()

	t1 := mkline.getVariableType("FONT_DIRS")

	c.Assert(t1, check.NotNil)
	c.Check(t1.String(), equals, "ShellList of Pathmask")

	t2 := mkline.getVariableType("FONT_DIRS.ttf")

	c.Assert(t2, check.NotNil)
	c.Check(t2.String(), equals, "ShellList of Pathmask")
}

func (s *Suite) TestVarUseContext_ToString(c *check.C) {
	G.globalData.InitVartypes()
	mkline := NewMkLine(NewLine("fname", 1, "# dummy", nil))
	vartype := mkline.getVariableType("PKGNAME")
	vuc := &VarUseContext{vartype, vucTimeUnknown, vucQuotBackt, vucExtentWord}

	c.Check(vuc.String(), equals, "(unknown PkgName backt word)")
}

func (s *Suite) TestMkLine_(c *check.C) {
	G.globalData.InitVartypes()

	G.Mk = s.NewMkLines("Makefile",
		"# $"+"NetBSD$",
		"ac_cv_libpari_libs+=\t-L${BUILDLINK_PREFIX.pari}/lib", // From math/clisp-pari/Makefile, rev. 1.8
		"var+=value")

	G.Mk.mklines[1].CheckVarassign()
	G.Mk.mklines[2].CheckVarassign()

	c.Check(s.Output(), equals, ""+
		"WARN: Makefile:2: ac_cv_libpari_libs is defined but not used. Spelling mistake?\n"+
		"WARN: Makefile:3: As var is modified using \"+=\", its name should indicate plural.\n"+
		"WARN: Makefile:3: var is defined but not used. Spelling mistake?\n")
}

// In variable assignments, a plain '#' introduces a line comment, unless
// it is escaped by a backslash. In shell commands, on the other hand, it
// is interpreted literally.
func (s *Suite) TestParselineMk(c *check.C) {
	line1 := NewMkLine(NewLine("fname", 1, "SED_CMD=\t's,\\#,hash,g'", nil))

	c.Check(line1.Varname(), equals, "SED_CMD")
	c.Check(line1.Value(), equals, "'s,#,hash,g'")

	line2 := NewMkLine(NewLine("fname", 1, "\tsed -e 's,\\#,hash,g'", nil))

	c.Check(line2.Shellcmd(), equals, "sed -e 's,\\#,hash,g'")
}

func (s *Suite) TestMkLine_LeadingSpace(c *check.C) {
	_ = NewMkLine(NewLine("rubyversion.mk", 427, " _RUBYVER=\t2.15", nil))

	c.Check(s.Output(), equals, "WARN: rubyversion.mk:427: Makefile lines should not start with space characters.\n")
}

func (s *Suite) TestMkLine_CheckVardefPermissions(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("options.mk",
		"# $"+"NetBSD$",
		"PKG_DEVELOPER?=\tyes",
		"COMMENT=\t${PKG_DEVELOPER}")

	mklines.Check()

	c.Check(s.Output(), equals, "WARN: options.mk:2: The variable PKG_DEVELOPER may not be given a default value by any package.\n")
}

func (s *Suite) TestMkLine_CheckVarusePermissions(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("options.mk",
		"# $"+"NetBSD$",
		"COMMENT=\t${GAMES_USER}",
		"COMMENT:=\t${PKGBASE}",
		"PYPKGPREFIX=${PKGBASE}")
	G.globalData.UserDefinedVars = map[string]*MkLine{
		"GAMES_USER": mklines.mklines[0],
	}

	mklines.Check()

	c.Check(s.Output(), equals, ""+
		"WARN: options.mk:2: The user-defined variable GAMES_USER is used but not added to BUILD_DEFS.\n"+
		"WARN: options.mk:3: PKGBASE should not be evaluated at load time.\n"+
		"WARN: options.mk:4: The variable PYPKGPREFIX may not be set in this file; it would be ok in pyversion.mk.\n"+
		"WARN: options.mk:4: PKGBASE should not be evaluated indirectly at load time.\n"+
		"NOTE: options.mk:4: This variable value should be aligned to column 17.\n")
}

func (s *Suite) TestMkLine_WarnVaruseLocalbase(c *check.C) {
	mkline := NewMkLine(NewLine("options.mk", 56, "PKGNAME=${LOCALBASE}", nil))

	mkline.WarnVaruseLocalbase()

	c.Check(s.Output(), equals, "WARN: options.mk:56: The LOCALBASE variable should not be used by packages.\n")
}

func (s *Suite) TestMkLine_Misc(c *check.C) {
	s.UseCommandLine(c, "-Wextra")
	G.globalData.InitVartypes()
	G.Pkg = NewPackage("category/pkgbase")
	G.Mk = s.NewMkLines("options.mk",
		"# $"+"NetBSD$",
		".for word in ${PKG_FAIL_REASON}",
		"PYTHON_VERSIONS_ACCEPTED=\t27 35 30",
		"CONFIGURE_ARGS+=\t--sharedir=${PREFIX}/share/kde",
		"COMMENT=\t# defined",
		".endfor",
		"GAMES_USER?=pkggames",
		"PLIST_SUBST+= CONDITIONAL=${CONDITIONAL}",
		"CONDITIONAL=\"@comment\"",
		"BUILD_DIRS=\t${WRKSRC}/../build")

	G.Mk.Check()

	c.Check(s.Output(), equals, ""+
		"WARN: options.mk:3: The values for PYTHON_VERSIONS_ACCEPTED should be in decreasing order.\n"+
		"NOTE: options.mk:4: Please .include \"../../meta-pkgs/kde3/kde3.mk\" instead of this line.\n"+
		"NOTE: options.mk:5: Please use \"# empty\", \"# none\" or \"yes\" instead of \"# defined\".\n"+
		"WARN: options.mk:7: Please include \"../../mk/bsd.prefs.mk\" before using \"?=\".\n"+
		"WARN: options.mk:10: Building the package should take place entirely inside ${WRKSRC}, not \"${WRKSRC}/..\".\n"+
		"NOTE: options.mk:10: You can use \"../build\" instead of \"${WRKSRC}/../build\".\n")
}

func (s *Suite) TestMkLine_CheckRelativePkgdir(c *check.C) {
	mkline := NewMkLine(NewLine("Makefile", 46, "# dummy", nil))

	mkline.CheckRelativePkgdir("../pkgbase")

	c.Check(s.Output(), equals, ""+
		"ERROR: Makefile:46: \"../pkgbase\" does not exist.\n"+
		"WARN: Makefile:46: \"../pkgbase\" is not a valid relative package directory.\n")
}

// PR pkg/46570, item 2
func (s *Suite) TestMkLine_UnfinishedVaruse(c *check.C) {
	s.UseCommandLine(c, "-Dunchecked")
	mkline := NewMkLine(NewLine("Makefile", 93, "EGDIRS=${EGDIR/apparmor.d ${EGDIR/dbus-1/system.d ${EGDIR/pam.d", nil))

	mkline.CheckVarassign()

	c.Check(s.Output(), equals, ""+
		"ERROR: Makefile:93: Invalid Makefile syntax at \"${EGDIR/apparmor.d ${EGDIR/dbus-1/system.d ${EGDIR/pam.d\".\n"+
		"WARN: Makefile:93: EGDIRS is defined but not used. Spelling mistake?\n")
}
