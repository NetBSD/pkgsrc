package getopt

import (
	"gopkg.in/check.v1"
	"netbsd.org/pkglint/intqa"
	"strings"
	"testing"
)

type Suite struct{}

var _ = check.Suite(new(Suite))

func Test(t *testing.T) { check.TestingT(t) }

func (s *Suite) Test_Options_Parse__short(c *check.C) {
	opts := NewOptions()
	var help bool
	opts.AddFlagVar('h', "help", &help, false, "prints a help page")

	args, err := opts.Parse([]string{"progname", "-h"})

	c.Assert(err, check.IsNil)
	c.Check(args, check.IsNil)
	c.Check(help, check.Equals, true)
}

func (s *Suite) Test_Options_Parse__short_string(c *check.C) {
	opts := NewOptions()
	var help bool
	var src string
	var dst string
	opts.AddFlagVar('h', "help", &help, false, "prints a help page")
	opts.AddStrVar('s', "src", &src, "", "source of the copy operation")
	opts.AddStrVar('d', "dst", &dst, "", "destination of the copy operation")

	args, err := opts.Parse([]string{"copy", "-hssource", "-d", "destination"})

	c.Assert(err, check.IsNil)
	c.Check(args, check.IsNil)
	c.Check(help, check.Equals, true)
	c.Check(src, check.Equals, "source")
	c.Check(dst, check.Equals, "destination")
}

func (s *Suite) Test_Options_Parse__short_string_unfinished(c *check.C) {
	opts := NewOptions()
	var unfinished string
	opts.AddStrVar('u', "unfinished", &unfinished, "", "demo")

	args, err := opts.Parse([]string{"program", "-u"})

	c.Assert(err.Error(), check.Equals, "program: option requires an argument: -u")
	c.Check(args, check.IsNil)
	c.Check(unfinished, check.Equals, "")
}

func (s *Suite) Test_Options_Parse__unknown_short(c *check.C) {
	opts := NewOptions()

	_, err := opts.Parse([]string{"progname", "-z"})

	c.Check(err.Error(), check.Equals, "progname: unknown option: -z")
}

func (s *Suite) Test_Options_Parse__unknown_short_with_argument(c *check.C) {
	opts := NewOptions()

	_, err := opts.Parse([]string{"progname", "-z", "arg"})

	c.Check(err.Error(), check.Equals, "progname: unknown option: -z")
}

func (s *Suite) Test_Options_Parse__unknown_long(c *check.C) {
	opts := NewOptions()

	_, err := opts.Parse([]string{"progname", "--unknown-long"})

	c.Check(err.Error(), check.Equals, "progname: unknown option: --unknown-long")
}

func (s *Suite) Test_Options_Parse__unknown_flag_in_group(c *check.C) {
	opts := NewOptions()
	opts.AddFlagGroup('W', "warnings", "", "")

	_, err := opts.Parse([]string{"progname", "-Wall", "-Werror"})

	c.Check(err.Error(), check.Equals, "progname: unknown option: -Werror")

	_, err = opts.Parse([]string{"progname", "--warnings=all", "--warnings=no-error"})

	c.Check(err.Error(), check.Equals, "progname: unknown option: --warnings=no-error")

	_, err = opts.Parse([]string{"progname", "-W"})

	c.Check(err.Error(), check.Equals, "progname: option requires an argument: -W")
}

func (s *Suite) Test_Options_Parse__abbreviated_long(c *check.C) {
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

func (s *Suite) Test_Options_Parse__mixed_args_and_options(c *check.C) {
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

func (s *Suite) Test_Options_Parse__string_list(c *check.C) {
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

	_, err = opts.Parse([]string{"progname", "-i"})

	if c.Check(err, check.NotNil) {
		c.Check(err.Error(), check.Equals, "progname: option requires an argument: -i")
	}

	_, err = opts.Parse([]string{"progname", "--include"})

	if c.Check(err, check.NotNil) {
		c.Check(err.Error(), check.Equals, "progname: option requires an argument: --include")
	}
}

func (s *Suite) Test_Options_Parse__long_flags(c *check.C) {
	var posFlags [5]bool
	var negFlags [5]bool
	var otherFlags [2]bool

	opts := NewOptions()
	opts.AddFlagVar(0, "pos0", &posFlags[0], false, "")
	opts.AddFlagVar(0, "pos1", &posFlags[1], false, "")
	opts.AddFlagVar(0, "pos2", &posFlags[2], false, "")
	opts.AddFlagVar(0, "pos3", &posFlags[3], false, "")
	opts.AddFlagVar(0, "pos4", &posFlags[4], false, "")
	opts.AddFlagVar(0, "neg0", &negFlags[0], true, "")
	opts.AddFlagVar(0, "neg1", &negFlags[1], true, "")
	opts.AddFlagVar(0, "neg2", &negFlags[2], true, "")
	opts.AddFlagVar(0, "neg3", &negFlags[3], true, "")
	opts.AddFlagVar(0, "neg4", &negFlags[4], true, "")
	opts.AddFlagVar(0, "other0", &otherFlags[0], false, "")
	opts.AddFlagVar(0, "other1", &otherFlags[1], false, "")

	args, err := opts.Parse([]string{"progname",
		"--pos0=true",
		"--pos1=on",
		"--pos2=enabled",
		"--pos3=1",
		"--pos4=yes",
		"--neg0=false",
		"--neg1=off",
		"--neg2=disabled",
		"--neg3=0",
		"--neg4=no",
		"--other0",
		"--other1=unknown"})

	c.Check(args, check.HasLen, 0)
	c.Check(posFlags, check.Equals, [5]bool{true, true, true, true, true})
	c.Check(negFlags, check.Equals, [5]bool{false, false, false, false, false})
	c.Check(otherFlags, check.Equals, [2]bool{true, false})
	c.Check(err.Error(), check.Equals, "progname: invalid argument for option --other1")
}

func (s *Suite) Test_Options_Parse__long_string(c *check.C) {
	opts := NewOptions()
	var src, dst string
	opts.AddStrVar('s', "src", &src, "", "source of the copy operation")
	opts.AddStrVar('d', "dst", &dst, "", "destination of the copy operation")

	args, err := opts.Parse([]string{"copy", "--src=source", "--dst", "destination", "arg"})

	c.Assert(err, check.IsNil)
	c.Check(args, check.DeepEquals, []string{"arg"})
	c.Check(src, check.Equals, "source")
	c.Check(dst, check.Equals, "destination")
}

func (s *Suite) Test_Options_Parse__long_string_unfinished(c *check.C) {
	opts := NewOptions()
	var unfinished string
	opts.AddStrVar('u', "unfinished", &unfinished, "", "unfinished option")

	args, err := opts.Parse([]string{"program", "--unfinished"})

	c.Check(err.Error(), check.Equals, "program: option requires an argument: --unfinished")
	c.Check(args, check.IsNil)
	c.Check(unfinished, check.Equals, "")
}

func (s *Suite) Test_Options_handleLongOption__string(c *check.C) {
	var extra bool

	opts := NewOptions()

	group := opts.AddFlagGroup('W', "warnings", "warning,...", "Print selected warnings")
	group.AddFlagVar("extra", &extra, false, "Print extra warnings")

	args, err := opts.Parse([]string{"progname", "--warnings"})

	c.Check(args, check.IsNil)
	c.Check(err.Error(), check.Equals, "progname: option requires an argument: --warnings")
	c.Check(extra, check.Equals, false)
}

func (s *Suite) Test_Options_handleLongOption__flag_group_without_argument(c *check.C) {
	var extra bool

	opts := NewOptions()
	group := opts.AddFlagGroup('W', "warnings", "warning,...", "Print selected warnings")
	group.AddFlagVar("extra", &extra, false, "Print extra warnings")

	args, err := opts.Parse([]string{"progname", "--warnings"})

	c.Check(args, check.IsNil)
	c.Check(err.Error(), check.Equals, "progname: option requires an argument: --warnings")
	c.Check(extra, check.Equals, false)
}

func (s *Suite) Test_Options_handleLongOption__flag_group_separate_argument(c *check.C) {
	var extra bool

	opts := NewOptions()
	group := opts.AddFlagGroup('W', "warnings", "warning,...", "Print selected warnings")
	group.AddFlagVar("extra", &extra, false, "Print extra warnings")

	args, err := opts.Parse([]string{"progname", "--warnings", "extra,unknown"})

	c.Check(args, check.IsNil)
	c.Check(err.Error(), check.Equals, "progname: unknown option: --warnings=unknown")
	c.Check(extra, check.Equals, true)
}

func (s *Suite) Test_Options_handleLongOption__flag_group_all_then_disable(c *check.C) {
	var false1, false2, true1, true2 bool

	opts := NewOptions()
	group := opts.AddFlagGroup('a', "answers", "answer,...", "Choose the answers")
	group.AddFlagVar("false1", &false1, false, "A")
	group.AddFlagVar("false2", &false2, false, "B")
	group.AddFlagVar("true1", &true1, true, "C")
	group.AddFlagVar("true2", &true2, true, "C")

	args, err := opts.Parse([]string{"progname", "--answers", "all,no-false1,no-true1", "arg"})

	c.Check(err, check.IsNil)
	c.Check(args, check.DeepEquals, []string{"arg"})
	c.Check(false1, check.Equals, false)
	c.Check(false2, check.Equals, true)
	c.Check(true1, check.Equals, false)
	c.Check(true2, check.Equals, true)
}

func (s *Suite) Test_Options_handleLongOption__flag_group_none_then_enable(c *check.C) {
	var false1, false2, true1, true2 bool

	opts := NewOptions()
	group := opts.AddFlagGroup('a', "answers", "answer,...", "Choose the answers")
	group.AddFlagVar("false1", &false1, false, "A")
	group.AddFlagVar("false2", &false2, false, "B")
	group.AddFlagVar("true1", &true1, true, "C")
	group.AddFlagVar("true2", &true2, true, "C")

	args, err := opts.Parse([]string{"progname", "--answers", "none,false1,true1", "arg"})

	c.Check(err, check.IsNil)
	c.Check(args, check.DeepEquals, []string{"arg"})
	c.Check(false1, check.Equals, true)
	c.Check(false2, check.Equals, false)
	c.Check(true1, check.Equals, true)
	c.Check(true2, check.Equals, false)
}

func (s *Suite) Test_Options_handleLongOption__internal_error(c *check.C) {
	var extra bool

	opts := NewOptions()
	group := opts.AddFlagGroup('W', "warnings", "warning,...", "Print selected warnings")
	group.AddFlagVar("extra", &extra, false, "Print extra warnings")

	// Intentionally damage internal structure to reach full code coverage.
	opts.options[0].data = "unexpected value"

	c.Check(
		func() { _, _ = opts.Parse([]string{"progname", "--warnings"}) },
		check.Panics,
		"getopt: internal error: unknown option type")
}

func (s *Suite) Test_Options_parseShortOptions__flag_group_separate_argument(c *check.C) {
	var extra bool

	opts := NewOptions()
	group := opts.AddFlagGroup('W', "warnings", "warning,...", "Print selected warnings")
	group.AddFlagVar("extra", &extra, false, "Print extra warnings")

	args, err := opts.Parse([]string{"progname", "-W", "extra,unknown"})

	c.Check(args, check.IsNil)
	c.Check(err.Error(), check.Equals, "progname: unknown option: -Wunknown")
	c.Check(extra, check.Equals, true)
}

func (s *Suite) Test_Options_Help(c *check.C) {
	var verbose bool
	var name string

	opts := NewOptions()
	opts.AddFlagVar('v', "verbose", &verbose, false, "Print a detailed log")
	opts.AddStrVar('n', "name", &name, "", "Name of the print job")

	var out strings.Builder
	opts.Help(&out, "progname [options] args")

	c.Check(out.String(), check.Equals, ""+
		"usage: progname [options] args\n"+
		"\n"+
		"  -v, --verbose   Print a detailed log\n"+
		"  -n, --name      Name of the print job\n")
}

func (s *Suite) Test_Options_Help__with_flag_group(c *check.C) {
	var verbose, basic, extra bool
	var name string

	opts := NewOptions()
	opts.AddFlagVar('v', "verbose", &verbose, false, "Print a detailed log")
	opts.AddStrVar('n', "name", &name, "", "Name of the print job")
	group := opts.AddFlagGroup('W', "warnings", "warning,...", "Print selected warnings")
	group.AddFlagVar("basic", &basic, true, "Print basic warnings")
	group.AddFlagVar("extra", &extra, false, "Print extra warnings")

	var out strings.Builder
	opts.Help(&out, "progname [options] args")

	c.Check(out.String(), check.Equals, ""+
		"usage: progname [options] args\n"+
		"\n"+
		"  -v, --verbose                Print a detailed log\n"+
		"  -n, --name                   Name of the print job\n"+
		"  -W, --warnings=warning,...   Print selected warnings\n"+
		"\n"+
		"  Flags for -W, --warnings:\n"+
		"    all     all of the following\n"+
		"    none    none of the following\n"+
		"    basic   Print basic warnings (enabled)\n"+
		"    extra   Print extra warnings (disabled)\n"+
		"\n"+
		"  (Prefix a flag with \"no-\" to disable it.)\n")
}

func (s *Suite) Test__test_names(c *check.C) {
	ck := intqa.NewTestNameChecker(c.Errorf)
	ck.Enable(intqa.EAll, -intqa.EMissingTest)
	ck.Check()
}
