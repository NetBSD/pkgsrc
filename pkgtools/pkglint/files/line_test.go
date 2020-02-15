package pkglint

import (
	"gopkg.in/check.v1"
)

func (s *Suite) Test_NewLine__assertion(c *check.C) {
	t := s.Init(c)

	t.ExpectAssert(func() { NewLine("filename", 123, "text", nil) })
}

func (s *Suite) Test_Line_RelLine__assertion(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("filename", 123, "")
	whole := NewLineWhole("filename")

	t.ExpectAssert(func() { line.RelLine(whole) })
}

func (s *Suite) Test_Line_RelLocation__assertion(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("filename", 123, "")
	whole := NewLineWhole("filename")

	t.ExpectAssert(func() { line.RelLocation(whole.Location) })
}

func (s *Suite) Test_Line_IsMultiline(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(t.NewLine("filename", 123, "text").IsMultiline(), false)
	t.CheckEquals(NewLineEOF("filename").IsMultiline(), false)

	t.CheckEquals(NewLineMulti("filename", 123, "text", []*RawLine{nil, nil, nil}).IsMultiline(), true)
}

func (s *Suite) Test_Line_Autofix__reuse_incomplete(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("filename.mk", 1, "")

	fix := line.Autofix()
	fix.Warnf("Warning.")
	// For some reason, the other required calls are left out.

	t.ExpectAssert(func() { _ = line.Autofix() })

	// Properly finish the standard call sequence for an Autofix.
	fix.Apply()

	t.CheckOutputLines(
		"WARN: filename.mk:1: Warning.")
}
