package main

import "gopkg.in/check.v1"

func (s *Suite) Test_ChecklinesPatch__with_comment(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	lines := t.NewLines("patch-WithComment",
		RcsId,
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

	t.CheckOutputEmpty()
}

func (s *Suite) Test_ChecklinesPatch__without_empty_line__autofix(c *check.C) {
	t := s.Init(c)

	patchLines := t.SetupFileLines("patch-WithoutEmptyLines",
		RcsId,
		"Text",
		"--- file.orig",
		"+++ file",
		"@@ -5,3 +5,3 @@",
		" context before",
		"-old line",
		"+old line",
		" context after")
	t.SetupFileLines("distinfo",
		RcsId,
		"",
		"SHA1 (some patch) = 87ffcaaa0b0677ec679fff612b44df1af05f04df") // Taken from breakpoint at AutofixDistinfo

	t.SetupCommandLine("-Wall", "--autofix")
	G.CurrentDir = t.TmpDir()
	G.Pkg = &Package{DistinfoFile: "distinfo"}

	ChecklinesPatch(patchLines)

	t.CheckOutputLines(
		"AUTOFIX: ~/patch-WithoutEmptyLines:2: Inserting a line \"\" before this line.",
		"AUTOFIX: ~/patch-WithoutEmptyLines:3: Inserting a line \"\" before this line.",
		"AUTOFIX: ~/distinfo:3: Replacing \"87ffcaaa0b0677ec679fff612b44df1af05f04df\" "+
			"with \"a7c35294b3853da0acedf8a972cb266baa9582a3\".")

	t.CheckFileLines("patch-WithoutEmptyLines",
		RcsId,
		"",
		"Text",
		"",
		"--- file.orig",
		"+++ file",
		"@@ -5,3 +5,3 @@",
		" context before",
		"-old line",
		"+old line",
		" context after")
	t.CheckFileLines("distinfo",
		RcsId,
		"",
		"SHA1 (some patch) = a7c35294b3853da0acedf8a972cb266baa9582a3")
}

func (s *Suite) Test_ChecklinesPatch__without_comment(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	lines := t.NewLines("patch-WithoutComment",
		RcsId,
		"",
		"--- file.orig",
		"+++ file",
		"@@ -5,3 +5,3 @@",
		" context before",
		"-old line",
		"+old line",
		" context after")

	ChecklinesPatch(lines)

	t.CheckOutputLines(
		"ERROR: patch-WithoutComment:3: Each patch must be documented.")
}

func (s *Suite) Test_ChecklinesPatch__git_without_comment(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	lines := t.NewLines("patch-aa",
		RcsId,
		"",
		"diff --git a/aa b/aa",
		"index 1234567..1234567 100644",
		"--- a/aa",
		"+++ b/aa",
		"@@ -1,1 +1,1 @@",
		"-old",
		"+new")

	ChecklinesPatch(lines)

	t.CheckOutputLines(
		"ERROR: patch-aa:5: Each patch must be documented.")
}

func (s *Suite) Test_checklineOtherAbsolutePathname(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("patch-ag", 1, "+$install -s -c ./bin/rosegarden ${DESTDIR}$BINDIR")

	checklineOtherAbsolutePathname(line, line.Text)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_ChecklinesPatch__error_code(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	lines := t.NewLines("patch-ErrorCode",
		RcsId,
		"",
		"*** Error code 1", // Looks like a context diff, but isn't.
		"",
		"--- file.orig",
		"+++ file",
		"@@ -5,3 +5,3 @@",
		" context before",
		"-old line",
		"+old line",
		" context after")

	ChecklinesPatch(lines)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_ChecklinesPatch__wrong_header_order(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	lines := t.NewLines("patch-WrongOrder",
		RcsId,
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

	t.CheckOutputLines(
		"WARN: patch-WrongOrder:7: Unified diff headers should be first ---, then +++.")
}

func (s *Suite) Test_ChecklinesPatch__context_diff(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	lines := t.NewLines("patch-ctx",
		RcsId,
		"",
		"diff -cr history.c.orig history.c",
		"*** history.c.orig",
		"--- history.c")

	ChecklinesPatch(lines)

	t.CheckOutputLines(
		"ERROR: patch-ctx:4: Each patch must be documented.",
		"WARN: patch-ctx:4: Please use unified diffs (diff -u) for patches.")
}

func (s *Suite) Test_ChecklinesPatch__no_patch(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("patch-aa",
		RcsId,
		"",
		"-- oldfile",
		"++ newfile")

	ChecklinesPatch(lines)

	t.CheckOutputLines(
		"ERROR: patch-aa: Contains no patch.")
}

func (s *Suite) Test_ChecklinesPatch__two_patched_files(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("patch-aa",
		RcsId,
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

	t.CheckOutputLines(
		"ERROR: patch-aa:3: Each patch must be documented.",
		"WARN: patch-aa: Contains patches for 2 files, should be only one.")
}

func (s *Suite) Test_ChecklinesPatch__documentation_that_looks_like_patch_lines(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("patch-aa",
		RcsId,
		"",
		"--- oldfile",
		"",
		"+++ newfile",
		"",
		"*** oldOrNewFile")

	ChecklinesPatch(lines)

	t.CheckOutputLines(
		"ERROR: patch-aa: Contains no patch.")
}

func (s *Suite) Test_ChecklinesPatch__only_unified_header_but_no_content(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("patch-unified",
		RcsId,
		"",
		"Documentation for the patch",
		"",
		"--- file.orig",
		"+++ file")

	ChecklinesPatch(lines)

	t.CheckOutputLines(
		"ERROR: patch-unified:EOF: No patch hunks for \"file\".")
}

func (s *Suite) Test_ChecklinesPatch__only_context_header_but_no_content(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("patch-context",
		RcsId,
		"",
		"Documentation for the patch",
		"",
		"*** file.orig",
		"--- file")

	ChecklinesPatch(lines)

	// Context diffs are deprecated, therefore it is not worth
	// adding extra code for checking them thoroughly.
	t.CheckOutputLines(
		"WARN: patch-context:5: Please use unified diffs (diff -u) for patches.")
}

func (s *Suite) Test_ChecklinesPatch__Makefile_with_absolute_pathnames(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("patch-unified",
		RcsId,
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

	t.CheckOutputLines(
		"WARN: patch-unified:10: Found absolute pathname: /bin/cp",
		"WARN: patch-unified:13: Found absolute pathname: /bin/cp")

	G.opts.WarnExtra = true

	ChecklinesPatch(lines)

	t.CheckOutputLines(
		"WARN: patch-unified:8: Found absolute pathname: /bin/cp",
		"WARN: patch-unified:10: Found absolute pathname: /bin/cp",
		"WARN: patch-unified:13: Found absolute pathname: /bin/cp",
		"WARN: patch-unified:15: Found absolute pathname: /bin/cp")
}

func (s *Suite) Test_ChecklinesPatch__no_newline_with_text_following(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("patch-aa",
		RcsId,
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

	t.CheckOutputLines(
		"WARN: patch-aa:12: Empty line or end of file expected.")
}

func (s *Suite) Test_ChecklinesPatch__no_newline(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("patch-aa",
		RcsId,
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

	t.CheckOutputEmpty()
}

func (s *Suite) Test_ChecklinesPatch__empty_lines_left_out_at_eof(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("patch-aa",
		RcsId,
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

	t.CheckOutputEmpty()
}

// In some context lines, the leading space character is missing.
// Since this is no problem for patch(1), pkglint also doesn't complain.
func (s *Suite) Test_ChecklinesPatch__context_lines_with_tab_instead_of_space(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("patch-aa",
		RcsId,
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

	t.CheckOutputEmpty()
}
