package main

import "gopkg.in/check.v1"

func (s *Suite) Test_Package_pkgnameFromDistname(c *check.C) {
	t := s.Init(c)

	pkg := NewPackage("dummy")
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

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_CheckVarorder(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Worder")
	pkg := NewPackage("x11/9term")

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
	pkg := NewPackage("x11/9term")

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

	pkg := NewPackage("x11/9term")

	pkg.CheckVarorder(t.NewMkLines("Makefile",
		MkRcsID,
		"",
		"DISTNAME=\tdistname-1.0",
		"CATEGORIES=\tsysutils",
		"",
		"MAINTAINER=\tpkgsrc-users@pkgsrc.org",
		"# comment",
		"COMMENT=\tComment",
		"LICENSE=\tgnu-gpl-v2"))

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_CheckVarorder__conditionals_skip(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Worder")

	pkg := NewPackage("x11/9term")

	pkg.CheckVarorder(t.NewMkLines("Makefile",
		MkRcsID,
		"",
		"DISTNAME=\tdistname-1.0",
		"CATEGORIES=\tsysutils",
		"",
		".if ${DISTNAME:Mdistname-*}",
		"MAINTAINER=\tpkgsrc-users@pkgsrc.org",
		".endif",
		"LICENSE=\tgnu-gpl-v2"))

	// No warning about the missing COMMENT since the conditional
	// skips the whole check.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_CheckVarorder_GitHub(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Worder")
	pkg := NewPackage("x11/9term")

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

func (s *Suite) Test_Package_varorder_license(c *check.C) {
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
	G.CurrentDir = t.TmpDir()

	G.CheckDirent(t.TmpDir() + "/x11/9term")

	// Since the error is grave enough, the warning about the correct position is suppressed.
	t.CheckOutputLines(
		"ERROR: ~/x11/9term/Makefile: Each package must define its LICENSE.")
}

// https://mail-index.netbsd.org/tech-pkg/2017/01/18/msg017698.html
func (s *Suite) Test_Package_CheckVarorder__MASTER_SITES(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Worder")
	pkg := NewPackage("category/package")

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
	pkg := NewPackage("category/package")

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

	pkg := NewPackage("category/pkgbase")
	pkg.vars.Define("PKGREVISION", t.NewMkLine("Makefile", 1, "PKGREVISION=14"))

	c.Check(pkg.getNbpart(), equals, "nb14")

	pkg.vars = NewScope()
	pkg.vars.Define("PKGREVISION", t.NewMkLine("Makefile", 1, "PKGREVISION=asdf"))

	c.Check(pkg.getNbpart(), equals, "")
}

func (s *Suite) Test_Package_determineEffectivePkgVars__precedence(c *check.C) {
	t := s.Init(c)

	pkg := NewPackage("category/pkgbase")
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

func (s *Suite) Test_Package_checkPossibleDowngrade(c *check.C) {
	t := s.Init(c)

	G.Pkg = NewPackage("category/pkgbase")
	G.CurPkgsrcdir = "../.."
	G.Pkg.EffectivePkgname = "package-1.0nb15"
	G.Pkg.EffectivePkgnameLine = t.NewMkLine("category/pkgbase/Makefile", 5, "PKGNAME=dummy")
	G.Pkgsrc.LastChange = map[string]*Change{
		"category/pkgbase": {
			Action:  "Updated",
			Version: "1.8",
			Line:    t.NewLine("doc/CHANGES", 116, "dummy"),
		},
	}

	G.Pkg.checkPossibleDowngrade()

	t.CheckOutputLines(
		"WARN: category/pkgbase/Makefile:5: The package is being downgraded from 1.8 (see ../../doc/CHANGES:116) to 1.0nb15.")

	G.Pkgsrc.LastChange["category/pkgbase"].Version = "1.0nb22"

	G.Pkg.checkPossibleDowngrade()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_checkdirPackage(c *check.C) {
	t := s.Init(c)

	t.SetupFileLines("Makefile",
		MkRcsID)
	G.CurrentDir = t.TmpDir()

	G.checkdirPackage(t.TmpDir())

	t.CheckOutputLines(
		"WARN: ~/Makefile: Neither PLIST nor PLIST.common exist, and PLIST_SRC is unset.",
		"WARN: ~/distinfo: File not found. Please run \""+confMake+" makesum\" or define NO_CHECKSUM=yes in the package Makefile.",
		"ERROR: ~/Makefile: Each package must define its LICENSE.",
		"WARN: ~/Makefile: No COMMENT given.")
}

func (s *Suite) Test_checkdirPackage__meta_package_without_license(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("Makefile",
		MkRcsID,
		"",
		"META_PACKAGE=\tyes")
	G.CurrentDir = t.TmpDir()
	t.SetupVartypes()

	G.checkdirPackage(t.TmpDir())

	t.CheckOutputLines(
		"WARN: ~/Makefile: No COMMENT given.") // No error about missing LICENSE.
}

func (s *Suite) Test_Package__varuse_at_load_time(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("doc/CHANGES-2016",
		"# dummy")
	t.CreateFileLines("doc/TODO",
		"# dummy")
	t.CreateFileLines("licenses/bsd-2",
		"# dummy")
	t.CreateFileLines("mk/fetch/sites.mk",
		"# dummy")
	t.CreateFileLines("mk/bsd.pkg.mk",
		"# dummy")
	t.CreateFileLines("mk/defaults/options.description",
		"option Description")
	t.CreateFileLines("mk/defaults/mk.conf",
		"# dummy")
	t.CreateFileLines("mk/tools/bsd.tools.mk",
		".include \"defaults.mk\"")
	t.CreateFileLines("mk/tools/defaults.mk",
		"TOOLS_CREATE+=false",
		"TOOLS_CREATE+=nice",
		"TOOLS_CREATE+=true",
		"_TOOLS_VARNAME.nice=NICE")
	t.CreateFileLines("mk/bsd.prefs.mk",
		"# dummy")

	t.CreateFileLines("category/pkgbase/Makefile",
		MkRcsID,
		"",
		"COMMENT= Unit test",
		"LICENSE= bsd-2",
		"PLIST_SRC=#none",
		"",
		"USE_TOOLS+= echo false",
		"FALSE_BEFORE!= echo false=${FALSE}",
		"NICE_BEFORE!= echo nice=${NICE}",
		"TRUE_BEFORE!= echo true=${TRUE}",
		"",
		".include \"../../mk/bsd.prefs.mk\"",
		"",
		"USE_TOOLS+= nice",
		"FALSE_AFTER!= echo false=${FALSE}",
		"NICE_AFTER!= echo nice=${NICE}",
		"TRUE_AFTER!= echo true=${TRUE}",
		"",
		"do-build:",
		"\t${ECHO} before: ${FALSE_BEFORE} ${NICE_BEFORE} ${TRUE_BEFORE}",
		"\t${ECHO} after: ${FALSE_AFTER} ${NICE_AFTER} ${TRUE_AFTER}",
		"\t${ECHO}; ${FALSE}; ${NICE}; ${TRUE}",
		"",
		".include \"../../mk/bsd.pkg.mk\"")
	t.CreateFileLines("category/pkgbase/distinfo",
		RcsID)

	G.Main("pkglint", "-q", "-Wperm", t.TmpDir()+"/category/pkgbase")

	t.CheckOutputLines(
		"WARN: ~/category/pkgbase/Makefile:8: To use the tool \"FALSE\" at load time, bsd.prefs.mk has to be included before.",
		"WARN: ~/category/pkgbase/Makefile:9: To use the tool \"NICE\" at load time, bsd.prefs.mk has to be included before.",
		"WARN: ~/category/pkgbase/Makefile:10: To use the tool \"TRUE\" at load time, bsd.prefs.mk has to be included before.",
		"WARN: ~/category/pkgbase/Makefile:16: To use the tool \"NICE\" at load time, it has to be added to USE_TOOLS before including bsd.prefs.mk.",
		"WARN: ~/category/pkgbase/Makefile:3: The canonical order of the variables is CATEGORIES, empty line, COMMENT, LICENSE.")
}

func (s *Suite) Test_Package_loadPackageMakefile(c *check.C) {
	t := s.Init(c)

	t.SetupFileLines("category/package/Makefile",
		MkRcsID,
		"",
		"PKGNAME=pkgname-1.67",
		"DISTNAME=distfile_1_67",
		".include \"../../category/package/Makefile\"")
	pkg := NewPackage("category/package")
	G.CurrentDir = t.TempFilename("category/package")
	G.CurPkgsrcdir = "../.."
	G.Pkg = pkg

	pkg.loadPackageMakefile(t.TempFilename("category/package/Makefile"))

	// Including a package Makefile directly is an error (in the last line),
	// but that is checked later.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_conditionalAndUnconditionalInclude(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	t.CreateFileLines("category/package/Makefile",
		MkRcsID,
		"",
		"COMMENT\t=Description",
		"LICENSE\t= gnu-gpl-v2",
		".include \"../../devel/zlib/buildlink3.mk\"",
		".if ${OPSYS} == \"Linux\"",
		".include \"../../sysutils/coreutils/buildlink3.mk\"",
		".endif",
		".include \"../../mk/bsd.pkg.mk\"")
	t.CreateFileLines("category/package/options.mk",
		MkRcsID,
		"",
		".if !empty(PKG_OPTIONS:Mzlib)",
		".  include \"../../devel/zlib/buildlink3.mk\"",
		".endif",
		".include \"../../sysutils/coreutils/buildlink3.mk\"")
	t.CreateFileLines("category/package/PLIST",
		PlistRcsID,
		"bin/program")
	t.CreateFileLines("category/package/distinfo",
		RcsID)

	t.CreateFileLines("devel/zlib/buildlink3.mk", "")
	t.CreateFileLines("licenses/gnu-gpl-v2", "")
	t.CreateFileLines("mk/bsd.pkg.mk", "")
	t.CreateFileLines("sysutils/coreutils/buildlink3.mk", "")

	pkg := NewPackage("category/package")
	G.CurrentDir = t.TmpDir() + "/category/package"
	G.CurPkgsrcdir = "../.."
	G.Pkg = pkg

	G.checkdirPackage("category/package")

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:3: The canonical order of the variables is CATEGORIES, empty line, COMMENT, LICENSE.",
		"WARN: ~/category/package/options.mk:3: Unknown option \"zlib\".",
		"WARN: ~/category/package/options.mk:4: \"../../devel/zlib/buildlink3.mk\" is "+
			"included conditionally here (depending on PKG_OPTIONS) and unconditionally in Makefile:5.",
		"WARN: ~/category/package/options.mk:6: \"../../sysutils/coreutils/buildlink3.mk\" is "+
			"included unconditionally here and conditionally in Makefile:7 (depending on OPSYS).")
}

// See https://github.com/rillig/pkglint/issues/1
func (s *Suite) Test_Package_includeWithoutExists(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	t.CreateFileLines("mk/bsd.pkg.mk")
	t.CreateFileLines("category/package/Makefile",
		MkRcsID,
		"",
		".include \"options.mk\"",
		"",
		".include \"../../mk/bsd.pkg.mk\"")

	G.CurrentDir = t.TempFilename("category/package")
	G.checkdirPackage(G.CurrentDir)

	t.CheckOutputLines(
		"ERROR: ~/category/package/options.mk: Cannot be read.")
}

// See https://github.com/rillig/pkglint/issues/1
func (s *Suite) Test_Package_includeAfterExists(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	t.CreateFileLines("mk/bsd.pkg.mk")
	t.CreateFileLines("category/package/Makefile",
		MkRcsID,
		"",
		".if exists(options.mk)",
		".  include \"options.mk\"",
		".endif",
		"",
		".include \"../../mk/bsd.pkg.mk\"")

	G.CurrentDir = t.TempFilename("category/package")
	G.checkdirPackage(G.CurrentDir)

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile: Neither PLIST nor PLIST.common exist, and PLIST_SRC is unset.",
		"WARN: ~/category/package/distinfo: File not found. Please run \"@BMAKE@ makesum\" or define NO_CHECKSUM=yes in the package Makefile.",
		"ERROR: ~/category/package/Makefile: Each package must define its LICENSE.",
		"WARN: ~/category/package/Makefile: No COMMENT given.",
		"ERROR: ~/category/package/Makefile:4: \"options.mk\" does not exist.",
		"ERROR: ~/category/package/Makefile:7: \"/mk/bsd.pkg.mk\" does not exist.")
}

// See https://github.com/rillig/pkglint/issues/1
func (s *Suite) Test_Package_includeOtherAfterExists(c *check.C) {
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

	G.CurrentDir = t.TempFilename("category/package")
	G.checkdirPackage(G.CurrentDir)

	t.CheckOutputLines(
		"ERROR: ~/category/package/another.mk: Cannot be read.")
}
