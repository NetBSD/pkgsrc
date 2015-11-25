package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) TestTreeMatch_successful(c *check.C) {
	var varname *string
	pattern := NewTree("not", NewTree("empty", &varname))
	tree := NewTree("not", NewTree("empty", "VARNAME"))

	c.Check(tree.Match(pattern), equals, true)
	c.Assert(varname, check.Not(equals), nil)
	c.Check(*varname, equals, "VARNAME")
}

func (s *Suite) TestTreeMatch_fails(c *check.C) {
	var varname *string
	pattern := NewTree("not", NewTree("empty", &varname))
	tree := NewTree("not", NewTree("full", "VARNAME"))

	c.Check(tree.Match(pattern), equals, false)
	c.Check(varname, equals, (*string)(nil))
}

func (s *Suite) TestTreeString(c *check.C) {
	c.Check(NewTree("not", NewTree("empty", "varname")).String(), equals, "(not (empty \"varname\"))")
}
