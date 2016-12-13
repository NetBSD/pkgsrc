package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) Test_CheckDirent_outside(c *check.C) {
	s.Init(c)
	s.CreateTmpFile("empty", "")

	CheckDirent(s.tmpdir)

	c.Check(s.Output(), equals, "ERROR: ~: Cannot determine the pkgsrc root directory for \"~\".\n")
}

func (s *Suite) Test_CheckDirent(c *check.C) {
	s.Init(c)
	s.CreateTmpFile("mk/bsd.pkg.mk", "")
	s.CreateTmpFile("category/package/Makefile", "")
	s.CreateTmpFile("category/Makefile", "")
	s.CreateTmpFile("Makefile", "")
	G.globalData.Pkgsrcdir = s.tmpdir

	CheckDirent(s.tmpdir)

	c.Check(s.Output(), equals, "ERROR: ~/Makefile: Must not be empty.\n")

	CheckDirent(s.tmpdir + "/category")

	c.Check(s.Output(), equals, "ERROR: ~/category/Makefile: Must not be empty.\n")

	CheckDirent(s.tmpdir + "/category/package")

	c.Check(s.Output(), equals, "ERROR: ~/category/package/Makefile: Must not be empty.\n")

	CheckDirent(s.tmpdir + "/category/package/nonexistent")

	c.Check(s.Output(), equals, "ERROR: ~/category/package/nonexistent: No such file or directory.\n")
}
