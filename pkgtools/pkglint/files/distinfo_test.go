package main

import "gopkg.in/check.v1"

func (s *Suite) Test_ChecklinesDistinfo(c *check.C) {
	t := s.Init(c)

	t.Chdir("category/package")
	t.CreateFileLines("patches/patch-aa",
		RcsID+" line is ignored for computing the SHA1 hash",
		"patch contents")
	t.CreateFileLines("patches/patch-ab",
		"patch contents")
	lines := t.SetupFileLines("distinfo",
		"should be the RCS ID",
		"should be empty",
		"MD5 (distfile.tar.gz) = 12345678901234567890123456789012",
		"SHA1 (distfile.tar.gz) = 1234567890123456789012345678901234567890",
		"SHA1 (patch-aa) = 6b98dd609f85a9eb9c4c1e4e7055a6aaa62b7cc7",
		"Size (patch-aa) = 104",
		"SHA1 (patch-ab) = 6b98dd609f85a9eb9c4c1e4e7055a6aaa62b7cc7",
		"Another invalid line",
		"SHA1 (patch-nonexistent) = 1234")
	G.Pkg = NewPackage(".")

	ChecklinesDistinfo(lines)

	t.CheckOutputLines(
		"ERROR: distinfo:1: Expected \"$"+"NetBSD$\".",
		"NOTE: distinfo:2: Empty line expected.",
		"ERROR: distinfo:5: Expected SHA1, RMD160, SHA512, Size checksums for \"distfile.tar.gz\", got MD5, SHA1.",
		"ERROR: distinfo:7: Expected SHA1 hash for patch-aa, got SHA1, Size.",
		"ERROR: distinfo:8: Invalid line: Another invalid line",
		"WARN: distinfo:9: Patch file \"patch-nonexistent\" does not exist in directory \"patches\".")
}

// When checking the complete pkgsrc tree, pkglint has all information it needs
// to check whether different packages use the same distfile but require
// different hashes for it.
//
// In such a case, typically one of the packages should put its distfiles into
// a DIST_SUBDIR.
func (s *Suite) Test_distinfoLinesChecker_checkGlobalDistfileMismatch(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()
	t.SetupPackage("category/package1")
	t.SetupPackage("category/package2")
	t.CreateFileLines("category/package1/distinfo",
		RcsID,
		"",
		"SHA512 (distfile-1.0.tar.gz) = 1234567811111111",
		"SHA512 (distfile-1.1.tar.gz) = 1111111111111111")
	t.CreateFileLines("category/package2/distinfo",
		RcsID,
		"",
		"SHA512 (distfile-1.0.tar.gz) = 1234567822222222",
		"SHA512 (distfile-1.1.tar.gz) = 1111111111111111")
	t.CreateFileLines("Makefile",
		MkRcsID,
		"",
		"COMMENT=\tThis is pkgsrc",
		"",
		"SUBDIR+=\tcategory")
	t.CreateFileLines("category/Makefile",
		MkRcsID,
		"",
		"COMMENT=\tUseful programs",
		"",
		"SUBDIR+=\tpackage1",
		"SUBDIR+=\tpackage2",
		"",
		".include \"../mk/misc/category.mk\"")

	G.Main("pkglint", "-r", "-Wall", "-Call", t.File("."))

	t.CheckOutputLines(
		"ERROR: ~/category/package1/distinfo:4: Expected SHA1, RMD160, SHA512, Size checksums for \"distfile-1.0.tar.gz\", got SHA512.",
		"ERROR: ~/category/package1/distinfo:EOF: Expected SHA1, RMD160, SHA512, Size checksums for \"distfile-1.1.tar.gz\", got SHA512.",
		"ERROR: ~/category/package2/distinfo:3: The SHA512 hash for distfile-1.0.tar.gz is 1234567822222222, "+
			"which conflicts with 1234567811111111 in ../package1/distinfo:3.",
		"ERROR: ~/category/package2/distinfo:4: Expected SHA1, RMD160, SHA512, Size checksums for \"distfile-1.0.tar.gz\", got SHA512.",
		"ERROR: ~/category/package2/distinfo:EOF: Expected SHA1, RMD160, SHA512, Size checksums for \"distfile-1.1.tar.gz\", got SHA512.",
		"WARN: ~/licenses/gnu-gpl-v2: This license seems to be unused.",
		"5 errors and 1 warning found.")
}

func (s *Suite) Test_ChecklinesDistinfo__uncommitted_patch(c *check.C) {
	t := s.Init(c)

	t.SetupPackage("category/package")
	t.Chdir("category/package")
	t.CreateFileDummyPatch("patches/patch-aa")
	t.CreateFileLines("CVS/Entries",
		"/distinfo/...")
	t.SetupFileLines("distinfo",
		RcsID,
		"",
		"SHA1 (patch-aa) = ebbf34b0641bcb508f17d5a27f2bf2a536d810ac")

	G.checkdirPackage(".")

	t.CheckOutputLines(
		"WARN: distinfo:3: patches/patch-aa is registered in distinfo but not added to CVS.")
}

func (s *Suite) Test_ChecklinesDistinfo__unrecorded_patches(c *check.C) {
	t := s.Init(c)

	t.SetupPackage("category/package")
	t.Chdir("category/package")
	t.CreateFileLines("patches/CVS/Entries")
	t.CreateFileDummyPatch("patches/patch-aa")
	t.CreateFileDummyPatch("patches/patch-src-Makefile")
	t.SetupFileLines("distinfo",
		RcsID,
		"",
		"SHA1 (distfile.tar.gz) = ...",
		"RMD160 (distfile.tar.gz) = ...",
		"SHA512 (distfile.tar.gz) = ...",
		"Size (distfile.tar.gz) = 1024 bytes")

	G.checkdirPackage(".")

	t.CheckOutputLines(
		"ERROR: distinfo: patch \"patches/patch-aa\" is not recorded. Run \""+confMake+" makepatchsum\".",
		"ERROR: distinfo: patch \"patches/patch-src-Makefile\" is not recorded. Run \""+confMake+" makepatchsum\".")
}

// The distinfo file and the patches are usually placed in the package
// directory. By defining PATCHDIR or DISTINFO_FILE, a package can define
// that they are somewhere else in pkgsrc.
func (s *Suite) Test_ChecklinesDistinfo__relative_path_in_distinfo(c *check.C) {
	t := s.Init(c)

	t.SetupPackage("category/package",
		"DISTINFO_FILE=\t../../other/common/distinfo",
		"PATCHDIR=\t../../devel/patches/patches")
	t.Remove("category/package/distinfo")
	t.CreateFileLines("devel/patches/patches/CVS/Entries")
	t.CreateFileDummyPatch("devel/patches/patches/patch-aa")
	t.CreateFileDummyPatch("devel/patches/patches/patch-only-in-patches")
	t.SetupFileLines("other/common/distinfo",
		RcsID,
		"",
		"SHA1 (patch-aa) = ...",
		"SHA1 (patch-only-in-distinfo) = ...")
	t.Chdir("category/package")

	G.checkdirPackage(".")

	t.CheckOutputLines(
		"ERROR: ../../other/common/distinfo:3: SHA1 hash of ../../devel/patches/patches/patch-aa differs "+
			"(distinfo has ..., patch file has ebbf34b0641bcb508f17d5a27f2bf2a536d810ac).",
		"WARN: ../../other/common/distinfo:4: Patch file \"patch-only-in-distinfo\" "+
			"does not exist in directory \"../../devel/patches/patches\".",
		"ERROR: ../../other/common/distinfo: patch \"../../devel/patches/patches/patch-only-in-patches\" "+
			"is not recorded. Run \""+confMake+" makepatchsum\".")
}

// When the distinfo file and the patches are placed in the same package,
// their diagnostics use short relative paths.
func (s *Suite) Test_ChecklinesDistinfo__distinfo_and_patches_in_separate_directory(c *check.C) {
	t := s.Init(c)

	t.SetupPackage("category/package",
		"DISTINFO_FILE=\t../../other/common/distinfo",
		"PATCHDIR=\t../../other/common/patches")
	t.Remove("category/package/distinfo")
	t.CreateFileLines("other/common/patches/CVS/Entries")
	t.CreateFileDummyPatch("other/common/patches/patch-aa")
	t.CreateFileDummyPatch("other/common/patches/patch-only-in-patches")
	t.SetupFileLines("other/common/distinfo",
		RcsID,
		"",
		"SHA1 (patch-aa) = ...",
		"SHA1 (patch-only-in-distinfo) = ...")
	t.Chdir("category/package")

	G.checkdirPackage(".")

	t.CheckOutputLines(
		"ERROR: ../../other/common/distinfo:3: SHA1 hash of patches/patch-aa differs "+
			"(distinfo has ..., patch file has ebbf34b0641bcb508f17d5a27f2bf2a536d810ac).",
		"WARN: ../../other/common/distinfo:4: Patch file \"patch-only-in-distinfo\" "+
			"does not exist in directory \"patches\".",
		"ERROR: ../../other/common/distinfo: patch \"patches/patch-only-in-patches\" "+
			"is not recorded. Run \""+confMake+" makepatchsum\".")
}

func (s *Suite) Test_ChecklinesDistinfo__manual_patches(c *check.C) {
	t := s.Init(c)

	t.Chdir("category/package")
	t.CreateFileLines("patches/manual-libtool.m4")
	lines := t.SetupFileLines("distinfo",
		RcsID,
		"",
		"SHA1 (patch-aa) = ...")

	ChecklinesDistinfo(lines)

	// When a distinfo file is checked on its own, without belonging to a package,
	// the PATCHDIR is not known and therefore no diagnostics are logged.
	t.CheckOutputEmpty()

	G.Pkg = NewPackage(".")

	ChecklinesDistinfo(lines)

	// When a distinfo file is checked in the context of a package,
	// the PATCHDIR is known, therefore the check is active.
	t.CheckOutputLines(
		"WARN: distinfo:3: Patch file \"patch-aa\" does not exist in directory \"patches\".")
}

// PHP modules that are not PECL use the distinfo file from lang/php* but
// their own patches directory. Therefore the distinfo file refers to missing
// patches. Since this strange situation is caused by the pkgsrc
// infrastructure, there is nothing a package author can do about.
//
// XXX: Re-check the documentation for this test.
func (s *Suite) Test_ChecklinesDistinfo__missing_php_patches(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()
	t.SetupCommandLine("-Wall,no-space")
	t.CreateFileLines("licenses/unknown-license")
	t.CreateFileLines("lang/php/ext.mk",
		MkRcsID,
		"",
		"PHPEXT_MK=      # defined",
		"PHPPKGSRCDIR=   ../../lang/php72",
		"LICENSE?=       unknown-license",
		"COMMENT?=       Some PHP package",
		"GENERATE_PLIST+=# none",
		"",
		".if !defined(PECL_VERSION)",
		"DISTINFO_FILE=  ${.CURDIR}/${PHPPKGSRCDIR}/distinfo",
		".endif",
		".if defined(USE_PHP_EXT_PATCHES)",
		"PATCHDIR=       ${.CURDIR}/${PHPPKGSRCDIR}/patches",
		".endif")
	t.CreateFileDummyPatch("lang/php72/patches/patch-php72")
	t.CreateFileLines("lang/php72/distinfo",
		RcsID,
		"",
		"SHA1 (patch-php72) = ebbf34b0641bcb508f17d5a27f2bf2a536d810ac")

	t.CreateFileLines("archivers/php-bz2/Makefile",
		MkRcsID,
		"",
		"USE_PHP_EXT_PATCHES=    yes",
		"",
		".include \"../../lang/php/ext.mk\"",
		".include \"../../mk/bsd.pkg.mk\"")

	G.CheckDirent(t.File("archivers/php-bz2"))

	t.CreateFileLines("archivers/php-zlib/Makefile",
		MkRcsID,
		"",
		".include \"../../lang/php/ext.mk\"",
		".include \"../../mk/bsd.pkg.mk\"")

	G.CheckDirent(t.File("archivers/php-zlib"))

	t.CheckOutputEmpty()
}

func (s *Suite) Test_distinfoLinesChecker_checkPatchSha1(c *check.C) {
	t := s.Init(c)

	G.Pkg = NewPackage(t.File("category/package"))
	distinfoLine := t.NewLine(t.File("category/package/distinfo"), 5, "")

	checker := &distinfoLinesChecker{}
	checker.checkPatchSha1(distinfoLine, "patch-nonexistent", "distinfo-sha1")

	t.CheckOutputLines(
		"ERROR: ~/category/package/distinfo:5: Patch patch-nonexistent does not exist.")
}
