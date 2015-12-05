package main

// based on pkglint.pl 1.896

import (
	"fmt"
	"os"
	"path"
	"strings"
)

const (
	reDependencyCmp      = `^((?:\$\{[\w_]+\}|[\w_\.+]|-[^\d])+)[<>]=?(\d[^-*?\[\]]*)$`
	reDependencyWildcard = `^((?:\$\{[\w_]+\}|[\w_\.+]|-[^\d\[])+)-(?:\[0-9\]\*|\d[^-]*)$`
	reMkCond             = `^\.(\s*)(if|ifdef|ifndef|else|elif|endif|for|endfor|undef)(?:\s+([^\s#][^#]*?))?\s*(?:#.*)?$`
	reMkInclude          = `^\.\s*(s?include)\s+\"([^\"]+)\"\s*(?:#.*)?$`
	reVarassign          = `^ *([-*+A-Z_a-z0-9.${}\[]+?)\s*([!+:?]?=)\s*((?:\\#|[^#])*?)(?:\s*(#.*))?$`
	rePkgname            = `^([\w\-.+]+)-(\d(?:\w|\.\d)*)$`
	rePkgbase            = `(?:[+.\w]|-[A-Z_a-z])+`
	rePkgversion         = `\d(?:\w|\.\d)*`
)

func explainRelativeDirs(line *Line) {
	line.explain(
		"Directories in the form \"../../category/package\" make it easier to",
		"move a package around in pkgsrc, for example from pkgsrc-wip to the",
		"main pkgsrc repository.")
}

// Returns the pkgsrc top-level directory, relative to the given file or directory.
func findPkgsrcTopdir(fname string) string {
	for _, dir := range []string{".", "..", "../..", "../../.."} {
		if fileExists(fname + "/" + dir + "/mk/bsd.pkg.mk") {
			return dir
		}
	}
	return ""
}

func loadPackageMakefile(fname string) []*Line {
	defer tracecall("loadPackageMakefile", fname)()

	var mainLines, allLines []*Line
	if !readMakefile(fname, &mainLines, &allLines) {
		errorf(fname, noLines, "Cannot be read.")
		return nil
	}

	if G.opts.DumpMakefile {
		debugf(G.currentDir, noLines, "Whole Makefile (with all included files) follows:")
		for _, line := range allLines {
			fmt.Printf("%s\n", line.String())
		}
	}

	determineUsedVariables(allLines)

	G.pkgContext.pkgdir = expandVariableWithDefault("PKGDIR", ".")
	G.pkgContext.distinfoFile = expandVariableWithDefault("DISTINFO_FILE", "distinfo")
	G.pkgContext.filesdir = expandVariableWithDefault("FILESDIR", "files")
	G.pkgContext.patchdir = expandVariableWithDefault("PATCHDIR", "patches")

	if varIsDefined("PHPEXT_MK") {
		if !varIsDefined("USE_PHP_EXT_PATCHES") {
			G.pkgContext.patchdir = "patches"
		}
		if varIsDefined("PECL_VERSION") {
			G.pkgContext.distinfoFile = "distinfo"
		}
	}

	_ = G.opts.DebugMisc &&
		dummyLine.debugf("DISTINFO_FILE=%s", G.pkgContext.distinfoFile) &&
		dummyLine.debugf("FILESDIR=%s", G.pkgContext.filesdir) &&
		dummyLine.debugf("PATCHDIR=%s", G.pkgContext.patchdir) &&
		dummyLine.debugf("PKGDIR=%s", G.pkgContext.pkgdir)

	return mainLines
}

func determineUsedVariables(lines []*Line) {
	re := regcomp(`(?:\$\{|\$\(|defined\(|empty\()([0-9+.A-Z_a-z]+)[:})]`)
	for _, line := range lines {
		rest := line.text
		for {
			m := re.FindStringSubmatchIndex(rest)
			if m == nil {
				break
			}
			varname := rest[m[2]:m[3]]
			useVar(line, varname)
			rest = rest[:m[0]] + rest[m[1]:]
		}
	}
}

func extractUsedVariables(line *Line, text string) []string {
	re := regcomp(`^(?:[^\$]+|\$[\$*<>?@]|\$\{([.0-9A-Z_a-z]+)(?::(?:[^\${}]|\$[^{])+)?\})`)
	rest := text
	var result []string
	for {
		m := re.FindStringSubmatchIndex(rest)
		if m == nil {
			break
		}
		varname := rest[negToZero(m[2]):negToZero(m[3])]
		rest = rest[:m[0]] + rest[m[1]:]
		if varname != "" {
			result = append(result, varname)
		}
	}

	if rest != "" {
		_ = G.opts.DebugMisc && line.debugf("extractUsedVariables: rest=%q", rest)
	}
	return result
}

// Returns the type of the variable (maybe guessed based on the variable name),
// or nil if the type cannot even be guessed.
func getVariableType(line *Line, varname string) *Vartype {

	if vartype := G.globalData.vartypes[varname]; vartype != nil {
		return vartype
	}
	if vartype := G.globalData.vartypes[varnameCanon(varname)]; vartype != nil {
		return vartype
	}

	if G.globalData.varnameToToolname[varname] != "" {
		return &Vartype{lkNone, CheckvarShellCommand, []AclEntry{{"*", "u"}}, guNotGuessed}
	}

	if m, toolvarname := match1(varname, `^TOOLS_(.*)`); m && G.globalData.varnameToToolname[toolvarname] != "" {
		return &Vartype{lkNone, CheckvarPathname, []AclEntry{{"*", "u"}}, guNotGuessed}
	}

	allowAll := []AclEntry{{"*", "adpsu"}}
	allowRuntime := []AclEntry{{"*", "adsu"}}

	// Guess the datatype of the variable based on naming conventions.
	var gtype *Vartype
	switch {
	case hasSuffix(varname, "DIRS"):
		gtype = &Vartype{lkShell, CheckvarPathmask, allowRuntime, guGuessed}
	case hasSuffix(varname, "DIR"), hasSuffix(varname, "_HOME"):
		gtype = &Vartype{lkNone, CheckvarPathname, allowRuntime, guGuessed}
	case hasSuffix(varname, "FILES"):
		gtype = &Vartype{lkShell, CheckvarPathmask, allowRuntime, guGuessed}
	case hasSuffix(varname, "FILE"):
		gtype = &Vartype{lkNone, CheckvarPathname, allowRuntime, guGuessed}
	case hasSuffix(varname, "PATH"):
		gtype = &Vartype{lkNone, CheckvarPathlist, allowRuntime, guGuessed}
	case hasSuffix(varname, "PATHS"):
		gtype = &Vartype{lkShell, CheckvarPathname, allowRuntime, guGuessed}
	case hasSuffix(varname, "_USER"):
		gtype = &Vartype{lkNone, CheckvarUserGroupName, allowAll, guGuessed}
	case hasSuffix(varname, "_GROUP"):
		gtype = &Vartype{lkNone, CheckvarUserGroupName, allowAll, guGuessed}
	case hasSuffix(varname, "_ENV"):
		gtype = &Vartype{lkShell, CheckvarShellWord, allowRuntime, guGuessed}
	case hasSuffix(varname, "_CMD"):
		gtype = &Vartype{lkNone, CheckvarShellCommand, allowRuntime, guGuessed}
	case hasSuffix(varname, "_ARGS"):
		gtype = &Vartype{lkShell, CheckvarShellWord, allowRuntime, guGuessed}
	case hasSuffix(varname, "_CFLAGS"), hasSuffix(varname, "_CPPFLAGS"), hasSuffix(varname, "_CXXFLAGS"), hasSuffix(varname, "_LDFLAGS"):
		gtype = &Vartype{lkShell, CheckvarShellWord, allowRuntime, guGuessed}
	case hasSuffix(varname, "_MK"):
		gtype = &Vartype{lkNone, CheckvarUnchecked, allowAll, guGuessed}
	case hasPrefix(varname, "PLIST."):
		gtype = &Vartype{lkNone, CheckvarYes, allowAll, guGuessed}
	}

	if gtype != nil {
		_ = G.opts.DebugVartypes && line.debugf("The guessed type of %q is %v.", varname, gtype)
	} else {
		_ = G.opts.DebugVartypes && line.debugf("No type definition found for %q.", varname)
	}
	return gtype
}

func resolveVariableRefs(text string) string {
	defer tracecall("resolveVariableRefs", text)()

	visited := make(map[string]bool) // To prevent endless loops

	str := text
	for {
		replaced := regcomp(`\$\{([\w.]+)\}`).ReplaceAllStringFunc(str, func(m string) string {
			varname := m[2 : len(m)-1]
			if !visited[varname] {
				visited[varname] = true
				if ctx := G.pkgContext; ctx != nil {
					if value, ok := ctx.varValue(varname); ok {
						return value
					}
				}
				if ctx := G.mkContext; ctx != nil {
					if value, ok := ctx.varValue(varname); ok {
						return value
					}
				}
			}
			return sprintf("${%s}", varname)
		})
		if replaced == str {
			return replaced
		}
		str = replaced
	}
}

func expandVariableWithDefault(varname, defaultValue string) string {
	line := G.pkgContext.vardef[varname]
	if line == nil {
		return defaultValue
	}

	value := line.extra["value"].(string)
	value = resolveVarsInRelativePath(value, true)
	if containsVarRef(value) {
		value = resolveVariableRefs(value)
	}
	_ = G.opts.DebugMisc && line.debugf("Expanded %q to %q", varname, value)
	return value
}

func getVariablePermissions(line *Line, varname string) string {
	if vartype := getVariableType(line, varname); vartype != nil {
		return vartype.effectivePermissions(line.fname)
	}

	_ = G.opts.DebugMisc && line.debugf("No type definition found for %q.", varname)
	return "adpsu"
}

func checklineLength(line *Line, maxlength int) {
	if len(line.text) > maxlength {
		line.warnf("Line too long (should be no more than %d characters).", maxlength)
		line.explain(
			"Back in the old time, terminals with 80x25 characters were common.",
			"And this is still the default size of many terminal emulators.",
			"Moderately short lines also make reading easier.")
	}
}

func checklineValidCharacters(line *Line, reChar string) {
	rest := regcomp(reChar).ReplaceAllString(line.text, "")
	if rest != "" {
		uni := ""
		for _, c := range rest {
			uni += sprintf(" %U", c)
		}
		line.warnf("Line contains invalid characters (%s).", uni[1:])
	}
}

func checklineValidCharactersInValue(line *Line, reValid string) {
	varname := line.extra["varname"].(string)
	value := line.extra["value"].(string)
	rest := regcomp(reValid).ReplaceAllString(value, "")
	if rest != "" {
		uni := ""
		for _, c := range rest {
			uni += sprintf(" %U", c)
		}
		line.warnf("%s contains invalid characters (%s).", varname, uni[1:])
	}
}

func checklineTrailingWhitespace(line *Line) {
	if hasSuffix(line.text, " ") || hasSuffix(line.text, "\t") {
		line.notef("Trailing white-space.")
		line.explain(
			"When a line ends with some white-space, that space is in most cases",
			"irrelevant and can be removed.")
		line.replaceRegex(`\s+\n$`, "\n")
	}
}

func checklineRcsid(line *Line, prefixRe, suggestedPrefix string) bool {
	defer tracecall("checklineRcsid", prefixRe, suggestedPrefix)()

	if !matches(line.text, `^`+prefixRe+`\$NetBSD(?::[^\$]+)?\$$`) {
		line.errorf("Expected %q.", suggestedPrefix+"$"+"NetBSD$")
		line.explain(
			"Several files in pkgsrc must contain the CVS Id, so that their current",
			"version can be traced back later from a binary package. This is to",
			"ensure reproducible builds, for example for finding bugs.")
		line.insertBefore(suggestedPrefix + "$" + "NetBSD$")
		return false
	}
	return true
}

func checklineRelativePath(line *Line, path string, mustExist bool) {
	if !G.isWip && contains(path, "/wip/") {
		line.errorf("A main pkgsrc package must not depend on a pkgsrc-wip package.")
	}

	resolvedPath := resolveVarsInRelativePath(path, true)
	if containsVarRef(resolvedPath) {
		return
	}

	abs := ifelseStr(hasPrefix(resolvedPath, "/"), "", G.currentDir+"/") + resolvedPath
	if _, err := os.Stat(abs); err != nil {
		if mustExist {
			line.errorf("%q does not exist.", resolvedPath)
		}
		return
	}

	switch {
	case matches(path, `^\.\./\.\./[^/]+/[^/]`):
	case hasPrefix(path, "../../mk/"):
		// There need not be two directory levels for mk/ files.
	case matches(path, `^\.\./mk/`) && G.curPkgsrcdir == "..":
		// That's fine for category Makefiles.
	case matches(path, `^\.\.`):
		line.warnf("Invalid relative path %q.", path)
	}
}

func checkfileExtra(fname string) {
	defer tracecall("checkfileExtra", fname)()

	if lines := LoadNonemptyLines(fname, false); lines != nil {
		checklinesTrailingEmptyLines(lines)
	}
}

func checklinesMessage(lines []*Line) {
	defer tracecall("checklinesMessage", lines[0].fname)()

	explanation := []string{
		"A MESSAGE file should consist of a header line, having 75 \"=\"",
		"characters, followed by a line containing only the RCS Id, then an",
		"empty line, your text and finally the footer line, which is the",
		"same as the header line."}

	if len(lines) < 3 {
		lastLine := lines[len(lines)-1]
		lastLine.warnf("File too short.")
		lastLine.explain(explanation...)
		return
	}

	hline := strings.Repeat("=", 75)
	if line := lines[0]; line.text != hline {
		line.warnf("Expected a line of exactly 75 \"=\" characters.")
		line.explain(explanation...)
	}
	checklineRcsid(lines[1], ``, "")
	for _, line := range lines {
		checklineLength(line, 80)
		checklineTrailingWhitespace(line)
		checklineValidCharacters(line, `[\t -~]`)
	}
	if lastLine := lines[len(lines)-1]; lastLine.text != hline {
		lastLine.warnf("Expected a line of exactly 75 \"=\" characters.")
		lastLine.explain(explanation...)
	}
	checklinesTrailingEmptyLines(lines)
}

func checklineRelativePkgdir(line *Line, pkgdir string) {
	checklineRelativePath(line, pkgdir, true)
	pkgdir = resolveVarsInRelativePath(pkgdir, false)

	if m, otherpkgpath := match1(pkgdir, `^(?:\./)?\.\./\.\./([^/]+/[^/]+)$`); m {
		if !fileExists(G.globalData.pkgsrcdir + "/" + otherpkgpath + "/Makefile") {
			line.errorf("There is no package in %q.", otherpkgpath)
		}

	} else {
		line.warnf("%q is not a valid relative package directory.", pkgdir)
		line.explain(
			"A relative pathname always starts with \"../../\", followed",
			"by a category, a slash and a the directory name of the package.",
			"For example, \"../../misc/screen\" is a valid relative pathname.")
	}
}

func checkfileMk(fname string) {
	defer tracecall("checkfileMk", fname)()

	lines := LoadNonemptyLines(fname, true)
	if lines == nil {
		return
	}

	ParselinesMk(lines)
	ChecklinesMk(lines)
	saveAutofixChanges(lines)
}

func checkfile(fname string) {
	defer tracecall("checkfile", fname)()

	basename := path.Base(fname)
	if matches(basename, `^(?:work.*|.*~|.*\.orig|.*\.rej)$`) {
		if G.opts.Import {
			errorf(fname, noLines, "Must be cleaned up before committing the package.")
		}
		return
	}

	st, err := os.Lstat(fname)
	if err != nil {
		errorf(fname, noLines, "%s", err)
		return
	}

	if st.Mode().IsRegular() && st.Mode().Perm()&0111 != 0 && !isCommitted(fname) {
		line := NewLine(fname, noLines, "", nil)
		line.warnf("Should not be executable.")
		line.explain(
			"No package file should ever be executable. Even the INSTALL and",
			"DEINSTALL scripts are usually not usable in the form they have in the",
			"package, as the pathnames get adjusted during installation. So there is",
			"no need to have any file executable.")
	}

	switch {
	case st.Mode().IsDir():
		switch {
		case basename == "files" || basename == "patches" || basename == "CVS":
			// Ok
		case matches(fname, `(?:^|/)files/[^/]*$`):
			// Ok
		case !isEmptyDir(fname):
			warnf(fname, noLines, "Unknown directory name.")
		}

	case st.Mode()&os.ModeSymlink != 0:
		if !matches(basename, `^work`) {
			warnf(fname, noLines, "Unknown symlink name.")
		}

	case !st.Mode().IsRegular():
		errorf(fname, noLines, "Only files and directories are allowed in pkgsrc.")

	case basename == "ALTERNATIVES":
		if G.opts.CheckAlternatives {
			checkfileExtra(fname)
		}

	case basename == "buildlink3.mk":
		if G.opts.CheckBuildlink3 {
			if lines := LoadNonemptyLines(fname, true); lines != nil {
				checklinesBuildlink3Mk(lines)
			}
		}

	case hasPrefix(basename, "DESCR"):
		if G.opts.CheckDescr {
			if lines := LoadNonemptyLines(fname, false); lines != nil {
				checklinesDescr(lines)
			}
		}

	case hasPrefix(basename, "distinfo"):
		if G.opts.CheckDistinfo {
			if lines := LoadNonemptyLines(fname, false); lines != nil {
				checklinesDistinfo(lines)
			}
		}

	case basename == "DEINSTALL" || basename == "INSTALL":
		if G.opts.CheckInstall {
			checkfileExtra(fname)
		}

	case hasPrefix(basename, "MESSAGE"):
		if G.opts.CheckMessage {
			if lines := LoadNonemptyLines(fname, false); lines != nil {
				checklinesMessage(lines)
			}
		}

	case matches(basename, `^patch-[-A-Za-z0-9_.~+]*[A-Za-z0-9_]$`):
		if G.opts.CheckPatches {
			if lines := LoadNonemptyLines(fname, false); lines != nil {
				checklinesPatch(lines)
			}
		}

	case matches(fname, `(?:^|/)patches/manual[^/]*$`):
		if G.opts.DebugUnchecked {
			debugf(fname, noLines, "Unchecked file %q.", fname)
		}

	case matches(fname, `(?:^|/)patches/[^/]*$`):
		warnf(fname, noLines, "Patch files should be named \"patch-\", followed by letters, '-', '_', '.', and digits only.")

	case matches(basename, `^(?:.*\.mk|Makefile.*)$`) && !matches(fname, `files/`) && !matches(fname, `patches/`):
		if G.opts.CheckMk {
			checkfileMk(fname)
		}

	case hasPrefix(basename, "PLIST"):
		if G.opts.CheckPlist {
			if lines := LoadNonemptyLines(fname, false); lines != nil {
				checklinesPlist(lines)
			}
		}

	case basename == "TODO" || basename == "README":
		// Ok

	case hasPrefix(basename, "CHANGES-"):
		// This only checks the file, but doesn’t register the changes globally.
		G.globalData.loadDocChangesFromFile(fname)

	case matches(fname, `(?:^|/)files/[^/]*$`):
		// Skip

	default:
		warnf(fname, noLines, "Unexpected file found.")
		if G.opts.CheckExtra {
			checkfileExtra(fname)
		}
	}
}

func checklinesTrailingEmptyLines(lines []*Line) {
	max := len(lines)
	last := max
	for last > 1 && lines[last-1].text == "" {
		last--
	}
	if last != max {
		lines[last].notef("Trailing empty lines.")
	}
}

func matchVarassign(text string) (m bool, varname, op, value, comment string) {
	if contains(text, "=") {
		m, varname, op, value, comment = match4(text, reVarassign)
	}
	return
}
