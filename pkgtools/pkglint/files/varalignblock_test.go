package pkglint

import "gopkg.in/check.v1"

// VaralignTester reduces the amount of test code for aligning variable
// assignments in Makefiles.
//
// The most interesting breakpoint for looking at these tests is
// VaralignBlock.optimalWidth.
type VaralignTester struct {
	suite       *Suite
	tester      *Tester
	input       []string // The actual input lines
	internals   []string // The expected internal state, the varalignBlockInfos
	diagnostics []string // The expected diagnostics in default mode
	autofixes   []string // The expected diagnostics in --autofix mode
	fixed       []string // The expected fixed lines, with spaces instead of tabs
	ShowSource  bool     // The --show-source command line option
}

func NewVaralignTester(s *Suite, c *check.C) *VaralignTester {
	t := s.Init(c)

	return &VaralignTester{suite: s, tester: t}
}

// Input remembers the input lines that are checked and possibly realigned.
func (vt *VaralignTester) Input(lines ...string) { vt.input = lines }

// Internals remembers the expected internal state of the varalignBlockInfos,
// to better trace down at which points the decisions are made.
func (vt *VaralignTester) Internals(lines ...string) { vt.internals = lines }

// Diagnostics remembers the expected diagnostics.
func (vt *VaralignTester) Diagnostics(diagnostics ...string) { vt.diagnostics = diagnostics }

// Autofixes remembers the expected diagnostics when pkglint is
// run with the --autofix option.
func (vt *VaralignTester) Autofixes(autofixes ...string) { vt.autofixes = autofixes }

// Fixed remembers the expected fixed lines. To make the layout changes
// clearly visible, the lines given here use spaces instead of tabs.
// The fixed lines that have been written to the file are still using tabs.
func (vt *VaralignTester) Fixed(lines ...string) { vt.fixed = lines }

// Run is called after setting up the data and runs the varalign checks twice.
// Once for getting the diagnostics and once for automatically fixing them.
func (vt *VaralignTester) Run() {
	vt.run(false)
	vt.run(true)
}

func (vt *VaralignTester) run(autofix bool) {
	t := vt.tester

	cmdline := []string{"-Wall"}
	if autofix {
		cmdline = append(cmdline, "--autofix")
	}
	if vt.ShowSource {
		cmdline = append(cmdline, "--source")
	}
	t.SetUpCommandLine(cmdline...)

	mklines := t.SetUpFileMkLines("Makefile", vt.input...)

	var varalign VaralignBlock
	for _, mkline := range mklines.mklines {
		// This standard test only covers a single paragraph.
		// Testing multiple paragraphs is done as a side-effect
		// by the various other pkglint tests.
		assert(!mkline.IsEmpty())

		varalign.Process(mkline)
	}
	infos := varalign.infos // since they are overwritten by Finish
	varalign.Finish()

	var actual []string
	for _, info := range infos {
		minWidth := condStr(info.rawIndex == 0, sprintf("%02d", info.varnameOpWidth()), "  ")
		infoStr := sprintf("%s %02d", minWidth, info.varnameOpSpaceWidth())
		actual = append(actual, infoStr)
	}
	t.CheckDeepEquals(actual, vt.internals)

	if autofix {
		t.CheckOutput(vt.autofixes)

		SaveAutofixChanges(mklines.lines)
		t.CheckFileLinesDetab("Makefile", vt.fixed...)
	} else {
		t.CheckOutput(vt.diagnostics)
	}
}

func (s *Suite) Test_VaralignBlock__one_line_simple_none(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=value")
	vt.Internals(
		"20 20")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned to column 25.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \"\" with \"\\t\".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_simple_space(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV= value")
	vt.Internals(
		"20 21")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned with tabs, not spaces, to column 25.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \" \" with \"\\t\".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_simple_tab(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\tvalue")
	vt.Internals(
		"20 24")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_simple_sss(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=   value")
	vt.Internals(
		"20 23")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned with tabs, not spaces, to column 25.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \"   \" with \"\\t\".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_simple_ttt(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\t\t\tvalue")
	vt.Internals(
		"20 40")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=                    value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_simple_tsts(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\t \t value")
	vt.Internals(
		"20 33")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned with tabs, not spaces, to column 25.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \"\\t \\t \" with \"\\t\".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_follow_none(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\\",
		"\tvalue")
	vt.Internals(
		"20 20",
		"   08")
	vt.Diagnostics(
		// TODO: There should be a space to the left of the backslash.
		nil...)
	vt.Autofixes(
		nil...)
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=\\",
		"        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_follow_space(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV= \\",
		"\tvalue")
	vt.Internals(
		"20 21",
		"   08")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV= \\",
		"        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_follow_tab(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\t\\",
		"\tvalue")
	vt.Internals(
		"20 24",
		"   08")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    \\",
		"        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_follow_sss(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=   \\",
		"\tvalue")
	vt.Internals(
		"20 23",
		"   08")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=   \\",
		"        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_follow_ttt(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\t\t\t\\",
		"\tvalue")
	vt.Internals(
		"20 40",
		"   08")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=                    \\",
		"        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_follow_tab72(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\t\t\t\t\t\t\t\\",
		"\tvalue")
	vt.Internals(
		"20 72",
		"   08")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=                                                    \\",
		"        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_follow_indent_none(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV= \\",
		"value")
	vt.Internals(
		"20 21",
		"   00")
	vt.Diagnostics(
		"NOTE: ~/Makefile:2: This continuation line should be indented with \"\\t\".")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:2: Replacing \"\" with \"\\t\".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV= \\",
		"        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_follow_indent_space(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV= \\",
		" value")
	vt.Internals(
		"20 21",
		"   01")
	vt.Diagnostics(
		"NOTE: ~/Makefile:2: This continuation line should be indented with \"\\t\".")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:2: Replacing \" \" with \"\\t\".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV= \\",
		"        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_follow_indent_tab(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV= \\",
		"\tvalue")
	vt.Internals(
		"20 21",
		"   08")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV= \\",
		"        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_follow_indent_sss(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV= \\",
		"   value")
	vt.Internals(
		"20 21",
		"   03")
	vt.Diagnostics(
		"NOTE: ~/Makefile:2: This continuation line should be indented with \"\\t\".")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:2: Replacing \"   \" with \"\\t\".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV= \\",
		"        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_follow_indent_tt(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV= \\",
		"\t\tvalue")
	vt.Internals(
		"20 21",
		"   16")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV= \\",
		"                value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_follow_indent_ttt(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV= \\",
		"\t\t\tvalue")
	vt.Internals(
		"20 21",
		"   24")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV= \\",
		"                        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_follow_indent_tsts(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV= \\",
		"\t \t value")
	vt.Internals(
		"20 21",
		"   17")
	vt.Diagnostics(
		"NOTE: ~/Makefile:2: This continuation line should be indented with \"\\t\\t \".")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:2: Replacing \"\\t \\t \" with \"\\t\\t \".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV= \\",
		"                 value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_initial_none(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=value \\",
		"\t\t    value")
	vt.Internals(
		"20 20",
		"   20")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned to column 25.",
		"NOTE: ~/Makefile:2: This continuation line should be indented with \"\\t\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \"\" with \"\\t\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"\\t\\t    \" with \"\\t\\t\\t\".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value \\",
		"                        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_initial_space(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV= value \\",
		"                     value")
	vt.Internals(
		"20 21",
		"   21")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned with tabs, not spaces, to column 25.",
		"NOTE: ~/Makefile:2: This continuation line should be indented with \"\\t\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \" \" with \"\\t\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"                     \" with \"\\t\\t\\t\".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value \\",
		"                        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_initial_tab(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\tvalue \\",
		"\t\t\tvalue")
	vt.Internals(
		"20 24",
		"   24")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value \\",
		"                        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_initial_sss(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=   value \\",
		"                       value")
	vt.Internals(
		"20 23",
		"   23")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned with tabs, not spaces, to column 25.",
		"NOTE: ~/Makefile:2: This continuation line should be indented with \"\\t\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \"   \" with \"\\t\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"                       \" with \"\\t\\t\\t\".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value \\",
		"                        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_initial_ttt(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\t\t\tvalue \\",
		"\t\t\t\t\tvalue")
	vt.Internals(
		"20 40",
		"   40")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=                    value \\",
		"                                        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_initial_tab64(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\tvalue\t\t\t\t\t\\",
		"\t\t\tvalue")
	vt.Internals(
		"20 24",
		"   24")
	vt.Diagnostics(
		// FIXME: backslash indentation must be space, tab or at column 73.
		nil...)
	vt.Autofixes(
		// FIXME: replace many tabs with a single space, since there are
		//  no more backslashes in this logical line.
		nil...)
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value                                   \\",
		"                        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_initial_tab72(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\tvalue\t\t\t\t\t\t\\",
		"\t\t\tvalue")
	vt.Internals(
		"20 24",
		"   24")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value                                           \\",
		"                        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_initial_indent_none(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\tvalue \\",
		"value")
	vt.Internals(
		"20 24",
		"   00")
	vt.Diagnostics(
		"NOTE: ~/Makefile:2: This continuation line should be indented with \"\\t\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:2: Replacing \"\" with \"\\t\\t\\t\".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value \\",
		"                        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_initial_indent_space(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\tvalue \\",
		" value")
	vt.Internals(
		"20 24",
		"   01")
	vt.Diagnostics(
		"NOTE: ~/Makefile:2: This continuation line should be indented with \"\\t\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:2: Replacing \" \" with \"\\t\\t\\t\".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value \\",
		"                        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_initial_indent_tab(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\tvalue \\",
		"\tvalue")
	vt.Internals(
		"20 24",
		"   08")
	vt.Diagnostics(
		nil...)
	vt.Autofixes(
		nil...)
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value \\",
		"        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_initial_indent_sss(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\tvalue \\",
		"   value")
	vt.Internals(
		"20 24",
		"   03")
	vt.Diagnostics(
		"NOTE: ~/Makefile:2: This continuation line should be indented with \"\\t\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:2: Replacing \"   \" with \"\\t\\t\\t\".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value \\",
		"                        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_initial_indent_tt(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\tvalue \\",
		"\t\tvalue")
	vt.Internals(
		"20 24",
		"   16")
	vt.Diagnostics(
		"NOTE: ~/Makefile:2: This continuation line should be indented with \"\\t\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:2: Replacing \"\\t\\t\" with \"\\t\\t\\t\".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value \\",
		"                        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_initial_indent_ttt(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\tvalue \\",
		"\t\t\tvalue")
	vt.Internals(
		"20 24",
		"   24")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value \\",
		"                        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_initial_indent_tsts(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\tvalue \\",
		"\t \t value")
	vt.Internals(
		"20 24",
		"   17")
	vt.Diagnostics(
		"NOTE: ~/Makefile:2: This continuation line should be indented with \"\\t\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:2: Replacing \"\\t \\t \" with \"\\t\\t\\t\".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value \\",
		"                        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_initial_indent_plus_sss(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\tvalue \\",
		"\t\t\t   value")
	vt.Internals(
		"20 24",
		"   27")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value \\",
		"                           value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__one_line_initial_indent_plus_tab(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\tvalue \\",
		"\t\t\t\tvalue")
	vt.Internals(
		"20 24",
		"   32")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value \\",
		"                                value")
	vt.Run()
}

// Commented lines are visually equivalent to uncommented lines.
// The alignment algorithm must treat them the same. The only difference
// is when follow-up lines start with a comment. This comment character
// precedes the indentation, but at the same time it is part of its width.
// Since the follow-up lines in their canonical form are always indented
// using tabs, the single comment character doesn't change the width.

// TODO: add systematic tests for commented lines

// Generally, the value in variable assignments is aligned
// at the next tab.
func (s *Suite) Test_VaralignBlock__one_var_tab(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR=\tone tab")
	vt.Internals(
		"04 08")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"VAR=    one tab")
	vt.Run()
}

// Having more tabs than necessary is allowed. This can be for aesthetic
// reasons to align this paragraph with the others in the same file.
func (s *Suite) Test_VaralignBlock__one_var_tabs(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR=\t\t\tseveral tabs")
	vt.Internals(
		"04 24")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"VAR=                    several tabs")
	vt.Run()
}

// Indentations with a single space are only allowed in some very few
// places, such as continuation lines or very long variable names.
// In a single paragraph of its own, indentation with a single space
// doesn't make sense, therefore it is replaced with a tab.
func (s *Suite) Test_VaralignBlock__one_var_space(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR= indented with one space")
	vt.Internals(
		"04 05")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned with tabs, not spaces, to column 9.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \" \" with \"\\t\".")
	vt.Fixed(
		"VAR=    indented with one space")
	vt.Run()
}

// While indentation with a single space is allowed in a few cases,
// indentation with several spaces is never allowed and is replaced
// with tabs.
func (s *Suite) Test_VaralignBlock__one_var_spaces(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR=   several spaces")
	vt.Internals(
		"04 07")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned with tabs, not spaces, to column 9.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \"   \" with \"\\t\".")
	vt.Fixed(
		"VAR=    several spaces")
	vt.Run()
}

// Inconsistently aligned lines for variables of the same length are
// replaced with tabs, so that they align nicely.
func (s *Suite) Test_VaralignBlock__two_vars__spaces(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR= indented with one space",
		"VAR=  indented with two spaces")
	vt.Internals(
		"04 05",
		"04 06")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned with tabs, not spaces, to column 9.",
		"NOTE: ~/Makefile:2: This variable value should be aligned with tabs, not spaces, to column 9.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \" \" with \"\\t\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"  \" with \"\\t\".")
	vt.Fixed(
		"VAR=    indented with one space",
		"VAR=    indented with two spaces")
	vt.Run()
}

// All variables in a block are aligned to the same depth.
func (s *Suite) Test_VaralignBlock__several_vars__spaces(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"GRP_A= value",
		"GRP_AA= value",
		"GRP_AAA= value",
		"GRP_AAAA= value")
	vt.Internals(
		"06 07",
		"07 08",
		"08 09",
		"09 10")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned with tabs, not spaces, to column 17.",
		"NOTE: ~/Makefile:2: This variable value should be aligned with tabs, not spaces, to column 17.",
		"NOTE: ~/Makefile:3: This variable value should be aligned with tabs, not spaces, to column 17.",
		"NOTE: ~/Makefile:4: This variable value should be aligned with tabs, not spaces, to column 17.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \" \" with \"\\t\\t\".",
		"AUTOFIX: ~/Makefile:2: Replacing \" \" with \"\\t\\t\".",
		"AUTOFIX: ~/Makefile:3: Replacing \" \" with \"\\t\".",
		"AUTOFIX: ~/Makefile:4: Replacing \" \" with \"\\t\".")
	vt.Fixed(
		"GRP_A=          value",
		"GRP_AA=         value",
		"GRP_AAA=        value",
		"GRP_AAAA=       value")
	vt.Run()
}

// Lines that are continued may be indented with a single space
// if the first line of the variable definition has no value.
func (s *Suite) Test_VaralignBlock__continuation(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR= \\",
		"\tvalue")
	vt.Internals(
		"04 05",
		"   08")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"VAR= \\",
		"        value")
	vt.Run()
}

// To align these two lines, the first line needs one more tab.
// The second line is further to the right but doesn't count as
// an outlier since it is not far enough.
// Adding one more tab to the indentation is generally considered ok.
func (s *Suite) Test_VaralignBlock__short_tab__long_space(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"BLOCK=\tindented with tab",
		"BLOCK_LONGVAR= indented with space")
	vt.Internals(
		"06 08",
		"14 15")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned to column 17.",
		"NOTE: ~/Makefile:2: This variable value should be aligned with tabs, not spaces, to column 17.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \"\\t\" with \"\\t\\t\".",
		"AUTOFIX: ~/Makefile:2: Replacing \" \" with \"\\t\".")
	vt.Fixed(
		"BLOCK=          indented with tab",
		"BLOCK_LONGVAR=  indented with space")
	vt.Run()
}

// When the indentation differs, the indentation is adjusted to the
// minimum necessary.
func (s *Suite) Test_VaralignBlock__short_long__tab(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"BLOCK=\tshort",
		"BLOCK_LONGVAR=\t\t\t\tlong")
	vt.Internals(
		"06 08",
		"14 40")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned to column 17.",
		"NOTE: ~/Makefile:2: This variable value should be aligned to column 17.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \"\\t\" with \"\\t\\t\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"\\t\\t\\t\\t\" with \"\\t\".")
	vt.Fixed(
		"BLOCK=          short",
		"BLOCK_LONGVAR=  long")
	vt.Run()
}

// For differing indentation, it doesn't matter whether the indentation
// is done with tabs or with spaces. It is aligned to the minimum
// necessary depth.
func (s *Suite) Test_VaralignBlock__space_and_tab(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR=    space",
		"VAR=\ttab ${VAR}")
	vt.Internals(
		"04 08",
		"04 08")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: Variable values should be aligned with tabs, not spaces.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \"    \" with \"\\t\".")
	vt.Fixed(
		"VAR=    space",
		"VAR=    tab ${VAR}")
	vt.Run()
}

// There must always be a visible space between the assignment operator
// and the value.
func (s *Suite) Test_VaralignBlock__no_space_at_all(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"PKG_FAIL_REASON+=\"Message\"")
	vt.Internals(
		"17 17")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned to column 25.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \"\" with \"\\t\".")
	vt.Fixed(
		"PKG_FAIL_REASON+=       \"Message\"")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__empty_continuation_in_column_1(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR= \\",
		"no indentation")
	vt.Internals(
		"04 05",
		"   00")
	vt.Diagnostics(
		"NOTE: ~/Makefile:2: This continuation line should be indented with \"\\t\".")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:2: Replacing \"\" with \"\\t\".")
	vt.Fixed(
		"VAR= \\",
		"        no indentation")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__empty_continuation_in_column_9(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR= \\",
		"\tminimum indentation")
	vt.Internals(
		"04 05",
		"   08")
	vt.Diagnostics(
		nil...)
	vt.Autofixes(
		nil...)
	vt.Fixed(
		"VAR= \\",
		"        minimum indentation")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__empty_continuation_space(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"REF=\tvalue",
		"VAR= \\",
		"\tminimum indentation")
	vt.Internals(
		"04 08",
		"04 05",
		"   08")
	vt.Diagnostics(
		"NOTE: ~/Makefile:2: This variable value should be aligned with tabs, not spaces, to column 9.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:2: Replacing \" \" with \"\\t\".")
	vt.Fixed(
		"REF=    value",
		"VAR=    \\",
		"        minimum indentation")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__empty_continuation_properly_indented(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"REF=\tvalue",
		"VAR=\t\\",
		"\tminimum indentation")
	vt.Internals(
		"04 08",
		"04 08",
		"   08")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"REF=    value",
		"VAR=    \\",
		"        minimum indentation")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__empty_continuation_too_narrow(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"LONG_VARIABLE=\tvalue",
		"VAR=\t\\",
		"\tminimum indentation")
	vt.Internals(
		"14 16",
		"04 08",
		"   08")
	vt.Diagnostics(
		"NOTE: ~/Makefile:2: This variable value should be aligned to column 17.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:2: Replacing \"\\t\" with \"\\t\\t\".")
	vt.Fixed(
		"LONG_VARIABLE=  value",
		"VAR=            \\",
		// TODO: This continuation line looks misplaced since there
		//  is plenty of space to the right.
		"        minimum indentation")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__empty_continuation_too_wide(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"LONG_VARIABLE=\tvalue",
		"REALLY_LONG_VARIABLE=\t\\",
		"\tminimum indentation")
	vt.Internals(
		"14 16",
		"21 24",
		"   08")
	vt.Diagnostics(
		nil...)
	vt.Autofixes()
	vt.Fixed(
		"LONG_VARIABLE=  value",
		"REALLY_LONG_VARIABLE=   \\",
		"        minimum indentation")
	vt.Run()
}

// Line 1 is currently indented to column 25.
// Line 2 is a continuation line with a very long variable name.
// Line 2 is indented to column 38, which is much larger than 25.
// Therefore line 2 is the outlier in this paragraph.
// The initial line of the continuation line is empty.
// It only contains a backslash, without the usual space to the left.
// This space should be inserted to the left of the backslash.
// Everything else is fine.
func (s *Suite) Test_VaralignBlock__outlier_in_follow_continuation(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"PATCHFILES+=\t\temacs20-jumbo-patch-20170723.gz",
		"SITES.emacs20-jumbo-patch-20170723.gz=\\",
		"\t\t\thttp://www.NetBSD.org/~dholland/patchkits/emacs20/")
	vt.Internals(
		"12 24",
		"38 38",
		"   24")
	vt.Diagnostics(
		"NOTE: ~/Makefile:2: This variable value should be aligned to column 40.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:2: Replacing \"\" with \" \".")
	vt.Fixed(
		"PATCHFILES+=            emacs20-jumbo-patch-20170723.gz",
		"SITES.emacs20-jumbo-patch-20170723.gz= \\",
		"                        http://www.NetBSD.org/~dholland/patchkits/emacs20/")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__continuation_lines(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"DISTFILES+=\tvalue",
		"DISTFILES+= \\", // The continuation backslash must be aligned.
		"\t\t\tvalue",    // The value is aligned deeper than necessary.
		"DISTFILES+=\t\t\tvalue",
		"DISTFILES+= value")
	vt.Internals(
		"11 16",
		"11 12",
		"   24",
		"11 32",
		"11 12")
	vt.Diagnostics(
		"NOTE: ~/Makefile:2: This variable value should be aligned with tabs, not spaces, to column 17.",
		"NOTE: ~/Makefile:3: This continuation line should be indented with \"\\t\\t\".",
		"NOTE: ~/Makefile:4: This variable value should be aligned to column 17.",
		"NOTE: ~/Makefile:5: This variable value should be aligned with tabs, not spaces, to column 17.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:2: Replacing \" \" with \"\\t\".",
		"AUTOFIX: ~/Makefile:3: Replacing \"\\t\\t\\t\" with \"\\t\\t\".",
		"AUTOFIX: ~/Makefile:4: Replacing \"\\t\\t\\t\" with \"\\t\".",
		"AUTOFIX: ~/Makefile:5: Replacing \" \" with \"\\t\".")
	vt.Fixed(
		"DISTFILES+=     value",
		"DISTFILES+=     \\",
		"                value",
		"DISTFILES+=     value",
		"DISTFILES+=     value")
	vt.Run()
}

// Line 1 is currently aligned at column 17. It could be shortened to column 9.
//
// Line 2--3 consists of multiple raw lines. The first of the raw lines
// contains a value, therefore it doesn't count as a pure continuation line
// for the purpose of realigning the paragraph. Pure continuation lines would
// be skipped completely; this line still takes place in realigning.
//
// Line 2 needs an indentation of at least 24. This is more than one tab away
// from the minimum required indentation of line 1, which is at column 9.
// By this reasoning, line 2--3 would be an outlier.
//
// In line 2--3, the first line and the continuation are aligned in the same
// column. Their relative indentation is 0, and that should be kept as-is.
// This one logical line looks like two separate lines, and because their
// indentation is the same, this logical line doesn't count as an outlier.
//
// Because line 2--3 is not an outlier, line 1 is realigned to column 25.
func (s *Suite) Test_VaralignBlock__continuation_line_one_tab_ahead(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR=\t\tvalue",
		"MASTER_SITE_NEDIT=\thttps://example.org \\",
		"\t\t\thttps://example.org")
	vt.Internals(
		"04 16",
		"18 24",
		"   24")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned to column 25.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \"\\t\\t\" with \"\\t\\t\\t\".")
	vt.Fixed(
		"VAR=                    value",
		"MASTER_SITE_NEDIT=      https://example.org \\",
		"                        https://example.org")
	vt.Run()
}

// As of June 2019, the long variable name doesn't count as an outlier
// because it only needs one more tab than the second-longest variable.
// This contradicts the visual impression, in which the variable names
// differ largely in their length.
//
// As soon as the V2 value would be properly indented with a tab, the
// visual difference would not be as much, therefore the current
// behavior is appropriate.
func (s *Suite) Test_VaralignBlock__outlier_more_than_8_spaces(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"V2=\tvalue",
		"V0000000000014=\tvalue")
	vt.Internals(
		"03 08",
		"15 16")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned to column 17.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \"\\t\" with \"\\t\\t\".")
	vt.Fixed(
		"V2=             value",
		"V0000000000014= value")
	vt.Run()
}

// Ensures that a wrong warning introduced in ccb56a5 is not logged.
// The warning was about continuation lines that should be reindented.
// In this case though, everything is already perfectly aligned.
func (s *Suite) Test_VaralignBlock__aligned_continuation(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"USE_TOOLS+=\t[ awk \\",
		"\t\tsed")
	vt.Internals(
		"11 16",
		"   16")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"USE_TOOLS+=     [ awk \\",
		"                sed")
	vt.Run()
}

// Shell commands in continuation lines are assumed to be already nicely indented.
// This particular example is not, but pkglint cannot decide this as of
// version 5.7.14 (July 2019).
func (s *Suite) Test_VaralignBlock__shell_command(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"USE_BUILTIN.Xfixes=\tyes",
		"USE_BUILTIN.Xfixes!=\t\t\t\t\t\t\t\\",
		"\tif ${PKG_ADMIN} pmatch ...; then\t\t\t\t\\",
		"\t\t:; else :; fi")
	vt.Internals(
		"19 24",
		"20 72",
		"   08",
		"   16")
	vt.Diagnostics(
		nil...)
	vt.Autofixes(
		nil...)
	vt.Fixed(
		"USE_BUILTIN.Xfixes=     yes",
		"USE_BUILTIN.Xfixes!=                                                    \\",
		"        if ${PKG_ADMIN} pmatch ...; then                                \\",
		"                :; else :; fi")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__escaped_varname(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"V.${v:S,\\#,,g}=\tvalue",
		"V2345678123456781234=\tvalue")
	vt.Internals(
		"15 16", // 15, since the number sign is not escaped when computing the indentation
		"21 24")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned to column 25.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \"\\t\" with \"\\t\\t\".")
	vt.Fixed(
		"V.${v:S,\\#,,g}=         value", // looks misaligned because of the backslash
		"V2345678123456781234=   value")
	vt.Run()
}

// The most common pattern for laying out continuation lines is to have all
// values in the continuation lines, one value per line, all indented to the same depth.
// The depth is either a single tab (see the test below) or aligns with the other
// variables in the paragraph (this test).
func (s *Suite) Test_VaralignBlock__continuation_value_starts_in_second_line(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"WRKSRC=\t${WRKDIR}",
		"DISTFILES=\tdistfile-1.0.0.tar.gz",
		"SITES.distfile-1.0.0.tar.gz= \\",
		"\t\t\t${MASTER_SITES_SOURCEFORGE} \\",
		"\t\t\t${MASTER_SITES_GITHUB}")
	vt.Internals(
		"07 08",
		"10 16",
		"28 29",
		"   24",
		"   24")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned to column 17.",
		"NOTE: ~/Makefile:4: This continuation line should be indented with \"\\t\\t\".",
		"NOTE: ~/Makefile:5: This continuation line should be indented with \"\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \"\\t\" with \"\\t\\t\".",
		"AUTOFIX: ~/Makefile:4: Replacing \"\\t\\t\\t\" with \"\\t\\t\".",
		"AUTOFIX: ~/Makefile:5: Replacing \"\\t\\t\\t\" with \"\\t\\t\".")
	vt.Fixed(
		"WRKSRC=         ${WRKDIR}",
		"DISTFILES=      distfile-1.0.0.tar.gz",
		"SITES.distfile-1.0.0.tar.gz= \\",
		"                ${MASTER_SITES_SOURCEFORGE} \\",
		"                ${MASTER_SITES_GITHUB}")
	vt.Run()
}

// The most common pattern for laying out continuation lines is to have all
// values in the continuation lines, one value per line, all indented to the same depth.
// The depth is either a single tab (this test) or aligns with the other
// variables in the paragraph (see the test above).
func (s *Suite) Test_VaralignBlock__continuation_value_starts_in_second_line_with_single_tab(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"WRKSRC=\t${WRKDIR}",
		"DISTFILES=\tdistfile-1.0.0.tar.gz",
		"SITES.distfile-1.0.0.tar.gz= \\",
		"\t${MASTER_SITES_SOURCEFORGE} \\",
		"\t${MASTER_SITES_GITHUB}")
	vt.Internals(
		"07 08",
		"10 16",
		"28 29",
		"   08",
		"   08")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned to column 17.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \"\\t\" with \"\\t\\t\".")
	vt.Fixed(
		"WRKSRC=         ${WRKDIR}",
		"DISTFILES=      distfile-1.0.0.tar.gz",
		"SITES.distfile-1.0.0.tar.gz= \\",
		"        ${MASTER_SITES_SOURCEFORGE} \\",
		"        ${MASTER_SITES_GITHUB}")
	vt.Run()
}

// Another common pattern is to write the first value in the first line and
// subsequent values indented to the same depth as the value in the first
// line.
//
// If the SITES line had only a single line containing a value, it would count
// as an outlier. But like this, the two variable expressions look massive
// enough so that the other variables should be aligned to them.
//
// The whole paragraph could be indented less by making the SITES line a
// pure continuation line, having only a backslash in its first line. Then
// everything could be aligned to column 17.
func (s *Suite) Test_VaralignBlock__continuation_value_starts_in_first_line(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"WRKSRC=\t${WRKDIR}",
		"DISTFILES=\tdistfile-1.0.0.tar.gz",
		"SITES.distfile-1.0.0.tar.gz=\t${MASTER_SITES_SOURCEFORGE} \\",
		"\t\t\t\t${MASTER_SITES_GITHUB}")
	vt.Internals(
		"07 08",
		"10 16",
		"28 32",
		"   32")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned to column 33.",
		"NOTE: ~/Makefile:2: This variable value should be aligned to column 33.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \"\\t\" with \"\\t\\t\\t\\t\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"\\t\" with \"\\t\\t\\t\".")
	vt.Fixed(
		"WRKSRC=                         ${WRKDIR}",
		"DISTFILES=                      distfile-1.0.0.tar.gz",
		"SITES.distfile-1.0.0.tar.gz=    ${MASTER_SITES_SOURCEFORGE} \\",
		"                                ${MASTER_SITES_GITHUB}")
	vt.Run()
}

// Continued lines that have mixed indentation are probably on purpose.
// Their minimum indentation should be aligned to the indentation of the
// other lines. The lines that are indented further should keep their
// relative indentation depth, no matter if that is done with spaces or
// with tabs.
func (s *Suite) Test_VaralignBlock__continuation_mixed_indentation_in_second_line(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"WRKSRC=\t${WRKDIR}",
		"DISTFILES=\tdistfile-1.0.0.tar.gz",
		"AWK_PROGRAM+= \\",
		"\t\t\t\t  /search/ { \\",
		"\t\t\t\t    action(); \\",
		"\t\t\t\t  }")
	vt.Internals(
		"07 08",
		"10 16",
		"13 14",
		"   34",
		"   36",
		"   34")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned to column 17.",
		"NOTE: ~/Makefile:3: This variable value should be aligned with tabs, not spaces, to column 17.",
		"NOTE: ~/Makefile:4: This continuation line should be indented with \"\\t\\t\".",
		"NOTE: ~/Makefile:5: This continuation line should be indented with \"\\t\\t  \".",
		"NOTE: ~/Makefile:6: This continuation line should be indented with \"\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \"\\t\" with \"\\t\\t\".",
		"AUTOFIX: ~/Makefile:3: Replacing \" \" with \"\\t\".",
		"AUTOFIX: ~/Makefile:4: Replacing \"\\t\\t\\t\\t  \" with \"\\t\\t\".",
		"AUTOFIX: ~/Makefile:5: Replacing \"\\t\\t\\t\\t    \" with \"\\t\\t  \".",
		"AUTOFIX: ~/Makefile:6: Replacing \"\\t\\t\\t\\t  \" with \"\\t\\t\".")
	vt.Fixed(
		"WRKSRC=         ${WRKDIR}",
		"DISTFILES=      distfile-1.0.0.tar.gz",
		"AWK_PROGRAM+=   \\",
		"                /search/ { \\",
		"                  action(); \\",
		"                }")
	vt.Run()
}

// Continuation lines may also start their values in the first line.
//
// The indentation of the continuation line is adjusted, preserving
// the relative indentation among its raw lines.
func (s *Suite) Test_VaralignBlock__continuation_mixed_indentation_in_first_line(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"WRKSRC=\t${WRKDIR}",
		"DISTFILES=\tdistfile-1.0.0.tar.gz",
		"AWK_PROGRAM+=\t\t\t  /search/ { \\",
		"\t\t\t\t    action(); \\",
		"\t\t\t\t  }")
	vt.Internals(
		"07 08",
		"10 16",
		"13 34",
		"   36",
		"   34")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned to column 17.",
		"NOTE: ~/Makefile:3: This variable value should be aligned with tabs, not spaces, to column 17.",
		"NOTE: ~/Makefile:4: This continuation line should be indented with \"\\t\\t\".",
		"NOTE: ~/Makefile:5: This continuation line should be indented with \"\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \"\\t\" with \"\\t\\t\".",
		"AUTOFIX: ~/Makefile:3: Replacing \"\\t\\t\\t  \" with \"\\t\".",
		"AUTOFIX: ~/Makefile:4: Replacing \"\\t\\t\\t\\t    \" with \"\\t\\t  \".",
		"AUTOFIX: ~/Makefile:5: Replacing \"\\t\\t\\t\\t  \" with \"\\t\\t\".")
	vt.Fixed(
		"WRKSRC=         ${WRKDIR}",
		"DISTFILES=      distfile-1.0.0.tar.gz",
		"AWK_PROGRAM+=   /search/ { \\",
		"                  action(); \\",
		"                }")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__follow_up_indented_with_spaces(c *check.C) {
	// FIXME: warn about the misleading empty line 6,
	//  but not in this test

	vt := NewVaralignTester(s, c)
	vt.Input(
		"DISTFILES= \\",
		" one space \\",
		"   three spaces \\",
		"        eight spaces \\",
		"\tand a tab \\",
		"   ") // trailing whitespace
	vt.Internals(
		"10 11",
		"   01",
		"   03",
		"   08",
		"   08",
		"   03")
	vt.Diagnostics(
		"NOTE: ~/Makefile:2: This continuation line should be indented with \"\\t\".",
		"NOTE: ~/Makefile:3: This continuation line should be indented with \"\\t\".",
		"NOTE: ~/Makefile:4: This continuation line should be indented with \"\\t\".")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:2: Replacing \" \" with \"\\t\".",
		"AUTOFIX: ~/Makefile:3: Replacing \"   \" with \"\\t\".",
		"AUTOFIX: ~/Makefile:4: Replacing \"        \" with \"\\t\".")
	vt.Fixed(
		"DISTFILES= \\",
		"        one space \\",
		"        three spaces \\",
		"        eight spaces \\",
		"        and a tab \\",
		"   ")
	vt.Run()
}

// When there is an outlier, no matter whether indented with space or tab,
// fix the whole block to use the indentation of the second-longest line.
// In this case, all of the remaining lines have the same indentation
// (as there is only 1 line at all).
// Therefore this existing indentation is used instead of the minimum necessary, which would only be a single tab.
func (s *Suite) Test_VaralignBlock__tab_outlier(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"DISTFILES=\t\tvery-very-very-very-long-distfile-name",
		"SITES.very-very-very-very-long-distfile-name=\t${MASTER_SITE_LOCAL}")
	vt.Internals(
		"10 24",
		"45 48")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"DISTFILES=              very-very-very-very-long-distfile-name",
		"SITES.very-very-very-very-long-distfile-name=   ${MASTER_SITE_LOCAL}")
	vt.Run()
}

// The SITES.* definition is indented less than the other lines,
// therefore the whole paragraph will be realigned to that depth.
func (s *Suite) Test_VaralignBlock__multiline(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"DIST_SUBDIR=            asc",
		"DISTFILES=              ${DISTNAME}${EXTRACT_SUFX} frontiers.mp3 \\",
		"                        machine_wars.mp3 time_to_strike.mp3",
		".for file in frontiers.mp3 machine_wars.mp3 time_to_strike.mp3",
		"SITES.${file}=  http://asc-hq.org/",
		".endfor",
		"WRKSRC=                 ${WRKDIR}/${PKGNAME_NOREV}")
	vt.Internals(
		"12 24",
		"10 24",
		"   24",
		"14 16",
		"07 24")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned with tabs, not spaces, to column 17.",
		"NOTE: ~/Makefile:2: This variable value should be aligned with tabs, not spaces, to column 17.",
		"NOTE: ~/Makefile:3: This continuation line should be indented with \"\\t\\t\".",
		"NOTE: ~/Makefile:5: Variable values should be aligned with tabs, not spaces.",
		"NOTE: ~/Makefile:7: This variable value should be aligned with tabs, not spaces, to column 17.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \"            \" with \"\\t\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"              \" with \"\\t\".",
		"AUTOFIX: ~/Makefile:3: Replacing \"                        \" with \"\\t\\t\".",
		"AUTOFIX: ~/Makefile:5: Replacing \"  \" with \"\\t\".",
		"AUTOFIX: ~/Makefile:7: Replacing \"                 \" with \"\\t\\t\".")
	vt.Fixed(
		"DIST_SUBDIR=    asc",
		"DISTFILES=      ${DISTNAME}${EXTRACT_SUFX} frontiers.mp3 \\",
		"                machine_wars.mp3 time_to_strike.mp3",
		".for file in frontiers.mp3 machine_wars.mp3 time_to_strike.mp3",
		"SITES.${file}=  http://asc-hq.org/",
		".endfor",
		"WRKSRC=         ${WRKDIR}/${PKGNAME_NOREV}")
	vt.Run()
}

// The CDROM variables align exactly at a tab position, therefore they must
// be indented by at least one more space. Since that one space is not
// enough to count as an outlier, everything is indented by one more tab.
func (s *Suite) Test_VaralignBlock__single_space(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"RESTRICTED=\tDo not sell, do not rent",
		"NO_BIN_ON_CDROM= ${RESTRICTED}",
		"NO_BIN_ON_FTP=\t${RESTRICTED}",
		"NO_SRC_ON_CDROM= ${RESTRICTED}",
		"NO_SRC_ON_FTP=\t${RESTRICTED}")
	vt.Internals(
		"11 16",
		"16 17",
		"14 16",
		"16 17",
		"14 16")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned to column 25.",
		"NOTE: ~/Makefile:2: This variable value should be aligned with tabs, not spaces, to column 25.",
		"NOTE: ~/Makefile:3: This variable value should be aligned to column 25.",
		"NOTE: ~/Makefile:4: This variable value should be aligned with tabs, not spaces, to column 25.",
		"NOTE: ~/Makefile:5: This variable value should be aligned to column 25.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \"\\t\" with \"\\t\\t\".",
		"AUTOFIX: ~/Makefile:2: Replacing \" \" with \"\\t\".",
		"AUTOFIX: ~/Makefile:3: Replacing \"\\t\" with \"\\t\\t\".",
		"AUTOFIX: ~/Makefile:4: Replacing \" \" with \"\\t\".",
		"AUTOFIX: ~/Makefile:5: Replacing \"\\t\" with \"\\t\\t\".")
	vt.Fixed(
		"RESTRICTED=             Do not sell, do not rent",
		"NO_BIN_ON_CDROM=        ${RESTRICTED}",
		"NO_BIN_ON_FTP=          ${RESTRICTED}",
		"NO_SRC_ON_CDROM=        ${RESTRICTED}",
		"NO_SRC_ON_FTP=          ${RESTRICTED}")
	vt.Run()
}

// These variables all look nicely aligned, but they use spaces instead of tabs for alignment.
// The spaces are replaced with tabs, which makes the indentation 4 spaces deeper in the first paragraph.
// In the second paragraph it's even 7 additional spaces.
// This is ok though since it is the prevailing indentation style in pkgsrc.
func (s *Suite) Test_VaralignBlock__only_space(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"REPLACE_PYTHON+= *.py",
		"REPLACE_PYTHON+= lib/*.py",
		"REPLACE_PYTHON+= src/*.py")
	vt.Internals(
		"16 17",
		"16 17",
		"16 17")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned with tabs, not spaces, to column 25.",
		"NOTE: ~/Makefile:2: This variable value should be aligned with tabs, not spaces, to column 25.",
		"NOTE: ~/Makefile:3: This variable value should be aligned with tabs, not spaces, to column 25.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \" \" with \"\\t\".",
		"AUTOFIX: ~/Makefile:2: Replacing \" \" with \"\\t\".",
		"AUTOFIX: ~/Makefile:3: Replacing \" \" with \"\\t\".")
	vt.Fixed(
		"REPLACE_PYTHON+=        *.py",
		"REPLACE_PYTHON+=        lib/*.py",
		"REPLACE_PYTHON+=        src/*.py")
	vt.Run()
}

// The indentation is deeper than necessary, but all lines agree on the same column.
// Therefore this indentation depth is kept. It looks good and is probably due to
// some other paragraphs in the file that are indented equally deep.
//
// As of December 2018, pkglint only looks at a single paragraph at a time,
// therefore it cannot reliably decide whether this deep indentation is necessary.
func (s *Suite) Test_VaralignBlock__mixed_tabs_and_spaces_same_column(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"DISTFILES+=             space",
		"DISTFILES+=\t\ttab")
	vt.Internals(
		"11 24",
		"11 24")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: Variable values should be aligned with tabs, not spaces.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \"             \" with \"\\t\\t\".")
	vt.Fixed(
		"DISTFILES+=             space",
		"DISTFILES+=             tab")
	vt.Run()
}

// Both lines are indented to the same column. Therefore none of them is considered an outlier.
func (s *Suite) Test_VaralignBlock__outlier_1(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"V= value",
		"V=\tvalue")
	vt.Internals(
		"02 03",
		"02 08")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned with tabs, not spaces, to column 9.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \" \" with \"\\t\".")
	vt.Fixed(
		"V=      value",
		"V=      value")
	vt.Run()
}

// A single space that ends at the same depth as a tab is replaced with a tab, for consistency.
func (s *Suite) Test_VaralignBlock__outlier_2(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"V.0008= value",
		"V=\tvalue")
	vt.Internals(
		"07 08",
		"02 08")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: Variable values should be aligned with tabs, not spaces.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \" \" with \"\\t\".")
	vt.Fixed(
		"V.0008= value",
		"V=      value")
	vt.Run()
}

// A short line that is indented with a tab is aligned to a longer line
// that is indented with a space. This is because space-indented lines are
// only allowed when their indentation is much deeper than the tab-indented
// ones (so-called outliers), or as the first line of a continuation line.
func (s *Suite) Test_VaralignBlock__outlier_3(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"V.00009= value",
		"V=\tvalue")
	vt.Internals(
		"08 09",
		"02 08")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned with tabs, not spaces, to column 17.",
		"NOTE: ~/Makefile:2: This variable value should be aligned to column 17.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \" \" with \"\\t\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"\\t\" with \"\\t\\t\".")
	vt.Fixed(
		"V.00009=        value",
		"V=              value")
	vt.Run()
}

// This space-indented line doesn't count as an outlier yet because it
// is only a single tab away. The limit is two tabs.
// Therefore both lines are indented with tabs.
func (s *Suite) Test_VaralignBlock__outlier_4(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"V.000000000016= value",
		"V=\tvalue")
	vt.Internals(
		"15 16",
		"02 08")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: Variable values should be aligned with tabs, not spaces.",
		"NOTE: ~/Makefile:2: This variable value should be aligned to column 17.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \" \" with \"\\t\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"\\t\" with \"\\t\\t\".")
	vt.Fixed(
		"V.000000000016= value",
		"V=              value")
	vt.Run()
}

// This space-indented line is an outlier since it is far enough from the
// tab-indented line. The latter would require 2 tabs to align to the former.
// Therefore the short line is not indented to the long line, in order to
// keep the indentation reasonably short for a large amount of the lines.
func (s *Suite) Test_VaralignBlock__outlier_5(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"V.0000000000017= value",
		"V=\tvalue")
	vt.Internals(
		"16 17",
		"02 08")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"V.0000000000017= value",
		"V=      value")
	vt.Run()
}

// Short space-indented lines do not count as outliers. They are are aligned to the longer tab-indented line.
func (s *Suite) Test_VaralignBlock__outlier_6(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"V= value",
		"V.000010=\tvalue")
	vt.Internals(
		"02 03",
		"09 16")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned with tabs, not spaces, to column 17.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \" \" with \"\\t\\t\".")
	vt.Fixed(
		"V=              value",
		"V.000010=       value")
	vt.Run()
}

// The long line is not an outlier but very close. One more space, and it would count.
func (s *Suite) Test_VaralignBlock__outlier_10(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"V.0000000000000000023= value", // Adjust from 23 to 24 (+ 1 tab)
		"V.000010=\tvalue")             // Adjust from 16 to 24 (+ 1 tab)
	vt.Internals(
		"22 23",
		"09 16")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned with tabs, not spaces, to column 25.",
		"NOTE: ~/Makefile:2: This variable value should be aligned to column 25.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \" \" with \"\\t\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"\\t\" with \"\\t\\t\".")
	vt.Fixed(
		"V.0000000000000000023=  value",
		"V.000010=               value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__outlier_11(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"V.00000000000000000024= value", // Keep at 24 (space to tab)
		"V.000010=\tvalue")              // Adjust from 16 to 24 (+ 1 tab)
	vt.Internals(
		"23 24",
		"09 16")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: Variable values should be aligned with tabs, not spaces.",
		"NOTE: ~/Makefile:2: This variable value should be aligned to column 25.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \" \" with \"\\t\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"\\t\" with \"\\t\\t\".")
	vt.Fixed(
		"V.00000000000000000024= value",
		"V.000010=               value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__outlier_12(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"V.000000000000000000025= value", // Keep at 25 (outlier)
		"V.000010=\tvalue")               // Keep at 16 (would require + 2 tabs)
	vt.Internals(
		"24 25",
		"09 16")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"V.000000000000000000025= value",
		"V.000010=       value")
	vt.Run()
}

// When the lines are indented inconsistently, the indentation is reduced
// to the required minimum.
func (s *Suite) Test_VaralignBlock__outlier_14(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"V.00008=\t\tvalue",     // Adjust from 24 to 16 (removes 1 tab)
		"V.00008=\t\t\t\tvalue") // Adjust from 40 to 16 (removes 3 tabs)
	vt.Internals(
		"08 24",
		"08 40")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned to column 17.",
		"NOTE: ~/Makefile:2: This variable value should be aligned to column 17.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \"\\t\\t\" with \"\\t\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"\\t\\t\\t\\t\" with \"\\t\".")
	vt.Fixed(
		"V.00008=        value",
		"V.00008=        value")
	vt.Run()
}

// The INSTALLATION_DIRS line is so long that it is considered an outlier,
// since compared to the DIST line, it is at least two tabs away.
// Pkglint before 2018-01-26 suggested that it "should be aligned to column 9",
// which is not possible since the variable name is already longer.
func (s *Suite) Test_VaralignBlock__long_short(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"INSTALLATION_DIRS=\tbin",
		"DIST=\t${WRKSRC}/dist")
	vt.Internals(
		"18 24",
		"05 08")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"INSTALLATION_DIRS=      bin",
		"DIST=   ${WRKSRC}/dist")
	vt.Run()
}

// Before 2018-01-26, pkglint wanted to replace the tab in the outlier with
// a space. After this change, the space-indented line would not look like an
// outlier anymore because the other values are aligned very close to the
// outlier value. To fix this case, the indentation of the other lines needs
// to be adjusted to the minimum required.
//
// FIXME: The definition of an outlier should be based on the actual indentation,
//  not on the minimum indentation. Or maybe even better on the corrected indentation.
//  In the below paragraph, the outlier is not indented enough to qualify as a visual outlier.
func (s *Suite) Test_VaralignBlock__tabbed_outlier(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		".if !empty(PKG_OPTIONS:Minspircd-sqloper)",
		"INSPIRCD_STORAGE_DRIVER?=\tmysql",
		"MODULES+=\t\tm_sqloper.cpp m_sqlutils.cpp",
		"HEADERS+=\t\tm_sqlutils.h",
		".endif")
	vt.Internals(
		"25 32",
		"09 24",
		"09 24")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		".if !empty(PKG_OPTIONS:Minspircd-sqloper)",
		"INSPIRCD_STORAGE_DRIVER?=       mysql",
		"MODULES+=               m_sqloper.cpp m_sqlutils.cpp",
		"HEADERS+=               m_sqlutils.h",
		".endif")
	vt.Run()
}

// When all continuation lines are indented exactly one tab more than the
// initial line, this is intentional.
//
// TODO: Make this rule more general: if the indentation of the continuation
//  lines is more than the initial line, it is intentional.
func (s *Suite) Test_VaralignBlock__indented_continuation_line(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"CONF_FILES_PERMS=\tsource \\",
		"\t\t\t\tdestination \\",
		"\t\t\t\tuser group 0644")
	vt.Internals(
		"17 24",
		"   32",
		"   32")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"CONF_FILES_PERMS=       source \\",
		"                                destination \\",
		"                                user group 0644")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__indented_continuation_line_in_paragraph(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"SUBST_CLASSES+=\t\tfix",
		"SUBST_STAGE.fix=\tpost-patch",
		"SUBST_SED.fix= \\",
		"\t-e 's,1,one,g' \\",
		"\t-e 's,2,two,g' \\",
		"\t-e 's,3,three,g'")
	vt.Internals(
		"15 24",
		"16 24",
		"14 15",
		"   08",
		"   08",
		"   08")
	vt.Diagnostics(
		"NOTE: ~/Makefile:3: This variable value should be aligned with tabs, not spaces, to column 25.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:3: Replacing \" \" with \"\\t\\t\".")
	vt.Fixed(
		"SUBST_CLASSES+=         fix",
		"SUBST_STAGE.fix=        post-patch",
		"SUBST_SED.fix=          \\",
		"        -e 's,1,one,g' \\",
		"        -e 's,2,two,g' \\",
		"        -e 's,3,three,g'")
	vt.Run()
}

// Up to 2018-01-27, it could happen that some source code was logged
// without a corresponding diagnostic. This was unintended and confusing.
func (s *Suite) Test_VaralignBlock__fix_without_diagnostic(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"MESSAGE_SUBST+=\t\tRUBY_DISTNAME=${RUBY_DISTNAME}",
		"PLIST_SUBST+=\t\tRUBY_SHLIBVER=${RUBY_SHLIBVER:Q} \\",
		"\t\t\tRUBY_SHLIBMAJOR=${RUBY_SHLIBMAJOR:Q} \\",
		"\t\t\tRUBY_NOSHLIBMAJOR=${RUBY_NOSHLIBMAJOR} \\",
		"\t\t\tRUBY_NAME=${RUBY_NAME:Q}")
	vt.Internals(
		"15 24",
		"13 24",
		"   24",
		"   24",
		"   24")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"MESSAGE_SUBST+=         RUBY_DISTNAME=${RUBY_DISTNAME}",
		"PLIST_SUBST+=           RUBY_SHLIBVER=${RUBY_SHLIBVER:Q} \\",
		"                        RUBY_SHLIBMAJOR=${RUBY_SHLIBMAJOR:Q} \\",
		"                        RUBY_NOSHLIBMAJOR=${RUBY_NOSHLIBMAJOR} \\",
		"                        RUBY_NAME=${RUBY_NAME:Q}")
	vt.ShowSource = true
	vt.Run()
}

// The two variables look like they were in two separate paragraphs, but
// they aren't. This is because the continuation line from the DISTFILES
// eats up the empty line that would otherwise separate the paragraphs.
func (s *Suite) Test_VaralignBlock__continuation_line_last_empty(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		// FIXME: Add a test for MkParser to warn about this apparently empty line.
		"DISTFILES= \\",
		"\ta \\",
		"\tb \\",
		"\tc \\",
		"", // This is the final line of the variable assignment.
		"NEXT_VAR=\tsecond line")
	vt.Internals(
		"10 11",
		"   08",
		"   08",
		"   08",
		"   00",
		"09 16")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned with tabs, not spaces, to column 17.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \" \" with \"\\t\".")
	vt.Fixed(
		"DISTFILES=      \\",
		"        a \\",
		"        b \\",
		"        c \\",
		"",
		"NEXT_VAR=       second line")
	vt.Run()
}

// Commented-out variables take part in the realignment.
// The TZ=UTC below is part of the two-line comment since make(1) interprets it in the same way.
//
// This is one of the few cases where commented variable assignments are treated specially.
// See MkLine.IsCommentedVarassign.
func (s *Suite) Test_VaralignBlock__realign_commented_single_lines(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"SHORT=\tvalue",
		"#DISTFILES=\tdistfile-1.0.0.tar.gz",
		"#CONTINUATION= \\",
		"#\t\tcontinued",
		"#CONFIGURE_ENV+= \\",
		"#TZ=UTC",
		"SHORT=\tvalue")
	vt.Internals(
		"06 08",
		"11 16",
		"14 15",
		"   16",
		"16 17",
		"   01",
		"06 08")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned to column 17.",
		"NOTE: ~/Makefile:3: This variable value should be aligned with tabs, not spaces, to column 17.",
		"NOTE: ~/Makefile:6: This continuation line should be indented with \"\\t\\t\".",
		"NOTE: ~/Makefile:7: This variable value should be aligned to column 17.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \"\\t\" with \"\\t\\t\".",
		"AUTOFIX: ~/Makefile:3: Replacing \" \" with \"\\t\".",
		"AUTOFIX: ~/Makefile:6: Replacing \"\" with \"\\t\\t\".",
		"AUTOFIX: ~/Makefile:7: Replacing \"\\t\" with \"\\t\\t\".")
	vt.Fixed(
		"SHORT=          value",
		"#DISTFILES=     distfile-1.0.0.tar.gz",
		"#CONTINUATION=  \\",
		"#               continued",
		"#CONFIGURE_ENV+= \\",
		"#               TZ=UTC",
		"SHORT=          value")
	vt.Run()
}

// Commented variable assignments are realigned, too.
// In this case, the BEFORE and COMMENTED variables are already aligned properly.
// The line starting with "AFTER" is part of the commented variable assignment,
// and since these are checked as well, it is realigned.
func (s *Suite) Test_VaralignBlock__realign_commented_continuation_line(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"BEFORE=\tvalue",
		"#COMMENTED= \\",
		"#\tvalue1 \\",
		"#\tvalue2 \\",
		"#\tvalue3 \\",
		"AFTER=\tafter")
	vt.Internals(
		"07 08",
		"11 12",
		"   08",
		"   08",
		"   08",
		"   00")
	vt.Diagnostics(
		"NOTE: ~/Makefile:6: This continuation line should be indented with \"\\t\".")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:6: Replacing \"\" with \"\\t\".")
	vt.Fixed(
		"BEFORE= value",
		"#COMMENTED= \\",
		"#       value1 \\",
		"#       value2 \\",
		"#       value3 \\",
		"        AFTER=  after")
	vt.Run()
}

// The HOMEPAGE is completely ignored. Since its value is empty it doesn't
// need any alignment. Whether it is commented out doesn't matter.
//
// If the HOMEPAGE were taken into account, the alignment would differ and
// the COMMENT line would be realigned to column 17, reducing the indentation by one tab.
func (s *Suite) Test_VaralignBlock__realign_variable_without_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"COMMENT=\t\tShort description of the package",
		"#HOMEPAGE=")
	vt.Internals(
		// The HOMEPAGE line is ignored completely since it has neither
		// variable value nor comment and therefore there's nothing
		// that could be aligned to other variables.
		"08 24")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"COMMENT=                Short description of the package",
		"#HOMEPAGE=")
	vt.Run()
}

// This commented multiline variable is already perfectly aligned.
// Nothing needs to be fixed.
// This is a simple case since a paragraph containing only one line
// is always aligned properly, except when the indentation uses spaces instead of tabs.
func (s *Suite) Test_VaralignBlock__realign_commented_multiline(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"#CONF_FILES+=\t\tfile1 \\",
		"#\t\t\tfile2")
	vt.Internals(
		"13 24",
		"   24")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"#CONF_FILES+=           file1 \\",
		"#                       file2")
	vt.Run()
}

// The VAR2 line is a continuation line that starts in column 9, just like
// the VAR1 line. Therefore the alignment is correct.
//
// Its follow-up line is indented with effectively tab-tab-space, and
// this relative indentation compared to the VAR2 line is preserved since
// it is often used for indenting AWK or shell programs.
//
// In this particular case, using a one-space indentation looks wrong,
// but as of July 2019, that's not something pkglint will know in the
// near future.
func (s *Suite) Test_VaralignBlock__mixed_indentation(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR1=\tvalue1",
		"VAR2=\tvalue2 \\",
		" \t \t value2 continued")
	vt.Internals(
		"05 08",
		"05 08",
		"   17")
	vt.Diagnostics(
		"NOTE: ~/Makefile:3: This continuation line should be indented with \"\\t\".")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:3: Replacing \" \\t \\t \" with \"\\t\\t \".")
	vt.Fixed(
		"VAR1=   value1",
		"VAR2=   value2 \\",
		"                 value2 continued")
	vt.Run()
}

// Ensure that the end-of-line comment is properly aligned
// to the variable values.
//
// This case may seem obvious, but in all other contexts, the whitespace
// before the comment is ignored. Therefore the end of the line would be
// after the "=" in these cases, and the alignment must take care to
// include the whitespace.
func (s *Suite) Test_VaralignBlock__eol_comment(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR1=\tdefined",
		"VAR2=\t# defined",
		"VAR3=\t#empty")
	vt.Internals(
		"05 08",
		"05 08",
		"05 08")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"VAR1=   defined",
		"VAR2=   # defined",
		"VAR3=   #empty")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__follow_up_indentation(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"EGDIR=\t\t\t${PREFIX}/share/examples/rtunes",
		"CONF_FILES=\t\t${EGDIR}/wrksrc.conf \\",
		"\t\t\t\t${PKG_SYSCONFDIR}/installed.conf",
		"EGDIR=\t\t\t${PREFIX}/share/examples/rtunes")
	vt.Internals(
		"06 24",
		"11 24",
		"   32",
		"06 24")
	vt.Diagnostics(
		nil...)
	vt.Autofixes(
		nil...)
	vt.Fixed(
		"EGDIR=                  ${PREFIX}/share/examples/rtunes",
		"CONF_FILES=             ${EGDIR}/wrksrc.conf \\",
		"                                ${PKG_SYSCONFDIR}/installed.conf",
		"EGDIR=                  ${PREFIX}/share/examples/rtunes")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__staircase(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"JAM_COMMAND=\t\\",
		"\tcd ${WRKSRC} &&\t\t\t\t\t\t\t\\",
		"\t\t${SETENV} ${MY_ENV}\t\t\t\t\t\\",
		"\t\t\t${PREFIX}/bin/my-cmd\t\t\t\t\\",
		"\t\t\t\t-options arg...")
	vt.Internals(
		"12 16",
		"   08",
		"   16",
		"   24",
		"   32")
	vt.Diagnostics(
		nil...)
	vt.Autofixes(
		nil...)
	vt.Fixed(
		"JAM_COMMAND=    \\",
		"        cd ${WRKSRC} &&                                                 \\",
		"                ${SETENV} ${MY_ENV}                                     \\",
		"                        ${PREFIX}/bin/my-cmd                            \\",
		"                                -options arg...")
	vt.Run()
}

// The follow-up lines may always start in column 9.
// This is used for long variable values, to prevent wrapping them
// into multiple lines.
func (s *Suite) Test_VaralignBlock__command_with_arguments(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"SED_REPLACEMENT_CMD= ${SED} -n \\",
		"\t-e s,a,b, \\",
		"\t-e s,a,b, \\",
		"\t-e s,a,b,")
	vt.Internals(
		"20 21",
		"   08",
		"   08",
		"   08")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned with tabs, not spaces, to column 25.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \" \" with \"\\t\".")
	vt.Fixed(
		"SED_REPLACEMENT_CMD=    ${SED} -n \\",
		"        -e s,a,b, \\",
		"        -e s,a,b, \\",
		"        -e s,a,b,")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock_Process__autofix(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wspace", "--show-autofix")

	mklines := t.NewMkLines("file.mk",
		"VAR=   value",    // Indentation 7, fixed to 8.
		"",                //
		"VAR=    value",   // Indentation 8, fixed to 8.
		"",                //
		"VAR=     value",  // Indentation 9, fixed to 8.
		"",                //
		"VAR= \tvalue",    // Mixed indentation 8, fixed to 8.
		"",                //
		"VAR=   \tvalue",  // Mixed indentation 8, fixed to 8.
		"",                //
		"VAR=    \tvalue", // Mixed indentation 16, fixed to 16.
		"",                //
		"VAR=\tvalue")     // Already aligned with tabs only, left unchanged.

	var varalign VaralignBlock
	for _, line := range mklines.mklines {
		varalign.Process(line)
	}
	varalign.Finish()

	t.CheckOutputLines(
		"NOTE: file.mk:1: This variable value should be aligned with tabs, not spaces, to column 9.",
		"AUTOFIX: file.mk:1: Replacing \"   \" with \"\\t\".",
		"NOTE: file.mk:3: Variable values should be aligned with tabs, not spaces.",
		"AUTOFIX: file.mk:3: Replacing \"    \" with \"\\t\".",
		"NOTE: file.mk:5: This variable value should be aligned with tabs, not spaces, to column 9.",
		"AUTOFIX: file.mk:5: Replacing \"     \" with \"\\t\".",
		"NOTE: file.mk:7: Variable values should be aligned with tabs, not spaces.",
		"AUTOFIX: file.mk:7: Replacing \" \\t\" with \"\\t\".",
		"NOTE: file.mk:9: Variable values should be aligned with tabs, not spaces.",
		"AUTOFIX: file.mk:9: Replacing \"   \\t\" with \"\\t\".",
		"NOTE: file.mk:11: Variable values should be aligned with tabs, not spaces.",
		"AUTOFIX: file.mk:11: Replacing \"    \\t\" with \"\\t\\t\".")
}

// When the lines of a paragraph are inconsistently aligned,
// they are realigned to the minimum required width.
func (s *Suite) Test_VaralignBlock_Process__reduce_indentation(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("file.mk",
		"VAR= \tvalue",
		"VAR=    \tvalue",
		"VAR=\t\t\t\tvalue",
		"",
		"VAR=\t\t\tneedlessly", // Nothing to be fixed here, since it looks good.
		"VAR=\t\t\tdeep",
		"VAR=\t\t\tindentation")

	var varalign VaralignBlock
	for _, mkline := range mklines.mklines {
		varalign.Process(mkline)
	}
	varalign.Finish()

	t.CheckOutputLines(
		"NOTE: file.mk:1: Variable values should be aligned with tabs, not spaces.",
		"NOTE: file.mk:2: This variable value should be aligned with tabs, not spaces, to column 9.",
		"NOTE: file.mk:3: This variable value should be aligned to column 9.")
}

// For every variable assignment, there is at least one space or tab between the variable
// name and the value. Even if it is the longest line, and even if the value would start
// exactly at a tab stop.
func (s *Suite) Test_VaralignBlock_Process__longest_line_no_space(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wspace")
	mklines := t.NewMkLines("file.mk",
		"SUBST_CLASSES+= aaaaaaaa",
		"SUBST_STAGE.aaaaaaaa= pre-configure",
		"SUBST_FILES.aaaaaaaa= *.pl",
		"SUBST_FILTER_CMD.aaaaaa=cat")

	var varalign VaralignBlock
	for _, mkline := range mklines.mklines {
		varalign.Process(mkline)
	}
	varalign.Finish()

	t.CheckOutputLines(
		"NOTE: file.mk:1: This variable value should be aligned with tabs, not spaces, to column 33.",
		"NOTE: file.mk:2: This variable value should be aligned with tabs, not spaces, to column 33.",
		"NOTE: file.mk:3: This variable value should be aligned with tabs, not spaces, to column 33.",
		"NOTE: file.mk:4: This variable value should be aligned to column 33.")
}

func (s *Suite) Test_VaralignBlock_Process__only_spaces(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("file.mk",
		"SUBST_CLASSES+= aaaaaaaa",
		"SUBST_STAGE.aaaaaaaa= pre-configure",
		"SUBST_FILES.aaaaaaaa= *.pl",
		"SUBST_FILTER_CMD.aaaaaaaa= cat")

	var varalign VaralignBlock
	for _, mkline := range mklines.mklines {
		varalign.Process(mkline)
	}
	varalign.Finish()

	t.CheckOutputLines(
		"NOTE: file.mk:1: This variable value should be aligned with tabs, not spaces, to column 33.",
		"NOTE: file.mk:2: This variable value should be aligned with tabs, not spaces, to column 33.",
		"NOTE: file.mk:3: This variable value should be aligned with tabs, not spaces, to column 33.",
		"NOTE: file.mk:4: This variable value should be aligned with tabs, not spaces, to column 33.")
}

func (s *Suite) Test_VaralignBlock_realignMultiEmptyInitial(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"VAR=\t${VAR}",
		// FIXME: It's not possible to align with tabs to column 21.
		"LONG_VARIABLE_NAME=    \t        \\",
		"\t${LONG_VARIABLE_NAME}")

	mklines.Check()

	t.CheckOutputLines(
		"NOTE: filename.mk:3: This variable value should be aligned with tabs, not spaces, to column 21.")
}

func (s *Suite) Test_VaralignBlock_split(c *check.C) {
	t := s.Init(c)

	test := func(textnl string, initial bool, expected varalignSplitResult) {
		actual := (&VaralignBlock{}).split(textnl, initial)

		t.CheckEquals(actual, expected)
		t.CheckEquals(
			actual.leadingComment+actual.varnameOp+
				actual.spaceBeforeValue+actual.value+actual.spaceAfterValue+
				actual.trailingComment+actual.spaceAfterComment+actual.continuation,
			textnl)
	}

	test("VAR=value\n", true,
		varalignSplitResult{
			leadingComment:    "",
			varnameOp:         "VAR=",
			spaceBeforeValue:  "",
			value:             "value",
			spaceAfterValue:   "",
			trailingComment:   "",
			spaceAfterComment: "",
			continuation:      "\n",
		})

	test("#VAR=value\n", true,
		varalignSplitResult{
			leadingComment:    "#",
			varnameOp:         "VAR=",
			spaceBeforeValue:  "",
			value:             "value",
			spaceAfterValue:   "",
			trailingComment:   "",
			spaceAfterComment: "",
			continuation:      "\n",
		})

	test("#VAR = value # comment \\\n", true,
		varalignSplitResult{
			leadingComment:    "#",
			varnameOp:         "VAR =",
			spaceBeforeValue:  " ",
			value:             "value",
			spaceAfterValue:   " ",
			trailingComment:   "# comment",
			spaceAfterComment: " ",
			continuation:      "\\\n",
		})

	test("VAR=value \\\n", true,
		varalignSplitResult{
			leadingComment:    "",
			varnameOp:         "VAR=",
			spaceBeforeValue:  "",
			value:             "value",
			spaceAfterValue:   " ",
			trailingComment:   "",
			spaceAfterComment: "",
			continuation:      "\\\n",
		})

	test("VAR=value # comment \\\n", true,
		varalignSplitResult{
			leadingComment:    "",
			varnameOp:         "VAR=",
			spaceBeforeValue:  "",
			value:             "value",
			spaceAfterValue:   " ",
			trailingComment:   "# comment",
			spaceAfterComment: " ",
			continuation:      "\\\n",
		})

	test("VAR=value # comment \\\\\n", true,
		varalignSplitResult{
			leadingComment:    "",
			varnameOp:         "VAR=",
			spaceBeforeValue:  "",
			value:             "value",
			spaceAfterValue:   " ",
			trailingComment:   "# comment \\\\",
			spaceAfterComment: "",
			continuation:      "\n",
		})

	test("VAR=\\# a [#] b # comment \\\\\n", true,
		varalignSplitResult{
			leadingComment:    "",
			varnameOp:         "VAR=",
			spaceBeforeValue:  "",
			value:             "\\# a [#] b",
			spaceAfterValue:   " ",
			trailingComment:   "# comment \\\\",
			spaceAfterComment: "",
			continuation:      "\n",
		})

	test("VAR.${param:[#]}=\tvalue\n", true,
		varalignSplitResult{
			leadingComment:    "",
			varnameOp:         "VAR.${param:[#]}=",
			spaceBeforeValue:  "\t",
			value:             "value",
			spaceAfterValue:   "",
			trailingComment:   "",
			spaceAfterComment: "",
			continuation:      "\n",
		})

	test("VAR=value", true,
		varalignSplitResult{
			leadingComment:    "",
			varnameOp:         "VAR=",
			spaceBeforeValue:  "",
			value:             "value",
			spaceAfterValue:   "",
			trailingComment:   "",
			spaceAfterComment: "",
			continuation:      "",
		})

	// Since this is a follow-up line, the text ends up in the variable
	// value, and varnameOp is necessarily empty.
	test("VAR=value", false,
		varalignSplitResult{
			leadingComment:    "",
			varnameOp:         "",
			spaceBeforeValue:  "",
			value:             "VAR=value",
			spaceAfterValue:   "",
			trailingComment:   "",
			spaceAfterComment: "",
			continuation:      "",
		})

	// In some edge cases the variable name is indented with ordinary spaces.
	// This must not lead to a panic.
	test("   VAR=value", true,
		varalignSplitResult{
			leadingComment:    "   ",
			varnameOp:         "VAR=",
			spaceBeforeValue:  "",
			value:             "value",
			spaceAfterValue:   "",
			trailingComment:   "",
			spaceAfterComment: "",
			continuation:      "",
		})

	// And in really edgy cases, the leading space may even be followed by tabs.
	// This should not happen in practice since it is really confusing.
	test(" \t VAR=value", true,
		varalignSplitResult{
			leadingComment:    " \t ",
			varnameOp:         "VAR=",
			spaceBeforeValue:  "",
			value:             "value",
			spaceAfterValue:   "",
			trailingComment:   "",
			spaceAfterComment: "",
			continuation:      "",
		})

	test("    value", false,
		varalignSplitResult{
			leadingComment:    "",
			varnameOp:         "",
			spaceBeforeValue:  "    ",
			value:             "value",
			spaceAfterValue:   "",
			trailingComment:   "",
			spaceAfterComment: "",
			continuation:      "",
		})

	// In practice it doesn't really happen that the last line of a file
	// ends in a backslash and at the same time it doesn't have the usual
	// newline ending.
	test("    value \\", false,
		varalignSplitResult{
			leadingComment:    "",
			varnameOp:         "",
			spaceBeforeValue:  "    ",
			value:             "value",
			spaceAfterValue:   " ",
			trailingComment:   "",
			spaceAfterComment: "",
			continuation:      "\\",
		})

	// Commented variable assignments are only valid if they
	// directly follow the comment sign.
	//
	// It is a programming error if such a line is ever added to
	// the VaralignBlock.
	t.ExpectAssert(
		func() { test("#  VAR=    value", true, varalignSplitResult{}) })
}

func (s *Suite) Test_varalignLine_canonicalFollow(c *check.C) {
	t := s.Init(c)

	test := func(comment, space string, expected bool) {
		l := varalignLine{
			parts: varalignSplitResult{
				leadingComment:   comment,
				spaceBeforeValue: space}}

		actual := l.canonicalFollow()

		t.CheckEquals(actual, expected)
	}

	// Follow-up lines should always be indented.
	test("", "", false)

	// Follow-up lines should be indented by tabs, not by spaces.
	test("", " ", false)

	// A tab is always canonical.
	test("", "\t", true)

	// A tab followed by up to 7 spaces is canonical.
	test("", "\t       ", true)

	// A tab followed by 8 spaces is not canonical, the spaces should be
	// replaced with a tab.
	test("", "\t        ", false)

	// There may be arbitrary many tabs.
	test("", "\t\t\t\t\t\t\t\t", true)

	// In commented follow-up lines, the value should be indented in the
	// same way as in uncommented lines.
	test("#", "", false)
	test("#", " ", false)
	test("#", "\t", true)
}
