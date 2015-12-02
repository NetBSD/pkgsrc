package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) TestPkgnameFromDistname(c *check.C) {
	G.pkgContext = newPkgContext("dummy")
	G.pkgContext.vardef["PKGNAME"] = NewLine("dummy", "dummy", "dummy", nil)

	c.Check(pkgnameFromDistname("pkgname-1.0", "whatever"), equals, "pkgname-1.0")
	c.Check(pkgnameFromDistname("${DISTNAME}", "distname-1.0"), equals, "distname-1.0")
	c.Check(pkgnameFromDistname("${DISTNAME:S/dist/pkg/}", "distname-1.0"), equals, "pkgname-1.0")
	c.Check(pkgnameFromDistname("${DISTNAME:S|a|b|g}", "panama-0.13"), equals, "pbnbmb-0.13")
	c.Check(pkgnameFromDistname("${DISTNAME:S|^lib||}", "libncurses"), equals, "ncurses")
	c.Check(pkgnameFromDistname("${DISTNAME:S|^lib||}", "mylib"), equals, "mylib")
}

func (s *Suite) TestChecklinesPackageMakefileVarorder(c *check.C) {
	s.UseCommandLine(c, "-Worder")
	G.pkgContext = newPkgContext("x11/9term")
	lines := s.NewLines("Makefile",
		"# $"+"NetBSD$",
		"",
		"DISTNAME=9term",
		"CATEGORIES=x11")

	ChecklinesPackageMakefileVarorder(lines)

	c.Check(s.Output(), equals, ""+
		"WARN: Makefile:3: CATEGORIES should be set here.\n"+
		"WARN: Makefile:3: COMMENT should be set here.\n"+
		"WARN: Makefile:3: LICENSE should be set here.\n")
}

func (s *Suite) TestGetNbpart(c *check.C) {
	G.pkgContext = newPkgContext("category/pkgbase")
	line := NewLine("Makefile", "1", "PKGREVISION=14", nil)
	parselineMk(line)
	G.pkgContext.vardef["PKGREVISION"] = line

	c.Check(getNbpart(), equals, "nb14")

	line = NewLine("Makefile", "1", "PKGREVISION=asdf", nil)
	parselineMk(line)
	G.pkgContext.vardef["PKGREVISION"] = line

	c.Check(getNbpart(), equals, "")
}
