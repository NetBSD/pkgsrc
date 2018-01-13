package main

import "gopkg.in/check.v1"

func (s *Suite) Test_Package_pkgnameFromDistname(c *check.C) {
	s.Init(c)
	pkg := NewPackage("dummy")
	pkg.vardef["PKGNAME"] = T.NewMkLine("Makefile", 5, "PKGNAME=dummy")

	c.Check(pkg.pkgnameFromDistname("pkgname-1.0", "whatever"), equals, "pkgname-1.0")
	c.Check(pkg.pkgnameFromDistname("${DISTNAME}", "distname-1.0"), equals, "distname-1.0")
	c.Check(pkg.pkgnameFromDistname("${DISTNAME:S/dist/pkg/}", "distname-1.0"), equals, "pkgname-1.0")
	c.Check(pkg.pkgnameFromDistname("${DISTNAME:S|a|b|g}", "panama-0.13"), equals, "pbnbmb-0.13")
	c.Check(pkg.pkgnameFromDistname("${DISTNAME:S|^lib||}", "libncurses"), equals, "ncurses")
	c.Check(pkg.pkgnameFromDistname("${DISTNAME:S|^lib||}", "mylib"), equals, "mylib")
	c.Check(pkg.pkgnameFromDistname("${DISTNAME:tl:S/-/./g:S/he/-/1}", "SaxonHE9-5-0-1J"), equals, "saxon-9.5.0.1j")
	c.Check(pkg.pkgnameFromDistname("${DISTNAME:C/beta/.0./}", "fspanel-0.8beta1"), equals, "${DISTNAME:C/beta/.0./}")
	c.Check(pkg.pkgnameFromDistname("${DISTNAME:S/-0$/.0/1}", "aspell-af-0.50-0"), equals, "aspell-af-0.50.0")

	s.CheckOutputEmpty()
}

func (s *Suite) Test_Package_ChecklinesPackageMakefileVarorder(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Worder")
	pkg := NewPackage("x11/9term")

	pkg.ChecklinesPackageMakefileVarorder(T.NewMkLines("Makefile",
		mkrcsid,
		"",
		"DISTNAME=9term",
		"CATEGORIES=x11"))

	s.CheckOutputEmpty()

	pkg.ChecklinesPackageMakefileVarorder(T.NewMkLines("Makefile",
		mkrcsid,
		"",
		"DISTNAME=9term",
		"CATEGORIES=x11",
		"",
		".include \"../../mk/bsd.pkg.mk\""))

	s.CheckOutputLines(
		"WARN: Makefile:6: The canonical position for the required variable COMMENT is here.",
		"WARN: Makefile:6: The canonical position for the required variable LICENSE is here.")
}

func (s *Suite) Test_Package_varorder_license(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Worder")

	s.CreateTmpFileLines("mk/bsd.pkg.mk", "# dummy")
	s.CreateTmpFileLines("x11/Makefile", mkrcsid)
	s.CreateTmpFileLines("x11/9term/PLIST", "@comment $"+"NetBSD$", "bin/9term")
	s.CreateTmpFileLines("x11/9term/distinfo", "$"+"NetBSD$")
	s.CreateTmpFileLines("x11/9term/Makefile",
		mkrcsid,
		"",
		"DISTNAME=9term-1.0",
		"CATEGORIES=x11",
		"",
		"COMMENT=Terminal",
		"",
		".include \"../../mk/bsd.pkg.mk\"")

	G.globalData.InitVartypes()
	G.globalData.Pkgsrcdir = s.TmpDir()
	G.CurrentDir = s.TmpDir()

	(&Pkglint{}).CheckDirent(s.TmpDir() + "/x11/9term")

	// Since the error is grave enough, the warning about the correct position is suppressed.
	s.CheckOutputLines(
		"ERROR: ~/x11/9term/Makefile: Each package must define its LICENSE.")
}

// https://mail-index.netbsd.org/tech-pkg/2017/01/18/msg017698.html
func (s *Suite) Test_Package_ChecklinesPackageMakefileVarorder__MASTER_SITES(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Worder")
	pkg := NewPackage("category/package")

	pkg.ChecklinesPackageMakefileVarorder(T.NewMkLines("Makefile",
		mkrcsid,
		"",
		"PKGNAME=\tpackage-1.0",
		"CATEGORIES=\tcategory",
		"MASTER_SITES=\thttp://example.org/",
		"MASTER_SITES+=\thttp://mirror.example.org/"))

	s.CheckOutputEmpty() // No warning that "MASTER_SITES appears too late"
}

func (s *Suite) Test_Package_getNbpart(c *check.C) {
	pkg := NewPackage("category/pkgbase")
	pkg.vardef["PKGREVISION"] = T.NewMkLine("Makefile", 1, "PKGREVISION=14")

	c.Check(pkg.getNbpart(), equals, "nb14")

	pkg.vardef["PKGREVISION"] = T.NewMkLine("Makefile", 1, "PKGREVISION=asdf")

	c.Check(pkg.getNbpart(), equals, "")
}

func (s *Suite) Test_Package_determineEffectivePkgVars__precedence(c *check.C) {
	pkg := NewPackage("category/pkgbase")
	pkgnameLine := T.NewMkLine("Makefile", 3, "PKGNAME=pkgname-1.0")
	distnameLine := T.NewMkLine("Makefile", 4, "DISTNAME=distname-1.0")
	pkgrevisionLine := T.NewMkLine("Makefile", 5, "PKGREVISION=13")

	pkg.defineVar(pkgnameLine, pkgnameLine.Varname())
	pkg.defineVar(distnameLine, distnameLine.Varname())
	pkg.defineVar(pkgrevisionLine, pkgrevisionLine.Varname())

	pkg.determineEffectivePkgVars()

	c.Check(pkg.EffectivePkgbase, equals, "pkgname")
	c.Check(pkg.EffectivePkgname, equals, "pkgname-1.0nb13")
	c.Check(pkg.EffectivePkgversion, equals, "1.0")
}

func (s *Suite) Test_Package_checkPossibleDowngrade(c *check.C) {
	s.Init(c)
	G.Pkg = NewPackage("category/pkgbase")
	G.CurPkgsrcdir = "../.."
	G.Pkg.EffectivePkgname = "package-1.0nb15"
	G.Pkg.EffectivePkgnameLine = T.NewMkLine("category/pkgbase/Makefile", 5, "PKGNAME=dummy")
	G.globalData.LastChange = map[string]*Change{
		"category/pkgbase": {
			Action:  "Updated",
			Version: "1.8",
			Line:    T.NewLine("doc/CHANGES", 116, "dummy"),
		},
	}

	G.Pkg.checkPossibleDowngrade()

	s.CheckOutputLines(
		"WARN: category/pkgbase/Makefile:5: The package is being downgraded from 1.8 (see ../../doc/CHANGES:116) to 1.0nb15")

	G.globalData.LastChange["category/pkgbase"].Version = "1.0nb22"

	G.Pkg.checkPossibleDowngrade()

	s.CheckOutputEmpty()
}

func (s *Suite) Test_checkdirPackage(c *check.C) {
	s.Init(c)
	s.CreateTmpFile("Makefile", ""+
		"# $"+"NetBSD$\n")
	G.CurrentDir = s.tmpdir

	checkdirPackage(s.tmpdir)

	s.CheckOutputLines(
		"WARN: ~/Makefile: Neither PLIST nor PLIST.common exist, and PLIST_SRC is unset. Are you sure PLIST handling is ok?",
		"WARN: ~/distinfo: File not found. Please run \"@BMAKE@ makesum\".",
		"ERROR: ~/Makefile: Each package must define its LICENSE.",
		"WARN: ~/Makefile: No COMMENT given.")
}

func (s *Suite) Test_checkdirPackage__meta_package_without_license(c *check.C) {
	s.Init(c)
	s.CreateTmpFileLines("Makefile",
		mkrcsid,
		"",
		"META_PACKAGE=\tyes")
	G.CurrentDir = s.TmpDir()
	G.globalData.InitVartypes()

	checkdirPackage(s.TmpDir())

	s.CheckOutputLines(
		"WARN: ~/Makefile: No COMMENT given.") // No error about missing LICENSE.
}

func (s *Suite) Test_Package__varuse_at_load_time(c *check.C) {
	s.Init(c)
	s.CreateTmpFileLines("doc/CHANGES-2016",
		"# dummy")
	s.CreateTmpFileLines("doc/TODO",
		"# dummy")
	s.CreateTmpFileLines("licenses/bsd-2",
		"# dummy")
	s.CreateTmpFileLines("mk/fetch/sites.mk",
		"# dummy")
	s.CreateTmpFileLines("mk/bsd.pkg.mk",
		"# dummy")
	s.CreateTmpFileLines("mk/defaults/options.description",
		"option Description")
	s.CreateTmpFileLines("mk/defaults/mk.conf",
		"# dummy")
	s.CreateTmpFileLines("mk/tools/bsd.tools.mk",
		".include \"defaults.mk\"")
	s.CreateTmpFileLines("mk/tools/defaults.mk",
		"TOOLS_CREATE+=false",
		"TOOLS_CREATE+=nice",
		"TOOLS_CREATE+=true",
		"_TOOLS_VARNAME.nice=NICE")
	s.CreateTmpFileLines("mk/bsd.prefs.mk",
		"# dummy")

	s.CreateTmpFileLines("category/pkgbase/Makefile",
		mkrcsid,
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
	s.CreateTmpFileLines("category/pkgbase/distinfo",
		"$"+"NetBSD$")

	(&Pkglint{}).Main("pkglint", "-q", "-Wperm", s.tmpdir+"/category/pkgbase")

	s.CheckOutputLines(
		"WARN: ~/category/pkgbase/Makefile:8: To use the tool \"FALSE\" at load time, bsd.prefs.mk has to be included before.",
		"WARN: ~/category/pkgbase/Makefile:9: To use the tool \"NICE\" at load time, bsd.prefs.mk has to be included before.",
		"WARN: ~/category/pkgbase/Makefile:10: To use the tool \"TRUE\" at load time, bsd.prefs.mk has to be included before.",
		"WARN: ~/category/pkgbase/Makefile:16: To use the tool \"NICE\" at load time, it has to be added to USE_TOOLS before including bsd.prefs.mk.")
}

func (s *Suite) Test_Package_loadPackageMakefile(c *check.C) {
	s.Init(c)
	makefile := s.CreateTmpFile("category/package/Makefile", ""+
		"# $"+"NetBSD$\n"+
		"\n"+
		"PKGNAME=pkgname-1.67\n"+
		"DISTNAME=distfile_1_67\n"+
		".include \"../../category/package/Makefile\"\n")
	pkg := NewPackage("category/package")
	G.CurrentDir = s.tmpdir + "/category/package"
	G.CurPkgsrcdir = "../.."
	G.Pkg = pkg

	pkg.loadPackageMakefile(makefile)

	s.CheckOutputEmpty()
}

func (s *Suite) Test_Package_conditionalAndUnconditionalInclude(c *check.C) {
	s.Init(c)
	G.globalData.InitVartypes()
	s.CreateTmpFileLines("category/package/Makefile",
		mkrcsid,
		"",
		"COMMENT\t=Description",
		"LICENSE\t= gnu-gpl-v2",
		".include \"../../devel/zlib/buildlink3.mk\"",
		".if ${OPSYS} == \"Linux\"",
		".include \"../../sysutils/coreutils/buildlink3.mk\"",
		".endif",
		".include \"../../mk/bsd.pkg.mk\"")
	s.CreateTmpFileLines("category/package/options.mk",
		mkrcsid,
		"",
		".if !empty(PKG_OPTIONS:Mzlib)",
		".  include \"../../devel/zlib/buildlink3.mk\"",
		".endif",
		".include \"../../sysutils/coreutils/buildlink3.mk\"")
	s.CreateTmpFileLines("category/package/PLIST",
		"@comment $"+"NetBSD$",
		"bin/program")
	s.CreateTmpFileLines("category/package/distinfo",
		"$"+"NetBSD$")

	s.CreateTmpFileLines("devel/zlib/buildlink3.mk", "")
	s.CreateTmpFileLines("licenses/gnu-gpl-v2", "")
	s.CreateTmpFileLines("mk/bsd.pkg.mk", "")
	s.CreateTmpFileLines("sysutils/coreutils/buildlink3.mk", "")

	pkg := NewPackage("category/package")
	G.globalData.Pkgsrcdir = s.tmpdir
	G.CurrentDir = s.tmpdir + "/category/package"
	G.CurPkgsrcdir = "../.."
	G.Pkg = pkg

	checkdirPackage("category/package")

	s.CheckOutputLines(
		"WARN: ~/category/package/options.mk:3: Unknown option \"zlib\".",
		"WARN: ~/category/package/options.mk:4: \"../../devel/zlib/buildlink3.mk\" is included conditionally here (depending on PKG_OPTIONS) and unconditionally in Makefile:5.",
		"WARN: ~/category/package/options.mk:6: \"../../sysutils/coreutils/buildlink3.mk\" is included unconditionally here and conditionally in Makefile:7 (depending on OPSYS).")
}
