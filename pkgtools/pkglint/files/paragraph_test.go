package pkglint

import "gopkg.in/check.v1"

func (s *Suite) Test_Paragraph__empty_line(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		"")

	t.ExpectAssert(func() { _ = NewParagraph(mklines, 0, 1) })
}

func (s *Suite) Test_Paragraph_Align(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--autofix")
	mklines := t.SetUpFileMkLines("filename.mk",
		MkCvsID,
		"VAR=value",
		"VAR=\t\t\tvalue")
	para := NewParagraph(mklines, 1, 3)

	para.Align()
	mklines.SaveAutofixChanges()

	t.CheckOutputLines(
		"AUTOFIX: ~/filename.mk:2: Replacing \"\" with \"\\t\".",
		"AUTOFIX: ~/filename.mk:3: Replacing \"\\t\\t\\t\" with \"\\t\".")

	t.CheckFileLinesDetab("filename.mk",
		MkCvsID,
		"VAR=    value",
		"VAR=    value")
}

func (s *Suite) Test_Paragraph_AlignTo(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--autofix")
	mklines := t.SetUpFileMkLines("filename.mk",
		MkCvsID,
		"VAR=value",
		"VAR=\t\tvalue",
		"# comment between the variable assignments",
		"VAR=\t \tvalue",
		"VAR=\t\t\tvalue")
	para := NewParagraph(mklines, 1, 6)

	para.AlignTo(16)
	mklines.SaveAutofixChanges()

	t.CheckOutputLines(
		"AUTOFIX: ~/filename.mk:2: Replacing \"\" with \"\\t\\t\".",
		"AUTOFIX: ~/filename.mk:5: Replacing \"\\t \\t\" with \"\\t\\t\".",
		"AUTOFIX: ~/filename.mk:6: Replacing \"\\t\\t\\t\" with \"\\t\\t\".")

	t.CheckFileLinesDetab("filename.mk",
		MkCvsID,
		"VAR=            value",
		"VAR=            value",
		"# comment between the variable assignments",
		"VAR=            value",
		"VAR=            value")
}

func (s *Suite) Test_Paragraph_AlignTo__continued_lines(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--autofix")
	mklines := t.SetUpFileMkLines("filename.mk",
		MkCvsID,
		"VAR= \\",
		"  value",
		"VAR= value1 \\",
		"value2 \\",
		"\t\tvalue3")
	para := NewParagraph(mklines, 1, 3)

	para.AlignTo(16)
	mklines.SaveAutofixChanges()

	t.CheckOutputLines(
		"AUTOFIX: ~/filename.mk:4: Replacing \" \" with \"\\t\\t\".")

	t.CheckFileLinesDetab("filename.mk",
		MkCvsID,
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
		MkCvsID,
		"VAR= value",
		"VERY_LONG_VARIABLE_NAME= value1")
	para := NewParagraph(mklines, 1, 3)

	para.AlignTo(8)
	mklines.SaveAutofixChanges()

	t.CheckOutputLines(
		"AUTOFIX: ~/filename.mk:2: Replacing \" \" with \"\\t\".")

	t.CheckFileLinesDetab("filename.mk",
		MkCvsID,
		"VAR=    value",
		// The space is preserved since this line is an outlier.
		"VERY_LONG_VARIABLE_NAME= value1")
}
