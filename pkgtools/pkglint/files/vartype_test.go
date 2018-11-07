package main

import (
	"gopkg.in/check.v1"
)

func (s *Suite) Test_Vartype_EffectivePermissions(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()

	if typ := G.Pkgsrc.vartypes["PREFIX"]; c.Check(typ, check.NotNil) {
		c.Check(typ.basicType.name, equals, "PathName")
		c.Check(typ.aclEntries, check.DeepEquals, []ACLEntry{{glob: "*", permissions: aclpUse}})
		c.Check(typ.EffectivePermissions("Makefile"), equals, aclpUse)
	}

	if typ := G.Pkgsrc.vartypes["EXTRACT_OPTS"]; c.Check(typ, check.NotNil) {
		c.Check(typ.basicType.name, equals, "ShellWord")
		c.Check(typ.EffectivePermissions("Makefile"), equals, aclpAppend|aclpSet)
		c.Check(typ.EffectivePermissions("options.mk"), equals, aclpUnknown)
	}
}

func (s *Suite) Test_BasicType_HasEnum(c *check.C) {
	vc := enum("catinstall middle maninstall")

	c.Check(vc.HasEnum("catinstall"), equals, true)
	c.Check(vc.HasEnum("middle"), equals, true)
	c.Check(vc.HasEnum("maninstall"), equals, true)
}

func (s *Suite) Test_ACLPermissions_Contains(c *check.C) {
	perms := aclpAllRuntime

	c.Check(perms.Contains(aclpAllRuntime), equals, true)
	c.Check(perms.Contains(aclpUse), equals, true)
	c.Check(perms.Contains(aclpUseLoadtime), equals, false)
}

func (s *Suite) Test_ACLPermissions_String(c *check.C) {
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
