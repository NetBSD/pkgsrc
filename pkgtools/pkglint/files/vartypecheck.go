package main

import (
	"path"
	"sort"
	"strings"
)

type VartypeCheck struct {
	MkLine MkLine
	Line   Line

	// The name of the variable being checked.
	//
	// In some cases (see WithVarnameValueMatch) it contains not the
	// variable name but more a "description" of a part of a variable.
	// See MachinePlatform for an example.
	Varname    string
	Op         MkOperator
	Value      string
	ValueNoVar string
	MkComment  string
	Guessed    bool // Whether the type definition is guessed (based on the variable name) or explicitly defined (see vardefs.go).
}

func (cv *VartypeCheck) Errorf(format string, args ...interface{}) { cv.Line.Errorf(format, args...) }
func (cv *VartypeCheck) Warnf(format string, args ...interface{})  { cv.Line.Warnf(format, args...) }
func (cv *VartypeCheck) Notef(format string, args ...interface{})  { cv.Line.Notef(format, args...) }

// Autofix returns the autofix instance belonging to the line.
//
// Usage:
//
//  fix := cv.Autofix()
//
//  fix.Errorf("Must not be ...")
//  fix.Warnf("Should not be ...")
//  fix.Notef("It is also possible ...")
//
//  fix.Explain(
//      "Explanation ...",
//      "... end of explanation.")
//
//  fix.Replace("from", "to")
//  fix.ReplaceAfter("prefix", "from", "to")
//  fix.ReplaceRegex(`[\t ]+`, "space", -1)
//  fix.InsertBefore("new line")
//  fix.InsertAfter("new line")
//  fix.Delete()
//  fix.Custom(func(showAutofix, autofix bool) {})
//
//  fix.Apply()
func (cv *VartypeCheck) Autofix() *Autofix { return cv.Line.Autofix() }

// WithValue returns a new VartypeCheck context by copying all
// fields except the value.
//
// This is typically used when calling a related check.
func (cv *VartypeCheck) WithValue(value string) *VartypeCheck {
	return cv.WithVarnameValue(cv.Varname, value)
}

// WithVarnameValue returns a new VartypeCheck context by copying all
// fields except the variable name and the value.
//
// This is typically used when checking parts of composite types.
func (cv *VartypeCheck) WithVarnameValue(varname, value string) *VartypeCheck {
	newVc := *cv
	newVc.Varname = varname
	newVc.Value = value
	newVc.ValueNoVar = cv.MkLine.WithoutMakeVariables(value)
	return &newVc
}

// WithVarnameValueMatch returns a new VartypeCheck context by copying all
// fields except the variable name, the operator (it is set to opUseMatch)
// and the value.
//
// This is typically used when checking parts of composite types,
// especially patterns.
func (cv *VartypeCheck) WithVarnameValueMatch(varname, value string) *VartypeCheck {
	newVc := *cv
	newVc.Varname = varname
	newVc.Op = opUseMatch
	newVc.Value = value
	newVc.ValueNoVar = cv.MkLine.WithoutMakeVariables(value)
	return &newVc
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
	if cv.Value == cv.ValueNoVar && cv.Value != "build" && cv.Value != "full" {
		cv.Warnf("Invalid dependency method %q. Valid methods are \"build\" or \"full\".", cv.Value)
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
		cv.Errorf("Invalid category %q.", cv.Value)
	}
}

// CFlag is a single option to the C/C++ compiler.
//
// XXX: How can flags like "-D NAME" be handled?
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
		cv.Warnf("Unknown compiler flag %q.", cflag)
	default:
		cv.Warnf("Compiler flag %q should start with a hyphen.", cflag)
	}
}

// Comment checks for the single-line description of the package.
func (cv *VartypeCheck) Comment() {
	value := cv.Value

	if value == "TODO: Short description of the package" { // See pkgtools/url2pkg/files/url2pkg.pl, keyword "COMMENT".
		cv.Errorf("COMMENT must be set.")
	}
	if m, first := match1(value, `^(?i)(a|an)[\t ]`); m {
		cv.Warnf("COMMENT should not begin with %q.", first)
	}
	if m, isA := match1(value, ` (is a|is an) `); m {
		cv.Warnf("COMMENT should not contain %q.", isA)
		Explain(
			"The words \"package is a\" are redundant.  Since every package comment",
			"could start with them, it is better to remove this redundancy in all",
			"cases.")
	}
	if G.Pkg != nil && G.Pkg.EffectivePkgbase != "" {
		pkgbase := G.Pkg.EffectivePkgbase
		if hasPrefix(strings.ToLower(value), strings.ToLower(pkgbase+" ")) {
			cv.Warnf("COMMENT should not start with the package name.")
			Explain(
				"The COMMENT is usually displayed together with the package name.",
				"Therefore it does not need to repeat the package name but should",
				"provide additional information instead.")
		}
	}
	if matches(value, `^[a-z]`) && cv.Op == opAssign {
		cv.Warnf("COMMENT should start with a capital letter.")
	}
	if hasSuffix(value, ".") {
		cv.Warnf("COMMENT should not end with a period.")
	}
	if len(value) > 70 {
		cv.Warnf("COMMENT should not be longer than 70 characters.")
	}
	if hasPrefix(value, "\"") && hasSuffix(value, "\"") ||
		hasPrefix(value, "'") && hasSuffix(value, "'") {
		cv.Warnf("COMMENT should not be enclosed in quotes.")
	}
}

// ConfFiles checks pairs of example file, configuration file.
//
// When a package is installed, the example file is installed as usual
// and is then copied to its final location.
func (cv *VartypeCheck) ConfFiles() {
	words, _ := splitIntoMkWords(cv.MkLine.Line, cv.Value)
	if len(words)%2 != 0 {
		cv.Warnf("Values for %s should always be pairs of paths.", cv.Varname)
	}

	for i, word := range words {
		cv.WithValue(word).PathName()

		if i%2 == 1 && !hasPrefix(word, "${") {
			cv.Warnf("The destination file %q should start with a variable reference.", word)
			Explain(
				"Since pkgsrc can be installed in different locations, the",
				"configuration files will also end up in different locations.",
				"Typical variables that are used for configuration files are",
				"PKG_SYSCONFDIR, PKG_SYSCONFBASE, PREFIX, VARBASE.")
		}
	}
}

func (cv *VartypeCheck) Dependency() {
	value := cv.Value

	parser := NewParser(cv.Line, value, false)
	deppat := parser.Dependency()
	if deppat != nil && deppat.Wildcard == "" && (parser.Rest() == "{,nb*}" || parser.Rest() == "{,nb[0-9]*}") {
		cv.Warnf("Dependency patterns of the form pkgbase>=1.0 don't need the \"{,nb*}\" extension.")
		Explain(
			"The \"{,nb*}\" extension is only necessary for dependencies of the",
			"form \"pkgbase-1.2\", since the pattern \"pkgbase-1.2\" doesn't match",
			"the version \"pkgbase-1.2nb5\".  For dependency patterns using the",
			"comparison operators, this is not necessary.")

	} else if deppat == nil || !parser.EOF() {
		cv.Warnf("Invalid dependency pattern %q.", value)
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
			cv.Warnf("Only [0-9]* is allowed in the numeric part of a dependency.")
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
			cv.Warnf("Please use %q instead of %q as the version pattern.", ver+"{,nb*}", ver)
			Explain(
				"Without the \"{,nb*}\" suffix, this version pattern only matches",
				"package versions that don't have a PKGREVISION (which is the part",
				"after the \"nb\").")
		}
		if suffix == "*" {
			cv.Warnf("Please use %q instead of %q as the version pattern.", ver+".*", ver+"*")
			Explain(
				"For example, the version \"1*\" also matches \"10.0.0\", which is",
				"probably not intended.")
		}

	} else if wildcard == "*" {
		cv.Warnf("Please use \"%[1]s-[0-9]*\" instead of \"%[1]s-*\".", deppat.Pkgbase)
		Explain(
			"If you use a * alone, the package specification may match other",
			"packages that have the same prefix but a longer name.  For example,",
			"foo-* matches foo-1.2 but also foo-client-1.2 and foo-server-1.2.")
	}

	withoutCharClasses := replaceAll(wildcard, `\[[\d-]+\]`, "")
	if contains(withoutCharClasses, "-") {
		cv.Warnf("The version pattern %q should not contain a hyphen.", wildcard)
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
	value := cv.Value
	if value != cv.ValueNoVar {
		return // It's probably not worth checking this.
	}

	if m, pattern, relpath, pkg := match3(value, `(.*):(\.\./\.\./[^/]+/([^/]+))$`); m {
		MkLineChecker{cv.MkLine}.CheckRelativePkgdir(relpath)

		switch pkg {
		case "gettext":
			cv.Warnf("Please use USE_TOOLS+=msgfmt instead of this dependency.")
		case "perl5":
			cv.Warnf("Please use USE_TOOLS+=perl:run instead of this dependency.")
		case "gmake":
			cv.Warnf("Please use USE_TOOLS+=gmake instead of this dependency.")
		}

		MkLineChecker{cv.MkLine}.CheckVartypePrimitive(cv.Varname, BtDependency, cv.Op, pattern, cv.MkComment, cv.Guessed)
		return
	}

	if matches(value, `:\.\./[^/]+$`) {
		cv.Warnf("Dependencies should have the form \"../../category/package\".")
		cv.MkLine.ExplainRelativeDirs()
		return
	}

	cv.Warnf("Invalid dependency pattern with path %q.", value)
	Explain(
		"Examples for valid dependency patterns with path are:",
		"  package-[0-9]*:../../category/package",
		"  package>=3.41:../../category/package",
		"  package-2.718:../../category/package")
}

func (cv *VartypeCheck) DistSuffix() {
	if cv.Value == ".tar.gz" {
		cv.Notef("%s is \".tar.gz\" by default, so this definition may be redundant.", cv.Varname)
	}
}

func (cv *VartypeCheck) EmulPlatform() {
	const rePart = `(?:\[[^\]]+\]|[^-\[])+`
	const rePair = `^(` + rePart + `)-(` + rePart + `)$`
	if m, opsysPattern, archPattern := match2(cv.Value, rePair); m {
		opsysCv := cv.WithVarnameValue("the operating system part of "+cv.Varname, opsysPattern)
		enumEmulOpsys.checker(opsysCv)

		archCv := cv.WithVarnameValue("the hardware architecture part of "+cv.Varname, archPattern)
		enumEmulArch.checker(archCv)
	} else {
		cv.Warnf("%q is not a valid emulation platform.", cv.Value)
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

func (cv *VartypeCheck) Enum(vmap map[string]bool, basicType *BasicType) {
	if cv.Op == opUseMatch {
		if !vmap[cv.Value] && cv.Value == cv.ValueNoVar {
			canMatch := false
			for value := range vmap {
				if ok, err := path.Match(cv.Value, value); err != nil {
					cv.Warnf("Invalid match pattern %q.", cv.Value)
					break
				} else if ok {
					canMatch = true
				}
			}
			if !canMatch {
				cv.Warnf("The pattern %q cannot match any of { %s } for %s.", cv.Value, basicType.AllowedEnums(), cv.Varname)
			}
		}
		return
	}

	if cv.Value == cv.ValueNoVar && !vmap[cv.Value] {
		cv.Warnf("%q is not valid for %s. Use one of { %s } instead.", cv.Value, cv.Varname, basicType.AllowedEnums())
	}
}

func (cv *VartypeCheck) FetchURL() {
	MkLineChecker{cv.MkLine}.CheckVartypePrimitive(cv.Varname, BtURL, cv.Op, cv.Value, cv.MkComment, cv.Guessed)

	for siteURL, siteName := range G.Pkgsrc.MasterSiteURLToVar {
		if hasPrefix(cv.Value, siteURL) {
			subdir := cv.Value[len(siteURL):]
			if hasPrefix(cv.Value, "https://github.com/") {
				subdir = strings.SplitAfter(subdir, "/")[0]
				cv.Warnf("Please use ${%s:=%s} instead of %q and run %q for further tips.",
					siteName, subdir, cv.Value, makeHelp("github"))
			} else {
				cv.Warnf("Please use ${%s:=%s} instead of %q.", siteName, subdir, cv.Value)
			}
			return
		}
	}

	if m, name, subdir := match2(cv.Value, `\$\{(MASTER_SITE_[^:]*).*:=(.*)\}$`); m {
		if G.Pkgsrc.MasterSiteVarToURL[name] == "" {
			cv.Errorf("The site %s does not exist.", name)
		}
		if !hasSuffix(subdir, "/") {
			cv.Errorf("The subdirectory in %s must end with a slash.", name)
		}
	}
}

// See PathName.
//
// See http://www.opengroup.org/onlinepubs/009695399/basedefs/xbd_chap03.html#tag_03_169
func (cv *VartypeCheck) FileName() {
	switch {
	case cv.Op == opUseMatch:
		break
	case contains(cv.ValueNoVar, "/"):
		cv.Warnf("A file name should not contain a slash.")
	case !matches(cv.ValueNoVar, `^[-0-9@A-Za-z.,_~+%]*$`):
		cv.Warnf("%q is not a valid file name.", cv.Value)
	}
}

func (cv *VartypeCheck) FileMask() {
	switch {
	case cv.Op == opUseMatch:
		break
	case contains(cv.ValueNoVar, "/"):
		cv.Warnf("A file name mask should not contain a slash.")
	case !matches(cv.ValueNoVar, `^[#%*+\-./0-9?@A-Z\[\]_a-z~]*$`):
		cv.Warnf("%q is not a valid file name mask.", cv.Value)
	}
}

func (cv *VartypeCheck) FileMode() {
	switch {
	case cv.Value != "" && cv.ValueNoVar == "":
		// Fine.
	case matches(cv.Value, `^[0-7]{3,4}$`):
		// Fine.
	default:
		cv.Warnf("Invalid file mode %q.", cv.Value)
	}
}

func (cv *VartypeCheck) GccReqd() {
	cv.Version()

	if m, major := match1(cv.Value, `^([5-9])\.\d+$`); m {
		fix := cv.Autofix()

		fix.Warnf("GCC version numbers should only contain the major version (%s).", major)
		fix.Explain(
			"For GCC up to 4.x, the major version consists of the first and",
			"second number, such as 4.8.",
			"",
			"Starting with GCC >= 5, the major version is only the first number",
			"such as 5 or 7.")
		fix.Replace(cv.Value, major)
		fix.Apply()
	}
}

func (cv *VartypeCheck) Homepage() {
	MkLineChecker{cv.MkLine}.CheckVartypePrimitive(cv.Varname, BtURL, cv.Op, cv.Value, cv.MkComment, cv.Guessed)

	if m, wrong, sitename, subdir := match3(cv.Value, `^(\$\{(MASTER_SITE\w+)(?::=([\w\-/]+))?\})`); m {
		baseURL := G.Pkgsrc.MasterSiteVarToURL[sitename]
		if sitename == "MASTER_SITES" && G.Pkg != nil {
			if mkline := G.Pkg.vars.FirstDefinition("MASTER_SITES"); mkline != nil {
				if masterSites := mkline.Value(); !containsVarRef(masterSites) {
					baseURL = masterSites
				}
			}
		}
		fixedURL := baseURL + subdir
		fix := cv.Autofix()
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
			cv.Warnf("Invalid identifier pattern %q for %s.", cv.Value, cv.Varname)
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
		cv.Warnf("Invalid identifier %q.", cv.Value)
	}
}

func (cv *VartypeCheck) Integer() {
	if !matches(cv.Value, `^\d+$`) {
		cv.Warnf("Invalid integer %q.", cv.Value)
	}
}

func (cv *VartypeCheck) LdFlag() {
	if cv.Op == opUseMatch {
		return
	}
	ldflag := cv.Value
	if m, rpathFlag := match1(ldflag, `^(-Wl,(?:-R|-rpath|--rpath))`); m {
		cv.Warnf("Please use \"${COMPILER_RPATH_FLAG}\" instead of %q.", rpathFlag)
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
		cv.Warnf("Unknown linker flag %q.", cv.Value)
	default:
		cv.Warnf("Linker flag %q should start with a hyphen.", cv.Value)
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
		archCv := cv.WithVarnameValueMatch(
			"the hardware architecture part of "+cv.Varname,
			archPattern)
		enumMachineGnuArch.checker(archCv)

		_ = vendorPattern

		opsysCv := cv.WithVarnameValueMatch(
			"the operating system part of "+cv.Varname,
			opsysPattern)
		enumMachineGnuPlatformOpsys.checker(opsysCv)

	} else {
		cv.Warnf("%q is not a valid platform pattern.", cv.Value)
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
	value := cv.Value

	m, _, domain := match2(value, `^([+\-.0-9A-Z_a-z]+)@([-\w\d.]+)$`)
	if !m {
		cv.Warnf("\"%s\" is not a valid mail address.", value)
		return
	}

	if strings.EqualFold(domain, "NetBSD.org") && domain != "NetBSD.org" {
		cv.Warnf("Please write \"NetBSD.org\" instead of %q.", domain)
	}
	if matches(value, `(?i)^(tech-pkg|packages)@NetBSD\.org$`) {
		cv.Errorf("This mailing list address is obsolete. Use pkgsrc-users@NetBSD.org instead.")
	}
}

// Message is a plain string. It should not be enclosed in quotes since
// that is the job of the code that uses the message.
//
// Lists of messages use a different type since they need the quotes
// around each message; see PKG_FAIL_REASON.
func (cv *VartypeCheck) Message() {
	varname, value := cv.Varname, cv.Value

	if matches(value, `^[\"'].*[\"']$`) {
		cv.Warnf("%s should not be quoted.", varname)
		Explain(
			"The quoting is only needed for variables which are interpreted as",
			"multiple words (or, generally speaking, a list of something).  A",
			"single text message does not belong to this class, since it is only",
			"printed as a whole.")
	}
}

// Option checks whether a single package option from options.mk conforms to the naming conventions.
func (cv *VartypeCheck) Option() {
	value := cv.Value

	if value != cv.ValueNoVar {
		return
	}

	if m, optname := match1(value, `^-?([a-z][-0-9a-z+]*)$`); m {
		if G.Mk != nil && !G.Mk.FirstTime("option:"+optname) {
			return
		}

		if _, found := G.Pkgsrc.PkgOptions[optname]; !found { // There's a difference between empty and absent here.
			cv.Warnf("Unknown option %q.", optname)
			Explain(
				"This option is not documented in the mk/defaults/options.description",
				"file.  Please think of a brief but precise description and either",
				"update that file yourself or suggest a description for this option",
				"on the tech-pkg@NetBSD.org mailing list.")
		}
		return
	}

	if matches(value, `^-?([a-z][-0-9a-z_\+]*)$`) {
		cv.Warnf("Use of the underscore character in option names is deprecated.")
		return
	}

	cv.Errorf("Invalid option name %q. Option names must start with a lowercase letter and be all-lowercase.", value)
}

// Pathlist checks variables like the PATH environment variable.
func (cv *VartypeCheck) Pathlist() {
	value := cv.Value

	// Sometimes, variables called PATH contain a single pathname,
	// especially those with auto-guessed type from MkLineImpl.VariableType.
	if !contains(value, ":") && cv.Guessed {
		cv.PathName()
		return
	}

	for _, path := range cv.MkLine.ValueSplit(value, ":") {
		if hasPrefix(path, "${") {
			continue
		}

		pathNoVar := cv.MkLine.WithoutMakeVariables(path)
		if !matches(pathNoVar, `^[-0-9A-Za-z._~+%/]*$`) {
			cv.Warnf("%q is not a valid pathname.", path)
		}

		if !hasPrefix(path, "/") {
			cv.Warnf("All components of %s (in this case %q) should be absolute paths.", cv.Varname, path)
		}
	}
}

// PathMask is a shell pattern for pathnames, possibly including slashes.
//
// See FileMask.
func (cv *VartypeCheck) PathMask() {
	if cv.Op == opUseMatch {
		return
	}
	if !matches(cv.ValueNoVar, `^[#%*+\-./0-9?@A-Z\[\]_a-z~]*$`) {
		cv.Warnf("%q is not a valid pathname mask.", cv.Value)
	}
	CheckLineAbsolutePathname(cv.Line, cv.Value)
}

// PathName checks for pathnames.
//
// Like FileName, but including slashes.
//
// See http://www.opengroup.org/onlinepubs/009695399/basedefs/xbd_chap03.html#tag_03_266
func (cv *VartypeCheck) PathName() {
	if cv.Op == opUseMatch {
		return
	}
	if !matches(cv.ValueNoVar, `^[#\-0-9A-Za-z._~+%/]*$`) {
		cv.Warnf("%q is not a valid pathname.", cv.Value)
	}
	CheckLineAbsolutePathname(cv.Line, cv.Value)
}

func (cv *VartypeCheck) Perl5Packlist() {
	if cv.Value != cv.ValueNoVar {
		cv.Warnf("%s should not depend on other variables.", cv.Varname)
	}
}

func (cv *VartypeCheck) Perms() {
	if cv.Value == "${ROOT_USER}" || cv.Value == "${ROOT_GROUP}" {
		valueName := cv.Value[2 : len(cv.Value)-1]
		fix := cv.Autofix()
		fix.Errorf("%s must not be used in permission definitions. Use REAL_%[1]s instead.", valueName)
		fix.Replace(valueName, "REAL_"+valueName)
		fix.Apply()
	}
}

func (cv *VartypeCheck) Pkgname() {
	value := cv.Value

	if cv.Op != opUseMatch && value == cv.ValueNoVar && !matches(value, rePkgname) {
		cv.Warnf("%q is not a valid package name.", value)
		Explain(
			"A valid package name has the form packagename-version, where version",
			"consists only of digits, letters and dots.")
	}
}

func (cv *VartypeCheck) PkgOptionsVar() {
	cv.VariableName()

	if matches(cv.Value, `\$\{PKGBASE[:\}]`) {
		cv.Errorf("PKGBASE must not be used in PKG_OPTIONS_VAR.")
		Explain(
			"PKGBASE is defined in bsd.pkg.mk, which is included as the",
			"very last file, but PKG_OPTIONS_VAR is evaluated earlier.",
			"Use ${PKGNAME:C/-[0-9].*//} instead.")
	}

	// PR 46570, item "6. It should complain in PKG_OPTIONS_VAR is wrong"
	if !hasPrefix(cv.Value, "PKG_OPTIONS.") {
		cv.Errorf("PKG_OPTIONS_VAR must be of the form %q, not %q.", "PKG_OPTIONS.*", cv.Value)
	}
}

// PkgPath checks a directory name relative to the top-level pkgsrc directory.
// Despite its name, it is more similar to RelativePkgDir than to RelativePkgPath.
func (cv *VartypeCheck) PkgPath() {
	pkgsrcdir := relpath(path.Dir(cv.MkLine.FileName), G.Pkgsrc.File("."))
	MkLineChecker{cv.MkLine}.CheckRelativePkgdir(pkgsrcdir + "/" + cv.Value)
}

func (cv *VartypeCheck) PkgRevision() {
	if !matches(cv.Value, `^[1-9]\d*$`) {
		cv.Warnf("%s must be a positive integer number.", cv.Varname)
	}
	if cv.Line.Basename != "Makefile" {
		cv.Errorf("%s only makes sense directly in the package Makefile.", cv.Varname)
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

	if m, opsysPattern, versionPattern, archPattern := match3(pattern, reTriple); m {
		opsysCv := cv.WithVarnameValueMatch("the operating system part of "+cv.Varname, opsysPattern)
		enumMachineOpsys.checker(opsysCv)

		versionCv := cv.WithVarnameValueMatch("the version part of "+cv.Varname, versionPattern)
		versionCv.Version()

		archCv := cv.WithVarnameValueMatch("the hardware architecture part of "+cv.Varname, archPattern)
		enumMachineArch.checker(archCv)

	} else {
		cv.Warnf("%q is not a valid platform pattern.", cv.Value)
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

// PrefixPathname checks for a pathname relative to ${PREFIX}.
func (cv *VartypeCheck) PrefixPathname() {
	if m, manSubdir := match1(cv.Value, `^man/(.+)`); m {
		from := "${PKGMANDIR}/" + manSubdir
		fix := cv.Autofix()
		fix.Warnf("Please use %q instead of %q.", from, cv.Value)
		fix.Replace(cv.Value, from)
		fix.Apply()
	}
}

func (cv *VartypeCheck) PythonDependency() {
	if cv.Value != cv.ValueNoVar {
		cv.Warnf("Python dependencies should not contain variables.")
	} else if !matches(cv.ValueNoVar, `^[+\-.0-9A-Z_a-z]+(?:|:link|:build)$`) {
		cv.Warnf("Invalid Python dependency %q.", cv.Value)
		Explain(
			"Python dependencies must be an identifier for a package, as",
			"specified in lang/python/versioned_dependencies.mk.  This",
			"identifier may be followed by :build for a build-time only",
			"dependency, or by :link for a run-time only dependency.")
	}
}

// RelativePkgDir refers to a package directory, e.g. ../../category/pkgbase.
func (cv *VartypeCheck) RelativePkgDir() {
	MkLineChecker{cv.MkLine}.CheckRelativePkgdir(cv.Value)
}

// RelativePkgPath refers to a file or directory, e.g. ../../category/pkgbase,
// ../../category/pkgbase/Makefile.
//
// See RelativePkgDir, which requires a directory, not a file.
func (cv *VartypeCheck) RelativePkgPath() {
	MkLineChecker{cv.MkLine}.CheckRelativePath(cv.Value, true)
}

func (cv *VartypeCheck) Restricted() {
	if cv.Value != "${RESTRICTED}" {
		cv.Warnf("The only valid value for %s is ${RESTRICTED}.", cv.Varname)
		Explain(
			"These variables are used to control which files may be mirrored on",
			"FTP servers or CD-ROM collections.  They are not intended to mark",
			"packages whose only MASTER_SITES are on ftp.NetBSD.org.")
	}
}

func (cv *VartypeCheck) SedCommand() {
}

func (cv *VartypeCheck) SedCommands() {
	tokens, rest := splitIntoShellTokens(cv.Line, cv.Value)
	if rest != "" {
		if contains(cv.Line.Text, "#") {
			cv.Errorf("Invalid shell words %q in sed commands.", rest)
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
					cv.Notef("Each sed command should appear in an assignment of its own.")
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
				cv.Errorf("The -e option to sed requires an argument.")
			}
		case token == "-E":
			// Switch to extended regular expressions mode.

		case token == "-n":
			// Don't print lines per default.

		case i == 0 && matches(token, `^(["']?)(?:\d*|/.*/)s.+["']?$`):
			cv.Notef("Please always use \"-e\" in sed commands, even if there is only one substitution.")

		default:
			cv.Warnf("Unknown sed command %q.", token)
		}
	}
}

func (cv *VartypeCheck) ShellCommand() {
	if cv.Op == opUseMatch || cv.Op == opUseCompare {
		return
	}
	setE := true
	NewShellLine(cv.MkLine).CheckShellCommand(cv.Value, &setE, RunTime)
}

// Zero or more shell commands, each terminated with a semicolon.
func (cv *VartypeCheck) ShellCommands() {
	NewShellLine(cv.MkLine).CheckShellCommands(cv.Value, RunTime)
}

func (cv *VartypeCheck) ShellWord() {
	NewShellLine(cv.MkLine).CheckWord(cv.Value, true, RunTime)
}

func (cv *VartypeCheck) Stage() {
	if !matches(cv.Value, `^(?:pre|do|post)-(?:extract|patch|configure|build|test|install)`) {
		cv.Warnf("Invalid stage name %q. Use one of {pre,do,post}-{extract,patch,configure,build,test,install}.", cv.Value)
	}
}

// Tool checks for tool names like "awk", "m4:pkgsrc", "digest:bootstrap".
func (cv *VartypeCheck) Tool() {
	if cv.Varname == "TOOLS_NOOP" && cv.Op == opAssignAppend {
		// no warning for package-defined tool definitions

	} else if m, toolname, tooldep := match2(cv.Value, `^([-\w]+|\[)(?::(\w+))?$`); m {
		if tool, _ := G.Tool(toolname, RunTime); tool == nil {
			cv.Errorf("Unknown tool %q.", toolname)
		}

		switch tooldep {
		case "", "bootstrap", "build", "pkgsrc", "run", "test":
		default:
			cv.Errorf("Unknown tool dependency %q. Use one of \"bootstrap\", \"build\", \"pkgsrc\", \"run\" or \"test\".", tooldep)
		}
	} else if cv.Op != opUseMatch && cv.Value == cv.ValueNoVar {
		cv.Errorf("Malformed tool dependency: %q.", cv.Value)
		Explain(
			"A tool dependency typically looks like \"sed\" or \"sed:run\".")
	}
}

// Unknown doesn't check for anything.
func (cv *VartypeCheck) Unknown() {
	// Do nothing.
}

func (cv *VartypeCheck) URL() {
	value := cv.Value

	if value == "" && hasPrefix(cv.MkComment, "#") {
		// Ok

	} else if containsVarRef(value) {
		// No further checks

	} else if m, _, host, _, _ := match4(value, `^(https?|ftp|gopher)://([-0-9A-Za-z.]+)(?::(\d+))?/([-%&+,./0-9:;=?@A-Z_a-z~]|#)*$`); m {
		if matches(host, `(?i)\.NetBSD\.org$`) && !matches(host, `\.NetBSD\.org$`) {
			fix := cv.Autofix()
			fix.Warnf("Please write NetBSD.org instead of %s.", host)
			fix.ReplaceRegex(`(?i)NetBSD\.org`, "NetBSD.org", 1)
			fix.Apply()
		}

	} else if m, scheme, _, absPath := match3(value, `^([0-9A-Za-z]+)://([^/]+)(.*)$`); m {
		switch {
		case scheme != "ftp" && scheme != "http" && scheme != "https" && scheme != "gopher":
			cv.Warnf("%q is not a valid URL. Only ftp, gopher, http, and https URLs are allowed here.", value)

		case absPath == "":
			cv.Notef("For consistency, please add a trailing slash to %q.", value)

		default:
			cv.Warnf("%q is not a valid URL.", value)
		}

	} else {
		cv.Warnf("%q is not a valid URL.", value)
	}
}

func (cv *VartypeCheck) UserGroupName() {
	if cv.Value == cv.ValueNoVar && !matches(cv.Value, `^[0-9_a-z]+$`) {
		cv.Warnf("Invalid user or group name %q.", cv.Value)
	}
}

// VariableName checks that the value is a valid variable name.
func (cv *VartypeCheck) VariableName() {
	if cv.Value == cv.ValueNoVar && !matches(cv.Value, `^[A-Z_][0-9A-Z_]*(?:[.].*)?$`) {
		cv.Warnf("%q is not a valid variable name.", cv.Value)
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
	value := cv.Value

	if cv.Op == opUseMatch {
		if value != "*" && !matches(value, `^[\d?\[][\w\-.*?\[\]]+$`) {
			cv.Warnf("Invalid version number pattern %q.", value)
			return
		}

		const digit = `(?:\d|\[[\d-]+\])`
		const alnum = `(?:\w|\[[\d-]+\])`
		if m, ver, suffix := match2(value, `^(`+digit+alnum+`*(?:\.`+alnum+`+)*)(\.\*|\*|)$`); m {
			if suffix == "*" && ver != "[0-9]" {
				cv.Warnf("Please use %q instead of %q as the version pattern.", ver+".*", ver+"*")
				Explain(
					"For example, the version \"1*\" also matches \"10.0.0\", which is",
					"probably not intended.")
			}
		}
		return
	}

	if value == cv.ValueNoVar && !matches(value, `^\d[\w.]*$`) {
		cv.Warnf("Invalid version number %q.", value)
	}
}

func (cv *VartypeCheck) WrapperReorder() {
	if !matches(cv.Value, `^reorder:l:([\w\-]+):([\w\-]+)$`) {
		cv.Warnf("Unknown wrapper reorder command %q.", cv.Value)
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
	cv.Warnf("Unknown wrapper transform command %q.", cmd)
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
		cv.Notef("You can use %q instead of %q.", rest, cv.Value)
		Explain(
			"These directories are interpreted relative to ${WRKSRC}.")

	} else if cv.Value != "" && cv.ValueNoVar == "" {
		// The value of another variable

	} else if !matches(cv.ValueNoVar, `^(?:\.|[0-9A-Za-z_@][-0-9A-Za-z_@./+]*)$`) {
		cv.Warnf("%q is not a valid subdirectory of ${WRKSRC}.", cv.Value)
	}
}

func (cv *VartypeCheck) Yes() {
	switch cv.Op {
	case opUseMatch:
		cv.Warnf("%s should only be used in a \".if defined(...)\" condition.", cv.Varname)
		Explain(
			"This variable can have only two values: defined or undefined.",
			"When it is defined, it means \"yes\", even when its value is",
			"\"no\" or the empty string.",
			"",
			"Therefore, it should not be checked by comparing its value",
			"but using \".if defined(VARNAME)\" alone.")

	default:
		if !matches(cv.Value, `^(?:YES|yes)(?:[\t ]+#.*)?$`) {
			cv.Warnf("%s should be set to YES or yes.", cv.Varname)
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
			cv.Warnf("%s should be matched against %q or %q, not %q.", cv.Varname, yes1, no1, cv.Value)
		}
	} else if cv.Op == opUseCompare {
		cv.Warnf("%s should be matched against %q or %q, not compared with %q.", cv.Varname, yes1, no1, cv.Value)
		Explain(
			"The yes/no value can be written in either upper or lower case, and",
			"both forms are actually used.  As long as this is the case, when",
			"checking the variable value, both must be accepted.")
	} else if !matches(cv.Value, `^(?:YES|yes|NO|no)(?:[\t ]+#.*)?$`) {
		cv.Warnf("%s should be set to YES, yes, NO, or no.", cv.Varname)
	}
}

func (cv *VartypeCheck) YesNoIndirectly() {
	if cv.ValueNoVar != "" {
		cv.YesNo()
	}
}
