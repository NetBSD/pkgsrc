package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) TestSplitIntoShellwords_LineContinuation(c *check.C) {
	line := NewLine("fname", "1", "dummy", nil)

	words, rest := splitIntoShellwords(line, "if true; then \\")

	c.Check(words, check.DeepEquals, []string{"if", "true", ";", "then"})
	c.Check(rest, equals, "\\")

	words, rest = splitIntoShellwords(line, "pax -s /.*~$$//g")

	c.Check(words, check.DeepEquals, []string{"pax", "-s", "/.*~$$//g"})
	c.Check(rest, equals, "")
}

func (s *Suite) TestChecklineMkShelltext(c *check.C) {
	G.mkContext = newMkContext()
	line := NewLine("fname", "1", "dummy", nil)

	NewMkShellLine(line).checklineMkShelltext("@# Comment")
}

func (s *Suite) TestChecklineMkShellword(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.InitVartypes()
	line := NewLine("fname", "1", "dummy", nil)

	c.Check(matches("${list}", `^`+reVarname+`$`), equals, true)
	c.Check(matches("${list}", `^`+reVarnameDirect+`$`), equals, false)

	checklineMkShellword(line, "${${list}}", false)

	c.Check(s.Output(), equals, "")

	checklineMkShellword(line, "\"$@\"", false)

	c.Check(s.Output(), equals, "WARN: fname:1: Please use \"${.TARGET}\" instead of \"$@\".\n")
}

func (s *Suite) TestShelltextContext_CheckCommandStart(c *check.C) {
	s.UseCommandLine(c, "-Wall")
	G.globalData.tools = map[string]bool{"echo": true}
	G.globalData.vartools = map[string]string{"echo": "ECHO"}
	G.globalData.toolsVarRequired = map[string]bool{"echo": true}
	G.mkContext = newMkContext()
	line := NewLine("fname", "3", "dummy", nil)

	checklineMkShellcmd(line, "echo \"hello, world\"")

	c.Check(s.Output(), equals, ""+
		"WARN: fname:3: The \"echo\" tool is used but not added to USE_TOOLS.\n"+
		"WARN: fname:3: Please use \"${ECHO}\" instead of \"echo\".\n")
}
