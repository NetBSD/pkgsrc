package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) TestParseLicenses(c *check.C) {
	c.Check(parseLicenses("gnu-gpl-v2"), check.DeepEquals, []string{"gnu-gpl-v2"})
	c.Check(parseLicenses("AND artistic"), check.DeepEquals, []string{"artistic"})
}
