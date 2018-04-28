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

	G.CurrentDir = t.TmpDir()
	CheckdirToplevel()

	// No error about "Unknown tool \"NetBSD\"."
	t.CheckOutputEmpty()
}
