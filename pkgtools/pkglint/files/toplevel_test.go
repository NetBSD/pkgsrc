package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) TestCheckdirToplevel(c *check.C) {
	s.CreateTmpFile(c, "Makefile", ""+
		"# $"+"NetBSD$\n"+
		"\n"+
		"SUBDIR+= x11\n"+
		"SUBDIR+=\tarchivers\n"+
		"SUBDIR+=\tccc\n"+
		"SUBDIR+=\tccc\n"+
		"#SUBDIR+=\tignoreme\n"+
		"SUBDIR+=\tnonexisting\n"+ // This just doesn’t happen in practice.
		"SUBDIR+=\tbbb\n")
	s.CreateTmpFile(c, "archivers/Makefile", "")
	s.CreateTmpFile(c, "bbb/Makefile", "")
	s.CreateTmpFile(c, "ccc/Makefile", "")
	s.CreateTmpFile(c, "x11/Makefile", "")
	G.globalData.InitVartypes()

	G.CurrentDir = s.tmpdir
	CheckdirToplevel()

	c.Check(s.OutputCleanTmpdir(), equals, ""+
		"WARN: ~/Makefile:3: Indentation should be a single tab character.\n"+
		"ERROR: ~/Makefile:6: Each subdir must only appear once.\n"+
		"WARN: ~/Makefile:7: \"ignoreme\" commented out without giving a reason.\n"+
		"WARN: ~/Makefile:9: bbb should come before ccc\n")
}
