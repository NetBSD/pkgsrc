package main

import (
	"fmt"
	"io"
	"netbsd.org/pkglint/getopt"
	"netbsd.org/pkglint/histogram"
	"netbsd.org/pkglint/line"
	"netbsd.org/pkglint/regex"
	"netbsd.org/pkglint/trace"
	"os"
	"os/user"
	"path"
	"path/filepath"
	"runtime/pprof"
	"strings"
)

const confMake = "@BMAKE@"
const confVersion = "@VERSION@"

func main() {
	G.logOut, G.logErr, trace.Out = os.Stdout, os.Stderr, os.Stdout
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

	if G.opts.Profiling {
		f, err := os.Create("pkglint.pprof")
		if err != nil {
			dummyLine.Fatalf("Cannot create profiling file: %s", err)
		}
		pprof.StartCPUProfile(f)
		defer pprof.StopCPUProfile()

		regex.Profiling = true
		G.loghisto = histogram.New()
		defer func() {
			G.loghisto.PrintStats("loghisto", G.logOut, 0)
			regex.PrintStats()
		}()
	}

	for _, arg := range G.opts.args {
		G.Todo = append(G.Todo, filepath.ToSlash(arg))
	}
	if len(G.Todo) == 0 {
		G.Todo = []string{"."}
	}

	G.globalData.Initialize()

	currentUser, err := user.Current()
	if err == nil {
		// On Windows, this is `Computername\Username`.
		G.CurrentUsername = regex.Compile(`^.*\\`).ReplaceAllString(currentUser.Username, "")
	}

	for len(G.Todo) != 0 {
		item := G.Todo[0]
		G.Todo = G.Todo[1:]
		pkglint.CheckDirent(item)
	}

	checkToplevelUnusedLicenses()
	pkglint.PrintSummary()
	if G.errors != 0 {
		return 1
	}
	return 0
}

func (pkglint *Pkglint) ParseCommandLine(args []string) *int {
	gopts := &G.opts
	opts := getopt.NewOptions()

	check := opts.AddFlagGroup('C', "check", "check,...", "enable or disable specific checks")
	opts.AddFlagVar('d', "debug", &trace.Tracing, false, "log verbose call traces for debugging")
	opts.AddFlagVar('e', "explain", &gopts.Explain, false, "explain the diagnostics or give further help")
	opts.AddFlagVar('f', "show-autofix", &gopts.PrintAutofix, false, "show what pkglint can fix automatically")
	opts.AddFlagVar('F', "autofix", &gopts.Autofix, false, "try to automatically fix some errors (experimental)")
	opts.AddFlagVar('g', "gcc-output-format", &gopts.GccOutput, false, "mimic the gcc output format")
	opts.AddFlagVar('h', "help", &gopts.PrintHelp, false, "print a detailed usage message")
	opts.AddFlagVar('I', "dumpmakefile", &gopts.DumpMakefile, false, "dump the Makefile after parsing")
	opts.AddFlagVar('i', "import", &gopts.Import, false, "prepare the import of a wip package")
	opts.AddFlagVar('m', "log-verbose", &gopts.LogVerbose, false, "allow the same log message more than once")
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

	if G.opts.PrintVersion {
		fmt.Fprintf(G.logOut, "%s\n", confVersion)
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

func (pkglint *Pkglint) CheckDirent(fname string) {
	if trace.Tracing {
		defer trace.Call1(fname)()
	}

	st, err := os.Lstat(fname)
	if err != nil || !st.Mode().IsDir() && !st.Mode().IsRegular() {
		NewLineWhole(fname).Errorf("No such file or directory.")
		return
	}
	isDir := st.Mode().IsDir()
	isReg := st.Mode().IsRegular()

	G.CurrentDir = ifelseStr(isReg, path.Dir(fname), fname)
	absCurrentDir := abspath(G.CurrentDir)
	G.Wip = !G.opts.Import && matches(absCurrentDir, `/wip/|/wip$`)
	G.Infrastructure = matches(absCurrentDir, `/mk/|/mk$`)
	G.CurPkgsrcdir = findPkgsrcTopdir(G.CurrentDir)
	if G.CurPkgsrcdir == "" {
		NewLineWhole(fname).Errorf("Cannot determine the pkgsrc root directory for %q.", G.CurrentDir)
		return
	}

	switch {
	case isDir && isEmptyDir(fname):
		return
	case isReg:
		Checkfile(fname)
		return
	}

	switch G.CurPkgsrcdir {
	case "../..":
		checkdirPackage(relpath(G.globalData.Pkgsrcdir, G.CurrentDir))
	case "..":
		CheckdirCategory()
	case ".":
		CheckdirToplevel()
	default:
		NewLineWhole(fname).Errorf("Cannot check directories outside a pkgsrc tree.")
	}
}

// Returns the pkgsrc top-level directory, relative to the given file or directory.
func findPkgsrcTopdir(fname string) string {
	for _, dir := range [...]string{".", "..", "../..", "../../.."} {
		if fileExists(fname + "/" + dir + "/mk/bsd.pkg.mk") {
			return dir
		}
	}
	return ""
}

func resolveVariableRefs(text string) string {
	if trace.Tracing {
		defer trace.Call1(text)()
	}

	visited := make(map[string]bool) // To prevent endless loops

	str := text
	for {
		replaced := regex.Compile(`\$\{([\w.]+)\}`).ReplaceAllStringFunc(str, func(m string) string {
			varname := m[2 : len(m)-1]
			if !visited[varname] {
				visited[varname] = true
				if G.Pkg != nil {
					if value, ok := G.Pkg.varValue(varname); ok {
						return value
					}
				}
				if G.Mk != nil {
					if value, ok := G.Mk.VarValue(varname); ok {
						return value
					}
				}
			}
			return "${" + varname + "}"
		})
		if replaced == str {
			return replaced
		}
		str = replaced
	}
}

func CheckfileExtra(fname string) {
	if trace.Tracing {
		defer trace.Call1(fname)()
	}

	if lines := LoadNonemptyLines(fname, false); lines != nil {
		ChecklinesTrailingEmptyLines(lines)
	}
}

func ChecklinesDescr(lines []line.Line) {
	if trace.Tracing {
		defer trace.Call1(lines[0].Filename())()
	}

	for _, line := range lines {
		LineChecker{line}.CheckLength(80)
		LineChecker{line}.CheckTrailingWhitespace()
		LineChecker{line}.CheckValidCharacters(`[\t -~]`)
		if contains(line.Text(), "${") {
			line.Notef("Variables are not expanded in the DESCR file.")
		}
	}
	ChecklinesTrailingEmptyLines(lines)

	if maxlines := 24; len(lines) > maxlines {
		line := lines[maxlines]

		line.Warnf("File too long (should be no more than %d lines).", maxlines)
		Explain(
			"The DESCR file should fit on a traditional terminal of 80x25",
			"characters.  It is also intended to give a _brief_ summary about",
			"the package's contents.")
	}

	SaveAutofixChanges(lines)
}

func ChecklinesMessage(lines []line.Line) {
	if trace.Tracing {
		defer trace.Call1(lines[0].Filename())()
	}

	explainMessage := func() {
		Explain(
			"A MESSAGE file should consist of a header line, having 75 \"=\"",
			"characters, followed by a line containing only the RCS Id, then an",
			"empty line, your text and finally the footer line, which is the",
			"same as the header line.")
	}

	if len(lines) < 3 {
		lastLine := lines[len(lines)-1]
		lastLine.Warnf("File too short.")
		explainMessage()
		return
	}

	hline := strings.Repeat("=", 75)
	if line := lines[0]; line.Text() != hline {
		line.Warnf("Expected a line of exactly 75 \"=\" characters.")
		explainMessage()
	}
	LineChecker{lines[1]}.CheckRcsid(``, "")
	for _, line := range lines {
		LineChecker{line}.CheckLength(80)
		LineChecker{line}.CheckTrailingWhitespace()
		LineChecker{line}.CheckValidCharacters(`[\t -~]`)
	}
	if lastLine := lines[len(lines)-1]; lastLine.Text() != hline {
		lastLine.Warnf("Expected a line of exactly 75 \"=\" characters.")
		explainMessage()
	}
	ChecklinesTrailingEmptyLines(lines)
}

func CheckfileMk(fname string) {
	if trace.Tracing {
		defer trace.Call1(fname)()
	}

	lines := LoadNonemptyLines(fname, true)
	if lines == nil {
		return
	}

	NewMkLines(lines).Check()
	SaveAutofixChanges(lines)
}

func Checkfile(fname string) {
	if trace.Tracing {
		defer trace.Call1(fname)()
	}

	basename := path.Base(fname)
	if hasPrefix(basename, "work") || hasSuffix(basename, "~") || hasSuffix(basename, ".orig") || hasSuffix(basename, ".rej") {
		if G.opts.Import {
			NewLineWhole(fname).Errorf("Must be cleaned up before committing the package.")
		}
		return
	}

	st, err := os.Lstat(fname)
	if err != nil {
		NewLineWhole(fname).Errorf("%s", err)
		return
	}

	if st.Mode().IsRegular() && st.Mode().Perm()&0111 != 0 && !isCommitted(fname) {
		line := NewLine(fname, 0, "", nil)
		line.Warnf("Should not be executable.")
		Explain(
			"No package file should ever be executable.  Even the INSTALL and",
			"DEINSTALL scripts are usually not usable in the form they have in",
			"the package, as the pathnames get adjusted during installation.",
			"So there is no need to have any file executable.")
	}

	switch {
	case st.Mode().IsDir():
		switch {
		case basename == "files" || basename == "patches" || basename == "CVS":
			// Ok
		case matches(fname, `(?:^|/)files/[^/]*$`):
			// Ok
		case !isEmptyDir(fname):
			NewLineWhole(fname).Warnf("Unknown directory name.")
		}

	case st.Mode()&os.ModeSymlink != 0:
		if !hasPrefix(basename, "work") {
			NewLineWhole(fname).Warnf("Unknown symlink name.")
		}

	case !st.Mode().IsRegular():
		NewLineWhole(fname).Errorf("Only files and directories are allowed in pkgsrc.")

	case basename == "ALTERNATIVES":
		if G.opts.CheckAlternatives {
			CheckfileExtra(fname)
		}

	case basename == "buildlink3.mk":
		if G.opts.CheckBuildlink3 {
			if lines := LoadNonemptyLines(fname, true); lines != nil {
				ChecklinesBuildlink3Mk(NewMkLines(lines))
			}
		}

	case hasPrefix(basename, "DESCR"):
		if G.opts.CheckDescr {
			if lines := LoadNonemptyLines(fname, false); lines != nil {
				ChecklinesDescr(lines)
			}
		}

	case basename == "distinfo":
		if G.opts.CheckDistinfo {
			if lines := LoadNonemptyLines(fname, false); lines != nil {
				ChecklinesDistinfo(lines)
			}
		}

	case basename == "DEINSTALL" || basename == "INSTALL":
		if G.opts.CheckInstall {
			CheckfileExtra(fname)
		}

	case hasPrefix(basename, "MESSAGE"):
		if G.opts.CheckMessage {
			if lines := LoadNonemptyLines(fname, false); lines != nil {
				ChecklinesMessage(lines)
			}
		}

	case matches(basename, `^patch-[-A-Za-z0-9_.~+]*[A-Za-z0-9_]$`):
		if G.opts.CheckPatches {
			if lines := LoadNonemptyLines(fname, false); lines != nil {
				ChecklinesPatch(lines)
			}
		}

	case matches(fname, `(?:^|/)patches/manual[^/]*$`):
		if trace.Tracing {
			trace.Step1("Unchecked file %q.", fname)
		}

	case matches(fname, `(?:^|/)patches/[^/]*$`):
		NewLineWhole(fname).Warnf("Patch files should be named \"patch-\", followed by letters, '-', '_', '.', and digits only.")

	case matches(basename, `^(?:.*\.mk|Makefile.*)$`) && !matches(fname, `files/`) && !matches(fname, `patches/`):
		if G.opts.CheckMk {
			CheckfileMk(fname)
		}

	case hasPrefix(basename, "PLIST"):
		if G.opts.CheckPlist {
			if lines := LoadNonemptyLines(fname, false); lines != nil {
				ChecklinesPlist(lines)
			}
		}

	case basename == "TODO" || basename == "README":
		// Ok

	case hasPrefix(basename, "CHANGES-"):
		// This only checks the file, but doesn't register the changes globally.
		G.globalData.loadDocChangesFromFile(fname)

	case matches(fname, `(?:^|/)files/[^/]*$`):
		// Skip

	case basename == "spec":
		// Ok in regression tests

	default:
		NewLineWhole(fname).Warnf("Unexpected file found.")
		if G.opts.CheckExtra {
			CheckfileExtra(fname)
		}
	}
}

func ChecklinesTrailingEmptyLines(lines []line.Line) {
	max := len(lines)
	last := max
	for last > 1 && lines[last-1].Text() == "" {
		last--
	}
	if last != max {
		lines[last].Notef("Trailing empty lines.")
	}
}
