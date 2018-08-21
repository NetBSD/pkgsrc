package main

import (
	"gopkg.in/check.v1"
)

func (s *Suite) Test_Line_log__gcc_format(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--gcc-output-format")
	line := t.NewLine("filename", 123, "text")

	line.Notef("Diagnostics can be logged in GCC-style.")

	t.CheckOutputLines(
		"filename:123: note: Diagnostics can be logged in GCC-style.")
}

func (s *Suite) Test_Line_log__print_source(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--show-autofix", "--source")
	line := t.NewLine("filename", 123, "text")

	fix := line.Autofix()
	fix.Notef("Diagnostics can show the differences in autofix mode.")
	fix.InsertBefore("new line before")
	fix.InsertAfter("new line after")
	fix.Apply()

	t.CheckOutputLines(
		"NOTE: filename:123: Diagnostics can show the differences in autofix mode.",
		"AUTOFIX: filename:123: Inserting a line \"new line before\" before this line.",
		"AUTOFIX: filename:123: Inserting a line \"new line after\" after this line.",
		"+\tnew line before",
		">\ttext",
		"+\tnew line after")
}

func (s *Suite) Test_RawLine_String(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("filename", 123, "text")

	c.Check(line.raw[0].String(), equals, "123:text\n")
}
