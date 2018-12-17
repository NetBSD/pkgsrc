package pkglint

import (
	"gopkg.in/check.v1"
)

func (s *Suite) Test_LicenseChecker_Check(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("licenses/gnu-gpl-v2",
		"The licenses for most software are designed to take away ...")
	mkline := t.NewMkLine("Makefile", 7, "LICENSE=dummy")

	licenseChecker := LicenseChecker{mkline}
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

func (s *Suite) Test_LicenseChecker_checkName__LICENSE_FILE(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()
	t.SetupPackage("category/package",
		"LICENSE=\tmy-license",
		"",
		"LICENSE_FILE=\tmy-license")
	t.CreateFileLines("category/package/my-license",
		"An individual license file.")

	G.Main("pkglint", t.File("category/package"))

	// FIXME: It should be allowed to place a license file directly into
	// the package directory.
	t.CheckOutputLines(
		"WARN: ~/category/package/my-license: Unexpected file found.",
		"0 errors and 1 warning found.")
}
