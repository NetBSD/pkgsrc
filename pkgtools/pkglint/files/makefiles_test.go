package main

import (
	check "gopkg.in/check.v1"
)

// In variable assignments, a plain '#' introduces a line comment, unless
// it is escaped by a backslash. In shell commands, on the other hand, it
// is interpreted literally.
func (s *Suite) TestParselineMk_VarAssign(c *check.C) {
	line := NewLine("fname", "1", "SED_CMD=\t's,\\#,hash,g'", nil)

	parselineMk(line)

	c.Check(line.extra["varname"], equals, "SED_CMD")
	c.Check(line.extra["value"], equals, "'s,#,hash,g'")
}

func (s *Suite) TestCheckForUsedComment_OK(c *check.C) {
	lines := s.NewLines("Makefile.common",
		"# $"+"NetBSD$",
		"",
		"# used by sysutils/mc")

	checkForUsedComment(lines, "sysutils/mc")
}

func (s *Suite) TestCheckForUsedComment_ShortFile0(c *check.C) {
	lines := s.NewLines("Makefile.common")

	checkForUsedComment(lines, "category/package")
}

func (s *Suite) TestCheckForUsedComment_ShortFile1(c *check.C) {
	lines := s.NewLines("Makefile.common",
		"# $"+"NetBSD$")

	checkForUsedComment(lines, "category/package")
}

func (s *Suite) TestCheckForUsedComment_ShortFile2(c *check.C) {
	lines := s.NewLines("Makefile.common",
		"# $"+"NetBSD$",
		"")

	checkForUsedComment(lines, "category/package")
}

func (s *Suite) TestCheckForUsedComment_NotMentioned(c *check.C) {
	lines := s.NewLines("Makefile.common",
		"# $"+"NetBSD$",
		"",
		"VARNAME=\tvalue")

	checkForUsedComment(lines, "category/package")

	c.Check(s.Output(), equals, "WARN: Makefile.common:2: Please add a line \"# used by category/package\" here.\n")
}

func (s *Suite) TestCheckForUsedComment_OnlyComments(c *check.C) {
	lines := s.NewLines("Makefile.common",
		"# $"+"NetBSD$",
		"#",
		"#")

	checkForUsedComment(lines, "category/package")

	c.Check(s.Output(), equals, "WARN: Makefile.common:3: Please add a line \"# used by category/package\" here.\n")
}
