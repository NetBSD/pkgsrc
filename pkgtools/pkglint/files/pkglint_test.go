package main

import (
	"io/ioutil"
	"path"
	"strings"
	"time"

	"gopkg.in/check.v1"
	"os"
)

func (s *Suite) Test_Pkglint_Main__help(c *check.C) {
	t := s.Init(c)

	exitcode := G.Main("pkglint", "-h")

	c.Check(exitcode, equals, 0)
	c.Check(t.Output(), check.Matches, `^\Qusage: pkglint [options] dir...\E\n(?s).+`)
}

func (s *Suite) Test_Pkglint_Main__version(c *check.C) {
	t := s.Init(c)

	exitcode := G.Main("pkglint", "--version")

	c.Check(exitcode, equals, 0)
	t.CheckOutputLines(
		confVersion)
}

func (s *Suite) Test_Pkglint_Main__no_args(c *check.C) {
	t := s.Init(c)

	exitcode := G.Main("pkglint")

	c.Check(exitcode, equals, 1)
	t.CheckOutputLines(
		"FATAL: \".\" must be inside a pkgsrc tree.")
}

func (s *Suite) Test_Pkglint_Main__only(c *check.C) {
	t := s.Init(c)

	exitcode := G.ParseCommandLine([]string{"pkglint", "-Wall", "-o", ":Q", "--version"})

	if c.Check(exitcode, check.NotNil) {
		c.Check(*exitcode, equals, 0)
	}
	c.Check(G.Opts.LogOnly, deepEquals, []string{":Q"})
	t.CheckOutputLines(
		confVersion)
}

func (s *Suite) Test_Pkglint_Main__unknown_option(c *check.C) {
	t := s.Init(c)

	exitcode := G.Main("pkglint", "--unknown-option")

	c.Check(exitcode, equals, 1)
	t.CheckOutputLines(
		"pkglint: unknown option: --unknown-option",
		"",
		"usage: pkglint [options] dir...",
		"",
		"  -C, --check=check,...       enable or disable specific checks",
		"  -d, --debug                 log verbose call traces for debugging",
		"  -e, --explain               explain the diagnostics or give further help",
		"  -f, --show-autofix          show what pkglint can fix automatically",
		"  -F, --autofix               try to automatically fix some errors",
		"  -g, --gcc-output-format     mimic the gcc output format",
		"  -h, --help                  show a detailed usage message",
		"  -I, --dumpmakefile          dump the Makefile after parsing",
		"  -i, --import                prepare the import of a wip package",
		"  -m, --log-verbose           allow the same log message more than once",
		"  -o, --only                  only log messages containing the given text",
		"  -p, --profiling             profile the executing program",
		"  -q, --quiet                 don't show a summary line when finishing",
		"  -r, --recursive             check subdirectories, too",
		"  -s, --source                show the source lines together with diagnostics",
		"  -V, --version               show the version number of pkglint",
		"  -W, --warning=warning,...   enable or disable groups of warnings",
		"",
		"  Flags for -C, --check:",
		"    all            all of the following",
		"    none           none of the following",
		"    ALTERNATIVES   check ALTERNATIVES files (enabled)",
		"    bl3            check buildlink3.mk files (enabled)",
		"    DESCR          check DESCR file (enabled)",
		"    distinfo       check distinfo file (enabled)",
		"    extra          check various additional files (disabled)",
		"    global         inter-package checks (disabled)",
		"    INSTALL        check INSTALL and DEINSTALL scripts (enabled)",
		"    Makefile       check Makefiles (enabled)",
		"    MESSAGE        check MESSAGE file (enabled)",
		"    mk             check other .mk files (enabled)",
		"    options        check options.mk files (enabled)",
		"    patches        check patches (enabled)",
		"    PLIST          check PLIST files (enabled)",
		"",
		"  Flags for -W, --warning:",
		"    all          all of the following",
		"    none         none of the following",
		"    absname      warn about use of absolute file names (enabled)",
		"    directcmd    warn about use of direct command names instead of Make variables (enabled)",
		"    extra        enable some extra warnings (disabled)",
		"    order        warn if Makefile entries are unordered (enabled)",
		"    perm         warn about unforeseen variable definition and use (disabled)",
		"    plist-depr   warn about deprecated paths in PLISTs (disabled)",
		"    plist-sort   warn about unsorted entries in PLISTs (disabled)",
		"    quoting      warn about quoting issues (disabled)",
		"    space        warn about inconsistent use of white-space (disabled)",
		"    style        warn about stylistic issues (disabled)",
		"    types        do some simple type checking in Makefiles (enabled)",
		"",
		"  (Prefix a flag with \"no-\" to disable it.)")
}

func (s *Suite) Test_Pkglint_Main__panic(c *check.C) {
	t := s.Init(c)

	pkg := t.SetupPackage("category/package")

	G.logOut = nil // Force an error that cannot happen in practice.

	c.Check(
		func() { G.Main("pkglint", pkg) },
		check.PanicMatches, `(?s).*\bnil pointer\b.*`)
}

// Demonstrates which infrastructure files are necessary to actually run
// pkglint in a realistic scenario.
// For most tests, this setup is too much work, therefore they
// initialize only those parts of the infrastructure they really
// need.
//
// Especially covers Pkglint.ShowSummary and Pkglint.Checkfile.
func (s *Suite) Test_Pkglint_Main__complete_package(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()

	// FIXME: pkglint should warn that the latest version in this file
	// (1.10) doesn't match the current version in the package (1.11).
	t.CreateFileLines("doc/CHANGES-2018",
		RcsID,
		"",
		"Changes to the packages collection and infrastructure in 2018:",
		"",
		"\tUpdated sysutils/checkperms to 1.10 [rillig 2018-01-05]")

	// See Pkgsrc.loadSuggestedUpdates.
	t.CreateFileLines("doc/TODO",
		RcsID,
		"",
		"Suggested package updates",
		"",
		"\to checkperms-1.13 [supports more file formats]")

	// The LICENSE in the package Makefile is searched here.
	t.CreateFileLines("licenses/bsd-2",
		"# dummy")

	// The MASTER_SITES in the package Makefile are searched here.
	// See Pkgsrc.loadMasterSites.
	t.CreateFileLines("mk/fetch/sites.mk",
		MkRcsID,
		"",
		"MASTER_SITE_GITHUB+=\thttps://github.com/")

	// The existence of this file makes the category "sysutils" valid.
	// The category "tools" on the other hand is not valid.
	t.CreateFileLines("sysutils/Makefile",
		MkRcsID)

	// The package Makefile is quite simple, containing just the
	// standard variable definitions. The data for checking the variable
	// values is partly defined in the pkgsrc infrastructure files
	// (as defined in the previous lines), and partly in the pkglint
	// code directly. Many details can be found in vartypecheck.go.
	t.CreateFileLines("sysutils/checkperms/Makefile",
		MkRcsID,
		"",
		"DISTNAME=\tcheckperms-1.11",
		"CATEGORIES=\tsysutils tools",
		"MASTER_SITES=\t${MASTER_SITE_GITHUB:=rillig/}",
		"",
		"MAINTAINER=\tpkgsrc-users@NetBSD.org",
		"HOMEPAGE=\thttps://github.com/rillig/checkperms/",
		"COMMENT=\tCheck file permissions",
		"LICENSE=\tbsd-2",
		"",
		".include \"../../mk/bsd.pkg.mk\"")

	t.CreateFileLines("sysutils/checkperms/MESSAGE",
		"===========================================================================",
		RcsID,
		"",
		"After installation, this package has to be configured in a special way.",
		"",
		"===========================================================================")

	t.CreateFileLines("sysutils/checkperms/PLIST",
		PlistRcsID,
		"bin/checkperms",
		"man/man1/checkperms.1")

	t.CreateFileLines("sysutils/checkperms/README",
		"When updating this package, test the pkgsrc bootstrap.")

	t.CreateFileLines("sysutils/checkperms/TODO",
		"Make the package work on MS-DOS")

	t.CreateFileLines("sysutils/checkperms/patches/patch-checkperms.c",
		RcsID,
		"",
		"A simple patch demonstrating that pkglint checks for missing",
		"removed lines. The hunk headers says that one line is to be",
		"removed, but in fact, there is no deletion line below it.",
		"",
		"--- a/checkperms.c",
		"+++ b/checkperms.c",
		"@@ -1,1 +1,3 @@", // at line 1, delete 1 line; at line 1, add 3 lines
		"+// Header 1",
		"+// Header 2",
		"+// Header 3")
	t.CreateFileLines("sysutils/checkperms/distinfo",
		RcsID,
		"",
		"SHA1 (checkperms-1.12.tar.gz) = 34c084b4d06bcd7a8bba922ff57677e651eeced5",
		"RMD160 (checkperms-1.12.tar.gz) = cd95029aa930b6201e9580b3ab7e36dd30b8f925",
		"SHA512 (checkperms-1.12.tar.gz) = 43e37b5963c63fdf716acdb470928d7e21a7bdfddd6c85cf626a11acc7f45fa52a53d4bcd83d543150328fe8cec5587987d2d9a7c5f0aaeb02ac1127ab41f8ae",
		"Size (checkperms-1.12.tar.gz) = 6621 bytes",
		"SHA1 (patch-checkperms.c) = asdfasdf") // Invalid SHA-1 checksum

	G.Main("pkglint", "-Wall", "-Call", t.File("sysutils/checkperms"))

	t.CheckOutputLines(
		"WARN: ~/sysutils/checkperms/Makefile:3: This package should be updated to 1.13 ([supports more file formats]).",
		"ERROR: ~/sysutils/checkperms/Makefile:4: Invalid category \"tools\".",
		"ERROR: ~/sysutils/checkperms/README: Packages in main pkgsrc must not have a README file.",
		"ERROR: ~/sysutils/checkperms/TODO: Packages in main pkgsrc must not have a TODO file.",
		"ERROR: ~/sysutils/checkperms/distinfo:7: SHA1 hash of patches/patch-checkperms.c differs "+
			"(distinfo has asdfasdf, patch file has e775969de639ec703866c0336c4c8e0fdd96309c).",
		"WARN: ~/sysutils/checkperms/patches/patch-checkperms.c:12: Premature end of patch hunk "+
			"(expected 1 lines to be deleted and 0 lines to be added).",
		"4 errors and 2 warnings found.",
		"(Run \"pkglint -e\" to show explanations.)",
		"(Run \"pkglint -fs\" to show what can be fixed automatically.)",
		"(Run \"pkglint -F\" to automatically fix some issues.)")
}

// go test -c -covermode count
// pkgsrcdir=...
// env PKGLINT_TESTCMDLINE="$pkgsrcdir -r" ./pkglint.test -test.coverprofile pkglint.cov
// go tool cover -html=pkglint.cov -o coverage.html
func (s *Suite) Test_Pkglint__coverage(c *check.C) {
	cmdline := os.Getenv("PKGLINT_TESTCMDLINE")
	if cmdline != "" {
		G.logOut, G.logErr, trace.Out = NewSeparatorWriter(os.Stdout), NewSeparatorWriter(os.Stderr), os.Stdout
		G.Main(append([]string{"pkglint"}, fields(cmdline)...)...)
	}
}

func (s *Suite) Test_Pkglint_CheckDirent__outside(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("empty")

	G.CheckDirent(t.File("."))

	t.CheckOutputLines(
		"ERROR: ~: Cannot determine the pkgsrc root directory for \"~\".")
}

func (s *Suite) Test_Pkglint_CheckDirent__empty_directory(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()
	t.CreateFileLines("category/package/CVS/Entries")

	G.CheckDirent(t.File("category/package"))

	// Empty directories are silently skipped.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Pkglint_CheckDirent__files_directory(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()
	t.CreateFileLines("category/package/files/README.md")

	G.CheckDirent(t.File("category/package/files"))

	// This diagnostic is not really correct, but it's an edge case anyway.
	t.CheckOutputLines(
		"ERROR: ~/category/package/files: Cannot check directories outside a pkgsrc tree.")
}

func (s *Suite) Test_Pkglint_CheckDirent__manual_patch(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()
	t.CreateFileLines("category/package/patches/manual-configure")
	t.CreateFileLines("category/package/Makefile",
		MkRcsID)

	G.CheckDirent(t.File("category/package"))

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile: Neither PLIST nor PLIST.common exist, and PLIST_SRC is unset.",
		"WARN: ~/category/package/distinfo: File not found. Please run \""+confMake+" makesum\" or define NO_CHECKSUM=yes in the package Makefile.",
		"ERROR: ~/category/package/Makefile: Each package must define its LICENSE.",
		"WARN: ~/category/package/Makefile: No COMMENT given.")
}

func (s *Suite) Test_Pkglint_CheckDirent(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("mk/bsd.pkg.mk")
	t.CreateFileLines("category/package/Makefile")
	t.CreateFileLines("category/Makefile")
	t.CreateFileLines("Makefile")

	G.CheckDirent(t.File("."))

	t.CheckOutputLines(
		"ERROR: ~/Makefile: Must not be empty.")

	G.CheckDirent(t.File("category"))

	t.CheckOutputLines(
		"ERROR: ~/category/Makefile: Must not be empty.")

	G.CheckDirent(t.File("category/package"))

	t.CheckOutputLines(
		"ERROR: ~/category/package/Makefile: Must not be empty.")

	G.CheckDirent(t.File("category/package/nonexistent"))

	t.CheckOutputLines(
		"ERROR: ~/category/package/nonexistent: No such file or directory.")
}

func (s *Suite) Test_resolveVariableRefs__circular_reference(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("fileName", 1, "GCC_VERSION=${GCC_VERSION}")
	G.Pkg = NewPackage(t.File("category/pkgbase"))
	G.Pkg.vars.Define("GCC_VERSION", mkline)

	resolved := resolveVariableRefs("gcc-${GCC_VERSION}")

	c.Check(resolved, equals, "gcc-${GCC_VERSION}")
}

func (s *Suite) Test_resolveVariableRefs__multilevel(c *check.C) {
	t := s.Init(c)

	mkline1 := t.NewMkLine("fileName", 10, "_=${SECOND}")
	mkline2 := t.NewMkLine("fileName", 11, "_=${THIRD}")
	mkline3 := t.NewMkLine("fileName", 12, "_=got it")
	G.Pkg = NewPackage(t.File("category/pkgbase"))
	defineVar(mkline1, "FIRST")
	defineVar(mkline2, "SECOND")
	defineVar(mkline3, "THIRD")

	resolved := resolveVariableRefs("you ${FIRST}")

	c.Check(resolved, equals, "you got it")
}

// Usually, a dot in a variable name means a parameterized form.
// In this case, it is part of a version number. Resolving these
// variables from the scope works nevertheless.
func (s *Suite) Test_resolveVariableRefs__special_chars(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("fileName", 10, "_=x11")
	G.Pkg = NewPackage(t.File("category/pkg"))
	G.Pkg.vars.Define("GST_PLUGINS0.10_TYPE", mkline)

	resolved := resolveVariableRefs("gst-plugins0.10-${GST_PLUGINS0.10_TYPE}/distinfo")

	c.Check(resolved, equals, "gst-plugins0.10-x11/distinfo")
}

func (s *Suite) Test_ChecklinesDescr(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("DESCR",
		strings.Repeat("X", 90),
		"", "", "", "", "", "", "", "", "10",
		"Try ${PREFIX}",
		"", "", "", "", "", "", "", "", "20",
		"", "", "", "", "", "", "", "", "", "30")

	ChecklinesDescr(lines)

	t.CheckOutputLines(
		"WARN: DESCR:1: Line too long (should be no more than 80 characters).",
		"NOTE: DESCR:11: Variables are not expanded in the DESCR file.",
		"WARN: DESCR:25: File too long (should be no more than 24 lines).")
}

func (s *Suite) Test_ChecklinesMessage__short(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("MESSAGE",
		"one line")

	ChecklinesMessage(lines)

	t.CheckOutputLines(
		"WARN: MESSAGE:1: File too short.")
}

func (s *Suite) Test_ChecklinesMessage__malformed(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("MESSAGE",
		"1",
		"2",
		"3",
		"4",
		"5")

	ChecklinesMessage(lines)

	t.CheckOutputLines(
		"WARN: MESSAGE:1: Expected a line of exactly 75 \"=\" characters.",
		"ERROR: MESSAGE:1: Expected \"$"+"NetBSD$\".",
		"WARN: MESSAGE:5: Expected a line of exactly 75 \"=\" characters.")
}

func (s *Suite) Test_ChecklinesMessage__autofix(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall", "--autofix")
	lines := t.SetupFileLines("MESSAGE",
		"1",
		"2",
		"3",
		"4",
		"5")

	ChecklinesMessage(lines)

	t.CheckOutputLines(
		"AUTOFIX: ~/MESSAGE:1: Inserting a line "+
			"\"===========================================================================\" "+
			"before this line.",
		"AUTOFIX: ~/MESSAGE:1: Inserting a line \"$"+"NetBSD$\" before this line.",
		"AUTOFIX: ~/MESSAGE:5: Inserting a line "+
			"\"===========================================================================\" "+
			"after this line.")
	t.CheckFileLines("MESSAGE",
		"===========================================================================",
		RcsID,
		"1",
		"2",
		"3",
		"4",
		"5",
		"===========================================================================")
}

// Demonstrates that an ALTERNATIVES file can be tested individually,
// without any dependencies on a whole package or a PLIST file.
func (s *Suite) Test_Pkglint_Checkfile__alternatives(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()
	lines := t.SetupFileLines("category/package/ALTERNATIVES",
		"bin/tar @PREFIX@/bin/gnu-tar")

	G.Main("pkglint", lines.FileName)

	t.CheckOutputLines(
		"NOTE: ~/category/package/ALTERNATIVES:1: @PREFIX@/ can be omitted from the file name.",
		"Looks fine.",
		"(Run \"pkglint -e\" to show explanations.)")
}

func (s *Suite) Test_Pkglint__profiling(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()
	t.Chdir(".")

	G.Main("pkglint", "--profiling")

	// Pkglint always writes the profiling data into the current directory.
	c.Check(fileExists("pkglint.pprof"), equals, true)

	err := os.Remove("pkglint.pprof")
	c.Check(err, check.IsNil)

	// Everything but the first few lines of output is not easily testable
	// or not interesting enough, since that info includes the exact timing
	// that the top time-consuming regular expressions took.
	firstOutput := strings.Split(t.Output(), "\n")[0]
	c.Check(firstOutput, equals, "ERROR: Makefile: Cannot be read.")
}

func (s *Suite) Test_Pkglint__profiling_error(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()
	t.Chdir(".")
	t.CreateFileLines("pkglint.pprof/file")

	exitcode := G.Main("pkglint", "--profiling")

	c.Check(exitcode, equals, 1)
	c.Check(t.Output(), check.Matches, `^FATAL: Cannot create profiling file: open pkglint\.pprof: .*\n$`)
}

func (s *Suite) Test_Pkglint_Checkfile__in_current_working_directory(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()
	t.SetupVartypes()
	t.CreateFileLines("licenses/mit")
	t.Chdir("category/package")
	t.CreateFileLines("log")
	t.CreateFileLines("Makefile",
		MkRcsID,
		"",
		"NO_CHECKSUM=    yes",
		"COMMENT=        Useful utilities",
		"LICENSE=        mit",
		"",
		".include \"../../mk/bsd.pkg.mk\"")
	t.CreateFileLines("PLIST",
		PlistRcsID,
		"bin/program")
	t.CreateFileLines("DESCR",
		"Package description")

	G.Main("pkglint")

	t.CheckOutputLines(
		"WARN: log: Unexpected file found.",
		"0 errors and 1 warning found.")
}

func (s *Suite) Test_Pkglint_Tool__prefer_mk_over_pkgsrc(c *check.C) {
	t := s.Init(c)

	G.Mk = t.NewMkLines("Makefile", MkRcsID)
	global := G.Pkgsrc.Tools.Define("tool", "TOOL", dummyMkLine)
	local := G.Mk.Tools.Define("tool", "TOOL", dummyMkLine)

	global.Validity = Nowhere
	local.Validity = AtRunTime

	loadTimeTool, loadTimeUsable := G.Tool("tool", LoadTime)
	runTimeTool, runTimeUsable := G.Tool("tool", RunTime)

	c.Check(loadTimeTool, equals, local)
	c.Check(loadTimeUsable, equals, false)
	c.Check(runTimeTool, equals, local)
	c.Check(runTimeUsable, equals, true)
}

func (s *Suite) Test_Pkglint_Tool__lookup_by_name_fallback(c *check.C) {
	t := s.Init(c)

	G.Mk = t.NewMkLines("Makefile", MkRcsID)
	global := G.Pkgsrc.Tools.Define("tool", "TOOL", dummyMkLine)

	global.Validity = Nowhere

	loadTimeTool, loadTimeUsable := G.Tool("tool", LoadTime)
	runTimeTool, runTimeUsable := G.Tool("tool", RunTime)

	c.Check(*loadTimeTool, equals, *global)
	c.Check(loadTimeUsable, equals, false)
	c.Check(*runTimeTool, equals, *global)
	c.Check(runTimeUsable, equals, false)
}

func (s *Suite) Test_Pkglint_Tool__lookup_by_varname(c *check.C) {
	t := s.Init(c)

	G.Mk = t.NewMkLines("Makefile", MkRcsID)
	global := G.Pkgsrc.Tools.Define("tool", "TOOL", dummyMkLine)
	local := G.Mk.Tools.Define("tool", "TOOL", dummyMkLine)

	global.Validity = Nowhere
	local.Validity = AtRunTime

	loadTimeTool, loadTimeUsable := G.Tool("${TOOL}", LoadTime)
	runTimeTool, runTimeUsable := G.Tool("${TOOL}", RunTime)

	c.Check(loadTimeTool, equals, local)
	c.Check(loadTimeUsable, equals, false)
	c.Check(runTimeTool, equals, local)
	c.Check(runTimeUsable, equals, true)
}

func (s *Suite) Test_Pkglint_Tool__lookup_by_varname_fallback(c *check.C) {
	t := s.Init(c)

	G.Mk = t.NewMkLines("Makefile", MkRcsID)
	G.Pkgsrc.Tools.def("tool", "TOOL", false, Nowhere)

	loadTimeTool, loadTimeUsable := G.Tool("${TOOL}", LoadTime)
	runTimeTool, runTimeUsable := G.Tool("${TOOL}", RunTime)

	c.Check(loadTimeTool.String(), equals, "tool:TOOL::Nowhere")
	c.Check(loadTimeUsable, equals, false)
	c.Check(runTimeTool.String(), equals, "tool:TOOL::Nowhere")
	c.Check(runTimeUsable, equals, false)
}

func (s *Suite) Test_Pkglint_Tool__lookup_by_varname_fallback_runtime(c *check.C) {
	t := s.Init(c)

	G.Mk = t.NewMkLines("Makefile", MkRcsID)
	G.Pkgsrc.Tools.def("tool", "TOOL", false, AtRunTime)

	loadTimeTool, loadTimeUsable := G.Tool("${TOOL}", LoadTime)
	runTimeTool, runTimeUsable := G.Tool("${TOOL}", RunTime)

	c.Check(loadTimeTool.String(), equals, "tool:TOOL::AtRunTime")
	c.Check(loadTimeUsable, equals, false)
	c.Check(runTimeTool.String(), equals, "tool:TOOL::AtRunTime")
	c.Check(runTimeUsable, equals, true)
}

func (s *Suite) Test_Pkglint_ToolByVarname__prefer_mk_over_pkgsrc(c *check.C) {
	t := s.Init(c)

	G.Mk = t.NewMkLines("Makefile", MkRcsID)
	global := G.Pkgsrc.Tools.Define("tool", "TOOL", dummyMkLine)
	local := G.Mk.Tools.Define("tool", "TOOL", dummyMkLine)

	global.Validity = Nowhere
	local.Validity = AtRunTime

	c.Check(G.ToolByVarname("TOOL", LoadTime), equals, local)
	c.Check(G.ToolByVarname("TOOL", RunTime), equals, local)
}

func (s *Suite) Test_Pkglint_ToolByVarname(c *check.C) {
	t := s.Init(c)

	G.Mk = t.NewMkLines("Makefile", MkRcsID)
	G.Pkgsrc.Tools.def("tool", "TOOL", false, AtRunTime)

	c.Check(G.ToolByVarname("TOOL", LoadTime).String(), equals, "tool:TOOL::AtRunTime")
	c.Check(G.ToolByVarname("TOOL", RunTime).String(), equals, "tool:TOOL::AtRunTime")
}

func (s *Suite) Test_CheckfileExtra(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Call", "-Wall,no-space")
	pkg := t.SetupPackage("category/package")
	t.CreateFileLines("category/package/INSTALL",
		"#! /bin/sh")
	t.CreateFileLines("category/package/DEINSTALL",
		"#! /bin/sh")

	G.CheckDirent(pkg)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Pkglint_Checkfile__before_import(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Call", "-Wall,no-space", "--import")
	pkg := t.SetupPackage("category/package")
	t.CreateFileLines("category/package/work/log")
	t.CreateFileLines("category/package/Makefile~")
	t.CreateFileLines("category/package/Makefile.orig")
	t.CreateFileLines("category/package/Makefile.rej")

	G.CheckDirent(pkg)

	t.CheckOutputLines(
		"ERROR: ~/category/package/Makefile.orig: Must be cleaned up before committing the package.",
		"ERROR: ~/category/package/Makefile.rej: Must be cleaned up before committing the package.",
		"ERROR: ~/category/package/Makefile~: Must be cleaned up before committing the package.",
		"ERROR: ~/category/package/work: Must be cleaned up before committing the package.")
}

func (s *Suite) Test_Pkglint_Checkfile__errors(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Call", "-Wall,no-space")
	t.SetupPkgsrc()
	t.CreateFileLines("category/package/files/subdir/file")
	t.CreateFileLines("category/package/files/subdir/subsub/file")
	G.Pkgsrc.LoadInfrastructure()

	G.Checkfile(t.File("category/package/options.mk"))
	G.Checkfile(t.File("category/package/files/subdir"))
	G.Checkfile(t.File("category/package/files/subdir/subsub"))
	G.Checkfile(t.File("category/package/files"))

	c.Check(t.Output(), check.Matches, `^`+
		`ERROR: ~/category/package/options.mk: Cannot determine file type: .*\n`+
		`WARN: ~/category/package/files/subdir/subsub: Unknown directory name\.\n`+
		`$`)
}

func (s *Suite) Test_Pkglint_Checkfile__file_selection(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Call", "-Wall,no-space")
	t.SetupPkgsrc()
	t.CreateFileLines("doc/CHANGES-2018",
		RcsID)
	t.CreateFileLines("category/package/buildlink3.mk",
		MkRcsID)
	t.CreateFileLines("category/package/unexpected.txt",
		RcsID)
	G.Pkgsrc.LoadInfrastructure()

	G.Checkfile(t.File("doc/CHANGES-2018"))
	G.Checkfile(t.File("category/package/buildlink3.mk"))
	G.Checkfile(t.File("category/package/unexpected.txt"))

	t.CheckOutputLines(
		"WARN: ~/category/package/buildlink3.mk:EOF: Expected a BUILDLINK_TREE line.",
		"WARN: ~/category/package/unexpected.txt: Unexpected file found.")
}

func (s *Suite) Test_Pkglint_Checkfile__readme_and_todo(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("category/Makefile",
		MkRcsID)

	t.CreateFileLines("category/package/files/README",
		"Extra file that is installed later.")
	t.CreateFileLines("category/package/patches/patch-README",
		RcsID,
		"",
		"Documentation",
		"",
		"--- old",
		"+++ new",
		"@@ -1,1 +1,1 @@",
		"-old",
		"+new")
	t.CreateFileLines("category/package/Makefile",
		MkRcsID,
		"CATEGORIES=category",
		"",
		"COMMENT=Comment",
		"LICENSE=2-clause-bsd")
	t.CreateFileLines("category/package/PLIST",
		PlistRcsID,
		"bin/program")
	t.CreateFileLines("category/package/README",
		"This package ...")
	t.CreateFileLines("category/package/TODO",
		"Make this package work.")
	t.CreateFileLines("category/package/distinfo",
		RcsID,
		"",
		"SHA1 (patch-README) = b9101ebf0bca8ce243ed6433b65555fa6a5ecd52")

	// Copy category/package/** to wip/package.
	for _, basename := range []string{"files/README", "patches/patch-README", "Makefile", "PLIST", "README", "TODO", "distinfo"} {
		src := "category/package/" + basename
		dst := "wip/package/" + basename
		text, err := ioutil.ReadFile(t.File(src))
		c.Check(err, check.IsNil)
		t.CreateFileLines(dst, strings.TrimSuffix(string(text), "\n"))
	}

	t.SetupPkgsrc()
	G.Pkgsrc.LoadInfrastructure()
	t.Chdir(".")

	G.Main("pkglint", "category/package", "wip/package")

	t.CheckOutputLines(
		"ERROR: category/package/README: Packages in main pkgsrc must not have a README file.",
		"ERROR: category/package/TODO: Packages in main pkgsrc must not have a TODO file.",
		"2 errors and 0 warnings found.")

	// FIXME: Do this resetting properly
	G.errors = 0
	G.warnings = 0
	G.logged = make(map[string]bool)
	G.Main("pkglint", "--import", "category/package", "wip/package")

	t.CheckOutputLines(
		"ERROR: category/package/README: Packages in main pkgsrc must not have a README file.",
		"ERROR: category/package/TODO: Packages in main pkgsrc must not have a TODO file.",
		"ERROR: wip/package/README: Must be cleaned up before committing the package.",
		"ERROR: wip/package/TODO: Must be cleaned up before committing the package.",
		"4 errors and 0 warnings found.")
}

func (s *Suite) Test_Pkglint_Checkfile__unknown_file_in_patches(c *check.C) {
	t := s.Init(c)

	t.CreateFileDummyPatch("category/Makefile/patches/index")

	G.Checkfile(t.File("category/Makefile/patches/index"))

	t.CheckOutputLines(
		"WARN: ~/category/Makefile/patches/index: " +
			"Patch files should be named \"patch-\", followed by letters, '-', '_', '.', and digits only.")
}

func (s *Suite) Test_Pkglint_Checkfile__file_in_files(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("category/package/files/index")

	G.Checkfile(t.File("category/package/files/index"))

	// These files are ignored since they could contain anything.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Pkglint_Checkfile__spec(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("category/package/spec")
	t.CreateFileLines("regress/package/spec")

	G.Checkfile(t.File("category/package/spec"))
	G.Checkfile(t.File("regress/package/spec"))

	t.CheckOutputLines(
		"WARN: ~/category/package/spec: Only packages in regress/ may have spec files.")
}

func (s *Suite) Test_Pkglint_checkMode__skipped(c *check.C) {
	t := s.Init(c)

	G.checkMode("work", os.ModeSymlink)
	G.checkMode("work.i386", os.ModeSymlink)
	G.checkMode("work.hostname", os.ModeSymlink)
	G.checkMode("other", os.ModeSymlink)

	G.checkMode("device", os.ModeDevice)

	t.CheckOutputLines(
		"WARN: other: Unknown symlink name.",
		"ERROR: device: Only files and directories are allowed in pkgsrc.")
}

func (s *Suite) Test_Pkglint_checkdirPackage(c *check.C) {
	t := s.Init(c)

	t.Chdir("category/package")
	t.CreateFileLines("Makefile",
		MkRcsID)

	G.checkdirPackage(".")

	t.CheckOutputLines(
		"WARN: Makefile: Neither PLIST nor PLIST.common exist, and PLIST_SRC is unset.",
		"WARN: distinfo: File not found. Please run \""+confMake+" makesum\" or define NO_CHECKSUM=yes in the package Makefile.",
		"ERROR: Makefile: Each package must define its LICENSE.",
		"WARN: Makefile: No COMMENT given.")
}

func (s *Suite) Test_Pkglint_checkdirPackage__PKGDIR(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	t.SetupPkgsrc()
	t.CreateFileLines("category/Makefile")
	t.CreateFileLines("other/package/Makefile",
		MkRcsID)
	t.CreateFileLines("other/package/PLIST",
		PlistRcsID,
		"bin/program")
	t.CreateFileLines("other/package/distinfo",
		RcsID,
		"",
		"SHA1 (patch-aa) = da39a3ee5e6b4b0d3255bfef95601890afd80709")
	t.CreateFileLines("category/package/patches/patch-aa",
		RcsID)
	t.Chdir("category/package")
	t.CreateFileLines("Makefile",
		MkRcsID,
		"",
		"CATEGORIES=\tcategory",
		"",
		"COMMENT=\tComment",
		"LICENSE=\t2-clause-bsd",
		"PKGDIR=\t\t../../other/package")

	// DISTINFO_FILE is resolved relative to PKGDIR, the other places
	// are resolved relative to the package base directory.
	G.checkdirPackage(".")

	t.CheckOutputLines(
		"ERROR: patches/patch-aa:1: Patch files must not be empty.")
}

func (s *Suite) Test_Pkglint_checkdirPackage__patch_without_distinfo(c *check.C) {
	t := s.Init(c)

	pkg := t.SetupPackage("category/package")
	t.CreateFileDummyPatch("category/package/patches/patch-aa")
	t.Remove("category/package/distinfo")

	G.CheckDirent(pkg)

	// FIXME: One of the below warnings is redundant.
	t.CheckOutputLines(
		"WARN: ~/category/package/distinfo: File not found. Please run \""+confMake+" makesum\" or define NO_CHECKSUM=yes in the package Makefile.",
		"WARN: ~/category/package/distinfo: File not found. Please run \""+confMake+" makepatchsum\".")
}

func (s *Suite) Test_Pkglint_checkdirPackage__meta_package_without_license(c *check.C) {
	t := s.Init(c)

	t.Chdir("category/package")
	t.CreateFileLines("Makefile",
		MkRcsID,
		"",
		"META_PACKAGE=\tyes")
	t.SetupVartypes()

	G.checkdirPackage(".")

	t.CheckOutputLines(
		"WARN: Makefile: No COMMENT given.") // No error about missing LICENSE.
}

func (s *Suite) Test_Pkglint_checkdirPackage__filename_with_variable(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall,no-order")
	pkg := t.SetupPackage("category/package",
		".include \"../../mk/bsd.prefs.mk\"",
		"",
		"RUBY_VERSIONS_ACCEPTED=\t22 23 24 25", // As of 2018.
		".for rv in ${RUBY_VERSIONS_ACCEPTED}",
		"RUBY_VER?=\t\t${rv}",
		".endfor",
		"",
		"RUBY_PKGDIR=\t../../lang/ruby-${RUBY_VER}-base",
		"DISTINFO_FILE=\t${RUBY_PKGDIR}/distinfo")

	// Pkglint cannot currently resolve the location of DISTINFO_FILE completely
	// because the variable \"rv\" comes from a .for loop.
	//
	// TODO: iterate over variables in simple .for loops like the above.
	G.CheckDirent(pkg)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Pkglint_checkdirPackage__ALTERNATIVES(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall,no-space")
	pkg := t.SetupPackage("category/package")
	t.CreateFileLines("category/package/ALTERNATIVES",
		"bin/wrapper bin/wrapper-impl")

	G.CheckDirent(pkg)

	t.CheckOutputLines(
		"ERROR: ~/category/package/ALTERNATIVES:1: " +
			"Alternative implementation \"bin/wrapper-impl\" must appear in the PLIST.")
}

func (s *Suite) Test_Pkglint_ShowSummary__explanations_with_only(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--only", "interesting")
	line := t.NewLine("Makefile", 27, "The old song")

	line.Warnf("Filtered warning.")               // Is not logged.
	Explain("Explanation for the above warning.") // Neither would this explanation be logged.
	G.ShowSummary()

	c.Check(G.explanationsAvailable, equals, false)
	t.CheckOutputLines(
		"Looks fine.") // "pkglint -e" is not advertised since the above explanation is not relevant.

	line.Warnf("What an interesting line.")
	Explain("This explanation is available.")
	G.ShowSummary()

	c.Check(G.explanationsAvailable, equals, true)
	t.CheckOutputLines(
		"WARN: Makefile:27: What an interesting line.",
		"0 errors and 1 warning found.",
		"(Run \"pkglint -e\" to show explanations.)")
}

func (s *Suite) Test_CheckfileMk__enoent(c *check.C) {
	t := s.Init(c)

	CheckfileMk(t.File("fileName.mk"))

	t.CheckOutputLines(
		"ERROR: ~/fileName.mk: Cannot be read.")
}

func (s *Suite) Test_Pkglint_checkExecutable(c *check.C) {
	t := s.Init(c)

	fileName := t.File("file.mk")
	fileInfo := ExecutableFileInfo{path.Base(fileName)}

	G.checkExecutable(fileName, fileInfo)

	t.CheckOutputLines(
		"WARN: ~/file.mk: Should not be executable.")

	t.SetupCommandLine("--autofix")

	G.checkExecutable(fileName, fileInfo)

	// FIXME: The error message "Cannot clear executable bits" is swallowed.
	t.CheckOutputLines(
		"AUTOFIX: ~/file.mk: Clearing executable bits")
}

func (s *Suite) Test_Pkglint_checkExecutable__already_committed(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("CVS/Entries",
		"/file.mk/modified////")
	fileName := t.File("file.mk")
	fileInfo := ExecutableFileInfo{path.Base(fileName)}

	G.checkExecutable(fileName, fileInfo)

	// See the "Too late" comment in Pkglint.checkExecutable.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_main(c *check.C) {
	t := s.Init(c)

	out, err := os.Create(t.CreateFileLines("out"))
	c.Check(err, check.IsNil)

	pkg := t.SetupPackage("category/package")

	func() {
		args := os.Args
		stdout := os.Stdout
		stderr := os.Stderr
		prevExit := exit
		defer func() {
			os.Stderr = stderr
			os.Stdout = stdout
			os.Args = args
			exit = prevExit
		}()
		os.Args = []string{"pkglint", pkg}
		os.Stdout = out
		os.Stderr = out
		exit = func(code int) {
			c.Check(code, equals, 0)
		}

		main()
	}()

	err = out.Close()
	c.Check(err, check.IsNil)

	t.CheckOutputEmpty()
	t.CheckFileLines("out",
		"Looks fine.")
}

// ExecutableFileInfo mocks a FileInfo because on Windows,
// regular files don't have the executable bit.
type ExecutableFileInfo struct {
	name string
}

func (i ExecutableFileInfo) Name() string       { return i.name }
func (i ExecutableFileInfo) Size() int64        { return 13 }
func (i ExecutableFileInfo) Mode() os.FileMode  { return 0777 }
func (i ExecutableFileInfo) ModTime() time.Time { return time.Unix(0, 0) }
func (i ExecutableFileInfo) IsDir() bool        { return false }
func (i ExecutableFileInfo) Sys() interface{}   { return nil }
