package pkglint

import (
	"gopkg.in/check.v1"
)

func (s *Suite) Test_Vartype_EffectivePermissions(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	if typ := G.Pkgsrc.vartypes.Canon("PREFIX"); c.Check(typ, check.NotNil) {
		c.Check(typ.basicType.name, equals, "Pathname")
		c.Check(typ.aclEntries, deepEquals, []ACLEntry{NewACLEntry("*", aclpUse)})
		c.Check(typ.EffectivePermissions("Makefile"), equals, aclpUse)
		c.Check(typ.EffectivePermissions("buildlink3.mk"), equals, aclpUse)
	}

	if typ := G.Pkgsrc.vartypes.Canon("EXTRACT_OPTS"); c.Check(typ, check.NotNil) {
		c.Check(typ.basicType.name, equals, "ShellWord")
		c.Check(typ.EffectivePermissions("Makefile"), equals, aclpAllWrite|aclpUse)
		c.Check(typ.EffectivePermissions("options.mk"), equals, aclpAllWrite|aclpUse)
	}
}

func (s *Suite) Test_Vartype_AlternativeFiles(c *check.C) {

	// test generates the files description for the "set" permission.
	test := func(rules []string, alternatives string) {
		aclEntries := (*VarTypeRegistry).parseACLEntries(nil, "", rules...)
		vartype := NewVartype(BtYesNo, NoVartypeOptions, aclEntries...)

		alternativeFiles := vartype.AlternativeFiles(aclpSet)

		c.Check(alternativeFiles, equals, alternatives)
	}

	// rules parses the given permission rules.
	//
	// There is a built-in check that prevents repeated adjacent permissions.
	// The "append" permission can be added alternatively to circumvent this
	// check, since that permission is effectively ignore by this test.
	rules := func(rules ...string) []string { return rules }

	// When there are no matching rules at all, there's nothing to describe.
	test(
		rules(
			"*: none"),
		"")

	// When there are only positive rules that are disjoint, these are
	// listed in the given order.
	test(
		rules(
			"buildlink3.mk: set",
			"Makefile: set, append", // to avoid "repeated permissions" panic
			"Makefile.*: set"),
		"buildlink3.mk, Makefile or Makefile.*")

	// When there are only positive rules and some of them overlap,
	// these are merged.
	test(
		rules(
			"buildlink3.mk: set",
			"special:*3.mk: set, append",
			"*.mk: set",
			"Makefile: set, append",
			"Makefile.*: set"),
		"*.mk, Makefile or Makefile.*")

	// When the last rule is "*", all previous rules are merged into that.
	test(
		rules(
			"buildlink3.mk: set",
			"special:*3.mk: set, append",
			"*.mk: set",
			"Makefile: set, append",
			"Makefile.*: set",
			"*: set, append"),
		"*")

	test(
		rules(
			"buildlink3.mk: set",
			"*: none"),
		"buildlink3.mk only")

	// Everywhere except in buildlink3.mk.
	test(
		rules(
			"buildlink3.mk: none",
			"*: set"),
		// TODO: should be "buildlink3.mk only".
		"*, but not buildlink3.mk")

	// If there are both positive and negative cases, preserve all the
	// rules verbatim. Otherwise it would be too confusing for the
	// pkglint users to see and maybe learn the actual rules.
	test(
		rules(
			"buildlink3.mk: none",
			"special:*3.mk: set",
			"*.mk: none",
			"Makefile: set",
			"Makefile.*: none",
			"*: set"),
		"*3.mk, Makefile or *, but not buildlink3.mk, *.mk or Makefile.*")

	test(
		rules(
			"buildlink3.mk: none",
			"builtin.mk: set",
			"Makefile: none",
			"*.mk: append"),
		// TODO: should be "builtin.mk only".
		"builtin.mk, but not buildlink3.mk, Makefile or *.mk")
}

func (s *Suite) Test_Vartype_String(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	vartype := G.Pkgsrc.VariableType(nil, "PKG_DEBUG_LEVEL")
	t.Check(vartype.String(), equals, "Integer (command-line-provided)")
}

func (s *Suite) Test_BasicType_HasEnum(c *check.C) {
	vc := enum("start middle end")

	c.Check(vc.HasEnum("start"), equals, true)
	c.Check(vc.HasEnum("middle"), equals, true)
	c.Check(vc.HasEnum("end"), equals, true)

	c.Check(vc.HasEnum("star"), equals, false)
	c.Check(vc.HasEnum("mid"), equals, false)
	c.Check(vc.HasEnum("nd"), equals, false)
	c.Check(vc.HasEnum("start middle"), equals, false)
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
}

func (s *Suite) Test_ACLPermissions_HumanString(c *check.C) {

	c.Check(ACLPermissions(0).HumanString(),
		equals, "") // Doesn't happen in practice

	c.Check(aclpAll.HumanString(),
		equals, "set, given a default value, appended to, used at load time, or used")
}

func (s *Suite) Test_Vartype_MayBeAppendedTo(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	c.Check(G.Pkgsrc.VariableType(nil, "COMMENT").MayBeAppendedTo(), equals, true)
	c.Check(G.Pkgsrc.VariableType(nil, "DEPENDS").MayBeAppendedTo(), equals, true)
	c.Check(G.Pkgsrc.VariableType(nil, "PKG_FAIL_REASON").MayBeAppendedTo(), equals, true)
	c.Check(G.Pkgsrc.VariableType(nil, "CONF_FILES").MayBeAppendedTo(), equals, true)
}
