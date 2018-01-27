package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) Test_checklineLicense(c *check.C) {
	t := s.Init(c)

	t.SetupFileLines("licenses/gnu-gpl-v2",
		"Most software \u2026")
	mkline := t.NewMkLine("Makefile", 7, "LICENSE=dummy")
	G.globalData.Pkgsrcdir = t.TmpDir()
	G.CurrentDir = t.TmpDir()

	licenseChecker := &LicenseChecker{mkline}
	licenseChecker.Check("gpl-v2", opAssign)

	t.CheckOutputLines(
		"WARN: Makefile:7: License file ~/licenses/gpl-v2 does not exist.")

	licenseChecker.Check("no-profit shareware", opAssign)

	t.CheckOutputLines(
		"ERROR: Makefile:7: Parse error for license condition \"no-profit shareware\".")

	licenseChecker.Check("no-profit AND shareware", opAssign)

	t.CheckOutputLines(
		"WARN: Makefile:7: License file ~/licenses/no-profit does not exist.",
		"ERROR: Makefile:7: License \"no-profit\" must not be used.",
		"WARN: Makefile:7: License file ~/licenses/shareware does not exist.",
		"ERROR: Makefile:7: License \"shareware\" must not be used.")

	licenseChecker.Check("gnu-gpl-v2", opAssign)

	t.CheckOutputEmpty()

	licenseChecker.Check("gnu-gpl-v2 AND gnu-gpl-v2 OR gnu-gpl-v2", opAssign)

	t.CheckOutputLines(
		"ERROR: Makefile:7: AND and OR operators in license conditions can only be combined using parentheses.")

	licenseChecker.Check("(gnu-gpl-v2 OR gnu-gpl-v2) AND gnu-gpl-v2", opAssign)

	t.CheckOutputEmpty()
}
