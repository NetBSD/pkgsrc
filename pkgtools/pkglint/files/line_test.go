package main

import (
	"gopkg.in/check.v1"
)

func (s *Suite) Test_Line_log__gcc_format(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--gcc-output-format")
	line := t.NewLine("fileName", 123, "text")

	line.Notef("Diagnostics can be logged in GCC-style.")

	t.CheckOutputLines(
		"fileName:123: note: Diagnostics can be logged in GCC-style.")
}

func (s *Suite) Test_Line_log__print_source(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--show-autofix", "--source")
	line := t.NewLine("fileName", 123, "text")

	fix := line.Autofix()
	fix.Notef("Diagnostics can show the differences in autofix mode.")
	fix.InsertBefore("new line before")
	fix.InsertAfter("new line after")
	fix.Apply()

	t.CheckOutputLines(
		"NOTE: fileName:123: Diagnostics can show the differences in autofix mode.",
		"AUTOFIX: fileName:123: Inserting a line \"new line before\" before this line.",
		"AUTOFIX: fileName:123: Inserting a line \"new line after\" after this line.",
		"+\tnew line before",
		">\ttext",
		"+\tnew line after")
}

// Ensures that when two packages produce a warning in the same file, both the
// warning and the corresponding source code are logged only once.
func (s *Suite) Test_Line_showSource__duplicates(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()
	t.CreateFileLines("category/dependency/patches/patch-aa",
		RcsID,
		"",
		"--- old file",
		"+++ new file",
		"@@ -1,1 +1,1 @@",
		"-old line",
		"+new line")
	t.SetupPackage("category/package1",
		"PATCHDIR=\t../../category/dependency/patches")
	t.SetupPackage("category/package2",
		"PATCHDIR=\t../../category/dependency/patches")

	G.Main("pkglint", "--source", "-Wall", t.File("category/package1"), t.File("category/package2"))

	t.CheckOutputLines(
		"ERROR: ~/category/package1/distinfo: patch \"../dependency/patches/patch-aa\" "+
			"is not recorded. Run \""+confMake+" makepatchsum\".",
		"",
		">\t--- old file",
		"ERROR: ~/category/dependency/patches/patch-aa:3: Each patch must be documented.",
		"",
		"ERROR: ~/category/package2/distinfo: patch \"../dependency/patches/patch-aa\" "+
			"is not recorded. Run \""+confMake+" makepatchsum\".",
		"",
		">\t--- old file",
		// FIXME: The above source line is missing a diagnostic.
		"",
		"3 errors and 0 warnings found.",
		"(Run \"pkglint -e\" to show explanations.)")
}

func (s *Suite) Test_RawLine_String(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("fileName", 123, "text")

	c.Check(line.raw[0].String(), equals, "123:text\n")
}
