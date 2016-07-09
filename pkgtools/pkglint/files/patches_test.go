package main

import (
	check "gopkg.in/check.v1"
	"io/ioutil"
)

func (s *Suite) Test_ChecklinesPatch__with_comment(c *check.C) {
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

func (s *Suite) Test_ChecklinesPatch__without_empty_line(c *check.C) {
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

func (s *Suite) Test_ChecklinesPatch__without_comment(c *check.C) {
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

func (s *Suite) Test_ChecklinesPatch__git_without_comment(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	lines := s.NewLines("patch-aa",
		"$"+"NetBSD$",
		"",
		"diff --git a/aa b/aa",
		"index 1234567..1234567 100644",
		"--- a/aa",
		"+++ b/aa",
		"@@ -1,1 +1,1 @@",
		"-old",
		"+new")

	ChecklinesPatch(lines)

	c.Check(s.Output(), equals, "ERROR: patch-aa:5: Each patch must be documented.\n")
}

func (s *Suite) Test_checklineOtherAbsolutePathname(c *check.C) {
	line := NewLine("patch-ag", 1, "+$install -s -c ./bin/rosegarden ${DESTDIR}$BINDIR", nil)

	checklineOtherAbsolutePathname(line, line.Text)

	c.Check(s.Output(), equals, "")
}

func (s *Suite) Test_ChecklinesPatch__error_code(c *check.C) {
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

func (s *Suite) Test_ChecklinesPatch__wrong_header_order(c *check.C) {
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

func (s *Suite) Test_ChecklinesPatch__context_diff(c *check.C) {
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

func (s *Suite) Test_ChecklinesPatch__no_patch(c *check.C) {
	lines := s.NewLines("patch-aa",
		"$"+"NetBSD$",
		"",
		"-- oldfile",
		"++ newfile")

	ChecklinesPatch(lines)

	c.Check(s.Output(), equals, "ERROR: patch-aa: Contains no patch.\n")
}

func (s *Suite) Test_ChecklinesPatch__two_patched_files(c *check.C) {
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

func (s *Suite) Test_ChecklinesPatch__documentation_that_looks_like_patch_lines(c *check.C) {
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

func (s *Suite) Test_ChecklinesPatch__only_unified_header_but_no_content(c *check.C) {
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

func (s *Suite) Test_ChecklinesPatch__only_context_header_but_no_content(c *check.C) {
	lines := s.NewLines("patch-context",
		"$"+"NetBSD$",
		"",
		"Documentation for the patch",
		"",
		"*** file.orig",
		"--- file")

	ChecklinesPatch(lines)

	// Context diffs are deprecated, therefore it is not worth
	// adding extra code for checking them thoroughly.
	c.Check(s.Output(), equals, "WARN: patch-context:5: Please use unified diffs (diff -u) for patches.\n")
}

func (s *Suite) Test_ChecklinesPatch__Makefile_with_absolute_pathnames(c *check.C) {
	lines := s.NewLines("patch-unified",
		"$"+"NetBSD$",
		"",
		"Documentation for the patch",
		"",
		"--- Makefile.orig",
		"+++ Makefile",
		"@@ -1,3 +1,7 @@",
		" \t/bin/cp context before",
		"-\t/bin/cp deleted",
		"+\t/bin/cp added",
		"+#\t/bin/cp added comment",
		"+# added comment",
		"+\t${DESTDIR}/bin/cp added",
		"+\t${prefix}/bin/cp added",
		" \t/bin/cp context after")

	ChecklinesPatch(lines)

	c.Check(s.Output(), equals, ""+
		"WARN: patch-unified:10: Found absolute pathname: /bin/cp\n"+
		"WARN: patch-unified:13: Found absolute pathname: /bin/cp\n")

	G.opts.WarnExtra = true

	ChecklinesPatch(lines)

	c.Check(s.Output(), equals, ""+
		"WARN: patch-unified:8: Found absolute pathname: /bin/cp\n"+
		"WARN: patch-unified:10: Found absolute pathname: /bin/cp\n"+
		"WARN: patch-unified:13: Found absolute pathname: /bin/cp\n"+
		"WARN: patch-unified:15: Found absolute pathname: /bin/cp\n")
}

func (s *Suite) Test_ChecklinesPatch__no_newline_with_text_following(c *check.C) {
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

func (s *Suite) Test_ChecklinesPatch__no_newline(c *check.C) {
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

func (s *Suite) Test_ChecklinesPatch__empty_lines_left_out_at_eof(c *check.C) {
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
func (s *Suite) Test_ChecklinesPatch__context_lines_with_tab_instead_of_space(c *check.C) {
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
