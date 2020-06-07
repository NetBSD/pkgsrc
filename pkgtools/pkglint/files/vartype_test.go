package pkglint

import (
	"gopkg.in/check.v1"
)

func (s *Suite) Test_ACLPermissions_Contains(c *check.C) {
	t := s.Init(c)

	perms := aclpAllRuntime

	t.CheckEquals(perms.Contains(aclpAllRuntime), true)
	t.CheckEquals(perms.Contains(aclpUse), true)
	t.CheckEquals(perms.Contains(aclpUseLoadtime), false)
}

func (s *Suite) Test_ACLPermissions_String(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(ACLPermissions(0).String(), "none")
	t.CheckEquals(aclpAll.String(), "set, set-default, append, use-loadtime, use")
}

func (s *Suite) Test_ACLPermissions_HumanString(c *check.C) {
	t := s.Init(c)

	// Doesn't happen in practice
	t.CheckEquals(ACLPermissions(0).HumanString(), "")

	t.CheckEquals(
		aclpAll.HumanString(),
		"set, given a default value, appended to, used at load time, or used")
}

func (s *Suite) Test_Vartype_IsNonemptyIfDefined(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	test := func(varname string, isNonempty bool) {
		vartype := G.Pkgsrc.VariableType(nil, varname)

		t.CheckEquals(vartype.IsNonemptyIfDefined(), isNonempty)
	}

	test("PKGPATH", true)
	test("PKGREVISION", true)
	test("OPSYS", true)
	test("OS_VERSION", false)
}

func (s *Suite) Test_Vartype_EffectivePermissions(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	if typ := G.Pkgsrc.vartypes.Canon("PREFIX"); c.Check(typ, check.NotNil) {
		t.CheckEquals(typ.basicType.name, "Pathname")
		t.CheckDeepEquals(typ.aclEntries, []ACLEntry{NewACLEntry("*", aclpUse)})
		t.CheckEquals(typ.EffectivePermissions("Makefile"), aclpUse)
		t.CheckEquals(typ.EffectivePermissions("buildlink3.mk"), aclpUse)
	}

	if typ := G.Pkgsrc.vartypes.Canon("EXTRACT_OPTS"); c.Check(typ, check.NotNil) {
		t.CheckEquals(typ.basicType.name, "ShellWord")
		t.CheckEquals(typ.EffectivePermissions("Makefile"), aclpAllWrite|aclpUse)
		t.CheckEquals(typ.EffectivePermissions("options.mk"), aclpAllWrite|aclpUse)
	}
}

func (s *Suite) Test_Vartype_AlternativeFiles(c *check.C) {
	t := s.Init(c)

	// test generates the files description for the "set" permission.
	test := func(rules []string, alternatives string) {
		aclEntries := (*VarTypeRegistry).parseACLEntries(nil, "", rules...)
		vartype := NewVartype(BtYesNo, NoVartypeOptions, aclEntries...)

		alternativeFiles := vartype.AlternativeFiles(aclpSet)

		t.CheckEquals(alternativeFiles, alternatives)
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
		"builtin.mk, but not buildlink3.mk, Makefile or *.mk")
}

func (s *Suite) Test_Vartype_MayBeAppendedTo(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	test := func(varname string, isAppendAllowed bool) {
		vartype := G.Pkgsrc.VariableType(nil, varname)

		t.CheckEquals(vartype.MayBeAppendedTo(), isAppendAllowed)
	}

	// There are several packages that append a parenthesized addition
	// to the comment, such as "(command-line version)".
	test("COMMENT", true)

	// Appending to a list is always ok.
	test("DEPENDS", true)
	test("PKG_FAIL_REASON", true)

	// This type is not marked as a list since it does not support
	// appending a single element, therefore the above rule does not apply.
	// Whenever something is appended, it must be in pairs of two words.
	test("CONF_FILES", true)

	// By convention, all variables ending in _AWK contain AWK code.
	// It is usual to append a single rule to it, such as:
	//  EXAMPLE_AWK+=   /condition/ { action }
	test("EXAMPLE_AWK", true)

	// This is another variable where the appended things should always
	// come in pairs. A typical example is:
	//  SUBST_SED.id+=  -e s,from,to,
	test("SUBST_SED.id", true)
}

func (s *Suite) Test_Vartype_String(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	vartype := G.Pkgsrc.VariableType(nil, "PKG_DEBUG_LEVEL")
	t.CheckEquals(vartype.String(), "Integer (command-line-provided)")
}

func (s *Suite) Test_BasicType_NeedsQ(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	test := func(varname string, isAppendAllowed bool) {
		vartype := G.Pkgsrc.VariableType(nil, varname)

		t.CheckEquals(vartype.basicType.NeedsQ(), isAppendAllowed)
	}

	test("BUILDLINK_DEPMETHOD.pkgbase", false)
	test("CATEGORIES", false)
	test("EXTRACT_SUFX", false)
	test("EMUL_PLATFORM", false)
	test("BINMODE", false)

	// Typically safe, seldom used in practice.
	test("DISTFILES", false)

	test("SUBST_CLASSES", false)
	test("PLIST_VARS", false)

	test("MAKE_JOBS", false) // XXX: What if MAKE_JOBS is undefined?
	test("PKGREVISION", false)

	// A specific platform does not have special characters.
	// The patterns for such platforms typically do, such as
	// x86_64-*-*.
	test("MACHINE_GNU_PLATFORM", false)

	// A specific platform does not have special characters.
	// The patterns for such platforms typically do, such as
	// NetBSD-*-*.
	test("MACHINE_PLATFORM", false)

	test("PERL5_PACKLIST", false)
	test("PKG_OPTIONS_VAR", false)
	test("PYTHON_VERSIONED_DEPENDENCIES", false)
	test("SUBST_STAGE.id", false)
	test("IS_BUILTIN.pkgbase", false)

	test("COMMENT", true)
	test("PKG_FAIL_REASON", true)
	test("SUBST_MESSAGE.id", true)
	test("CC", true)

	test("TOOLS_NOOP", false)
}

func (s *Suite) Test_BasicType_HasEnum(c *check.C) {
	t := s.Init(c)

	vc := enum("start middle end")

	t.CheckEquals(vc.HasEnum("start"), true)
	t.CheckEquals(vc.HasEnum("middle"), true)
	t.CheckEquals(vc.HasEnum("end"), true)

	t.CheckEquals(vc.HasEnum("star"), false)
	t.CheckEquals(vc.HasEnum("mid"), false)
	t.CheckEquals(vc.HasEnum("nd"), false)
	t.CheckEquals(vc.HasEnum("start middle"), false)
}
