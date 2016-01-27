package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) TestChecklinesBuildlink3(c *check.C) {
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("buildlink3.mk",
		"# $"+"NetBSD$",
		"# XXX This file was created automatically using createbuildlink-@PKGVERSION@",
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

	ChecklinesBuildlink3Mk(mklines)

	c.Check(s.Output(), equals, ""+
		"ERROR: buildlink3.mk:12: \"/x11/Xbae\" does not exist.\n"+
		"ERROR: buildlink3.mk:12: There is no package in \"x11/Xbae\".\n"+
		"ERROR: buildlink3.mk:14: \"/mk/motif.buildlink3.mk\" does not exist.\n"+
		"ERROR: buildlink3.mk:2: This comment indicates unfinished work (url2pkg).\n")
}

// Before version 5.3, pkglint wrongly warned here.
// The mk/haskell.mk file takes care of constructing the correct PKGNAME,
// but pkglint had not looked at that file.
func (s *Suite) TestChecklinesBuildlink3_NameMismatch(c *check.C) {
	G.globalData.InitVartypes()
	G.Pkg = NewPackage("x11/hs-X11")
	G.Pkg.EffectivePkgbase = "X11"
	G.Pkg.EffectivePkgnameLine = NewMkLine(NewLine("Makefile", 3, "DISTNAME=\tX11-1.0", nil))
	mklines := s.NewMkLines("buildlink3.mk",
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

	ChecklinesBuildlink3Mk(mklines)

	c.Check(s.Output(), equals, "ERROR: buildlink3.mk:3: Package name mismatch between \"hs-X11\" in this file and \"X11\" from Makefile:3.\n")
}

func (s *Suite) TestChecklinesBuildlink3_NameMismatchMultipleInclusion(c *check.C) {
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("buildlink3.mk",
		"# $"+"NetBSD$",
		"",
		"BUILDLINK_TREE+=\tpkgbase1",
		"",
		".if !defined(PKGBASE2_BUILDLINK3_MK)",
		"PKGBASE2_BUILDLINK3_MK:=",
		"",
		".endif",
		"",
		"BUILDLINK_TREE+=\t-pkgbase1")

	ChecklinesBuildlink3Mk(mklines)

	c.Check(s.Output(), equals, ""+
		"ERROR: buildlink3.mk:5: Package name mismatch between multiple-inclusion guard \"PKGBASE2\" (expected \"PKGBASE1\") and package name \"pkgbase1\" (from line 3).\n"+
		"WARN: buildlink3.mk:9: Definition of BUILDLINK_API_DEPENDS is missing.\n")
}

func (s *Suite) TestChecklinesBuildlink3_NameMismatchAbiApi(c *check.C) {
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("buildlink3.mk",
		"# $"+"NetBSD$",
		"",
		"BUILDLINK_TREE+=\ths-X11",
		"",
		".if !defined(HS_X11_BUILDLINK3_MK)",
		"HS_X11_BUILDLINK3_MK:=",
		"",
		"BUILDLINK_API_DEPENDS.hs-X11+=\ths-X11>=1.6.1",
		"BUILDLINK_ABI_DEPENDS.hs-X11+=\ths-X12>=1.6.1.2nb2",
		"",
		".endif\t# HS_X11_BUILDLINK3_MK",
		"",
		"BUILDLINK_TREE+=\t-hs-X11")

	ChecklinesBuildlink3Mk(mklines)

	c.Check(s.Output(), equals, "WARN: buildlink3.mk:9: Package name mismatch between ABI \"hs-X12\" and API \"hs-X11\" (from line 8).\n")
}

func (s *Suite) TestChecklinesBuildlink3_AbiApiVersions(c *check.C) {
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("buildlink3.mk",
		"# $"+"NetBSD$",
		"",
		"BUILDLINK_TREE+=\ths-X11",
		"",
		".if !defined(HS_X11_BUILDLINK3_MK)",
		"HS_X11_BUILDLINK3_MK:=",
		"",
		"BUILDLINK_API_DEPENDS.hs-X11+=\ths-X11>=1.6.1",
		"BUILDLINK_ABI_DEPENDS.hs-X11+=\ths-X11>=1.6.0",
		"",
		".endif\t# HS_X11_BUILDLINK3_MK",
		"",
		"BUILDLINK_TREE+=\t-hs-X11")

	ChecklinesBuildlink3Mk(mklines)

	c.Check(s.Output(), equals, ""+
		"WARN: buildlink3.mk:9: ABI version \"1.6.0\" should be at least API version \"1.6.1\" (see line 8).\n")
}

func (s *Suite) TestChecklinesBuildlink3_NoBuildlinkTreeAtBeginning(c *check.C) {
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("buildlink3.mk",
		"# $"+"NetBSD$",
		"",
		".if !defined(HS_X11_BUILDLINK3_MK)",
		"HS_X11_BUILDLINK3_MK:=",
		"",
		"BUILDLINK_DEPMETHOD.hs-X11?=\tfull",
		"BUILDLINK_API_DEPENDS.hs-X11+=\ths-X11>=1.6.1",
		"BUILDLINK_ABI_DEPENDS.hs-X11+=\ths-X11>=1.6.1.2nb2",
		"",
		".endif\t# HS_X11_BUILDLINK3_MK",
		"",
		"BUILDLINK_TREE+=\t-hs-X11")

	ChecklinesBuildlink3Mk(mklines)

	c.Check(s.Output(), equals, "WARN: buildlink3.mk:3: Expected a BUILDLINK_TREE line.\n")
}

func (s *Suite) TestChecklinesBuildlink3_NoBuildlinkTreeAtEnd(c *check.C) {
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("buildlink3.mk",
		"# $"+"NetBSD$",
		"",
		"BUILDLINK_DEPMETHOD.hs-X11?=\tfull",
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
		"# needless comment",
		"BUILDLINK_TREE+=\t-hs-X11")

	ChecklinesBuildlink3Mk(mklines)

	c.Check(s.Output(), equals, ""+
		"WARN: buildlink3.mk:3: This line belongs inside the .ifdef block.\n"+
		"WARN: buildlink3.mk:15: This line should contain the following text: BUILDLINK_TREE+=\t-hs-X11\n")
}

func (s *Suite) TestChecklinesBuildlink3_MultipleInclusionWrong(c *check.C) {
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("buildlink3.mk",
		"# $"+"NetBSD$",
		"",
		"BUILDLINK_TREE+=\ths-X11",
		"",
		".if !defined(HS_X11_BUILDLINK3_MK)",
		"UNRELATED_BUILDLINK3_MK:=")

	ChecklinesBuildlink3Mk(mklines)

	c.Check(s.Output(), equals, ""+
		"WARN: buildlink3.mk:6: UNRELATED_BUILDLINK3_MK is defined but not used. Spelling mistake?\n"+
		"WARN: buildlink3.mk:6: This line should contain the following text: HS_X11_BUILDLINK3_MK:=\n")
}

func (s *Suite) TestChecklinesBuildlink3_EndIfMissing(c *check.C) {
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("buildlink3.mk",
		"# $"+"NetBSD$",
		"",
		"BUILDLINK_TREE+=\tpkgbase1",
		"",
		".if !defined(PKGBASE1_BUILDLINK3_MK)",
		"PKGBASE1_BUILDLINK3_MK:=")

	ChecklinesBuildlink3Mk(mklines)

	c.Check(s.Output(), equals, "WARN: buildlink3.mk:EOF: Expected .endif\n")
}

func (s *Suite) TestChecklinesBuildlink3_UnknownDependencyPatterns(c *check.C) {
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("buildlink3.mk",
		"# $"+"NetBSD$",
		"",
		"BUILDLINK_TREE+= hs-X11",
		"",
		".if !defined(HS_X11_BUILDLINK3_MK)",
		"HS_X11_BUILDLINK3_MK:=",
		"",
		"BUILDLINK_DEPMETHOD.hs-X11?=\tfull",
		"BUILDLINK_API_DEPENDS.hs-X11+=\ths-X11!=1.6.1",
		"BUILDLINK_ABI_DEPENDS.hs-X11+=\ths-X11!=1.6.1.2nb2",
		"",
		".endif\t# HS_X11_BUILDLINK3_MK",
		"",
		"BUILDLINK_TREE+=\t-hs-X11")

	ChecklinesBuildlink3Mk(mklines)

	c.Check(s.Output(), equals, ""+
		"WARN: buildlink3.mk:9: Unknown dependency pattern \"hs-X11!=1.6.1\".\n"+
		"WARN: buildlink3.mk:10: Unknown dependency pattern \"hs-X11!=1.6.1.2nb2\".\n")
}

func (s *Suite) TestChecklinesBuildlink3_PkgbaseWithVariable(c *check.C) {
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("buildlink3.mk",
		"# $"+"NetBSD$",
		"",
		"BUILDLINK_TREE+=\t${PYPKGPREFIX}-wxWidgets",
		"",
		".if !defined(PY_WXWIDGETS_BUILDLINK3_MK)",
		"PY_WXWIDGETS_BUILDLINK3_MK:=",
		"",
		"BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-wxWidgets+=\t${PYPKGPREFIX}-wxWidgets>=2.6.1.0",
		"BUILDLINK_ABI_DEPENDS.${PYPKGPREFIX}-wxWidgets+=\t${PYPKGPREFIX}-wxWidgets>=2.8.10.1nb26",
		"",
		".endif",
		"",
		"BUILDLINK_TREE+=\t-${PYPKGPREFIX}-wxWidgets")

	ChecklinesBuildlink3Mk(mklines)

	c.Check(s.Output(), equals, "WARN: buildlink3.mk:3: Please use \"py\" instead of \"${PYPKGPREFIX}\".\n")
}

func (s *Suite) TestChecklinesBuildlink3_PkgbaseWithUnknownVariable(c *check.C) {
	G.globalData.InitVartypes()
	mklines := s.NewMkLines("buildlink3.mk",
		"# $"+"NetBSD$",
		"",
		"BUILDLINK_TREE+=\t${LICENSE}-wxWidgets",
		"",
		".if !defined(LICENSE_BUILDLINK3_MK)",
		"LICENSE_BUILDLINK3_MK:=",
		"",
		"BUILDLINK_API_DEPENDS.${LICENSE}-wxWidgets+=\t${PYPKGPREFIX}-wxWidgets>=2.6.1.0",
		"BUILDLINK_ABI_DEPENDS.${LICENSE}-wxWidgets+=\t${PYPKGPREFIX}-wxWidgets>=2.8.10.1nb26",
		"",
		".endif",
		"",
		"BUILDLINK_TREE+=\t-${PYPKGPREFIX}-wxWidgets")

	ChecklinesBuildlink3Mk(mklines)

	c.Check(s.Output(), equals, ""+
		"WARN: buildlink3.mk:3: Please replace \"${LICENSE}\" with a simple string.\n"+
		"WARN: buildlink3.mk:13: This line should contain the following text: BUILDLINK_TREE+=\t-${LICENSE}-wxWidgets\n")
}
