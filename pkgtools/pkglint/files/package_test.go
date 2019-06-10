package pkglint

import (
	"gopkg.in/check.v1"
	"strings"
)

func (s *Suite) Test_Package_checkLinesBuildlink3Inclusion__file_but_not_package(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("category/dependency/buildlink3.mk")
	G.Pkg = NewPackage(t.File("category/package"))
	mklines := t.NewMkLines("category/package/buildlink3.mk",
		MkRcsID,
		"",
		".include \"../../category/dependency/buildlink3.mk\"")

	G.Pkg.checkLinesBuildlink3Inclusion(mklines)

	t.CheckOutputLines(
		"WARN: category/package/buildlink3.mk:3: " +
			"../../category/dependency/buildlink3.mk is included by this file " +
			"but not by the package.")
}

func (s *Suite) Test_Package_checkLinesBuildlink3Inclusion__package_but_not_file(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("category/dependency/buildlink3.mk")
	G.Pkg = NewPackage(t.File("category/package"))
	G.Pkg.bl3["../../category/dependency/buildlink3.mk"] =
		t.NewMkLine("../../category/dependency/buildlink3.mk", 1, "")
	mklines := t.NewMkLines("category/package/buildlink3.mk",
		MkRcsID)

	t.EnableTracingToLog()
	G.Pkg.checkLinesBuildlink3Inclusion(mklines)

	// This is only traced but not logged as a regular warning since
	// several packages have build dependencies that are not needed
	// for building other packages. These cannot be flagged as warnings.
	t.CheckOutputLines(
		"TRACE: + (*Package).checkLinesBuildlink3Inclusion()",
		"TRACE: 1   ../../category/dependency/buildlink3.mk "+
			"is included by the package but not by the buildlink3.mk file.",
		"TRACE: - (*Package).checkLinesBuildlink3Inclusion()")
}

// Just for code coverage.
func (s *Suite) Test_Package_checkLinesBuildlink3Inclusion__no_tracing(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"PKGNAME=\tpackage-1.0")
	t.CreateFileDummyBuildlink3("category/package/buildlink3.mk")
	t.FinishSetUp()

	t.DisableTracing()
	G.Check(t.File("category/package"))

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_pkgnameFromDistname(c *check.C) {
	t := s.Init(c)

	var once Once
	test := func(pkgname, distname, expectedPkgname string, diagnostics ...string) {
		t.SetUpPackage("category/package",
			"PKGNAME=\t"+pkgname,
			"DISTNAME=\t"+distname)
		if once.FirstTime("called") {
			t.FinishSetUp()
		}

		pkg := NewPackage(t.File("category/package"))
		pkg.loadPackageMakefile()
		pkg.determineEffectivePkgVars()
		t.Check(pkg.EffectivePkgname, equals, expectedPkgname)
		t.CheckOutput(diagnostics)
	}

	test("pkgname-1.0", "whatever", "pkgname-1.0")

	test("${DISTNAME}", "distname-1.0", "distname-1.0",
		"NOTE: ~/category/package/Makefile:4: This assignment is probably redundant since PKGNAME is ${DISTNAME} by default.")

	test("${DISTNAME:S/dist/pkg/}", "distname-1.0", "pkgname-1.0")

	test("${DISTNAME:S|a|b|g}", "panama-0.13", "pbnbmb-0.13")

	// The substitution succeeds, but the substituted value is missing
	// the package version. Therefore it is discarded completely.
	test("${DISTNAME:S|^lib||}", "libncurses", "")

	// The substitution succeeds, but the substituted value is missing
	// the package version. Therefore it is discarded completely.
	test("${DISTNAME:S|^lib||}", "mylib", "")

	test("${DISTNAME:tl:S/-/./g:S/he/-/1}", "SaxonHE9-5-0-1J", "saxon-9.5.0.1j")

	test("${DISTNAME:C/beta/.0./}", "fspanel-0.8beta1", "fspanel-0.8.0.1")

	test("${DISTNAME:C/Gtk2/p5-gtk2/}", "Gtk2-1.0", "p5-gtk2-1.0")

	test("${DISTNAME:S/-0$/.0/1}", "aspell-af-0.50-0", "aspell-af-0.50.0")

	test("${DISTNAME:M*.tar.gz:C,\\..*,,}", "aspell-af-0.50-0", "")

	test("${DISTNAME:S,a,b,c,d}", "aspell-af-0.50-0", "bspell-af-0.50-0",
		"WARN: ~/category/package/Makefile:4: Invalid variable modifier \"c,d\" for \"DISTNAME\".")

	test("${DISTFILE:C,\\..*,,}", "aspell-af-0.50-0", "")
}

func (s *Suite) Test_Package_CheckVarorder__only_required_variables(c *check.C) {
	t := s.Init(c)

	pkg := NewPackage(t.File("x11/9term"))
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"",
		"DISTNAME=9term",
		"CATEGORIES=x11",
		"",
		".include \"../../mk/bsd.pkg.mk\"")

	pkg.CheckVarorder(mklines)

	t.CheckOutputLines(
		"WARN: Makefile:3: The canonical order of the variables is " +
			"DISTNAME, CATEGORIES, empty line, COMMENT, LICENSE.")
}

func (s *Suite) Test_Package_CheckVarorder__with_optional_variables(c *check.C) {
	t := s.Init(c)

	pkg := NewPackage(t.File("x11/9term"))
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"",
		"GITHUB_PROJECT=project",
		"DISTNAME=9term",
		"CATEGORIES=x11")

	pkg.CheckVarorder(mklines)

	// TODO: Make this warning more specific to the actual situation.
	t.CheckOutputLines(
		"WARN: Makefile:3: The canonical order of the variables is " +
			"GITHUB_PROJECT, DISTNAME, CATEGORIES, GITHUB_PROJECT, empty line, " +
			"COMMENT, LICENSE.")
}

// Just for code coverage.
func (s *Suite) Test_Package_CheckVarorder__no_tracing(c *check.C) {
	t := s.Init(c)

	pkg := NewPackage(t.File("x11/9term"))
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"",
		"DISTNAME=9term",
		"CATEGORIES=x11",
		"",
		".include \"../../mk/bsd.pkg.mk\"")
	t.DisableTracing()

	pkg.CheckVarorder(mklines)

	t.CheckOutputLines(
		"WARN: Makefile:3: The canonical order of the variables is " +
			"DISTNAME, CATEGORIES, empty line, COMMENT, LICENSE.")
}

// Ensure that comments and empty lines do not lead to panics.
// This would be when accessing fields from the MkLine without checking the line type before.
func (s *Suite) Test_Package_CheckVarorder__comments_do_not_crash(c *check.C) {
	t := s.Init(c)

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
			"GITHUB_PROJECT, DISTNAME, CATEGORIES, GITHUB_PROJECT, empty line, " +
			"COMMENT, LICENSE.")
}

func (s *Suite) Test_Package_CheckVarorder__comments_are_ignored(c *check.C) {
	t := s.Init(c)

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

	pkg := NewPackage(t.File("category/package"))
	mklines := t.NewMkLines("Makefile",
		MkRcsID,
		"",
		"DISTNAME=\tdistname-1.0",
		"CATEGORIES=\tsysutils",
		"",
		".if ${DISTNAME:Mdistname-*}",
		"MAINTAINER=\tpkgsrc-users@NetBSD.org",
		".endif",
		"LICENSE=\tgnu-gpl-v2")

	pkg.CheckVarorder(mklines)

	// No warning about the missing COMMENT since the .if directive
	// causes the whole check to be skipped.
	t.CheckOutputEmpty()

	// Just for code coverage.
	t.DisableTracing()
	pkg.CheckVarorder(mklines)
	t.CheckOutputEmpty()
}

// TODO: Add more tests like skip_if_there_are_directives for other line types.

func (s *Suite) Test_Package_CheckVarorder__GITHUB_PROJECT_at_the_top(c *check.C) {
	t := s.Init(c)

	pkg := NewPackage(t.File("x11/9term"))

	pkg.CheckVarorder(t.NewMkLines("Makefile",
		MkRcsID,
		"",
		"GITHUB_PROJECT=\t\tautocutsel",
		"DISTNAME=\t\tautocutsel-0.10.0",
		"CATEGORIES=\t\tx11",
		"MASTER_SITES=\t\t${MASTER_SITE_GITHUB:=sigmike/}",
		"GITHUB_TAG=\t\t${PKGVERSION_NOREV}",
		"",
		"COMMENT=\tComment",
		"LICENSE=\tgnu-gpl-v2"))

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_CheckVarorder__GITHUB_PROJECT_at_the_bottom(c *check.C) {
	t := s.Init(c)

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

	t.CreateFileLines("mk/bsd.pkg.mk", "# dummy")
	t.CreateFileLines("x11/Makefile", MkRcsID)
	t.CreateFileLines("x11/9term/PLIST", PlistRcsID, "bin/9term")
	t.CreateFileLines("x11/9term/Makefile",
		MkRcsID,
		"",
		"DISTNAME=\t9term-1.0",
		"CATEGORIES=\tx11",
		"",
		"COMMENT=\tTerminal",
		"",
		"NO_CHECKSUM=\tyes",
		"",
		".include \"../../mk/bsd.pkg.mk\"")

	t.SetUpVartypes()

	G.Check(t.File("x11/9term"))

	// Since the error is grave enough, the warning about the correct position is suppressed.
	// TODO: Knowing the correct position helps, though.
	t.CheckOutputLines(
		"ERROR: ~/x11/9term/Makefile: Each package must define its LICENSE.")
}

// https://mail-index.netbsd.org/tech-pkg/2017/01/18/msg017698.html
func (s *Suite) Test_Package_CheckVarorder__MASTER_SITES(c *check.C) {
	t := s.Init(c)

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

func (s *Suite) Test_Package_CheckVarorder__diagnostics(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
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
			"GITHUB_PROJECT, DISTNAME, PKGNAME, CATEGORIES, " +
			"MASTER_SITES, GITHUB_PROJECT, DIST_SUBDIR, empty line, " +
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

func (s *Suite) Test_Package_nbPart(c *check.C) {
	t := s.Init(c)

	pkg := NewPackage(t.File("category/pkgbase"))
	pkg.vars.Define("PKGREVISION", t.NewMkLine("Makefile", 1, "PKGREVISION=14"))

	c.Check(pkg.nbPart(), equals, "nb14")

	pkg.vars = NewScope()
	pkg.vars.Define("PKGREVISION", t.NewMkLine("Makefile", 1, "PKGREVISION=asdf"))

	c.Check(pkg.nbPart(), equals, "")
}

// PKGNAME is stronger than DISTNAME.
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

	pkg := t.SetUpPackage("category/package",
		"DISTNAME=\tdistname-1.0",
		"PKGNAME=\tdistname-1.0")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputLines(
		"NOTE: ~/category/package/Makefile:4: " +
			"This assignment is probably redundant since PKGNAME is ${DISTNAME} by default.")
}

func (s *Suite) Test_Package_determineEffectivePkgVars__simple_reference(c *check.C) {
	t := s.Init(c)

	pkg := t.SetUpPackage("category/package",
		"DISTNAME=\tdistname-1.0",
		"PKGNAME=\t${DISTNAME}")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputLines(
		"NOTE: ~/category/package/Makefile:4: " +
			"This assignment is probably redundant since PKGNAME is ${DISTNAME} by default.")
}

func (s *Suite) Test_Package_determineEffectivePkgVars__invalid_DISTNAME(c *check.C) {
	t := s.Init(c)

	pkg := t.SetUpPackage("category/package",
		"DISTNAME=\tpkgname-version")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:3: " +
			"As DISTNAME is not a valid package name, please define the PKGNAME explicitly.")
}

func (s *Suite) Test_Package_determineEffectivePkgVars__C_modifier(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("x11/p5-gtk2",
		"DISTNAME=\tGtk2-1.0",
		"PKGNAME=\t${DISTNAME:C:Gtk2:p5-gtk2:}")
	t.FinishSetUp()
	pkg := NewPackage(t.File("x11/p5-gtk2"))
	files, mklines, allLines := pkg.load()

	pkg.check(files, mklines, allLines)

	t.Check(pkg.EffectivePkgname, equals, "p5-gtk2-1.0")
}

// In some cases the PKGNAME is derived from DISTNAME, and it seems as
// if the :C modifier would not affect anything. This may nevertheless
// be on purpose since the modifier may apply to future versions and
// do things like replacing a "-1" with a ".1".
func (s *Suite) Test_Package_determineEffectivePkgVars__ineffective_C_modifier(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"DISTNAME=\tdistname-1.0",
		"PKGNAME=\t${DISTNAME:C:does_not_match:replacement:}")
	t.FinishSetUp()
	pkg := NewPackage(t.File("category/package"))
	files, mklines, allLines := pkg.load()

	pkg.check(files, mklines, allLines)

	t.Check(pkg.EffectivePkgname, equals, "distname-1.0")
	t.CheckOutputEmpty()
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

	t.SetUpCommandLine("--dumpmakefile")
	t.SetUpPkgsrc()
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
	// TODO: There is no .include line at the end of the Makefile.
	//  This should always be checked though.
	t.FinishSetUp()

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

	t.SetUpPkgsrc()
	t.SetUpTool("printf", "", AtRunTime)
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
		// At this point, all tools from USE_TOOLS are defined with their variables.
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

	t.SetUpCommandLine("-q", "-Wall,no-space")
	t.FinishSetUp()

	G.Check(t.File("category/pkgbase"))

	t.CheckOutputLines(
		"NOTE: ~/category/pkgbase/Makefile:14: Consider the :sh modifier instead of != for \"echo false=${FALSE:Q}\".",
		"WARN: ~/category/pkgbase/Makefile:14: To use the tool ${FALSE} at load time, bsd.prefs.mk has to be included before.",
		"NOTE: ~/category/pkgbase/Makefile:15: Consider the :sh modifier instead of != for \"echo nice=${NICE:Q}\".",

		// TODO: replace "at load time" with "before including bsd.prefs.mk in line ###".
		// TODO: ${NICE} could be used at load time if it were added to USE_TOOLS earlier.
		"WARN: ~/category/pkgbase/Makefile:15: The tool ${NICE} cannot be used at load time.",

		"NOTE: ~/category/pkgbase/Makefile:16: Consider the :sh modifier instead of != for \"echo true=${TRUE:Q}\".",
		"WARN: ~/category/pkgbase/Makefile:16: To use the tool ${TRUE} at load time, bsd.prefs.mk has to be included before.",
		"NOTE: ~/category/pkgbase/Makefile:24: Consider the :sh modifier instead of != for \"echo false=${FALSE:Q}\".",
		"NOTE: ~/category/pkgbase/Makefile:25: Consider the :sh modifier instead of != for \"echo nice=${NICE:Q}\".",
		"WARN: ~/category/pkgbase/Makefile:25: The tool ${NICE} cannot be used at load time.",
		"NOTE: ~/category/pkgbase/Makefile:26: Consider the :sh modifier instead of != for \"echo true=${TRUE:Q}\".")
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
	// This test demonstrates that a file including itself does not lead to an
	// endless loop while parsing. It might trigger an error in the future.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package__relative_included_filenames_in_same_directory(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"PKGNAME=\tpkgname-1.67",
		"DISTNAME=\tdistfile_1_67",
		".include \"../../category/package/other.mk\"")
	t.CreateFileLines("category/package/other.mk",
		MkRcsID,
		"PKGNAME=\tpkgname-1.67",
		"DISTNAME=\tdistfile_1_67",
		".include \"../../category/package/other.mk\"")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	// TODO: Since other.mk is referenced via "../../category/package",
	//  it would be nice if this relative path would be reflected in the output
	//  instead of referring just to "other.mk".
	//  This needs to be fixed somewhere near relpath.
	//
	// The notes are in reverse order because they are produced when checking
	// other.mk, and there the relative order is correct (line 2 before line 3).
	t.CheckOutputLines(
		"NOTE: ~/category/package/Makefile:4: "+
			"Definition of PKGNAME is redundant because of other.mk:2.",
		"NOTE: ~/category/package/Makefile:3: "+
			"Definition of DISTNAME is redundant because of other.mk:3.")
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
	pkg := t.SetUpPackage("category/package",
		"PECL_VERSION=\t1.1.2",
		".include \"../../lang/php/ext.mk\"")
	t.FinishSetUp()

	G.Check(pkg)
}

func (s *Suite) Test_Package_checkIncludeConditionally__conditional_and_unconditional_include(c *check.C) {
	t := s.Init(c)

	t.SetUpOption("zlib", "")
	t.SetUpPackage("category/package",
		".include \"../../devel/zlib/buildlink3.mk\"",
		".if ${OPSYS} == \"Linux\"",
		".include \"../../sysutils/coreutils/buildlink3.mk\"",
		".endif")
	t.CreateFileLines("devel/zlib/buildlink3.mk", "")
	t.CreateFileLines("sysutils/coreutils/buildlink3.mk", "")

	t.CreateFileLines("category/package/options.mk",
		MkRcsID,
		"",
		".if !empty(PKG_OPTIONS:Mzlib)",
		".  include \"../../devel/zlib/buildlink3.mk\"",
		".endif",
		".include \"../../sysutils/coreutils/buildlink3.mk\"")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.checkdirPackage(".")

	t.CheckOutputLines(
		"WARN: options.mk:4: \"../../devel/zlib/buildlink3.mk\" is "+
			"included conditionally here (depending on PKG_OPTIONS) "+
			"and unconditionally in Makefile:20.",
		"WARN: options.mk:6: \"../../sysutils/coreutils/buildlink3.mk\" is "+
			"included unconditionally here "+
			"and conditionally in Makefile:22 (depending on OPSYS).",
		"WARN: options.mk:3: Expected definition of PKG_OPTIONS_VAR.")
}

// See https://github.com/rillig/pkglint/issues/1
func (s *Suite) Test_Package__include_without_exists(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".include \"options.mk\"")
	t.FinishSetUp()

	G.checkdirPackage(t.File("category/package"))

	t.CheckOutputLines(
		"ERROR: ~/category/package/Makefile:20: Cannot read \"options.mk\".")
}

// See https://github.com/rillig/pkglint/issues/1
func (s *Suite) Test_Package__include_after_exists(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".if exists(options.mk)",
		".  include \"options.mk\"",
		".endif")
	t.FinishSetUp()

	G.checkdirPackage(t.File("category/package"))

	// No error message at all because of the .if exists before.
	t.CheckOutputEmpty()
}

// See https://github.com/rillig/pkglint/issues/1
func (s *Suite) Test_Package_readMakefile__include_other_after_exists(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".if exists(options.mk)",
		".  include \"another.mk\"",
		".endif")
	t.FinishSetUp()

	G.checkdirPackage(t.File("category/package"))

	t.CheckOutputLines(
		"ERROR: ~/category/package/Makefile:21: Cannot read \"another.mk\".")
}

// See https://mail-index.netbsd.org/tech-pkg/2018/07/22/msg020092.html
func (s *Suite) Test_Package__redundant_master_sites(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.SetUpMasterSite("MASTER_SITE_R_CRAN", "http://cran.r-project.org/src/")
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
	t.FinishSetUp()

	// See Package.checkfilePackageMakefile
	G.checkdirPackage(t.File("math/R-date"))

	// The definition in Makefile:6 is redundant because the same definition
	// occurs later in Makefile.extension:4.
	//
	// When a file includes another file, it's always the including file that
	// is marked as redundant since the included file typically provides the
	// generally useful value for several packages;
	// see RedundantScope.handleVarassign, keyword includePath.
	t.CheckOutputLines(
		"NOTE: ~/math/R-date/Makefile:6: " +
			"Definition of MASTER_SITES is redundant " +
			"because of ../../math/R/Makefile.extension:4.")
}

func (s *Suite) Test_Package_checkUpdate(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/pkg1",
		"PKGNAME=                package1-1.0")
	t.SetUpPackage("category/pkg2",
		"PKGNAME=                package2-1.0")
	t.SetUpPackage("category/pkg3",
		"PKGNAME=                package3-5.0")
	t.CreateFileLines("doc/TODO",
		"Suggested package updates",
		"",
		"",
		"\t"+"O wrong bullet",
		"\t"+"o package-without-version",
		"\t"+"o package1-1.0",
		"\t"+"o package2-2.0 [nice new features]",
		"\t"+"o package3-3.0 [security update]")
	t.Chdir(".")

	t.Main("-Wall,no-space", "category/pkg1", "category/pkg2", "category/pkg3")

	t.CheckOutputLines(
		"WARN: category/pkg1/../../doc/TODO:3: Invalid line format \"\".",
		"WARN: category/pkg1/../../doc/TODO:4: Invalid line format \"\\tO wrong bullet\".",
		"WARN: category/pkg1/../../doc/TODO:5: Invalid package name \"package-without-version\".",
		"NOTE: category/pkg1/Makefile:4: The update request to 1.0 from doc/TODO has been done.",
		"WARN: category/pkg2/Makefile:4: This package should be updated to 2.0 ([nice new features]).",
		"NOTE: category/pkg3/Makefile:4: This package is newer than the update request to 3.0 ([security update]).",
		"0 errors and 4 warnings found.",
		"(Run \"pkglint -e\" to show explanations.)")
}

func (s *Suite) Test_NewPackage(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("category/Makefile",
		MkRcsID)
	t.FinishSetUp()

	c.Check(
		func() { NewPackage("category") },
		check.PanicMatches,
		`Pkglint internal error: Package directory "category" must be two subdirectories below the pkgsrc root ".*".`)
}

// Before 2018-09-09, the .CURDIR variable did not have a fallback value.
// When resolving the relative path x11/gst-x11/${.CURDIR}/../../multimedia/gst-base/distinfo,
// "gst-x11/${.CURDIR}" was interpreted as "category/package", and the whole
// path was resolved to "x11/multimedia/gst-base/distinfo, which of course
// could not be found.
func (s *Suite) Test__distinfo_from_other_package(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall,no-space")
	t.SetUpPkgsrc()
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
	t.FinishSetUp()

	G.Check("x11/gst-x11")

	t.CheckOutputLines(
		"WARN: x11/gst-x11/Makefile: Neither PLIST nor PLIST.common exist, and PLIST_SRC is unset.",
		"ERROR: x11/gst-x11/Makefile: Each package must define its LICENSE.",
		"WARN: x11/gst-x11/Makefile: Each package should define a COMMENT.",
		"WARN: x11/gst-x11/../../multimedia/gst-base/distinfo:3: Patch file \"patch-aa\" does not exist in directory \"../../x11/gst-x11/patches\".")
}

func (s *Suite) Test_Package_checkfilePackageMakefile__GNU_CONFIGURE(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall,no-space")
	pkg := t.SetUpPackage("category/package",
		"GNU_CONFIGURE=\tyes",
		"USE_LANGUAGES=\t#")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:20: GNU_CONFIGURE almost always needs a C compiler, but \"c\" is not added to USE_LANGUAGES in line 21.")
}

// Packages that define GNU_CONFIGURE should also set at least USE_LANGUAGES=c.
// Except if they know what they are doing, as documented in the comment "none, really".
func (s *Suite) Test_Package_checkfilePackageMakefile__GNU_CONFIGURE_ok(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall,no-space")
	pkg := t.SetUpPackage("category/package",
		"GNU_CONFIGURE=\tyes",
		"USE_LANGUAGES=\t# none, really")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_checkfilePackageMakefile__REPLACE_PERL(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall,no-space")
	pkg := t.SetUpPackage("category/package",
		"REPLACE_PERL=\t*.pl",
		"NO_CONFIGURE=\tyes")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:20: REPLACE_PERL is ignored when NO_CONFIGURE is set (in line 21).")
}

func (s *Suite) Test_Package_checkfilePackageMakefile__META_PACKAGE_with_distinfo(c *check.C) {
	t := s.Init(c)

	pkg := t.SetUpPackage("category/package",
		"META_PACKAGE=\tyes")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputLines(
		"WARN: ~/category/package/distinfo: " +
			"This file should not exist since NO_CHECKSUM or META_PACKAGE is set.")
}

func (s *Suite) Test_Package_checkfilePackageMakefile__USE_IMAKE_and_USE_X11(c *check.C) {
	t := s.Init(c)

	pkg := t.SetUpPackage("category/package",
		"USE_X11=\tyes",
		"USE_IMAKE=\tyes")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputLines(
		"NOTE: ~/category/package/Makefile:21: USE_IMAKE makes USE_X11 in line 20 redundant.")
}

func (s *Suite) Test_Package_checkGnuConfigureUseLanguages__no_C(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"USE_LANGUAGES=\tfortran77",
		"USE_LANGUAGES+=\tc++14",
		"USE_LANGUAGES+=\tada",
		"GNU_CONFIGURE=\tyes")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:23: "+
			"GNU_CONFIGURE almost always needs a C compiler, "+
			"but \"c\" is not added to USE_LANGUAGES in line 20.",
		"WARN: ~/category/package/Makefile:23: "+
			"GNU_CONFIGURE almost always needs a C compiler, "+
			"but \"c\" is not added to USE_LANGUAGES in line 21.",
		"WARN: ~/category/package/Makefile:23: "+
			"GNU_CONFIGURE almost always needs a C compiler, "+
			"but \"c\" is not added to USE_LANGUAGES in line 22.")
}

func (s *Suite) Test_Package_checkGnuConfigureUseLanguages__C_in_the_middle(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"USE_LANGUAGES=\tfortran77",
		"USE_LANGUAGES+=\tc99",
		"USE_LANGUAGES+=\tada",
		"GNU_CONFIGURE=\tyes")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	// Until March 2019 pkglint wrongly warned that USE_LANGUAGES would not
	// include c or c99, although c99 was added.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_checkGnuConfigureUseLanguages__realistic_compiler_mk(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"USE_LANGUAGES=\tfortran77",
		"USE_LANGUAGES+=\tc++",
		"USE_LANGUAGES+=\tada",
		"GNU_CONFIGURE=\tyes",
		"",
		".include \"../../mk/compiler.mk\"")
	t.CreateFileLines("mk/compiler.mk",
		MkRcsID,
		".include \"bsd.prefs.mk\"",
		"",
		"USE_LANGUAGES?=\tc",
		"USE_LANGUAGES+=\tc",
		"USE_LANGUAGES+=\tc++")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	// The package defines several languages it needs, but C is not one of them.
	// When the package is loaded, the included files are read in recursively, even
	// when they come from the pkgsrc infrastructure.
	//
	// Up to March 2019, the USE_LANGUAGES definitions from mk/compiler.mk were
	// loaded as if they were defined by the package, without taking the conditionals
	// into account. Thereby "c" was added unconditionally to USE_LANGUAGES.
	//
	// Since March 2019 the infrastructure files are ignored when determining the value
	// of USE_LANGUAGES.
	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:23: "+
			"GNU_CONFIGURE almost always needs a C compiler, "+
			"but \"c\" is not added to USE_LANGUAGES in line 20.",
		"WARN: ~/category/package/Makefile:23: "+
			"GNU_CONFIGURE almost always needs a C compiler, "+
			"but \"c\" is not added to USE_LANGUAGES in line 21.",
		"WARN: ~/category/package/Makefile:23: "+
			"GNU_CONFIGURE almost always needs a C compiler, "+
			"but \"c\" is not added to USE_LANGUAGES in line 22.")
}

func (s *Suite) Test_Package_checkGnuConfigureUseLanguages__only_GNU_CONFIGURE(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"GNU_CONFIGURE=\tyes")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_checkGnuConfigureUseLanguages__ok(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"GNU_CONFIGURE=\tyes",
		"USE_LANGUAGES=\tc++ objc")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_checkUseLanguagesCompilerMk__too_late(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".include \"../../mk/compiler.mk\"",
		"USE_LANGUAGES=\tc c99 fortran ada c++14")
	t.CreateFileLines("mk/compiler.mk",
		MkRcsID)
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:21: " +
			"Modifying USE_LANGUAGES after including ../../mk/compiler.mk has no effect.")
}

func (s *Suite) Test_Package_checkUseLanguagesCompilerMk__compiler_mk(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".include \"compiler.mk\"",
		"USE_LANGUAGES=\tc c99 fortran ada c++14",
		".include \"../../mk/compiler.mk\"",
		"USE_LANGUAGES=\tc c99 fortran ada c++14")
	t.CreateFileLines("category/package/compiler.mk",
		MkRcsID)
	t.CreateFileLines("mk/compiler.mk",
		MkRcsID)
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"NOTE: ~/category/package/Makefile:23: "+
			"Definition of USE_LANGUAGES is redundant because of line 21.",
		"WARN: ~/category/package/Makefile:23: "+
			"Modifying USE_LANGUAGES after including ../../mk/compiler.mk has no effect.")
}

func (s *Suite) Test_Package_readMakefile__skipping(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall,no-space")
	pkg := t.SetUpPackage("category/package",
		".include \"${MYSQL_PKGSRCDIR:S/-client$/-server/}/buildlink3.mk\"")
	t.FinishSetUp()

	t.EnableTracingToLog()
	G.Check(pkg)
	t.EnableSilentTracing()

	// Since 2018-12-16 there is no warning or note anymore for the
	// buildlink3.mk file being skipped since it didn't help the average
	// pkglint user.

	// The information is still available in the trace log though.

	output := t.Output()
	var relevant []string
	for _, line := range strings.Split(output, "\n") {
		if contains(line, "Skipping") {
			relevant = append(relevant, line)
		}
	}

	c.Check(relevant, deepEquals, []string{
		"TRACE: 1 2 3 4   ~/category/package/Makefile:20: " +
			"Skipping include file \"${MYSQL_PKGSRCDIR:S/-client$/-server/}/buildlink3.mk\". " +
			"This may result in false warnings."})
}

func (s *Suite) Test_Package_readMakefile__not_found(c *check.C) {
	t := s.Init(c)

	pkg := t.SetUpPackage("category/package",
		".include \"../../devel/zlib/buildlink3.mk\"")
	t.CreateFileLines("devel/zlib/buildlink3.mk",
		".include \"../../enoent/enoent/buildlink3.mk\"")
	t.FinishSetUp()

	G.checkdirPackage(pkg)

	t.CheckOutputLines(
		"ERROR: ~/devel/zlib/buildlink3.mk:1: Cannot read \"../../enoent/enoent/buildlink3.mk\".")
}

func (s *Suite) Test_Package_readMakefile__relative(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("category/package/extra.mk",
		MkRcsID)
	pkg := t.SetUpPackage("category/package",
		".include \"../package/extra.mk\"")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:20: " +
			"References to other packages should look " +
			"like \"../../category/package\", not \"../package\".")
}

// When a buildlink3.mk file is included, the corresponding builtin.mk
// file is included by the pkgsrc infrastructure. Therefore all variables
// declared in the builtin.mk file become known in the package.
func (s *Suite) Test_Package_readMakefile__builtin_mk(c *check.C) {
	t := s.Init(c)

	t.SetUpTool("echo", "ECHO", AtRunTime)
	t.SetUpPackage("category/package",
		".include \"../../category/lib1/buildlink3.mk\"",
		"",
		"show-var-from-builtin: .PHONY",
		"\techo ${VAR_FROM_BUILTIN} ${OTHER_VAR}")
	t.CreateFileDummyBuildlink3("category/lib1/buildlink3.mk")
	t.CreateFileLines("category/lib1/builtin.mk",
		MkRcsID,
		"VAR_FROM_BUILTIN=\t# defined")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:23: Please use \"${ECHO}\" instead of \"echo\".",
		"WARN: ~/category/package/Makefile:23: OTHER_VAR is used but not defined.")
}

// Ensures that the paths in Package.included are indeed relative to the
// package directory. This hadn't been the case until March 2019.
func (s *Suite) Test_Package_readMakefile__included(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".include \"../../devel/library/buildlink3.mk\"",
		".include \"../../lang/language/module.mk\"")
	t.SetUpPackage("devel/library")
	t.CreateFileDummyBuildlink3("devel/library/buildlink3.mk")
	t.CreateFileLines("devel/library/builtin.mk",
		MkRcsID)
	t.CreateFileLines("lang/language/module.mk",
		MkRcsID,
		".include \"version.mk\"")
	t.CreateFileLines("lang/language/version.mk",
		MkRcsID)
	t.FinishSetUp()
	pkg := NewPackage(t.File("category/package"))

	pkg.loadPackageMakefile()

	expected := []string{
		"../../devel/library/buildlink3.mk",
		"../../devel/library/builtin.mk",
		"../../lang/language/module.mk",
		"../../lang/language/version.mk",
		"suppress-varorder.mk"}

	seen := pkg.included
	for _, filename := range expected {
		if !seen.Seen(filename) {
			c.Errorf("File %q is not seen.", filename)
		}
	}
	t.Check(seen.seen, check.HasLen, 5)
}

// Just for code coverage.
func (s *Suite) Test_Package_findIncludedFile__no_tracing(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".include \"../../${UNKNOWN_PKGPATH}/buildlink3.mk\"",
		".include \"../../lang/language/buildlink3.mk\"")
	t.CreateFileLines("lang/language/buildlink3.mk",
		MkRcsID)
	t.FinishSetUp()
	pkg := NewPackage(t.File("category/package"))
	t.DisableTracing()

	pkg.loadPackageMakefile()

	expected := []string{
		"../../lang/language/buildlink3.mk",
		"../../lang/language/builtin.mk",
		"suppress-varorder.mk"}

	seen := pkg.included
	for _, filename := range expected {
		if !seen.Seen(filename) {
			c.Errorf("File %q is not seen.", filename)
		}
	}
	t.Check(seen.seen, check.HasLen, 3)
}

func (s *Suite) Test_Package_checkLocallyModified(c *check.C) {
	t := s.Init(c)

	G.Username = "example-user"
	t.CreateFileLines("category/package/CVS/Entries",
		"/Makefile//modified//")

	// In packages without specific MAINTAINER, everyone may commit changes.

	pkg := t.SetUpPackage("category/package",
		"MAINTAINER=\tpkgsrc-users@NetBSD.org")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputEmpty()

	// A package with a MAINTAINER may be edited with care.

	t.SetUpPackage("category/package",
		"MAINTAINER=\tmaintainer@example.org")

	G.Check(pkg)

	t.CheckOutputLines(
		"NOTE: ~/category/package/Makefile: " +
			"Please only commit changes that maintainer@example.org would approve.")

	// A package with an OWNER may NOT be edited by others.

	pkg = t.SetUpPackage("category/package",
		"#MAINTAINER=\t# undefined",
		"OWNER=\towner@example.org")

	G.Check(pkg)

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile: " +
			"Don't commit changes to this file without asking the OWNER, owner@example.org.")

	// In a package with both OWNER and MAINTAINER, OWNER wins.

	pkg = t.SetUpPackage("category/package",
		"MAINTAINER=\tmaintainer@example.org",
		"OWNER=\towner@example.org")

	G.Check(pkg)

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile: "+
			"Don't commit changes to this file without asking the OWNER, owner@example.org.",
		"NOTE: ~/category/package/Makefile: "+
			"Please only commit changes that maintainer@example.org would approve.")

	// ... unless you are the owner, of course.

	G.Username = "owner"

	G.Check(pkg)

	t.CheckOutputEmpty()
}

// Just for code coverage.
func (s *Suite) Test_Package_checkLocallyModified__no_tracing(c *check.C) {
	t := s.Init(c)

	G.Username = "example-user"
	t.CreateFileLines("category/package/CVS/Entries",
		"/Makefile//modified//")

	pkg := t.SetUpPackage("category/package",
		"MAINTAINER=\tmaintainer@example.org")
	t.FinishSetUp()
	t.DisableTracing()

	G.Check(pkg)

	t.CheckOutputLines(
		"NOTE: ~/category/package/Makefile: Please only commit changes " +
			"that maintainer@example.org would approve.")
}

func (s *Suite) Test_Package_checkLocallyModified__directory(c *check.C) {
	t := s.Init(c)

	G.Username = "example-user"
	t.CreateFileLines("category/package/CVS/Entries",
		"/Makefile//modified//",
		"D/patches////")
	t.CreateFileDummyPatch("category/package/patches/patch-aa")

	pkg := t.SetUpPackage("category/package",
		"MAINTAINER=\tmaintainer@example.org")
	t.CreateFileLines("category/package/distinfo",
		RcsID,
		"",
		"SHA1 (patch-aa) = ebbf34b0641bcb508f17d5a27f2bf2a536d810ac")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputLines(
		"NOTE: ~/category/package/Makefile: " +
			"Please only commit changes that " +
			"maintainer@example.org would approve.")
}

// In practice the distinfo file can always be autofixed since it has
// just been read successfully and the corresponding patch file could
// also be autofixed right before.
func (s *Suite) Test_Package_AutofixDistinfo__missing_file(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	G.Pkg = NewPackage(t.File("category/package"))
	t.FinishSetUp()

	G.Pkg.AutofixDistinfo("old", "new")

	t.CheckOutputLines(
		"ERROR: ~/category/package/distinfo: Cannot be read.")
}

func (s *Suite) Test_Package__using_common_Makefile_overriding_DISTINFO_FILE(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("security/pinentry")
	t.CreateFileLines("security/pinentry/Makefile.common",
		MkRcsID,
		"DISTINFO_FILE=\t${.CURDIR}/../../security/pinentry/distinfo")
	t.SetUpPackage("security/pinentry-fltk",
		".include \"../../security/pinentry/Makefile.common\"",
		"DISTINFO_FILE=\t${.CURDIR}/distinfo")
	t.CreateFileDummyPatch("security/pinentry-fltk/patches/patch-aa")
	t.CreateFileLines("security/pinentry-fltk/distinfo",
		RcsID,
		"",
		"SHA1 (patch-aa) = ebbf34b0641bcb508f17d5a27f2bf2a536d810ac")
	t.FinishSetUp()

	G.Check(t.File("security/pinentry"))

	t.CheckOutputEmpty()

	G.Check(t.File("security/pinentry-fltk"))

	// The DISTINFO_FILE definition from pinentry-fltk overrides
	// the one from pinentry since it appears later.
	// Therefore the patch is searched for at the right location.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package__redundant_variable_in_unrelated_files(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("databases/py-trytond-ldap-authentication",
		".include \"../../devel/py-trytond/Makefile.common\"",
		".include \"../../lang/python/egg.mk\"")
	t.CreateFileLines("devel/py-trytond/Makefile.common",
		MkRcsID,
		"PY_PATCHPLIST=\tyes")
	t.CreateFileLines("lang/python/egg.mk",
		MkRcsID,
		"PY_PATCHPLIST=\tyes")
	t.FinishSetUp()

	G.Check(t.File("databases/py-trytond-ldap-authentication"))

	// Since egg.mk and Makefile.common are unrelated, the definition of
	// PY_PATCHPLIST is not redundant in these files.
	t.CheckOutputEmpty()
}

// Pkglint loads some files from the pkgsrc infrastructure and skips others.
//
// When a buildlink3.mk file from the infrastructure is included, it should
// be allowed to include its corresponding builtin.mk file in turn.
//
// This is necessary to load the correct variable assignments for the
// redundancy check, in particular variable assignments that serve as
// arguments to "procedure calls", such as mk/find-files.mk.
func (s *Suite) Test_Package_readMakefile__include_infrastructure(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--dumpmakefile")
	t.SetUpPackage("category/package",
		".include \"../../mk/dlopen.buildlink3.mk\"",
		".include \"../../mk/pthread.buildlink3.mk\"")
	t.CreateFileLines("mk/dlopen.buildlink3.mk",
		".include \"dlopen.builtin.mk\"")
	t.CreateFileLines("mk/dlopen.builtin.mk",
		".include \"pthread.builtin.mk\"")
	t.CreateFileLines("mk/pthread.buildlink3.mk",
		".include \"pthread.builtin.mk\"")
	t.CreateFileLines("mk/pthread.builtin.mk",
		"# This should be included by pthread.buildlink3.mk")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"Whole Makefile (with all included files) follows:",
		"~/category/package/Makefile:1: "+MkRcsID,
		"~/category/package/Makefile:2: ",
		"~/category/package/Makefile:3: DISTNAME=\tdistname-1.0",
		"~/category/package/Makefile:4: #PKGNAME=\tpackage-1.0",
		"~/category/package/Makefile:5: CATEGORIES=\tcategory",
		"~/category/package/Makefile:6: MASTER_SITES=\t# none",
		"~/category/package/Makefile:7: ",
		"~/category/package/Makefile:8: MAINTAINER=\tpkgsrc-users@NetBSD.org",
		"~/category/package/Makefile:9: HOMEPAGE=\t# none",
		"~/category/package/Makefile:10: COMMENT=\tDummy package",
		"~/category/package/Makefile:11: LICENSE=\t2-clause-bsd",
		"~/category/package/Makefile:12: ",
		"~/category/package/Makefile:13: .include \"suppress-varorder.mk\"",
		"~/category/package/suppress-varorder.mk:1: "+MkRcsID,
		"~/category/package/Makefile:14: # empty",
		"~/category/package/Makefile:15: # empty",
		"~/category/package/Makefile:16: # empty",
		"~/category/package/Makefile:17: # empty",
		"~/category/package/Makefile:18: # empty",
		"~/category/package/Makefile:19: # empty",
		"~/category/package/Makefile:20: .include \"../../mk/dlopen.buildlink3.mk\"",
		"~/category/package/../../mk/dlopen.buildlink3.mk:1: .include \"dlopen.builtin.mk\"",
		"~/mk/dlopen.builtin.mk:1: .include \"pthread.builtin.mk\"",
		"~/category/package/Makefile:21: .include \"../../mk/pthread.buildlink3.mk\"",
		"~/category/package/../../mk/pthread.buildlink3.mk:1: .include \"pthread.builtin.mk\"",
		"~/mk/pthread.builtin.mk:1: # This should be included by pthread.buildlink3.mk",
		"~/category/package/Makefile:22: ",
		"~/category/package/Makefile:23: .include \"../../mk/bsd.pkg.mk\"")
}

// As of April 2019, there are only a few files in the whole pkgsrc tree
// that are called Makefile.*, except Makefile.common, which occurs more
// often.
//
// Using the file extension for variants of that Makefile is confusing,
// therefore they should be renamed to *.mk.
func (s *Suite) Test_Package__Makefile_files(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileLines("category/package/Makefile.common",
		MkRcsID)
	t.CreateFileLines("category/package/Makefile.orig",
		MkRcsID)
	t.CreateFileLines("category/package/Makefile.php",
		MkRcsID)
	t.CreateFileLines("category/package/ext.mk",
		MkRcsID)
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	// No warning for the Makefile.orig since the package is not
	// being imported at the moment; see Pkglint.checkReg.
	t.CheckOutputLines(
		"NOTE: ~/category/package/Makefile.php: " +
			"Consider renaming \"Makefile.php\" to \"php.mk\".")
}
