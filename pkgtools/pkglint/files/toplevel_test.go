package main

import "gopkg.in/check.v1"

func (s *Suite) Test_CheckdirToplevel(c *check.C) {
	t := s.Init(c)

	t.SetupFileLines("Makefile",
		MkRcsId,
		"",
		"SUBDIR+= x11",
		"SUBDIR+=\tarchivers",
		"SUBDIR+=\tccc",
		"SUBDIR+=\tccc",
		"#SUBDIR+=\tignoreme",
		"SUBDIR+=\tnonexisting", // This doesn't happen in practice, therefore no warning.
		"SUBDIR+=\tbbb")
	t.SetupFileLines("archivers/Makefile")
	t.SetupFileLines("bbb/Makefile")
	t.SetupFileLines("ccc/Makefile")
	t.SetupFileLines("x11/Makefile")
	G.globalData.InitVartypes()

	G.CurrentDir = t.TmpDir()
	CheckdirToplevel()

	t.CheckOutputLines(
		"WARN: ~/Makefile:3: Indentation should be a single tab character.",
		"ERROR: ~/Makefile:6: Each subdir must only appear once.",
		"WARN: ~/Makefile:7: \"ignoreme\" commented out without giving a reason.",
		"WARN: ~/Makefile:9: bbb should come before ccc")
}
