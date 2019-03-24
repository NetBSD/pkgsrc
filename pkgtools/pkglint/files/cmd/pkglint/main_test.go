package main

import (
	"io/ioutil"
	"os"
	"testing"

	"gopkg.in/check.v1"
)

type Suite struct{}

func Test(t *testing.T) {
	check.Suite(new(Suite))
	check.TestingT(t)
}

// This test goes into great lengths to bring the code coverage to 100%.
// Without this test, the main function would be a trivial one-liner.
// To make that one-liner testable, the call to os.Exit must be mockable.
func (s *Suite) Test_main(c *check.C) {
	tmpdir := c.MkDir()
	out, err := os.Create(tmpdir + "/out")
	c.Assert(err, check.IsNil)

	prevStdout := os.Stdout
	prevArgs := os.Args
	prevExit := exit
	defer func() {
		os.Stdout = prevStdout
		os.Args = prevArgs
		exit = prevExit
	}()

	os.Stdout = out
	os.Args = []string{"pkglint", "--version"}
	exit = func(code int) { c.Check(code, check.Equals, 0) }

	main()

	err = out.Close()
	c.Assert(err, check.IsNil)

	output, err := ioutil.ReadFile(out.Name())
	c.Assert(err, check.IsNil)

	c.Check(string(output), check.Matches, `^(@VERSION@|\d+(\.\d+)+(nb\d+)?)\n$`)
}
