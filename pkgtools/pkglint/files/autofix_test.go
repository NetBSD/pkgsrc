package main

import (
	"gopkg.in/check.v1"
	"strings"
)

func (s *Suite) Test_Autofix_ReplaceRegex(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--show-autofix")
	lines := t.SetupFileLines("Makefile",
		"line1",
		"line2",
		"line3")

	fix := lines[1].Autofix()
	fix.Warnf("Something's wrong here.")
	fix.ReplaceRegex(`.`, "X", -1)
	fix.Apply()
	SaveAutofixChanges(lines)

	c.Check(lines[1].raw[0].textnl, equals, "XXXXX\n")
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

func (s *Suite) Test_Autofix_ReplaceRegex_with_autofix(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--autofix", "--source")
	lines := t.SetupFileLines("Makefile",
		"line1",
		"line2",
		"line3")

	fix := lines[1].Autofix()
	fix.Warnf("Something's wrong here.")
	fix.ReplaceRegex(`.`, "X", 3)
	fix.Apply()

	t.CheckOutputLines(
		"AUTOFIX: ~/Makefile:2: Replacing \"l\" with \"X\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"i\" with \"X\".",
		"AUTOFIX: ~/Makefile:2: Replacing \"n\" with \"X\".",
		"-\tline2",
		"+\tXXXe2")

	fix.Warnf("Use Y instead of X.")
	fix.Replace("X", "Y")
	fix.Apply()

	t.CheckOutputLines(
		"",
		"AUTOFIX: ~/Makefile:2: Replacing \"X\" with \"Y\".",
		"-\tline2",
		"+\tYXXe2")

	SaveAutofixChanges(lines)

	t.CheckFileLines("Makefile",
		"line1",
		"YXXe2",
		"line3")
}

func (s *Suite) Test_Autofix_ReplaceRegex_with_show_autofix(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--show-autofix", "--source")
	lines := t.SetupFileLines("Makefile",
		"line1",
		"line2",
		"line3")

	fix := lines[1].Autofix()
	fix.Warnf("Something's wrong here.")
	fix.ReplaceRegex(`.`, "X", -1)
	fix.Apply()

	fix.Warnf("Use Y instead of X.")
	fix.Replace("X", "Y")
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
		"AUTOFIX: ~/Makefile:2: Replacing \"X\" with \"Y\".",
		"-\tline2",
		"+\tYXXXX")
}

func (s *Suite) Test_autofix_MkLines(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--autofix")
	t.SetupFileLines("category/basename/Makefile",
		"line1 := value1",
		"line2 := value2",
		"line3 := value3")
	pkg := NewPackage(t.File("category/basename"))
	G.Pkg = pkg
	mklines := pkg.loadPackageMakefile()
	G.Pkg = nil

	fix := mklines.mklines[1].Autofix()
	fix.Warnf("Something's wrong here.")
	fix.ReplaceRegex(`...`, "XXX", -1)
	fix.Apply()

	fix = mklines.mklines[2].Autofix()
	fix.Warnf("Something's wrong here.")
	fix.ReplaceRegex(`...`, "XXX", 1)
	fix.Apply()

	SaveAutofixChanges(mklines.lines)

	t.CheckOutputLines(
		"AUTOFIX: ~/category/basename/Makefile:2: Replacing \"lin\" with \"XXX\".",
		"AUTOFIX: ~/category/basename/Makefile:2: Replacing \"e2 \" with \"XXX\".",
		"AUTOFIX: ~/category/basename/Makefile:2: Replacing \":= \" with \"XXX\".",
		"AUTOFIX: ~/category/basename/Makefile:2: Replacing \"val\" with \"XXX\".",
		"AUTOFIX: ~/category/basename/Makefile:2: Replacing \"ue2\" with \"XXX\".",
		"AUTOFIX: ~/category/basename/Makefile:3: Replacing \"lin\" with \"XXX\".")
	t.CheckFileLines("category/basename/Makefile",
		"line1 := value1",
		"XXXXXXXXXXXXXXX",
		"XXXe3 := value3")
}

func (s *Suite) Test_Autofix__multiple_modifications(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--show-autofix", "--explain")

	line := t.NewLine("fname", 1, "original")

	c.Check(line.autofix, check.IsNil)
	c.Check(line.raw, check.DeepEquals, t.NewRawLines(1, "original\n"))

	{
		fix := line.Autofix()
		fix.Warnf("Silent-Magic-Diagnostic")
		fix.ReplaceRegex(`(.)(.*)(.)`, "lriginao", 1) // XXX: the replacement should be "$3$2$1"
		fix.Apply()
	}

	c.Check(line.autofix, check.NotNil)
	c.Check(line.raw, check.DeepEquals, t.NewRawLines(1, "original\n", "lriginao\n"))
	t.CheckOutputLines(
		"AUTOFIX: fname:1: Replacing \"original\" with \"lriginao\".")

	{
		fix := line.Autofix()
		fix.Warnf("Silent-Magic-Diagnostic")
		fix.Replace("i", "u")
		fix.Apply()
	}

	c.Check(line.autofix, check.NotNil)
	c.Check(line.raw, check.DeepEquals, t.NewRawLines(1, "original\n", "lruginao\n"))
	c.Check(line.raw[0].textnl, equals, "lruginao\n")
	t.CheckOutputLines(
		"AUTOFIX: fname:1: Replacing \"i\" with \"u\".")

	{
		fix := line.Autofix()
		fix.Warnf("Silent-Magic-Diagnostic")
		fix.Replace("lruginao", "middle")
		fix.Apply()
	}

	c.Check(line.autofix, check.NotNil)
	c.Check(line.raw, check.DeepEquals, t.NewRawLines(1, "original\n", "middle\n"))
	c.Check(line.raw[0].textnl, equals, "middle\n")
	t.CheckOutputLines(
		"AUTOFIX: fname:1: Replacing \"lruginao\" with \"middle\".")

	{
		fix := line.Autofix()
		fix.Warnf("Silent-Magic-Diagnostic")
		fix.InsertBefore("before")
		fix.Apply()

		fix.Warnf("Silent-Magic-Diagnostic")
		fix.InsertBefore("between before and middle")
		fix.Apply()

		fix.Warnf("Silent-Magic-Diagnostic")
		fix.InsertAfter("between middle and after")
		fix.Apply()

		fix.Notef("This diagnostic is necessary for the following explanation.")
		fix.Explain(
			"When inserting multiple lines, Apply must be called in-between.",
			"Otherwise the changes are not described to the human reader.")
		fix.InsertAfter("after")
		fix.Apply()
	}

	c.Check(line.autofix.linesBefore, check.DeepEquals, []string{
		"before\n",
		"between before and middle\n"})
	c.Check(line.autofix.lines[0].textnl, equals, "middle\n")
	c.Check(line.autofix.linesAfter, deepEquals, []string{
		"between middle and after\n",
		"after\n"})
	t.CheckOutputLines(
		"AUTOFIX: fname:1: Inserting a line \"before\" before this line.",
		"AUTOFIX: fname:1: Inserting a line \"between before and middle\" before this line.",
		"AUTOFIX: fname:1: Inserting a line \"between middle and after\" after this line.",
		"NOTE: fname:1: This diagnostic is necessary for the following explanation.",
		"AUTOFIX: fname:1: Inserting a line \"after\" after this line.",
		"",
		"\tWhen inserting multiple lines, Apply must be called in-between.",
		"\tOtherwise the changes are not described to the human reader.",
		"")

	{
		fix := line.Autofix()
		fix.Warnf("Silent-Magic-Diagnostic")
		fix.Delete()
		fix.Apply()
	}

	c.Check(line.autofix.linesBefore, check.DeepEquals, []string{
		"before\n",
		"between before and middle\n"})
	c.Check(line.autofix.lines[0].textnl, equals, "")
	c.Check(line.autofix.linesAfter, deepEquals, []string{
		"between middle and after\n",
		"after\n"})
	t.CheckOutputLines(
		"AUTOFIX: fname:1: Deleting this line.")
}

func (s *Suite) Test_Autofix_show_source_code(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--show-autofix", "--source")
	mklines := t.SetupFileMkLines("Makefile",
		MkRcsID,
		"# before \\",
		"The old song \\",
		"after")
	line := mklines.lines[1]

	{
		fix := line.Autofix()
		fix.Warnf("Using \"old\" is deprecated.")
		fix.Replace("old", "new")
		fix.Apply()
	}

	t.CheckOutputLines(
		"WARN: ~/Makefile:2--4: Using \"old\" is deprecated.",
		"AUTOFIX: ~/Makefile:3: Replacing \"old\" with \"new\".",
		">\t# before \\",
		"-\tThe old song \\",
		"+\tThe new song \\",
		">\tafter")
}

func (s *Suite) Test_Autofix_InsertBefore(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--show-autofix", "--source")
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

	t.SetupCommandLine("--show-autofix", "--source")
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

// Demonstrates that the --show-autofix option only shows those diagnostics
// that would be fixed.
func (s *Suite) Test_Autofix_suppress_unfixable_warnings(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--show-autofix", "--source")
	lines := t.NewLines("Makefile",
		"line1",
		"line2",
		"line3")

	lines[0].Warnf("This warning is not shown since it is not automatically fixed.")

	fix := lines[1].Autofix()
	fix.Warnf("Something's wrong here.")
	fix.ReplaceRegex(`.`, "X", -1)
	fix.Apply()

	fix.Warnf("The XXX marks are usually not fixed, use TODO instead.")
	fix.Replace("XXX", "TODO")
	fix.Apply()

	lines[2].Warnf("Neither is this warning shown.")

	t.CheckOutputLines(
		"WARN: Makefile:2: Something's wrong here.",
		"AUTOFIX: Makefile:2: Replacing \"l\" with \"X\".",
		"AUTOFIX: Makefile:2: Replacing \"i\" with \"X\".",
		"AUTOFIX: Makefile:2: Replacing \"n\" with \"X\".",
		"AUTOFIX: Makefile:2: Replacing \"e\" with \"X\".",
		"AUTOFIX: Makefile:2: Replacing \"2\" with \"X\".",
		"-\tline2",
		"+\tXXXXX",
		"",
		"WARN: Makefile:2: The XXX marks are usually not fixed, use TODO instead.",
		"AUTOFIX: Makefile:2: Replacing \"XXX\" with \"TODO\".",
		"-\tline2",
		"+\tTODOXX")
}

// If an Autofix doesn't do anything it must not log any diagnostics.
func (s *Suite) Test_Autofix_failed_replace(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("Makefile", 14, "Original text")

	fix := line.Autofix()
	fix.Warnf("All-uppercase words should not be used at all.")
	fix.ReplaceRegex(`\b[A-Z]{3,}\b`, "---censored---", -1)
	fix.Apply()

	// No output since there was no all-uppercase word in the text.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_SaveAutofixChanges(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--autofix")
	lines := t.SetupFileLines("DESCR",
		"Line 1",
		"Line 2")

	fix := lines[0].Autofix()
	fix.Warnf("Dummy warning.")
	fix.Replace("X", "Y")
	fix.Apply()

	// Since nothing has been effectively changed,
	// nothing needs to be saved.
	SaveAutofixChanges(lines)

	// And therefore, no AUTOFIX action must appear in the log.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Autofix_CustomFix(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("Makefile",
		"line1",
		"line2",
		"line3")

	doFix := func(line Line) {
		fix := line.Autofix()
		fix.Warnf("Please write in ALL-UPPERCASE.")
		fix.Custom(func(printAutofix, autofix bool) {
			fix.Describef(int(line.firstLine), "Converting to uppercase")
			if printAutofix || autofix {
				line.Text = strings.ToUpper(line.Text)
			}
		})
		fix.Apply()
	}

	doFix(lines[0])

	t.CheckOutputLines(
		"WARN: Makefile:1: Please write in ALL-UPPERCASE.")

	t.SetupCommandLine("--show-autofix")

	doFix(lines[1])

	t.CheckOutputLines(
		"WARN: Makefile:2: Please write in ALL-UPPERCASE.",
		"AUTOFIX: Makefile:2: Converting to uppercase")
	c.Check(lines[1].Text, equals, "LINE2")

	t.SetupCommandLine("--autofix")

	doFix(lines[2])

	t.CheckOutputLines(
		"AUTOFIX: Makefile:3: Converting to uppercase")
	c.Check(lines[2].Text, equals, "LINE3")
}

func (s *Suite) Test_Autofix_Explain(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("Makefile", 74, "line1")

	fix := line.Autofix()
	fix.Warnf("Please write row instead of line.")
	fix.Replace("line", "row")
	fix.Explain("Explanation")
	fix.Apply()

	t.CheckOutputLines(
		"WARN: Makefile:74: Please write row instead of line.")
	c.Check(G.explanationsAvailable, equals, true)
}

// Since the diagnostic doesn't contain the string "few", nothing happens.
func (s *Suite) Test_Autofix__skip(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--only", "few", "--autofix")

	lines := t.SetupFileLines("fname",
		"111 222 333 444 555")

	fix := lines[0].Autofix()
	fix.Warnf("Many.")
	fix.Explain(
		"Explanation.")
	fix.Replace("111", "___")
	fix.ReplaceAfter(" ", "222", "___")
	fix.ReplaceRegex(`\d+`, "___", 1)
	fix.InsertBefore("before")
	fix.InsertAfter("after")
	fix.Delete()
	fix.Apply()

	SaveAutofixChanges(lines)

	t.CheckOutputEmpty()
	t.CheckFileLines("fname",
		"111 222 333 444 555")
	c.Check(lines[0].raw[0].textnl, equals, "111 222 333 444 555\n")
}
