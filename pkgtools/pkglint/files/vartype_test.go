package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) TestVartypeEffectivePermissions(c *check.C) {
	G.globalData.InitVartypes()

	{
		t := G.globalData.vartypes["PREFIX"]

		c.Check(t.checker.name, equals, "Pathname")
		c.Check(t.aclEntries, check.DeepEquals, []AclEntry{{glob: "*", permissions: "u"}})
		c.Check(t.effectivePermissions("Makefile"), equals, "u")
	}

	{
		t := G.globalData.vartypes["EXTRACT_OPTS"]

		c.Check(t.checker.name, equals, "ShellWord")
		c.Check(t.effectivePermissions("Makefile"), equals, "as")
		c.Check(t.effectivePermissions("../Makefile"), equals, "as")
		c.Check(t.effectivePermissions("options.mk"), equals, "?")
	}
}

func (s *Suite) TestVarCheckerHasEnum(c *check.C) {
	vc := enum("catinstall middle maninstall")

	c.Check(vc.HasEnum("catinstall"), equals, true)
	c.Check(vc.HasEnum("middle"), equals, true)
	c.Check(vc.HasEnum("maninstall"), equals, true)
}
