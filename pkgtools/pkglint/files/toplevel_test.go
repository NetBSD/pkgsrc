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
		"WARN: ~/Makefile:9: bbb should come before ccc.",

		// This warning is at the very end because mklines.Check() is called at the end.
		// Ideally it would be at the same place as the other warning from Makefile:3.
		"NOTE: ~/Makefile:3: This variable value should be aligned with tabs, not spaces, to column 17.")
}
