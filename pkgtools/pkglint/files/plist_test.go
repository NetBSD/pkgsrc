package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) TestChecklinesPlist(c *check.C) {
	lines := s.NewLines("PLIST",
		"bin/i386/6c",
		"bin/program",
		"@exec ${MKDIR} include/pkgbase",
		"${PLIST.man}man/cat3/strcpy.4",
		"${PLIST.obsolete}@unexec rmdir /tmp")

	checklinesPlist(lines)

	c.Check(s.Output(), equals, ""+
		"ERROR: PLIST:1: Expected \"@comment $NetBSD: plist_test.go,v 1.2 2015/12/02 21:46:46 rillig Exp $\".\n"+
		"WARN: PLIST:1: The bin/ directory should not have subdirectories.\n"+
		"WARN: PLIST:5: Please remove this line. It is no longer necessary.\n")
}
