package main

import "gopkg.in/check.v1"

func (s *Suite) Test_CheckdirCategory__totally_broken(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	t.CreateFileLines("archivers/Makefile",
		"# $",
		"SUBDIR+=pkg1",
		"SUBDIR+=\u0020aaaaa",
		"SUBDIR-=unknown #doesn\u2019t work",
		"",
		".include \"../mk/category.mk\"")

	CheckdirCategory(t.File("archivers"))

	t.CheckOutputLines(
		"ERROR: ~/archivers/Makefile:1: Expected \"# $"+"NetBSD$\".",
		"WARN: ~/archivers/Makefile:4: Line contains invalid characters (U+2019).",
		"WARN: ~/archivers/Makefile:4: SUBDIR- is defined but not used.",
		"ERROR: ~/archivers/Makefile:6: \"../mk/category.mk\" does not exist.",
		"ERROR: ~/archivers/Makefile:2: COMMENT= line expected.",
		"WARN: ~/archivers/Makefile:2: Indentation should be a single tab character.",
		"WARN: ~/archivers/Makefile:3: Indentation should be a single tab character.",
		"WARN: ~/archivers/Makefile:3: \"aaaaa\" should come before \"pkg1\".",
		"ERROR: ~/archivers/Makefile:4: SUBDIR+= line or empty line expected.",
		"ERROR: ~/archivers/Makefile:2: \"pkg1\" exists in the Makefile, but not in the file system.",
		"ERROR: ~/archivers/Makefile:3: \"aaaaa\" exists in the Makefile, but not in the file system.",
		"WARN: ~/archivers/Makefile:4: This line should contain the following text: .include \"../mk/misc/category.mk\"",
		"ERROR: ~/archivers/Makefile:4: The file should end here.")
}

func (s *Suite) Test_CheckdirCategory__invalid_comment(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	t.CreateFileLines("archivers/Makefile",
		MkRcsID,
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
		"WARN: ~/archivers/Makefile:2: COMMENT contains invalid characters (U+005C U+0024 U+0024 U+0024 U+0024 U+0022).")
}

func (s *Suite) Test_CheckdirCategory__wip(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()
	t.SetupVartypes()
	t.CreateFileLines("mk/misc/category.mk")
	t.CreateFileLines("wip/package/Makefile")
	t.CreateFileLines("wip/fs-only/Makefile")
	t.CreateFileLines("wip/Makefile",
		MkRcsID,
		"COMMENT=\tCategory comment",
		"",
		"SUBDIR+=\tmk-only",
		"#SUBDIR+=\tpackage",
		"SUBDIR+=\tpackage",
		"",
		"wip-specific-target: .PHONY",
		"\t${RUN}wip-specific-command",
		"",
		".include \"../mk/misc/category.mk\"")

	G.CheckDirent(t.File("wip"))

	t.CheckOutputLines(
		"WARN: ~/wip/Makefile:5: \"package\" commented out without giving a reason.",
		"ERROR: ~/wip/Makefile:6: \"package\" must only appear once.",
		"ERROR: ~/wip/Makefile:4: \"fs-only\" exists in the file system, but not in the Makefile.",
		"ERROR: ~/wip/Makefile:4: \"mk-only\" exists in the Makefile, but not in the file system.")
}
