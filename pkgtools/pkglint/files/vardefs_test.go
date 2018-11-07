package main

import "gopkg.in/check.v1"

func (s *Suite) Test_Pkgsrc_InitVartypes(c *check.C) {
	t := s.Init(c)

	src := NewPkgsrc(t.File("."))
	src.InitVartypes()

	c.Check(src.vartypes["BSD_MAKE_ENV"].basicType.name, equals, "ShellWord")
	c.Check(src.vartypes["USE_BUILTIN.*"].basicType.name, equals, "YesNoIndirectly")
}

func (s *Suite) Test_Pkgsrc_InitVartypes__enumFrom(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("editors/emacs/modules.mk",
		MkRcsID,
		"",
		"_EMACS_VERSIONS_ALL=    emacs31",
		"_EMACS_VERSIONS_ALL+=   emacs29")
	t.CreateFileLines("mk/java-vm.mk",
		MkRcsID,
		"",
		"_PKG_JVMS.8=            openjdk8 oracle-jdk8",
		"_PKG_JVMS.7=            ${_PKG_JVMS.8} openjdk7 sun-jdk7",
		"_PKG_JVMS.6=            ${_PKG_JVMS.7} sun-jdk6 jdk16")
	t.CreateFileLines("mk/compiler.mk",
		MkRcsID,
		"",
		"_COMPILERS=             gcc ido mipspro-ucode \\",
		"                        sunpro",
		"_PSEUDO_COMPILERS=      ccache distcc f2c g95",
		"",
		".for _version_ in gnu++14 c++14 gnu++11 c++11 gnu++0x c++0x gnu++03 c++03",
		".  if !empty(USE_LANGUAGES:M${_version_})",
		"USE_LANGUAGES+=         c++",
		".  endif",
		".endfor")

	t.SetupVartypes()

	checkEnumValues := func(varname, values string) {
		vartype := G.Pkgsrc.VariableType(varname).String()
		c.Check(vartype, equals, values)
	}

	checkEnumValues("EMACS_VERSIONS_ACCEPTED", "ShellList of enum: emacs29 emacs31 ")
	checkEnumValues("PKG_JVM", "enum: jdk16 openjdk7 openjdk8 oracle-jdk8 sun-jdk6 sun-jdk7 ")
	checkEnumValues("USE_LANGUAGES", "ShellList of enum: ada c c++ c++03 c++0x c++11 c++14 c99 fortran fortran77 gnu++03 gnu++0x gnu++11 gnu++14 java obj-c++ objc ")
	checkEnumValues("PKGSRC_COMPILER", "ShellList of enum: ccache distcc f2c g95 gcc ido mipspro-ucode sunpro ")
}

func (s *Suite) Test_Pkgsrc_InitVartypes__enumFromDirs(c *check.C) {
	t := s.Init(c)

	// To make the test useful, these directories must differ from the
	// PYPKGPREFIX default value in vardefs.go.
	t.CreateFileLines("lang/python28/Makefile", MkRcsID)
	t.CreateFileLines("lang/python33/Makefile", MkRcsID)

	t.SetupVartypes()

	checkEnumValues := func(varname, values string) {
		vartype := G.Pkgsrc.VariableType(varname).String()
		c.Check(vartype, equals, values)
	}

	checkEnumValues("PYPKGPREFIX", "enum: py28 py33 ")
}

func (s *Suite) Test_parseACLEntries(c *check.C) {
	t := s.Init(c)

	t.ExpectPanic(
		func() { parseACLEntries("VARNAME", "buildlink3.mk: *; *: *") },
		"Pkglint internal error: Invalid ACL permission \"*\" for \"VARNAME\".")

	t.ExpectPanic(
		func() { parseACLEntries("VARNAME", "buildlink3.mk: use; *: use") },
		"Pkglint internal error: Repeated permissions \"use\" for \"VARNAME\".")

	t.ExpectPanic(
		func() { parseACLEntries("VARNAME", "*.txt: use") },
		"Pkglint internal error: Invalid ACL glob \"*.txt\" for \"VARNAME\".")

	t.ExpectPanic(
		func() { parseACLEntries("VARNAME", "*.mk: use; buildlink3.mk: append") },
		"Pkglint internal error: Ineffective ACL glob \"buildlink3.mk\" for \"VARNAME\".")
}

func (s *Suite) Test_Pkgsrc_InitVartypes__LP64PLATFORMS(c *check.C) {
	t := s.Init(c)

	pkg := t.SetupPackage("category/package",
		"BROKEN_ON_PLATFORM=\t${LP64PLATFORMS}")

	G.CheckDirent(pkg)

	// No warning about a missing :Q operator.
	// All PLATFORM variables must be either lkNone or lkSpace.
	t.CheckOutputEmpty()
}
