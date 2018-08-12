package main

import "gopkg.in/check.v1"

func (s *Suite) Test_InitVartypes__enumFrom(c *check.C) {
	t := s.Init(c)

	t.SetupFileMkLines("editors/emacs/modules.mk",
		MkRcsID,
		"",
		"_EMACS_VERSIONS_ALL=\temacs31",
		"_EMACS_VERSIONS_ALL=\tignored")
	mklines := t.SetupFileMkLines("Makefile",
		MkRcsID,
		"")

	t.SetupVartypes()
	vartype := mklines.mklines[1].VariableType("EMACS_VERSIONS_ACCEPTED")

	c.Check(vartype.String(), equals, "ShellList of enum: emacs31 ")
}
