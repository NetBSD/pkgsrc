package main

import "gopkg.in/check.v1"

func (s *Suite) Test_CheckfileAlternatives__PLIST(c *check.C) {
	t := s.Init(c)

	t.SetupPackage("category/package")
	t.Chdir("category/package")
	t.CreateFileLines("ALTERNATIVES",
		"sbin/sendmail @PREFIX@/sbin/sendmail.postfix@POSTFIXVER@",
		"sbin/sendmail @PREFIX@/sbin/sendmail.exim@EXIMVER@",
		"bin/echo bin/gnu-echo",
		"bin/editor bin/vim -e",
		"invalid")
	t.CreateFileLines("PLIST",
		PlistRcsID,
		"bin/echo",
		"bin/vim",
		"sbin/sendmail.exim${EXIMVER}")

	G.CheckDirent(".")

	t.CheckOutputLines(
		"ERROR: ALTERNATIVES:1: Alternative implementation \"@PREFIX@/sbin/sendmail.postfix@POSTFIXVER@\" must appear in the PLIST as \"sbin/sendmail.postfix${POSTFIXVER}\".",
		"NOTE: ALTERNATIVES:1: @PREFIX@/ can be omitted from the file name.",
		"NOTE: ALTERNATIVES:2: @PREFIX@/ can be omitted from the file name.",
		"ERROR: ALTERNATIVES:3: Alternative wrapper \"bin/echo\" must not appear in the PLIST.",
		"ERROR: ALTERNATIVES:3: Alternative implementation \"bin/gnu-echo\" must appear in the PLIST.",
		"ERROR: ALTERNATIVES:5: Invalid ALTERNATIVES line \"invalid\".")
}

func (s *Suite) Test_CheckfileAlternatives__empty(c *check.C) {
	t := s.Init(c)

	t.Chdir("category/package")
	t.CreateFileLines("ALTERNATIVES")

	G.Pkg = NewPackage(".")

	CheckfileAlternatives("ALTERNATIVES")

	t.CheckOutputLines(
		"ERROR: ALTERNATIVES: Must not be empty.")
}
