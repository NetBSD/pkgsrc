package histogram_test

import (
	"gopkg.in/check.v1"
	"netbsd.org/pkglint/histogram"
	"strings"
	"testing"
)

type Suite struct{}

var _ = check.Suite(new(Suite))

func Test(t *testing.T) { check.TestingT(t) }

func (s *Suite) Test_Histogram(c *check.C) {
	hgr := histogram.New()
	hgr.Add("one", 1)
	hgr.Add("two", 2)
	hgr.Add("three", 3)

	var out strings.Builder
	hgr.PrintStats(&out, "caption", 2)

	c.Check(out.String(), check.Equals, ""+
		"caption      3 three\n"+
		"caption      2 two\n")
}
