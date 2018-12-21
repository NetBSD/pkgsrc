package pkglint

import "gopkg.in/check.v1"

func (s *Suite) Test_CheckFileAlternatives__PLIST(c *check.C) {
	t := s.Init(c)

	t.SetupPackage("category/package")
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
		PlistRcsID,
		"bin/echo",
		"bin/vim",
		"sbin/sendmail.exim${EXIMVER}")

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

	t.SetupCommandLine("--autofix")

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
