package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) Test_Vartype_EffectivePermissions(c *check.C) {
	G.globalData.InitVartypes()

	if t := G.globalData.vartypes["PREFIX"]; c.Check(t, check.NotNil) {
		c.Check(t.checker.name, equals, "Pathname")
		c.Check(t.aclEntries, check.DeepEquals, []AclEntry{{glob: "*", permissions: aclpUse}})
		c.Check(t.EffectivePermissions("Makefile"), equals, aclpUse)
	}

	if t := G.globalData.vartypes["EXTRACT_OPTS"]; c.Check(t, check.NotNil) {
		c.Check(t.checker.name, equals, "ShellWord")
		c.Check(t.EffectivePermissions("Makefile"), equals, aclpAppend|aclpSet)
		c.Check(t.EffectivePermissions("../Makefile"), equals, aclpAppend|aclpSet)
		c.Check(t.EffectivePermissions("options.mk"), equals, aclpUnknown)
	}
}

func (s *Suite) Test_VarChecker_HasEnum(c *check.C) {
	vc := enum("catinstall middle maninstall")

	c.Check(vc.HasEnum("catinstall"), equals, true)
	c.Check(vc.HasEnum("middle"), equals, true)
	c.Check(vc.HasEnum("maninstall"), equals, true)
}

func (s *Suite) Test_AclPermissions_Contains(c *check.C) {
	perms := aclpAllRuntime

	c.Check(perms.Contains(aclpAllRuntime), equals, true)
	c.Check(perms.Contains(aclpUse), equals, true)
	c.Check(perms.Contains(aclpUseLoadtime), equals, false)
}

func (s *Suite) Test_AclPermissions_String(c *check.C) {
	c.Check(AclPermissions(0).String(), equals, "none")
	c.Check(aclpAll.String(), equals, "set, set-default, append, use-loadtime, use")
	c.Check(aclpUnknown.String(), equals, "unknown")
}
