package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) Test_parseLicenses(c *check.C) {
	c.Check(parseLicenses("gnu-gpl-v2"), check.DeepEquals, &LicenseCondition{Name: "gnu-gpl-v2"})
	c.Check(parseLicenses("AND artistic"), check.IsNil)
}

func (s *Suite) Test_checklineLicense(c *check.C) {
	s.CreateTmpFile(c, "licenses/gnu-gpl-v2", "Most software \u2026")
	mkline := NewMkLine(NewLine("Makefile", 7, "LICENSE=dummy", nil))
	G.globalData.Pkgsrcdir = s.tmpdir
	G.CurrentDir = s.tmpdir

	licenseChecker := &LicenseChecker{mkline}
	licenseChecker.Check("gpl-v2", opAssign)

	c.Check(s.Output(), equals, "WARN: Makefile:7: License file ~/licenses/gpl-v2 does not exist.\n")

	licenseChecker.Check("no-profit shareware", opAssign)

	c.Check(s.Output(), equals, "ERROR: Makefile:7: Parse error for license condition \"no-profit shareware\".\n")

	licenseChecker.Check("no-profit AND shareware", opAssign)

	c.Check(s.Output(), equals, ""+
		"WARN: Makefile:7: License file ~/licenses/no-profit does not exist.\n"+
		"ERROR: Makefile:7: License \"no-profit\" must not be used.\n"+
		"WARN: Makefile:7: License file ~/licenses/shareware does not exist.\n"+
		"ERROR: Makefile:7: License \"shareware\" must not be used.\n")

	licenseChecker.Check("gnu-gpl-v2", opAssign)

	c.Check(s.Output(), equals, "")

	licenseChecker.Check("gnu-gpl-v2 AND gnu-gpl-v2 OR gnu-gpl-v2", opAssign)

	c.Check(s.Output(), equals, "ERROR: Makefile:7: AND and OR operators in license conditions can only be combined using parentheses.\n")

	licenseChecker.Check("(gnu-gpl-v2 OR gnu-gpl-v2) AND gnu-gpl-v2", opAssign)

	c.Check(s.Output(), equals, "")
}
