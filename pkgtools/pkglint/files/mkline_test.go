package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) TestChecklineMkVartype_SimpleType(c *check.C) {
	s.UseCommandLine(c, "-Wtypes")
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
	c.Check(lines[0].raw[0].String(), equals, "1:VAR=\tvalue\n")
	c.Check(lines[2].changed, equals, true)
	c.Check(lines[2].raw[0].String(), equals, "3:VAR=\tvalue\n")
	c.Check(lines[4].changed, equals, true)
	c.Check(lines[4].raw[0].String(), equals, "5:VAR=\tvalue\n")
	c.Check(lines[6].changed, equals, true)
	c.Check(lines[6].raw[0].String(), equals, "7:VAR=\tvalue\n")
	c.Check(lines[8].changed, equals, true)
	c.Check(lines[8].raw[0].String(), equals, "9:VAR=\tvalue\n")
	c.Check(lines[10].changed, equals, true)
	c.Check(lines[10].raw[0].String(), equals, "11:VAR=\tvalue\n")
	c.Check(lines[12].changed, equals, false)
	c.Check(lines[12].raw[0].String(), equals, "13:VAR=\tvalue\n")
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

	mkline.checkVarassign()

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

	c.Check(s.Output(), equals, "WARN: fname:1: \"x386\" is not valid for the hardware architecture part of EMUL_PLATFORM. Use one of { aarch64 aarch64eb alpha amd64 arc arm arm26 arm32 cobalt coldfire convex dreamcast earm earmeb earmhf earmhfeb earmv4 earmv4eb earmv5 earmv5eb earmv6 earmv6eb earmv6hf earmv6hfeb earmv7 earmv7eb earmv7hf earmv7hfeb evbarm hpcmips hpcsh hppa hppa64 i386 i586 i686 ia64 m68000 m68k m88k mips mips64 mips64eb mips64el mipseb mipsel mipsn32 mlrisc ns32k pc532 pmax powerpc powerpc64 rs6000 s390 sh3eb sh3el sparc sparc64 vax x86_64 } instead.\n")

	NewMkLine(NewLine("fname", 1, ".if ${EMUL_PLATFORM:Mlinux-x386}", nil)).CheckCond()

	c.Check(s.Output(), equals, "WARN: fname:1: The pattern \"x386\" cannot match any of { aarch64 aarch64eb alpha amd64 arc arm arm26 arm32 cobalt coldfire convex dreamcast earm earmeb earmhf earmhfeb earmv4 earmv4eb earmv5 earmv5eb earmv6 earmv6eb earmv6hf earmv6hfeb earmv7 earmv7eb earmv7hf earmv7hfeb evbarm hpcmips hpcsh hppa hppa64 i386 i586 i686 ia64 m68000 m68k m88k mips mips64 mips64eb mips64el mipseb mipsel mipsn32 mlrisc ns32k pc532 pmax powerpc powerpc64 rs6000 s390 sh3eb sh3el sparc sparc64 vax x86_64 } for the hardware architecture part of EMUL_PLATFORM.\n")

	NewMkLine(NewLine("fname", 98, ".if ${MACHINE_PLATFORM:MUnknownOS-*-*} || ${MACHINE_ARCH:Mx86}", nil)).CheckCond()

	c.Check(s.Output(), equals, ""+
		"WARN: fname:98: The pattern \"UnknownOS\" cannot match any of { AIX BSDOS Bitrig Cygwin Darwin DragonFly FreeBSD FreeMiNT GNUkFreeBSD HPUX Haiku IRIX Interix Linux Minix MirBSD NetBSD OSF1 OpenBSD QNX SCO_SV SunOS UnixWare } for the operating system part of MACHINE_PLATFORM.\n"+
		"WARN: fname:98: The pattern \"x86\" cannot match any of { aarch64 aarch64eb alpha amd64 arc arm arm26 arm32 cobalt coldfire convex dreamcast earm earmeb earmhf earmhfeb earmv4 earmv4eb earmv5 earmv5eb earmv6 earmv6eb earmv6hf earmv6hfeb earmv7 earmv7eb earmv7hf earmv7hfeb evbarm hpcmips hpcsh hppa hppa64 i386 i586 i686 ia64 m68000 m68k m88k mips mips64 mips64eb mips64el mipseb mipsel mipsn32 mlrisc ns32k pc532 pmax powerpc powerpc64 rs6000 s390 sh3eb sh3el sparc sparc64 vax x86_64 } for MACHINE_ARCH.\n")
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

	c.Check(vuc.String(), equals, "(PkgName time:unknown quoting:backt extent:word)")
}

func (s *Suite) TestMkLine_(c *check.C) {
	G.globalData.InitVartypes()

	G.Mk = s.NewMkLines("Makefile",
		"# $"+"NetBSD$",
		"ac_cv_libpari_libs+=\t-L${BUILDLINK_PREFIX.pari}/lib") // From math/clisp-pari/Makefile, rev. 1.8

	G.Mk.mklines[1].checkVarassign()

	c.Check(s.Output(), equals, "WARN: Makefile:2: ac_cv_libpari_libs is defined but not used. Spelling mistake?\n")
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

	// From shells/zsh/Makefile.common, rev. 1.78
	NewMkLine(NewLine("fname", 1, "\t# $ sha1 patches/patch-ac", nil))

	c.Check(s.Output(), equals, "")
}

func (s *Suite) TestMkLine_LeadingSpace(c *check.C) {
	_ = NewMkLine(NewLine("rubyversion.mk", 427, " _RUBYVER=\t2.15", nil))

	c.Check(s.Output(), equals, "WARN: rubyversion.mk:427: Makefile lines should not start with space characters.\n")
}

func (s *Suite) TestMkLine_checkVarassignDefPermissions(c *check.C) {
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

func (s *Suite) Test_MkLine_CheckVarusePermissions_LoadTime(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("options.mk",
		"# $"+"NetBSD$",
		"WRKSRC:=${.CURDIR}")

	mklines.Check()

	c.Check(s.Output(), equals, "") // Don’t warn that “.CURDIR should not be evaluated at load time.”
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
	mkline := NewMkLine(NewLine("Makefile", 93, "EGDIRS=${EGDIR/apparmor.d ${EGDIR/dbus-1/system.d ${EGDIR/pam.d", nil))

	mkline.checkVarassign()

	c.Check(s.Output(), equals, ""+
		"WARN: Makefile:93: Pkglint parse error in MkLine.Tokenize at \"${EGDIR/apparmor.d ${EGDIR/dbus-1/system.d ${EGDIR/pam.d\".\n"+
		"WARN: Makefile:93: Pkglint parse error in ShTokenizer.ShAtom at \"${EGDIR/apparmor.d ${EGDIR/dbus-1/system.d ${EGDIR/pam.d\" (quoting=plain)\n"+
		"WARN: Makefile:93: EGDIRS is defined but not used. Spelling mistake?\n")
}

func (s *Suite) TestMkLine_variableNeedsQuoting_1(c *check.C) {
	mkline := NewMkLine(NewLine("fname", 1, "PKGNAME := ${UNKNOWN}", nil))
	G.globalData.InitVartypes()

	vuc := &VarUseContext{G.globalData.vartypes["PKGNAME"], vucTimeParse, vucQuotUnknown, vucExtentWord}
	nq := mkline.variableNeedsQuoting("UNKNOWN", nil, vuc)

	c.Check(nq, equals, nqDontKnow)
}

func (s *Suite) TestMkLine_variableNeedsQuoting_2(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	s.RegisterMasterSite("MASTER_SITE_SOURCEFORGE", "http://downloads.sourceforge.net/sourceforge/")
	mkline := NewMkLine(NewLine("Makefile", 95, "MASTER_SITES=\t${HOMEPAGE}", nil))

	vuc := &VarUseContext{G.globalData.vartypes["MASTER_SITES"], vucTimeRun, vucQuotPlain, vucExtentWord}
	nq := mkline.variableNeedsQuoting("HOMEPAGE", G.globalData.vartypes["HOMEPAGE"], vuc)

	c.Check(nq, equals, nqNo)

	mkline.checkVarassign()

	c.Check(s.Output(), equals, "") // Up to pkglint 5.3.6, it warned about a missing :Q here, which was wrong.
}

// Assigning lists to lists is ok.
func (s *Suite) TestMkLine_variableNeedsQuoting_3(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	s.RegisterMasterSite("MASTER_SITE_SOURCEFORGE", "http://downloads.sourceforge.net/sourceforge/")
	mkline := NewMkLine(NewLine("Makefile", 96, "MASTER_SITES=\t${MASTER_SITE_SOURCEFORGE:=squirrel-sql/}", nil))

	mkline.checkVarassign()

	c.Check(s.Output(), equals, "")
}

func (s *Suite) TestMkLine_variableNeedsQuoting_4(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	mkline := NewMkLine(NewLine("builtin.mk", 3, "USE_BUILTIN.Xfixes!=\t${PKG_ADMIN} pmatch 'pkg-[0-9]*' ${BUILTIN_PKG.Xfixes:Q}", nil))

	mkline.checkVarassign()

	c.Check(s.Output(), equals, ""+
		"WARN: builtin.mk:3: PKG_ADMIN should not be evaluated at load time.\n"+
		"NOTE: builtin.mk:3: The :Q operator isn't necessary for ${BUILTIN_PKG.Xfixes} here.\n")
}

func (s *Suite) TestMkLine_variableNeedsQuoting_5(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	mkline := NewMkLine(NewLine("Makefile", 3, "SUBST_SED.hpath=\t-e 's|^\\(INSTALL[\t:]*=\\).*|\\1${INSTALL}|'", nil))

	mkline.checkVarassign()

	c.Check(s.Output(), equals, "WARN: Makefile:3: Please use ${INSTALL:Q} instead of ${INSTALL} and make sure the variable appears outside of any quoting characters.\n")
}

func (s *Suite) TestMkLine_variableNeedsQuoting_6(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	s.RegisterTool(&Tool{Name: "find", Varname: "FIND", Predefined: true})
	s.RegisterTool(&Tool{Name: "sort", Varname: "SORT", Predefined: true})
	G.Pkg = NewPackage("category/pkgbase")
	G.Mk = s.NewMkLines("Makefile",
		"# $"+"NetBSD$",
		"GENERATE_PLIST= cd ${DESTDIR}${PREFIX}; ${FIND} * \\( -type f -or -type l \\) | ${SORT};")

	G.Mk.determineDefinedVariables()
	G.Mk.mklines[1].Check()

	c.Check(s.Output(), equals, ""+
		"WARN: Makefile:2: The exitcode of the left-hand-side command of the pipe operator is ignored.\n")
}

func (s *Suite) TestMkLine_variableNeedsQuoting_7(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	G.Mk = s.NewMkLines("Makefile",
		"# $"+"NetBSD$",
		"EGDIR=\t${EGDIR}/${MACHINE_GNU_PLATFORM}")

	G.Mk.mklines[1].Check()

	c.Check(s.Output(), equals, "")
}

// Based on graphics/circos/Makefile.
func (s *Suite) TestMkLine_variableNeedsQuoting_8(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	s.RegisterTool(&Tool{Name: "perl", Varname: "PERL5", Predefined: true})
	s.RegisterTool(&Tool{Name: "bash", Varname: "BASH", Predefined: true})
	G.globalData.InitVartypes()
	G.Mk = s.NewMkLines("Makefile",
		"# $"+"NetBSD$",
		"\t${RUN} cd ${WRKSRC} && ( ${ECHO} ${PERL5:Q} ; ${ECHO} ) | ${BASH} ./install",
		"\t${RUN} cd ${WRKSRC} && ( ${ECHO} ${PERL5} ; ${ECHO} ) | ${BASH} ./install")

	G.Mk.mklines[1].Check()
	G.Mk.mklines[2].Check()

	c.Check(s.Output(), equals, ""+
		"WARN: Makefile:2: The exitcode of the left-hand-side command of the pipe operator is ignored.\n"+
		"WARN: Makefile:3: The exitcode of the left-hand-side command of the pipe operator is ignored.\n")
}

// Based on mail/mailfront/Makefile.
func (s *Suite) TestMkLine_variableNeedsQuoting_9(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	G.Mk = s.NewMkLines("Makefile",
		"# $"+"NetBSD$",
		"MASTER_SITES=${HOMEPAGE}archive/")

	G.Mk.mklines[1].Check()

	c.Check(s.Output(), equals, "") // Don’t suggest to use ${HOMEPAGE:Q}.
}

// Based on www/firefox31/xpi.mk.
func (s *Suite) TestMkLine_variableNeedsQuoting_10(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	s.RegisterTool(&Tool{Name: "awk", Varname: "AWK", Predefined: true})
	s.RegisterTool(&Tool{Name: "echo", Varname: "ECHO", Predefined: true})
	G.Mk = s.NewMkLines("xpi.mk",
		"# $"+"NetBSD$",
		"\t id=$$(${AWK} '{print}' < ${WRKSRC}/idfile) && echo \"$$id\"",
		"\t id=`${AWK} '{print}' < ${WRKSRC}/idfile` && echo \"$$id\"")

	G.Mk.mklines[1].Check()
	G.Mk.mklines[2].Check()

	c.Check(s.Output(), equals, "WARN: xpi.mk:2: Invoking subshells via $(...) is not portable enough.\n") // Don’t suggest to use ${AWK:Q}.
}

func (s *Suite) TestMkLine_variableNeedsQuoting_11(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	G.Mk = s.NewMkLines("x11/mlterm/Makefile",
		"# $"+"NetBSD$",
		"SUBST_SED.link=-e 's|(LIBTOOL_LINK).*(LIBS)|& ${LDFLAGS:M*:Q}|g'",
		"SUBST_SED.link=-e 's|(LIBTOOL_LINK).*(LIBS)|& '${LDFLAGS:M*:Q}'|g'")

	G.Mk.mklines[1].Check()
	G.Mk.mklines[2].Check()

	c.Check(s.Output(), equals, "WARN: x11/mlterm/Makefile:2: Please move ${LDFLAGS:M*:Q} outside of any quoting characters.\n")
}

func (s *Suite) TestMkLine_variableNeedsQuoting_12(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	s.RegisterMasterSite("MASTER_SITE_GITHUB", "https://github.com/")
	G.globalData.InitVartypes()
	G.Mk = s.NewMkLines("devel/catch/Makefile",
		"# $"+"NetBSD$",
		"HOMEPAGE=\t${MASTER_SITE_GITHUB:=philsquared/Catch/}",
		"HOMEPAGE=\t${MASTER_SITE_GITHUB}",
		"HOMEPAGE=\t${MASTER_SITES}",
		"HOMEPAGE=\t${MASTER_SITES}${GITHUB_PROJECT}")

	G.Mk.Check()

	c.Check(s.Output(), equals, ""+
		"WARN: devel/catch/Makefile:2: HOMEPAGE should not be defined in terms of MASTER_SITEs. Use https://github.com/philsquared/Catch/ directly.\n"+
		"WARN: devel/catch/Makefile:3: HOMEPAGE should not be defined in terms of MASTER_SITEs. Use https://github.com/ directly.\n"+
		"WARN: devel/catch/Makefile:4: HOMEPAGE should not be defined in terms of MASTER_SITEs.\n"+
		"WARN: devel/catch/Makefile:5: HOMEPAGE should not be defined in terms of MASTER_SITEs.\n")
}

func (s *Suite) TestMkLine_variableNeedsQuoting_13(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	s.RegisterTool(&Tool{Varname: "SH", Predefined: true})
	G.globalData.InitVartypes()
	G.Mk = s.NewMkLines("x11/labltk/Makefile",
		"# $"+"NetBSD$",
		"CONFIGURE_ARGS+=\t-tklibs \"`${SH} -c '${ECHO} $$TK_LD_FLAGS'`\"")

	G.Mk.mklines[1].Check()

	c.Check(s.Output(), equals, "") // Don’t suggest ${ECHO:Q} here.
}

func (s *Suite) TestMkLine_variableNeedsQuoting_14(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	G.Mk = s.NewMkLines("x11/qt5-qtbase/Makefile.common",
		"BUILDLINK_TRANSFORM+=opt:-ldl:${BUILDLINK_LDADD.dl:M*}")

	G.Mk.mklines[0].Check()

	// Note: The :M* modifier is not necessary, since this is not a GNU Configure package.
	c.Check(s.Output(), equals, "WARN: x11/qt5-qtbase/Makefile.common:1: Please use ${BUILDLINK_LDADD.dl:Q} instead of ${BUILDLINK_LDADD.dl:M*}.\n")
}

func (s *Suite) TestMkLine_variableNeedsQuoting_15(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	G.Mk = s.NewMkLines("benchmarks/iozone/Makefile",
		"SUBST_MESSAGE.crlf=\tStripping EOL CR in ${REPLACE_PERL}")

	G.Mk.mklines[0].Check()

	c.Check(s.Output(), equals, "") // Don’t suggest ${REPLACE_PERL:Q}.
}

func (s *Suite) TestMkLine_variableNeedsQuoting_16(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	G.Mk = s.NewMkLines("audio/jack-rack/Makefile",
		"# $"+"NetBSD$",
		"LADSPA_PLUGIN_PATH?=\t${PREFIX}/lib/ladspa",
		"CPPFLAGS+=\t\t-DLADSPA_PATH=\"\\\"${LADSPA_PLUGIN_PATH}\\\"\"")

	G.Mk.Check()

	c.Check(s.Output(), equals, "WARN: audio/jack-rack/Makefile:3: The list variable LADSPA_PLUGIN_PATH should not be embedded in a word.\n")
}

func (s *Suite) TestMkLine_variableNeedsQuoting_17(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	G.Mk = s.NewMkLines("x11/eterm/Makefile",
		"# $"+"NetBSD$",
		"DISTFILES=\t${DEFAULT_DISTFILES} ${PIXMAP_FILES}")

	G.Mk.Check()

	c.Check(s.Output(), equals, "") // Don’t warn about missing :Q operators.
}

func (s *Suite) TestMkLine_variableNeedsQuoting_18(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	s.RegisterMasterSite("MASTER_SITE_GNOME", "http://ftp.gnome.org/")
	G.globalData.InitVartypes()
	G.Mk = s.NewMkLines("x11/gtk3/Makefile",
		"# $"+"NetBSD$",
		"MASTER_SITES=\tftp://ftp.gtk.org/${PKGNAME}/ ${MASTER_SITE_GNOME:=subdir/}")

	G.Mk.mklines[1].checkVarassignVaruse()

	c.Check(s.Output(), equals, "") // Don’t warn about missing :Q operators.
}

func (s *Suite) Test_MkLine_variableNeedsQuoting_tool_in_CONFIGURE_ENV(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	G.globalData.Tools = NewToolRegistry()
	G.globalData.Tools.RegisterVarname("tar", "TAR")

	mklines := s.NewMkLines("Makefile",
		"# $"+"NetBSD$",
		"",
		"CONFIGURE_ENV+=\tSYS_TAR_COMMAND_PATH=${TOOLS_TAR:Q}")

	mklines.mklines[2].checkVarassignVaruse()

	// The TOOLS_* variables only contain the path to the tool,
	// without any additional arguments that might be necessary.
	c.Check(s.Output(), equals, "NOTE: Makefile:3: The :Q operator isn't necessary for ${TOOLS_TAR} here.\n")
}

func (s *Suite) Test_MkLine_Varuse_Modifier_L(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	G.Mk = s.NewMkLines("x11/xkeyboard-config/Makefile",
		"FILES_SUBST+=XKBCOMP_SYMLINK=${${XKBBASE}/xkbcomp:L:Q}")

	G.Mk.mklines[0].Check()

	c.Check(s.Output(), equals, "") // Don’t warn that ${XKBBASE}/xkbcomp is used but not defined.
}

func (s *Suite) Test_MkLine_Cond_ShellCommand(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	G.Mk = s.NewMkLines("security/openssl/Makefile",
		"# $"+"NetBSD$",
		".if ${PKGSRC_COMPILER} == \"gcc\" && ${CC} == \"cc\"",
		".endif")

	G.Mk.Check()

	c.Check(s.Output(), equals, "") // Don’t warn about unknown shell command "cc".
}

func (s *Suite) disabledTest_MkLine_Pkgmandir(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	G.Mk = s.NewMkLines("chat/ircII/Makefile",
		"# $"+"NetBSD$",
		"CONFIGURE_ARGS+=--mandir=${DESTDIR}${PREFIX}/man",
		"CONFIGURE_ARGS+=--mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}")

	G.Mk.Check()

	c.Check(s.Output(), equals, "WARN: chat/ircII/Makefile:2: Please use ${PKGMANDIR} instead of \"man\".\n")
}

func (s *Suite) Test_MkLine_Check_Cflags_Backticks(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	G.Mk = s.NewMkLines("chat/pidgin-icb/Makefile",
		"# $"+"NetBSD$",
		"CFLAGS+=\t`pkg-config pidgin --cflags`")
	mkline := G.Mk.mklines[1]

	words, rest := splitIntoMkWords(mkline.Line, mkline.Value())

	c.Check(words, deepEquals, []string{"`pkg-config pidgin --cflags`"})
	c.Check(rest, equals, "")

	G.Mk.mklines[1].CheckVartype("CFLAGS", opAssignAppend, "`pkg-config pidgin --cflags`", "")

	c.Check(s.Output(), equals, "") // No warning about "`pkg-config" being an unknown CFlag.
}

func (s *Suite) Test_MkLine_MasterSites_WordPart(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("geography/viking/Makefile",
		"# $"+"NetBSD$",
		"MASTER_SITES=\t${MASTER_SITE_SOURCEFORGE:=viking/}${VERSION}/")

	mklines.Check()

	c.Check(s.Output(), equals, "WARN: geography/viking/Makefile:2: "+
		"The list variable MASTER_SITE_SOURCEFORGE should not be embedded in a word.\n")
}

func (s *Suite) Test_MkLine_ShellCommand_WordPart(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("x11/lablgtk1/Makefile",
		"# $"+"NetBSD$",
		"CONFIGURE_ENV+=\tCC=${CC}")

	mklines.Check()

	c.Check(s.Output(), equals, "WARN: x11/lablgtk1/Makefile:2: Please use ${CC:Q} instead of ${CC}.\n")
}

func (s *Suite) Test_MkLine_shell_varuse_in_backt_dquot(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("x11/motif/Makefile",
		"# $"+"NetBSD$",
		"post-patch:",
		"\tfiles=`${GREP} -l \".fB$${name}.fP(3)\" *.3`")

	mklines.Check()

	c.Check(s.Output(), equals, "WARN: x11/motif/Makefile:3: Unknown shell command \"${GREP}\".\n") // No parse errors.
}

// See PR 46570, Ctrl+F "3. In lang/perl5".
func (s *Suite) Test_MkLine_getVariableType(c *check.C) {
	mkline := NewMkLine(dummyLine)

	c.Check(mkline.getVariableType("_PERL5_PACKLIST_AWK_STRIP_DESTDIR"), check.IsNil)
	c.Check(mkline.getVariableType("SOME_DIR").guessed, equals, true)
	c.Check(mkline.getVariableType("SOMEDIR").guessed, equals, true)
}

// See PR 46570, Ctrl+F "4. Shell quoting".
// Pkglint is correct, since this definition for CPPFLAGS should be
// seen by the shell as three words, not one word.
func (s *Suite) Test_MkLine_Cflags(c *check.C) {
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("Makefile",
		"# $"+"NetBSD$",
		"CPPFLAGS.SunOS+=\t-DPIPECOMMAND=\\\"/usr/sbin/sendmail -bs %s\\\"")

	mklines.Check()

	c.Check(s.Output(), equals, ""+
		"WARN: Makefile:2: Unknown compiler flag \"-bs\".\n"+
		"WARN: Makefile:2: Compiler flag \"%s\\\\\\\"\" should start with a hyphen.\n")
}
