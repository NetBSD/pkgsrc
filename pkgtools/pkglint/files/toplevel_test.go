package main

import "gopkg.in/check.v1"

func (s *Suite) Test_CheckdirToplevel(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("Makefile",
		MkRcsID,
		"",
		"SUBDIR+= x11",
		"SUBDIR+=\tarchivers",
		"SUBDIR+=\tccc",
		"SUBDIR+=\tccc",
		"#SUBDIR+=\tignoreme",
		"SUBDIR+=\tnonexisting", // This doesn't happen in practice, therefore no warning.
		"SUBDIR+=\tbbb")
	t.CreateFileLines("archivers/Makefile")
	t.CreateFileLines("bbb/Makefile")
	t.CreateFileLines("ccc/Makefile")
	t.CreateFileLines("x11/Makefile")
	t.SetupVartypes()

	CheckdirToplevel(t.File("."))

	t.CheckOutputLines(
		"WARN: ~/Makefile:3: Indentation should be a single tab character.",
		"ERROR: ~/Makefile:6: Each subdir must only appear once.",
		"WARN: ~/Makefile:7: \"ignoreme\" commented out without giving a reason.",
		"WARN: ~/Makefile:9: bbb should come before ccc.")
}
