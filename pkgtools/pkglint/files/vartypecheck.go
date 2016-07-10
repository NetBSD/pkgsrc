package main

import (
	"path"
	"sort"
	"strings"
)

type VartypeCheck struct {
	MkLine     *MkLine
	Line       *Line
	Varname    string
	Op         MkOperator
	Value      string
	ValueNoVar string
	MkComment  string
	Guessed    bool // Whether the type definition is guessed (based on the variable name) or explicitly defined (see vardefs.go).
}

type MkOperator uint8

const (
	opAssign        MkOperator = iota // =
	opAssignShell                     // !=
	opAssignEval                      // :=
	opAssignAppend                    // +=
	opAssignDefault                   // ?=
	opUse                             //
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
	reMachineOpsys = "" + // See mk/platform
		"AIX|BSDOS|Bitrig|Cygwin|Darwin|DragonFly|FreeBSD|FreeMiNT|GNUkFreeBSD|" +
		"HPUX|Haiku|IRIX|Interix|Linux|Minix|MirBSD|NetBSD|OSF1|OpenBSD|QNX|SCO_SV|SunOS|UnixWare"

	// See mk/emulator/emulator-vars.mk.
	reEmulOpsys = "" +
		"bitrig|bsdos|cygwin|darwin|dragonfly|freebsd|" +
		"haiku|hpux|interix|irix|linux|mirbsd|netbsd|openbsd|osf1|solaris|sunos"

	// Hardware architectures having the same name in bsd.own.mk and the GNU world.
	// These are best-effort guesses, since they depend on the operating system.
	reArch = "" +
		"aarch64|alpha|amd64|arc|arm|cobalt|convex|dreamcast|i386|" +
		"hpcmips|hpcsh|hppa|hppa64|ia64|" +
		"m68k|m88k|mips|mips64|mips64el|mipseb|mipsel|mipsn32|mlrisc|" +
		"ns32k|pc532|pmax|powerpc|powerpc64|rs6000|s390|sparc|sparc64|vax|x86_64"

	// See mk/bsd.prefs.mk:/^GNU_ARCH\./
	reMachineArch = "" +
		reArch + "|" +
		"aarch64eb|amd64|arm26|arm32|coldfire|earm|earmeb|earmhf|earmhfeb|earmv4|earmv4eb|earmv5|" +
		"earmv5eb|earmv6|earmv6eb|earmv6hf|earmv6hfeb|earmv7|earmv7eb|earmv7hf|earmv7hfeb|evbarm|" +
		"i386|i586|i686|m68000|mips|mips64eb|sh3eb|sh3el"

	// See mk/bsd.prefs.mk:/^GNU_ARCH\./
	reMachineGnuArch = "" +
		reArch + "|" +
		"aarch64_be|arm|armeb|armv4|armv4eb|armv6|armv6eb|armv7|armv7eb|" +
		"i486|m5407|m68010|mips64|mipsel|sh|shle|x86_64"

	reEmulArch = reMachineArch // Just a wild guess.
)

func enumFromRe(re string) *VarChecker {
	values := strings.Split(re, "|")
	sort.Strings(values)
	seen := make(map[string]bool)
	var unique []string
	for _, value := range values {
		if !seen[value] {
			seen[value] = true
			unique = append(unique, value)
		}
	}
	return enum(strings.Join(unique, " "))
}

var (
	enumMachineOpsys            = enumFromRe(reMachineOpsys)
	enumMachineArch             = enumFromRe(reMachineArch)
	enumMachineGnuArch          = enumFromRe(reMachineGnuArch)
	enumEmulOpsys               = enumFromRe(reEmulOpsys)
	enumEmulArch                = enumFromRe(reEmulArch)
	enumMachineGnuPlatformOpsys = enumEmulOpsys
)

func (cv *VartypeCheck) AwkCommand() {
	if G.opts.Debug {
		traceStep1("Unchecked AWK command: %q", cv.Value)
	}
}

func (cv *VartypeCheck) BasicRegularExpression() {
	if G.opts.Debug {
		traceStep1("Unchecked basic regular expression: %q", cv.Value)
	}
}

func (cv *VartypeCheck) BuildlinkDepmethod() {
	if !containsVarRef(cv.Value) && cv.Value != "build" && cv.Value != "full" {
		cv.Line.Warn1("Invalid dependency method %q. Valid methods are \"build\" or \"full\".", cv.Value)
	}
}

func (cv *VartypeCheck) Category() {
	if cv.Value != "wip" && fileExists(G.CurrentDir+"/"+G.CurPkgsrcdir+"/"+cv.Value+"/Makefile") {
		return
	}
	switch cv.Value {
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
		cv.Line.Error1("Invalid category %q.", cv.Value)
	}
}

// A single option to the C/C++ compiler.
func (cv *VartypeCheck) CFlag() {
	if cv.Op == opUseMatch {
		return
	}
	cflag := cv.Value
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
		cv.Line.Warn1("Unknown compiler flag %q.", cflag)
	default:
		cv.Line.Warn1("Compiler flag %q should start with a hyphen.", cflag)
	}
}

// The single-line description of the package.
func (cv *VartypeCheck) Comment() {
	line, value := cv.Line, cv.Value

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
	line, value := cv.Line, cv.Value

	parser := NewParser(line, value, false)
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
	line, value := cv.Line, cv.Value
	if value != cv.ValueNoVar {
		return // It's probably not worth checking this.
	}

	if m, pattern, relpath, pkg := match3(value, `(.*):(\.\./\.\./[^/]+/([^/]+))$`); m {
		cv.MkLine.CheckRelativePkgdir(relpath)

		switch pkg {
		case "msgfmt", "gettext":
			line.Warn0("Please use USE_TOOLS+=msgfmt instead of this dependency.")
		case "perl5":
			line.Warn0("Please use USE_TOOLS+=perl:run instead of this dependency.")
		case "gmake":
			line.Warn0("Please use USE_TOOLS+=gmake instead of this dependency.")
		}

		cv.MkLine.CheckVartypePrimitive(cv.Varname, CheckvarDependency, cv.Op, pattern, cv.MkComment, cv.Guessed)
		return
	}

	if matches(value, `:\.\./[^/]+$`) {
		line.Warn0("Dependencies should have the form \"../../category/package\".")
		cv.MkLine.explainRelativeDirs()
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
	if cv.Value == ".tar.gz" {
		cv.Line.Note1("%s is \".tar.gz\" by default, so this definition may be redundant.", cv.Varname)
	}
}

func (cv *VartypeCheck) EmulPlatform() {
	const rePart = `(?:\[[^\]]+\]|[^-\[])+`
	const rePair = `^(` + rePart + `)-(` + rePart + `)$`
	if m, opsysPattern, archPattern := match2(cv.Value, rePair); m {
		opsysCv := &VartypeCheck{
			cv.MkLine,
			cv.Line,
			"the operating system part of " + cv.Varname,
			cv.Op,
			opsysPattern,
			opsysPattern,
			cv.MkComment,
			cv.Guessed}
		enumEmulOpsys.checker(opsysCv)

		// no check for os_version

		archCv := &VartypeCheck{
			cv.MkLine,
			cv.Line,
			"the hardware architecture part of " + cv.Varname,
			cv.Op,
			archPattern,
			archPattern,
			cv.MkComment,
			cv.Guessed}
		enumEmulArch.checker(archCv)
	} else {
		cv.Line.Warn1("%q is not a valid emulation platform.", cv.Value)
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
	cv.MkLine.CheckVartypePrimitive(cv.Varname, CheckvarURL, cv.Op, cv.Value, cv.MkComment, cv.Guessed)

	for siteURL, siteName := range G.globalData.MasterSiteURLToVar {
		if hasPrefix(cv.Value, siteURL) {
			subdir := cv.Value[len(siteURL):]
			if hasPrefix(cv.Value, "https://github.com/") {
				subdir = strings.SplitAfter(subdir, "/")[0]
				cv.Line.Warnf("Please use ${%s:=%s} instead of %q and run \"%s help topic=github\" for further tips.",
					siteName, subdir, cv.Value, confMake)
			} else {
				cv.Line.Warnf("Please use ${%s:=%s} instead of %q.", siteName, subdir, cv.Value)
			}
			return
		}
	}

	if m, name, subdir := match2(cv.Value, `\$\{(MASTER_SITE_[^:]*).*:=(.*)\}$`); m {
		if G.globalData.MasterSiteVarToURL[name] == "" {
			cv.Line.Error1("The site %s does not exist.", name)
		}
		if !hasSuffix(subdir, "/") {
			cv.Line.Error1("The subdirectory in %s must end with a slash.", name)
		}
	}
}

// See Pathname
// See http://www.opengroup.org/onlinepubs/009695399/basedefs/xbd_chap03.html#tag_03_169
func (cv *VartypeCheck) Filename() {
	switch {
	case cv.Op == opUseMatch:
		break
	case contains(cv.ValueNoVar, "/"):
		cv.Line.Warn0("A filename should not contain a slash.")
	case !matches(cv.ValueNoVar, `^[-0-9@A-Za-z.,_~+%]*$`):
		cv.Line.Warn1("%q is not a valid filename.", cv.Value)
	}
}

func (cv *VartypeCheck) Filemask() {
	if cv.Op == opUseMatch {
		return
	}
	if !matches(cv.ValueNoVar, `^[-0-9A-Za-z._~+%*?]*$`) {
		cv.Line.Warn1("%q is not a valid filename mask.", cv.Value)
	}
}

func (cv *VartypeCheck) FileMode() {
	switch {
	case cv.Value != "" && cv.ValueNoVar == "":
		// Fine.
	case matches(cv.Value, `^[0-7]{3,4}`):
		// Fine.
	default:
		cv.Line.Warn1("Invalid file mode %q.", cv.Value)
	}
}

func (cv *VartypeCheck) Homepage() {
	cv.MkLine.CheckVartypePrimitive(cv.Varname, CheckvarURL, cv.Op, cv.Value, cv.MkComment, cv.Guessed)

	if m, wrong, sitename, subdir := match3(cv.Value, `^(\$\{(MASTER_SITE\w+)(?::=([\w\-/]+))?\})`); m {
		baseURL := G.globalData.MasterSiteVarToURL[sitename]
		if sitename == "MASTER_SITES" && G.Pkg != nil {
			masterSites, _ := G.Pkg.varValue("MASTER_SITES")
			if !containsVarRef(masterSites) {
				baseURL = masterSites
			}
		}
		fixedURL := baseURL + subdir
		explain := false
		if baseURL != "" {
			if !cv.Line.AutofixReplace(wrong, fixedURL) {
				cv.Line.Warn1("HOMEPAGE should not be defined in terms of MASTER_SITEs. Use %s directly.", fixedURL)
				explain = true
			}
		} else {
			cv.Line.Warn0("HOMEPAGE should not be defined in terms of MASTER_SITEs.")
			explain = true
		}
		if explain {
			Explain(
				"The HOMEPAGE is a single URL, while MASTER_SITES is a list of URLs.",
				"As long as this list has exactly one element, this works, but as",
				"soon as another site is added, the HOMEPAGE would not be a valid",
				"URL anymore.",
				"",
				"Defining MASTER_SITES=${HOMEPAGE} is ok, though.")
		}
	}
}

func (cv *VartypeCheck) Identifier() {
	if cv.Op == opUseMatch {
		if cv.Value == cv.ValueNoVar && !matches(cv.Value, `^[\w*?]`) {
			cv.Line.Warn2("Invalid identifier pattern %q for %s.", cv.Value, cv.Varname)
		}
		return
	}
	if cv.Value != cv.ValueNoVar {
		//line.logWarning("Identifiers should be given directly.")
	}
	switch {
	case matches(cv.ValueNoVar, `^[+\-.0-9A-Z_a-z]+$`):
		// Fine.
	case cv.Value != "" && cv.ValueNoVar == "":
		// Don't warn here.
	default:
		cv.Line.Warn1("Invalid identifier %q.", cv.Value)
	}
}

func (cv *VartypeCheck) Integer() {
	if !matches(cv.Value, `^\d+$`) {
		cv.Line.Warn1("Invalid integer %q.", cv.Value)
	}
}

func (cv *VartypeCheck) LdFlag() {
	if cv.Op == opUseMatch {
		return
	}
	ldflag := cv.Value
	if m, rpathFlag := match1(ldflag, `^(-Wl,(?:-R|-rpath|--rpath))`); m {
		cv.Line.Warn1("Please use \"${COMPILER_RPATH_FLAG}\" instead of %q.", rpathFlag)
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
		ldflag != cv.ValueNoVar:
		return
	case hasPrefix(ldflag, "-"):
		cv.Line.Warn1("Unknown linker flag %q.", cv.Value)
	default:
		cv.Line.Warn1("Linker flag %q should start with a hypen.", cv.Value)
	}
}

func (cv *VartypeCheck) License() {
	checklineLicense(cv.MkLine, cv.Value)
}

func (cv *VartypeCheck) MachineGnuPlatform() {
	if cv.Value != cv.ValueNoVar {
		return
	}

	const rePart = `(?:\[[^\]]+\]|[^-\[])+`
	const rePair = `^(` + rePart + `)-(` + rePart + `)$`
	const reTriple = `^(` + rePart + `)-(` + rePart + `)-(` + rePart + `)$`

	pattern := cv.Value
	if matches(pattern, rePair) && hasSuffix(pattern, "*") {
		pattern += "-*"
	}

	if m, archPattern, vendorPattern, opsysPattern := match3(pattern, reTriple); m {
		archCv := &VartypeCheck{
			cv.MkLine,
			cv.Line,
			"the hardware architecture part of " + cv.Varname,
			opUseMatch, // Always allow patterns, since this is a PlatformPattern.
			archPattern,
			archPattern,
			cv.MkComment,
			cv.Guessed}
		enumMachineGnuArch.checker(archCv)

		_ = vendorPattern

		opsysCv := &VartypeCheck{
			cv.MkLine,
			cv.Line,
			"the operating system part of " + cv.Varname,
			opUseMatch, // Always allow patterns, since this is a PlatformPattern.
			opsysPattern,
			opsysPattern,
			cv.MkComment,
			cv.Guessed}
		enumMachineGnuPlatformOpsys.checker(opsysCv)

	} else {
		cv.Line.Warn1("%q is not a valid platform pattern.", cv.Value)
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

func (cv *VartypeCheck) MailAddress() {
	line, value := cv.Line, cv.Value

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
	line, varname, value := cv.Line, cv.Varname, cv.Value

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
	line, value, valueNovar := cv.Line, cv.Value, cv.ValueNoVar

	if value != valueNovar {
		if G.opts.Debug {
			traceStep1("Unchecked option name: %q", value)
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
	if !contains(cv.Value, ":") && cv.Guessed {
		cv.MkLine.CheckVartypePrimitive(cv.Varname, CheckvarPathname, cv.Op, cv.Value, cv.MkComment, cv.Guessed)
		return
	}

	for _, path := range strings.Split(cv.Value, ":") {
		if contains(path, "${") {
			continue
		}

		if !matches(path, `^[-0-9A-Za-z._~+%/]*$`) {
			cv.Line.Warn1("%q is not a valid pathname.", path)
		}

		if !hasPrefix(path, "/") {
			cv.Line.Warn2("All components of %s (in this case %q) should be absolute paths.", cv.Varname, path)
		}
	}
}

// Shell globbing including slashes.
// See Filemask
func (cv *VartypeCheck) Pathmask() {
	if cv.Op == opUseMatch {
		return
	}
	if !matches(cv.ValueNoVar, `^[#\-0-9A-Za-z._~+%*?/\[\]]*`) {
		cv.Line.Warn1("%q is not a valid pathname mask.", cv.Value)
	}
	cv.Line.CheckAbsolutePathname(cv.Value)
}

// Like Filename, but including slashes
// See http://www.opengroup.org/onlinepubs/009695399/basedefs/xbd_chap03.html#tag_03_266
func (cv *VartypeCheck) Pathname() {
	if cv.Op == opUseMatch {
		return
	}
	if !matches(cv.ValueNoVar, `^[#\-0-9A-Za-z._~+%/]*$`) {
		cv.Line.Warn1("%q is not a valid pathname.", cv.Value)
	}
	cv.Line.CheckAbsolutePathname(cv.Value)
}

func (cv *VartypeCheck) Perl5Packlist() {
	if cv.Value != cv.ValueNoVar {
		cv.Line.Warn1("%s should not depend on other variables.", cv.Varname)
	}
}

func (cv *VartypeCheck) Perms() {
	if cv.Value == "${ROOT_USER}" || cv.Value == "${ROOT_GROUP}" {
		valuename := cv.Value[2 : len(cv.Value)-1]
		cv.Line.Error1("%s must not be used in permission definitions. Use REAL_%[1]s instead.", valuename)
	}
}

func (cv *VartypeCheck) PkgName() {
	if cv.Op != opUseMatch && cv.Value == cv.ValueNoVar && !matches(cv.Value, rePkgname) {
		cv.Line.Warn1("%q is not a valid package name. A valid package name has the form packagename-version, where version consists only of digits, letters and dots.", cv.Value)
	}
}

func (cv *VartypeCheck) PkgOptionsVar() {
	cv.MkLine.CheckVartypePrimitive(cv.Varname, CheckvarVariableName, cv.Op, cv.Value, cv.MkComment, cv.Guessed)
	if matches(cv.Value, `\$\{PKGBASE[:\}]`) {
		cv.Line.Error0("PKGBASE must not be used in PKG_OPTIONS_VAR.")
		Explain3(
			"PKGBASE is defined in bsd.pkg.mk, which is included as the",
			"very last file, but PKG_OPTIONS_VAR is evaluated earlier.",
			"Use ${PKGNAME:C/-[0-9].*//} instead.")
	}

	// PR 46570, item "6. It should complain in PKG_OPTIONS_VAR is wrong"
	if !hasPrefix(cv.Value, "PKG_OPTIONS.") {
		cv.Line.Error2("PKG_OPTIONS_VAR must be of the form %q, not %q.", "PKG_OPTIONS.*", cv.Value)
	}
}

// A directory name relative to the top-level pkgsrc directory.
// Despite its name, it is more similar to RelativePkgDir than to RelativePkgPath.
func (cv *VartypeCheck) PkgPath() {
	cv.MkLine.CheckRelativePkgdir(G.CurPkgsrcdir + "/" + cv.Value)
}

func (cv *VartypeCheck) PkgRevision() {
	if !matches(cv.Value, `^[1-9]\d*$`) {
		cv.Line.Warn1("%s must be a positive integer number.", cv.Varname)
	}
	if path.Base(cv.Line.Fname) != "Makefile" {
		cv.Line.Error1("%s only makes sense directly in the package Makefile.", cv.Varname)
		Explain(
			"Usually, different packages using the same Makefile.common have",
			"different dependencies and will be bumped at different times (e.g.",
			"for shlib major bumps) and thus the PKGREVISIONs must be in the",
			"separate Makefiles.  There is no practical way of having this",
			"information in a commonly used Makefile.")
	}
}

func (cv *VartypeCheck) MachinePlatform() {
	cv.MachinePlatformPattern()
}

func (cv *VartypeCheck) MachinePlatformPattern() {
	if cv.Value != cv.ValueNoVar {
		return
	}

	const rePart = `(?:\[[^\]]+\]|[^-\[])+`
	const rePair = `^(` + rePart + `)-(` + rePart + `)$`
	const reTriple = `^(` + rePart + `)-(` + rePart + `)-(` + rePart + `)$`

	pattern := cv.Value
	if matches(pattern, rePair) && hasSuffix(pattern, "*") {
		pattern += "-*"
	}

	if m, opsysPattern, _, archPattern := match3(pattern, reTriple); m {
		opsysCv := &VartypeCheck{
			cv.MkLine,
			cv.Line,
			"the operating system part of " + cv.Varname,
			opUseMatch, // Always allow patterns, since this is a PlatformPattern.
			opsysPattern,
			opsysPattern,
			cv.MkComment,
			cv.Guessed}
		enumMachineOpsys.checker(opsysCv)

		// no check for os_version

		archCv := &VartypeCheck{
			cv.MkLine,
			cv.Line,
			"the hardware architecture part of " + cv.Varname,
			opUseMatch, // Always allow patterns, since this is a PlatformPattern.
			archPattern,
			archPattern,
			cv.MkComment,
			cv.Guessed}
		enumMachineArch.checker(archCv)

	} else {
		cv.Line.Warn1("%q is not a valid platform pattern.", cv.Value)
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
	if m, mansubdir := match1(cv.Value, `^man/(.+)`); m {
		cv.Line.Warn2("Please use \"${PKGMANDIR}/%s\" instead of %q.", mansubdir, cv.Value)
	}
}

func (cv *VartypeCheck) PythonDependency() {
	if cv.Value != cv.ValueNoVar {
		cv.Line.Warn0("Python dependencies should not contain variables.")
	} else if !matches(cv.ValueNoVar, `^[+\-.0-9A-Z_a-z]+(?:|:link|:build)$`) {
		cv.Line.Warn1("Invalid Python dependency %q.", cv.Value)
		Explain4(
			"Python dependencies must be an identifier for a package, as",
			"specified in lang/python/versioned_dependencies.mk.  This",
			"identifier may be followed by :build for a build-time only",
			"dependency, or by :link for a run-time only dependency.")
	}
}

// Refers to a package directory, e.g. ../../category/pkgbase.
func (cv *VartypeCheck) RelativePkgDir() {
	cv.MkLine.CheckRelativePkgdir(cv.Value)
}

// Refers to a file or directory, e.g. ../../category/pkgbase, ../../category/pkgbase/Makefile.
func (cv *VartypeCheck) RelativePkgPath() {
	cv.MkLine.CheckRelativePath(cv.Value, true)
}

func (cv *VartypeCheck) Restricted() {
	if cv.Value != "${RESTRICTED}" {
		cv.Line.Warn1("The only valid value for %s is ${RESTRICTED}.", cv.Varname)
		Explain3(
			"These variables are used to control which files may be mirrored on",
			"FTP servers or CD-ROM collections.  They are not intended to mark",
			"packages whose only MASTER_SITES are on ftp.NetBSD.org.")
	}
}

func (cv *VartypeCheck) SedCommand() {
}

func (cv *VartypeCheck) SedCommands() {
	line := cv.Line
	mkline := cv.MkLine

	tokens, rest := splitIntoShellTokens(line, cv.Value)
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
				mkline.CheckVartypePrimitive(cv.Varname, CheckvarSedCommand, cv.Op, tokens[i], cv.MkComment, cv.Guessed)
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
	if cv.Op == opUseMatch || cv.Op == opUse {
		return
	}
	setE := true
	NewShellLine(cv.MkLine).CheckShellCommand(cv.Value, &setE)
}

// Zero or more shell commands, each terminated with a semicolon.
func (cv *VartypeCheck) ShellCommands() {
	NewShellLine(cv.MkLine).CheckShellCommands(cv.Value)
}

func (cv *VartypeCheck) ShellWord() {
	NewShellLine(cv.MkLine).CheckWord(cv.Value, true)
}

func (cv *VartypeCheck) Stage() {
	if !matches(cv.Value, `^(?:pre|do|post)-(?:extract|patch|configure|build|test|install)`) {
		cv.Line.Warn1("Invalid stage name %q. Use one of {pre,do,post}-{extract,patch,configure,build,test,install}.", cv.Value)
	}
}

func (cv *VartypeCheck) String() {
	// No further checks possible.
}

func (cv *VartypeCheck) Tool() {
	if cv.Varname == "TOOLS_NOOP" && cv.Op == opAssignAppend {
		// no warning for package-defined tool definitions

	} else if m, toolname, tooldep := match2(cv.Value, `^([-\w]+|\[)(?::(\w+))?$`); m {
		if G.globalData.Tools.byName[toolname] == nil {
			cv.Line.Error1("Unknown tool %q.", toolname)
		}
		switch tooldep {
		case "", "bootstrap", "build", "pkgsrc", "run":
		default:
			cv.Line.Error1("Unknown tool dependency %q. Use one of \"build\", \"pkgsrc\" or \"run\".", tooldep)
		}
	} else if cv.Op != opUseMatch {
		cv.Line.Error1("Invalid tool syntax: %q.", cv.Value)
	}
}

func (cv *VartypeCheck) Unchecked() {
	// Do nothing, as the name says.
}

func (cv *VartypeCheck) URL() {
	line, value := cv.Line, cv.Value

	if value == "" && hasPrefix(cv.MkComment, "#") {
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
	if cv.Value == cv.ValueNoVar && !matches(cv.Value, `^[0-9_a-z]+$`) {
		cv.Line.Warn1("Invalid user or group name %q.", cv.Value)
	}
}

func (cv *VartypeCheck) VariableName() {
	if cv.Value == cv.ValueNoVar && !matches(cv.Value, `^[A-Z_][0-9A-Z_]*(?:[.].*)?$`) {
		cv.Line.Warn1("%q is not a valid variable name.", cv.Value)
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
	if cv.Op == opUseMatch {
		if !matches(cv.Value, `^[\d?\[][\w\-.*?\[\]]+$`) {
			cv.Line.Warn1("Invalid version number pattern %q.", cv.Value)
		}
	} else if cv.Value == cv.ValueNoVar && !matches(cv.Value, `^\d[\w.]*$`) {
		cv.Line.Warn1("Invalid version number %q.", cv.Value)
	}
}

func (cv *VartypeCheck) WrapperReorder() {
	if !matches(cv.Value, `^reorder:l:([\w\-]+):([\w\-]+)$`) {
		cv.Line.Warn1("Unknown wrapper reorder command %q.", cv.Value)
	}
}

func (cv *VartypeCheck) WrapperTransform() {
	cmd := cv.Value
	if hasPrefix(cmd, "rm:-") ||
		matches(cmd, `^(R|l|rpath):([^:]+):(.+)$`) ||
		matches(cmd, `^'?(opt|rename|rm-optarg|rmdir):.*$`) ||
		cmd == "-e" ||
		matches(cmd, `^["']?s[|:,]`) {
		return
	}
	cv.Line.Warn1("Unknown wrapper transform command %q.", cmd)
}

func (cv *VartypeCheck) WrkdirSubdirectory() {
	cv.MkLine.CheckVartypePrimitive(cv.Varname, CheckvarPathname, cv.Op, cv.Value, cv.MkComment, cv.Guessed)
}

// A directory relative to ${WRKSRC}, for use in CONFIGURE_DIRS and similar variables.
func (cv *VartypeCheck) WrksrcSubdirectory() {
	if m, _, rest := match2(cv.Value, `^(\$\{WRKSRC\})(?:/(.*))?`); m {
		if rest == "" {
			rest = "."
		}
		cv.Line.Note2("You can use %q instead of %q.", rest, cv.Value)
		Explain1(
			"These directories are interpreted relative to ${WRKSRC}.")

	} else if cv.Value != "" && cv.ValueNoVar == "" {
		// The value of another variable

	} else if !matches(cv.ValueNoVar, `^(?:\.|[0-9A-Za-z_@][-0-9A-Za-z_@./+]*)$`) {
		cv.Line.Warn1("%q is not a valid subdirectory of ${WRKSRC}.", cv.Value)
	}
}

func (cv *VartypeCheck) Yes() {
	switch cv.Op {
	case opUseMatch:
		cv.Line.Warn1("%s should only be used in a \".if defined(...)\" conditional.", cv.Varname)
		Explain(
			"This variable can have only two values: defined or undefined.",
			"When it is defined, it means \"yes\", even when its value is",
			"\"no\" or the empty string.",
			"",
			"Therefore, it should not be checked by comparing its value",
			"but using \".if defined(VARNAME)\" alone.")

	default:
		if !matches(cv.Value, `^(?:YES|yes)(?:\s+#.*)?$`) {
			cv.Line.Warn1("%s should be set to YES or yes.", cv.Varname)
			Explain4(
				"This variable means \"yes\" if it is defined, and \"no\" if it is",
				"undefined.  Even when it has the value \"no\", this means \"yes\".",
				"Therefore when it is defined, its value should correspond to its",
				"meaning.")
		}
	}
}

func (cv *VartypeCheck) YesNo() {
	const (
		yes1 = "[yY][eE][sS]"
		yes2 = "[Yy][Ee][Ss]"
		no1  = "[nN][oO]"
		no2  = "[Nn][Oo]"
	)
	if cv.Op == opUseMatch {
		switch cv.Value {
		case yes1, yes2, no1, no2:
		default:
			cv.Line.Warnf("%s should be matched against %q or %q, not %q.", cv.Varname, yes1, no1, cv.Value)
		}
	} else if cv.Op == opUse {
		cv.Line.Warnf("%s should be matched against %q or %q, not compared with %q.", cv.Varname, yes1, no1, cv.Value)
		Explain(
			"The yes/no value can be written in either upper or lower case, and",
			"both forms are actually used.  As long as this is the case, when",
			"checking the variable value, both must be accepted.")
	} else if !matches(cv.Value, `^(?:YES|yes|NO|no)(?:\s+#.*)?$`) {
		cv.Line.Warn1("%s should be set to YES, yes, NO, or no.", cv.Varname)
	}
}

func (cv *VartypeCheck) YesNoIndirectly() {
	if cv.ValueNoVar != "" {
		cv.YesNo()
	}
}
