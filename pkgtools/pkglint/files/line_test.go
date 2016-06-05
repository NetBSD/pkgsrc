package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) TestLineModify(c *check.C) {
	s.UseCommandLine(c, "--show-autofix")

	line := NewLine("fname", 1, "dummy", s.NewRawLines(1, "original\n"))

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

func (s *Suite) TestLine_CheckAbsolutePathname(c *check.C) {
	line := NewLine("Makefile", 1, "# dummy", nil)

	line.CheckAbsolutePathname("bindir=/bin")
	line.CheckAbsolutePathname("bindir=/../lib")

	c.Check(s.Output(), equals, "WARN: Makefile:1: Found absolute pathname: /bin\n")
}

func (s *Suite) TestShowAutofix_replace(c *check.C) {
	s.UseCommandLine(c, "--show-autofix", "--source")
	line := NewLineMulti("Makefile", 27, 29, "# old", s.NewRawLines(
		27, "before\n",
		28, "The old song\n",
		29, "after\n"))

	if !line.AutofixReplace("old", "new") {
		line.Warn0("Using \"old\" is deprecated.")
	}

	c.Check(s.Output(), equals, ""+
		"\n"+
		"> before\n"+
		"- The old song\n"+
		"+ The new song\n"+
		"> after\n"+
		"WARN: Makefile:27--29: Using \"old\" is deprecated.\n"+
		"AUTOFIX: Makefile:27--29: Replacing \"old\" with \"new\".\n")
}

func (s *Suite) TestShowAutofix_insert(c *check.C) {
	s.UseCommandLine(c, "--show-autofix", "--source")
	line := NewLine("Makefile", 30, "original", s.NewRawLines(30, "original\n"))

	if !line.AutofixInsertBefore("inserted") {
		line.Warn0("Dummy")
	}

	c.Check(s.Output(), equals, ""+
		"\n"+
		"+ inserted\n"+
		"> original\n"+
		"WARN: Makefile:30: Dummy\n"+
		"AUTOFIX: Makefile:30: Inserting a line \"inserted\" before this line.\n")
}

func (s *Suite) TestShowAutofix_delete(c *check.C) {
	s.UseCommandLine(c, "--show-autofix", "--source")
	line := NewLine("Makefile", 30, "to be deleted", s.NewRawLines(30, "to be deleted\n"))

	if !line.AutofixDelete() {
		line.Warn0("Dummy")
	}

	c.Check(s.Output(), equals, ""+
		"\n"+
		"- to be deleted\n"+
		"WARN: Makefile:30: Dummy\n"+
		"AUTOFIX: Makefile:30: Deleting this line.\n")
}

func (s *Suite) TestLine_CheckTrailingWhitespace(c *check.C) {
	line := NewLine("Makefile", 32, "The line must go on   ", nil)

	line.CheckTrailingWhitespace()

	c.Check(s.Output(), equals, "NOTE: Makefile:32: Trailing white-space.\n")
}
