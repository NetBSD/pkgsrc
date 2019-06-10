package pkglint

import "gopkg.in/check.v1"

func (s *Suite) Test_Paragraph_Clear(c *check.C) {
	t := s.Init(c)

	para := NewParagraph(nil)

	para.Clear()

	t.Check(para.mklines, check.IsNil)

	para.Add(t.NewMkLine("filename.mk", 123, "#"))

	para.Clear()

	t.Check(para.mklines, check.IsNil)
}

func (s *Suite) Test_Paragraph_Add__empty_line(c *check.C) {
	t := s.Init(c)

	para := NewParagraph(nil)

	para.Clear()

	t.Check(para.mklines, check.IsNil)

	t.ExpectPanic(
		func() { para.Add(t.NewMkLine("filename.mk", 123, "")) },
		"Pkglint internal error: A paragraph must not contain empty lines.")
}

func (s *Suite) Test_Paragraph_Align(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--autofix")
	mklines := t.SetUpFileMkLines("filename.mk",
		MkRcsID,
		"VAR=value",
		"VAR=\t\t\tvalue")
	para := NewParagraph(nil)
	for _, mkline := range mklines.mklines {
		// Strictly speaking, lines 1 and 2 don't belong to the paragraph,
		// but aligning the lines works nevertheless.
		para.Add(mkline)
	}

	para.Align()
	mklines.SaveAutofixChanges()

	t.CheckOutputLines(
		"AUTOFIX: ~/filename.mk:2: Replacing \"\" with \"\\t\".",
		"AUTOFIX: ~/filename.mk:3: Replacing \"\\t\\t\\t\" with \"\\t\".")

	t.CheckFileLinesDetab("filename.mk",
		MkRcsID,
		"VAR=    value",
		"VAR=    value")
}

func (s *Suite) Test_Paragraph_AlignTo(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--autofix")
	mklines := t.SetUpFileMkLines("filename.mk",
		MkRcsID,
		"VAR=value",
		"VAR=\t\tvalue",
		"VAR=\t \tvalue",
		"VAR=\t\t\tvalue")
	para := NewParagraph(nil)
	for _, mkline := range mklines.mklines {
		// Strictly speaking, lines 1 and 2 don't belong to the paragraph,
		// but aligning the lines works nevertheless.
		para.Add(mkline)
	}

	para.AlignTo(16)
	mklines.SaveAutofixChanges()

	t.CheckOutputLines(
		"AUTOFIX: ~/filename.mk:2: Replacing \"\" with \"\\t\\t\".",
		"AUTOFIX: ~/filename.mk:4: Replacing \"\\t \\t\" with \"\\t\\t\".",
		"AUTOFIX: ~/filename.mk:5: Replacing \"\\t\\t\\t\" with \"\\t\\t\".")

	t.CheckFileLinesDetab("filename.mk",
		MkRcsID,
		"VAR=            value",
		"VAR=            value",
		"VAR=            value",
		"VAR=            value")
}

func (s *Suite) Test_Paragraph_AlignTo__continued_lines(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--autofix")
	mklines := t.SetUpFileMkLines("filename.mk",
		MkRcsID,
		"VAR= \\",
		"  value",
		"VAR= value1 \\",
		"value2 \\",
		"\t\tvalue3")
	para := NewParagraph(nil)
	for _, mkline := range mklines.mklines {
		para.Add(mkline)
	}

	para.AlignTo(16)
	mklines.SaveAutofixChanges()

	t.CheckOutputLines(
		"AUTOFIX: ~/filename.mk:4: Replacing \" \" with \"\\t\\t\".")

	t.CheckFileLinesDetab("filename.mk",
		MkRcsID,
		// Since this line does not contain the actual value, it doesn't need to be aligned.
		"VAR= \\",
		"  value",
		"VAR=            value1 \\",
		// TODO: The continuation lines should be indented with at least one tab.
		"value2 \\",
		"                value3")
}

func (s *Suite) Test_Paragraph_AlignTo__outlier(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--autofix")
	mklines := t.SetUpFileMkLines("filename.mk",
		MkRcsID,
		"VAR= value",
		"VERY_LONG_VARIABLE_NAME= value1")
	para := NewParagraph(nil)
	for _, mkline := range mklines.mklines {
		para.Add(mkline)
	}

	para.AlignTo(8)
	mklines.SaveAutofixChanges()

	t.CheckOutputLines(
		"AUTOFIX: ~/filename.mk:2: Replacing \" \" with \"\\t\".")

	t.CheckFileLinesDetab("filename.mk",
		MkRcsID,
		"VAR=    value",
		// The space is preserved since this line is an outlier.
		"VERY_LONG_VARIABLE_NAME= value1")
}
