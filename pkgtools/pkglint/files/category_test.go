package main

import "gopkg.in/check.v1"

func (s *Suite) Test_CheckdirCategory__totally_broken(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
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
		"ERROR: ~/archivers/Makefile:6: \"../mk/category.mk\" does not exist.",
		"NOTE: ~/archivers/Makefile:1: Empty line expected after this line.",
		"ERROR: ~/archivers/Makefile:2: COMMENT= line expected.",
		"NOTE: ~/archivers/Makefile:1: Empty line expected after this line.", // XXX: Duplicate.
		"WARN: ~/archivers/Makefile:3: \"aaaaa\" should come before \"pkg1\".",
		"ERROR: ~/archivers/Makefile:4: SUBDIR+= line or empty line expected.",
		"ERROR: ~/archivers/Makefile:2: \"pkg1\" exists in the Makefile but not in the file system.",
		"ERROR: ~/archivers/Makefile:3: \"aaaaa\" exists in the Makefile but not in the file system.",
		"NOTE: ~/archivers/Makefile:3: Empty line expected after this line.",
		"WARN: ~/archivers/Makefile:4: This line should contain the following text: .include \"../mk/misc/category.mk\"",
		"ERROR: ~/archivers/Makefile:4: The file should end here.")
}

func (s *Suite) Test_CheckdirCategory__invalid_comment(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	t.CreateFileLines("archivers/Makefile",
		MkRcsID,
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

	t.SetupPkgsrc()
	t.SetupVartypes()
	t.CreateFileLines("mk/misc/category.mk")
	t.CreateFileLines("wip/package/Makefile")
	t.CreateFileLines("wip/Makefile",
		MkRcsID,
		"",
		"COMMENT=\tCategory comment",
		"",
		"SUBDIR+=\tpackage",
		"",
		"wip-specific-target: .PHONY",
		"\t${RUN}wip-specific-command",
		"",
		".include \"../mk/misc/category.mk\"")

	G.CheckDirent(t.File("wip"))

	t.CheckOutputLines(
		"WARN: ~/wip/Makefile:8: Unknown shell command \"wip-specific-command\".")
}

func (s *Suite) Test_CheckdirCategory__subdirs(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()
	t.SetupVartypes()
	t.CreateFileLines("mk/misc/category.mk")
	t.CreateFileLines("category/in-wrong-order/Makefile")
	t.CreateFileLines("category/duplicate/Makefile")
	t.CreateFileLines("category/fs-only/Makefile")
	t.CreateFileLines("category/mk-and-fs/Makefile")
	t.CreateFileLines("category/commented-mk-and-fs/Makefile")
	t.CreateFileLines("category/commented-without-reason/Makefile")
	t.CreateFileLines("category/Makefile",
		MkRcsID,
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

	t.SetupCommandLine("-Wall", "--show-autofix")
	t.SetupPkgsrc()
	t.SetupVartypes()
	t.CreateFileLines("mk/misc/category.mk")
	t.CreateFileLines("category/mk-and-fs/Makefile")
	t.CreateFileLines("category/zzz-fs-only/Makefile")
	t.CreateFileLines("category/Makefile",
		MkRcsID,
		"",
		"COMMENT=\tCategory comment",
		"",
		"SUBDIR+=\tmk-and-fs",
		"",
		".include \"../mk/misc/category.mk\"")

	CheckdirCategory(t.File("category"))

	t.CheckOutputLines(
		"ERROR: ~/category/Makefile:6: \"zzz-fs-only\" exists in the file system but not in the Makefile.",
		"AUTOFIX: ~/category/Makefile:6: Inserting a line \"SUBDIR+=\\tzzz-fs-only\" before this line.")
}

func (s *Suite) Test_CheckdirCategory__indentation(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()
	t.SetupVartypes()
	t.CreateFileLines("mk/misc/category.mk")
	t.CreateFileLines("category/package1/Makefile")
	t.CreateFileLines("category/package2/Makefile")
	t.CreateFileLines("category/Makefile",
		MkRcsID,
		"",
		"COMMENT=\tCategory comment",
		"",
		"SUBDIR+=                    package1",
		"SUBDIR+=\tpackage2",
		"",
		".include \"../mk/misc/category.mk\"")

	CheckdirCategory(t.File("category"))

	t.CheckOutputLines(
		"NOTE: ~/category/Makefile:5: This variable value should be aligned with tabs, not spaces, to column 17.")
}
