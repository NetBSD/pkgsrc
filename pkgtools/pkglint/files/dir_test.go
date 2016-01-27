package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) TestCheckDirent_outside(c *check.C) {
	s.CreateTmpFile(c, "empty", "")

	CheckDirent(s.tmpdir)

	c.Check(s.Output(), equals, "ERROR: ~: Cannot determine the pkgsrc root directory for \"~\".\n")
}

func (s *Suite) TestCheckDirent(c *check.C) {
	s.CreateTmpFile(c, "mk/bsd.pkg.mk", "")
	s.CreateTmpFile(c, "category/package/Makefile", "")
	s.CreateTmpFile(c, "category/Makefile", "")
	s.CreateTmpFile(c, "Makefile", "")
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
