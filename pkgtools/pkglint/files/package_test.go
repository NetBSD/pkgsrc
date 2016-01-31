package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) TestPkgnameFromDistname(c *check.C) {
	pkg := NewPackage("dummy")
	pkg.vardef["PKGNAME"] = NewMkLine(NewLine("Makefile", 5, "PKGNAME=dummy", nil))

	c.Check(pkg.pkgnameFromDistname("pkgname-1.0", "whatever"), equals, "pkgname-1.0")
	c.Check(pkg.pkgnameFromDistname("${DISTNAME}", "distname-1.0"), equals, "distname-1.0")
	c.Check(pkg.pkgnameFromDistname("${DISTNAME:S/dist/pkg/}", "distname-1.0"), equals, "pkgname-1.0")
	c.Check(pkg.pkgnameFromDistname("${DISTNAME:S|a|b|g}", "panama-0.13"), equals, "pbnbmb-0.13")
	c.Check(pkg.pkgnameFromDistname("${DISTNAME:S|^lib||}", "libncurses"), equals, "ncurses")
	c.Check(pkg.pkgnameFromDistname("${DISTNAME:S|^lib||}", "mylib"), equals, "mylib")

	c.Check(s.Output(), equals, "")
}

func (s *Suite) TestChecklinesPackageMakefileVarorder(c *check.C) {
	s.UseCommandLine(c, "-Worder")
	pkg := NewPackage("x11/9term")

	pkg.ChecklinesPackageMakefileVarorder(s.NewMkLines("Makefile",
		"# $"+"NetBSD$",
		"",
		"DISTNAME=9term",
		"CATEGORIES=x11"))

	c.Check(s.Output(), equals, "")

	pkg.ChecklinesPackageMakefileVarorder(s.NewMkLines("Makefile",
		"# $"+"NetBSD$",
		"",
		"DISTNAME=9term",
		"CATEGORIES=x11",
		"",
		".include \"../../mk/bsd.pkg.mk\""))

	c.Check(s.Output(), equals, ""+
		"WARN: Makefile:6: The canonical position for the required variable COMMENT is here.\n"+
		"WARN: Makefile:6: The canonical position for the required variable LICENSE is here.\n")
}

func (s *Suite) TestGetNbpart(c *check.C) {
	pkg := NewPackage("category/pkgbase")
	pkg.vardef["PKGREVISION"] = NewMkLine(NewLine("Makefile", 1, "PKGREVISION=14", nil))

	c.Check(pkg.getNbpart(), equals, "nb14")

	pkg.vardef["PKGREVISION"] = NewMkLine(NewLine("Makefile", 1, "PKGREVISION=asdf", nil))

	c.Check(pkg.getNbpart(), equals, "")
}

func (s *Suite) TestMkLines_CheckForUsedComment(c *check.C) {
	s.UseCommandLine(c, "--show-autofix")
	s.NewMkLines("Makefile.common",
		"# $"+"NetBSD$",
		"",
		"# used by sysutils/mc",
	).checkForUsedComment("sysutils/mc")

	c.Check(s.Output(), equals, "")

	s.NewMkLines("Makefile.common").checkForUsedComment("category/package")

	c.Check(s.Output(), equals, "")

	s.NewMkLines("Makefile.common",
		"# $"+"NetBSD$",
	).checkForUsedComment("category/package")

	c.Check(s.Output(), equals, "")

	s.NewMkLines("Makefile.common",
		"# $"+"NetBSD$",
		"",
	).checkForUsedComment("category/package")

	c.Check(s.Output(), equals, "")

	s.NewMkLines("Makefile.common",
		"# $"+"NetBSD$",
		"",
		"VARNAME=\tvalue",
	).checkForUsedComment("category/package")

	c.Check(s.Output(), equals, ""+
		"WARN: Makefile.common:2: Please add a line \"# used by category/package\" here.\n"+
		"AUTOFIX: Makefile.common:2: Inserting a line \"# used by category/package\" before this line.\n")

	s.NewMkLines("Makefile.common",
		"# $"+"NetBSD$",
		"#",
		"#",
	).checkForUsedComment("category/package")

	c.Check(s.Output(), equals, ""+
		"WARN: Makefile.common:3: Please add a line \"# used by category/package\" here.\n"+
		"AUTOFIX: Makefile.common:3: Inserting a line \"# used by category/package\" before this line.\n")
}

func (s *Suite) TestPackage_DetermineEffectivePkgVars_Precedence(c *check.C) {
	pkg := NewPackage("category/pkgbase")
	pkgnameLine := NewMkLine(NewLine("Makefile", 3, "PKGNAME=pkgname-1.0", nil))
	distnameLine := NewMkLine(NewLine("Makefile", 4, "DISTNAME=distname-1.0", nil))
	pkgrevisionLine := NewMkLine(NewLine("Makefile", 5, "PKGREVISION=13", nil))

	pkg.defineVar(pkgnameLine, pkgnameLine.Varname())
	pkg.defineVar(distnameLine, distnameLine.Varname())
	pkg.defineVar(pkgrevisionLine, pkgrevisionLine.Varname())

	pkg.determineEffectivePkgVars()

	c.Check(pkg.EffectivePkgbase, equals, "pkgname")
	c.Check(pkg.EffectivePkgname, equals, "pkgname-1.0nb13")
	c.Check(pkg.EffectivePkgversion, equals, "1.0")
}

func (s *Suite) TestPackage_CheckPossibleDowngrade(c *check.C) {
	G.Pkg = NewPackage("category/pkgbase")
	G.CurPkgsrcdir = "../.."
	G.Pkg.EffectivePkgname = "package-1.0nb15"
	G.Pkg.EffectivePkgnameLine = NewMkLine(NewLine("category/pkgbase/Makefile", 5, "PKGNAME=dummy", nil))
	G.globalData.LastChange = map[string]*Change{
		"category/pkgbase": &Change{
			Action:  "Updated",
			Version: "1.8",
			Line:    NewLine("doc/CHANGES", 116, "dummy", nil),
		},
	}

	G.Pkg.checkPossibleDowngrade()

	c.Check(s.Output(), equals, "WARN: category/pkgbase/Makefile:5: The package is being downgraded from 1.8 (see ../../doc/CHANGES:116) to 1.0nb15\n")

	G.globalData.LastChange["category/pkgbase"].Version = "1.0nb22"

	G.Pkg.checkPossibleDowngrade()

	c.Check(s.Output(), equals, "")
}
