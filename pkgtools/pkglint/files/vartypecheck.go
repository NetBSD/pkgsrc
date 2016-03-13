package main

import (
	"path"
	"strings"
)

type VartypeCheck struct {
	mkline      *MkLine
	line        *Line
	varname     string
	op          MkOperator
	value       string
	valueNovar  string
	comment     string
	listContext bool
	guessed     bool // Whether the type definition is guessed (based on the variable name) or explicitly defined (see vardefs.go).
}

type MkOperator uint8

const (
	opAssign        MkOperator = iota // =
	opAssignShell                     // !=
	opAssignEval                      // :=
	opAssignAppend                    // +=
	opAssignDefault                   // ?=
	opUse                             //
	opUseLoadtime                     //
	opUseMatch                        // Used in the :M operator
)

func NewMkOperator(op string) MkOperator {
	switch op {
	case "=":
		return opAssign
	case "!=":
		return opAssignShell
	case ":=":
		return opAssignEval
	case "+=":
		return opAssignAppend
	case "?=":
		return opAssignDefault
	}
	return opAssign
}

func (op MkOperator) String() string {
	return [...]string{"=", "!=", ":=", "+=", "?=", "use", "use-loadtime", "use-match"}[op]
}

const (
	reEmulPlatform = "" +
		"bitrig|bsdos|cygwin|darwin|dragonfly|freebsd|" +
		"haiku|hpux|interix|irix|linux|mirbsd|netbsd|openbsd|osf1|solaris"
	rePlatformOs = "" +
		"Bitrig|BSDOS|Cygwin|Darwin|DragonFly|FreeBSD|" +
		"Haiku|HPUX|Interix|IRIX|Linux|MirBSD|NetBSD|OpenBSD|OSF1|QNX|SunOS"
	rePlatformArch = "" +
		"alpha|amd64|arc|arm|arm32|cobalt|convex|dreamcast|" +
		"hpcmips|hpcsh|hppa|i386|ia64|" +
		"m68k|m88k|mips|mips64|mips64eb|mips64el|mipseb|mipsel|mipsn32|" +
		"ns32k|pc532|pmax|powerpc|rs6000|s390|sh3eb|sh3el|sparc|sparc64|vax|x86_64"
)

var (
	emulPlatformEnum = enum(strings.Replace(reEmulPlatform, "|", " ", -1))
	platformOsEnum   = enum(strings.Replace(rePlatformOs, "|", " ", -1))
	platformArchEnum = enum(strings.Replace(rePlatformArch, "|", " ", -1))
)

func (cv *VartypeCheck) AwkCommand() {
	if G.opts.DebugUnchecked {
		cv.line.Debug1("Unchecked AWK command: %q", cv.value)
	}
}

func (cv *VartypeCheck) BasicRegularExpression() {
	if G.opts.DebugUnchecked {
		cv.line.Debug1("Unchecked basic regular expression: %q", cv.value)
	}
}

func (cv *VartypeCheck) BuildlinkDepmethod() {
	if !containsVarRef(cv.value) && cv.value != "build" && cv.value != "full" {
		cv.line.Warn1("Invalid dependency method %q. Valid methods are \"build\" or \"full\".", cv.value)
	}
}

func (cv *VartypeCheck) Category() {
	if fileExists(G.CurrentDir + "/" + G.CurPkgsrcdir + "/" + cv.value + "/Makefile") {
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
		cv.line.Error1("Invalid category %q.", cv.value)
	}
}

// A single option to the C/C++ compiler.
func (cv *VartypeCheck) CFlag() {
	if cv.op == opUseMatch {
		return
	}
	cflag := cv.value
	switch {
	case matches(cflag, `^-[DILOUWfgm]`),
		hasPrefix(cflag, "-std="),
		cflag == "-c99",
		cflag == "-c",
		cflag == "-no-integrated-as",
		cflag == "-pthread",
		hasPrefix(cflag, "`") && hasSuffix(cflag, "`"),
		containsVarRef(cflag):
		return
	case hasPrefix(cflag, "-"):
		cv.line.Warn1("Unknown compiler flag %q.", cflag)
	default:
		cv.line.Warn1("Compiler flag %q should start with a hyphen.", cflag)
	}
}

// The single-line description of the package.
func (cv *VartypeCheck) Comment() {
	line, value := cv.line, cv.value

	if value == "TODO: Short description of the package" { // See pkgtools/url2pkg/files/url2pkg.pl, keyword "COMMENT".
		line.Error0("COMMENT must be set.")
	}
	if m, first := match1(value, `^(?i)(a|an)\s`); m {
		line.Warn1("COMMENT should not begin with %q.", first)
	}
	if matches(value, `^[a-z]`) {
		line.Warn0("COMMENT should start with a capital letter.")
	}
	if hasSuffix(value, ".") {
		line.Warn0("COMMENT should not end with a period.")
	}
	if len(value) > 70 {
		line.Warn0("COMMENT should not be longer than 70 characters.")
	}
}

func (cv *VartypeCheck) Dependency() {
	line, value := cv.line, cv.value

	parser := NewParser(line, value)
	deppat := parser.Dependency()
	if deppat != nil && deppat.wildcard == "" && (parser.Rest() == "{,nb*}" || parser.Rest() == "{,nb[0-9]*}") {
		line.Warn0("Dependency patterns of the form pkgbase>=1.0 don't need the \"{,nb*}\" extension.")
		Explain4(
			"The \"{,nb*}\" extension is only necessary for dependencies of the",
			"form \"pkgbase-1.2\", since the pattern \"pkgbase-1.2\" doesn't match",
			"the version \"pkgbase-1.2nb5\".  For dependency patterns using the",
			"comparison operators, this is not necessary.")

	} else if deppat == nil || !parser.EOF() {
		line.Warn1("Unknown dependency pattern %q.", value)
		Explain(
			"Typical dependencies have the following forms:",
			"",
			"\tpackage>=2.5",
			"\tpackage-[0-9]*",
			"\tpackage-3.141",
			"\tpackage>=2.71828<=3.1415")
		return
	}

	wildcard := deppat.wildcard
	if m, inside := match1(wildcard, `^\[(.*)\]\*$`); m {
		if inside != "0-9" {
			line.Warn0("Only [0-9]* is allowed in the numeric part of a dependency.")
		}

	} else if m, ver, suffix := match2(wildcard, `^(\d\w*(?:\.\w+)*)(\.\*|\{,nb\*\}|\{,nb\[0-9\]\*\}|\*|)$`); m {
		if suffix == "" {
			line.Warn2("Please use %q instead of %q as the version pattern.", ver+"{,nb*}", ver)
			Explain3(
				"Without the \"{,nb*}\" suffix, this version pattern only matches",
				"package versions that don't have a PKGREVISION (which is the part",
				"after the \"nb\").")
		}
		if suffix == "*" {
			line.Warn2("Please use %q instead of %q as the version pattern.", ver+".*", ver+"*")
			Explain2(
				"For example, the version \"1*\" also matches \"10.0.0\", which is",
				"probably not intended.")
		}

	} else if wildcard == "*" {
		line.Warn1("Please use \"%[1]s-[0-9]*\" instead of \"%[1]s-*\".", deppat.pkgbase)
		Explain3(
			"If you use a * alone, the package specification may match other",
			"packages that have the same prefix, but a longer name.  For example,",
			"foo-* matches foo-1.2, but also foo-client-1.2 and foo-server-1.2.")
	}

	if nocclasses := regcomp(`\[[\d-]+\]`).ReplaceAllString(wildcard, ""); contains(nocclasses, "-") {
		line.Warn1("The version pattern %q should not contain a hyphen.", wildcard)
		Explain(
			"Pkgsrc interprets package names with version numbers like this:",
			"",
			"\t\"foo-2.0-2.1.x\" => pkgbase \"foo\", version \"2.0-2.1.x\"",
			"",
			"To make the \"2.0\" above part of the package basename, the hyphen",
			"must be omitted, so the full package name becomes \"foo2.0-2.1.x\".")
	}
}

func (cv *VartypeCheck) DependencyWithPath() {
	line, value := cv.line, cv.value
	if value != cv.valueNovar {
		return // It's probably not worth checking this.
	}

	if m, pattern, relpath, pkg := match3(value, `(.*):(\.\./\.\./[^/]+/([^/]+))$`); m {
		cv.mkline.CheckRelativePkgdir(relpath)

		switch pkg {
		case "msgfmt", "gettext":
			line.Warn0("Please use USE_TOOLS+=msgfmt instead of this dependency.")
		case "perl5":
			line.Warn0("Please use USE_TOOLS+=perl:run instead of this dependency.")
		case "gmake":
			line.Warn0("Please use USE_TOOLS+=gmake instead of this dependency.")
		}

		cv.mkline.CheckVartypePrimitive(cv.varname, CheckvarDependency, cv.op, pattern, cv.comment, cv.listContext, cv.guessed)
		return
	}

	if matches(value, `:\.\./[^/]+$`) {
		line.Warn0("Dependencies should have the form \"../../category/package\".")
		cv.mkline.explainRelativeDirs()
		return
	}

	line.Warn1("Unknown dependency pattern with path %q.", value)
	Explain4(
		"Examples for valid dependency patterns with path are:",
		"  package-[0-9]*:../../category/package",
		"  package>=3.41:../../category/package",
		"  package-2.718:../../category/package")
}

func (cv *VartypeCheck) DistSuffix() {
	if cv.value == ".tar.gz" {
		cv.line.Note1("%s is \".tar.gz\" by default, so this definition may be redundant.", cv.varname)
	}
}

func (cv *VartypeCheck) EmulPlatform() {
	const rePart = `(?:\[[^\]]+\]|[^-\[])+`
	const rePair = `^(` + rePart + `)-(` + rePart + `)$`
	if m, opsysPattern, archPattern := match2(cv.value, rePair); m {
		opsysCv := &VartypeCheck{
			cv.mkline,
			cv.line,
			"the operating system part of " + cv.varname,
			cv.op,
			opsysPattern,
			opsysPattern,
			cv.comment,
			cv.listContext,
			cv.guessed}
		emulPlatformEnum.checker(opsysCv)

		// no check for os_version

		archCv := &VartypeCheck{
			cv.mkline,
			cv.line,
			"the hardware architecture part of " + cv.varname,
			cv.op,
			archPattern,
			archPattern,
			cv.comment,
			cv.listContext,
			cv.guessed}
		platformArchEnum.checker(archCv)
	} else {
		cv.line.Warn1("%q is not a valid emulation platform.", cv.value)
		Explain(
			"An emulation platform has the form <OPSYS>-<MACHINE_ARCH>.",
			"OPSYS is the lower-case name of the operating system, and",
			"MACHINE_ARCH is the hardware architecture.",
			"",
			"Examples:",
			"* linux-i386",
			"* irix-mipsel")
	}
}

func (cv *VartypeCheck) FetchURL() {
	cv.mkline.CheckVartypePrimitive(cv.varname, CheckvarURL, cv.op, cv.value, cv.comment, cv.listContext, cv.guessed)

	for siteURL, siteName := range G.globalData.MasterSiteUrls {
		if hasPrefix(cv.value, siteURL) {
			subdir := cv.value[len(siteURL):]
			if hasPrefix(cv.value, "https://github.com/") {
				subdir = strings.SplitAfter(subdir, "/")[0]
				cv.line.Warnf("Please use ${%s:=%s} instead of %q and run \"%s help topic=github\" for further tips.",
					siteName, subdir, cv.value, confMake)
			} else {
				cv.line.Warnf("Please use ${%s:=%s} instead of %q.", siteName, subdir, cv.value)
			}
			return
		}
	}

	if m, name, subdir := match2(cv.value, `\$\{(MASTER_SITE_[^:]*).*:=(.*)\}$`); m {
		if !G.globalData.MasterSiteVars[name] {
			cv.line.Error1("%s does not exist.", name)
		}
		if !hasSuffix(subdir, "/") {
			cv.line.Error1("The subdirectory in %s must end with a slash.", name)
		}
	}
}

// See Pathname
// See http://www.opengroup.org/onlinepubs/009695399/basedefs/xbd_chap03.html#tag_03_169
func (cv *VartypeCheck) Filename() {
	switch {
	case cv.op == opUseMatch:
		break
	case contains(cv.valueNovar, "/"):
		cv.line.Warn0("A filename should not contain a slash.")
	case !matches(cv.valueNovar, `^[-0-9@A-Za-z.,_~+%]*$`):
		cv.line.Warn1("%q is not a valid filename.", cv.value)
	}
}

func (cv *VartypeCheck) Filemask() {
	if cv.op == opUseMatch {
		return
	}
	if !matches(cv.valueNovar, `^[-0-9A-Za-z._~+%*?]*$`) {
		cv.line.Warn1("%q is not a valid filename mask.", cv.value)
	}
}

func (cv *VartypeCheck) FileMode() {
	switch {
	case cv.value != "" && cv.valueNovar == "":
		// Fine.
	case matches(cv.value, `^[0-7]{3,4}`):
		// Fine.
	default:
		cv.line.Warn1("Invalid file mode %q.", cv.value)
	}
}

func (cv *VartypeCheck) Identifier() {
	if cv.op == opUseMatch {
		if cv.value == cv.valueNovar && !matches(cv.value, `^[\w*?]`) {
			cv.line.Warn2("Invalid identifier pattern %q for %s.", cv.value, cv.varname)
		}
		return
	}
	if cv.value != cv.valueNovar {
		//line.logWarning("Identifiers should be given directly.")
	}
	switch {
	case matches(cv.valueNovar, `^[+\-.0-9A-Z_a-z]+$`):
		// Fine.
	case cv.value != "" && cv.valueNovar == "":
		// Don't warn here.
	default:
		cv.line.Warn1("Invalid identifier %q.", cv.value)
	}
}

func (cv *VartypeCheck) Integer() {
	if !matches(cv.value, `^\d+$`) {
		cv.line.Warn1("Invalid integer %q.", cv.value)
	}
}

func (cv *VartypeCheck) LdFlag() {
	if cv.op == opUseMatch {
		return
	}
	ldflag := cv.value
	if m, rpathFlag := match1(ldflag, `^(-Wl,(?:-R|-rpath|--rpath))`); m {
		cv.line.Warn1("Please use \"${COMPILER_RPATH_FLAG}\" instead of %q.", rpathFlag)
		return
	}

	switch {
	case hasPrefix(ldflag, "-L"),
		hasPrefix(ldflag, "-l"),
		ldflag == "-pthread",
		ldflag == "-static",
		hasPrefix(ldflag, "-static-"),
		hasPrefix(ldflag, "-Wl,-"),
		hasPrefix(ldflag, "`") && hasSuffix(ldflag, "`"),
		ldflag != cv.valueNovar:
		return
	case hasPrefix(ldflag, "-"):
		cv.line.Warn1("Unknown linker flag %q.", cv.value)
	default:
		cv.line.Warn1("Linker flag %q should start with a hypen.", cv.value)
	}
}

func (cv *VartypeCheck) License() {
	checklineLicense(cv.mkline, cv.value)
}

func (cv *VartypeCheck) MailAddress() {
	line, value := cv.line, cv.value

	if m, _, domain := match2(value, `^([+\-.0-9A-Z_a-z]+)@([-\w\d.]+)$`); m {
		if strings.EqualFold(domain, "NetBSD.org") && domain != "NetBSD.org" {
			line.Warn1("Please write \"NetBSD.org\" instead of %q.", domain)
		}
		if matches(value, `(?i)^(tech-pkg|packages)@NetBSD\.org$`) {
			line.Error0("This mailing list address is obsolete. Use pkgsrc-users@NetBSD.org instead.")
		}

	} else {
		line.Warn1("\"%s\" is not a valid mail address.", value)
	}
}

// See ${STEP_MSG}, ${PKG_FAIL_REASON}
func (cv *VartypeCheck) Message() {
	line, varname, value := cv.line, cv.varname, cv.value

	if matches(value, `^[\"'].*[\"']$`) {
		line.Warn1("%s should not be quoted.", varname)
		Explain(
			"The quoting is only needed for variables which are interpreted as",
			"multiple words (or, generally speaking, a list of something).  A",
			"single text message does not belong to this class, since it is only",
			"printed as a whole.",
			"",
			"On the other hand, PKG_FAIL_REASON is a _list_ of text messages, so",
			"in that case, the quoting has to be done.")
	}
}

// A package option from options.mk
func (cv *VartypeCheck) Option() {
	line, value, valueNovar := cv.line, cv.value, cv.valueNovar

	if value != valueNovar {
		if G.opts.DebugUnchecked {
			line.Debug1("Unchecked option name: %q", value)
		}
		return
	}

	if m, optname := match1(value, `^-?([a-z][-0-9a-z+]*)$`); m {
		if _, found := G.globalData.PkgOptions[optname]; !found { // There’s a difference between empty and absent here.
			line.Warn1("Unknown option \"%s\".", optname)
			Explain4(
				"This option is not documented in the mk/defaults/options.description",
				"file.  Please think of a brief but precise description and either",
				"update that file yourself or suggest a description for this option",
				"on the tech-pkg@NetBSD.org mailing list.")
		}
		return
	}

	if matches(value, `^-?([a-z][-0-9a-z_\+]*)$`) {
		line.Warn0("Use of the underscore character in option names is deprecated.")
		return
	}

	line.Error1("Invalid option name %q. Option names must start with a lowercase letter and be all-lowercase.", value)
}

// The PATH environment variable
func (cv *VartypeCheck) Pathlist() {
	if !contains(cv.value, ":") && cv.guessed {
		cv.mkline.CheckVartypePrimitive(cv.varname, CheckvarPathname, cv.op, cv.value, cv.comment, cv.listContext, cv.guessed)
		return
	}

	for _, path := range strings.Split(cv.value, ":") {
		if contains(path, "${") {
			continue
		}

		if !matches(path, `^[-0-9A-Za-z._~+%/]*$`) {
			cv.line.Warn1("%q is not a valid pathname.", path)
		}

		if !hasPrefix(path, "/") {
			cv.line.Warn2("All components of %s (in this case %q) should be absolute paths.", cv.varname, path)
		}
	}
}

// Shell globbing including slashes.
// See Filemask
func (cv *VartypeCheck) Pathmask() {
	if cv.op == opUseMatch {
		return
	}
	if !matches(cv.valueNovar, `^[#\-0-9A-Za-z._~+%*?/\[\]]*`) {
		cv.line.Warn1("%q is not a valid pathname mask.", cv.value)
	}
	cv.line.CheckAbsolutePathname(cv.value)
}

// Like Filename, but including slashes
// See http://www.opengroup.org/onlinepubs/009695399/basedefs/xbd_chap03.html#tag_03_266
func (cv *VartypeCheck) Pathname() {
	if cv.op == opUseMatch {
		return
	}
	if !matches(cv.valueNovar, `^[#\-0-9A-Za-z._~+%/]*$`) {
		cv.line.Warn1("%q is not a valid pathname.", cv.value)
	}
	cv.line.CheckAbsolutePathname(cv.value)
}

func (cv *VartypeCheck) Perl5Packlist() {
	if cv.value != cv.valueNovar {
		cv.line.Warn1("%s should not depend on other variables.", cv.varname)
	}
}

func (cv *VartypeCheck) PkgName() {
	if cv.op != opUseMatch && cv.value == cv.valueNovar && !matches(cv.value, rePkgname) {
		cv.line.Warn1("%q is not a valid package name. A valid package name has the form packagename-version, where version consists only of digits, letters and dots.", cv.value)
	}
}

func (cv *VartypeCheck) PkgOptionsVar() {
	cv.mkline.CheckVartypePrimitive(cv.varname, CheckvarVarname, cv.op, cv.value, cv.comment, false, cv.guessed)
	if matches(cv.value, `\$\{PKGBASE[:\}]`) {
		cv.line.Error0("PKGBASE must not be used in PKG_OPTIONS_VAR.")
		Explain3(
			"PKGBASE is defined in bsd.pkg.mk, which is included as the",
			"very last file, but PKG_OPTIONS_VAR is evaluated earlier.",
			"Use ${PKGNAME:C/-[0-9].*//} instead.")
	}
}

// A directory name relative to the top-level pkgsrc directory.
// Despite its name, it is more similar to RelativePkgDir than to RelativePkgPath.
func (cv *VartypeCheck) PkgPath() {
	cv.mkline.CheckRelativePkgdir(G.CurPkgsrcdir + "/" + cv.value)
}

func (cv *VartypeCheck) PkgRevision() {
	if !matches(cv.value, `^[1-9]\d*$`) {
		cv.line.Warn1("%s must be a positive integer number.", cv.varname)
	}
	if path.Base(cv.line.Fname) != "Makefile" {
		cv.line.Error1("%s only makes sense directly in the package Makefile.", cv.varname)
		Explain(
			"Usually, different packages using the same Makefile.common have",
			"different dependencies and will be bumped at different times (e.g.",
			"for shlib major bumps) and thus the PKGREVISIONs must be in the",
			"separate Makefiles.  There is no practical way of having this",
			"information in a commonly used Makefile.")
	}
}

func (cv *VartypeCheck) PlatformPattern() {
	if cv.value != cv.valueNovar {
		return
	}

	const rePart = `(?:\[[^\]]+\]|[^-\[])+`
	const reTriple = `^(` + rePart + `)-(` + rePart + `)-(` + rePart + `)$`
	if m, opsysPattern, _, archPattern := match3(cv.value, reTriple); m {
		opsysCv := &VartypeCheck{
			cv.mkline,
			cv.line,
			"the operating system part of " + cv.varname,
			opUseMatch, // Always allow patterns, since this is a PlatformPattern.
			opsysPattern,
			opsysPattern,
			cv.comment,
			cv.listContext,
			cv.guessed}
		platformOsEnum.checker(opsysCv)

		// no check for os_version

		archCv := &VartypeCheck{
			cv.mkline,
			cv.line,
			"the hardware architecture part of " + cv.varname,
			opUseMatch, // Always allow patterns, since this is a PlatformPattern.
			archPattern,
			archPattern,
			cv.comment,
			cv.listContext,
			cv.guessed}
		platformArchEnum.checker(archCv)

	} else {
		cv.line.Warn1("%q is not a valid platform pattern.", cv.value)
		Explain(
			"A platform pattern has the form <OPSYS>-<OS_VERSION>-<MACHINE_ARCH>.",
			"Each of these components may be a shell globbing expression.",
			"",
			"Examples:",
			"* NetBSD-[456].*-i386",
			"* *-*-*",
			"* Linux-*-*")
	}
}

// A pathname relative to ${PREFIX}.
func (cv *VartypeCheck) PrefixPathname() {
	if m, mansubdir := match1(cv.value, `^man/(.+)`); m {
		cv.line.Warn2("Please use \"${PKGMANDIR}/%s\" instead of %q.", mansubdir, cv.value)
	}
}

func (cv *VartypeCheck) PythonDependency() {
	if cv.value != cv.valueNovar {
		cv.line.Warn0("Python dependencies should not contain variables.")
	} else if !matches(cv.valueNovar, `^[+\-.0-9A-Z_a-z]+(?:|:link|:build)$`) {
		cv.line.Warn1("Invalid Python dependency %q.", cv.value)
		Explain4(
			"Python dependencies must be an identifier for a package, as",
			"specified in lang/python/versioned_dependencies.mk.  This",
			"identifier may be followed by :build for a build-time only",
			"dependency, or by :link for a run-time only dependency.")
	}
}

// Refers to a package directory, e.g. ../../category/pkgbase.
func (cv *VartypeCheck) RelativePkgDir() {
	cv.mkline.CheckRelativePkgdir(cv.value)
}

// Refers to a file or directory, e.g. ../../category/pkgbase, ../../category/pkgbase/Makefile.
func (cv *VartypeCheck) RelativePkgPath() {
	cv.mkline.CheckRelativePath(cv.value, true)
}

func (cv *VartypeCheck) Restricted() {
	if cv.value != "${RESTRICTED}" {
		cv.line.Warn1("The only valid value for %s is ${RESTRICTED}.", cv.varname)
		Explain3(
			"These variables are used to control which files may be mirrored on",
			"FTP servers or CD-ROM collections.  They are not intended to mark",
			"packages whose only MASTER_SITES are on ftp.NetBSD.org.")
	}
}

func (cv *VartypeCheck) SedCommand() {
}

func (cv *VartypeCheck) SedCommands() {
	line := cv.line
	mkline := cv.mkline
	shline := NewShellLine(mkline)

	tokens, rest := splitIntoShellTokens(line, cv.value)
	if rest != "" {
		if strings.Contains(line.Text, "#") {
			line.Error1("Invalid shell words %q in sed commands.", rest)
			Explain4(
				"When sed commands have embedded \"#\" characters, they need to be",
				"escaped with a backslash, otherwise make(1) will interpret them as a",
				"comment, no matter if they occur in single or double quotes or",
				"whatever.")
		}
		return
	}

	ntokens := len(tokens)
	ncommands := 0

	for i := 0; i < ntokens; i++ {
		token := tokens[i]
		shline.CheckToken(token, true)

		switch {
		case token == "-e":
			if i+1 < ntokens {
				// Check the real sed command here.
				i++
				ncommands++
				if ncommands > 1 {
					line.Note0("Each sed command should appear in an assignment of its own.")
					Explain(
						"For example, instead of",
						"    SUBST_SED.foo+=        -e s,command1,, -e s,command2,,",
						"use",
						"    SUBST_SED.foo+=        -e s,command1,,",
						"    SUBST_SED.foo+=        -e s,command2,,",
						"",
						"This way, short sed commands cannot be hidden at the end of a line.")
				}
				shline.CheckToken(tokens[i-1], true)
				shline.CheckToken(tokens[i], true)
				mkline.CheckVartypePrimitive(cv.varname, CheckvarSedCommand, cv.op, tokens[i], cv.comment, cv.listContext, cv.guessed)
			} else {
				line.Error0("The -e option to sed requires an argument.")
			}
		case token == "-E":
			// Switch to extended regular expressions mode.

		case token == "-n":
			// Don't print lines per default.

		case i == 0 && matches(token, `^(["']?)(?:\d*|/.*/)s.+["']?$`):
			line.Note0("Please always use \"-e\" in sed commands, even if there is only one substitution.")

		default:
			line.Warn1("Unknown sed command %q.", token)
		}
	}
}

func (cv *VartypeCheck) ShellCommand() {
	if cv.op == opUseMatch {
		return
	}
	setE := true
	NewShellLine(cv.mkline).CheckShellCommand(cv.value, &setE)
}

// Zero or more shell commands, each terminated with a semicolon.
func (cv *VartypeCheck) ShellCommands() {
	NewShellLine(cv.mkline).CheckShellCommands(cv.value)
}

func (cv *VartypeCheck) ShellWord() {
	if !cv.listContext {
		NewShellLine(cv.mkline).CheckToken(cv.value, true)
	}
}

func (cv *VartypeCheck) Stage() {
	if !matches(cv.value, `^(?:pre|do|post)-(?:extract|patch|configure|build|test|install)`) {
		cv.line.Warn1("Invalid stage name %q. Use one of {pre,do,post}-{extract,patch,configure,build,test,install}.", cv.value)
	}
}

func (cv *VartypeCheck) String() {
	// No further checks possible.
}

func (cv *VartypeCheck) Tool() {
	if cv.varname == "TOOLS_NOOP" && cv.op == opAssignAppend {
		// no warning for package-defined tool definitions

	} else if m, toolname, tooldep := match2(cv.value, `^([-\w]+|\[)(?::(\w+))?$`); m {
		if !G.globalData.Tools[toolname] {
			cv.line.Error1("Unknown tool %q.", toolname)
		}
		switch tooldep {
		case "", "bootstrap", "build", "pkgsrc", "run":
		default:
			cv.line.Error1("Unknown tool dependency %q. Use one of \"build\", \"pkgsrc\" or \"run\".", tooldep)
		}
	} else if cv.op != opUseMatch {
		cv.line.Error1("Invalid tool syntax: %q.", cv.value)
	}
}

func (cv *VartypeCheck) Unchecked() {
	// Do nothing, as the name says.
}

func (cv *VartypeCheck) URL() {
	line, value := cv.line, cv.value

	if value == "" && hasPrefix(cv.comment, "#") {
		// Ok

	} else if containsVarRef(value) {
		// No further checks

	} else if m, _, host, _, _ := match4(value, `^(https?|ftp|gopher)://([-0-9A-Za-z.]+)(?::(\d+))?/([-%&+,./0-9:;=?@A-Z_a-z~]|#)*$`); m {
		if matches(host, `(?i)\.NetBSD\.org$`) && !matches(host, `\.NetBSD\.org$`) {
			line.Warn1("Please write NetBSD.org instead of %s.", host)
		}

	} else if m, scheme, _, absPath := match3(value, `^([0-9A-Za-z]+)://([^/]+)(.*)$`); m {
		switch {
		case scheme != "ftp" && scheme != "http" && scheme != "https" && scheme != "gopher":
			line.Warn1("%q is not a valid URL. Only ftp, gopher, http, and https URLs are allowed here.", value)

		case absPath == "":
			line.Note1("For consistency, please add a trailing slash to %q.", value)

		default:
			line.Warn1("%q is not a valid URL.", value)
		}

	} else {
		line.Warn1("%q is not a valid URL.", value)
	}
}

func (cv *VartypeCheck) UserGroupName() {
	if cv.value == cv.valueNovar && !matches(cv.value, `^[0-9_a-z]+$`) {
		cv.line.Warn1("Invalid user or group name %q.", cv.value)
	}
}

func (cv *VartypeCheck) Varname() {
	if cv.value == cv.valueNovar && !matches(cv.value, `^[A-Z_][0-9A-Z_]*(?:[.].*)?$`) {
		cv.line.Warn1("%q is not a valid variable name.", cv.value)
		Explain(
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
	if cv.op == opUseMatch {
		if !matches(cv.value, `^[\d?\[][\w\-.*?\[\]]+$`) {
			cv.line.Warn1("Invalid version number pattern %q.", cv.value)
		}
	} else if cv.value == cv.valueNovar && !matches(cv.value, `^\d[\w.]+$`) {
		cv.line.Warn1("Invalid version number %q.", cv.value)
	}
}

func (cv *VartypeCheck) WrapperReorder() {
	if !matches(cv.value, `^reorder:l:([\w\-]+):([\w\-]+)$`) {
		cv.line.Warn1("Unknown wrapper reorder command %q.", cv.value)
	}
}

func (cv *VartypeCheck) WrapperTransform() {
	cmd := cv.value
	if hasPrefix(cmd, "rm:-") ||
		matches(cmd, `^(R|l|rpath):([^:]+):(.+)$`) ||
		matches(cmd, `^'?(opt|rename|rm-optarg|rmdir):.*$`) ||
		cmd == "-e" ||
		matches(cmd, `^["']?s[|:,]`) {
		return
	}
	cv.line.Warn1("Unknown wrapper transform command %q.", cmd)
}

func (cv *VartypeCheck) WrkdirSubdirectory() {
	cv.mkline.CheckVartypePrimitive(cv.varname, CheckvarPathname, cv.op, cv.value, cv.comment, cv.listContext, cv.guessed)
}

// A directory relative to ${WRKSRC}, for use in CONFIGURE_DIRS and similar variables.
func (cv *VartypeCheck) WrksrcSubdirectory() {
	if m, _, rest := match2(cv.value, `^(\$\{WRKSRC\})(?:/(.*))?`); m {
		if rest == "" {
			rest = "."
		}
		cv.line.Note2("You can use %q instead of %q.", rest, cv.value)
		Explain1(
			"These directories are interpreted relative to ${WRKSRC}.")

	} else if cv.value != "" && cv.valueNovar == "" {
		// The value of another variable

	} else if !matches(cv.valueNovar, `^(?:\.|[0-9A-Za-z_@][-0-9A-Za-z_@./+]*)$`) {
		cv.line.Warn1("%q is not a valid subdirectory of ${WRKSRC}.", cv.value)
	}
}

func (cv *VartypeCheck) Yes() {
	switch cv.op {
	case opUseMatch:
		cv.line.Warn1("%s should only be used in a \".if defined(...)\" conditional.", cv.varname)
		Explain(
			"This variable can have only two values: defined or undefined.",
			"When it is defined, it means \"yes\", even when its value is",
			"\"no\" or the empty string.",
			"",
			"Therefore, it should not be checked by comparing its value",
			"but using \".if defined(VARNAME)\" alone.")

	default:
		if !matches(cv.value, `^(?:YES|yes)(?:\s+#.*)?$`) {
			cv.line.Warn1("%s should be set to YES or yes.", cv.varname)
			Explain4(
				"This variable means \"yes\" if it is defined, and \"no\" if it is",
				"undefined.  Even when it has the value \"no\", this means \"yes\".",
				"Therefore when it is defined, its value should correspond to its",
				"meaning.")
		}
	}
}

func (cv *VartypeCheck) YesNo() {
	if cv.op == opUseMatch {
		switch cv.value {
		case "[yY][eE][sS]":
		case "[Yy][Ee][Ss]":
		case "[nN][oO]":
		case "[Nn][Oo]":
		default:
			cv.line.Warnf("%s should be matched against %q or %q, not %q.", cv.varname, "[yY][eE][sS]", "[nN][oO]", cv.value)
		}
	} else if !matches(cv.value, `^(?:YES|yes|NO|no)(?:\s+#.*)?$`) {
		cv.line.Warn1("%s should be set to YES, yes, NO, or no.", cv.varname)
	}
}

func (cv *VartypeCheck) YesNoIndirectly() {
	if cv.valueNovar != "" {
		cv.YesNo()
	}
}
