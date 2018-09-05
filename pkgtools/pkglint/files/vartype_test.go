package main

import (
	"gopkg.in/check.v1"
)

func (s *Suite) Test_Vartype_EffectivePermissions(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()

	if t := G.Pkgsrc.vartypes["PREFIX"]; c.Check(t, check.NotNil) {
		c.Check(t.basicType.name, equals, "Pathname")
		c.Check(t.aclEntries, check.DeepEquals, []ACLEntry{{glob: "*", permissions: aclpUse}})
		c.Check(t.EffectivePermissions("Makefile"), equals, aclpUse)
	}

	if t := G.Pkgsrc.vartypes["EXTRACT_OPTS"]; c.Check(t, check.NotNil) {
		c.Check(t.basicType.name, equals, "ShellWord")
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
	c.Check(ACLPermissions(0).String(), equals, "none")
	c.Check(aclpAll.String(), equals, "set, set-default, append, use-loadtime, use")
	c.Check(aclpUnknown.String(), equals, "unknown")
}

func (s *Suite) Test_Vartype_IsConsideredList(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()

	c.Check(G.Pkgsrc.VariableType("COMMENT").IsConsideredList(), equals, false)
	c.Check(G.Pkgsrc.VariableType("DEPENDS").IsConsideredList(), equals, false)
	c.Check(G.Pkgsrc.VariableType("PKG_FAIL_REASON").IsConsideredList(), equals, true)
	c.Check(G.Pkgsrc.VariableType("CONF_FILES").IsConsideredList(), equals, true)
}
