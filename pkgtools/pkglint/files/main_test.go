package main

import (
	"os"

	check "gopkg.in/check.v1"
)

func (s *Suite) TestMainHelp(c *check.C) {
	exitcode := new(Pkglint).Main("pkglint", "-h")

	c.Check(exitcode, equals, 0)
	c.Check(s.Output(), check.Matches, `^\Qusage: pkglint [options] dir...\E\n(?s).+`)
}

func (s *Suite) TestMainVersion(c *check.C) {
	exitcode := new(Pkglint).Main("pkglint", "--version")

	c.Check(exitcode, equals, 0)
	c.Check(s.Output(), equals, confVersion+"\n")
}

func (s *Suite) TestMainNoArgs(c *check.C) {
	exitcode := new(Pkglint).Main("pkglint")

	c.Check(exitcode, equals, 1)
	c.Check(s.Stderr(), equals, "FATAL: \".\" is not inside a pkgsrc tree.\n")
}

// go test -c -covermode count
// pkgsrcdir=...
// env PKGLINT_TESTCMDLINE="$pkgsrcdir -r" ./pkglint.test -test.coverprofile pkglint.cov -check.f TestRunPkglint
// go tool cover -html=pkglint.cov -o coverage.html
func (s *Suite) TestRunPkglint(c *check.C) {
	cmdline := os.Getenv("PKGLINT_TESTCMDLINE")
	if cmdline != "" {
		G.logOut, G.logErr, G.debugOut = os.Stdout, os.Stderr, os.Stdout
		new(Pkglint).Main(append([]string{"pkglint"}, splitOnSpace(cmdline)...)...)
	}
}
