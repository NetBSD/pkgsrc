package main

import "gopkg.in/check.v1"

func (s *Suite) Test_ChecklinesBuildlink3Mk__unfinished_url2pkg(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	t.CreateFileLines("x11/Xbae/Makefile")
	t.CreateFileLines("mk/motif.buildlink3.mk")
	mklines := t.SetupFileMkLines("buildlink3.mk",
		MkRcsID,
		"# XXX This file was created automatically using createbuildlink-@PKGVERSION@",
		"",
		"BUILDLINK_TREE+=\tXbae",
		"",
		"BUILDLINK_DEPMETHOD.Xbae?=\tfull",
		".if !defined(XBAE_BUILDLINK3_MK)",
		"XBAE_BUILDLINK3_MK:=",
		"",
		"BUILDLINK_API_DEPENDS.Xbae+=\tXbae>=4.8.4",
		"BUILDLINK_ABI_DEPENDS.Xbae+=\tXbae>=4.51.01nb2",
		"BUILDLINK_PKGSRCDIR.Xbae?=\t../../x11/Xbae",
		"",
		".include \"../../mk/motif.buildlink3.mk\"",
		".endif # XBAE_BUILDLINK3_MK",
		"",
		"BUILDLINK_TREE+=\t-Xbae")

	ChecklinesBuildlink3Mk(mklines)

	t.CheckOutputLines(
		"ERROR: ~/buildlink3.mk:2: This comment indicates unfinished work (url2pkg).")
}

// Before version 5.3, pkglint wrongly warned here.
// The mk/haskell.mk file takes care of constructing the correct PKGNAME,
// but pkglint had not looked at that file.
//
// Since then, pkglint also looks at files from mk/ when they are directly
// included, and therefore finds the default definition for PKGNAME.
func (s *Suite) Test_ChecklinesBuildlink3Mk__name_mismatch_Haskell_incomplete(c *check.C) {
	t := s.Init(c)

	t.SetupPackage("x11/hs-X11",
		"DISTNAME=\tX11-1.0")
	t.Chdir("x11/hs-X11")
	t.CreateFileLines("buildlink3.mk",
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

	G.CheckDirent(".")

	// This warning only occurs because pkglint cannot see mk/haskell.mk in this test.
	t.CheckOutputLines(
		"ERROR: buildlink3.mk:3: Package name mismatch between \"hs-X11\" in this file and \"X11\" from Makefile:3.")
}

// Before version 5.3, pkglint wrongly warned here.
// The mk/haskell.mk file takes care of constructing the correct PKGNAME,
// but pkglint had not looked at that file.
//
// Since then, pkglint also looks at files from mk/ when they are directly
// included, and therefore finds the default definition for PKGNAME.
func (s *Suite) Test_ChecklinesBuildlink3Mk__name_mismatch_Haskell_complete(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("mk/haskell.mk",
		MkRcsID,
		"PKGNAME?=\ths-${DISTNAME}")
	t.SetupPackage("x11/hs-X11",
		"DISTNAME=\tX11-1.0",
		"",
		".include \"../../mk/haskell.mk\"")
	t.Chdir("x11/hs-X11")
	t.CreateFileLines("buildlink3.mk",
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

	G.CheckDirent(".")

	t.CheckOutputEmpty()
}

func (s *Suite) Test_ChecklinesBuildlink3Mk__name_mismatch_multiple_inclusion(c *check.C) {
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

func (s *Suite) Test_ChecklinesBuildlink3Mk__name_mismatch_abi_api(c *check.C) {
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
		"BUILDLINK_ABI_DEPENDS.hs-X12+=\ths-X11>=1.6.1.2nb2",
		"",
		".endif\t# HS_X11_BUILDLINK3_MK",
		"",
		"BUILDLINK_TREE+=\t-hs-X11")

	ChecklinesBuildlink3Mk(mklines)

	t.CheckOutputLines(
		"WARN: buildlink3.mk:9: Package name mismatch between ABI \"hs-X12\" and API \"hs-X11\" (from line 8).",
		"WARN: buildlink3.mk:10: Only buildlink variables for \"hs-X11\", not \"hs-X12\" may be set in this file.")
}

func (s *Suite) Test_ChecklinesBuildlink3Mk__abi_api_versions(c *check.C) {
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

// As of October 2018, pkglint parses package dependencies a little
// different than the pkg_* tools.
// In all but two cases this works, this is one of the exceptions.
// The "{totem,totem-xine}" cannot be parsed, therefore the check skipped.
func (s *Suite) Test_Buildlink3Checker_checkVarassign__abi_api_versions_brace(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	t.CreateFileLines("multimedia/totem/Makefile")
	mklines := t.SetupFileMkLines("multimedia/totem/buildlink3.mk",
		MkRcsID,
		"",
		"BUILDLINK_TREE+=\ttotem",
		"",
		".if !defined(TOTEM_BUILDLINK3_MK)",
		"TOTEM_BUILDLINK3_MK:=",
		"",
		"BUILDLINK_API_DEPENDS.totem+=\t{totem,totem-xine}>=1.4.0",
		"BUILDLINK_ABI_DEPENDS.totem+=\ttotem>=2.32.0nb46",
		"BUILDLINK_PKGSRCDIR.totem?=\t../../multimedia/totem",
		"",
		".endif # TOTEM_BUILDLINK3_MK",
		"",
		"BUILDLINK_TREE+=\t-totem")

	ChecklinesBuildlink3Mk(mklines)

	// No warning about ABI "totem" and API "{totem,totem-xine}"
	// because that case is explicitly not checked.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_ChecklinesBuildlink3Mk__missing_BUILDLINK_TREE_at_beginning(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	mklines := t.NewMkLines("buildlink3.mk",
		MkRcsID,
		"",
		".if !defined(HS_X11_BUILDLINK3_MK)",
		"HS_X11_BUILDLINK3_MK:=",
		".endif")

	ChecklinesBuildlink3Mk(mklines)

	t.CheckOutputLines(
		"WARN: buildlink3.mk:3: Expected a BUILDLINK_TREE line.")
}

// In buildlink3.mk files, there is no need to place any comments
// in the autogenerated code, therefore this warning is justified.
func (s *Suite) Test_ChecklinesBuildlink3Mk__missing_BUILDLINK_TREE_at_end(c *check.C) {
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
		"BUILDLINK_ABI_DEPENDS.hs-X11+=\ths-X11>=1.6.1.2nb2",
		"",
		".endif\t# HS_X11_BUILDLINK3_MK",
		"",
		"# needless comment",
		"BUILDLINK_TREE+=\t-hs-X11")

	ChecklinesBuildlink3Mk(mklines)

	t.CheckOutputLines(
		"WARN: buildlink3.mk:13: This line should contain the following text: BUILDLINK_TREE+=\t-hs-X11")
}

func (s *Suite) Test_ChecklinesBuildlink3Mk__DEPMETHOD_placement(c *check.C) {
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
		"BUILDLINK_TREE+=\t-hs-X11")

	ChecklinesBuildlink3Mk(mklines)

	t.CheckOutputLines(
		"WARN: buildlink3.mk:3: This line belongs inside the .ifdef block.")
}

func (s *Suite) Test_ChecklinesBuildlink3Mk__multiple_inclusion_wrong(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	mklines := t.NewMkLines("buildlink3.mk",
		MkRcsID,
		"",
		"BUILDLINK_TREE+=\ths-X11",
		"",
		".if !defined(HS_X11_BUILDLINK3_MK)",
		"UNRELATED_BUILDLINK3_MK:=",
		".endif")

	ChecklinesBuildlink3Mk(mklines)

	t.CheckOutputLines(
		"WARN: buildlink3.mk:5: HS_X11_BUILDLINK3_MK is used but not defined.",
		"WARN: buildlink3.mk:6: UNRELATED_BUILDLINK3_MK is defined but not used.",
		"WARN: buildlink3.mk:6: This line should contain the following text: HS_X11_BUILDLINK3_MK:=")
}

func (s *Suite) Test_ChecklinesBuildlink3Mk__missing_endif(c *check.C) {
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
		"ERROR: buildlink3.mk:EOF: .if from line 5 must be closed.",
		"NOTE: buildlink3.mk:6: Empty line expected after this line.")
}

func (s *Suite) Test_ChecklinesBuildlink3Mk__invalid_dependency_patterns(c *check.C) {
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
		"BUILDLINK_DEPMETHOD.hs-X11?=\tfull",
		"BUILDLINK_API_DEPENDS.hs-X11+=\ths-X11!=1.6.1",
		"BUILDLINK_ABI_DEPENDS.hs-X11+=\ths-X11!=1.6.1.2nb2",
		"",
		".endif\t# HS_X11_BUILDLINK3_MK",
		"",
		"BUILDLINK_TREE+=\t-hs-X11")

	ChecklinesBuildlink3Mk(mklines)

	t.CheckOutputLines(
		"WARN: buildlink3.mk:9: Invalid dependency pattern \"hs-X11!=1.6.1\".",
		"WARN: buildlink3.mk:10: Invalid dependency pattern \"hs-X11!=1.6.1.2nb2\".")
}

func (s *Suite) Test_ChecklinesBuildlink3Mk__PKGBASE_with_variable(c *check.C) {
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

func (s *Suite) Test_ChecklinesBuildlink3Mk__PKGBASE_with_unknown_variable(c *check.C) {
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
		"BUILDLINK_API_DEPENDS.${LICENSE}-wxWidgets+=\t${LICENSE}-wxWidgets>=2.6.1.0",
		"BUILDLINK_ABI_DEPENDS.${LICENSE}-wxWidgets+=\t${LICENSE}-wxWidgets>=2.8.10.1nb26",
		"",
		".endif",
		"",
		"BUILDLINK_TREE+=\t-${LICENSE}-wxWidgets")

	ChecklinesBuildlink3Mk(mklines)

	t.CheckOutputLines(
		"WARN: buildlink3.mk:3: LICENSE may not be used in any file; it is a write-only variable.",
		// FIXME: License is not a list type, although it can be appended to.
		"WARN: buildlink3.mk:3: The list variable LICENSE should not be embedded in a word.",
		"WARN: buildlink3.mk:8: LICENSE should not be evaluated indirectly at load time.",
		"WARN: buildlink3.mk:8: LICENSE may not be used in any file; it is a write-only variable.",
		// FIXME: License is not a list type, although it can be appended to.
		"WARN: buildlink3.mk:8: The list variable LICENSE should not be embedded in a word.",
		"WARN: buildlink3.mk:9: LICENSE should not be evaluated indirectly at load time.",
		"WARN: buildlink3.mk:9: LICENSE may not be used in any file; it is a write-only variable.",
		// FIXME: License is not a list type, although it can be appended to.
		"WARN: buildlink3.mk:9: The list variable LICENSE should not be embedded in a word.",
		"WARN: buildlink3.mk:13: LICENSE may not be used in any file; it is a write-only variable.",
		// FIXME: License is not a list type, although it can be appended to.
		"WARN: buildlink3.mk:13: The list variable LICENSE should not be embedded in a word.",
		"WARN: buildlink3.mk:3: Please replace \"${LICENSE}\" with a simple string (also in other variables in this file).")
}

// Since the buildlink3 checker does not use MkLines.ForEach, it has to keep
// track of the nesting depth of .if directives.
func (s *Suite) Test_Buildlink3Checker_checkMainPart__nested_if(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	mklines := t.SetupFileMkLines("category/package/buildlink3.mk",
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
		".if ${OPSYS} == NetBSD",
		".endif",
		"",
		".endif\t# HS_X11_BUILDLINK3_MK",
		"",
		"BUILDLINK_TREE+=\t-hs-X11")

	ChecklinesBuildlink3Mk(mklines)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Buildlink3Checker_checkMainPart__comment_at_end_of_file(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()
	mklines := t.SetupFileMkLines("category/package/buildlink3.mk",
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
		"BUILDLINK_TREE+=\t-hs-X11",
		"",
		"# the end")

	ChecklinesBuildlink3Mk(mklines)

	t.CheckOutputLines(
		"WARN: ~/category/package/buildlink3.mk:14: The file should end here.")
}
