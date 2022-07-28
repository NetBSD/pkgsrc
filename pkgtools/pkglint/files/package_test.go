package pkglint

import (
	"gopkg.in/check.v1"
	"os"
	"sort"
	"strings"
)

func (s *Suite) Test_Package__varuse_at_load_time(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.SetUpTool("printf", "", AtRunTime)
	t.CreateFileLines("licenses/2-clause-bsd",
		"# dummy")
	t.CreateFileLines("category/Makefile")
	t.CreateFileLines("mk/tools/defaults.mk",
		"TOOLS_CREATE+=false",
		"TOOLS_CREATE+=nice",
		"TOOLS_CREATE+=true",
		"_TOOLS_VARNAME.nice=NICE")
	t.CreateFileLines("category/pkgbase/DESCR",
		"Description")

	t.CreateFileLines("category/pkgbase/Makefile",
		MkCvsID,
		"",
		"PKGNAME=\tloadtime-vartest-1.0",
		"CATEGORIES=\tcategory",
		"",
		"COMMENT=\tDemonstrate variable values during parsing",
		"LICENSE=\t2-clause-bsd",
		"",
		"PLIST_SRC=\t# none",
		"NO_CHECKSUM=\tyes",
		"NO_CONFIGURE=\tyes",
		"",
		"USE_TOOLS+=\techo false",
		"FALSE_BEFORE!=\techo false=${FALSE:Q}", // false=
		"NICE_BEFORE!=\techo nice=${NICE:Q}",    // nice=
		"TRUE_BEFORE!=\techo true=${TRUE:Q}",    // true=
		//
		// All three variables above are empty since the tool
		// variables are initialized by bsd.prefs.mk. The variables
		// from share/mk/sys.mk are available, though.
		//
		"",
		".include \"../../mk/bsd.prefs.mk\"",
		//
		// At this point, all tools from USE_TOOLS are defined with their variables.
		// ${FALSE} works, but a plain "false" might call the wrong tool.
		// That's because the tool wrappers are not set up yet. This
		// happens between the post-depends and pre-fetch stages. Even
		// then, the plain tool names may only be used in the
		// {pre,do,post}-* targets, since a recursive make(1) needs to be
		// run to set up the correct PATH.
		//
		"",
		"USE_TOOLS+=\tnice",
		//
		// The "nice" tool will only be available as ${NICE} after bsd.pkg.mk
		// has been included. Even including bsd.prefs.mk another time does
		// not have any effect since it is guarded against multiple inclusion.
		//
		"",
		".include \"../../mk/bsd.prefs.mk\"", // Has no effect.
		"",
		"FALSE_AFTER!=\techo false=${FALSE:Q}", // false=false
		"NICE_AFTER!=\techo nice=${NICE:Q}",    // nice=
		"TRUE_AFTER!=\techo true=${TRUE:Q}",    // true=true
		"",
		"do-build:",
		"\t${RUN} printf 'before:  %-20s  %-20s  %-20s\\n' ${FALSE_BEFORE} ${NICE_BEFORE} ${TRUE_BEFORE}",
		"\t${RUN} printf 'after:   %-20s  %-20s  %-20s\\n' ${FALSE_AFTER} ${NICE_AFTER} ${TRUE_AFTER}",
		"\t${RUN} printf 'runtime: %-20s  %-20s  %-20s\\n' false=${FALSE:Q} nice=${NICE:Q} true=${TRUE:Q}",
		"",
		".include \"../../mk/bsd.pkg.mk\"")

	t.SetUpCommandLine("-q", "-Wall")
	t.FinishSetUp()

	G.Check(t.File("category/pkgbase"))

	t.CheckOutputLines(
		"NOTE: ~/category/pkgbase/Makefile:14: Consider the :sh modifier instead of != for \"echo false=${FALSE:Q}\".",
		"WARN: ~/category/pkgbase/Makefile:14: To use the tool ${FALSE} at load time, bsd.prefs.mk has to be included before.",
		"NOTE: ~/category/pkgbase/Makefile:15: Consider the :sh modifier instead of != for \"echo nice=${NICE:Q}\".",

		// TODO: replace "at load time" with "before including bsd.prefs.mk in line ###".
		// TODO: ${NICE} could be used at load time if it were added to USE_TOOLS earlier.
		"WARN: ~/category/pkgbase/Makefile:15: The tool ${NICE} cannot be used at load time.",

		"NOTE: ~/category/pkgbase/Makefile:16: Consider the :sh modifier instead of != for \"echo true=${TRUE:Q}\".",
		"WARN: ~/category/pkgbase/Makefile:16: To use the tool ${TRUE} at load time, bsd.prefs.mk has to be included before.",
		"NOTE: ~/category/pkgbase/Makefile:24: Consider the :sh modifier instead of != for \"echo false=${FALSE:Q}\".",
		"NOTE: ~/category/pkgbase/Makefile:25: Consider the :sh modifier instead of != for \"echo nice=${NICE:Q}\".",
		"WARN: ~/category/pkgbase/Makefile:25: The tool ${NICE} cannot be used at load time.",
		"NOTE: ~/category/pkgbase/Makefile:26: Consider the :sh modifier instead of != for \"echo true=${TRUE:Q}\".")
}

func (s *Suite) Test_Package__relative_included_filenames_in_same_directory(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"PKGNAME=\tpkgname-1.67",
		"DISTNAME=\tdistfile_1_67",
		".include \"../../category/package/other.mk\"")
	t.CreateFileLines("category/package/other.mk",
		MkCvsID,
		"PKGNAME=\tpkgname-1.67",
		"DISTNAME=\tdistfile_1_67",
		".include \"../../category/package/other.mk\"")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	// TODO: Since other.mk is referenced via "../../category/package",
	//  it would be nice if this relative path would be reflected in the output
	//  instead of referring just to "other.mk".
	//  This needs to be fixed somewhere near Relpath.
	//
	// The notes are in reverse order because they are produced when checking
	// other.mk, and there the relative order is correct (line 2 before line 3).
	t.CheckOutputLines(
		"NOTE: ~/category/package/Makefile:4: "+
			"Definition of PKGNAME is redundant because of other.mk:2.",
		"NOTE: ~/category/package/Makefile:3: "+
			"Definition of DISTNAME is redundant because of other.mk:3.")
}

func (s *Suite) Test_Package__using_common_Makefile_overriding_DISTINFO_FILE(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("security/pinentry")
	t.CreateFileLines("security/pinentry/Makefile.common",
		MkCvsID,
		"DISTINFO_FILE=\t${.CURDIR}/../../security/pinentry/distinfo")
	t.SetUpPackage("security/pinentry-fltk",
		".include \"../../security/pinentry/Makefile.common\"",
		"DISTINFO_FILE=\t${.CURDIR}/distinfo")
	t.CreateFileDummyPatch("security/pinentry-fltk/patches/patch-aa")
	t.CreateFileLines("security/pinentry-fltk/distinfo",
		CvsID,
		"",
		"SHA1 (patch-aa) = 9a93207561abfef7e7550598c5a08f2c3226995b")
	t.FinishSetUp()

	G.Check(t.File("security/pinentry"))

	t.CheckOutputEmpty()

	G.Check(t.File("security/pinentry-fltk"))

	// The DISTINFO_FILE definition from pinentry-fltk overrides
	// the one from pinentry since it appears later.
	// Therefore the patch is searched for at the right location.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package__redundant_variable_in_unrelated_files(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("databases/py-trytond-ldap-authentication",
		".include \"../../devel/py-trytond/Makefile.common\"",
		".include \"../../lang/python/egg.mk\"")
	t.CreateFileLines("devel/py-trytond/Makefile.common",
		MkCvsID,
		"PY_PATCHPLIST=\tyes")
	t.CreateFileLines("lang/python/egg.mk",
		MkCvsID,
		"PY_PATCHPLIST=\tyes")
	t.FinishSetUp()

	G.Check(t.File("databases/py-trytond-ldap-authentication"))

	// Since egg.mk and Makefile.common are unrelated, the definition of
	// PY_PATCHPLIST is not redundant in these files.
	t.CheckOutputEmpty()
}

// As of April 2019, there are only a few files in the whole pkgsrc tree
// that are called Makefile.*, except Makefile.common, which occurs more
// often.
//
// Using the file extension for variants of that Makefile is confusing,
// therefore they should be renamed to *.mk.
func (s *Suite) Test_Package__Makefile_files(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileLines("category/package/Makefile.common",
		MkCvsID)
	t.CreateFileLines("category/package/Makefile.orig",
		MkCvsID)
	t.CreateFileLines("category/package/Makefile.php",
		MkCvsID)
	t.CreateFileLines("category/package/ext.mk",
		MkCvsID)
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	// No warning for the Makefile.orig since the package is not
	// being imported at the moment; see Pkglint.checkReg.
	t.CheckOutputLines(
		"NOTE: ~/category/package/Makefile.php: " +
			"Consider renaming \"Makefile.php\" to \"php.mk\".")
}

func (s *Suite) Test_Package__patch_in_FILESDIR(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "-Call")
	t.SetUpPackage("category/package")
	t.CreateFileLines("category/package/files/patch-aa",
		"This file can contain anything, no matter what the filename says.")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	// No warnings. The files in FILESDIR are independent of pkgsrc
	// and may contain anything. There are no naming conventions or
	// anything else.
	t.CheckOutputEmpty()
}

// See https://mail-index.netbsd.org/tech-pkg/2018/07/22/msg020092.html
func (s *Suite) Test_Package__redundant_master_sites(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.SetUpMasterSite("MASTER_SITE_R_CRAN", "http://cran.r-project.org/src/")
	t.CreateFileLines("math/R/Makefile.extension",
		MkCvsID,
		"",
		"PKGNAME?=\tR-${R_PKGNAME}-${R_PKGVER}",
		"MASTER_SITES?=\t${MASTER_SITE_R_CRAN:=contrib/}",
		"GENERATE_PLIST+=\techo \"bin/r-package\";",
		"NO_CHECKSUM=\tyes",
		"LICENSE?=\tgnu-gpl-v2")
	t.CreateFileLines("math/R-date/Makefile",
		MkCvsID,
		"",
		"R_PKGNAME=\tdate",
		"R_PKGVER=\t1.2.3",
		"COMMENT=\tR package for handling date arithmetic",
		"MASTER_SITES=\t${MASTER_SITE_R_CRAN:=contrib/}", // Redundant; see math/R/Makefile.extension.
		"",
		".include \"../../math/R/Makefile.extension\"",
		".include \"../../mk/bsd.pkg.mk\"")
	t.CreateFileLines("math/R-date/DESCR",
		"Description")
	t.FinishSetUp()

	// See Package.checkfilePackageMakefile
	G.checkdirPackage(t.File("math/R-date"))

	// The definition in Makefile:6 is redundant because the same definition
	// occurs later in Makefile.extension:4.
	//
	// When a file includes another file, it's always the including file that
	// is marked as redundant since the included file typically provides the
	// generally useful value for several packages;
	// see RedundantScope.handleVarassign, keyword includePath.
	t.CheckOutputLines(
		"NOTE: ~/math/R-date/Makefile:6: " +
			"Definition of MASTER_SITES is redundant " +
			"because of ../../math/R/Makefile.extension:4.")
}

// Before 2018-09-09, the .CURDIR variable did not have a fallback value.
// When resolving the relative path x11/gst-x11/${.CURDIR}/../../multimedia/gst-base/distinfo,
// "gst-x11/${.CURDIR}" was interpreted as "category/package", and the whole
// path was resolved to "x11/multimedia/gst-base/distinfo, which of course
// could not be found.
func (s *Suite) Test_Package__distinfo_from_other_package(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.Chdir(".")
	t.CreateFileLines("x11/gst-x11/Makefile",
		MkCvsID,
		".include \"../../multimedia/gst-base/Makefile.common\"",
		".include \"../../mk/bsd.pkg.mk\"")
	t.CreateFileDummyPatch("x11/gst-x11/patches/patch-aa")
	t.CreateFileLines("multimedia/gst-base/Makefile.common",
		MkCvsID,
		".include \"plugins.mk\"")
	t.CreateFileLines("multimedia/gst-base/plugins.mk",
		MkCvsID,
		"DISTINFO_FILE=\t${.CURDIR}/../../multimedia/gst-base/distinfo")
	t.CreateFileLines("multimedia/gst-base/distinfo",
		CvsID,
		"",
		"SHA1 (patch-aa) = 1234")
	t.FinishSetUp()

	G.Check("x11/gst-x11")

	t.CheckOutputLines(
		"WARN: x11/gst-x11/Makefile: This package should have a PLIST file.",
		"ERROR: x11/gst-x11/Makefile: Each package must define its LICENSE.",
		"WARN: x11/gst-x11/Makefile: Each package should define a COMMENT.",
		"ERROR: x11/gst-x11/../../multimedia/gst-base/distinfo:3: "+
			"SHA1 hash of ../../x11/gst-x11/patches/patch-aa differs "+
			"(distinfo has 1234, patch file has 9a93207561abfef7e7550598c5a08f2c3226995b).",
		"ERROR: x11/gst-x11/Makefile: Each package must have a DESCR file.")
}

func (s *Suite) Test_Package__case_insensitive(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.SetUpPackage("net/p5-Net-DNS")
	t.SetUpPackage("category/package",
		"DEPENDS+=\tp5-Net-DNS>=0:../../net/p5-net-dns")
	t.FinishSetUp()

	// this test is only interesting on a case-insensitive filesystem
	if !t.File("mk/BSD.PKG.MK").IsFile() {
		return
	}

	G.Check(t.File("category/package"))

	// TODO: On a case-sensitive filesystem, p5-net-dns would not be found.
	t.CheckOutputEmpty()
}

// This package has several identifiers that all differ:
//  - it lives in the directory "package"
//  - the package name is "pkgname"
//  - it downloads "distname-1.0.tar.gz"
//    (in some places the distname is used as the package name)
//  - in options.mk its name is "optid"
//  - in buildlink3.mk its name is "bl3id"
// All these identifiers should ideally be the same.
// For historic reasons, the package directory and the package name
// may differ.
func (s *Suite) Test_Package__different_package_identifiers(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"DISTNAME=\tdistname-1.0",
		"PKGNAME=\tpkgname-1.0")
	t.CreateFileLines("mk/bsd.options.mk")
	t.CreateFileLines("category/package/options.mk",
		MkCvsID,
		"",
		"PKG_OPTIONS_VAR=\tPKG_OPTIONS.optid",
		"PKG_SUPPORTED_OPTIONS=\t# none",
		"",
		".include \"../../mk/bsd.options.mk\"",
		"",
		"# Nothing to do here")
	t.CreateFileBuildlink3Id("category/package/buildlink3.mk", "bl3id")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.checkdirPackage(".")

	t.CheckOutputLines(
		"ERROR: buildlink3.mk:3: Package name mismatch "+
			"between \"bl3id\" in this file and \"pkgname\" from Makefile:4.",
		"WARN: options.mk:3: The buildlink3 identifier \"bl3id\" "+
			"should be the same as the options identifier \"optid\".")

}

func (s *Suite) Test_NewPackage(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("category/Makefile",
		MkCvsID)
	t.FinishSetUp()

	t.ExpectAssert(func() { NewPackage("category") })
}

func (s *Suite) Test_Package_load__variable_from_Makefile_used_in_builtin_mk(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("devel/binutils",
		"BINUTILS_PREFIX=\t${PREFIX}/${MACHINE_GNU_PLATFORM}")
	t.CreateFileLines("devel/binutils/builtin.mk",
		MkCvsID,
		".include \"../../mk/bsd.prefs.mk\"",
		"BINUTILS_PREFIX?=\t/usr",
		"",
		"BUILTIN_FIND_FILES.BINUTILS_FILES:=\t${BINUTILS_PREFIX}/include/bfd.h")
	t.FinishSetUp()

	G.Check(t.File("devel/binutils"))

	// The BINUTILS_PREFIX from the Makefile is not used since the
	// builtin.mk file is only parsed inside of buildlink3.mk, and
	// that doesn't happen for the package itself, but only for those
	// packages that depend on this package.
	t.CheckOutputLines(
		"WARN: ~/devel/binutils/Makefile:20: " +
			"BINUTILS_PREFIX is defined but not used.")
}

func (s *Suite) Test_Package_load__buildlink3_mk_includes_other_mk(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--explain")
	t.SetUpPackage("multimedia/libav")
	t.CreateFileBuildlink3("multimedia/libav/buildlink3.mk",
		".include \"available.mk\"")
	t.CreateFileLines("multimedia/libav/available.mk",
		MkCvsID,
		"",
		"LIBAV_AVAILABLE=\tno")
	t.FinishSetUp()

	G.Check(t.File("multimedia/libav"))

	// From looking at the file available.mk alone, this variable looks
	// unused indeed, but its intention is to be used by other packages.
	// The explanation has a large paragraph covering exactly this case,
	// therefore the warning is ok.
	t.CheckOutputLines(
		"WARN: ~/multimedia/libav/available.mk:3: "+
			"LIBAV_AVAILABLE is defined but not used.",
		"",
		"\tThis might be a simple typo.",
		"",
		"\tIf a package provides a file containing several related variables",
		"\t(such as module.mk, app.mk, extension.mk), that file may define",
		"\tvariables that look unused since they are only used by other",
		"\tpackages. These variables should be documented at the head of the",
		"\tfile; see mk/subst.mk for an example of such a documentation",
		"\tcomment.",
		"")
}

// Demonstrates that Makefile fragments are handled differently,
// depending on the directory they are in.
func (s *Suite) Test_Package_load__extra_files(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"PKGDIR=\t../../category/other")
	t.SetUpPackage("category/other")
	t.Chdir("category/package")
	t.CreateFileLines("gnu-style.mk",
		"ifeq ($(CC),gcc)",
		"IS_GCC=\tyes",
		"else",
		"IS_GCC=\tno",
		"endif")
	t.CreateFileLines("patches/patch-Makefile.mk",
		CvsID,
		"",
		"Documentation",
		"",
		"--- Makefile.mk.orig",
		"--- Makefile.mk",
		"@@ -1,1 +1,1 @@",
		"- old",
		"+ new")
	t.CreateFileLines("patches/readme.mk", // Is ignored
		"This is not a BSD-style Makefile.")
	t.Copy("gnu-style.mk", "files/gnu-style.mk")
	t.Copy("gnu-style.mk", "../../category/other/gnu-style.mk")

	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		// All *.mk files in the package directory are assumed
		// to be BSD-style Makefiles, therefore the many warnings.
		"WARN: gnu-style.mk:1: Please use curly braces {} instead of round parentheses () for CC.",
		"ERROR: gnu-style.mk:1: Unknown Makefile line format: \"ifeq ($(CC),gcc)\".",
		"ERROR: gnu-style.mk:3: Unknown Makefile line format: \"else\".",
		"ERROR: gnu-style.mk:5: Unknown Makefile line format: \"endif\".",

		"ERROR: distinfo: Patch \"patches/patch-Makefile.mk\" is not recorded. Run \""+confMake+" makepatchsum\".",

		// The following diagnostics are duplicated because the files from
		// the package directory are loaded once during Package.load, just
		// for collecting the used variables. And then a second time in
		// Package.check to perform the actual checks.
		//
		// The above diagnostics are only those from parsing the file, to
		// correctly classify the lines. This is because the main purpose
		// of Package.load above is to load the files and collect some
		// data, not to perform the actual checks.
		//
		// Therefore, the below lines contain two more diagnostics.
		"WARN: gnu-style.mk:1: Please use curly braces {} instead of round parentheses () for CC.",
		"ERROR: gnu-style.mk:1: Unknown Makefile line format: \"ifeq ($(CC),gcc)\".",
		"ERROR: gnu-style.mk:3: Unknown Makefile line format: \"else\".",
		"ERROR: gnu-style.mk:5: Unknown Makefile line format: \"endif\".",
		"ERROR: gnu-style.mk:1: Expected \""+MkCvsID+"\".",
		"WARN: gnu-style.mk:2: IS_GCC is defined but not used.",
		"WARN: gnu-style.mk:2: Variable IS_GCC is overwritten in line 4.",

		// There is no warning about files/gnu-style.mk since pkglint
		// doesn't even attempt at guessing the file type. Files placed
		// in this directory can have an arbitrary format.

		"ERROR: ../../category/other/distinfo: Patch \"../../category/package/patches/"+
			"patch-Makefile.mk\" is not recorded. Run \""+confMake+" makepatchsum\".",

		// All *.mk files from PKGDIR are loaded to see which variables
		// they define, in order to make the check for unused variables
		// more reliable.
		//
		// All files that belong to the package itself, and not to pkgsrc
		// should therefore be placed in the files/ directory.
		"WARN: ../../category/other/gnu-style.mk:1: "+
			"Please use curly braces {} instead of round parentheses () for CC.",
		"ERROR: ../../category/other/gnu-style.mk:1: Unknown Makefile line format: \"ifeq ($(CC),gcc)\".",
		"ERROR: ../../category/other/gnu-style.mk:3: Unknown Makefile line format: \"else\".",
		"ERROR: ../../category/other/gnu-style.mk:5: Unknown Makefile line format: \"endif\".",
		"ERROR: ../../category/other/gnu-style.mk:1: Expected \""+MkCvsID+"\".",
		"WARN: ../../category/other/gnu-style.mk:2: IS_GCC is defined but not used.",
		"WARN: ../../category/other/gnu-style.mk:2: Variable IS_GCC is overwritten in line 4.",

		"ERROR: patches/patch-Makefile.mk: Contains no patch.",
		"WARN: patches/readme.mk: Patch files should be named \"patch-\", followed by letters, '-', '_', '.', and digits only.")
}

func (s *Suite) Test_Package_loadBuildlink3Pkgbase(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".include \"../../category/lib/buildlink3.mk\"")
	t.CreateFileBuildlink3("category/package/buildlink3.mk",
		"pkgbase := package",
		".include \"../../mk/pkg-build-options.mk\"",
		".include \"../../category/lib/buildlink3.mk\"")
	t.SetUpPackage("category/lib")
	t.CreateFileBuildlink3("category/lib/buildlink3.mk",
		"pkgbase := lib",
		".include \"../../mk/pkg-build-options.mk\"")
	t.CreateFileLines("mk/pkg-build-options.mk")
	t.Chdir("category/package")
	t.FinishSetUp()
	pkg := NewPackage(".")

	pkg.Check()

	t.CheckOutputEmpty()
	seenPkgbase := pkg.seenPkgbase
	t.CheckLen(seenPkgbase.seen, 2)
	t.CheckEquals(seenPkgbase.Seen("lib"), true)
	t.CheckEquals(seenPkgbase.Seen("package"), true)
}

func (s *Suite) Test_Package_loadPackageMakefile__dump(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--dumpmakefile")
	t.SetUpPkgsrc()
	t.CreateFileLines("category/Makefile")
	t.CreateFileLines("category/package/DESCR",
		"Description")
	t.CreateFileLines("category/package/PLIST",
		PlistCvsID,
		"bin/program")
	t.CreateFileLines("category/package/distinfo",
		CvsID,
		"",
		"BLAKE2s (distfile-1.0.tar.gz) = 12341234...",
		"SHA512 (distfile-1.0.tar.gz) = 12341234...",
		"Size (distfile-1.0.tar.gz) = 12341234...")
	t.CreateFileLines("category/package/Makefile",
		MkCvsID,
		"",
		"DISTNAME=\tpackage-1.0",
		"CATEGORIES=\tcategory",
		"",
		"COMMENT=\tComment",
		"LICENSE=\t2-clause-bsd")
	// TODO: There is no .include line at the end of the Makefile.
	//  This should always be checked though.
	t.FinishSetUp()

	G.checkdirPackage(t.File("category/package"))

	t.CheckOutputLines(
		"Whole Makefile (with all included files) follows:",
		"~/category/package/Makefile:1: "+MkCvsID,
		"~/category/package/Makefile:2: ",
		"~/category/package/Makefile:3: DISTNAME=\tpackage-1.0",
		"~/category/package/Makefile:4: CATEGORIES=\tcategory",
		"~/category/package/Makefile:5: ",
		"~/category/package/Makefile:6: COMMENT=\tComment",
		"~/category/package/Makefile:7: LICENSE=\t2-clause-bsd")
}

func (s *Suite) Test_Package_loadPackageMakefile(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("category/package/Makefile",
		MkCvsID,
		"",
		"PKGNAME=pkgname-1.67",
		"DISTNAME=distfile_1_67",
		".include \"../../category/package/Makefile\"")
	pkg := NewPackage(t.File("category/package"))

	pkg.loadPackageMakefile()

	// Including a package Makefile directly is an error (in the last line),
	// but that is checked later.
	// This test demonstrates that a file including itself does not lead to an
	// endless loop while parsing. It might trigger an error in the future.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_loadPackageMakefile__PECL_VERSION(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("lang/php/ext.mk",
		MkCvsID,
		"",
		"PHPEXT_MK=      # defined",
		"PHPPKGSRCDIR=   ../../lang/php72",
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
	pkg := t.SetUpPackage("category/package",
		"PECL_VERSION=\t1.1.2",
		".include \"../../lang/php/ext.mk\"")
	t.FinishSetUp()

	G.Check(pkg)
}

// Pkglint loads some files from the pkgsrc infrastructure and skips others.
//
// When a buildlink3.mk file from the infrastructure is included, it should
// be allowed to include its corresponding builtin.mk file in turn.
//
// This is necessary to load the correct variable assignments for the
// redundancy check, in particular variable assignments that serve as
// arguments to "procedure calls", such as mk/find-files.mk.
func (s *Suite) Test_Package_parse__include_infrastructure(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--dumpmakefile")
	t.SetUpPackage("category/package",
		".include \"../../mk/dlopen.buildlink3.mk\"",
		".include \"../../mk/pthread.buildlink3.mk\"")
	t.CreateFileLines("mk/dlopen.buildlink3.mk",
		".include \"dlopen.builtin.mk\"")
	t.CreateFileLines("mk/dlopen.builtin.mk",
		".include \"pthread.builtin.mk\"")
	t.CreateFileLines("mk/pthread.buildlink3.mk",
		".include \"pthread.builtin.mk\"")
	t.CreateFileLines("mk/pthread.builtin.mk",
		"# This should be included by pthread.buildlink3.mk")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"Whole Makefile (with all included files) follows:",
		"~/category/package/Makefile:1: "+MkCvsID,
		"~/category/package/Makefile:2: ",
		"~/category/package/Makefile:3: DISTNAME=\tpackage-1.0",
		"~/category/package/Makefile:4: #PKGNAME=\tpackage-1.0",
		"~/category/package/Makefile:5: CATEGORIES=\tcategory",
		"~/category/package/Makefile:6: MASTER_SITES=\t# none",
		"~/category/package/Makefile:7: ",
		"~/category/package/Makefile:8: MAINTAINER=\tpkgsrc-users@NetBSD.org",
		"~/category/package/Makefile:9: HOMEPAGE=\t# none",
		"~/category/package/Makefile:10: COMMENT=\tDummy package",
		"~/category/package/Makefile:11: LICENSE=\t2-clause-bsd",
		"~/category/package/Makefile:12: ",
		"~/category/package/Makefile:13: .include \"suppress-varorder.mk\"",
		"~/category/package/suppress-varorder.mk:1: "+MkCvsID,
		"~/category/package/Makefile:14: ",
		"~/category/package/Makefile:15: # filler",
		"~/category/package/Makefile:16: # filler",
		"~/category/package/Makefile:17: # filler",
		"~/category/package/Makefile:18: # filler",
		"~/category/package/Makefile:19: ",
		"~/category/package/Makefile:20: .include \"../../mk/dlopen.buildlink3.mk\"",
		"~/category/package/../../mk/dlopen.buildlink3.mk:1: .include \"dlopen.builtin.mk\"",
		"~/mk/dlopen.builtin.mk:1: .include \"pthread.builtin.mk\"",
		"~/category/package/Makefile:21: .include \"../../mk/pthread.buildlink3.mk\"",
		"~/category/package/../../mk/pthread.buildlink3.mk:1: .include \"pthread.builtin.mk\"",
		"~/mk/pthread.builtin.mk:1: # This should be included by pthread.buildlink3.mk",
		"~/category/package/Makefile:22: ",
		"~/category/package/Makefile:23: .include \"../../mk/bsd.pkg.mk\"")
}

// See https://github.com/rillig/pkglint/issues/1
func (s *Suite) Test_Package_parse__include_without_exists(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".include \"options.mk\"")
	t.FinishSetUp()

	G.checkdirPackage(t.File("category/package"))

	t.CheckOutputLines(
		"ERROR: ~/category/package/Makefile:20: Cannot read \"options.mk\".")
}

// See https://github.com/rillig/pkglint/issues/1
func (s *Suite) Test_Package_parse__include_after_exists(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".if exists(options.mk)",
		".  include \"options.mk\"",
		".endif")
	t.FinishSetUp()

	G.checkdirPackage(t.File("category/package"))

	// No error message at all because of the .if exists before.
	t.CheckOutputEmpty()
}

// See https://github.com/rillig/pkglint/issues/1
func (s *Suite) Test_Package_parse__include_other_after_exists(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".if exists(options.mk)",
		".  include \"another.mk\"",
		".endif")
	t.FinishSetUp()

	G.checkdirPackage(t.File("category/package"))

	t.CheckOutputLines(
		"ERROR: ~/category/package/Makefile:21: Cannot read \"another.mk\".")
}

func (s *Suite) Test_Package_parse__simple(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.Chdir("category/package")
	t.FinishSetUp()

	pkg := NewPackage(".")
	pkg.included.Trace = true
	pkg.load()

	t.CheckOutputLines(
		"FirstTime: suppress-varorder.mk")
}

func (s *Suite) Test_Package_parse__nonexistent_Makefile(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.Chdir("category/package")
	t.Remove("Makefile")
	t.FinishSetUp()

	pkg := NewPackage(".")
	pkg.included.Trace = true
	pkg.load()

	t.CheckOutputLines(
		"ERROR: Makefile: Cannot be read.")
}

func (s *Suite) Test_Package_parse__include_in_same_directory(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".include \"version.mk\"")
	t.Chdir("category/package")
	t.CreateFileLines("version.mk",
		MkCvsID)
	t.FinishSetUp()

	pkg := NewPackage(".")
	pkg.included.Trace = true
	pkg.load()

	t.CheckOutputLines(
		"FirstTime: suppress-varorder.mk",
		"FirstTime: version.mk")
}

func (s *Suite) Test_Package_parse__nonexistent_include(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".include \"version.mk\"")
	t.Chdir("category/package")
	t.FinishSetUp()

	pkg := NewPackage(".")
	pkg.included.Trace = true
	pkg.load()

	t.CheckOutputLines(
		"FirstTime: suppress-varorder.mk",
		"FirstTime: version.mk",
		"ERROR: Makefile:20: Cannot read \"version.mk\".")
}

// When reading the package Makefile, pkglint loads and interprets each
// file only once. This is especially important for packages with a large
// dependency graph containing many common subdependencies.
func (s *Suite) Test_Package_parse__include_twice(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".include \"version.mk\"",
		".include \"version.mk\"")
	t.Chdir("category/package")
	t.CreateFileLines("version.mk",
		MkCvsID)
	t.FinishSetUp()

	pkg := NewPackage(".")
	pkg.included.Trace = true
	pkg.load()

	t.CheckOutputLines(
		"FirstTime: suppress-varorder.mk",
		"FirstTime: version.mk")
}

func (s *Suite) Test_Package_parse__include_in_other_directory(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".include \"../../category/other/version.mk\"")
	t.Chdir("category/package")
	t.CreateFileLines("../../category/other/version.mk",
		MkCvsID)
	t.FinishSetUp()

	pkg := NewPackage(".")
	pkg.included.Trace = true
	pkg.load()

	t.CheckOutputLines(
		"FirstTime: suppress-varorder.mk",
		"FirstTime: ../../category/other/version.mk")
}

// Demonstrates that Package.included contains the file paths of the
// included files, relative to the package directory.
func (s *Suite) Test_Package_parse__includes_in_other_directory(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".include \"../../category/other/module.mk\"")
	t.Chdir("category/package")
	t.CreateFileLines("../../category/other/module.mk",
		MkCvsID,
		".include \"version.mk\"")
	t.CreateFileLines("../../category/other/version.mk",
		MkCvsID)
	t.FinishSetUp()

	pkg := NewPackage(".")
	pkg.included.Trace = true
	pkg.load()

	t.CheckOutputLines(
		"FirstTime: suppress-varorder.mk",
		"FirstTime: ../../category/other/module.mk",
		"FirstTime: ../../category/other/version.mk")
}

func (s *Suite) Test_Package_parse__nonexistent_in_other_directory(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".include \"../../category/other/module.mk\"")
	t.Chdir("category/package")
	t.CreateFileLines("../../category/other/module.mk",
		MkCvsID,
		".include \"version.mk\"")
	t.FinishSetUp()

	pkg := NewPackage(".")
	pkg.included.Trace = true
	pkg.load()

	t.CheckOutputLines(
		"FirstTime: suppress-varorder.mk",
		"FirstTime: ../../category/other/module.mk",
		"FirstTime: ../../category/other/version.mk",
		"ERROR: ../../category/other/module.mk:2: Cannot read \"version.mk\".")
}

func (s *Suite) Test_Package_parse__skipping(c *check.C) {
	t := s.Init(c)

	pkg := t.SetUpPackage("category/package",
		".include \"${MYSQL_PKGSRCDIR:S/-client$/-server/}/buildlink3.mk\"")
	t.FinishSetUp()

	t.EnableTracingToLog()
	G.Check(pkg)
	t.EnableSilentTracing()

	// Since 2018-12-16 there is no warning or note anymore for the
	// buildlink3.mk file being skipped since it didn't help the average
	// pkglint user.

	// The information is still available in the trace log though.

	output := t.Output()
	var relevant []string
	for _, line := range strings.Split(output, "\n") {
		if contains(line, "Skipping unresolvable") {
			relevant = append(relevant, line)
		}
	}

	t.CheckDeepEquals(relevant, []string{
		"TRACE: 1 2 3 4   ~/category/package/Makefile:20: " +
			"Skipping unresolvable include file \"${MYSQL_PKGSRCDIR:S/-client$/-server/}/buildlink3.mk\"."})
}

func (s *Suite) Test_Package_parse__not_found(c *check.C) {
	t := s.Init(c)

	pkg := t.SetUpPackage("category/package",
		".include \"../../devel/zlib/buildlink3.mk\"")
	t.CreateFileLines("devel/zlib/buildlink3.mk",
		".include \"../../enoent/enoent/buildlink3.mk\"")
	t.FinishSetUp()

	G.checkdirPackage(pkg)

	t.CheckOutputLines(
		"ERROR: ~/devel/zlib/buildlink3.mk:1: Cannot read \"../../enoent/enoent/buildlink3.mk\".")
}

func (s *Suite) Test_Package_parse__relative(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("category/package/extra.mk",
		MkCvsID)
	pkg := t.SetUpPackage("category/package",
		".include \"../package/extra.mk\"")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:20: " +
			"References to other packages should look " +
			"like \"../../category/package\", not \"../package\".")
}

// When a buildlink3.mk file is included, the corresponding builtin.mk
// file is included by the pkgsrc infrastructure. Therefore all variables
// declared in the builtin.mk file become known in the package.
func (s *Suite) Test_Package_parse__builtin_mk(c *check.C) {
	t := s.Init(c)

	t.SetUpTool("echo", "ECHO", AtRunTime)
	t.SetUpPackage("category/package",
		".include \"../../category/lib1/buildlink3.mk\"",
		"",
		"show-var-from-builtin: .PHONY",
		"\techo ${VAR_FROM_BUILTIN} ${OTHER_VAR}")
	t.CreateFileBuildlink3("category/lib1/buildlink3.mk")
	t.CreateFileLines("category/lib1/builtin.mk",
		MkCvsID,
		"VAR_FROM_BUILTIN=\t# defined")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:23: Please use \"${ECHO}\" instead of \"echo\".",
		"WARN: ~/category/package/Makefile:23: OTHER_VAR is used but not defined.")
}

// Ensures that the paths in Package.included are indeed relative to the
// package directory. This hadn't been the case until March 2019.
func (s *Suite) Test_Package_parse__included(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".include \"../../devel/library/buildlink3.mk\"",
		".include \"../../lang/language/module.mk\"")
	t.SetUpPackage("devel/library")
	t.CreateFileBuildlink3("devel/library/buildlink3.mk")
	t.CreateFileLines("devel/library/builtin.mk",
		MkCvsID)
	t.CreateFileLines("lang/language/module.mk",
		MkCvsID,
		".include \"version.mk\"")
	t.CreateFileLines("lang/language/version.mk",
		MkCvsID)
	t.FinishSetUp()
	t.Chdir("category/package")
	pkg := NewPackage(".")

	pkg.included.Trace = true
	pkg.loadPackageMakefile()

	t.CheckOutputLines(
		"FirstTime: suppress-varorder.mk",
		"FirstTime: ../../devel/library/buildlink3.mk",
		"FirstTime: ../../devel/library/builtin.mk",
		"FirstTime: ../../lang/language/module.mk",
		"FirstTime: ../../lang/language/version.mk")
}

func (s *Suite) Test_Package_parse__include_Makefile_common_same_directory(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/dependency")
	t.CreateFileLines("category/dependency/Makefile.common",
		MkCvsID,
		"#",
		"#")
	t.SetUpPackage("category/package",
		".include \"../../category/dependency/Makefile.common\"",
		".include \"Makefile.common\"")
	t.CreateFileLines("category/package/Makefile.common",
		MkCvsID,
		"#",
		"#")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"WARN: ~/category/dependency/Makefile.common:1: " +
			"Please add a line \"# used by category/package/Makefile\" here.")
}

func (s *Suite) Test_Package_parse__include_Makefile_common_explicit(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/dependency")
	t.CreateFileLines("category/dependency/Makefile.common",
		MkCvsID,
		"#",
		"#")
	t.SetUpPackage("category/package",
		".include \"../../category/dependency/Makefile.common\"",
		".include \"../../category/package/Makefile.common\"")
	t.CreateFileLines("category/package/Makefile.common",
		MkCvsID,
		"#",
		"#")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"WARN: ~/category/dependency/Makefile.common:1: " +
			"Please add a line \"# used by category/package/Makefile\" here.")
}

func (s *Suite) Test_Package_parse__fallback_lookup_in_package_directory(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("mk/pthread.buildlink3.mk",
		MkCvsID,
		".include \"../../mk/pthread.builtin.mk\"")
	t.CreateFileLines("mk/pthread.builtin.mk",
		MkCvsID)
	t.SetUpPackage("category/package",
		".include \"../../mk/pthread.buildlink3.mk\"")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"WARN: ~/mk/pthread.buildlink3.mk:2: " +
			"The path to the included file should be \"pthread.builtin.mk\".")
}

func (s *Suite) Test_Package_loadIncluded__nested_inclusion(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("x11/kde-runtime4",
		".include \"../../x11/kde-libs4/buildlink3.mk\"")
	t.SetUpPackage("x11/kde-libs4")
	t.CreateFileBuildlink3("x11/kde-libs4/buildlink3.mk",
		".include \"../../databases/openldap/buildlink3.mk\"")
	t.SetUpPackage("databases/openldap")
	t.CreateFileBuildlink3("databases/openldap/buildlink3.mk",
		"VAR=\tvalue",
		"VAR=\tvalue") // Provoke a warning in this file.
	t.FinishSetUp()
	// Without this line, the current directory is an absolute directory,
	// and the pkgsrc top directory is as well. One of them prevents the
	// verbose paths from being generated.
	t.Chdir(".")

	G.Check("x11/kde-runtime4")

	// The first part of the path must be "x11/kde-runtime4" to easily
	// identify the package by which all other files are included.
	t.CheckOutputLines(
		"NOTE: x11/kde-runtime4/../../databases/openldap/buildlink3.mk:13: " +
			"Definition of VAR is redundant because of line 12.")
}

// Just for code coverage.
func (s *Suite) Test_Package_resolveIncludedFile__no_tracing(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".include \"../../mk/${UNKNOWN_PKGPATH}.mk\"",
		".include \"../../${UNKNOWN_PKGPATH}/buildlink3.mk\"",
		".include \"../../lang/language/buildlink3.mk\"")
	t.CreateFileLines("lang/language/buildlink3.mk",
		MkCvsID)
	t.FinishSetUp()
	pkg := NewPackage(t.File("category/package"))
	t.DisableTracing()

	pkg.included.Trace = true
	pkg.loadPackageMakefile()

	t.CheckOutputLines(
		"FirstTime: suppress-varorder.mk",
		"FirstTime: ../../lang/language/buildlink3.mk",
		"FirstTime: ../../lang/language/builtin.mk")
}

func (s *Suite) Test_Package_resolveIncludedFile__skipping(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".include \"../../mk/known.mk\"",
		".include \"../../${UNKNOWN_PKGPATH}/buildlink3.mk\"",
		".include \"../../lang/language/buildlink3.mk\"")
	t.CreateFileLines("mk/known.mk",
		MkCvsID,
		".include \"${UNKNOWN}.mk\"")
	t.CreateFileLines("lang/language/buildlink3.mk",
		MkCvsID)
	t.FinishSetUp()
	pkg := NewPackage(t.File("category/package"))

	t.EnableTracingToLog()
	pkg.loadPackageMakefile()

	// The trace log does not contain the message that mk/known.mk includes
	// a file that is skipped. This is because most package authors are not
	// involved in the pkgsrc infrastructure, therefore there's no point in
	// logging anything about these files.
	t.CheckOutputLinesMatching(`.*Skipping.*`,
		"TRACE: 1 2   ~/category/package/Makefile:21: "+
			"Skipping unresolvable include file \"../../${UNKNOWN_PKGPATH}/buildlink3.mk\".")
}

func (s *Suite) Test_Package_shouldDiveInto(c *check.C) {
	t := s.Init(c)
	t.Chdir("category/package")

	test := func(including CurrPath, included RelPath, expected bool) {
		pkg := NewPackage(".")
		actual := pkg.shouldDiveInto(including, included)
		t.CheckEquals(actual, expected)
	}

	// The variables that appear in these files are largely modeled by
	// pkglint in the file vardefs.go. Therefore parsing these files again
	// doesn't make much sense.
	test("Makefile", "../../mk/bsd.pkg.mk", false)
	test("Makefile", "../../mk/bsd.prefs.mk", false)
	test("Makefile", "../../mk/bsd.fast.prefs.mk", false)

	// All files that are included from outside of the pkgsrc infrastructure
	// are relevant. This is typically mk/compiler.mk or the various
	// mk/*.buildlink3.mk files.
	test("Makefile", "Makefile.common", true)
	test("Makefile", "../../mk/compiler.mk", true)

	// The mk/*.buildlink3.mk files often come with a companion file called
	// mk/*.builtin.mk, which also defines variables that are visible from
	// the package.
	//
	// This case is needed for getting the redundancy check right. Without it
	// there will be warnings about redundant assignments to the
	// BUILTIN_CHECK.pthread variable.
	test("pthread.buildlink3.mk", "pthread.builtin.mk", true)
	test("../../mk/pthread.buildlink3.mk", "pthread.builtin.mk", true)
	test("../../mk/pthread.buildlink3.mk", "../../mk/pthread.builtin.mk", true)

	// Files other than the companion builtin.mk are ignored.
	test("../../mk/pthread.buildlink3.mk", "pthread.internals.mk", false)

	// Files that are included from within the pkgsrc infrastructure are not
	// interesting since their content is largely modeled by pkglint in the
	// file vardefs.go.
	test("../../mk/one.mk", "two.mk", false)
	test("../../mk/one.mk", "../../mk/two.mk", false)
	test("../../mk/one.mk", "../lang/go/version.mk", false)

	// wip/mk doesn't count as infrastructure since it is often used as a
	// second layer, using the API of the main mk/ infrastructure.
	test("wip/mk/cargo-binary.mk", "../../lang/rust/cargo.mk", true)
}

func (s *Suite) Test_Package_collectSeenInclude__builtin_mk(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".include \"builtin.mk\"")
	t.CreateFileLines("category/package/builtin.mk",
		MkCvsID)
	t.FinishSetUp()

	pkg := NewPackage(t.File("category/package"))
	pkg.load()

	t.CheckEquals(pkg.seenInclude, true)
}

func (s *Suite) Test_Package_collectSeenInclude__multiple(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".include \"001.mk\"",
		".include \"002.mk\"")
	t.CreateFileLines("category/package/001.mk",
		MkCvsID)
	t.CreateFileLines("category/package/002.mk",
		MkCvsID)
	t.FinishSetUp()

	t.EnableTracingToLog()
	G.Check(t.File("category/package"))
	t.EnableSilentTracing()

	// TODO: It's not necessary to trace this message three times.
	t.CheckOutputLinesMatching(`^TRACE: .*seenInclude`,
		"TRACE: 1 2 3 4   Including \"suppress-varorder.mk\" sets seenInclude.",
		"TRACE: 1 2 3 4   Including \"001.mk\" sets seenInclude.",
		"TRACE: 1 2 3 4   Including \"002.mk\" sets seenInclude.")
}

// Just ensure that pkglint doesn't crash.
func (s *Suite) Test_Package_loadPlistDirs__empty(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileLines("category/package/PLIST.common",
		nil...)
	t.FinishSetUp()

	pkg := NewPackage(t.File("category/package"))
	pkg.load()

	var dirs []RelPath
	for dir := range pkg.Plist.UnconditionalDirs {
		dirs = append(dirs, dir)
	}
	sort.Slice(dirs, func(i, j int) bool { return dirs[i] < dirs[j] })

	t.CheckDeepEquals(dirs, []RelPath{"bin"}) // see t.SetUpPackage
}

func (s *Suite) Test_Package_loadPlistDirs(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileLines("category/package/PLIST.common",
		PlistCvsID,
		"@exec echo hello",
		"${PLIST.condition}dir/subdir/file",
		"${PLIST.condition}mixed/conditional-file",
		"mixed/unconditional-file",
		"@unexec echo bye")
	t.FinishSetUp()

	pkg := NewPackage(t.File("category/package"))
	pkg.load()

	var dirs []RelPath
	for dir := range pkg.Plist.UnconditionalDirs {
		dirs = append(dirs, dir)
	}
	sort.Slice(dirs, func(i, j int) bool { return dirs[i] < dirs[j] })

	t.CheckDeepEquals(dirs, []RelPath{
		"bin", // from t.SetUpPackage
		// dir is not listed because it is conditional.
		// dir/subdir is not listed because it is conditional.
		"mixed"})
}

func (s *Suite) Test_Package_check__files_Makefile(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileLines("category/package/files/Makefile",
		"This file may contain anything.")

	t.Main("category/package/files/Makefile")

	// Since there is nothing to check in files/*, pkglint could
	// as well report this as a usage error.
	//
	// Until June 2019, checking individual files in FILESDIR had
	// been enabled by the -Call command line option.
	t.CheckOutputLines(
		"Looks fine.")

	t.Main("category/package")

	t.CheckOutputLines(
		"Looks fine.")
}

func (s *Suite) Test_Package_check__patches_Makefile(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileLines("category/package/patches/Makefile",
		"This file may contain anything.")

	t.Main("category/package")

	t.CheckOutputLines(
		"WARN: ~/category/package/patches/Makefile: Patch files should be "+
			"named \"patch-\", followed by letters, '-', '_', '.', and digits only.",
		"1 warning found.")
}

func (s *Suite) Test_Package_check__redundant_WRKSRC(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"WRKSRC=\t${WRKDIR}/package-1.0")

	t.Main("-q", "category/package")

	t.CheckOutputLines(
		"NOTE: ~/category/package/Makefile:20: " +
			"Setting WRKSRC to \"${WRKDIR}/package-1.0\" is redundant.")
}

func (s *Suite) Test_Package_checkDescr__DESCR_SRC(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("other/package")
	t.SetUpPackage("category/package",
		"DESCR_SRC=\t../../other/package/DESCR")
	t.Remove("category/package/DESCR")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_checkDescr__no_package(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("category/package/module.mk")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		"ERROR: Makefile: Cannot be read.")
}

// All files that can possibly be added to DISTFILES need a corresponding
// entry in the distinfo file.
//
// https://mail-index.netbsd.org/pkgsrc-changes/2020/02/05/msg206172.html
// https://mail-index.netbsd.org/pkgsrc-changes/2020/03/25/msg209445.html
func (s *Suite) Test_Package_checkDistfilesInDistinfo__indirect_conditional_DISTFILES(c *check.C) {
	G.Experimental = true

	t := s.Init(c)

	t.SetUpPackage("category/package",
		".include \"../../mk/bsd.prefs.mk\"",
		"",
		"DISTFILES.i386=\t\tdistfile-i386.tar.gz",
		"DISTFILES.x86=\t\tdistfile-x86.tar.gz",
		"DISTFILES.other=\tdistfile-other.tar.gz",
		"",
		".if ${MACHINE_ARCH} == i386",
		"DISTFILES+=\t${DISTFILES.i386} ${DISTFILES.x86}",
		".else",
		"DISTFILES+=\t${DISTFILES.other}",
		".endif",
		"",
		"DISTFILES+=\tok-3.tar.gz")
	t.CreateFileLines("category/package/distinfo",
		CvsID,
		"",
		"BLAKE2s (ok-3.tar.gz) = 1234",
		"SHA512 (ok-3.tar.gz) = 1234",
		"Size (ok-3.tar.gz) = 1234",
		"BLAKE2s (package-1.0.tar.gz) = 1234",
		"SHA512 (package-1.0.tar.gz) = 1234",
		"Size (package-1.0.tar.gz) = 1234")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		"WARN: Makefile:27: Distfile \"distfile-i386.tar.gz\" is not mentioned in distinfo.",
		"WARN: Makefile:27: Distfile \"distfile-x86.tar.gz\" is not mentioned in distinfo.",
		"WARN: Makefile:29: Distfile \"distfile-other.tar.gz\" is not mentioned in distinfo.")
}

func (s *Suite) Test_Package_checkDistfilesInDistinfo__unresolvable(c *check.C) {
	G.Experimental = true

	t := s.Init(c)

	t.SetUpPackage("category/package",
		".include \"../../mk/bsd.prefs.mk\"",
		"",
		".if ${MACHINE_ARCH} == i386",
		"DISTFILES+=\t${UNKNOWN} missing-i386-1.0.tar.gz",
		".endif",
		"",
		"DISTFILES+=\tok-3.tar.gz missing-all-1.0.tar.gz")
	t.CreateFileLines("category/package/distinfo",
		CvsID,
		"",
		"BLAKE2s (ok-3.tar.gz) = 1234",
		"SHA512 (ok-3.tar.gz) = 1234",
		"Size (ok-3.tar.gz) = 1234",
		"BLAKE2s (package-1.0.tar.gz) = 1234",
		"SHA512 (package-1.0.tar.gz) = 1234",
		"Size (package-1.0.tar.gz) = 1234")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check(".")

	// DISTFILES refers to the missing variable UNKNOWN. Therefore, pkglint
	// skips that part of the variable. It still checks all other files that
	// are listed somewhere in DISTFILES.
	t.CheckOutputLines(
		"WARN: Makefile:23: UNKNOWN is used but not defined.",
		"WARN: Makefile:23: Distfile \"missing-i386-1.0.tar.gz\" "+
			"is not mentioned in distinfo.",
		"WARN: Makefile:26: Distfile \"missing-all-1.0.tar.gz\" "+
			"is not mentioned in distinfo.")
}

func (s *Suite) Test_Package_checkDistfilesInDistinfo__indirect_DIST_SUBDIR(c *check.C) {
	G.Experimental = true

	t := s.Init(c)

	t.SetUpPackage("category/package",
		".include \"../../mk/bsd.prefs.mk\"",
		"",
		// As of 2020-03-26, pkglint doesn't know how to resolve PKGNAME_NOREV.
		"DIST_SUBDIR=\t${PKGNAME_NOREV}",
		// Strictly speaking, this is redundant, but as of 2020-03-26,
		// pkglint doesn't infer the default DISTFILES, so it needs a bit of help here.
		"DISTFILES+=\tdistfile-1.0.tar.gz",
		"DISTFILES+=\tdistfile-other.tar.gz")
	t.CreateFileLines("distinfo",
		CvsID,
		"",
		"SHA1 (package-1.0/distfile-other.tar.gz) = 1234",
		"BLAKE2s (package-1.0/distfile-other.tar.gz) = 1234",
		"SHA512 (package-1.0/distfile-other.tar.gz) = 1234",
		"Size (package-1.0/distfile-other.tar.gz) = 1234",
		"SHA1 (package-1.0/package-1.0.tar.gz) = 1234",
		"BLAKE2s (package-1.0/package-1.0.tar.gz) = 1234",
		"SHA512 (package-1.0/package-1.0.tar.gz) = 1234",
		"Size (package-1.0/package-1.0.tar.gz) = 1234")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		"WARN: Makefile:24: Distfile \"distfile-other.tar.gz\" is not mentioned in distinfo.")
}

func (s *Suite) Test_Package_checkDistfilesInDistinfo__depending_on_package_settable(c *check.C) {
	G.Experimental = true

	t := s.Init(c)

	t.SetUpPackage("print/tex-varisize",
		"DISTNAME=\tvarisize",
		"PKGNAME=\ttex-${DISTNAME}-2014",
		"TEXLIVE_REV=\t15878",
		"",
		"TEXLIVE_UNVERSIONED=\tyes",
		"",
		".include \"../../print/texlive/package.mk\"")
	t.CreateFileLines("print/tex-varisize/distinfo",
		CvsID,
		"",
		"BLAKE2s (tex-varisize-15878/varisize.tar.xz) = 1234",
		"SHA512 (tex-varisize-15878/varisize.tar.xz) = 1234",
		"Size (tex-varisize-15878/varisize.tar.xz) = 3176 bytes")
	t.CreateFileLines("print/texlive/package.mk",
		MkCvsID,
		"",
		".if empty(TEXLIVE_UNVERSIONED)",
		"DISTFILES?=\t${DISTNAME}.r${TEXLIVE_REV}${EXTRACT_SUFX}",
		".endif")
	t.Chdir("print/tex-varisize")
	t.FinishSetUp()

	G.Check(".")

	// The package-settable TEXLIVE_UNVERSIONED is definitely not empty,
	// therefore the line in package.mk doesn't apply.
	// FIXME: This warning is wrong because the line in package.mk is unreachable.
	//  See MkLines.IsUnreachable.
	t.CheckOutputLines(
		"WARN: ../../print/texlive/package.mk:4: Distfile \"varisize.r15878.tar.gz\" " +
			"is not mentioned in ../../print/tex-varisize/distinfo.")
}

func (s *Suite) Test_Package_checkDistfilesInDistinfo__empty_distfiles(c *check.C) {
	G.Experimental = true

	t := s.Init(c)

	t.SetUpPackage("category/package",
		"DISTFILES=\t# none")
	t.CreateFileLines("category/package/distinfo",
		CvsID)
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check(".")

	// For completely empty distinfo files, the check is skipped.
	t.CheckOutputLines(
		"WARN: distinfo: This file should not exist.",
		"NOTE: distinfo:1: Empty line expected below this line.")
}

func (s *Suite) Test_Package_checkDistfilesInDistinfo__no_distfiles(c *check.C) {
	G.Experimental = true

	t := s.Init(c)

	t.SetUpPackage("category/package",
		"#DISTNAME=\t# undefined",
		"#DISTFILES=\t# undefined")
	t.CreateFileLines("category/package/distinfo",
		CvsID,
		"",
		"BLAKE2s (distfile-1.0.tar.gz) = 1234",
		"SHA512 (distfile-1.0.tar.gz) = 1234",
		"Size (distfile-1.0.tar.gz) = 1234 bytes")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check(".")

	// For completely empty DISTFILES, the check is skipped.
	t.CheckOutputLines(
		"WARN: distinfo: This file should not exist.")
}

func (s *Suite) Test_Package_checkPkgConfig__no_buildlink3(c *check.C) {
	t := s.Init(c)

	t.SetUpTool("pkg-config", "", Nowhere)
	t.SetUpPackage("category/package",
		"USE_TOOLS+=\tpkg-config")
	t.Chdir("category/package")
	t.FinishSetUp()

	pkg := NewPackage(".")
	pkg.Check()

	t.CheckOutputLines(
		"WARN: Makefile:1: The package uses the tool \"pkg-config\" " +
			"but doesn't include any buildlink3 file.")
}

func (s *Suite) Test_Package_checkPkgConfig__plain_buildlink3(c *check.C) {
	t := s.Init(c)

	t.SetUpTool("pkg-config", "", Nowhere)
	t.SetUpPackage("category/package",
		"USE_TOOLS+=\tpkg-config",
		".include \"../../devel/library/buildlink3.mk\"")
	t.SetUpPackage("devel/library")
	t.CreateFileBuildlink3("devel/library/buildlink3.mk")
	t.Chdir("category/package")
	t.FinishSetUp()

	pkg := NewPackage(".")
	pkg.Check()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_checkPkgConfig__mk_buildlink3(c *check.C) {
	t := s.Init(c)

	t.SetUpTool("pkg-config", "", Nowhere)
	t.SetUpPackage("category/package",
		"USE_TOOLS+=\tpkg-config",
		".include \"../../mk/curses.buildlink3.mk\"")
	t.CreateFileLines("mk/curses.buildlink3.mk")
	t.Chdir("category/package")
	t.FinishSetUp()

	pkg := NewPackage(".")
	pkg.Check()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_checkfilePackageMakefile__GNU_CONFIGURE(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall")
	pkg := t.SetUpPackage("category/package",
		"GNU_CONFIGURE=\tyes",
		"USE_LANGUAGES=\t#")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:20: GNU_CONFIGURE almost always needs a C compiler, but \"c\" is not added to USE_LANGUAGES in line 21.")
}

// Packages that define GNU_CONFIGURE should also set at least USE_LANGUAGES=c.
// Except if they know what they are doing, as documented in the comment "none, really".
func (s *Suite) Test_Package_checkfilePackageMakefile__GNU_CONFIGURE_ok(c *check.C) {
	t := s.Init(c)

	pkg := t.SetUpPackage("category/package",
		"GNU_CONFIGURE=\tyes",
		"USE_LANGUAGES=\t# none, really")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_checkfilePackageMakefile__REPLACE_PERL(c *check.C) {
	t := s.Init(c)

	pkg := t.SetUpPackage("category/package",
		"REPLACE_PERL=\t*.pl",
		"NO_CONFIGURE=\tyes")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:20: REPLACE_PERL is ignored when NO_CONFIGURE is set (in line 21).")
}

func (s *Suite) Test_Package_checkfilePackageMakefile__META_PACKAGE_with_distinfo(c *check.C) {
	t := s.Init(c)

	pkg := t.SetUpPackage("category/package",
		"META_PACKAGE=\tyes")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:20: This package should not have a PLIST file.",
		"WARN: ~/category/package/distinfo: This file should not exist.")
}

func (s *Suite) Test_Package_checkfilePackageMakefile__META_PACKAGE_with_patch(c *check.C) {
	t := s.Init(c)

	pkg := t.SetUpPackage("category/package",
		"META_PACKAGE=\tyes")
	t.Remove("category/package/PLIST")
	t.CreateFileDummyPatch("category/package/patches/patch-aa")
	t.CreateFileLines("category/package/distinfo",
		CvsID,
		"",
		"SHA1 (patch-aa) = 9a93207561abfef7e7550598c5a08f2c3226995b")

	t.FinishSetUp()

	G.Check(pkg)

	// At first it may sound strange to have a META_PACKAGE with patches.
	// As of June 2019, there are 21 meta packages that have a patches
	// directory.
	// These patches are not used by the meta package itself.
	// They are just stored there in the "most obvious location",
	// to be used by the related packages.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_checkfilePackageMakefile__USE_IMAKE_and_USE_X11(c *check.C) {
	t := s.Init(c)

	pkg := t.SetUpPackage("category/package",
		"USE_X11=\tyes",
		"USE_IMAKE=\tyes")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputLines(
		"NOTE: ~/category/package/Makefile:21: USE_IMAKE makes USE_X11 in line 20 redundant.")
}

func (s *Suite) Test_Package_checkfilePackageMakefile__USE_IMAKE_without_USE_X11(c *check.C) {
	t := s.Init(c)

	pkg := t.SetUpPackage("category/package",
		"USE_IMAKE=\tyes")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_checkfilePackageMakefile__USE_IMAKE_and_USE_X11_in_infra(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("mk/x11.buildlink3.mk",
		MkCvsID,
		"USE_X11=\tyes")
	pkg := t.SetUpPackage("category/package",
		".include \"../../mk/x11.buildlink3.mk\"",
		"USE_IMAKE=\tyes")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_checkfilePackageMakefile__PLIST_common(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.Copy("category/package/PLIST", "category/package/PLIST.common")
	t.Remove("category/package/PLIST")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	// No warning about missing PLIST file.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_checkfilePackageMakefile__files_Makefile(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "-Call")
	t.SetUpPackage("category/package",
		"#LICENSE=\t# none")
	t.CreateFileLines("category/package/files/Makefile",
		"#")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"ERROR: ~/category/package/Makefile: Each package must define its LICENSE.")
}

// Until version 19.3.5, pkglint warned that this package would need a
// distinfo file.
func (s *Suite) Test_Package_checkfilePackageMakefile__no_distfiles(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"DISTFILES=\t# none")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"WARN: ~/category/package/distinfo: This file should not exist.")
}

func (s *Suite) Test_Package_checkfilePackageMakefile__distfiles(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"DISTFILES=\tpackage-1.0.tar.gz")
	t.Remove("category/package/distinfo")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"WARN: ~/category/package/distinfo: " +
			"A package that downloads files should have a distinfo file.")
}

func (s *Suite) Test_Package_checkfilePackageMakefile__no_distname(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"#DISTNAME=\t#undefined",
		"PKGNAME=\tpackage-1.0")
	t.Remove("category/package/distinfo")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputEmpty()
}

// The fonts/t1lib package has split the options handling between the
// package Makefile and options.mk. Make sure that this situation is
// handled correctly by pkglint.
//
// See "tr.SeenPrefs = true".
func (s *Suite) Test_Package_checkfilePackageMakefile__options_mk(c *check.C) {
	t := s.Init(c)

	t.SetUpOption("option", "An example option")
	t.SetUpPackage("category/package",
		".include \"options.mk\"",
		"",
		".if ${PKG_OPTIONS:Moption}",
		".endif")
	t.CreateFileLines("mk/bsd.options.mk")
	t.CreateFileLines("category/package/options.mk",
		MkCvsID,
		"",
		"PKG_OPTIONS_VAR=\tPKG_OPTIONS.package",
		"PKG_SUPPORTED_OPTIONS=\toption",
		"",
		".include \"../../mk/bsd.options.mk\"",
		"",
		".if ${PKG_OPTIONS:Moption}",
		".endif")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputEmpty()
}

// When the lines of the package Makefile are checked, it is necessary
// to know whether bsd.prefs.mk has already been included.
//
// When the files are loaded recursively, Package.seenPrefs is set to
// true as soon as some file includes bsd.prefs.mk. After that, when
// loading reaches the main package Makefile again, Package.prefsLine
// is set to the line that had just been included.
//
// In this test case, the preferences are loaded indirectly by line 22,
// which includes common.mk, and that in turn includes bsd.prefs.mk.
func (s *Suite) Test_Package_checkfilePackageMakefile__prefs_indirect(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".if ${OPSYS} == NetBSD", // 20: OPSYS is not yet defined here.
		".endif",                 // 21
		".include \"common.mk\"", // 22: OPSYS gets defined.
		".if ${OPSYS} == NetBSD", // 23: Now OPSYS is defined.
		".endif")
	t.CreateFileLines("category/package/common.mk",
		MkCvsID,
		"",
		".include \"../../mk/bsd.prefs.mk\"")
	t.FinishSetUp()
	pkg := NewPackage(t.File("category/package"))

	files, mklines, allLines := pkg.load()

	t.CheckEquals(pkg.seenPrefs, false)
	t.CheckEquals(pkg.prefsLine, mklines.mklines[21])

	pkg.check(files, mklines, allLines)

	t.CheckEquals(pkg.seenPrefs, true)
	t.CheckEquals(pkg.prefsLine, mklines.mklines[21])

	// Since bsd.prefs.mk is included indirectly by common.mk,
	// OPSYS may be used at load time in line 23, but not in line 20.
	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:20: " +
			"To use OPSYS at load time, " +
			".include \"../../mk/bsd.prefs.mk\" first.")
}

func (s *Suite) Test_Package_checkfilePackageMakefile__redundancy_in_infra(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".include \"../../mk/redundant.mk\"",
		".include \"redundant.mk\"")
	t.CreateFileLines("mk/redundant.mk",
		MkCvsID,
		"INFRA_REDUNDANT:=\t# empty",
		"INFRA_REDUNDANT=\t# empty")
	t.CreateFileLines("category/package/redundant.mk",
		MkCvsID,
		"PKG_REDUNDANT:=\t# empty",
		"PKG_REDUNDANT=\t# empty")
	t.Chdir(".")
	t.FinishSetUp()

	G.checkdirPackage("category/package")

	t.CheckOutputLines(
		"NOTE: category/package/redundant.mk:3: "+
			"Definition of PKG_REDUNDANT is redundant because of line 2.",
		"WARN: category/package/redundant.mk:2: "+
			"PKG_REDUNDANT is defined but not used.")

	G.Check("mk/redundant.mk")

	// The redundancy check applies both to package Makefiles and to
	// makefile fragments that are given in the command line.
	t.CheckOutputLines(
		"NOTE: mk/redundant.mk:3: " +
			"Definition of INFRA_REDUNDANT is redundant because of line 2.")

	// If the global checks are enabled, redundancy warnings from the
	// pkgsrc infrastructure are reported as well.
	//
	// This prevents the redundant PKG_OPTIONS definition from
	// mk/bsd.options.mk to be shown when checking a normal package.
	t.SetUpCommandLine("-Wall", "-Cglobal")

	G.checkdirPackage("category/package")

	t.CheckOutputLines(
		"NOTE: category/package/../../mk/redundant.mk:3: "+
			"Definition of INFRA_REDUNDANT is redundant because of line 2.",
		"NOTE: category/package/redundant.mk:3: "+
			"Definition of PKG_REDUNDANT is redundant because of line 2.",
		"WARN: category/package/redundant.mk:2: "+
			"PKG_REDUNDANT is defined but not used.")
}

// When a package defines PLIST_SRC, it may or may not use the
// PLIST file from the package directory. Therefore the check
// is skipped completely.
func (s *Suite) Test_Package_checkPlist__PLIST_SRC(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"PLIST_SRC=\t${WRKDIR}/PLIST")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_checkPlist__META_PACKAGE(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"META_PACKAGE=\tyes")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:20: This package should not have a PLIST file.",
		"WARN: ~/category/package/distinfo: This file should not exist.")
}

func (s *Suite) Test_Package_checkPlist__Perl5_packlist(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/p5-Packlist",
		"PERL5_PACKLIST=\tauto/Packlist/.packlist")
	t.FinishSetUp()

	G.Check(t.File("category/p5-Packlist"))

	t.CheckOutputLines(
		"WARN: ~/category/p5-Packlist/Makefile:20: This package should not have a PLIST file.")
}

func (s *Suite) Test_Package_checkPlist__PERL5_USE_PACKLIST_no(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/p5-NoPacklist",
		"PERL5_USE_PACKLIST=\tno")
	t.FinishSetUp()

	G.Check(t.File("category/p5-NoPacklist"))

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_checkPlist__PERL5_USE_PACKLIST_yes(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/p5-Packlist",
		"PERL5_USE_PACKLIST=\tyes")
	t.FinishSetUp()

	G.Check(t.File("category/p5-Packlist"))

	t.CheckOutputLines(
		"WARN: ~/category/p5-Packlist/Makefile:20: This package should not have a PLIST file.")
}

func (s *Suite) Test_Package_checkPlist__unused_PLIST_variable(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"PLIST_VARS+=\tused unused",
		"PLIST.used=\tyes",
		"PLIST.unused=\tyes")
	t.CreateFileLines("category/package/PLIST",
		PlistCvsID,
		"${PLIST.used}bin/a")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		"WARN: Makefile:20: PLIST identifier \"unused\" is not used in any PLIST file.")
}

func (s *Suite) Test_Package_CheckVarorder__only_required_variables(c *check.C) {
	t := s.Init(c)

	pkg := NewPackage(t.File("x11/9term"))
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"DISTNAME=9term",
		"CATEGORIES=x11",
		"",
		".include \"../../mk/bsd.pkg.mk\"")

	pkg.CheckVarorder(mklines)

	t.CheckOutputLines(
		"WARN: Makefile:3: The canonical order of the variables is " +
			"DISTNAME, CATEGORIES, empty line, COMMENT, LICENSE.")
}

func (s *Suite) Test_Package_CheckVarorder__with_optional_variables(c *check.C) {
	t := s.Init(c)

	pkg := NewPackage(t.File("x11/9term"))
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"GITHUB_PROJECT=project",
		"DISTNAME=9term",
		"CATEGORIES=x11")

	pkg.CheckVarorder(mklines)

	// TODO: Make this warning more specific to the actual situation.

	// Before 2022-03-11, the GitHub variables were allowed above DISTNAME,
	// which allowed more variation than necessary and made the warning longer.
	t.CheckOutputLines(
		"WARN: Makefile:3: The canonical order of the variables is " +
			"DISTNAME, CATEGORIES, GITHUB_PROJECT, empty line, " +
			"COMMENT, LICENSE.")
}

// Just for code coverage.
func (s *Suite) Test_Package_CheckVarorder__no_tracing(c *check.C) {
	t := s.Init(c)

	pkg := NewPackage(t.File("x11/9term"))
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"DISTNAME=9term",
		"CATEGORIES=x11",
		"",
		".include \"../../mk/bsd.pkg.mk\"")
	t.DisableTracing()

	pkg.CheckVarorder(mklines)

	t.CheckOutputLines(
		"WARN: Makefile:3: The canonical order of the variables is " +
			"DISTNAME, CATEGORIES, empty line, COMMENT, LICENSE.")
}

// Ensure that comments and empty lines do not lead to panics.
// This had been the case when the code accessed fields like Varname from the
// MkLine without checking the line type before.
func (s *Suite) Test_Package_CheckVarorder__comments_do_not_crash(c *check.C) {
	t := s.Init(c)

	pkg := NewPackage(t.File("x11/9term"))
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"GITHUB_PROJECT=project",
		"",
		"# comment",
		"",
		"DISTNAME=9term",
		"# comment",
		"CATEGORIES=x11")

	pkg.CheckVarorder(mklines)

	t.CheckOutputLines(
		"WARN: Makefile:3: The canonical order of the variables is " +
			"DISTNAME, CATEGORIES, GITHUB_PROJECT, empty line, " +
			"COMMENT, LICENSE.")
}

func (s *Suite) Test_Package_CheckVarorder__comments_are_ignored(c *check.C) {
	t := s.Init(c)

	pkg := NewPackage(t.File("x11/9term"))
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"DISTNAME=\tdistname-1.0",
		"CATEGORIES=\tsysutils",
		"",
		"MAINTAINER=\tpkgsrc-users@NetBSD.org",
		"# comment",
		"COMMENT=\tComment",
		"LICENSE=\tgnu-gpl-v2")

	pkg.CheckVarorder(mklines)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_CheckVarorder__commented_variable_assignment(c *check.C) {
	t := s.Init(c)

	pkg := NewPackage(t.File("x11/9term"))
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"DISTNAME=\tdistname-1.0",
		"CATEGORIES=\tsysutils",
		"",
		"MAINTAINER=\tpkgsrc-users@NetBSD.org",
		"#HOMEPAGE=\thttps://example.org/",
		"COMMENT=\tComment",
		"LICENSE=\tgnu-gpl-v2")

	pkg.CheckVarorder(mklines)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_CheckVarorder__skip_because_of_foreign_variable(c *check.C) {
	t := s.Init(c)

	pkg := NewPackage(t.File("x11/9term"))
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"DISTNAME=\tdistname-1.0",
		"USE_TOOLS+=gmake",
		"CATEGORIES=\tsysutils",
		"",
		"MAINTAINER=\tpkgsrc-users@NetBSD.org",
		"#HOMEPAGE=\thttps://example.org/",
		"COMMENT=\tComment",
		"LICENSE=\tgnu-gpl-v2")

	t.EnableTracingToLog()
	pkg.CheckVarorder(mklines)

	t.CheckOutputLinesMatching(`.*varorder.*`,
		"TRACE: 1   Skipping varorder because of line 4.")
}

func (s *Suite) Test_Package_CheckVarorder__skip_if_there_are_directives(c *check.C) {
	t := s.Init(c)

	pkg := NewPackage(t.File("category/package"))
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"DISTNAME=\tdistname-1.0",
		"CATEGORIES=\tsysutils",
		"",
		".if ${DISTNAME:Mdistname-*}",
		"MAINTAINER=\tpkgsrc-users@NetBSD.org",
		".endif",
		"LICENSE=\tgnu-gpl-v2")

	pkg.CheckVarorder(mklines)

	// No warning about the missing COMMENT since the .if directive
	// causes the whole check to be skipped.
	t.CheckOutputEmpty()

	// Just for code coverage.
	t.DisableTracing()
	pkg.CheckVarorder(mklines)
	t.CheckOutputEmpty()
}

// TODO: Add more tests like skip_if_there_are_directives for other line types.

func (s *Suite) Test_Package_CheckVarorder__GITHUB_PROJECT_at_the_top(c *check.C) {
	t := s.Init(c)

	pkg := NewPackage(t.File("x11/9term"))
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"GITHUB_PROJECT=\t\tautocutsel",
		"DISTNAME=\t\tautocutsel-0.10.0",
		"CATEGORIES=\t\tx11",
		"MASTER_SITES=\t\t${MASTER_SITE_GITHUB:=sigmike/}",
		"GITHUB_TAG=\t\t${PKGVERSION_NOREV}",
		"",
		"COMMENT=\tComment",
		"LICENSE=\tgnu-gpl-v2")

	pkg.CheckVarorder(mklines)

	// Before 2022-03-11, the GitHub variables were allowed above DISTNAME,
	// which allowed more variation than necessary and made the warning longer.
	t.CheckOutputLines(
		"WARN: Makefile:3: The canonical order of the variables is " +
			"DISTNAME, CATEGORIES, MASTER_SITES, GITHUB_PROJECT, " +
			"GITHUB_TAG, empty line, COMMENT, LICENSE.")
}

func (s *Suite) Test_Package_CheckVarorder__GITHUB_PROJECT_at_the_bottom(c *check.C) {
	t := s.Init(c)

	pkg := NewPackage(t.File("x11/9term"))
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"DISTNAME=\t\tautocutsel-0.10.0",
		"CATEGORIES=\t\tx11",
		"MASTER_SITES=\t\t${MASTER_SITE_GITHUB:=sigmike/}",
		"GITHUB_PROJECT=\t\tautocutsel",
		"GITHUB_TAG=\t\t${PKGVERSION_NOREV}",
		"",
		"COMMENT=\tComment",
		"LICENSE=\tgnu-gpl-v2")

	pkg.CheckVarorder(mklines)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_CheckVarorder__license(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("mk/bsd.pkg.mk", "# dummy")
	t.CreateFileLines("x11/Makefile", MkCvsID)
	t.CreateFileLines("x11/9term/DESCR", "Terminal")
	t.CreateFileLines("x11/9term/PLIST", PlistCvsID, "bin/9term")
	t.CreateFileLines("x11/9term/Makefile",
		MkCvsID,
		"",
		"DISTNAME=\t9term-1.0",
		"CATEGORIES=\tx11",
		"",
		"COMMENT=\tTerminal",
		"",
		"NO_CHECKSUM=\tyes",
		"",
		".include \"../../mk/bsd.pkg.mk\"")

	t.SetUpVartypes()

	G.Check(t.File("x11/9term"))

	// Since the error is grave enough, the warning about the correct position is suppressed.
	// TODO: Knowing the correct position helps, though.
	t.CheckOutputLines(
		"ERROR: ~/x11/9term/Makefile: Each package must define its LICENSE.")
}

// https://mail-index.netbsd.org/tech-pkg/2017/01/18/msg017698.html
func (s *Suite) Test_Package_CheckVarorder__MASTER_SITES(c *check.C) {
	t := s.Init(c)

	pkg := NewPackage(t.File("category/package"))
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"PKGNAME=\tpackage-1.0",
		"CATEGORIES=\tcategory",
		"MASTER_SITES=\thttp://example.org/",
		"MASTER_SITES+=\thttp://mirror.example.org/",
		"",
		"COMMENT=\tComment",
		"LICENSE=\tgnu-gpl-v2")

	pkg.CheckVarorder(mklines)

	// No warning that "MASTER_SITES appears too late"
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_CheckVarorder__diagnostics(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	pkg := NewPackage(t.File("category/package"))
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"CATEGORIES=     net",
		"",
		"COMMENT=        Comment",
		"LICENSE=        gnu-gpl-v3",
		"",
		"GITHUB_PROJECT= pkgbase",
		"DISTNAME=       v1.0",
		"PKGNAME=        ${GITHUB_PROJECT}-${DISTNAME}",
		"MASTER_SITES=   ${MASTER_SITE_GITHUB:=project/}",
		"DIST_SUBDIR=    ${GITHUB_PROJECT}",
		"",
		"MAINTAINER=     maintainer@example.org",
		"HOMEPAGE=       https://github.com/project/pkgbase/",
		"",
		".include \"../../mk/bsd.pkg.mk\"")

	pkg.CheckVarorder(mklines)

	t.CheckOutputLines(
		"WARN: Makefile:3: The canonical order of the variables is " +
			"DISTNAME, PKGNAME, CATEGORIES, " +
			"MASTER_SITES, GITHUB_PROJECT, DIST_SUBDIR, empty line, " +
			"MAINTAINER, HOMEPAGE, COMMENT, LICENSE.")

	// After moving the variables according to the warning:
	mklines = t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"DISTNAME=       v1.0",
		"PKGNAME=        ${GITHUB_PROJECT}-${DISTNAME}",
		"CATEGORIES=     net",
		"MASTER_SITES=   ${MASTER_SITE_GITHUB:=project/}",
		"GITHUB_PROJECT= pkgbase",
		"DIST_SUBDIR=    ${GITHUB_PROJECT}",
		"",
		"MAINTAINER=     maintainer@example.org",
		"HOMEPAGE=       https://github.com/project/pkgbase/",
		"COMMENT=        Comment",
		"LICENSE=        gnu-gpl-v3",
		"",
		".include \"../../mk/bsd.pkg.mk\"")

	pkg.CheckVarorder(mklines)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_CheckVarorder__comment_at_end_of_section(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	pkg := NewPackage(t.File("category/package"))
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"CATEGORIES=     net",
		"SITES.*=        # none",
		"# comment after the last variable of a section",
		"",
		"MAINTAINER=     maintainer@example.org",
		"HOMEPAGE=       https://github.com/project/pkgbase/",
		"COMMENT=        Comment",
		"LICENSE=        gnu-gpl-v3",
		"",
		".include \"../../mk/bsd.pkg.mk\"")

	t.EnableTracingToLog()
	pkg.CheckVarorder(mklines)

	// The varorder code is not skipped, not even because of the comment
	// after SITES.*.
	t.CheckOutputLinesMatching(`.*varorder.*`,
		nil...)
}

func (s *Suite) Test_Package_CheckVarorder__comments_between_sections(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	pkg := NewPackage(t.File("category/package"))
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"CATEGORIES=     net",
		"",
		"# comment 1",
		"",
		"# comment 2",
		"",
		"MAINTAINER=     maintainer@example.org",
		"HOMEPAGE=       https://github.com/project/pkgbase/",
		"COMMENT=        Comment",
		"LICENSE=        gnu-gpl-v3",
		"",
		".include \"../../mk/bsd.pkg.mk\"")

	pkg.CheckVarorder(mklines)

	// The empty line between the comments is not treated as a section separator.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_CheckVarorder__commented_varassign(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	pkg := NewPackage(t.File("category/package"))
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"CATEGORIES=     net",
		"#MASTER_SITES=  # none",
		"",
		"HOMEPAGE=       https://github.com/project/pkgbase/",
		"#HOMEPAGE=      https://github.com/project/pkgbase/",
		"#HOMEPAGE=      https://github.com/project/pkgbase/",
		"#HOMEPAGE=      https://github.com/project/pkgbase/",
		"#HOMEPAGE=      https://github.com/project/pkgbase/",
		"LICENSE=        gnu-gpl-v3",
		"COMMENT=        Comment",
		"",
		".include \"../../mk/bsd.pkg.mk\"")

	pkg.CheckVarorder(mklines)

	// The order of the variables LICENSE and COMMENT is intentionally
	// wrong to force the warning.
	//
	// Up to June 2019 (308099138a62) pkglint mentioned in the warning
	// each commented variable assignment, even repeatedly for the same
	// variable name.
	//
	// These variable assignments should be in the correct order, even
	// if they are commented out. It's not necessary though to list a
	// variable more than once.
	t.CheckOutputLines(
		"WARN: Makefile:3: The canonical order of the variables is " +
			"CATEGORIES, MASTER_SITES, empty line, HOMEPAGE, COMMENT, LICENSE.")
}

func (s *Suite) Test_Package_CheckVarorder__DEPENDS(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	pkg := NewPackage(t.File("category/package"))
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		"CATEGORIES=     net",
		"",
		"COMMENT=        Comment",
		"LICENSE=        license",
		"MAINTAINER=     maintainer@example.org", // In wrong order
		"",
		"DEPENDS+=       dependency>=1.0:../../category/dependency",
		"",
		".include \"../../mk/bsd.pkg.mk\"")

	pkg.CheckVarorder(mklines)

	t.CheckOutputLines(
		"WARN: Makefile:3: The canonical order of the variables is " +
			"CATEGORIES, empty line, MAINTAINER, COMMENT, LICENSE, empty line, DEPENDS.")
}

func (s *Suite) Test_Package_checkGnuConfigureUseLanguages__no_C(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"USE_LANGUAGES=\tfortran77",
		"USE_LANGUAGES+=\tc++14",
		"USE_LANGUAGES+=\tada",
		"GNU_CONFIGURE=\tyes")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:23: "+
			"GNU_CONFIGURE almost always needs a C compiler, "+
			"but \"c\" is not added to USE_LANGUAGES in line 20.",
		"WARN: ~/category/package/Makefile:23: "+
			"GNU_CONFIGURE almost always needs a C compiler, "+
			"but \"c\" is not added to USE_LANGUAGES in line 21.",
		"WARN: ~/category/package/Makefile:23: "+
			"GNU_CONFIGURE almost always needs a C compiler, "+
			"but \"c\" is not added to USE_LANGUAGES in line 22.")
}

func (s *Suite) Test_Package_checkGnuConfigureUseLanguages__C_in_the_middle(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"USE_LANGUAGES=\tfortran77",
		"USE_LANGUAGES+=\tc99",
		"USE_LANGUAGES+=\tada",
		"GNU_CONFIGURE=\tyes")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	// Until March 2019 pkglint wrongly warned that USE_LANGUAGES would not
	// include c or c99, although c99 was added.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_checkGnuConfigureUseLanguages__realistic_compiler_mk(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"USE_LANGUAGES=\tfortran77",
		"USE_LANGUAGES+=\tc++",
		"USE_LANGUAGES+=\tada",
		"GNU_CONFIGURE=\tyes",
		"",
		".include \"../../mk/compiler.mk\"")
	t.CreateFileLines("mk/compiler.mk",
		"_CXX_STD_VERSIONS=\tc++ c++14",
		".if ${USE_LANGUAGES:Mada} \\",
		" || ${USE_LANGUAGES:Mc} \\",
		" || ${USE_LANGUAGES:Mfortran77}",
		".endif",
		"",
		// This line is ignored since it comes from the pkgsrc infrastructure.
		"USE_LANGUAGES?=\t\tc")

	t.FinishSetUp()

	G.Check(t.File("category/package"))

	// The package defines several languages it needs, but C is not one of them.
	// When the package is loaded, the included files are read in recursively, even
	// when they come from the pkgsrc infrastructure.
	//
	// Up to March 2019, the USE_LANGUAGES definitions from mk/compiler.mk were
	// loaded as if they were defined by the package, without taking the conditionals
	// into account. Thereby "c" was added unconditionally to USE_LANGUAGES.
	//
	// Since March 2019 the infrastructure files are ignored when determining the value
	// of USE_LANGUAGES.
	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:23: "+
			"GNU_CONFIGURE almost always needs a C compiler, "+
			"but \"c\" is not added to USE_LANGUAGES in line 20.",
		"WARN: ~/category/package/Makefile:23: "+
			"GNU_CONFIGURE almost always needs a C compiler, "+
			"but \"c\" is not added to USE_LANGUAGES in line 21.",
		"WARN: ~/category/package/Makefile:23: "+
			"GNU_CONFIGURE almost always needs a C compiler, "+
			"but \"c\" is not added to USE_LANGUAGES in line 22.")
}

func (s *Suite) Test_Package_checkGnuConfigureUseLanguages__only_GNU_CONFIGURE(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"GNU_CONFIGURE=\tyes")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_checkGnuConfigureUseLanguages__ok(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"GNU_CONFIGURE=\tyes",
		"USE_LANGUAGES=\tc++ objc")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_checkGnuConfigureUseLanguages__not_constant_1(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".if 0",
		"GNU_CONFIGURE=\tyes",
		".endif",
		"USE_LANGUAGES=\tc++ objc")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_checkGnuConfigureUseLanguages__not_constant_2(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"GNU_CONFIGURE=\tyes",
		".if 0",
		"USE_LANGUAGES=\tc++ objc",
		".endif")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_checkUseLanguagesCompilerMk__too_late(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".include \"../../mk/compiler.mk\"",
		"USE_LANGUAGES=\tc c99 fortran ada c++14")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:21: " +
			"Modifying USE_LANGUAGES after including ../../mk/compiler.mk has no effect.")
}

func (s *Suite) Test_Package_checkUseLanguagesCompilerMk__compiler_mk(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"USE_LANGUAGES=\tc c99 fortran ada c++14",
		".include \"../../mk/compiler.mk\"",
		".include \"compiler.mk\"",
		"USE_LANGUAGES=\tc c99 fortran ada c++14")
	t.CreateFileLines("category/package/compiler.mk",
		MkCvsID,
		"USE_LANGUAGES=\tc++")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:20: "+
			"Variable USE_LANGUAGES is overwritten in compiler.mk:2.",
		"WARN: ~/category/package/compiler.mk:2: "+
			"Modifying USE_LANGUAGES after including ../../mk/compiler.mk has no effect.",
		"WARN: ~/category/package/Makefile:23: "+
			"Modifying USE_LANGUAGES after including ../../mk/compiler.mk has no effect.")
}

func (s *Suite) Test_Package_checkUseLanguagesCompilerMk__endian_mk(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".include \"endian.mk\"",
		"USE_LANGUAGES=\tc c99 fortran ada c++14",
		".include \"../../mk/endian.mk\"",
		"USE_LANGUAGES=\tc c99 fortran ada c++14")
	t.CreateFileLines("category/package/endian.mk",
		MkCvsID)
	t.CreateFileLines("mk/endian.mk",
		MkCvsID)
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"NOTE: ~/category/package/Makefile:23: "+
			"Definition of USE_LANGUAGES is redundant because of line 21.",
		"WARN: ~/category/package/Makefile:23: "+
			"Modifying USE_LANGUAGES after including ../../mk/compiler.mk has no effect.")
}

func (s *Suite) Test_Package_checkMesonGnuMake(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("devel/meson/build.mk")
	t.SetUpTool("gmake", "", AtRunTime)
	t.SetUpPackage("category/package",
		"USE_TOOLS+=\tgmake",
		"",
		".include \"../../devel/meson/build.mk\"")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check(".")

	// XXX: Giving the line number where gmake is actually used by the
	//  package would be nice. Without that information, it is unclear why
	//  the package uses gmake at all.
	t.CheckOutputLines(
		"WARN: Meson packages usually don't need GNU make.")
}

func (s *Suite) Test_Package_checkMesonConfigureArgs(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("devel/meson/build.mk")
	t.SetUpPackage("category/package",
		"CONFIGURE_ARGS+=\t--enable-feature",
		"",
		".include \"../../devel/meson/build.mk\"")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		"WARN: Makefile:20: Meson packages usually don't need CONFIGURE_ARGS.")
}

func (s *Suite) Test_Package_checkMesonConfigureArgs__include(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("devel/meson/build.mk")
	t.CreateFileLines("devel/libcommon/use.mk",
		MkCvsID,
		"",
		"CONFIGURE_ARGS+=\t--enable-feature")
	t.SetUpPackage("category/package",
		".include \"../../devel/libcommon/use.mk\"",
		".include \"../../devel/meson/build.mk\"")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check(".")

	// When checking the package x11/libxkbcommon, do not warn that
	// converters/libiconv/builtin.mk defines CONFIGURE_ARGS, since that
	// file may be used by other packages as well, or the relevant section
	// may be guarded by '.if ${HAS_CONFIGURE}'.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_checkMesonPython(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("devel/meson/build.mk")
	t.CreateFileLines("lang/python/application.mk")
	t.SetUpPackage("category/package",
		"PYTHON_FOR_BUILD_ONLY=\ttool",
		"",
		".include \"../../lang/python/application.mk\"",
		".include \"../../devel/meson/build.mk\"")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_checkMesonPython__missing_PYTHON_FOR_BUILD_ONLY(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("devel/meson/build.mk")
	t.CreateFileLines("lang/python/application.mk")
	t.SetUpPackage("category/package",
		".include \"../../lang/python/application.mk\"",
		".include \"../../devel/meson/build.mk\"")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		"WARN: Meson packages usually need Python only at build time.")
}

// PKGNAME is stronger than DISTNAME.
func (s *Suite) Test_Package_determineEffectivePkgVars__precedence(c *check.C) {
	t := s.Init(c)

	pkg := NewPackage(t.File("category/pkgbase"))
	pkgnameLine := t.NewMkLine("Makefile", 3, "PKGNAME=pkgname-1.0")
	distnameLine := t.NewMkLine("Makefile", 4, "DISTNAME=distname-1.0")
	pkgrevisionLine := t.NewMkLine("Makefile", 5, "PKGREVISION=13")

	pkg.vars.Define(pkgnameLine.Varname(), pkgnameLine)
	pkg.vars.Define(distnameLine.Varname(), distnameLine)
	pkg.vars.Define(pkgrevisionLine.Varname(), pkgrevisionLine)

	pkg.determineEffectivePkgVars()

	t.CheckEquals(pkg.EffectivePkgbase, "pkgname")
	t.CheckEquals(pkg.EffectivePkgname, "pkgname-1.0nb13")
	t.CheckEquals(pkg.EffectivePkgversion, "1.0")
}

func (s *Suite) Test_Package_determineEffectivePkgVars__same(c *check.C) {
	t := s.Init(c)

	pkg := t.SetUpPackage("category/package",
		"DISTNAME=\tdistname-1.0",
		"PKGNAME=\tdistname-1.0")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputLines(
		"NOTE: ~/category/package/Makefile:4: " +
			"This assignment is probably redundant since PKGNAME is ${DISTNAME} by default.")
}

func (s *Suite) Test_Package_determineEffectivePkgVars__simple_reference(c *check.C) {
	t := s.Init(c)

	pkg := t.SetUpPackage("category/package",
		"DISTNAME=\tdistname-1.0",
		"PKGNAME=\t${DISTNAME}")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputLines(
		"NOTE: ~/category/package/Makefile:4: " +
			"This assignment is probably redundant since PKGNAME is ${DISTNAME} by default.")
}

func (s *Suite) Test_Package_determineEffectivePkgVars__commented(c *check.C) {
	t := s.Init(c)

	pkg := t.SetUpPackage("category/package",
		"DISTNAME=\tdistname-1.0",
		"PKGNAME=\t${DISTNAME} # intentionally")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_determineEffectivePkgVars__invalid_DISTNAME(c *check.C) {
	t := s.Init(c)

	pkg := t.SetUpPackage("category/package",
		"DISTNAME=\tpkgname-version")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:3: " +
			"As DISTNAME is not a valid package name, please define the PKGNAME explicitly.")
}

func (s *Suite) Test_Package_determineEffectivePkgVars__indirect_DISTNAME(c *check.C) {
	t := s.Init(c)

	pkg := t.SetUpPackage("category/package",
		"DISTNAME=\t${DISTFILES:[1]:C,\\..*,,}")
	t.FinishSetUp()

	G.Check(pkg)

	// No warning since the case of DISTNAME being dependent on another
	// variable is too difficult to analyze.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_determineEffectivePkgVars__C_modifier(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("x11/p5-gtk2",
		"DISTNAME=\tGtk2-1.0",
		"PKGNAME=\t${DISTNAME:C:Gtk2:p5-gtk2:}")
	t.FinishSetUp()
	pkg := NewPackage(t.File("x11/p5-gtk2"))
	files, mklines, allLines := pkg.load()

	pkg.check(files, mklines, allLines)

	t.CheckEquals(pkg.EffectivePkgname, "p5-gtk2-1.0")
}

// In some cases the PKGNAME is derived from DISTNAME, and it seems as
// if the :C modifier would not affect anything. This may nevertheless
// be on purpose since the modifier may apply to future versions and
// do things like replacing a "-1" with a ".1".
func (s *Suite) Test_Package_determineEffectivePkgVars__ineffective_C_modifier(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"DISTNAME=\tdistname-1.0",
		"PKGNAME=\t${DISTNAME:C:does_not_match:replacement:}")
	t.FinishSetUp()
	pkg := NewPackage(t.File("category/package"))
	files, mklines, allLines := pkg.load()

	pkg.check(files, mklines, allLines)

	t.CheckEquals(pkg.EffectivePkgname, "distname-1.0")
	t.CheckOutputLines(
		"NOTE: ~/category/package/Makefile:4: " +
			"The modifier :C:does_not_match:replacement: does not have an effect.")
}

func (s *Suite) Test_Package_determineEffectivePkgVars__ineffective_S_modifier_with_variable(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"VERSION=\t1.008",
		"DISTNAME=\tdistname-v${VERSION}",
		"PKGNAME=\t${DISTNAME:S/v1/1/}")
	t.FinishSetUp()
	pkg := NewPackage(t.File("category/package"))
	files, mklines, allLines := pkg.load()

	pkg.check(files, mklines, allLines)

	// TODO: Expand ${VERSION}, that's pretty simple.
	t.CheckEquals(pkg.EffectivePkgname, "") // Because of the unexpanded VERSION.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_determineEffectivePkgVars__effective_S_modifier_with_variable(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"MINOR_VERSION=\t1.008",
		"DISTNAME=\tdistname-v1.${MINOR_VERSION}",
		"PKGNAME=\t${DISTNAME:S/v1/1/}")
	t.FinishSetUp()
	pkg := NewPackage(t.File("category/package"))
	files, mklines, allLines := pkg.load()

	pkg.check(files, mklines, allLines)

	t.CheckEquals(pkg.EffectivePkgname, "") // because of MINOR_VERSION
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_determineEffectivePkgVars__Python_prefix(c *check.C) {
	t := s.Init(c)

	G.Experimental = true
	t.SetUpPackage("category/package",
		"PKGNAME=\tpackage-2.0",
		".include \"../../lang/python/extension.mk\"")
	t.CreateFileLines("lang/python/extension.mk",
		MkCvsID)

	t.Main("-Wall", "category/package")

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:4: The PKGNAME of Python extensions should start with ${PYPKGPREFIX}.",
		"1 warning found.")
}

func (s *Suite) Test_Package_determineEffectivePkgVars__Python_prefix_PKGNAME_variable(c *check.C) {
	t := s.Init(c)

	G.Experimental = true
	t.SetUpPackage("category/package",
		"PKGNAME=\t${VAR}-package-2.0",
		".include \"../../lang/python/extension.mk\"")
	t.CreateFileLines("lang/python/extension.mk",
		MkCvsID,
		"VAR=\tvalue")

	t.Main("-Wall", "category/package")

	// Since PKGNAME starts with a variable, pkglint doesn't investigate
	// further what the possible value of this variable could be. If it
	// did, it would see that the prefix is not PYPKGPREFIX and would
	// complain.
	t.CheckOutputLines(
		"Looks fine.")
}

// As of August 2019, pkglint loads the package files in alphabetical order.
// This means that the package Makefile is loaded early, and includes by
// other files may be invisible yet. This applies to both Makefile.* and to
// *.mk since both of these appear later.
//
// The effects of these files are nevertheless visible at the right time
// because the package Makefile is loaded including all its included files.
func (s *Suite) Test_Package_determineEffectivePkgVars__Python_prefix_late(c *check.C) {
	t := s.Init(c)

	G.Experimental = true
	t.SetUpPackage("category/package",
		"PKGNAME=\tpackage-2.0",
		".include \"common.mk\"")
	t.CreateFileLines("category/package/common.mk",
		MkCvsID,
		".include \"../../lang/python/extension.mk\"")
	t.CreateFileLines("lang/python/extension.mk",
		MkCvsID)

	t.Main("-Wall", "category/package")

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:4: "+
			"The PKGNAME of Python extensions should start with ${PYPKGPREFIX}.",
		"1 warning found.")
}

// The infrastructure file mk/haskell.mk sets a default for PKGNAME
// that differs from the plain DISTNAME. This makes the assignment
// PKGNAME=${DISTNAME} non-redundant.
func (s *Suite) Test_Package_determineEffectivePkgVars__Haskell(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"PKGNAME=\t${DISTNAME}",
		".include \"../../mk/haskell.mk\"")
	t.CreateFileLines("mk/haskell.mk",
		MkCvsID,
		"PKGNAME?=\ths-${DISTNAME}")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	// Up to 2020-06-28, pkglint wrongly produced a note about
	// PKGNAME being "probably redundant".
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_determineEffectivePkgVars__bsd_pkg_mk(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"PKGNAME=\t${DISTNAME}")
	t.CreateFileLines("mk/bsd.pkg.mk",
		MkCvsID,
		"PKGNAME?=\t${DISTNAME}")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	// Contrary to the one from mk/haskell.mk, the default assignment in
	// mk/bsd.pkg.mk is not included in the RedundantScope.
	t.CheckOutputLines(
		"NOTE: ~/category/package/Makefile:4: This assignment is probably " +
			"redundant since PKGNAME is ${DISTNAME} by default.")
}

func (s *Suite) Test_Package_nbPart(c *check.C) {
	t := s.Init(c)

	pkg := NewPackage(t.File("category/pkgbase"))
	pkg.vars.Define("PKGREVISION", t.NewMkLine("Makefile", 1, "PKGREVISION=14"))

	t.CheckEquals(pkg.nbPart(), "nb14")

	pkg.vars = NewScope()
	pkg.vars.Define("PKGREVISION", t.NewMkLine("Makefile", 1, "PKGREVISION=asdf"))

	t.CheckEquals(pkg.nbPart(), "")
}

func (s *Suite) Test_Package_pkgnameFromDistname(c *check.C) {
	t := s.Init(c)

	var once Once
	test := func(pkgname, distname, expectedPkgname string, diagnostics ...string) {
		t.SetUpPackage("category/package",
			"PKGNAME=\t"+pkgname,
			"DISTNAME=\t"+distname)
		if once.FirstTime("called") {
			t.FinishSetUp()
		}

		pkg := NewPackage(t.File("category/package"))
		_, allLines := pkg.loadPackageMakefile()
		pkg.redundant = NewRedundantScope() // See Package.checkfilePackageMakefile.
		pkg.redundant.IsRelevant = func(mkline *MkLine) bool { return false }
		pkg.redundant.Check(allLines)
		pkg.determineEffectivePkgVars()
		t.CheckEquals(pkg.EffectivePkgname, expectedPkgname)
		t.CheckOutput(diagnostics)
	}

	test("pkgname-1.0", "whatever", "pkgname-1.0")

	test("${DISTNAME}", "distname-1.0", "distname-1.0",
		"NOTE: ~/category/package/Makefile:4: This assignment is probably redundant since PKGNAME is ${DISTNAME} by default.")

	test("${DISTNAME:S/dist/pkg/}", "distname-1.0", "pkgname-1.0")

	test("${DISTNAME:S|a|b|g}", "panama-0.13", "pbnbmb-0.13")

	// The substitution succeeds, but the substituted value is missing
	// the package version. Therefore it is discarded completely.
	test("${DISTNAME:S|^lib||}", "libncurses", "")

	// The substitution does not have an effect.
	// The substituted value is missing the package version.
	// Therefore it is discarded completely.
	test("${DISTNAME:S|^lib||}", "mylib", "",
		"NOTE: ~/category/package/Makefile:4: The modifier :S|^lib|| does not have an effect.")

	test("${DISTNAME:tl:S/-/./g:S/he/-/1}", "SaxonHE9-5-0-1J", "saxon-9.5.0.1j")

	test("${DISTNAME:C/beta/.0./}", "fspanel-0.8beta1", "fspanel-0.8.0.1")

	test("${DISTNAME:C/Gtk2/p5-gtk2/}", "Gtk2-1.0", "p5-gtk2-1.0")

	test("${DISTNAME:S/-0$/.0/1}", "aspell-af-0.50-0", "aspell-af-0.50.0")

	test("${DISTNAME:M*.tar.gz:C,\\..*,,}", "aspell-af-0.50-0", "")

	test("${DISTNAME:S,a,b,c,d}", "aspell-af-0.50-0", "bspell-af-0.50-0",
		"WARN: ~/category/package/Makefile:4: Invalid variable modifier \"c,d\" for \"DISTNAME\".")

	test("${DISTFILE:C,\\..*,,}", "aspell-af-0.50-0", "")

	// Parse error because of missing closing brace, parsing succeeds.
	test("${DISTNAME:M", "package-1.0", "",
		"WARN: ~/category/package/Makefile:4: "+
			"Missing closing \"}\" for \"DISTNAME\".")

	// Parse error with an unparseable rest.
	test("$", "package-1.0", "",
		nil...)
}

func (s *Suite) Test_Package_checkPossibleDowngrade(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("doc/CHANGES-2018",
		"\tUpdated category/pkgbase to 1.8 [committer 2018-01-05]")
	G.Pkgsrc.loadDocChanges()

	t.Chdir("category/pkgbase")
	pkg := NewPackage(".")
	pkg.EffectivePkgname = "package-1.0nb15"
	pkg.EffectivePkgnameLine = t.NewMkLine("Makefile", 5, "PKGNAME=dummy")

	pkg.checkPossibleDowngrade()

	t.CheckOutputLines(
		"WARN: Makefile:5: The package is being downgraded from 1.8 (see ../../doc/CHANGES-2018:1) to 1.0nb15.")

	G.Pkgsrc.LastChange["category/pkgbase"].target = "1.0nb22"

	pkg.checkPossibleDowngrade()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_checkPossibleDowngrade__moved(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/pkgbase",
		"PKGNAME=\tpackage-1.0")
	t.CreateFileLines("doc/CHANGES-2018",
		"\tUpdated category/old-package to 1.8 [committer 2018-01-05]",
		"\tMoved category/old-package to category/pkgbase [committer 2018-01-05]")
	t.FinishSetUp()

	pkg := NewPackage(t.File("category/pkgbase"))
	pkg.load()
	pkg.determineEffectivePkgVars()
	pkg.checkPossibleDowngrade()

	t.CheckEquals(G.Pkgsrc.LastChange["category/pkgbase"].Action, Moved)
	// No warning because the latest action is not Updated.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_checkPossibleDowngrade__locally_modified_update(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"PKGNAME=\tpackage-1.8")
	t.CreateFileLines("doc/CHANGES-2018",
		"\tUpdated category/package to 1.0 [committer 2018-01-05]")
	t.CreateFileLines("category/package/CVS/Entries",
		"/Makefile//modified//")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	// Since the Makefile is locally modified, pkglint doesn't issue
	// any warning since it assumes the package is being upgraded.
	t.CheckOutputEmpty()

	// When the Makefile is no longer locally modified, the warning
	// is activated again.
	t.Remove("category/package/CVS/Entries")
	G.cvsEntriesDir = ""

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"NOTE: ~/category/package/Makefile:4: Package version \"1.8\" " +
			"is greater than the latest \"1.0\" from ../../doc/CHANGES-2018:1.")
}

func (s *Suite) Test_Package_checkUpdate(c *check.C) {
	t := s.Init(c)

	// The package names intentionally differ from the package directories
	// to ensure that the check uses the package name.
	t.SetUpPackage("category/pkg1",
		"PKGNAME=\tpackage1-1.0")
	t.SetUpPackage("category/pkg2",
		"PKGNAME=\tpackage2-1.0")
	t.SetUpPackage("category/pkg3",
		"PKGNAME=\tpackage3-5.0")
	t.CreateFileLines("doc/TODO",
		CvsID,
		"Suggested package updates",
		"=========================",
		"For possible Perl packages updates, see http://www.NetBSD.org/~wiz/perl.html.",
		"",
		"\t"+"o package1-1.0",
		"\t"+"o package1-1.0 [with comment]",
		"\t"+"o package2-2.0",
		"\t"+"o package2-2.0 [nice new features]",
		"\t"+"o package3-3.0",
		"\t"+"o package3-3.0 [security update]")
	t.Chdir(".")

	t.Main("-Wall", "category/pkg1", "category/pkg2", "category/pkg3")

	t.CheckOutputLines(
		"NOTE: category/pkg1/Makefile:4: The update request to 1.0 from ../../doc/TODO:6 has been done.",
		"NOTE: category/pkg1/Makefile:4: The update request to 1.0 (with comment) from ../../doc/TODO:7 has been done.",
		"WARN: category/pkg2/Makefile:4: This package should be updated to 2.0 (see ../../doc/TODO:8).",
		"WARN: category/pkg2/Makefile:4: This package should be updated to 2.0 (nice new features; see ../../doc/TODO:9).",
		"NOTE: category/pkg3/Makefile:4: This package is newer than the update request to 3.0 from ../../doc/TODO:10.",
		"NOTE: category/pkg3/Makefile:4: This package is newer than the update request to 3.0 (security update) from ../../doc/TODO:11.",
		"2 warnings and 4 notes found.")
}

func (s *Suite) Test_Package_checkDirent__errors(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Call", "-Wall")
	t.SetUpPkgsrc()
	t.CreateFileLines("category/package/files/subdir/file")
	t.CreateFileLines("category/package/files/subdir/subsub/file")
	t.FinishSetUp()

	pkg := NewPackage(t.File("category/package"))
	pkg.checkDirent(t.File("category/package/options.mk"), 0444)
	pkg.checkDirent(t.File("category/package/files/subdir"), 0555|os.ModeDir)
	pkg.checkDirent(t.File("category/package/files/subdir/subsub"), 0555|os.ModeDir)
	pkg.checkDirent(t.File("category/package/files"), 0555|os.ModeDir)

	t.CheckOutputLines(
		"ERROR: ~/category/package/options.mk: Cannot be read.",
		"WARN: ~/category/package/files/subdir/subsub: Unknown directory name.")
}

func (s *Suite) Test_Package_checkDirent__file_selection(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Call", "-Wall")
	t.SetUpPkgsrc()
	t.CreateFileLines("doc/CHANGES-2018",
		CvsID)
	t.CreateFileLines("category/package/buildlink3.mk",
		MkCvsID,
		"")
	t.CreateFileLines("category/package/unexpected.txt",
		CvsID)
	t.FinishSetUp()

	pkg := NewPackage(t.File("category/package"))
	pkg.checkDirent(t.File("doc/CHANGES-2018"), 0444)
	pkg.checkDirent(t.File("category/package/buildlink3.mk"), 0444)
	pkg.checkDirent(t.File("category/package/unexpected.txt"), 0444)

	t.CheckOutputLines(
		"NOTE: ~/category/package/buildlink3.mk:2: Trailing empty lines.",
		"WARN: ~/category/package/buildlink3.mk:EOF: Expected a BUILDLINK_TREE line.",
		"WARN: ~/category/package/unexpected.txt: Unexpected file found.")
}

// Since all required information is passed to G.checkDirent via parameters,
// this test produces the expected results even though none of these files actually exists.
func (s *Suite) Test_Package_checkDirent__skipped(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.FinishSetUp()
	t.Chdir("category/package")
	pkg := NewPackage(".")

	pkg.checkDirent("work", os.ModeSymlink)
	pkg.checkDirent("work.i386", os.ModeSymlink)
	pkg.checkDirent("work.hostname", os.ModeSymlink)
	pkg.checkDirent("other", os.ModeSymlink)

	pkg.checkDirent("device", os.ModeDevice)

	t.CheckOutputLines(
		"WARN: other: Invalid symlink name.",
		"ERROR: device: Only files and directories are allowed in pkgsrc.")
}

// In packages without specific MAINTAINER, everyone may commit changes.
func (s *Suite) Test_Package_checkOwnerMaintainer__no_maintainer(c *check.C) {
	t := s.Init(c)

	G.Username = "example-user"
	t.CreateFileLines("category/package/CVS/Entries",
		"/Makefile//modified//")
	t.SetUpPackage("category/package",
		"MAINTAINER=\tpkgsrc-users@NetBSD.org")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputEmpty()
}

// A package with a MAINTAINER may be edited by the maintainer itself.
func (s *Suite) Test_Package_checkOwnerMaintainer__maintainer_equal(c *check.C) {
	t := s.Init(c)

	G.Username = "maintainer"
	t.CreateFileLines("category/package/CVS/Entries",
		"/Makefile//modified//")
	t.SetUpPackage("category/package",
		"MAINTAINER=\tmaintainer@example.org")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputEmpty()
}

// A package with a MAINTAINER may be edited by everyone, with care.
func (s *Suite) Test_Package_checkOwnerMaintainer__maintainer_unequal(c *check.C) {
	t := s.Init(c)

	G.Username = "example-user"
	t.CreateFileLines("category/package/CVS/Entries",
		"/Makefile//modified//")
	t.SetUpPackage("category/package",
		"MAINTAINER=\tmaintainer@example.org")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"NOTE: ~/category/package: " +
			"Please only commit changes that maintainer@example.org would approve.")
}

func (s *Suite) Test_Package_checkOwnerMaintainer__maintainer_unequal_several_files(c *check.C) {
	t := s.Init(c)

	G.Username = "example-user"
	t.CreateFileLines("category/package/CVS/Entries",
		"/Makefile//modified//",
		"/PLIST//modified//",
		"/distinfo//modified//")
	t.SetUpPackage("category/package",
		"MAINTAINER=\tmaintainer@example.org")
	t.Chdir("category/package")
	t.FinishSetUp()
	G.Logger.verbose = false // Suppress duplicate messages

	G.Check(".")

	t.CheckOutputLines(
		"NOTE: Please only commit changes " +
			"that maintainer@example.org would approve.")
}

// A package with an OWNER may be edited by the owner itself.
func (s *Suite) Test_Package_checkOwnerMaintainer__owner_equal(c *check.C) {
	t := s.Init(c)

	G.Username = "owner"
	t.CreateFileLines("category/package/CVS/Entries",
		"/Makefile//modified//")
	t.SetUpPackage("category/package",
		"OWNER=\towner@example.org")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_checkOwnerMaintainer__owner_unequal(c *check.C) {
	t := s.Init(c)

	G.Username = "example-user"
	t.CreateFileLines("category/package/CVS/Entries",
		"/Makefile//modified//")
	t.SetUpPackage("category/package",
		"OWNER=\towner@example.org")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile: " +
			"Don't commit changes to this file without asking the OWNER, owner@example.org.")
}

// In a package with both OWNER and MAINTAINER, OWNER wins.
func (s *Suite) Test_Package_checkOwnerMaintainer__both(c *check.C) {
	t := s.Init(c)

	G.Username = "example-user"
	t.CreateFileLines("category/package/CVS/Entries",
		"/Makefile//modified//")
	t.SetUpPackage("category/package",
		"MAINTAINER=\tmaintainer@example.org",
		"OWNER=\towner@example.org")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile: " +
			"Don't commit changes to this file without asking the OWNER, owner@example.org.")
}

// Just for code coverage.
func (s *Suite) Test_Package_checkOwnerMaintainer__no_tracing(c *check.C) {
	t := s.Init(c)

	G.Username = "example-user"
	t.CreateFileLines("category/package/CVS/Entries",
		"/Makefile//modified//")

	pkg := t.SetUpPackage("category/package",
		"MAINTAINER=\tmaintainer@example.org")
	t.FinishSetUp()
	t.DisableTracing()

	G.Check(pkg)

	t.CheckOutputLines(
		"NOTE: ~/category/package: Please only commit changes " +
			"that maintainer@example.org would approve.")
}

func (s *Suite) Test_Package_checkOwnerMaintainer__directory(c *check.C) {
	t := s.Init(c)

	G.Username = "example-user"
	t.CreateFileLines("category/package/CVS/Entries",
		"/Makefile//modified//",
		"D/patches////")
	t.CreateFileDummyPatch("category/package/patches/patch-aa")

	pkg := t.SetUpPackage("category/package",
		"MAINTAINER=\tmaintainer@example.org")
	t.CreateFileLines("category/package/distinfo",
		CvsID,
		"",
		"SHA1 (patch-aa) = 9a93207561abfef7e7550598c5a08f2c3226995b")
	t.FinishSetUp()

	G.Check(pkg)

	// No warning for the patches directory, only for regular files.
	t.CheckOutputLines(
		"NOTE: ~/category/package: " +
			"Please only commit changes that " +
			"maintainer@example.org would approve.")
}

func (s *Suite) Test_Package_checkOwnerMaintainer__url2pkg(c *check.C) {
	t := s.Init(c)

	G.Username = "example-user"
	pkg := t.SetUpPackage("category/package",
		"MAINTAINER=\tINSERT_YOUR_MAIL_ADDRESS_HERE")
	t.CreateFileLines("category/package/CVS/Entries",
		"/Makefile//modified//")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:8: " +
			"\"INSERT_YOUR_MAIL_ADDRESS_HERE\" is not a valid mail address.")
}

func (s *Suite) Test_Package_checkFreeze(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--explain")
	pkg := t.SetUpPackage("category/package")
	t.CreateFileLines("category/package/CVS/Entries",
		"/Makefile//modified//")
	t.CreateFileLines("doc/CHANGES-2018",
		"\tmk/bsd.pkg.mk: started freeze for 2018Q2 [freezer 2018-03-20]")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputLines(
		"NOTE: ~/category/package/Makefile: Pkgsrc is frozen since 2018-03-20.",
		"",
		"\tDuring a pkgsrc freeze, changes to pkgsrc should only be made very",
		"\tcarefully. See https://www.NetBSD.org/developers/pkgsrc/ for the",
		"\texact rules.",
		"")
}

func (s *Suite) Test_Package_checkFreeze__freeze_ended(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--explain")
	pkg := t.SetUpPackage("category/package")
	t.CreateFileLines("category/package/CVS/Entries",
		"/Makefile//modified//")
	t.CreateFileLines("doc/CHANGES-2018",
		"\tmk/bsd.pkg.mk: started freeze for 2018Q2 [freezer 2018-03-20]",
		"\tmk/bsd.pkg.mk: freeze ended for 2018Q2 [freezer 2018-03-27]")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_checkLinesBuildlink3Inclusion__file_but_not_package(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("category/dependency/buildlink3.mk")
	t.CreateFileLines("category/dependency/module.mk")
	pkg := NewPackage(t.File("category/package"))
	mklines := t.NewMkLines("category/package/buildlink3.mk",
		MkCvsID,
		"",
		".include \"../../category/dependency/buildlink3.mk\"",
		".include \"../../category/dependency/module.mk\"")

	pkg.checkLinesBuildlink3Inclusion(mklines)

	t.CheckOutputLines(
		"WARN: category/package/buildlink3.mk:3: " +
			"../../category/dependency/buildlink3.mk is included by this file " +
			"but not by the package.")
}

// Several files from the pkgsrc infrastructure are named *.buildlink3.mk,
// even though they don't follow the typical file format for buildlink3.mk
// files. Therefore they are ignored by this check.
func (s *Suite) Test_Package_checkLinesBuildlink3Inclusion__infra_buildlink_file(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".include \"../../mk/motif.buildlink3.mk\"")
	t.CreateFileBuildlink3("category/package/buildlink3.mk",
		".include \"../../mk/motif.buildlink3.mk\"")
	t.CreateFileLines("mk/motif.buildlink3.mk",
		MkCvsID)

	t.Main("--quiet", "-Wall", "category/package")

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_checkLinesBuildlink3Inclusion__package_but_not_file(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("category/dependency/buildlink3.mk")
	pkg := NewPackage(t.File("category/package"))
	pkg.bl3["../../category/dependency/buildlink3.mk"] =
		t.NewMkLine("../../category/dependency/buildlink3.mk", 1, "")
	mklines := t.NewMkLines("category/package/buildlink3.mk",
		MkCvsID)

	t.EnableTracingToLog()
	pkg.checkLinesBuildlink3Inclusion(mklines)

	// This is only traced but not logged as a regular warning since
	// several packages have build dependencies that are not needed
	// for building other packages. These cannot be flagged as warnings.
	t.CheckOutputLines(
		"TRACE: + (*Package).checkLinesBuildlink3Inclusion()",
		"TRACE: 1   ../../category/dependency/buildlink3.mk "+
			"is included by the package but not by the buildlink3.mk file.",
		"TRACE: - (*Package).checkLinesBuildlink3Inclusion()")
}

// The file mk/ocaml.mk uses ../.. to reach PKGSRCDIR.
// The canonical path is .. since ocaml.mk is only one directory away
// from PKGSRCDIR.
// Before 2019-12-07, pkglint didn't resolve the resulting path correctly.
func (s *Suite) Test_Package_checkLinesBuildlink3Inclusion__mk_dotdot_dotdot(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("x11/ocaml-graphics",
		".include \"../../mk/ocaml.mk\"")
	t.CreateFileLines("mk/ocaml.mk",
		MkCvsID,
		".include \"../../lang/ocaml/buildlink3.mk\"")
	t.CreateFileLines("lang/ocaml/buildlink3.mk",
		MkCvsID)
	t.Chdir(".")
	t.FinishSetUp()
	pkg := NewPackage("x11/ocaml-graphics")

	files, mklines, allLines := pkg.load()
	pkg.check(files, mklines, allLines)

	t.CheckDeepEquals(
		keys(pkg.bl3),
		[]string{"../../lang/ocaml/buildlink3.mk"})
	t.CheckOutputEmpty()
}

// Ocaml packages include ../../mk/ocaml.mk.
// That file uses the canonical .. to reach PKGSRCDIR,
// not the ../.. that is typically used in packages.
func (s *Suite) Test_Package_checkLinesBuildlink3Inclusion__mk_dotdot(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("x11/ocaml-graphics",
		".include \"../../mk/ocaml.mk\"")
	t.CreateFileLines("mk/ocaml.mk",
		MkCvsID,
		".include \"../lang/ocaml/buildlink3.mk\"")
	t.CreateFileLines("lang/ocaml/buildlink3.mk",
		MkCvsID)
	t.Chdir(".")
	t.FinishSetUp()
	pkg := NewPackage("x11/ocaml-graphics")

	files, mklines, allLines := pkg.load()
	pkg.check(files, mklines, allLines)

	t.CheckDeepEquals(
		keys(pkg.bl3),
		[]string{"../../lang/ocaml/buildlink3.mk"})
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_checkLinesBuildlink3Inclusion__ocaml(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("x11/ocaml-graphics",
		".include \"../../mk/ocaml.mk\"")
	t.CreateFileBuildlink3("x11/ocaml-graphics/buildlink3.mk",
		".include \"../../lang/ocaml/buildlink3.mk\"")
	t.CreateFileLines("mk/ocaml.mk",
		MkCvsID,
		// Note: this is ../.. even though .. is enough.
		".include \"../../lang/ocaml/buildlink3.mk\"")
	t.CreateFileLines("lang/ocaml/buildlink3.mk",
		MkCvsID)
	t.Chdir(".")
	t.FinishSetUp()

	G.Check("mk/ocaml.mk")
	G.checkdirPackage("x11/ocaml-graphics")

	// Up to 2020-02-15, pkglint reported a missing relative path in
	// mk/ocaml.mk:2 since resolving relative paths had not used the
	// correct base directory.
	t.CheckOutputEmpty()
}

// Just for code coverage.
func (s *Suite) Test_Package_checkLinesBuildlink3Inclusion__no_tracing(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileBuildlink3("category/package/buildlink3.mk")
	t.FinishSetUp()

	t.DisableTracing()
	G.Check(t.File("category/package"))

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_checkIncludeConditionally__conditional_and_unconditional_include(c *check.C) {
	t := s.Init(c)

	t.SetUpOption("zlib", "")
	t.SetUpPackage("category/package",
		".include \"../../mk/bsd.prefs.mk\"",
		".include \"../../devel/zlib/buildlink3.mk\"",
		".if ${OPSYS} == \"Linux\"",
		".include \"../../sysutils/coreutils/buildlink3.mk\"",
		".endif")
	t.CreateFileLines("mk/bsd.options.mk", "")
	t.CreateFileLines("devel/zlib/buildlink3.mk", "")
	t.CreateFileLines("sysutils/coreutils/buildlink3.mk", "")

	t.CreateFileLines("category/package/options.mk",
		MkCvsID,
		"",
		"PKG_OPTIONS_VAR=\tPKG_OPTIONS.package",
		"PKG_SUPPORTED_OPTIONS=\tzlib",
		"",
		".include \"../../mk/bsd.options.mk\"",
		"",
		".if !empty(PKG_OPTIONS:Mzlib)",
		".  include \"../../devel/zlib/buildlink3.mk\"",
		".endif",
		".include \"../../sysutils/coreutils/buildlink3.mk\"")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.checkdirPackage(".")

	t.CheckOutputLines(
		"WARN: Makefile:21: \"../../devel/zlib/buildlink3.mk\" is included "+
			"unconditionally here "+
			"and conditionally in options.mk:9 (depending on PKG_OPTIONS).",
		"WARN: Makefile:23: \"../../sysutils/coreutils/buildlink3.mk\" is included "+
			"conditionally here (depending on OPSYS) and "+
			"unconditionally in options.mk:11.")
}

func (s *Suite) Test_Package_checkIncludeConditionally__explain_PKG_OPTIONS_in_Makefile(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--explain")
	t.SetUpOption("zlib", "use zlib compression")

	t.CreateFileLines("mk/bsd.options.mk",
		MkCvsID)
	t.CreateFileLines("devel/zlib/buildlink3.mk",
		MkCvsID)
	t.SetUpPackage("category/package",
		"PKG_OPTIONS_VAR=\tPKG_OPTIONS.package",
		"PKG_SUPPORTED_OPTIONS=\tzlib",
		"",
		".include \"../../mk/bsd.options.mk\"",
		"",
		".if ${PKG_OPTIONS:Mzlib}",
		".include \"../../devel/zlib/buildlink3.mk\"",
		".endif")
	t.CreateFileBuildlink3("category/package/buildlink3.mk",
		".include \"../../devel/zlib/buildlink3.mk\"")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.checkdirPackage(".")

	t.CheckOutputLines(
		"WARN: Makefile:26: "+
			"\"../../devel/zlib/buildlink3.mk\" is included conditionally here "+
			"(depending on PKG_OPTIONS) and unconditionally in buildlink3.mk:12.",
		"",
		"\tWhen including a dependent file, the conditions in the buildlink3.mk",
		"\tfile should be the same as in options.mk or the Makefile.",
		"",
		"\tTo find out the PKG_OPTIONS of this package at build time, have a",
		"\tlook at mk/pkg-build-options.mk.",
		"")
}

func (s *Suite) Test_Package_checkIncludeConditionally__no_explanation(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--explain")
	t.CreateFileLines("devel/zlib/buildlink3.mk",
		MkCvsID)
	t.SetUpPackage("category/package",
		".include \"../../mk/bsd.prefs.mk\"",
		"",
		".if ${OPSYS} == Linux",
		".include \"../../devel/zlib/buildlink3.mk\"",
		".endif")
	t.CreateFileBuildlink3("category/package/buildlink3.mk",
		".include \"../../devel/zlib/buildlink3.mk\"")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.checkdirPackage(".")

	t.CheckOutputLines(
		"WARN: Makefile:23: " +
			"\"../../devel/zlib/buildlink3.mk\" is included conditionally here " +
			"(depending on OPSYS) and unconditionally in buildlink3.mk:12.")
}

func (s *Suite) Test_Package_checkIncludeConditionally__conditionally_no_variable(c *check.C) {
	t := s.Init(c)

	t.SetUpOption("zlib", "")
	t.SetUpPackage("category/package",
		".include \"../../devel/zlib/buildlink3.mk\"",
		".if exists(/usr/include)",
		".include \"../../sysutils/coreutils/buildlink3.mk\"",
		".endif")
	t.CreateFileLines("mk/bsd.options.mk", "")
	t.CreateFileLines("devel/zlib/buildlink3.mk", "")
	t.CreateFileLines("sysutils/coreutils/buildlink3.mk", "")

	t.CreateFileLines("category/package/options.mk",
		MkCvsID,
		"",
		"PKG_OPTIONS_VAR=\tPKG_OPTIONS.package",
		"PKG_SUPPORTED_OPTIONS=\t# none",
		"",
		".include \"../../mk/bsd.options.mk\"",
		"",
		".if exists(/usr/include)",
		".  include \"../../devel/zlib/buildlink3.mk\"",
		".endif",
		".include \"../../sysutils/coreutils/buildlink3.mk\"")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.checkdirPackage(".")

	t.CheckOutputLines(
		"WARN: Makefile:20: \"../../devel/zlib/buildlink3.mk\" "+
			"is included unconditionally here "+
			"and conditionally in options.mk:9.",
		"WARN: Makefile:22: \"../../sysutils/coreutils/buildlink3.mk\" "+
			"is included conditionally here "+
			"and unconditionally in options.mk:11.")
}

func (s *Suite) Test_Package_checkIncludeConditionally__explain_PKG_OPTIONS_in_options_mk(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--explain")
	t.SetUpOption("zlib", "use zlib compression")

	t.CreateFileLines("mk/bsd.options.mk",
		MkCvsID)
	t.CreateFileLines("devel/zlib/buildlink3.mk",
		MkCvsID)
	t.SetUpPackage("category/package",
		".include \"options.mk\"")
	t.CreateFileLines("category/package/options.mk",
		MkCvsID,
		"",
		"PKG_OPTIONS_VAR=\tPKG_OPTIONS.package",
		"PKG_SUPPORTED_OPTIONS=\tzlib",
		"",
		".include \"../../mk/bsd.options.mk\"",
		"",
		".if ${PKG_OPTIONS:Mzlib}",
		".include \"../../devel/zlib/buildlink3.mk\"",
		".endif")
	t.CreateFileBuildlink3("category/package/buildlink3.mk",
		".include \"../../devel/zlib/buildlink3.mk\"")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.checkdirPackage(".")

	t.CheckOutputLines(
		"WARN: buildlink3.mk:12: "+
			"\"../../devel/zlib/buildlink3.mk\" is included unconditionally here "+
			"and conditionally in options.mk:9 (depending on PKG_OPTIONS).",
		"",
		"\tWhen including a dependent file, the conditions in the buildlink3.mk",
		"\tfile should be the same as in options.mk or the Makefile.",
		"",
		"\tTo find out the PKG_OPTIONS of this package at build time, have a",
		"\tlook at mk/pkg-build-options.mk.",
		"")
}

func (s *Suite) Test_Package_checkIncludeConditionally__unconditionally_first(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.Chdir("category/package")
	t.CreateFileLines("including.mk",
		MkCvsID,
		"",
		".include \"../../mk/bsd.prefs.mk\"",
		"",
		".include \"included.mk\"",
		".if ${OPSYS} == \"Linux\"",
		".include \"included.mk\"",
		".endif")
	t.CreateFileLines("included.mk",
		MkCvsID)
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		"WARN: including.mk:5: \"included.mk\" is included " +
			"unconditionally here and conditionally in line 7 (depending on OPSYS).")
}

func (s *Suite) Test_Package_checkIncludeConditionally__only_conditionally(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".include \"../../mk/bsd.prefs.mk\"",
		"",
		".if ${OPSYS} == \"Linux\"",
		".include \"included.mk\"",
		".endif")
	t.Chdir("category/package")
	t.CreateFileLines("included.mk",
		MkCvsID)
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_checkIncludeConditionally__conditionally_first(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.Chdir("category/package")
	t.CreateFileLines("including.mk",
		MkCvsID,
		"",
		".include \"../../mk/bsd.prefs.mk\"",
		"",
		".if ${OPSYS} == \"Linux\"",
		".include \"included.mk\"",
		".endif",
		".include \"included.mk\"")
	t.CreateFileLines("included.mk",
		MkCvsID)
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		"WARN: including.mk:6: \"included.mk\" is included " +
			"conditionally here (depending on OPSYS) and unconditionally in line 8.")
}

func (s *Suite) Test_Package_checkIncludeConditionally__included_multiple_times(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.Chdir("category/package")
	t.CreateFileLines("including.mk",
		MkCvsID,
		"",
		".include \"../../mk/bsd.prefs.mk\"",
		"",
		".include \"included.mk\"",
		".if ${OPSYS} == \"Linux\"",
		".include \"included.mk\"",
		".endif",
		"",
		".include \"included.mk\"",
		".if ${OPSYS} == \"Linux\"",
		".include \"included.mk\"",
		".endif")
	t.CreateFileLines("included.mk",
		MkCvsID)
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		"WARN: including.mk:5: \"included.mk\" is included "+
			"unconditionally here and conditionally in line 12 (depending on OPSYS).",
		"WARN: including.mk:7: \"included.mk\" is included "+
			"conditionally here (depending on OPSYS) and unconditionally in line 10.",
		"WARN: including.mk:10: \"included.mk\" is included "+
			"unconditionally here and conditionally in line 12 (depending on OPSYS).")
}

// For preferences files, it doesn't matter whether they are included
// conditionally or unconditionally since at the end they are included
// anyway by the infrastructure.
func (s *Suite) Test_Package_checkIncludeConditionally__prefs(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.Chdir("category/package")
	t.CreateFileLines("including.mk",
		MkCvsID,
		"",
		".include \"../../mk/bsd.prefs.mk\"",
		".if ${OPSYS} == \"Linux\"",
		".include \"../../mk/bsd.prefs.mk\"",
		".endif")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Package_checkIncludeConditionally__other_directory(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".include \"../../category/package-base/including.mk\"")
	t.CreateFileLines("category/package-base/including.mk",
		MkCvsID,
		"",
		".include \"included.mk\"",
		".if ${OPSYS} == \"Linux\"",
		".include \"included.mk\"",
		".endif",
		"",
		".include \"included.mk\"",
		".if ${OPSYS} == \"Linux\"",
		".include \"included.mk\"",
		".endif")
	t.CreateFileLines("category/package-base/included.mk",
		MkCvsID)

	t.Main("-Wall", "-Call", "category/package")

	// TODO: Understand why ../../category/package-base/including.mk is
	//  not checked for (un)conditional includes.
	t.CheckOutputLines(
		"Looks fine.")
}

// In practice the distinfo file can always be autofixed since it has
// just been read successfully and the corresponding patch file could
// also be autofixed right before.
func (s *Suite) Test_Package_AutofixDistinfo__missing_file(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	pkg := NewPackage(t.File("category/package"))
	t.FinishSetUp()

	pkg.AutofixDistinfo("old", "new")

	t.CheckOutputLines(
		"ERROR: ~/category/package/distinfo: Cannot be read.")
}

func (s *Suite) Test_Package_Includes(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".include \"unconditionally.mk\"",
		".if 0",
		".include \"never.mk\"",
		".endif",
		".if ${OPSYS} == Linux",
		".include \"conditionally.mk\"",
		".endif")
	t.CreateFileLines("category/package/unconditionally.mk",
		MkCvsID)
	t.CreateFileLines("category/package/conditionally.mk",
		MkCvsID)
	t.CreateFileLines("category/package/never.mk",
		MkCvsID)
	t.FinishSetUp()

	pkg := NewPackage(t.File("category/package"))

	pkg.load()

	t.CheckEquals(pkg.Includes("unconditionally.mk") != nil, true)
	t.CheckEquals(pkg.Includes("conditionally.mk") != nil, true)
	t.CheckEquals(pkg.Includes("other.mk") != nil, false)

	// The file never.mk is in conditionalIncludes since pkglint only
	// analyzes on the syntactical level. It doesn't evaluate the
	// condition from the .if to see whether it is satisfiable.
	//
	// See Package.collectConditionalIncludes and Indentation.IsConditional.
	t.CheckEquals(
		pkg.conditionalIncludes["never.mk"].Location,
		NewLocation(t.File("category/package/Makefile"), 22))
}
