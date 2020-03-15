package pkglint

import "gopkg.in/check.v1"

func CheckLinesBuildlink3Mk(mklines *MkLines) {
	NewBuildlink3Checker(mklines).Check()
}

// This test ensures that CheckLinesBuildlink3Mk really checks for
// buildlink3.mk files that are included by the buildlink3.mk file
// but not by the package.
func (s *Suite) Test_CheckLinesBuildlink3Mk__package(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("category/dependency1/buildlink3.mk",
		MkCvsID)
	t.CreateFileLines("category/dependency2/buildlink3.mk",
		MkCvsID)
	t.SetUpPackage("category/package",
		".include \"../../category/dependency1/buildlink3.mk\"")

	t.CreateFileBuildlink3("category/package/buildlink3.mk",
		".include \"../../category/dependency2/buildlink3.mk\"")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"WARN: ~/category/package/buildlink3.mk:12: " +
			"../../category/dependency2/buildlink3.mk is included " +
			"by this file but not by the package.")
}

func (s *Suite) Test_CheckLinesBuildlink3Mk__unfinished_url2pkg(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.CreateFileLines("x11/Xbae/Makefile")
	t.CreateFileLines("mk/motif.buildlink3.mk")
	mklines := t.SetUpFileMkLines("category/package/buildlink3.mk",
		MkCvsID,
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

	CheckLinesBuildlink3Mk(mklines)

	t.CheckOutputLines(
		"ERROR: ~/category/package/buildlink3.mk:2: This comment indicates unfinished work (url2pkg).")
}

// Before version 5.3, pkglint wrongly warned here.
// The mk/haskell.mk file takes care of constructing the correct PKGNAME,
// but pkglint had not looked at that file.
//
// Since then, pkglint also looks at files from mk/ when they are directly
// included, and therefore finds the default definition for PKGNAME.
func (s *Suite) Test_CheckLinesBuildlink3Mk__name_mismatch_Haskell_incomplete(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("x11/hs-X11",
		"DISTNAME=\tX11-1.0")
	t.Chdir("x11/hs-X11")
	t.CreateFileLines("buildlink3.mk",
		MkCvsID,
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
	t.FinishSetUp()

	G.Check(".")

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
func (s *Suite) Test_CheckLinesBuildlink3Mk__name_mismatch_Haskell_complete(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("mk/haskell.mk",
		MkCvsID,
		"PKGNAME?=\ths-${DISTNAME}")
	t.SetUpPackage("x11/hs-X11",
		"DISTNAME=\tX11-1.0",
		"",
		".include \"../../mk/haskell.mk\"")
	t.Chdir("x11/hs-X11")
	t.CreateFileLines("buildlink3.mk",
		MkCvsID,
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
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputEmpty()
}

func (s *Suite) Test_CheckLinesBuildlink3Mk__name_mismatch__Perl(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("x11/p5-gtk2",
		"DISTNAME=\tGtk2-1.0",
		"PKGNAME=\t${DISTNAME:C:Gtk2:p5-gtk2:}")
	t.CreateFileLines("x11/p5-gtk2/buildlink3.mk",
		MkCvsID,
		"",
		"BUILDLINK_TREE+=\tp5-gtk2",
		"",
		".if !defined(P5_GTK2_BUILDLINK3_MK)",
		"P5_GTK2_BUILDLINK3_MK:=",
		"",
		"BUILDLINK_API_DEPENDS.p5-gtk2+=\tp5-gtk2>=1.0",
		"BUILDLINK_ABI_DEPENDS.p5-gtk2+=\tp5-gtk2>=1.0",
		"",
		".endif\t# P5_GTK2_BUILDLINK3_MK",
		"",
		"BUILDLINK_TREE+=\t-p5-gtk2")
	t.FinishSetUp()

	G.Check(t.File("x11/p5-gtk2"))

	// Up to 2019-03-17, pkglint wrongly complained about a mismatch
	// between the package name from buildlink3.mk (p5-gtk2) and the
	// one from the package Makefile (Gtk2).
	//
	// Pkglint had taken this information from the DISTNAME variable,
	// ignoring the fact that PKGNAME was also defined.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_CheckLinesBuildlink3Mk__name_mismatch__lib(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("converters/libiconv")
	t.CreateFileLines("converters/libiconv/buildlink3.mk",
		MkCvsID,
		"",
		"BUILDLINK_TREE+=\ticonv",
		"",
		".if !defined(ICONV_BUILDLINK3_MK)",
		"ICONV_BUILDLINK3_MK:=",
		"",
		"BUILDLINK_API_DEPENDS.iconv+=\tlibiconv>=1.0",
		"BUILDLINK_ABI_DEPENDS.iconv+=\tlibiconv>=1.0",
		"",
		".endif\t# ICONV_BUILDLINK3_MK",
		"",
		"BUILDLINK_TREE+=\t-iconv")
	t.FinishSetUp()

	G.Check(t.File("converters/libiconv"))

	// Up to 2019-10-12, pkglint complained about a mismatch
	// between the package name from buildlink3.mk (iconv) and the
	// one from the package Makefile (libiconv).
	//
	// This mismatch is not important enough to warrant a global
	// renaming of the buildlink3 identifier, therefore the warning
	// is suppressed in cases like this.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_CheckLinesBuildlink3Mk__name_mismatch__version_ok(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("editors/emacs22",
		"PKGNAME=\temacs22-22.0")
	t.CreateFileLines("editors/emacs22/buildlink3.mk",
		MkCvsID,
		"",
		"BUILDLINK_TREE+=\temacs",
		"",
		".if !defined(EMACS_BUILDLINK3_MK)",
		"EMACS_BUILDLINK3_MK:=",
		"",
		"BUILDLINK_API_DEPENDS.emacs+=\temacs22>=1.0",
		"BUILDLINK_ABI_DEPENDS.emacs+=\temacs22>=1.0",
		"",
		".endif\t# EMACS_BUILDLINK3_MK",
		"",
		"BUILDLINK_TREE+=\t-emacs")
	t.FinishSetUp()

	G.Check(t.File("editors/emacs22"))

	// Up to 2019-10-12, pkglint complained about a mismatch
	// between the package name from buildlink3.mk (emacs) and the
	// one from the package Makefile (emacs22).
	//
	// This mismatch is not important enough to warrant a global
	// renaming of the buildlink3 identifier, therefore the warning
	// is suppressed in cases like this.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_CheckLinesBuildlink3Mk__name_mismatch__version_bad(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("editors/emacs-client",
		"PKGNAME=\temacs-client-22.0")
	t.CreateFileLines("editors/emacs-client/buildlink3.mk",
		MkCvsID,
		"",
		"BUILDLINK_TREE+=\temacs",
		"",
		".if !defined(EMACS_BUILDLINK3_MK)",
		"EMACS_BUILDLINK3_MK:=",
		"",
		"BUILDLINK_API_DEPENDS.emacs+=\temacs-client>=1.0",
		"BUILDLINK_ABI_DEPENDS.emacs+=\temacs-client>=1.0",
		"",
		".endif\t# EMACS_BUILDLINK3_MK",
		"",
		"BUILDLINK_TREE+=\t-emacs")
	t.FinishSetUp()

	G.Check(t.File("editors/emacs-client"))

	t.CheckOutputLines(
		"ERROR: ~/editors/emacs-client/buildlink3.mk:3: " +
			"Package name mismatch between \"emacs\" in this file " +
			"and \"emacs-client\" from Makefile:4.")
}

func (s *Suite) Test_CheckLinesBuildlink3Mk__name_mismatch_multiple_inclusion(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("buildlink3.mk",
		MkCvsID,
		"",
		"BUILDLINK_TREE+=\tpkgbase1",
		"",
		".if !defined(PKGBASE2_BUILDLINK3_MK)",
		"PKGBASE2_BUILDLINK3_MK:=",
		"",
		".endif",
		"",
		"BUILDLINK_TREE+=\t-pkgbase1")

	CheckLinesBuildlink3Mk(mklines)

	t.CheckOutputLines(
		"ERROR: buildlink3.mk:5: Package name mismatch between multiple-inclusion guard \"PKGBASE2\" "+
			"(expected \"PKGBASE1\") and package name \"pkgbase1\" (from line 3).",
		"WARN: buildlink3.mk:9: Definition of BUILDLINK_API_DEPENDS is missing.")
}

func (s *Suite) Test_CheckLinesBuildlink3Mk__name_mismatch_abi_api(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("buildlink3.mk",
		MkCvsID,
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

	CheckLinesBuildlink3Mk(mklines)

	t.CheckOutputLines(
		"WARN: buildlink3.mk:9: Package name mismatch between ABI \"hs-X12\" and API \"hs-X11\" (from line 8).",
		"WARN: buildlink3.mk:10: Only buildlink variables for \"hs-X11\", not \"hs-X12\" may be set in this file.")
}

func (s *Suite) Test_CheckLinesBuildlink3Mk__abi_api_versions(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("buildlink3.mk",
		MkCvsID,
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

	CheckLinesBuildlink3Mk(mklines)

	t.CheckOutputLines(
		"WARN: buildlink3.mk:9: ABI version \"1.6.0\" should be at least API version \"1.6.1\" (see line 8).")
}

func (s *Suite) Test_CheckLinesBuildlink3Mk__missing_BUILDLINK_TREE_at_beginning(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("buildlink3.mk",
		MkCvsID,
		"",
		".if !defined(HS_X11_BUILDLINK3_MK)",
		"HS_X11_BUILDLINK3_MK:=",
		".endif")

	CheckLinesBuildlink3Mk(mklines)

	t.CheckOutputLines(
		"WARN: buildlink3.mk:3: Expected a BUILDLINK_TREE line.")
}

// In buildlink3.mk files, there is no need to place any comments
// in the autogenerated code, therefore this warning is justified.
func (s *Suite) Test_CheckLinesBuildlink3Mk__missing_BUILDLINK_TREE_at_end(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("buildlink3.mk",
		MkCvsID,
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

	CheckLinesBuildlink3Mk(mklines)

	t.CheckOutputLines(
		"WARN: buildlink3.mk:13: This line should contain the following text: BUILDLINK_TREE+=\t-hs-X11")
}

func (s *Suite) Test_CheckLinesBuildlink3Mk__DEPMETHOD_placement(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("buildlink3.mk",
		MkCvsID,
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

	CheckLinesBuildlink3Mk(mklines)

	t.CheckOutputLines(
		"WARN: buildlink3.mk:3: This line belongs inside the .ifdef block.")
}

func (s *Suite) Test_CheckLinesBuildlink3Mk__multiple_inclusion_wrong(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("buildlink3.mk",
		MkCvsID,
		"",
		"BUILDLINK_TREE+=\ths-X11",
		"",
		".if !defined(HS_X11_BUILDLINK3_MK)",
		"UNRELATED_BUILDLINK3_MK:=",
		".endif")

	CheckLinesBuildlink3Mk(mklines)

	t.CheckOutputLines(
		"WARN: buildlink3.mk:5: HS_X11_BUILDLINK3_MK is used but not defined.",
		"WARN: buildlink3.mk:6: UNRELATED_BUILDLINK3_MK is defined but not used.",
		"WARN: buildlink3.mk:6: This line should contain the following text: HS_X11_BUILDLINK3_MK:=")
}

func (s *Suite) Test_CheckLinesBuildlink3Mk__missing_endif(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("buildlink3.mk",
		MkCvsID,
		"",
		"BUILDLINK_TREE+=\tpkgbase1",
		"",
		".if !defined(PKGBASE1_BUILDLINK3_MK)",
		"PKGBASE1_BUILDLINK3_MK:=")

	CheckLinesBuildlink3Mk(mklines)

	t.CheckOutputLines(
		"ERROR: buildlink3.mk:EOF: .if from line 5 must be closed.",
		"NOTE: buildlink3.mk:6: Empty line expected below this line.")
}

func (s *Suite) Test_CheckLinesBuildlink3Mk__invalid_dependency_patterns(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("buildlink3.mk",
		MkCvsID,
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

	CheckLinesBuildlink3Mk(mklines)

	t.CheckOutputLines(
		"WARN: buildlink3.mk:9: Invalid dependency pattern \"hs-X11!=1.6.1\".",
		"WARN: buildlink3.mk:10: Invalid dependency pattern \"hs-X11!=1.6.1.2nb2\".")
}

func (s *Suite) Test_CheckLinesBuildlink3Mk__PKG_OPTIONS(c *check.C) {
	t := s.Init(c)

	t.SetUpOption("option", "")
	t.SetUpPkgsrc()
	t.SetUpPackage("category/package")
	t.CreateFileBuildlink3("category/package/buildlink3.mk",
		".include \"../../mk/bsd.fast.prefs.mk\"",
		".if ${PKG_OPTIONS:Moption}",
		".endif")
	t.FinishSetUp()

	G.Check(t.File("category/package/buildlink3.mk"))

	t.CheckOutputLines(
		"ERROR: ~/category/package/buildlink3.mk:13: " +
			"PKG_OPTIONS is not available in buildlink3.mk files.")
}

// Just for branch coverage.
func (s *Suite) Test_Buildlink3Checker_Check__no_tracing(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileBuildlink3("category/package/buildlink3.mk")
	t.DisableTracing()
	t.FinishSetUp()

	G.Check(t.File("category/package/buildlink3.mk"))

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Buildlink3Checker_checkUniquePkgbase(c *check.C) {
	t := s.Init(c)

	G.InterPackage.Enable()

	test := func(pkgbase string, pkgpath RelPath, diagnostics ...string) {
		mkline := t.NewMkLine(t.File(pkgpath+"/buildlink3.mk"), 123, "")

		(*Buildlink3Checker).checkUniquePkgbase(nil, pkgbase, mkline)

		t.CheckOutput(diagnostics)
	}

	// From now on, the pkgbase "php" may only be used for "php\d+".
	test("php", "lang/php56",
		nil...)

	// No warning since "php" is a valid buildlink3 basename for "php72".
	test("php", "lang/php72",
		nil...)

	// But this is a clear typo.
	test("php", "security/pgp",
		"ERROR: ~/security/pgp/buildlink3.mk:123: "+
			"Duplicate package identifier \"php\" already appeared "+
			"in ../../lang/php56/buildlink3.mk:123.")

	// This combination is not allowed because the names "php" and "php-pcre"
	// differ too much. The only allowed inexact match is that the pkgname
	// has one more number than the pkgbase, no matter at which position.
	test("php", "textproc/php-pcre",
		"ERROR: ~/textproc/php-pcre/buildlink3.mk:123: "+
			"Duplicate package identifier \"php\" already appeared "+
			"in ../../lang/php56/buildlink3.mk:123.")

	test("ruby-module", "net/ruby24-module",
		nil...)

	test("ruby-module", "net/ruby26-module",
		nil...)

	test("ruby-module", "net/ruby26-module12",
		"ERROR: ~/net/ruby26-module12/buildlink3.mk:123: "+
			"Duplicate package identifier \"ruby-module\" already appeared "+
			"in ../../net/ruby24-module/buildlink3.mk:123.")

	test("package", "devel/package",
		nil...)

	test("package", "wip/package",
		nil...)
}

func (s *Suite) Test_Buildlink3Checker_checkUniquePkgbase__chdir(c *check.C) {
	t := s.Init(c)

	G.InterPackage.Enable()
	t.Chdir("lang/php56")

	test := func(pkgbase string, path CurrPath, diagnostics ...string) {
		mkline := t.NewMkLine(path.JoinNoClean("buildlink3.mk"), 123, "")

		(*Buildlink3Checker).checkUniquePkgbase(nil, pkgbase, mkline)

		t.CheckOutput(diagnostics)
	}

	test("php", "../../lang/php72",
		nil...)

	// Using the identifier "php" is ok in the current directory since
	// its relative path from the pkgsrc root is "lang/php56", which
	// starts with "php" as well.
	test("php", ".",
		nil...)
}

func (s *Suite) Test_Buildlink3Checker_checkSecondParagraph__missing_mkbase(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"DISTNAME=\t# empty",
		"PKGNAME=\t# empty, to force mkbase to be empty")
	t.CreateFileBuildlink3("category/package/buildlink3.mk")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	// There is no warning from buildlink3.mk about mismatched package names
	// since that is only a follow-up error of being unable to parse the pkgbase.
	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:3: As DISTNAME is not a valid package name, "+
			"please define the PKGNAME explicitly.",
		"WARN: ~/category/package/Makefile:4: \"\" is not a valid package name.")
}

func (s *Suite) Test_Buildlink3Checker_checkMainPart__if_else_endif(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileBuildlink3("category/package/buildlink3.mk",
		".include \"../../mk/bsd.fast.prefs.mk\"",
		"",
		".if ${X11_TYPE} == modular",
		".else",
		".endif")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputEmpty()
}

// The buildlink3 checker does not use MkLines.ForEach since that would make
// the code more difficult to understand. Without MkLines.ForEach, it has to
// keep track of the nesting depth of .if directives itself.
func (s *Suite) Test_Buildlink3Checker_checkMainPart__nested_if(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.Chdir("category/package")
	t.FinishSetUp()
	mklines := t.SetUpFileMkLines("buildlink3.mk",
		MkCvsID,
		"",
		"BUILDLINK_TREE+=\ths-X11",
		"",
		".if !defined(HS_X11_BUILDLINK3_MK)",
		"HS_X11_BUILDLINK3_MK:=",
		"",
		"BUILDLINK_API_DEPENDS.hs-X11+=\ths-X11>=1.6.1",
		"BUILDLINK_ABI_DEPENDS.hs-X11+=\ths-X11>=1.6.1.2nb2",
		"",
		".include \"../../mk/bsd.fast.prefs.mk\"",
		"",
		".if ${OPSYS} == NetBSD",
		".endif",
		"",
		".endif\t# HS_X11_BUILDLINK3_MK",
		"",
		"BUILDLINK_TREE+=\t-hs-X11")

	CheckLinesBuildlink3Mk(mklines)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Buildlink3Checker_checkMainPart__comment_at_end_of_file(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.SetUpFileMkLines("category/package/buildlink3.mk",
		MkCvsID,
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

	CheckLinesBuildlink3Mk(mklines)

	t.CheckOutputLines(
		"WARN: ~/category/package/buildlink3.mk:14: The file should end here.")
}

func (s *Suite) Test_Buildlink3Checker_checkVarUse__PKG_BUILD_OPTIONS(c *check.C) {
	t := s.Init(c)

	t.SetUpOption("option", "")
	t.SetUpPkgsrc()
	t.CreateFileLines("mk/pkg-build-options.mk")
	t.SetUpPackage("category/package")
	t.CreateFileBuildlink3("category/package/buildlink3.mk",
		"pkgbase := unrelated",
		".include \"../../mk/pkg-build-options.mk\"",
		"",
		".if ${PKG_BUILD_OPTIONS:Moption}", // missing variable parameter
		".endif",
		"",
		".if ${PKG_BUILD_OPTIONS.package:Moption}", // wrong variable parameter
		".endif",
		"",
		".if ${PKG_BUILD_OPTIONS.unrelated:Moption}", // corresponds to pkgbase above
		".endif")
	t.FinishSetUp()

	G.Check(t.File("category/package/buildlink3.mk"))

	// TODO: Warn about PKG_BUILD_OPTIONS.package since that variable is not defined.
	t.CheckOutputLines(
		"WARN: ~/category/package/buildlink3.mk:15: "+
			"PKG_BUILD_OPTIONS is used but not defined.",
		"WARN: ~/category/package/buildlink3.mk:21: "+
			"Wrong PKG_BUILD_OPTIONS, expected \"package\" instead of \"unrelated\".")
}

// As of October 2018, pkglint parses package dependencies a little
// different than the pkg_* tools.
// In all but two cases this works, this is one of the exceptions.
// The "{totem,totem-xine}" cannot be parsed, therefore the check skipped.
func (s *Suite) Test_Buildlink3Checker_checkVarassign__abi_api_versions_brace(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.CreateFileLines("multimedia/totem/Makefile")
	mklines := t.SetUpFileMkLines("multimedia/totem/buildlink3.mk",
		MkCvsID,
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

	CheckLinesBuildlink3Mk(mklines)

	// No warning about ABI "totem" and API "{totem,totem-xine}"
	// because that case is explicitly not checked.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Buildlink3Checker_checkVarassign__dependencies_with_path(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileBuildlink3("category/package/buildlink3.mk",
		"BUILDLINK_ABI_DEPENDS.package+=\tpackage>=1.0:../../category/package",
		"BUILDLINK_API_DEPENDS.package+=\tpackage>=1.5:../../category/package")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	// Since these dependencies are malformed, they are not processed further.
	// Doing that would reveal that the ABI version should be higher than the API version.
	t.CheckOutputLines(
		"WARN: ~/category/package/buildlink3.mk:12: "+
			"Invalid dependency pattern \"package>=1.0:../../category/package\".",
		"WARN: ~/category/package/buildlink3.mk:13: "+
			"Invalid dependency pattern \"package>=1.5:../../category/package\".")
}

func (s *Suite) Test_Buildlink3Checker_checkVarassign__abi_without_api(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	// t.CreateFileBuildlink3() cannot be used here since it always adds an API line.
	t.CreateFileLines("category/package/buildlink3.mk",
		MkCvsID,
		"",
		"BUILDLINK_TREE+=\tpackage",
		"",
		".if !defined(PACKAGE_BUILDLINK3_MK)",
		"PACKAGE_BUILDLINK3_MK:=",
		"",
		"BUILDLINK_PKGSRCDIR.package?=\t../../category/package",
		"BUILDLINK_DEPMETHOD.package?=\tbuild",
		"BUILDLINK_ABI_DEPENDS.package+=\tpackage>=1.0",
		"",
		".endif # PACKAGE_BUILDLINK3_MK",
		"",
		"BUILDLINK_TREE+=\t-package")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	// Since only ABI is given but not API, the check for ABI >= API cannot be done.
	t.CheckOutputLines(
		"WARN: ~/category/package/buildlink3.mk:13: Definition of BUILDLINK_API_DEPENDS is missing.")
}

func (s *Suite) Test_Buildlink3Checker_checkVarassign__abi_and_api_with_variables(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileBuildlink3("category/package/buildlink3.mk",
		"BUILDLINK_ABI_DEPENDS.package+=\tpackage>=${ABI_VERSION}",
		"BUILDLINK_API_DEPENDS.package+=\tpackage>=${API_VERSION}",
		"",
		"ABI_VERSION=\t1.0",
		"API_VERSION=\t1.5")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	// Since the versions contain variable references, pkglint refuses to compare them.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Buildlink3Checker_checkVarassign__api_with_variable(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileBuildlink3("category/package/buildlink3.mk",
		"BUILDLINK_ABI_DEPENDS.package+=\tpackage>=1.0",
		"BUILDLINK_API_DEPENDS.package+=\tpackage>=${API_VERSION}",
		"",
		"API_VERSION=\t1.5")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	// Since the versions contain variable references, pkglint refuses to compare them.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Buildlink3Checker_checkVarassign__abi_and_api_with_pattern(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileBuildlink3("category/package/buildlink3.mk",
		"BUILDLINK_ABI_DEPENDS.package+=\tpackage-1.*",
		"BUILDLINK_API_DEPENDS.package+=\tpackage-2.*")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	// Since the versions do not contain lower bounds (they are package-1.*
	// instead of package>=1), pkglint refuses to compare them.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Buildlink3Checker_checkVarassign__api_with_pattern(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileBuildlink3("category/package/buildlink3.mk",
		"BUILDLINK_ABI_DEPENDS.package+=\tpackage>=1",
		"BUILDLINK_API_DEPENDS.package+=\tpackage-1.*")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	// Since the API version does not contain lower bounds (it is package-1.*
	// instead of package>=1), pkglint refuses to compare the versions.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Buildlink3Checker_checkVarassign__other_variables(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileBuildlink3("category/package/buildlink3.mk",
		"BUILDLINK_TREE+=\tmistake", // Wrong, but doesn't happen in practice.
		"",
		"LDFLAGS.NetBSD+=\t-ldl",
		"",
		"BUILDLINK_DEPMETHOD.other+=\tbuild",
		"",
		"BUILDLINK_API_DEPENDS.other+=\tother>=3")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"WARN: ~/category/package/buildlink3.mk:16: " +
			"Only buildlink variables for \"package\", " +
			"not \"other\" may be set in this file.")
}

func (s *Suite) Test_Buildlink3Checker_checkVaruseInPkgbase__PKGBASE_with_variable_PHP_PKG_PREFIX(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.Chdir(".")
	t.FinishSetUp()
	mklines := t.NewMkLines("x11/php-wxwidgets/buildlink3.mk",
		MkCvsID,
		"",
		"BUILDLINK_TREE+=\t${PHP_PKG_PREFIX}-wxWidgets",
		"",
		".if !defined(PHP_WXWIDGETS_BUILDLINK3_MK)",
		"PHP_WXWIDGETS_BUILDLINK3_MK:=",
		"",
		"BUILDLINK_API_DEPENDS.${PHP_PKG_PREFIX}-wxWidgets+=\t${PHP_PKG_PREFIX}-wxWidgets>=2.6.1.0",
		"BUILDLINK_ABI_DEPENDS.${PHP_PKG_PREFIX}-wxWidgets+=\t${PHP_PKG_PREFIX}-wxWidgets>=2.8.10.1nb26",
		"",
		".endif",
		"",
		"BUILDLINK_TREE+=\t-${PHP_PKG_PREFIX}-wxWidgets")

	CheckLinesBuildlink3Mk(mklines)

	t.CheckOutputLines(
		"ERROR: x11/php-wxwidgets/buildlink3.mk:3: "+
			"Identifiers for BUILDLINK_TREE must not refer to other variables.",
		"WARN: x11/php-wxwidgets/buildlink3.mk:8: "+
			"To use PHP_PKG_PREFIX at load time, "+
			".include \"../../mk/bsd.fast.prefs.mk\" first.",
		"ERROR: x11/php-wxwidgets/buildlink3.mk:13: "+
			"Identifiers for BUILDLINK_TREE must not refer to other variables.",
		"WARN: x11/php-wxwidgets/buildlink3.mk:3: "+
			"Please use \"php\" instead of \"${PHP_PKG_PREFIX}\" "+
			"(also in other variables in this file).")
}

func (s *Suite) Test_Buildlink3Checker_checkVaruseInPkgbase__PKGBASE_with_variable_PYPKGPREFIX(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.Chdir(".")
	t.FinishSetUp()
	mklines := t.NewMkLines("x11/py-wxwidgets/buildlink3.mk",
		MkCvsID,
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

	CheckLinesBuildlink3Mk(mklines)

	t.CheckOutputLines(
		"ERROR: x11/py-wxwidgets/buildlink3.mk:3: "+
			"Identifiers for BUILDLINK_TREE must not refer to other variables.",
		"WARN: x11/py-wxwidgets/buildlink3.mk:8: "+
			"To use PYPKGPREFIX at load time, "+
			".include \"../../mk/bsd.fast.prefs.mk\" first.",
		"ERROR: x11/py-wxwidgets/buildlink3.mk:13: "+
			"Identifiers for BUILDLINK_TREE must not refer to other variables.",
		"WARN: x11/py-wxwidgets/buildlink3.mk:3: "+
			"Please use \"py\" instead of \"${PYPKGPREFIX}\" "+
			"(also in other variables in this file).")
}

func (s *Suite) Test_Buildlink3Checker_checkVaruseInPkgbase__PKGBASE_with_variable_RUBY_BASE(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.Chdir(".")
	t.FinishSetUp()
	mklines := t.NewMkLines("x11/ruby1-wxwidgets/buildlink3.mk",
		MkCvsID,
		"",
		"BUILDLINK_TREE+=\t${RUBY_BASE}-wxWidgets",
		"",
		".if !defined(RUBY_WXWIDGETS_BUILDLINK3_MK)",
		"RUBY_WXWIDGETS_BUILDLINK3_MK:=",
		"",
		"BUILDLINK_API_DEPENDS.${RUBY_BASE}-wxWidgets+=\t${RUBY_BASE}-wxWidgets>=2.6.1.0",
		"BUILDLINK_ABI_DEPENDS.${RUBY_BASE}-wxWidgets+=\t${RUBY_BASE}-wxWidgets>=2.8.10.1nb26",
		"",
		".endif",
		"",
		"BUILDLINK_TREE+=\t-${RUBY_BASE}-wxWidgets")

	CheckLinesBuildlink3Mk(mklines)

	t.CheckOutputLines(
		"ERROR: x11/ruby1-wxwidgets/buildlink3.mk:3: "+
			"Identifiers for BUILDLINK_TREE must not refer to other variables.",
		"WARN: x11/ruby1-wxwidgets/buildlink3.mk:8: "+
			"To use RUBY_BASE at load time, "+
			".include \"../../mk/bsd.fast.prefs.mk\" first.",
		"ERROR: x11/ruby1-wxwidgets/buildlink3.mk:13: "+
			"Identifiers for BUILDLINK_TREE must not refer to other variables.",
		"WARN: x11/ruby1-wxwidgets/buildlink3.mk:3: "+
			"Please use \"ruby\" instead of \"${RUBY_BASE}\" "+
			"(also in other variables in this file).")
}

func (s *Suite) Test_Buildlink3Checker_checkVaruseInPkgbase__PKGBASE_with_variable_RUBY_PKGPREFIX(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.Chdir(".")
	t.FinishSetUp()
	mklines := t.NewMkLines("x11/ruby2-wxwidgets/buildlink3.mk",
		MkCvsID,
		"",
		"BUILDLINK_TREE+=\t${RUBY_PKGPREFIX}-wxWidgets",
		"",
		".if !defined(RUBY_WXWIDGETS_BUILDLINK3_MK)",
		"RUBY_WXWIDGETS_BUILDLINK3_MK:=",
		"",
		"BUILDLINK_API_DEPENDS.${RUBY_PKGPREFIX}-wxWidgets+=\t${RUBY_PKGPREFIX}-wxWidgets>=2.6.1.0",
		"BUILDLINK_ABI_DEPENDS.${RUBY_PKGPREFIX}-wxWidgets+=\t${RUBY_PKGPREFIX}-wxWidgets>=2.8.10.1nb26",
		"",
		".endif",
		"",
		"BUILDLINK_TREE+=\t-${RUBY_PKGPREFIX}-wxWidgets")

	CheckLinesBuildlink3Mk(mklines)

	t.CheckOutputLines(
		"ERROR: x11/ruby2-wxwidgets/buildlink3.mk:3: "+
			"Identifiers for BUILDLINK_TREE must not refer to other variables.",
		"WARN: x11/ruby2-wxwidgets/buildlink3.mk:8: "+
			"To use RUBY_PKGPREFIX at load time, "+
			".include \"../../mk/bsd.fast.prefs.mk\" first.",
		"ERROR: x11/ruby2-wxwidgets/buildlink3.mk:13: "+
			"Identifiers for BUILDLINK_TREE must not refer to other variables.",
		"WARN: x11/ruby2-wxwidgets/buildlink3.mk:3: "+
			"Please use \"ruby\" instead of \"${RUBY_PKGPREFIX}\" "+
			"(also in other variables in this file).")
}

func (s *Suite) Test_Buildlink3Checker_checkVaruseInPkgbase__PKGBASE_with_unknown_variable(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.Chdir(".")
	t.FinishSetUp()
	mklines := t.NewMkLines("buildlink3.mk",
		MkCvsID,
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

	CheckLinesBuildlink3Mk(mklines)

	t.CheckOutputLines(
		"ERROR: buildlink3.mk:3: Identifiers for BUILDLINK_TREE must not refer to other variables.",
		"WARN: buildlink3.mk:3: LICENSE should not be used in this file; "+
			"it would be ok in Makefile, Makefile.* or *.mk, but not buildlink3.mk or builtin.mk.",
		"WARN: buildlink3.mk:3: The variable LICENSE should be quoted as part of a shell word.",
		"WARN: buildlink3.mk:8: The variable LICENSE should be quoted as part of a shell word.",
		"WARN: buildlink3.mk:8: The variable LICENSE should be quoted as part of a shell word.",
		"WARN: buildlink3.mk:9: The variable LICENSE should be quoted as part of a shell word.",
		"WARN: buildlink3.mk:9: The variable LICENSE should be quoted as part of a shell word.",
		"ERROR: buildlink3.mk:13: Identifiers for BUILDLINK_TREE must not refer to other variables.",
		"WARN: buildlink3.mk:13: The variable LICENSE should be quoted as part of a shell word.",
		"WARN: buildlink3.mk:3: Please replace \"${LICENSE}\" with a simple string "+
			"(also in other variables in this file).")
}
