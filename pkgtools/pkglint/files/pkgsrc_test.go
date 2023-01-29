package pkglint

import (
	"gopkg.in/check.v1"
	"os"
	"path/filepath"
)

func (s *Suite) Test_Pkgsrc__frozen(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileLines("doc/CHANGES-2018",
		"\tmk/bsd.pkg.mk: started freeze for pkgsrc-2018Q2 branch [freezer 2018-03-25]")
	t.FinishSetUp()

	t.CheckEquals(G.Pkgsrc.changes.LastFreezeStart, "2018-03-25")
}

func (s *Suite) Test_Pkgsrc__not_frozen(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileLines("doc/CHANGES-2018",
		"\tmk/bsd.pkg.mk: started freeze for pkgsrc-2018Q2 branch [freezer 2018-03-25]",
		"\tmk/bsd.pkg.mk: freeze ended for pkgsrc-2018Q2 branch [freezer 2018-03-27]")
	t.FinishSetUp()

	t.CheckEquals(G.Pkgsrc.changes.LastFreezeStart, "2018-03-25")
	t.CheckEquals(G.Pkgsrc.changes.LastFreezeEnd, "2018-03-27")
}

func (s *Suite) Test_Pkgsrc__frozen_with_typo(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileLines("doc/CHANGES-2018",
		// The closing bracket is missing.
		"\tmk/bsd.pkg.mk: started freeze for pkgsrc-2018Q2 branch [freezer 2018-03-25")
	t.FinishSetUp()

	t.CheckEquals(G.Pkgsrc.changes.LastFreezeStart, "")
}

func (s *Suite) Test_Pkgsrc__caching(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("lang/Makefile")
	t.CreateFileLines("lang/python27/Makefile")

	latest := G.Pkgsrc.Latest("lang", `^python[0-9]+$`, "../../lang/$0")

	t.CheckEquals(latest, "../../lang/python27")

	cached := G.Pkgsrc.Latest("lang", `^python[0-9]+$`, "../../lang/$0")

	t.CheckEquals(cached, "../../lang/python27")
}

// Ensures that pkglint can handle MASTER_SITES definitions with and
// without line continuations.
//
// See https://mail-index.netbsd.org/tech-pkg/2017/01/18/msg017698.html.
func (s *Suite) Test_Pkgsrc_loadMasterSites(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("mk/fetch/sites.mk",
		MkCvsID,
		"",
		"MASTER_SITE_A+= https://example.org/distfiles/",
		"MASTER_SITE_B+= https://b.example.org/distfiles/ \\",
		"  https://b2.example.org/distfiles/",
		"MASTER_SITE_A+= https://a.example.org/distfiles/ ${other}",
		"",
		"MASTER_SITE_BACKUP+=\t",
		"\thttps://backup.example.org/",
		"",
		"OTHER_VARIABLE=\tyes # only for code coverage")

	G.Pkgsrc.loadMasterSites()

	t.CheckEquals(G.Pkgsrc.MasterSiteURLToVar["example.org/distfiles/"], "MASTER_SITE_A")
	t.CheckEquals(G.Pkgsrc.MasterSiteURLToVar["b.example.org/distfiles/"], "MASTER_SITE_B")
	t.CheckEquals(G.Pkgsrc.MasterSiteURLToVar["b2.example.org/distfiles/"], "MASTER_SITE_B")
	t.CheckEquals(G.Pkgsrc.MasterSiteURLToVar["a.example.org/distfiles/"], "MASTER_SITE_A")
	t.CheckEquals(G.Pkgsrc.MasterSiteVarToURL["MASTER_SITE_A"], "https://example.org/distfiles/")
	t.CheckEquals(G.Pkgsrc.MasterSiteVarToURL["MASTER_SITE_B"], "https://b.example.org/distfiles/")

	// Ignored entries:
	t.CheckEquals(G.Pkgsrc.MasterSiteURLToVar["${other}"], "")
	t.CheckEquals(G.Pkgsrc.MasterSiteURLToVar["backup.example.org/"], "")
	t.CheckEquals(G.Pkgsrc.MasterSiteVarToURL["MASTER_SITE_BACKUP"], "")
}

func (s *Suite) Test_Pkgsrc_loadPkgOptions(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("mk/defaults/options.description",
		"option-name      Description of the option",
		"<<<<< Merge conflict",
		"===== Merge conflict",
		">>>>> Merge conflict")

	G.Pkgsrc.loadPkgOptions()

	t.CheckOutputLines(
		"ERROR: ~/mk/defaults/options.description:2: Invalid line format: <<<<< Merge conflict",
		"ERROR: ~/mk/defaults/options.description:3: Invalid line format: ===== Merge conflict",
		"ERROR: ~/mk/defaults/options.description:4: Invalid line format: >>>>> Merge conflict")
}

func (s *Suite) Test_Pkgsrc_parseSuggestedUpdates(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("doc/TODO",
		CvsID,
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

	t.CheckDeepEquals(todo, []SuggestedUpdate{
		{lines.Lines[6].Location, "CSP", "0.34", ""},
		{lines.Lines[7].Location, "freeciv-client", "2.5.0", "(urgent)"}})
}

func (s *Suite) Test_Pkgsrc_parseSuggestedUpdates__wip(c *check.C) {
	t := s.Init(c)

	pkg := t.SetUpPackage("wip/package",
		"DISTNAME=\tpackage-1.11")
	t.CreateFileLines("wip/TODO",
		CvsID,
		"",
		"Suggested package updates",
		"",
		"\to package-1.13 [cool new features]")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckOutputLines(
		"WARN: ~/wip/package/Makefile:3: " +
			"This package should be updated to 1.13 (cool new features; see ../../wip/TODO:5).")
}

func (s *Suite) Test_Pkgsrc_parseSuggestedUpdates__parse_errors(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("doc/TODO",
		"", // missing CvsID
		"Suggested package updates",
		"==============", // usually this line is a bit longer
		"",
		"", // usually there's only a single empty line
		"\t"+"O wrong bullet",
		"\t"+"o package-without-version",
		"\t"+"o CSP-0.34",
		"\t"+"o freeciv-client-2.5.0 (urgent)", // missing [brackets]
		"\t"+"o mix-2.5.0 [urgent)",            // bracket + parenthesis
		"",
		"\t"+"o ignored-0.0")

	todo := G.Pkgsrc.parseSuggestedUpdates(lines)

	t.CheckDeepEquals(todo, []SuggestedUpdate{
		{lines.Lines[7].Location, "CSP", "0.34", ""},
		{lines.Lines[8].Location, "freeciv-client", "2.5.0", "(urgent)"},
		{lines.Lines[9].Location, "mix", "2.5.0", "[urgent)"}})

	t.CheckOutputLines(
		"WARN: doc/TODO:6: Invalid line format \"\\tO wrong bullet\".",
		"WARN: doc/TODO:7: Invalid package name \"package-without-version\".")
}

func (s *Suite) Test_Pkgsrc_loadTools(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("mk/tools/bsd.tools.mk",
		".include \"flex.mk\"",
		".include \"gettext.mk\"",
		".include \"../nonexistent.mk\"", // Is skipped because of the slash.
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
	t.CreateFileLines("mk/tools/tools.NetBSD.mk",
		"TOOLS_PLATFORM.ggrep=\t/usr/bin/grep")

	G.Pkgsrc.loadTools()

	t.EnableTracingToLog()
	G.Pkgsrc.Tools.Trace()
	t.DisableTracing()

	t.CheckOutputLines(
		"TRACE: + (*Tools).Trace()",
		"TRACE: 1   tool bzcat:::Nowhere",
		"TRACE: 1   tool bzip2:::Nowhere",
		"TRACE: 1   tool chown:CHOWN::Nowhere",
		"TRACE: 1   tool echo:ECHO:var:AfterPrefsMk",
		"TRACE: 1   tool echo -n:ECHO_N:var:AfterPrefsMk",
		"TRACE: 1   tool false:FALSE:var:AtRunTime",
		"TRACE: 1   tool gawk:AWK::Nowhere",
		"TRACE: 1   tool ggrep:::Nowhere",
		"TRACE: 1   tool m4:::AfterPrefsMk",
		"TRACE: 1   tool msgfmt:::AtRunTime",
		"TRACE: 1   tool mv:MV::AtRunTime",
		"TRACE: 1   tool pwd:PWD::AfterPrefsMk",
		"TRACE: 1   tool strip:::AtRunTime",
		"TRACE: 1   tool test:TEST:var:AfterPrefsMk",
		"TRACE: 1   tool true:TRUE:var:AfterPrefsMk",
		"TRACE: - (*Tools).Trace()")
}

// As a side-benefit, loadTools also loads the _BUILD_DEFS.
func (s *Suite) Test_Pkgsrc_loadTools__BUILD_DEFS(c *check.C) {
	t := s.Init(c)

	t.SetUpTool("echo", "ECHO", AtRunTime)
	pkg := t.SetUpPackage("category/package",
		"pre-configure:",
		"\t@${ECHO} ${PKG_SYSCONFDIR} ${VARBASE}")
	t.CreateFileLines("mk/bsd.pkg.mk",
		MkCvsID,
		"_BUILD_DEFS+=\tPKG_SYSCONFBASEDIR PKG_SYSCONFDIR",
		"",
		"BUILD_DEFINITIONS+=\tIGNORED\t")
	t.CreateFileLines("mk/defaults/mk.conf",
		MkCvsID,
		"",
		"VARBASE=\t\t/var/pkg",
		"PKG_SYSCONFBASEDIR=\t/usr/pkg/etc",
		"PKG_SYSCONFDIR=\t/usr/pkg/etc")
	t.FinishSetUp()

	G.Check(pkg)

	t.CheckEquals(G.Pkgsrc.IsBuildDef("PKG_SYSCONFDIR"), true)
	t.CheckEquals(G.Pkgsrc.IsBuildDef("VARBASE"), false)

	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:21: " +
			"The user-defined variable VARBASE is used but not added to BUILD_DEFS.")
}

func (s *Suite) Test_Pkgsrc_loadTools__conditional_in_mk_tools(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/tools/defaults.mk",
		".if 0",
		"USE_TOOLS+=\tcond-false",
		".endif",
		".if 1",
		"USE_TOOLS+=\tcond-true",
		".endif",
		"USE_TOOLS+=\tunconditional")
	t.FinishSetUp()

	// The above FinishSetUp implicitly and indirectly calls loadTools.

	t.CheckEquals(G.Pkgsrc.Tools.ByName("cond-false").Validity, Nowhere)
	t.CheckEquals(G.Pkgsrc.Tools.ByName("cond-true").Validity, Nowhere)
	t.CheckEquals(G.Pkgsrc.Tools.ByName("unconditional").Validity, AtRunTime)
}

func (s *Suite) Test_Pkgsrc_loadTools__conditional_in_bsd_pkg_mk(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/bsd.pkg.mk",
		".if 0",
		"USE_TOOLS+=\tcond-false",
		".endif",
		".if 1",
		"USE_TOOLS+=\tcond-true",
		".endif",
		"USE_TOOLS+=\tunconditional")
	t.FinishSetUp()

	// The above FinishSetUp implicitly and indirectly calls loadTools.

	t.CheckEquals(G.Pkgsrc.Tools.ByName("cond-false").Validity, Nowhere)
	t.CheckEquals(G.Pkgsrc.Tools.ByName("cond-true").Validity, Nowhere)
	t.CheckEquals(G.Pkgsrc.Tools.ByName("unconditional").Validity, AtRunTime)
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
		MkCvsID)

	t.ExpectFatal(
		G.Pkgsrc.loadTools,
		"FATAL: ~/mk/tools/bsd.tools.mk: Too few tool files.")
}

// Just for code coverage, for the IsRelevant callback.
func (s *Suite) Test_Pkgsrc_loadToolsPlatform__redundant(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.SetUpTool("tool", "", AfterPrefsMk)
	t.CreateFileLines("mk/tools/tools.NetBSD.mk",
		"TOOLS_PLATFORM.tool?=\t/bin/available",
		"TOOLS_PLATFORM.tool?=\t/bin/available")
	t.Chdir(".")
	t.FinishSetUp()
}

func (s *Suite) Test_Pkgsrc_initDeprecatedVars(c *check.C) {
	t := s.Init(c)

	t.SetUpTool("echo", "ECHO", AtRunTime)
	t.SetUpVartypes()
	G.Pkgsrc.initDeprecatedVars()
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"USE_PERL5=\t\tyes",
		"SUBST_POSTCMD.class=\t${ECHO}",
		"CPPFLAGS+=\t\t${BUILDLINK_CPPFLAGS.${PKG_JVM}}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: Makefile:2: Definition of USE_PERL5 is deprecated. "+
			"Use USE_TOOLS+=perl or USE_TOOLS+=perl:run instead.",
		"WARN: Makefile:3: Definition of SUBST_POSTCMD.class is deprecated. "+
			"Has been removed, as it seemed unused.")
}

func (s *Suite) Test_Pkgsrc_loadUntypedVars(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.SetUpTool("echo", "ECHO", AtRunTime)
	t.CreateFileLines("mk/infra.mk",
		MkCvsID,
		"#",
		"# System-provided variables:",
		"#",
		"# DOCUMENTED",
		"#\tThis variable is not actually defined but still documented.",
		"#\tThis may be because its definition is evaluated dynamically.",
		"",
		".if !defined(INFRA_MK)",
		"INFRA_MK:=",
		"",
		"UNTYPED.one=\tone",
		"UNTYPED.two=\ttwo",
		"ECHO=\t\techo",
		"_UNTYPED=\tinfrastructure only",
		".for p in param",
		"PARAMETERIZED.${p}=\tparameterized",
		"INDIRECT_${p}=\tindirect",
		".endfor",
		"#COMMENTED=\tcommented",
		".endif")
	t.FinishSetUp()

	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"",
		"do-build:",
		"\t: ${INFRA_MK} ${UNTYPED.three} ${ECHO}",
		"\t: ${_UNTYPED} ${PARAMETERIZED.param}",
		"\t: ${INDIRECT_param}",
		"\t: ${DOCUMENTED} ${COMMENTED}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: filename.mk:4: INFRA_MK is used but not defined.",
		"WARN: filename.mk:5: _UNTYPED is used but not defined.",
		"WARN: filename.mk:6: INDIRECT_param is used but not defined.")
}

func (s *Suite) Test_Pkgsrc_loadUntypedVars__badly_named_directory(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/subdir.mk/file.mk",
		MkCvsID)
	t.FinishSetUp()

	// Even when a directory is named *.mk, pkglint doesn't crash.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Pkgsrc_loadUntypedVars__local_varnames(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("mk/check/check-files.mk",
		MkCvsID,
		"${:U}=\t${CHECK_FILES_SKIP:@f@${f}@}",
		"\t${/} ${} ${UNKNOWN}")

	G.Pkgsrc.loadUntypedVars()

	ignored := func(varname string) {
		vartype := G.Pkgsrc.VariableType(nil, varname)
		t.Check(vartype, check.IsNil, check.Commentf("%s", varname))
	}
	added := func(varname string, basicType *BasicType) {
		vartype := G.Pkgsrc.VariableType(nil, "CHECK_FILES_SKIP")
		if t.CheckNotNil(vartype) {
			t.CheckEquals(vartype.basicType, BtPathPattern)
		}
	}

	added("CHECK_FILES_SKIP", BtPathPattern)
	added("UNKNOWN", BtUnknown)

	ignored("")
	ignored("f")
	ignored(".f.")
	ignored("/")
	ignored("PREFIX")

	t.CheckOutputLines(
		"WARN: ~/mk/check/check-files.mk:3: " +
			"Invalid part \"/\" after variable name \"\".")
}

// An optional tool is not available by default.
// A package can choose to include a tool by adding it to USE_TOOLS.
func (s *Suite) Test_Pkgsrc_loadUntypedVars__tools(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"do-configure:",
		"\tlinux-tool",
		"\toptional-tool")
	t.CreateFileLines("mk/tools/default.mk",
		MkCvsID,
		"",
		// This tool is available by default.
		".if ${OPSYS} == Linux",
		"TOOLS_CREATE+=\tlinux-tool",
		".endif",
		"",
		// This tool is only available if it is listed in USE_TOOLS.
		".if ${_USE_TOOLS:Moptional-tool}",
		"TOOLS_CREATE+=\toptional-tool",
		".endif")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	// FIXME: The command names must be recognized.
	// TODO: linux-tool must be available to the package.
	// TODO: optional-tool must not be available to the package.
	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:21: "+
			"Unknown shell command \"linux-tool\".",
		"WARN: ~/category/package/Makefile:22: "+
			"Unknown shell command \"optional-tool\".")
}

func (s *Suite) Test_Pkgsrc_Latest__multiple_candidates(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("lang/Makefile")
	t.CreateFileLines("lang/python27/Makefile")
	t.CreateFileLines("lang/python35/Makefile")

	latest := G.Pkgsrc.Latest("lang", `^python[0-9]+$`, "../../lang/$0")

	t.CheckEquals(latest, "../../lang/python35")
}

func (s *Suite) Test_Pkgsrc_Latest__not_found(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("lang/Makefile")

	latest := G.Pkgsrc.Latest("lang", `^python[0-9]+$`, "../../lang/$0")

	t.CheckEquals(latest, "")

	t.CheckOutputLines(
		"ERROR: ~/lang: Cannot find package versions of \"^python[0-9]+$\".")
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

	t.CheckDeepEquals(versions, []string{
		"postgresql95",
		"postgresql97",
		"postgresql10",
		"postgresql11"})
}

func (s *Suite) Test_Pkgsrc_ListVersions__ensure_transitive(c *check.C) {
	t := s.Init(c)

	names := []string{
		"base",
		"base0",
		"base000",
		"base-client",
		"base1",
		"base01",
		"base-client1",
		"base5",
		"base10"}

	keys := make(map[string]int)
	for _, name := range names {
		if m, _, versionStr := match2(name, `^(\D+)(\d+)$`); m {
			keys[name] = toInt(versionStr, 0)
		}
	}

	less := func(a, b string) bool {
		if keyI, keyJ := keys[a], keys[b]; keyI != keyJ {
			return keyI < keyJ
		}
		return naturalLess(a, b)
	}

	test := func(i int, j int) {
		actual := less(names[i], names[j])
		expected := i < j
		if actual != expected {
			t.CheckDeepEquals(
				[]interface{}{names[i], condStr(actual, "<", "!<"), names[j]},
				[]interface{}{names[i], condStr(expected, "<", "!<"), names[j]})
		}
	}

	for i := range names {
		for j := range names {
			test(i, j)
		}
	}
}

func (s *Suite) Test_Pkgsrc_ListVersions__numeric_multiple_numbers(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("emulators/suse_131_32_gtk2/Makefile")
	t.CreateFileLines("emulators/suse_131_32_qt5/Makefile")
	t.CreateFileLines("emulators/suse_131_gtk2/Makefile")
	t.CreateFileLines("emulators/suse_131_qt5/Makefile")

	versions := G.Pkgsrc.ListVersions("emulators", `^suse_(\d+).*$`, "$1", true)

	t.CheckDeepEquals(versions, []string{
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

	t.CheckDeepEquals(versionsUpTo2, []string{"go14", "go19", "go111", "go2"})

	t.CreateFileLines("lang/go37/Makefile")

	// Clear the cache; pkglint doesn't expect file system changes during the scan.
	for k := range G.Pkgsrc.listVersions {
		delete(G.Pkgsrc.listVersions, k)
	}

	versionsUpTo37 := G.Pkgsrc.ListVersions("lang", `^go[0-9]+$`, "$0", true)

	t.CheckDeepEquals(versionsUpTo37, []string{"go14", "go19", "go111", "go2", "go37"})
}

func (s *Suite) Test_Pkgsrc_ListVersions__invalid_argument(c *check.C) {
	t := s.Init(c)

	t.ExpectAssert(func() { G.Pkgsrc.ListVersions("databases", `postgresql[0-9]+`, "$0", true) })
	t.ExpectAssert(func() { G.Pkgsrc.ListVersions("databases", `^postgresql[0-9]+`, "$0", true) })

	G.Testing = false
	versions := G.Pkgsrc.ListVersions("databases", `^postgresql[0-9]+`, "$0", false)

	t.CheckLen(versions, 0)
}

func (s *Suite) Test_Pkgsrc_ListVersions__no_basedir(c *check.C) {
	t := s.Init(c)

	versions := G.Pkgsrc.ListVersions("lang", `^python[0-9]+$`, "../../lang/$0", true)

	t.CheckLen(versions, 0)
	t.CheckOutputLines(
		"ERROR: ~/lang: Cannot find package versions of \"^python[0-9]+$\".")
}

func (s *Suite) Test_Pkgsrc_ListVersions__no_subdirs(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("lang/Makefile")

	versions := G.Pkgsrc.ListVersions("lang", `^python[0-9]+$`, "../../lang/$0", true)

	t.CheckLen(versions, 0)
	t.CheckOutputLines(
		"ERROR: ~/lang: Cannot find package versions of \"^python[0-9]+$\".")
}

// Ensures that failed lookups are also cached since they can be assumed
// not to change during a single pkglint run.
func (s *Suite) Test_Pkgsrc_ListVersions__error_is_cached(c *check.C) {
	t := s.Init(c)

	versions := G.Pkgsrc.ListVersions("lang", `^python[0-9]+$`, "../../lang/$0", true)

	t.CheckLen(versions, 0)
	t.CheckOutputLines(
		"ERROR: ~/lang: Cannot find package versions of \"^python[0-9]+$\".")

	versions2 := G.Pkgsrc.ListVersions("lang", `^python[0-9]+$`, "../../lang/$0", true)

	t.CheckLen(versions2, 0)
	t.CheckOutputEmpty() // No repeated error message
}

func (s *Suite) Test_Pkgsrc_ListVersions__empty_directories_are_ignored(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("lang/lang123/Makefile")
	t.CreateFileLines("lang/lang124/empty/empty/empty/empty/CVS/Entries")

	versions := G.Pkgsrc.ListVersions("lang", `^lang[0-9]+$`, "lang/$0", true)

	// lang/lang124 is not mentioned since it is "essentially empty".
	t.CheckDeepEquals(versions, []string{"lang/lang123"})
}

// See PR 46570, Ctrl+F "3. In lang/perl5".
func (s *Suite) Test_Pkgsrc_VariableType(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("echo", "ECHO", AtRunTime)

	test := func(varname string, vartype string) {
		actualType := G.Pkgsrc.VariableType(nil, varname)
		if vartype == "" {
			t.CheckNil(actualType)
		} else {
			if t.CheckNotNil(actualType) {
				t.CheckEquals(actualType.String(), vartype)
			}
		}
	}

	test("_PERL5_PACKLIST_AWK_STRIP_DESTDIR", "")
	test("SOME_DIR", "Pathname (guessed)")
	test("SOMEDIR", "Pathname (guessed)")
	test("SEARCHPATHS", "Pathname (list, guessed)")
	test("MYPACKAGE_USER", "UserGroupName (guessed)")
	test("MYPACKAGE_GROUP", "UserGroupName (guessed)")
	test("MY_CMD_ENV", "ShellWord (list, guessed)")
	test("MY_CMD_ARGS", "ShellWord (list, guessed)")
	test("MY_CMD_CFLAGS", "CFlag (list, guessed)")
	test("MY_CMD_LDFLAGS", "LdFlag (list, guessed)")
	test("PLIST.abcde", "Yes (package-settable)")
	test("TOOLS_ECHO", "Pathname")
	test("TOOLS_UNKNOWN", "")
}

// Guessing the variable type works for both plain and parameterized variable names.
func (s *Suite) Test_Pkgsrc_VariableType__varparam(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()

	t1 := G.Pkgsrc.VariableType(nil, "FONT_DIRS")

	t.AssertNotNil(t1)
	t.CheckEquals(t1.String(), "PathPattern (list, guessed)")

	t2 := G.Pkgsrc.VariableType(nil, "FONT_DIRS.ttf")

	t.AssertNotNil(t2)
	t.CheckEquals(t2.String(), "PathPattern (list, guessed)")
}

// Guessing the variable type also works for variables that are
// not known to pkglint but are found when scanning mk/* for otherwise
// unknown variables.
func (s *Suite) Test_Pkgsrc_VariableType__from_mk(c *check.C) {
	t := s.Init(c)

	// The type of OSNAME.* cannot be guessed from the variable name,
	// but it is a known variable since the pkgsrc infrastructure uses
	// it. But still, its type is unknown.

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/sys-vars.mk",
		MkCvsID,
		"",
		"PKGSRC_MAKE_ENV?=\t# none",
		"CPPPATH?=\tcpp",
		"OSNAME.Linux?=\tLinux")
	t.SetUpPackage("category/package",
		"PKGSRC_MAKE_ENV+=\tCPP=${CPPPATH:Q}",
		"PKGSRC_UNKNOWN_ENV+=\tCPP=${ABCPATH:Q}",
		"OSNAME.SunOS=\t\t${OSNAME.Other}")

	t.Main("-Wall", "category/package")

	if typ := G.Pkgsrc.VariableType(nil, "PKGSRC_MAKE_ENV"); t.CheckNotNil(typ) {
		t.CheckEquals(typ.String(), "ShellWord (list, guessed)")
	}

	if typ := G.Pkgsrc.VariableType(nil, "CPPPATH"); t.CheckNotNil(typ) {
		t.CheckEquals(typ.String(), "Pathlist (guessed)")
	}

	if typ := G.Pkgsrc.VariableType(nil, "OSNAME.Other"); t.CheckNotNil(typ) {
		t.CheckEquals(typ.String(), "Unknown")
	}

	// No warnings about "defined but not used" or "used but not defined"
	// (which both rely on VariableType) may appear here for PKGSRC_MAKE_ENV
	// and CPPPATH since these two variables are defined somewhere in the
	// infrastructure.
	t.CheckOutputLines(
		"WARN: ~/category/package/Makefile:21: PKGSRC_UNKNOWN_ENV is defined but not used.",
		"WARN: ~/category/package/Makefile:21: ABCPATH is used but not defined.",
		"2 warnings found.",
		t.Shquote("(Run \"pkglint -e -Wall %s\" to show explanations.)", "category/package"))
}

func (s *Suite) Test_Pkgsrc_guessVariableType__SKIP(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"MY_CHECK_SKIP=\t*.c \"quoted*pathname\"",
		"MY_CHECK_SKIP+=\t*.cpp",
		".if ${MY_CHECK_SKIP}",
		".endif")

	mklines.Check()

	vartype := G.Pkgsrc.VariableType(mklines, "MY_CHECK_SKIP")
	t.CheckEquals(vartype.IsGuessed(), true)
	t.CheckEquals(vartype.EffectivePermissions("filename.mk"), aclpAllRuntime)

	// The permissions for MY_CHECK_SKIP say aclpAllRuntime, which excludes
	// aclpUseLoadtime. Therefore, there should be a warning about the VarUse in
	// the .if line. As of March 2019, pkglint skips the permissions check for
	// guessed variables since that variable might have an entirely different
	// meaning; see MkVarUseChecker.checkPermissions.
	//
	// There is no warning for the += operator in line 3 since the variable type
	// (although guessed) is a list of things, and lists may be appended to.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Pkgsrc_checkToplevelUnusedLicenses(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/misc/category.mk")
	t.CreateFileLines("licenses/2-clause-bsd")
	t.CreateFileLines("licenses/gnu-gpl-v3")

	t.CreateFileLines("Makefile",
		MkCvsID,
		"SUBDIR+=\tcategory")

	t.CreateFileLines("category/Makefile",
		MkCvsID,
		"",
		"COMMENT=\tExample category",
		"",
		"SUBDIR+=\tpackage",
		"SUBDIR+=\tpackage2",
		"",
		".include \"../mk/misc/category.mk\"")

	t.SetUpPackage("category/package",
		"LICENSE=\t2-clause-bsd")
	t.SetUpPackage("category/package2",
		"LICENSE=\tmissing")

	t.Main("-r", "-Cglobal", ".")

	t.CheckOutputLines(
		"ERROR: ~/category/package2/Makefile:11: License file ../../licenses/missing does not exist.",
		"WARN: ~/licenses/gnu-gpl-v2: This license seems to be unused.", // Added by Tester.SetUpPkgsrc
		"WARN: ~/licenses/gnu-gpl-v3: This license seems to be unused.",
		"1 error and 2 warnings found.",
		t.Shquote("(Run \"pkglint -e -r -Cglobal %s\" to show explanations.)", "."))
}

func (s *Suite) Test_Pkgsrc_ReadDir(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("dir/aaa-subdir/file")
	t.CreateFileLines("dir/subdir/file")
	t.CreateFileLines("dir/file")
	t.CreateFileLines("dir/.git/file")
	t.CreateFileLines("dir/CVS/Entries")
	t.CreateFileLines("dir/empty/empty/empty/empty/CVS/Entries")

	infos := G.Pkgsrc.ReadDir("dir")

	var names []string
	for _, info := range infos {
		names = append(names, info.Name())
	}

	t.CheckDeepEquals(names, []string{"aaa-subdir", "empty", "file", "subdir"})
}

func (s *Suite) Test_Pkgsrc_Relpath(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(G.Pkgsrc.topdir, t.tmpdir)
	t.Chdir(".")
	t.CheckEquals(G.Pkgsrc.topdir, NewCurrPath("."))

	test := func(from, to CurrPath, result RelPath) {
		t.CheckEquals(G.Pkgsrc.Relpath(from, to), result)
	}

	// TODO: add tests going from each of (top, cat, pkg, pkgsub) to the others

	test("category", "other/package", "../other/package")
	test("category/package", "other", "../../other")

	test("some/dir", "some/directory", "../../some/directory")
	test("some/directory", "some/dir", "../../some/dir")

	test("category/package/.", ".", "../..")

	// This case is handled by one of the shortcuts that avoid file system access.
	test(
		"./.",
		"x11/frameworkintegration/../../meta-pkgs/kde/kf5.mk",
		"meta-pkgs/kde/kf5.mk")

	test(".hidden/dir", ".", "../..")
	test("dir/.hidden", ".", "../..")

	// This happens when "pkglint -r x11" is run.
	G.Pkgsrc.topdir = "x11/.."

	test(
		"./.",
		"x11/frameworkintegration/../../meta-pkgs/kde/kf5.mk",
		"meta-pkgs/kde/kf5.mk")
	test(
		"x11/..",
		"x11/frameworkintegration/../../meta-pkgs/kde/kf5.mk",
		"meta-pkgs/kde/kf5.mk")

	volume := NewCurrPathSlash(filepath.VolumeName(t.tmpdir.String()))
	G.Pkgsrc.topdir = volume.JoinNoClean("usr/pkgsrc")

	// Taken from Test_MkLineChecker_CheckRelativePath__wip_mk
	test(
		G.Pkgsrc.File("wip/package"),
		G.Pkgsrc.File("wip/package/../mk/git-package.mk"),
		"../../wip/mk/git-package.mk")

	// Taken from Test_Package_parse__relative
	test(
		G.Pkgsrc.File("category/package"),
		G.Pkgsrc.File("category/package/../package/extra.mk"),
		"extra.mk")

	// Make sure that .. in later positions is resolved correctly as well.
	test(
		G.Pkgsrc.File("category/package"),
		G.Pkgsrc.File("category/package/sub/../../package/extra.mk"),
		"extra.mk")

	G.Pkgsrc.topdir = t.tmpdir

	test("some/dir", "some/dir/../..", "../..")
	test("some/dir", "some/dir/./././../..", "../..")
	test("some/dir", "some/dir/", ".")

	test("some/dir", ".", "../..")
	test("some/dir/.", ".", "../..")

	chdir := func(path CurrPath) {
		// See Tester.Chdir; a direct Chdir works here since this test
		// neither loads lines nor processes them.
		assertNil(os.Chdir(path.String()), "Chdir %s", path)
		G.cwd = G.Abs(path)
	}

	t.CreateFileLines("testdir/subdir/dummy")
	chdir("testdir/subdir")

	test(".", ".", ".")
	test("./.", "./dir", "dir")

	test("dir", ".", "..")
	test("dir", "dir", ".")
	test("dir", "dir/file", "file")
	test("dir", "dir/..", "..")

	test(".", "../../other/package", "../../other/package")

	// Even though this path could be shortened to "../package",
	// in pkgsrc the convention is to always go from a package
	// directory up to the root and then back to the other package
	// directory.
	test(".", "../../testdir/package", "../../testdir/package")

	chdir("..")

	// When pkglint is run from a category directory to test
	// the complete pkgsrc.
	test("..", "../other/package", "other/package")

	chdir(t.tmpdir.JoinNoClean(".."))

	test(
		"pkgsrc/category/package",
		"pkgsrc/category/package/../../other/package",
		"../../other/package")

	test(
		"pkgsrc/category/package",
		"pkgsrc/category/package/../../category/other",
		"../../category/other")

	chdir(t.tmpdir.JoinNoClean("testdir").JoinNoClean("subdir"))

	test("..", ".", "subdir")
	test("../..", ".", "testdir/subdir")
	test("../../", ".", "testdir/subdir")
}

func (s *Suite) Test_Pkgsrc_File(c *check.C) {
	t := s.Init(c)

	G.Pkgsrc.topdir = "$pkgsrcdir"

	test := func(rel PkgsrcPath, resolved CurrPath) {
		t.CheckEquals(G.Pkgsrc.File(rel), resolved)
	}

	test(".", "$pkgsrcdir")
	test("category", "$pkgsrcdir/category")

	test(
		"category/package/../../mk/bsd.prefs.mk",
		"$pkgsrcdir/mk/bsd.prefs.mk")

	G.Pkgsrc.topdir = "."

	test(".", ".")
	test("filename", "filename")
}

func (s *Suite) Test_Pkgsrc_FilePkg(c *check.C) {
	t := s.Init(c)

	t.Chdir(".")

	test := func(rel PackagePath, abs CurrPath) {
		actual := G.Pkgsrc.FilePkg(rel)
		t.CheckEquals(actual, abs)
	}

	test("", "")
	test("category/package", "")
	test("../package", "")
	test("../../category", "")
	test("../../category/package", "category/package")
	test("../../../something", "")
}
