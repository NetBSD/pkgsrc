package main

import (
	"fmt"
	"io"
	"os"
	"path/filepath"
	"runtime/pprof"
)

const confMake = "@BMAKE@"
const confVersion = "@VERSION@"

func main() {
	G.logOut, G.logErr, G.debugOut = os.Stdout, os.Stderr, os.Stdout
	os.Exit(new(Pkglint).Main(os.Args...))
}

type Pkglint struct{}

func (pkglint *Pkglint) Main(args ...string) (exitcode int) {
	defer func() {
		if r := recover(); r != nil {
			if _, ok := r.(pkglintFatal); ok {
				exitcode = 1
			} else {
				panic(r)
			}
		}
	}()

	if exitcode := pkglint.ParseCommandLine(args); exitcode != nil {
		return *exitcode
	}

	if G.opts.PrintVersion {
		fmt.Fprintf(G.logOut, "%s\n", confVersion)
		return 0
	}

	if G.opts.Profiling {
		f, err := os.Create("pkglint.pprof")
		if err != nil {
			dummyLine.Fatalf("Cannot create profiling file: %s", err)
		}
		pprof.StartCPUProfile(f)
		defer pprof.StopCPUProfile()

		G.rematch = NewHistogram()
		G.renomatch = NewHistogram()
		G.retime = NewHistogram()
		G.loghisto = NewHistogram()
	}

	for _, arg := range G.opts.args {
		G.Todo = append(G.Todo, filepath.ToSlash(arg))
	}
	if len(G.Todo) == 0 {
		G.Todo = []string{"."}
	}

	G.globalData.Initialize()

	for len(G.Todo) != 0 {
		item := G.Todo[0]
		G.Todo = G.Todo[1:]
		CheckDirent(item)
	}

	checktoplevelUnusedLicenses()
	pkglint.PrintSummary()
	if G.opts.Profiling {
		G.loghisto.PrintStats("loghisto", G.logOut, 0)
		G.rematch.PrintStats("rematch", G.logOut, 10)
		G.renomatch.PrintStats("renomatch", G.logOut, 10)
		G.retime.PrintStats("retime", G.logOut, 10)
	}
	if G.errors != 0 {
		return 1
	}
	return 0
}

func (pkglint *Pkglint) ParseCommandLine(args []string) *int {
	gopts := &G.opts
	opts := NewOptions()

	check := opts.AddFlagGroup('C', "check", "check,...", "enable or disable specific checks")
	debug := opts.AddFlagGroup('D', "debugging", "debug,...", "enable or disable debugging categories")
	opts.AddFlagVar('e', "explain", &gopts.Explain, false, "explain the diagnostics or give further help")
	opts.AddFlagVar('f', "show-autofix", &gopts.PrintAutofix, false, "show what pkglint can fix automatically")
	opts.AddFlagVar('F', "autofix", &gopts.Autofix, false, "try to automatically fix some errors (experimental)")
	opts.AddFlagVar('g', "gcc-output-format", &gopts.GccOutput, false, "mimic the gcc output format")
	opts.AddFlagVar('h', "help", &gopts.PrintHelp, false, "print a detailed usage message")
	opts.AddFlagVar('I', "dumpmakefile", &gopts.DumpMakefile, false, "dump the Makefile after parsing")
	opts.AddFlagVar('i', "import", &gopts.Import, false, "prepare the import of a wip package")
	opts.AddFlagVar('p', "profiling", &gopts.Profiling, false, "profile the executing program")
	opts.AddFlagVar('q', "quiet", &gopts.Quiet, false, "don't print a summary line when finishing")
	opts.AddFlagVar('r', "recursive", &gopts.Recursive, false, "check subdirectories, too")
	opts.AddFlagVar('s', "source", &gopts.PrintSource, false, "show the source lines together with diagnostics")
	opts.AddFlagVar('V', "version", &gopts.PrintVersion, false, "print the version number of pkglint")
	warn := opts.AddFlagGroup('W', "warning", "warning,...", "enable or disable groups of warnings")

	check.AddFlagVar("ALTERNATIVES", &gopts.CheckAlternatives, true, "check ALTERNATIVES files")
	check.AddFlagVar("bl3", &gopts.CheckBuildlink3, true, "check buildlink3.mk files")
	check.AddFlagVar("DESCR", &gopts.CheckDescr, true, "check DESCR file")
	check.AddFlagVar("distinfo", &gopts.CheckDistinfo, true, "check distinfo file")
	check.AddFlagVar("extra", &gopts.CheckExtra, false, "check various additional files")
	check.AddFlagVar("global", &gopts.CheckGlobal, false, "inter-package checks")
	check.AddFlagVar("INSTALL", &gopts.CheckInstall, true, "check INSTALL and DEINSTALL scripts")
	check.AddFlagVar("Makefile", &gopts.CheckMakefile, true, "check Makefiles")
	check.AddFlagVar("MESSAGE", &gopts.CheckMessage, true, "check MESSAGE file")
	check.AddFlagVar("mk", &gopts.CheckMk, true, "check other .mk files")
	check.AddFlagVar("patches", &gopts.CheckPatches, true, "check patches")
	check.AddFlagVar("PLIST", &gopts.CheckPlist, true, "check PLIST files")

	debug.AddFlagVar("include", &gopts.DebugInclude, false, "included files")
	debug.AddFlagVar("misc", &gopts.DebugMisc, false, "all things that didn't fit elsewhere")
	debug.AddFlagVar("patches", &gopts.DebugPatches, false, "the states of the patch parser")
	debug.AddFlagVar("quoting", &gopts.DebugQuoting, false, "additional information about quoting")
	debug.AddFlagVar("shell", &gopts.DebugShell, false, "the parsers for shell words and shell commands")
	debug.AddFlagVar("tools", &gopts.DebugTools, false, "the tools framework")
	debug.AddFlagVar("trace", &gopts.DebugTrace, false, "follow subroutine calls")
	debug.AddFlagVar("unchecked", &gopts.DebugUnchecked, false, "show the current limitations of pkglint")
	debug.AddFlagVar("unused", &gopts.DebugUnused, false, "unused variables")
	debug.AddFlagVar("vartypes", &gopts.DebugVartypes, false, "additional type information")
	debug.AddFlagVar("varuse", &gopts.DebugVaruse, false, "contexts where variables are used")

	warn.AddFlagVar("absname", &gopts.WarnAbsname, true, "warn about use of absolute file names")
	warn.AddFlagVar("directcmd", &gopts.WarnDirectcmd, true, "warn about use of direct command names instead of Make variables")
	warn.AddFlagVar("extra", &gopts.WarnExtra, false, "enable some extra warnings")
	warn.AddFlagVar("order", &gopts.WarnOrder, false, "warn if Makefile entries are unordered")
	warn.AddFlagVar("perm", &gopts.WarnPerm, false, "warn about unforeseen variable definition and use")
	warn.AddFlagVar("plist-depr", &gopts.WarnPlistDepr, false, "warn about deprecated paths in PLISTs")
	warn.AddFlagVar("plist-sort", &gopts.WarnPlistSort, false, "warn about unsorted entries in PLISTs")
	warn.AddFlagVar("quoting", &gopts.WarnQuoting, false, "warn about quoting issues")
	warn.AddFlagVar("space", &gopts.WarnSpace, false, "warn about inconsistent use of white-space")
	warn.AddFlagVar("style", &gopts.WarnStyle, false, "warn about stylistic issues")
	warn.AddFlagVar("types", &gopts.WarnTypes, true, "do some simple type checking in Makefiles")

	remainingArgs, err := opts.Parse(args)
	if err != nil {
		fmt.Fprintf(G.logErr, "%s\n\n", err)
		opts.Help(G.logErr, "pkglint [options] dir...")
		exitcode := 1
		return &exitcode
	}
	gopts.args = remainingArgs

	if gopts.PrintHelp {
		opts.Help(G.logOut, "pkglint [options] dir...")
		exitcode := 0
		return &exitcode
	}

	return nil
}

func (pkglint *Pkglint) PrintSummary() {
	if !G.opts.Quiet {
		if G.errors != 0 || G.warnings != 0 {
			fmt.Fprintf(G.logOut, "%d %s and %d %s found.\n",
				G.errors, ifelseStr(G.errors == 1, "error", "errors"),
				G.warnings, ifelseStr(G.warnings == 1, "warning", "warnings"))
		} else {
			io.WriteString(G.logOut, "looks fine.\n")
		}
		if G.explanationsAvailable && !G.opts.Explain {
			fmt.Fprint(G.logOut, "(Run \"pkglint -e\" to show explanations.)\n")
		}
		if G.autofixAvailable && !G.opts.PrintAutofix && !G.opts.Autofix {
			fmt.Fprint(G.logOut, "(Run \"pkglint -fs\" to show what can be fixed automatically.)\n")
		}
		if G.autofixAvailable && !G.opts.Autofix {
			fmt.Fprint(G.logOut, "(Run \"pkglint -F\" to automatically fix some issues.)\n")
		}
	}
}
