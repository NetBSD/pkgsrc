package main

import (
	"strings"

	"gopkg.in/check.v1"
	"netbsd.org/pkglint/trace"
	"os"
)

func (s *Suite) Test_Pkglint_Main_help(c *check.C) {
	t := s.Init(c)

	exitcode := G.Main("pkglint", "-h")

	c.Check(exitcode, equals, 0)
	c.Check(t.Output(), check.Matches, `^\Qusage: pkglint [options] dir...\E\n(?s).+`)
}

func (s *Suite) Test_Pkglint_Main_version(c *check.C) {
	t := s.Init(c)

	exitcode := G.Main("pkglint", "--version")

	c.Check(exitcode, equals, 0)
	t.CheckOutputLines(
		confVersion)
}

func (s *Suite) Test_Pkglint_Main_no_args(c *check.C) {
	t := s.Init(c)

	exitcode := G.Main("pkglint")

	c.Check(exitcode, equals, 1)
	t.CheckOutputLines(
		"FATAL: \".\" is not inside a pkgsrc tree.")
}

func (s *Suite) Test_Pkglint_Main__only(c *check.C) {
	t := s.Init(c)

	exitcode := G.ParseCommandLine([]string{"pkglint", "-Wall", "-o", ":Q", "--version"})

	if c.Check(exitcode, check.NotNil) {
		c.Check(*exitcode, equals, 0)
	}
	c.Check(G.opts.LogOnly, deepEquals, []string{":Q"})
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
		"  -F, --autofix               try to automatically fix some errors (experimental)",
		"  -g, --gcc-output-format     mimic the gcc output format",
		"  -h, --help                  print a detailed usage message",
		"  -I, --dumpmakefile          dump the Makefile after parsing",
		"  -i, --import                prepare the import of a wip package",
		"  -m, --log-verbose           allow the same log message more than once",
		"  -o, --only                  only log messages containing the given text",
		"  -p, --profiling             profile the executing program",
		"  -q, --quiet                 don't print a summary line when finishing",
		"  -r, --recursive             check subdirectories, too",
		"  -s, --source                show the source lines together with diagnostics",
		"  -V, --version               print the version number of pkglint",
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

// Demonstrates which infrastructure files are necessary to actually run
// pkglint in a realistic scenario.
// For most tests, this setup is too much work, therefore they
// initialize only those parts of the infrastructure they really
// need.
//
// Especially covers Pkglint.PrintSummary and Pkglint.Checkfile.
func (s *Suite) Test_Pkglint_Main__complete_package(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()

	// FIXME: pkglint should warn that the latest version in this file
	// (1.10) doesn't match the current version in the package (1.11).
	t.SetupFileLines("doc/CHANGES-2018",
		RcsID,
		"",
		"Changes to the packages collection and infrastructure in 2018:",
		"",
		"\tUpdated sysutils/checkperms to 1.10 [rillig 2018-01-05]")

	// See Pkgsrc.loadSuggestedUpdates.
	t.SetupFileLines("doc/TODO",
		RcsID,
		"",
		"Suggested package updates",
		"",
		"\to checkperms-1.13 [supports more file formats]")

	// The LICENSE in the package Makefile is searched here.
	t.SetupFileLines("licenses/bsd-2",
		"# dummy")

	// The MASTER_SITES in the package Makefile are searched here.
	// See Pkgsrc.loadMasterSites.
	t.SetupFileMkLines("mk/fetch/sites.mk",
		MkRcsID,
		"",
		"MASTER_SITE_GITHUB+=\thttps://github.com/")

	// The existence of this file makes the category "sysutils" valid.
	// The category "tools" on the other hand is not valid.
	t.SetupFileMkLines("sysutils/Makefile",
		MkRcsID)

	// The package Makefile is quite simple, containing just the
	// standard variable definitions. The data for checking the variable
	// values is partly defined in the pkgsrc infrastructure files
	// (as defined in the previous lines), and partly in the pkglint
	// code directly. Many details can be found in vartypecheck.go.
	t.SetupFileMkLines("sysutils/checkperms/Makefile",
		MkRcsID,
		"",
		"DISTNAME=\tcheckperms-1.11",
		"CATEGORIES=\tsysutils tools",
		"MASTER_SITES=\t${MASTER_SITE_GITHUB:=rillig/}",
		"",
		"MAINTAINER=\tpkgsrc-users@pkgsrc.org",
		"HOMEPAGE=\thttps://github.com/rillig/checkperms/",
		"COMMENT=\tCheck file permissions",
		"LICENSE=\tbsd-2",
		"",
		".include \"../../mk/bsd.pkg.mk\"")

	t.SetupFileLines("sysutils/checkperms/MESSAGE",
		"===========================================================================",
		RcsID,
		"",
		"After installation, this package has to be configured in a special way.",
		"",
		"===========================================================================")

	t.SetupFileLines("sysutils/checkperms/PLIST",
		PlistRcsID,
		"bin/checkperms",
		"man/man1/checkperms.1")

	t.SetupFileLines("sysutils/checkperms/README",
		"When updating this package, test the pkgsrc bootstrap.")

	t.SetupFileLines("sysutils/checkperms/TODO",
		"Make the package work on MS-DOS")

	t.SetupFileLines("sysutils/checkperms/patches/patch-checkperms.c",
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
	t.SetupFileLines("sysutils/checkperms/distinfo",
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
		"ERROR: ~/sysutils/checkperms/distinfo:7: SHA1 hash of patches/patch-checkperms.c differs "+
			"(distinfo has asdfasdf, patch file has e775969de639ec703866c0336c4c8e0fdd96309c). "+
			"Run \""+confMake+" makepatchsum\".",
		"WARN: ~/sysutils/checkperms/patches/patch-checkperms.c:12: Premature end of patch hunk "+
			"(expected 1 lines to be deleted and 0 lines to be added).",
		"2 errors and 2 warnings found.",
		"(Run \"pkglint -e\" to show explanations.)",
		"(Run \"pkglint -fs\" to show what can be fixed automatically.)",
		"(Run \"pkglint -F\" to automatically fix some issues.)")
}

// go test -c -covermode count
// pkgsrcdir=...
// env PKGLINT_TESTCMDLINE="$pkgsrcdir -r" ./pkglint.test -test.coverprofile pkglint.cov
// go tool cover -html=pkglint.cov -o coverage.html
func (s *Suite) Test_Pkglint_coverage(c *check.C) {
	cmdline := os.Getenv("PKGLINT_TESTCMDLINE")
	if cmdline != "" {
		G.logOut, G.logErr, trace.Out = NewSeparatorWriter(os.Stdout), NewSeparatorWriter(os.Stderr), os.Stdout
		G.Main(append([]string{"pkglint"}, splitOnSpace(cmdline)...)...)
	}
}

func (s *Suite) Test_Pkglint_CheckDirent__outside(c *check.C) {
	t := s.Init(c)

	t.SetupFileLines("empty")

	G.CheckDirent(t.File("."))

	t.CheckOutputLines(
		"ERROR: ~: Cannot determine the pkgsrc root directory for \"~\".")
}

func (s *Suite) Test_Pkglint_CheckDirent(c *check.C) {
	t := s.Init(c)

	t.SetupFileLines("mk/bsd.pkg.mk")
	t.SetupFileLines("category/package/Makefile")
	t.SetupFileLines("category/Makefile")
	t.SetupFileLines("Makefile")

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

	mkline := t.NewMkLine("fname", 1, "GCC_VERSION=${GCC_VERSION}")
	G.Pkg = NewPackage(t.File("category/pkgbase"))
	G.Pkg.vars.Define("GCC_VERSION", mkline)

	resolved := resolveVariableRefs("gcc-${GCC_VERSION}")

	c.Check(resolved, equals, "gcc-${GCC_VERSION}")
}

func (s *Suite) Test_resolveVariableRefs__multilevel(c *check.C) {
	t := s.Init(c)

	mkline1 := t.NewMkLine("fname", 10, "_=${SECOND}")
	mkline2 := t.NewMkLine("fname", 11, "_=${THIRD}")
	mkline3 := t.NewMkLine("fname", 12, "_=got it")
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

	mkline := t.NewMkLine("fname", 10, "_=x11")
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

func (s *Suite) Test_Pkgsrc_Latest_no_basedir(c *check.C) {
	t := s.Init(c)

	latest := G.Pkgsrc.Latest("lang", `^python[0-9]+$`, "../../lang/$0")

	c.Check(latest, equals, "")
	t.CheckOutputLines(
		"ERROR: Cannot find latest version of \"^python[0-9]+$\" in \"~/lang\".")
}

func (s *Suite) Test_Pkgsrc_Latest_no_subdirs(c *check.C) {
	t := s.Init(c)

	t.SetupFileLines("lang/Makefile")

	latest := G.Pkgsrc.Latest("lang", `^python[0-9]+$`, "../../lang/$0")

	c.Check(latest, equals, "")
	t.CheckOutputLines(
		"ERROR: Cannot find latest version of \"^python[0-9]+$\" in \"~/lang\".")
}

func (s *Suite) Test_Pkgsrc_Latest_single(c *check.C) {
	t := s.Init(c)

	t.SetupFileLines("lang/Makefile")
	t.SetupFileLines("lang/python27/Makefile")

	latest := G.Pkgsrc.Latest("lang", `^python[0-9]+$`, "../../lang/$0")

	c.Check(latest, equals, "../../lang/python27")
}

func (s *Suite) Test_Pkgsrc_Latest_multi(c *check.C) {
	t := s.Init(c)

	t.SetupFileLines("lang/Makefile")
	t.SetupFileLines("lang/python27/Makefile")
	t.SetupFileLines("lang/python35/Makefile")

	latest := G.Pkgsrc.Latest("lang", `^python[0-9]+$`, "../../lang/$0")

	c.Check(latest, equals, "../../lang/python35")
}

func (s *Suite) Test_Pkgsrc_Latest_numeric(c *check.C) {
	t := s.Init(c)

	t.SetupFileLines("databases/postgresql95/Makefile")
	t.SetupFileLines("databases/postgresql97/Makefile")
	t.SetupFileLines("databases/postgresql100/Makefile")
	t.SetupFileLines("databases/postgresql104/Makefile")

	latest := G.Pkgsrc.Latest("databases", `^postgresql[0-9]+$`, "$0")

	c.Check(latest, equals, "postgresql104")
}

// Demonstrates that an ALTERNATIVES file can be tested individually,
// without any dependencies on a whole package or a PLIST file.
func (s *Suite) Test_Pkglint_Checkfile__alternatives(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()
	lines := t.SetupFileLines("category/package/ALTERNATIVES",
		"bin/tar @PREFIX@/bin/gnu-tar")

	G.Main("pkglint", lines[0].Filename)

	t.CheckOutputLines(
		"NOTE: ~/category/package/ALTERNATIVES:1: @PREFIX@/ can be omitted from the file name.",
		"Looks fine.",
		"(Run \"pkglint -e\" to show explanations.)")
}

func (s *Suite) Test_Pkglint__profiling(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()
	G.Main("pkglint", "--profiling", t.File("."))

	// Pkglint always writes the profiling data into the current directory.
	// Luckily, this directory is usually writable.
	c.Check(fileExists("pkglint.pprof"), equals, true)

	err := os.Remove("pkglint.pprof")
	c.Check(err, check.IsNil)

	// Everything but the first few lines of output is not easily testable
	// or not interesting enough, since that info includes the exact timing
	// that the top time-consuming regular expressions took.
	firstOutput := strings.Split(t.Output(), "\n")[0]
	c.Check(firstOutput, equals, "ERROR: ~/Makefile: Cannot be read.")
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
