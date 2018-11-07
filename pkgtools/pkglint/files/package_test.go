package main

import "gopkg.in/check.v1"

func (s *Suite) Test_Package_checklinesBuildlink3Inclusion__file_but_not_package(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("category/dependency/buildlink3.mk")
	G.Pkg = NewPackage(t.File("category/package"))
	mklines := t.NewMkLines("category/package/buildlink3.mk",
		MkRcsID,
		"",
		".include \"../../category/dependency/buildlink3.mk\"")

	G.Pkg.checklinesBuildlink3Inclusion(mklines)

	t.CheckOutputLines(
		"WARN: category/package/buildlink3.mk:3: category/dependency/buildlink3.mk is included by this file but not by the package.")
}

func (s *Suite) Test_Package_checklinesBuildlink3Inclusion__package_but_not_file(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("category/dependency/buildlink3.mk")
	G.Pkg = NewPackage(t.File("category/package"))
	G.Pkg.bl3["../../category/dependency/buildlink3.mk"] = t.NewLine("fileName", 1, "")
	mklines := t.NewMkLines("category/package/buildlink3.mk",
		MkRcsID)

	t.EnableTracingToLog()
	G.Pkg.checklinesBuildlink3Inclusion(mklines)

	t.CheckOutputLines(
		"TRACE: + (*Package).checklinesBuildlink3Inclusion()",
		"TRACE: 1   ../../category/dependency/buildlink3.mk/buildlink3.mk is included by the package but not by the buildlink3.mk file.",
		"TRACE: - (*Package).checklinesBuildlink3Inclusion()")
}

func (s *Suite) Test_Package_pkgnameFromDistname(c *check.C) {
	t := s.Init(c)

	pkg := NewPackage(t.File("category/package"))
	pkg.vars.Define("PKGNAME", t.NewMkLine("Makefile", 5, "PKGNAME=dummy"))

	c.Check(pkg.pkgnameFromDistname("pkgname-1.0", "whatever"), equals, "pkgname-1.0")
	c.Check(pkg.pkgnameFromDistname("${DISTNAME}", "distname-1.0"), equals, "distname-1.0")
	c.Check(pkg.pkgnameFromDistname("${DISTNAME:S/dist/pkg/}", "distname-1.0"), equals, "pkgname-1.0")
	c.Check(pkg.pkgnameFromDistname("${DISTNAME:S|a|b|g}", "panama-0.13"), equals, "pbnbmb-0.13")
	c.Check(pkg.pkgnameFromDistname("${DISTNAME:S|^lib||}", "libncurses"), equals, "ncurses")
	c.Check(pkg.pkgnameFromDistname("${DISTNAME:S|^lib||}", "mylib"), equals, "mylib")
	c.Check(pkg.pkgnameFromDistname("${DISTNAME:tl:S/-/./g:S/he/-/1}", "SaxonHE9-5-0-1J"), equals, "saxon-9.5.0.1j")
	c.Check(pkg.pkgnameFromDistname("${DISTNAME:C/beta/.0./}", "fspanel-0.8beta1"), equals, "${DISTNAME:C/beta/.0./}")
	c.Check(pkg.pkgnameFromDistname("${DISTNAME:S/-0$/.0/1}", "aspell-af-0.50-0"), equals, "aspell-af-0.50.0")

	// FIXME: Should produce a parse error since the :S modifier is malformed; see Test_MkParser_MkTokens.
	c.Check(pkg.pkgnameFromDistname("${DISTNAME:S,a,b,c,d}", "aspell-af-0.50-0"), equals, "bspell-af-0.50-0")

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_CheckVarorder(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Worder")
	pkg := NewPackage(t.File("x11/9term"))

	pkg.CheckVarorder(t.NewMkLines("Makefile",
		MkRcsID,
		"",
		"GITHUB_PROJECT=project",
		"DISTNAME=9term",
		"CATEGORIES=x11"))

	t.CheckOutputLines(
		"WARN: Makefile:3: The canonical order of the variables is " +
			"GITHUB_PROJECT, DISTNAME, CATEGORIES, GITHUB_PROJECT, empty line, COMMENT, LICENSE.")

	pkg.CheckVarorder(t.NewMkLines("Makefile",
		MkRcsID,
		"",
		"DISTNAME=9term",
		"CATEGORIES=x11",
		"",
		".include \"../../mk/bsd.pkg.mk\""))

	t.CheckOutputLines(
		"WARN: Makefile:3: The canonical order of the variables is " +
			"DISTNAME, CATEGORIES, empty line, COMMENT, LICENSE.")
}

// Ensure that comments and empty lines do not lead to panics.
func (s *Suite) Test_Package_CheckVarorder__comments_do_not_crash(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Worder")
	pkg := NewPackage(t.File("x11/9term"))

	pkg.CheckVarorder(t.NewMkLines("Makefile",
		MkRcsID,
		"",
		"GITHUB_PROJECT=project",
		"",
		"# comment",
		"",
		"DISTNAME=9term",
		"# comment",
		"CATEGORIES=x11"))

	t.CheckOutputLines(
		"WARN: Makefile:3: The canonical order of the variables is " +
			"GITHUB_PROJECT, DISTNAME, CATEGORIES, GITHUB_PROJECT, empty line, COMMENT, LICENSE.")
}

func (s *Suite) Test_Package_CheckVarorder__comments_are_ignored(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Worder")

	pkg := NewPackage(t.File("x11/9term"))

	pkg.CheckVarorder(t.NewMkLines("Makefile",
		MkRcsID,
		"",
		"DISTNAME=\tdistname-1.0",
		"CATEGORIES=\tsysutils",
		"",
		"MAINTAINER=\tpkgsrc-users@NetBSD.org",
		"# comment",
		"COMMENT=\tComment",
		"LICENSE=\tgnu-gpl-v2"))

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_CheckVarorder__skip_if_there_are_directives(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Worder")

	pkg := NewPackage(t.File("category/package"))

	pkg.CheckVarorder(t.NewMkLines("Makefile",
		MkRcsID,
		"",
		"DISTNAME=\tdistname-1.0",
		"CATEGORIES=\tsysutils",
		"",
		".if ${DISTNAME:Mdistname-*}",
		"MAINTAINER=\tpkgsrc-users@NetBSD.org",
		".endif",
		"LICENSE=\tgnu-gpl-v2"))

	// No warning about the missing COMMENT since the directive
	// causes the whole check to be skipped.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_CheckVarorder__GitHub(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Worder")
	pkg := NewPackage(t.File("x11/9term"))

	pkg.CheckVarorder(t.NewMkLines("Makefile",
		MkRcsID,
		"",
		"DISTNAME=\t\tautocutsel-0.10.0",
		"CATEGORIES=\t\tx11",
		"MASTER_SITES=\t\t${MASTER_SITE_GITHUB:=sigmike/}",
		"GITHUB_PROJECT=\t\tautocutsel",
		"GITHUB_TAG=\t\t${PKGVERSION_NOREV}",
		"",
		"COMMENT=\tComment",
		"LICENSE=\tgnu-gpl-v2"))

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_CheckVarorder__license(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Worder")

	t.CreateFileLines("mk/bsd.pkg.mk", "# dummy")
	t.CreateFileLines("x11/Makefile", MkRcsID)
	t.CreateFileLines("x11/9term/PLIST", PlistRcsID, "bin/9term")
	t.CreateFileLines("x11/9term/distinfo", RcsID)
	t.CreateFileLines("x11/9term/Makefile",
		MkRcsID,
		"",
		"DISTNAME=9term-1.0",
		"CATEGORIES=x11",
		"",
		"COMMENT=Terminal",
		"",
		".include \"../../mk/bsd.pkg.mk\"")

	t.SetupVartypes()

	G.CheckDirent(t.File("x11/9term"))

	// Since the error is grave enough, the warning about the correct position is suppressed.
	t.CheckOutputLines(
		"ERROR: ~/x11/9term/Makefile: Each package must define its LICENSE.")
}

// https://mail-index.netbsd.org/tech-pkg/2017/01/18/msg017698.html
func (s *Suite) Test_Package_CheckVarorder__MASTER_SITES(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Worder")
	pkg := NewPackage(t.File("category/package"))

	pkg.CheckVarorder(t.NewMkLines("Makefile",
		MkRcsID,
		"",
		"PKGNAME=\tpackage-1.0",
		"CATEGORIES=\tcategory",
		"MASTER_SITES=\thttp://example.org/",
		"MASTER_SITES+=\thttp://mirror.example.org/",
		"",
		"COMMENT=\tComment",
		"LICENSE=\tgnu-gpl-v2"))

	// No warning that "MASTER_SITES appears too late"
	t.CheckOutputEmpty()
}

// The diagnostics must be helpful.
// In the case of wip/ioping, they were ambiguous and wrong.
func (s *Suite) Test_Package_CheckVarorder__diagnostics(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Worder")
	t.SetupVartypes()
	pkg := NewPackage(t.File("category/package"))

	pkg.CheckVarorder(t.NewMkLines("Makefile",
		MkRcsID,
		"",
		"CATEGORIES=     net",
		"",
		"COMMENT=        Comment",
		"LICENSE=        gnu-gpl-v3",
		"",
		"GITHUB_PROJECT= pkgbase",
		"DISTNAME=       v1.0",
		"PKGNAME=        ${GITHUB_PROJECT}-${DISTNAME}",
		"MASTER_SITES=   ${MASTER_SITE_GITHUB:=project/}",
		"DIST_SUBDIR=    ${GITHUB_PROJECT}",
		"",
		"MAINTAINER=     maintainer@example.org",
		"HOMEPAGE=       https://github.com/project/pkgbase/",
		"",
		".include \"../../mk/bsd.pkg.mk\""))

	t.CheckOutputLines(
		"WARN: Makefile:3: The canonical order of the variables is " +
			"GITHUB_PROJECT, DISTNAME, PKGNAME, CATEGORIES, MASTER_SITES, GITHUB_PROJECT, DIST_SUBDIR, empty line, " +
			"MAINTAINER, HOMEPAGE, COMMENT, LICENSE.")

	// After moving the variables according to the warning:
	pkg.CheckVarorder(t.NewMkLines("Makefile",
		MkRcsID,
		"",
		"GITHUB_PROJECT= pkgbase",
		"DISTNAME=       v1.0",
		"PKGNAME=        ${GITHUB_PROJECT}-${DISTNAME}",
		"CATEGORIES=     net",
		"MASTER_SITES=   ${MASTER_SITE_GITHUB:=project/}",
		"DIST_SUBDIR=    ${GITHUB_PROJECT}",
		"",
		"MAINTAINER=     maintainer@example.org",
		"HOMEPAGE=       https://github.com/project/pkgbase/",
		"COMMENT=        Comment",
		"LICENSE=        gnu-gpl-v3",
		"",
		".include \"../../mk/bsd.pkg.mk\""))

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_getNbpart(c *check.C) {
	t := s.Init(c)

	pkg := NewPackage(t.File("category/pkgbase"))
	pkg.vars.Define("PKGREVISION", t.NewMkLine("Makefile", 1, "PKGREVISION=14"))

	c.Check(pkg.getNbpart(), equals, "nb14")

	pkg.vars = NewScope()
	pkg.vars.Define("PKGREVISION", t.NewMkLine("Makefile", 1, "PKGREVISION=asdf"))

	c.Check(pkg.getNbpart(), equals, "")
}

func (s *Suite) Test_Package_determineEffectivePkgVars__precedence(c *check.C) {
	t := s.Init(c)

	pkg := NewPackage(t.File("category/pkgbase"))
	pkgnameLine := t.NewMkLine("Makefile", 3, "PKGNAME=pkgname-1.0")
	distnameLine := t.NewMkLine("Makefile", 4, "DISTNAME=distname-1.0")
	pkgrevisionLine := t.NewMkLine("Makefile", 5, "PKGREVISION=13")

	pkg.vars.Define(pkgnameLine.Varname(), pkgnameLine)
	pkg.vars.Define(distnameLine.Varname(), distnameLine)
	pkg.vars.Define(pkgrevisionLine.Varname(), pkgrevisionLine)

	pkg.determineEffectivePkgVars()

	c.Check(pkg.EffectivePkgbase, equals, "pkgname")
	c.Check(pkg.EffectivePkgname, equals, "pkgname-1.0nb13")
	c.Check(pkg.EffectivePkgversion, equals, "1.0")
}

func (s *Suite) Test_Package_determineEffectivePkgVars__same(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall,no-order")
	pkg := t.SetupPackage("category/package",
		"DISTNAME=\tdistname-1.0",
		"PKGNAME=\tdistname-1.0")

	G.CheckDirent(pkg)

	t.CheckOutputLines(
		"NOTE: ~/category/package/Makefile:20: " +
			"PKGNAME is ${DISTNAME} by default. You probably don't need to define PKGNAME.")
}

func (s *Suite) Test_Package_determineEffectivePkgVars__invalid_DISTNAME(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall,no-order")
	pkg := t.SetupPackage("category/package",
		"DISTNAME=\tpkgname-version")

	G.CheckDirent(pkg)

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:3: " +
			"As DISTNAME is not a valid package name, please define the PKGNAME explicitly.")
}

func (s *Suite) Test_Package_checkPossibleDowngrade(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("doc/CHANGES-2018",
		"\tUpdated category/pkgbase to 1.8 [committer 2018-01-05]")
	G.Pkgsrc.loadDocChanges()

	t.Chdir("category/pkgbase")
	G.Pkg = NewPackage(".")
	G.Pkg.EffectivePkgname = "package-1.0nb15"
	G.Pkg.EffectivePkgnameLine = t.NewMkLine("Makefile", 5, "PKGNAME=dummy")

	G.Pkg.checkPossibleDowngrade()

	t.CheckOutputLines(
		"WARN: Makefile:5: The package is being downgraded from 1.8 (see ../../doc/CHANGES-2018:1) to 1.0nb15.")

	G.Pkgsrc.LastChange["category/pkgbase"].Version = "1.0nb22"

	G.Pkg.checkPossibleDowngrade()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_loadPackageMakefile__dump(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--dumpmakefile")
	t.SetupVartypes()
	t.SetupPkgsrc()
	t.CreateFileLines("category/Makefile")
	t.CreateFileLines("category/package/PLIST",
		PlistRcsID,
		"bin/program")
	t.CreateFileLines("category/package/distinfo",
		RcsID,
		"",
		"SHA1 (distfile-1.0.tar.gz) = 12341234...",
		"RMD160 (distfile-1.0.tar.gz) = 12341234...",
		"SHA512 (distfile-1.0.tar.gz) = 12341234...",
		"Size (distfile-1.0.tar.gz) = 12341234...")
	t.CreateFileLines("category/package/Makefile",
		MkRcsID,
		"",
		"CATEGORIES=category",
		"",
		"COMMENT=\tComment",
		"LICENSE=\t2-clause-bsd")

	G.checkdirPackage(t.File("category/package"))

	t.CheckOutputLines(
		"Whole Makefile (with all included files) follows:",
		"~/category/package/Makefile:1: "+MkRcsID,
		"~/category/package/Makefile:2: ",
		"~/category/package/Makefile:3: CATEGORIES=category",
		"~/category/package/Makefile:4: ",
		"~/category/package/Makefile:5: COMMENT=\tComment",
		"~/category/package/Makefile:6: LICENSE=\t2-clause-bsd")
}

func (s *Suite) Test_Package__varuse_at_load_time(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()
	t.SetupTool("printf", "", AtRunTime)
	t.CreateFileLines("licenses/2-clause-bsd",
		"# dummy")
	t.CreateFileLines("misc/Makefile")
	t.CreateFileLines("mk/tools/defaults.mk",
		"TOOLS_CREATE+=false",
		"TOOLS_CREATE+=nice",
		"TOOLS_CREATE+=true",
		"_TOOLS_VARNAME.nice=NICE")

	t.CreateFileLines("category/pkgbase/Makefile",
		MkRcsID,
		"",
		"PKGNAME=        loadtime-vartest-1.0",
		"CATEGORIES=     misc",
		"",
		"COMMENT=        Demonstrate variable values during parsing",
		"LICENSE=        2-clause-bsd",
		"",
		"PLIST_SRC=      # none",
		"NO_CHECKSUM=    yes",
		"NO_CONFIGURE=   yes",
		"",
		"USE_TOOLS+=     echo false",
		"FALSE_BEFORE!=  echo false=${FALSE:Q}", // false=
		"NICE_BEFORE!=   echo nice=${NICE:Q}",   // nice=
		"TRUE_BEFORE!=   echo true=${TRUE:Q}",   // true=
		//
		// All three variables above are empty since the tool
		// variables are initialized by bsd.prefs.mk. The variables
		// from share/mk/sys.mk are available, though.
		//
		"",
		".include \"../../mk/bsd.prefs.mk\"",
		//
		// Now all tools from USE_TOOLS are defined with their variables.
		// ${FALSE} works, but a plain "false" might call the wrong tool.
		// That's because the tool wrappers are not set up yet. This
		// happens between the post-depends and pre-fetch stages. Even
		// then, the plain tool names may only be used in the
		// {pre,do,post}-* targets, since a recursive make(1) needs to be
		// run to set up the correct PATH.
		//
		"",
		"USE_TOOLS+=     nice",
		//
		// The "nice" tool will only be available as ${NICE} after bsd.pkg.mk
		// has been included. Even including bsd.prefs.mk another time does
		// not have any effect since it is guarded against multiple inclusion.
		//
		"",
		".include \"../../mk/bsd.prefs.mk\"", // Has no effect.
		"",
		"FALSE_AFTER!=   echo false=${FALSE:Q}", // false=false
		"NICE_AFTER!=    echo nice=${NICE:Q}",   // nice=
		"TRUE_AFTER!=    echo true=${TRUE:Q}",   // true=true
		"",
		"do-build:",
		"\t${RUN} printf 'before:  %-20s  %-20s  %-20s\\n' ${FALSE_BEFORE} ${NICE_BEFORE} ${TRUE_BEFORE}",
		"\t${RUN} printf 'after:   %-20s  %-20s  %-20s\\n' ${FALSE_AFTER} ${NICE_AFTER} ${TRUE_AFTER}",
		"\t${RUN} printf 'runtime: %-20s  %-20s  %-20s\\n' false=${FALSE:Q} nice=${NICE:Q} true=${TRUE:Q}",
		"",
		".include \"../../mk/bsd.pkg.mk\"")

	t.SetupCommandLine("-q", "-Wall,no-space")
	G.Pkgsrc.LoadInfrastructure()
	G.CheckDirent(t.File("category/pkgbase"))

	t.CheckOutputLines(
		"WARN: ~/category/pkgbase/Makefile:14: To use the tool ${FALSE} at load time, bsd.prefs.mk has to be included before.",
		"WARN: ~/category/pkgbase/Makefile:15: To use the tool ${NICE} at load time, it has to be added to USE_TOOLS before including bsd.prefs.mk.",
		"WARN: ~/category/pkgbase/Makefile:16: To use the tool ${TRUE} at load time, bsd.prefs.mk has to be included before.",
		"WARN: ~/category/pkgbase/Makefile:25: To use the tool ${NICE} at load time, it has to be added to USE_TOOLS before including bsd.prefs.mk.")
}

func (s *Suite) Test_Package_loadPackageMakefile(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("category/package/Makefile",
		MkRcsID,
		"",
		"PKGNAME=pkgname-1.67",
		"DISTNAME=distfile_1_67",
		".include \"../../category/package/Makefile\"")
	G.Pkg = NewPackage(t.File("category/package"))

	G.Pkg.loadPackageMakefile()

	// Including a package Makefile directly is an error (in the last line),
	// but that is checked later.
	// A file including itself does not lead to an endless loop while parsing
	// but may still produce unexpected warnings, such as redundant definitions.
	t.CheckOutputLines(
		"NOTE: ~/category/package/Makefile:3: Definition of PKGNAME is redundant "+
			"because of ../../category/package/Makefile:3.",
		"NOTE: ~/category/package/Makefile:4: Definition of DISTNAME is redundant "+
			"because of ../../category/package/Makefile:4.")
}

func (s *Suite) Test_Package_loadPackageMakefile__PECL_VERSION(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("lang/php/ext.mk",
		MkRcsID,
		"",
		"PHPEXT_MK=      # defined",
		"PHPPKGSRCDIR=   ../../lang/php72",
		"LICENSE?=        unknown-license",
		"COMMENT?=       Some PHP package",
		"GENERATE_PLIST+=# none",
		"",
		".if !defined(PECL_VERSION)",
		"DISTINFO_FILE=  ${.CURDIR}/${PHPPKGSRCDIR}/distinfo",
		".endif",
		".if defined(USE_PHP_EXT_PATCHES)",
		"PATCHDIR=       ${.CURDIR}/${PHPPKGSRCDIR}/patches",
		".endif")
	pkg := t.SetupPackage("category/package",
		"PECL_VERSION=\t1.1.2",
		".include \"../../lang/php/ext.mk\"")

	G.CheckDirent(pkg)
}

func (s *Suite) Test_Package_CheckInclude__conditional_and_unconditional_include(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	t.CreateFileLines("devel/zlib/buildlink3.mk", "")
	t.CreateFileLines("licenses/gnu-gpl-v2", "")
	t.CreateFileLines("mk/bsd.pkg.mk", "")
	t.CreateFileLines("sysutils/coreutils/buildlink3.mk", "")

	t.Chdir("category/package")
	t.CreateFileLines("Makefile",
		MkRcsID,
		"",
		"COMMENT=\tDescription",
		"LICENSE=\tgnu-gpl-v2",
		".include \"../../devel/zlib/buildlink3.mk\"",
		".if ${OPSYS} == \"Linux\"",
		".include \"../../sysutils/coreutils/buildlink3.mk\"",
		".endif",
		".include \"../../mk/bsd.pkg.mk\"")
	t.CreateFileLines("options.mk",
		MkRcsID,
		"",
		".if !empty(PKG_OPTIONS:Mzlib)",
		".  include \"../../devel/zlib/buildlink3.mk\"",
		".endif",
		".include \"../../sysutils/coreutils/buildlink3.mk\"")
	t.CreateFileLines("PLIST",
		PlistRcsID,
		"bin/program")
	t.CreateFileLines("distinfo",
		RcsID)

	G.checkdirPackage(".")

	t.CheckOutputLines(
		"WARN: Makefile:3: The canonical order of the variables is CATEGORIES, empty line, COMMENT, LICENSE.",
		"WARN: options.mk:3: Unknown option \"zlib\".",
		"WARN: options.mk:4: \"../../devel/zlib/buildlink3.mk\" is "+
			"included conditionally here (depending on PKG_OPTIONS) and unconditionally in Makefile:5.",
		"WARN: options.mk:6: \"../../sysutils/coreutils/buildlink3.mk\" is "+
			"included unconditionally here and conditionally in Makefile:7 (depending on OPSYS).",
		"WARN: options.mk:3: Expected definition of PKG_OPTIONS_VAR.")
}

// See https://github.com/rillig/pkglint/issues/1
func (s *Suite) Test_Package__include_without_exists(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	t.CreateFileLines("mk/bsd.pkg.mk")
	t.CreateFileLines("category/package/Makefile",
		MkRcsID,
		"",
		".include \"options.mk\"",
		"",
		".include \"../../mk/bsd.pkg.mk\"")

	G.checkdirPackage(t.File("category/package"))

	t.CheckOutputLines(
		"ERROR: ~/category/package/Makefile:3: Cannot read \"options.mk\".")
}

// See https://github.com/rillig/pkglint/issues/1
func (s *Suite) Test_Package__include_after_exists(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	t.CreateFileLines("mk/bsd.pkg.mk")
	t.Chdir("category/package")
	t.CreateFileLines("Makefile",
		MkRcsID,
		"",
		".if exists(options.mk)",
		".  include \"options.mk\"",
		".endif",
		"",
		".include \"../../mk/bsd.pkg.mk\"")

	G.checkdirPackage(".")

	t.CheckOutputLines(
		"WARN: Makefile: Neither PLIST nor PLIST.common exist, and PLIST_SRC is unset.",
		"WARN: distinfo: File not found. Please run \""+confMake+" makesum\" or define NO_CHECKSUM=yes in the package Makefile.",
		"ERROR: Makefile: Each package must define its LICENSE.",
		"WARN: Makefile: No COMMENT given.",
		"ERROR: Makefile:4: \"options.mk\" does not exist.")
}

// See https://github.com/rillig/pkglint/issues/1
func (s *Suite) Test_Package_readMakefile__include_other_after_exists(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	t.CreateFileLines("mk/bsd.pkg.mk")
	t.CreateFileLines("category/package/Makefile",
		MkRcsID,
		"",
		".if exists(options.mk)",
		".  include \"another.mk\"",
		".endif",
		"",
		".include \"../../mk/bsd.pkg.mk\"")

	G.checkdirPackage(t.File("category/package"))

	t.CheckOutputLines(
		"ERROR: ~/category/package/Makefile:4: Cannot read \"another.mk\".")
}

// See https://mail-index.netbsd.org/tech-pkg/2018/07/22/msg020092.html
func (s *Suite) Test_Package__redundant_master_sites(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	t.SetupMasterSite("MASTER_SITE_R_CRAN", "http://cran.r-project.org/src/")
	t.CreateFileLines("mk/bsd.pkg.mk")
	t.CreateFileLines("licenses/gnu-gpl-v2",
		"The licenses for most software are designed to take away ...")
	t.CreateFileLines("math/R/Makefile.extension",
		MkRcsID,
		"",
		"PKGNAME?=\tR-${R_PKGNAME}-${R_PKGVER}",
		"MASTER_SITES?=\t${MASTER_SITE_R_CRAN:=contrib/}",
		"GENERATE_PLIST+=\techo \"bin/r-package\";",
		"NO_CHECKSUM=\tyes",
		"LICENSE?=\tgnu-gpl-v2")
	t.CreateFileLines("math/R-date/Makefile",
		MkRcsID,
		"",
		"R_PKGNAME=\tdate",
		"R_PKGVER=\t1.2.3",
		"COMMENT=\tR package for handling date arithmetic",
		"MASTER_SITES=\t${MASTER_SITE_R_CRAN:=contrib/}", // Redundant; see math/R/Makefile.extension.
		"",
		".include \"../../math/R/Makefile.extension\"",
		".include \"../../mk/bsd.pkg.mk\"")

	// See Package.checkfilePackageMakefile
	// See Scope.uncond
	G.checkdirPackage(t.File("math/R-date"))

	t.CheckOutputLines(
		"NOTE: ~/math/R-date/Makefile:6: Definition of MASTER_SITES is redundant because of ../../math/R/Makefile.extension:4.")
}

func (s *Suite) Test_Package_checkUpdate(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()
	t.CreateFileLines("doc/TODO",
		"Suggested package updates",
		"",
		"",
		"\t"+"O wrong bullet",
		"\t"+"o package-without-version",
		"\t"+"o package1-1.0",
		"\t"+"o package2-2.0 [nice new features]",
		"\t"+"o package3-3.0 [security update]")
	t.CreateFileLines("licenses/gnu-gpl-v2",
		"The licenses for most software are designed to take away ...")

	t.CreateFileLines("category/pkg1/Makefile",
		MkRcsID,
		"",
		"PKGNAME=                package1-1.0",
		"GENERATE_PLIST+=        echo \"bin/program\";",
		"NO_CHECKSUM=            yes",
		"LICENSE=                gnu-gpl-v2")
	t.CreateFileLines("category/pkg2/Makefile",
		MkRcsID,
		"",
		"PKGNAME=                package2-1.0",
		"GENERATE_PLIST+=        echo \"bin/program\";",
		"NO_CHECKSUM=            yes",
		"LICENSE=                gnu-gpl-v2")
	t.CreateFileLines("category/pkg3/Makefile",
		MkRcsID,
		"",
		"PKGNAME=                package3-5.0",
		"GENERATE_PLIST+=        echo \"bin/program\";",
		"NO_CHECKSUM=            yes",
		"LICENSE=                gnu-gpl-v2")

	t.Chdir(".")
	G.Main("pkglint", "-Wall,no-space,no-order", "category/pkg1", "category/pkg2", "category/pkg3")

	t.CheckOutputLines(
		"WARN: category/pkg1/../../doc/TODO:3: Invalid line format \"\".",
		"WARN: category/pkg1/../../doc/TODO:4: Invalid line format \"\\tO wrong bullet\".",
		"WARN: category/pkg1/../../doc/TODO:5: Invalid package name \"package-without-version\".",
		"WARN: category/pkg1/Makefile: No COMMENT given.",
		"NOTE: category/pkg1/Makefile:3: The update request to 1.0 from doc/TODO has been done.",
		"WARN: category/pkg1/Makefile:4: Please use \"${ECHO}\" instead of \"echo\".",
		"WARN: category/pkg2/Makefile: No COMMENT given.",
		"WARN: category/pkg2/Makefile:3: This package should be updated to 2.0 ([nice new features]).",
		"WARN: category/pkg2/Makefile:4: Please use \"${ECHO}\" instead of \"echo\".",
		"WARN: category/pkg3/Makefile: No COMMENT given.",
		"NOTE: category/pkg3/Makefile:3: This package is newer than the update request to 3.0 ([security update]).",
		"WARN: category/pkg3/Makefile:4: Please use \"${ECHO}\" instead of \"echo\".",
		"0 errors and 10 warnings found.",
		"(Run \"pkglint -e\" to show explanations.)")
}

func (s *Suite) Test_NewPackage(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()
	t.CreateFileLines("category/Makefile",
		MkRcsID)

	c.Check(
		func() { NewPackage("category") },
		check.PanicMatches,
		`Package directory "category" must be two subdirectories below the pkgsrc root ".*".`)
}

// Before 2018-09-09, the .CURDIR variable did not have a fallback value.
// When resolving the relative path x11/gst-x11/${.CURDIR}/../../multimedia/gst-base/distinfo,
// "gst-x11/${.CURDIR}" was interpreted as "category/package", and the whole
// path was resolved to "x11/multimedia/gst-base/distinfo, which of course
// could not be found.
func (s *Suite) Test__distinfo_from_other_package(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall,no-space")
	t.SetupPkgsrc()
	t.Chdir(".")
	t.CreateFileLines("x11/gst-x11/Makefile",
		MkRcsID,
		".include \"../../multimedia/gst-base/Makefile.common\"",
		".include \"../../mk/bsd.pkg.mk\"")
	t.CreateFileLines("multimedia/gst-base/Makefile.common",
		MkRcsID,
		".include \"plugins.mk\"")
	t.CreateFileLines("multimedia/gst-base/plugins.mk",
		MkRcsID,
		"DISTINFO_FILE=\t${.CURDIR}/../../multimedia/gst-base/distinfo")
	t.CreateFileLines("multimedia/gst-base/distinfo",
		RcsID,
		"",
		"SHA1 (patch-aa) = 1234")

	G.CheckDirent("x11/gst-x11")

	t.CheckOutputLines(
		"WARN: x11/gst-x11/Makefile: Neither PLIST nor PLIST.common exist, and PLIST_SRC is unset.",
		"ERROR: x11/gst-x11/Makefile: Each package must define its LICENSE.",
		"WARN: x11/gst-x11/Makefile: No COMMENT given.",
		"WARN: x11/gst-x11/../../multimedia/gst-base/distinfo:3: Patch file \"patch-aa\" does not exist in directory \"../../x11/gst-x11/patches\".")
}

func (s *Suite) Test_Package_checkfilePackageMakefile__GNU_CONFIGURE(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall,no-space")
	pkg := t.SetupPackage("category/package",
		"GNU_CONFIGURE=\tyes",
		"USE_LANGUAGES=\t#")

	G.CheckDirent(pkg)

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:20: GNU_CONFIGURE almost always needs a C compiler, but \"c\" is not added to USE_LANGUAGES in line 21.")
}

func (s *Suite) Test_Package_checkfilePackageMakefile__GNU_CONFIGURE_ok(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall,no-space")
	pkg := t.SetupPackage("category/package",
		"GNU_CONFIGURE=\tyes",
		"USE_LANGUAGES=\t# none, really")

	G.CheckDirent(pkg)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_checkfilePackageMakefile__REPLACE_PERL(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall,no-space")
	pkg := t.SetupPackage("category/package",
		"REPLACE_PERL=\t*.pl",
		"NO_CONFIGURE=\tyes")

	G.CheckDirent(pkg)

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:20: REPLACE_PERL is ignored when NO_CONFIGURE is set (in line 21).")
}

func (s *Suite) Test_Package_checkfilePackageMakefile__META_PACKAGE_with_distinfo(c *check.C) {
	t := s.Init(c)

	pkg := t.SetupPackage("category/package",
		"META_PACKAGE=\tyes")

	G.CheckDirent(pkg)

	t.CheckOutputLines(
		"WARN: ~/category/package/distinfo: " +
			"This file should not exist if NO_CHECKSUM or META_PACKAGE is set.")
}

func (s *Suite) Test_Package_checkfilePackageMakefile__USE_IMAKE_and_USE_X11(c *check.C) {
	t := s.Init(c)

	pkg := t.SetupPackage("category/package",
		"USE_X11=\tyes",
		"USE_IMAKE=\tyes")

	G.CheckDirent(pkg)

	t.CheckOutputLines(
		"NOTE: ~/category/package/Makefile:21: USE_IMAKE makes USE_X11 in line 20 superfluous.")
}

func (s *Suite) Test_Package_readMakefile__skipping(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall,no-space")
	pkg := t.SetupPackage("category/package",
		".include \"${MYSQL_PKGSRCDIR:S/-client$/-server/}/buildlink3.mk\"")

	G.CheckDirent(pkg)

	t.CheckOutputLines(
		"NOTE: ~/category/package/Makefile:20: " +
			"Skipping include file \"${MYSQL_PKGSRCDIR:S/-client$/-server/}/buildlink3.mk\". " +
			"This may result in false warnings.")
}

func (s *Suite) Test_Package_readMakefile__not_found(c *check.C) {
	t := s.Init(c)

	pkg := t.SetupPackage("category/package",
		".include \"../../devel/zlib/buildlink3.mk\"")
	t.CreateFileLines("devel/zlib/buildlink3.mk",
		".include \"../../enoent/enoent/buildlink3.mk\"")

	G.checkdirPackage(pkg)

	t.CheckOutputLines(
		"ERROR: ~/devel/zlib/buildlink3.mk:1: Cannot read \"../../enoent/enoent/buildlink3.mk\".")
}

func (s *Suite) Test_Package_readMakefile__relative(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("category/package/extra.mk",
		MkRcsID)
	pkg := t.SetupPackage("category/package",
		".include \"../package/extra.mk\"")

	G.CheckDirent(pkg)

	// FIXME: One of the below warnings is redundant.
	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:20: References to other packages should look like \"../../category/package\", not \"../package\".",
		"WARN: ~/category/package/Makefile:20: Invalid relative path \"../package/extra.mk\".")
}

func (s *Suite) Test_Package_checkLocallyModified(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall,no-order")
	G.CurrentUsername = "example-user"
	t.CreateFileLines("category/package/CVS/Entries",
		"/Makefile//modified//")

	// Since MAINTAINER= pkgsrc-users@NetBSD.org, everyone may commit changes.

	pkg := t.SetupPackage("category/package")

	G.CheckDirent(pkg)

	t.CheckOutputEmpty()

	// A package with a MAINTAINER may be edited with care.

	t.CreateFileLines("category/package/Makefile",
		MkRcsID,
		"",
		"DISTNAME=\tdistname-1.0",
		"CATEGORIES=\tcategory",
		"MASTER_SITES=\t# none",
		"",
		"MAINTAINER=\tmaintainer@example.org", // Different from default value
		"HOMEPAGE=\t# none",
		"COMMENT=\tDummy package",
		"LICENSE=\t2-clause-bsd",
		"",
		".include \"../../mk/bsd.pkg.mk\"")

	G.CheckDirent(pkg)

	t.CheckOutputLines(
		"NOTE: ~/category/package/Makefile: " +
			"Please only commit changes that maintainer@example.org would approve.")

	// A package with an OWNER may NOT be edited by others.

	pkg = t.SetupPackage("category/package",
		"OWNER=\towner@example.org")

	G.CheckDirent(pkg)

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile: " +
			"Don't commit changes to this file without asking the OWNER, owner@example.org.")

	// ... unless you are the owner, of course.

	G.CurrentUsername = "owner"

	G.CheckDirent(pkg)

	t.CheckOutputEmpty()
}
