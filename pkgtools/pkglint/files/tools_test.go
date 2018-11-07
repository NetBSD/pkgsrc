package main

import "gopkg.in/check.v1"

func (s *Suite) Test_Tool_UsableAtLoadTime(c *check.C) {

	nowhere := Tool{"nowhere", "", false, Nowhere}
	c.Check(nowhere.UsableAtLoadTime(false), equals, false)
	c.Check(nowhere.UsableAtLoadTime(true), equals, false)

	load := Tool{"load", "", false, AfterPrefsMk}
	c.Check(load.UsableAtLoadTime(false), equals, false)
	c.Check(load.UsableAtLoadTime(true), equals, true)

	run := Tool{"run", "", false, AtRunTime}
	c.Check(run.UsableAtLoadTime(false), equals, false)
	c.Check(run.UsableAtLoadTime(true), equals, false)
}

func (s *Suite) Test_Tool_UsableAtRunTime(c *check.C) {

	nowhere := Tool{"nowhere", "", false, Nowhere}
	c.Check(nowhere.UsableAtRunTime(), equals, false)

	load := Tool{"load", "", false, AfterPrefsMk}
	c.Check(load.UsableAtRunTime(), equals, true)

	run := Tool{"run", "", false, AtRunTime}
	c.Check(run.UsableAtRunTime(), equals, true)
}

// USE_TOOLS is an operating-system-dependent variable.
// Many other tool variables have the form VARNAME.${tool},
// which confused an earlier version of pkglint into
// thinking that the below definition was about a tool
// called "NetBSD".
func (s *Suite) Test_Tools_ParseToolLine(c *check.C) {
	t := s.Init(c)

	t.SetupTool("tool1", "", Nowhere)
	t.SetupVartypes()
	t.CreateFileLines("Makefile",
		MkRcsID,
		"",
		"USE_TOOLS.NetBSD+=\ttool1")

	CheckdirToplevel(t.File("."))

	// No error about "Unknown tool \"NetBSD\"."
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Tools_Define__invalid_tool_name(c *check.C) {
	t := s.Init(c)

	reg := NewTools("")

	reg.Define("tool_name", "", dummyMkLine)
	reg.Define("tool:dependency", "", dummyMkLine)
	reg.Define("tool:build", "", dummyMkLine)

	// As of October 2018, the underscore is not used in any tool name.
	// If there should ever be such a case, just use a different character for testing.
	t.CheckOutputLines(
		"ERROR: Invalid tool name \"tool_name\".",
		"ERROR: Invalid tool name \"tool:dependency\".",
		"ERROR: Invalid tool name \"tool:build\".")
}

func (s *Suite) Test_Tools_Trace__coverage(c *check.C) {
	t := s.Init(c)

	t.DisableTracing()

	reg := NewTools("")
	reg.Trace()

	t.CheckOutputEmpty()
}

func (s *Suite) Test_Tools__USE_TOOLS_predefined_sed(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()
	t.CreateFileLines("mk/bsd.prefs.mk",
		"USE_TOOLS+=\tsed:pkgsrc")
	t.CreateFileLines("mk/tools/defaults.mk",
		"_TOOLS_VARNAME.sed=\tSED")
	t.CreateFileLines("module.mk",
		MkRcsID,
		"",
		"do-build:",
		"\t${SED} < input > output",
		"\t${AWK} < input > output")

	G.Main("pkglint", "-Wall", t.File("module.mk"))

	// Since this test doesn't load the usual tool definitions via
	// G.Pkgsrc.loadTools, AWK is not known at all.
	t.CheckOutputLines(
		"WARN: ~/module.mk:5: Unknown shell command \"${AWK}\".",
		"WARN: ~/module.mk:5: AWK is used but not defined.",
		"0 errors and 2 warnings found.",
		"(Run \"pkglint -e\" to show explanations.)")
}

// It may happen that a tool is first defined without knowing its
// variable name. When trying to define the tool with its variable name
// later, the existing definition is amended.
func (s *Suite) Test_Tools__add_varname_later(c *check.C) {

	tools := NewTools("")
	tool := tools.Define("tool", "", dummyMkLine)

	c.Check(tool.Name, equals, "tool")
	c.Check(tool.Varname, equals, "")

	// Updates the existing tool definition.
	tools.Define("tool", "TOOL", dummyMkLine)

	c.Check(tool.Name, equals, "tool")
	c.Check(tool.Varname, equals, "TOOL")
}

func (s *Suite) Test_Tools__load_from_infrastructure(c *check.C) {
	t := s.Init(c)

	tools := NewTools("")

	tools.ParseToolLine(t.NewMkLine("create.mk", 2, "TOOLS_CREATE+= load"), true, false)
	tools.ParseToolLine(t.NewMkLine("create.mk", 3, "TOOLS_CREATE+= run"), true, false)
	tools.ParseToolLine(t.NewMkLine("create.mk", 4, "TOOLS_CREATE+= nowhere"), true, false)

	// The references to the tools are stable,
	// the lookup methods always return the same objects.
	load := tools.ByName("load")
	run := tools.ByName("run")
	nowhere := tools.ByName("nowhere")

	// All tools are defined by name, but their variable names are not yet known.
	// At this point they may not be used, neither by the pkgsrc infrastructure nor by a package.
	c.Check(load.String(), equals, "load:::Nowhere")
	c.Check(run.String(), equals, "run:::Nowhere")
	c.Check(nowhere.String(), equals, "nowhere:::Nowhere")

	// The name RUN_CMD avoids conflicts with RUN.
	tools.ParseToolLine(t.NewMkLine("varnames.mk", 2, "_TOOLS_VARNAME.load=    LOAD"), true, false)
	tools.ParseToolLine(t.NewMkLine("varnames.mk", 3, "_TOOLS_VARNAME.run=     RUN_CMD"), true, false)
	tools.ParseToolLine(t.NewMkLine("varnames.mk", 4, "_TOOLS_VARNAME.nowhere= NOWHERE"), true, false)

	// At this point the tools can be found by their variable names, too.
	// They still may not be used.
	c.Check(load.String(), equals, "load:LOAD::Nowhere")
	c.Check(run.String(), equals, "run:RUN_CMD::Nowhere")
	c.Check(nowhere.String(), equals, "nowhere:NOWHERE::Nowhere")
	c.Check(tools.ByVarname("LOAD"), equals, load)
	c.Check(tools.ByVarname("RUN_CMD"), equals, run)
	c.Check(tools.ByVarname("NOWHERE"), equals, nowhere)
	c.Check(load.String(), equals, "load:LOAD::Nowhere")
	c.Check(run.String(), equals, "run:RUN_CMD::Nowhere")
	c.Check(nowhere.String(), equals, "nowhere:NOWHERE::Nowhere")

	tools.ParseToolLine(t.NewMkLine("bsd.prefs.mk", 2, "USE_TOOLS+= load"), true, true)

	// Tools that are added to USE_TOOLS in bsd.prefs.mk may be used afterwards.
	// By variable name, they may be used both at load time as well as run time.
	// By plain name, they may be used only in {pre,do,post}-* targets.
	c.Check(load.String(), equals, "load:LOAD::AfterPrefsMk")

	tools.ParseToolLine(t.NewMkLine("bsd.pkg.mk", 2, "USE_TOOLS+= run"), true, true)

	// Tools that are added to USE_TOOLS in bsd.pkg.mk may be used afterwards at run time.
	// The {pre,do,post}-* targets may use both forms (${CAT} and cat).
	// All other targets must use the variable form (${CAT}).
	c.Check(run.String(), equals, "run:RUN_CMD::AtRunTime")

	// That's all for parsing tool definitions from the pkgsrc infrastructure.
	// See Test_Tools__package_Makefile for a continuation.
}

func (s *Suite) Test_Tools__package_Makefile(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()
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
	G.Pkgsrc.LoadInfrastructure()

	tools := NewTools("")
	tools.Fallback(G.Pkgsrc.Tools)

	load := tools.ByName("load")
	run := tools.ByName("run")
	nowhere := tools.ByName("nowhere")
	before := tools.ByName("pkg-before-prefs")
	after := tools.ByName("pkg-after-prefs")

	c.Check(load.UsableAtRunTime(), equals, true)
	c.Check(run.UsableAtRunTime(), equals, true)
	c.Check(nowhere.UsableAtRunTime(), equals, false)

	// The seenPrefs variable is only relevant for the package Makefile.
	// All other files must not use the tools at load time.
	// For them, seenPrefs can be thought of as being true from the beginning.

	tools.ParseToolLine(t.NewMkLine("Makefile", 2, "USE_TOOLS+=     pkg-before-prefs"), false, true)

	c.Check(before.Validity, equals, AfterPrefsMk)
	c.Check(tools.SeenPrefs, equals, false)

	tools.ParseToolLine(t.NewMkLine("Makefile", 3, ".include \"../../mk/bsd.prefs.mk\""), false, true)

	c.Check(tools.SeenPrefs, equals, true)

	tools.ParseToolLine(t.NewMkLine("Makefile", 4, "USE_TOOLS+=     pkg-after-prefs"), false, true)

	c.Check(after.Validity, equals, AtRunTime)
}

func (s *Suite) Test_Tools__builtin_mk(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()
	t.SetupCommandLine("-Wall,no-space")
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
	G.Pkgsrc.LoadInfrastructure()

	// Tools that are defined by pkgsrc as load-time tools
	// may be used in any file at load time.

	mklines := t.SetupFileMkLines("builtin.mk",
		MkRcsID,
		"",
		"VAR!=   ${ECHO} 'too early'",
		"VAR!=   ${LOAD} 'too early'",
		"VAR!=   ${RUN_CMD} 'never allowed'",
		"VAR!=   ${NOWHERE} 'never allowed'",
		"",
		".include \"../../mk/buildlink3/bsd.builtin.mk\"",
		"",
		"VAR!=   ${ECHO} 'valid'",
		"VAR!=   ${LOAD} 'valid'",
		"VAR!=   ${RUN_CMD} 'never allowed'",
		"VAR!=   ${NOWHERE} 'never allowed'",
		"",
		"VAR!=   ${VAR}")

	mklines.Check()

	t.CheckOutputLines(
		"WARN: ~/builtin.mk:3: To use the tool ${ECHO} at load time, bsd.prefs.mk has to be included before.",
		"WARN: ~/builtin.mk:4: To use the tool ${LOAD} at load time, bsd.prefs.mk has to be included before.",
		"WARN: ~/builtin.mk:5: The tool ${RUN_CMD} cannot be used at load time.",
		"WARN: ~/builtin.mk:6: The tool ${NOWHERE} cannot be used at load time.",
		"WARN: ~/builtin.mk:12: The tool ${RUN_CMD} cannot be used at load time.",
		"WARN: ~/builtin.mk:13: The tool ${NOWHERE} cannot be used at load time.")
}

func (s *Suite) Test_Tools__implicit_definition_in_bsd_pkg_mk(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()
	t.SetupCommandLine("-Wall,no-space")
	t.CreateFileLines("mk/tools/defaults.mk",
		MkRcsID) // None
	t.CreateFileLines("mk/bsd.prefs.mk",
		"USE_TOOLS+=     load")
	t.CreateFileLines("mk/bsd.pkg.mk",
		"USE_TOOLS+=     run")

	// It's practically impossible that a tool is added to USE_TOOLS in
	// bsd.pkg.mk and not defined earlier in mk/tools/defaults.mk, but
	// the pkglint code is even prepared for these rare cases.
	// In other words, this test is only there for the code coverage.
	G.Pkgsrc.LoadInfrastructure()

	c.Check(G.Pkgsrc.Tools.ByName("run").String(), equals, "run:::AtRunTime")
}

func (s *Suite) Test_Tools__both_prefs_and_pkg_mk(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()
	t.SetupCommandLine("-Wall,no-space")
	t.CreateFileLines("mk/tools/defaults.mk",
		MkRcsID)
	t.CreateFileLines("mk/bsd.prefs.mk",
		"USE_TOOLS+=     both")
	t.CreateFileLines("mk/bsd.pkg.mk",
		"USE_TOOLS+=     both")

	// The echo tool is mentioned in both files. The file bsd.prefs.mk
	// grants more use cases (load time + run time), therefore it wins.
	G.Pkgsrc.LoadInfrastructure()

	c.Check(G.Pkgsrc.Tools.ByName("both").Validity, equals, AfterPrefsMk)
}

func (s *Suite) Test_Tools__tools_having_the_same_variable_name(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()
	t.SetupCommandLine("-Wall,no-space")
	t.CreateFileLines("mk/tools/defaults.mk",
		"_TOOLS_VARNAME.awk=     AWK",
		"_TOOLS_VARNAME.gawk=    AWK",
		"_TOOLS_VARNAME.gsed=    SED",
		"_TOOLS_VARNAME.sed=     SED")
	t.CreateFileLines("mk/bsd.prefs.mk",
		"USE_TOOLS+=     awk sed")

	G.Pkgsrc.LoadInfrastructure()

	c.Check(G.Pkgsrc.Tools.ByName("awk").Validity, equals, AfterPrefsMk)
	c.Check(G.Pkgsrc.Tools.ByName("sed").Validity, equals, AfterPrefsMk)
	c.Check(G.Pkgsrc.Tools.ByName("gawk").Validity, equals, Nowhere)
	c.Check(G.Pkgsrc.Tools.ByName("gsed").Validity, equals, Nowhere)

	t.EnableTracingToLog()
	G.Pkgsrc.Tools.Trace()
	t.DisableTracing()

	t.CheckOutputLines(
		"TRACE: + (*Tools).Trace(\"Pkgsrc\")",
		"TRACE: 1   tool awk:AWK::AfterPrefsMk",
		"TRACE: 1   tool echo:ECHO:var:AfterPrefsMk",
		"TRACE: 1   tool echo -n:ECHO_N:var:AfterPrefsMk",
		"TRACE: 1   tool false:FALSE:var:AtRunTime",
		"TRACE: 1   tool gawk:AWK::Nowhere",
		"TRACE: 1   tool gsed:SED::Nowhere",
		"TRACE: 1   tool sed:SED::AfterPrefsMk",
		"TRACE: 1   tool test:TEST:var:AfterPrefsMk",
		"TRACE: 1   tool true:TRUE:var:AfterPrefsMk",
		"TRACE: - (*Tools).Trace(\"Pkgsrc\")")

	tools := NewTools("module.mk")
	tools.Fallback(G.Pkgsrc.Tools)

	t.EnableTracingToLog()
	tools.Trace()
	t.DisableTracing()

	t.CheckOutputLines(
		"TRACE: + (*Tools).Trace(\"module.mk\")",
		"TRACE: 1 + (*Tools).Trace(\"Pkgsrc\")",
		"TRACE: 1 2   tool awk:AWK::AfterPrefsMk",
		"TRACE: 1 2   tool echo:ECHO:var:AfterPrefsMk",
		"TRACE: 1 2   tool echo -n:ECHO_N:var:AfterPrefsMk",
		"TRACE: 1 2   tool false:FALSE:var:AtRunTime",
		"TRACE: 1 2   tool gawk:AWK::Nowhere",
		"TRACE: 1 2   tool gsed:SED::Nowhere",
		"TRACE: 1 2   tool sed:SED::AfterPrefsMk",
		"TRACE: 1 2   tool test:TEST:var:AfterPrefsMk",
		"TRACE: 1 2   tool true:TRUE:var:AfterPrefsMk",
		"TRACE: 1 - (*Tools).Trace(\"Pkgsrc\")",
		"TRACE: - (*Tools).Trace(\"module.mk\")")
}

func (s *Suite) Test_ToolTime_String(c *check.C) {
	c.Check(LoadTime.String(), equals, "LoadTime")
	c.Check(RunTime.String(), equals, "RunTime")
}

func (s *Suite) Test_Tools__var(c *check.C) {
	t := s.Init(c)

	t.SetupPkgsrc()
	t.CreateFileLines("mk/tools/defaults.mk",
		"TOOLS_CREATE+=          ln",
		"_TOOLS_VARNAME.ln=      LN")
	t.CreateFileLines("mk/bsd.pkg.mk",
		"USE_TOOLS+=             ln")
	G.Pkgsrc.LoadInfrastructure()

	mklines := t.NewMkLines("module.mk",
		MkRcsID,
		"",
		"pre-configure:",
		"\t${LN} from to")

	mklines.Check()

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
	nonGnu := NewTools("non-gnu")
	nonGnu.def("sed", "SED", false, AfterPrefsMk)

	gnu := NewTools("gnu")
	gnu.def("gsed", "SED", false, Nowhere)

	local1 := NewTools("local")
	local1.def("sed", "SED", false, AfterPrefsMk)
	local1.Fallback(gnu)

	c.Check(local1.ByName("sed").Validity, equals, AfterPrefsMk)
	c.Check(local1.ByName("gsed").Validity, equals, Nowhere)

	local2 := NewTools("local")
	local2.def("gsed", "SED", false, Nowhere)
	local2.Fallback(nonGnu)

	c.Check(local2.ByName("sed").Validity, equals, AfterPrefsMk)
	c.Check(local2.ByName("gsed").Validity, equals, Nowhere)

	// No matter in which order the tool definitions are encountered,
	// the non-GNU version is always chosen since the GNU version is
	// not available at all.
	c.Check(local1.ByVarname("SED").String(), equals, "sed:SED::AfterPrefsMk")
	c.Check(local2.ByVarname("SED").String(), equals, "sed:SED::AfterPrefsMk")
}

// Demonstrates how the Tools type handles tools that share the same
// variable name. Of these tools, the GNU variant is preferred.
//
// In this unrealistic variant, the GNU tool is defined in bsd.prefs.mk
// and the non-GNU tool is only defined but not made available.
//
// See also Pkglint.Tool.
func (s *Suite) Test_Tools_Fallback__tools_having_the_same_variable_name_unrealistic(c *check.C) {
	nonGnu := NewTools("non-gnu")
	nonGnu.def("sed", "SED", false, Nowhere)

	gnu := NewTools("gnu")
	gnu.def("gsed", "SED", false, AfterPrefsMk)

	local1 := NewTools("local")
	local1.def("sed", "SED", false, Nowhere)
	local1.Fallback(gnu)

	c.Check(local1.ByName("sed").Validity, equals, Nowhere)
	c.Check(local1.ByName("gsed").Validity, equals, AfterPrefsMk)

	local2 := NewTools("local")
	local2.def("gsed", "SED", false, AfterPrefsMk)
	local2.Fallback(nonGnu)

	c.Check(local2.ByName("sed").Validity, equals, Nowhere)
	c.Check(local2.ByName("gsed").Validity, equals, AfterPrefsMk)

	// FIXME: Must both be gsed:SED::AfterPrefsMk
	c.Check(local1.ByVarname("SED").String(), equals, "sed:SED::Nowhere")
	c.Check(local2.ByVarname("SED").String(), equals, "sed:SED::Nowhere")
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

	t.SetupPackage("category/package",
		"USE_CMAKE=\tyes",
		"",
		"do-test:",
		"\tcd ${WRKSRC} && cmake")
	t.CreateFileLines("mk/tools/defaults.mk",
		".if defined(USE_CMAKE)",
		"USE_TOOLS+=\tcmake cpack",
		".endif")
	G.Pkgsrc.LoadInfrastructure()

	G.CheckDirent(t.File("category/package"))

	t.CheckOutputEmpty()
}
