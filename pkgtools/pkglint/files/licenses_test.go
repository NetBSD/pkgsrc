package pkglint

import (
	"gopkg.in/check.v1"
)

func (s *Suite) Test_LicenseChecker_Check(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("licenses/gnu-gpl-v2",
		"The licenses for most software are designed to take away ...")

	test := func(licenseValue string, diagnostics ...string) {
		mklines := t.SetUpFileMkLines("Makefile",
			"LICENSE=\t"+licenseValue)

		mklines.ForEach(func(mkline *MkLine) {
			(&LicenseChecker{mklines, mkline}).Check(mkline.Value(), opAssign)
		})

		t.CheckOutput(diagnostics)
	}

	test("gpl-v2",
		"ERROR: ~/Makefile:1: License file licenses/gpl-v2 does not exist.")

	test("no-profit shareware",
		"ERROR: ~/Makefile:1: Parse error for license condition \"no-profit shareware\".")

	test("no-profit AND shareware",
		"ERROR: ~/Makefile:1: License file licenses/no-profit does not exist.",
		"ERROR: ~/Makefile:1: License file licenses/shareware does not exist.")

	test("gnu-gpl-v2",
		nil...)

	test("gnu-gpl-v2 AND gnu-gpl-v2 OR gnu-gpl-v2",
		"ERROR: ~/Makefile:1: AND and OR operators in license conditions "+
			"can only be combined using parentheses.")

	test("gnu-gpl-v2 AND (gnu-gpl-v2) OR gnu-gpl-v2",
		"ERROR: ~/Makefile:1: AND and OR operators in license conditions "+
			"can only be combined using parentheses.")

	test("(gnu-gpl-v2 OR gnu-gpl-v2) AND gnu-gpl-v2",
		nil...)

	test("gnu-gpl-v2 OR (gnu-gpl-v2 AND gnu-gpl-v2)",
		nil...)
}

func (s *Suite) Test_LicenseChecker_checkName__LICENSE_FILE(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.SetUpPackage("category/package",
		"LICENSE=\tmy-license",
		"",
		"LICENSE_FILE=\tmy-license")
	t.CreateFileLines("category/package/my-license",
		"An individual license file.")

	t.Main("category/package")

	// There is no warning about the unusual file name in the package directory.
	// If it were not mentioned in LICENSE_FILE, the file named my-license
	// would be warned about.
	t.CheckOutputLines(
		"Looks fine.")
}

func (s *Suite) Test_LicenseChecker_checkName__LICENSE_FILE_absolute(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.SetUpPackage("category/package",
		"LICENSE_FILE=\t/usr/license")

	t.Main("category/package")

	t.CheckOutputLines(
		"ERROR: ~/category/package/Makefile:20: LICENSE_FILE must not be an absolute path.",
		"1 error found.")
}
