package main

import "gopkg.in/check.v1"

func (s *Suite) Test_MkLineChecker_CheckVartype__simple_type(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wtypes")
	G.globalData.InitVartypes()
	mkline := NewMkLine(NewLine("fname", 1, "COMMENT=\tA nice package", nil))

	vartype1 := G.globalData.vartypes["COMMENT"]
	c.Assert(vartype1, check.NotNil)
	c.Check(vartype1.guessed, equals, false)

	vartype := mkline.VariableType("COMMENT")

	c.Assert(vartype, check.NotNil)
	c.Check(vartype.basicType.name, equals, "Comment")
	c.Check(vartype.guessed, equals, false)
	c.Check(vartype.kindOfList, equals, lkNone)

	MkLineChecker{mkline}.CheckVartype("COMMENT", opAssign, "A nice package", "")

	c.Check(s.Stdout(), equals, "WARN: fname:1: COMMENT should not begin with \"A\".\n")
}

func (s *Suite) Test_MkLineChecker_CheckVartype(c *check.C) {
	G.globalData.InitVartypes()
	mkline := NewMkLine(NewLine("fname", 1, "DISTNAME=gcc-${GCC_VERSION}", nil))

	MkLineChecker{mkline}.CheckVartype("DISTNAME", opAssign, "gcc-${GCC_VERSION}", "")
}

// Pkglint once interpreted all lists as consisting of shell tokens,
// splitting this URL at the ampersands.
func (s *Suite) Test_MkLineChecker_checkVarassign__URL_with_shell_special_characters(c *check.C) {
	s.Init(c)
	G.Pkg = NewPackage("graphics/gimp-fix-ca")
	G.globalData.InitVartypes()
	mkline := NewMkLine(NewLine("fname", 10, "MASTER_SITES=http://registry.gimp.org/file/fix-ca.c?action=download&id=9884&file=", nil))

	MkLineChecker{mkline}.checkVarassign()

	s.CheckOutputEmpty()
}

func (s *Suite) Test_MkLineChecker_Check__conditions(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wtypes")
	G.globalData.InitVartypes()

	MkLineChecker{NewMkLine(NewLine("fname", 1, ".if !empty(PKGSRC_COMPILER:Mmycc)", nil))}.CheckCond()

	c.Check(s.Stdout(), equals, "WARN: fname:1: The pattern \"mycc\" cannot match any of "+
		"{ ccache ccc clang distcc f2c gcc hp icc ido "+
		"mipspro mipspro-ucode pcc sunpro xlc } for PKGSRC_COMPILER.\n")

	MkLineChecker{NewMkLine(NewLine("fname", 1, ".elif ${A} != ${B}", nil))}.CheckCond()

	c.Check(s.Stdout(), equals, "")

	MkLineChecker{NewMkLine(NewLine("fname", 1, ".if ${HOMEPAGE} == \"mailto:someone@example.org\"", nil))}.CheckCond()

	s.CheckOutputLines(
		"WARN: fname:1: \"mailto:someone@example.org\" is not a valid URL.")

	MkLineChecker{NewMkLine(NewLine("fname", 1, ".if !empty(PKGSRC_RUN_TEST:M[Y][eE][sS])", nil))}.CheckCond()

	s.CheckOutputLines(
		"WARN: fname:1: PKGSRC_RUN_TEST should be matched against \"[yY][eE][sS]\" or \"[nN][oO]\", not \"[Y][eE][sS]\".")

	MkLineChecker{NewMkLine(NewLine("fname", 1, ".if !empty(IS_BUILTIN.Xfixes:M[yY][eE][sS])", nil))}.CheckCond()

	s.CheckOutputEmpty()

	MkLineChecker{NewMkLine(NewLine("fname", 1, ".if !empty(${IS_BUILTIN.Xfixes:M[yY][eE][sS]})", nil))}.CheckCond()

	s.CheckOutputLines(
		"WARN: fname:1: The empty() function takes a variable name as parameter, not a variable expression.")

	MkLineChecker{NewMkLine(NewLine("fname", 1, ".if ${EMUL_PLATFORM} == \"linux-x386\"", nil))}.CheckCond()

	s.CheckOutputLines(
		"WARN: fname:1: \"x386\" is not valid for the hardware architecture part of EMUL_PLATFORM. Use one of { aarch64 aarch64eb alpha amd64 arc arm arm26 arm32 cobalt coldfire convex dreamcast earm earmeb earmhf earmhfeb earmv4 earmv4eb earmv5 earmv5eb earmv6 earmv6eb earmv6hf earmv6hfeb earmv7 earmv7eb earmv7hf earmv7hfeb evbarm hpcmips hpcsh hppa hppa64 i386 i586 i686 ia64 m68000 m68k m88k mips mips64 mips64eb mips64el mipseb mipsel mipsn32 mlrisc ns32k pc532 pmax powerpc powerpc64 rs6000 s390 sh3eb sh3el sparc sparc64 vax x86_64 } instead.")

	MkLineChecker{NewMkLine(NewLine("fname", 1, ".if ${EMUL_PLATFORM:Mlinux-x386}", nil))}.CheckCond()

	s.CheckOutputLines(
		"WARN: fname:1: The pattern \"x386\" cannot match any of { aarch64 aarch64eb alpha amd64 arc arm arm26 arm32 cobalt coldfire convex dreamcast earm earmeb earmhf earmhfeb earmv4 earmv4eb earmv5 earmv5eb earmv6 earmv6eb earmv6hf earmv6hfeb earmv7 earmv7eb earmv7hf earmv7hfeb evbarm hpcmips hpcsh hppa hppa64 i386 i586 i686 ia64 m68000 m68k m88k mips mips64 mips64eb mips64el mipseb mipsel mipsn32 mlrisc ns32k pc532 pmax powerpc powerpc64 rs6000 s390 sh3eb sh3el sparc sparc64 vax x86_64 } for the hardware architecture part of EMUL_PLATFORM.")

	MkLineChecker{NewMkLine(NewLine("fname", 98, ".if ${MACHINE_PLATFORM:MUnknownOS-*-*} || ${MACHINE_ARCH:Mx86}", nil))}.CheckCond()

	s.CheckOutputLines(
		"WARN: fname:98: The pattern \"UnknownOS\" cannot match any of { AIX BSDOS Bitrig Cygwin Darwin DragonFly FreeBSD FreeMiNT GNUkFreeBSD HPUX Haiku IRIX Interix Linux Minix MirBSD NetBSD OSF1 OpenBSD QNX SCO_SV SunOS UnixWare } for the operating system part of MACHINE_PLATFORM.",
		"WARN: fname:98: The pattern \"x86\" cannot match any of { aarch64 aarch64eb alpha amd64 arc arm arm26 arm32 cobalt coldfire convex dreamcast earm earmeb earmhf earmhfeb earmv4 earmv4eb earmv5 earmv5eb earmv6 earmv6eb earmv6hf earmv6hfeb earmv7 earmv7eb earmv7hf earmv7hfeb evbarm hpcmips hpcsh hppa hppa64 i386 i586 i686 ia64 m68000 m68k m88k mips mips64 mips64eb mips64el mipseb mipsel mipsn32 mlrisc ns32k pc532 pmax powerpc powerpc64 rs6000 s390 sh3eb sh3el sparc sparc64 vax x86_64 } for MACHINE_ARCH.")
}

func (s *Suite) Test_MkLineChecker_checkVarassign(c *check.C) {
	s.Init(c)
	G.globalData.InitVartypes()

	G.Mk = s.NewMkLines("Makefile",
		mkrcsid,
		"ac_cv_libpari_libs+=\t-L${BUILDLINK_PREFIX.pari}/lib") // From math/clisp-pari/Makefile, rev. 1.8

	MkLineChecker{G.Mk.mklines[1]}.checkVarassign()

	s.CheckOutputLines(
		"WARN: Makefile:2: ac_cv_libpari_libs is defined but not used. Spelling mistake?")
}

func (s *Suite) Test_MkLineChecker_checkVarassignDefPermissions(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.globalData.InitVartypes()
	mkline := NewMkLine(NewLine("options.mk", 2, "PKG_DEVELOPER?=\tyes", nil))

	MkLineChecker{mkline}.checkVarassignDefPermissions()

	s.CheckOutputLines(
		"WARN: options.mk:2: The variable PKG_DEVELOPER may not be given a default value by any package.")
}

func (s *Suite) Test_MkLineChecker_CheckVarusePermissions(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("options.mk",
		mkrcsid,
		"COMMENT=\t${GAMES_USER}",
		"COMMENT:=\t${PKGBASE}",
		"PYPKGPREFIX=${PKGBASE}")
	G.globalData.UserDefinedVars = map[string]MkLine{
		"GAMES_USER": mklines.mklines[0],
	}

	mklines.Check()

	s.CheckOutputLines(
		"WARN: options.mk:2: The user-defined variable GAMES_USER is used but not added to BUILD_DEFS.",
		"WARN: options.mk:3: PKGBASE should not be evaluated at load time.",
		"WARN: options.mk:4: The variable PYPKGPREFIX may not be set in this file; it would be ok in pyversion.mk.",
		"WARN: options.mk:4: PKGBASE should not be evaluated indirectly at load time.",
		"NOTE: options.mk:4: This variable value should be aligned to column 17.")
}

func (s *Suite) Test_MkLineChecker_CheckVarusePermissions__load_time(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("options.mk",
		mkrcsid,
		"WRKSRC:=${.CURDIR}")

	mklines.Check()

	s.CheckOutputEmpty() // Don't warn that ".CURDIR should not be evaluated at load time."
}

func (s *Suite) Test_MkLineChecker_WarnVaruseLocalbase(c *check.C) {
	s.Init(c)
	mkline := NewMkLine(NewLine("options.mk", 56, "PKGNAME=${LOCALBASE}", nil))

	MkLineChecker{mkline}.WarnVaruseLocalbase()

	s.CheckOutputLines(
		"WARN: options.mk:56: The LOCALBASE variable should not be used by packages.")
}

func (s *Suite) Test_MkLineChecker_CheckRelativePkgdir(c *check.C) {
	s.Init(c)
	mkline := NewMkLine(NewLine("Makefile", 46, "# dummy", nil))

	MkLineChecker{mkline}.CheckRelativePkgdir("../pkgbase")

	s.CheckOutputLines(
		"ERROR: Makefile:46: \"../pkgbase\" does not exist.",
		"WARN: Makefile:46: \"../pkgbase\" is not a valid relative package directory.")
}

// PR pkg/46570, item 2
func (s *Suite) Test_MkLineChecker__unclosed_varuse(c *check.C) {
	s.Init(c)
	mkline := NewMkLine(NewLine("Makefile", 93, "EGDIRS=${EGDIR/apparmor.d ${EGDIR/dbus-1/system.d ${EGDIR/pam.d", nil))

	MkLineChecker{mkline}.checkVarassign()

	s.CheckOutputLines(
		"WARN: Makefile:93: Pkglint parse error in MkLine.Tokenize at \"${EGDIR/apparmor.d ${EGDIR/dbus-1/system.d ${EGDIR/pam.d\".",
		"WARN: Makefile:93: Pkglint parse error in ShTokenizer.ShAtom at \"${EGDIR/apparmor.d ${EGDIR/dbus-1/system.d ${EGDIR/pam.d\" (quoting=plain)",
		"WARN: Makefile:93: EGDIRS is defined but not used. Spelling mistake?")
}

func (s *Suite) Test_MkLineChecker__Varuse_Modifier_L(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.globalData.InitVartypes()
	G.Mk = s.NewMkLines("x11/xkeyboard-config/Makefile",
		"FILES_SUBST+=XKBCOMP_SYMLINK=${${XKBBASE}/xkbcomp:L:Q}")

	MkLineChecker{G.Mk.mklines[0]}.Check()

	s.CheckOutputEmpty() // Don't warn that ${XKBBASE}/xkbcomp is used but not defined.
}

func (s *Suite) Test_MkLineChecker_CheckCond__comparison_with_shell_command(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.globalData.InitVartypes()
	G.Mk = s.NewMkLines("security/openssl/Makefile",
		mkrcsid,
		".if ${PKGSRC_COMPILER} == \"gcc\" && ${CC} == \"cc\"",
		".endif")

	G.Mk.Check()

	// Don't warn about unknown shell command "cc".
	s.CheckOutputLines(
		"WARN: security/openssl/Makefile:2: Use ${PKGSRC_COMPILER:Mgcc} instead of the == operator.")
}

func (s *Suite) Test_MkLine_CheckCond_comparing_PKGSRC_COMPILER_with_eqeq(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.globalData.InitVartypes()
	G.Mk = s.NewMkLines("audio/pulseaudio/Makefile",
		mkrcsid,
		".if ${OPSYS} == \"Darwin\" && ${PKGSRC_COMPILER} == \"clang\"",
		".endif")

	G.Mk.Check()

	s.CheckOutputLines(
		"WARN: audio/pulseaudio/Makefile:2: Use ${PKGSRC_COMPILER:Mclang} instead of the == operator.")
}

func (s *Suite) Test_MkLineChecker_CheckVartype__CFLAGS_with_backticks(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.globalData.InitVartypes()
	G.Mk = s.NewMkLines("chat/pidgin-icb/Makefile",
		mkrcsid,
		"CFLAGS+=\t`pkg-config pidgin --cflags`")
	mkline := G.Mk.mklines[1]

	words, rest := splitIntoMkWords(mkline, mkline.Value())

	c.Check(words, deepEquals, []string{"`pkg-config pidgin --cflags`"})
	c.Check(rest, equals, "")

	MkLineChecker{G.Mk.mklines[1]}.CheckVartype("CFLAGS", opAssignAppend, "`pkg-config pidgin --cflags`", "")

	s.CheckOutputEmpty() // No warning about "`pkg-config" being an unknown CFlag.
}

// See PR 46570, Ctrl+F "4. Shell quoting".
// Pkglint is correct, since the shell sees this definition for
// CPPFLAGS as three words, not one word.
func (s *Suite) Test_MkLineChecker_CheckVartype_CFLAGS(c *check.C) {
	s.Init(c)
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("Makefile",
		mkrcsid,
		"CPPFLAGS.SunOS+=\t-DPIPECOMMAND=\\\"/usr/sbin/sendmail -bs %s\\\"")

	mklines.Check()

	s.CheckOutputLines(
		"WARN: Makefile:2: Unknown compiler flag \"-bs\".",
		"WARN: Makefile:2: Compiler flag \"%s\\\\\\\"\" should start with a hyphen.")
}
