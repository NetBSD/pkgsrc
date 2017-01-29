package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) Test_Line_modifications(c *check.C) {
	s.Init(c)
	s.UseCommandLine("--show-autofix")

	line := NewLine("fname", 1, "dummy", s.NewRawLines(1, "original\n")).(*LineImpl)

	c.Check(line.changed, equals, false)
	c.Check(line.raw, check.DeepEquals, s.NewRawLines(1, "original\n"))

	line.AutofixReplaceRegexp(`(.)(.*)(.)`, "$3$2$1")

	c.Check(line.changed, equals, true)
	c.Check(line.raw, check.DeepEquals, s.NewRawLines(1, "original\n", "lriginao\n"))

	line.changed = false
	line.AutofixReplace("i", "u")

	c.Check(line.changed, equals, true)
	c.Check(line.raw, check.DeepEquals, s.NewRawLines(1, "original\n", "lruginao\n"))
	c.Check(line.raw[0].textnl, equals, "lruginao\n")

	line.changed = false
	line.AutofixReplace("lruginao", "middle")

	c.Check(line.changed, equals, true)
	c.Check(line.raw, check.DeepEquals, s.NewRawLines(1, "original\n", "middle\n"))
	c.Check(line.raw[0].textnl, equals, "middle\n")

	line.AutofixInsertBefore("before")
	line.AutofixInsertBefore("between before and middle")
	line.AutofixInsertAfter("between middle and after")
	line.AutofixInsertAfter("after")

	c.Check(line.modifiedLines(), check.DeepEquals, []string{
		"before\n",
		"between before and middle\n",
		"middle\n",
		"between middle and after\n",
		"after\n"})

	line.AutofixDelete()

	c.Check(line.modifiedLines(), check.DeepEquals, []string{
		"before\n",
		"between before and middle\n",
		"",
		"between middle and after\n",
		"after\n"})
}

func (s *Suite) Test_Line_show_autofix_AutofixReplace(c *check.C) {
	s.Init(c)
	s.UseCommandLine("--show-autofix", "--source")
	line := NewLineMulti("Makefile", 27, 29, "# old", s.NewRawLines(
		27, "before\n",
		28, "The old song\n",
		29, "after\n"))

	if !line.AutofixReplace("old", "new") {
		line.Warnf("Using \"old\" is deprecated.")
	}

	s.CheckOutputLines(
		"",
		"> before",
		"- The old song",
		"+ The new song",
		"> after",
		"WARN: Makefile:27--29: Using \"old\" is deprecated.",
		"AUTOFIX: Makefile:27--29: Replacing \"old\" with \"new\".")
}

func (s *Suite) Test_Line_show_autofix_AutofixInsertBefore(c *check.C) {
	s.Init(c)
	s.UseCommandLine("--show-autofix", "--source")
	line := NewLine("Makefile", 30, "original", s.NewRawLines(30, "original\n"))

	if !line.AutofixInsertBefore("inserted") {
		line.Warnf("Dummy")
	}

	s.CheckOutputLines(
		"",
		"+ inserted",
		"> original",
		"WARN: Makefile:30: Dummy",
		"AUTOFIX: Makefile:30: Inserting a line \"inserted\" before this line.")
}

func (s *Suite) Test_Line_show_autofix_AutofixDelete(c *check.C) {
	s.Init(c)
	s.UseCommandLine("--show-autofix", "--source")
	line := NewLine("Makefile", 30, "to be deleted", s.NewRawLines(30, "to be deleted\n"))

	if !line.AutofixDelete() {
		line.Warnf("Dummy")
	}

	s.CheckOutputLines(
		"",
		"- to be deleted",
		"WARN: Makefile:30: Dummy",
		"AUTOFIX: Makefile:30: Deleting this line.")
}
