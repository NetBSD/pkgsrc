package pkglint

import "gopkg.in/check.v1"

func (s *Suite) Test_NewNetBSDProject(c *check.C) {
	t := s.Init(c)

	project := NewNetBSDProject()

	t.CheckNotNil(project.deprecated)
	t.CheckEquals(0, len(project.deprecated))
}

func (s *Suite) Test_NetBSDProject_Deprecated(c *check.C) {
	t := s.Init(c)

	project := NewNetBSDProject()
	project.deprecated["DEPRECATED"] = "Use NEW_AND_SHINY instead."
	G.Project = project
	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"DEPRECATED=\t${DEPRECATED}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: filename.mk:2: Definition of DEPRECATED is deprecated. Use NEW_AND_SHINY instead.",
		"WARN: filename.mk:2: Use of \"DEPRECATED\" is deprecated. Use NEW_AND_SHINY instead.")
}

func (s *Suite) Test_NetBSDProject_Types(c *check.C) {
	t := s.Init(c)

	project := NewNetBSDProject()
	project.Types().acl("VAR", BtUnknown, NoVartypeOptions, "*.mk: append")

	t.CheckEquals(project.Types().Canon("VAR").basicType, BtUnknown)
	t.CheckEquals(project.Types().Canon("UNDEFINED"), (*Vartype)(nil))
}
