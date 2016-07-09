package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) Test_parseLicenses(c *check.C) {
	c.Check(parseLicenses("gnu-gpl-v2"), check.DeepEquals, []string{"gnu-gpl-v2"})
	c.Check(parseLicenses("AND artistic"), check.DeepEquals, []string{"artistic"})
}

func (s *Suite) Test_checklineLicense(c *check.C) {
	s.CreateTmpFile(c, "licenses/gnu-gpl-v2", "Most software \u2026")
	mkline := NewMkLine(NewLine("Makefile", 7, "LICENSE=dummy", nil))
	G.globalData.Pkgsrcdir = s.tmpdir
	G.CurrentDir = s.tmpdir

	checklineLicense(mkline, "gpl-v2")

	c.Check(s.Output(), equals, "WARN: Makefile:7: License file ~/licenses/gpl-v2 does not exist.\n")

	checklineLicense(mkline, "no-profit shareware")

	c.Check(s.Output(), equals, ""+
		"WARN: Makefile:7: License file ~/licenses/no-profit does not exist.\n"+
		"WARN: Makefile:7: License \"no-profit\" is deprecated.\n"+
		"WARN: Makefile:7: License file ~/licenses/shareware does not exist.\n"+
		"WARN: Makefile:7: License \"shareware\" is deprecated.\n")

	checklineLicense(mkline, "gnu-gpl-v2")

	c.Check(s.Output(), equals, "")
}
