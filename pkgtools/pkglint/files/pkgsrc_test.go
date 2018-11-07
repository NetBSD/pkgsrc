package main

import "gopkg.in/check.v1"

// Ensures that pkglint can handle MASTER_SITES definitions with and
// without line continuations.
//
// See https://mail-index.netbsd.org/tech-pkg/2017/01/18/msg017698.html.
func (s *Suite) Test_Pkgsrc_loadMasterSites(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("mk/fetch/sites.mk",
		MkRcsID,
		"",
		"MASTER_SITE_A+= https://example.org/distfiles/",
		"MASTER_SITE_B+= https://b.example.org/distfiles/ \\",
		"  https://b2.example.org/distfiles/",
		"MASTER_SITE_A+= https://a.example.org/distfiles/")

	G.Pkgsrc.loadMasterSites()

	c.Check(G.Pkgsrc.MasterSiteURLToVar["https://example.org/distfiles/"], equals, "MASTER_SITE_A")
	c.Check(G.Pkgsrc.MasterSiteURLToVar["https://b.example.org/distfiles/"], equals, "MASTER_SITE_B")
	c.Check(G.Pkgsrc.MasterSiteURLToVar["https://b2.example.org/distfiles/"], equals, "MASTER_SITE_B")
	c.Check(G.Pkgsrc.MasterSiteURLToVar["https://a.example.org/distfiles/"], equals, "MASTER_SITE_A")
	c.Check(G.Pkgsrc.MasterSiteVarToURL["MASTER_SITE_A"], equals, "https://example.org/distfiles/")
	c.Check(G.Pkgsrc.MasterSiteVarToURL["MASTER_SITE_B"], equals, "https://b.example.org/distfiles/")
}

func (s *Suite) Test_Pkgsrc_parseSuggestedUpdates(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("doc/TODO",
		"",
		"Suggested package updates",
		"==============",
		"For Perl updates \u2026",
		"",
		"\t"+"o CSP-0.34",
		"\t"+"o freeciv-client-2.5.0 (urgent)",
		"",
		"\t"+"o ignored-0.0")

	todo := G.Pkgsrc.parseSuggestedUpdates(lines)

	c.Check(todo, check.DeepEquals, []SuggestedUpdate{
		{lines.Lines[5], "CSP", "0.34", ""},
		{lines.Lines[6], "freeciv-client", "2.5.0", "(urgent)"}})
}

func (s *Suite) Test_Pkgsrc_loadTools(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("mk/tools/bsd.tools.mk",
		".include \"flex.mk\"",
		".include \"gettext.mk\"",
		".include \"strip.mk\"",
		".include \"replace.mk\"")
	t.CreateFileLines("mk/tools/defaults.mk",
		"_TOOLS_VARNAME.chown=CHOWN",
		"_TOOLS_VARNAME.gawk=AWK",
		"_TOOLS_VARNAME.mv=MV",
		"_TOOLS_VARNAME.pwd=PWD")
	t.CreateFileLines("mk/tools/flex.mk",
		"# empty")
	t.CreateFileLines("mk/tools/gettext.mk",
		".if ${USE_TOOLS:Mgettext}", // This conditional prevents msgfmt from
		"USE_TOOLS+=msgfmt",         // being added to the default USE_TOOLS.
		".endif",
		"TOOLS_CREATE+=msgfmt")
	t.CreateFileLines("mk/tools/strip.mk",
		".if defined(_INSTALL_UNSTRIPPED) || !defined(TOOLS_PLATFORM.strip)",
		"TOOLS_NOOP+=            strip",
		".else",
		"TOOLS_CREATE+=          strip",
		"TOOLS_PATH.strip=       ${TOOLS_PLATFORM.strip}",
		".endif",
		"STRIP?=         strip")
	t.CreateFileLines("mk/tools/replace.mk",
		"_TOOLS.bzip2=\tbzip2 bzcat",
		"#TOOLS_CREATE+=commented out",
		"_UNRELATED_VAR=\t# empty")
	t.CreateFileLines("mk/bsd.prefs.mk",
		"USE_TOOLS+=\tpwd",
		"USE_TOOLS+=\tm4:pkgsrc")
	t.CreateFileLines("mk/bsd.pkg.mk",
		"USE_TOOLS+=\tmv")

	G.Pkgsrc.loadTools()

	t.EnableTracingToLog()
	G.Pkgsrc.Tools.Trace()
	t.DisableTracing()

	t.CheckOutputLines(
		"TRACE: + (*Tools).Trace(\"Pkgsrc\")",
		"TRACE: 1   tool bzcat:::Nowhere",
		"TRACE: 1   tool bzip2:::Nowhere",
		"TRACE: 1   tool chown:CHOWN::Nowhere",
		"TRACE: 1   tool echo:ECHO:var:AfterPrefsMk",
		"TRACE: 1   tool echo -n:ECHO_N:var:AfterPrefsMk",
		"TRACE: 1   tool false:FALSE:var:AtRunTime",
		"TRACE: 1   tool gawk:AWK::Nowhere",
		"TRACE: 1   tool m4:::AfterPrefsMk",
		"TRACE: 1   tool msgfmt:::Nowhere",
		"TRACE: 1   tool mv:MV::AtRunTime",
		"TRACE: 1   tool pwd:PWD::AfterPrefsMk",
		"TRACE: 1   tool strip:::Nowhere",
		"TRACE: 1   tool test:TEST:var:AfterPrefsMk",
		"TRACE: 1   tool true:TRUE:var:AfterPrefsMk",
		"TRACE: - (*Tools).Trace(\"Pkgsrc\")")
}

// As a side-benefit, loadTools also loads the _BUILD_DEFS.
func (s *Suite) Test_Pkgsrc_loadTools__BUILD_DEFS(c *check.C) {
	t := s.Init(c)

	t.SetupTool("echo", "ECHO", AtRunTime)
	pkg := t.SetupPackage("category/package",
		"pre-configure:",
		"\t@${ECHO} ${PKG_SYSCONFDIR} ${VARBASE}")
	t.CreateFileLines("mk/bsd.pkg.mk",
		MkRcsID,
		"_BUILD_DEFS+=\tPKG_SYSCONFBASEDIR PKG_SYSCONFDIR")
	G.Pkgsrc.LoadInfrastructure()

	G.CheckDirent(pkg)

	c.Check(G.Pkgsrc.IsBuildDef("PKG_SYSCONFDIR"), equals, true)
	c.Check(G.Pkgsrc.IsBuildDef("VARBASE"), equals, false)

	// FIXME: There should be a warning for VARBASE, but G.Pkgsrc.UserDefinedVars
	// does not contain anything at mklinechecker.go:/UserDefinedVars/.
}

func (s *Suite) Test_Pkgsrc_loadDocChangesFromFile(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("doc/CHANGES-2018",
		"\tAdded category/package version 1.0 [author1 2015-01-01]", // Wrong year
		"\tUpdated category/package to 1.5 [author2 2018-01-02]",
		"\tRenamed category/package to category/pkg [author3 2018-01-03]",
		"\tMoved category/package to other/package [author4 2018-01-04]",
		"\tRemoved category/package [author5 2018-01-09]", // Too far in the future
		"\tRemoved category/package successor category/package2 [author6 2018-01-06]",
		"\tDowngraded category/package to 1.2 [author7 2018-01-07]",
		"",
		"\ttoo few fields",
		"\ttoo many many many many many fields",
		"\tmissing brackets around author",
		"\tAdded another [new package]")

	changes := G.Pkgsrc.loadDocChangesFromFile(t.File("doc/CHANGES-2018"))

	c.Assert(len(changes), equals, 7)
	c.Check(*changes[0], equals, Change{changes[0].Line, "Added", "category/package", "1.0", "author1", "2015-01-01"})
	c.Check(*changes[1], equals, Change{changes[1].Line, "Updated", "category/package", "1.5", "author2", "2018-01-02"})
	c.Check(*changes[2], equals, Change{changes[2].Line, "Renamed", "category/package", "", "author3", "2018-01-03"})
	c.Check(*changes[3], equals, Change{changes[3].Line, "Moved", "category/package", "", "author4", "2018-01-04"})
	c.Check(*changes[4], equals, Change{changes[4].Line, "Removed", "category/package", "", "author5", "2018-01-09"})
	c.Check(*changes[5], equals, Change{changes[5].Line, "Removed", "category/package", "", "author6", "2018-01-06"})
	c.Check(*changes[6], equals, Change{changes[6].Line, "Downgraded", "category/package", "1.2", "author7", "2018-01-07"})

	t.CheckOutputLines(
		"WARN: ~/doc/CHANGES-2018:1: Year 2015 for category/package does not match the file name ~/doc/CHANGES-2018.",
		"WARN: ~/doc/CHANGES-2018:6: Date 2018-01-06 for category/package is earlier than 2018-01-09 for category/package.",
		"WARN: ~/doc/CHANGES-2018:12: Unknown doc/CHANGES line: \tAdded another [new package]")
}

func (s *Suite) Test_Pkgsrc_loadDocChanges__not_found(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()
	t.Remove("doc/CHANGES-2018")
	t.Remove("doc/TODO")
	t.Remove("doc")

	t.ExpectFatal(
		G.Pkgsrc.loadDocChanges,
		"FATAL: ~/doc: Cannot be read for loading the package changes.")
}

func (s *Suite) Test_Pkgsrc_loadDocChangesFromFile__not_found(c *check.C) {
	t := s.Init(c)

	t.ExpectFatal(
		func() { G.Pkgsrc.loadDocChangesFromFile(t.File("doc/CHANGES-2018")) },
		"FATAL: ~/doc/CHANGES-2018: Cannot be read.")
}

func (s *Suite) Test_Pkgsrc_loadDocChangesFromFile__wip(c *check.C) {
	t := s.Init(c)

	pkg := t.SetupPackage("wip/package",
		"DISTNAME=\tpackage-1.11",
		"CATEGORIES=\tlocal")
	t.CreateFileLines("wip/TODO",
		RcsID,
		"",
		"Suggested package updates",
		"",
		"\to package-1.13 [cool new features]")
	G.Pkgsrc.LoadInfrastructure()

	G.CheckDirent(pkg)

	t.CheckOutputLines(
		"WARN: ~/wip/package/Makefile:3: This package should be updated to 1.13 ([cool new features]).")
}

func (s *Suite) Test_Pkgsrc__deprecated(c *check.C) {
	t := s.Init(c)

	t.SetupTool("echo", "ECHO", AtRunTime)
	G.Pkgsrc.initDeprecatedVars()
	mklines := t.NewMkLines("Makefile",
		"USE_PERL5=\tyes",
		"SUBST_POSTCMD.class=${ECHO}")

	MkLineChecker{mklines.mklines[0]}.checkVarassign()
	MkLineChecker{mklines.mklines[1]}.checkVarassign()

	t.CheckOutputLines(
		"WARN: Makefile:1: Definition of USE_PERL5 is deprecated. Use USE_TOOLS+=perl or USE_TOOLS+=perl:run instead.",
		"WARN: Makefile:2: Definition of SUBST_POSTCMD.class is deprecated. Has been removed, as it seemed unused.")
}

func (s *Suite) Test_Pkgsrc_ListVersions__no_basedir(c *check.C) {
	t := s.Init(c)

	versions := G.Pkgsrc.ListVersions("lang", `^python[0-9]+$`, "../../lang/$0", true)

	c.Check(versions, check.HasLen, 0)
	t.CheckOutputLines(
		"ERROR: Cannot find package versions of \"^python[0-9]+$\" in \"~/lang\".")
}

func (s *Suite) Test_Pkgsrc_ListVersions__no_subdirs(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("lang/Makefile")

	versions := G.Pkgsrc.ListVersions("lang", `^python[0-9]+$`, "../../lang/$0", true)

	c.Check(versions, check.HasLen, 0)
	t.CheckOutputLines(
		"ERROR: Cannot find package versions of \"^python[0-9]+$\" in \"~/lang\".")
}

// Ensures that failed lookups are also cached since they can be assumed
// not to change during a single pkglint run.
func (s *Suite) Test_Pkgsrc_ListVersions__error_is_cached(c *check.C) {
	t := s.Init(c)

	versions := G.Pkgsrc.ListVersions("lang", `^python[0-9]+$`, "../../lang/$0", true)

	c.Check(versions, check.HasLen, 0)
	t.CheckOutputLines(
		"ERROR: Cannot find package versions of \"^python[0-9]+$\" in \"~/lang\".")

	versions2 := G.Pkgsrc.ListVersions("lang", `^python[0-9]+$`, "../../lang/$0", true)

	c.Check(versions2, check.HasLen, 0)
	t.CheckOutputEmpty() // No repeated error message
}

func (s *Suite) Test_Pkgsrc__caching(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("lang/Makefile")
	t.CreateFileLines("lang/python27/Makefile")

	latest := G.Pkgsrc.Latest("lang", `^python[0-9]+$`, "../../lang/$0")

	c.Check(latest, equals, "../../lang/python27")

	cached := G.Pkgsrc.Latest("lang", `^python[0-9]+$`, "../../lang/$0")

	c.Check(cached, equals, "../../lang/python27")
}

func (s *Suite) Test_Pkgsrc_Latest__multi(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("lang/Makefile")
	t.CreateFileLines("lang/python27/Makefile")
	t.CreateFileLines("lang/python35/Makefile")

	latest := G.Pkgsrc.Latest("lang", `^python[0-9]+$`, "../../lang/$0")

	c.Check(latest, equals, "../../lang/python35")
}

func (s *Suite) Test_Pkgsrc_Latest__not_found(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("lang/Makefile")

	latest := G.Pkgsrc.Latest("lang", `^python[0-9]+$`, "../../lang/$0")

	c.Check(latest, equals, "")

	t.CheckOutputLines(
		"ERROR: Cannot find package versions of \"^python[0-9]+$\" in \"~/lang\".")
}

// In 2017, PostgreSQL changed their versioning scheme to SemVer,
// and since the pkgsrc directory contains the major version,
// without any separating dots, the case of version 10 being
// later than 95 needs to be handled specially.
func (s *Suite) Test_Pkgsrc_ListVersions__postgresql(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("databases/postgresql95/Makefile")
	t.CreateFileLines("databases/postgresql97/Makefile")
	t.CreateFileLines("databases/postgresql10/Makefile")
	t.CreateFileLines("databases/postgresql11/Makefile")

	versions := G.Pkgsrc.ListVersions("databases", `^postgresql[0-9]+$`, "$0", true)

	c.Check(versions, check.DeepEquals, []string{
		"postgresql95",
		"postgresql97",
		"postgresql10",
		"postgresql11"})
}

func (s *Suite) Test_Pkgsrc_ListVersions__numeric_multiple_numbers(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("emulators/suse_131_32_gtk2/Makefile")
	t.CreateFileLines("emulators/suse_131_32_qt5/Makefile")
	t.CreateFileLines("emulators/suse_131_gtk2/Makefile")
	t.CreateFileLines("emulators/suse_131_qt5/Makefile")

	versions := G.Pkgsrc.ListVersions("emulators", `^suse_(\d+).*$`, "$1", true)

	c.Check(versions, deepEquals, []string{
		"131",
		"131",
		"131",
		"131"})
}

func (s *Suite) Test_Pkgsrc_ListVersions__go(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("lang/go14/Makefile")
	t.CreateFileLines("lang/go19/Makefile")
	t.CreateFileLines("lang/go111/Makefile")
	t.CreateFileLines("lang/go2/Makefile")

	versionsUpTo2 := G.Pkgsrc.ListVersions("lang", `^go[0-9]+$`, "$0", true)

	c.Check(versionsUpTo2, deepEquals, []string{"go14", "go19", "go111", "go2"})

	t.CreateFileLines("lang/go37/Makefile")

	// Clear the cache; pkglint doesn't expect file system changes during the scan.
	for k := range G.Pkgsrc.listVersions {
		delete(G.Pkgsrc.listVersions, k)
	}

	versionsUpTo37 := G.Pkgsrc.ListVersions("lang", `^go[0-9]+$`, "$0", true)

	c.Check(versionsUpTo37, deepEquals, []string{"go14", "go19", "go111", "go2", "go37"})
}

func (s *Suite) Test_Pkgsrc_ListVersions__invalid_argument(c *check.C) {
	t := s.Init(c)

	t.ExpectPanic(
		func() { G.Pkgsrc.ListVersions("databases", `postgresql[0-9]+`, "$0", true) },
		"Pkglint internal error: Regular expression \"postgresql[0-9]+\" must be anchored at both ends.")
}

func (s *Suite) Test_Pkgsrc_loadPkgOptions(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("mk/defaults/options.description",
		"option-name      Description of the option",
		"<<<<< Merge conflict",
		"===== Merge conflict",
		">>>>> Merge conflict")

	t.ExpectFatal(
		G.Pkgsrc.loadPkgOptions,
		"FATAL: ~/mk/defaults/options.description:2: Unknown line format: <<<<< Merge conflict")
}

func (s *Suite) Test_Pkgsrc_loadTools__no_tools_found(c *check.C) {
	t := s.Init(c)

	t.ExpectFatal(
		G.Pkgsrc.loadTools,
		"FATAL: ~/mk/tools/bsd.tools.mk: Cannot be read.")

	t.CreateFileLines("mk/tools/bsd.tools.mk")

	t.ExpectFatal(
		G.Pkgsrc.loadTools,
		"FATAL: ~/mk/tools/bsd.tools.mk: Must not be empty.")

	t.CreateFileLines("mk/tools/bsd.tools.mk",
		MkRcsID)

	t.ExpectFatal(
		G.Pkgsrc.loadTools,
		"FATAL: ~/mk/tools/bsd.tools.mk: Too few tool files.")
}

// See PR 46570, Ctrl+F "3. In lang/perl5".
func (s *Suite) Test_Pkgsrc_VariableType(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()

	checkType := func(varname string, vartype string) {
		actualType := G.Pkgsrc.VariableType(varname)
		if vartype == "" {
			c.Check(actualType, check.IsNil)
		} else {
			if c.Check(actualType, check.NotNil) {
				c.Check(actualType.String(), equals, vartype)
			}
		}
	}

	checkType("_PERL5_PACKLIST_AWK_STRIP_DESTDIR", "")
	checkType("SOME_DIR", "PathName (guessed)")
	checkType("SOMEDIR", "PathName (guessed)")
	checkType("SEARCHPATHS", "ShellList of PathName (guessed)")
	checkType("MYPACKAGE_USER", "UserGroupName (guessed)")
	checkType("MYPACKAGE_GROUP", "UserGroupName (guessed)")
	checkType("MY_CMD_ENV", "ShellList of ShellWord (guessed)")
	checkType("MY_CMD_ARGS", "ShellList of ShellWord (guessed)")
	checkType("MY_CMD_CFLAGS", "ShellList of CFlag (guessed)")
	checkType("MY_CMD_LDFLAGS", "ShellList of LdFlag (guessed)")
	checkType("PLIST.abcde", "Yes")
}

// Guessing the variable type works for both plain and parameterized variable names.
func (s *Suite) Test_Pkgsrc_VariableType__varparam(c *check.C) {
	t := s.Init(c)

	t.SetupVartypes()

	t1 := G.Pkgsrc.VariableType("FONT_DIRS")

	c.Assert(t1, check.NotNil)
	c.Check(t1.String(), equals, "ShellList of PathMask (guessed)")

	t2 := G.Pkgsrc.VariableType("FONT_DIRS.ttf")

	c.Assert(t2, check.NotNil)
	c.Check(t2.String(), equals, "ShellList of PathMask (guessed)")
}

// Guessing the variable type also works for variables that are
// not known to pkglint but are found when scanning mk/* for otherwise
// unknown variables.
func (s *Suite) Test_Pkgsrc_VariableType__from_mk(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()
	t.CreateFileLines("mk/sys-vars.mk",
		MkRcsID,
		"",
		"PKGSRC_MAKE_ENV?=\t# none",
		"CPPPATH?=\tcpp")

	pkg := t.SetupPackage("category/package",
		"PKGSRC_MAKE_ENV+=\tCPP=${CPPPATH:Q}",
		"PKGSRC_UNKNOWN_ENV+=\tCPP=${ABCPATH:Q}")

	G.Main("pkglint", "-Wall", pkg)

	if typ := G.Pkgsrc.VariableType("PKGSRC_MAKE_ENV"); c.Check(typ, check.NotNil) {
		c.Check(typ.String(), equals, "ShellList of ShellWord (guessed)")
	}

	if typ := G.Pkgsrc.VariableType("CPPPATH"); c.Check(typ, check.NotNil) {
		c.Check(typ.String(), equals, "Pathlist (guessed)")
	}

	// No warnings about "defined but not used" or "used but not defined"
	// (which both rely on VariableType) may appear here for PKGSRC_MAKE_ENV
	// and CPPPATH since these two variables are defined somewhere in the
	// infrastructure.
	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:21: ABCPATH is used but not defined.",
		"WARN: ~/category/package/Makefile:21: PKGSRC_UNKNOWN_ENV is defined but not used.",
		"0 errors and 2 warnings found.")
}
