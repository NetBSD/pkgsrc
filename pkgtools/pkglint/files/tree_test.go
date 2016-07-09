package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) Test_Tree_String(c *check.C) {
	c.Check(NewTree("not", NewTree("empty", "varname")).String(), equals, "(not (empty \"varname\"))")
}
