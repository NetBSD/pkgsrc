package pkglint

import "gopkg.in/check.v1"

func (s *Suite) Test_Tool_UsableAtLoadTime(c *check.C) {
	t := s.Init(c)

	nowhere := Tool{"nowhere", "", false, Nowhere, nil, nil, nil}
	t.CheckEquals(nowhere.UsableAtLoadTime(false), false)
	t.CheckEquals(nowhere.UsableAtLoadTime(true), false)

	load := Tool{"load", "", false, AfterPrefsMk, nil, nil, nil}
	t.CheckEquals(load.UsableAtLoadTime(false), false)
	t.CheckEquals(load.UsableAtLoadTime(true), true)

	run := Tool{"run", "", false, AtRunTime, nil, nil, nil}
	t.CheckEquals(run.UsableAtLoadTime(false), false)
	t.CheckEquals(run.UsableAtLoadTime(true), false)
}

func (s *Suite) Test_Tool_UsableAtLoadTime__pkgconfig_builtin_mk(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--explain")
	t.SetUpTool("tool1", "TOOL1", AfterPrefsMk)
	t.SetUpTool("tool2", "TOOL2", AfterPrefsMk)
	t.SetUpPackage("category/package")
	t.CreateFileLines("mk/buildlink3/pkgconfig-builtin.mk")
	t.FinishSetUp()

	mklines := t.SetUpFileMkLines("category/package/filename.mk",
		MkCvsID,
		"",
		"OUT!=\t${TOOL1} ${OUT}",
		"",
		".include \"../../mk/buildlink3/pkgconfig-builtin.mk\"",
		"",
		"OUT!=\t${TOOL2} ${OUT}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: ~/category/package/filename.mk:3: " +
			"To use the tool ${TOOL1} at load time, " +
			"bsd.prefs.mk has to be included before.")
	// Maybe an explanation might help here.
	// There is surprisingly few feedback on any of the explanations
	// though (about 0 in 10 years), therefore I don't even know
	// whether anyone reads them.
}

func (s *Suite) Test_Tool_UsableAtRunTime(c *check.C) {
	t := s.Init(c)

	nowhere := Tool{"nowhere", "", false, Nowhere, nil, nil, nil}
	t.CheckEquals(nowhere.UsableAtRunTime(), false)

	load := Tool{"load", "", false, AfterPrefsMk, nil, nil, nil}
	t.CheckEquals(load.UsableAtRunTime(), true)

	run := Tool{"run", "", false, AtRunTime, nil, nil, nil}
	t.CheckEquals(run.UsableAtRunTime(), true)
}

func (s *Suite) Test_Tools__USE_TOOLS_predefined_sed(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/bsd.prefs.mk",
		"USE_TOOLS+=\tsed:pkgsrc")
	t.CreateFileLines("mk/tools/defaults.mk",
		"_TOOLS_VARNAME.sed=\tSED")
	t.CreateFileLines("module.mk",
		MkCvsID,
		"",
		"do-build:",
		"\t${SED} < input > output",
		"\t${AWK} < input > output")

	t.Main("-Wall", "module.mk")

	// Since this test doesn't load the usual tool definitions via
	// G.Pkgsrc.loadTools, AWK is not known at all.
	t.CheckOutputLines(
		"WARN: ~/module.mk:5: Unknown shell command \"${AWK}\".",
		"WARN: ~/module.mk:5: AWK is used but not defined.",
		"2 warnings found.",
		t.Shquote("(Run \"pkglint -e -Wall %s\" to show explanations.)", "module.mk"))
}

// It may happen that a tool is first defined without knowing its
// variable name. When trying to define the tool with its variable name
// later, the existing definition is amended.
func (s *Suite) Test_Tools__add_varname_later(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("dummy.mk", 123, "DUMMY=\tvalue")
	tools := NewTools()
	tool := tools.Define("tool", "", mkline)

	t.CheckEquals(tool.Name, "tool")
	t.CheckEquals(tool.Varname, "")

	// Updates the existing tool definition.
	tools.Define("tool", "TOOL", mkline)

	t.CheckEquals(tool.Name, "tool")
	t.CheckEquals(tool.Varname, "TOOL")
}

func (s *Suite) Test_Tools__load_from_infrastructure(c *check.C) {
	t := s.Init(c)

	tools := NewTools()

	// Only used for variable lookup, which is irrelevant for this test.
	dummyMklines := t.NewMkLines("dummy.mk")

	createMklines := t.NewMkLines("create.mk",
		MkCvsID,
		"TOOLS_CREATE+= load",
		"TOOLS_CREATE+= run",
		"TOOLS_CREATE+= nowhere")

	createMklines.ForEach(func(mkline *MkLine) {
		tools.ParseToolLine(createMklines, mkline, true, false)
	})

	// The references to the tools are stable,
	// the lookup methods always return the same objects.
	load := tools.ByName("load")
	run := tools.ByName("run")
	nowhere := tools.ByName("nowhere")

	// All tools are defined by name, but their variable names are not yet known.
	// At this point they may not be used, neither by the pkgsrc infrastructure nor by a package.
	t.CheckEquals(load.String(), "load:::AtRunTime")
	t.CheckEquals(run.String(), "run:::AtRunTime")
	t.CheckEquals(nowhere.String(), "nowhere:::AtRunTime")

	// The variable name RUN is reserved by pkgsrc, therefore RUN_CMD.
	varnamesMklines := t.NewMkLines("varnames.mk",
		MkCvsID,
		"_TOOLS_VARNAME.load=    LOAD",
		"_TOOLS_VARNAME.run=     RUN_CMD",
		"_TOOLS_VARNAME.nowhere= NOWHERE")

	varnamesMklines.ForEach(func(mkline *MkLine) {
		tools.ParseToolLine(varnamesMklines, mkline, true, false)
	})

	// At this point the tools can be found by their variable names, too.
	// They still may not be used.
	t.CheckEquals(load.String(), "load:LOAD::AtRunTime")
	t.CheckEquals(run.String(), "run:RUN_CMD::AtRunTime")
	t.CheckEquals(nowhere.String(), "nowhere:NOWHERE::AtRunTime")
	t.CheckEquals(tools.ByVarname("LOAD"), load)
	t.CheckEquals(tools.ByVarname("RUN_CMD"), run)
	t.CheckEquals(tools.ByVarname("NOWHERE"), nowhere)
	t.CheckEquals(load.String(), "load:LOAD::AtRunTime")
	t.CheckEquals(run.String(), "run:RUN_CMD::AtRunTime")
	t.CheckEquals(nowhere.String(), "nowhere:NOWHERE::AtRunTime")

	tools.ParseToolLine(dummyMklines, t.NewMkLine("bsd.prefs.mk", 2, "USE_TOOLS+= load"), true, true)

	// Tools that are added to USE_TOOLS in bsd.prefs.mk may be used afterwards.
	// By variable name, they may be used both at load time as well as run time.
	// By plain name, they may be used only in {pre,do,post}-* targets.
	t.CheckEquals(load.String(), "load:LOAD::AfterPrefsMk")

	tools.ParseToolLine(dummyMklines, t.NewMkLine("bsd.pkg.mk", 2, "USE_TOOLS+= run"), true, true)

	// Tools that are added to USE_TOOLS in bsd.pkg.mk may be used afterwards at run time.
	// The {pre,do,post}-* targets may use both forms (${CAT} and cat).
	// All other targets must use the variable form (${CAT}).
	t.CheckEquals(run.String(), "run:RUN_CMD::AtRunTime")

	// That's all for parsing tool definitions from the pkgsrc infrastructure.
	// See Test_Tools__package_Makefile for a continuation.
}

func (s *Suite) Test_Tools__package_Makefile(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/tools/defaults.mk",
		"TOOLS_CREATE+=  load",
		"TOOLS_CREATE+=  run",
		"TOOLS_CREATE+=  nowhere",
		"TOOLS_CREATE+=  pkg-before-prefs",
		"TOOLS_CREATE+=  pkg-after-prefs",
		"_TOOLS_VARNAME.load=                    LOAD",
		"_TOOLS_VARNAME.run=                     RUN_CMD",
		"_TOOLS_VARNAME.nowhere=                 NOWHERE",
		"_TOOLS_VARNAME.pkg-before-prefs=        PKG_BEFORE_PREFS",
		"_TOOLS_VARNAME.pkg-after-prefs=         PKG_AFTER_PREFS")
	t.CreateFileLines("mk/bsd.prefs.mk",
		"USE_TOOLS+=     load")
	t.CreateFileLines("mk/bsd.pkg.mk",
		"USE_TOOLS+=     run")
	t.FinishSetUp()

	tools := NewTools()
	tools.Fallback(G.Pkgsrc.Tools)

	load := tools.ByName("load")
	run := tools.ByName("run")
	nowhere := tools.ByName("nowhere")
	before := tools.ByName("pkg-before-prefs")
	after := tools.ByName("pkg-after-prefs")

	t.CheckEquals(load.UsableAtRunTime(), true)
	t.CheckEquals(run.UsableAtRunTime(), true)
	t.CheckEquals(nowhere.UsableAtRunTime(), true)

	// The seenPrefs variable is only relevant for the package Makefile.
	// All other files must not use the tools at load time.
	// For them, seenPrefs can be thought of as being true from the beginning.

	// Only used for variable lookup, which is irrelevant for this test.
	dummyMklines := t.NewMkLines("dummy.mk")

	tools.ParseToolLine(dummyMklines, t.NewMkLine("Makefile", 2, "USE_TOOLS+=     pkg-before-prefs"), false, true)

	t.CheckEquals(before.Validity, AfterPrefsMk)
	t.CheckEquals(tools.SeenPrefs, false)

	tools.ParseToolLine(dummyMklines, t.NewMkLine("Makefile", 3, ".include \"../../mk/bsd.prefs.mk\""), false, true)

	t.CheckEquals(tools.SeenPrefs, true)

	tools.ParseToolLine(dummyMklines, t.NewMkLine("Makefile", 4, "USE_TOOLS+=     pkg-after-prefs"), false, true)

	t.CheckEquals(after.Validity, AtRunTime)
}

func (s *Suite) Test_Tools__builtin_mk(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/tools/defaults.mk",
		"TOOLS_CREATE+=  load",
		"TOOLS_CREATE+=  run",
		"TOOLS_CREATE+=  nowhere",
		"_TOOLS_VARNAME.load=                    LOAD",
		"_TOOLS_VARNAME.run=                     RUN_CMD",
		"_TOOLS_VARNAME.nowhere=                 NOWHERE")
	t.CreateFileLines("mk/bsd.prefs.mk",
		"USE_TOOLS+=     load")
	t.CreateFileLines("mk/bsd.pkg.mk",
		"USE_TOOLS+=     run")
	t.CreateFileLines("mk/buildlink3/bsd.builtin.mk")
	t.FinishSetUp()

	// Tools that are defined by pkgsrc as load-time tools
	// may be used in any file at load time.

	mklines := t.SetUpFileMkLines("category/package/builtin.mk",
		MkCvsID,
		"",
		"VAR!=\t${ECHO} 'too early'",
		"VAR!=\t${LOAD} 'too early'",
		"VAR!=\t${RUN_CMD} 'never allowed'",
		"VAR!=\t${NOWHERE} 'never allowed'",
		"",
		".include \"../../mk/buildlink3/bsd.builtin.mk\"",
		"",
		"VAR!=\t${ECHO} 'valid'",
		"VAR!=\t${LOAD} 'valid'",
		"VAR!=\t${RUN_CMD} 'never allowed'",
		"VAR!=\t${NOWHERE} 'never allowed'",
		"",
		"VAR!=\t${VAR}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: ~/category/package/builtin.mk:3: To use the tool ${ECHO} at load time, bsd.prefs.mk has to be included before.",
		"WARN: ~/category/package/builtin.mk:4: To use the tool ${LOAD} at load time, bsd.prefs.mk has to be included before.",
		"WARN: ~/category/package/builtin.mk:5: The tool ${RUN_CMD} cannot be used at load time.",
		"WARN: ~/category/package/builtin.mk:6: The tool ${NOWHERE} cannot be used at load time.",
		"WARN: ~/category/package/builtin.mk:12: The tool ${RUN_CMD} cannot be used at load time.",
		"WARN: ~/category/package/builtin.mk:13: The tool ${NOWHERE} cannot be used at load time.")
}

func (s *Suite) Test_Tools__implicit_definition_in_bsd_pkg_mk(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/tools/defaults.mk",
		MkCvsID) // None
	t.CreateFileLines("mk/bsd.prefs.mk",
		"USE_TOOLS+=     load")
	t.CreateFileLines("mk/bsd.pkg.mk",
		"USE_TOOLS+=     run")

	// It's practically impossible that a tool is added to USE_TOOLS in
	// bsd.pkg.mk and not defined earlier in mk/tools/defaults.mk, but
	// the pkglint code is even prepared for these rare cases.
	// In other words, this test is only there for the code coverage.
	t.FinishSetUp()

	t.CheckEquals(G.Pkgsrc.Tools.ByName("run").String(), "run:::AtRunTime")
}

func (s *Suite) Test_Tools__both_prefs_and_pkg_mk(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/tools/defaults.mk",
		MkCvsID)
	t.CreateFileLines("mk/bsd.prefs.mk",
		"USE_TOOLS+=     both")
	t.CreateFileLines("mk/bsd.pkg.mk",
		"USE_TOOLS+=     both")

	// The echo tool is mentioned in both files. The file bsd.prefs.mk
	// grants more use cases (load time + run time), therefore it wins.
	t.FinishSetUp()

	t.CheckEquals(G.Pkgsrc.Tools.ByName("both").Validity, AfterPrefsMk)
}

func (s *Suite) Test_Tools__tools_having_the_same_variable_name(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/tools/defaults.mk",
		"_TOOLS_VARNAME.awk=     AWK",
		"_TOOLS_VARNAME.gawk=    AWK",
		"_TOOLS_VARNAME.gsed=    SED",
		"_TOOLS_VARNAME.sed=     SED")
	t.CreateFileLines("mk/bsd.prefs.mk",
		"USE_TOOLS+=     awk sed")

	t.FinishSetUp()

	t.CheckEquals(G.Pkgsrc.Tools.ByName("awk").Validity, AfterPrefsMk)
	t.CheckEquals(G.Pkgsrc.Tools.ByName("sed").Validity, AfterPrefsMk)
	t.CheckEquals(G.Pkgsrc.Tools.ByName("gawk").Validity, Nowhere)
	t.CheckEquals(G.Pkgsrc.Tools.ByName("gsed").Validity, Nowhere)

	t.EnableTracingToLog()
	G.Pkgsrc.Tools.Trace()
	t.DisableTracing()

	t.CheckOutputLines(
		"TRACE: + (*Tools).Trace()",
		"TRACE: 1   tool awk:AWK::AfterPrefsMk",
		"TRACE: 1   tool echo:ECHO:var:AfterPrefsMk",
		"TRACE: 1   tool echo -n:ECHO_N:var:AfterPrefsMk",
		"TRACE: 1   tool false:FALSE:var:AtRunTime",
		"TRACE: 1   tool gawk:AWK::Nowhere",
		"TRACE: 1   tool gsed:SED::Nowhere",
		"TRACE: 1   tool sed:SED::AfterPrefsMk",
		"TRACE: 1   tool test:TEST:var:AfterPrefsMk",
		"TRACE: 1   tool true:TRUE:var:AfterPrefsMk",
		"TRACE: - (*Tools).Trace()")

	tools := NewTools()
	tools.Fallback(G.Pkgsrc.Tools)

	t.EnableTracingToLog()
	tools.Trace()
	t.DisableTracing()

	t.CheckOutputLines(
		"TRACE: + (*Tools).Trace()",
		"TRACE: 1 + (*Tools).Trace()",
		"TRACE: 1 2   tool awk:AWK::AfterPrefsMk",
		"TRACE: 1 2   tool echo:ECHO:var:AfterPrefsMk",
		"TRACE: 1 2   tool echo -n:ECHO_N:var:AfterPrefsMk",
		"TRACE: 1 2   tool false:FALSE:var:AtRunTime",
		"TRACE: 1 2   tool gawk:AWK::Nowhere",
		"TRACE: 1 2   tool gsed:SED::Nowhere",
		"TRACE: 1 2   tool sed:SED::AfterPrefsMk",
		"TRACE: 1 2   tool test:TEST:var:AfterPrefsMk",
		"TRACE: 1 2   tool true:TRUE:var:AfterPrefsMk",
		"TRACE: 1 - (*Tools).Trace()",
		"TRACE: - (*Tools).Trace()")
}

func (s *Suite) Test_Tools__var(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/tools/defaults.mk",
		"TOOLS_CREATE+=          ln",
		"_TOOLS_VARNAME.ln=      LN")
	t.CreateFileLines("mk/bsd.pkg.mk",
		"USE_TOOLS+=             ln")
	t.FinishSetUp()

	mklines := t.NewMkLines("module.mk",
		MkCvsID,
		"",
		"pre-configure:",
		"\t${LN} from to")

	mklines.Check()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Tools__aliases(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("mk/tools/replace.mk",
		MkCvsID,
		"TOOLS_CREATE+=\tsed",
		"TOOLS_PATH.sed=\t/bin/sed",
		"",
		"TOOLS_CREATE+=\tgsed",
		"TOOLS_PATH.gsed=\t/bin/gnu-sed",
		"TOOLS_ALIASES.gsed=\tsed ${tool}")

	infraTools := NewTools()
	mklines.ForEach(func(mkline *MkLine) {
		infraTools.ParseToolLine(mklines, mkline, false, false)
	})

	t.CheckEquals(infraTools.ByName("sed").String(), "sed:::AtRunTime")
	t.CheckEquals(infraTools.ByName("gsed").String(), "gsed:::AtRunTime:sed")

	pkgTools := NewTools()
	pkgTools.Fallback(infraTools)

	t.CheckEquals(pkgTools.ByName("sed").String(), "sed:::AtRunTime")
	t.CheckEquals(pkgTools.ByName("gsed").String(), "gsed:::AtRunTime:sed")

	mkline := t.NewMkLine("Makefile", 123, "USE_TOOLS+=\tgsed")
	pkgTools.ParseToolLine(mklines, mkline, false, false)

	// Since sed is an alias of gsed, it gets the same validity.
	t.CheckEquals(pkgTools.ByName("sed").String(), "sed:::AfterPrefsMk")
	t.CheckEquals(pkgTools.ByName("gsed").String(), "gsed:::AfterPrefsMk:sed")
}

func (s *Suite) Test_Tools__aliases_in_for_loop(c *check.C) {
	t := s.Init(c)

	mklines := t.NewMkLines("mk/tools/replace.mk",
		MkCvsID,
		"_TOOLS_GREP=\tgrep egrep fgrep",
		"TOOLS_CREATE+=\tgrep egrep fgrep ggrep",
		".for t in ${_TOOLS_GREP}",
		"TOOLS_ALIASES.ggrep+=\t${t}",
		".endfor")

	mklines.collectVariables() // calls ParseToolLine internally

	t.CheckDeepEquals(
		mklines.Tools.ByName("ggrep").Aliases,
		[]string{"grep", "egrep", "fgrep"})
}

// The cmake tool is included conditionally. The condition is so simple that
// pkglint could parse it but it depends on the particular package.
// This is something that pkglint cannot do right now, since the global tools
// are loaded once for all packages.
//
// Therefore there is a workaround for USE_CMAKE.
//
// See mk/tools/cmake.mk.
func (s *Suite) Test_Tools__cmake(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"USE_CMAKE=\tyes",
		"",
		"do-test:",
		"\tcd ${WRKSRC} && cmake")
	t.CreateFileLines("mk/tools/defaults.mk",
		".if defined(USE_CMAKE)",
		"USE_TOOLS+=\tcmake cpack",
		".endif")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Tools__gmake(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"USE_TOOLS=\tgmake",
		"",
		"do-test:",
		"\tcd ${WRKSRC} && make tests")
	t.CreateFileLines("mk/tools/bsd.tools.mk",
		".include \"defaults.mk\"",
		".include \"replace.mk\"",
		".include \"make.mk\"")
	t.CreateFileLines("mk/tools/make.mk",
		"TOOLS_CREATE+=\tmake",
		"TOOLS_PATH.make=\t/usr/bin/make")
	t.CreateFileLines("mk/tools/replace.mk",
		"TOOLS_CREATE+=\tgmake",
		"TOOLS_PATH.gmake=\t/usr/bin/gnu-make")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Tools__autoconf213(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"USE_TOOLS=\tautoconf213",
		"",
		"do-test:",
		"\tautoconf")
	t.CreateFileLines("mk/tools/defaults.mk",
		"_TOOLS_DEPMETHOD.autoconf213=\tDEPENDS")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	// No warning, since autoconf213 defines autoconf implicitly.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Tools_Define__invalid_tool_name(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("dummy.mk", 123, "DUMMY=\tvalue")
	reg := NewTools()

	t.Check(reg.Define("tool_name", "", mkline), check.IsNil)
	t.Check(reg.Define("tool:dependency", "", mkline), check.IsNil)
	t.Check(reg.Define("tool:build", "", mkline), check.IsNil)

	// As of October 2018, the underscore is not used in any tool name.
	// If there should ever be such a case, just use a different character for testing.
	t.CheckOutputLines(
		"ERROR: dummy.mk:123: Invalid tool name \"tool_name\".",
		"ERROR: dummy.mk:123: Invalid tool name \"tool:dependency\".",
		"ERROR: dummy.mk:123: Invalid tool name \"tool:build\".")

	t.Check(reg.byName, check.HasLen, 0)
}

func (s *Suite) Test_Tools_Trace__coverage(c *check.C) {
	t := s.Init(c)

	t.DisableTracing()

	reg := NewTools()
	reg.Trace()

	t.CheckOutputEmpty()
}

// USE_TOOLS is an operating-system-dependent variable.
// Many other tool variables have the form VARNAME.${tool},
// which confused an earlier version of pkglint into
// thinking that the below definition was about a tool
// called "NetBSD".
func (s *Suite) Test_Tools_ParseToolLine__opsys(c *check.C) {
	t := s.Init(c)

	t.SetUpTool("tool1", "", Nowhere)
	t.SetUpVartypes()
	t.CreateFileLines("Makefile",
		MkCvsID,
		"",
		"USE_TOOLS.NetBSD+=\ttool1")

	CheckdirToplevel(t.File("."))

	// No error about "Unknown tool \"NetBSD\"."
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Tools_ParseToolLine__invalid_tool_name(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("Makefile",
		MkCvsID,
		"",
		".for t in abc ${UNDEFINED}",
		"TOOLS_CREATE+=\t\t${t}",
		"_TOOLS_VARNAME.${t}=\tVARNAME",
		"TOOLS_PATH.${t}=\t/bin/${t}",
		"TOOLS_ALIASES.${t}=\t${t} ${u} ${t}-arm64",
		"TOOLS_ALIASES.tool=\t${t} ${u} ${t}-arm64",
		"_TOOLS.${t}=\t${t}",
		".endfor")

	mklines.collectVariables()
	t.Check(mklines.Tools.byName, check.HasLen, 1)
	t.CheckEquals(mklines.Tools.ByName("tool").String(), "tool:::Nowhere:abc")

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Tools_ParseToolLine__private_tool_undefined(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"",
		"\tmd5sum filename")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: filename.mk:3: Unknown shell command \"md5sum\".")
}

// Tools that are defined by a package by adding to TOOLS_CREATE can
// be used without adding them to USE_TOOLS again.
func (s *Suite) Test_Tools_ParseToolLine__private_tool_defined(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"TOOLS_CREATE+=\tmd5sum",
		"",
		"\tmd5sum filename")

	mklines.Check()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Tools_parseUseTools(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc()
	t.CreateFileLines("mk/triple-tool.mk",
		MkCvsID,
		"",
		"USE_TOOLS+=\tunknown unknown unknown")
	t.FinishSetUp()

	t.Check(G.Pkgsrc.Tools.ByName("unknown"), check.IsNil)

	t.CheckOutputEmpty()
}

// Demonstrates how the Tools type handles tools that share the same
// variable name. Of these tools, the GNU variant is preferred.
//
// In this realistic variant, the non-GNU tool is defined in bsd.prefs.mk
// and the GNU tool is only defined but not made available.
//
// See also Pkglint.Tool.
func (s *Suite) Test_Tools_Fallback__tools_having_the_same_variable_name_realistic(c *check.C) {
	t := s.Init(c)

	nonGnu := NewTools()
	nonGnu.def("sed", "SED", false, AfterPrefsMk, nil)

	gnu := NewTools()
	gnu.def("gsed", "SED", false, Nowhere, nil)

	local1 := NewTools()
	local1.def("sed", "SED", false, AfterPrefsMk, nil)
	local1.Fallback(gnu)

	t.CheckEquals(local1.ByName("sed").Validity, AfterPrefsMk)
	t.CheckEquals(local1.ByName("gsed").Validity, Nowhere)

	local2 := NewTools()
	local2.def("gsed", "SED", false, Nowhere, nil)
	local2.Fallback(nonGnu)

	t.CheckEquals(local2.ByName("sed").Validity, AfterPrefsMk)
	t.CheckEquals(local2.ByName("gsed").Validity, Nowhere)

	// No matter in which order the tool definitions are encountered,
	// the non-GNU version is always chosen since the GNU version is
	// not available at all.
	t.CheckEquals(local1.ByVarname("SED").String(), "sed:SED::AfterPrefsMk")
	t.CheckEquals(local2.ByVarname("SED").String(), "sed:SED::AfterPrefsMk")
}

// Demonstrates how the Tools type handles tools that share the same
// variable name. Of these tools, the GNU variant is preferred.
//
// In this unrealistic variant, the GNU tool is defined in bsd.prefs.mk
// and the non-GNU tool is only defined but not made available.
//
// See also Pkglint.Tool.
func (s *Suite) Test_Tools_Fallback__tools_having_the_same_variable_name_unrealistic(c *check.C) {
	t := s.Init(c)

	// This simulates a tool defined in the tools framework but not added
	// to USE_TOOLS, neither by bsd.prefs.mk nor by bsd.pkg.mk.
	nonGnu := NewTools()
	nonGnu.def("sed", "SED", false, Nowhere, nil)

	// This simulates a tool that is added to USE_TOOLS in bsd.prefs.mk.
	gnu := NewTools()
	gnu.def("gsed", "SED", false, AfterPrefsMk, nil)
	gnu.ByName("gsed").Aliases = []string{"sed"}

	// This simulates a package that doesn't mention the sed tool at all.
	// The call to .def() is therefore unrealistic.
	// Nevertheless, since the GNU tools define the gsed tool as well,
	// it is available even though not explicitly mentioned in the package.
	local1 := NewTools()
	local1.def("sed", "SED", false, Nowhere, nil)
	local1.Fallback(gnu)

	t.CheckEquals(local1.ByName("sed").Validity, Nowhere)
	t.CheckEquals(local1.ByName("gsed").Validity, AfterPrefsMk)

	local2 := NewTools()
	local2.def("gsed", "SED", false, AfterPrefsMk, []string{"sed"})
	local2.Fallback(nonGnu)

	t.CheckEquals(local2.ByName("sed").Validity, AfterPrefsMk)
	t.CheckEquals(local2.ByName("gsed").Validity, AfterPrefsMk)

	t.CheckEquals(local1.ByVarname("SED").String(), "sed:SED::AfterPrefsMk")
	t.CheckEquals(local2.ByVarname("SED").String(), "sed:SED::AfterPrefsMk")
}

func (s *Suite) Test_Tools_Fallback__called_twice(c *check.C) {
	t := s.Init(c)

	tools := NewTools()
	fallback := NewTools()

	tools.Fallback(fallback)

	t.ExpectAssert(func() { tools.Fallback(fallback) })
}

func (s *Suite) Test_Tools_IsValidToolName(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpTool("[", "", AtRunTime)
	t.SetUpTool("echo -n", "ECHO_N", AtRunTime)
	mklines := t.NewMkLines("filename.mk",
		MkCvsID,
		"",
		"USE_TOOLS+=\t[")

	mklines.Check()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_ToolTime_String(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(LoadTime.String(), "LoadTime")
	t.CheckEquals(RunTime.String(), "RunTime")
}
