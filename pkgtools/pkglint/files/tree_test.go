package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) TestTreeString(c *check.C) {
	c.Check(NewTree("not", NewTree("empty", "varname")).String(), equals, "(not (empty \"varname\"))")
}
