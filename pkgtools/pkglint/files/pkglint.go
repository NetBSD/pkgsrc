package main

import (
	"fmt"
	"netbsd.org/pkglint/getopt"
	"netbsd.org/pkglint/histogram"
	"netbsd.org/pkglint/regex"
	"netbsd.org/pkglint/textproc"
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

// Pkglint contains all global variables of this Go package.
// The rest of the global state is in the other packages:
//  regex.Profiling    (not thread-local)
//  regex.res          (and related variables; not thread-safe)
//  textproc.Testing   (not thread-local; harmless)
//  tracing.Tracing    (not thread-safe)
//  tracing.Out        (not thread-safe)
//  tracing.traceDepth (not thread-safe)
type Pkglint struct {
	opts   CmdOpts  // Command line options.
	Pkgsrc *Pkgsrc  // Global data, mostly extracted from mk/*.
	Pkg    *Package // The package that is currently checked.
	Mk     *MkLines // The Makefile (or fragment) that is currently checked.

	Todo            []string // The files or directories that still need to be checked.
	Wip             bool     // Is the currently checked item from pkgsrc-wip?
	Infrastructure  bool     // Is the currently checked item from the pkgsrc infrastructure?
	Testing         bool     // Is pkglint in self-testing mode (only during development)?
	CurrentUsername string   // For checking against OWNER and MAINTAINER
	CvsEntriesDir   string   // Cached to avoid I/O
	CvsEntriesLines []Line

	errors                int
	warnings              int
	explainNext           bool
	logged                map[string]bool
	explanationsAvailable bool
	explanationsGiven     map[string]bool
	autofixAvailable      bool
	logOut                *SeparatorWriter
	logErr                *SeparatorWriter

	loghisto  *histogram.Histogram
	loaded    *histogram.Histogram
	res       regex.Registry
	fileCache *FileCache
}

func NewPkglint() Pkglint {
	return Pkglint{
		res:       regex.NewRegistry(),
		fileCache: NewFileCache(200)}
}

type CmdOpts struct {
	CheckAlternatives,
	CheckBuildlink3,
	CheckDescr,
	CheckDistinfo,
	CheckExtra,
	CheckGlobal,
	CheckInstall,
	CheckMakefile,
	CheckMessage,
	CheckMk,
	CheckOptions,
	CheckPatches,
	CheckPlist bool

	WarnAbsname,
	WarnDirectcmd,
	WarnExtra,
	WarnOrder,
	WarnPerm,
	WarnPlistDepr,
	WarnPlistSort,
	WarnQuoting,
	WarnSpace,
	WarnStyle,
	WarnTypes bool

	Explain,
	Autofix,
	GccOutput,
	PrintHelp,
	DumpMakefile,
	Import,
	LogVerbose,
	Profiling,
	Quiet,
	Recursive,
	PrintAutofix,
	PrintSource,
	PrintVersion bool

	LogOnly []string

	args []string
}

type Hash struct {
	hash string
	line Line
}

// G is the abbreviation for "global state";
// it is the only global variable in this Go package
var G = NewPkglint()

var exit = os.Exit // Indirect access, to allow main() to be tested.

func main() {
	G.logOut = NewSeparatorWriter(os.Stdout)
	G.logErr = NewSeparatorWriter(os.Stderr)
	trace.Out = os.Stdout
	exit(G.Main(os.Args...))
}

// Main runs the main program with the given arguments.
// argv[0] is the program name.
//
// Note: during tests, calling this method disables tracing
// because the command line option --debug sets trace.Tracing
// back to false.
func (pkglint *Pkglint) Main(argv ...string) (exitcode int) {
	defer func() {
		if r := recover(); r != nil {
			if _, ok := r.(pkglintFatal); ok {
				exitcode = 1
			} else {
				panic(r)
			}
		}
	}()

	if exitcode := pkglint.ParseCommandLine(argv); exitcode != nil {
		return *exitcode
	}

	if pkglint.opts.Profiling {
		f, err := os.Create("pkglint.pprof")
		if err != nil {
			G.Panicf("Cannot create profiling file: %s", err)
		}
		defer f.Close()

		pprof.StartCPUProfile(f)
		defer pprof.StopCPUProfile()

		pkglint.res.Profiling()
		pkglint.loghisto = histogram.New()
		pkglint.loaded = histogram.New()
		defer func() {
			pkglint.logOut.Write("")
			pkglint.loghisto.PrintStats("loghisto", pkglint.logOut.out, -1)
			G.res.PrintStats(pkglint.logOut.out)
			pkglint.loaded.PrintStats("loaded", pkglint.logOut.out, 10)
			pkglint.logOut.WriteLine(fmt.Sprintf("fileCache: %d hits, %d misses", pkglint.fileCache.hits, pkglint.fileCache.misses))
		}()
	}

	for _, arg := range pkglint.opts.args {
		pkglint.Todo = append(pkglint.Todo, filepath.ToSlash(arg))
	}
	if len(pkglint.Todo) == 0 {
		pkglint.Todo = []string{"."}
	}

	firstArg := G.Todo[0]
	if fileExists(firstArg) {
		firstArg = path.Dir(firstArg)
	}
	relTopdir := findPkgsrcTopdir(firstArg)
	if relTopdir == "" {
		G.Panicf("%q is not inside a pkgsrc tree.", firstArg)
	}

	pkglint.Pkgsrc = NewPkgsrc(firstArg + "/" + relTopdir)
	pkglint.Pkgsrc.LoadInfrastructure()

	currentUser, err := user.Current()
	if err == nil {
		// On Windows, this is `Computername\Username`.
		pkglint.CurrentUsername = replaceAll(currentUser.Username, `^.*\\`, "")
	}

	for len(pkglint.Todo) != 0 {
		item := pkglint.Todo[0]
		pkglint.Todo = pkglint.Todo[1:]
		pkglint.CheckDirent(item)
	}

	checkToplevelUnusedLicenses()
	pkglint.PrintSummary()
	if pkglint.errors != 0 {
		return 1
	}
	return 0
}

func (pkglint *Pkglint) ParseCommandLine(args []string) *int {
	gopts := &pkglint.opts
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
	opts.AddStrList('o', "only", &gopts.LogOnly, "only log messages containing the given text")
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
	check.AddFlagVar("options", &gopts.CheckOptions, true, "check options.mk files")
	check.AddFlagVar("patches", &gopts.CheckPatches, true, "check patches")
	check.AddFlagVar("PLIST", &gopts.CheckPlist, true, "check PLIST files")

	warn.AddFlagVar("absname", &gopts.WarnAbsname, true, "warn about use of absolute file names")
	warn.AddFlagVar("directcmd", &gopts.WarnDirectcmd, true, "warn about use of direct command names instead of Make variables")
	warn.AddFlagVar("extra", &gopts.WarnExtra, false, "enable some extra warnings")
	warn.AddFlagVar("order", &gopts.WarnOrder, true, "warn if Makefile entries are unordered")
	warn.AddFlagVar("perm", &gopts.WarnPerm, false, "warn about unforeseen variable definition and use")
	warn.AddFlagVar("plist-depr", &gopts.WarnPlistDepr, false, "warn about deprecated paths in PLISTs")
	warn.AddFlagVar("plist-sort", &gopts.WarnPlistSort, false, "warn about unsorted entries in PLISTs")
	warn.AddFlagVar("quoting", &gopts.WarnQuoting, false, "warn about quoting issues")
	warn.AddFlagVar("space", &gopts.WarnSpace, false, "warn about inconsistent use of white-space")
	warn.AddFlagVar("style", &gopts.WarnStyle, false, "warn about stylistic issues")
	warn.AddFlagVar("types", &gopts.WarnTypes, true, "do some simple type checking in Makefiles")

	remainingArgs, err := opts.Parse(args)
	if err != nil {
		fmt.Fprintf(pkglint.logErr.out, "%s\n\n", err)
		opts.Help(pkglint.logErr.out, "pkglint [options] dir...")
		exitcode := 1
		return &exitcode
	}
	gopts.args = remainingArgs

	if gopts.PrintHelp {
		opts.Help(pkglint.logOut.out, "pkglint [options] dir...")
		exitcode := 0
		return &exitcode
	}

	if pkglint.opts.PrintVersion {
		fmt.Fprintf(pkglint.logOut.out, "%s\n", confVersion)
		exitcode := 0
		return &exitcode
	}

	return nil
}

func (pkglint *Pkglint) PrintSummary() {
	if !pkglint.opts.Quiet && !pkglint.opts.Autofix {
		if pkglint.errors != 0 || pkglint.warnings != 0 {
			pkglint.logOut.Printf("%d %s and %d %s found.\n",
				pkglint.errors, ifelseStr(pkglint.errors == 1, "error", "errors"),
				pkglint.warnings, ifelseStr(pkglint.warnings == 1, "warning", "warnings"))
		} else {
			pkglint.logOut.WriteLine("Looks fine.")
		}
		if pkglint.explanationsAvailable && !pkglint.opts.Explain {
			pkglint.logOut.WriteLine("(Run \"pkglint -e\" to show explanations.)")
		}
		if pkglint.autofixAvailable && !pkglint.opts.PrintAutofix {
			pkglint.logOut.WriteLine("(Run \"pkglint -fs\" to show what can be fixed automatically.)")
		}
		if pkglint.autofixAvailable && !pkglint.opts.Autofix {
			pkglint.logOut.WriteLine("(Run \"pkglint -F\" to automatically fix some issues.)")
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

	dir := ifelseStr(isReg, path.Dir(fname), fname)
	pkgsrcRel := G.Pkgsrc.ToRel(dir)
	pkglint.Wip = matches(pkgsrcRel, `^wip(/|$)`)
	pkglint.Infrastructure = matches(pkgsrcRel, `^mk(/|$)`)
	pkgsrcdir := findPkgsrcTopdir(dir)
	if pkgsrcdir == "" {
		NewLineWhole(fname).Errorf("Cannot determine the pkgsrc root directory for %q.", cleanpath(dir))
		return
	}

	switch {
	case isDir && isEmptyDir(fname):
		return
	case isReg:
		pkglint.Checkfile(fname)
		return
	}

	switch pkgsrcdir {
	case "../..":
		pkglint.checkdirPackage(dir)
	case "..":
		CheckdirCategory(dir)
	case ".":
		CheckdirToplevel(dir)
	default:
		NewLineWhole(fname).Errorf("Cannot check directories outside a pkgsrc tree.")
	}
}

func (pkglint *Pkglint) Panicf(format string, args ...interface{}) {
	prefix := ifelseStr(G.opts.GccOutput, llFatal.GccName, llFatal.TraditionalName)
	pkglint.logErr.Write(prefix + ": " + fmt.Sprintf(format, args...) + "\n")
	panic(pkglintFatal{})
}

// Assertf checks that the condition is true. Otherwise it terminates the
// process with a fatal error message, prefixed with "Pkglint internal error".
//
// This method must only be used for programming errors.
// For runtime errors, use Panicf.
func (pkglint *Pkglint) Assertf(cond bool, format string, args ...interface{}) {
	if !cond {
		pkglint.Panicf("Pkglint internal error: "+format, args...)
	}
}

func (pkglint *Pkglint) NewPrefixReplacer(s string) *textproc.PrefixReplacer {
	return textproc.NewPrefixReplacer(s, &pkglint.res)
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

func resolveVariableRefs(text string) (resolved string) {
	if !contains(text, "${") {
		return text
	}

	visited := make(map[string]bool) // To prevent endless loops

	replacer := func(m string) string {
		varname := m[2 : len(m)-1]
		if !visited[varname] {
			visited[varname] = true
			if G.Pkg != nil {
				if value, ok := G.Pkg.vars.Value(varname); ok {
					return value
				}
			}
			if G.Mk != nil {
				if value, ok := G.Mk.vars.Value(varname); ok {
					return value
				}
			}
		}
		return "${" + varname + "}"
	}

	str := text
	for {
		replaced := replaceAllFunc(str, `\$\{([\w.]+)\}`, replacer)
		if replaced == str {
			if trace.Tracing && str != text {
				trace.Stepf("resolveVariableRefs %q => %q", text, replaced)
			}
			return replaced
		}
		str = replaced
	}
}

func CheckfileExtra(fname string) {
	if trace.Tracing {
		defer trace.Call1(fname)()
	}

	if lines := Load(fname, NotEmpty|LogErrors); lines != nil {
		ChecklinesTrailingEmptyLines(lines)
	}
}

func ChecklinesDescr(lines []Line) {
	if trace.Tracing {
		defer trace.Call1(lines[0].Filename)()
	}

	for _, line := range lines {
		CheckLineLength(line, 80)
		CheckLineTrailingWhitespace(line)
		CheckLineValidCharacters(line)
		if contains(line.Text, "${") {
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

func ChecklinesMessage(lines []Line) {
	if trace.Tracing {
		defer trace.Call1(lines[0].Filename)()
	}

	explanation := []string{
		"A MESSAGE file should consist of a header line, having 75 \"=\"",
		"characters, followed by a line containing only the RCS Id, then an",
		"empty line, your text and finally the footer line, which is the",
		"same as the header line."}

	if len(lines) < 3 {
		lastLine := lines[len(lines)-1]
		lastLine.Warnf("File too short.")
		Explain(explanation...)
		return
	}

	hline := strings.Repeat("=", 75)
	if line := lines[0]; line.Text != hline {
		fix := line.Autofix()
		fix.Warnf("Expected a line of exactly 75 \"=\" characters.")
		fix.Explain(explanation...)
		fix.InsertBefore(hline)
		fix.Apply()
		CheckLineRcsid(lines[0], ``, "")
	} else if 1 < len(lines) {
		CheckLineRcsid(lines[1], ``, "")
	}
	for _, line := range lines {
		CheckLineLength(line, 80)
		CheckLineTrailingWhitespace(line)
		CheckLineValidCharacters(line)
	}
	if lastLine := lines[len(lines)-1]; lastLine.Text != hline {
		fix := lastLine.Autofix()
		fix.Warnf("Expected a line of exactly 75 \"=\" characters.")
		fix.Explain(explanation...)
		fix.InsertAfter(hline)
		fix.Apply()
	}
	ChecklinesTrailingEmptyLines(lines)

	SaveAutofixChanges(lines)
}

func CheckfileMk(fname string) {
	if trace.Tracing {
		defer trace.Call1(fname)()
	}

	mklines := LoadMk(fname, NotEmpty|LogErrors)
	if mklines == nil {
		return
	}

	mklines.Check()
	mklines.SaveAutofixChanges()
}

func (pkglint *Pkglint) Checkfile(fname string) {
	if trace.Tracing {
		defer trace.Call1(fname)()
	}

	basename := path.Base(fname)
	pkgsrcRel := G.Pkgsrc.ToRel(fname)
	depth := strings.Count(pkgsrcRel, "/")

	if depth == 2 && !G.Wip {
		if contains(basename, "README") || contains(basename, "TODO") {
			NewLineWhole(fname).Errorf("Packages in main pkgsrc must not have a %s file.", basename)
			return
		}
	}

	switch {
	case hasPrefix(basename, "work"),
		hasSuffix(basename, "~"),
		hasSuffix(basename, ".orig"),
		hasSuffix(basename, ".rej"),
		contains(basename, "README") && depth == 2,
		contains(basename, "TODO") && depth == 2:
		if pkglint.opts.Import {
			NewLineWhole(fname).Errorf("Must be cleaned up before committing the package.")
		}
		return
	}

	st, err := os.Lstat(fname)
	if err != nil {
		NewLineWhole(fname).Errorf("Cannot determine file type: %s", err)
		return
	}

	pkglint.checkExecutable(fname, st)
	pkglint.checkMode(fname, st.Mode())
}

// checkMode checks a directory entry based on its file name and its mode
// (regular file, directory, symlink).
func (pkglint *Pkglint) checkMode(fname string, mode os.FileMode) {
	basename := path.Base(fname)
	switch {
	case mode.IsDir():
		switch {
		case basename == "files" || basename == "patches" || isIgnoredFilename(basename):
			// Ok
		case matches(fname, `(?:^|/)files/[^/]*$`):
			// Ok
		case !isEmptyDir(fname):
			NewLineWhole(fname).Warnf("Unknown directory name.")
		}

	case mode&os.ModeSymlink != 0:
		if !hasPrefix(basename, "work") {
			NewLineWhole(fname).Warnf("Unknown symlink name.")
		}

	case !mode.IsRegular():
		NewLineWhole(fname).Errorf("Only files and directories are allowed in pkgsrc.")

	case basename == "ALTERNATIVES":
		if pkglint.opts.CheckAlternatives {
			var plistFiles map[string]bool
			if G.Pkg != nil {
				plistFiles = G.Pkg.PlistFiles
			}
			CheckfileAlternatives(fname, plistFiles)
		}

	case basename == "buildlink3.mk":
		if pkglint.opts.CheckBuildlink3 {
			if mklines := LoadMk(fname, NotEmpty|LogErrors); mklines != nil {
				ChecklinesBuildlink3Mk(mklines)
			}
		}

	case hasPrefix(basename, "DESCR"):
		if pkglint.opts.CheckDescr {
			if lines := Load(fname, NotEmpty|LogErrors); lines != nil {
				ChecklinesDescr(lines)
			}
		}

	case basename == "distinfo":
		if pkglint.opts.CheckDistinfo {
			if lines := Load(fname, NotEmpty|LogErrors); lines != nil {
				ChecklinesDistinfo(lines)
			}
		}

	case basename == "DEINSTALL" || basename == "INSTALL":
		if pkglint.opts.CheckInstall {
			CheckfileExtra(fname)
		}

	case hasPrefix(basename, "MESSAGE"):
		if pkglint.opts.CheckMessage {
			if lines := Load(fname, NotEmpty|LogErrors); lines != nil {
				ChecklinesMessage(lines)
			}
		}

	case basename == "options.mk":
		if pkglint.opts.CheckOptions {
			if mklines := LoadMk(fname, NotEmpty|LogErrors); mklines != nil {
				ChecklinesOptionsMk(mklines)
			}
		}

	case matches(basename, `^patch-[-A-Za-z0-9_.~+]*[A-Za-z0-9_]$`):
		if pkglint.opts.CheckPatches {
			if lines := Load(fname, NotEmpty|LogErrors); lines != nil {
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
		if pkglint.opts.CheckMk {
			CheckfileMk(fname)
		}

	case hasPrefix(basename, "PLIST"):
		if pkglint.opts.CheckPlist {
			if lines := Load(fname, NotEmpty|LogErrors); lines != nil {
				ChecklinesPlist(lines)
			}
		}

	case hasPrefix(basename, "CHANGES-"):
		// This only checks the file, but doesn't register the changes globally.
		_ = pkglint.Pkgsrc.loadDocChangesFromFile(fname)

	case matches(fname, `(?:^|/)files/[^/]*$`):
		// Skip

	case basename == "spec":
		if !hasPrefix(G.Pkgsrc.ToRel(fname), "regress/") {
			NewLineWhole(fname).Warnf("Only packages in regress/ may have spec files.")
		}

	default:
		NewLineWhole(fname).Warnf("Unexpected file found.")
		if pkglint.opts.CheckExtra {
			CheckfileExtra(fname)
		}
	}
}

func (pkglint *Pkglint) checkExecutable(fname string, st os.FileInfo) {
	switch {
	case !st.Mode().IsRegular():
		// Directories and other entries may be executable.

	case st.Mode().Perm()&0111 == 0:
		// Good.

	case isCommitted(fname):
		// Too late to be fixed by the package developer, since
		// CVS remembers the executable bit in the repo file.
		// At this point, it can only be reset by the CVS admins.

	default:
		line := NewLine(fname, 0, "", nil)
		fix := line.Autofix()
		fix.Warnf("Should not be executable.")
		fix.Explain(
			"No package file should ever be executable.  Even the INSTALL and",
			"DEINSTALL scripts are usually not usable in the form they have in",
			"the package, as the pathnames get adjusted during installation.",
			"So there is no need to have any file executable.")
		fix.Custom(func(printAutofix, autofix bool) {
			fix.Describef(0, "Clearing executable bits")
			if autofix {
				if err := os.Chmod(fname, st.Mode()&^0111); err != nil {
					line.Errorf("Cannot clear executable bits: %s", err)
				}
			}
		})
		fix.Apply()
	}
}

func ChecklinesTrailingEmptyLines(lines []Line) {
	max := len(lines)
	last := max
	for last > 1 && lines[last-1].Text == "" {
		last--
	}
	if last != max {
		lines[last].Notef("Trailing empty lines.")
	}
}

// Tool returns the tool definition from the closest scope (file, global), or nil.
// The command can be "sed" or "gsed" or "${SED}".
// If a tool is returned, usable tells whether that tool has been added
// to USE_TOOLS in the current scope.
func (pkglint *Pkglint) Tool(command string, time ToolTime) (tool *Tool, usable bool) {
	varname := ""
	if m, toolVarname := match1(command, `^\$\{(\w+)\}$`); m {
		varname = toolVarname
	}

	tools := pkglint.tools()

	if t := tools.ByName(command); t != nil {
		if tools.Usable(t, time) {
			return t, true
		}
		tool = t
	}

	if t := tools.ByVarname(varname); t != nil {
		if tools.Usable(t, time) {
			return t, true
		}
		if tool == nil {
			tool = t
		}
	}
	return
}

// ToolByVarname looks up the tool by its variable name, e.g. "SED".
//
// The returned tool may come either from the current Makefile or the
// current package. It is not guaranteed to be usable; that must be
// checked by the calling code.
func (pkglint *Pkglint) ToolByVarname(varname string, time ToolTime) *Tool {
	return pkglint.tools().ByVarname(varname)
}

func (pkglint *Pkglint) tools() *Tools {
	if G.Mk != nil {
		return G.Mk.Tools
	} else {
		return G.Pkgsrc.Tools
	}
}
