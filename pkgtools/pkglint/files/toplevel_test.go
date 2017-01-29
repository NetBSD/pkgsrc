package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) Test_CheckdirToplevel(c *check.C) {
	s.Init(c)
	s.CreateTmpFile("Makefile", ""+
		"# $"+"NetBSD$\n"+
		"\n"+
		"SUBDIR+= x11\n"+
		"SUBDIR+=\tarchivers\n"+
		"SUBDIR+=\tccc\n"+
		"SUBDIR+=\tccc\n"+
		"#SUBDIR+=\tignoreme\n"+
		"SUBDIR+=\tnonexisting\n"+ // This doesn't happen in practice, therefore no warning.
		"SUBDIR+=\tbbb\n")
	s.CreateTmpFile("archivers/Makefile", "")
	s.CreateTmpFile("bbb/Makefile", "")
	s.CreateTmpFile("ccc/Makefile", "")
	s.CreateTmpFile("x11/Makefile", "")
	G.globalData.InitVartypes()

	G.CurrentDir = s.tmpdir
	CheckdirToplevel()

	s.CheckOutputLines(
		"WARN: ~/Makefile:3: Indentation should be a single tab character.",
		"ERROR: ~/Makefile:6: Each subdir must only appear once.",
		"WARN: ~/Makefile:7: \"ignoreme\" commented out without giving a reason.",
		"WARN: ~/Makefile:9: bbb should come before ccc")
}
