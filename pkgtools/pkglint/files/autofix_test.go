package pkglint

import (
	"gopkg.in/check.v1"
	"os"
	"runtime"
	"strings"
)

func (s *Suite) Test_Autofix_Warnf__duplicate(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("DESCR", 1, "Description of the package")

	fix := line.Autofix()
	fix.Warnf("Warning 1.")
	t.ExpectAssert(func() { fix.Warnf("Warning 2.") })
}

func (s *Suite) Test_Autofix__default_leaves_line_unchanged(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--source")
	mklines := t.SetUpFileMkLines("Makefile",
		"# row 1 \\",
		"continuation of row 1")
	line := mklines.lines.Lines[0]

	fix := line.Autofix()
	fix.Warnf("Row should be replaced with line.")
	fix.Replace("row", "line")
	fix.ReplaceRegex(`row \d+`, "the above line", -1)
	fix.InsertBefore("above")
	fix.InsertAfter("below")
	fix.Delete()
	fix.Apply()

	t.CheckEquals(fix.RawText(), ""+
		"# row 1 \\\n"+
		"continuation of row 1\n")
	t.CheckOutputLines(
		">\t# row 1 \\",
		">\tcontinuation of row 1",
		"WARN: ~/Makefile:1--2: Row should be replaced with line.")
	t.CheckEquals(fix.modified, true)
}

func (s *Suite) Test_Autofix__show_autofix_modifies_line(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--source", "--show-autofix")
	mklines := t.SetUpFileMkLines("Makefile",
		"# row 1 \\",
		"continuation of row 1")
	line := mklines.lines.Lines[0]

	fix := line.Autofix()
	fix.Warnf("Row should be replaced with line.")
	fix.ReplaceAfter("", "# row", "# line")
	fix.ReplaceRegex(`row \d+`, "the above line", -1)
	fix.InsertBefore("above")
	fix.InsertAfter("below")
	fix.Delete()
	fix.Apply()

	t.CheckEquals(fix.RawText(), ""+
		"above\n"+
		"below\n")
	t.CheckOutputLines(
		"WARN: ~/Makefile:1--2: Row should be replaced with line.",
		"AUTOFIX: ~/Makefile:1: Replacing \"# row\" with \"# line\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"row 1\" with \"the above line\".",
		"AUTOFIX: ~/Makefile:1: Inserting a line \"above\" before this line.",
		"AUTOFIX: ~/Makefile:2: Inserting a line \"below\" after this line.",
		"AUTOFIX: ~/Makefile:1: Deleting this line.",
		"AUTOFIX: ~/Makefile:2: Deleting this line.",
		"+\tabove",
		"-\t# row 1 \\",
		"-\tcontinuation of row 1",
		"+\tbelow")
	t.CheckEquals(fix.modified, true)
}

func (s *Suite) Test_Autofix_ReplaceAfter__autofix_in_continuation_line(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--autofix", "--source")
	mklines := t.SetUpFileMkLines("Makefile",
		"# line 1 \\",
		"continuation 1 \\",
		"continuation 2")

	fix := mklines.lines.Lines[0].Autofix()
	fix.Warnf("Line should be replaced with Row.")
	fix.ReplaceAfter("", "line", "row")
	fix.Apply()

	t.CheckOutputLines(
		"AUTOFIX: ~/Makefile:1: Replacing \"line\" with \"row\".",
		"-\t# line 1 \\",
		"+\t# row 1 \\",
		"\tcontinuation 1 \\",
		"\tcontinuation 2")
}

func (s *Suite) Test_Autofix_ReplaceAfter__autofix_several_times_in_continuation_line(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--autofix", "--source")
	mklines := t.SetUpFileMkLines("Makefile",
		"# line 1 \\",
		"continuation 1 \\",
		"continuation 2")

	fix := mklines.lines.Lines[0].Autofix()
	fix.Warnf("N should be replaced with V.")
	fix.ReplaceAfter("", "n", "v")
	fix.Apply()

	// Nothing is logged or fixed because the "n" appears more than once,
	// and as of June 2019, pkglint doesn't know which occurrence is the
	// correct one.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Autofix_ReplaceAfter__autofix_one_time(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--autofix", "--source")
	mklines := t.SetUpFileMkLines("Makefile",
		MkCvsID,
		"VAR=\t$$(var) $(var)")

	mklines.Check()

	// Nothing is replaced since, as of June 2019, pkglint doesn't
	// know which of the two "$(var)" should be replaced.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Autofix_ReplaceRegex__show_autofix(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--show-autofix")
	lines := t.SetUpFileLines("Makefile",
		"line1",
		"line2",
		"line3")

	fix := lines.Lines[1].Autofix()
	fix.Warnf("Something's wrong here.")
	fix.ReplaceRegex(`.`, "X", -1)
	fix.Apply()
	SaveAutofixChanges(lines)

	t.CheckEquals(lines.Lines[1].raw[0].textnl, "XXXXX\n")
	t.CheckFileLines("Makefile",
		"line1",
		"line2",
		"line3")
	t.CheckOutputLines(
		"WARN: ~/Makefile:2: Something's wrong here.",
		"AUTOFIX: ~/Makefile:2: Replacing \"l\" with \"X\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"i\" with \"X\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"n\" with \"X\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"e\" with \"X\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"2\" with \"X\".")
}

func (s *Suite) Test_Autofix_ReplaceRegex__autofix(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--autofix", "--source")
	lines := t.SetUpFileLines("Makefile",
		"line1",
		"line2",
		"line3")

	fix := lines.Lines[1].Autofix()
	fix.Warnf("Something's wrong here.")
	fix.ReplaceRegex(`.`, "X", 3)
	fix.Apply()

	t.CheckOutputLines(
		"AUTOFIX: ~/Makefile:2: Replacing \"l\" with \"X\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"i\" with \"X\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"n\" with \"X\".",
		"-\tline2",
		"+\tXXXe2")

	// After calling fix.Apply above, the autofix is ready to be used again.
	fix.Warnf("Use Y instead of X.")
	fix.Replace("XXX", "YYY")
	fix.Apply()

	t.CheckOutputLines(
		"AUTOFIX: ~/Makefile:2: Replacing \"XXX\" with \"YYY\".",
		"-\tline2",
		"+\tYYYe2")

	SaveAutofixChanges(lines)

	t.CheckFileLines("Makefile",
		"line1",
		"YYYe2",
		"line3")
}

func (s *Suite) Test_Autofix_ReplaceRegex__show_autofix_and_source(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--show-autofix", "--source")
	lines := t.SetUpFileLines("Makefile",
		"line1",
		"line2",
		"line3")

	fix := lines.Lines[1].Autofix()
	fix.Warnf("Something's wrong here.")
	fix.ReplaceRegex(`.`, "X", -1)
	fix.Apply()

	fix.Warnf("Use Y instead of X.")
	fix.Replace("XXXXX", "YYYYY")
	fix.Apply()

	SaveAutofixChanges(lines)

	t.CheckOutputLines(
		"WARN: ~/Makefile:2: Something's wrong here.",
		"AUTOFIX: ~/Makefile:2: Replacing \"l\" with \"X\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"i\" with \"X\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"n\" with \"X\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"e\" with \"X\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"2\" with \"X\".",
		"-\tline2",
		"+\tXXXXX",
		"",
		"WARN: ~/Makefile:2: Use Y instead of X.",
		"AUTOFIX: ~/Makefile:2: Replacing \"XXXXX\" with \"YYYYY\".",
		"-\tline2",
		"+\tYYYYY")
}

// When an autofix replaces text, it does not touch those
// lines that have been inserted before since these are
// usually already correct.
func (s *Suite) Test_Autofix_ReplaceAfter__after_inserting_a_line(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--show-autofix")
	line := t.NewLine("filename", 5, "initial text")

	fix := line.Autofix()
	fix.Notef("Inserting a line.")
	fix.InsertBefore("line before")
	fix.InsertAfter("line after")
	fix.Apply()

	fix.Notef("Replacing text.")
	fix.Replace("l", "L")
	fix.ReplaceRegex(`i`, "I", 1)
	fix.Apply()

	t.CheckOutputLines(
		"NOTE: filename:5: Inserting a line.",
		"AUTOFIX: filename:5: Inserting a line \"line before\" before this line.",
		"AUTOFIX: filename:5: Inserting a line \"line after\" after this line.",
		"NOTE: filename:5: Replacing text.",
		"AUTOFIX: filename:5: Replacing \"l\" with \"L\".",
		"AUTOFIX: filename:5: Replacing \"i\" with \"I\".")
}

func (s *Suite) Test_Autofix_ReplaceAt(c *check.C) {
	t := s.Init(c)

	lines := func(lines ...string) []string { return lines }
	diagnostics := lines
	autofixes := lines
	test := func(texts []string, rawIndex int, column int, from, to string, diagnostics []string, autofixes []string) {

		mainPart := func() {
			mklines := t.NewMkLines("filename.mk", texts...)
			assert(len(mklines.mklines) == 1)
			mkline := mklines.mklines[0]

			fix := mkline.Autofix()
			fix.Notef("Should be appended instead of assigned.")
			fix.ReplaceAt(rawIndex, column, from, to)
			fix.Anyway()
			fix.Apply()
		}

		t.SetUpCommandLine("-Wall")
		mainPart()
		t.CheckOutput(diagnostics)

		t.SetUpCommandLine("-Wall", "--autofix")
		mainPart()
		t.CheckOutput(autofixes)
	}

	test(
		lines(
			"VAR=value1 \\",
			"\tvalue2"),
		0, 3, "=", "+=",
		diagnostics(
			"NOTE: filename.mk:1: Should be appended instead of assigned."),
		autofixes(
			"AUTOFIX: filename.mk:1: Replacing \"=\" with \"+=\"."))

	// If the text at the precisely given position does not match,
	// the note is still printed because of the fix.Anyway(), but
	// nothing is replaced automatically.
	test(
		lines(
			"VAR=value1 \\",
			"\tvalue2"),
		0, 3, "?", "+=",
		diagnostics(
			"NOTE: filename.mk:1--2: Should be appended instead of assigned."),
		autofixes(
			nil...))

	// Getting the line number wrong is a strange programming error, and
	// there does not need to be any code checking for this in the main code.
	t.ExpectPanicMatches(
		func() { test(lines("VAR=value"), 10, 3, "from", "to", nil, nil) },
		`runtime error: index out of range.*`)

	// It is a programming error to replace a string with itself, since that
	// would produce confusing diagnostics.
	t.ExpectAssert(
		func() { test(lines("VAR=value"), 0, 4, "value", "value", nil, nil) })

	// Getting the column number wrong may happen when a previous replacement
	// has made the string shorter than before, therefore no panic in this case.
	test(
		lines(
			"VAR=value1 \\",
			"\tvalue2"),
		0, 20, "?", "+=",
		diagnostics(
			"NOTE: filename.mk:1--2: Should be appended instead of assigned."),
		autofixes(
			nil...))
}

func (s *Suite) Test_SaveAutofixChanges(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--autofix")
	lines := t.SetUpFileLines("example.txt",
		"line1 := value1",
		"line2 := value2",
		"line3 := value3")

	fix := lines.Lines[1].Autofix()
	fix.Warnf("Something's wrong here.")
	fix.ReplaceRegex(`...`, "XXX", 2)
	fix.Apply()

	SaveAutofixChanges(lines)

	t.CheckOutputLines(
		"AUTOFIX: ~/example.txt:2: Replacing \"lin\" with \"XXX\".",
		"AUTOFIX: ~/example.txt:2: Replacing \"e2 \" with \"XXX\".")
	t.CheckFileLines("example.txt",
		"line1 := value1",
		"XXXXXX:= value2",
		"line3 := value3")
}

func (s *Suite) Test_SaveAutofixChanges__no_changes_necessary(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--autofix")
	lines := t.SetUpFileLines("DESCR",
		"Line 1",
		"Line 2")

	fix := lines.Lines[0].Autofix()
	fix.Warnf("Dummy warning.")
	fix.Replace("X", "Y")
	fix.Apply()

	// Since nothing has been effectively changed,
	// nothing needs to be saved.
	SaveAutofixChanges(lines)

	// And therefore, no AUTOFIX action must appear in the log.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Autofix__multiple_fixes(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--show-autofix", "--explain")

	line := t.NewLine("filename", 1, "original")

	c.Check(line.autofix, check.IsNil)
	t.CheckDeepEquals(line.raw, t.NewRawLines(1, "original\n"))

	{
		fix := line.Autofix()
		fix.Warnf(SilentAutofixFormat)
		fix.ReplaceRegex(`(.)(.*)(.)`, "lriginao", 1) // XXX: the replacement should be "$3$2$1"
		fix.Apply()
	}

	c.Check(line.autofix, check.NotNil)
	t.CheckDeepEquals(line.raw, t.NewRawLines(1, "original\n", "lriginao\n"))
	t.CheckOutputLines(
		"AUTOFIX: filename:1: Replacing \"original\" with \"lriginao\".")

	{
		fix := line.Autofix()
		fix.Warnf(SilentAutofixFormat)
		fix.Replace("ig", "ug")
		fix.Apply()
	}

	c.Check(line.autofix, check.NotNil)
	t.CheckDeepEquals(line.raw, t.NewRawLines(1, "original\n", "lruginao\n"))
	t.CheckEquals(line.raw[0].textnl, "lruginao\n")
	t.CheckOutputLines(
		"AUTOFIX: filename:1: Replacing \"ig\" with \"ug\".")

	{
		fix := line.Autofix()
		fix.Warnf(SilentAutofixFormat)
		fix.Replace("lruginao", "middle")
		fix.Apply()
	}

	c.Check(line.autofix, check.NotNil)
	t.CheckDeepEquals(line.raw, t.NewRawLines(1, "original\n", "middle\n"))
	t.CheckEquals(line.raw[0].textnl, "middle\n")
	t.CheckOutputLines(
		"AUTOFIX: filename:1: Replacing \"lruginao\" with \"middle\".")

	t.CheckEquals(line.raw[0].textnl, "middle\n")
	t.CheckOutputEmpty()

	{
		fix := line.Autofix()
		fix.Warnf(SilentAutofixFormat)
		fix.Delete()
		fix.Apply()
	}

	t.CheckEquals(line.Autofix().RawText(), "")
	t.CheckOutputLines(
		"AUTOFIX: filename:1: Deleting this line.")
}

func (s *Suite) Test_Autofix_Explain__without_explain_option(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("Makefile", 74, "line1")

	fix := line.Autofix()
	fix.Warnf("Please write row instead of line.")
	fix.Replace("line", "row")
	fix.Explain("Explanation")
	fix.Apply()

	t.CheckOutputLines(
		"WARN: Makefile:74: Please write row instead of line.")
	t.CheckEquals(G.Logger.explanationsAvailable, true)
}

func (s *Suite) Test_Autofix_Explain__default(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--explain")
	line := t.NewLine("Makefile", 74, "line1")

	fix := line.Autofix()
	fix.Warnf("Please write row instead of line.")
	fix.Replace("line", "row")
	fix.Explain("Explanation")
	fix.Apply()

	t.CheckOutputLines(
		"WARN: Makefile:74: Please write row instead of line.",
		"",
		"\tExplanation",
		"")
	t.CheckEquals(G.Logger.explanationsAvailable, true)
}

func (s *Suite) Test_Autofix_Explain__show_autofix(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--show-autofix", "--explain")
	line := t.NewLine("Makefile", 74, "line1")

	fix := line.Autofix()
	fix.Warnf("Please write row instead of line.")
	fix.Replace("line", "row")
	fix.Explain("Explanation")
	fix.Apply()

	t.CheckOutputLines(
		"WARN: Makefile:74: Please write row instead of line.",
		"AUTOFIX: Makefile:74: Replacing \"line\" with \"row\".",
		"",
		"\tExplanation",
		"")
	t.CheckEquals(G.Logger.explanationsAvailable, true)
}

func (s *Suite) Test_Autofix_Explain__autofix(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--autofix", "--explain")
	line := t.NewLine("Makefile", 74, "line1")

	fix := line.Autofix()
	fix.Warnf("Please write row instead of line.")
	fix.Replace("line", "row")
	fix.Explain("Explanation")
	fix.Apply()

	t.CheckOutputLines(
		"AUTOFIX: Makefile:74: Replacing \"line\" with \"row\".")
	t.CheckEquals(G.Logger.explanationsAvailable, false) // Not necessary.
}

func (s *Suite) Test_Autofix_Explain__SilentAutofixFormat(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--explain")
	line := t.NewLine("example.txt", 1, "Text")

	fix := line.Autofix()
	fix.Warnf(SilentAutofixFormat)
	t.ExpectAssert(func() { fix.Explain("Explanation for inserting a line before.") })
}

// To combine a silent diagnostic with an explanation, two separate autofixes
// are necessary.
func (s *Suite) Test_Autofix_Explain__silent_with_diagnostic(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--explain")
	line := t.NewLine("example.txt", 1, "Text")

	fix := line.Autofix()
	fix.Warnf(SilentAutofixFormat)
	fix.InsertBefore("before")
	fix.Apply()

	fix.Notef("This diagnostic is necessary for the following explanation.")
	fix.Explain(
		"When inserting multiple lines, Apply must be called in-between.",
		"Otherwise the changes are not described to the human reader.")
	fix.InsertAfter("after")
	fix.Apply()

	t.CheckOutputLines(
		"NOTE: example.txt:1: This diagnostic is necessary for the following explanation.",
		"",
		"\tWhen inserting multiple lines, Apply must be called in-between.",
		"\tOtherwise the changes are not described to the human reader.",
		"")
	t.CheckEquals(fix.RawText(), "Text\n")
}

func (s *Suite) Test_Autofix__show_autofix_and_source_continuation_line(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--show-autofix", "--source")
	mklines := t.SetUpFileMkLines("Makefile",
		MkCvsID,
		"# before \\",
		"The old song \\",
		"after")
	line := mklines.lines.Lines[1]

	fix := line.Autofix()
	fix.Warnf("Using \"old\" is deprecated.")
	fix.Replace("old", "new")
	fix.Apply()

	// Using a tab for indentation preserves the exact layout in the output
	// since in pkgsrc Makefiles, tabs are also used in the middle of the line
	// to align the variable values. Using a single space for indentation would
	// make some of the lines appear misaligned in the pkglint output although
	// they are correct in the Makefiles.
	t.CheckOutputLines(
		"WARN: ~/Makefile:3: Using \"old\" is deprecated.",
		"AUTOFIX: ~/Makefile:3: Replacing \"old\" with \"new\".",
		"\t# before \\",
		"-\tThe old song \\",
		"+\tThe new song \\",
		"\tafter")
}

func (s *Suite) Test_Autofix_InsertBefore(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--show-autofix", "--source")
	line := t.NewLine("Makefile", 30, "original")

	fix := line.Autofix()
	fix.Warnf("Dummy.")
	fix.InsertBefore("inserted")
	fix.Apply()

	t.CheckOutputLines(
		"WARN: Makefile:30: Dummy.",
		"AUTOFIX: Makefile:30: Inserting a line \"inserted\" before this line.",
		"+\tinserted",
		">\toriginal")
}

func (s *Suite) Test_Autofix_Delete(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--show-autofix", "--source")
	line := t.NewLine("Makefile", 30, "to be deleted")

	fix := line.Autofix()
	fix.Warnf("Dummy.")
	fix.Delete()
	fix.Apply()

	t.CheckOutputLines(
		"WARN: Makefile:30: Dummy.",
		"AUTOFIX: Makefile:30: Deleting this line.",
		"-\tto be deleted")
}

// Deleting a line from a Makefile also deletes its continuation lines.
func (s *Suite) Test_Autofix_Delete__continuation_line(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--show-autofix", "--source")
	mklines := t.SetUpFileMkLines("Makefile",
		MkCvsID,
		"# line 1 \\",
		"continued")
	line := mklines.lines.Lines[1]

	fix := line.Autofix()
	fix.Warnf("Dummy warning.")
	fix.Delete()
	fix.Apply()

	t.CheckOutputLines(
		"WARN: ~/Makefile:2--3: Dummy warning.",
		"AUTOFIX: ~/Makefile:2: Deleting this line.",
		"AUTOFIX: ~/Makefile:3: Deleting this line.",
		"-\t# line 1 \\",
		"-\tcontinued")
}

func (s *Suite) Test_Autofix_Delete__combined_with_insert(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--show-autofix", "--source")
	line := t.NewLine("Makefile", 30, "to be deleted")

	fix := line.Autofix()
	fix.Warnf("This line should be replaced completely.")
	fix.Delete()
	fix.InsertAfter("below")
	fix.InsertBefore("above")
	fix.Apply()

	t.CheckOutputLines(
		"WARN: Makefile:30: This line should be replaced completely.",
		"AUTOFIX: Makefile:30: Deleting this line.",
		"AUTOFIX: Makefile:30: Inserting a line \"below\" after this line.",
		"AUTOFIX: Makefile:30: Inserting a line \"above\" before this line.",
		"+\tabove",
		"-\tto be deleted",
		"+\tbelow")
}

// Demonstrates that without the --show-autofix option, diagnostics are
// shown even when they cannot be autofixed.
//
// This is typical when an autofix is provided for simple scenarios,
// but the code actually found is a little more complicated.
func (s *Suite) Test_Autofix__show_unfixable_diagnostics_in_default_mode(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--source")
	lines := t.NewLines("Makefile",
		"line1",
		"line2",
		"line3")

	lines.Lines[0].Warnf("This warning is shown since the --show-autofix option is not given.")

	fix := lines.Lines[1].Autofix()
	fix.Warnf("This warning cannot be fixed and is therefore not shown.")
	fix.Replace("XXX", "TODO")
	fix.Apply()

	fix.Warnf("This warning cannot be fixed automatically but should be shown anyway.")
	fix.Replace("XXX", "TODO")
	fix.Anyway()
	fix.Apply()

	// If this warning should ever appear it is probably because fix.anyway is not reset properly.
	fix.Warnf("This warning cannot be fixed and is therefore not shown.")
	fix.Replace("XXX", "TODO")
	fix.Apply()

	lines.Lines[2].Warnf("This warning is also shown.")

	t.CheckOutputLines(
		">\tline1",
		"WARN: Makefile:1: This warning is shown since the --show-autofix option is not given.",
		"",
		">\tline2",
		"WARN: Makefile:2: This warning cannot be fixed automatically but should be shown anyway.",
		"",
		">\tline3",
		"WARN: Makefile:3: This warning is also shown.")
}

// Demonstrates that the --show-autofix option only shows those diagnostics
// that would be fixed.
func (s *Suite) Test_Autofix__suppress_unfixable_warnings_with_show_autofix(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--show-autofix", "--source")
	lines := t.NewLines("Makefile",
		"line1",
		"line2",
		"line3")

	lines.Lines[0].Warnf("This warning is not shown since it is not part of a fix.")

	fix := lines.Lines[1].Autofix()
	fix.Warnf("Something's wrong here.")
	fix.ReplaceRegex(`.....`, "XXX", 1)
	fix.Apply()

	fix.Warnf("Since XXX marks are usually not fixed, use TODO instead to draw attention.")
	fix.Replace("XXX", "TODO")
	fix.Apply()

	lines.Lines[2].Warnf("Neither is this warning shown.")

	t.CheckOutputLines(
		"WARN: Makefile:2: Something's wrong here.",
		"AUTOFIX: Makefile:2: Replacing \"line2\" with \"XXX\".",
		"-\tline2",
		"+\tXXX",
		"",
		"WARN: Makefile:2: Since XXX marks are usually not fixed, use TODO instead to draw attention.",
		"AUTOFIX: Makefile:2: Replacing \"XXX\" with \"TODO\".",
		"-\tline2",
		"+\tTODO")
}

// With the default command line options, this warning is printed.
// With the --show-autofix option this warning is NOT printed since it
// cannot be fixed automatically.
func (s *Suite) Test_Autofix_Anyway__options(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--show-autofix")

	line := t.NewLine("filename", 3, "")
	fix := line.Autofix()

	fix.Warnf("This autofix doesn't match.")
	fix.Replace("doesn't match", "")
	fix.Anyway()
	fix.Apply()

	t.CheckOutputEmpty()

	t.SetUpCommandLine()

	fix.Warnf("This autofix doesn't match.")
	fix.Replace("doesn't match", "")
	fix.Anyway()
	fix.Apply()

	t.CheckOutputLines(
		"WARN: filename:3: This autofix doesn't match.")
}

// If an Autofix doesn't do anything, it must not log any diagnostics.
func (s *Suite) Test_Autofix__noop_replace(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("Makefile", 14, "Original text")

	fix := line.Autofix()
	fix.Warnf("All-uppercase words should not be used at all.")
	fix.ReplaceRegex(`\b[A-Z]{3,}\b`, "---censored---", -1)
	fix.Apply()

	// No output since there was no all-uppercase word in the text.
	t.CheckOutputEmpty()
}

// When using Autofix.Custom, it is tricky to get all the details right.
// For best results, see the existing examples and the documentation.
//
// Since this custom fix only operates on the text of the current line,
// it can handle both the --show-autofix and the --autofix cases using
// the same code.
func (s *Suite) Test_Autofix_Custom__in_memory(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("Makefile",
		"line1",
		"line2",
		"line3")

	doFix := func(line *Line) {
		fix := line.Autofix()
		fix.Warnf("Please write in ALL-UPPERCASE.")
		fix.Custom(func(showAutofix, autofix bool) {
			fix.Describef(int(line.firstLine), "Converting to uppercase")
			if showAutofix || autofix {
				line.Text = strings.ToUpper(line.Text)
			}
		})
		fix.Apply()
	}

	doFix(lines.Lines[0])

	t.CheckOutputLines(
		"WARN: Makefile:1: Please write in ALL-UPPERCASE.")

	t.SetUpCommandLine("--show-autofix")

	doFix(lines.Lines[1])

	t.CheckOutputLines(
		"WARN: Makefile:2: Please write in ALL-UPPERCASE.",
		"AUTOFIX: Makefile:2: Converting to uppercase")
	t.CheckEquals(lines.Lines[1].Text, "LINE2")

	t.SetUpCommandLine("--autofix")

	doFix(lines.Lines[2])

	t.CheckOutputLines(
		"AUTOFIX: Makefile:3: Converting to uppercase")
	t.CheckEquals(lines.Lines[2].Text, "LINE3")
}

// Since the diagnostic doesn't contain the string "few", nothing happens.
func (s *Suite) Test_Autofix_skip(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--only", "few", "--autofix")

	mklines := t.SetUpFileMkLines("filename",
		"VAR=\t111 222 333 444 555 \\",
		"666")
	lines := mklines.lines

	fix := lines.Lines[0].Autofix()
	fix.Warnf("Many.")
	fix.Explain(
		"Explanation.")

	// None of the following actions has any effect because of the --only option above.
	fix.Replace("111", "___")
	fix.ReplaceAfter(" ", "222", "___")
	fix.ReplaceAt(0, 0, "VAR", "NEW")
	fix.ReplaceRegex(`\d+`, "___", 1)
	fix.InsertBefore("before")
	fix.InsertAfter("after")
	fix.Delete()
	fix.Custom(func(showAutofix, autofix bool) {})

	fix.Apply()

	SaveAutofixChanges(lines)

	t.CheckOutputEmpty()
	t.CheckFileLines("filename",
		"VAR=\t111 222 333 444 555 \\",
		"666")
	t.CheckEquals(fix.RawText(), ""+
		"VAR=\t111 222 333 444 555 \\\n"+
		"666\n")
}

// Demonstrates how to filter log messages.
// The --autofix option can restrict the fixes to exactly one group or topic.
func (s *Suite) Test_Autofix_Apply__only(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--autofix", "--source", "--only", "interesting")
	line := t.NewLine("Makefile", 27, "The old song")

	// Is completely ignored, including any autofixes.
	fix := line.Autofix()
	fix.Warnf("Using \"old\" is deprecated.")
	fix.Replace("old", "new1")
	fix.Apply()

	fix.Warnf("Using \"old\" is interesting.")
	fix.Replace("old", "new2")
	fix.Apply()

	t.CheckOutputLines(
		"AUTOFIX: Makefile:27: Replacing \"old\" with \"new2\".",
		"-\tThe old song",
		"+\tThe new2 song")
}

func (s *Suite) Test_Autofix_Apply__panic(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("filename", 123, "text")

	t.ExpectAssert(
		func() {
			fix := line.Autofix()
			fix.Apply()
		})

	t.ExpectAssert(
		func() {
			fix := line.Autofix()
			fix.Replace("from", "to")
			fix.Apply()
		})

	t.ExpectPanic(
		func() {
			fix := line.Autofix()
			fix.Warnf("Warning without period")
			fix.Apply()
		},
		"Pkglint internal error: Autofix: format \"Warning without period\" must end with a period.")
}

// Ensures that empty lines are logged between the diagnostics,
// even when combining normal warnings and autofix warnings.
//
// Up to 2018-10-27, pkglint didn't insert the required empty line in this case.
func (s *Suite) Test_Autofix_Apply__explanation_followed_by_note(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--source")
	line := t.NewLine("README.txt", 123, "text")

	fix := line.Autofix()
	fix.Warnf("A warning with autofix.")
	fix.Explain("Explanation.")
	fix.Replace("text", "Text")
	fix.Apply()

	line.Notef("A note without fix.")

	t.CheckOutputLines(
		">\ttext",
		"WARN: README.txt:123: A warning with autofix.",
		"",
		">\ttext",
		"NOTE: README.txt:123: A note without fix.")
}

func (s *Suite) Test_Autofix_Anyway__autofix_option(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--autofix")
	line := t.NewLine("filename", 5, "text")

	fix := line.Autofix()
	fix.Notef("This line is quite short.")
	fix.Replace("not found", "needle")
	fix.Anyway()
	fix.Apply()

	// The replacement text is not found, therefore the note should not be logged.
	// Because of fix.Anyway, the note should be logged anyway.
	// But because of the --autofix option, the note should not be logged.
	// Therefore, in the end nothing is shown in this case.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Autofix_Anyway__autofix_and_show_autofix_options(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--autofix", "--show-autofix")
	line := t.NewLine("filename", 5, "text")

	fix := line.Autofix()
	fix.Notef("This line is quite short.")
	fix.Replace("not found", "needle")
	fix.Anyway()
	fix.Apply()

	// The text to be replaced is not found. Because nothing is fixed here,
	// there's no need to log anything.
	//
	// But fix.Anyway is set, therefore the diagnostic should be logged even
	// though it cannot be fixed automatically. This comes handy in situations
	// where simple cases can be fixed automatically and more complex cases
	// (often involving special characters that need to be escaped properly)
	// should nevertheless result in a diagnostics.
	//
	// The --autofix option is set, which means that the diagnostics don't
	// get logged, only the actual fixes do.
	//
	// But then there's also the --show-autofix option, which logs the
	// corresponding diagnostic for each autofix that actually changes
	// something. But this autofix doesn't change anything, therefore even
	// the --show-autofix doesn't have an effect.
	//
	// Therefore, in the end nothing is logged in this case.
	t.CheckOutputEmpty()
}

// The --autofix option normally suppresses the diagnostics and just logs
// the actual fixes. Adding the --show-autofix option logs both.
func (s *Suite) Test_Autofix_Apply__autofix_and_show_autofix_options(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--autofix", "--show-autofix")
	line := t.NewLine("filename", 5, "text")

	fix := line.Autofix()
	fix.Notef("This line is quite short.")
	fix.Replace("text", "replacement")
	fix.Apply()

	t.CheckOutputLines(
		"NOTE: filename:5: This line is quite short.",
		"AUTOFIX: filename:5: Replacing \"text\" with \"replacement\".")
}

// In --autofix mode or --show-autofix mode, the fix.Anyway doesn't
// have any effect, therefore the errors from such autofixes are
// not counted, and the exitcode stays at 0.
func (s *Suite) Test_Autofix_Apply__anyway_error(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--autofix")
	mklines := t.SetUpFileMkLines("filename.mk",
		MkCvsID,
		"VAR=\tvalue")

	fix := mklines.mklines[1].Autofix()
	fix.Errorf("From must be To.")
	fix.Replace("from", "to")
	fix.Anyway()
	fix.Apply()

	mklines.SaveAutofixChanges()

	t.CheckEquals(G.Logger.errors, 0)
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Autofix_Apply__source_autofix_no_change(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--autofix", "--source")
	lines := t.SetUpFileLines("filename",
		"word word word")

	fix := lines.Lines[0].Autofix()
	fix.Notef("Word should be replaced, but pkglint is not sure which one.")
	fix.Replace("word", "replacement")
	fix.Anyway()
	fix.Apply()

	lines.SaveAutofixChanges()

	// Nothing is replaced since, as of June 2019, pkglint doesn't
	// know which of the three "word" should be replaced.
	//
	// The note is not logged since fix.Anyway only applies when neither
	// --show-autofix nor --autofix is given in the command line.
	t.CheckOutputEmpty()
	t.CheckFileLines("filename",
		"word word word")
}

// Ensures that without explanations, the separator between the individual
// diagnostics are generated.
func (s *Suite) Test_Autofix_Apply__source_without_explain(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--source", "--explain", "--show-autofix")
	line := t.NewLine("filename", 5, "text")

	fix := line.Autofix()
	fix.Notef("This line is quite short.")
	fix.Replace("text", "replacement")
	fix.Apply()

	fix.Warnf("Follow-up warning, separated.")
	fix.Replace("replacement", "text again")
	fix.Apply()

	t.CheckOutputLines(
		"NOTE: filename:5: This line is quite short.",
		"AUTOFIX: filename:5: Replacing \"text\" with \"replacement\".",
		"-\ttext",
		"+\treplacement",
		"",
		"WARN: filename:5: Follow-up warning, separated.",
		"AUTOFIX: filename:5: Replacing \"replacement\" with \"text again\".",
		"-\ttext",
		"+\ttext again")
}

// After fixing part of a line, the whole line needs to be parsed again.
//
// As of May 2019, this is not done yet.
func (s *Suite) Test_Autofix_Apply__text_after_replacing_string(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--autofix")
	mkline := t.NewMkLine("filename.mk", 123, "VAR=\tvalue")

	fix := mkline.Autofix()
	fix.Notef("Just a demo.")
	fix.Replace("value", "new value")
	fix.Apply()

	t.CheckOutputLines(
		"AUTOFIX: filename.mk:123: Replacing \"value\" with \"new value\".")

	t.CheckEquals(mkline.raw[0].textnl, "VAR=\tnew value\n")
	t.CheckEquals(mkline.raw[0].orignl, "VAR=\tvalue\n")
	t.CheckEquals(mkline.Text, "VAR=\tnew value")
	// TODO: should be updated as well.
	t.CheckEquals(mkline.Value(), "value")
}

// After fixing part of a line, the whole line needs to be parsed again.
//
// As of May 2019, this is not done yet.
func (s *Suite) Test_Autofix_Apply__text_after_replacing_regex(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--autofix")
	mkline := t.NewMkLine("filename.mk", 123, "VAR=\tvalue")

	fix := mkline.Autofix()
	fix.Notef("Just a demo.")
	fix.ReplaceRegex(`va...`, "new value", -1)
	fix.Apply()

	t.CheckOutputLines(
		"AUTOFIX: filename.mk:123: Replacing \"value\" with \"new value\".")

	t.CheckEquals(mkline.raw[0].textnl, "VAR=\tnew value\n")
	t.CheckEquals(mkline.raw[0].orignl, "VAR=\tvalue\n")
	t.CheckEquals(mkline.Text, "VAR=\tnew value")
	// TODO: should be updated as well.
	t.CheckEquals(mkline.Value(), "value")
}

// Pkglint tries to order the diagnostics from top to bottom.
// Still, it could be possible that in a multiline the second line
// gets a diagnostic before the first line. This only happens when
// both replacements happen in the same autofix block, which doesn't
// happen often.
//
// This covers the "action.lineno < first" condition.
func (s *Suite) Test_Autofix_affectedLinenos__reverse(c *check.C) {
	t := s.Init(c)

	test := func(diagnostics ...string) {
		mklines := t.NewMkLines("filename.mk",
			"VAR=\tline 1 \\",
			"\tline 2")
		mkline := mklines.mklines[0]

		fix := mkline.Autofix()
		fix.Warnf("Replacements from bottom to top.")
		fix.Replace("line 2", "bbb")
		fix.Replace("line 1", "aaa")
		fix.Apply()

		t.CheckOutput(diagnostics)
	}

	t.SetUpCommandLine("--source")
	test(
		">\tVAR=\tline 1 \\",
		">\t\tline 2",
		"WARN: filename.mk:1--2: Replacements from bottom to top.")

	t.SetUpCommandLine("--source", "--show-autofix")
	test(
		"WARN: filename.mk:1--2: Replacements from bottom to top.",
		"AUTOFIX: filename.mk:2: Replacing \"line 2\" with \"bbb\".",
		"AUTOFIX: filename.mk:1: Replacing \"line 1\" with \"aaa\".",
		"-\tVAR=\tline 1 \\",
		"+\tVAR=\taaa \\",
		"-\t\tline 2",
		"+\t\tbbb")
}

// Just for branch coverage.
func (s *Suite) Test_Autofix_setDiag__no_testing_mode(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("file.mk", 123, "text")

	G.Testing = false

	fix := line.Autofix()
	fix.Notef("Note.")
	fix.Replace("from", "to")
	fix.Apply()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Autofix_setDiag__bad_call_sequence(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("file.mk", 123, "text")
	fix := line.Autofix()
	fix.Notef("Note.")

	t.ExpectAssert(func() { fix.Notef("Note 2.") })

	fix.level = nil // To cover the second assertion.
	t.ExpectAssert(func() { fix.Notef("Note 2.") })
}

func (s *Suite) Test_Autofix_assertRealLine(c *check.C) {
	t := s.Init(c)

	line := NewLineEOF("filename.mk")
	fix := line.Autofix()
	fix.Warnf("Warning.")

	t.ExpectAssert(func() { fix.Replace("from", "to") })
}

func (s *Suite) Test_SaveAutofixChanges__file_removed(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--autofix")
	lines := t.SetUpFileLines("subdir/file.txt",
		"line 1")
	_ = os.RemoveAll(t.File("subdir"))

	fix := lines.Lines[0].Autofix()
	fix.Warnf("Should start with an uppercase letter.")
	fix.Replace("line", "Line")
	fix.Apply()

	SaveAutofixChanges(lines)

	t.CheckOutputMatches(
		"AUTOFIX: ~/subdir/file.txt:1: Replacing \"line\" with \"Line\".",
		`ERROR: ~/subdir/file.txt.pkglint.tmp: Cannot write: .*`)
}

func (s *Suite) Test_SaveAutofixChanges__file_busy_Windows(c *check.C) {
	t := s.Init(c)

	if runtime.GOOS != "windows" {
		return
	}

	t.SetUpCommandLine("--autofix")
	lines := t.SetUpFileLines("subdir/file.txt",
		"line 1")

	// As long as the file is kept open, it cannot be overwritten or deleted.
	openFile, err := os.OpenFile(t.File("subdir/file.txt"), 0, 0666)
	defer func() { assertNil(openFile.Close(), "") }()
	c.Check(err, check.IsNil)

	fix := lines.Lines[0].Autofix()
	fix.Warnf("Should start with an uppercase letter.")
	fix.Replace("line", "Line")
	fix.Apply()

	SaveAutofixChanges(lines)

	t.CheckOutputMatches(
		"AUTOFIX: ~/subdir/file.txt:1: Replacing \"line\" with \"Line\".",
		`ERROR: ~/subdir/file.txt.pkglint.tmp: Cannot overwrite with autofixed content: .*`)
}

// This test covers the highly unlikely situation in which a file is loaded
// by pkglint, and just before writing the autofixed content back, another
// process takes the file and replaces it with a directory of the same name.
//
// 100% code coverage sometimes requires creativity. :)
func (s *Suite) Test_SaveAutofixChanges__cannot_overwrite(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--autofix")
	lines := t.SetUpFileLines("file.txt",
		"line 1")

	c.Check(os.RemoveAll(t.File("file.txt")), check.IsNil)
	c.Check(os.MkdirAll(t.File("file.txt"), 0777), check.IsNil)

	fix := lines.Lines[0].Autofix()
	fix.Warnf("Should start with an uppercase letter.")
	fix.Replace("line", "Line")
	fix.Apply()

	SaveAutofixChanges(lines)

	t.CheckOutputMatches(
		"AUTOFIX: ~/file.txt:1: Replacing \"line\" with \"Line\".",
		`ERROR: ~/file.txt.pkglint.tmp: Cannot overwrite with autofixed content: .*`)
}

// Up to 2018-11-25, pkglint in some cases logged only the source without
// a corresponding warning.
func (s *Suite) Test_Autofix__lonely_source(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--source")
	G.Logger.Opts.LogVerbose = false // For realistic conditions; otherwise all diagnostics are logged.

	t.SetUpPackage("x11/xorg-cf-files",
		".include \"../../x11/xorgproto/buildlink3.mk\"")
	t.SetUpPackage("x11/xorgproto",
		"DISTNAME=\txorgproto-1.0")
	t.CreateFileDummyBuildlink3("x11/xorgproto/buildlink3.mk")
	t.CreateFileLines("x11/xorgproto/builtin.mk",
		MkCvsID,
		"",
		"BUILTIN_PKG:=\txorgproto",
		"",
		"PRE_XORGPROTO_LIST_MISSING =\tapplewmproto",
		"",
		".for id in ${PRE_XORGPROTO_LIST_MISSING}",
		".endfor")
	t.Chdir(".")
	t.FinishSetUp()

	G.Check("x11/xorg-cf-files")
	G.Check("x11/xorgproto")

	t.CheckOutputLines(
		">\tPRE_XORGPROTO_LIST_MISSING =\tapplewmproto",
		"NOTE: x11/xorgproto/builtin.mk:5: Unnecessary space after variable name \"PRE_XORGPROTO_LIST_MISSING\".")
}

// Up to 2018-11-26, pkglint in some cases logged only the source without
// a corresponding warning.
func (s *Suite) Test_Autofix__lonely_source_2(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--source", "--explain")
	G.Logger.Opts.LogVerbose = false // For realistic conditions; otherwise all diagnostics are logged.

	t.SetUpPackage("print/tex-bibtex8",
		"MAKE_FLAGS+=\tCFLAGS=${CFLAGS.${PKGSRC_COMPILER}}")
	t.Chdir(".")
	t.FinishSetUp()

	G.Check("print/tex-bibtex8")

	t.CheckOutputLines(
		">\tMAKE_FLAGS+=\tCFLAGS=${CFLAGS.${PKGSRC_COMPILER}}",
		"WARN: print/tex-bibtex8/Makefile:20: Please use ${CFLAGS.${PKGSRC_COMPILER}:Q} instead of ${CFLAGS.${PKGSRC_COMPILER}}.",
		"",
		"\tSee the pkgsrc guide, section \"Echoing a string exactly as-is\":",
		"\thttps://www.NetBSD.org/docs/pkgsrc/pkgsrc.html#echo-literal",
		"",
		">\tMAKE_FLAGS+=\tCFLAGS=${CFLAGS.${PKGSRC_COMPILER}}",
		"WARN: print/tex-bibtex8/Makefile:20: The list variable PKGSRC_COMPILER should not be embedded in a word.",
		"",
		"\tWhen a list variable has multiple elements, this expression expands",
		"\tto something unexpected:",
		"",
		"\tExample: ${MASTER_SITE_SOURCEFORGE}directory/ expands to",
		"",
		"\t\thttps://mirror1.sf.net/ https://mirror2.sf.net/directory/",
		"",
		"\tThe first URL is missing the directory. To fix this, write",
		"\t\t${MASTER_SITE_SOURCEFORGE:=directory/}.",
		"",
		"\tExample: -l${LIBS} expands to",
		"",
		"\t\t-llib1 lib2",
		"",
		"\tThe second library is missing the -l. To fix this, write",
		"\t${LIBS:S,^,-l,}.",
		"")
}

// RawText returns the raw text of the fixed line, including line ends.
// This may differ from the original text when the --show-autofix
// or --autofix options are enabled.
func (fix *Autofix) RawText() string {
	var text strings.Builder
	for _, lineBefore := range fix.linesBefore {
		text.WriteString(lineBefore)
	}
	for _, raw := range fix.line.raw {
		text.WriteString(raw.textnl)
	}
	for _, lineAfter := range fix.linesAfter {
		text.WriteString(lineAfter)
	}
	return text.String()
}
