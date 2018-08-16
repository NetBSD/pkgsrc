package main

import (
	"netbsd.org/pkglint/regex"
	"netbsd.org/pkglint/trace"
	"path"
	"sort"
	"strings"
)

type VartypeCheck struct {
	MkLine     MkLine
	Line       Line
	Varname    string
	Op         MkOperator
	Value      string
	ValueNoVar string
	MkComment  string
	Guessed    bool // Whether the type definition is guessed (based on the variable name) or explicitly defined (see vardefs.go).
}

// NewVartypeCheckValue creates a VartypeCheck context by copying all
// fields except the value. This is typically used when checking parts
// of composite types.
func NewVartypeCheckValue(vc *VartypeCheck, value string) *VartypeCheck {
	valueNoVar := vc.MkLine.WithoutMakeVariables(value)

	copy := *vc
	copy.Value = value
	copy.ValueNoVar = valueNoVar
	return &copy
}

type MkOperator uint8

const (
	opAssign        MkOperator = iota // =
	opAssignShell                     // !=
	opAssignEval                      // :=
	opAssignAppend                    // +=
	opAssignDefault                   // ?=
	opUseCompare                      // A variable is compared to a value, e.g. in a condition.
	opUseMatch                        // A variable is matched using the :M or :N modifier.
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

func enumFromRe(re string) *BasicType {
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
	if trace.Tracing {
		trace.Step1("Unchecked AWK command: %q", cv.Value)
	}
}

func (cv *VartypeCheck) BasicRegularExpression() {
	if trace.Tracing {
		trace.Step1("Unchecked basic regular expression: %q", cv.Value)
	}
}

func (cv *VartypeCheck) BuildlinkDepmethod() {
	if !containsVarRef(cv.Value) && cv.Value != "build" && cv.Value != "full" {
		cv.Line.Warnf("Invalid dependency method %q. Valid methods are \"build\" or \"full\".", cv.Value)
	}
}

func (cv *VartypeCheck) Category() {
	if cv.Value != "wip" && fileExists(G.Pkgsrc.File(cv.Value+"/Makefile")) {
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
		cv.Line.Errorf("Invalid category %q.", cv.Value)
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
		cv.Line.Warnf("Unknown compiler flag %q.", cflag)
	default:
		cv.Line.Warnf("Compiler flag %q should start with a hyphen.", cflag)
	}
}

// The single-line description of the package.
func (cv *VartypeCheck) Comment() {
	line, value := cv.Line, cv.Value

	if value == "TODO: Short description of the package" { // See pkgtools/url2pkg/files/url2pkg.pl, keyword "COMMENT".
		line.Errorf("COMMENT must be set.")
	}
	if m, first := match1(value, `^(?i)(a|an)\s`); m {
		line.Warnf("COMMENT should not begin with %q.", first)
	}
	if m, isA := match1(value, ` (is a|is an) `); m {
		line.Warnf("COMMENT should not contain %q.", isA)
		Explain(
			"The words \"package is a\" are redundant.  Since every package comment",
			"could start with them, it is better to remove this redundancy in all",
			"cases.")
	}
	if G.Pkg != nil && G.Pkg.EffectivePkgbase != "" {
		pkgbase := G.Pkg.EffectivePkgbase
		if strings.HasPrefix(strings.ToLower(value), strings.ToLower(pkgbase+" ")) {
			line.Warnf("COMMENT should not start with the package name.")
			Explain(
				"The COMMENT is usually displayed together with the package name.",
				"Therefore it does not need to repeat the package name but should",
				"provide additional information instead.")
		}
	}
	if matches(value, `^[a-z]`) {
		line.Warnf("COMMENT should start with a capital letter.")
	}
	if hasSuffix(value, ".") {
		line.Warnf("COMMENT should not end with a period.")
	}
	if len(value) > 70 {
		line.Warnf("COMMENT should not be longer than 70 characters.")
	}
	if hasPrefix(value, "\"") && hasSuffix(value, "\"") ||
		hasPrefix(value, "'") && hasSuffix(value, "'") {
		line.Warnf("COMMENT should not be enclosed in quotes.")
	}
}

func (cv *VartypeCheck) ConfFiles() {
	words, _ := splitIntoMkWords(cv.MkLine.Line, cv.Value)
	if len(words)%2 != 0 {
		cv.Line.Warnf("Values for %s should always be pairs of paths.", cv.Varname)
	}

	for i, word := range words {
		NewVartypeCheckValue(cv, word).Pathname()

		if i%2 == 1 && !hasPrefix(word, "${") {
			cv.Line.Warnf("The destination file %q should start with a variable reference.", word)
			Explain(
				"Since pkgsrc can be installed in different locations, the",
				"configuration files will also end up in different locations.",
				"Typical variables that are used for configuration files are",
				"PKG_SYSCONFDIR, PKG_SYSCONFBASE, PREFIX, VARBASE.")
		}
	}
}

func (cv *VartypeCheck) Dependency() {
	line, value := cv.Line, cv.Value

	parser := NewParser(line, value, false)
	deppat := parser.Dependency()
	if deppat != nil && deppat.Wildcard == "" && (parser.Rest() == "{,nb*}" || parser.Rest() == "{,nb[0-9]*}") {
		line.Warnf("Dependency patterns of the form pkgbase>=1.0 don't need the \"{,nb*}\" extension.")
		Explain(
			"The \"{,nb*}\" extension is only necessary for dependencies of the",
			"form \"pkgbase-1.2\", since the pattern \"pkgbase-1.2\" doesn't match",
			"the version \"pkgbase-1.2nb5\".  For dependency patterns using the",
			"comparison operators, this is not necessary.")

	} else if deppat == nil || !parser.EOF() {
		line.Warnf("Unknown dependency pattern %q.", value)
		Explain(
			"Typical dependencies have the following forms:",
			"",
			"\tpackage>=2.5",
			"\tpackage-[0-9]*",
			"\tpackage-3.141",
			"\tpackage>=2.71828<=3.1415")
		return
	}

	wildcard := deppat.Wildcard
	if m, inside := match1(wildcard, `^\[(.*)\]\*$`); m {
		if inside != "0-9" {
			line.Warnf("Only [0-9]* is allowed in the numeric part of a dependency.")
			Explain(
				"The pattern -[0-9] means any version.  All other version patterns",
				"should be expressed using the comparison operators like < or >= or",
				"even >=2<3.",
				"",
				"Patterns like -[0-7] will only match the first digit of the version",
				"number and will not do the correct thing when the package reaches",
				"version 10.")
		}

	} else if m, ver, suffix := match2(wildcard, `^(\d\w*(?:\.\w+)*)(\.\*|\{,nb\*\}|\{,nb\[0-9\]\*\}|\*|)$`); m {
		if suffix == "" {
			line.Warnf("Please use %q instead of %q as the version pattern.", ver+"{,nb*}", ver)
			Explain(
				"Without the \"{,nb*}\" suffix, this version pattern only matches",
				"package versions that don't have a PKGREVISION (which is the part",
				"after the \"nb\").")
		}
		if suffix == "*" {
			line.Warnf("Please use %q instead of %q as the version pattern.", ver+".*", ver+"*")
			Explain(
				"For example, the version \"1*\" also matches \"10.0.0\", which is",
				"probably not intended.")
		}

	} else if wildcard == "*" {
		line.Warnf("Please use \"%[1]s-[0-9]*\" instead of \"%[1]s-*\".", deppat.Pkgbase)
		Explain(
			"If you use a * alone, the package specification may match other",
			"packages that have the same prefix, but a longer name.  For example,",
			"foo-* matches foo-1.2, but also foo-client-1.2 and foo-server-1.2.")
	}

	if nocclasses := regex.Compile(`\[[\d-]+\]`).ReplaceAllString(wildcard, ""); contains(nocclasses, "-") {
		line.Warnf("The version pattern %q should not contain a hyphen.", wildcard)
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
		MkLineChecker{cv.MkLine}.CheckRelativePkgdir(relpath)

		switch pkg {
		case "msgfmt", "gettext":
			line.Warnf("Please use USE_TOOLS+=msgfmt instead of this dependency.")
		case "perl5":
			line.Warnf("Please use USE_TOOLS+=perl:run instead of this dependency.")
		case "gmake":
			line.Warnf("Please use USE_TOOLS+=gmake instead of this dependency.")
		}

		MkLineChecker{cv.MkLine}.CheckVartypePrimitive(cv.Varname, BtDependency, cv.Op, pattern, cv.MkComment, cv.Guessed)
		return
	}

	if matches(value, `:\.\./[^/]+$`) {
		line.Warnf("Dependencies should have the form \"../../category/package\".")
		cv.MkLine.ExplainRelativeDirs()
		return
	}

	line.Warnf("Unknown dependency pattern with path %q.", value)
	Explain(
		"Examples for valid dependency patterns with path are:",
		"  package-[0-9]*:../../category/package",
		"  package>=3.41:../../category/package",
		"  package-2.718:../../category/package")
}

func (cv *VartypeCheck) DistSuffix() {
	if cv.Value == ".tar.gz" {
		cv.Line.Notef("%s is \".tar.gz\" by default, so this definition may be redundant.", cv.Varname)
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
		cv.Line.Warnf("%q is not a valid emulation platform.", cv.Value)
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
	MkLineChecker{cv.MkLine}.CheckVartypePrimitive(cv.Varname, BtURL, cv.Op, cv.Value, cv.MkComment, cv.Guessed)

	for siteURL, siteName := range G.Pkgsrc.MasterSiteURLToVar {
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
		if G.Pkgsrc.MasterSiteVarToURL[name] == "" {
			cv.Line.Errorf("The site %s does not exist.", name)
		}
		if !hasSuffix(subdir, "/") {
			cv.Line.Errorf("The subdirectory in %s must end with a slash.", name)
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
		cv.Line.Warnf("A filename should not contain a slash.")
	case !matches(cv.ValueNoVar, `^[-0-9@A-Za-z.,_~+%]*$`):
		cv.Line.Warnf("%q is not a valid filename.", cv.Value)
	}
}

func (cv *VartypeCheck) Filemask() {
	if cv.Op == opUseMatch {
		return
	}
	if !matches(cv.ValueNoVar, `^[-0-9A-Za-z._~+%*?]*$`) {
		cv.Line.Warnf("%q is not a valid filename mask.", cv.Value)
	}
}

func (cv *VartypeCheck) FileMode() {
	switch {
	case cv.Value != "" && cv.ValueNoVar == "":
		// Fine.
	case matches(cv.Value, `^[0-7]{3,4}`):
		// Fine.
	default:
		cv.Line.Warnf("Invalid file mode %q.", cv.Value)
	}
}

func (cv *VartypeCheck) Homepage() {
	MkLineChecker{cv.MkLine}.CheckVartypePrimitive(cv.Varname, BtURL, cv.Op, cv.Value, cv.MkComment, cv.Guessed)

	if m, wrong, sitename, subdir := match3(cv.Value, `^(\$\{(MASTER_SITE\w+)(?::=([\w\-/]+))?\})`); m {
		baseURL := G.Pkgsrc.MasterSiteVarToURL[sitename]
		if sitename == "MASTER_SITES" && G.Pkg != nil {
			masterSites, _ := G.Pkg.varValue("MASTER_SITES")
			if !containsVarRef(masterSites) {
				baseURL = masterSites
			}
		}
		fixedURL := baseURL + subdir
		fix := cv.Line.Autofix()
		if baseURL != "" {
			fix.Warnf("HOMEPAGE should not be defined in terms of MASTER_SITEs. Use %s directly.", fixedURL)
		} else {
			fix.Warnf("HOMEPAGE should not be defined in terms of MASTER_SITEs.")
		}
		fix.Explain(
			"The HOMEPAGE is a single URL, while MASTER_SITES is a list of URLs.",
			"As long as this list has exactly one element, this works, but as",
			"soon as another site is added, the HOMEPAGE would not be a valid",
			"URL anymore.",
			"",
			"Defining MASTER_SITES=${HOMEPAGE} is ok, though.")
		fix.Replace(wrong, fixedURL)
		fix.Apply()
	}
}

func (cv *VartypeCheck) Identifier() {
	if cv.Op == opUseMatch {
		if cv.Value == cv.ValueNoVar && !matches(cv.Value, `^[\w*?]`) {
			cv.Line.Warnf("Invalid identifier pattern %q for %s.", cv.Value, cv.Varname)
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
		cv.Line.Warnf("Invalid identifier %q.", cv.Value)
	}
}

func (cv *VartypeCheck) Integer() {
	if !matches(cv.Value, `^\d+$`) {
		cv.Line.Warnf("Invalid integer %q.", cv.Value)
	}
}

func (cv *VartypeCheck) LdFlag() {
	if cv.Op == opUseMatch {
		return
	}
	ldflag := cv.Value
	if m, rpathFlag := match1(ldflag, `^(-Wl,(?:-R|-rpath|--rpath))`); m {
		cv.Line.Warnf("Please use \"${COMPILER_RPATH_FLAG}\" instead of %q.", rpathFlag)
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
		cv.Line.Warnf("Unknown linker flag %q.", cv.Value)
	default:
		cv.Line.Warnf("Linker flag %q should start with a hypen.", cv.Value)
	}
}

func (cv *VartypeCheck) License() {
	licenseChecker := &LicenseChecker{cv.MkLine}
	licenseChecker.Check(cv.Value, cv.Op)
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
		cv.Line.Warnf("%q is not a valid platform pattern.", cv.Value)
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
			line.Warnf("Please write \"NetBSD.org\" instead of %q.", domain)
		}
		if matches(value, `(?i)^(tech-pkg|packages)@NetBSD\.org$`) {
			line.Errorf("This mailing list address is obsolete. Use pkgsrc-users@NetBSD.org instead.")
		}

	} else {
		line.Warnf("\"%s\" is not a valid mail address.", value)
	}
}

// See ${STEP_MSG}, ${PKG_FAIL_REASON}
func (cv *VartypeCheck) Message() {
	line, varname, value := cv.Line, cv.Varname, cv.Value

	if matches(value, `^[\"'].*[\"']$`) {
		line.Warnf("%s should not be quoted.", varname)
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

// Option checks whether a single package option from options.mk conforms to the naming conventions.
func (cv *VartypeCheck) Option() {
	line, value, valueNovar := cv.Line, cv.Value, cv.ValueNoVar

	if value != valueNovar {
		if trace.Tracing {
			trace.Step1("Unchecked option name: %q", value)
		}
		return
	}

	if m, optname := match1(value, `^-?([a-z][-0-9a-z+]*)$`); m {
		if G.Mk != nil && !G.Mk.FirstTime("option:"+optname) {
			return
		}

		if _, found := G.Pkgsrc.PkgOptions[optname]; !found { // There's a difference between empty and absent here.
			line.Warnf("Unknown option %q.", optname)
			Explain(
				"This option is not documented in the mk/defaults/options.description",
				"file.  Please think of a brief but precise description and either",
				"update that file yourself or suggest a description for this option",
				"on the tech-pkg@NetBSD.org mailing list.")
		}
		return
	}

	if matches(value, `^-?([a-z][-0-9a-z_\+]*)$`) {
		line.Warnf("Use of the underscore character in option names is deprecated.")
		return
	}

	line.Errorf("Invalid option name %q. Option names must start with a lowercase letter and be all-lowercase.", value)
}

// Pathlist checks variables like the PATH environment variable.
func (cv *VartypeCheck) Pathlist() {
	// Sometimes, variables called PATH contain a single pathname,
	// especially those with auto-guessed type from MkLineImpl.VariableType.
	if !contains(cv.Value, ":") && cv.Guessed {
		MkLineChecker{cv.MkLine}.CheckVartypePrimitive(cv.Varname, BtPathname, cv.Op, cv.Value, cv.MkComment, cv.Guessed)
		return
	}

	for _, path := range cv.MkLine.ValueSplit(cv.Value, ":") {
		if hasPrefix(path, "${") {
			continue
		}

		pathNoVar := cv.MkLine.WithoutMakeVariables(path)
		if !matches(pathNoVar, `^[-0-9A-Za-z._~+%/]*$`) {
			cv.Line.Warnf("%q is not a valid pathname.", path)
		}

		if !hasPrefix(path, "/") {
			cv.Line.Warnf("All components of %s (in this case %q) should be absolute paths.", cv.Varname, path)
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
		cv.Line.Warnf("%q is not a valid pathname mask.", cv.Value)
	}
	CheckLineAbsolutePathname(cv.Line, cv.Value)
}

// Like Filename, but including slashes.
//
// See http://www.opengroup.org/onlinepubs/009695399/basedefs/xbd_chap03.html#tag_03_266
func (cv *VartypeCheck) Pathname() {
	if cv.Op == opUseMatch {
		return
	}
	if !matches(cv.ValueNoVar, `^[#\-0-9A-Za-z._~+%/]*$`) {
		cv.Line.Warnf("%q is not a valid pathname.", cv.Value)
	}
	CheckLineAbsolutePathname(cv.Line, cv.Value)
}

func (cv *VartypeCheck) Perl5Packlist() {
	if cv.Value != cv.ValueNoVar {
		cv.Line.Warnf("%s should not depend on other variables.", cv.Varname)
	}
}

func (cv *VartypeCheck) Perms() {
	if cv.Value == "${ROOT_USER}" || cv.Value == "${ROOT_GROUP}" {
		valuename := cv.Value[2 : len(cv.Value)-1]
		cv.Line.Errorf("%s must not be used in permission definitions. Use REAL_%[1]s instead.", valuename)
	}
}

func (cv *VartypeCheck) PkgName() {
	if cv.Op != opUseMatch && cv.Value == cv.ValueNoVar && !matches(cv.Value, rePkgname) {
		cv.Line.Warnf("%q is not a valid package name. A valid package name has the form packagename-version, where version consists only of digits, letters and dots.", cv.Value)
	}
}

func (cv *VartypeCheck) PkgOptionsVar() {
	MkLineChecker{cv.MkLine}.CheckVartypePrimitive(cv.Varname, BtVariableName, cv.Op, cv.Value, cv.MkComment, cv.Guessed)
	if matches(cv.Value, `\$\{PKGBASE[:\}]`) {
		cv.Line.Errorf("PKGBASE must not be used in PKG_OPTIONS_VAR.")
		Explain(
			"PKGBASE is defined in bsd.pkg.mk, which is included as the",
			"very last file, but PKG_OPTIONS_VAR is evaluated earlier.",
			"Use ${PKGNAME:C/-[0-9].*//} instead.")
	}

	// PR 46570, item "6. It should complain in PKG_OPTIONS_VAR is wrong"
	if !hasPrefix(cv.Value, "PKG_OPTIONS.") {
		cv.Line.Errorf("PKG_OPTIONS_VAR must be of the form %q, not %q.", "PKG_OPTIONS.*", cv.Value)
	}
}

// A directory name relative to the top-level pkgsrc directory.
// Despite its name, it is more similar to RelativePkgDir than to RelativePkgPath.
func (cv *VartypeCheck) PkgPath() {
	pkgsrcdir := relpath(path.Dir(cv.MkLine.Filename), G.Pkgsrc.File("."))
	MkLineChecker{cv.MkLine}.CheckRelativePkgdir(pkgsrcdir + "/" + cv.Value)
}

func (cv *VartypeCheck) PkgRevision() {
	if !matches(cv.Value, `^[1-9]\d*$`) {
		cv.Line.Warnf("%s must be a positive integer number.", cv.Varname)
	}
	if path.Base(cv.Line.Filename) != "Makefile" {
		cv.Line.Errorf("%s only makes sense directly in the package Makefile.", cv.Varname)
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
		cv.Line.Warnf("%q is not a valid platform pattern.", cv.Value)
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
		cv.Line.Warnf("Please use \"${PKGMANDIR}/%s\" instead of %q.", mansubdir, cv.Value)
	}
}

func (cv *VartypeCheck) PythonDependency() {
	if cv.Value != cv.ValueNoVar {
		cv.Line.Warnf("Python dependencies should not contain variables.")
	} else if !matches(cv.ValueNoVar, `^[+\-.0-9A-Z_a-z]+(?:|:link|:build)$`) {
		cv.Line.Warnf("Invalid Python dependency %q.", cv.Value)
		Explain(
			"Python dependencies must be an identifier for a package, as",
			"specified in lang/python/versioned_dependencies.mk.  This",
			"identifier may be followed by :build for a build-time only",
			"dependency, or by :link for a run-time only dependency.")
	}
}

// Refers to a package directory, e.g. ../../category/pkgbase.
func (cv *VartypeCheck) RelativePkgDir() {
	MkLineChecker{cv.MkLine}.CheckRelativePkgdir(cv.Value)
}

// Refers to a file or directory, e.g. ../../category/pkgbase, ../../category/pkgbase/Makefile.
func (cv *VartypeCheck) RelativePkgPath() {
	MkLineChecker{cv.MkLine}.CheckRelativePath(cv.Value, true)
}

func (cv *VartypeCheck) Restricted() {
	if cv.Value != "${RESTRICTED}" {
		cv.Line.Warnf("The only valid value for %s is ${RESTRICTED}.", cv.Varname)
		Explain(
			"These variables are used to control which files may be mirrored on",
			"FTP servers or CD-ROM collections.  They are not intended to mark",
			"packages whose only MASTER_SITES are on ftp.NetBSD.org.")
	}
}

func (cv *VartypeCheck) SedCommand() {
}

func (cv *VartypeCheck) SedCommands() {
	line := cv.Line

	tokens, rest := splitIntoShellTokens(line, cv.Value)
	if rest != "" {
		if strings.Contains(line.Text, "#") {
			line.Errorf("Invalid shell words %q in sed commands.", rest)
			Explain(
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
					line.Notef("Each sed command should appear in an assignment of its own.")
					Explain(
						"For example, instead of",
						"    SUBST_SED.foo+=        -e s,command1,, -e s,command2,,",
						"use",
						"    SUBST_SED.foo+=        -e s,command1,,",
						"    SUBST_SED.foo+=        -e s,command2,,",
						"",
						"This way, short sed commands cannot be hidden at the end of a line.")
				}
				MkLineChecker{cv.MkLine}.CheckVartypePrimitive(cv.Varname, BtSedCommand, cv.Op, tokens[i], cv.MkComment, cv.Guessed)
			} else {
				line.Errorf("The -e option to sed requires an argument.")
			}
		case token == "-E":
			// Switch to extended regular expressions mode.

		case token == "-n":
			// Don't print lines per default.

		case i == 0 && matches(token, `^(["']?)(?:\d*|/.*/)s.+["']?$`):
			line.Notef("Please always use \"-e\" in sed commands, even if there is only one substitution.")

		default:
			line.Warnf("Unknown sed command %q.", token)
		}
	}
}

func (cv *VartypeCheck) ShellCommand() {
	if cv.Op == opUseMatch || cv.Op == opUseCompare {
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
		cv.Line.Warnf("Invalid stage name %q. Use one of {pre,do,post}-{extract,patch,configure,build,test,install}.", cv.Value)
	}
}

// Tool checks for tool names like "awk", "m4:pkgsrc", "digest:bootstrap".
func (cv *VartypeCheck) Tool() {
	if cv.Varname == "TOOLS_NOOP" && cv.Op == opAssignAppend {
		// no warning for package-defined tool definitions

	} else if m, toolname, tooldep := match2(cv.Value, `^([-\w]+|\[)(?::(\w+))?$`); m {
		if G.Pkgsrc.Tools.ByName(toolname) == nil && (G.Mk == nil || G.Mk.toolRegistry.ByName(toolname) == nil) {
			cv.Line.Errorf("Unknown tool %q.", toolname)
		}
		switch tooldep {
		case "", "bootstrap", "build", "pkgsrc", "run", "test":
		default:
			cv.Line.Errorf("Unknown tool dependency %q. Use one of \"bootstrap\", \"build\", \"pkgsrc\", \"run\" or \"test\".", tooldep)
		}
	} else if cv.Op != opUseMatch && cv.Value == cv.ValueNoVar {
		cv.Line.Errorf("Malformed tool dependency: %q.", cv.Value)
		Explain(
			"A tool dependency typically looks like \"sed\" or \"sed:run\".")
	}
}

func (cv *VartypeCheck) Unknown() {
	// Do nothing.
}

func (cv *VartypeCheck) URL() {
	line, value := cv.Line, cv.Value

	if value == "" && hasPrefix(cv.MkComment, "#") {
		// Ok

	} else if containsVarRef(value) {
		// No further checks

	} else if m, _, host, _, _ := match4(value, `^(https?|ftp|gopher)://([-0-9A-Za-z.]+)(?::(\d+))?/([-%&+,./0-9:;=?@A-Z_a-z~]|#)*$`); m {
		if matches(host, `(?i)\.NetBSD\.org$`) && !matches(host, `\.NetBSD\.org$`) {
			line.Warnf("Please write NetBSD.org instead of %s.", host)
		}

	} else if m, scheme, _, absPath := match3(value, `^([0-9A-Za-z]+)://([^/]+)(.*)$`); m {
		switch {
		case scheme != "ftp" && scheme != "http" && scheme != "https" && scheme != "gopher":
			line.Warnf("%q is not a valid URL. Only ftp, gopher, http, and https URLs are allowed here.", value)

		case absPath == "":
			line.Notef("For consistency, please add a trailing slash to %q.", value)

		default:
			line.Warnf("%q is not a valid URL.", value)
		}

	} else {
		line.Warnf("%q is not a valid URL.", value)
	}
}

func (cv *VartypeCheck) UserGroupName() {
	if cv.Value == cv.ValueNoVar && !matches(cv.Value, `^[0-9_a-z]+$`) {
		cv.Line.Warnf("Invalid user or group name %q.", cv.Value)
	}
}

func (cv *VartypeCheck) VariableName() {
	if cv.Value == cv.ValueNoVar && !matches(cv.Value, `^[A-Z_][0-9A-Z_]*(?:[.].*)?$`) {
		cv.Line.Warnf("%q is not a valid variable name.", cv.Value)
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
			cv.Line.Warnf("Invalid version number pattern %q.", cv.Value)
		}
	} else if cv.Value == cv.ValueNoVar && !matches(cv.Value, `^\d[\w.]*$`) {
		cv.Line.Warnf("Invalid version number %q.", cv.Value)
	}
}

func (cv *VartypeCheck) WrapperReorder() {
	if !matches(cv.Value, `^reorder:l:([\w\-]+):([\w\-]+)$`) {
		cv.Line.Warnf("Unknown wrapper reorder command %q.", cv.Value)
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
	cv.Line.Warnf("Unknown wrapper transform command %q.", cmd)
}

func (cv *VartypeCheck) WrkdirSubdirectory() {
	MkLineChecker{cv.MkLine}.CheckVartypePrimitive(cv.Varname, BtPathname, cv.Op, cv.Value, cv.MkComment, cv.Guessed)
}

// A directory relative to ${WRKSRC}, for use in CONFIGURE_DIRS and similar variables.
func (cv *VartypeCheck) WrksrcSubdirectory() {
	if m, _, rest := match2(cv.Value, `^(\$\{WRKSRC\})(?:/(.*))?`); m {
		if rest == "" {
			rest = "."
		}
		cv.Line.Notef("You can use %q instead of %q.", rest, cv.Value)
		Explain(
			"These directories are interpreted relative to ${WRKSRC}.")

	} else if cv.Value != "" && cv.ValueNoVar == "" {
		// The value of another variable

	} else if !matches(cv.ValueNoVar, `^(?:\.|[0-9A-Za-z_@][-0-9A-Za-z_@./+]*)$`) {
		cv.Line.Warnf("%q is not a valid subdirectory of ${WRKSRC}.", cv.Value)
	}
}

func (cv *VartypeCheck) Yes() {
	switch cv.Op {
	case opUseMatch:
		cv.Line.Warnf("%s should only be used in a \".if defined(...)\" condition.", cv.Varname)
		Explain(
			"This variable can have only two values: defined or undefined.",
			"When it is defined, it means \"yes\", even when its value is",
			"\"no\" or the empty string.",
			"",
			"Therefore, it should not be checked by comparing its value",
			"but using \".if defined(VARNAME)\" alone.")

	default:
		if !matches(cv.Value, `^(?:YES|yes)(?:\s+#.*)?$`) {
			cv.Line.Warnf("%s should be set to YES or yes.", cv.Varname)
			Explain(
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
	} else if cv.Op == opUseCompare {
		cv.Line.Warnf("%s should be matched against %q or %q, not compared with %q.", cv.Varname, yes1, no1, cv.Value)
		Explain(
			"The yes/no value can be written in either upper or lower case, and",
			"both forms are actually used.  As long as this is the case, when",
			"checking the variable value, both must be accepted.")
	} else if !matches(cv.Value, `^(?:YES|yes|NO|no)(?:\s+#.*)?$`) {
		cv.Line.Warnf("%s should be set to YES, yes, NO, or no.", cv.Varname)
	}
}

func (cv *VartypeCheck) YesNoIndirectly() {
	if cv.ValueNoVar != "" {
		cv.YesNo()
	}
}
