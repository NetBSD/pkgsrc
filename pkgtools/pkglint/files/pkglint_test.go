package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) TestDetermineUsedVariables_simple(c *check.C) {
	G.mkContext = newMkContext()
	line := NewLine("fname", "1", "${VAR}", nil)
	lines := []*Line{line}

	determineUsedVariables(lines)

	c.Check(len(G.mkContext.varuse), equals, 1)
	c.Check(G.mkContext.varuse["VAR"], equals, line)
}

func (s *Suite) TestDetermineUsedVariables_nested(c *check.C) {
	G.mkContext = newMkContext()
	line := NewLine("fname", "2", "${outer.${inner}}", nil)
	lines := []*Line{line}

	determineUsedVariables(lines)

	c.Check(len(G.mkContext.varuse), equals, 3)
	c.Check(G.mkContext.varuse["inner"], equals, line)
	c.Check(G.mkContext.varuse["outer."], equals, line)
	c.Check(G.mkContext.varuse["outer.*"], equals, line)
}

func (s *Suite) TestReShellword(c *check.C) {
	re := `^(?:` + reShellword + `)$`
	matches := check.NotNil
	doesntMatch := check.IsNil

	c.Check(match("", re), doesntMatch)
	c.Check(match("$var", re), matches)
	c.Check(match("$var$var", re), matches)
	c.Check(match("$var;;", re), doesntMatch) // More than one shellword
	c.Check(match("'single-quoted'", re), matches)
	c.Check(match("\"", re), doesntMatch)       // Incomplete string
	c.Check(match("'...'\"...\"", re), matches) // Mixed strings
	c.Check(match("\"...\"", re), matches)
	c.Check(match("`cat file`", re), matches)
}

func (s *Suite) TestResolveVariableRefs_CircularReference(c *check.C) {
	line := NewLine("fname", "1", "dummy", nil)
	line.extra["value"] = "${GCC_VERSION}"
	G.pkgContext = newPkgContext(".")
	G.pkgContext.vardef["GCC_VERSION"] = line // circular reference

	resolved := resolveVariableRefs("gcc-${GCC_VERSION}")

	c.Check(resolved, equals, "gcc-${GCC_VERSION}")
}

func (s *Suite) TestResolveVariableRefs_Multilevel(c *check.C) {
	line1 := NewLine("fname", "dummy", "dummy", nil)
	line1.extra["value"] = "${SECOND}"
	line2 := NewLine("fname", "dummy", "dummy", nil)
	line2.extra["value"] = "${THIRD}"
	line3 := NewLine("fname", "dummy", "dummy", nil)
	line3.extra["value"] = "got it"
	G.pkgContext = newPkgContext(".")
	G.pkgContext.vardef["FIRST"] = line1
	G.pkgContext.vardef["SECOND"] = line2
	G.pkgContext.vardef["THIRD"] = line3

	resolved := resolveVariableRefs("you ${FIRST}")

	c.Check(resolved, equals, "you got it")
}

func (s *Suite) TestResolveVariableRefs_SpecialChars(c *check.C) {
	line := NewLine("fname", "dummy", "dummy", nil)
	line.extra["value"] = "x11"
	G.pkgContext = newPkgContext("category/pkg")
	G.pkgContext.vardef["GST_PLUGINS0.10_TYPE"] = line

	resolved := resolveVariableRefs("gst-plugins0.10-${GST_PLUGINS0.10_TYPE}/distinfo")

	c.Check(resolved, equals, "gst-plugins0.10-x11/distinfo")
}

func (s *Suite) TestChecklineRcsid(c *check.C) {
	lines := s.NewLines("fname",
		"$"+"NetBSD: dummy $",
		"$"+"NetBSD$",
		"$"+"Id: dummy $",
		"$"+"Id$",
		"$"+"FreeBSD$")

	for _, line := range lines {
		checklineRcsid(line, ``, "")
	}

	c.Check(s.Output(), equals, ""+
		"ERROR: fname:3: Expected \"$"+"NetBSD$\".\n"+
		"ERROR: fname:4: Expected \"$"+"NetBSD$\".\n"+
		"ERROR: fname:5: Expected \"$"+"NetBSD$\".\n")
}

func (s *Suite) TestMatchVarassign(c *check.C) {
	m, varname, op, value, comment := matchVarassign("C++=c11")

	c.Check(m, equals, true)
	c.Check(varname, equals, "C+")
	c.Check(op, equals, "+=")
	c.Check(value, equals, "c11")
	c.Check(comment, equals, "")
}
