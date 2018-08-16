package main

import (
	"gopkg.in/check.v1"
)

func (s *Suite) Test_checklineLicense(c *check.C) {
	t := s.Init(c)

	t.SetupFileLines("licenses/gnu-gpl-v2",
		"Most software \u2026")
	mkline := t.NewMkLine("Makefile", 7, "LICENSE=dummy")

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

func (s *Suite) Test_checkToplevelUnusedLicenses(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()
	t.SetupFileLines("mk/misc/category.mk")
	t.SetupFileLines("licenses/2-clause-bsd")
	t.SetupFileLines("licenses/gnu-gpl-v3")

	t.SetupFileLines("Makefile",
		MkRcsID,
		"SUBDIR+=\tcategory")

	t.SetupFileLines("category/Makefile",
		MkRcsID,
		"COMMENT=\tExample category",
		"",
		"SUBDIR+=\tpackage",
		"",
		".include \"../mk/misc/category.mk\"")

	t.SetupFileLines("category/package/Makefile",
		MkRcsID,
		"CATEGORIES=\tcategory",
		"",
		"COMMENT=Example package",
		"LICENSE=\t2-clause-bsd",
		"NO_CHECKSUM=\tyes")
	t.SetupFileLines("category/package/PLIST",
		PlistRcsID,
		"bin/program")

	G.Main("pkglint", "-r", "-Cglobal", t.File("."))

	t.CheckOutputLines(
		"WARN: ~/licenses/gnu-gpl-v3: This license seems to be unused.",
		"0 errors and 1 warning found.")
}

func (s *Suite) Test_LicenseChecker_checkLicenseName__LICENSE_FILE(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()
	t.SetupCommandLine("-Wno-space")
	t.SetupFileLines("category/package/DESCR",
		"Package description")
	t.SetupFileMkLines("category/package/Makefile",
		MkRcsID,
		"",
		"CATEGORIES=     chinese",
		"",
		"COMMENT=        Useful tools",
		"LICENSE=        my-license",
		"",
		"LICENSE_FILE=   my-license",
		"NO_CHECKSUM=    yes",
		"",
		".include \"../../mk/bsd.pkg.mk\"")
	t.SetupFileLines("category/package/PLIST",
		PlistRcsID,
		"bin/program")
	t.SetupFileLines("category/package/my-license",
		"An individual license file.")

	G.Main("pkglint", t.File("category/package"))

	// FIXME: It should be allowed to place a license file directly into
	// the package directory.
	t.CheckOutputLines(
		"WARN: ~/category/package/my-license: Unexpected file found.", "0 errors and 1 warning found.")
}
