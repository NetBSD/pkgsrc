package getopt

import (
	check "gopkg.in/check.v1"
	"testing"
)

type Suite struct{}

var _ = check.Suite(new(Suite))

func Test(t *testing.T) { check.TestingT(t) }

func (s *Suite) Test_Options_Parse_short(c *check.C) {
	opts := NewOptions()
	var help bool
	opts.AddFlagVar('h', "help", &help, false, "prints a help page")

	args, err := opts.Parse([]string{"progname", "-h"})

	c.Assert(err, check.IsNil)
	c.Check(args, check.IsNil)
	c.Check(help, check.Equals, true)
}

func (s *Suite) Test_Options_Parse_unknown_short(c *check.C) {
	opts := NewOptions()

	_, err := opts.Parse([]string{"progname", "-z"})

	c.Check(err.Error(), check.Equals, "progname: unknown option: -z")
}

func (s *Suite) Test_Options_Parse_unknown_long(c *check.C) {
	opts := NewOptions()

	_, err := opts.Parse([]string{"progname", "--unknown-long"})

	c.Check(err.Error(), check.Equals, "progname: unknown option: --unknown-long")
}

func (s *Suite) Test_Options_Parse_unknown_flag_in_group(c *check.C) {
	opts := NewOptions()
	opts.AddFlagGroup('W', "warnings", "", "")

	_, err := opts.Parse([]string{"progname", "-Wall", "-Werror"})

	c.Check(err.Error(), check.Equals, "progname: unknown option: -Werror")

	_, err = opts.Parse([]string{"progname", "--warnings=all", "--warnings=no-error"})

	c.Check(err.Error(), check.Equals, "progname: unknown option: --warnings=no-error")

	_, err = opts.Parse([]string{"progname", "-W"})

	c.Check(err.Error(), check.Equals, "progname: option requires an argument: -W")
}

func (s *Suite) Test_Options_Parse_abbreviated_long(c *check.C) {
	opts := NewOptions()
	var longFlag, longerFlag bool
	opts.AddFlagVar('?', "long", &longFlag, false, "")
	opts.AddFlagVar('?', "longer", &longerFlag, false, "")

	_, err := opts.Parse([]string{"progname", "--lo"})

	c.Check(err.Error(), check.Equals, "progname: ambiguous option: --lo could mean --long or --longer")

	args, err := opts.Parse([]string{"progname", "--long"})

	c.Assert(err, check.IsNil)
	c.Check(args, check.IsNil)
	c.Check(longFlag, check.Equals, true)
	c.Check(longerFlag, check.Equals, false)

	longFlag = false
	args, err = opts.Parse([]string{"progname", "--longe"})

	c.Assert(err, check.IsNil)
	c.Check(args, check.IsNil)
	c.Check(longFlag, check.Equals, false)
	c.Check(longerFlag, check.Equals, true)
}

func (s *Suite) Test_Options_Parse_mixed_args_and_options(c *check.C) {
	opts := NewOptions()
	var aflag, bflag bool
	opts.AddFlagVar('a', "aflag", &aflag, false, "")
	opts.AddFlagVar('b', "bflag", &bflag, false, "")

	args, err := opts.Parse([]string{"progname", "-a", "arg1", "-b", "arg2"})

	c.Assert(err, check.IsNil)
	c.Check(args, check.DeepEquals, []string{"arg1", "arg2"})
	c.Check(aflag, check.Equals, true)
	c.Check(bflag, check.Equals, true)

	aflag = false
	bflag = false
	args, err = opts.Parse([]string{"progname", "-a", "--", "arg1", "-b", "arg2"})

	c.Assert(err, check.IsNil)
	c.Check(args, check.DeepEquals, []string{"arg1", "-b", "arg2"})
	c.Check(aflag, check.Equals, true)
	c.Check(bflag, check.Equals, false)
}

func (s *Suite) Test_Options_Parse_string_list(c *check.C) {
	opts := NewOptions()
	var verbose bool
	var includes []string
	var excludes []string
	opts.AddStrList('e', "exclude", &excludes, "")
	opts.AddStrList('i', "include", &includes, "")
	opts.AddFlagVar('v', "verbose", &verbose, false, "")

	args, err := opts.Parse([]string{"progname",
		"-viincluded1",
		"-i", "included2",
		"--include=included3",
		"--include", "included4",
		"-eexcluded1",
		"-e", "excluded2",
		"--exclude=excluded3",
		"--exclude", "excluded4"})

	c.Check(args, check.IsNil)
	c.Check(err, check.IsNil)
	c.Check(includes, check.DeepEquals, []string{"included1", "included2", "included3", "included4"})
	c.Check(excludes, check.DeepEquals, []string{"excluded1", "excluded2", "excluded3", "excluded4"})

	args, err = opts.Parse([]string{"progname", "-i"})

	c.Check(err.Error(), check.Equals, "progname: option requires an argument: -i")

	args, err = opts.Parse([]string{"progname", "--include"})

	c.Check(err.Error(), check.Equals, "progname: option requires an argument: --include")
}
