package main

import (
	check "gopkg.in/check.v1"
	"io/ioutil"
)

func (s *Suite) TestChecklinesPatch_WithComment(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	lines := s.NewLines("patch-WithComment",
		"$"+"NetBSD$",
		"",
		"Text",
		"Text",
		"",
		"--- file.orig",
		"+++ file",
		"@@ -5,3 +5,3 @@",
		" context before",
		"-old line",
		"+old line",
		" context after")

	ChecklinesPatch(lines)

	c.Check(s.Output(), equals, "")
}

func (s *Suite) TestChecklinesPatch_WithoutEmptyLine(c *check.C) {
	fname := s.CreateTmpFile(c, "patch-WithoutEmptyLines", "dummy")
	s.UseCommandLine(c, "-Wall", "--autofix")
	lines := s.NewLines(fname,
		"$"+"NetBSD$",
		"Text",
		"--- file.orig",
		"+++ file",
		"@@ -5,3 +5,3 @@",
		" context before",
		"-old line",
		"+old line",
		" context after")

	ChecklinesPatch(lines)

	c.Check(s.Output(), equals, ""+
		"AUTOFIX: ~/patch-WithoutEmptyLines:2: Inserting a line \"\" before this line.\n"+
		"AUTOFIX: ~/patch-WithoutEmptyLines:3: Inserting a line \"\" before this line.\n"+
		"AUTOFIX: ~/patch-WithoutEmptyLines: Has been auto-fixed. Please re-run pkglint.\n")

	fixed, err := ioutil.ReadFile(fname)
	c.Assert(err, check.IsNil)
	c.Check(string(fixed), equals, ""+
		"$"+"NetBSD$\n"+
		"\n"+
		"Text\n"+
		"\n"+
		"--- file.orig\n"+
		"+++ file\n"+
		"@@ -5,3 +5,3 @@\n"+
		" context before\n"+
		"-old line\n"+
		"+old line\n"+
		" context after\n")
}

func (s *Suite) TestChecklinesPatch_WithoutComment(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	lines := s.NewLines("patch-WithoutComment",
		"$"+"NetBSD$",
		"",
		"--- file.orig",
		"+++ file",
		"@@ -5,3 +5,3 @@",
		" context before",
		"-old line",
		"+old line",
		" context after")

	ChecklinesPatch(lines)

	c.Check(s.Output(), equals, "ERROR: patch-WithoutComment:3: Each patch must be documented.\n")
}

func (s *Suite) TestChecklineOtherAbsolutePathname(c *check.C) {
	line := NewLine("patch-ag", 1, "+$install -s -c ./bin/rosegarden ${DESTDIR}$BINDIR", nil)

	checklineOtherAbsolutePathname(line, line.Text)

	c.Check(s.Output(), equals, "")
}

func (s *Suite) TestChecklinesPatch_ErrorCode(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	lines := s.NewLines("patch-ErrorCode",
		"$"+"NetBSD$",
		"",
		"*** Error code 1", // Looks like a context diff, but isn’t.
		"",
		"--- file.orig",
		"+++ file",
		"@@ -5,3 +5,3 @@",
		" context before",
		"-old line",
		"+old line",
		" context after")

	ChecklinesPatch(lines)

	c.Check(s.Output(), equals, "")
}

func (s *Suite) TestChecklinesPatch_WrongOrder(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	lines := s.NewLines("patch-WrongOrder",
		"$"+"NetBSD$",
		"",
		"Text",
		"Text",
		"",
		"+++ file",      // Wrong
		"--- file.orig", // Wrong
		"@@ -5,3 +5,3 @@",
		" context before",
		"-old line",
		"+old line",
		" context after")

	ChecklinesPatch(lines)

	c.Check(s.Output(), equals, "WARN: patch-WrongOrder:7: Unified diff headers should be first ---, then +++.\n")
}

func (s *Suite) TestChecklinesPatch_ContextDiff(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	lines := s.NewLines("patch-ctx",
		"$"+"NetBSD$",
		"",
		"diff -cr history.c.orig history.c",
		"*** history.c.orig",
		"--- history.c")

	ChecklinesPatch(lines)

	c.Check(s.Output(), equals, ""+
		"ERROR: patch-ctx:4: Each patch must be documented.\n"+
		"WARN: patch-ctx:4: Please use unified diffs (diff -u) for patches.\n")
}

func (s *Suite) TestChecklinesPatch_NoPatch(c *check.C) {
	lines := s.NewLines("patch-aa",
		"$"+"NetBSD$",
		"",
		"-- oldfile",
		"++ newfile")

	ChecklinesPatch(lines)

	c.Check(s.Output(), equals, "ERROR: patch-aa: Contains no patch.\n")
}

func (s *Suite) TestChecklinesPatch_TwoPatches(c *check.C) {
	lines := s.NewLines("patch-aa",
		"$"+"NetBSD$",
		"",
		"--- oldfile",
		"+++ newfile",
		"@@ -1 +1 @@",
		"-old",
		"+new",
		"--- oldfile2",
		"+++ newfile2",
		"@@ -1 +1 @@",
		"-old",
		"+new")

	ChecklinesPatch(lines)

	c.Check(s.Output(), equals, ""+
		"ERROR: patch-aa:3: Each patch must be documented.\n"+
		"WARN: patch-aa: Contains patches for 2 files, should be only one.\n")
}

func (s *Suite) TestChecklinesPatch_PatchlikeDocumentation(c *check.C) {
	lines := s.NewLines("patch-aa",
		"$"+"NetBSD$",
		"",
		"--- oldfile",
		"",
		"+++ newfile",
		"",
		"*** oldOrNewFile")

	ChecklinesPatch(lines)

	c.Check(s.Output(), equals, "ERROR: patch-aa: Contains no patch.\n")
}

func (s *Suite) TestChecklinesPatch_OnlyUnifiedHeader(c *check.C) {
	lines := s.NewLines("patch-unified",
		"$"+"NetBSD$",
		"",
		"Documentation for the patch",
		"",
		"--- file.orig",
		"+++ file")

	ChecklinesPatch(lines)

	c.Check(s.Output(), equals, "ERROR: patch-unified:EOF: No patch hunks for \"file\".\n")
}

func (s *Suite) TestChecklinesPatch_OnlyContextHeader(c *check.C) {
	lines := s.NewLines("patch-context",
		"$"+"NetBSD$",
		"",
		"Documentation for the patch",
		"",
		"*** file.orig",
		"--- file")

	ChecklinesPatch(lines)

	c.Check(s.Output(), equals, "WARN: patch-context:5: Please use unified diffs (diff -u) for patches.\n")
}

func (s *Suite) TestChecklinesPatch_Makefile(c *check.C) {
	lines := s.NewLines("patch-unified",
		"$"+"NetBSD$",
		"",
		"Documentation for the patch",
		"",
		"--- Makefile.orig",
		"+++ Makefile",
		"@@ -1,3 +1,5 @@",
		" \t/bin/cp context before",
		"-\t/bin/cp deleted",
		"+\t/bin/cp added",
		"+#\t/bin/cp added comment",
		"+# added comment",
		" \t/bin/cp context after")

	ChecklinesPatch(lines)

	c.Check(s.Output(), equals, ""+
		"WARN: patch-unified:10: Found absolute pathname: /bin/cp\n")

	G.opts.WarnExtra = true

	ChecklinesPatch(lines)

	c.Check(s.Output(), equals, ""+
		"WARN: patch-unified:8: Found absolute pathname: /bin/cp\n"+
		"WARN: patch-unified:10: Found absolute pathname: /bin/cp\n"+
		"WARN: patch-unified:13: Found absolute pathname: /bin/cp\n")
}

func (s *Suite) TestChecklinesPatch_NoNewline_withFollowingText(c *check.C) {
	lines := s.NewLines("patch-aa",
		"$"+"NetBSD$",
		"",
		"comment",
		"",
		"--- oldfile",
		"+++ newfile",
		"@@ -1 +1 @@",
		"-old",
		"\\ No newline at end of file",
		"+new",
		"\\ No newline at end of file",
		"last line (a comment)")

	ChecklinesPatch(lines)

	c.Check(s.Output(), equals, "WARN: patch-aa:12: Empty line or end of file expected.\n")
}

func (s *Suite) TestChecklinesPatch_NoNewline(c *check.C) {
	lines := s.NewLines("patch-aa",
		"$"+"NetBSD$",
		"",
		"comment",
		"",
		"--- oldfile",
		"+++ newfile",
		"@@ -1 +1 @@",
		"-old",
		"\\ No newline at end of file",
		"+new",
		"\\ No newline at end of file")

	ChecklinesPatch(lines)

	c.Check(s.Output(), equals, "")
}

func (s *Suite) TestChecklinesPatch_ShortAtEof(c *check.C) {
	lines := s.NewLines("patch-aa",
		"$"+"NetBSD$",
		"",
		"comment",
		"",
		"--- oldfile",
		"+++ newfile",
		"@@ -1,7 +1,6 @@",
		" 1",
		" 2",
		" 3",
		"-4",
		" 5",
		" 6") // Line 7 was empty, therefore omitted

	ChecklinesPatch(lines)

	c.Check(s.Output(), equals, "")
}

// In some context lines, the leading space character is missing.
// Since this is no problem for patch(1), pkglint also doesn’t complain.
func (s *Suite) TestChecklinesPatch_AddTab(c *check.C) {
	lines := s.NewLines("patch-aa",
		"$"+"NetBSD$",
		"",
		"comment",
		"",
		"--- oldfile",
		"+++ newfile",
		"@@ -1,3 +1,3 @@",
		"\tcontext",
		"-old",
		"+new",
		"\tcontext")

	ChecklinesPatch(lines)

	c.Check(s.Output(), equals, "")
}
