package main

import "gopkg.in/check.v1"

func (s *Suite) Test_CheckdirCategory_totally_broken(c *check.C) {
	t := s.Init(c)

	G.globalData.InitVartypes()
	t.SetupFileLines("archivers/Makefile",
		"# $",
		"SUBDIR+=pkg1",
		"SUBDIR+=\u0020aaaaa",
		"SUBDIR-=unknown #doesn\u2019t work",
		"",
		".include \"../mk/category.mk\"")
	G.CurrentDir = t.TempFilename("archivers")

	CheckdirCategory()

	t.CheckOutputLines(
		"ERROR: ~/archivers/Makefile:1: Expected \"# $"+"NetBSD$\".",
		"WARN: ~/archivers/Makefile:4: Line contains invalid characters (U+2019).",
		"WARN: ~/archivers/Makefile:4: SUBDIR- is defined but not used. Spelling mistake?",
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

func (s *Suite) Test_CheckdirCategory_invalid_comment(c *check.C) {
	t := s.Init(c)

	G.globalData.InitVartypes()
	t.SetupFileLines("archivers/Makefile",
		MkRcsId,
		"COMMENT=\t\\Make $$$$ fast\"",
		"",
		"SUBDIR+=\tpackage",
		"",
		".include \"../mk/misc/category.mk\"")
	t.SetupFileLines("archivers/package/Makefile",
		"# dummy")
	t.SetupFileLines("mk/misc/category.mk",
		"# dummy")
	G.CurrentDir = t.TempFilename("archivers")
	G.CurPkgsrcdir = ".."

	CheckdirCategory()

	t.CheckOutputLines(
		"WARN: ~/archivers/Makefile:2: COMMENT contains invalid characters (U+005C U+0024 U+0024 U+0024 U+0024 U+0022).")
}
