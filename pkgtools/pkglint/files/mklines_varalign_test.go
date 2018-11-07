package main

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
	diagnostics []string // The expected diagnostics in default mode
	autofixes   []string // The expected diagnostics in --autofix mode
	fixed       []string // The expected fixed lines, with spaces instead of tabs
	source      bool
}

func NewVaralignTester(s *Suite, c *check.C) *VaralignTester {
	t := s.Init(c)

	return &VaralignTester{suite: s, tester: t}
}

// Input remembers the input lines that are checked and possibly realigned.
func (vt *VaralignTester) Input(lines ...string) { vt.input = lines }

// Diagnostics remembers the expected diagnostics.
func (vt *VaralignTester) Diagnostics(diagnostics ...string) { vt.diagnostics = diagnostics }

// Autofixes remembers the expected diagnostics when pkglint is
// run with the --autofix option.
func (vt *VaralignTester) Autofixes(autofixes ...string) { vt.autofixes = autofixes }

// Fixed remembers the expected fixed lines. To make the layout changes
// clearly visible, tabs are replaced with spaces in these expected lines.
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
	if vt.source {
		cmdline = append(cmdline, "--source")
	}
	t.SetupCommandLine(cmdline...)

	mklines := t.SetupFileMkLines("Makefile", vt.input...)

	var varalign VaralignBlock
	for _, mkline := range mklines.mklines {
		varalign.Check(mkline)
	}
	varalign.Finish()

	if autofix {
		if len(vt.autofixes) > 0 {
			t.CheckOutputLines(vt.autofixes...)
		} else {
			t.CheckOutputEmpty()
		}

		SaveAutofixChanges(mklines.lines)
		t.CheckFileLinesDetab("Makefile", vt.fixed...)
	} else {
		if len(vt.diagnostics) > 0 {
			t.CheckOutputLines(vt.diagnostics...)
		} else {
			t.CheckOutputEmpty()
		}
	}
}

// Generally, the value in variable assignments is aligned
// at the next tab.
func (s *Suite) Test_Varalign__one_var_tab(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR=\tone tab")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"VAR=    one tab")
	vt.Run()
}

// Having more tabs than necessary is allowed. This can be for aesthetic
// reasons to align this paragraph with the others in the same file.
func (s *Suite) Test_Varalign__one_var_tabs(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR=\t\t\tseveral tabs")
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
func (s *Suite) Test_Varalign__one_var_space(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR= indented with one space")
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
func (s *Suite) Test_Varalign__one_var_spaces(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR=   several spaces")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned with tabs, not spaces, to column 9.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \"   \" with \"\\t\".")
	vt.Fixed(
		"VAR=    several spaces")
	vt.Run()
}

// Inconsistently aligned lines for variables of the same length are
// replaced with tabs, so that they nicely align.
func (s *Suite) Test_Varalign__two_vars__spaces(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR= indented with one space",
		"VAR=  indented with two spaces")
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
func (s *Suite) Test_Varalign__several_vars__spaces(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"GRP_A= value",
		"GRP_AA= value",
		"GRP_AAA= value",
		"GRP_AAAA= value")
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

// Continuation lines may be indented with a single space.
func (s *Suite) Test_Varalign__continuation(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR= \\",
		"\tvalue")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"VAR= \\",
		"        value")
	vt.Run()
}

// To align these two lines, the first line needs more more tab.
// The second line is further to the right but doesn't count as
// an outlier since it is not far enough.
// Adding one more tab to the indentation is generally considered ok.
func (s *Suite) Test_Varalign__short_tab__long_space(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"BLOCK=\tindented with tab",
		"BLOCK_LONGVAR= indented with space")
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
func (s *Suite) Test_Varalign__short_long__tab(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"BLOCK=\tshort",
		"BLOCK_LONGVAR=\tlong")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned to column 17.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \"\\t\" with \"\\t\\t\".")
	vt.Fixed(
		"BLOCK=          short",
		"BLOCK_LONGVAR=  long")
	vt.Run()
}

// For differing indentation, it doesn't matter whether the indentation
// is done with tabs or with spaces. It is aligned to the minimum
// necessary depth.
func (s *Suite) Test_Varalign__space_and_tab(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR=    space",
		"VAR=\ttab ${VAR}")
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
func (s *Suite) Test_Varalign__no_space_at_all(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"PKG_FAIL_REASON+=\"Message\"")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned to column 25.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \"\" with \"\\t\".")
	vt.Fixed(
		"PKG_FAIL_REASON+=       \"Message\"")
	vt.Run()
}

// Continuation lines without any content on the first line may use
// a space for variable value alignment.
// They are ignored when calculating the preferred alignment depth.
func (s *Suite) Test_Varalign__continuation_lines(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"DISTFILES+=\tvalue",
		"DISTFILES+= \\", // The continuation backslash must be aligned.
		"\t\t\tvalue",    // The value is already aligned.
		"DISTFILES+=\t\t\tvalue",
		"DISTFILES+= value",
		"",
		"DISTFILES= \\",
		"value")
	vt.Diagnostics(
		"NOTE: ~/Makefile:2--3: This variable value should be aligned with tabs, not spaces, to column 17.",
		"NOTE: ~/Makefile:2--3: This line should be aligned with \"\\t\\t\".",
		"NOTE: ~/Makefile:4: This variable value should be aligned to column 17.",
		"NOTE: ~/Makefile:5: This variable value should be aligned with tabs, not spaces, to column 17.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:2: Replacing \" \" with \"\\t\".",
		"AUTOFIX: ~/Makefile:3: Replacing indentation \"\\t\\t\\t\" with \"\\t\\t\".",
		"AUTOFIX: ~/Makefile:4: Replacing \"\\t\\t\\t\" with \"\\t\".",
		"AUTOFIX: ~/Makefile:5: Replacing \" \" with \"\\t\".")
	vt.Fixed(
		"DISTFILES+=     value",
		"DISTFILES+=     \\",
		"                value",
		"DISTFILES+=     value",
		"DISTFILES+=     value",
		"",
		"DISTFILES= \\",
		"value")
	vt.Run()
}

// Ensures that a wrong warning introduced in ccb56a5 is not logged.
func (s *Suite) Test_Varalign__aligned_continuation(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"USE_TOOLS+=\t[ awk \\",
		"\t\tsed")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"USE_TOOLS+=     [ awk \\",
		"                sed")
	vt.Run()
}

// Shell commands are assumed to be already nicely indented.
// This particular example is not, but pkglint cannot decide this as of
// version 5.5.2.
func (s *Suite) Test_Varalign__shell_command(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"USE_BUILTIN.Xfixes=\tyes",
		"USE_BUILTIN.Xfixes!=\t\t\t\t\t\t\t\\",
		"\tif ${PKG_ADMIN} pmatch ...; then\t\t\t\t\t\\",
		"\t\t:; else :; fi")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"USE_BUILTIN.Xfixes=     yes",
		"USE_BUILTIN.Xfixes!=                                                    \\",
		"        if ${PKG_ADMIN} pmatch ...; then                                        \\",
		"                :; else :; fi")
	vt.Run()
}

// The most common pattern for laying out continuation lines is to have all
// values in the continuation lines, one value per line, all indented to the
// same depth.
// The depth is either a single tab or aligns with the other variables in the
// paragraph.
func (s *Suite) Test_Varalign__continuation_value_starts_in_second_line(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"WRKSRC=\t${WRKDIR}",
		"DISTFILES=\tdistfile-1.0.0.tar.gz",
		"SITES.distfile-1.0.0.tar.gz= \\",
		"\t\t\t${MASTER_SITES_SOURCEFORGE} \\",
		"\t\t\t${MASTER_SITES_GITHUB}")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned to column 17.",
		"NOTE: ~/Makefile:3--5: This line should be aligned with \"\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \"\\t\" with \"\\t\\t\".",
		"AUTOFIX: ~/Makefile:4: Replacing indentation \"\\t\\t\\t\" with \"\\t\\t\".",
		"AUTOFIX: ~/Makefile:5: Replacing indentation \"\\t\\t\\t\" with \"\\t\\t\".")
	vt.Fixed(
		"WRKSRC=         ${WRKDIR}",
		"DISTFILES=      distfile-1.0.0.tar.gz",
		"SITES.distfile-1.0.0.tar.gz= \\",
		"                ${MASTER_SITES_SOURCEFORGE} \\",
		"                ${MASTER_SITES_GITHUB}")
	vt.Run()
}

// Another common pattern is to write the first value in the first line and
// subsequent values indented to the same depth as the value in the first
// line.
func (s *Suite) Test_Varalign__continuation_value_starts_in_first_line(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"WRKSRC=\t${WRKDIR}",
		"DISTFILES=\tdistfile-1.0.0.tar.gz",
		"SITES.distfile-1.0.0.tar.gz=\t${MASTER_SITES_SOURCEFORGE} \\",
		"\t\t\t\t${MASTER_SITES_GITHUB}")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned to column 17.",
		"NOTE: ~/Makefile:3--4: This line should be aligned with \"\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \"\\t\" with \"\\t\\t\".",
		"AUTOFIX: ~/Makefile:4: Replacing indentation \"\\t\\t\\t\\t\" with \"\\t\\t\".")
	vt.Fixed(
		"WRKSRC=         ${WRKDIR}",
		"DISTFILES=      distfile-1.0.0.tar.gz",
		"SITES.distfile-1.0.0.tar.gz=    ${MASTER_SITES_SOURCEFORGE} \\",
		"                ${MASTER_SITES_GITHUB}")
	vt.Run()
}

// Continued lines that have mixed indentation are probably on purpose.
// Their minimum indentation should be aligned to the indentation of the
// other lines. The lines that are indented further should keep their
// relative indentation depth, no matter if that is done with spaces or
// with tabs.
func (s *Suite) Test_Varalign__continuation_mixed_indentation_in_second_line(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"WRKSRC=\t${WRKDIR}",
		"DISTFILES=\tdistfile-1.0.0.tar.gz",
		"AWK_PROGRAM+= \\",
		"\t\t\t\t  /search/ { \\",
		"\t\t\t\t    action(); \\",
		"\t\t\t\t  }")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned to column 17.",
		"NOTE: ~/Makefile:3--6: This variable value should be aligned with tabs, not spaces, to column 17.",
		"NOTE: ~/Makefile:3--6: This line should be aligned with \"\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \"\\t\" with \"\\t\\t\".",
		"AUTOFIX: ~/Makefile:3: Replacing \" \" with \"\\t\".",
		"AUTOFIX: ~/Makefile:4: Replacing indentation \"\\t\\t\\t\\t  \" with \"\\t\\t\".",
		"AUTOFIX: ~/Makefile:5: Replacing indentation \"\\t\\t\\t\\t    \" with \"\\t\\t  \".",
		"AUTOFIX: ~/Makefile:6: Replacing indentation \"\\t\\t\\t\\t  \" with \"\\t\\t\".")
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
func (s *Suite) Test_Varalign__continuation_mixed_indentation_in_first_line(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"WRKSRC=\t${WRKDIR}",
		"DISTFILES=\tdistfile-1.0.0.tar.gz",
		"AWK_PROGRAM+=\t\t\t  /search/ { \\",
		"\t\t\t\t    action(); \\",
		"\t\t\t\t  }")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned to column 17.",
		"NOTE: ~/Makefile:3--5: This variable value should be aligned with tabs, not spaces, to column 17.",
		"NOTE: ~/Makefile:3--5: This line should be aligned with \"\\t\\t\".")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \"\\t\" with \"\\t\\t\".",
		"AUTOFIX: ~/Makefile:3: Replacing \"\\t\\t\\t  \" with \"\\t\".",
		"AUTOFIX: ~/Makefile:4: Replacing indentation \"\\t\\t\\t\\t    \" with \"\\t\\t  \".",
		"AUTOFIX: ~/Makefile:5: Replacing indentation \"\\t\\t\\t\\t  \" with \"\\t\\t\".")
	vt.Fixed(
		"WRKSRC=         ${WRKDIR}",
		"DISTFILES=      distfile-1.0.0.tar.gz",
		"AWK_PROGRAM+=   /search/ { \\",
		"                  action(); \\",
		"                }")
	vt.Run()
}

// When there is an outlier, no matter whether indented using space or tab,
// fix the whole block to use the indentation of the second-longest line.
// Since all of the remaining lines have the same indentation (in this case,
// there is only 1 line at all), that existing indentation is used instead of
// the minimum necessary, which would only be a single tab.
func (s *Suite) Test_Varalign__tab_outlier(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"DISTFILES=\t\tvery-very-very-very-long-distfile-name",
		"SITES.very-very-very-very-long-distfile-name=\t${MASTER_SITE_LOCAL}")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"DISTFILES=              very-very-very-very-long-distfile-name",
		"SITES.very-very-very-very-long-distfile-name=   ${MASTER_SITE_LOCAL}")
	vt.Run()
}

// The SITES.* definition is indented less than the other lines,
// therefore the whole paragraph will be realigned to that depth.
func (s *Suite) Test_Varalign__multiline(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"DIST_SUBDIR=            asc",
		"DISTFILES=              ${DISTNAME}${EXTRACT_SUFX} frontiers.mp3 \\",
		"                        machine_wars.mp3 time_to_strike.mp3",
		".for file in frontiers.mp3 machine_wars.mp3 time_to_strike.mp3",
		"SITES.${file}=  http://asc-hq.org/",
		".endfor",
		"WRKSRC=                 ${WRKDIR}/${PKGNAME_NOREV}")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned with tabs, not spaces, to column 17.",
		"NOTE: ~/Makefile:2--3: This variable value should be aligned with tabs, not spaces, to column 17.",
		"NOTE: ~/Makefile:2--3: This line should be aligned with \"\\t\\t\".",
		"NOTE: ~/Makefile:5: Variable values should be aligned with tabs, not spaces.",
		"NOTE: ~/Makefile:7: This variable value should be aligned with tabs, not spaces, to column 17.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \"            \" with \"\\t\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"              \" with \"\\t\".",
		"AUTOFIX: ~/Makefile:3: Replacing indentation \"                        \" with \"\\t\\t\".",
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
func (s *Suite) Test_Varalign__single_space(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"RESTRICTED=\tDo not sell, do not rent",
		"NO_BIN_ON_CDROM= ${RESTRICTED}",
		"NO_BIN_ON_FTP=\t${RESTRICTED}",
		"NO_SRC_ON_CDROM= ${RESTRICTED}",
		"NO_SRC_ON_FTP=\t${RESTRICTED}")
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

// These variables all look nicely aligned, but they use spaces instead
// of tabs for alignment. The spaces are replaced with tabs, making the
// indentation a little deeper.
func (s *Suite) Test_Varalign__only_space(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"DISTFILES+= space",
		"DISTFILES+= space",
		"",
		"REPLACE_PYTHON+= *.py",
		"REPLACE_PYTHON+= lib/*.py",
		"REPLACE_PYTHON+= src/*.py")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned with tabs, not spaces, to column 17.",
		"NOTE: ~/Makefile:2: This variable value should be aligned with tabs, not spaces, to column 17.",
		"NOTE: ~/Makefile:4: This variable value should be aligned with tabs, not spaces, to column 25.",
		"NOTE: ~/Makefile:5: This variable value should be aligned with tabs, not spaces, to column 25.",
		"NOTE: ~/Makefile:6: This variable value should be aligned with tabs, not spaces, to column 25.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \" \" with \"\\t\".",
		"AUTOFIX: ~/Makefile:2: Replacing \" \" with \"\\t\".",
		"AUTOFIX: ~/Makefile:4: Replacing \" \" with \"\\t\".",
		"AUTOFIX: ~/Makefile:5: Replacing \" \" with \"\\t\".",
		"AUTOFIX: ~/Makefile:6: Replacing \" \" with \"\\t\".")
	vt.Fixed(
		"DISTFILES+=     space",
		"DISTFILES+=     space",
		"",
		"REPLACE_PYTHON+=        *.py",
		"REPLACE_PYTHON+=        lib/*.py",
		"REPLACE_PYTHON+=        src/*.py")
	vt.Run()
}

// The indentation is deeper than necessary, but all lines agree on
// the same column. Therefore this indentation depth is kept.
func (s *Suite) Test_Varalign__mixed_tabs_and_spaces_same_column(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"DISTFILES+=             space",
		"DISTFILES+=\t\ttab")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: Variable values should be aligned with tabs, not spaces.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \"             \" with \"\\t\\t\".")
	vt.Fixed(
		"DISTFILES+=             space",
		"DISTFILES+=             tab")
	vt.Run()
}

// Both lines are indented to the same column. This is a very simple case.
func (s *Suite) Test_Varalign__outlier_1(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"V= value",
		"V=\tvalue")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned with tabs, not spaces, to column 9.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \" \" with \"\\t\".")
	vt.Fixed(
		"V=      value",
		"V=      value")
	vt.Run()
}

// A single space that ends at the same depth as a tab is replaced with a
// tab, for consistency.
func (s *Suite) Test_Varalign__outlier_2(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"V.0008= value",
		"V=\tvalue")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: Variable values should be aligned with tabs, not spaces.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \" \" with \"\\t\".")
	vt.Fixed(
		"V.0008= value",
		"V=      value")
	vt.Run()
}

// A short line that is indented with spaces is aligned to a longer line
// that is indented with tabs. This is because space-indented lines are
// only special when their indentation is much deeper than the tab-indented
// ones.
func (s *Suite) Test_Varalign__outlier_3(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"V.00009= value",
		"V=\tvalue")
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
func (s *Suite) Test_Varalign__outlier_4(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"V.000000000016= value",
		"V=\tvalue")
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
func (s *Suite) Test_Varalign__outlier_5(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"V.0000000000017= value",
		"V=\tvalue")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"V.0000000000017= value",
		"V=      value")
	vt.Run()
}

// Short space-indented lines are expanded to the tab-depth.
func (s *Suite) Test_Varalign__outlier_6(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"V= value",
		"V.000010=\tvalue")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned with tabs, not spaces, to column 17.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \" \" with \"\\t\\t\".")
	vt.Fixed(
		"V=              value",
		"V.000010=       value")
	vt.Run()
}

// The long line is not an outlier but very close. One more space, and
// it would count.
func (s *Suite) Test_Varalign__outlier_10(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"V.0000000000000000023= value", // Adjust from 23 to 24 (+ 1 tab)
		"V.000010=\tvalue")             // Adjust from 16 to 24 (+ 1 tab)
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

func (s *Suite) Test_Varalign__outlier_11(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"V.00000000000000000024= value", // Keep at 24 (space to tab)
		"V.000010=\tvalue")              // Adjust from 16 to 24 (+ 1 tab)
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

func (s *Suite) Test_Varalign__outlier_12(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"V.000000000000000000025= value", // Keep at 25 (outlier)
		"V.000010=\tvalue")               // Keep at 16 (would require + 2 tabs)
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"V.000000000000000000025= value",
		"V.000010=       value")
	vt.Run()
}

// When the lines are indented inconsistently, the indentation is reduced
// to the required minimum.
func (s *Suite) Test_Varalign__outlier_14(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"V.00008=\t\tvalue",     // Adjust from 24 to 16 (removes 1 tab)
		"V.00008=\t\t\t\tvalue") // Adjust from 40 to 16 (removes 3 tabs)
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
// Pkglint before 2018-26-01 suggested that it "should be aligned to column 9",
// which is not possible since the variable name is already longer.
func (s *Suite) Test_Varalign__long_short(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"INSTALLATION_DIRS=\tbin",
		"DIST=\t${WRKSRC}/dist")
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
func (s *Suite) Test_Varalign__tabbed_outlier(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		".if !empty(PKG_OPTIONS:Minspircd-sqloper)",
		"INSPIRCD_STORAGE_DRIVER?=\tmysql",
		"MODULES+=\t\tm_sqloper.cpp m_sqlutils.cpp",
		"HEADERS+=\t\tm_sqlutils.h",
		".endif")
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
func (s *Suite) Test_Varalign__indented_continuation_line(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"CONF_FILES_PERMS=\tsource \\",
		"\t\t\t\tdestination \\",
		"\t\t\t\tuser group 0644")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"CONF_FILES_PERMS=       source \\",
		"                                destination \\",
		"                                user group 0644")
	vt.Run()
}

func (s *Suite) Test_Varalign__indented_continuation_line_in_paragraph(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"SUBST_CLASSES+=\t\tfix",
		"SUBST_STAGE.fix=\tpost-patch",
		"SUBST_SED.fix= \\",
		"\t-e 's,1,one,g' \\",
		"\t-e 's,2,two,g' \\",
		"\t-e 's,3,three,g'")
	vt.Diagnostics(
		"NOTE: ~/Makefile:3--6: This variable value should be aligned with tabs, not spaces, to column 25.")
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
func (s *Suite) Test_Varalign__fix_without_diagnostic(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"MESSAGE_SUBST+=\t\tRUBY_DISTNAME=${RUBY_DISTNAME}",
		"PLIST_SUBST+=\t\tRUBY_SHLIBVER=${RUBY_SHLIBVER:Q} \\",
		"\t\t\tRUBY_SHLIBMAJOR=${RUBY_SHLIBMAJOR:Q} \\",
		"\t\t\tRUBY_NOSHLIBMAJOR=${RUBY_NOSHLIBMAJOR} \\",
		"\t\t\tRUBY_NAME=${RUBY_NAME:Q}")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"MESSAGE_SUBST+=         RUBY_DISTNAME=${RUBY_DISTNAME}",
		"PLIST_SUBST+=           RUBY_SHLIBVER=${RUBY_SHLIBVER:Q} \\",
		"                        RUBY_SHLIBMAJOR=${RUBY_SHLIBMAJOR:Q} \\",
		"                        RUBY_NOSHLIBMAJOR=${RUBY_NOSHLIBMAJOR} \\",
		"                        RUBY_NAME=${RUBY_NAME:Q}")
	vt.source = true
	vt.Run()
}

// The two variables look like they were in two separate paragraphs, but
// they aren't. This is because the continuation line from the DISTFILES
// eats up the empty line that would otherwise separate the paragraphs.
func (s *Suite) Test_Varalign__continuation_line_last_empty(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"DISTFILES= \\",
		"\ta \\",
		"\tb \\",
		"\tc \\",
		"",
		"NEXT_VAR=\tmust not be indented")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1--5: This variable value should be aligned with tabs, not spaces, to column 17.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \" \" with \"\\t\".")
	vt.Fixed(
		"DISTFILES=      \\",
		"        a \\",
		"        b \\",
		"        c \\",
		"",
		"NEXT_VAR=       must not be indented")
	vt.Run()
}

// Commented-out variables take part in the realignment.
// The TZ=UTC below is part of the two-line comment since make(1)
// interprets it in the same way.
func (s *Suite) Test_Varalign__realign_commented_single_lines(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"SHORT=\tvalue",
		"#DISTFILES=\tdistfile-1.0.0.tar.gz",
		"#CONTINUATION= \\",
		"#\t\tcontinued",
		"#CONFIGURE_ENV+= \\",
		"#TZ=UTC",
		"SHORT=\tvalue")
	vt.Diagnostics(
		"NOTE: ~/Makefile:1: This variable value should be aligned to column 17.",
		"NOTE: ~/Makefile:3--4: This variable value should be aligned with tabs, not spaces, to column 17.",
		"NOTE: ~/Makefile:5--6: This line should be aligned with \"\\t\\t\".",
		"NOTE: ~/Makefile:7: This variable value should be aligned to column 17.")
	vt.Autofixes(
		"AUTOFIX: ~/Makefile:1: Replacing \"\\t\" with \"\\t\\t\".",
		"AUTOFIX: ~/Makefile:3: Replacing \" \" with \"\\t\".",
		"AUTOFIX: ~/Makefile:6: Replacing indentation \"\" with \"\\t\\t\".",
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

func (s *Suite) Test_Varalign__realign_commented_continuation_line(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"BEFORE=\tvalue",
		"#COMMENTED= \\",
		"#\tvalue1 \\",
		"#\tvalue2 \\",
		"#\tvalue3 \\",
		"AFTER=\tafter") // This line continues the comment.
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"BEFORE= value",
		"#COMMENTED= \\",
		"#       value1 \\",
		"#       value2 \\",
		"#       value3 \\",
		"AFTER=  after")
	vt.Run()
}

// The HOMEPAGE is completely ignored. Since its value is empty it doesn't
// need any alignment. Whether it is commented out doesn't matter.
func (s *Suite) Test_Varalign__realign_variable_without_value(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"COMMENT=\t\tShort description of the package",
		"#HOMEPAGE=")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"COMMENT=                Short description of the package",
		"#HOMEPAGE=")
	vt.Run()
}

// This commented multiline variable is already perfectly aligned.
// Nothing needs to be fixed.
func (s *Suite) Test_Varalign__realign_commented_multiline(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"#CONF_FILES+=\t\tfile1 \\",
		"#\t\t\tfile2")
	vt.Diagnostics()
	vt.Autofixes()
	vt.Fixed(
		"#CONF_FILES+=           file1 \\",
		"#                       file2")
	vt.Run()
}

// FIXME: The diagnostic does not correspond to the autofix; see "if oldWidth == 8".
func (s *Suite) Test_Varalign__mixed_indentation(c *check.C) {
	vt := NewVaralignTester(s, c)
	vt.Input(
		"VAR1=\tvalue1",
		"VAR2=\tvalue2 \\",
		" \t \t value2 continued")
	vt.Diagnostics(
	/*"NOTE: ~/Makefile:2--3: This line should be aligned with \"\\t\"."*/ )
	vt.Autofixes(
	/*"AUTOFIX: ~/Makefile:3: Replacing indentation \" \\t \\t \" with \"\\t\\t \"."*/ )
	vt.Fixed(
		"VAR1=   value1",
		"VAR2=   value2 \\",
		"                 value2 continued")
	vt.Run()
}
