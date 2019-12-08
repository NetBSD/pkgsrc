package pkglint

import "gopkg.in/check.v1"

func (s *Suite) Test_CheckdirCategory__totally_broken(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.CreateFileLines("archivers/Makefile",
		"# $",
		"SUBDIR+=pkg1",
		"SUBDIR+= aaaaa",
		"SUBDIR-=unknown #doesn\u2019t work",
		"",
		".include \"../mk/category.mk\"")

	CheckdirCategory(t.File("archivers"))

	t.CheckOutputLines(
		"ERROR: ~/archivers/Makefile:1: Expected \"# $"+"NetBSD$\".",
		"WARN: ~/archivers/Makefile:4: Line contains invalid characters (U+2019).",
		"WARN: ~/archivers/Makefile:4: SUBDIR- is defined but not used.",
		"NOTE: ~/archivers/Makefile:2: This variable value should be aligned to column 17.",
		"NOTE: ~/archivers/Makefile:3: This variable value should be aligned with tabs, not spaces, to column 17.",
		"NOTE: ~/archivers/Makefile:4: This variable value should be aligned to column 17.",
		"ERROR: ~/archivers/Makefile:6: Relative path \"../mk/category.mk\" does not exist.",
		"NOTE: ~/archivers/Makefile:1: Empty line expected after this line.",
		"ERROR: ~/archivers/Makefile:2: COMMENT= line expected.",
		"NOTE: ~/archivers/Makefile:1: Empty line expected after this line.", // XXX: Duplicate.
		"WARN: ~/archivers/Makefile:3: \"aaaaa\" should come before \"pkg1\".",
		"ERROR: ~/archivers/Makefile:4: SUBDIR+= line or empty line expected.",
		"ERROR: ~/archivers/Makefile:2: \"pkg1\" exists in the Makefile but not in the file system.",
		"ERROR: ~/archivers/Makefile:3: \"aaaaa\" exists in the Makefile but not in the file system.",
		"NOTE: ~/archivers/Makefile:3: Empty line expected after this line.",
		"WARN: ~/archivers/Makefile:4: This line should contain the following text: .include \"../mk/misc/category.mk\"",
		"ERROR: ~/archivers/Makefile:4: The file must end here.")
}

func (s *Suite) Test_CheckdirCategory__invalid_comment(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.CreateFileLines("archivers/Makefile",
		MkCvsID,
		"",
		"COMMENT=\t\\Make $$$$ fast\"",
		"",
		"SUBDIR+=\tpackage",
		"",
		".include \"../mk/misc/category.mk\"")
	t.CreateFileLines("archivers/package/Makefile",
		"# dummy")
	t.CreateFileLines("mk/misc/category.mk",
		"# dummy")

	CheckdirCategory(t.File("archivers"))

	t.CheckOutputLines(
		"WARN: ~/archivers/Makefile:3: COMMENT contains invalid characters (U+005C U+0024 U+0024 U+0024 U+0024 U+0022).")
}

// The pkgsrc-wip Makefile has a large section with special code below
// the SUBDIR list. This section is skipped by pkglint since it is assumed
// to work.
//
// In all other category files, pkglint checks that directly after the
// SUBDIR section there is only an empty line and the .include line.
func (s *Suite) Test_CheckdirCategory__wip(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/misc/category.mk")
	t.CreateFileLines("wip/package/Makefile")
	t.CreateFileLines("wip/Makefile",
		MkCvsID,
		"",
		"COMMENT=\tCategory comment",
		"",
		"SUBDIR+=\tpackage",
		"",
		"wip-specific-target: .PHONY",
		"\t${RUN}wip-specific-command",
		"",
		".include \"../mk/misc/category.mk\"")
	t.FinishSetUp()

	G.Check(t.File("wip"))

	t.CheckOutputLines(
		"WARN: ~/wip/Makefile:8: Unknown shell command \"wip-specific-command\".")
}

func (s *Suite) Test_CheckdirCategory__subdirs(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/misc/category.mk")
	t.CreateFileLines("category/in-wrong-order/Makefile")
	t.CreateFileLines("category/duplicate/Makefile")
	t.CreateFileLines("category/fs-only/Makefile")
	t.CreateFileLines("category/mk-and-fs/Makefile")
	t.CreateFileLines("category/commented-mk-and-fs/Makefile")
	t.CreateFileLines("category/commented-without-reason/Makefile")
	t.CreateFileLines("category/Makefile",
		MkCvsID,
		"",
		"COMMENT=\tCategory comment",
		"",
		"SUBDIR+=\tduplicate",
		"SUBDIR+=\tin-wrong-order",
		"SUBDIR+=\tduplicate",
		"SUBDIR+=\tmk-and-fs",
		"SUBDIR+=\tmk-only",
		"#SUBDIR+=\tcommented-mk-and-fs\t# Reason",
		"#SUBDIR+=\tcommented-mk-only\t# Reason",
		"#SUBDIR+=\tcommented-without-reason",
		"",
		".include \"../mk/misc/category.mk\"")
	t.FinishSetUp()

	CheckdirCategory(t.File("category"))

	t.CheckOutputLines(
		"ERROR: ~/category/Makefile:7: \"duplicate\" must only appear once, already seen in line 5.",
		"WARN: ~/category/Makefile:7: \"duplicate\" should come before \"in-wrong-order\".",
		"WARN: ~/category/Makefile:10: \"commented-mk-and-fs\" should come before \"mk-only\".",
		"WARN: ~/category/Makefile:12: \"commented-without-reason\" commented out without giving a reason.",
		"ERROR: ~/category/Makefile:6: \"fs-only\" exists in the file system but not in the Makefile.",
		"ERROR: ~/category/Makefile:9: \"mk-only\" exists in the Makefile but not in the file system.",
		"ERROR: ~/category/Makefile:11: \"commented-mk-only\" exists in the Makefile but not in the file system.")
}

func (s *Suite) Test_CheckdirCategory__only_in_Makefile(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/misc/category.mk")
	t.CreateFileLines("category/both/Makefile")
	t.CreateFileLines("category/Makefile",
		MkCvsID,
		"",
		"COMMENT=\tCategory comment",
		"",
		"SUBDIR+=\tabove-only-in-makefile",
		"SUBDIR+=\tboth",
		"SUBDIR+=\tonly-in-makefile",
		"",
		".include \"../mk/misc/category.mk\"")
	t.FinishSetUp()

	CheckdirCategory(t.File("category"))

	t.CheckOutputLines(
		"ERROR: ~/category/Makefile:5: \"above-only-in-makefile\" exists in the Makefile "+
			"but not in the file system.",
		"ERROR: ~/category/Makefile:7: \"only-in-makefile\" exists in the Makefile "+
			"but not in the file system.")
}

func (s *Suite) Test_CheckdirCategory__only_in_file_system(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/misc/category.mk")
	t.CreateFileLines("category/above-only-in-fs/Makefile")
	t.CreateFileLines("category/both/Makefile")
	t.CreateFileLines("category/only-in-fs/Makefile")
	t.CreateFileLines("category/Makefile",
		MkCvsID,
		"",
		"COMMENT=\tCategory comment",
		"",
		"SUBDIR+=\tboth",
		"",
		".include \"../mk/misc/category.mk\"")
	t.FinishSetUp()

	CheckdirCategory(t.File("category"))

	t.CheckOutputLines(
		"ERROR: ~/category/Makefile:5: \"above-only-in-fs\" exists in the file system "+
			"but not in the Makefile.",
		"ERROR: ~/category/Makefile:6: \"only-in-fs\" exists in the file system "+
			"but not in the Makefile.")
}

func (s *Suite) Test_CheckdirCategory__recursive(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-r")
	t.SetUpPkgsrc()
	t.CreateFileLines("mk/misc/category.mk")
	t.CreateFileLines("category/commented/Makefile")
	t.CreateFileLines("category/package/Makefile")
	t.CreateFileLines("category/Makefile",
		MkCvsID,
		"",
		"COMMENT=\tCategory comment",
		"",
		"#SUBDIR+=\tcommented\t# reason",
		"SUBDIR+=\tpackage",
		"",
		".include \"../mk/misc/category.mk\"")
	t.Chdir("category")
	t.FinishSetUp()

	// The default argument "." is added when parsing the command line.
	// It is only removed in Pkglint.Main, therefore it stays there even
	// after the call to CheckdirCategory. This is a bit unrealistic,
	// but close enough for this test.
	t.CheckDeepEquals(G.Todo.entries, []CurrPath{"."})

	CheckdirCategory(".")

	t.CheckOutputEmpty()
	t.CheckDeepEquals(G.Todo.entries, []CurrPath{"./package", "."})
}

// Ensures that a directory in the file system can be added at the very
// end of the SUBDIR list. This case takes a different code path than
// an addition in the middle.
//
// The warning appears in the empty line below the SUBDIR lines
// since the new SUBDIR would be inserted before that empty line.
// It would have also been possible to insert the new SUBDIR after
// the last SUBDIR line, but that would have been three more lines of code.
func (s *Suite) Test_CheckdirCategory__subdirs_file_system_at_the_bottom(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--show-autofix")
	t.SetUpPkgsrc()
	t.CreateFileLines("mk/misc/category.mk")
	t.CreateFileLines("category/mk-and-fs/Makefile")
	t.CreateFileLines("category/zzz-fs-only/Makefile")
	t.CreateFileLines("category/Makefile",
		MkCvsID,
		"",
		"COMMENT=\tCategory comment",
		"",
		"SUBDIR+=\tmk-and-fs",
		"",
		".include \"../mk/misc/category.mk\"")
	t.FinishSetUp()

	CheckdirCategory(t.File("category"))

	t.CheckOutputLines(
		"ERROR: ~/category/Makefile:6: \"zzz-fs-only\" exists in the file system but not in the Makefile.",
		"AUTOFIX: ~/category/Makefile:6: Inserting a line \"SUBDIR+=\\tzzz-fs-only\" before this line.")
}

func (s *Suite) Test_CheckdirCategory__indentation(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/misc/category.mk")
	t.CreateFileLines("category/package1/Makefile")
	t.CreateFileLines("category/package2/Makefile")
	t.CreateFileLines("category/Makefile",
		MkCvsID,
		"",
		"COMMENT=\tCategory comment",
		"",
		"SUBDIR+=                    package1",
		"SUBDIR+=\tpackage2",
		"",
		".include \"../mk/misc/category.mk\"")
	t.FinishSetUp()

	CheckdirCategory(t.File("category"))

	t.CheckOutputLines(
		"NOTE: ~/category/Makefile:5: This variable value should be aligned with tabs, not spaces, to column 17.")
}

func (s *Suite) Test_CheckdirCategory__comment_at_the_top(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/misc/category.mk")
	t.CreateFileLines("category/package/Makefile")
	t.CreateFileLines("category/Makefile",
		MkCvsID,
		"",
		"# This category collects all programs that don't fit anywhere else.",
		"",
		"COMMENT=\tCategory comment",
		"",
		"SUBDIR+=\tpackage",
		"",
		".include \"../mk/misc/category.mk\"")
	t.FinishSetUp()

	CheckdirCategory(t.File("category"))

	// These are quite a few warnings and errors, just because there is
	// an additional comment above the COMMENT definition.
	// On the other hand, the category Makefiles are so simple and their
	// structure has been fixed for at least 20 years, therefore this case
	// is rather exotic anyway.
	t.CheckOutputLines(
		"ERROR: ~/category/Makefile:3: COMMENT= line expected.",
		"NOTE: ~/category/Makefile:2: Empty line expected after this line.",
		"ERROR: ~/category/Makefile:3: SUBDIR+= line or empty line expected.",
		"ERROR: ~/category/Makefile:3: \"package\" exists in the file system but not in the Makefile.",
		"NOTE: ~/category/Makefile:2: Empty line expected after this line.",
		"WARN: ~/category/Makefile:3: This line should contain the following text: .include \"../mk/misc/category.mk\"",
		"ERROR: ~/category/Makefile:3: The file must end here.")
}

func (s *Suite) Test_CheckdirCategory__unexpected_EOF_while_reading_SUBDIR(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/misc/category.mk")
	t.CreateFileLines("category/package/Makefile")
	t.CreateFileLines("category/Makefile",
		MkCvsID,
		"",
		"COMMENT=\tCategory comment",
		"",
		"SUBDIR+=\tpackage")
	t.FinishSetUp()

	CheckdirCategory(t.File("category"))

	// Doesn't happen in practice since categories are created very seldom.
	t.CheckOutputLines(
		"NOTE: ~/category/Makefile:5: Empty line expected after this line.",
		"WARN: ~/category/Makefile:EOF: This line should contain the following text: "+
			".include \"../mk/misc/category.mk\"")
}

func (s *Suite) Test_CheckdirCategory__no_Makefile(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("category/other-file")
	t.FinishSetUp()

	G.Check(t.File("category"))

	t.CheckOutputLines(
		"ERROR: ~/category/Makefile: Cannot be read.")
}

func (s *Suite) Test_CheckdirCategory__case_mismatch(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/misc/category.mk")
	t.CreateFileLines("category/p5-Net-DNS/Makefile")
	t.CreateFileLines("category/Makefile",
		MkCvsID,
		"",
		"COMMENT=\tCategory comment",
		"",
		"SUBDIR+=\tp5-net-dns",
		"",
		".include \"../mk/misc/category.mk\"")
	t.FinishSetUp()

	G.Check(t.File("category"))

	t.CheckOutputLines(
		"ERROR: ~/category/Makefile:5: \"p5-Net-DNS\" "+
			"exists in the file system but not in the Makefile.",
		"ERROR: ~/category/Makefile:5: \"p5-net-dns\" "+
			"exists in the Makefile but not in the file system.")
}
