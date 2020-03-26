package pkglint

import "gopkg.in/check.v1"

func (s *Suite) Test_CheckLinesDistinfo__parse_errors(c *check.C) {
	t := s.Init(c)

	t.Chdir("category/package")
	t.CreateFileLines("patches/patch-aa",
		CvsID+" line is ignored for computing the SHA1 hash",
		"patch contents")
	t.CreateFileLines("patches/patch-ab",
		"patch contents")
	lines := t.SetUpFileLines("distinfo",
		"should be the CVS ID",
		"should be empty",
		"MD5 (distfile-1.0.tar.gz) = 12345678901234567890123456789012",
		"SHA1 (distfile-1.0.tar.gz) = 1234567890123456789012345678901234567890",
		"SHA1 (patch-aa) = 6b98dd609f85a9eb9c4c1e4e7055a6aaa62b7cc7",
		"Size (patch-aa) = 104",
		"SHA1 (patch-ab) = 6b98dd609f85a9eb9c4c1e4e7055a6aaa62b7cc7",
		"Another invalid line",
		"SHA1 (patch-nonexistent) = 1234")
	pkg := NewPackage(".")

	CheckLinesDistinfo(pkg, lines)

	t.CheckOutputLines(
		"ERROR: distinfo:1: Expected \"$"+"NetBSD$\".",
		"NOTE: distinfo:1: Empty line expected above this line.",
		"ERROR: distinfo:1: Invalid line: should be the CVS ID",
		"ERROR: distinfo:2: Invalid line: should be empty",
		"ERROR: distinfo:8: Invalid line: Another invalid line",
		"ERROR: distinfo:3: Expected SHA1, RMD160, SHA512, Size checksums for \"distfile-1.0.tar.gz\", got MD5, SHA1.",
		"ERROR: distinfo:5: Expected SHA1 hash for patch-aa, got SHA1, Size.",
		"WARN: distinfo:9: Patch file \"patch-nonexistent\" does not exist in directory \"patches\".")
}

func (s *Suite) Test_distinfoLinesChecker_parse__trailing_empty_line(c *check.C) {
	t := s.Init(c)

	lines := t.SetUpFileLines("distinfo",
		CvsID,
		"")

	CheckLinesDistinfo(nil, lines)

	t.CheckOutputLines(
		"NOTE: ~/distinfo:2: Trailing empty lines.")
}

func (s *Suite) Test_distinfoLinesChecker_parse__empty_file(c *check.C) {
	t := s.Init(c)

	lines := t.SetUpFileLines("distinfo",
		CvsID)

	CheckLinesDistinfo(nil, lines)

	t.CheckOutputLines(
		"NOTE: ~/distinfo:1: Empty line expected below this line.")
}

func (s *Suite) Test_distinfoLinesChecker_parse__commented_first_line(c *check.C) {
	t := s.Init(c)

	// This mismatch can happen for inexperienced pkgsrc users.
	// It's not easy to keep all these different file types apart.
	lines := t.SetUpFileLines("distinfo",
		PlistCvsID)

	CheckLinesDistinfo(nil, lines)

	t.CheckOutputLines(
		"ERROR: ~/distinfo:1: Expected \""+CvsID+"\".",
		"NOTE: ~/distinfo:1: Empty line expected above this line.",
		"ERROR: ~/distinfo:1: Invalid line: "+PlistCvsID)
}

func (s *Suite) Test_distinfoLinesChecker_parse__completely_empty_file(c *check.C) {
	t := s.Init(c)

	lines := t.SetUpFileLines("distinfo",
		nil...)

	CheckLinesDistinfo(nil, lines)

	t.CheckOutputLines(
		"NOTE: ~/distinfo:EOF: Empty line expected above this line.")
}

// When the distinfo file and the patches are placed in the same package,
// their diagnostics use short relative paths.
func (s *Suite) Test_distinfoLinesChecker_check__distinfo_and_patches_in_separate_directory(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"DISTINFO_FILE=\t../../other/common/distinfo",
		"PATCHDIR=\t../../other/common/patches")
	t.Remove("category/package/distinfo")
	t.CreateFileLines("other/common/patches/CVS/Entries")
	t.CreateFileDummyPatch("other/common/patches/patch-aa")
	t.CreateFileDummyPatch("other/common/patches/patch-only-in-patches")
	t.SetUpFileLines("other/common/distinfo",
		CvsID,
		"",
		"SHA1 (patch-aa) = ...",
		"SHA1 (patch-only-in-distinfo) = ...")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.checkdirPackage(".")

	t.CheckOutputLines(
		"ERROR: ../../other/common/distinfo:3: SHA1 hash of patches/patch-aa differs "+
			"(distinfo has ..., patch file has ebbf34b0641bcb508f17d5a27f2bf2a536d810ac).",
		"WARN: ../../other/common/distinfo:4: Patch file \"patch-only-in-distinfo\" "+
			"does not exist in directory \"patches\".",
		"ERROR: ../../other/common/distinfo: Patch \"patches/patch-only-in-patches\" "+
			"is not recorded. Run \""+confMake+" makepatchsum\".")
}

func (s *Suite) Test_distinfoLinesChecker_check__manual_patches(c *check.C) {
	t := s.Init(c)

	t.Chdir("category/package")
	t.CreateFileLines("patches/manual-libtool.m4")
	lines := t.SetUpFileLines("distinfo",
		CvsID,
		"",
		"SHA1 (patch-aa) = ...")

	CheckLinesDistinfo(nil, lines)

	// When a distinfo file is checked on its own, without belonging to a package,
	// the PATCHDIR is not known and therefore no diagnostics are logged.
	t.CheckOutputEmpty()

	pkg := NewPackage(".")

	CheckLinesDistinfo(pkg, lines)

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
func (s *Suite) Test_distinfoLinesChecker_check__missing_php_patches(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("licenses/unknown-license")
	t.CreateFileLines("lang/php/ext.mk",
		MkCvsID,
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
		CvsID,
		"",
		"SHA1 (patch-php72) = ebbf34b0641bcb508f17d5a27f2bf2a536d810ac")

	t.CreateFileLines("archivers/php-bz2/Makefile",
		MkCvsID,
		"",
		"USE_PHP_EXT_PATCHES=\tyes",
		"",
		".include \"../../lang/php/ext.mk\"",
		".include \"../../mk/bsd.pkg.mk\"")
	t.CreateFileLines("archivers/php-bz2/DESCR",
		"Description")
	t.FinishSetUp()

	G.Check(t.File("archivers/php-bz2"))

	t.CreateFileLines("archivers/php-zlib/Makefile",
		MkCvsID,
		"",
		".include \"../../lang/php/ext.mk\"",
		".include \"../../mk/bsd.pkg.mk\"")
	t.CreateFileLines("archivers/php-zlib/DESCR",
		"Description")

	G.Check(t.File("archivers/php-zlib"))

	t.CheckOutputEmpty()
}

func (s *Suite) Test_distinfoLinesChecker_checkFilename(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileLines("category/package/distinfo",
		CvsID,
		"",
		"SHA1 (ok-1.0.tar.gz) = 1234",
		"RMD160 (ok-1.0.tar.gz) = 1234",
		"SHA512 (ok-1.0.tar.gz) = 1234",
		"Size (ok-1.0.tar.gz) = 1234",
		"SHA1 (not-ok.tar.gz) = 1234",
		"RMD160 (not-ok.tar.gz) = 1234",
		"SHA512 (not-ok.tar.gz) = 1234",
		"Size (not-ok.tar.gz) = 1234",
		"SHA1 (non-versioned/not-ok.tar.gz) = 1234",
		"RMD160 (non-versioned/not-ok.tar.gz) = 1234",
		"SHA512 (non-versioned/not-ok.tar.gz) = 1234",
		"Size (non-versioned/not-ok.tar.gz) = 1234",
		"SHA1 (versioned-1/ok.tar.gz) = 1234",
		"RMD160 (versioned-1/ok.tar.gz) = 1234",
		"SHA512 (versioned-1/ok.tar.gz) = 1234",
		"Size (versioned-1/ok.tar.gz) = 1234")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		"WARN: distinfo:7: Distfiles without version number "+
			"should be placed in a versioned DIST_SUBDIR.",
		"WARN: distinfo:11: Distfiles without version number "+
			"should be placed in a versioned DIST_SUBDIR.")
}

func (s *Suite) Test_distinfoLinesChecker_checkAlgorithms__nonexistent_distfile_called_patch(c *check.C) {
	t := s.Init(c)

	t.Chdir("category/package")
	lines := t.SetUpFileLines("distinfo",
		CvsID,
		"",
		"MD5 (patch-5.3.tar.gz) = 12345678901234567890123456789012",
		"SHA1 (patch-5.3.tar.gz) = 1234567890123456789012345678901234567890")
	pkg := NewPackage(".")

	CheckLinesDistinfo(pkg, lines)

	// Even though the filename starts with "patch-" and therefore looks like
	// a patch, it is a normal distfile because it has other hash algorithms
	// than exactly SHA1.
	t.CheckOutputLines(
		"ERROR: distinfo:3: Expected SHA1, RMD160, SHA512, Size checksums " +
			"for \"patch-5.3.tar.gz\", got MD5, SHA1.")
}

func (s *Suite) Test_distinfoLinesChecker_checkAlgorithms__wrong_distfile_algorithms(c *check.C) {
	t := s.Init(c)

	t.Chdir("category/package")
	lines := t.SetUpFileLines("distinfo",
		CvsID,
		"",
		"MD5 (distfile.tar.gz) = 12345678901234567890123456789012",
		"SHA1 (distfile.tar.gz) = 1234567890123456789012345678901234567890")

	CheckLinesDistinfo(nil, lines)

	t.CheckOutputLines(
		"ERROR: distinfo:3: Expected SHA1, RMD160, SHA512, Size checksums " +
			"for \"distfile.tar.gz\", got MD5, SHA1.")
}

// This case only happens when a distinfo file is checked on its own,
// without any reference to a pkgsrc package. Additionally the distfile
// must start with the patch- prefix and the algorithms must be wrong
// for both distfile or patch.
//
// This test only demonstrates the edge case.
func (s *Suite) Test_distinfoLinesChecker_checkAlgorithms__ambiguous_distfile(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--explain")
	t.Chdir("category/package")
	lines := t.SetUpFileLines("distinfo",
		CvsID,
		"",
		"MD5 (patch-4.2.tar.gz) = 12345678901234567890123456789012")

	CheckLinesDistinfo(nil, lines)

	t.CheckOutputLines(
		"ERROR: distinfo:3: Wrong checksum algorithms MD5 for patch-4.2.tar.gz.",
		"",
		"\tDistfiles that are downloaded from external sources must have the",
		"\tchecksum algorithms SHA1, RMD160, SHA512, Size.",
		"",
		"\tPatch files from pkgsrc must have only the SHA1 hash.",
		"")
}

func (s *Suite) Test_distinfoLinesChecker_checkAlgorithms__wrong_patch_algorithms(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.Chdir("category/package")
	t.CreateFileDummyPatch("patches/patch-aa")
	t.SetUpFileLines("distinfo",
		CvsID,
		"",
		"MD5 (patch-aa) = 12345678901234567890123456789012",
		"SHA1 (patch-aa) = 1234567890123456789012345678901234567890")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		"ERROR: distinfo:3: Expected SHA1 hash for patch-aa, got MD5, SHA1.",
		"ERROR: distinfo:4: SHA1 hash of patches/patch-aa differs "+
			"(distinfo has 1234567890123456789012345678901234567890, "+
			"patch file has ebbf34b0641bcb508f17d5a27f2bf2a536d810ac).")
}

func (s *Suite) Test_distinfoLinesChecker_checkAlgorithms__missing_patch_with_distfile_checksums(c *check.C) {
	t := s.Init(c)

	lines := t.SetUpFileLines("distinfo",
		CvsID,
		"",
		"SHA1 (patch-aa) = ...",
		"RMD160 (patch-aa) = ...",
		"SHA512 (patch-aa) = ...",
		"Size (patch-aa) = ... bytes")

	CheckLinesDistinfo(nil, lines)

	// The file name certainly looks like a pkgsrc patch, but there
	// is no corresponding file in the file system, and there is no
	// current package to correctly determine the PATCHDIR. Therefore
	// pkglint doesn't know whether this is a distfile or a missing
	// patch file and doesn't warn at all.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_distinfoLinesChecker_checkAlgorithms__existing_patch_with_distfile_checksums(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileLines("category/package/distinfo",
		CvsID,
		"",
		"SHA1 (patch-aa) = ...",
		"RMD160 (patch-aa) = ...",
		"SHA512 (patch-aa) = ...",
		"Size (patch-aa) = ... bytes")
	t.CreateFileDummyPatch("category/package/patches/patch-aa")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	// Even though the checksums in the distinfo file look as if they
	// refer to a distfile, there is a patch file in the file system
	// that matches the distinfo lines. When checking a pkgsrc package
	// (as opposed to checking a distinfo file on its own), this means
	// that the distinfo lines clearly refer to that patch file and not
	// to a distfile.
	t.CheckOutputLines(
		"ERROR: ~/category/package/distinfo:3: "+
			"Expected SHA1 hash for patch-aa, got SHA1, RMD160, SHA512, Size.",
		"ERROR: ~/category/package/distinfo:3: "+
			"SHA1 hash of patches/patch-aa differs (distinfo has ..., "+
			"patch file has ebbf34b0641bcb508f17d5a27f2bf2a536d810ac).")
}

func (s *Suite) Test_distinfoLinesChecker_checkAlgorithms__missing_patch_with_wrong_algorithms(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.SetUpFileLines("category/package/distinfo",
		CvsID,
		"",
		"RMD160 (patch-aa) = ...")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	// Patch files usually have the SHA1 hash or none at all if they are fresh.
	// In all other cases pkglint assumes that the file is a distfile,
	// therefore it requires the usual distfile checksum algorithms here.
	t.CheckOutputLines(
		"ERROR: ~/category/package/distinfo:3: " +
			"Expected SHA1, RMD160, SHA512, Size checksums for \"patch-aa\", got RMD160.")
}

// When there is at least one correct hash for a distfile and the distfile
// has already been downloaded to pkgsrc/distfiles, which is the standard
// distfiles location, running pkglint --autofix adds the missing hashes.
func (s *Suite) Test_distinfoLinesChecker_checkAlgorithmsDistfile__add_missing_hashes_for_existing_distfile(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--explain")
	t.SetUpPackage("category/package")
	t.CreateFileLines("category/package/distinfo",
		CvsID,
		"",
		"RMD160 (package-1.0.txt) = 1a88147a0344137404c63f3b695366eab869a98a",
		"Size (package-1.0.txt) = 13 bytes",
		"CRC32 (package-1.0.txt) = asdf")
	t.CreateFileLines("distfiles/package-1.0.txt",
		"hello, world")
	t.FinishSetUp()

	// This run is only used to verify that the RMD160 hash is correct, and if
	// it should ever differ, the correct hash will appear in an error message.
	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"ERROR: ~/category/package/distinfo:3: "+
			"Expected SHA1, RMD160, SHA512, Size checksums for \"package-1.0.txt\", "+
			"got RMD160, Size, CRC32.",
		"ERROR: ~/category/package/distinfo:3: Missing SHA1 hash for package-1.0.txt.",
		"ERROR: ~/category/package/distinfo:3: Missing SHA512 hash for package-1.0.txt.")

	t.SetUpCommandLine("-Wall", "--autofix", "--show-autofix", "--source")

	G.Check(t.File("category/package"))

	// Since the file exists in the distfiles directory, pkglint checks the
	// hash right away. It also adds the missing hashes since this file is
	// not a patch file.
	t.CheckOutputLines(
		"ERROR: ~/category/package/distinfo:3: Missing SHA1 hash for package-1.0.txt.",
		"AUTOFIX: ~/category/package/distinfo:3: "+
			"Inserting a line \"SHA1 (package-1.0.txt) "+
			"= cd50d19784897085a8d0e3e413f8612b097c03f1\" "+
			"above this line.",
		"+\tSHA1 (package-1.0.txt) = cd50d19784897085a8d0e3e413f8612b097c03f1",
		">\tRMD160 (package-1.0.txt) = 1a88147a0344137404c63f3b695366eab869a98a",
		"",
		"ERROR: ~/category/package/distinfo:3: Missing SHA512 hash for package-1.0.txt.",
		"AUTOFIX: ~/category/package/distinfo:3: "+
			"Inserting a line \"SHA512 (package-1.0.txt) "+
			"= f65f341b35981fda842b09b2c8af9bcdb7602a4c2e6fa1f7d41f0974d3e3122f"+
			"268fc79d5a4af66358f5133885cd1c165c916f80ab25e5d8d95db46f803c782c\" below this line.",
		"+\tSHA1 (package-1.0.txt) = cd50d19784897085a8d0e3e413f8612b097c03f1",
		">\tRMD160 (package-1.0.txt) = 1a88147a0344137404c63f3b695366eab869a98a",
		"+\tSHA512 (package-1.0.txt) = f65f341b35981fda842b09b2c8af9bcdb7602a4c2e6fa1f7d41f0974d3e3122f"+
			"268fc79d5a4af66358f5133885cd1c165c916f80ab25e5d8d95db46f803c782c")

	t.SetUpCommandLine("-Wall")

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"ERROR: ~/category/package/distinfo:3: " +
			"Expected SHA1, RMD160, SHA512, Size checksums for \"package-1.0.txt\", " +
			"got SHA1, RMD160, SHA512, Size, CRC32.")
}

// When some of the hashes for a distfile are missing, pkglint can calculate
// them. In order to do this, the distfile needs to be downloaded first. This
// often requires manual work, otherwise it would have been done already.
//
// Since the distfile has not been downloaded in this test case, pkglint can
// only explain how to download the distfile.
func (s *Suite) Test_distinfoLinesChecker_checkAlgorithmsDistfile__add_missing_hashes_for_nonexistent_distfile(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--explain")
	t.SetUpPackage("category/package")
	t.CreateFileLines("category/package/distinfo",
		CvsID,
		"",
		"RMD160 (package-1.0.txt) = 1a88147a0344137404c63f3b695366eab869a98a",
		"Size (package-1.0.txt) = 13 bytes",
		"CRC32 (package-1.0.txt) = asdf")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"ERROR: ~/category/package/distinfo:3: "+
			"Expected SHA1, RMD160, SHA512, Size checksums for \"package-1.0.txt\", "+
			"got RMD160, Size, CRC32.",
		"",
		"\tTo add the missing lines to the distinfo file, run",
		"\t\t"+confMake+" distinfo",
		"\tfor each variant of the package until all distfiles are downloaded",
		"\tto ${PKGSRCDIR}/distfiles.",
		"",
		"\tThe variants are typically selected by setting EMUL_PLATFORM or",
		"\tsimilar variables in the command line.",
		"",
		"\tAfter that, run \"cvs update -C distinfo\" to revert the distinfo file",
		"\tto the previous state, since the above commands have removed some of",
		"\tthe entries.",
		"",
		"\tAfter downloading all possible distfiles, run \"pkglint --autofix\",",
		"\twhich will find the downloaded distfiles and add the missing hashes",
		"\tto the distinfo file.",
		"")

	t.SetUpCommandLine("-Wall", "--autofix", "--show-autofix", "--source")

	G.Check(t.File("category/package"))

	// Since the distfile does not exist, pkglint cannot fix anything.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_distinfoLinesChecker_checkAlgorithmsDistfile__wrong_distfile_hash(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileLines("category/package/distinfo",
		CvsID,
		"",
		"RMD160 (package-1.0.txt) = 1234wrongHash1234")
	t.CreateFileLines("distfiles/package-1.0.txt",
		"hello, world")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"ERROR: ~/category/package/distinfo:3: "+
			"Expected SHA1, RMD160, SHA512, Size checksums for \"package-1.0.txt\", "+
			"got RMD160.",
		"ERROR: ~/category/package/distinfo:3: "+
			"The RMD160 checksum for \"package-1.0.txt\" is 1234wrongHash1234 in distinfo, "+
			"1a88147a0344137404c63f3b695366eab869a98a in ../../distfiles/package-1.0.txt.")
}

func (s *Suite) Test_distinfoLinesChecker_checkAlgorithmsDistfile__no_usual_algorithm(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileLines("category/package/distinfo",
		CvsID,
		"",
		"MD5 (package-1.0.txt) = 1234wrongHash1234")
	t.CreateFileLines("distfiles/package-1.0.txt",
		"hello, world")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"ERROR: ~/category/package/distinfo:3: " +
			"Expected SHA1, RMD160, SHA512, Size checksums for \"package-1.0.txt\", " +
			"got MD5.")
}

func (s *Suite) Test_distinfoLinesChecker_checkAlgorithmsDistfile__top_algorithms_missing(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileLines("category/package/distinfo",
		CvsID,
		"",
		"SHA512 (package-1.0.txt) = f65f341b35981fda842b09b2c8af9bcdb7602a4c2e6fa1f7"+
			"d41f0974d3e3122f268fc79d5a4af66358f5133885cd1c165c916f80ab25e5d8d95db46f803c782c",
		"Size (package-1.0.txt) = 13 bytes")
	t.CreateFileLines("distfiles/package-1.0.txt",
		"hello, world")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"ERROR: ~/category/package/distinfo:3: "+
			"Expected SHA1, RMD160, SHA512, Size checksums for \"package-1.0.txt\", "+
			"got SHA512, Size.",
		"ERROR: ~/category/package/distinfo:3: Missing SHA1 hash for package-1.0.txt.",
		"ERROR: ~/category/package/distinfo:3: Missing RMD160 hash for package-1.0.txt.")
}

func (s *Suite) Test_distinfoLinesChecker_checkAlgorithmsDistfile__bottom_algorithms_missing(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileLines("category/package/distinfo",
		CvsID,
		"",
		"SHA1 (package-1.0.txt) = cd50d19784897085a8d0e3e413f8612b097c03f1",
		"RMD160 (package-1.0.txt) = 1a88147a0344137404c63f3b695366eab869a98a")
	t.CreateFileLines("distfiles/package-1.0.txt",
		"hello, world")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"ERROR: ~/category/package/distinfo:3: "+
			"Expected SHA1, RMD160, SHA512, Size checksums for \"package-1.0.txt\", "+
			"got SHA1, RMD160.",
		"ERROR: ~/category/package/distinfo:4: Missing SHA512 hash for package-1.0.txt.",
		"ERROR: ~/category/package/distinfo:4: Missing Size hash for package-1.0.txt.")

	t.SetUpCommandLine("-Wall", "--autofix")

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"AUTOFIX: ~/category/package/distinfo:4: "+
			"Inserting a line \"SHA512 (package-1.0.txt) = f65f341b35981fda842b"+
			"09b2c8af9bcdb7602a4c2e6fa1f7d41f0974d3e3122f268fc79d5a4af66358f513"+
			"3885cd1c165c916f80ab25e5d8d95db46f803c782c\" below this line.",
		"AUTOFIX: ~/category/package/distinfo:4: "+
			"Inserting a line \"Size (package-1.0.txt) = 13 bytes\" below this line.")
}

func (s *Suite) Test_distinfoLinesChecker_checkAlgorithmsDistfile__algorithms_in_wrong_order(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileLines("category/package/distinfo",
		CvsID,
		"",
		"RMD160 (package-1.0.txt) = 1a88147a0344137404c63f3b695366eab869a98a",
		"SHA1 (package-1.0.txt) = cd50d19784897085a8d0e3e413f8612b097c03f1",
		"Size (package-1.0.txt) = 13 bytes",
		"SHA512 (package-1.0.txt) = f65f341b35981fda842b09b2c8af9bcdb7602a4c2e6fa1f7"+
			"d41f0974d3e3122f268fc79d5a4af66358f5133885cd1c165c916f80ab25e5d8d95db46f803c782c")

	t.CreateFileLines("distfiles/package-1.0.txt",
		"hello, world")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	// This case doesn't happen in practice, therefore there's no autofix for it.
	t.CheckOutputLines(
		"ERROR: ~/category/package/distinfo:3: " +
			"Expected SHA1, RMD160, SHA512, Size checksums for \"package-1.0.txt\", " +
			"got RMD160, SHA1, Size, SHA512.")
}

func (s *Suite) Test_distinfoLinesChecker_checkAlgorithmsDistfile__some_algorithms_in_wrong_order(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileLines("category/package/distinfo",
		CvsID,
		"",
		"RMD160 (package-1.0.txt) = 1a88147a0344137404c63f3b695366eab869a98a",
		"Size (package-1.0.txt) = 13 bytes",
		"SHA512 (package-1.0.txt) = f65f341b35981fda842b09b2c8af9bcdb7602a4c2e6fa1f7"+
			"d41f0974d3e3122f268fc79d5a4af66358f5133885cd1c165c916f80ab25e5d8d95db46f803c782c")

	t.CreateFileLines("distfiles/package-1.0.txt",
		"hello, world")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	// This case doesn't happen in practice, therefore there's no autofix for it.
	t.CheckOutputLines(
		"ERROR: ~/category/package/distinfo:3: "+
			"Expected SHA1, RMD160, SHA512, Size checksums for \"package-1.0.txt\", "+
			"got RMD160, Size, SHA512.",
		"ERROR: ~/category/package/distinfo:3: Missing SHA1 hash for package-1.0.txt.")
}

func (s *Suite) Test_distinfoLinesChecker_checkUnrecordedPatches(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.Chdir("category/package")
	t.CreateFileLines("patches/CVS/Entries")
	t.CreateFileDummyPatch("patches/patch-aa")
	t.CreateFileDummyPatch("patches/patch-src-Makefile")
	t.SetUpFileLines("distinfo",
		CvsID,
		"",
		"SHA1 (distfile.tar.gz) = ...",
		"RMD160 (distfile.tar.gz) = ...",
		"SHA512 (distfile.tar.gz) = ...",
		"Size (distfile.tar.gz) = 1024 bytes")
	t.FinishSetUp()

	G.checkdirPackage(".")

	t.CheckOutputLines(
		"WARN: distinfo:3: Distfiles without version number should be placed in a versioned DIST_SUBDIR.",
		"ERROR: distinfo: Patch \"patches/patch-aa\" is not recorded. Run \""+confMake+" makepatchsum\".",
		"ERROR: distinfo: Patch \"patches/patch-src-Makefile\" is not recorded. Run \""+confMake+" makepatchsum\".")
}

// When checking the complete pkgsrc tree, pkglint has all information it needs
// to check whether different packages use the same distfile but require
// different hashes for it.
//
// In such a case, typically one of the packages should put its distfiles into
// a DIST_SUBDIR.
func (s *Suite) Test_distinfoLinesChecker_checkGlobalDistfileMismatch(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.SetUpPackage("category/package1")
	t.SetUpPackage("category/package2")
	t.CreateFileLines("category/package1/distinfo",
		CvsID,
		"",
		"SHA512 (distfile-1.0.tar.gz) = 1234567811111111",
		"SHA512 (distfile-1.1.tar.gz) = 1111111111111111",
		"SHA512 (patch-4.2.tar.gz) = 1234567812345678")
	t.CreateFileLines("category/package2/distinfo",
		CvsID,
		"",
		"SHA512 (distfile-1.0.tar.gz) = 1234567822222222",
		"SHA512 (distfile-1.1.tar.gz) = 1111111111111111",
		"SHA512 (encoding-error.tar.gz) = 12345678abcdefgh")
	t.CreateFileLines("Makefile",
		MkCvsID,
		"",
		"COMMENT=\tThis is pkgsrc",
		"",
		"SUBDIR+=\tcategory")
	t.CreateFileLines("category/Makefile",
		MkCvsID,
		"",
		"COMMENT=\tUseful programs",
		"",
		"SUBDIR+=\tpackage1",
		"SUBDIR+=\tpackage2",
		"",
		".include \"../mk/misc/category.mk\"")

	t.Main("-r", "-Wall", "-Call", ".")

	t.CheckOutputLines(
		"ERROR: ~/category/package1/distinfo:3: "+
			"Expected SHA1, RMD160, SHA512, Size checksums for \"distfile-1.0.tar.gz\", got SHA512.",
		"ERROR: ~/category/package1/distinfo:4: "+
			"Expected SHA1, RMD160, SHA512, Size checksums for \"distfile-1.1.tar.gz\", got SHA512.",
		"ERROR: ~/category/package1/distinfo:5: "+
			"Expected SHA1, RMD160, SHA512, Size checksums for \"patch-4.2.tar.gz\", got SHA512.",

		"ERROR: ~/category/package2/distinfo:3: "+
			"Expected SHA1, RMD160, SHA512, Size checksums for \"distfile-1.0.tar.gz\", got SHA512.",
		"ERROR: ~/category/package2/distinfo:3: "+
			"The SHA512 hash for distfile-1.0.tar.gz is 1234567822222222, "+
			"which conflicts with 1234567811111111 in ../../category/package1/distinfo:3.",
		"ERROR: ~/category/package2/distinfo:4: "+
			"Expected SHA1, RMD160, SHA512, Size checksums for \"distfile-1.1.tar.gz\", got SHA512.",
		"ERROR: ~/category/package2/distinfo:5: "+
			"Expected SHA1, RMD160, SHA512, Size checksums for \"encoding-error.tar.gz\", got SHA512.",
		"ERROR: ~/category/package2/distinfo:5: "+
			"The SHA512 hash for encoding-error.tar.gz contains a non-hex character.",

		"WARN: ~/licenses/gnu-gpl-v2: This license seems to be unused.",
		"8 errors and 1 warning found.",
		t.Shquote("(Run \"pkglint -e -r -Wall -Call %s\" to show explanations.)", "."))

	// Ensure that hex.DecodeString does not waste memory here.
	t.CheckEquals(len(G.InterPackage.hashes["SHA512:distfile-1.0.tar.gz"].hash), 8)
	t.CheckEquals(cap(G.InterPackage.hashes["SHA512:distfile-1.0.tar.gz"].hash), 8)
}

func (s *Suite) Test_distinfoLinesChecker_checkUncommittedPatch__bad(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.Chdir("category/package")
	t.CreateFileDummyPatch("patches/patch-aa")
	t.CreateFileLines("CVS/Entries",
		"/distinfo//modified//")
	t.SetUpFileLines("distinfo",
		CvsID,
		"",
		"SHA1 (patch-aa) = ebbf34b0641bcb508f17d5a27f2bf2a536d810ac")
	t.FinishSetUp()

	G.checkdirPackage(".")

	t.CheckOutputLines(
		"WARN: distinfo:3: patches/patch-aa is registered in distinfo but not added to CVS.")
}

func (s *Suite) Test_distinfoLinesChecker_checkUncommittedPatch__good(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.Chdir("category/package")
	t.CreateFileDummyPatch("patches/patch-aa")
	t.CreateFileLines("CVS/Entries",
		"/distinfo//modified//")
	t.CreateFileLines("patches/CVS/Entries",
		"/patch-aa//modified//")
	t.SetUpFileLines("distinfo",
		CvsID,
		"",
		"SHA1 (patch-aa) = ebbf34b0641bcb508f17d5a27f2bf2a536d810ac")
	t.FinishSetUp()

	G.checkdirPackage(".")

	t.CheckOutputEmpty()
}

// The distinfo file and the patches are usually placed in the package
// directory. By defining PATCHDIR or DISTINFO_FILE, a package can define
// that they are somewhere else in pkgsrc.
func (s *Suite) Test_distinfoLinesChecker_checkPatchSha1__relative_path_in_distinfo(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"DISTINFO_FILE=\t../../other/common/distinfo",
		"PATCHDIR=\t../../devel/patches/patches")
	t.Remove("category/package/distinfo")
	t.CreateFileLines("devel/patches/patches/CVS/Entries")
	t.CreateFileDummyPatch("devel/patches/patches/patch-aa")
	t.CreateFileDummyPatch("devel/patches/patches/patch-only-in-patches")
	t.SetUpFileLines("other/common/distinfo",
		CvsID,
		"",
		"SHA1 (patch-aa) = ...",
		"SHA1 (patch-only-in-distinfo) = ...")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.checkdirPackage(".")

	t.CheckOutputLines(
		"ERROR: ../../other/common/distinfo:3: SHA1 hash of ../../devel/patches/patches/patch-aa differs "+
			"(distinfo has ..., patch file has ebbf34b0641bcb508f17d5a27f2bf2a536d810ac).",
		"WARN: ../../other/common/distinfo:4: Patch file \"patch-only-in-distinfo\" "+
			"does not exist in directory \"../../devel/patches/patches\".",
		"ERROR: ../../other/common/distinfo: Patch \"../../devel/patches/patches/patch-only-in-patches\" "+
			"is not recorded. Run \""+confMake+" makepatchsum\".")
}

func (s *Suite) Test_distinfoLinesChecker_checkPatchSha1(c *check.C) {
	t := s.Init(c)

	pkg := NewPackage(t.File("category/package"))
	distinfoLine := t.NewLine(t.File("category/package/distinfo"), 5, "")

	checker := distinfoLinesChecker{pkg, nil, "", false, nil, nil}
	checker.checkPatchSha1(distinfoLine, "patch-nonexistent", "distinfo-sha1")

	t.CheckOutputLines(
		"ERROR: ~/category/package/distinfo:5: Patch patch-nonexistent does not exist.")
}
