package pkglint

import "gopkg.in/check.v1"

func (s *Suite) Test_CheckFileAlternatives__PLIST(c *check.C) {
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
		"ERROR: ALTERNATIVES:7: Alternative implementation \"@VARBASE@/game/scores\" "+
			"must appear in the PLIST as \"${VARBASE}/game/scores\".")

	t.SetUpCommandLine("--autofix")

	G.Check(".")

	t.CheckOutputLines(
		"AUTOFIX: ALTERNATIVES:3: Replacing \"bin/gnu-echo\" with \"@PREFIX@/bin/gnu-echo\".",
		"AUTOFIX: ALTERNATIVES:4: Replacing \"bin/vim\" with \"@PREFIX@/bin/vim\".")
}

func (s *Suite) Test_CheckFileAlternatives__empty(c *check.C) {
	t := s.Init(c)

	t.Chdir("category/package")
	t.CreateFileLines("ALTERNATIVES")

	G.Pkg = NewPackage(".")

	CheckFileAlternatives("ALTERNATIVES")

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

	t.CheckOutputEmpty()
}
