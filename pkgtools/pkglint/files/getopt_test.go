package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) Test_Options_Parse_short(c *check.C) {
	opts := NewOptions()
	var help bool
	opts.AddFlagVar('h', "help", &help, false, "prints a help page")

	args, err := opts.Parse([]string{"progname", "-h"})

	c.Assert(err, check.IsNil)
	c.Check(args, check.IsNil)
	c.Check(help, equals, true)
}

func (s *Suite) Test_Options_Parse_unknown_short(c *check.C) {
	opts := NewOptions()

	_, err := opts.Parse([]string{"progname", "-z"})

	c.Check(err.Error(), equals, "progname: unknown option: -z")
}

func (s *Suite) Test_Options_Parse_unknown_long(c *check.C) {
	opts := NewOptions()

	_, err := opts.Parse([]string{"progname", "--unknown-long"})

	c.Check(err.Error(), equals, "progname: unknown option: --unknown-long")
}

func (s *Suite) Test_Options_Parse_unknown_flag_in_group(c *check.C) {
	opts := NewOptions()
	opts.AddFlagGroup('W', "warnings", "", "")

	_, err := opts.Parse([]string{"progname", "-Wall", "-Werror"})

	c.Check(err.Error(), equals, "progname: unknown option: -Werror")

	_, err = opts.Parse([]string{"progname", "--warnings=all", "--warnings=no-error"})

	c.Check(err.Error(), equals, "progname: unknown option: --warnings=no-error")

	_, err = opts.Parse([]string{"progname", "-W"})

	c.Check(err.Error(), equals, "progname: option requires an argument: -W")
}

func (s *Suite) Test_Options_Parse_abbreviated_long(c *check.C) {
	opts := NewOptions()
	var longFlag, longerFlag bool
	opts.AddFlagVar('?', "long", &longFlag, false, "")
	opts.AddFlagVar('?', "longer", &longerFlag, false, "")

	_, err := opts.Parse([]string{"progname", "--lo"})

	c.Check(err.Error(), equals, "progname: ambiguous option: --lo could mean --long or --longer")

	args, err := opts.Parse([]string{"progname", "--long"})

	c.Assert(err, check.IsNil)
	c.Check(args, check.IsNil)
	c.Check(longFlag, equals, true)
	c.Check(longerFlag, equals, false)

	longFlag = false
	args, err = opts.Parse([]string{"progname", "--longe"})

	c.Assert(err, check.IsNil)
	c.Check(args, check.IsNil)
	c.Check(longFlag, equals, false)
	c.Check(longerFlag, equals, true)
}

func (s *Suite) Test_Options_Parse_mixed_args_and_options(c *check.C) {
	opts := NewOptions()
	var aflag, bflag bool
	opts.AddFlagVar('a', "aflag", &aflag, false, "")
	opts.AddFlagVar('b', "bflag", &bflag, false, "")

	args, err := opts.Parse([]string{"progname", "-a", "arg1", "-b", "arg2"})

	c.Assert(err, check.IsNil)
	c.Check(args, check.DeepEquals, []string{"arg1", "arg2"})
	c.Check(aflag, equals, true)
	c.Check(bflag, equals, true)

	aflag = false
	bflag = false
	args, err = opts.Parse([]string{"progname", "-a", "--", "arg1", "-b", "arg2"})

	c.Assert(err, check.IsNil)
	c.Check(args, check.DeepEquals, []string{"arg1", "-b", "arg2"})
	c.Check(aflag, equals, true)
	c.Check(bflag, equals, false)
}
