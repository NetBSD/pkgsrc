package main

import "gopkg.in/check.v1"

func (s *Suite) Test_ToolRegistry_ParseToolLine(c *check.C) {
	t := s.Init(c)

	t.SetupTool(&Tool{Name: "tool1", Predefined: true})
	t.SetupVartypes()
	t.SetupFileLines("Makefile",
		MkRcsID,
		"",
		"USE_TOOLS.NetBSD+=\ttool1")

	CheckdirToplevel(t.File("."))

	// No error about "Unknown tool \"NetBSD\"."
	t.CheckOutputEmpty()
}

func (s *Suite) Test_ToolRegistry_validateToolName__invalid(c *check.C) {
	t := s.Init(c)

	reg := NewToolRegistry()

	reg.Register("tool_name", dummyMkLine)

	// Currently, the underscore is not used in any tool name.
	// If there should ever be such a case, just use a different character.
	t.CheckOutputLines(
		"ERROR: Invalid tool name \"tool_name\".")
}
