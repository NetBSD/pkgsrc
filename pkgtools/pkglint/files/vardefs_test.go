package main

import "gopkg.in/check.v1"

func (s *Suite) Test_InitVartypes__enumFrom(c *check.C) {
	t := s.Init(c)

	t.SetupFileMkLines("editors/emacs/modules.mk",
		MkRcsID,
		"",
		"_EMACS_VERSIONS_ALL=    emacs31",
		"_EMACS_VERSIONS_ALL+=   emacs29")
	t.SetupFileMkLines("mk/java-vm.mk",
		MkRcsID,
		"",
		"_PKG_JVMS.8=            openjdk8 oracle-jdk8",
		"_PKG_JVMS.7=            ${_PKG_JVMS.8} openjdk7 sun-jdk7",
		"_PKG_JVMS.6=            ${_PKG_JVMS.7} sun-jdk6 jdk16")
	t.SetupFileMkLines("mk/compiler.mk",
		MkRcsID,
		"",
		"_COMPILERS=             gcc ido mipspro-ucode \\",
		"                        sunpro",
		"_PSEUDO_COMPILERS=	     ccache distcc f2c g95",
		"",
		".for _version_ in gnu++14 c++14 gnu++11 c++11 gnu++0x c++0x gnu++03 c++03",
		".  if !empty(USE_LANGUAGES:M${_version_})",
		"USE_LANGUAGES+=		c++",
		".  endif",
		".endfor")
	mklines := t.SetupFileMkLines("Makefile",
		MkRcsID,
		"")

	t.SetupVartypes()

	checkEnumValues := func(varname, values string) {
		vartype := mklines.mklines[1].VariableType(varname).String()
		c.Check(vartype, equals, values)
	}

	checkEnumValues("EMACS_VERSIONS_ACCEPTED", "ShellList of enum: emacs29 emacs31 ")
	checkEnumValues("PKG_JVM", "enum: jdk16 openjdk7 openjdk8 oracle-jdk8 sun-jdk6 sun-jdk7 ")
	checkEnumValues("USE_LANGUAGES", "ShellList of enum: ada c c++ c++03 c++0x c++11 c++14 c99 fortran fortran77 gnu++03 gnu++0x gnu++11 gnu++14 java obj-c++ objc ")
	checkEnumValues("PKGSRC_COMPILER", "ShellList of enum: ccache distcc f2c g95 gcc ido mipspro-ucode sunpro ")
}
