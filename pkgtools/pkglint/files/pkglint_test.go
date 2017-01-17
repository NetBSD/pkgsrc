package main

import (
	"strings"

	check "gopkg.in/check.v1"
	"netbsd.org/pkglint/trace"
	"os"
)

func (s *Suite) Test_Pkglint_Main_help(c *check.C) {
	exitcode := new(Pkglint).Main("pkglint", "-h")

	c.Check(exitcode, equals, 0)
	c.Check(s.Output(), check.Matches, `^\Qusage: pkglint [options] dir...\E\n(?s).+`)
}

func (s *Suite) Test_Pkglint_Main_version(c *check.C) {
	exitcode := new(Pkglint).Main("pkglint", "--version")

	c.Check(exitcode, equals, 0)
	c.Check(s.Output(), equals, confVersion+"\n")
}

func (s *Suite) Test_Pkglint_Main_no_args(c *check.C) {
	exitcode := new(Pkglint).Main("pkglint")

	c.Check(exitcode, equals, 1)
	c.Check(s.Stderr(), equals, "FATAL: \".\" is not inside a pkgsrc tree.\n")
}

// go test -c -covermode count
// pkgsrcdir=...
// env PKGLINT_TESTCMDLINE="$pkgsrcdir -r" ./pkglint.test -test.coverprofile pkglint.cov
// go tool cover -html=pkglint.cov -o coverage.html
func (s *Suite) Test_Pkglint_coverage(c *check.C) {
	cmdline := os.Getenv("PKGLINT_TESTCMDLINE")
	if cmdline != "" {
		G.logOut, G.logErr, trace.Out = os.Stdout, os.Stderr, os.Stdout
		new(Pkglint).Main(append([]string{"pkglint"}, splitOnSpace(cmdline)...)...)
	}
}

func (s *Suite) Test_Pkglint_CheckDirent__outside(c *check.C) {
	s.Init(c)
	s.CreateTmpFile("empty", "")

	new(Pkglint).CheckDirent(s.tmpdir)

	c.Check(s.Output(), equals, "ERROR: ~: Cannot determine the pkgsrc root directory for \"~\".\n")
}

func (s *Suite) Test_Pkglint_CheckDirent(c *check.C) {
	s.Init(c)
	s.CreateTmpFile("mk/bsd.pkg.mk", "")
	s.CreateTmpFile("category/package/Makefile", "")
	s.CreateTmpFile("category/Makefile", "")
	s.CreateTmpFile("Makefile", "")
	G.globalData.Pkgsrcdir = s.tmpdir
	pkglint := new(Pkglint)

	pkglint.CheckDirent(s.tmpdir)

	c.Check(s.Output(), equals, "ERROR: ~/Makefile: Must not be empty.\n")

	pkglint.CheckDirent(s.tmpdir + "/category")

	c.Check(s.Output(), equals, "ERROR: ~/category/Makefile: Must not be empty.\n")

	pkglint.CheckDirent(s.tmpdir + "/category/package")

	c.Check(s.Output(), equals, "ERROR: ~/category/package/Makefile: Must not be empty.\n")

	pkglint.CheckDirent(s.tmpdir + "/category/package/nonexistent")

	c.Check(s.Output(), equals, "ERROR: ~/category/package/nonexistent: No such file or directory.\n")
}

func (s *Suite) Test_resolveVariableRefs__circular_reference(c *check.C) {
	mkline := NewMkLine(NewLine("fname", 1, "GCC_VERSION=${GCC_VERSION}", nil))
	G.Pkg = NewPackage(".")
	G.Pkg.vardef["GCC_VERSION"] = mkline

	resolved := resolveVariableRefs("gcc-${GCC_VERSION}")

	c.Check(resolved, equals, "gcc-${GCC_VERSION}")
}

func (s *Suite) Test_resolveVariableRefs__multilevel(c *check.C) {
	mkline1 := NewMkLine(NewLine("fname", 10, "_=${SECOND}", nil))
	mkline2 := NewMkLine(NewLine("fname", 11, "_=${THIRD}", nil))
	mkline3 := NewMkLine(NewLine("fname", 12, "_=got it", nil))
	G.Pkg = NewPackage(".")
	defineVar(mkline1, "FIRST")
	defineVar(mkline2, "SECOND")
	defineVar(mkline3, "THIRD")

	resolved := resolveVariableRefs("you ${FIRST}")

	c.Check(resolved, equals, "you got it")
}

func (s *Suite) Test_resolveVariableRefs__special_chars(c *check.C) {
	mkline := NewMkLine(NewLine("fname", 10, "_=x11", nil))
	G.Pkg = NewPackage("category/pkg")
	G.Pkg.vardef["GST_PLUGINS0.10_TYPE"] = mkline

	resolved := resolveVariableRefs("gst-plugins0.10-${GST_PLUGINS0.10_TYPE}/distinfo")

	c.Check(resolved, equals, "gst-plugins0.10-x11/distinfo")
}

func (s *Suite) Test_ChecklinesDescr(c *check.C) {
	lines := s.NewLines("DESCR",
		strings.Repeat("X", 90),
		"", "", "", "", "", "", "", "", "10",
		"Try ${PREFIX}",
		"", "", "", "", "", "", "", "", "20",
		"", "", "", "", "", "", "", "", "", "30")

	ChecklinesDescr(lines)

	c.Check(s.Output(), equals, ""+
		"WARN: DESCR:1: Line too long (should be no more than 80 characters).\n"+
		"NOTE: DESCR:11: Variables are not expanded in the DESCR file.\n"+
		"WARN: DESCR:25: File too long (should be no more than 24 lines).\n")
}

func (s *Suite) Test_ChecklinesMessage__short(c *check.C) {
	lines := s.NewLines("MESSAGE",
		"one line")

	ChecklinesMessage(lines)

	c.Check(s.Output(), equals, "WARN: MESSAGE:1: File too short.\n")
}

func (s *Suite) Test_ChecklinesMessage__malformed(c *check.C) {
	lines := s.NewLines("MESSAGE",
		"1",
		"2",
		"3",
		"4",
		"5")

	ChecklinesMessage(lines)

	c.Check(s.Output(), equals, ""+
		"WARN: MESSAGE:1: Expected a line of exactly 75 \"=\" characters.\n"+
		"ERROR: MESSAGE:2: Expected \"$"+"NetBSD$\".\n"+
		"WARN: MESSAGE:5: Expected a line of exactly 75 \"=\" characters.\n")
}

func (s *Suite) Test_GlobalData_Latest(c *check.C) {
	s.Init(c)
	G.globalData.Pkgsrcdir = s.TmpDir()

	latest1 := G.globalData.Latest("lang", `^python[0-9]+$`, "../../lang/$0")

	c.Check(latest1, equals, "")
	c.Check(s.Output(), equals, "ERROR: Cannot find latest version of \"^python[0-9]+$\" in \"~\".\n")

	s.CreateTmpFile("lang/Makefile", "")
	G.globalData.latest = nil

	latest2 := G.globalData.Latest("lang", `^python[0-9]+$`, "../../lang/$0")

	c.Check(latest2, equals, "")
	c.Check(s.Output(), equals, "ERROR: Cannot find latest version of \"^python[0-9]+$\" in \"~\".\n")

	s.CreateTmpFile("lang/python27/Makefile", "")
	G.globalData.latest = nil

	latest3 := G.globalData.Latest("lang", `^python[0-9]+$`, "../../lang/$0")

	c.Check(latest3, equals, "../../lang/python27")
	c.Check(s.Output(), equals, "")

	s.CreateTmpFile("lang/python35/Makefile", "")
	G.globalData.latest = nil

	latest4 := G.globalData.Latest("lang", `^python[0-9]+$`, "../../lang/$0")

	c.Check(latest4, equals, "../../lang/python35")
	c.Check(s.Output(), equals, "")
}
