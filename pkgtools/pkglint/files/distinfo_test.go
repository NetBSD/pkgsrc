package main

import "gopkg.in/check.v1"

func (s *Suite) Test_ChecklinesDistinfo(c *check.C) {
	t := s.Init(c)

	t.Chdir("category/package")
	t.SetupFileLines("patches/patch-aa",
		RcsID+" line is ignored for computing the SHA1 hash",
		"patch contents")
	t.SetupFileLines("patches/patch-ab",
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
		"ERROR: distinfo:8: Invalid line.",
		"WARN: distinfo:9: Patch file \"patch-nonexistent\" does not exist in directory \"patches\".")
}

func (s *Suite) Test_ChecklinesDistinfo_global_hash_mismatch(c *check.C) {
	t := s.Init(c)

	otherLine := t.NewLine("other/distinfo", 7, "dummy")
	G.Pkgsrc.Hashes = map[string]*Hash{"SHA512:pkgname-1.0.tar.gz": {"Some-512-bit-hash", otherLine}}
	lines := t.NewLines("distinfo",
		RcsID,
		"",
		"SHA512 (pkgname-1.0.tar.gz) = 12341234")

	ChecklinesDistinfo(lines)

	t.CheckOutputLines(
		"ERROR: distinfo:3: The hash SHA512 for pkgname-1.0.tar.gz is 12341234, which differs from Some-512-bit-hash in other/distinfo:7.",
		"ERROR: distinfo:EOF: Expected SHA1, RMD160, SHA512, Size checksums for \"pkgname-1.0.tar.gz\", got SHA512.")
}

func (s *Suite) Test_ChecklinesDistinfo_uncommitted_patch(c *check.C) {
	t := s.Init(c)

	t.Chdir("category/package")
	t.SetupFileLines("patches/patch-aa",
		RcsID,
		"",
		"--- oldfile",
		"+++ newfile",
		"@@ -1,1 +1,1 @@",
		"-old",
		"+new")
	t.SetupFileLines("CVS/Entries",
		"/distinfo/...")
	lines := t.SetupFileLines("distinfo",
		RcsID,
		"",
		"SHA1 (patch-aa) = 5ad1fb9b3c328fff5caa1a23e8f330e707dd50c0")
	G.Pkg = NewPackage(".")

	ChecklinesDistinfo(lines)

	t.CheckOutputLines(
		"WARN: distinfo:3: patches/patch-aa is registered in distinfo but not added to CVS.")
}

func (s *Suite) Test_ChecklinesDistinfo_unrecorded_patches(c *check.C) {
	t := s.Init(c)

	t.Chdir("category/package")
	t.SetupFileLines("patches/CVS/Entries")
	t.SetupFileLines("patches/patch-aa")
	t.SetupFileLines("patches/patch-src-Makefile")
	lines := t.SetupFileLines("distinfo",
		RcsID,
		"",
		"SHA1 (distfile.tar.gz) = ...",
		"RMD160 (distfile.tar.gz) = ...",
		"SHA512 (distfile.tar.gz) = ...",
		"Size (distfile.tar.gz) = 1024 bytes")
	G.Pkg = NewPackage(".")

	ChecklinesDistinfo(lines)

	t.CheckOutputLines(
		"ERROR: distinfo: patch \"patches/patch-aa\" is not recorded. Run \""+confMake+" makepatchsum\".",
		"ERROR: distinfo: patch \"patches/patch-src-Makefile\" is not recorded. Run \""+confMake+" makepatchsum\".")
}

func (s *Suite) Test_ChecklinesDistinfo_manual_patches(c *check.C) {
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
	// the PATCHDIR is known, therefore the checks are active.
	t.CheckOutputLines(
		"WARN: distinfo:3: Patch file \"patch-aa\" does not exist in directory \"patches\".")
}

// PHP modules that are not PECL use the distinfo file from lang/php* but
// their own patches directory. Therefore the distinfo file refers to missing
// patches. Since this strange situation is caused by the pkgsrc
// infrastructure, there is nothing a package author can do about.
func (s *Suite) Test_ChecklinesDistinfo__missing_php_patches(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()
	t.SetupCommandLine("-Wall,no-space")
	t.CreateFileLines("licenses/unknown-license")
	t.CreateFileLines("lang/php/ext.mk",
		MkRcsID,
		"",
		"PHPEXT_MK=      # defined",
		"PHPPKGSRCDIR=   lang/php72",
		"LICENSE?=        unknown-license",
		"COMMENT?=       Some PHP package",
		"GENERATE_PLIST+=# none",
		"",
		".if !defined(PECL_VERSION)",
		"DISTINFO_FILE=  ${.CURDIR}/${PHPPKGSRCDIR}/distinfo",
		".endif",
		".if defined(USE_PHP_EXT_PATCHES)",
		"PATCHDIR=       ${.CURDIR}/${PHPPKGSRCDIR}/patches",
		".endif")
	t.CreateFileLines("lang/php72/patches/patch-php72",
		RcsID,
		"",
		"Documentation",
		"",
		"--- old file",
		"+++ new file",
		"@@ -1,1 +1,1 @@",
		"-old",
		"+new")
	t.SetupFileLines("lang/php72/distinfo",
		RcsID,
		"",
		"SHA1 (patch-php72) = c109b2089f5ddbc5372b2ab28115ff558ee4187d")

	t.CreateFileLines("archivers/php-bz2/Makefile",
		MkRcsID,
		"",
		"USE_PHP_EXT_PATCHES=    yes",
		"",
		".include \"../../lang/php/ext.mk\"",
		".include \"../../mk/bsd.pkg.mk\"")
	t.CreateFileLines("archivers/php-zlib/Makefile",
		MkRcsID,
		"",
		".include \"../../lang/php/ext.mk\"",
		".include \"../../mk/bsd.pkg.mk\"")

	G.CheckDirent(t.File("archivers/php-bz2"))
	G.CheckDirent(t.File("archivers/php-zlib"))

	t.CheckOutputEmpty()
}
