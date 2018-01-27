package main

import "gopkg.in/check.v1"

func (s *Suite) Test_Package_pkgnameFromDistname(c *check.C) {
	t := s.Init(c)

	pkg := NewPackage("dummy")
	pkg.vardef["PKGNAME"] = t.NewMkLine("Makefile", 5, "PKGNAME=dummy")

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

func (s *Suite) Test_Package_ChecklinesPackageMakefileVarorder(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Worder")
	pkg := NewPackage("x11/9term")

	pkg.ChecklinesPackageMakefileVarorder(t.NewMkLines("Makefile",
		MkRcsId,
		"",
		"DISTNAME=9term",
		"CATEGORIES=x11"))

	t.CheckOutputEmpty()

	pkg.ChecklinesPackageMakefileVarorder(t.NewMkLines("Makefile",
		MkRcsId,
		"",
		"DISTNAME=9term",
		"CATEGORIES=x11",
		"",
		".include \"../../mk/bsd.pkg.mk\""))

	t.CheckOutputLines(
		"WARN: Makefile:6: The canonical position for the required variable COMMENT is here.",
		"WARN: Makefile:6: The canonical position for the required variable LICENSE is here.")
}

func (s *Suite) Test_Package_varorder_license(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Worder")

	t.CreateFileLines("mk/bsd.pkg.mk", "# dummy")
	t.CreateFileLines("x11/Makefile", MkRcsId)
	t.CreateFileLines("x11/9term/PLIST", PlistRcsId, "bin/9term")
	t.CreateFileLines("x11/9term/distinfo", RcsId)
	t.CreateFileLines("x11/9term/Makefile",
		MkRcsId,
		"",
		"DISTNAME=9term-1.0",
		"CATEGORIES=x11",
		"",
		"COMMENT=Terminal",
		"",
		".include \"../../mk/bsd.pkg.mk\"")

	G.globalData.InitVartypes()
	G.globalData.Pkgsrcdir = t.TmpDir()
	G.CurrentDir = t.TmpDir()

	(&Pkglint{}).CheckDirent(t.TmpDir() + "/x11/9term")

	// Since the error is grave enough, the warning about the correct position is suppressed.
	t.CheckOutputLines(
		"ERROR: ~/x11/9term/Makefile: Each package must define its LICENSE.")
}

// https://mail-index.netbsd.org/tech-pkg/2017/01/18/msg017698.html
func (s *Suite) Test_Package_ChecklinesPackageMakefileVarorder__MASTER_SITES(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Worder")
	pkg := NewPackage("category/package")

	pkg.ChecklinesPackageMakefileVarorder(t.NewMkLines("Makefile",
		MkRcsId,
		"",
		"PKGNAME=\tpackage-1.0",
		"CATEGORIES=\tcategory",
		"MASTER_SITES=\thttp://example.org/",
		"MASTER_SITES+=\thttp://mirror.example.org/"))

	// No warning that "MASTER_SITES appears too late"
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_getNbpart(c *check.C) {
	t := s.Init(c)

	pkg := NewPackage("category/pkgbase")
	pkg.vardef["PKGREVISION"] = t.NewMkLine("Makefile", 1, "PKGREVISION=14")

	c.Check(pkg.getNbpart(), equals, "nb14")

	pkg.vardef["PKGREVISION"] = t.NewMkLine("Makefile", 1, "PKGREVISION=asdf")

	c.Check(pkg.getNbpart(), equals, "")
}

func (s *Suite) Test_Package_determineEffectivePkgVars__precedence(c *check.C) {
	t := s.Init(c)

	pkg := NewPackage("category/pkgbase")
	pkgnameLine := t.NewMkLine("Makefile", 3, "PKGNAME=pkgname-1.0")
	distnameLine := t.NewMkLine("Makefile", 4, "DISTNAME=distname-1.0")
	pkgrevisionLine := t.NewMkLine("Makefile", 5, "PKGREVISION=13")

	pkg.defineVar(pkgnameLine, pkgnameLine.Varname())
	pkg.defineVar(distnameLine, distnameLine.Varname())
	pkg.defineVar(pkgrevisionLine, pkgrevisionLine.Varname())

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
	G.globalData.LastChange = map[string]*Change{
		"category/pkgbase": {
			Action:  "Updated",
			Version: "1.8",
			Line:    t.NewLine("doc/CHANGES", 116, "dummy"),
		},
	}

	G.Pkg.checkPossibleDowngrade()

	t.CheckOutputLines(
		"WARN: category/pkgbase/Makefile:5: The package is being downgraded from 1.8 (see ../../doc/CHANGES:116) to 1.0nb15")

	G.globalData.LastChange["category/pkgbase"].Version = "1.0nb22"

	G.Pkg.checkPossibleDowngrade()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_checkdirPackage(c *check.C) {
	t := s.Init(c)

	t.SetupFileLines("Makefile",
		MkRcsId)
	G.CurrentDir = t.TmpDir()

	checkdirPackage(t.TmpDir())

	t.CheckOutputLines(
		"WARN: ~/Makefile: Neither PLIST nor PLIST.common exist, and PLIST_SRC is unset. Are you sure PLIST handling is ok?",
		"WARN: ~/distinfo: File not found. Please run \"@BMAKE@ makesum\".",
		"ERROR: ~/Makefile: Each package must define its LICENSE.",
		"WARN: ~/Makefile: No COMMENT given.")
}

func (s *Suite) Test_checkdirPackage__meta_package_without_license(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("Makefile",
		MkRcsId,
		"",
		"META_PACKAGE=\tyes")
	G.CurrentDir = t.TmpDir()
	G.globalData.InitVartypes()

	checkdirPackage(t.TmpDir())

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
		MkRcsId,
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
		RcsId)

	(&Pkglint{}).Main("pkglint", "-q", "-Wperm", t.TmpDir()+"/category/pkgbase")

	t.CheckOutputLines(
		"WARN: ~/category/pkgbase/Makefile:8: To use the tool \"FALSE\" at load time, bsd.prefs.mk has to be included before.",
		"WARN: ~/category/pkgbase/Makefile:9: To use the tool \"NICE\" at load time, bsd.prefs.mk has to be included before.",
		"WARN: ~/category/pkgbase/Makefile:10: To use the tool \"TRUE\" at load time, bsd.prefs.mk has to be included before.",
		"WARN: ~/category/pkgbase/Makefile:16: To use the tool \"NICE\" at load time, it has to be added to USE_TOOLS before including bsd.prefs.mk.")
}

func (s *Suite) Test_Package_loadPackageMakefile(c *check.C) {
	t := s.Init(c)

	t.SetupFileLines("category/package/Makefile",
		MkRcsId,
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

	G.globalData.InitVartypes()
	t.CreateFileLines("category/package/Makefile",
		MkRcsId,
		"",
		"COMMENT\t=Description",
		"LICENSE\t= gnu-gpl-v2",
		".include \"../../devel/zlib/buildlink3.mk\"",
		".if ${OPSYS} == \"Linux\"",
		".include \"../../sysutils/coreutils/buildlink3.mk\"",
		".endif",
		".include \"../../mk/bsd.pkg.mk\"")
	t.CreateFileLines("category/package/options.mk",
		MkRcsId,
		"",
		".if !empty(PKG_OPTIONS:Mzlib)",
		".  include \"../../devel/zlib/buildlink3.mk\"",
		".endif",
		".include \"../../sysutils/coreutils/buildlink3.mk\"")
	t.CreateFileLines("category/package/PLIST",
		PlistRcsId,
		"bin/program")
	t.CreateFileLines("category/package/distinfo",
		RcsId)

	t.CreateFileLines("devel/zlib/buildlink3.mk", "")
	t.CreateFileLines("licenses/gnu-gpl-v2", "")
	t.CreateFileLines("mk/bsd.pkg.mk", "")
	t.CreateFileLines("sysutils/coreutils/buildlink3.mk", "")

	pkg := NewPackage("category/package")
	G.globalData.Pkgsrcdir = t.TmpDir()
	G.CurrentDir = t.TmpDir() + "/category/package"
	G.CurPkgsrcdir = "../.."
	G.Pkg = pkg

	checkdirPackage("category/package")

	t.CheckOutputLines(
		"WARN: ~/category/package/options.mk:3: Unknown option \"zlib\".",
		"WARN: ~/category/package/options.mk:4: \"../../devel/zlib/buildlink3.mk\" is "+
			"included conditionally here (depending on PKG_OPTIONS) and unconditionally in Makefile:5.",
		"WARN: ~/category/package/options.mk:6: \"../../sysutils/coreutils/buildlink3.mk\" is "+
			"included unconditionally here and conditionally in Makefile:7 (depending on OPSYS).")
}
