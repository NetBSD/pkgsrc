package pkglint

import (
	"gopkg.in/check.v1"
	"strconv"
	"strings"
)

// VaralignTester reduces the amount of test code for aligning variable
// assignments in Makefiles.
//
// The most interesting breakpoint for looking at these tests is
// VaralignBlock.optimalWidth.
type VaralignTester struct {
	suite       *Suite
	tester      *Tester
	input       []string // The actual input lines
	inputDetab  []string // The expected input lines with spaces
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
func (vt *VaralignTester) Input(lines ...string) {
	vt.tester.CheckDotColumns(lines...)
	vt.input = lines
}

// InputDetab validates the input lines after replacing tabs with spaces.
//
// Calling it is optional.
func (vt *VaralignTester) InputDetab(lines ...string) { vt.inputDetab = lines }

// Internals remembers the expected internal state of the varalignBlockInfos,
// to better trace down at which points the decisions are made.
//
// Each line has the format "<min-width> <actual-width> <right-margin>".
//
// Calling it is optional.
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
	vt.tester.Chdir(".")
	vt.run(false)
	vt.run(true)
	vt.checkTestName()
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
	if len(vt.inputDetab) > 0 {
		t.CheckFileLinesDetab("Makefile", vt.inputDetab...)
	}

	var varalign VaralignBlock
	for _, mkline := range mklines.mklines {
		// This standard test only covers a single paragraph.
		// Testing multiple paragraphs is done as a side-effect
		// by the various other pkglint tests.
		assert(!mkline.IsEmpty())

		varalign.Process(mkline)
	}

	var actualInternals []string
	if len(vt.internals) > 0 {
		var actual []string
		for _, mkinfo := range varalign.mkinfos {
			for _, info := range mkinfo.infos {
				var minWidth, curWidth, continuation string
				minWidth = condStr(info.rawIndex == 0, sprintf("%02d", info.spaceBeforeValueColumn()), "  ")
				curWidth = sprintf(" %02d", info.valueColumn())
				if info.isContinuation() {
					continuation = sprintf(" %02d", info.continuationColumn())
				}
				actual = append(actual, minWidth+curWidth+continuation)
			}
		}
		actualInternals = actual
	}

	varalign.Finish()

	if len(vt.internals) > 0 {
		t.CheckDeepEquals(actualInternals, vt.internals)
	}

	if autofix {
		t.CheckOutput(vt.autofixes)

		SaveAutofixChanges(mklines.lines)
		t.CheckFileLinesDetab("Makefile", vt.fixed...)
	} else {
		t.CheckOutput(vt.diagnostics)
	}
}

func (vt *VaralignTester) checkTestName() {
	testName := vt.tester.c.TestName()
	if !matches(testName, `__(lead|var)\d*_`) {
		return
	}

	type descriptor struct {
		name  string
		width int
	}
	descriptorsString := func(ds []descriptor) string {
		var strs []string
		for _, d := range ds {
			strs = append(strs, sprintf("%s%d", d.name, d.width))
		}
		return strings.Join(strs, "_")
	}

	var actual []descriptor
	width := 0
	describe := func(str string, descr string) {
		width = tabWidthAppend(width, str)
		actual = append(actual, descriptor{descr, width})
	}
	describeHspace := func(hspace string) {
		width = tabWidthAppend(width, hspace)
		var descr string
		switch {
		case hspace == "":
			descr = "none"
		case hspace == "\t":
			descr = "tab"
		case hspace == " ":
			descr = "space"
		case matches(hspace, `^\t+$`):
			descr = "tabs"
		case matches(hspace, `^ +$`):
			descr = "spaces"
		case matches(hspace, `^\t+ {0,7}$`):
			descr = "indent"
		default:
			descr = strings.Replace(strings.Replace(hspace, " ", "s", -1), "\t", "t", -1)
		}
		actual = append(actual, descriptor{descr, width})
	}

	vt.tester.NewMkLines("Makefile", vt.input...).ForEach(func(mkline *MkLine) {
		if !mkline.IsVarassignMaybeCommented() {
			return
		}

		for i, input := range mkline.raw {
			parts := NewVaralignSplitter().split(input.Orig(), i == 0)
			width = 0
			if parts.leadingComment != "" {
				describe(parts.leadingComment, "lead")
			}
			if parts.varnameOp != "" {
				describe(parts.varnameOp, "var")
			}
			describeHspace(parts.spaceBeforeValue)
			if parts.value != "" {
				describe(parts.value, "value")
			}
			if parts.value != "" && parts.continuation != "" {
				describeHspace(parts.spaceAfterValue)
			}
			if parts.continuation != "" {
				describe(parts.continuation, "cont")
			}
		}
	})

	var expected []descriptor
	testDescr := strings.SplitN(testName, "__", 2)[1]
	for i, part := range strings.Split(testDescr, "_") {
		m, name, widthStr := match2(part, `^([a-z]+)(\d*)$`)
		assert(m)
		width, err := strconv.Atoi(widthStr)
		if err != nil || width == 0 {
			width = 0
			if i < len(actual) && name == actual[i].name {
				width = actual[i].width
			}
		}
		expected = append(expected, descriptor{name, width})
	}

	vt.tester.CheckDeepEquals(descriptorsString(actual), descriptorsString(expected))
	vt.tester.CheckDeepEquals(expected, actual)
}

func (s *Suite) Test_VaralignBlock__var_none_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=value")
	vt.Internals(
		"20 20")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned to column 25 instead of 21.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"\" with \"\\t\".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value")
	vt.Run()
}

// Indentations with a single space are only allowed in some very few
// places, such as continuation lines or very long variable names.
// In a single paragraph of its own, indentation with a single space
// doesn't make sense, therefore it is replaced with a tab.
func (s *Suite) Test_VaralignBlock__var_space_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV= value")
	vt.Internals(
		"20 21")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned with tabs, not spaces, to column 25 instead of 22.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \" \" with \"\\t\".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value")
	vt.Run()
}

// While indentation with a single space is allowed in a few cases,
// indentation with several spaces is never allowed and is replaced
// with tabs.
func (s *Suite) Test_VaralignBlock__var_spaces7_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR=   several spaces")
	vt.Internals(
		"04 07")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned with tabs, not spaces, to column 9 instead of 8.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"   \" with \"\\t\".")
	vt.Fixed(
		"VAR=    several spaces")
	vt.Run()
}

// Inconsistently aligned lines for variables of the same length are
// replaced with tabs, so that they align nicely.
func (s *Suite) Test_VaralignBlock__var4_space5_value_var4_spaces6_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR= indented with one space",
		"VAR=  indented with two spaces")
	vt.Internals(
		"04 05",
		"04 06")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned with tabs, not spaces, to column 9 instead of 6.",
		"NOTE: Makefile:2: This variable value should be aligned with tabs, not spaces, to column 9 instead of 7.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \" \" with \"\\t\".",
		"AUTOFIX: Makefile:2: Replacing \"  \" with \"\\t\".")
	vt.Fixed(
		"VAR=    indented with one space",
		"VAR=    indented with two spaces")
	vt.Run()
}

// Generally, the value in variable assignments is aligned at the next tab.
func (s *Suite) Test_VaralignBlock__var_tab8_value(c *check.C) {
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

func (s *Suite) Test_VaralignBlock__var_tab24_value(c *check.C) {
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

func (s *Suite) Test_VaralignBlock__var_spaces_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=   value")
	vt.Internals(
		"20 23")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned with tabs, not spaces, to column 25 instead of 24.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"   \" with \"\\t\".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value")
	vt.Run()
}

// Having more tabs than necessary is allowed. This can be for aesthetic
// reasons to align this paragraph with the others in the same file.
func (s *Suite) Test_VaralignBlock__var_tabs_value(c *check.C) {
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

func (s *Suite) Test_VaralignBlock__var_tsts_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\t \t value")
	vt.Internals(
		"20 33")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned with tabs, not spaces, to column 25 instead of 34.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"\\t \\t \" with \"\\t\".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var_none_cont_tab_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\\",
		"\tvalue")
	vt.Internals(
		"20 20 20",
		"   08")
	vt.Diagnostics(
		"NOTE: Makefile:1: The continuation backslash should be preceded by a single space or tab.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"\" with \" \".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV= \\",
		"        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var_space_cont_tab_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV= \\",
		"\tvalue")
	vt.Internals(
		"20 21 21",
		"   08")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV= \\",
		"        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var_tab_cont_tab_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\t\\",
		"\tvalue")
	vt.Internals(
		"20 24 24",
		"   08")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    \\",
		"        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var_spaces_cont_tab_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=   \\",
		"\tvalue")
	vt.Internals(
		"20 23 23",
		"   08")
	vt.Diagnostics(
		"NOTE: Makefile:1: The continuation backslash should be preceded by a single space or tab.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"   \" with \" \".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV= \\",
		"        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var_tabs_cont_tab_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\t\t\t\\",
		"\tvalue")
	vt.Internals(
		"20 40 40",
		"   08")
	vt.Diagnostics(
		"NOTE: Makefile:1: The continuation backslash should be preceded by a single space or tab.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"\\t\\t\\t\" with \" \".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV= \\",
		"        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var_tabs72_cont_tab_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\t\t\t\t\t\t\t\\",
		"\tvalue")
	vt.Internals(
		"20 72 72",
		"   08")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=                                                    \\",
		"        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var_space_cont_none_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV= \\",
		"value")
	vt.Internals(
		"20 21 21",
		"   00")
	vt.Diagnostics(
		"NOTE: Makefile:2: This continuation line should be indented with \"\\t\".")
	vt.Autofixes(
		"AUTOFIX: Makefile:2: Replacing \"\" with \"\\t\".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV= \\",
		"        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var_space_cont_space_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV= \\",
		" value")
	vt.Internals(
		"20 21 21",
		"   01")
	vt.Diagnostics(
		"NOTE: Makefile:2: This continuation line should be indented with \"\\t\".")
	vt.Autofixes(
		"AUTOFIX: Makefile:2: Replacing \" \" with \"\\t\".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV= \\",
		"        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var_space_cont_spaces3_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV= \\",
		"   value")
	vt.Internals(
		"20 21 21",
		"   03")
	vt.Diagnostics(
		"NOTE: Makefile:2: This continuation line should be indented with \"\\t\".")
	vt.Autofixes(
		"AUTOFIX: Makefile:2: Replacing \"   \" with \"\\t\".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV= \\",
		"        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var20_space_cont_tabs16_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV= \\",
		"\t\tvalue")
	vt.Internals(
		"20 21 21",
		"   16")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV= \\",
		"                value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var20_space_cont_tabs24_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV= \\",
		"\t\t\tvalue")
	vt.Internals(
		"20 21 21",
		"   24")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV= \\",
		"                        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var20_space_cont_tsts_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV= \\",
		"\t \t value")
	vt.Internals(
		"20 21 21",
		"   17")
	vt.Diagnostics(
		"NOTE: Makefile:2: This continuation line should be indented with \"\\t\\t \".")
	vt.Autofixes(
		"AUTOFIX: Makefile:2: Replacing \"\\t \\t \" with \"\\t\\t \".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV= \\",
		"                 value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var20_none_value_space_cont_indent20_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=value \\",
		"\t\t    value")
	vt.Internals(
		"20 20 26",
		"   20")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned to column 25 instead of 21.",
		"NOTE: Makefile:2: This continuation line should be indented with \"\\t\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"\" with \"\\t\".",
		"AUTOFIX: Makefile:2: Replacing \"\\t\\t    \" with \"\\t\\t\\t\".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value \\",
		"                        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var20_space_value_space_cont_spaces21_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV= value \\",
		"                     value")
	vt.Internals(
		"20 21 27",
		"   21")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned with tabs, not spaces, to column 25 instead of 22.",
		"NOTE: Makefile:2: This continuation line should be indented with \"\\t\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \" \" with \"\\t\".",
		"AUTOFIX: Makefile:2: Replacing \"                     \" with \"\\t\\t\\t\".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value \\",
		"                        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var_tab24_value_space_cont_tabs24_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\tvalue \\",
		"\t\t\tvalue")
	vt.Internals(
		"20 24 30",
		"   24")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value \\",
		"                        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var_spaces_value_space_cont_spaces_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=   value \\",
		"                       value")
	vt.Internals(
		"20 23 29",
		"   23")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned with tabs, not spaces, to column 25 instead of 24.",
		"NOTE: Makefile:2: This continuation line should be indented with \"\\t\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"   \" with \"\\t\".",
		"AUTOFIX: Makefile:2: Replacing \"                       \" with \"\\t\\t\\t\".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value \\",
		"                        value")
	vt.Run()
}

// The indentation is deeper than necessary, but that's ok.
//
// In most cases, this deeper indentation matches the other
// paragraphs in the same file.
func (s *Suite) Test_VaralignBlock__var_tabs40_value_space_cont_tabs40_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\t\t\tvalue \\",
		"\t\t\t\t\tvalue")
	vt.Internals(
		"20 40 46",
		"   40")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=                    value \\",
		"                                        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var_tab24_value_tabs64_cont_tabs24_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\tvalue\t\t\t\t\t\\",
		"\t\t\tvalue")
	vt.Internals(
		"20 24 64",
		"   24")
	vt.Diagnostics(
		// TODO: Or the continuation may be in column 73.
		"NOTE: Makefile:1: The continuation backslash should be preceded by a single space or tab.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"\\t\\t\\t\\t\\t\" with \" \".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value \\",
		"                        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var_tab24_value_tabs72_cont_tabs24_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\tvalue\t\t\t\t\t\t\\",
		"\t\t\tvalue")
	vt.Internals(
		"20 24 72",
		"   24")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value                                           \\",
		"                        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var_tab_value_space_cont_none_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\tvalue \\",
		"value")
	vt.Internals(
		"20 24 30",
		"   00")
	vt.Diagnostics(
		"NOTE: Makefile:2: This continuation line should be indented with \"\\t\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: Makefile:2: Replacing \"\" with \"\\t\\t\\t\".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value \\",
		"                        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var_tab_value_space_cont_space_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\tvalue \\",
		" value")
	vt.Internals(
		"20 24 30",
		"   01")
	vt.Diagnostics(
		"NOTE: Makefile:2: This continuation line should be indented with \"\\t\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: Makefile:2: Replacing \" \" with \"\\t\\t\\t\".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value \\",
		"                        value")
	vt.Run()
}

// The follow-up values should have at least the same indentation as the initial value.
func (s *Suite) Test_VaralignBlock__var_tab24_value_space_cont_tab_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\tvalue \\",
		"\tvalue")
	vt.Internals(
		"20 24 30",
		"   08")
	vt.Diagnostics(
		"NOTE: Makefile:2: This continuation line should be indented with \"\\t\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: Makefile:2: Replacing \"\\t\" with \"\\t\\t\\t\".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value \\",
		"                        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var_tab24_value_space_cont_spaces3_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\tvalue \\",
		"   value")
	vt.Internals(
		"20 24 30",
		"   03")
	vt.Diagnostics(
		"NOTE: Makefile:2: This continuation line should be indented with \"\\t\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: Makefile:2: Replacing \"   \" with \"\\t\\t\\t\".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value \\",
		"                        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var_tab24_value_space_cont_tabs16_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\tvalue \\",
		"\t\tvalue")
	vt.Internals(
		"20 24 30",
		"   16")
	vt.Diagnostics(
		"NOTE: Makefile:2: This continuation line should be indented with \"\\t\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: Makefile:2: Replacing \"\\t\\t\" with \"\\t\\t\\t\".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value \\",
		"                        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var_tab24_value_space_cont_tsts_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\tvalue \\",
		"\t \t value")
	vt.Internals(
		"20 24 30",
		"   17")
	vt.Diagnostics(
		"NOTE: Makefile:2: This continuation line should be indented with \"\\t\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: Makefile:2: Replacing \"\\t \\t \" with \"\\t\\t\\t\".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value \\",
		"                        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var_tab24_value_space_cont_indent27_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\tvalue \\",
		"\t\t\t   value")
	vt.Internals(
		"20 24 30",
		"   27")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value \\",
		"                           value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var_tab24_value_space_cont_tabs32_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\tvalue \\",
		"\t\t\t\tvalue")
	vt.Internals(
		"20 24 30",
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

// All variables in a block are aligned to the same depth.
func (s *Suite) Test_VaralignBlock__var6_space_value_var7_space_value_var8_space_value_var9_space_value(c *check.C) {
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
		"NOTE: Makefile:1: This variable value should be aligned with tabs, not spaces, to column 17 instead of 8.",
		"NOTE: Makefile:2: This variable value should be aligned with tabs, not spaces, to column 17 instead of 9.",
		"NOTE: Makefile:3: This variable value should be aligned with tabs, not spaces, to column 17 instead of 10.",
		"NOTE: Makefile:4: This variable value should be aligned with tabs, not spaces, to column 17 instead of 11.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \" \" with \"\\t\\t\".",
		"AUTOFIX: Makefile:2: Replacing \" \" with \"\\t\\t\".",
		"AUTOFIX: Makefile:3: Replacing \" \" with \"\\t\".",
		"AUTOFIX: Makefile:4: Replacing \" \" with \"\\t\".")
	vt.Fixed(
		"GRP_A=          value",
		"GRP_AA=         value",
		"GRP_AAA=        value",
		"GRP_AAAA=       value")
	vt.Run()
}

// In lines that are continued, the continuation backslash may be separated
// with a single space if the first line contains only the backslash, but
// not a variable value.
func (s *Suite) Test_VaralignBlock__var4_space_cont_tab_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR= \\",
		"\tvalue")
	vt.Internals(
		"04 05 05",
		"   08")
	vt.Diagnostics(
		nil...)
	vt.Autofixes(
		nil...)
	vt.Fixed(
		"VAR= \\",
		"        value")
	vt.Run()
}

// To align these two lines, the first line needs one more tab.
// The second line is further to the right but doesn't count as
// an outlier since it is not far enough.
// Adding one more tab to the indentation is generally considered ok.
func (s *Suite) Test_VaralignBlock__var_tab8_value_var_space15_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"BLOCK=\tindented with tab",
		"BLOCK_LONGVAR= indented with space")
	vt.Internals(
		"06 08",
		"14 15")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned to column 17 instead of 9.",
		"NOTE: Makefile:2: This variable value should be aligned with tabs, not spaces, to column 17 instead of 16.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"\\t\" with \"\\t\\t\".",
		"AUTOFIX: Makefile:2: Replacing \" \" with \"\\t\".")
	vt.Fixed(
		"BLOCK=          indented with tab",
		"BLOCK_LONGVAR=  indented with space")
	vt.Run()
}

// When the indentation differs, the indentation is adjusted to the
// minimum necessary.
func (s *Suite) Test_VaralignBlock__var_tab8_value_var14_tabs40_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"BLOCK=\tshort",
		"BLOCK_LONGVAR=\t\t\t\tlong")
	vt.Internals(
		"06 08",
		"14 40")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned to column 17 instead of 9.",
		"NOTE: Makefile:2: This variable value should be aligned to column 17 instead of 41.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"\\t\" with \"\\t\\t\".",
		"AUTOFIX: Makefile:2: Replacing \"\\t\\t\\t\\t\" with \"\\t\".")
	vt.Fixed(
		"BLOCK=          short",
		"BLOCK_LONGVAR=  long")
	vt.Run()
}

// For differing indentation, it doesn't matter whether the indentation
// is done with tabs or with spaces. It is aligned to the minimum
// necessary depth.
func (s *Suite) Test_VaralignBlock__var_spaces8_value_var_tab_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR=    space",
		"VAR=\ttab ${VAR}")
	vt.Internals(
		"04 08",
		"04 08")
	vt.Diagnostics(
		"NOTE: Makefile:1: Variable values should be aligned with tabs, not spaces.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"    \" with \"\\t\".")
	vt.Fixed(
		"VAR=    space",
		"VAR=    tab ${VAR}")
	vt.Run()
}

// There should always be a visible space between the assignment operator
// and the value.
func (s *Suite) Test_VaralignBlock__var17_none_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"PKG_FAIL_REASON+=\"Message\"")
	vt.Internals(
		"17 17")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned to column 25 instead of 18.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"\" with \"\\t\".")
	vt.Fixed(
		"PKG_FAIL_REASON+=       \"Message\"")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var4_space_cont_none_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR= \\",
		"no indentation")
	vt.Internals(
		"04 05 05",
		"   00")
	vt.Diagnostics(
		"NOTE: Makefile:2: This continuation line should be indented with \"\\t\".")
	vt.Autofixes(
		"AUTOFIX: Makefile:2: Replacing \"\" with \"\\t\".")
	vt.Fixed(
		"VAR= \\",
		"        no indentation")
	vt.Run()
}

// The simple variable assignment in line 1 determines the main alignment
// column, to which line 2 is then aligned.
//
// If the variable name in line 2 were longer, the space would be ok.
func (s *Suite) Test_VaralignBlock__var_tab8_value_var4_space_cont_tab_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"REF=\tvalue",
		"VAR= \\",
		"\tminimum indentation")
	vt.Internals(
		"04 08",
		"04 05 05",
		"   08")
	vt.Diagnostics(
		"NOTE: Makefile:2: This variable value should be aligned with tabs, not spaces, to column 9 instead of 6.")
	vt.Autofixes(
		"AUTOFIX: Makefile:2: Replacing \" \" with \"\\t\".")
	vt.Fixed(
		"REF=    value",
		"VAR=    \\",
		"        minimum indentation")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var_tab8_value_var_tab8_cont_tab_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"REF=\tvalue",
		"VAR=\t\\",
		"\tminimum indentation")
	vt.Internals(
		"04 08",
		"04 08 08",
		"   08")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"REF=    value",
		"VAR=    \\",
		"        minimum indentation")
	vt.Run()
}

// The difference in the variable names is 10 characters, but when aligned
// with tabs, their values only differ by a single tab. This is not enough
// to count as an outlier.
func (s *Suite) Test_VaralignBlock__var14_tab_value_var4_tab_cont_tab_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"LONG_VARIABLE=\tvalue",
		"VAR=\t\\",
		"\tminimum indentation")
	vt.Internals(
		"14 16",
		"04 08 08",
		"   08")
	vt.Diagnostics(
		"NOTE: Makefile:2: This variable value should be aligned to column 17 instead of 9.")
	vt.Autofixes(
		"AUTOFIX: Makefile:2: Replacing \"\\t\" with \"\\t\\t\".")
	vt.Fixed(
		"LONG_VARIABLE=  value",
		"VAR=            \\",
		// TODO: This continuation line looks misplaced since there
		//  is plenty of space to the right.
		"        minimum indentation")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var14_tab_value_var21_tab_cont_tab_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"LONG_VARIABLE=\tvalue",
		"REALLY_LONG_VARIABLE=\t\\",
		"\tminimum indentation")
	vt.Internals(
		"14 16",
		"21 24 24",
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
func (s *Suite) Test_VaralignBlock__var12_tabs24_value_var38_none_cont_tabs24_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"PATCHFILES+=\t\temacs20-jumbo-patch-20170723.gz",
		"SITES.emacs20-jumbo-patch-20170723.gz=\\",
		"\t\t\thttp://www.NetBSD.org/~dholland/patchkits/emacs20/")
	vt.Internals(
		"12 24",
		"38 38 38",
		"   24")
	vt.Diagnostics(
		"NOTE: Makefile:2: The continuation backslash should be preceded by a single space or tab.")
	vt.Autofixes(
		"AUTOFIX: Makefile:2: Replacing \"\" with \" \".")
	vt.Fixed(
		"PATCHFILES+=            emacs20-jumbo-patch-20170723.gz",
		"SITES.emacs20-jumbo-patch-20170723.gz= \\",
		"                        http://www.NetBSD.org/~dholland/patchkits/emacs20/")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var_tab16_value_var_space_cont_tabs24_value_var_tabs32_value_var11_space_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"DISTFILES+=\tvalue",
		"DISTFILES+= \\", // The continuation backslash must be aligned.
		"\t\t\tvalue",    // The value is aligned deeper than necessary.
		"DISTFILES+=\t\t\tvalue",
		"DISTFILES+= value")
	vt.Internals(
		"11 16",
		"11 12 12",
		"   24",
		"11 32",
		"11 12")
	vt.Diagnostics(
		"NOTE: Makefile:2: This variable value should be aligned with tabs, not spaces, to column 17 instead of 13.",
		"NOTE: Makefile:3: This continuation line should be indented with \"\\t\\t\".",
		"NOTE: Makefile:4: This variable value should be aligned to column 17 instead of 33.",
		"NOTE: Makefile:5: This variable value should be aligned with tabs, not spaces, to column 17 instead of 13.")
	vt.Autofixes(
		"AUTOFIX: Makefile:2: Replacing \" \" with \"\\t\".",
		"AUTOFIX: Makefile:3: Replacing \"\\t\\t\\t\" with \"\\t\\t\".",
		"AUTOFIX: Makefile:4: Replacing \"\\t\\t\\t\" with \"\\t\".",
		"AUTOFIX: Makefile:5: Replacing \" \" with \"\\t\".")
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
func (s *Suite) Test_VaralignBlock__var_tabs16_value_var_tab24_value_space_cont_tabs24_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR=\t\tvalue",
		"MASTER_SITE_NEDIT=\thttps://example.org \\",
		"\t\t\thttps://example.org")
	vt.Internals(
		"04 16",
		"18 24 44",
		"   24")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned to column 25 instead of 17.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"\\t\\t\" with \"\\t\\t\\t\".")
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
func (s *Suite) Test_VaralignBlock__var_tab8_value_var_tab16_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"V2=\tvalue",
		"V0000000000014=\tvalue")
	vt.Internals(
		"03 08",
		"15 16")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned to column 17 instead of 9.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"\\t\" with \"\\t\\t\".")
	vt.Fixed(
		"V2=             value",
		"V0000000000014= value")
	vt.Run()
}

// Ensures that a wrong warning introduced in ccb56a5 is not logged.
// The warning was about continuation lines that should be reindented.
// In this case though, everything is already perfectly aligned.
func (s *Suite) Test_VaralignBlock__var_tab16_value_space_cont_tabs16_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"USE_TOOLS+=\t[ awk \\",
		"\t\tsed")
	vt.Internals(
		"11 16 22",
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
func (s *Suite) Test_VaralignBlock__var_tab24_value_var20_tabs72_cont_tab_value_tabs72_cont_tabs16_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"USE_BUILTIN.Xfixes=\tyes",
		"USE_BUILTIN.Xfixes!=\t\t\t\t\t\t\t\\",
		"\tif ${PKG_ADMIN} pmatch ...; then\t\t\t\t\\",
		"\t\t:; else :; fi")
	vt.Internals(
		"19 24",
		"20 72 72",
		"   08 72",
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

// For escaped variable names, the number of actual characters in the
// Makefile is relevant for indenting the source code. Therefore, the
// parsed and unescaped mkline.Varname cannot be used here.
func (s *Suite) Test_VaralignBlock__escaped_varname(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"V.${v:S,\\#,,g}=\tvalue",
		"V2345678123456781234=\tvalue")
	vt.Internals(
		"15 16", // 15, since the number sign is still escaped when computing the indentation
		"21 24")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned to column 25 instead of 17.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"\\t\" with \"\\t\\t\".")
	vt.Fixed(
		"V.${v:S,\\#,,g}=         value", // looks misaligned because of the Go string literal
		"V2345678123456781234=   value")
	vt.Run()
}

// The most common pattern for laying out continuation lines is to have all
// values in the continuation lines, one value per line, all indented to the same depth.
// The depth is either a single tab (see the test below) or aligns with the other
// variables in the paragraph (this test).
func (s *Suite) Test_VaralignBlock__var_tab8_value_var_tab16_value_var28_space_cont_tabs24_value_space_cont_tabs24_value(c *check.C) {
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
		"28 29 29",
		"   24 52",
		"   24")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned to column 17 instead of 9.",
		"NOTE: Makefile:4: This continuation line should be indented with \"\\t\\t\".",
		"NOTE: Makefile:5: This continuation line should be indented with \"\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"\\t\" with \"\\t\\t\".",
		"AUTOFIX: Makefile:4: Replacing \"\\t\\t\\t\" with \"\\t\\t\".",
		"AUTOFIX: Makefile:5: Replacing \"\\t\\t\\t\" with \"\\t\\t\".")
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
func (s *Suite) Test_VaralignBlock__var_tab8_value_var_tab16_value_var28_space_cont_tab_value_space_cont_tab_value(c *check.C) {
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
		"28 29 29",
		"   08 36",
		"   08")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned to column 17 instead of 9.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"\\t\" with \"\\t\\t\".")
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
func (s *Suite) Test_VaralignBlock__var_tab8_value_var_tab16_value_var28_tab_value_space_cont_tabs32_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"WRKSRC=\t${WRKDIR}",
		"DISTFILES=\tdistfile-1.0.0.tar.gz",
		"SITES.distfile-1.0.0.tar.gz=\t${MASTER_SITES_SOURCEFORGE} \\",
		"\t\t\t\t${MASTER_SITES_GITHUB}")
	vt.InputDetab(
		"WRKSRC= ${WRKDIR}",
		"DISTFILES=      distfile-1.0.0.tar.gz",
		"SITES.distfile-1.0.0.tar.gz=    ${MASTER_SITES_SOURCEFORGE} \\",
		"                                ${MASTER_SITES_GITHUB}")
	vt.Internals(
		"07 08",
		"10 16",
		"28 32 60",
		"   32")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned to column 33 instead of 9.",
		"NOTE: Makefile:2: This variable value should be aligned to column 33 instead of 17.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"\\t\" with \"\\t\\t\\t\\t\".",
		"AUTOFIX: Makefile:2: Replacing \"\\t\" with \"\\t\\t\\t\".")
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
func (s *Suite) Test_VaralignBlock__var_tab8_value_var_tab16_value_var13_space_cont_indent34_value_space_cont_indent36_value_space_cont_indent34_value(c *check.C) {
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
		"13 14 14",
		"   34 45",
		"   36 46",
		"   34")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned to column 17 instead of 9.",
		"NOTE: Makefile:3: This variable value should be aligned with tabs, not spaces, to column 17 instead of 15.",
		"NOTE: Makefile:4: This continuation line should be indented with \"\\t\\t\".",
		"NOTE: Makefile:5: This continuation line should be indented with \"\\t\\t  \".",
		"NOTE: Makefile:6: This continuation line should be indented with \"\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"\\t\" with \"\\t\\t\".",
		"AUTOFIX: Makefile:3: Replacing \" \" with \"\\t\".",
		"AUTOFIX: Makefile:4: Replacing \"\\t\\t\\t\\t  \" with \"\\t\\t\".",
		"AUTOFIX: Makefile:5: Replacing \"\\t\\t\\t\\t    \" with \"\\t\\t  \".",
		"AUTOFIX: Makefile:6: Replacing \"\\t\\t\\t\\t  \" with \"\\t\\t\".")
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
		"13 34 45",
		"   36 46",
		"   34")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned to column 17 instead of 9.",
		"NOTE: Makefile:3: This variable value should be aligned with tabs, not spaces, to column 17 instead of 35.",
		"NOTE: Makefile:4: This continuation line should be indented with \"\\t\\t  \".",
		"NOTE: Makefile:5: This continuation line should be indented with \"\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"\\t\" with \"\\t\\t\".",
		"AUTOFIX: Makefile:3: Replacing \"\\t\\t\\t  \" with \"\\t\".",
		"AUTOFIX: Makefile:4: Replacing \"\\t\\t\\t\\t    \" with \"\\t\\t  \".",
		"AUTOFIX: Makefile:5: Replacing \"\\t\\t\\t\\t  \" with \"\\t\\t\".")
	vt.Fixed(
		"WRKSRC=         ${WRKDIR}",
		"DISTFILES=      distfile-1.0.0.tar.gz",
		"AWK_PROGRAM+=   /search/ { \\",
		"                  action(); \\",
		"                }")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__follow_up_indented_with_spaces(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"DISTFILES= \\",
		" one space \\",
		"   three spaces \\",
		"        eight spaces \\",
		"\tand a tab \\",
		"   ") // trailing whitespace
	vt.Internals(
		"10 11 11",
		"   01 11",
		"   03 16",
		"   08 21",
		"   08 18",
		"   03")
	vt.Diagnostics(
		"NOTE: Makefile:2: This continuation line should be indented with \"\\t\".",
		"NOTE: Makefile:3: This continuation line should be indented with \"\\t\".",
		"NOTE: Makefile:4: This continuation line should be indented with \"\\t\".")
	vt.Autofixes(
		"AUTOFIX: Makefile:2: Replacing \" \" with \"\\t\".",
		"AUTOFIX: Makefile:3: Replacing \"   \" with \"\\t\".",
		"AUTOFIX: Makefile:4: Replacing \"        \" with \"\\t\".")
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
// Therefore this existing indentation is used instead of the minimum
// necessary, which would only be a single tab.
func (s *Suite) Test_VaralignBlock__var_tabs24_value_var45_tab_value(c *check.C) {
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
func (s *Suite) Test_VaralignBlock__var_spaces24_value_space_cont_spaces24_value_var_spaces16_value_var_spaces24_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"DISTFILES=              ${DISTNAME}${EXTRACT_SUFX} frontiers.mp3 \\",
		"                        machine_wars.mp3 time_to_strike.mp3",
		".for file in frontiers.mp3 machine_wars.mp3 time_to_strike.mp3",
		"SITES.${file}=  http://asc-hq.org/",
		".endfor",
		"WRKSRC=                 ${WRKDIR}/${PKGNAME_NOREV}")
	vt.Internals(
		"10 24 65",
		"   24",
		"14 16",
		"07 24")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned with tabs, not spaces, to column 17 instead of 25.",
		"NOTE: Makefile:2: This continuation line should be indented with \"\\t\\t\".",
		"NOTE: Makefile:4: Variable values should be aligned with tabs, not spaces.",
		"NOTE: Makefile:6: This variable value should be aligned with tabs, not spaces, to column 17 instead of 25.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"              \" with \"\\t\".",
		"AUTOFIX: Makefile:2: Replacing \"                        \" with \"\\t\\t\".",
		"AUTOFIX: Makefile:4: Replacing \"  \" with \"\\t\".",
		"AUTOFIX: Makefile:6: Replacing \"                 \" with \"\\t\\t\".")
	vt.Fixed(
		"DISTFILES=      ${DISTNAME}${EXTRACT_SUFX} frontiers.mp3 \\",
		"                machine_wars.mp3 time_to_strike.mp3",
		".for file in frontiers.mp3 machine_wars.mp3 time_to_strike.mp3",
		"SITES.${file}=  http://asc-hq.org/",
		".endfor",
		"WRKSRC=         ${WRKDIR}/${PKGNAME_NOREV}")
	vt.Run()
}

// The CDROM variable aligns exactly at a tab position, therefore it must
// be indented by at least one more space. Since that one space is not
// enough to count as an outlier, each line is indented by one more tab.
func (s *Suite) Test_VaralignBlock__var_tab16_value_var16_space_value_var14_tab_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"RESTRICTED=\tDo not sell, do not rent",
		"NO_BIN_ON_CDROM= ${RESTRICTED}",
		"NO_BIN_ON_FTP=\t${RESTRICTED}")
	vt.Internals(
		"11 16",
		"16 17",
		"14 16")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned to column 25 instead of 17.",
		"NOTE: Makefile:2: This variable value should be aligned with tabs, not spaces, to column 25 instead of 18.",
		"NOTE: Makefile:3: This variable value should be aligned to column 25 instead of 17.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"\\t\" with \"\\t\\t\".",
		"AUTOFIX: Makefile:2: Replacing \" \" with \"\\t\".",
		"AUTOFIX: Makefile:3: Replacing \"\\t\" with \"\\t\\t\".")
	vt.Fixed(
		"RESTRICTED=             Do not sell, do not rent",
		"NO_BIN_ON_CDROM=        ${RESTRICTED}",
		"NO_BIN_ON_FTP=          ${RESTRICTED}")
	vt.Run()
}

// These variables all look nicely aligned, but they use spaces instead of tabs for alignment.
// The spaces are replaced with tabs, which makes the indentation 4 spaces deeper in the first paragraph.
// In the second paragraph it's even 7 additional spaces.
// This is ok though since it is the prevailing indentation style in pkgsrc.
func (s *Suite) Test_VaralignBlock__var16_space_value_var16_space_value_var16_space_value(c *check.C) {
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
		"NOTE: Makefile:1: This variable value should be aligned with tabs, not spaces, to column 25 instead of 18.",
		"NOTE: Makefile:2: This variable value should be aligned with tabs, not spaces, to column 25 instead of 18.",
		"NOTE: Makefile:3: This variable value should be aligned with tabs, not spaces, to column 25 instead of 18.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \" \" with \"\\t\".",
		"AUTOFIX: Makefile:2: Replacing \" \" with \"\\t\".",
		"AUTOFIX: Makefile:3: Replacing \" \" with \"\\t\".")
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
func (s *Suite) Test_VaralignBlock__var_spaces24_value_var_tabs24_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"DISTFILES+=             space",
		"DISTFILES+=\t\ttab")
	vt.Internals(
		"11 24",
		"11 24")
	vt.Diagnostics(
		"NOTE: Makefile:1: Variable values should be aligned with tabs, not spaces.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"             \" with \"\\t\\t\".")
	vt.Fixed(
		"DISTFILES+=             space",
		"DISTFILES+=             tab")
	vt.Run()
}

// Both lines are indented to the same column. Therefore none of them is considered an outlier.
func (s *Suite) Test_VaralignBlock__var2_space_value_var2_tab_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"V= value",
		"V=\tvalue")
	vt.Internals(
		"02 03",
		"02 08")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned with tabs, not spaces, to column 9 instead of 4.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \" \" with \"\\t\".")
	vt.Fixed(
		"V=      value",
		"V=      value")
	vt.Run()
}

// A single space that ends at the same depth as a tab is replaced with a tab, for consistency.
func (s *Suite) Test_VaralignBlock__var7_space_value_var2_tab_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"V.0008= value",
		"V=\tvalue")
	vt.Internals(
		"07 08",
		"02 08")
	vt.Diagnostics(
		"NOTE: Makefile:1: Variable values should be aligned with tabs, not spaces.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \" \" with \"\\t\".")
	vt.Fixed(
		"V.0008= value",
		"V=      value")
	vt.Run()
}

// A short line that is indented with a tab is aligned to a longer line
// that is indented with a space. This is because space-indented lines are
// only allowed when their indentation is much deeper than the tab-indented
// ones (so-called outliers), or as the first line of a continuation line.
func (s *Suite) Test_VaralignBlock__var8_space_value_var2_tab_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"V.00009= value",
		"V=\tvalue")
	vt.Internals(
		"08 09",
		"02 08")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned with tabs, not spaces, to column 17 instead of 10.",
		"NOTE: Makefile:2: This variable value should be aligned to column 17 instead of 9.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \" \" with \"\\t\".",
		"AUTOFIX: Makefile:2: Replacing \"\\t\" with \"\\t\\t\".")
	vt.Fixed(
		"V.00009=        value",
		"V=              value")
	vt.Run()
}

// This space-indented line doesn't count as an outlier yet because it
// is only a single tab away. The limit is two tabs.
// Therefore both lines are indented with tabs.
func (s *Suite) Test_VaralignBlock__var15_space_value_var2_tab_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"V.000000000016= value",
		"V=\tvalue")
	vt.Internals(
		"15 16",
		"02 08")
	vt.Diagnostics(
		"NOTE: Makefile:1: Variable values should be aligned with tabs, not spaces.",
		"NOTE: Makefile:2: This variable value should be aligned to column 17 instead of 9.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \" \" with \"\\t\".",
		"AUTOFIX: Makefile:2: Replacing \"\\t\" with \"\\t\\t\".")
	vt.Fixed(
		"V.000000000016= value",
		"V=              value")
	vt.Run()
}

// This space-indented line is an outlier since it is far enough from the
// tab-indented line. The latter would require 2 tabs to align to the former.
// Therefore the short line is not indented to the long line, in order to
// keep the indentation reasonably short for a large amount of the lines.
func (s *Suite) Test_VaralignBlock__var16_space_value_var2_tab_value(c *check.C) {
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
func (s *Suite) Test_VaralignBlock__var2_space_value_var9_tab_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"V= value",
		"V.000010=\tvalue")
	vt.Internals(
		"02 03",
		"09 16")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned with tabs, not spaces, to column 17 instead of 4.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \" \" with \"\\t\\t\".")
	vt.Fixed(
		"V=              value",
		"V.000010=       value")
	vt.Run()
}

// The long line is not an outlier but very close. One more space, and it would count.
func (s *Suite) Test_VaralignBlock__var22_space_value_var9_tab_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"V.0000000000000000023= value", // Adjust from 23 to 24 (+ 1 tab)
		"V.000010=\tvalue")             // Adjust from 16 to 24 (+ 1 tab)
	vt.Internals(
		"22 23",
		"09 16")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned with tabs, not spaces, to column 25 instead of 24.",
		"NOTE: Makefile:2: This variable value should be aligned to column 25 instead of 17.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \" \" with \"\\t\".",
		"AUTOFIX: Makefile:2: Replacing \"\\t\" with \"\\t\\t\".")
	vt.Fixed(
		"V.0000000000000000023=  value",
		"V.000010=               value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var23_space_value_var9_tab_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"V.00000000000000000024= value", // Keep at 24 (space to tab)
		"V.000010=\tvalue")              // Adjust from 16 to 24 (+ 1 tab)
	vt.Internals(
		"23 24",
		"09 16")
	vt.Diagnostics(
		"NOTE: Makefile:1: Variable values should be aligned with tabs, not spaces.",
		"NOTE: Makefile:2: This variable value should be aligned to column 25 instead of 17.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \" \" with \"\\t\".",
		"AUTOFIX: Makefile:2: Replacing \"\\t\" with \"\\t\\t\".")
	vt.Fixed(
		"V.00000000000000000024= value",
		"V.000010=               value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var24_space_value_var9_tab_value(c *check.C) {
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
func (s *Suite) Test_VaralignBlock__var_tabs24_value_var_tabs40_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"V.00008=\t\tvalue",     // Adjust from 24 to 16 (removes 1 tab)
		"V.00008=\t\t\t\tvalue") // Adjust from 40 to 16 (removes 3 tabs)
	vt.Internals(
		"08 24",
		"08 40")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned to column 17 instead of 25.",
		"NOTE: Makefile:2: This variable value should be aligned to column 17 instead of 41.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"\\t\\t\" with \"\\t\".",
		"AUTOFIX: Makefile:2: Replacing \"\\t\\t\\t\\t\" with \"\\t\".")
	vt.Fixed(
		"V.00008=        value",
		"V.00008=        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var_tab8_value_var29_spaces32_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"SHORT=\tvalue",
		"VERY_VERY_LONG_VARIABLE_NAME=   value")
	vt.Internals(
		"06 08",
		"29 32")
	vt.Diagnostics(
		"NOTE: Makefile:2: This outlier variable value should be aligned with a single space.")
	vt.Autofixes(
		"AUTOFIX: Makefile:2: Replacing \"   \" with \" \".")
	vt.Fixed(
		"SHORT=  value",
		"VERY_VERY_LONG_VARIABLE_NAME= value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var6_space_value_var10_tab_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"SHORT= value",
		"LONG_NAME=\tvalue")
	vt.Internals(
		"06 07",
		"10 16")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned with tabs, not spaces, to column 17 instead of 8.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \" \" with \"\\t\\t\".")
	vt.Fixed(
		"SHORT=          value",
		"LONG_NAME=      value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var6_tab_value_var21_none_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"SHORT=\tvalue",
		"LONG.678901234567890=value")
	vt.Internals(
		"06 08",
		"21 21")
	vt.Diagnostics(
		"NOTE: Makefile:2: This outlier variable value should be aligned with a single space.")
	vt.Autofixes(
		"AUTOFIX: Makefile:2: Replacing \"\" with \" \".")
	vt.Fixed(
		"SHORT=  value",
		"LONG.678901234567890= value")
	vt.Run()
}

// The INSTALLATION_DIRS line is so long that it is considered an outlier,
// since compared to the DIST line, it is at least two tabs away.
//
// Pkglint before 2018-01-26 suggested that it "should be aligned to column 9",
// which is not possible since the variable name is already longer.
func (s *Suite) Test_VaralignBlock__var_tab24_value_var_tab8_value(c *check.C) {
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
func (s *Suite) Test_VaralignBlock__var_tab32_value_var_tabs24_value_var_tabs24_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"INSPIRCD_STORAGE_DRIVER?=\tvalue",
		"MODULES+=\t\tvalue",
		"HEADERS+=\t\tvalue")
	vt.Internals(
		"25 32",
		"09 24",
		"09 24")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"INSPIRCD_STORAGE_DRIVER?=       value",
		"MODULES+=               value",
		"HEADERS+=               value")
	vt.Run()
}

// When all continuation lines are indented exactly one tab more than the
// initial line, this is intentional.
//
// TODO: Make this rule more general: if the indentation of the continuation
//  lines is more than the initial line, it is intentional.
func (s *Suite) Test_VaralignBlock__var_tab24_value_space_cont_tabs32_value_space_cont_tabs32_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"CONF_FILES_PERMS=\tsource \\",
		"\t\t\t\tdestination \\",
		"\t\t\t\tuser group 0644")
	vt.Internals(
		"17 24 31",
		"   32 44",
		"   32")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"CONF_FILES_PERMS=       source \\",
		"                                destination \\",
		"                                user group 0644")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var_tabs24_value_var_tab24_value_var_space_cont_tab_value_space_cont_tab_value_space_cont_tab_value(c *check.C) {
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
		"14 15 15",
		"   08 23",
		"   08 23",
		"   08")
	vt.Diagnostics(
		"NOTE: Makefile:3: This variable value should be aligned with tabs, not spaces, to column 25 instead of 16.")
	vt.Autofixes(
		"AUTOFIX: Makefile:3: Replacing \" \" with \"\\t\\t\".")
	vt.Fixed(
		"SUBST_CLASSES+=         fix",
		"SUBST_STAGE.fix=        post-patch",
		"SUBST_SED.fix=          \\",
		"        -e 's,1,one,g' \\",
		"        -e 's,2,two,g' \\",
		"        -e 's,3,three,g'")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__lead_var_tab8_value_lead_var_tab16_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"#VAR=\tvalue",
		"#VAR.param=\tvalue")
	vt.Internals(
		"05 08",
		"11 16")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned to column 17 instead of 9.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"\\t\" with \"\\t\\t\".")
	vt.Fixed(
		"#VAR=           value",
		"#VAR.param=     value")
	vt.Run()
}

// Before 19.3.6, pkglint would indent the last line in column 16.
//
// The value in the first line starts in column 16, which means that all
// follow-up lines should also start in column 16 or further to the right.
//
// Line 2 though is already quite long, and even though its right margin
// is in column 72, it needs to be indented at least as much as the value
// of the first line.
func (s *Suite) Test_VaralignBlock__var_tab_value63_space_cont_tab8_value71_space_cont_tab8_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"PROGFILES=\t67890 234567890 234567890 234567890 234567890 2 \\",
		"\t890 234567890 234567890 234567890 234567890 234567890 234567890 \\",
		"\tvalue")
	vt.Internals(
		"10 16 64",
		"   08 72",
		"   08")
	vt.Diagnostics(
		"NOTE: Makefile:2: This continuation line should be "+
			"indented with \"\\t\\t\".",
		"NOTE: Makefile:3: This continuation line should be "+
			"indented with \"\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: Makefile:2: Replacing \"\\t\" with \"\\t\\t\".",
		"AUTOFIX: Makefile:3: Replacing \"\\t\" with \"\\t\\t\".")
	vt.Fixed(
		"PROGFILES=      67890 234567890 234567890 234567890 234567890 2 \\",
		"                890 234567890 234567890 234567890 234567890 234567890 234567890 \\",
		"                value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__var8_tabs80_cont_tab_value_tabs72_cont_tab_value_tabs72_cont_tab_value9(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR...7=\t\t\t\t\t\t\t\t\t\\",
		"\t.\t\t\t\t\t\t\t\t\\",
		"\t.\t\t\t\t\t\t\t\t\\",
		"\t.")
	vt.InputDetab(
		"VAR...7=                                                                        \\",
		"        .                                                               \\",
		"        .                                                               \\",
		"        .")
	vt.Diagnostics(
		"NOTE: Makefile:1: The continuation backslash should be in column 73, not 81.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"\\t\\t\\t\\t\\t\\t\\t\\t\\t\" with \"\\t\\t\\t\\t\\t\\t\\t\\t\".")
	vt.Fixed(
		"VAR...7=                                                                \\",
		"        .                                                               \\",
		"        .                                                               \\",
		"        .")
	vt.Run()
}

// Up to 2020-01-27, pkglint removed all spaces before the backslash,
// which was against the rule of having at least one space.
func (s *Suite) Test_VaralignBlock__right_margin(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"CONFIGURE_ARGS+=\t\\",
		"\t.....................................................................79\t\\",
		"\t............................................................70 \t\t\\",
		"\t........................................................66")
	vt.Diagnostics(
		"NOTE: Makefile:2: The continuation backslash should be preceded by a single space.",
		"NOTE: Makefile:3: The continuation backslash should be in column 73, not 81.")
	vt.Autofixes(
		"AUTOFIX: Makefile:2: Replacing \"\\t\" with \" \".",
		"AUTOFIX: Makefile:3: Replacing \" \\t\\t\" with \"\\t\".")
	vt.Fixed(
		"CONFIGURE_ARGS+=        \\",
		"        .....................................................................79 \\",
		"        ............................................................70  \\",
		"        ........................................................66")
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
		"13 24 57",
		"   24 61",
		"   24 63",
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
		"DISTFILES= \\",
		"\ta \\",
		"\tb \\",
		"\tc \\",
		"", // This is the final line of the variable assignment.
		"NEXT_VAR=\tsecond line")
	vt.Internals(
		"10 11 11",
		"   08 10",
		"   08 10",
		"   08 10",
		"   00",
		"09 16")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned with tabs, not spaces, to column 17 instead of 12.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \" \" with \"\\t\".")
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
		"14 15 15",
		"   16",
		"16 17 17",
		"   01",
		"06 08")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned to column 17 instead of 9.",
		"NOTE: Makefile:3: This variable value should be aligned with tabs, not spaces, to column 17 instead of 16.",
		"NOTE: Makefile:6: This continuation line should be indented with \"\\t\\t\".",
		"NOTE: Makefile:7: This variable value should be aligned to column 17 instead of 9.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"\\t\" with \"\\t\\t\".",
		"AUTOFIX: Makefile:3: Replacing \" \" with \"\\t\".",
		"AUTOFIX: Makefile:6: Replacing \"\" with \"\\t\\t\".",
		"AUTOFIX: Makefile:7: Replacing \"\\t\" with \"\\t\\t\".")
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
		"11 12 12",
		"   08 15",
		"   08 15",
		"   08 15",
		"   00")
	vt.Diagnostics(
		"NOTE: Makefile:6: This continuation line should be indented with \"\\t\".")
	vt.Autofixes(
		"AUTOFIX: Makefile:6: Replacing \"\" with \"\\t\".")
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
		"13 24 30",
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
		"05 08 15",
		"   17")
	vt.Diagnostics(
		"NOTE: Makefile:3: This continuation line should be indented with \"\\t\\t \".")
	vt.Autofixes(
		"AUTOFIX: Makefile:3: Replacing \" \\t \\t \" with \"\\t\\t \".")
	vt.Fixed(
		"VAR1=   value1",
		"VAR2=   value2 \\",
		"                 value2 continued")
	vt.Run()
}

// The follow-up line is quite short in this case, therefore it is not
// necessary to indent it with a single tab. There's enough space to
// the right so that it can be aligned at the common alignment.
func (s *Suite) Test_VaralignBlock__long_line_followed_by_short_line_with_small_indentation(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR...........16+=\t....30........40........50........60........70 234567 \\",
		"\t\t..20........30")
	vt.Internals(
		"18 24 78",
		"   16")
	vt.Diagnostics(
		"NOTE: Makefile:2: This continuation line should be indented with \"\\t\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: Makefile:2: Replacing \"\\t\\t\" with \"\\t\\t\\t\".")
	vt.Fixed(
		"VAR...........16+=      ....30........40........50........60........70 234567 \\",
		"                        ..20........30")
	vt.Run()
}

// Continuation lines that are indented 2 tabs are obviously not
// space-constrained, otherwise they would use only a single tab.
// Therefore they have to be aligned with the other values.
func (s *Suite) Test_VaralignBlock__commented_cont_tab16(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"#SITES.long-distfile.tar.gz= \\",
		"#\t\t-https://example.org/",
		"#PATCH_DIST_STRIP=\t-p1")
	vt.Internals(
		"28 29 29",
		"   16",
		"18 24")
	vt.Diagnostics(
		"NOTE: Makefile:2: This continuation line should be indented with \"\\t\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: Makefile:2: Replacing \"\\t\\t\" with \"\\t\\t\\t\".")
	vt.Fixed(
		"#SITES.long-distfile.tar.gz= \\",
		"#                       -https://example.org/",
		"#PATCH_DIST_STRIP=      -p1")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__shift_already_long_line_to_the__right(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"INSTALLATION_DIRS+=\tvalue",
		"CONF_FILES=\t..20........30........40........50........60........70 \\",
		"\t\t..20")
	vt.Internals(
		"19 24",
		"11 16 71",
		"   16")
	vt.Diagnostics(
		"NOTE: Makefile:2: This variable value should be aligned to column 25 instead of 17.",
		"NOTE: Makefile:3: This continuation line should be indented with \"\\t\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: Makefile:2: Replacing \"\\t\" with \"\\t\\t\".",
		"AUTOFIX: Makefile:3: Replacing \"\\t\\t\" with \"\\t\\t\\t\".")
	vt.Fixed(
		"INSTALLATION_DIRS+=     value",
		"CONF_FILES=             ..20........30........40........50........60........70 \\",
		"                        ..20")
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

// Since CONF_FILES is a list of tuples, it makes sense to have different
// indentation for the two tuple elements.
func (s *Suite) Test_VaralignBlock__follow_up_indentation(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"EGDIR=\t\t\t${PREFIX}/share/examples/rtunes",
		"CONF_FILES=\t\t${EGDIR}/wrksrc.conf \\",
		"\t\t\t\t${PKG_SYSCONFDIR}/installed.conf",
		"EGDIR=\t\t\t${PREFIX}/share/examples/rtunes")
	vt.Internals(
		"06 24",
		"11 24 45",
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

// For shell commands, it makes sense to have the full flexibility of
// arbitrary indentation.
func (s *Suite) Test_VaralignBlock__staircase(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"JAM_COMMAND=\t\\",
		"\tcd ${WRKSRC} &&\t\t\t\t\t\t\t\\",
		"\t\t${SETENV} ${MY_ENV}\t\t\t\t\t\\",
		"\t\t\t${PREFIX}/bin/my-cmd\t\t\t\t\\",
		"\t\t\t\t-options arg...")
	vt.Internals(
		"12 16 16",
		"   08 72",
		"   16 72",
		"   24 72",
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

// The follow-up lines may only start in column 9 if they are longer than
// 72 characters. Since this is not the case in this test, they are realigned
// to match the initial line.
//
// Since the variable value is a shell command and the follow-up lines contain
// its arguments only, it would only be possible to indent them by one more
// tab. But that is probably getting too special-cased.
func (s *Suite) Test_VaralignBlock__command_with_arguments(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"SED_REPLACEMENT_CMD= ${SED} -n \\",
		"\t-e s,a,b, \\",
		"\t-e s,a,b, \\",
		"\t-e s,a,b,")
	vt.Internals(
		"20 21 31",
		"   08 18",
		"   08 18",
		"   08")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned with tabs, not spaces, to column 25 instead of 22.",
		"NOTE: Makefile:2: This continuation line should be indented with \"\\t\\t\\t\".",
		"NOTE: Makefile:3: This continuation line should be indented with \"\\t\\t\\t\".",
		"NOTE: Makefile:4: This continuation line should be indented with \"\\t\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \" \" with \"\\t\".",
		"AUTOFIX: Makefile:2: Replacing \"\\t\" with \"\\t\\t\\t\".",
		"AUTOFIX: Makefile:3: Replacing \"\\t\" with \"\\t\\t\\t\".",
		"AUTOFIX: Makefile:4: Replacing \"\\t\" with \"\\t\\t\\t\".")
	vt.Fixed(
		"SED_REPLACEMENT_CMD=    ${SED} -n \\",
		"                        -e s,a,b, \\",
		"                        -e s,a,b, \\",
		"                        -e s,a,b,")
	vt.Run()
}

// Variables with empty values and no comments are completely ignored,
// since they have nothing to be aligned with the other lines.
func (s *Suite) Test_VaralignBlock__empty_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"EMPTY_VALUE=",
		"VAR=\t\tvalue")
	vt.Internals(
		"04 16")
	vt.Diagnostics(
		nil...)
	vt.Autofixes(
		nil...)
	vt.Fixed(
		"EMPTY_VALUE=",
		"VAR=            value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__aligned(c *check.C) {
	t := s.Init(c)

	test := func(data ...interface{}) {
		lines, expected := t.SplitStringsBool(data)
		t.CheckDotColumns(lines...)

		mklines := t.NewMkLines("filename.mk",
			lines...)
		assert(len(mklines.mklines) == 1)

		var varalign VaralignBlock
		varalign.Process(mklines.mklines[0])
		varalign.Finish()

		output := t.Output()
		if expected {
			t.CheckEquals(output, "")
		} else if output == "" {
			t.Check(output, check.Not(check.Equals), "output should not be empty")
		}
	}

	// The first line uses a space for indentation, which is typical of
	// the outlier line in VaralignBlock.
	//
	// The second line starts in column 0, which is too far to the left.
	// For a human reader the second line looks like a variable assignment
	// of its own.
	test(
		"CONFIGURE_ENV+= \\",
		"AWK=${AWK:Q}",
		false)

	// The second line is indented and therefore visually distinct from
	// a Makefile assignment line. Everything's fine.
	test(
		"CONFIGURE_ENV+= \\",
		"\tAWK=${AWK:Q}",
		true)

	// The first line may also use a tab instead of a space for indentation.
	// This is typical of variable assignments whose name is short enough
	// to be aligned with the other lines.
	test(
		"CONFIGURE_ENV+=\t\\",
		"AWK=${AWK:Q}",
		false)
	test(
		"CONFIGURE_ENV+=\t\\",
		"\tAWK=${AWK:Q}",
		true)

	// The first line contains a value, and the second line has the same
	// indentation as the first line. This looks nicely aligned.
	test(
		"CONFIGURE_ENV+=\tAWK=${AWK:Q} \\",
		"\t\tSED=${SED:Q}",
		true)

	// The second line is indented less than the first line. This looks
	// confusing to the human reader because the actual values do not
	// appear in a rectangular shape in the source code.
	test(
		"VAR.param=\tvalue \\",
		"\t10........20........30........40........50........60..64",
		false)

	// The second line is indented with a single tab because otherwise
	// it would be longer than 72 characters. It could be argued that
	// in this case it is ok to use the smaller indentation. That would
	// make the indentation rules more complicated than necessary though.
	// If absolutely necessary, it is possible to use a continued line
	// with only the backslash in the first line. These may be indented
	// with a single tab.
	test(
		"VAR.param=\tvalue \\",
		"\t10........20........30........40........50........60...65",
		false)

	test(
		"VAR.param=\tvalue \\",
		"\t\t\t......32\t\t\t\t\t......80.",
		true)

	// Having the continuation line in column 0 looks even more confusing.
	test(
		"CONFIGURE_ENV+=\tAWK=${AWK:Q} \\",
		"SED=${SED:Q}",
		false)

	// Longer continuation lines may use internal indentation to represent
	// AWK or shell code.
	test(
		"GENERATE_PLIST+=\t/pattern/ { \\",
		"\t\t\t  action(); \\",
		"\t\t\t}",
		true)

	// If any of the continuation lines is indented less than the first
	// line, it looks confusing.
	test(
		"GENERATE_PLIST+=\t/pattern/ { \\",
		"\t  action(); \\",
		"\t}",
		false)

	// If the first line is empty, the indentation may start in column 8,
	// and the continuation lines have to be indented as least as far to
	// the right as the second line.
	test(
		"GENERATE_PLIST+= \\",
		"\t/pattern/ { \\",
		"\t  action(); \\",
		"\t}",
		true)

	// The very last line is indented at column 0, therefore the whole
	// line is not indented properly.
	test(
		"GENERATE_PLIST+= \\",
		"\t/pattern/ { \\",
		"\t  action(); \\",
		"}",
		false)

	// If there is no visible variable value at all, pkglint must not crash.
	// This case doesn't occur in practice since the code is usually
	// succinct enough to avoid these useless lines.
	//
	// The first line is empty, the second line is indented to column 8 and
	// the remaining lines are all indented by at least 8, therefore the
	// alignment is correct.
	//
	// A theoretical use case might be to have a long explaining comment
	// in the continuation lines, but that is not possible syntactically.
	// In the line "VAR= value \# comment", the \# is interpreted as
	// an escaped number sign, and not as a continuation marker followed
	// by a comment. In the line "VAR= value \ # comment", the backslash
	// is not a continuation marker as well, since it is not the very
	// last character of the line.
	test(
		"CONFIGURE_ENV+= \\",
		"\t\\",
		"\t\\",
		"\t# nothing",
		true)

	// Commented variable assignments can also be tested for alignment.
	test(
		"#CONFIGURE_ENV+= \\",
		"\tvalue",
		true)

	// In commented multilines, bmake doesn't care whether the
	// continuation lines does or doesn't start with a comment character.
	// For human readers though, it is confusing to omit the leading
	// comment character.
	//
	// For determining whether a multiline is aligned, the initial comment
	// character is ignored.
	test(
		"#CONFIGURE_ENV+= \\",
		"#\tvalue",
		true)

	// The indentation of the continuation line is neither 8 nor the
	// indentation of the first line. Therefore the line is not aligned.
	test(
		"#CONFIGURE_ENV+= value1 \\",
		"#\t\tvalue2",
		false)
}

// It's ok to have all backslashes in the same column, even if that column
// is not 73.
func (s *Suite) Test_VaralignBlock__continuation_backslashes_aligned(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR=\tvalue value value\t\\",
		"\tvalue\t\t\t\\",
		"\tvalue\t\t\t\\",
		"\tvalue")
	vt.Internals(
		"04 08 32",
		"   08 32",
		"   08 32",
		"   08")
	vt.Diagnostics(
		nil...)
	vt.Autofixes(
		nil...)
	vt.Fixed(
		"VAR=    value value value       \\",
		"        value                   \\",
		"        value                   \\",
		"        value")
	vt.Run()
}

// The backslash in the first line is separated by a single tab.
// This looks strange but pkglint considers it acceptable
// since there is a simple rule saying "a single tab is always ok".
// Any rule that would replace this simple rule
// would have to be similarly simple and intuitive.
func (s *Suite) Test_VaralignBlock__continuation_backslashes_aligned_except_initial(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR=\tvalue value value\t\\",
		"\tvalue\t\t\t\t\\",
		"\tvalue\t\t\t\t\\",
		"\tvalue")
	vt.Internals(
		"04 08 32",
		"   08 40",
		"   08 40",
		"   08")
	vt.Diagnostics(
		nil...)
	vt.Autofixes(
		nil...)
	// TODO: The backslashes should be aligned by a _simple_ rule.
	vt.Fixed(
		"VAR=    value value value       \\",
		"        value                           \\",
		"        value                           \\",
		"        value")
	vt.Run()
}

// Lines whose continuation backslash is indented by a single space are
// usually those that stick out further than column 73. These are not
// touched by the realignment.
func (s *Suite) Test_VaralignBlock__continuation_backslashes_one_sticks_out(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR=\tvalue\t\\",
		"\tvalue value value \\",
		"\tvalue\t\\",
		"\tvalue")
	vt.Internals(
		"04 08 16",
		"   08 26",
		"   08 16",
		"   08")
	vt.Diagnostics(
		nil...)
	vt.Autofixes(
		nil...)
	vt.Fixed(
		"VAR=    value   \\",
		"        value value value \\",
		"        value   \\",
		"        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__realign_continuation_backslashes(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR4567890.234567890=\t....30........40........50\t\t\t\\",
		"\t\t..20........30........40........50\t\t\t\\",
		"\t\t..20........30........40........50")
	vt.InputDetab(
		"VAR4567890.234567890=   ....30........40........50                      \\",
		"                ..20........30........40........50                      \\",
		"                ..20........30........40........50")
	vt.Internals(
		"21 24 72",
		"   16 72",
		"   16")
	vt.Diagnostics(
		"NOTE: Makefile:2: This continuation line should be indented with \"\\t\\t\\t\".",
		"NOTE: Makefile:3: This continuation line should be indented with \"\\t\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: Makefile:2: Replacing \"\\t\\t\" with \"\\t\\t\\t\".",
		"AUTOFIX: Makefile:2: Replacing \"\\t\\t\\t\\\\\" with \"\\t\\t\\\\\".",
		"AUTOFIX: Makefile:3: Replacing \"\\t\\t\" with \"\\t\\t\\t\".")
	vt.Fixed(
		"VAR4567890.234567890=   ....30........40........50                      \\",
		"                        ..20........30........40........50              \\",
		"                        ..20........30........40........50")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__initial_value_tab80(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VVVVVVVVVVVVVVVVVVV=\tvalue\t\t\t\t\t\t\t\\",
		"\t\t\tvalue\t\t\t\t\t\t\\",
		"\t\t\tvalue\t\t\t\t\t\t\\",
		"\t\t\tvalue")
	vt.Internals(
		"20 24 80",
		"   24 72",
		"   24 72",
		"   24")
	vt.Diagnostics(
		"NOTE: Makefile:1: The continuation backslash should be in column 73, not 81.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"\\t\\t\\t\\t\\t\\t\\t\" with \"\\t\\t\\t\\t\\t\\t\".")
	vt.Fixed(
		"VVVVVVVVVVVVVVVVVVV=    value                                           \\",
		"                        value                                           \\",
		"                        value                                           \\",
		"                        value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock__long_lines(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR=\t\t\t\t\t\tvalue\t\t \\",
		"\tvalue \t \\",
		"\tvalue")
	vt.Internals(
		"04 48 65",
		"   08 17",
		"   08")
	vt.Diagnostics(
		"NOTE: Makefile:1: The continuation backslash should be in column 57, not 66.",
		"NOTE: Makefile:2: This continuation line should be indented with \"\\t\\t\\t\\t\\t\\t\".",
		"NOTE: Makefile:3: This continuation line should be indented with \"\\t\\t\\t\\t\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"\\t\\t \" with \"\\t\".",
		"AUTOFIX: Makefile:2: Replacing \"\\t\" with \"\\t\\t\\t\\t\\t\\t\".",
		"AUTOFIX: Makefile:2: Replacing \" \\t \\\\\" with \" \\\\\".",
		"AUTOFIX: Makefile:3: Replacing \"\\t\" with \"\\t\\t\\t\\t\\t\\t\".")
	vt.Fixed(
		"VAR=                                            value   \\",
		"                                                value \\",
		"                                                value")
	vt.Run()
}

// A practical chaotic test case, derived from wip/compat32_mit-krb5/Makefile.
// It made pkglint before 2019-09-03 panic.
func (s *Suite) Test_VaralignBlock__long_lines_2(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"INSTALLATION_DIRS=\t......32......40......48......56......64......72......80......88.....   \\"+
			"\t\t\t\t ....136.....144.....152.....160.....168.....176.....184...\t\t \\",
		"\t\t\t......32......40......48......56......64......72......80..\t\t       \t\\",
		"\t\t\t......32......40......48......56......64......72......80..\t\t       \t\\",
		"\t\t\t......32......40......48.")
	vt.InputDetab(
		"INSTALLATION_DIRS=      ......32......40......48......56......64......72......80......88.....   \\"+
			"                                ....136.....144.....152.....160.....168.....176.....184...              \\",
		"                        ......32......40......48......56......64......72......80..                      \\",
		"                        ......32......40......48......56......64......72......80..                      \\",
		"                        ......32......40......48.")
	vt.Internals(
		"18 24 201",
		"   24 104",
		"   24 104",
		"   24")
	vt.Diagnostics(
		"NOTE: Makefile:1: The continuation backslash should be preceded by a single space.",
		"NOTE: Makefile:2: The continuation backslash should be preceded by a single space.",
		"NOTE: Makefile:3: The continuation backslash should be preceded by a single space.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"\\t\\t \" with \" \".",
		"AUTOFIX: Makefile:2: Replacing \"\\t\\t       \\t\" with \" \".",
		"AUTOFIX: Makefile:3: Replacing \"\\t\\t       \\t\" with \" \".")
	vt.Fixed(
		"INSTALLATION_DIRS=      ......32......40......48......56......64......72......80......88.....   \\"+
			"                                ....136.....144.....152.....160.....168.....176.....184... \\",
		"                        ......32......40......48......56......64......72......80.. \\",
		"                        ......32......40......48......56......64......72......80.. \\",
		"                        ......32......40......48.")
	vt.Run()
}

// Each MkLine has its own right margin.
// As of December 2019, it is ok when these are not aligned per paragraph.
func (s *Suite) Test_VaralignBlock__right_margin_in_adjacent_lines(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR1=\t\\",
		"\t......16\t\t\\",
		"\t......16\t\t\\",
		"\t......16",
		"VAR2=\t\\",
		"\t......16\t\t\t\\",
		"\t......16\t\t\t\\",
		"\t......16")
	vt.InputDetab(
		"VAR1=   \\",
		"        ......16                \\",
		"        ......16                \\",
		"        ......16",
		"VAR2=   \\",
		"        ......16                        \\",
		"        ......16                        \\",
		"        ......16")
	vt.Internals(
		"05 08 08",
		"   08 32",
		"   08 32",
		"   08",
		"05 08 08",
		"   08 40",
		"   08 40",
		"   08")
	vt.Diagnostics(
		nil...)
	vt.Autofixes(
		nil...)
	vt.Fixed(
		"VAR1=   \\",
		"        ......16                \\",
		"        ......16                \\",
		"        ......16",
		"VAR2=   \\",
		"        ......16                        \\",
		"        ......16                        \\",
		"        ......16")
	vt.Run()
}

// This code comes from usr.bin/make/unit-tests/varcmd.mk.
// Its purpose is unclear and irrelevant for this test.
// The two .ifmake directives are unknown to pkglint since they are not
// used in pkgsrc.
// The variable assignments are not aligned.  That's good, but why?
// It might be because of the unknown '.ifmake' or for a completely
// different reason.
//
// Yes, it is because '.ifmake' is not a known directive, therefore
// VaralignBlock.Process does not classify it as IsDirective and skips
// the block.
func (s *Suite) Test_VaralignBlock__unknown_line_format(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		".ifmake two",
		"# this should not work",
		"FU+= oops",
		"FOO+= oops",
		"_FU:= ${FU}",
		"_FOO:= ${FOO}",
		"two: immutable",
		"immutable:",
		"\t:",
		".endif",
		".ifmake four",
		"VAR=Internal",
		".MAKEOVERRIDES+= VAR",
		".endif")
	vt.Diagnostics(
		"ERROR: Makefile:1: Unknown Makefile line format: \".ifmake two\".",
		"ERROR: Makefile:11: Unknown Makefile line format: \".ifmake four\".")
	vt.Autofixes(
		nil...)
	vt.Fixed(
		".ifmake two",
		"# this should not work",
		"FU+= oops",
		"FOO+= oops",
		"_FU:= ${FU}",
		"_FOO:= ${FOO}",
		"two: immutable",
		"immutable:",
		"        :",
		".endif",
		".ifmake four",
		"VAR=Internal",
		".MAKEOVERRIDES+= VAR",
		".endif")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock_Process__var_spaces7_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR=   value")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned with tabs, not spaces, to column 9 instead of 8.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"   \" with \"\\t\".")
	vt.Fixed(
		"VAR=    value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock_Process__var_spaces8_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR=    value")
	vt.Diagnostics(
		"NOTE: Makefile:1: Variable values should be aligned with tabs, not spaces.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"    \" with \"\\t\".")
	vt.Fixed(
		"VAR=    value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock_Process__var_spaces9_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR=     value")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned with tabs, not spaces, to column 9 instead of 10.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"     \" with \"\\t\".")
	vt.Fixed(
		"VAR=    value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock_Process__var_st8_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR= \tvalue")
	vt.Diagnostics(
		"NOTE: Makefile:1: Variable values should be aligned with tabs, not spaces.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \" \\t\" with \"\\t\".")
	vt.Fixed(
		"VAR=    value")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock_Process__var_ssst8_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR=   \tvalue")
	vt.Diagnostics(
		"NOTE: Makefile:1: Variable values should be aligned with tabs, not spaces.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"   \\t\" with \"\\t\".")
	vt.Fixed(
		"VAR=    value")
	vt.Run()
}

// Since the variable is visually aligned at column 17, the alignment
// is kept at that depth, although a smaller indentation were possible.
func (s *Suite) Test_VaralignBlock_Process__var_sssst16_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR=    \tvalue")
	vt.Diagnostics(
		"NOTE: Makefile:1: Variable values should be aligned with tabs, not spaces.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"    \\t\" with \"\\t\\t\".")
	vt.Fixed(
		"VAR=            value")
	vt.Run()
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
		"NOTE: file.mk:2: This variable value should be aligned with tabs, not spaces, to column 9 instead of 17.",
		"NOTE: file.mk:3: This variable value should be aligned to column 9 instead of 33.")
}

// For every variable assignment, there is at least one space or tab between the variable
// name and the value. Even if it is the longest line, and even if the value would start
// exactly at a tab stop.
func (s *Suite) Test_VaralignBlock_Process__longest_line_no_space(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"SUBST_CLASSES+= 123456",
		"SUBST_STAGE.123456= pre-configure",
		"SUBST_FILES.123456= *.pl",
		"SUBST_FILTER_CMD.123456=cat")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned "+
			"with tabs, not spaces, to column 33 instead of 17.",
		"NOTE: Makefile:2: This variable value should be aligned "+
			"with tabs, not spaces, to column 33 instead of 21.",
		"NOTE: Makefile:3: This variable value should be aligned "+
			"with tabs, not spaces, to column 33 instead of 21.",
		"NOTE: Makefile:4: This variable value should be aligned "+
			"to column 33 instead of 25.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \" \" with \"\\t\\t\\t\".",
		"AUTOFIX: Makefile:2: Replacing \" \" with \"\\t\\t\".",
		"AUTOFIX: Makefile:3: Replacing \" \" with \"\\t\\t\".",
		"AUTOFIX: Makefile:4: Replacing \"\" with \"\\t\".")
	vt.Fixed(
		"SUBST_CLASSES+=                 123456",
		"SUBST_STAGE.123456=             pre-configure",
		"SUBST_FILES.123456=             *.pl",
		"SUBST_FILTER_CMD.123456=        cat")
	vt.Run()
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
		"NOTE: file.mk:1: This variable value should be aligned with tabs, not spaces, to column 33 instead of 17.",
		"NOTE: file.mk:2: This variable value should be aligned with tabs, not spaces, to column 33 instead of 23.",
		"NOTE: file.mk:3: This variable value should be aligned with tabs, not spaces, to column 33 instead of 23.",
		"NOTE: file.mk:4: This variable value should be aligned with tabs, not spaces, to column 33 instead of 28.")
}

func (s *Suite) Test_VaralignBlock_processVarassign__comment_with_continuation(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR.param= # comment \\",
		"#\tthe comment continues")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned with tabs, not spaces, to column 17 instead of 12.",
		"NOTE: Makefile:2: This continuation line should be indented with \"\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \" \" with \"\\t\".",
		"AUTOFIX: Makefile:2: Replacing \"\\t\" with \"\\t\\t\".")
	vt.Fixed(
		"VAR.param=      # comment \\",
		"#               the comment continues")
	vt.Run()
}

func (s *Suite) Test_VaralignBlock_Finish__continuation_beyond_right_margin(c *check.C) {
	vt := NewVaralignTester(s, c)

	vt.Input(
		"VAR....8......16..=\t\t......40......48.\t\t\t\t\\",   // column 80
		"\t\t\t......32......40......48......56......64..\t\\", // column 72
		"\t\t\t...29")
	vt.InputDetab(
		"VAR....8......16..=             ......40......48.                               \\",
		"                        ......32......40......48......56......64..      \\",
		"                        ...29")
	vt.Diagnostics(
		// XXX: In this case, it would also help to reduce the indentation
		//  of the variable value.
		"NOTE: Makefile:1: The continuation backslash should be "+
			"in column 73, not 81.",
		"NOTE: Makefile:2: This continuation line should be "+
			"indented with \"\\t\\t\\t\\t\".",
		"NOTE: Makefile:3: This continuation line should be "+
			"indented with \"\\t\\t\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"\\t\\t\\t\\t\" with \"\\t\\t\\t\".",
		"AUTOFIX: Makefile:2: Replacing \"\\t\\t\\t\" with \"\\t\\t\\t\\t\".",
		"AUTOFIX: Makefile:2: Replacing \"\\t\\\\\" with \" \\\\\".",
		"AUTOFIX: Makefile:3: Replacing \"\\t\\t\\t\" with \"\\t\\t\\t\\t\".")
	vt.Fixed(
		"VAR....8......16..=             ......40......48.                       \\",
		"                                ......32......40......48......56......64.. \\",
		"                                ...29")
	vt.Run()
}

func (s *Suite) Test_varalignLine_realignDetails(c *check.C) {
	vt := NewVaralignTester(s, c)

	// Just a random example to exercise some of the code paths,
	// with no particular intention.
	vt.Input(
		"VAR=\t\tvalue",
		"VAR= \\",
		"\t\t    ..24 \\",
		"\t..12")
	vt.Diagnostics(
		"NOTE: Makefile:2: This variable value should be aligned "+
			"with tabs, not spaces, to column 17 instead of 6.",
		"NOTE: Makefile:3: This continuation line should be indented with \"\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: Makefile:2: Replacing \" \" with \"\\t\\t\".",
		"AUTOFIX: Makefile:3: Replacing \"\\t\\t    \" with \"\\t\\t\".")
	vt.Fixed(
		"VAR=            value",
		"VAR=            \\",
		"                ..24 \\",
		"        ..12")
	vt.Run()
}

func (s *Suite) Test_VaralignSplitter_split(c *check.C) {
	t := s.Init(c)

	test := func(rawText string, initial bool, expected varalignParts) {
		actual := NewVaralignSplitter().split(rawText, initial)

		t.CheckEquals(actual, expected)
		t.CheckEquals(
			actual.leadingComment+actual.varnameOp+
				actual.spaceBeforeValue+actual.value+
				actual.spaceAfterValue+actual.continuation,
			rawText)
	}

	// This case is prevented from occurring in practice by the guard
	// code in VaralignBlock.processVarassign, see INCLUSION_GUARD_MK.
	test("VAR=", true,
		varalignParts{
			leadingComment:   "",
			varnameOp:        "VAR=",
			spaceBeforeValue: "",
			value:            "",
			spaceAfterValue:  "",
			continuation:     ""})

	test("VAR=value", true,
		varalignParts{
			leadingComment:   "",
			varnameOp:        "VAR=",
			spaceBeforeValue: "",
			value:            "value",
			spaceAfterValue:  "",
			continuation:     ""})

	test("#VAR=value", true,
		varalignParts{
			leadingComment:   "#",
			varnameOp:        "VAR=",
			spaceBeforeValue: "",
			value:            "value",
			spaceAfterValue:  "",
			continuation:     ""})

	test("#VAR = value # comment \\", true,
		varalignParts{
			leadingComment:   "#",
			varnameOp:        "VAR =",
			spaceBeforeValue: " ",
			value:            "value # comment",
			spaceAfterValue:  " ",
			continuation:     "\\"})

	test("VAR=value \\", true,
		varalignParts{
			leadingComment:   "",
			varnameOp:        "VAR=",
			spaceBeforeValue: "",
			value:            "value",
			spaceAfterValue:  " ",
			continuation:     "\\"})

	test("VAR=value # comment \\", true,
		varalignParts{
			leadingComment:   "",
			varnameOp:        "VAR=",
			spaceBeforeValue: "",
			value:            "value # comment",
			spaceAfterValue:  " ",
			continuation:     "\\"})

	test("VAR=value # comment \\\\", true,
		varalignParts{
			leadingComment:   "",
			varnameOp:        "VAR=",
			spaceBeforeValue: "",
			value:            "value # comment \\\\",
			spaceAfterValue:  "",
			continuation:     ""})

	test("VAR=\\# a [#] b # comment \\\\", true,
		varalignParts{
			leadingComment:   "",
			varnameOp:        "VAR=",
			spaceBeforeValue: "",
			value:            "\\# a [#] b # comment \\\\",
			spaceAfterValue:  "",
			continuation:     ""})

	test("VAR.${param:[#]}=\tvalue", true,
		varalignParts{
			leadingComment:   "",
			varnameOp:        "VAR.${param:[#]}=",
			spaceBeforeValue: "\t",
			value:            "value",
			spaceAfterValue:  "",
			continuation:     ""})

	test("VAR=value", true,
		varalignParts{
			leadingComment:   "",
			varnameOp:        "VAR=",
			spaceBeforeValue: "",
			value:            "value",
			spaceAfterValue:  "",
			continuation:     ""})

	// Since this is a follow-up line, the text ends up in the variable
	// value, and varnameOp is necessarily empty.
	test("VAR=value", false,
		varalignParts{
			leadingComment:   "",
			varnameOp:        "",
			spaceBeforeValue: "",
			value:            "VAR=value",
			spaceAfterValue:  "",
			continuation:     ""})

	// In some edge cases the variable name is indented with ordinary spaces.
	// This must not lead to a panic.
	test("   VAR=value", true,
		varalignParts{
			leadingComment:   "   ",
			varnameOp:        "VAR=",
			spaceBeforeValue: "",
			value:            "value",
			spaceAfterValue:  "",
			continuation:     ""})

	// And in really edgy cases, the leading space may even be followed by tabs.
	// This should not happen in practice since it is really confusing.
	test(" \t VAR=value", true,
		varalignParts{
			leadingComment:   " \t ",
			varnameOp:        "VAR=",
			spaceBeforeValue: "",
			value:            "value",
			spaceAfterValue:  "",
			continuation:     ""})

	test("    value", false,
		varalignParts{
			leadingComment:   "",
			varnameOp:        "",
			spaceBeforeValue: "    ",
			value:            "value",
			spaceAfterValue:  "",
			continuation:     ""})

	// In practice it doesn't really happen that the last line of a file
	// ends in a backslash and at the same time it doesn't have the usual
	// newline ending.
	test("    value \\", false,
		varalignParts{
			leadingComment:   "",
			varnameOp:        "",
			spaceBeforeValue: "    ",
			value:            "value",
			spaceAfterValue:  " ",
			continuation:     "\\"})

	// A follow-up line may start with a comment character. There are
	// two possible interpretations:
	//
	// 1. It is a leading comment, and the rest of the line is parsed
	// as usual.
	//
	// 2. It is a continuation of the value, and therefore the value ends
	// here; everything below this line is part of the trailing comment.
	//
	// The character that follows the comment character decides which
	// interpretation is used. A space makes the comment a trailing
	// comment since that's the way these trailing comments typically look.
	// Any other character makes it a leading comment.

	test("#\tcomment", false,
		varalignParts{
			leadingComment:   "#",
			varnameOp:        "",
			spaceBeforeValue: "\t",
			value:            "comment",
			spaceAfterValue:  "",
			continuation:     ""})

	test("#\tcomment \\", false,
		varalignParts{
			leadingComment:   "#",
			varnameOp:        "",
			spaceBeforeValue: "\t",
			value:            "comment",
			spaceAfterValue:  " ",
			continuation:     "\\"})

	test("# comment", false,
		varalignParts{
			leadingComment:   "",
			varnameOp:        "",
			spaceBeforeValue: "",
			value:            "# comment",
			spaceAfterValue:  "",
			continuation:     ""})

	test("# comment \\", false,
		varalignParts{
			leadingComment:   "",
			varnameOp:        "",
			spaceBeforeValue: "",
			value:            "# comment",
			spaceAfterValue:  " ",
			continuation:     "\\"})

	// Commented variable assignments are only valid if they
	// directly follow the comment sign.
	//
	// It is a programming error if such a line is ever added to
	// the VaralignBlock.
	t.ExpectAssert(
		func() { test("#  VAR=    value", true, varalignParts{}) })

	t.ExpectAssert(
		func() { test("VAR=\tvalue\n", true, varalignParts{}) })
}

func (s *Suite) Test_varalignMkLine_rightMargin(c *check.C) {
	t := s.Init(c)

	test := func(common bool, expectedRightMargin int, lines ...string) {
		t.CheckDotColumns(lines...)
		mklines := t.NewMkLines("filename.mk",
			lines...)

		var block VaralignBlock
		mklines.ForEach(func(mkline *MkLine) {
			block.Process(mkline)
		})

		t.CheckLen(block.mkinfos, 1)
		for _, mkinfo := range block.mkinfos {
			actualCommon, actualMargin := mkinfo.rightMargin()
			t.CheckDeepEquals(
				[]interface{}{actualCommon, actualMargin},
				[]interface{}{common, expectedRightMargin})
		}
	}

	// Lines without continuation don't have a right margin.
	test(false, 0,
		"VAR=\t...13")

	// Lines with a needless continuation also don't have a right margin.
	// The backslash in the first line is ignored completely since it
	// is commonly aligned at a different position than the other
	// backslashes. Either with a single space (which wouldn't matter
	// anyway) or with some tabs to the column of the variable value.
	test(false, 0,
		"VAR=\t\\",
		"\tvalue")

	test(false, 0,
		"VAR=\t\t\t\\",
		"\tvalue")

	// Single spaces are ignored since they do not explicitly express
	// the intention to draw a common right margin.
	test(false, 0,
		"VAR= \\",
		"\t......16........26 \\",
		"\tvalue")

	// Single tabs take part in the right margin since they are already
	// aligned at a multiple of 8. Pkglint therefore assumes that it is
	// intended to have a common right margin.
	//
	// There is no common margin, and the minimum necessary margin is 32.
	test(false, 32,
		"VAR=\t\\",
		"\t\\",
		"\t......16........26\t\\",
		"\tvalue")

	// The first line is ignored since it is empty, which leaves only
	// a single remaining line. That is not enough to decide whether
	// a right margin is really intended (or is it?), therefore no
	// right margin is assumed.
	test(false, 0,
		"VAR=\t\\",
		"\t......16........26\t\\",
		"\tvalue")

	// In long lines, the backslash is usually separated by a single
	// space and is therefore ignored.
	// All remaining backslashes (there is only 1) are aligned in the
	// same column.
	//
	// XXX: Why is 1 relevant backslash not enough?
	test(false, 0,
		"VAR=\t\t\\",
		"\t......16......24......32......40 \\",
		"\tvalue")

	// Again, the first line is ignored, and each remaining line has
	// the backslash in a different position. This means no common
	// margin.
	test(false, 0,
		"VAR=\t\t\\",
		"\t\t\\",
		"\t......16......24......32......40 \\",
		"\tvalue")

	// When there are at least 2 relevant backslashes, they produce a
	// right margin.
	test(true, 16,
		"VAR=\t...13\t\\",
		"\t\t\\",
		"\t......16......24......32......40 \\",
		"\tvalue")

	// If a long line uses a tab (and thereby becomes longer than
	// strictly necessary), that is a sign that the line is not
	// thought to be overly long, therefore it is probably desired
	// to align all lines in that column.
	test(false, 48,
		"VAR=\t...13\t\\",
		"\t......16......24......32......40\t\\",
		"\t...13")

	// If the relevant backslashes are in different columns, there is
	// no common right margin.
	test(false, 16,
		"VAR=\t...13\t\\",   // column 16
		"\t...13\t\t\t\t\\", // column 40
		"\t...13")

	// It doesn't matter whether the backslash is aligned using spaces
	// or tabs, as they are visually the same.
	test(false, 16,
		"VAR=    ...13   \\", // column 16
		"\t...13\t\t\t\t\\",  // column 40
		"\t...13")

	// The common right margin is determined by starting from the right
	// and searching until there are at least 2 lines having the same
	// right margin.
	test(false, 40,
		"VAR=\t\\",          // column 16
		"\tv\t\t\t\t\t\\",   // column 48
		"\tv\t\t\t\\",       // column 32
		"\tv\t\t\t\t\\",     // column 40
		"\tv\t\t\t\t\t\t\\", // column 56
		"\tv\t\t\t\t\\",     // column 40, for the second time
		"\tv\t\t\\",         // column 24
		"\tv")

	// All backslashes are in different columns.
	// Therefore, suggest the minimum possible column for the backslashes.
	test(false, 16,
		"VAR=\t\\",          // column 16
		"\tv\t\t\t\t\t\\",   // column 48
		"\tv\t\t\t\\",       // column 32
		"\tv\t\t\t\t\\",     // column 40
		"\tv\t\t\t\t\t\t\\", // column 56
		"\tv\t\t\\",         // column 24
		"\tv")

	// The decision of choosing column 24 may feel somewhat arbitrary,
	// but this whole situation is artificially constructed anyway.
	//
	// The intention of choosing the largest column with at least two
	// backslashes is simply that this will fix most practical occurrences
	// where most of the backslashes are already aligned in that column,
	// and only a few are in column 64.
	test(false, 24,
		"VAR=\t\\",                         // column 16
		"\tv\t\t\t\\",                      // column 32
		"\tv\t\t\t\t\\",                    // column 40
		"\t......16......24......32\t\t\\", // column 48
		"\tv\t\t\\",                        // column 24
		"\tv\t\t\\",                        // column 24, appears twice
		"\tv")

	// The reasonable maximum value for the right margin is 72 since
	// that column is the last that is still visible on an 80x25 display.
	test(false, 72,
		"VAR=\t\\",                    // column 16
		"\tv\t\t\t\t\t\t\t\t\t\t\t\\", // column 96
		"\tv\t\t\t\t\t\t\t\t\t\t\t\\", // column 96
		"\tv\t\t\t\t\t\t\t\t\t\t\t\\", // column 96
		"\tv\t\t\t\t\t\t\t\t\t\t\t\\", // column 96
		"\tv\t\t\t\t\\",               // column 40
		"\tv\t\t\\",                   // column 24
		"\tv\t\t\\",                   // column 24, appears twice
		"\tv")

	// The continuation backslash in the first line is too far to the right.
	test(false, 72,
		"VAR....8......16..=\t\t......40......48.\t\t\t\t\\",   // column 80
		"\t\t\t......32......40......48......56......64..\t\\", // column 72
		"\t\t\t...29")

	// If the right margin lies completely off-screen (that is, beyond
	// column 72), it counts as a right margin, but not as canonical.
	// The preferred right margin is shifted left to column 72,
	// to make it actually visible.
	test(false, 72,
		"VAR=\t\\",                    // column 16
		"\tv\t\t\t\t\t\t\t\t\t\t\t\\", // column 96
		"\tv\t\t\t\t\t\t\t\t\t\t\t\\", // column 96
		"\tv\t\t\t\t\t\t\t\t\t\t\t\\", // column 96
		"\tv\t\t\t\t\t\t\t\t\t\t\t\\", // column 96
		"\tv")
}

func (s *Suite) Test_varalignLine_alignValueSingle(c *check.C) {
	t := s.Init(c)

	test := func(before string, column int, after string, diagnostics ...string) {

		doTest := func(autofix bool) {
			t.CheckDotColumns(before)
			mkline := t.NewMkLine("filename.mk", 123, before)
			parts := NewVaralignSplitter().split(before, true)
			info := &varalignLine{mkline, 0, false, parts}

			info.alignValueSingle(column)

			t.CheckEqualsf(
				mkline.RawText(0), after,
				"Line.raw.text, autofix=%v", autofix)
			t.CheckEqualsf(info.String(), after,
				"info.String, autofix=%v", autofix)
		}

		t.ExpectDiagnosticsAutofix(doTest, diagnostics...)
	}

	// The variable value is already in column 8, thus nothing to fix.
	test(
		"VAR=\tvalue",
		8,

		"VAR=\tvalue",
		nil...)

	// Aligned to the wrong column, using only tabs.
	test(
		"VAR=\tvalue",
		16,

		"VAR=\t\tvalue",
		"NOTE: filename.mk:123: This variable value "+
			"should be aligned to column 17 instead of 9.",
		"AUTOFIX: filename.mk:123: Replacing \"\\t\" with \"\\t\\t\".")

	// Aligned to the wrong column, using a mixture of tabs and spaces.
	test(
		"VAR=\t    value",
		16,

		"VAR=\t\tvalue",
		"NOTE: filename.mk:123: This variable value "+
			"should be aligned with tabs, not spaces, to column 17 instead of 13.",
		"AUTOFIX: filename.mk:123: Replacing \"\\t    \" with \"\\t\\t\".")

	// Correct column, but using spaces for indentation.
	test(
		"VAR=  \t    \tvalue",
		16,

		"VAR=\t\tvalue",
		"NOTE: filename.mk:123: Variable values "+
			"should be aligned with tabs, not spaces.",
		"AUTOFIX: filename.mk:123: Replacing \"  \\t    \\t\" with \"\\t\\t\".")

	// If the value is indented more than necessary, the redundant
	// indentation is dropped.
	test(
		"VAR=\t\t\t\t\tvalue",
		8,

		"VAR=\tvalue",
		"NOTE: filename.mk:123: "+
			"This variable value should be aligned to column 9 instead of 41.",
		"AUTOFIX: filename.mk:123: Replacing \"\\t\\t\\t\\t\\t\" with \"\\t\".")

	// An outlier should use a single space, to be as far to the
	// left as possible.
	//
	// XXX: Why is this line not considered an outlier?
	//  info.isCanonicalInitial returns true for it.
	test(
		"VAR....8......16......24......32=\t\t\t\t\tvalue",
		8,

		"VAR....8......16......24......32=\t\t\t\t\tvalue",
		nil...)

	// An outlier should use a single space, to be as far to the
	// left as possible.
	test(
		"VAR....8......16......24......32=\t\t\t \t\tvalue",
		8,

		"VAR....8......16......24......32= value",
		"NOTE: filename.mk:123: This outlier variable value "+
			"should be aligned with a single space.",
		"AUTOFIX: filename.mk:123: Replacing \"\\t\\t\\t \\t\\t\" with \" \".")
}

func (s *Suite) Test_varalignLine_alignValueInitial__empty(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"VAR=\t${VAR}",
		"LONG_VARIABLE_NAME=    \t        \\",
		"\t${LONG_VARIABLE_NAME}")

	mklines.Check()

	t.CheckOutputLines(
		"NOTE: filename.mk:3: The continuation backslash should be preceded by a single space or tab.")
}

func (s *Suite) Test_varalignLine_alignValueInitial__empty_spaces(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR=    \\",
		"\tvalue",
		// This line is necessary to trigger the realignment; see VaralignBlock.Finish.
		"VAR= value")
	vt.Internals(
		"04 08 08",
		"   08",
		"04 05")
	vt.Diagnostics(
		"NOTE: Makefile:1: Variable values should be aligned with tabs, not spaces.",
		"NOTE: Makefile:3: This variable value should be aligned with tabs, not spaces, to column 9 instead of 6.")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"    \" with \"\\t\".",
		"AUTOFIX: Makefile:3: Replacing \" \" with \"\\t\".")
	vt.Fixed(
		"VAR=    \\",
		"        value",
		"VAR=    value")
	vt.Run()
}

func (s *Suite) Test_varalignLine_alignValueInitial__spaces(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR=    value1 \\",
		"        value2")
	vt.Internals(
		"04 08 15",
		"   08")
	vt.Diagnostics(
		"NOTE: Makefile:1: Variable values should be aligned with tabs, not spaces.",
		"NOTE: Makefile:2: This continuation line should be indented with \"\\t\".")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"    \" with \"\\t\".",
		"AUTOFIX: Makefile:2: Replacing \"        \" with \"\\t\".")
	vt.Fixed(
		"VAR=    value1 \\",
		"        value2")
	vt.Run()
}

func (s *Suite) Test_varalignLine_alignValueInitial(c *check.C) {
	t := s.Init(c)

	test := func(before string, column int, after string, diagnostics ...string) {
		t.CheckDotColumns(before)

		doTest := func(autofix bool) {
			mklines := t.NewMkLines("filename.mk",
				before,
				"\t...13")
			assert(len(mklines.mklines) == 1)
			mkline := mklines.mklines[0]

			text := mkline.RawText(0)
			parts := NewVaralignSplitter().split(text, true)
			info := &varalignLine{mkline, 0, false, parts}

			info.alignValueInitial(column)

			t.CheckEqualsf(
				mkline.RawText(0), after,
				"Line.raw.text, autofix=%v", autofix)

			t.CheckEqualsf(info.String(), after,
				"info.String, autofix=%v", autofix)
		}

		t.ExpectDiagnosticsAutofix(doTest, diagnostics...)
	}

	// The value is already in column 8, thus nothing to do.
	test(
		"VAR=\tvalue \\",
		8,

		"VAR=\tvalue \\",
		nil...)

	test(
		"VAR=\tvalue \\",
		16,

		"VAR=\t\tvalue \\",
		"NOTE: filename.mk:1: This variable value should be aligned to column 17 instead of 9.",
		"AUTOFIX: filename.mk:1: Replacing \"\\t\" with \"\\t\\t\".")

	// The column is already correct,
	// but the alignment should be done with tabs, not spaces.
	test(
		"VAR=  \t  \tvalue \\",
		16,

		"VAR=\t\tvalue \\",
		"NOTE: filename.mk:1: Variable values should be aligned with tabs, not spaces.",
		"AUTOFIX: filename.mk:1: Replacing \"  \\t  \\t\" with \"\\t\\t\".")

	// Both the column and the use of spaces in the alignment
	// need to be fixed.
	test(
		"VAR=  \t    value \\",
		16,

		"VAR=\t\tvalue \\",
		"NOTE: filename.mk:1: This variable value should be aligned with tabs, not spaces, to column 17 instead of 13.",
		"AUTOFIX: filename.mk:1: Replacing \"  \\t    \" with \"\\t\\t\".")
}

// This example is quite unrealistic since typically the first line is
// the least indented.
//
// All follow-up lines are indented with at least one tab, to make clear
// they are continuation lines.
func (s *Suite) Test_varalignLine_alignValueMultiFollow__unrealistic(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR= \\",
		"        value1 \\",
		"          value2 \\",
		"      value3 \\",
		"value4 \\",
		"\\",
		"# comment")
	vt.Internals(
		"04 05 05",
		"   08 15",
		"   10 17",
		"   06 13",
		"   00 07",
		"   00 00",
		"   00")
	vt.Diagnostics(
		"NOTE: Makefile:2: This continuation line should be indented with \"\\t\".",
		"NOTE: Makefile:3: This continuation line should be indented with \"\\t  \".",
		"NOTE: Makefile:4: This continuation line should be indented with \"\\t\".",
		"NOTE: Makefile:5: This continuation line should be indented with \"\\t\".",
		"NOTE: Makefile:6: This continuation line should be indented with \"\\t\".",
		"NOTE: Makefile:7: This continuation line should be indented with \"\\t\".")
	vt.Autofixes(
		"AUTOFIX: Makefile:2: Replacing \"        \" with \"\\t\".",
		"AUTOFIX: Makefile:3: Replacing \"          \" with \"\\t  \".",
		"AUTOFIX: Makefile:4: Replacing \"      \" with \"\\t\".",
		"AUTOFIX: Makefile:5: Replacing \"\" with \"\\t\".",
		"AUTOFIX: Makefile:6: Replacing \"\" with \"\\t\".",
		"AUTOFIX: Makefile:7: Replacing \"\" with \"\\t\".")
	vt.Fixed(
		"VAR= \\",
		"        value1 \\",
		"          value2 \\",
		"        value3 \\",
		"        value4 \\",
		"        \\",
		"        # comment")
	vt.Run()
}

func (s *Suite) Test_varalignLine_alignValueMultiFollow(c *check.C) {
	t := s.Init(c)

	// newLine creates a line consisting of either 2 or 3 physical lines.
	// The given text ends up in the raw line with index 1.
	newLine := func(text string, column, indentDiff int) (*varalignLine, *MkLine) {
		t.CheckDotColumns("", text)

		leading := alignWith("VAR=", indent(column)) + "value \\"
		trailing := indent(column) + "trailing"
		n := condInt(hasSuffix(text, "\\"), 3, 2)
		lines := []string{leading, text, trailing}[:n]

		mklines := t.NewMkLines("filename.mk",
			lines...)
		assert(len(mklines.mklines) == 1)
		mkline := mklines.mklines[0]

		parts := NewVaralignSplitter().split(text, false)
		return &varalignLine{mkline, 1, false, parts}, mkline
	}

	test := func(before string, column, indentDiff int, after string, diagnostics ...string) {

		doTest := func(autofix bool) {
			info, mkline := newLine(before, column, indentDiff)
			width := imax(column, info.valueColumn()+indentDiff)

			info.alignValueMultiFollow(width)

			t.CheckEquals(mkline.RawText(1), after)
		}

		t.ExpectDiagnosticsAutofix(
			doTest,
			diagnostics...)
	}

	test(
		"value", 24, 0,
		"\t\t\tvalue",

		"NOTE: filename.mk:2: This continuation line should be "+
			"indented with \"\\t\\t\\t\".",
		"AUTOFIX: filename.mk:2: Replacing \"\" with \"\\t\\t\\t\".")

	test(
		"value \\", 24, 0,
		"\t\t\tvalue \\",

		"NOTE: filename.mk:2: This continuation line should be "+
			"indented with \"\\t\\t\\t\".",
		"AUTOFIX: filename.mk:2: Replacing \"\" with \"\\t\\t\\t\".")

	test(
		"value   \\", 24, 0,
		"\t\t\tvalue \\",

		"NOTE: filename.mk:2: This continuation line should be "+
			"indented with \"\\t\\t\\t\".",
		"AUTOFIX: filename.mk:2: Replacing \"\" with \"\\t\\t\\t\".",
		"AUTOFIX: filename.mk:2: Replacing \"   \\\\\" with \" \\\\\".")

	// The position of the continuation backslash is preserved.
	test(
		"value\t\t\t\t\t\t\\", 24, 0,
		"\t\t\tvalue\t\t\t\\",

		"NOTE: filename.mk:2: This continuation line should be indented "+
			"with \"\\t\\t\\t\".",
		"AUTOFIX: filename.mk:2: Replacing \"\" with \"\\t\\t\\t\".",
		"AUTOFIX: filename.mk:2: "+
			"Replacing \"\\t\\t\\t\\t\\t\\t\\\\\" "+
			"with \"\\t\\t\\t\\\\\".")

	test(
		"value\t\t\t\t\t\t\t\t\t\\", 24, 0,
		"\t\t\tvalue\t\t\t\t\t\t\\",

		"NOTE: filename.mk:2: This continuation line should be indented "+
			"with \"\\t\\t\\t\".",
		"AUTOFIX: filename.mk:2: Replacing \"\" with \"\\t\\t\\t\".",
		"AUTOFIX: filename.mk:2: "+
			"Replacing \"\\t\\t\\t\\t\\t\\t\\t\\t\\t\\\\\" "+
			"with \"\\t\\t\\t\\t\\t\\t\\\\\".")

	// If the value is so wide that the continuation backslash cannot
	// be kept in column 72, the line is still adjusted, and the
	// continuation backslash is separated with a single space.
	test(
		"value\t\t\t\t\t\t\t......64\t\\", 24, 0,
		"\t\t\tvalue\t\t\t\t\t\t\t......64 \\",

		"NOTE: filename.mk:2: This continuation line should be indented with \"\\t\\t\\t\".",
		"AUTOFIX: filename.mk:2: Replacing \"\" with \"\\t\\t\\t\".",
		"AUTOFIX: filename.mk:2: Replacing \"\\t\\\\\" with \" \\\\\".")

	// The indentation of the continuation backslash is even preserved
	// when it is not aligned with tabs only but with spaces.
	test(
		"value\t\t\t\t\t\t   \\", 24, 0,
		"\t\t\tvalue\t\t\t   \\",

		"NOTE: filename.mk:2: This continuation line should be indented "+
			"with \"\\t\\t\\t\".",
		"AUTOFIX: filename.mk:2: Replacing \"\" with \"\\t\\t\\t\".",
		"AUTOFIX: filename.mk:2: "+
			"Replacing \"\\t\\t\\t\\t\\t\\t   \\\\\" "+
			"with \"\\t\\t\\t   \\\\\".")

	// Since the value is shifted to the right, the position of the
	// continuation backslash cannot be preserved, therefore it is
	// shifted to the right along with the value.
	test(
		"value \\", 24, 0,
		"\t\t\tvalue \\",

		"NOTE: filename.mk:2: This continuation line should be indented "+
			"with \"\\t\\t\\t\".",
		"AUTOFIX: filename.mk:2: Replacing \"\" with \"\\t\\t\\t\".")

	// The second line is indented deeper (40) than the first line (24).
	// Assuming that the relative indentation was intended, it is preserved.
	test(
		"\t\t\t\t\t...45 \\", 24, 0,
		"\t\t\t\t\t...45 \\",

		nil...)

	// The second line is indented deeper (35) than the first line (24).
	// It uses tabs and spaces for indentation.
	// Assuming that the relative indentation was intended, it is preserved.
	test(
		"\t\t\t\t   ...40 \\", 24, 0,
		"\t\t\t\t   ...40 \\",

		nil...)

	// The value is missing in this line, there is only the continuation
	// backslash. It is preserved as well.
	test(
		"\t\t\t\t   \\", 24, 0,
		"\t\t\t\t   \\",

		nil...)

	// If the indentation is not in the canonical form, it is corrected.
	test(
		"\t   \t\t\t   \\", 24, 0,
		"\t\t\t\t   \\",

		// The diagnostic is carefully chosen to just say how this
		// particular line should be indented. It does not mention the rule
		// that the indentation should be preferably tabs and up to 7 spaces.
		//
		// Above all, the diagnostic does not say "be indented with tabs",
		// as that would be wrong for follow-up lines.
		"NOTE: filename.mk:2: This continuation line should be indented with \"\\t\\t\\t\\t   \".",
		"AUTOFIX: filename.mk:2: Replacing \"\\t   \\t\\t\\t   \" with \"\\t\\t\\t\\t   \".")
}

func (s *Suite) Test_varalignLine_alignValueMultiFollow__unindent_long_lines(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"SHORT=\tvalue",
		"PROGRAM_AWK=\t\t\t\t........50........60........70 \\",
		"\t\t\t\t\t\t\t\t\t3                \\",
		"\t\t\t\t\t\t\t\t\t74               \\",
		"\t\t\t\t\t\t\t\t\t-75  \t\t\t  \\",
		"\t\t\t\t\t\t\t\t\t..76 \\",
		"\t\t\t\t\t\t\t\t66 \\",
		"\t\t\t\t\t\t\t\t1")
	vt.InputDetab(
		"SHORT=  value",
		"PROGRAM_AWK=                            ........50........60........70 \\",
		"                                                                        3                \\",
		"                                                                        74               \\",
		"                                                                        -75                       \\",
		"                                                                        ..76 \\",
		"                                                                66 \\",
		"                                                                1")
	vt.Internals(
		"06 08",
		"12 40 71",
		"   72 89",
		"   72 89",
		"   72 98",
		"   72 77",
		"   64 67",
		"   64")
	vt.Diagnostics(
		"NOTE: Makefile:1: This variable value should be aligned to column 17 instead of 9.",
		"NOTE: Makefile:2: This variable value should be aligned to column 17 instead of 41.",
		"NOTE: Makefile:3: This continuation line should be indented with \"\\t\\t\\t\\t\\t\\t\".",
		"NOTE: Makefile:4: This continuation line should be indented with \"\\t\\t\\t\\t\\t\\t\".",
		"NOTE: Makefile:5: This continuation line should be indented with \"\\t\\t\\t\\t\\t\\t\".",
		"NOTE: Makefile:6: This continuation line should be indented with \"\\t\\t\\t\\t\\t\\t\".",
		"NOTE: Makefile:7: This continuation line should be indented with \"\\t\\t\\t\\t\\t\".",
		"NOTE: Makefile:8: This continuation line should be indented with \"\\t\\t\\t\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"\\t\" with \"\\t\\t\".",
		"AUTOFIX: Makefile:2: Replacing \"\\t\\t\\t\\t\" with \"\\t\".",
		"AUTOFIX: Makefile:3: Replacing \"\\t\\t\\t\\t\\t\\t\\t\\t\\t\" with \"\\t\\t\\t\\t\\t\\t\".",
		"AUTOFIX: Makefile:3: Replacing \"                \\\\\" with \"\\t\\t\\t\\\\\".",
		"AUTOFIX: Makefile:4: Replacing \"\\t\\t\\t\\t\\t\\t\\t\\t\\t\" with \"\\t\\t\\t\\t\\t\\t\".",
		"AUTOFIX: Makefile:4: Replacing \"               \\\\\" with \"\\t\\t\\t\\\\\".",
		"AUTOFIX: Makefile:5: Replacing \"\\t\\t\\t\\t\\t\\t\\t\\t\\t\" with \"\\t\\t\\t\\t\\t\\t\".",
		"AUTOFIX: Makefile:5: Replacing \"  \\t\\t\\t  \\\\\" with \"\\t\\t\\t\\\\\".",
		"AUTOFIX: Makefile:6: Replacing \"\\t\\t\\t\\t\\t\\t\\t\\t\\t\" with \"\\t\\t\\t\\t\\t\\t\".",
		"AUTOFIX: Makefile:7: Replacing \"\\t\\t\\t\\t\\t\\t\\t\\t\" with \"\\t\\t\\t\\t\\t\".",
		"AUTOFIX: Makefile:8: Replacing \"\\t\\t\\t\\t\\t\\t\\t\\t\" with \"\\t\\t\\t\\t\\t\".")
	vt.Fixed(
		// After shifting the lines to the left, none of the lines is
		// considered "long" anymore, therefore the backslashes are not
		// kept in column 72. Nevertheless they look unorganized right now.
		"SHORT=          value",
		"PROGRAM_AWK=    ........50........60........70 \\",
		"                                                3                       \\",
		"                                                74                      \\",
		"                                                -75                     \\",
		"                                                ..76 \\",
		"                                        66 \\",
		"                                        1")
	vt.Run()
}

// In this example, the continued lines are indented less than the line
// containing the first value. This is not the common style, therefore all
// continuation lines are aligned to the value of the first line.
func (s *Suite) Test_varalignLine_alignValueMultiFollow__unindent_long_initial_line(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR.....10!=\t\t....30........40........50....56\t\t\t\\",
		"\t\t    ........30........40.\t\t\t\t\\",
		"\t\t    ........30........40........50........60......68\t\\",
		"\t\t    ...25\t\t\t\t\t\t\\",
		"\t\t-7")
	vt.InputDetab(
		"VAR.....10!=            ....30........40........50....56                        \\",
		"                    ........30........40.                               \\",
		"                    ........30........40........50........60......68    \\",
		"                    ...25                                               \\",
		"                -7")
	vt.Internals(
		"12 24 80",
		"   20 72",
		"   20 72",
		"   20 72",
		"   16")
	vt.Diagnostics(
		"NOTE: Makefile:1: The continuation backslash should be in column 73, not 81.",
		"NOTE: Makefile:2: This continuation line should be indented with \"\\t\\t\\t\".",
		"NOTE: Makefile:3: This continuation line should be indented with \"\\t\\t\\t\".",
		"NOTE: Makefile:4: This continuation line should be indented with \"\\t\\t\\t\".",
		"NOTE: Makefile:5: This continuation line should be indented with \"\\t\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: Makefile:1: Replacing \"\\t\\t\\t\" with \"\\t\\t\".",
		"AUTOFIX: Makefile:2: Replacing \"\\t\\t    \" with \"\\t\\t\\t\".",
		"AUTOFIX: Makefile:3: Replacing \"\\t\\t    \" with \"\\t\\t\\t\".",
		"AUTOFIX: Makefile:3: Replacing \"\\t\\\\\" with \" \\\\\".",
		"AUTOFIX: Makefile:4: Replacing \"\\t\\t    \" with \"\\t\\t\\t\".",
		"AUTOFIX: Makefile:5: Replacing \"\\t\\t\" with \"\\t\\t\\t\".")
	vt.Fixed(
		"VAR.....10!=            ....30........40........50....56                \\",
		"                        ........30........40.                           \\",
		"                        ........30........40........50........60......68 \\",
		"                        ...25                                           \\",
		"                        -7")
	vt.Run()
}

func (s *Suite) Test_varalignLine_alignValue(c *check.C) {
	t := s.Init(c)

	test := func(before string, column int, after string, diagnostics ...string) {
		t.CheckDotColumns(before)

		doTest := func(autofix bool) {
			mklines := t.NewMkLines("filename.mk",
				before,
				"\t...13")
			assert(len(mklines.mklines) == 1)
			mkline := mklines.mklines[0]

			text := mkline.RawText(0)
			parts := NewVaralignSplitter().split(text, true)
			info := &varalignLine{mkline, 0, false, parts}

			info.alignValue(column)

			t.CheckEqualsf(
				mkline.RawText(0), after,
				"Line.raw.text, autofix=%v", autofix)

			t.CheckEqualsf(info.String(), after,
				"info.String, autofix=%v", autofix)
		}

		t.ExpectDiagnosticsAutofix(doTest, diagnostics...)
	}

	testAssert := func(before string, column int) {
		t.CheckDotColumns(before)

		doTest := func(autofix bool) {
			mklines := t.NewMkLines("filename.mk",
				before,
				"\t...13")
			assert(len(mklines.mklines) == 1)
			mkline := mklines.mklines[0]

			text := mkline.RawText(0)
			parts := NewVaralignSplitter().split(text, true)
			info := &varalignLine{mkline, 0, false, parts}

			t.ExpectAssert(
				func() { info.alignValue(column) })

			t.CheckEqualsf(
				mkline.RawText(0), before,
				"Line.raw.text, autofix=%v", autofix)

			t.CheckEqualsf(info.String(), before,
				"info.String, autofix=%v", autofix)
		}

		t.ExpectDiagnosticsAutofix(doTest, nil...)
	}

	// The value is already in column 8, thus nothing to do.
	testAssert(
		"VAR=\tvalue \\",
		8)

	test(
		"VAR=\tvalue \\",
		16,

		"VAR=\t\tvalue \\",
		"NOTE: filename.mk:1: This variable value should be aligned to column 17 instead of 9.",
		"AUTOFIX: filename.mk:1: Replacing \"\\t\" with \"\\t\\t\".")

	// The column is already correct,
	// but the alignment should be done with tabs, not spaces.
	test(
		"VAR=  \t  \tvalue \\",
		16,

		"VAR=\t\tvalue \\",
		"NOTE: filename.mk:1: Variable values should be aligned with tabs, not spaces.",
		"AUTOFIX: filename.mk:1: Replacing \"  \\t  \\t\" with \"\\t\\t\".")

	// Both the column and the use of spaces in the alignment
	// need to be fixed.
	test(
		"VAR=  \t    value \\",
		16,

		"VAR=\t\tvalue \\",
		"NOTE: filename.mk:1: This variable value should be aligned with tabs, not spaces, to column 17 instead of 13.",
		"AUTOFIX: filename.mk:1: Replacing \"  \\t    \" with \"\\t\\t\".")
}

// The seemingly empty line 3 is actually a continuation from the line above it.
// Its indentation is is not fixed since that would lead to trailing whitespace.
func (s *Suite) Test_varalignLine_alignFollow(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR=\t\t...21 \\",
		"\t\t...21 \\",
		"")
	vt.InputDetab(
		"VAR=            ...21 \\",
		"                ...21 \\",
		"")
	vt.Diagnostics(
		nil...)
	vt.Autofixes(
		nil...)
	vt.Fixed(
		"VAR=            ...21 \\",
		"                ...21 \\",
		"")
	vt.Run()
}

func (s *Suite) Test_varalignLine_alignContinuation(c *check.C) {
	t := s.Init(c)

	lines := func(lines ...string) []string { return lines }
	test := func(before []string, rawIndex, valueColumn, rightMarginColumn int, after string, diagnostics ...string) {
		t.CheckDotColumns(before...)

		doTest := func(autofix bool) {
			mklines := t.NewMkLines("filename.mk", before...)
			assert(len(mklines.mklines) == 1)
			mkline := mklines.mklines[0]

			text := mkline.RawText(rawIndex)
			parts := NewVaralignSplitter().split(text, rawIndex == 0)
			info := &varalignLine{mkline, rawIndex, false, parts}

			info.alignContinuation(valueColumn, rightMarginColumn)

			t.CheckEqualsf(
				mkline.RawText(rawIndex), after,
				"Line.raw.text, autofix=%v", autofix)

			t.CheckEqualsf(info.String(), after,
				"info.String, autofix=%v", autofix)
		}

		t.ExpectDiagnosticsAutofix(doTest, diagnostics...)
	}

	// In this line, there is no continuation backslash,
	// thus nothing to align.
	test(
		lines(
			"VAR=\t...13"),
		0, 32, 48,

		"VAR=\t...13",
		nil...)

	// The continuation backslash in line 1 is already canonical,
	// independently of the alignment column for the variable values.
	//
	// XXX: Maybe later enforce the continuation backslash to be
	//  aligned at newWidth.
	test(
		lines(
			"VAR=\t...13 \\",
			"\t...13"),
		0, 32, 48,

		"VAR=\t...13 \\",
		nil...)

	// In line 2, there is no continuation backslash,
	// thus nothing to align.
	test(
		lines(
			"VAR=\t...13 \\",
			"\t...13"),
		1, 32, 48,

		"\t...13",
		nil...)

	// A single tab before the continuation backslash is always
	// considered canonical, thus nothing to align.
	//
	// XXX: Why? It would be better to force the tab to the valueColumn.
	test(
		lines(
			"VAR=\t...13\t\\",
			"\t...13"),
		0, 32, 48,

		"VAR=\t...13\t\\",
		nil...)

	// Column 24 is left of the valueAlign,
	// therefore there is nothing to align.
	//
	// XXX: Why? It would be better to force the tab to the valueColumn.
	test(
		lines(
			"VAR=\t...13\t\t\\",
			"\t...13"),
		0, 32, 48,

		"VAR=\t...13\t\t\\",
		nil...)

	// Column 32 is the valueColumn, therefore there is nothing to align.
	test(
		lines(
			"VAR=\t...13\t\t\t\\",
			"\t...13"),
		0, 32, 48,

		"VAR=\t...13\t\t\t\\",
		nil...)

	// Column 40 is somewhere between the valueColumn and the right margin
	// of the MkLine and is thus arbitrary.
	// It is aligned to the right margin.
	test(
		lines(
			"VAR=\t...13\t\t\t\t\\",
			"\t...13"),
		0, 32, 48,

		"VAR=\t...13\t\t\t\t\t\\",
		"NOTE: filename.mk:1: "+
			"The continuation backslash should be in column 49, not 41.",
		"AUTOFIX: filename.mk:1: Replacing \"\\t\\t\\t\\t\" "+
			"with \"\\t\\t\\t\\t\\t\".")

	// Column 48 is already at the right margin, thus nothing to align.
	test(
		lines(
			"VAR=\t......16......24......32\t\t\\",
			"\t...13"),
		0, 32, 48,

		"VAR=\t......16......24......32\t\t\\",
		nil...)

	// Column 56 is right of the right margin.
	// It is reduced to the right margin.
	test(
		lines(
			"VAR=\t......16......24\t\t\t\t\\",
			"\t...13"),
		0, 32, 48,

		"VAR=\t......16......24\t\t\t\\",
		"NOTE: filename.mk:1: "+
			"The continuation backslash should be in column 49, not 57.",
		"AUTOFIX: filename.mk:1: Replacing \"\\t\\t\\t\\t\" "+
			"with \"\\t\\t\\t\".")

	// Column 72 is the "natural" column for continuation backslashes,
	// therefore there is nothing to align.
	test(
		lines(
			"VAR=\t...13\t\t\t\t\t\t\t\t\\",
			"\t...13"),
		0, 32, 48,

		"VAR=\t...13\t\t\t\t\t\t\t\t\\",
		nil...)

	// If the value itself forces the continuation backslash to be beyond
	// column 72, the continuation backslash should only be separated by
	// a single space, to keep it as close to the text as possible.
	test(
		lines(
			"VAR=\t...13\t\t\t\t\t\t\t\t...77\t\\",
			"\t...13"),
		0, 32, 48,

		"VAR=\t...13\t\t\t\t\t\t\t\t...77 \\",
		"NOTE: filename.mk:1: The continuation backslash should be "+
			"preceded by a single space.",
		"AUTOFIX: filename.mk:1: Replacing \"\\t\" with \" \".")

	test(
		lines(
			"VAR=\t...13\t\t\t\t\t\t\t\t...77\t\t\t\\",
			"\t...13"),
		0, 32, 48,

		"VAR=\t...13\t\t\t\t\t\t\t\t...77 \\",
		"NOTE: filename.mk:1: The continuation backslash should be "+
			"preceded by a single space.",
		"AUTOFIX: filename.mk:1: Replacing \"\\t\\t\\t\" with \" \".")
}

func (s *Suite) Test_varalignLine_replaceSpaceBeforeValue(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--autofix", "--show-autofix")
	mklines := t.NewMkLines("filename.mk",
		"VAR=  \t  value")
	line := mklines.lines.Lines[0]
	parts := NewVaralignSplitter().split(line.RawText(0), true)
	info := varalignLine{line, 0, false, parts}
	fix := line.Autofix()
	fix.Warnf("Warning.")

	info.replaceSpaceBeforeValue(fix, "\t\t")
	fix.Apply()

	t.CheckOutputLines(
		"WARN: filename.mk:1: Warning.",
		"AUTOFIX: filename.mk:1: Replacing \"  \\t  \" with \"\\t\\t\".")
}

func (s *Suite) Test_varalignLine_replaceSpaceBeforeContinuationSilently(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--autofix", "--show-autofix")
	mklines := t.NewMkLines("filename.mk",
		"VAR=  \t  value   \\",
		"\\tend")
	line := mklines.lines.Lines[0]
	parts := NewVaralignSplitter().split(line.RawText(0), true)
	info := varalignLine{line, 0, false, parts}
	fix := line.Autofix()
	fix.Warnf("Warning.")

	info.replaceSpaceBeforeContinuationSilently(fix, 32)
	fix.Apply()

	t.CheckOutputLines(
		"WARN: filename.mk:1: Warning.",
		"AUTOFIX: filename.mk:1: Replacing \"   \\\\\" with \"\\t\\t\\t\\\\\".")

	t.CheckOutputEmpty()
}

func (s *Suite) Test_varalignLine_explainWrongColumn(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("filename.mk", 123, "")
	fix := mkline.Autofix()
	fix.Notef("Note.")
	(*varalignLine)(nil).explainWrongColumn(fix)
	fix.Apply()

	t.CheckOutputLines(
		"NOTE: filename.mk:123: Note.")
	t.CheckEquals(G.Logger.explanationsAvailable, true)
}

// This constellation doesn't occur in practice because the code in
// VaralignBlock.processVarassign skips it, see INCLUSION_GUARD_MK.
func (s *Suite) Test_varalignParts_isEmptyContinuation__edge_case(c *check.C) {
	t := s.Init(c)

	parts := NewVaralignSplitter().split("VAR=", true)

	t.CheckEquals(parts.isEmptyContinuation(), false)
}

// I've never seen an intentionally continued comment in practice,
// but pkglint needs to be able to handle this situation anyway.
func (s *Suite) Test_varalignParts_spaceBeforeContinuation__continued_comment(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR=\tvalue # comment \\",
		"\tstill comment \\",
		"\tand still")
	vt.Internals(
		"04 08 24",
		"   08 22",
		"   08")
	vt.Diagnostics(
		nil...)
	vt.Autofixes(
		nil...)
	vt.Fixed(
		"VAR=    value # comment \\",
		"        still comment \\",
		"        and still")
	vt.Run()
}

func (s *Suite) Test_varalignParts_spaceBeforeContinuationIndex__assertion(c *check.C) {
	t := s.Init(c)

	test := func(value, continuation string) {
		parts := varalignParts{value: value, continuation: continuation}

		t.ExpectAssert(
			func() { _ = parts.spaceBeforeContinuationIndex() })
	}

	test("", "")
	test("value", "")
	test("", "\\")
}

// This test runs isCanonicalInitial directly since as of August 2019
// that function is only used in a single place, and from this place
// varnameOpSpaceWidth is always bigger than width.
func (s *Suite) Test_varalignParts_isCanonicalInitial(c *check.C) {
	t := s.Init(c)

	var v varalignLine
	v.varnameOp = "LONG.123456789="
	v.spaceBeforeValue = " "
	t.CheckEquals(v.isCanonicalInitial(16), false)

	v.varnameOp = "LONG.1234567890="

	t.CheckEquals(v.isCanonicalInitial(16), true)

	v.spaceBeforeValue = ""

	t.CheckEquals(v.isCanonicalInitial(16), false)
}

func (s *Suite) Test_varalignParts_isCanonicalFollow(c *check.C) {
	t := s.Init(c)

	test := func(comment, space string, expected bool) {
		l := varalignLine{
			varalignParts: varalignParts{
				leadingComment:   comment,
				spaceBeforeValue: space}}

		actual := l.isCanonicalFollow()

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

func (s *Suite) Test_varalignParts_isTooLongFor(c *check.C) {
	t := s.Init(c)

	test := func(valueColumn int, value, continuation string, tooLong bool) {
		t.CheckDotColumns(indent(valueColumn) + value)

		parts := varalignParts{value: value, continuation: continuation}
		t.CheckEquals(parts.isTooLongFor(valueColumn), tooLong)
	}

	// In lines without continuation backslash,
	// the value may go up to the continuation backslash.
	test(64, ".......73", "", false)
	test(64, "........74", "", true)

	// In lines with continuation backslash,
	// the value including a space and the continuation backslash
	// may go up to column 73.
	test(64, ".....71", "\\", false)
	test(64, "......72", "\\", true)
}
