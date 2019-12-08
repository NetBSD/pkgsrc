package pkglint

import (
	"fmt"
	"io"
	"netbsd.org/pkglint/getopt"
	"netbsd.org/pkglint/histogram"
	"netbsd.org/pkglint/regex"
	tracePkg "netbsd.org/pkglint/trace"
	"os"
	"os/user"
	"path"
	"runtime"
	"runtime/debug"
	"runtime/pprof"
	"strings"
)

const confMake = "@BMAKE@"
const confVersion = "@VERSION@"

// Pkglint is a container for all global variables of this Go package.
type Pkglint struct {
	Opts   CmdOpts  // Command line options.
	Pkgsrc Pkgsrc   // Global data, mostly extracted from mk/*.
	Pkg    *Package // The package that is currently checked, or nil.

	Todo CurrPathQueue // The files or directories that still need to be checked.

	Wip            bool   // Is the currently checked file or package from pkgsrc-wip?
	Infrastructure bool   // Is the currently checked file from the pkgsrc infrastructure?
	Testing        bool   // Is pkglint in self-testing mode (only during development)?
	Experimental   bool   // For experimental features, only enabled individually in tests
	Username       string // For checking against OWNER and MAINTAINER

	cvsEntriesDir CurrPath // Cached to avoid I/O
	cvsEntries    map[string]CvsEntry

	Logger Logger

	loaded    *histogram.Histogram
	res       regex.Registry
	fileCache *FileCache
	interner  StringInterner

	// cwd is the absolute path to the current working
	// directory. It is used for speeding up Relpath and abspath.
	// There is no other use for it.
	cwd CurrPath

	InterPackage InterPackage
}

func NewPkglint(stdout io.Writer, stderr io.Writer) Pkglint {
	cwd, err := os.Getwd()
	assertNil(err, "os.Getwd")

	p := Pkglint{
		res:       regex.NewRegistry(),
		fileCache: NewFileCache(200),
		cwd:       NewCurrPathSlash(cwd),
		interner:  NewStringInterner()}
	p.Logger.out = NewSeparatorWriter(stdout)
	p.Logger.err = NewSeparatorWriter(stderr)
	return p
}

// unusablePkglint returns a pkglint object that crashes as early as possible.
// This is to ensure that tests are properly initialized and shut down.
func unusablePkglint() Pkglint { return Pkglint{} }

type CmdOpts struct {
	CheckGlobal bool

	WarnExtra,
	WarnPerm,
	WarnQuoting bool

	Profiling,
	ShowHelp,
	DumpMakefile,
	Import,
	Recursive,
	ShowVersion bool

	LogOnly []string

	args []string
}

type Hash struct {
	hash     []byte
	location Location
}

type pkglintFatal struct{}

// G is the abbreviation for "global state";
// this and the tracer are the only global variables in this Go package.
var (
	G     = NewPkglint(os.Stdout, os.Stderr)
	trace tracePkg.Tracer
)

// Main runs the main program with the given arguments.
// args[0] is the program name.
//
// Note: during tests, calling this method disables tracing
// because the getopt parser resets all options before the actual parsing.
// One of these options is trace.Tracing, which is connected to --debug.
//
// It also discards the -Wall option that is used by default in other tests.
func (pkglint *Pkglint) Main(stdout io.Writer, stderr io.Writer, args []string) (exitCode int) {
	G.Logger.out = NewSeparatorWriter(stdout)
	G.Logger.err = NewSeparatorWriter(stderr)
	trace.Out = stdout

	defer func() {
		if r := recover(); r != nil {
			_ = r.(pkglintFatal)
			exitCode = 1
		}
	}()

	if exitcode := pkglint.ParseCommandLine(args); exitcode != -1 {
		return exitcode
	}

	if pkglint.Opts.Profiling {
		defer pkglint.setUpProfiling()()
	}

	pkglint.prepareMainLoop()

	for !pkglint.Todo.IsEmpty() {
		pkglint.Check(pkglint.Todo.Pop())
	}

	pkglint.Pkgsrc.checkToplevelUnusedLicenses()

	pkglint.Logger.ShowSummary(args)
	if pkglint.Logger.errors != 0 {
		return 1
	}
	return 0
}

func (pkglint *Pkglint) setUpProfiling() func() {

	var cleanups []func()
	atExit := func(cleanup func()) {
		cleanups = append(cleanups, cleanup)
	}

	atExit(func() {
		pkglint.fileCache.table = nil
		pkglint.fileCache.mapping = nil
		runtime.GC()

		fd, err := os.Create("pkglint.heapdump")
		assertNil(err, "heapDump.create")

		debug.WriteHeapDump(fd.Fd())

		err = fd.Close()
		assertNil(err, "heapDump.close")

		G = unusablePkglint() // Free all memory.
		runtime.GC()          // For detecting possible memory leaks; see qa-pkglint.
	})

	f, err := os.Create("pkglint.pprof")
	if err != nil {
		pkglint.Logger.TechErrorf("pkglint.pprof", "Cannot create profiling file: %s", err)
		panic(pkglintFatal{})
	}
	atExit(func() { assertNil(f.Close(), "") })

	err = pprof.StartCPUProfile(f)
	assertNil(err, "Cannot start profiling")
	atExit(pprof.StopCPUProfile)

	pkglint.res.Profiling()
	pkglint.Logger.histo = histogram.New()
	pkglint.loaded = histogram.New()
	atExit(func() {
		pkglint.Logger.out.Write("")
		pkglint.Logger.histo.PrintStats(pkglint.Logger.out.out, "loghisto", -1)
		pkglint.res.PrintStats(pkglint.Logger.out.out)
		pkglint.loaded.PrintStats(pkglint.Logger.out.out, "loaded", 10)
		pkglint.Logger.out.WriteLine(sprintf("fileCache: %d hits, %d misses", pkglint.fileCache.hits, pkglint.fileCache.misses))
	})

	return func() {
		for i := range cleanups {
			cleanups[len(cleanups)-1-i]()
		}
	}
}

func (pkglint *Pkglint) prepareMainLoop() {
	firstDir := pkglint.Todo.Front()
	if firstDir.IsFile() {
		// FIXME: consider DirNoClean
		firstDir = firstDir.DirClean()
	}

	relTopdir := findPkgsrcTopdir(firstDir)
	if relTopdir.IsEmpty() {
		// If the first argument to pkglint is not inside a pkgsrc tree,
		// pkglint doesn't know where to load the infrastructure files from,
		// and these are needed for virtually every single check.
		// Therefore, the only sensible thing to do is to quit immediately.
		NewLineWhole(firstDir).Fatalf("Must be inside a pkgsrc tree.")
	}

	pkglint.Pkgsrc = NewPkgsrc(firstDir.JoinNoClean(relTopdir))
	pkglint.Wip = pkglint.Pkgsrc.IsWip(firstDir) // See Pkglint.checkMode.
	pkglint.Pkgsrc.LoadInfrastructure()

	currentUser, err := user.Current()
	assertNil(err, "user.Current")
	// On Windows, this is `Computername\Username`.
	pkglint.Username = replaceAll(currentUser.Username, `^.*\\`, "")
}

func (pkglint *Pkglint) ParseCommandLine(args []string) int {
	gopts := &pkglint.Opts
	lopts := &pkglint.Logger.Opts
	opts := getopt.NewOptions()

	check := opts.AddFlagGroup('C', "check", "check,...", "enable or disable specific checks")
	opts.AddFlagVar('d', "debug", &trace.Tracing, false, "log verbose call traces for debugging")
	opts.AddFlagVar('e', "explain", &lopts.Explain, false, "explain the diagnostics or give further help")
	opts.AddFlagVar('f', "show-autofix", &lopts.ShowAutofix, false, "show what pkglint can fix automatically")
	opts.AddFlagVar('F', "autofix", &lopts.Autofix, false, "try to automatically fix some errors")
	opts.AddFlagVar('g', "gcc-output-format", &lopts.GccOutput, false, "mimic the gcc output format")
	opts.AddFlagVar('h', "help", &gopts.ShowHelp, false, "show a detailed usage message")
	opts.AddFlagVar('I', "dumpmakefile", &gopts.DumpMakefile, false, "dump the Makefile after parsing")
	opts.AddFlagVar('i', "import", &gopts.Import, false, "prepare the import of a wip package")
	opts.AddStrList('o', "only", &gopts.LogOnly, "only log diagnostics containing the given text")
	opts.AddFlagVar('p', "profiling", &gopts.Profiling, false, "profile the executing program")
	opts.AddFlagVar('q', "quiet", &lopts.Quiet, false, "don't show a summary line when finishing")
	opts.AddFlagVar('r', "recursive", &gopts.Recursive, false, "check subdirectories, too")
	opts.AddFlagVar('s', "source", &lopts.ShowSource, false, "show the source lines together with diagnostics")
	opts.AddFlagVar('V', "version", &gopts.ShowVersion, false, "show the version number of pkglint")
	warn := opts.AddFlagGroup('W', "warning", "warning,...", "enable or disable groups of warnings")

	check.AddFlagVar("global", &gopts.CheckGlobal, false, "inter-package checks")

	warn.AddFlagVar("extra", &gopts.WarnExtra, false, "enable some extra warnings")
	warn.AddFlagVar("perm", &gopts.WarnPerm, false, "warn about unforeseen variable definition and use")
	warn.AddFlagVar("quoting", &gopts.WarnQuoting, false, "warn about quoting issues")

	remainingArgs, err := opts.Parse(args)
	if err != nil {
		errOut := pkglint.Logger.err.out
		_, _ = fmt.Fprintln(errOut, err)
		_, _ = fmt.Fprintln(errOut, "")
		opts.Help(errOut, "pkglint [options] dir...")
		return 1
	}
	gopts.args = remainingArgs

	if gopts.ShowHelp {
		opts.Help(pkglint.Logger.out.out, "pkglint [options] dir...")
		return 0
	}

	if pkglint.Opts.ShowVersion {
		_, _ = fmt.Fprintf(pkglint.Logger.out.out, "%s\n", confVersion)
		return 0
	}

	for _, arg := range pkglint.Opts.args {
		pkglint.Todo.Push(NewCurrPathSlash(arg))
	}
	if pkglint.Todo.IsEmpty() {
		pkglint.Todo.Push(".")
	}

	return -1
}

// Check checks a directory entry, which can be a regular file,
// a directory or a symlink (only allowed for the working directory).
//
// This is the method that is called for each command line argument.
//
// It sets up all the global state (infrastructure, wip) for accurately
// classifying the entry.
func (pkglint *Pkglint) Check(dirent CurrPath) {
	if trace.Tracing {
		defer trace.Call(dirent)()
	}

	st, err := dirent.Lstat()
	if err != nil {
		NewLineWhole(dirent).Errorf("No such file or directory.")
		return
	}

	pkglint.checkMode(dirent, st.Mode())
}

func (pkglint *Pkglint) checkMode(dirent CurrPath, mode os.FileMode) {
	// TODO: merge duplicate code in Package.checkDirent
	isDir := mode.IsDir()
	isReg := mode.IsRegular()
	if !isDir && !isReg {
		NewLineWhole(dirent).Errorf("No such file or directory.")
		return
	}

	dir := dirent
	if !isDir {
		dir = dirent.DirNoClean()
	}

	basename := dirent.Base()
	pkgsrcRel := pkglint.Pkgsrc.ToRel(dirent)

	pkglint.Wip = pkgsrcRel.HasPrefixPath("wip")
	pkglint.Infrastructure = pkgsrcRel.HasPrefixPath("mk")
	pkgsrcdir := findPkgsrcTopdir(dir)
	if pkgsrcdir.IsEmpty() {
		G.Logger.TechErrorf("",
			"Cannot determine the pkgsrc root directory for %q.",
			dirent)
		return
	}

	if isReg {
		pkglint.checkExecutable(dirent, mode)
		pkglint.checkReg(dirent, basename, pkgsrcRel.Count())
		return
	}

	if isEmptyDir(dirent) {
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
		NewLineWhole(dirent).Errorf("Cannot check directories outside a pkgsrc tree.")
	}
}

// checkdirPackage checks a complete pkgsrc package, including each
// of the files individually, and also when seen in combination.
func (pkglint *Pkglint) checkdirPackage(dir CurrPath) {
	if trace.Tracing {
		defer trace.Call(dir)()
	}

	pkglint.Pkg = NewPackage(dir)
	defer func() { pkglint.Pkg = nil }()
	pkglint.Pkg.Check()
}

// Returns the pkgsrc top-level directory, relative to the given directory.
func findPkgsrcTopdir(dirname CurrPath) RelPath {
	for _, dir := range [...]RelPath{".", "..", "../..", "../../.."} {
		if dirname.JoinNoClean(dir).JoinNoClean("mk/bsd.pkg.mk").IsFile() {
			return dir
		}
	}
	return ""
}

func resolveVariableRefs(mklines *MkLines, text string) (resolved string) {
	// TODO: How does this fit into the Scope type, which is newer than this function?

	if !containsVarRef(text) {
		return text
	}

	visited := make(map[string]bool) // To prevent endless loops

	replacer := func(m string) string {
		varname := m[2 : len(m)-1]
		if !visited[varname] {
			visited[varname] = true
			if G.Pkg != nil {
				if value, ok := G.Pkg.vars.LastValueFound(varname); ok {
					return value
				}
			}
			if mklines != nil {
				if value, ok := mklines.vars.LastValueFound(varname); ok {
					return value
				}
			}
		}
		return "${" + varname + "}"
	}

	str := text
	for {
		// TODO: Replace regular expression with full parser.
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

func CheckFileOther(filename CurrPath) {
	if trace.Tracing {
		defer trace.Call(filename)()
	}

	if lines := Load(filename, NotEmpty|LogErrors); lines != nil {
		CheckLinesTrailingEmptyLines(lines)
	}
}

func CheckLinesDescr(lines *Lines) {
	if trace.Tracing {
		defer trace.Call(lines.Filename)()
	}

	for _, line := range lines.Lines {
		ck := LineChecker{line}
		ck.CheckLength(80)
		ck.CheckTrailingWhitespace()
		ck.CheckValidCharacters()

		if containsVarRef(line.Text) {
			tokens, _ := NewMkLexer(line.Text, nil).MkTokens()
			for _, token := range tokens {
				if token.Varuse != nil && G.Pkgsrc.VariableType(nil, token.Varuse.varname) != nil {
					line.Notef("Variables are not expanded in the DESCR file.")
				}
			}
		}
	}

	CheckLinesTrailingEmptyLines(lines)

	if maxLines := 24; lines.Len() > maxLines {
		line := lines.Lines[maxLines]

		line.Warnf("File too long (should be no more than %d lines).", maxLines)
		line.Explain(
			"The DESCR file should fit on a traditional terminal of 80x25 characters.",
			"It is also intended to give a _brief_ summary about the package's contents.")
	}

	SaveAutofixChanges(lines)
}

func CheckLinesMessage(lines *Lines) {
	if trace.Tracing {
		defer trace.Call(lines.Filename)()
	}

	// For now, skip all checks when the MESSAGE may be built from multiple
	// files.
	//
	// If the need arises, some of the checks may be activated again, but
	// that requires more sophisticated code.
	if G.Pkg != nil && G.Pkg.vars.IsDefined("MESSAGE_SRC") {
		return
	}

	explanation := func() []string {
		return []string{
			"A MESSAGE file should consist of a header line, having 75 \"=\"",
			"characters, followed by a line containing only the CVS Id, then an",
			"empty line, your text and finally the footer line, which is the",
			"same as the header line."}
	}

	if lines.Len() < 3 {
		line := lines.LastLine()
		line.Warnf("File too short.")
		line.Explain(explanation()...)
		return
	}

	hline := "==========================================================================="
	if line := lines.Lines[0]; line.Text != hline {
		fix := line.Autofix()
		fix.Warnf("Expected a line of exactly 75 \"=\" characters.")
		fix.Explain(explanation()...)
		fix.InsertBefore(hline)
		fix.Apply()
		lines.CheckCvsID(0, ``, "")
	} else {
		lines.CheckCvsID(1, ``, "")
	}
	for _, line := range lines.Lines {
		ck := LineChecker{line}
		ck.CheckLength(80)
		ck.CheckTrailingWhitespace()
		ck.CheckValidCharacters()
	}
	if lastLine := lines.LastLine(); lastLine.Text != hline {
		fix := lastLine.Autofix()
		fix.Warnf("Expected a line of exactly 75 \"=\" characters.")
		fix.Explain(explanation()...)
		fix.InsertAfter(hline)
		fix.Apply()
	}
	CheckLinesTrailingEmptyLines(lines)

	SaveAutofixChanges(lines)
}

func CheckFileMk(filename CurrPath) {
	if trace.Tracing {
		defer trace.Call(filename)()
	}

	mklines := LoadMk(filename, NotEmpty|LogErrors)
	if mklines == nil {
		return
	}

	if G.Pkg != nil {
		G.Pkg.checkFileMakefileExt(filename)
	}

	mklines.Check()
	mklines.SaveAutofixChanges()
}

// checkReg checks the given regular file.
// depth is 3 for files in the package directory, and 4 or more for files
// deeper in the directory hierarchy, such as in files/ or patches/.
func (pkglint *Pkglint) checkReg(filename CurrPath, basename string, depth int) {

	if depth == 3 && !pkglint.Wip {
		// FIXME: There's no good reason for prohibiting a README file.
		if contains(basename, "README") || contains(basename, "TODO") {
			NewLineWhole(filename).Errorf("Packages in main pkgsrc must not have a %s file.", basename)
			// TODO: Add a convincing explanation.
			return
		}
	}

	switch {
	case hasSuffix(basename, "~"),
		hasSuffix(basename, ".orig"),
		hasSuffix(basename, ".rej"),
		contains(basename, "README") && depth == 3,
		contains(basename, "TODO") && depth == 3:
		if pkglint.Opts.Import {
			NewLineWhole(filename).Errorf("Must be cleaned up before committing the package.")
		}
		return
	}

	switch {
	case basename == "ALTERNATIVES":
		CheckFileAlternatives(filename)

	case basename == "buildlink3.mk":
		if mklines := LoadMk(filename, NotEmpty|LogErrors); mklines != nil {
			CheckLinesBuildlink3Mk(mklines)
		}

	case hasPrefix(basename, "DESCR"):
		if lines := Load(filename, NotEmpty|LogErrors); lines != nil {
			CheckLinesDescr(lines)
		}

	case basename == "distinfo":
		if lines := Load(filename, NotEmpty|LogErrors); lines != nil {
			CheckLinesDistinfo(G.Pkg, lines)
		}

	case basename == "DEINSTALL" || basename == "INSTALL":
		CheckFileOther(filename)

	case hasPrefix(basename, "MESSAGE"):
		if lines := Load(filename, NotEmpty|LogErrors); lines != nil {
			CheckLinesMessage(lines)
		}

	case basename == "options.mk":
		if mklines := LoadMk(filename, NotEmpty|LogErrors); mklines != nil {
			CheckLinesOptionsMk(mklines)
		}

	case matches(basename, `^patch-[-\w.~+]*\w$`):
		if lines := Load(filename, NotEmpty|LogErrors); lines != nil {
			CheckLinesPatch(lines)
		}

		// FIXME: consider DirNoClean
	case filename.DirClean().Base() == "patches" && matches(filename.Base(), `^manual[^/]*$`):
		if trace.Tracing {
			trace.Stepf("Unchecked file %q.", filename)
		}

		// FIXME: consider DirNoClean
	case filename.DirClean().Base() == "patches":
		NewLineWhole(filename).Warnf("Patch files should be named \"patch-\", followed by letters, '-', '_', '.', and digits only.")

	case (hasPrefix(basename, "Makefile") || hasSuffix(basename, ".mk")) &&
		// FIXME: consider DirNoClean
		// FIXME: G.Pkgsrc.Rel(filename) instead of filename
		!filename.DirClean().ContainsPath("files"):
		CheckFileMk(filename)

	case hasPrefix(basename, "PLIST"):
		if lines := Load(filename, NotEmpty|LogErrors); lines != nil {
			CheckLinesPlist(G.Pkg, lines)
		}

	case hasPrefix(basename, "CHANGES-"):
		// This only checks the file but doesn't register the changes globally.
		_ = pkglint.Pkgsrc.loadDocChangesFromFile(filename)

		// FIXME: consider DirNoClean
	case filename.DirClean().Base() == "files":
		// Skip files directly in the files/ directory, but not those further down.

	case basename == "spec":
		if !pkglint.Pkgsrc.ToRel(filename).HasPrefixPath("regress") {
			NewLineWhole(filename).Warnf("Only packages in regress/ may have spec files.")
		}

	case pkglint.matchesLicenseFile(basename):
		break

	default:
		NewLineWhole(filename).Warnf("Unexpected file found.")
	}
}

func (pkglint *Pkglint) matchesLicenseFile(basename string) bool {
	if pkglint.Pkg == nil {
		return false
	}

	licenseFile := pkglint.Pkg.vars.LastValue("LICENSE_FILE")
	return basename == path.Base(licenseFile)
}

func (pkglint *Pkglint) checkExecutable(filename CurrPath, mode os.FileMode) {
	if mode.Perm()&0111 == 0 {
		// Not executable at all.
		return
	}

	if isCommitted(filename) {
		// Too late to be fixed by the package developer, since
		// CVS remembers the executable bit in the repo file.
		// At this point, it can only be reset by the CVS admins.
		return
	}

	line := NewLineWhole(filename)
	fix := line.Autofix()
	fix.Warnf("Should not be executable.")
	fix.Explain(
		"No package file should ever be executable.",
		"Even the INSTALL and DEINSTALL scripts are usually not usable",
		"in the form they have in the package,",
		"as the pathnames get adjusted during installation.",
		"So there is no need to have any file executable.")
	fix.Custom(func(showAutofix, autofix bool) {
		fix.Describef(0, "Clearing executable bits")
		if autofix {
			if err := filename.Chmod(mode &^ 0111); err != nil {
				G.Logger.TechErrorf(filename.CleanPath(), "Cannot clear executable bits: %s", err)
			}
		}
	})
	fix.Apply()
}

func CheckLinesTrailingEmptyLines(lines *Lines) {
	max := lines.Len()

	last := max
	for last > 1 && lines.Lines[last-1].Text == "" {
		last--
	}

	if last != max {
		lines.Lines[last].Notef("Trailing empty lines.")
	}
}

// Tool returns the tool definition from the closest scope (file, global), or nil.
// The command can be "sed" or "gsed" or "${SED}".
// If a tool is returned, usable tells whether that tool has been added
// to USE_TOOLS in the current scope (file or package).
func (pkglint *Pkglint) Tool(mklines *MkLines, command string, time ToolTime) (tool *Tool, usable bool) {
	tools := pkglint.tools(mklines)

	if varUse := ToVarUse(command); varUse != nil {
		tool = tools.ByVarname(varUse.varname)
	} else {
		tool = tools.ByName(command)
	}

	return tool, tool != nil && tools.Usable(tool, time)
}

// ToolByVarname looks up the tool by its variable name, e.g. "SED".
//
// The returned tool may come either from the current file or the current package.
// It is not guaranteed to be usable (added to USE_TOOLS), only defined;
// that must be checked by the calling code,
// see Tool.UsableAtLoadTime and Tool.UsableAtRunTime.
func (pkglint *Pkglint) ToolByVarname(mklines *MkLines, varname string) *Tool {
	return pkglint.tools(mklines).ByVarname(varname)
}

func (pkglint *Pkglint) tools(mklines *MkLines) *Tools {
	if mklines != nil {
		return mklines.Tools
	} else {
		return pkglint.Pkgsrc.Tools
	}
}

func (pkglint *Pkglint) loadCvsEntries(filename CurrPath) map[string]CvsEntry {
	// FIXME: consider DirNoClean
	dir := filename.DirClean()
	if dir == pkglint.cvsEntriesDir {
		return pkglint.cvsEntries
	}

	var entries map[string]CvsEntry

	handle := func(line *Line, add bool, text string) {
		if !hasPrefix(text, "/") {
			return
		}

		fields := strings.Split(text, "/")
		if len(fields) != 6 {
			line.Errorf("Invalid line: %s", line.Text)
			return
		}

		if add {
			entries[fields[1]] = CvsEntry{fields[1], fields[2], fields[3], fields[4], fields[5]}
		} else {
			delete(entries, fields[1])
		}
	}

	lines := Load(dir.JoinNoClean("CVS/Entries"), 0)
	if lines != nil {
		entries = make(map[string]CvsEntry)
		for _, line := range lines.Lines {
			handle(line, true, line.Text)
		}

		logLines := Load(dir.JoinNoClean("CVS/Entries.Log"), 0)
		if logLines != nil {
			for _, line := range logLines.Lines {
				text := line.Text
				if hasPrefix(text, "A ") {
					handle(line, true, text[2:])
				} else if hasPrefix(text, "R ") {
					handle(line, false, text[2:])
				}
			}
		}
	}

	pkglint.cvsEntriesDir = dir
	pkglint.cvsEntries = entries
	return entries
}

func (pkglint *Pkglint) Abs(filename CurrPath) CurrPath {
	if !filename.IsAbs() {
		return pkglint.cwd.JoinNoClean(NewRelPath(filename.AsPath())).Clean()
	}
	return filename.Clean()
}

type InterPackage struct {
	hashes       map[string]*Hash    // Maps "alg:filename" => hash (inter-package check).
	usedLicenses map[string]struct{} // Maps "license name" => true (inter-package check).
	bl3Names     map[string]Location // Maps buildlink3 identifiers to their first occurrence.
}

func (ip *InterPackage) Enable() {
	*ip = InterPackage{
		make(map[string]*Hash),
		make(map[string]struct{}),
		make(map[string]Location)}
}

func (ip *InterPackage) Enabled() bool { return ip.hashes != nil }

func (ip *InterPackage) Hash(alg string, filename RelPath, hashBytes []byte, loc *Location) *Hash {
	key := alg + ":" + filename.String()
	if otherHash := ip.hashes[key]; otherHash != nil {
		return otherHash
	}

	ip.hashes[key] = &Hash{hashBytes, *loc}
	return nil
}

func (ip *InterPackage) UseLicense(name string) {
	if ip.usedLicenses != nil {
		ip.usedLicenses[intern(name)] = struct{}{}
	}
}

func (ip *InterPackage) IsLicenseUsed(name string) bool {
	_, used := ip.usedLicenses[name]
	return used
}

// Bl3 remembers that the given buildlink3 name is used at the given location.
// Since these names must be unique, there should be no other location where
// the same name is used.
func (ip *InterPackage) Bl3(name string, loc *Location) *Location {
	if ip.bl3Names == nil {
		return nil
	}

	if prev, found := ip.bl3Names[name]; found {
		return &prev
	}

	ip.bl3Names[name] = *loc
	return nil
}
