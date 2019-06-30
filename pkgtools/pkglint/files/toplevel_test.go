package pkglint

import "gopkg.in/check.v1"

func (s *Suite) Test_CheckdirToplevel(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("Makefile",
		MkCvsID,
		"",
		"SUBDIR+= x11",
		"SUBDIR+=\tarchivers",
		"SUBDIR+=\tccc",
		"SUBDIR+=\tccc",
		"#SUBDIR+=\tignoreme",
		"SUBDIR+=\tnonexisting", // This doesn't happen in practice, therefore no warning.
		"SUBDIR+=\tbbb",
		"SUBDIR+=\t${SITE_SPECIFIC_PKGS}")
	t.CreateFileLines("archivers/Makefile")
	t.CreateFileLines("bbb/Makefile")
	t.CreateFileLines("ccc/Makefile")
	t.CreateFileLines("x11/Makefile")
	t.SetUpVartypes()

	CheckdirToplevel(t.File("."))

	t.CheckOutputLines(
		"WARN: ~/Makefile:3: Indentation should be a single tab character.",
		"ERROR: ~/Makefile:6: Each subdir must only appear once.",
		"WARN: ~/Makefile:7: \"ignoreme\" commented out without giving a reason.",
		"WARN: ~/Makefile:9: bbb should come before ccc.",

		// This warning is at the very end because mklines.Check() is called at the end.
		// Ideally it would be at the same place as the other warning from Makefile:3.
		"NOTE: ~/Makefile:3: This variable value should be aligned with tabs, not spaces, to column 17.")
}

func (s *Suite) Test_Toplevel_checkSubdir__sorting_x11(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("Makefile",
		MkCvsID,
		"",
		"SUBDIR+=\tx11",
		"SUBDIR+=\tsysutils",
		"SUBDIR+=\tarchivers")
	t.CreateFileLines("archivers/Makefile")
	t.CreateFileLines("sysutils/Makefile")
	t.CreateFileLines("x11/Makefile")
	t.SetUpVartypes()

	CheckdirToplevel(t.File("."))

	t.CheckOutputLines(
		"WARN: ~/Makefile:4: sysutils should come before x11.",
		"WARN: ~/Makefile:5: archivers should come before sysutils.")
}

func (s *Suite) Test_Toplevel_checkSubdir__commented_without_reason(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("Makefile",
		MkCvsID,
		"",
		"#SUBDIR+=\taaa",
		"#SUBDIR+=\tbbb\t#",
		"#SUBDIR+=\tccc\t# reason")
	t.CreateFileLines("aaa/Makefile")
	t.CreateFileLines("bbb/Makefile")
	t.CreateFileLines("ccc/Makefile")
	t.SetUpVartypes()

	CheckdirToplevel(t.File("."))

	t.CheckOutputLines(
		"WARN: ~/Makefile:3: \"aaa\" commented out without giving a reason.",
		"WARN: ~/Makefile:4: \"bbb\" commented out without giving a reason.")
}

func (s *Suite) Test_CheckdirToplevel__recursive(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("mk/misc/category.mk",
		MkCvsID)
	t.SetUpPackage("category/package",
		"UNKNOWN=\tvalue")
	t.CreateFileLines("Makefile",
		MkCvsID,
		"",
		"SUBDIR+=\tcategory")
	t.CreateFileLines("category/Makefile",
		MkCvsID,
		"",
		"COMMENT=\tThe category",
		"",
		"SUBDIR+=\tpackage",
		"",
		".include \"../mk/misc/category.mk\"")

	t.Main("-Wall", "-r", ".")

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:20: UNKNOWN is defined but not used.",
		"0 errors and 1 warning found.",
		"(Run \"pkglint -e\" to show explanations.)")
}

func (s *Suite) Test_CheckdirToplevel__recursive_inter_package(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("mk/misc/category.mk",
		MkCvsID)
	t.SetUpPackage("category/package",
		"UNKNOWN=\tvalue")
	t.CreateFileLines("Makefile",
		MkCvsID,
		"",
		"SUBDIR+=\tcategory")
	t.CreateFileLines("category/Makefile",
		MkCvsID,
		"",
		"COMMENT=\tThe category",
		"",
		"SUBDIR+=\tpackage",
		"",
		".include \"../mk/misc/category.mk\"")

	t.Main("-Wall", "-Call", "-r", ".")

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:20: UNKNOWN is defined but not used.",
		"WARN: ~/licenses/gnu-gpl-v2: This license seems to be unused.",
		"0 errors and 2 warnings found.",
		"(Run \"pkglint -e\" to show explanations.)")
}
