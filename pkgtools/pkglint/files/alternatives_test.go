package pkglint

import "gopkg.in/check.v1"

func (s *Suite) Test_CheckFileAlternatives__empty(c *check.C) {
	t := s.Init(c)

	t.Chdir("category/package")
	t.CreateFileLines("ALTERNATIVES")

	pkg := NewPackage(".")

	CheckFileAlternatives("ALTERNATIVES", pkg)

	t.CheckOutputLines(
		"ERROR: ALTERNATIVES: Must not be empty.")
}

func (s *Suite) Test_CheckFileAlternatives__ALTERNATIVES_SRC(c *check.C) {
	t := s.Init(c)

	// It's a strange situation, having an ALTERNATIVES file defined by
	// the package but then referring to another package's file by means
	// of ALTERNATIVES_SRC. As of February 2019 I don't remember if I
	// really had this case in mind when I initially wrote the code in
	// CheckFileAlternatives.
	t.SetUpPackage("category/package",
		"ALTERNATIVES_SRC=\talts")
	t.CreateFileLines("category/package/ALTERNATIVES",
		"bin/pgm @PREFIX@/bin/gnu-program",
		"bin/pgm @PREFIX@/bin/nb-program")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	// The ALTERNATIVES file in this package is not checked at all.
	// If it were, there would be an error for the repeated bin/pgm.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_AlternativesChecker_Check__PLIST(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.Chdir("category/package")
	t.CreateFileLines("ALTERNATIVES",
		"sbin/sendmail @PREFIX@/sbin/sendmail.postfix@POSTFIXVER@",
		"sbin/sendmail @PREFIX@/sbin/sendmail.exim@EXIMVER@",
		"bin/echo bin/gnu-echo",
		"bin/editor bin/vim -e",
		"invalid",
		"bin/browser\t${PREFIX}/bin/firefox",
		"highscores   @VARBASE@/game/scores",
		"sbin/init /sbin/init")
	t.CreateFileLines("PLIST",
		PlistCvsID,
		"bin/echo",
		"bin/vim",
		"sbin/sendmail.exim${EXIMVER}")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		"ERROR: ALTERNATIVES:1: Alternative implementation \"@PREFIX@/sbin/sendmail.postfix@POSTFIXVER@\" "+
			"must appear in the PLIST as \"sbin/sendmail.postfix${POSTFIXVER}\".",
		"ERROR: ALTERNATIVES:3: Alternative wrapper \"bin/echo\" must not appear in the PLIST.",
		"ERROR: ALTERNATIVES:3: Alternative implementation \"bin/gnu-echo\" must appear in the PLIST.",
		"ERROR: ALTERNATIVES:3: Alternative implementation \"bin/gnu-echo\" must be an absolute path.",
		"ERROR: ALTERNATIVES:4: Alternative implementation \"bin/vim\" must be an absolute path.",
		"ERROR: ALTERNATIVES:5: Invalid line \"invalid\".",
		"ERROR: ALTERNATIVES:6: Alternative implementation \"${PREFIX}/bin/firefox\" must appear in the PLIST.",
		"ERROR: ALTERNATIVES:6: Alternative implementation \"${PREFIX}/bin/firefox\" must be an absolute path.",
		"ERROR: ALTERNATIVES:7: Alternative wrapper \"highscores\" "+
			"must be in \"bin\" or \"sbin\".",
		"ERROR: ALTERNATIVES:7: Alternative implementation \"@VARBASE@/game/scores\" "+
			"must appear in the PLIST as \"${VARBASE}/game/scores\".")

	t.SetUpCommandLine("--autofix")

	G.Check(".")

	t.CheckOutputLines(
		"AUTOFIX: ALTERNATIVES:3: Replacing \"bin/gnu-echo\" with \"@PREFIX@/bin/gnu-echo\".",
		"AUTOFIX: ALTERNATIVES:4: Replacing \"bin/vim\" with \"@PREFIX@/bin/vim\".")
}

func (s *Suite) Test_AlternativesChecker_checkLine(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.Chdir("category/package")
	t.CreateFileLines("ALTERNATIVES",
		"bin/no-args @PREFIX@/bin/echo",
		"bin/with-args @PREFIX@/bin/echo hello,",
		"bin/with-quoted-args @PREFIX@/bin/echo \"hello, world\" \\ cowboy",
		"bin/trailing @PREFIX@/bin/echo spaces ",
		"/abs-echo @PREFIX@/bin/echo")
	t.CreateFileLines("PLIST",
		PlistCvsID,
		"bin/echo")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		"NOTE: ALTERNATIVES:4: Trailing whitespace.",
		"ERROR: ALTERNATIVES:5: Alternative wrapper \"/abs-echo\" "+
			"must be relative to PREFIX.")
}

func (s *Suite) Test_AlternativesChecker_checkLine__absolute(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("ALTERNATIVES",
		"relative @PREFIX@/bin/echo",
		"/absolute @PREFIX@/bin/echo")

	CheckFileAlternatives(t.File("ALTERNATIVES"), nil)

	t.CheckOutputLines(
		"ERROR: ~/ALTERNATIVES:1: Alternative wrapper \"relative\" "+
			"must be in \"bin\" or \"sbin\".",
		"ERROR: ~/ALTERNATIVES:2: Alternative wrapper \"/absolute\" "+
			"must be relative to PREFIX.")
}

func (s *Suite) Test_AlternativesChecker_checkLine__PLIST(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.Chdir("category/package")
	t.CreateFileLines("ALTERNATIVES",
		"bin/echo @PREFIX@/bin/gnu-echo",
		"bin/editor @PREFIX@/bin/vim -e")
	t.CreateFileLines("PLIST",
		PlistCvsID,
		"bin/echo",
		"bin/gnu-echo",
		"bin/vim")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		"ERROR: ALTERNATIVES:1: Alternative wrapper \"bin/echo\" " +
			"must not appear in the PLIST.")
}

func (s *Suite) Test_AlternativesChecker_checkLine__dir(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("ALTERNATIVES",
		"in/typo @PREFIX@/bin/typo",
		"sbin/daemon @PREFIX@/sbin/daemon-impl",
		"typo/program @PREFIX@/typo/program-impl",
		"man/man1/program.1 @PREFIX@/man/man1/program-impl.1")

	CheckFileAlternatives(t.File("ALTERNATIVES"), nil)

	t.CheckOutputLines(
		"ERROR: ~/ALTERNATIVES:1: Alternative wrapper \"in/typo\" "+
			"must be in \"bin\" or \"sbin\".",
		"ERROR: ~/ALTERNATIVES:3: Alternative wrapper \"typo/program\" "+
			"must be in \"bin\" or \"sbin\".",
		"ERROR: ~/ALTERNATIVES:4: Alternative wrapper \"man/man1/program.1\" "+
			"must be in \"bin\" or \"sbin\".")
}

func (s *Suite) Test_AlternativesChecker_checkAlternativeAbs(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.Chdir("category/package")
	t.CreateFileLines("ALTERNATIVES",
		"bin/echo bin/gnu-echo",
		"bin/editor bin/vim -e")
	t.CreateFileLines("PLIST",
		PlistCvsID,
		"bin/echo",
		"bin/gnu-echo",
		"bin/vim")
	t.FinishSetUp()

	t.CheckOutputEmpty()
}

// A file that is mentioned in the ALTERNATIVES file must appear
// in the package's PLIST files. It may appear there conditionally,
// assuming that manual testing will reveal inconsistencies. Or
// that this scenario is an edge case anyway.
func (s *Suite) Test_AlternativesChecker_checkAlternativePlist__conditional(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.Chdir("category/package")
	t.CreateFileLines("ALTERNATIVES",
		"bin/wrapper1 @PREFIX@/bin/always-exists",
		"bin/wrapper2 @PREFIX@/bin/conditional",
		"bin/wrapper3 @PREFIX@/bin/not-found")
	t.CreateFileLines("PLIST",
		PlistCvsID,
		"bin/always-exists",
		"${PLIST.cond}bin/conditional")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		"ERROR: ALTERNATIVES:3: Alternative implementation \"@PREFIX@/bin/not-found\" " +
			"must appear in the PLIST as \"bin/not-found\".")
}

// Manual pages must not be listed in the ALTERNATIVES file.
// Instead, they are handled automatically based on the program in bin/ or
// sbin/.
func (s *Suite) Test_AlternativesChecker_checkAlternativePlist__PKGMANDIR(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileLines("category/package/ALTERNATIVES",
		"@PKGMANDIR@/man1/blockdiag @PREFIX@/@PKGMANDIR@/man1/blockdiag-@PYVERSSUFFIX@.1")
	t.CreateFileLines("category/package/PLIST",
		PlistCvsID,
		"man/man1/blockdiag-${PYVERSSUFFIX}.1")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"ERROR: ~/category/package/ALTERNATIVES:1: "+
			"Alternative wrapper \"@PKGMANDIR@/man1/blockdiag\" "+
			"must be in \"bin\" or \"sbin\".",
		"ERROR: ~/category/package/ALTERNATIVES:1: "+
			"Alternative implementation "+
			"\"@PREFIX@/@PKGMANDIR@/man1/blockdiag-@PYVERSSUFFIX@.1\" "+
			"must appear in the PLIST as "+
			"\"${PKGMANDIR}/man1/blockdiag-${PYVERSSUFFIX}.1\".")
}
