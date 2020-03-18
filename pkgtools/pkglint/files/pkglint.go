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
	"runtime"
	"runtime/debug"
	"runtime/pprof"
	"strings"
)

const confMake = "@BMAKE@"
const confVersion = "@VERSION@"

// Pkglint is a container for all global variables of this Go package.
type Pkglint struct {
	CheckGlobal bool

	WarnExtra,
	WarnPerm,
	WarnQuoting bool

	Profiling,
	DumpMakefile,
	Import,
	Network,
	Recursive bool

	Pkgsrc Pkgsrc // Global data, mostly extracted from mk/*.

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
func (p *Pkglint) Main(stdout io.Writer, stderr io.Writer, args []string) (exitCode int) {
	G.Logger.out = NewSeparatorWriter(stdout)
	G.Logger.err = NewSeparatorWriter(stderr)
	trace.Out = stdout

	defer func() {
		if r := recover(); r != nil {
			_ = r.(pkglintFatal)
			exitCode = 1
		}
	}()

	if exitcode := p.ParseCommandLine(args); exitcode != -1 {
		return exitcode
	}

	if p.Profiling {
		defer p.setUpProfiling()()
	}

	p.prepareMainLoop()

	for !p.Todo.IsEmpty() {
		p.Check(p.Todo.Pop())
	}

	p.Pkgsrc.checkToplevelUnusedLicenses()

	p.Logger.ShowSummary(args)
	if p.Logger.errors != 0 {
		return 1
	}
	return 0
}

func (p *Pkglint) setUpProfiling() func() {

	var cleanups []func()
	atExit := func(cleanup func()) {
		cleanups = append(cleanups, cleanup)
	}

	atExit(func() {
		p.fileCache.table = nil
		p.fileCache.mapping = nil
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
		p.Logger.TechErrorf("pkglint.pprof", "Cannot create profiling file: %s", err)
		panic(pkglintFatal{})
	}
	atExit(func() { assertNil(f.Close(), "") })

	err = pprof.StartCPUProfile(f)
	assertNil(err, "Cannot start profiling")
	atExit(pprof.StopCPUProfile)

	p.res.Profiling()
	p.Logger.histo = histogram.New()
	p.loaded = histogram.New()
	atExit(func() {
		p.Logger.out.Write("")
		p.Logger.histo.PrintStats(p.Logger.out.out, "loghisto", -1)
		p.res.PrintStats(p.Logger.out.out)
		p.loaded.PrintStats(p.Logger.out.out, "loaded", 10)
		p.Logger.out.WriteLine(sprintf("fileCache: %d hits, %d misses", p.fileCache.hits, p.fileCache.misses))
	})

	return func() {
		for i := range cleanups {
			cleanups[len(cleanups)-1-i]()
		}
	}
}

func (p *Pkglint) prepareMainLoop() {
	firstDir := p.Todo.Front()
	if firstDir.IsFile() {
		firstDir = firstDir.Dir()
	}

	relTopdir := p.findPkgsrcTopdir(firstDir)
	if relTopdir.IsEmpty() {
		// If the first argument to pkglint is not inside a pkgsrc tree,
		// pkglint doesn't know where to load the infrastructure files from,
		// Since virtually every single check needs these files,
		// the only sensible thing to do is to quit immediately.
		G.Logger.TechFatalf(firstDir, "Must be inside a pkgsrc tree.")
	}

	p.Pkgsrc = NewPkgsrc(firstDir.JoinNoClean(relTopdir))
	p.Wip = p.Pkgsrc.IsWip(firstDir) // See Pkglint.checkMode.
	p.Pkgsrc.LoadInfrastructure()

	currentUser, err := user.Current()
	assertNil(err, "user.Current")
	// On Windows, this is `Computername\Username`.
	p.Username = replaceAll(currentUser.Username, `^.*\\`, "")
}

func (p *Pkglint) ParseCommandLine(args []string) int {
	lopts := &p.Logger.Opts
	opts := getopt.NewOptions()

	var showHelp bool
	var showVersion bool

	check := opts.AddFlagGroup('C', "check", "check,...", "enable or disable specific checks")
	opts.AddFlagVar('d', "debug", &trace.Tracing, false, "log verbose call traces for debugging")
	opts.AddFlagVar('e', "explain", &lopts.Explain, false, "explain the diagnostics or give further help")
	opts.AddFlagVar('f', "show-autofix", &lopts.ShowAutofix, false, "show what pkglint can fix automatically")
	opts.AddFlagVar('F', "autofix", &lopts.Autofix, false, "try to automatically fix some errors")
	opts.AddFlagVar('g', "gcc-output-format", &lopts.GccOutput, false, "mimic the gcc output format")
	opts.AddFlagVar('h', "help", &showHelp, false, "show a detailed usage message")
	opts.AddFlagVar('I', "dumpmakefile", &p.DumpMakefile, false, "dump the Makefile after parsing")
	opts.AddFlagVar('i', "import", &p.Import, false, "prepare the import of a wip package")
	opts.AddFlagVar('n', "network", &p.Network, false, "enable checks that need network access")
	opts.AddStrList('o', "only", &lopts.Only, "only log diagnostics containing the given text")
	opts.AddFlagVar('p', "profiling", &p.Profiling, false, "profile the executing program")
	opts.AddFlagVar('q', "quiet", &lopts.Quiet, false, "don't show a summary line when finishing")
	opts.AddFlagVar('r', "recursive", &p.Recursive, false, "check subdirectories, too")
	opts.AddFlagVar('s', "source", &lopts.ShowSource, false, "show the source lines together with diagnostics")
	opts.AddFlagVar('V', "version", &showVersion, false, "show the version number of pkglint")
	warn := opts.AddFlagGroup('W', "warning", "warning,...", "enable or disable groups of warnings")

	check.AddFlagVar("global", &p.CheckGlobal, false, "inter-package checks")

	warn.AddFlagVar("extra", &p.WarnExtra, false, "enable some extra warnings")
	warn.AddFlagVar("perm", &p.WarnPerm, false, "warn about unforeseen variable definition and use")
	warn.AddFlagVar("quoting", &p.WarnQuoting, false, "warn about quoting issues")

	remainingArgs, err := opts.Parse(args)
	if err != nil {
		errOut := p.Logger.err.out
		_, _ = fmt.Fprintln(errOut, err)
		_, _ = fmt.Fprintln(errOut, "")
		opts.Help(errOut, "pkglint [options] dir...")
		return 1
	}

	if showHelp {
		opts.Help(p.Logger.out.out, "pkglint [options] dir...")
		return 0
	}

	if showVersion {
		_, _ = fmt.Fprintf(p.Logger.out.out, "%s\n", confVersion)
		return 0
	}

	for _, arg := range remainingArgs {
		p.Todo.Push(NewCurrPathSlash(arg))
	}
	if p.Todo.IsEmpty() {
		p.Todo.Push(".")
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
func (p *Pkglint) Check(dirent CurrPath) {
	if trace.Tracing {
		defer trace.Call(dirent)()
	}

	st, err := dirent.Lstat()
	if err != nil {
		NewLineWhole(dirent).Errorf("No such file or directory.")
		return
	}

	p.checkMode(dirent, st.Mode())
}

func (p *Pkglint) checkMode(dirent CurrPath, mode os.FileMode) {
	// TODO: merge duplicate code in Package.checkDirent
	isDir := mode.IsDir()
	isReg := mode.IsRegular()
	if !isDir && !isReg {
		NewLineWhole(dirent).Errorf("No such file or directory.")
		return
	}

	dir := dirent
	if !isDir {
		dir = dirent.Dir()
	}

	basename := dirent.Base()
	pkgsrcRel := p.Pkgsrc.Rel(dirent)

	p.Wip = pkgsrcRel.HasPrefixPath("wip")
	p.Infrastructure = pkgsrcRel.HasPrefixPath("mk")
	pkgsrcdir := p.findPkgsrcTopdir(dir)
	if pkgsrcdir.IsEmpty() {
		G.Logger.TechErrorf("",
			"Cannot determine the pkgsrc root directory for %q.",
			dirent)
		return
	}

	if isReg {
		p.checkExecutable(dirent, mode)
		p.checkReg(dirent, basename, pkgsrcRel.Count(), nil)
		return
	}

	if isEmptyDir(dirent) {
		return
	}

	switch pkgsrcdir {
	case "../..":
		p.checkdirPackage(dir)
	case "..":
		CheckdirCategory(dir)
	case ".":
		CheckdirToplevel(dir)
	default:
		NewLineWhole(dirent).Errorf("Cannot check directories outside a pkgsrc tree.")
	}
}

// checkdirPackage checks a complete pkgsrc package, including each
// of the files individually, and when seen in combination.
func (p *Pkglint) checkdirPackage(dir CurrPath) {
	if trace.Tracing {
		defer trace.Call(dir)()
	}

	pkg := NewPackage(dir)
	pkg.Check()
}

// Returns the pkgsrc top-level directory, relative to the given directory.
func (*Pkglint) findPkgsrcTopdir(dirname CurrPath) RelPath {
	for _, dir := range [...]RelPath{".", "..", "../..", "../../.."} {
		if dirname.JoinNoClean(dir).JoinNoClean("mk/bsd.pkg.mk").IsFile() {
			return dir
		}
	}
	return ""
}

func resolveVariableRefs(text string, mklines *MkLines, pkg *Package) string {
	// TODO: How does this fit into the Scope type, which is newer than this function?

	if !containsVarUse(text) {
		return text
	}

	if pkg == nil {
		pkg = mklines.pkg
	}

	visited := make(map[string]bool) // To prevent endless loops

	replace := func(m string) string {
		varname := m[2 : len(m)-1]
		if !visited[varname] {
			visited[varname] = true

			if mklines != nil {
				// TODO: At load time, use mklines.loadVars instead.
				if value, found, indeterminate := mklines.allVars.LastValueFound(varname); found && !indeterminate {
					return value
				}
			}

			if pkg != nil {
				if value, found, indeterminate := pkg.vars.LastValueFound(varname); found && !indeterminate {
					return value
				}
			}
		}
		return "${" + varname + "}"
	}

	str := text
	for {
		// TODO: Replace regular expression with full parser.
		replaced := replaceAllFunc(str, `\$\{([\w.]+)\}`, replace)
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

	checkVarRefs := func(line *Line) {
		tokens, _ := NewMkLexer(line.Text, nil).MkTokens()
		for _, token := range tokens {
			switch {
			case token.Varuse == nil,
				!hasPrefix(token.Text, "${"),
				G.Pkgsrc.VariableType(nil, token.Varuse.varname) == nil:
			default:
				line.Notef("Variables like %q are not expanded in the DESCR file.",
					token.Text)
			}
		}
	}

	for _, line := range lines.Lines {
		ck := LineChecker{line}
		ck.CheckLength(80)
		ck.CheckTrailingWhitespace()
		ck.CheckValidCharacters()
		checkVarRefs(line)
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

func CheckLinesMessage(lines *Lines, pkg *Package) {
	if trace.Tracing {
		defer trace.Call(lines.Filename)()
	}

	// For now, skip all checks when the MESSAGE may be built from multiple
	// files.
	//
	// If the need arises, some of these checks may be activated again, but
	// that requires more sophisticated code.
	if pkg != nil && pkg.vars.IsDefined("MESSAGE_SRC") {
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
		fix.InsertAbove(hline)
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
		fix.InsertBelow(hline)
		fix.Apply()
	}
	CheckLinesTrailingEmptyLines(lines)

	SaveAutofixChanges(lines)
}

func CheckFileMk(filename CurrPath, pkg *Package) {
	if trace.Tracing {
		defer trace.Call(filename)()
	}

	mklines := LoadMk(filename, pkg, NotEmpty|LogErrors)
	if mklines == nil {
		return
	}

	if pkg != nil {
		pkg.checkFileMakefileExt(filename)
	}

	mklines.Check()
	mklines.SaveAutofixChanges()
}

// checkReg checks the given regular file.
// depth is 3 for files in the package directory, and 4 or more for files
// deeper in the directory hierarchy, such as in files/ or patches/.
func (p *Pkglint) checkReg(filename CurrPath, basename string, depth int, pkg *Package) {

	if depth == 3 && !p.Wip {
		if contains(basename, "TODO") {
			NewLineWhole(filename).Errorf("Packages in main pkgsrc must not have a %s file.", basename)
			// TODO: Add a convincing explanation.
			return
		}
	}

	switch {
	case hasSuffix(basename, "~"),
		hasSuffix(basename, ".orig"),
		hasSuffix(basename, ".rej"),
		contains(basename, "TODO") && depth == 3:
		if p.Import {
			NewLineWhole(filename).Errorf("Must be cleaned up before committing the package.")
		}
		return
	}

	p.checkRegCvsSubst(filename)

	switch {
	case basename == "ALTERNATIVES":
		CheckFileAlternatives(filename, pkg)

	case basename == "buildlink3.mk":
		if mklines := LoadMk(filename, pkg, NotEmpty|LogErrors); mklines != nil {
			CheckLinesBuildlink3Mk(mklines)
		}

	case hasPrefix(basename, "DESCR"):
		if lines := Load(filename, NotEmpty|LogErrors); lines != nil {
			CheckLinesDescr(lines)
		}

	case basename == "distinfo":
		if lines := Load(filename, NotEmpty|LogErrors); lines != nil {
			CheckLinesDistinfo(pkg, lines)
		}

	case basename == "DEINSTALL" || basename == "INSTALL":
		CheckFileOther(filename)

	case hasPrefix(basename, "MESSAGE"):
		if lines := Load(filename, NotEmpty|LogErrors); lines != nil {
			CheckLinesMessage(lines, pkg)
		}

	case basename == "options.mk":
		if mklines := LoadMk(filename, pkg, NotEmpty|LogErrors); mklines != nil {
			buildlinkID := ""
			if pkg != nil {
				buildlinkID = pkg.buildlinkID
			}
			CheckLinesOptionsMk(mklines, buildlinkID)
		}

	case matches(basename, `^patch-[-\w.~+]*\w$`):
		if lines := Load(filename, NotEmpty|LogErrors); lines != nil {
			CheckLinesPatch(lines, pkg)
		}

	case filename.Dir().Base() == "patches" && matches(filename.Base(), `^manual[^/]*$`):
		if trace.Tracing {
			trace.Stepf("Unchecked file %q.", filename)
		}

	case filename.Dir().Base() == "patches":
		NewLineWhole(filename).Warnf("Patch files should be named \"patch-\", followed by letters, '-', '_', '.', and digits only.")

	case (hasPrefix(basename, "Makefile") || hasSuffix(basename, ".mk")) &&
		!G.Pkgsrc.Rel(filename).AsPath().ContainsPath("files"):
		CheckFileMk(filename, pkg)

	case hasPrefix(basename, "PLIST"):
		if lines := Load(filename, NotEmpty|LogErrors); lines != nil {
			CheckLinesPlist(pkg, lines)
		}

	case contains(basename, "README"):
		break

	case hasPrefix(basename, "CHANGES-"):
		// This only checks the file but doesn't register the changes globally.
		_ = p.Pkgsrc.loadDocChangesFromFile(filename)

	case filename.Dir().Base() == "files":
		// Skip files directly in the files/ directory, but not those further down.

	case basename == "spec":
		if !p.Pkgsrc.Rel(filename).HasPrefixPath("regress") {
			NewLineWhole(filename).Warnf("Only packages in regress/ may have spec files.")
		}

	case pkg != nil && pkg.matchesLicenseFile(basename):
		break

	default:
		NewLineWhole(filename).Warnf("Unexpected file found.")
	}
}

func (p *Pkglint) checkRegCvsSubst(filename CurrPath) {
	entries := G.loadCvsEntries(filename)
	entry, found := entries[filename.Base()]
	if !found || entry.Options == "" {
		return
	}

	diag := NewLineWhole(filename)
	diag.Errorf("The CVS keyword substitution must be the default one.")
	diag.Explain(
		"The CVS keyword \\$NetBSD\\$ is used throughout pkgsrc to record",
		"changes to each file.",
		"Based on this information, the bulk builds decide when a package",
		"has to be rebuilt.",
		"",
		"For more information, see",
		"https://www.gnu.org/software/trans-coord/manual/cvs/html_node/Substitution-modes.html.",
		"",
		sprintf("To fix this, run \"cvs admin -kkv %s\"", shquote(filename.Base())))
}

func (p *Pkglint) checkExecutable(filename CurrPath, mode os.FileMode) {
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
func (p *Pkglint) Tool(mklines *MkLines, command string, time ToolTime) (tool *Tool, usable bool) {
	tools := p.tools(mklines)

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
func (p *Pkglint) ToolByVarname(mklines *MkLines, varname string) *Tool {
	return p.tools(mklines).ByVarname(varname)
}

func (p *Pkglint) tools(mklines *MkLines) *Tools {
	if mklines != nil {
		return mklines.Tools
	} else {
		return p.Pkgsrc.Tools
	}
}

func (p *Pkglint) loadCvsEntries(filename CurrPath) map[string]CvsEntry {
	dir := filename.Dir().Clean()
	if dir == p.cvsEntriesDir {
		return p.cvsEntries
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

	p.cvsEntriesDir = dir
	p.cvsEntries = entries
	return entries
}

func (p *Pkglint) Abs(filename CurrPath) CurrPath {
	if !filename.IsAbs() {
		return p.cwd.JoinNoClean(NewRelPath(filename.AsPath())).Clean()
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
