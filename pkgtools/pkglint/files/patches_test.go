package pkglint

import "gopkg.in/check.v1"

// This is how each patch should look like.
func (s *Suite) Test_CheckLinesPatch__with_comment(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("patch-WithComment",
		CvsID,
		"",
		"This part describes:",
		"* the purpose of the patch,",
		"* to which operating systems it applies",
		"* either why it is specific to pkgsrc",
		"* or where it has been reported upstream",
		"",
		"--- file.orig",
		"+++ file",
		"@@ -5,3 +5,3 @@",
		" context before",
		"-old line",
		"+new line",
		" context after")

	CheckLinesPatch(lines, nil)

	t.CheckOutputEmpty()
}

// To make the patch comment clearly visible, it should be surrounded by empty lines.
// The missing empty lines are inserted by pkglint.
func (s *Suite) Test_CheckLinesPatch__without_empty_line__autofix(c *check.C) {
	t := s.Init(c)

	t.Chdir("category/package")
	patchLines := t.SetUpFileLines("patch-WithoutEmptyLines",
		CvsID,
		"Text",
		"--- file.orig",
		"+++ file",
		"@@ -5,3 +5,3 @@",
		" context before",
		"-old line",
		"+new line",
		" context after")
	t.CreateFileLines("distinfo",
		CvsID,
		"",
		// The hash is taken from a breakpoint at the beginning of AutofixDistinfo, oldSha1
		"SHA1 (some patch) = 49abd735b7e706ea9ed6671628bb54e91f7f5ffb")

	t.SetUpCommandLine("-Wall", "--autofix")
	pkg := NewPackage(".")

	CheckLinesPatch(patchLines, pkg)

	t.CheckOutputLines(
		"AUTOFIX: patch-WithoutEmptyLines:2: Inserting a line \"\" before this line.",
		"AUTOFIX: patch-WithoutEmptyLines:3: Inserting a line \"\" before this line.",
		"AUTOFIX: distinfo:3: Replacing \"49abd735b7e706ea9ed6671628bb54e91f7f5ffb\" "+
			"with \"4938fc8c0b483dc2e33e741b0da883d199e78164\".")

	t.CheckFileLines("patch-WithoutEmptyLines",
		CvsID,
		"",
		"Text",
		"",
		"--- file.orig",
		"+++ file",
		"@@ -5,3 +5,3 @@",
		" context before",
		"-old line",
		"+new line",
		" context after")
	t.CheckFileLines("distinfo",
		CvsID,
		"",
		"SHA1 (some patch) = 4938fc8c0b483dc2e33e741b0da883d199e78164")
}

func (s *Suite) Test_CheckLinesPatch__no_comment_and_no_empty_lines(c *check.C) {
	t := s.Init(c)

	patchLines := t.SetUpFileLines("patch-WithoutEmptyLines",
		CvsID,
		"--- file.orig",
		"+++ file",
		"@@ -1,1 +1,1 @@",
		"-old line",
		"+new line")

	CheckLinesPatch(patchLines, nil)

	// These duplicate notes are actually correct. There should be an
	// empty line above the documentation and one below it. Since there
	// is no documentation yet, the line number for above and below is
	// the same. Outside of the testing environment, this duplicate
	// diagnostic is suppressed; see LogVerbose.
	t.CheckOutputLines(
		"NOTE: ~/patch-WithoutEmptyLines:2: Empty line expected before this line.",
		"ERROR: ~/patch-WithoutEmptyLines:2: Each patch must be documented.",
		"NOTE: ~/patch-WithoutEmptyLines:2: Empty line expected.")
}

func (s *Suite) Test_CheckLinesPatch__without_comment(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("patch-WithoutComment",
		CvsID,
		"",
		"--- file.orig",
		"+++ file",
		"@@ -5,3 +5,3 @@",
		" context before",
		"-old line",
		"+old line",
		" context after")

	CheckLinesPatch(lines, nil)

	t.CheckOutputLines(
		"ERROR: patch-WithoutComment:3: Each patch must be documented.")
}

// The output of BSD Make typically contains "*** Error code".
// In some really good patches, this output is included in the patch comment,
// to document why the patch is necessary.
func (s *Suite) Test_CheckLinesPatch__error_code(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("patch-ErrorCode",
		CvsID,
		"",
		"*** Error code 1", // Looks like a context diff but isn't.
		"",
		"--- file.orig",
		"+++ file",
		"@@ -5,3 +5,3 @@",
		" context before",
		"-old line",
		"+old line",
		" context after")

	CheckLinesPatch(lines, nil)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_CheckLinesPatch__wrong_header_order(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("patch-WrongOrder",
		CvsID,
		"",
		"Text",
		"Text",
		"",
		"+++ file",      // Wrong order
		"--- file.orig", // Wrong order
		"@@ -5,3 +5,3 @@",
		" context before",
		"-old line",
		"+old line",
		" context after")

	CheckLinesPatch(lines, nil)

	t.CheckOutputLines(
		"WARN: patch-WrongOrder:7: Unified diff headers should be first ---, then +++.")
}

// Context diffs are old and deprecated. Therefore pkglint doesn't check them thoroughly.
func (s *Suite) Test_CheckLinesPatch__context_diff(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("patch-ctx",
		CvsID,
		"",
		"diff -cr history.c.orig history.c",
		"*** history.c.orig",
		"--- history.c")

	CheckLinesPatch(lines, nil)

	t.CheckOutputLines(
		"ERROR: patch-ctx:4: Each patch must be documented.",
		"WARN: patch-ctx:4: Please use unified diffs (diff -u) for patches.")
}

func (s *Suite) Test_CheckLinesPatch__no_patch(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("patch-aa",
		CvsID,
		"",
		"-- oldfile",
		"++ newfile")

	CheckLinesPatch(lines, nil)

	t.CheckOutputLines(
		"ERROR: patch-aa: Contains no patch.")
}

func (s *Suite) Test_CheckLinesPatch__two_patched_files(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("patch-aa",
		CvsID,
		"",
		"A single patch file can apply to more than one file at a time.",
		"It shouldn't though, to keep the relation between patch files",
		"and patched files simple.",
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

	CheckLinesPatch(lines, nil)

	t.CheckOutputLines(
		"WARN: patch-aa: Contains patches for 2 files, should be only one.")
}

func (s *Suite) Test_CheckLinesPatch__two_patched_files_for_CVE(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("patch-CVE-2019-0001",
		CvsID,
		"",
		"Patches that are provided by upstream for a specific topic don't",
		"need to be split artificially.",
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

	CheckLinesPatch(lines, nil)

	t.CheckOutputEmpty()
}

// The patch headers are only recognized as such if they appear directly below each other.
func (s *Suite) Test_CheckLinesPatch__documentation_that_looks_like_patch_lines(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("patch-aa",
		CvsID,
		"",
		"--- oldfile",
		"",
		"+++ newfile",
		"",
		"*** oldOrNewFile")

	CheckLinesPatch(lines, nil)

	t.CheckOutputLines(
		"ERROR: patch-aa: Contains no patch.")
}

func (s *Suite) Test_CheckLinesPatch__only_unified_header_but_no_content(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("patch-unified",
		CvsID,
		"",
		"Documentation for the patch",
		"",
		"--- file.orig",
		"+++ file")

	CheckLinesPatch(lines, nil)

	t.CheckOutputLines(
		"ERROR: patch-unified:EOF: No patch hunks for \"file\".")
}

func (s *Suite) Test_CheckLinesPatch__only_context_header_but_no_content(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("patch-context",
		CvsID,
		"",
		"Documentation for the patch",
		"",
		"*** file.orig",
		"--- file")

	CheckLinesPatch(lines, nil)

	// Context diffs are deprecated, therefore it is not worth
	// adding extra code for checking them thoroughly.
	t.CheckOutputLines(
		"WARN: patch-context:5: Please use unified diffs (diff -u) for patches.")
}

func (s *Suite) Test_CheckLinesPatch__no_newline_with_text_following(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("patch-aa",
		CvsID,
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

	CheckLinesPatch(lines, nil)

	t.CheckOutputLines(
		"WARN: patch-aa:12: Empty line or end of file expected.")
}

func (s *Suite) Test_CheckLinesPatch__no_newline(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("patch-aa",
		CvsID,
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

	CheckLinesPatch(lines, nil)

	t.CheckOutputEmpty()
}

// Some patch files may end before reaching the expected line count (in this case 7 lines).
// This is ok if only context lines are missing. These context lines are assumed to be empty lines.
func (s *Suite) Test_CheckLinesPatch__empty_lines_left_out_at_eof(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("patch-aa",
		CvsID,
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

	CheckLinesPatch(lines, nil)

	t.CheckOutputEmpty()
}

// In some context lines, the leading space character may be missing.
// Since this is no problem for patch(1), pkglint also doesn't complain.
func (s *Suite) Test_CheckLinesPatch__context_lines_with_tab_instead_of_space(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("patch-aa",
		CvsID,
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

	CheckLinesPatch(lines, nil)

	t.CheckOutputEmpty()
}

// Before 2018-01-28, pkglint had panicked when checking an empty
// patch file, as a slice index was out of bounds.
func (s *Suite) Test_CheckLinesPatch__autofix_empty_patch(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--autofix")
	lines := t.NewLines("patch-aa",
		CvsID)

	CheckLinesPatch(lines, nil)

	t.CheckOutputEmpty()
}

// Before 2018-01-28, pkglint had panicked when checking an empty
// patch file, as a slice index was out of bounds.
func (s *Suite) Test_CheckLinesPatch__autofix_long_empty_patch(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--autofix")
	lines := t.SetUpFileLines("patch-aa",
		CvsID,
		"")

	CheckLinesPatch(lines, nil)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_CheckLinesPatch__crlf_autofix(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--autofix")
	lines := t.SetUpFileLines("patch-aa",
		CvsID,
		"",
		"Documentation",
		"",
		"--- oldfile",
		"+++ newfile",
		"@@ -1,1 +1,1 @@\r",
		"-old line",
		"+new line")

	CheckLinesPatch(lines, nil)

	// To relieve the pkgsrc package maintainers from this boring work,
	// the pkgsrc infrastructure could fix these issues before actually
	// applying the patches.
	t.CheckOutputLines(
		"AUTOFIX: ~/patch-aa:7: Replacing \"\\r\\n\" with \"\\n\".")
}

func (s *Suite) Test_CheckLinesPatch__autogenerated(c *check.C) {
	t := s.Init(c)

	lines := t.SetUpFileLines("patch-aa",
		CvsID,
		"",
		"Documentation",
		"",
		"--- configure.orig",
		"+++ configure",
		"@@ -1,1 +1,1 @@",
		"-old line",
		"+: Avoid regenerating within pkgsrc")

	CheckLinesPatch(lines, nil)

	t.CheckOutputLines(
		"ERROR: ~/patch-aa:9: This code must not be included in patches.")
}

func (s *Suite) Test_CheckLinesPatch__empty_context_lines_in_hunk(c *check.C) {
	t := s.Init(c)

	lines := t.SetUpFileLines("patch-aa",
		CvsID,
		"",
		"Documentation",
		"",
		"--- configure.orig",
		"+++ configure",
		"@@ -1,3 +1,3 @@",
		"",
		"-old line",
		"+new line")

	CheckLinesPatch(lines, nil)

	// The first context line should start with a single space character,
	// but that would mean trailing whitespace, so it may be left out.
	// The last context line is omitted completely because it would also
	// have trailing whitespace, and if that were removed, would be a
	// trailing empty line.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_CheckLinesPatch__invalid_line_in_hunk(c *check.C) {
	t := s.Init(c)

	lines := t.SetUpFileLines("patch-aa",
		CvsID,
		"",
		"Documentation",
		"",
		"--- configure.orig",
		"+++ configure",
		"@@ -1,3 +1,3 @@",
		"",
		"-old line",
		"<<<<<<<<",
		"+new line")

	CheckLinesPatch(lines, nil)

	t.CheckOutputLines(
		"ERROR: ~/patch-aa:10: Invalid line in unified patch hunk: <<<<<<<<")
}

func (s *Suite) Test_PatchChecker_Check__missing_CVS_Id(c *check.C) {
	t := s.Init(c)

	lines := t.SetUpFileLines("patch-aa",
		"This first line is missing the CVS Id",
		"",
		"Documentation")

	CheckLinesPatch(lines, nil)

	t.CheckOutputLines(
		sprintf("ERROR: ~/patch-aa:1: Expected %q.", CvsID),
		"NOTE: ~/patch-aa:1: Empty line expected before this line.",
		"ERROR: ~/patch-aa: Contains no patch.")
}

func (s *Suite) Test_PatchChecker_Check__add_file(c *check.C) {
	t := s.Init(c)

	lines := t.SetUpFileLines("patch-aa",
		CvsID,
		"",
		"This patch creates a new file.",
		"",
		"--- /dev/null",
		"+++ added-file",
		"@@ -0,0 +1,1 @@",
		"+ added line")

	CheckLinesPatch(lines, nil)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_PatchChecker_Check__delete_file(c *check.C) {
	t := s.Init(c)

	lines := t.SetUpFileLines("patch-aa",
		CvsID,
		"",
		"This patch deletes an existing file.",
		"",
		"--- deleted-file",
		"+++ /dev/null",
		"@@ -1,1 +0,0 @@",
		"- deleted line")

	CheckLinesPatch(lines, nil)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_PatchChecker_Check__absolute_path(c *check.C) {
	t := s.Init(c)

	lines := t.SetUpFileLines("patch-aa",
		CvsID,
		"",
		"This patch deletes an existing file.",
		"",
		"--- /absolute",
		"+++ /absolute",
		"@@ -1,1 +1,1 @@",
		"- deleted line",
		"+ added line")

	CheckLinesPatch(lines, nil)

	// XXX: Patches must not apply to absolute paths.
	// The only allowed exception is /dev/null.
	// ^(---|\+\+\+) /(?!dev/null)
	t.CheckOutputEmpty()
}

func (s *Suite) Test_PatchChecker_checkUnifiedDiff__lines_at_end(c *check.C) {
	t := s.Init(c)

	lines := t.SetUpFileLines("patch-aa",
		CvsID,
		"",
		"Documentation",
		"",
		"--- old",
		"+++ new",
		"@@ -1,1 +1,1 @@",
		"- old",
		"+ new",
		"",
		"This line is not part of the patch. Since it is separated from",
		"the patch by an empty line, there is no reason for a warning.")

	CheckLinesPatch(lines, nil)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_PatchChecker_checkBeginDiff__multiple_patches_without_documentation(c *check.C) {
	t := s.Init(c)

	lines := t.SetUpFileLines("patch-aa",
		CvsID,
		"",
		"--- old",
		"+++ new",
		"@@ -1,1 +1,1 @@",
		"- old",
		"+ new",
		"",
		"--- old",
		"+++ new",
		"@@ -1,1 +1,1 @@",
		"- old",
		"+ new")

	CheckLinesPatch(lines, nil)

	// The "must be documented" error message is only given before the first
	// patch since that's the only place where the documentation is expected.
	// Since each pkgsrc patch should only patch a single file, this situation
	// is an edge case anyway.
	t.CheckOutputLines(
		"ERROR: ~/patch-aa:3: Each patch must be documented.",
		"WARN: ~/patch-aa: Contains patches for 2 files, should be only one.")
}

func (s *Suite) Test_PatchChecker_checkConfigure__no_GNU(c *check.C) {
	t := s.Init(c)

	lines := t.SetUpFileLines("patch-aa",
		CvsID,
		"",
		"Documentation",
		"",
		"--- configure.sh.orig",
		"+++ configure.sh",
		"@@ -1,1 +1,1 @@",
		"-old line",
		"+: Avoid regenerating within pkgsrc")

	CheckLinesPatch(lines, nil)

	// No warning since configure.sh is probably not a GNU-style
	// configure file.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_PatchChecker_checkConfigure__GNU(c *check.C) {
	t := s.Init(c)

	lines := t.SetUpFileLines("patch-aa",
		CvsID,
		"",
		"Documentation",
		"",
		"--- configure.orig",
		"+++ configure",
		"@@ -1,1 +1,1 @@",
		"-old line",
		"+: Avoid regenerating within pkgsrc")

	CheckLinesPatch(lines, nil)

	t.CheckOutputLines(
		"ERROR: ~/patch-aa:9: This code must not be included in patches.")
}

// I'm not sure whether configure.in is really relevant for this check.
// As of December 2019, there is absolutely no package that uses
// CONFIGURE_SCRIPTS_OVERRIDE.
func (s *Suite) Test_PatchChecker_checkConfigure__configure_in(c *check.C) {
	t := s.Init(c)

	lines := t.SetUpFileLines("patch-aa",
		CvsID,
		"",
		"Documentation",
		"",
		"--- configure.in.orig",
		"+++ configure.in",
		"@@ -1,1 +1,1 @@",
		"-old line",
		"+: Avoid regenerating within pkgsrc")

	CheckLinesPatch(lines, nil)

	t.CheckOutputLines(
		"ERROR: ~/patch-aa:9: This code must not be included in patches.")
}

// I'm not sure whether configure.ac is really relevant for this check.
// As of December 2019, there is absolutely no package that uses
// CONFIGURE_SCRIPTS_OVERRIDE.
func (s *Suite) Test_PatchChecker_checkConfigure__configure_ac(c *check.C) {
	t := s.Init(c)

	lines := t.SetUpFileLines("patch-aa",
		CvsID,
		"",
		"Documentation",
		"",
		"--- configure.ac.orig",
		"+++ configure.ac",
		"@@ -1,1 +1,1 @@",
		"-old line",
		"+: Avoid regenerating within pkgsrc")

	CheckLinesPatch(lines, nil)

	t.CheckOutputLines(
		"ERROR: ~/patch-aa:9: This code must not be included in patches.")
}

func (s *Suite) Test_PatchChecker_checktextCvsID(c *check.C) {
	t := s.Init(c)

	lines := t.SetUpFileLines("patch-aa",
		CvsID,
		"",
		"Documentation",
		"",
		"--- configure.sh.orig",
		"+++ configure.sh",
		"@@ -1,3 +1,3 @@ $"+"Id$",
		" $"+"Id$",
		"-old line",
		"+new line $varname",
		" $"+"Author: authorship $")

	CheckLinesPatch(lines, nil)

	t.CheckOutputLines(
		"WARN: ~/patch-aa:7: Found CVS tag \"$"+"Id$\". Please remove it.",
		"WARN: ~/patch-aa:8: Found CVS tag \"$"+"Id$\". Please remove it by reducing the number of context lines using pkgdiff or \"diff -U[210]\".",
		"WARN: ~/patch-aa:11: Found CVS tag \"$"+"Author$\". Please remove it by reducing the number of context lines using pkgdiff or \"diff -U[210]\".")
}

// Autogenerated "comments" from Git or other tools don't count as real
// comments since they don't convey any intention of a human developer.
func (s *Suite) Test_PatchChecker_isEmptyLine(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("patch-aa",
		CvsID,
		"",
		"diff --git a/aa b/aa",
		"index 1234567..1234567 100644",
		"Index: from Subversion",
		"============= separator or conflict marker",
		"",
		"--- a/aa",
		"+++ b/aa",
		"@@ -1,1 +1,1 @@",
		"-old",
		"+new")

	CheckLinesPatch(lines, nil)

	t.CheckOutputLines(
		"ERROR: patch-aa:8: Each patch must be documented.")
}
