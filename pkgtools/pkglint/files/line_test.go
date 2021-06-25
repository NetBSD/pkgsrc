package pkglint

import (
	"gopkg.in/check.v1"
	"netbsd.org/pkglint/regex"
)

func (s *Suite) Test_RawLine_Orig(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("filename", 123, "text")

	t.CheckEquals(line.raw[0].orignl, "text\n")
	t.CheckEquals(line.raw[0].Orig(), "text")
}

func (s *Suite) Test_NewLocation(c *check.C) {
	t := s.Init(c)

	loc := NewLocation("subdir/filename", 123)

	t.CheckEquals(loc.Filename, NewCurrPathString("subdir/filename"))
	t.CheckEquals(loc.lineno, 123)
}

func (s *Suite) Test_Location_Lineno(c *check.C) {
	t := s.Init(c)

	loc := NewLocation("subdir/filename", 123)

	t.CheckEquals(loc.Lineno(0), 123)
}

func (s *Suite) Test_Location_File(c *check.C) {
	t := s.Init(c)

	loc := NewLocation("subdir/filename", 123)

	t.CheckEquals(loc.File("other"), NewCurrPathString("subdir/other"))
}

func (s *Suite) Test_NewLine__assertion(c *check.C) {
	t := s.Init(c)

	t.ExpectAssert(func() { NewLine("filename", 123, "text", nil) })
}

func (s *Suite) Test_NewLineMulti(c *check.C) {
	t := s.Init(c)

	line := NewLineMulti("subdir/filename", 123, "", []*RawLine{nil, nil, nil})

	t.CheckEquals(line.Filename(), NewCurrPathString("subdir/filename"))
	t.CheckEquals(line.Linenos(), "123--125")
}

func (s *Suite) Test_NewLineEOF(c *check.C) {
	t := s.Init(c)

	line := NewLineEOF("subdir/filename")

	t.CheckEquals(line.Filename(), NewCurrPathString("subdir/filename"))
	t.CheckEquals(line.Linenos(), "EOF")
}

func (s *Suite) Test_NewLineWhole(c *check.C) {
	t := s.Init(c)

	line := NewLineWhole("subdir/filename")

	t.CheckEquals(line.Filename(), NewCurrPathString("subdir/filename"))
	t.CheckEquals(line.Linenos(), "")
}

func (s *Suite) Test_Line_Filename(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("subdir/filename", 123, "")

	t.CheckEquals(line.Filename(), NewCurrPathString("subdir/filename"))
}

func (s *Suite) Test_Line_File(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("subdir/filename", 123, "")

	t.CheckEquals(line.File("subsub/nested"),
		NewCurrPathString("subdir/subsub/nested"))
}

func (s *Suite) Test_Line_Linenos(c *check.C) {
	t := s.Init(c)

	single := t.NewLine("filename", 123, "")
	whole := NewLineWhole("filename")
	multi := NewLineMulti("filename", 123, "text", []*RawLine{nil, nil, nil})

	t.CheckEquals(single.Linenos(), "123")
	t.CheckEquals(whole.Linenos(), "")
	t.CheckEquals(multi.Linenos(), "123--125")
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

func (s *Suite) Test_Line_Rel(c *check.C) {
	t := s.Init(c)

	t.Chdir(".")
	line1 := t.NewLine("subdir/filename", 123, "from")

	rel := line1.Rel("other/filename")

	t.CheckEquals(rel, NewRelPathString("../other/filename"))
}

func (s *Suite) Test_Line_IsMultiline(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(t.NewLine("filename", 123, "text").IsMultiline(), false)

	t.CheckEquals(NewLineEOF("filename").IsMultiline(), false)

	multi := NewLineMulti("filename", 123, "text", []*RawLine{nil, nil, nil})
	t.CheckEquals(multi.IsMultiline(), true)
}

func (s *Suite) Test_Line_RawText(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--show-autofix")
	line := t.NewLine("filename", 123, "text")

	t.CheckEquals(line.RawText(0), "text")

	fix := line.Autofix()
	fix.Notef("Replacing.")
	fix.Replace("text", "replaced")
	fix.Apply()

	t.CheckEquals(line.RawText(0), "replaced")

	t.CheckOutputLines(
		"NOTE: filename:123: Replacing.",
		"AUTOFIX: filename:123: Replacing \"text\" with \"replaced\".")
}

func (s *Suite) Test_Line_IsCvsID(c *check.C) {
	t := s.Init(c)

	test := func(text string, prefix regex.Pattern, expectedID bool, expectedExpanded bool) {
		line := t.NewLine("filename", 123, text)

		id, expanded := line.IsCvsID(prefix)

		t.CheckEquals(id, expectedID)
		t.CheckEquals(expanded, expectedExpanded)
	}

	test(CvsID, ``, true, false)

	test("$"+"NetBSD: ... $", ``, true, true)
}

func (s *Suite) Test_Line_Errorf(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("filename", 123, "text")

	line.Errorf("For your information.")

	t.CheckOutputLines(
		"ERROR: filename:123: For your information.")
}

func (s *Suite) Test_Line_Warnf(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("filename", 123, "text")

	line.Warnf("For your information.")

	t.CheckOutputLines(
		"WARN: filename:123: For your information.")
}

func (s *Suite) Test_Line_Notef(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("filename", 123, "text")

	line.Notef("For your information.")

	t.CheckOutputLines(
		"NOTE: filename:123: For your information.")
}

func (s *Suite) Test_Line_Explain(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--explain")
	line := t.NewLine("filename", 123, "text")

	line.Notef("For your information.")
	line.Explain(
		"First line",
		"continues.")

	t.CheckOutputLines(
		"NOTE: filename:123: For your information.",
		"",
		"\tFirst line continues.",
		"")
}

func (s *Suite) Test_Line_Explain__without_diagnostic(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--explain")
	line := t.NewLine("filename", 123, "text")

	// It is unusual to have an explanation without any preceding
	// diagnostic.
	line.Explain(
		"First line",
		"continues.")

	// There is no empty line above the explanation since that is the
	// job of the SeparatorWriter, which only steps in if there is a
	// diagnostic above the explanation.
	t.CheckOutputLines(
		"\tFirst line continues.",
		"")
}

func (s *Suite) Test_Line_String(c *check.C) {
	t := s.Init(c)

	line := t.NewLine("filename", 123, "text")
	t.CheckEquals(line.String(), "filename:123: text")

	// Since Line.String is only used for debugging purposes, trailing
	// whitespace is OK.
	t.CheckEquals(NewLineEOF("filename").String(), "filename:EOF: ")

	multi := NewLineMulti("filename", 123, "text", []*RawLine{nil, nil, nil})
	t.CheckEquals(multi.String(), "filename:123--125: text")
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
