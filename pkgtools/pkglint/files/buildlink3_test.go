package main

import "gopkg.in/check.v1"

func (s *Suite) Test_ChecklinesBuildlink3Mk(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	mklines := t.SetupFileMkLines("buildlink3.mk",
		MkRcsID,
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

	t.CheckOutputLines(
		"ERROR: ~/buildlink3.mk:12: \"x11/Xbae\" does not exist.",
		"ERROR: ~/buildlink3.mk:12: There is no package in \"x11/Xbae\".",
		"ERROR: ~/buildlink3.mk:14: \"mk/motif.buildlink3.mk\" does not exist.",
		"ERROR: ~/buildlink3.mk:2: This comment indicates unfinished work (url2pkg).")
}

// Before version 5.3, pkglint wrongly warned here.
// The mk/haskell.mk file takes care of constructing the correct PKGNAME,
// but pkglint had not looked at that file.
func (s *Suite) Test_ChecklinesBuildlink3Mk_name_mismatch(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	G.Pkg = NewPackage(t.File("x11/hs-X11"))
	G.Pkg.EffectivePkgbase = "X11"
	G.Pkg.EffectivePkgnameLine = t.NewMkLine("Makefile", 3, "DISTNAME=\tX11-1.0")
	mklines := t.NewMkLines("buildlink3.mk",
		MkRcsID,
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

	t.CheckOutputLines(
		"ERROR: buildlink3.mk:3: Package name mismatch between \"hs-X11\" in this file and \"X11\" from Makefile:3.")
}

func (s *Suite) Test_ChecklinesBuildlink3Mk_name_mismatch_multiple_inclusion(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	mklines := t.NewMkLines("buildlink3.mk",
		MkRcsID,
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

	t.CheckOutputLines(
		"ERROR: buildlink3.mk:5: Package name mismatch between multiple-inclusion guard \"PKGBASE2\" (expected \"PKGBASE1\") and package name \"pkgbase1\" (from line 3).",
		"WARN: buildlink3.mk:9: Definition of BUILDLINK_API_DEPENDS is missing.")
}

func (s *Suite) Test_ChecklinesBuildlink3Mk_name_mismatch_abi_api(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	mklines := t.NewMkLines("buildlink3.mk",
		MkRcsID,
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

	t.CheckOutputLines(
		"WARN: buildlink3.mk:9: Package name mismatch between ABI \"hs-X12\" and API \"hs-X11\" (from line 8).")
}

func (s *Suite) Test_ChecklinesBuildlink3Mk_abi_api_versions(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	mklines := t.NewMkLines("buildlink3.mk",
		MkRcsID,
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

	t.CheckOutputLines(
		"WARN: buildlink3.mk:9: ABI version \"1.6.0\" should be at least API version \"1.6.1\" (see line 8).")
}

func (s *Suite) Test_ChecklinesBuildlink3Mk_no_BUILDLINK_TREE_at_beginning(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	mklines := t.NewMkLines("buildlink3.mk",
		MkRcsID,
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

	t.CheckOutputLines(
		"WARN: buildlink3.mk:3: Expected a BUILDLINK_TREE line.")
}

func (s *Suite) Test_ChecklinesBuildlink3Mk_no_BUILDLINK_TREE_at_end(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	mklines := t.NewMkLines("buildlink3.mk",
		MkRcsID,
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

	t.CheckOutputLines(
		"WARN: buildlink3.mk:3: This line belongs inside the .ifdef block.",
		"WARN: buildlink3.mk:15: This line should contain the following text: BUILDLINK_TREE+=\t-hs-X11")
}

func (s *Suite) Test_ChecklinesBuildlink3Mk_multiple_inclusion_wrong(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	mklines := t.NewMkLines("buildlink3.mk",
		MkRcsID,
		"",
		"BUILDLINK_TREE+=\ths-X11",
		"",
		".if !defined(HS_X11_BUILDLINK3_MK)",
		"UNRELATED_BUILDLINK3_MK:=")

	ChecklinesBuildlink3Mk(mklines)

	t.CheckOutputLines(
		"WARN: buildlink3.mk:6: UNRELATED_BUILDLINK3_MK is defined but not used.",
		"WARN: buildlink3.mk:6: This line should contain the following text: HS_X11_BUILDLINK3_MK:=")
}

func (s *Suite) Test_ChecklinesBuildlink3Mk_missing_endif(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	mklines := t.NewMkLines("buildlink3.mk",
		MkRcsID,
		"",
		"BUILDLINK_TREE+=\tpkgbase1",
		"",
		".if !defined(PKGBASE1_BUILDLINK3_MK)",
		"PKGBASE1_BUILDLINK3_MK:=")

	ChecklinesBuildlink3Mk(mklines)

	t.CheckOutputLines(
		"WARN: buildlink3.mk:EOF: Expected \".endif\".")
}

func (s *Suite) Test_ChecklinesBuildlink3Mk_unknown_dependency_patterns(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	mklines := t.NewMkLines("buildlink3.mk",
		MkRcsID,
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

	t.CheckOutputLines(
		"WARN: buildlink3.mk:9: Unknown dependency pattern \"hs-X11!=1.6.1\".",
		"WARN: buildlink3.mk:10: Unknown dependency pattern \"hs-X11!=1.6.1.2nb2\".")
}

func (s *Suite) Test_ChecklinesBuildlink3Mk_PKGBASE_with_variable(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	mklines := t.NewMkLines("buildlink3.mk",
		MkRcsID,
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

	t.CheckOutputLines(
		"WARN: buildlink3.mk:3: Please use \"py\" instead of \"${PYPKGPREFIX}\" (also in other variables in this file).")
}

func (s *Suite) Test_ChecklinesBuildlink3Mk_PKGBASE_with_unknown_variable(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	mklines := t.NewMkLines("buildlink3.mk",
		MkRcsID,
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

	t.CheckOutputLines(
		"WARN: buildlink3.mk:3: Please replace \"${LICENSE}\" with a simple string (also in other variables in this file).",
		"WARN: buildlink3.mk:13: This line should contain the following text: BUILDLINK_TREE+=\t-${LICENSE}-wxWidgets")
}

// Those .include lines that are not indented at all may stay as-is.
// This special exception might have been for backwards-compatibility,
// but ideally should be handled like everywhere else.
// See MkLineChecker.checkInclude.
func (s *Suite) Test_ChecklinesBuildlink3Mk_indentation(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
	t.SetupVartypes()
	mklines := t.SetupFileMkLines("buildlink3.mk",
		MkRcsID,
		"",
		".if ${VAAPI_AVAILABLE} == \"yes\"",
		"",
		"BUILDLINK_TREE+=	libva",
		"",
		".  if !defined(LIBVA_BUILDLINK3_MK)",
		"LIBVA_BUILDLINK3_MK:=",
		"",
		"BUILDLINK_API_DEPENDS.libva+=	libva>=1.0.6",
		"BUILDLINK_PKGSRCDIR.libva?=	../../multimedia/libva",
		"",
		".include \"../../x11/libX11/buildlink3.mk\"",
		"",
		".  endif	# LIBVA_BUILDLINK3_MK",
		"",
		"BUILDLINK_TREE+=	-libva",
		"",
		".endif # VAAPI_AVAILABLE")

	ChecklinesBuildlink3Mk(mklines)

	// No warning about the indentation of the .include lines.
	t.CheckOutputLines(
		"ERROR: ~/buildlink3.mk:11: \"multimedia/libva\" does not exist.",
		"ERROR: ~/buildlink3.mk:11: There is no package in \"multimedia/libva\".",
		"ERROR: ~/buildlink3.mk:13: \"x11/libX11/buildlink3.mk\" does not exist.",
		"WARN: ~/buildlink3.mk:3: Expected a BUILDLINK_TREE line.")
}
