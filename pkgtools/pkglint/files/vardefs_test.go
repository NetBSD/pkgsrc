package pkglint

import "gopkg.in/check.v1"

func (s *Suite) Test_VarTypeRegistry_Init(c *check.C) {
	t := s.Init(c)

	src := NewPkgsrc(t.File("."))
	src.vartypes.Init(&src)

	c.Check(src.vartypes.Canon("BSD_MAKE_ENV").basicType.name, equals, "ShellWord")
	c.Check(src.vartypes.Canon("USE_BUILTIN.*").basicType.name, equals, "YesNoIndirectly")
}

func (s *Suite) Test_VarTypeRegistry_enumFrom(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("editors/emacs/modules.mk",
		MkCvsID,
		"",
		"_EMACS_VERSIONS_ALL=    emacs31",
		"_EMACS_VERSIONS_ALL+=   emacs29")
	t.CreateFileLines("mk/java-vm.mk",
		MkCvsID,
		"",
		"_PKG_JVMS.8=            openjdk8 oracle-jdk8",
		"_PKG_JVMS.7=            ${_PKG_JVMS.8} openjdk7 sun-jdk7",
		"_PKG_JVMS.6=            ${_PKG_JVMS.7} jdk16")
	t.CreateFileLines("mk/compiler.mk",
		MkCvsID,
		"",
		"_COMPILERS=             gcc ido mipspro-ucode \\",
		"                        sunpro",
		"_PSEUDO_COMPILERS=      ccache distcc f2c g95",
		"",
		".for _version_ in gnu++14 c++14 gnu++11 c++11 gnu++0x c++0x gnu++03 c++03",
		".  if !empty(USE_LANGUAGES:M${_version_})",
		"USE_LANGUAGES+=         c++",
		".  endif",
		".endfor",
		"",
		".for _version_", // Just for code coverage.
		".endfor",
		"",
		".for version in c99 c200x", // Just for code coverage.
		".endfor")

	t.SetUpVartypes()

	test := func(varname, values string) {
		vartype := G.Pkgsrc.VariableType(nil, varname).String()
		c.Check(vartype, equals, values)
	}

	test("EMACS_VERSIONS_ACCEPTED", "enum: emacs29 emacs31  (list, package-settable)")
	test("PKG_JVM", "enum: jdk16 openjdk7 openjdk8 oracle-jdk8 sun-jdk7  (system-provided)")
	test("USE_LANGUAGES", "enum: ada c c++ c++03 c++0x c++11 c++14 c99 "+
		"fortran fortran77 gnu++03 gnu++0x gnu++11 gnu++14 java obj-c++ objc  (list, package-settable)")
	test("PKGSRC_COMPILER", "enum: ccache distcc f2c g95 gcc ido mipspro-ucode sunpro  (list, user-settable)")
}

func (s *Suite) Test_VarTypeRegistry_enumFrom__no_tracing(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("mk/existing.mk",
		MkCvsID,
		"VAR=\tfirst second")
	reg := NewVarTypeRegistry()
	t.DisableTracing()

	existingType := reg.enumFrom(&G.Pkgsrc, "mk/existing.mk", "defval", "VAR")
	noAssignmentsType := reg.enumFrom(&G.Pkgsrc, "mk/existing.mk", "defval", "OTHER_VAR")
	nonexistentType := reg.enumFrom(&G.Pkgsrc, "mk/nonexistent.mk", "defval", "VAR")

	t.Check(existingType.AllowedEnums(), equals, "first second")
	t.Check(noAssignmentsType.AllowedEnums(), equals, "defval")
	t.Check(nonexistentType.AllowedEnums(), equals, "defval")
}

func (s *Suite) Test_VarTypeRegistry_enumFromDirs(c *check.C) {
	t := s.Init(c)

	// To make the test useful, these directories must differ from the
	// PYPKGPREFIX default value in vardefs.go.
	t.CreateFileLines("lang/python28/Makefile", MkCvsID)
	t.CreateFileLines("lang/python33/Makefile", MkCvsID)

	t.SetUpVartypes()

	test := func(varname, values string) {
		vartype := G.Pkgsrc.VariableType(nil, varname).String()
		c.Check(vartype, equals, values)
	}

	test("PYPKGPREFIX", "enum: py28 py33  (system-provided)")
}

func (s *Suite) Test_VarTypeRegistry_enumFromFiles(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("mk/platform/NetBSD.mk")
	t.CreateFileLines("mk/platform/README")
	t.CreateFileLines("mk/platform/SunOS.mk")
	t.CreateFileLines("mk/platform/SunOS.mk~")

	t.SetUpVartypes()

	test := func(varname, values string) {
		vartype := G.Pkgsrc.VariableType(nil, varname).String()
		c.Check(vartype, equals, values)
	}

	test("OPSYS", "enum: NetBSD SunOS  (system-provided)")
}

func (s *Suite) Test_VarTypeRegistry_parseACLEntries__invalid_arguments(c *check.C) {
	t := s.Init(c)

	reg := NewVarTypeRegistry()
	parseACLEntries := reg.parseACLEntries

	t.ExpectPanic(
		func() { parseACLEntries("VARNAME", "buildlink3.mk: *", "*: *") },
		"Pkglint internal error: "+
			"Invalid ACL permission \"*\" for \"VARNAME\" in \"buildlink3.mk\". "+
			"Remaining parts are \"*\". "+
			"Valid permissions are default, set, append, use, use-loadtime (in this order), or none.")

	t.ExpectPanic(
		func() { parseACLEntries("VARNAME", "buildlink3.mk: use", "*: use") },
		"Pkglint internal error: Repeated permissions \"use\" for \"VARNAME\".")

	t.ExpectPanic(
		func() { parseACLEntries("VARNAME", "*.txt: use") },
		"Pkglint internal error: Invalid ACL glob \"*.txt\" for \"VARNAME\".")

	t.ExpectPanic(
		func() { parseACLEntries("VARNAME", "*.mk: use", "buildlink3.mk: append") },
		"Pkglint internal error: Unreachable ACL pattern \"buildlink3.mk\" for \"VARNAME\".")

	t.ExpectPanic(
		func() { parseACLEntries("VARNAME", "no colon") },
		"Pkglint internal error: ACL entry \"no colon\" must have exactly 1 colon.")

	t.ExpectPanic(
		func() { parseACLEntries("VARNAME", "too: many: colons") },
		"Pkglint internal error: ACL entry \"too: many: colons\" must have exactly 1 colon.")

	t.ExpectAssert(func() { parseACLEntries("VAR") })
}

func (s *Suite) Test_VarTypeRegistry_Init__LP64PLATFORMS(c *check.C) {
	t := s.Init(c)

	pkg := t.SetUpPackage("category/package",
		"BROKEN_ON_PLATFORM=\t${LP64PLATFORMS}")
	t.FinishSetUp()

	G.Check(pkg)

	// No warning about a missing :Q operator.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_VarTypeRegistry_Init__no_tracing(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("editors/emacs/modules.mk",
		MkCvsID,
		"",
		"_EMACS_VERSIONS_ALL=    emacs31",
		"_EMACS_VERSIONS_ALL+=   emacs29")
	t.DisableTracing()

	t.SetUpVartypes() // Just for code coverage.

	t.CheckOutputEmpty()
}

func (s *Suite) Test_VarTypeRegistry_Init__no_testing(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.Remove("mk/fetch/sites.mk")
	G.Testing = false
	t.ExpectFatal(
		t.FinishSetUp,
		"FATAL: ~/mk/fetch/sites.mk: Cannot be read.")
}

func (s *Suite) Test_VarTypeRegistry_Init__MASTER_SITES(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("mk/fetch/sites.mk",
		MkCvsID,
		"",
		"MASTER_SITE_GITHUB=\thttps://github.com/",
		"",
		"OTHER=\tvalue") // For branch coverage of hasPrefix.*MASTER_SITE_

	t.SetUpVartypes()

	vartype := G.Pkgsrc.VariableType(nil, "MASTER_SITE_GITHUB")
	t.Check(vartype.String(), equals, "FetchURL (list, system-provided)")
}
