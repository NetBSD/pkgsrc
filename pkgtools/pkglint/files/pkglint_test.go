package pkglint

import (
	"gopkg.in/check.v1"
	"io/ioutil"
	"os"
	"path"
	"path/filepath"
	"strings"
)

func (pkglint *Pkglint) usable() bool { return pkglint.fileCache != nil }

func (s *Suite) Test_Pkglint_Main__help(c *check.C) {
	t := s.Init(c)

	exitCode := t.Main("-h")

	c.Check(exitCode, equals, 0)
	t.CheckOutputLines(
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
		"  -m, --log-verbose           allow the same diagnostic more than once",
		"  -o, --only                  only log diagnostics containing the given text",
		"  -p, --profiling             profile the executing program",
		"  -q, --quiet                 don't show a summary line when finishing",
		"  -r, --recursive             check subdirectories, too",
		"  -s, --source                show the source lines together with diagnostics",
		"  -V, --version               show the version number of pkglint",
		"  -W, --warning=warning,...   enable or disable groups of warnings",
		"",
		"  Flags for -C, --check:",
		"    all      all of the following",
		"    none     none of the following",
		"    global   inter-package checks (disabled)",
		"",
		"  Flags for -W, --warning:",
		"    all       all of the following",
		"    none      none of the following",
		"    extra     enable some extra warnings (disabled)",
		"    perm      warn about unforeseen variable definition and use (disabled)",
		"    quoting   warn about quoting issues (disabled)",
		"    space     warn about inconsistent use of whitespace (disabled)",
		"    style     warn about stylistic issues (disabled)",
		"",
		"  (Prefix a flag with \"no-\" to disable it.)")
}

func (s *Suite) Test_Pkglint_Main__version(c *check.C) {
	t := s.Init(c)

	exitcode := t.Main("--version")

	c.Check(exitcode, equals, 0)
	t.CheckOutputLines(
		confVersion)
}

func (s *Suite) Test_Pkglint_Main__no_args(c *check.C) {
	t := s.Init(c)

	exitcode := t.Main()

	// The "." from the error message is the implicit argument added in Pkglint.Main.
	c.Check(exitcode, equals, 1)
	t.CheckOutputLines(
		"FATAL: \".\" must be inside a pkgsrc tree.")
}

func (s *Suite) Test_Pkglint_ParseCommandLine__only(c *check.C) {
	t := s.Init(c)

	exitcode := G.ParseCommandLine([]string{"pkglint", "-Wall", "--only", ":Q", "--version"})

	if exitcode != -1 {
		c.Check(exitcode, equals, 0)
	}
	c.Check(G.Opts.LogOnly, deepEquals, []string{":Q"})
	t.CheckOutputLines(
		confVersion)
}

func (s *Suite) Test_Pkglint_Main__unknown_option(c *check.C) {
	t := s.Init(c)

	exitcode := t.Main("--unknown-option")

	c.Check(exitcode, equals, 1)
	c.Check(t.Output(), check.Matches,
		`\Qpkglint: unknown option: --unknown-option\E\n`+
			`\Q\E\n`+
			`\Qusage: pkglint [options] dir...\E\n`+
			`(?s).+`)
	// See Test_Pkglint_Main__help for the complete output.
}

// Demonstrates which infrastructure files are necessary to actually run
// pkglint in a realistic scenario.
//
// Especially covers Pkglint.ShowSummary and Pkglint.checkReg.
func (s *Suite) Test_Pkglint_Main__complete_package(c *check.C) {
	t := s.Init(c)

	// Since the general infrastructure setup is useful for several tests,
	// it is available as a separate method.
	//
	// In this test, several of the infrastructure files are later
	// overwritten with more realistic and interesting content.
	// This is typical of the pkglint tests.
	t.SetUpPkgsrc()

	t.CreateFileLines("doc/CHANGES-2018",
		CvsID,
		"",
		"Changes to the packages collection and infrastructure in 2018:",
		"",
		"\tUpdated sysutils/checkperms to 1.10 [rillig 2018-01-05]")

	// See Pkgsrc.loadSuggestedUpdates.
	t.CreateFileLines("doc/TODO",
		CvsID,
		"",
		"Suggested package updates",
		"",
		"\to checkperms-1.13 [supports more file formats]")

	// The MASTER_SITES in the package Makefile are searched here.
	// See Pkgsrc.loadMasterSites.
	t.CreateFileLines("mk/fetch/sites.mk",
		MkCvsID,
		"",
		"MASTER_SITE_GITHUB+=\thttps://github.com/")

	// After setting up the pkgsrc infrastructure, the files for
	// a complete pkgsrc package are created individually.
	//
	// In this test each file is created manually for demonstration purposes.
	// Other tests typically call t.SetUpPackage, which does most of the work
	// shown here while allowing to adjust the package Makefile a little bit.

	// The existence of this file makes the category "sysutils" valid,
	// so that it can be used in CATEGORIES in the package Makefile.
	// The category "tools" on the other hand is not valid.
	t.CreateFileLines("sysutils/Makefile",
		MkCvsID)

	// The package Makefile in this test is quite simple, containing just the
	// standard variable definitions. The data for checking the variable
	// values is partly defined in the pkgsrc infrastructure files
	// (as defined in the previous lines), and partly in the pkglint
	// code directly. Many details can be found in vartypecheck.go.
	t.CreateFileLines("sysutils/checkperms/Makefile",
		MkCvsID,
		"",
		"DISTNAME=\tcheckperms-1.11",
		"CATEGORIES=\tsysutils tools",
		"MASTER_SITES=\t${MASTER_SITE_GITHUB:=rillig/}",
		"",
		"MAINTAINER=\tpkgsrc-users@NetBSD.org",
		"HOMEPAGE=\thttps://github.com/rillig/checkperms/",
		"COMMENT=\tCheck file permissions",
		"LICENSE=\t2-clause-bsd",
		"",
		".include \"../../mk/bsd.pkg.mk\"")

	t.CreateFileLines("sysutils/checkperms/MESSAGE",
		"===========================================================================",
		CvsID,
		"",
		"After installation, this package has to be configured in a special way.",
		"",
		"===========================================================================")

	t.CreateFileLines("sysutils/checkperms/PLIST",
		PlistCvsID,
		"bin/checkperms",
		"man/man1/checkperms.1")

	t.CreateFileLines("sysutils/checkperms/README",
		"When updating this package, test the pkgsrc bootstrap.")

	t.CreateFileLines("sysutils/checkperms/TODO",
		"Make the package work on MS-DOS")

	t.CreateFileLines("sysutils/checkperms/patches/patch-checkperms.c",
		CvsID,
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
		CvsID,
		"",
		"SHA1 (checkperms-1.12.tar.gz) = 34c084b4d06bcd7a8bba922ff57677e651eeced5",
		"RMD160 (checkperms-1.12.tar.gz) = cd95029aa930b6201e9580b3ab7e36dd30b8f925",
		"SHA512 (checkperms-1.12.tar.gz) = "+
			"43e37b5963c63fdf716acdb470928d7e21a7bdfddd6c85cf626a11acc7f45fa5"+
			"2a53d4bcd83d543150328fe8cec5587987d2d9a7c5f0aaeb02ac1127ab41f8ae",
		"Size (checkperms-1.12.tar.gz) = 6621 bytes",
		"SHA1 (patch-checkperms.c) = asdfasdf") // Invalid SHA-1 checksum

	t.Main("-Wall", "-Call", t.File("sysutils/checkperms"))

	t.CheckOutputLines(
		"NOTE: ~/sysutils/checkperms/Makefile:3: "+
			"Package version \"1.11\" is greater than the latest \"1.10\" "+
			"from ../../doc/CHANGES-2018:5.",
		"WARN: ~/sysutils/checkperms/Makefile:3: "+
			"This package should be updated to 1.13 ([supports more file formats]).",
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

func (s *Suite) Test_Pkglint_Main__autofix_exitcode(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("filename.mk",
		"")

	exitcode := t.Main("-Wall", "--autofix", t.File("filename.mk"))

	t.CheckOutputLines(
		"AUTOFIX: ~/filename.mk:1: Inserting a line \"" + MkCvsID + "\" before this line.")
	t.Check(exitcode, equals, 0)
}

// Run pkglint in a realistic environment.
//
//  env \
//  PKGLINT_TESTDIR="..." \
//  PKGLINT_TESTCMDLINE="-r" \
//  go test -covermode=count -test.coverprofile pkglint.cov
//
//  go tool cover -html=pkglint.cov -o coverage.html
//
// To measure the branch coverage of pkglint checking a complete pkgsrc installation,
// install https://github.com/rillig/gobco and adjust the following code:
//
//  env \
//  PKGLINT_TESTDIR=C:/Users/rillig/git/pkgsrc \
//  PKGLINT_TESTCMDLINE="-r -Wall -Call -e" \
//  gobco -test.covermode=count \
//      -test.coverprofile=pkglint-pkgsrc.pprof \
//      -timeout=3600s -check.f '^Test_Pkglint__realistic' \
//      > pkglint-pkgsrc.out
//
// See https://github.com/rillig/gobco for the tool to measure the branch coverage.
func (s *Suite) Test_Pkglint__realistic(c *check.C) {
	if cwd := os.Getenv("PKGLINT_TESTDIR"); cwd != "" {
		err := os.Chdir(cwd)
		c.Assert(err, check.IsNil)
	}

	cmdline := os.Getenv("PKGLINT_TESTCMDLINE")
	if cmdline != "" {
		G.Main(os.Stdout, os.Stderr, append([]string{"pkglint"}, strings.Fields(cmdline)...))
	}
}

func (s *Suite) Test_Pkglint_Check__outside(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("empty")

	G.Check(t.File("."))

	// In a realistic scenario, pkglint will only reach this point
	// when the first command line argument is valid but a following
	// argument is outside the pkgsrc tree.
	//
	// If the first argument is already outside of any pkgsrc tree,
	// pkglint will exit with a fatal error message since it doesn't
	// know where to load the infrastructure files from.
	t.CheckOutputLines(
		"ERROR: ~: Cannot determine the pkgsrc root directory for \"~\".")
}

func (s *Suite) Test_Pkglint_Check__empty_directory(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("category/package/CVS/Entries")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	// Empty directories are silently skipped.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Pkglint_Check__files_directory(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("category/package/files/README.md")
	t.FinishSetUp()

	G.Check(t.File("category/package/files"))

	// This diagnostic is not really correct, but it's an edge case anyway.
	t.CheckOutputLines(
		"ERROR: ~/category/package/files: Cannot check directories outside a pkgsrc tree.")
}

func (s *Suite) Test_Pkglint_Check__patches_directory(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileDummyPatch("category/package/patches/patch-README.md")
	t.FinishSetUp()

	G.Check(t.File("category/package/patches"))

	// This diagnostic is not really correct, but it's an edge case anyway.
	t.CheckOutputLines(
		"ERROR: ~/category/package/patches: Cannot check directories outside a pkgsrc tree.")
}

// See devel/libtool for an example package that uses manual patches.
func (s *Suite) Test_Pkglint_Check__manual_patch(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileLines("category/package/patches/unknown-file")
	t.CreateFileLines("category/package/patches/manual-configure")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	// Pkglint doesn't inspect the manual patch files, it also doesn't mark them as unknown files.
	t.CheckOutputLines(
		"WARN: ~/category/package/patches/unknown-file: Patch files should be named \"patch-\", " +
			"followed by letters, '-', '_', '.', and digits only.")
}

func (s *Suite) Test_Pkglint_Check__doc_TODO(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.FinishSetUp()

	G.Check(G.Pkgsrc.File("doc/TODO"))

	// The file doc/TODO cannot be checked explicitly and individually.
	// It is loaded as part of the pkgsrc infrastructure and is thus
	// checked implicitly whenever a package or an individual file is checked.
	t.CheckOutputLines(
		"WARN: ~/doc/TODO: Unexpected file found.")
}

// This test covers the different code paths for deciding whether a directory
// should be checked as the top-level, a category or a package.
func (s *Suite) Test_Pkglint_Check(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.CreateFileLines("mk/misc/category.mk")
	t.CreateFileLines("mk/bsd.pkg.mk")
	t.CreateFileLines("category/package/Makefile")
	t.CreateFileLines("category/Makefile",
		MkCvsID,
		"",
		"COMMENT=\tCategory\u0007",
		"",
		"SUBDIR+=\tpackage",
		"",
		".include \"../mk/misc/category.mk\"")
	t.CreateFileLines("Makefile",
		MkCvsID,
		"COMMENT=\tToplevel\u0005")

	G.Check(t.File("."))

	t.CheckOutputLines(
		"WARN: ~/Makefile:2: Line contains invalid characters (U+0005).")

	G.Check(t.File("category"))

	t.CheckOutputLines(
		"WARN: ~/category/Makefile:3: Line contains invalid characters (U+0007).",
		"WARN: ~/category/Makefile:3: COMMENT contains invalid characters (U+0007).")

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"ERROR: ~/category/package/Makefile: Must not be empty.")

	G.Check(t.File("category/package/nonexistent"))

	t.CheckOutputLines(
		"ERROR: ~/category/package/nonexistent: No such file or directory.")
}

func (s *Suite) Test_Pkglint_checkMode__neither_file_nor_directory(c *check.C) {
	t := s.Init(c)

	G.checkMode("/dev/null", os.ModeDevice)

	t.CheckOutputLines(
		"ERROR: /dev/null: No such file or directory.")
}

// Pkglint must never be trapped in an endless loop, even when
// resolving the value of a variable that refers back to itself.
func (s *Suite) Test_resolveVariableRefs__circular_reference(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("filename.mk", 1, "VAR=\t1:${VAR}+ 2:${VAR}")
	G.Pkg = NewPackage(t.File("category/pkgbase"))
	G.Pkg.vars.Define("VAR", mkline)

	// TODO: It may be better to define MkLines.Resolve and Package.Resolve,
	//  to clearly state the scope of the involved variables.
	resolved := resolveVariableRefs(nil, "the a:${VAR} b:${VAR}")

	// TODO: The ${VAR} after "b:" should also be expanded since there
	//  is no recursion.
	c.Check(resolved, equals, "the a:1:${VAR}+ 2:${VAR} b:${VAR}")
}

func (s *Suite) Test_resolveVariableRefs__multilevel(c *check.C) {
	t := s.Init(c)

	mkline1 := t.NewMkLine("filename.mk", 10, "FIRST=\t${SECOND}")
	mkline2 := t.NewMkLine("filename.mk", 11, "SECOND=\t${THIRD}")
	mkline3 := t.NewMkLine("filename.mk", 12, "THIRD=\tgot it")
	G.Pkg = NewPackage(t.File("category/pkgbase"))
	G.Pkg.vars.Define("FIRST", mkline1)
	G.Pkg.vars.Define("SECOND", mkline2)
	G.Pkg.vars.Define("THIRD", mkline3)

	// TODO: Add a similar test in which some of the variables are defined
	//  conditionally or with differing values, just to see what pkglint does
	//  in such a case.
	resolved := resolveVariableRefs(nil, "you ${FIRST}")

	c.Check(resolved, equals, "you got it")
}

// Usually, a dot in a variable name means a parameterized form.
// In this case, it is part of a version number. Resolving these
// variables from the scope works nevertheless.
func (s *Suite) Test_resolveVariableRefs__special_chars(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("filename.mk", 10, "_=x11")
	G.Pkg = NewPackage(t.File("category/pkg"))
	G.Pkg.vars.Define("GST_PLUGINS0.10_TYPE", mkline)

	resolved := resolveVariableRefs(nil, "gst-plugins0.10-${GST_PLUGINS0.10_TYPE}/distinfo")

	c.Check(resolved, equals, "gst-plugins0.10-x11/distinfo")
}

func (s *Suite) Test_CheckLinesDescr(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	lines := t.NewLines("DESCR",
		"word "+strings.Repeat("X", 80),
		strings.Repeat("X", 90), // No warning since there are no spaces.
		"", "", "", "", "", "", "", "10",
		"Try ${PREFIX}",
		"", "", "", "", "", "", "", "", "20",
		"... expressions like ${key} to ... ${unfinished",
		"", "", "", "", "", "", "", "", "30")

	CheckLinesDescr(lines)

	// The package author may think that variables like ${PREFIX}
	// are expanded in DESCR files too, but that doesn't happen.
	//
	// Variables that are not well-known in pkgsrc are not warned
	// about since these are probably legitimate examples, as seen
	// in devel/go-properties/DESCR.
	t.CheckOutputLines(
		"WARN: DESCR:1: Line too long (should be no more than 80 characters).",
		"NOTE: DESCR:11: Variables are not expanded in the DESCR file.",
		"WARN: DESCR:25: File too long (should be no more than 24 lines).")
}

func (s *Suite) Test_CheckLinesMessage__one_line_of_text(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("MESSAGE",
		"one line")

	CheckLinesMessage(lines)

	t.CheckOutputLines(
		"WARN: MESSAGE:1: File too short.")
}

func (s *Suite) Test_CheckLinesMessage__one_hline(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("MESSAGE",
		strings.Repeat("=", 75))

	CheckLinesMessage(lines)

	t.CheckOutputLines(
		"WARN: MESSAGE:1: File too short.")
}

func (s *Suite) Test_CheckLinesMessage__malformed(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("MESSAGE",
		"1",
		"2",
		"3",
		"4",
		"5")

	CheckLinesMessage(lines)

	t.CheckOutputLines(
		"WARN: MESSAGE:1: Expected a line of exactly 75 \"=\" characters.",
		"ERROR: MESSAGE:1: Expected \"$"+"NetBSD$\".",
		"WARN: MESSAGE:5: Expected a line of exactly 75 \"=\" characters.")
}

func (s *Suite) Test_CheckLinesMessage__autofix(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--autofix")
	lines := t.SetUpFileLines("MESSAGE",
		"1",
		"2",
		"3",
		"4",
		"5")

	CheckLinesMessage(lines)

	t.CheckOutputLines(
		"AUTOFIX: ~/MESSAGE:1: Inserting a line \"=============================="+
			"=============================================\" before this line.",
		"AUTOFIX: ~/MESSAGE:1: Inserting a line \"$"+"NetBSD$\" before this line.",
		"AUTOFIX: ~/MESSAGE:5: Inserting a line \"=============================="+
			"=============================================\" after this line.")
	t.CheckFileLines("MESSAGE",
		"===========================================================================",
		CvsID,
		"1",
		"2",
		"3",
		"4",
		"5",
		"===========================================================================")
}

func (s *Suite) Test_CheckLinesMessage__common(c *check.C) {
	t := s.Init(c)

	hline := strings.Repeat("=", 75)
	t.SetUpPackage("category/package",
		"MESSAGE_SRC=\t../../category/package/MESSAGE.common",
		"MESSAGE_SRC+=\t${.CURDIR}/MESSAGE")
	t.CreateFileLines("category/package/MESSAGE.common",
		hline,
		CvsID,
		"common line")
	t.CreateFileLines("category/package/MESSAGE",
		hline)

	t.Main("category/package")

	t.CheckOutputLines(
		"Looks fine.")
}

// Demonstrates that an ALTERNATIVES file can be tested individually,
// without any dependencies on a whole package or a PLIST file.
func (s *Suite) Test_Pkglint_checkReg__alternatives(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	lines := t.SetUpFileLines("category/package/ALTERNATIVES",
		"bin/tar bin/gnu-tar")

	t.Main(lines.Filename)

	t.CheckOutputLines(
		"ERROR: ~/category/package/ALTERNATIVES:1: Alternative implementation \"bin/gnu-tar\" must be an absolute path.",
		"1 error and 0 warnings found.",
		"(Run \"pkglint -e\" to show explanations.)")
}

// Just for branch coverage.
func (s *Suite) Test_Pkglint_checkReg__file_not_found(c *check.C) {
	t := s.Init(c)

	t.Chdir(".")

	G.checkReg("buildlink3.mk", "buildlink3.mk", 2)
	G.checkReg("DESCR", "DESCR", 2)
	G.checkReg("distinfo", "distinfo", 2)
	G.checkReg("MESSAGE", "MESSAGE", 2)
	G.checkReg("patches/patch-aa", "patch-aa", 2)
	G.checkReg("PLIST", "PLIST", 2)

	t.CheckOutputLines(
		"ERROR: buildlink3.mk: Cannot be read.",
		"ERROR: DESCR: Cannot be read.",
		"ERROR: distinfo: Cannot be read.",
		"ERROR: MESSAGE: Cannot be read.",
		"ERROR: patches/patch-aa: Cannot be read.",
		"ERROR: PLIST: Cannot be read.")
}

// Just for branch coverage.
func (s *Suite) Test_Pkglint_checkReg__no_tracing(c *check.C) {
	t := s.Init(c)

	t.Chdir(".")
	t.DisableTracing()

	G.checkReg("patches/manual-aa", "manual-aa", 2)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Pkglint__profiling(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.Chdir(".")

	t.Main("--profiling")

	// Pkglint always writes the profiling data into the current directory.
	// TODO: Make the location of the profiling log a mandatory parameter.
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

	t.Chdir(".")
	t.CreateFileLines("pkglint.pprof/file")

	exitcode := t.Main("--profiling")

	c.Check(exitcode, equals, 1)
	t.CheckOutputMatches(
		`FATAL: Cannot create profiling file: open pkglint\.pprof: .*`)
}

func (s *Suite) Test_Pkglint_checkReg__in_current_working_directory(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.Chdir("category/package")
	t.CreateFileLines("log")

	t.Main()

	t.CheckOutputLines(
		"WARN: log: Unexpected file found.",
		"0 errors and 1 warning found.")
}

func (s *Suite) Test_Pkglint_Tool__prefer_mk_over_pkgsrc(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("dummy.mk", 123, "DUMMY=\tvalue")
	mklines := t.NewMkLines("Makefile", MkCvsID)
	global := G.Pkgsrc.Tools.Define("tool", "TOOL", mkline)
	local := mklines.Tools.Define("tool", "TOOL", mkline)

	global.Validity = Nowhere
	local.Validity = AtRunTime

	loadTimeTool, loadTimeUsable := G.Tool(mklines, "tool", LoadTime)
	runTimeTool, runTimeUsable := G.Tool(mklines, "tool", RunTime)

	c.Check(loadTimeTool, equals, local)
	c.Check(loadTimeUsable, equals, false)
	c.Check(runTimeTool, equals, local)
	c.Check(runTimeUsable, equals, true)
}

func (s *Suite) Test_Pkglint_Tool__lookup_by_name_fallback(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("Makefile", MkCvsID)
	t.SetUpTool("tool", "", Nowhere)

	loadTimeTool, loadTimeUsable := G.Tool(mklines, "tool", LoadTime)
	runTimeTool, runTimeUsable := G.Tool(mklines, "tool", RunTime)

	// The tool is returned even though it may not be used at the moment.
	// The calling code must explicitly check for usability.

	c.Check(loadTimeTool.String(), equals, "tool:::Nowhere")
	c.Check(loadTimeUsable, equals, false)
	c.Check(runTimeTool.String(), equals, "tool:::Nowhere")
	c.Check(runTimeUsable, equals, false)
}

// TODO: Document the purpose of this test.
func (s *Suite) Test_Pkglint_Tool__lookup_by_varname(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("dummy.mk", 123, "DUMMY=\tvalue")
	mklines := t.NewMkLines("Makefile", MkCvsID)
	global := G.Pkgsrc.Tools.Define("tool", "TOOL", mkline)
	local := mklines.Tools.Define("tool", "TOOL", mkline)

	global.Validity = Nowhere
	local.Validity = AtRunTime

	loadTimeTool, loadTimeUsable := G.Tool(mklines, "${TOOL}", LoadTime)
	runTimeTool, runTimeUsable := G.Tool(mklines, "${TOOL}", RunTime)

	c.Check(loadTimeTool, equals, local)
	c.Check(loadTimeUsable, equals, false)
	c.Check(runTimeTool, equals, local)
	c.Check(runTimeUsable, equals, true)
}

// TODO: Document the purpose of this test.
func (s *Suite) Test_Pkglint_Tool__lookup_by_varname_fallback(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("Makefile", MkCvsID)
	G.Pkgsrc.Tools.def("tool", "TOOL", false, Nowhere, nil)

	loadTimeTool, loadTimeUsable := G.Tool(mklines, "${TOOL}", LoadTime)
	runTimeTool, runTimeUsable := G.Tool(mklines, "${TOOL}", RunTime)

	c.Check(loadTimeTool.String(), equals, "tool:TOOL::Nowhere")
	c.Check(loadTimeUsable, equals, false)
	c.Check(runTimeTool.String(), equals, "tool:TOOL::Nowhere")
	c.Check(runTimeUsable, equals, false)
}

// TODO: Document the purpose of this test.
func (s *Suite) Test_Pkglint_Tool__lookup_by_varname_fallback_runtime(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("Makefile", MkCvsID)
	G.Pkgsrc.Tools.def("tool", "TOOL", false, AtRunTime, nil)

	loadTimeTool, loadTimeUsable := G.Tool(mklines, "${TOOL}", LoadTime)
	runTimeTool, runTimeUsable := G.Tool(mklines, "${TOOL}", RunTime)

	c.Check(loadTimeTool.String(), equals, "tool:TOOL::AtRunTime")
	c.Check(loadTimeUsable, equals, false)
	c.Check(runTimeTool.String(), equals, "tool:TOOL::AtRunTime")
	c.Check(runTimeUsable, equals, true)
}

func (s *Suite) Test_Pkglint_ToolByVarname__prefer_mk_over_pkgsrc(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("dummy.mk", 123, "DUMMY=\tvalue")
	mklines := t.NewMkLines("Makefile", MkCvsID)
	global := G.Pkgsrc.Tools.Define("tool", "TOOL", mkline)
	local := mklines.Tools.Define("tool", "TOOL", mkline)

	global.Validity = Nowhere
	local.Validity = AtRunTime

	c.Check(G.ToolByVarname(mklines, "TOOL"), equals, local)
}

func (s *Suite) Test_Pkglint_ToolByVarname(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("Makefile", MkCvsID)
	G.Pkgsrc.Tools.def("tool", "TOOL", false, AtRunTime, nil)

	c.Check(G.ToolByVarname(mklines, "TOOL").String(), equals, "tool:TOOL::AtRunTime")
}

func (s *Suite) Test_Pkglint_checkReg__other(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Call", "-Wall,no-space")
	pkg := t.SetUpPackage("category/package")
	t.CreateFileLines("category/package/INSTALL",
		"#! /bin/sh")
	t.CreateFileLines("category/package/DEINSTALL",
		"#! /bin/sh")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Pkglint_Check__invalid_files_before_import(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Call", "-Wall,no-space", "--import")
	pkg := t.SetUpPackage("category/package")
	t.CreateFileLines("category/package/work/log")
	t.CreateFileLines("category/package/Makefile~")
	t.CreateFileLines("category/package/Makefile.orig")
	t.CreateFileLines("category/package/Makefile.rej")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputLines(
		"ERROR: ~/category/package/Makefile.orig: Must be cleaned up before committing the package.",
		"ERROR: ~/category/package/Makefile.rej: Must be cleaned up before committing the package.",
		"ERROR: ~/category/package/Makefile~: Must be cleaned up before committing the package.",
		"ERROR: ~/category/package/work: Must be cleaned up before committing the package.")
}

func (s *Suite) Test_Pkglint_checkReg__readme_and_todo(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("category/Makefile",
		MkCvsID)

	t.CreateFileLines("category/package/files/README",
		"Extra file that is installed later.")
	t.CreateFileDummyPatch("category/package/patches/patch-README")
	t.CreateFileLines("category/package/Makefile",
		MkCvsID,
		"CATEGORIES=category",
		"",
		"COMMENT=Comment",
		"LICENSE=2-clause-bsd")
	t.CreateFileLines("category/package/PLIST",
		PlistCvsID,
		"bin/program")
	t.CreateFileLines("category/package/README",
		"This package ...")
	t.CreateFileLines("category/package/TODO",
		"Make this package work.")
	t.CreateFileLines("category/package/distinfo",
		CvsID,
		"",
		"SHA1 (patch-README) = ebbf34b0641bcb508f17d5a27f2bf2a536d810ac")

	// Copy category/package/** to wip/package.
	err := filepath.Walk(
		t.File("category/package"),
		func(pathname string, info os.FileInfo, err error) error {
			if info.Mode().IsRegular() {
				src := filepath.ToSlash(pathname)
				dst := strings.Replace(src, "category/package", "wip/package", 1)
				text, e := ioutil.ReadFile(src)
				c.Check(e, check.IsNil)
				_ = os.MkdirAll(path.Dir(dst), 0700)
				e = ioutil.WriteFile(dst, []byte(text), 0600)
				c.Check(e, check.IsNil)
			}
			return err
		})
	c.Check(err, check.IsNil)

	t.SetUpPkgsrc()
	t.Chdir(".")

	t.Main("category/package", "wip/package")

	t.CheckOutputLines(
		"ERROR: category/package/README: Packages in main pkgsrc must not have a README file.",
		"ERROR: category/package/TODO: Packages in main pkgsrc must not have a TODO file.",
		"2 errors and 0 warnings found.")

	t.Main("--import", "category/package", "wip/package")

	t.CheckOutputLines(
		"ERROR: category/package/README: Packages in main pkgsrc must not have a README file.",
		"ERROR: category/package/TODO: Packages in main pkgsrc must not have a TODO file.",
		"ERROR: wip/package/README: Must be cleaned up before committing the package.",
		"ERROR: wip/package/TODO: Must be cleaned up before committing the package.",
		"4 errors and 0 warnings found.")
}

func (s *Suite) Test_Pkglint_checkReg__unknown_file_in_patches(c *check.C) {
	t := s.Init(c)

	t.CreateFileDummyPatch("category/Makefile/patches/index")

	G.checkReg(t.File("category/Makefile/patches/index"), "index", 3)

	t.CheckOutputLines(
		"WARN: ~/category/Makefile/patches/index: " +
			"Patch files should be named \"patch-\", followed by letters, '-', '_', '.', and digits only.")
}

func (s *Suite) Test_Pkglint_checkReg__patch_for_Makefile_fragment(c *check.C) {
	t := s.Init(c)

	t.CreateFileDummyPatch("category/package/patches/patch-compiler.mk")
	t.Chdir("category/package")

	G.checkReg(t.File("patches/patch-compiler.mk"), "patch-compiler.mk", 3)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Pkglint_checkReg__file_in_files(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("category/package/files/index")

	G.checkReg(t.File("category/package/files/index"), "index", 3)

	// These files are ignored since they could contain anything.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Pkglint_checkReg__spec(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("category/package/spec")
	t.CreateFileLines("regress/package/spec")

	G.checkReg(t.File("category/package/spec"), "spec", 2)
	G.checkReg(t.File("regress/package/spec"), "spec", 2)

	t.CheckOutputLines(
		"WARN: ~/category/package/spec: Only packages in regress/ may have spec files.")
}

// A package that is very incomplete may produce lots of warnings.
// This case is unrealistic since most packages are either generated by url2pkg
// or copied from an existing working package.
func (s *Suite) Test_Pkglint_checkdirPackage(c *check.C) {
	t := s.Init(c)

	t.Chdir("category/package")
	t.CreateFileLines("Makefile",
		MkCvsID)

	G.checkdirPackage(".")

	t.CheckOutputLines(
		"WARN: Makefile: This package should have a PLIST file.",
		"WARN: distinfo: A package that downloads files should have a distinfo file.",
		"ERROR: Makefile: Each package must define its LICENSE.",
		"WARN: Makefile: Each package should define a COMMENT.")
}

func (s *Suite) Test_Pkglint_checkdirPackage__PKGDIR(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("category/Makefile")
	t.CreateFileLines("other/package/Makefile",
		MkCvsID)
	t.CreateFileLines("other/package/PLIST",
		PlistCvsID,
		"bin/program")
	t.CreateFileLines("other/package/distinfo",
		CvsID,
		"",
		"SHA1 (patch-aa) = da39a3ee5e6b4b0d3255bfef95601890afd80709")
	t.CreateFileLines("category/package/patches/patch-aa",
		CvsID)
	t.Chdir("category/package")
	t.CreateFileLines("Makefile",
		MkCvsID,
		"",
		"CATEGORIES=\tcategory",
		"",
		"COMMENT=\tComment",
		"LICENSE=\t2-clause-bsd",
		"PKGDIR=\t\t../../other/package")
	t.FinishSetUp()

	// DISTINFO_FILE is resolved relative to PKGDIR,
	// the other locations are resolved relative to the package base directory.
	G.checkdirPackage(".")

	t.CheckOutputLines(
		"ERROR: patches/patch-aa:1: Patch files must not be empty.")
}

func (s *Suite) Test_Pkglint_checkdirPackage__patch_without_distinfo(c *check.C) {
	t := s.Init(c)

	pkg := t.SetUpPackage("category/package")
	t.CreateFileDummyPatch("category/package/patches/patch-aa")
	t.Remove("category/package/distinfo")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputLines(
		"WARN: ~/category/package/distinfo: A package that downloads files should have a distinfo file.",
		"WARN: ~/category/package/distinfo: A package with patches should have a distinfo file.")
}

func (s *Suite) Test_Pkglint_checkdirPackage__meta_package_without_license(c *check.C) {
	t := s.Init(c)

	t.Chdir("category/package")
	t.CreateFileLines("Makefile",
		MkCvsID,
		"",
		"META_PACKAGE=\tyes")
	t.SetUpVartypes()

	G.checkdirPackage(".")

	// No error about missing LICENSE since meta-packages don't need a license.
	// They are so simple that there is no reason to have any license.
	t.CheckOutputLines(
		"WARN: Makefile: Each package should define a COMMENT.")
}

func (s *Suite) Test_Pkglint_checkdirPackage__filename_with_variable(c *check.C) {
	t := s.Init(c)

	pkg := t.SetUpPackage("category/package",
		".include \"../../mk/bsd.prefs.mk\"",
		"",
		"RUBY_VERSIONS_ACCEPTED=\t22 23 24 25", // As of 2018.
		".for rv in ${RUBY_VERSIONS_ACCEPTED}",
		"RUBY_VER?=\t\t${rv}",
		".endfor",
		"",
		"RUBY_PKGDIR=\t../../lang/ruby-${RUBY_VER}-base",
		"DISTINFO_FILE=\t${RUBY_PKGDIR}/distinfo")
	t.FinishSetUp()

	// As of January 2019, pkglint cannot resolve the location of DISTINFO_FILE completely
	// because the variable \"rv\" comes from a .for loop.
	//
	// TODO: iterate over variables in simple .for loops like the above.
	// TODO: when implementing the above, take care of deeply nested loops (42.zip).
	G.Check(pkg)

	t.CheckOutputEmpty()

	// Just for code coverage.
	t.DisableTracing()
	G.Check(pkg)
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Pkglint_checkdirPackage__ALTERNATIVES(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall,no-space")
	pkg := t.SetUpPackage("category/package")
	t.CreateFileLines("category/package/ALTERNATIVES",
		"bin/wrapper bin/wrapper-impl")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputLines(
		"ERROR: ~/category/package/ALTERNATIVES:1: "+
			"Alternative implementation \"bin/wrapper-impl\" must appear in the PLIST.",
		"ERROR: ~/category/package/ALTERNATIVES:1: "+
			"Alternative implementation \"bin/wrapper-impl\" must be an absolute path.")
}

func (s *Suite) Test_Pkglint_checkdirPackage__nonexistent_DISTINFO_FILE(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"DISTINFO_FILE=\tnonexistent")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"WARN: ~/category/package/nonexistent: A package that downloads files should have a distinfo file.",
		"ERROR: ~/category/package/Makefile:20: Relative path \"nonexistent\" does not exist.")
}

func (s *Suite) Test_CheckFileMk__enoent(c *check.C) {
	t := s.Init(c)

	CheckFileMk(t.File("filename.mk"))

	t.CheckOutputLines(
		"ERROR: ~/filename.mk: Cannot be read.")
}

// Just for code coverage.
func (s *Suite) Test_CheckFileOther__no_tracing(c *check.C) {
	t := s.Init(c)

	t.DisableTracing()

	CheckFileOther(t.File("filename.mk"))

	t.CheckOutputLines(
		"ERROR: ~/filename.mk: Cannot be read.")
}

func (s *Suite) Test_Pkglint_checkExecutable(c *check.C) {
	t := s.Init(c)

	filename := t.CreateFileLines("file.mk")
	err := os.Chmod(filename, 0555)
	assertNil(err, "")

	G.checkExecutable(filename, 0555)

	t.CheckOutputLines(
		"WARN: ~/file.mk: Should not be executable.")

	t.SetUpCommandLine("--autofix")

	G.checkExecutable(filename, 0555)

	t.CheckOutputMatches(
		"AUTOFIX: ~/file.mk: Clearing executable bits")

	// On Windows, this is effectively a no-op test since there is no
	// execute-bit. The only relevant permissions bit is whether a
	// file is readonly or not.
	st, err := os.Lstat(filename)
	if t.Check(err, check.IsNil) {
		t.Check(st.Mode()&0111, equals, os.FileMode(0))
	}
}

func (s *Suite) Test_Pkglint_checkExecutable__error(c *check.C) {
	t := s.Init(c)

	filename := t.File("file.mk")

	G.checkExecutable(filename, 0555)

	t.CheckOutputLines(
		"WARN: ~/file.mk: Should not be executable.")

	t.SetUpCommandLine("--autofix")

	G.checkExecutable(filename, 0555)

	t.CheckOutputMatches(
		"AUTOFIX: ~/file.mk: Clearing executable bits",
		`ERROR: ~/file.mk: Cannot clear executable bits: chmod ~/file.mk: .*`)
}

func (s *Suite) Test_Pkglint_checkExecutable__already_committed(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("CVS/Entries",
		"/file.mk//modified//")
	filename := t.File("file.mk")

	G.checkExecutable(filename, 0555)

	// See the "Too late" comment in Pkglint.checkExecutable.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Pkglint_Main(c *check.C) {
	t := s.Init(c)

	out, err := os.Create(t.CreateFileLines("out"))
	c.Check(err, check.IsNil)
	outProfiling, err := os.Create(t.CreateFileLines("out.profiling"))
	c.Check(err, check.IsNil)

	t.SetUpPackage("category/package")
	t.Chdir("category/package")
	t.FinishSetUp()

	runMain := func(out *os.File, commandLine ...string) {
		exitCode := G.Main(out, out, commandLine)
		c.Check(exitCode, equals, 0)
	}

	runMain(out, "pkglint", ".")
	runMain(outProfiling, "pkglint", "--profiling", ".")

	c.Check(out.Close(), check.IsNil)
	c.Check(outProfiling.Close(), check.IsNil)

	t.CheckOutputEmpty()          // Because all output is redirected.
	t.CheckFileLines("../../out", // See the t.Chdir above.
		"Looks fine.")
	// outProfiling is not checked because it contains timing information.
}

func (s *Suite) Test_InterPackage_Bl3__same_identifier(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package1",
		"PKGNAME=\t${DISTNAME:@v@${v}@}") // Make the package name non-obvious.
	t.SetUpPackage("category/package2",
		"PKGNAME=\t${DISTNAME:@v@${v}@}") // Make the package name non-obvious.
	t.CreateFileDummyBuildlink3("category/package1/buildlink3.mk")
	t.Copy("category/package1/buildlink3.mk", "category/package2/buildlink3.mk")
	t.Chdir(".")
	t.FinishSetUp()

	G.InterPackage.Enable()
	G.Check("category/package1")
	G.Check("category/package2")

	t.CheckOutputLines(
		"ERROR: category/package2/buildlink3.mk:3: Duplicate package identifier " +
			"\"package1\" already appeared in ../../category/package1/buildlink3.mk:3.")
}

func (s *Suite) Test_Pkglint_loadCvsEntries(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("CVS/Entries",
		"/invalid/",
		"must be silently ignored",
		"/name/revision/timestamp/options/tagdate")

	t.Check(isCommitted(t.File("name")), equals, true)

	t.CheckOutputLines(
		"ERROR: ~/CVS/Entries:1: Invalid line: /invalid/")
}

func (s *Suite) Test_Pkglint_loadCvsEntries__with_Entries_Log(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("CVS/Entries",
		"/invalid/",
		"must be silently ignored",
		"/name//modified//",
		"/removed//modified//")

	t.CreateFileLines("CVS/Entries.Log",
		"A /invalid/",
		"A /added//modified//",
		"must be silently ignored",
		"R /invalid/",
		"R /removed//modified//")

	t.Check(isCommitted(t.File("name")), equals, true)
	t.Check(isCommitted(t.File("added")), equals, true)
	t.Check(isCommitted(t.File("removed")), equals, false)

	t.CheckOutputLines(
		"ERROR: ~/CVS/Entries:1: Invalid line: /invalid/",
		"ERROR: ~/CVS/Entries.Log:1: Invalid line: A /invalid/",
		"ERROR: ~/CVS/Entries.Log:4: Invalid line: R /invalid/")
}
