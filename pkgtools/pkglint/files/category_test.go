package pkglint

import "gopkg.in/check.v1"

func (s *Suite) Test_CheckdirCategory__totally_broken(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.CreateFileLines("archivers/Makefile",
		"# $",
		"SUBDIR+=pkg1",
		"SUBDIR+= aaaaa",
		"SUBDIR-=unknown #doesn\u2019t work",
		"",
		".include \"../mk/category.mk\"")

	CheckdirCategory(t.File("archivers"), false)

	t.CheckOutputLines(
		"ERROR: ~/archivers/Makefile:1: Expected \"# $"+"NetBSD$\".",
		"WARN: ~/archivers/Makefile:4: Line contains invalid characters (U+2019).",
		"WARN: ~/archivers/Makefile:4: SUBDIR- is defined but not used.",
		"NOTE: ~/archivers/Makefile:2: This variable value should be aligned to column 17 instead of 9.",
		"NOTE: ~/archivers/Makefile:3: This variable value should be aligned with tabs, not spaces, to column 17 instead of 10.",
		"NOTE: ~/archivers/Makefile:4: This variable value should be aligned to column 17 instead of 9.",
		"ERROR: ~/archivers/Makefile:6: Relative path \"../mk/category.mk\" does not exist.",
		"NOTE: ~/archivers/Makefile:2: Empty line expected above this line.",
		"ERROR: ~/archivers/Makefile:2: COMMENT= line expected.",
		"NOTE: ~/archivers/Makefile:2: Empty line expected above this line.",
		"WARN: ~/archivers/Makefile:3: \"aaaaa\" should come before \"pkg1\".",
		"ERROR: ~/archivers/Makefile:4: SUBDIR+= line or empty line expected.",
		"ERROR: ~/archivers/Makefile:2: \"pkg1\" does not contain a package.",
		"ERROR: ~/archivers/Makefile:3: \"aaaaa\" does not contain a package.",
		"NOTE: ~/archivers/Makefile:4: Empty line expected above this line.",
		"WARN: ~/archivers/Makefile:4: This line should consist of the following text: .include \"../mk/misc/category.mk\"",
		"ERROR: ~/archivers/Makefile:4: The file must end here.")
}

func (s *Suite) Test_CheckdirCategory__invalid_comment(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.CreateFileLines("archivers/Makefile",
		MkCvsID,
		"",
		"COMMENT=\t\\Make $$$$ fast\"",
		"",
		"SUBDIR+=\tpackage",
		"",
		".include \"../mk/misc/category.mk\"")
	t.CreateFileLines("archivers/package/Makefile",
		"# dummy")
	t.CreateFileLines("mk/misc/category.mk",
		"# dummy")

	CheckdirCategory(t.File("archivers"), true)

	t.CheckOutputLines(
		"WARN: ~/archivers/Makefile:3: COMMENT contains invalid characters (\\ $ $ $ $ \").")
}

// The pkgsrc-wip Makefile has a large section with special code below
// the SUBDIR list. This section is skipped by pkglint since it is assumed
// to work.
//
// In all other category files, pkglint checks that directly after the
// SUBDIR section there is only an empty line and the .include line.
func (s *Suite) Test_CheckdirCategory__wip(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/misc/category.mk")
	t.CreateFileLines("wip/package/Makefile")
	t.CreateFileLines("wip/Makefile",
		MkCvsID,
		"",
		"COMMENT=\tCategory comment",
		"",
		"SUBDIR+=\tpackage",
		"",
		"wip-specific-target: .PHONY",
		"\t${RUN}wip-specific-command",
		"",
		".include \"../mk/misc/category.mk\"")
	t.FinishSetUp()

	G.Check(t.File("wip"))

	t.CheckOutputLines(
		"WARN: ~/wip/Makefile:8: Unknown shell command \"wip-specific-command\".")
}

func (s *Suite) Test_CheckdirCategory__subdirs(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/misc/category.mk")
	t.CreateFileLines("category/in-wrong-order/Makefile")
	t.CreateFileLines("category/duplicate/Makefile")
	t.CreateFileLines("category/fs-only/Makefile")
	t.CreateFileLines("category/mk-and-fs/Makefile")
	t.CreateFileLines("category/commented-mk-and-fs/Makefile")
	t.CreateFileLines("category/commented-without-reason/Makefile")
	t.CreateFileLines("category/Makefile",
		MkCvsID,
		"",
		"COMMENT=\tCategory comment",
		"",
		"SUBDIR+=\tduplicate",
		"SUBDIR+=\tin-wrong-order",
		"SUBDIR+=\tduplicate",
		"SUBDIR+=\tmk-and-fs",
		"SUBDIR+=\tmk-only",
		"#SUBDIR+=\tcommented-mk-and-fs\t# Reason",
		"#SUBDIR+=\tcommented-mk-only\t# Reason",
		"#SUBDIR+=\tcommented-without-reason",
		"",
		".include \"../mk/misc/category.mk\"")
	t.FinishSetUp()

	CheckdirCategory(t.File("category"), false)

	t.CheckOutputLines(
		"ERROR: ~/category/Makefile:7: \"duplicate\" must only appear once, already seen in line 5.",
		"WARN: ~/category/Makefile:7: \"duplicate\" should come before \"in-wrong-order\".",
		"WARN: ~/category/Makefile:10: \"commented-mk-and-fs\" should come before \"mk-only\".",
		"WARN: ~/category/Makefile:12: \"commented-without-reason\" commented out without giving a reason.",
		"ERROR: ~/category/Makefile:6: Package \"fs-only\" must be listed here.",
		"ERROR: ~/category/Makefile:9: \"mk-only\" does not contain a package.",
		"ERROR: ~/category/Makefile:11: \"commented-mk-only\" does not contain a package.")
}

func (s *Suite) Test_CheckdirCategory__only_in_Makefile(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/misc/category.mk")
	t.CreateFileLines("category/both/Makefile")
	t.CreateFileLines("category/Makefile",
		MkCvsID,
		"",
		"COMMENT=\tCategory comment",
		"",
		"SUBDIR+=\tabove-only-in-makefile",
		"SUBDIR+=\tboth",
		"SUBDIR+=\tonly-in-makefile",
		"",
		".include \"../mk/misc/category.mk\"")
	t.FinishSetUp()

	CheckdirCategory(t.File("category"), false)

	t.CheckOutputLines(
		"ERROR: ~/category/Makefile:5: "+
			"\"above-only-in-makefile\" does not contain a package.",
		"ERROR: ~/category/Makefile:7: "+
			"\"only-in-makefile\" does not contain a package.")
}

func (s *Suite) Test_CheckdirCategory__only_in_file_system(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/misc/category.mk")
	t.CreateFileLines("category/above-only-in-fs/Makefile")
	t.CreateFileLines("category/both/Makefile")
	t.CreateFileLines("category/only-in-fs/Makefile")
	t.CreateFileLines("category/Makefile",
		MkCvsID,
		"",
		"COMMENT=\tCategory comment",
		"",
		"SUBDIR+=\tboth",
		"",
		".include \"../mk/misc/category.mk\"")
	t.FinishSetUp()

	CheckdirCategory(t.File("category"), false)

	t.CheckOutputLines(
		"ERROR: ~/category/Makefile:5: Package \"above-only-in-fs\" must be listed here.",
		"ERROR: ~/category/Makefile:6: Package \"only-in-fs\" must be listed here.")
}

func (s *Suite) Test_CheckdirCategory__recursive(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-r")
	t.SetUpPkgsrc()
	t.CreateFileLines("mk/misc/category.mk")
	t.CreateFileLines("category/commented/Makefile")
	t.CreateFileLines("category/package/Makefile")
	t.CreateFileLines("category/Makefile",
		MkCvsID,
		"",
		"COMMENT=\tCategory comment",
		"",
		"#SUBDIR+=\tcommented\t# reason",
		"SUBDIR+=\tpackage",
		"",
		".include \"../mk/misc/category.mk\"")
	t.Chdir("category")
	t.FinishSetUp()

	// The default argument "." is added when parsing the command line.
	// It is only removed in Pkglint.Main, therefore it stays there even
	// after the call to CheckdirCategory. This is a bit unrealistic,
	// but close enough for this test.
	t.CheckDeepEquals(G.Todo.entries, []CurrPath{"."})

	CheckdirCategory(".", true)

	t.CheckOutputEmpty()
	t.CheckDeepEquals(G.Todo.entries, []CurrPath{"./package", "."})
}

// Ensures that a directory in the file system can be added at the very
// end of the SUBDIR list. This case takes a different code path than
// an addition in the middle.
//
// The warning appears in the empty line below the SUBDIR lines
// since the new SUBDIR would be inserted before that empty line.
// It would have also been possible to insert the new SUBDIR after
// the last SUBDIR line, but that would have been three more lines of code.
func (s *Suite) Test_CheckdirCategory__subdirs_file_system_at_the_bottom(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--show-autofix")
	t.SetUpPkgsrc()
	t.CreateFileLines("mk/misc/category.mk")
	t.CreateFileLines("category/mk-and-fs/Makefile")
	t.CreateFileLines("category/zzz-fs-only/Makefile")
	t.CreateFileLines("category/Makefile",
		MkCvsID,
		"",
		"COMMENT=\tCategory comment",
		"",
		"SUBDIR+=\tmk-and-fs",
		"",
		".include \"../mk/misc/category.mk\"")
	t.FinishSetUp()

	CheckdirCategory(t.File("category"), false)

	t.CheckOutputLines(
		"ERROR: ~/category/Makefile:6: Package \"zzz-fs-only\" must be listed here.",
		"AUTOFIX: ~/category/Makefile:6: Inserting a line \"SUBDIR+=\\tzzz-fs-only\" above this line.")
}

func (s *Suite) Test_CheckdirCategory__indentation(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/misc/category.mk")
	t.CreateFileLines("category/package1/Makefile")
	t.CreateFileLines("category/package2/Makefile")
	t.CreateFileLines("category/Makefile",
		MkCvsID,
		"",
		"COMMENT=\tCategory comment",
		"",
		"SUBDIR+=                    package1",
		"SUBDIR+=\tpackage2",
		"",
		".include \"../mk/misc/category.mk\"")
	t.FinishSetUp()

	CheckdirCategory(t.File("category"), false)

	t.CheckOutputLines(
		"NOTE: ~/category/Makefile:5: This variable value should be aligned " +
			"with tabs, not spaces, to column 17 instead of 29.")
}

func (s *Suite) Test_CheckdirCategory__comment_at_the_top(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/misc/category.mk")
	t.CreateFileLines("category/package/Makefile")
	t.CreateFileLines("category/Makefile",
		MkCvsID,
		"",
		"# This category collects all programs that don't fit anywhere else.",
		"",
		"COMMENT=\tCategory comment",
		"",
		"SUBDIR+=\tpackage",
		"",
		".include \"../mk/misc/category.mk\"")
	t.FinishSetUp()

	CheckdirCategory(t.File("category"), false)

	// These are quite a few warnings and errors, just because there is
	// an additional comment above the COMMENT definition.
	// On the other hand, the category Makefiles are so simple and their
	// structure has been fixed for at least 20 years, therefore this case
	// is rather exotic anyway.
	t.CheckOutputLines(
		"ERROR: ~/category/Makefile:3: COMMENT= line expected.",
		"NOTE: ~/category/Makefile:3: Empty line expected above this line.",
		"ERROR: ~/category/Makefile:3: SUBDIR+= line or empty line expected.",
		"ERROR: ~/category/Makefile:3: Package \"package\" must be listed here.",
		"NOTE: ~/category/Makefile:3: Empty line expected above this line.",
		"WARN: ~/category/Makefile:3: This line should consist of the following text: .include \"../mk/misc/category.mk\"",
		"ERROR: ~/category/Makefile:3: The file must end here.")
}

func (s *Suite) Test_CheckdirCategory__unexpected_EOF_while_reading_SUBDIR(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/misc/category.mk")
	t.CreateFileLines("category/package/Makefile")
	t.CreateFileLines("category/Makefile",
		MkCvsID,
		"",
		"COMMENT=\tCategory comment",
		"",
		"SUBDIR+=\tpackage")
	t.FinishSetUp()

	CheckdirCategory(t.File("category"), false)

	// Doesn't happen in practice since categories are created very seldom.
	t.CheckOutputLines(
		"NOTE: ~/category/Makefile:5: Empty line expected below this line.",
		"WARN: ~/category/Makefile:EOF: This line should consist of the following text: "+
			".include \"../mk/misc/category.mk\"")
}

func (s *Suite) Test_CheckdirCategory__no_Makefile(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("category/other-file")
	t.FinishSetUp()

	G.Check(t.File("category"))

	t.CheckOutputLines(
		"ERROR: ~/category/Makefile: Cannot be read.")
}

func (s *Suite) Test_CheckdirCategory__case_mismatch(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/misc/category.mk")
	t.CreateFileLines("category/p5-Net-DNS/Makefile")
	t.CreateFileLines("category/Makefile",
		MkCvsID,
		"",
		"COMMENT=\tCategory comment",
		"",
		"SUBDIR+=\tp5-net-dns",
		"",
		".include \"../mk/misc/category.mk\"")
	t.FinishSetUp()

	G.Check(t.File("category"))

	t.CheckOutputLines(
		"ERROR: ~/category/Makefile:5: "+
			"Package \"p5-Net-DNS\" must be listed here.",
		"ERROR: ~/category/Makefile:5: "+
			"\"p5-net-dns\" does not contain a package.")
}

func (s *Suite) Test_CheckdirCategory__dot(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/misc/category.mk")
	t.CreateFileLines("category/Makefile",
		MkCvsID,
		"",
		"COMMENT=\tCategory comment",
		"",
		"SUBDIR+=\tpackage",
		"",
		".include \"../mk/misc/category.mk\"")
	t.Chdir("category")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		"ERROR: Makefile:5: \"package\" does not contain a package.")
}

func (s *Suite) Test_CheckdirCategory__absolute(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/misc/category.mk")
	t.CreateFileLines("category/Makefile",
		MkCvsID,
		"",
		"COMMENT=\tCategory comment",
		"",
		"SUBDIR+=\t/other",
		"",
		".include \"../mk/misc/category.mk\"")
	t.Chdir("category")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		"WARN: Makefile:5: The filename \"/other\" "+
			"contains the invalid character \"/\".",
		"ERROR: Makefile:5: \"/other\" must be a relative path.")
}

func (s *Suite) Test_CheckdirCategory__subdir_that_is_not_a_package(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/misc/category.mk")
	t.CreateFileLines("category/Makefile",
		MkCvsID,
		"",
		"COMMENT=\tCategory comment",
		"",
		"SUBDIR+=\tsub2",
		"",
		".include \"../mk/misc/category.mk\"")
	t.CreateFileLines("category/sub1/module.mk")
	t.CreateFileLines("category/sub2/module.mk")
	t.Chdir("category")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		"ERROR: Makefile:5: \"sub2\" does not contain a package.")
}

func (s *Suite) Test_CheckdirCategory__case_insensitive_file_system(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/PACKAGE")
	t.SetUpPackage("category/Package") // may overwrite PACKAGE
	t.SetUpPackage("category/package") // may overwrite PACKAGE
	t.CreateFileLines("mk/misc/category.mk")
	t.CreateFileLines("category/Makefile",
		MkCvsID,
		"",
		"COMMENT=\tCategory comment",
		"",
		"SUBDIR+=\tPACKAGE",
		"SUBDIR+=\tPackage",
		"SUBDIR+=\tpackage",
		"",
		".include \"../mk/misc/category.mk\"")
	t.Chdir("category")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		"ERROR: Makefile:6: On case-insensitive file systems, "+
			"\"Package\" is the same as \"PACKAGE\" from line 5.",
		"ERROR: Makefile:7: On case-insensitive file systems, "+
			"\"package\" is the same as \"PACKAGE\" from line 5.")
}

func (s *Suite) Test_CheckPackageDirCollision__main(c *check.C) {
	t := s.Init(c)

	// on case-insensitive filesystems, the packages 'Package' and 'package'
	// overwrite 'PACKAGE'.
	t.SetUpPackage("category/PACKAGE")
	t.SetUpPackage("category/Package")
	t.SetUpPackage("category/package")
	t.CreateFileLines("mk/misc/category.mk")
	t.Chdir("category/package")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		"ERROR: ../Makefile:5: On case-insensitive file systems, "+
			"\"PACKAGE\" is the same as \"package\".",
		"ERROR: ../Makefile:6: On case-insensitive file systems, "+
			"\"Package\" is the same as \"package\".")
}

func (s *Suite) Test_CheckPackageDirCollision__wip(c *check.C) {
	t := s.Init(c)

	// on case-insensitive filesystems, the package 'Package' overwrites
	// 'PACKAGE'.
	t.SetUpPackage("category/PACKAGE")
	t.SetUpPackage("category/Package")
	t.SetUpPackage("wip/package",
		"CATEGORIES=\tcategory")
	t.CreateFileLines("mk/misc/category.mk")
	t.Chdir("wip/package")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		"ERROR: ../../category/Makefile:5: "+
			"On case-insensitive file systems, "+
			"\"PACKAGE\" is the same as \"package\".",
		"ERROR: ../../category/Makefile:6: "+
			"On case-insensitive file systems, "+
			"\"Package\" is the same as \"package\".")
}
