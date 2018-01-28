package main

import (
	"strings"

	"gopkg.in/check.v1"
	"netbsd.org/pkglint/trace"
	"os"
)

func (s *Suite) Test_Pkglint_Main_help(c *check.C) {
	t := s.Init(c)

	exitcode := new(Pkglint).Main("pkglint", "-h")

	c.Check(exitcode, equals, 0)
	c.Check(t.Output(), check.Matches, `^\Qusage: pkglint [options] dir...\E\n(?s).+`)
}

func (s *Suite) Test_Pkglint_Main_version(c *check.C) {
	t := s.Init(c)

	exitcode := new(Pkglint).Main("pkglint", "--version")

	c.Check(exitcode, equals, 0)
	t.CheckOutputLines(
		confVersion)
}

func (s *Suite) Test_Pkglint_Main_no_args(c *check.C) {
	t := s.Init(c)

	exitcode := new(Pkglint).Main("pkglint")

	c.Check(exitcode, equals, 1)
	t.CheckOutputLines(
		"FATAL: \".\" is not inside a pkgsrc tree.")
}

func (s *Suite) Test_Pkglint_Main__only(c *check.C) {
	t := s.Init(c)

	exitcode := new(Pkglint).ParseCommandLine([]string{"pkglint", "-Wall", "-o", ":Q", "--version"})

	c.Check(exitcode, deepEquals, new(int))
	c.Check(G.opts.LogOnly, deepEquals, []string{":Q"})
	t.CheckOutputLines(
		"@VERSION@")
}

// go test -c -covermode count
// pkgsrcdir=...
// env PKGLINT_TESTCMDLINE="$pkgsrcdir -r" ./pkglint.test -test.coverprofile pkglint.cov
// go tool cover -html=pkglint.cov -o coverage.html
func (s *Suite) Test_Pkglint_coverage(c *check.C) {
	cmdline := os.Getenv("PKGLINT_TESTCMDLINE")
	if cmdline != "" {
		G.logOut, G.logErr, trace.Out = NewSeparatorWriter(os.Stdout), NewSeparatorWriter(os.Stderr), os.Stdout
		new(Pkglint).Main(append([]string{"pkglint"}, splitOnSpace(cmdline)...)...)
	}
}

func (s *Suite) Test_Pkglint_CheckDirent__outside(c *check.C) {
	t := s.Init(c)

	t.SetupFileLines("empty")

	new(Pkglint).CheckDirent(t.TmpDir())

	t.CheckOutputLines(
		"ERROR: ~: Cannot determine the pkgsrc root directory for \"~\".")
}

func (s *Suite) Test_Pkglint_CheckDirent(c *check.C) {
	t := s.Init(c)

	t.SetupFileLines("mk/bsd.pkg.mk")
	t.SetupFileLines("category/package/Makefile")
	t.SetupFileLines("category/Makefile")
	t.SetupFileLines("Makefile")
	G.globalData.Pkgsrcdir = t.TmpDir()
	pkglint := new(Pkglint)

	pkglint.CheckDirent(t.TmpDir())

	t.CheckOutputLines(
		"ERROR: ~/Makefile: Must not be empty.")

	pkglint.CheckDirent(t.TempFilename("category"))

	t.CheckOutputLines(
		"ERROR: ~/category/Makefile: Must not be empty.")

	pkglint.CheckDirent(t.TempFilename("category/package"))

	t.CheckOutputLines(
		"ERROR: ~/category/package/Makefile: Must not be empty.")

	pkglint.CheckDirent(t.TempFilename("category/package/nonexistent"))

	t.CheckOutputLines(
		"ERROR: ~/category/package/nonexistent: No such file or directory.")
}

func (s *Suite) Test_resolveVariableRefs__circular_reference(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("fname", 1, "GCC_VERSION=${GCC_VERSION}")
	G.Pkg = NewPackage(".")
	G.Pkg.vardef["GCC_VERSION"] = mkline

	resolved := resolveVariableRefs("gcc-${GCC_VERSION}")

	c.Check(resolved, equals, "gcc-${GCC_VERSION}")
}

func (s *Suite) Test_resolveVariableRefs__multilevel(c *check.C) {
	t := s.Init(c)

	mkline1 := t.NewMkLine("fname", 10, "_=${SECOND}")
	mkline2 := t.NewMkLine("fname", 11, "_=${THIRD}")
	mkline3 := t.NewMkLine("fname", 12, "_=got it")
	G.Pkg = NewPackage(".")
	defineVar(mkline1, "FIRST")
	defineVar(mkline2, "SECOND")
	defineVar(mkline3, "THIRD")

	resolved := resolveVariableRefs("you ${FIRST}")

	c.Check(resolved, equals, "you got it")
}

func (s *Suite) Test_resolveVariableRefs__special_chars(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("fname", 10, "_=x11")
	G.Pkg = NewPackage("category/pkg")
	G.Pkg.vardef["GST_PLUGINS0.10_TYPE"] = mkline

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
		"AUTOFIX: ~/MESSAGE:1: Inserting a line \"===================================="+
			"=======================================\" before this line.",
		"AUTOFIX: ~/MESSAGE:1: Inserting a line \"$NetBSD: pkglint_test.go,v 1.14 2018/01/28 23:21:16 rillig Exp $\" before this line.",
		"AUTOFIX: ~/MESSAGE:5: Inserting a line \"===================================="+
			"=======================================\" after this line.")
	t.CheckFileLines("MESSAGE",
		"===========================================================================",
		"$NetBSD: pkglint_test.go,v 1.14 2018/01/28 23:21:16 rillig Exp $",
		"1",
		"2",
		"3",
		"4",
		"5",
		"===========================================================================")
}

func (s *Suite) Test_GlobalData_Latest(c *check.C) {
	t := s.Init(c)

	G.globalData.Pkgsrcdir = t.TmpDir()

	latest1 := G.globalData.Latest("lang", `^python[0-9]+$`, "../../lang/$0")

	c.Check(latest1, equals, "")
	t.CheckOutputLines(
		"ERROR: Cannot find latest version of \"^python[0-9]+$\" in \"~\".")

	t.SetupFileLines("lang/Makefile")
	G.globalData.latest = nil

	latest2 := G.globalData.Latest("lang", `^python[0-9]+$`, "../../lang/$0")

	c.Check(latest2, equals, "")
	t.CheckOutputLines(
		"ERROR: Cannot find latest version of \"^python[0-9]+$\" in \"~\".")

	t.SetupFileLines("lang/python27/Makefile")
	G.globalData.latest = nil

	latest3 := G.globalData.Latest("lang", `^python[0-9]+$`, "../../lang/$0")

	c.Check(latest3, equals, "../../lang/python27")
	t.CheckOutputEmpty()

	t.SetupFileLines("lang/python35/Makefile")
	G.globalData.latest = nil

	latest4 := G.globalData.Latest("lang", `^python[0-9]+$`, "../../lang/$0")

	c.Check(latest4, equals, "../../lang/python35")
	t.CheckOutputEmpty()
}
