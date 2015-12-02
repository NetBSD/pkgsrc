package main

import (
	"path"
	"strings"
)

type VartypeCheck struct {
	line        *Line
	varname     string
	op          string
	value       string
	valueNovar  string
	comment     string
	listContext bool
	guessed     Guessed
}

func (cv *VartypeCheck) AwkCommand() {
	_ = G.opts.DebugUnchecked && cv.line.debugf("Unchecked AWK command: %q", cv.value)
}

func (cv *VartypeCheck) BasicRegularExpression() {
	_ = G.opts.DebugUnchecked && cv.line.debugf("Unchecked basic regular expression: %q", cv.value)
}

func (cv *VartypeCheck) BuildlinkDepmethod() {
	if !containsVarRef(cv.value) && cv.value != "build" && cv.value != "full" {
		cv.line.warnf("Invalid dependency method %q. Valid methods are \"build\" or \"full\".", cv.value)
	}
}

func (cv *VartypeCheck) Category() {
	if fileExists(G.currentDir + "/" + G.curPkgsrcdir + "/" + cv.value + "/Makefile") {
		return
	}
	switch cv.value {
	case
		"chinese", "crosspkgtools",
		"gnome", "gnustep",
		"japanese", "java",
		"kde", "korean",
		"linux", "local",
		"packages", "perl5", "plan9", "python",
		"ruby",
		"scm",
		"tcl", "tk",
		"windowmaker",
		"xmms":
	default:
		cv.line.errorf("Invalid category %q.", cv.value)
	}
}

// A single option to the C/C++ compiler.
func (cv *VartypeCheck) CFlag() {
	line, value := cv.line, cv.value

	switch {
	case matches(value, `^-[DILOUWfgm]`),
		hasPrefix(value, "-std="),
		value == "-c99":
	case hasPrefix(value, "-"):
		line.warnf("Unknown compiler flag %q.", value)
	case !containsVarRef(value):
		line.warnf("Compiler flag %q should start with a hyphen.", value)
	}
}

// The single-line description of the package.
func (cv *VartypeCheck) Comment() {
	line, value := cv.line, cv.value

	if value == "SHORT_DESCRIPTION_OF_THE_PACKAGE" {
		line.errorf("COMMENT must be set.")
	}
	if m, first := match1(value, `^(?i)(a|an)\s`); m {
		line.warnf("COMMENT should not begin with %q.", first)
	}
	if matches(value, `^[a-z]`) {
		line.warnf("COMMENT should start with a capital letter.")
	}
	if hasSuffix(value, ".") {
		line.warnf("COMMENT should not end with a period.")
	}
	if len(value) > 70 {
		line.warnf("COMMENT should not be longer than 70 characters.")
	}
}

func (cv *VartypeCheck) Dependency() {
	line, value := cv.line, cv.value

	if m, depbase, depop, depversion := match3(value, `^(`+rePkgbase+`)(<|=|>|<=|>=|!=|-)(`+rePkgversion+`)$`); m {
		_, _, _ = depbase, depop, depversion
		return
	}

	if m, depbase, bracket, version, versionWildcard, other := match5(value, `^(`+rePkgbase+`)-(?:\[(.*)\]\*|(\d+(?:\.\d+)*(?:\.\*)?)(\{,nb\*\}|\*|)|(.*))?$`); m {
		switch {
		case bracket != "":
			if bracket != "0-9" {
				line.warnf("Only [0-9]* is allowed in the numeric part of a dependency.")
			}

		case version != "" && versionWildcard != "":
			// Fine.

		case version != "":
			line.warnf("Please append \"{,nb*}\" to the version number of this dependency.")
			line.explain(
				"Usually, a dependency should stay valid when the PKGREVISION is",
				"increased, since those changes are most often editorial. In the",
				"current form, the dependency only matches if the PKGREVISION is",
				"undefined.")

		case other == "*":
			line.warnf("Please use \"%s-[0-9]*\" instead of \"%s-*\".", depbase, depbase)
			line.explain(
				"If you use a * alone, the package specification may match other",
				"packages that have the same prefix, but a longer name. For example,",
				"foo-* matches foo-1.2, but also foo-client-1.2 and foo-server-1.2.")

		default:
			line.errorf("Unknown dependency pattern %q.", value)
		}
		return
	}

	switch {
	case contains(value, "{"):
		// No check yet for alternative dependency patterns.
		_ = G.opts.DebugUnchecked && line.debugf("Unchecked alternative dependency pattern: %s", value)

	case value != cv.valueNovar:
		_ = G.opts.DebugUnchecked && line.debugf("Unchecked dependency: %s", value)

	default:
		line.warnf("Unknown dependency format: %s", value)
		line.explain(
			"Typical dependencies have the following forms:",
			"",
			"* package>=2.5",
			"* package-[0-9]*",
			"* package-3.141")
	}
}

func (cv *VartypeCheck) DependencyWithPath() {
	line, value := cv.line, cv.value
	if value != cv.valueNovar {
		return // It's probably not worth checking this.
	}

	if m, pattern, relpath, _, pkg := match4(value, `(.*):(\.\./\.\./([^/]+)/([^/]+))$`); m {
		checklineRelativePkgdir(line, relpath)

		switch pkg {
		case "msgfmt", "gettext":
			line.warnf("Please use USE_TOOLS+=msgfmt instead of this dependency.")
		case "perl5":
			line.warnf("Please use USE_TOOLS+=perl:run instead of this dependency.")
		case "gmake":
			line.warnf("Please use USE_TOOLS+=gmake instead of this dependency.")
		}

		if !matches(pattern, reDependencyCmp) && !matches(pattern, reDependencyWildcard) {
			line.errorf("Unknown dependency pattern %q.", pattern)
		}
		return
	}

	if matches(value, `:\.\./[^/]+$`) {
		line.warnf("Dependencies should have the form \"../../category/package\".")
		explainRelativeDirs(line)
		return
	}

	line.warnf("Unknown dependency format.")
	line.explain(
		"Examples for valid dependencies are:",
		"  package-[0-9]*:../../category/package",
		"  package>=3.41:../../category/package",
		"  package-2.718:../../category/package")
}

func (cv *VartypeCheck) DistSuffix() {
	if cv.value == ".tar.gz" {
		cv.line.notef("%s is \".tar.gz\" by default, so this definition may be redundant.", cv.varname)
	}
}

func (cv *VartypeCheck) EmulPlatform() {

	if m, opsys, arch := match2(cv.value, `^(\w+)-(\w+)$`); m {
		if !matches(opsys, `^(?:bsdos|cygwin|darwin|dragonfly|freebsd|haiku|hpux|interix|irix|linux|netbsd|openbsd|osf1|sunos|solaris)$`) {
			cv.line.warnf("Unknown operating system: %s", opsys)
		}
		// no check for os_version
		if !matches(arch, `^(?:i386|alpha|amd64|arc|arm|arm32|cobalt|convex|dreamcast|hpcmips|hpcsh|hppa|ia64|m68k|m88k|mips|mips64|mipsel|mipseb|mipsn32|ns32k|pc532|pmax|powerpc|rs6000|s390|sparc|sparc64|vax|x86_64)$`) {
			cv.line.warnf("Unknown hardware architecture: %s", arch)
		}

	} else {
		cv.line.warnf("%q is not a valid emulation platform.", cv.value)
		cv.line.explain(
			"An emulation platform has the form <OPSYS>-<MACHINE_ARCH>.",
			"OPSYS is the lower-case name of the operating system, and MACHINE_ARCH",
			"is the hardware architecture.",
			"",
			"Examples: linux-i386, irix-mipsel.")
	}
}

func (cv *VartypeCheck) FetchURL() {
	checklineMkVartypePrimitive(cv.line, cv.varname, CheckvarURL, cv.op, cv.value, cv.comment, cv.listContext, cv.guessed)

	for siteUrl, siteName := range G.globalData.masterSiteUrls {
		if hasPrefix(cv.value, siteUrl) {
			subdir := cv.value[len(siteUrl):]
			isGithub := hasPrefix(cv.value, "https://github.com/")
			if isGithub {
				subdir = strings.SplitAfter(subdir, "/")[0]
			}
			cv.line.warnf("Please use ${%s:=%s} instead of %q.", siteName, subdir, cv.value)
			if isGithub {
				cv.line.warnf("Run \"%s help topic=github\" for further tips.", confMake)
			}
			return
		}
	}
}

// See Pathname
// See http://www.opengroup.org/onlinepubs/009695399/basedefs/xbd_chap03.html#tag_03_169
func (cv *VartypeCheck) Filename() {
	switch {
	case contains(cv.valueNovar, "/"):
		cv.line.warnf("A filename should not contain a slash.")
	case !matches(cv.valueNovar, `^[-0-9@A-Za-z.,_~+%]*$`):
		cv.line.warnf("%q is not a valid filename.", cv.value)
	}
}

func (cv *VartypeCheck) Filemask() {
	if !matches(cv.valueNovar, `^[-0-9A-Za-z._~+%*?]*$`) {
		cv.line.warnf("%q is not a valid filename mask.", cv.value)
	}
}

func (cv *VartypeCheck) FileMode() {
	switch {
	case cv.value != "" && cv.valueNovar == "":
		// Fine.
	case matches(cv.value, `^[0-7]{3,4}`):
		// Fine.
	default:
		cv.line.warnf("Invalid file mode %q.", cv.value)
	}
}

func (cv *VartypeCheck) Identifier() {
	if cv.value != cv.valueNovar {
		//line.logWarning("Identifiers should be given directly.")
	}
	switch {
	case matches(cv.valueNovar, `^[+\-.0-9A-Z_a-z]+$`):
		// Fine.
	case cv.value != "" && cv.valueNovar == "":
		// Don't warn here.
	default:
		cv.line.warnf("Invalid identifier %q.", cv.value)
	}
}

func (cv *VartypeCheck) Integer() {
	if !matches(cv.value, `^\d+$`) {
		cv.line.warnf("Invalid integer %q.", cv.value)
	}
}

func (cv *VartypeCheck) LdFlag() {
	if matches(cv.value, `^-[Ll]`) || cv.value == "-static" {
		return
	} else if m, rpathFlag := match1(cv.value, `^(-Wl,(?:-R|-rpath|--rpath))`); m {
		cv.line.warnf("Please use ${COMPILER_RPATH_FLAG} instead of %s.", rpathFlag)

	} else if hasPrefix(cv.value, "-") {
		cv.line.warnf("Unknown linker flag %q.", cv.value)

	} else if cv.value == cv.valueNovar {
		cv.line.warnf("Linker flag %q does not start with a dash.", cv.value)
	}
}

func (cv *VartypeCheck) License() {
	checklineLicense(cv.line, cv.value)
}

func (cv *VartypeCheck) MailAddress() {
	line, value := cv.line, cv.value

	if m, _, domain := match2(value, `^([+\-.0-9A-Z_a-z]+)@([-\w\d.]+)$`); m {
		if strings.EqualFold(domain, "NetBSD.org") && domain != "NetBSD.org" {
			line.warnf("Please write \"NetBSD.org\" instead of %q.", domain)
		}
		if matches(value, `(?i)^(tech-pkg|packages)@NetBSD\.org$`) {
			line.errorf("This mailing list address is obsolete. Use pkgsrc-users@NetBSD.org instead.")
		}

	} else {
		line.warnf("\"%s\" is not a valid mail address.", value)
	}
}

// See ${STEP_MSG}, ${PKG_FAIL_REASON}
func (cv *VartypeCheck) Message() {
	line, varname, value := cv.line, cv.varname, cv.value

	if matches(value, `^[\"'].*[\"']$`) {
		line.warnf("%s should not be quoted.", varname)
		line.explain(
			"The quoting is only needed for variables which are interpreted as",
			"multiple words (or, generally speaking, a list of something). A single",
			"text message does not belong to this class, since it is only printed",
			"as a whole.",
			"",
			"On the other hand, PKG_FAIL_REASON is a _list_ of text messages, so in",
			"that case, the quoting has to be done.`")
	}
}

// A package option from options.mk
func (cv *VartypeCheck) Option() {
	line, value, valueNovar := cv.line, cv.value, cv.valueNovar

	if value != valueNovar {
		_ = G.opts.DebugUnchecked && line.debugf("Unchecked option name: %q", value)
		return
	}

	if m, optname := match1(value, `^-?([a-z][-0-9a-z\+]*)$`); m {
		if _, found := G.globalData.pkgOptions[optname]; !found { // There’s a difference between empty and absent here.
			line.warnf("Unknown option \"%s\".", optname)
			line.explain(
				"This option is not documented in the mk/defaults/options.description",
				"file. If this is not a typo, please think of a brief but precise",
				"description and either update that file yourself or ask on the",
				"tech-pkg@NetBSD.org mailing list.")
		}
		return
	}

	if matches(value, `^-?([a-z][-0-9a-z_\+]*)$`) {
		line.warnf("Use of the underscore character in option names is deprecated.")
		return
	}

	line.errorf("Invalid option name.")
}

// The PATH environment variable
func (cv *VartypeCheck) Pathlist() {
	if !contains(cv.value, ":") && cv.guessed == GUESSED {
		checklineMkVartypePrimitive(cv.line, cv.varname, CheckvarPathname, cv.op, cv.value, cv.comment, cv.listContext, cv.guessed)
		return
	}

	for _, path := range strings.Split(cv.value, ":") {
		if contains(path, "${") {
			continue
		}

		if !matches(path, `^[-0-9A-Za-z._~+%/]*$`) {
			cv.line.warnf("%q is not a valid pathname.", path)
		}

		if !hasPrefix(path, "/") {
			cv.line.warnf("All components of %s (in this case %q) should be absolute paths.", cv.varname, path)
		}
	}
}

// Shell globbing including slashes.
// See Filemask
func (cv *VartypeCheck) Pathmask() {
	if !matches(cv.valueNovar, `^[#\-0-9A-Za-z._~+%*?/\[\]]*`) {
		cv.line.warnf("%q is not a valid pathname mask.", cv.value)
	}
	checklineMkAbsolutePathname(cv.line, cv.value)
}

// Like Filename, but including slashes
// See http://www.opengroup.org/onlinepubs/009695399/basedefs/xbd_chap03.html#tag_03_266
func (cv *VartypeCheck) Pathname() {
	if !matches(cv.valueNovar, `^[#\-0-9A-Za-z._~+%/]*$`) {
		cv.line.warnf("%q is not a valid pathname.", cv.value)
	}
	checklineMkAbsolutePathname(cv.line, cv.value)
}

func (cv *VartypeCheck) Perl5Packlist() {
	if cv.value != cv.valueNovar {
		cv.line.warnf("%s should not depend on other variables.", cv.varname)
	}
}

func (cv *VartypeCheck) PkgName() {
	if cv.value == cv.valueNovar && !matches(cv.value, rePkgname) {
		cv.line.warnf("%q is not a valid package name. A valid package name has the form packagename-version, where version consists only of digits, letters and dots.", cv.value)
	}
}

func (cv *VartypeCheck) PkgOptionsVar() {
	checklineMkVartypePrimitive(cv.line, cv.varname, CheckvarVarname, cv.op, cv.value, cv.comment, false, cv.guessed)
	if matches(cv.value, `\$\{PKGBASE[:\}]`) {
		cv.line.errorf("PKGBASE must not be used in PKG_OPTIONS_VAR.")
		cv.line.explain(
			"PKGBASE is defined in bsd.pkg.mk, which is included as the",
			"very last file, but PKG_OPTIONS_VAR is evaluated earlier.",
			"Use ${PKGNAME:C/-[0-9].*//} instead.")
	}
}

// A directory name relative to the top-level pkgsrc directory.
// Despite its name, it is more similar to RelativePkgDir than to RelativePkgPath.
func (cv *VartypeCheck) PkgPath() {
	checklineRelativePkgdir(cv.line, G.curPkgsrcdir+"/"+cv.value)
}

func (cv *VartypeCheck) PkgRevision() {
	if !matches(cv.value, `^[1-9]\d*$`) {
		cv.line.warnf("%s must be a positive integer number.", cv.varname)
	}
	if path.Base(cv.line.fname) != "Makefile" {
		cv.line.errorf("%s only makes sense directly in the package Makefile.", cv.varname)
		cv.line.explain(
			"Usually, different packages using the same Makefile.common have",
			"different dependencies and will be bumped at different times (e.g. for",
			"shlib major bumps) and thus the PKGREVISIONs must be in the separate",
			"Makefiles. There is no practical way of having this information in a",
			"commonly used Makefile.")
	}
}

func (cv *VartypeCheck) PlatformTriple() {
	if cv.value != cv.valueNovar {
		return
	}

	rePart := `(?:\[[^\]]+\]|[^-\[])+`
	reTriple := `^(` + rePart + `)-(` + rePart + `)-(` + rePart + `)$`
	if m, opsys, _, arch := match3(cv.value, reTriple); m {
		if !matches(opsys, `^(?:\*|BSDOS|Cygwin|Darwin|DragonFly|FreeBSD|Haiku|HPUX|Interix|IRIX|Linux|NetBSD|OpenBSD|OSF1|QNX|SunOS)$`) {
			cv.line.warnf("Unknown operating system: %s", opsys)
		}
		// no check for os_version
		if !matches(arch, `^(?:\*|i386|alpha|amd64|arc|arm|arm32|cobalt|convex|dreamcast|hpcmips|hpcsh|hppa|ia64|m68k|m88k|mips|mips64|mipsel|mipseb|mipsn32|ns32k|pc532|pmax|powerpc|rs6000|s390|sparc|sparc64|vax|x86_64)$`) {
			cv.line.warnf("Unknown hardware architecture: %s", arch)
		}

	} else {
		cv.line.warnf("%q is not a valid platform triple.", cv.value)
		cv.line.explain(
			"A platform triple has the form <OPSYS>-<OS_VERSION>-<MACHINE_ARCH>.",
			"Each of these components may be a shell globbing expression.",
			"Examples: NetBSD-*-i386, *-*-*, Linux-*-*.")
	}
}

func (cv *VartypeCheck) PrefixPathname() {
	if m, mansubdir := match1(cv.value, `^man/(.+)`); m {
		cv.line.warnf("Please use \"${PKGMANDIR}/%s\" instead of %q.", mansubdir, cv.value)
	}
}

func (cv *VartypeCheck) PythonDependency() {
	if cv.value != cv.valueNovar {
		cv.line.warnf("Python dependencies should not contain variables.")
	}
	if !matches(cv.valueNovar, `^[+\-.0-9A-Z_a-z]+(?:|:link|:build)$`) {
		cv.line.warnf("Invalid Python dependency %q.", cv.value)
		cv.line.explain(
			"Python dependencies must be an identifier for a package, as specified",
			"in lang/python/versioned_dependencies.mk. This identifier may be",
			"followed by :build for a build-time only dependency, or by :link for",
			"a run-time only dependency.")
	}
}

// Refers to a package directory.
func (cv *VartypeCheck) RelativePkgDir() {
	checklineRelativePkgdir(cv.line, cv.value)
}

// Refers to a file or directory.
func (cv *VartypeCheck) RelativePkgPath() {
	checklineRelativePath(cv.line, cv.value, true)
}

func (cv *VartypeCheck) Restricted() {
	if cv.value != "${RESTRICTED}" {
		cv.line.warnf("The only valid value for %s is ${RESTRICTED}.", cv.varname)
		cv.line.explain(
			"These variables are used to control which files may be mirrored on FTP",
			"servers or CD-ROM collections. They are not intended to mark packages",
			"whose only MASTER_SITES are on ftp.NetBSD.org.")
	}
}

func (cv *VartypeCheck) SedCommand() {
}

func (cv *VartypeCheck) SedCommands() {
	line := cv.line

	words, rest := splitIntoShellwords(line, cv.value)
	if rest != "" {
		if contains(cv.value, "#") {
			line.errorf("Invalid shell words in sed commands.")
			line.explain(
				"When sed commands have embedded \"#\" characters, they need to be",
				"escaped with a backslash, otherwise make(1) will interpret them as a",
				"comment, no matter if they occur in single or double quotes or",
				"whatever.")
		}
		return
	}

	nwords := len(words)
	ncommands := 0

	for i := 0; i < nwords; i++ {
		word := words[i]
		checklineMkShellword(cv.line, word, true)

		switch {
		case word == "-e":
			if i+1 < nwords {
				// Check the real sed command here.
				i++
				ncommands++
				if ncommands > 1 {
					line.notef("Each sed command should appear in an assignment of its own.")
					line.explain(
						"For example, instead of",
						"    SUBST_SED.foo+=        -e s,command1,, -e s,command2,,",
						"use",
						"    SUBST_SED.foo+=        -e s,command1,,",
						"    SUBST_SED.foo+=        -e s,command2,,",
						"",
						"This way, short sed commands cannot be hidden at the end of a line.")
				}
				checklineMkShellword(line, words[i-1], true)
				checklineMkShellword(line, words[i], true)
				checklineMkVartypePrimitive(line, cv.varname, CheckvarSedCommand, cv.op, words[i], cv.comment, cv.listContext, cv.guessed)
			} else {
				line.errorf("The -e option to sed requires an argument.")
			}
		case word == "-E":
			// Switch to extended regular expressions mode.

		case word == "-n":
			// Don't print lines per default.

		case i == 0 && matches(word, `^(["']?)(?:\d*|/.*/)s.+["']?$`):
			line.notef("Please always use \"-e\" in sed commands, even if there is only one substitution.")

		default:
			line.warnf("Unknown sed command %q.", word)
		}
	}
}

func (cv *VartypeCheck) ShellCommand() {
	NewMkShellLine(cv.line).checklineMkShelltext(cv.value)
}

func (cv *VartypeCheck) ShellWord() {
	if !cv.listContext {
		checklineMkShellword(cv.line, cv.value, true)
	}
}

func (cv *VartypeCheck) Stage() {
	if !matches(cv.value, `^(?:pre|do|post)-(?:extract|patch|configure|build|test|install)`) {
		cv.line.warnf("Invalid stage name %q. Use one of {pre,do,post}-{extract,patch,configure,build,test,install}.", cv.value)
	}
}

func (cv *VartypeCheck) String() {
	// No further checks possible.
}

func (cv *VartypeCheck) Tool() {
	if cv.varname == "TOOLS_NOOP" && cv.op == "+=" {
		// no warning for package-defined tool definitions

	} else if m, toolname, tooldep := match2(cv.value, `^([-\w]+|\[)(?::(\w+))?$`); m {
		if !G.globalData.tools[toolname] {
			cv.line.errorf("Unknown tool %q.", toolname)
		}
		switch tooldep {
		case "", "bootstrap", "build", "pkgsrc", "run":
		default:
			cv.line.errorf("Unknown tool dependency %q. Use one of \"build\", \"pkgsrc\" or \"run\".", tooldep)
		}
	} else {
		cv.line.errorf("Invalid tool syntax: %q.", cv.value)
	}
}

func (cv *VartypeCheck) Unchecked() {
	// Do nothing, as the name says.
}

func (cv *VartypeCheck) URL() {
	line, value := cv.line, cv.value

	if value == "" && hasPrefix(cv.comment, "#") {
		// Ok

	} else if m, name, subdir := match2(value, `\$\{(MASTER_SITE_[^:]*).*:=(.*)\}$`); m {
		if !G.globalData.masterSiteVars[name] {
			line.errorf("%s does not exist.", name)
		}
		if !hasSuffix(subdir, "/") {
			line.errorf("The subdirectory in %s must end with a slash.", name)
		}

	} else if containsVarRef(value) {
		// No further checks

	} else if m, _, host, _, _ := match4(value, `^(https?|ftp|gopher)://([-0-9A-Za-z.]+)(?::(\d+))?/([-%&+,./0-9:=?@A-Z_a-z~]|#)*$`); m {
		if matches(host, `(?i)\.NetBSD\.org$`) && !matches(host, `\.NetBSD\.org$`) {
			line.warnf("Please write NetBSD.org instead of %s.", host)
		}

	} else if m, scheme, _, absPath := match3(value, `^([0-9A-Za-z]+)://([^/]+)(.*)$`); m {
		switch {
		case scheme != "ftp" && scheme != "http" && scheme != "https" && scheme != "gopher":
			line.warnf("%q is not a valid URL. Only ftp, gopher, http, and https URLs are allowed here.", value)

		case absPath == "":
			line.notef("For consistency, please add a trailing slash to %q.", value)

		default:
			line.warnf("%q is not a valid URL.", value)
		}

	} else {
		line.warnf("%q is not a valid URL.", value)
	}
}

func (cv *VartypeCheck) UserGroupName() {
	if cv.value == cv.valueNovar && !matches(cv.value, `^[0-9_a-z]+$`) {
		cv.line.warnf("Invalid user or group name %q.", cv.value)
	}
}

func (cv *VartypeCheck) Varname() {
	if cv.value == cv.valueNovar && !matches(cv.value, `^[A-Z_][0-9A-Z_]*(?:[.].*)?$`) {
		cv.line.warnf("%q is not a valid variable name.", cv.value)
		cv.line.explain(
			"Variable names are restricted to only uppercase letters and the",
			"underscore in the basename, and arbitrary characters in the",
			"parameterized part, following the dot.",
			"",
			"Examples:",
			"\t* PKGNAME",
			"\t* PKG_OPTIONS.gnuchess")
	}
}

func (cv *VartypeCheck) Version() {
	if !matches(cv.value, `^([\d.])+$`) {
		cv.line.warnf("Invalid version number %q.", cv.value)
	}
}

func (cv *VartypeCheck) WrapperReorder() {
	if !matches(cv.value, `^reorder:l:([\w\-]+):([\w\-]+)$`) {
		cv.line.warnf("Unknown wrapper reorder command %q.", cv.value)
	}
}

func (cv *VartypeCheck) WrapperTransform() {
	switch {
	case matches(cv.value, `^rm:(?:-[DILOUWflm].*|-std=.*)$`):
	case matches(cv.value, `^l:([^:]+):(.+)$`):
	case matches(cv.value, `^'?(?:opt|rename|rm-optarg|rmdir):.*$`):
	case cv.value == "-e":
	case matches(cv.value, `^\"?'?s[|:,]`):
	default:
		cv.line.warnf("Unknown wrapper transform command %q.", cv.value)
	}
}

func (cv *VartypeCheck) WrkdirSubdirectory() {
	checklineMkVartypePrimitive(cv.line, cv.varname, CheckvarPathname, cv.op, cv.value, cv.comment, cv.listContext, cv.guessed)
}

// A directory relative to ${WRKSRC}, for use in CONFIGURE_DIRS and similar variables.
func (cv *VartypeCheck) WrksrcSubdirectory() {
	if m, _, rest := match2(cv.value, `^(\$\{WRKSRC\})(?:/(.*))?`); m {
		if rest == "" {
			rest = "."
		}
		cv.line.notef("You can use %q instead of %q.", rest, cv.value)

	} else if cv.value != "" && cv.valueNovar == "" {
		// The value of another variable

	} else if !matches(cv.valueNovar, `^(?:\.|[0-9A-Za-z_@][-0-9A-Za-z_@./+]*)$`) {
		cv.line.warnf("%q is not a valid subdirectory of ${WRKSRC}.", cv.value)
	}
}

// Used for variables that are checked using `.if defined(VAR)`.
func (cv *VartypeCheck) Yes() {
	if !matches(cv.value, `^(?:YES|yes)(?:\s+#.*)?$`) {
		cv.line.warnf("%s should be set to YES or yes.", cv.varname)
		cv.line.explain(
			"This variable means \"yes\" if it is defined, and \"no\" if it is",
			"undefined. Even when it has the value \"no\", this means \"yes\".",
			"Therefore when it is defined, its value should correspond to its",
			"meaning.")
	}
}

// The type YesNo is used for variables that are checked using
//     .if defined(VAR) && !empty(VAR:M[Yy][Ee][Ss])
//
func (cv *VartypeCheck) YesNo() {
	if !matches(cv.value, `^(?:YES|yes|NO|no)(?:\s+#.*)?$`) {
		cv.line.warnf("%s should be set to YES, yes, NO, or no.", cv.varname)
	}
}

// Like YesNo, but the value may be produced by a shell command using the
// != operator.
func (cv *VartypeCheck) YesNo_Indirectly() {
	if cv.valueNovar != "" && !matches(cv.value, `^(?:YES|yes|NO|no)(?:\s+#.*)?$`) {
		cv.line.warnf("%s should be set to YES, yes, NO, or no.", cv.varname)
	}
}
