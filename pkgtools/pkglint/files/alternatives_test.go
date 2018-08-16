package main

import "gopkg.in/check.v1"

func (s *Suite) Test_Alternatives_PLIST(c *check.C) {
	t := s.Init(c)

	t.Chdir("category/package")
	t.SetupFileLines("ALTERNATIVES",
		"sbin/sendmail @PREFIX@/sbin/sendmail.postfix@POSTFIXVER@",
		"sbin/sendmail @PREFIX@/sbin/sendmail.exim@EXIMVER@",
		"bin/echo bin/gnu-echo",
		"bin/editor bin/vim -e")

	G.Pkg = NewPackage(".")
	G.Pkg.PlistFiles["bin/echo"] = true
	G.Pkg.PlistFiles["bin/vim"] = true
	G.Pkg.PlistFiles["sbin/sendmail.exim${EXIMVER}"] = true

	CheckfileAlternatives("ALTERNATIVES", G.Pkg.PlistFiles)

	t.CheckOutputLines(
		"ERROR: ALTERNATIVES:1: Alternative implementation \"@PREFIX@/sbin/sendmail.postfix@POSTFIXVER@\" must appear in the PLIST as \"sbin/sendmail.postfix${POSTFIXVER}\".",
		"NOTE: ALTERNATIVES:1: @PREFIX@/ can be omitted from the file name.",
		"NOTE: ALTERNATIVES:2: @PREFIX@/ can be omitted from the file name.",
		"ERROR: ALTERNATIVES:3: Alternative wrapper \"bin/echo\" must not appear in the PLIST.",
		"ERROR: ALTERNATIVES:3: Alternative implementation \"bin/gnu-echo\" must appear in the PLIST.")
}
