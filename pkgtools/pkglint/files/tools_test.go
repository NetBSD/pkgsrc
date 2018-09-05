package main

import "gopkg.in/check.v1"

func (s *Suite) Test_Tools_ParseToolLine(c *check.C) {
	t := s.Init(c)

	t.SetupToolUsable("tool1", "")
	t.SetupVartypes()
	t.SetupFileLines("Makefile",
		MkRcsID,
		"",
		"USE_TOOLS.NetBSD+=\ttool1")

	CheckdirToplevel(t.File("."))

	// No error about "Unknown tool \"NetBSD\"."
	t.CheckOutputEmpty()
}

func (s *Suite) Test_Tools_validateToolName__invalid(c *check.C) {
	t := s.Init(c)

	reg := NewTools("")

	reg.Define("tool_name", "", dummyMkLine)
	reg.Define("tool:dependency", "", dummyMkLine)
	reg.Define("tool:build", "", dummyMkLine)

	// Currently, the underscore is not used in any tool name.
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
	t.SetupFileMkLines("module.mk",
		MkRcsID,
		"",
		"do-build:",
		"\t${SED} < input > output",
		"\t${AWK} < input > output")

	G.Main("pkglint", "-Wall", t.File("module.mk"))

	t.CheckOutputLines(
		"WARN: ~/module.mk:5: Unknown shell command \"${AWK}\".",
		"0 errors and 1 warning found.",
		"(Run \"pkglint -e\" to show explanations.)")
}

func (s *Suite) Test_Tools__add_varname_later(c *check.C) {

	tools := NewTools("")
	tool := tools.Define("tool", "", dummyMkLine)

	c.Check(tool.Name, equals, "tool")
	c.Check(tool.Varname, equals, "")

	// Should update the existing tool definition.
	tools.Define("tool", "TOOL", dummyMkLine)

	c.Check(tool.Name, equals, "tool")
	c.Check(tool.Varname, equals, "TOOL")
}

func (s *Suite) Test_Tools__load_from_infrastructure(c *check.C) {
	t := s.Init(c)

	tools := NewTools("")

	tools.ParseToolLine(t.NewMkLine("create.mk", 2, "TOOLS_CREATE+= load"))
	tools.ParseToolLine(t.NewMkLine("create.mk", 3, "TOOLS_CREATE+= run"))
	tools.ParseToolLine(t.NewMkLine("create.mk", 4, "TOOLS_CREATE+= nowhere"))

	// The references to the tools are stable,
	// the lookup methods always return the same objects.
	load := tools.ByName("load")
	run := tools.ByName("run")
	nowhere := tools.ByName("nowhere")

	// All tools are defined by name, but their variable names are not yet known.
	// At this point they may not be used, neither by the pkgsrc infrastructure nor by a package.
	c.Check(load, deepEquals, &Tool{"load", "", false, Nowhere})
	c.Check(run, deepEquals, &Tool{"run", "", false, Nowhere})
	c.Check(nowhere, deepEquals, &Tool{"nowhere", "", false, Nowhere})

	// The name RUN_CMD avoids conflicts with RUN.
	tools.ParseToolLine(t.NewMkLine("varnames.mk", 2, "_TOOLS_VARNAME.load=    LOAD"))
	tools.ParseToolLine(t.NewMkLine("varnames.mk", 3, "_TOOLS_VARNAME.run=     RUN_CMD"))
	tools.ParseToolLine(t.NewMkLine("varnames.mk", 4, "_TOOLS_VARNAME.nowhere= NOWHERE"))

	// At this point the tools can be found by their variable names, too.
	// They still may not be used.
	c.Check(load, deepEquals, &Tool{"load", "LOAD", false, Nowhere})
	c.Check(run, deepEquals, &Tool{"run", "RUN_CMD", false, Nowhere})
	c.Check(nowhere, deepEquals, &Tool{"nowhere", "NOWHERE", false, Nowhere})
	c.Check(tools.ByVarname("LOAD"), equals, load)
	c.Check(tools.ByVarname("RUN_CMD"), equals, run)
	c.Check(tools.ByVarname("NOWHERE"), equals, nowhere)
	c.Check(load.UsableAtLoadTime(false), equals, false)
	c.Check(load.UsableAtLoadTime(true), equals, false)
	c.Check(load.UsableAtRunTime(), equals, false)
	c.Check(run.UsableAtLoadTime(false), equals, false)
	c.Check(run.UsableAtLoadTime(true), equals, false)
	c.Check(run.UsableAtRunTime(), equals, false)
	c.Check(nowhere.UsableAtLoadTime(false), equals, false)
	c.Check(nowhere.UsableAtLoadTime(true), equals, false)
	c.Check(nowhere.UsableAtRunTime(), equals, false)

	tools.ParseToolLine(t.NewMkLine("bsd.prefs.mk", 2, "USE_TOOLS+= load"))

	// Tools that are added to USE_TOOLS in bsd.prefs.mk may be used afterwards.
	// By variable name, they may be used both at load time as well as run time.
	// By plain name, they may be used only in {pre,do,post}-* targets.
	c.Check(load, deepEquals, &Tool{"load", "LOAD", false, AfterPrefsMk})
	c.Check(load.UsableAtLoadTime(false), equals, false)
	c.Check(load.UsableAtLoadTime(true), equals, true)
	c.Check(load.UsableAtRunTime(), equals, true)

	tools.ParseToolLine(t.NewMkLine("bsd.pkg.mk", 2, "USE_TOOLS+= run"))

	// Tools that are added to USE_TOOLS in bsd.pkg.mk may be used afterwards at run time.
	// The {pre,do,post}-* targets may use both forms (${CAT} and cat).
	// All other targets must use the variable form (${CAT}).
	c.Check(run, deepEquals, &Tool{"run", "RUN_CMD", false, AtRunTime})
	c.Check(run.UsableAtLoadTime(false), equals, false)
	c.Check(run.UsableAtLoadTime(false), equals, false)
	c.Check(run.UsableAtRunTime(), equals, true)

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
	tools.AddAll(G.Pkgsrc.Tools)

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
	// For them, seenPrefs can be though of as being true from the beginning.

	tools.ParseToolLine(t.NewMkLine("Makefile", 2, "USE_TOOLS+=     pkg-before-prefs"))

	c.Check(before.Validity, equals, AfterPrefsMk)
	c.Check(before.UsableAtLoadTime(false), equals, false)
	c.Check(before.UsableAtLoadTime(true), equals, true)
	c.Check(before.UsableAtRunTime(), equals, true)

	c.Check(tools.SeenPrefs, equals, false)

	tools.ParseToolLine(t.NewMkLine("Makefile", 3, ".include \"../../mk/bsd.prefs.mk\""))

	c.Check(tools.SeenPrefs, equals, true)

	tools.ParseToolLine(t.NewMkLine("Makefile", 4, "USE_TOOLS+=     pkg-after-prefs"))

	c.Check(after.Validity, equals, AtRunTime)
	c.Check(after.UsableAtLoadTime(false), equals, false)
	c.Check(after.UsableAtLoadTime(true), equals, false)
	c.Check(after.UsableAtRunTime(), equals, true)
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

	mklines := t.NewMkLines("builtin.mk",
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
		"WARN: builtin.mk:3: To use the tool ${ECHO} at load time, bsd.prefs.mk has to be included before.",
		"WARN: builtin.mk:4: To use the tool ${LOAD} at load time, bsd.prefs.mk has to be included before.",
		"WARN: builtin.mk:5: The tool ${RUN_CMD} cannot be used at load time.",
		"WARN: builtin.mk:6: The tool ${NOWHERE} cannot be used at load time.",
		"WARN: builtin.mk:12: The tool ${RUN_CMD} cannot be used at load time.",
		"WARN: builtin.mk:13: The tool ${NOWHERE} cannot be used at load time.")
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

	c.Check(G.Pkgsrc.Tools.ByName("run"), deepEquals, &Tool{"run", "", false, AtRunTime})
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
		"TRACE: 1   tool &{Name:awk Varname:AWK MustUseVarForm:false Validity:AfterPrefsMk}",
		"TRACE: 1   tool &{Name:echo Varname:ECHO MustUseVarForm:true Validity:AfterPrefsMk}",
		"TRACE: 1   tool &{Name:echo -n Varname:ECHO_N MustUseVarForm:true Validity:AfterPrefsMk}",
		"TRACE: 1   tool &{Name:false Varname:FALSE MustUseVarForm:true Validity:Nowhere}",
		"TRACE: 1   tool &{Name:gawk Varname:AWK MustUseVarForm:false Validity:Nowhere}",
		"TRACE: 1   tool &{Name:gsed Varname:SED MustUseVarForm:false Validity:Nowhere}",
		"TRACE: 1   tool &{Name:sed Varname:SED MustUseVarForm:false Validity:AfterPrefsMk}",
		"TRACE: 1   tool &{Name:test Varname:TEST MustUseVarForm:true Validity:AfterPrefsMk}",
		"TRACE: 1   tool &{Name:true Varname:TRUE MustUseVarForm:true Validity:AfterPrefsMk}",
		"TRACE: - (*Tools).Trace(\"Pkgsrc\")")

	tools := NewTools("module.mk")
	tools.AddAll(G.Pkgsrc.Tools)

	t.EnableTracingToLog()
	tools.Trace()
	t.DisableTracing()

	t.CheckOutputLines(
		"TRACE: + (*Tools).Trace(\"module.mk\")",
		"TRACE: 1   tool &{Name:awk Varname:AWK MustUseVarForm:false Validity:AfterPrefsMk}",
		"TRACE: 1   tool &{Name:echo Varname:ECHO MustUseVarForm:true Validity:AfterPrefsMk}",
		"TRACE: 1   tool &{Name:echo -n Varname:ECHO_N MustUseVarForm:true Validity:AfterPrefsMk}",
		"TRACE: 1   tool &{Name:false Varname:FALSE MustUseVarForm:true Validity:Nowhere}",
		"TRACE: 1   tool &{Name:gawk Varname:AWK MustUseVarForm:false Validity:Nowhere}",
		"TRACE: 1   tool &{Name:gsed Varname:SED MustUseVarForm:false Validity:Nowhere}",
		"TRACE: 1   tool &{Name:sed Varname:SED MustUseVarForm:false Validity:AfterPrefsMk}",
		"TRACE: 1   tool &{Name:test Varname:TEST MustUseVarForm:true Validity:AfterPrefsMk}",
		"TRACE: 1   tool &{Name:true Varname:TRUE MustUseVarForm:true Validity:AfterPrefsMk}",
		"TRACE: - (*Tools).Trace(\"module.mk\")")
}

func (s *Suite) Test_ToolTime_String(c *check.C) {
	c.Check(LoadTime.String(), equals, "LoadTime")
	c.Check(RunTime.String(), equals, "RunTime")
}

func (s *Suite) Test_Tools__var(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall")
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

// Demonstrates how the Tools type handles tool that share the same
// variable name. Of these tools, the GNU variant is preferred.
//
// See also Pkglint.Tool.
func (s *Suite) Test_Tools_AddAll__tools_having_the_same_variable_name(c *check.C) {
	nonGnu := NewTools("non-gnu")
	nonGnu.Define("sed", "SED", dummyMkLine).SetValidity(AfterPrefsMk, "")

	gnu := NewTools("gnu")
	gnu.Define("gsed", "SED", dummyMkLine)

	local1 := NewTools("local")
	local1.AddAll(nonGnu)
	local1.AddAll(gnu)

	c.Check(local1.ByName("sed").Validity, equals, AfterPrefsMk)
	c.Check(local1.ByName("gsed").Validity, equals, Nowhere)
	local1.Trace()

	local2 := NewTools("local")
	local2.AddAll(gnu)
	local2.AddAll(nonGnu)

	c.Check(local2.ByName("sed").Validity, equals, AfterPrefsMk)
	c.Check(local2.ByName("gsed").Validity, equals, Nowhere)
	local2.Trace()

	nonGnu.ByName("sed").Validity = Nowhere
	gnu.ByName("gsed").Validity = AfterPrefsMk

	local3 := NewTools("local")
	local3.AddAll(nonGnu)
	local3.AddAll(gnu)

	c.Check(local3.ByName("sed").Validity, equals, Nowhere)
	c.Check(local3.ByName("gsed").Validity, equals, AfterPrefsMk)
	local3.Trace()

	local4 := NewTools("local")
	local4.AddAll(gnu)
	local4.AddAll(nonGnu)

	c.Check(local4.ByName("sed").Validity, equals, Nowhere)
	c.Check(local4.ByName("gsed").Validity, equals, AfterPrefsMk)
	local4.Trace()

	c.Check(local1, deepEquals, local2)
	c.Check(local4, deepEquals, local4)
}
