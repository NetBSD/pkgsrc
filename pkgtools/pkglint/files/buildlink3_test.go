package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) TestChecklinesBuildlink3(c *check.C) {
	G.globalData.InitVartypes()
	lines := s.NewLines("buildlink3.mk",
		"# $"+"NetBSD$",
		"# XXX automatically generated",
		"",
		"BUILDLINK_TREE+=        Xbae",
		"",
		"BUILDLINK_DEPMETHOD.Xbae?=\tfull",
		".if !defined(XBAE_BUILDLINK3_MK)",
		"XBAE_BUILDLINK3_MK:=",
		"",
		"BUILDLINK_API_DEPENDS.Xbae+=    Xbae>=4.8.4",
		"BUILDLINK_ABI_DEPENDS.Xbae+=    Xbae>=4.51.01nb2",
		"BUILDLINK_PKGSRCDIR.Xbae?=      ../../x11/Xbae",
		"",
		".include \"../../mk/motif.buildlink3.mk\"",
		".endif # XBAE_BUILDLINK3_MK",
		"",
		"BUILDLINK_TREE+=        -Xbae")

	checklinesBuildlink3Mk(lines)

	c.Check(s.Output(), equals, ""+
		"ERROR: buildlink3.mk:14: \"/mk/motif.buildlink3.mk\" does not exist.\n"+
		"NOTE: buildlink3.mk:2: Please read this comment and remove it if appropriate.\n")
}

// The mismatch reported here is a false positive. The mk/haskell.mk file
// takes care of constructing the correct PKGNAME, but pkglint doesn’t
// look at that file.
func (s *Suite) TestChecklinesBuildlink3_NameMismatch(c *check.C) {
	s.UseCommandLine(c, "-Wall", "-Call")
	G.globalData.InitVartypes()
	G.pkgContext = newPkgContext("x11/hs-X11")
	G.pkgContext.effectivePkgbase = "X11"
	G.pkgContext.effectivePkgnameLine = NewLine("Makefile", "3", "DISTNAME=\tX11-1.0", nil)
	lines := s.NewLines("buildlink3.mk",
		"# $"+"NetBSD$",
		"",
		"BUILDLINK_TREE+=\ths-X11",
		"",
		".if !defined(HS_X11_BUILDLINK3_MK)",
		"HS_X11_BUILDLINK3_MK:=",
		"",
		"BUILDLINK_API_DEPENDS.hs-X11+=\ths-X11>=1.6.1",
		"BUILDLINK_ABI_DEPENDS.hs-X11+=\ths-X11>=1.6.1.2nb2",
		"",
		".endif\t# HS_X11_BUILDLINK3_MK",
		"",
		"BUILDLINK_TREE+=\t-hs-X11")

	checklinesBuildlink3Mk(lines)

	c.Check(s.Output(), equals, ""+
		"ERROR: buildlink3.mk:3: Package name mismatch between \"hs-X11\" ...\n"+
		"ERROR: Makefile:3: ... and \"X11\".\n")
}

func (s *Suite) TestChecklinesBuildlink3_NoBuildlinkTree(c *check.C) {
	s.UseCommandLine(c, "-Wall", "-Call")
	G.globalData.InitVartypes()
	lines := s.NewLines("buildlink3.mk",
		"# $"+"NetBSD$",
		"",
		"BUILDLINK_DEPMETHOD.hs-X11?=\tfull",
		"BUILDLINK_TREE+=\ths-X11",
		"",
		".if !defined(HS_X11_BUILDLINK3_MK)",
		"HS_X11_BUILDLINK3_MK:=",
		"",
		"BUILDLINK_API_DEPENDS.hs-X11+=\ths-X11>=1.6.1",
		"BUILDLINK_ABI_DEPENDS.hs-X11+=\ths-X11>=1.6.1.2nb2",
		"",
		".endif\t# HS_X11_BUILDLINK3_MK",
		"",
		"# needless comment",
		"BUILDLINK_TREE+=\t-hs-X11")

	checklinesBuildlink3Mk(lines)

	c.Check(s.Output(), equals, ""+
		"WARN: buildlink3.mk:3: This line belongs inside the .ifdef block.\n"+
		"WARN: buildlink3.mk:14: Expected BUILDLINK_TREE line.\n"+
		"WARN: buildlink3.mk:14: The file should end here.\n")
}
