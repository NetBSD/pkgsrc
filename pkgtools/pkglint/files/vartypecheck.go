package pkglint

import (
	"netbsd.org/pkglint/pkgver"
	"netbsd.org/pkglint/regex"
	"netbsd.org/pkglint/textproc"
	"path"
	"strings"
)

// VartypeCheck groups together the various checks for variables of the different types.
type VartypeCheck struct {
	MkLines *MkLines
	MkLine  *MkLine

	// The name of the variable being checked.
	//
	// In some cases (see WithVarnameValueMatch) it contains not the
	// variable name but more a "description" of a part of a variable.
	// See MachinePlatform for an example.
	Varname    string
	Op         MkOperator
	Value      string
	ValueNoVar string // The Value with all expressions removed.
	MkComment  string // The comment including the "#".
	Guessed    bool   // Whether the type definition is guessed (based on the variable name) or explicitly defined (see vardefs.go).
}

func (cv *VartypeCheck) Errorf(format string, args ...interface{}) { cv.MkLine.Errorf(format, args...) }
func (cv *VartypeCheck) Warnf(format string, args ...interface{})  { cv.MkLine.Warnf(format, args...) }
func (cv *VartypeCheck) Notef(format string, args ...interface{})  { cv.MkLine.Notef(format, args...) }
func (cv *VartypeCheck) Explain(explanation ...string)             { cv.MkLine.Explain(explanation...) }

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
//  fix.InsertAbove("new line")
//  fix.InsertBelow("new line")
//  fix.Delete()
//  fix.Custom(func(showAutofix, autofix bool) {})
//
//  fix.Apply()
func (cv *VartypeCheck) Autofix() *Autofix { return cv.MkLine.Autofix() }

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
// such as the patterns from ONLY_FOR_PLATFORM.
func (cv *VartypeCheck) WithVarnameValueMatch(varname, value string) *VartypeCheck {
	newVc := *cv
	newVc.Varname = varname
	newVc.Op = opUseMatch
	newVc.Value = value
	newVc.ValueNoVar = cv.MkLine.WithoutMakeVariables(value)
	return &newVc
}

func (cv *VartypeCheck) AwkCommand() {
	if trace.Tracing {
		trace.Step1("Unchecked AWK command: %q", cv.Value)
	}
}

// BasicRegularExpression checks for a basic regular expression, as
// defined by POSIX.
//
// When they are used in a list variable (as for CHECK_FILES_SKIP), they
// cannot include spaces. Instead, a dot or [[:space:]] must be used.
// The regular expressions do not need any quotation for the shell; all
// quoting issues are handled by the pkgsrc infrastructure.
//
// The opposite situation is when the regular expression is part of a sed
// command. In such a case the shell quoting is undone before checking the
// regular expression, and this is where spaces and tabs can appear.
//
// TODO: Add check for EREs as well.
//
// See https://pubs.opengroup.org/onlinepubs/009695399/basedefs/xbd_chap09.html#tag_09_03.
// See https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap09.html#tag_09_03.
func (cv *VartypeCheck) BasicRegularExpression() {

	// same order as in the OpenGroup spec
	allowedAfterBackslash := textproc.NewByteSet(")({}1-9.[\\*^$")

	lexer := textproc.NewLexer(cv.ValueNoVar)

	parseCharacterClass := func() {
		for !lexer.EOF() {
			if lexer.SkipByte('\\') {
				if !lexer.EOF() {
					lexer.Skip(1)
				}
			} else if lexer.SkipByte(']') {
				return
			} else {
				lexer.Skip(1)
			}
		}
	}

	parseBackslash := func() {
		if lexer.EOF() {
			return
		}

		if !lexer.TestByteSet(allowedAfterBackslash) {
			cv.Warnf("In a basic regular expression, a backslash followed by %q is undefined.", lexer.Rest()[:1])
			cv.Explain(
				"Only the characters . [ \\ * ^ $ may be escaped using a backslash.",
				"Except when the escaped character appears in a character class like [\\.a-z].",
				"",
				"To fix this, remove the backslash before the character.")
		}
		lexer.Skip(1)
	}

	for !lexer.EOF() {
		switch {
		case lexer.SkipByte('['):
			parseCharacterClass()

		case lexer.SkipByte('\\'):
			parseBackslash()

		case lexer.Skip(1):
		}
	}
}

func (cv *VartypeCheck) BuildlinkDepmethod() {
	if cv.Value == cv.ValueNoVar && cv.Value != "build" && cv.Value != "full" {
		cv.Warnf("Invalid dependency method %q. Valid methods are \"build\" or \"full\".", cv.Value)
	}
}

func (cv *VartypeCheck) Category() {
	if cv.Value != "wip" && G.Pkgsrc.File(NewPkgsrcPath(NewPath(cv.Value)).JoinNoClean("Makefile")).IsFile() {
		return
	}

	switch cv.Value {
	case
		"chinese",
		"gnome", "gnustep",
		"japanese", "java",
		"kde", "korean",
		"linux", "local", "lua",
		"perl5", "plan9", "python",
		"R", "ruby",
		"scm",
		"tcl", "tk",
		"windowmaker",
		"xmms":
	default:
		cv.Errorf("Invalid category %q.", cv.Value)
	}
}

// CFlag is a single option to the C/C++ compiler.
func (cv *VartypeCheck) CFlag() {
	if cv.Op == opUseMatch {
		return
	}

	cflag := cv.Value
	switch {
	case hasPrefix(cflag, "-l"), hasPrefix(cflag, "-L"):
		cv.Warnf("%q is a linker flag and belong to LDFLAGS, LIBS or LDADD instead of %s.",
			cflag, cv.Varname)
	}

	if strings.Count(cflag, "\"")%2 != 0 {
		cv.Warnf("Compiler flag %q has unbalanced double quotes.", cflag)
	}
	if strings.Count(cflag, "'")%2 != 0 {
		cv.Warnf("Compiler flag %q has unbalanced single quotes.", cflag)
	}
}

// Comment checks for the single-line description of a package.
//
// The comment for categories is checked in CheckdirCategory since these
// almost never change.
func (cv *VartypeCheck) Comment() {
	value := cv.Value

	// See pkgtools/url2pkg/files/url2pkg.py, keyword 'COMMENT'.
	if value == "TODO: Short description of the package" {
		cv.Errorf("COMMENT must be set.")
	}

	if m, first := match1(value, `^(?i)(a|an)[\t ]`); m {
		cv.Warnf("COMMENT should not begin with %q.", first)
	}

	pkg := cv.MkLines.pkg
	if pkg != nil && pkg.EffectivePkgbase != "" {
		prefix := strings.ToLower(pkg.EffectivePkgbase + " ")
		if hasPrefix(strings.ToLower(value), prefix) {
			cv.Warnf("COMMENT should not start with the package name.")
			cv.Explain(
				"The COMMENT is usually displayed together with the package name.",
				"Therefore it does not need to repeat the package name but should",
				"provide additional information instead.")
		}
	}

	if matches(value, `^[a-z]`) && cv.Op == opAssign {
		cv.Warnf("COMMENT should start with a capital letter.")
	}

	if m, isA := match1(value, `\b(is an?)\b`); m {
		cv.Warnf("COMMENT should not contain %q.", isA)
		cv.Explain(
			"The words \"package is a\" are redundant.",
			"Since every package comment could start with them,",
			"it is better to remove this redundancy in all cases.")
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
	words := cv.MkLine.ValueFields(cv.Value)
	if len(words)%2 != 0 {
		cv.Warnf("Values for %s should always be pairs of paths.", cv.Varname)
	}

	for i, word := range words {
		cv.WithValue(word).PathnameSpace()

		if i%2 == 1 && !matches(word, `["']*\$\{`) {
			cv.Warnf("The destination file %q should start with a variable reference.", word)
			cv.Explain(
				"Since pkgsrc can be installed in different locations, the",
				"configuration files will also end up in different locations.",
				"Typical variables that are used for configuration files are",
				"PKG_SYSCONFDIR, PKG_SYSCONFBASE, PREFIX, VARBASE.")
		}
	}
}

func (cv *VartypeCheck) DependencyPattern() {
	value := cv.Value

	parser := NewMkParser(nil, value)
	deppat := parser.DependencyPattern()
	rest := parser.Rest()

	if deppat != nil && deppat.Wildcard == "" && (rest == "{,nb*}" || rest == "{,nb[0-9]*}") {
		cv.Warnf("Dependency patterns of the form pkgbase>=1.0 don't need the \"{,nb*}\" extension.")
		cv.Explain(
			"The \"{,nb*}\" extension is only necessary for dependencies of the",
			"form \"pkgbase-1.2\", since the pattern \"pkgbase-1.2\" doesn't match",
			"the version \"pkgbase-1.2nb5\".",
			"For dependency patterns using the comparison operators,",
			"this is not necessary.")

	} else if deppat == nil && contains(cv.ValueNoVar, "{") {
		// Don't warn about complicated patterns like "{ssh{,6}>=0,openssh>=0}"
		// that pkglint doesn't understand as of January 2019.
		return

	} else if deppat == nil || rest != "" {
		cv.Warnf("Invalid dependency pattern %q.", value)
		cv.Explain(
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
			cv.Explain(
				"The pattern -[0-9] means any version.",
				"All other version patterns should be expressed using",
				"the comparison operators like < or >= or even >=2<3.",
				"",
				"Patterns like -[0-7] will only match the first digit of the version",
				"number and will not do the correct thing when the package reaches",
				"version 10.")
		}

	} else if m, ver, suffix := match2(wildcard, `^(\d\w*(?:\.\w+)*)(\.\*|\{,nb\*\}|\{,nb\[0-9\]\*\}|\*|)$`); m {
		if suffix == "" {
			cv.Warnf("Please use %q instead of %q as the version pattern.", ver+"{,nb*}", ver)
			cv.Explain(
				"Without the \"{,nb*}\" suffix, this version pattern only matches",
				"package versions that don't have a PKGREVISION (which is the part",
				"after the \"nb\").")
		}
		if suffix == "*" {
			cv.Warnf("Please use %q instead of %q as the version pattern.", ver+".*", ver+"*")
			cv.Explain(
				"For example, the version \"1*\" also matches \"10.0.0\", which is",
				"probably not intended.")
		}

	} else if wildcard == "*" {
		cv.Warnf("Please use \"%[1]s-[0-9]*\" instead of \"%[1]s-*\".", deppat.Pkgbase)
		cv.Explain(
			"If you use a * alone, the package specification may match other",
			"packages that have the same prefix but a longer name.",
			"For example, foo-* matches foo-1.2 but also",
			"foo-client-1.2 and foo-server-1.2.")
	}

	withoutCharClasses := replaceAll(wildcard, `\[[\d-]+\]`, "")
	if contains(withoutCharClasses, "-") {
		cv.Warnf("The version pattern %q should not contain a hyphen.", wildcard)
		cv.Explain(
			"Pkgsrc interprets package names with version numbers like this:",
			"",
			"\t\"foo-2.0-2.1.x\" => pkgbase \"foo\", version \"2.0-2.1.x\"",
			"",
			"To make the \"2.0\" above part of the package basename, the hyphen",
			"must be omitted, so the full package name becomes \"foo2.0-2.1.x\".")
	}

	checkDepends := func(
		prefix string,
		depends func(data *Buildlink3Data) *DependencyPattern,
		dependsLine func(data *Buildlink3Data) *MkLine,
	) {
		if deppat.LowerOp == "" {
			return
		}
		pkg := cv.MkLines.pkg
		if pkg == nil {
			return
		}
		if !hasPrefix(cv.Varname, prefix) {
			return
		}
		bl3id := Buildlink3ID(varnameParam(cv.Varname))
		data := pkg.bl3Data[bl3id]
		if data == nil {
			return
		}
		defpat := depends(data)
		if defpat == nil || defpat.LowerOp == "" {
			return
		}
		limit := condInt(defpat.LowerOp == ">=" && deppat.LowerOp == ">", 1, 0)
		if pkgver.Compare(deppat.Lower, defpat.Lower) < limit {
			cv.Notef("The requirement %s%s is already guaranteed by the %s%s from %s.",
				deppat.LowerOp, deppat.Lower, defpat.LowerOp, defpat.Lower,
				cv.MkLine.RelMkLine(dependsLine(data)))
		}
	}

	checkDepends(
		"BUILDLINK_API_DEPENDS.",
		func(data *Buildlink3Data) *DependencyPattern { return data.apiDepends },
		func(data *Buildlink3Data) *MkLine { return data.apiDependsLine },
	)
	checkDepends(
		"BUILDLINK_ABI_DEPENDS.",
		func(data *Buildlink3Data) *DependencyPattern { return data.abiDepends },
		func(data *Buildlink3Data) *MkLine { return data.abiDependsLine })
}

func (cv *VartypeCheck) DependencyWithPath() {
	value := cv.Value
	valueNoVar := cv.ValueNoVar

	if valueNoVar == "" || valueNoVar == ":" {
		return
	}

	parts := cv.MkLine.ValueSplit(value, ":")
	if len(parts) != 2 {
		cv.Warnf("Invalid dependency pattern with path %q.", value)
		cv.Explain(
			"Examples for valid dependency patterns with path are:",
			"  package-[0-9]*:../../category/package",
			"  package>=3.41:../../category/package",
			"  package-2.718{,nb*}:../../category/package")
		return
	}

	pattern := parts[0]
	dependencyDir := NewPath(parts[1])
	if dependencyDir.IsAbs() {
		cv.Errorf("Dependency paths like %q must be relative.", parts[1])
		return
	}

	pathParts := dependencyDir.Parts()
	if len(pathParts) >= 2 && pathParts[0] == ".." && pathParts[1] != ".." {
		cv.Warnf("Dependency paths should have the form \"../../category/package\".")
		cv.MkLine.ExplainRelativeDirs()
	}

	if !containsVarUse(parts[1]) {
		ck := MkLineChecker{cv.MkLines, cv.MkLine}
		rel := NewRelPath(dependencyDir)
		ck.CheckRelativePkgdir(rel, NewPackagePath(rel))
	}

	pkg := pathParts[len(pathParts)-1]
	switch pkg {
	case "gettext":
		cv.Warnf("Please use USE_TOOLS+=msgfmt instead of this dependency.")
	case "perl5":
		cv.Warnf("Please use USE_TOOLS+=perl:run instead of this dependency.")
	case "gmake":
		cv.Warnf("Please use USE_TOOLS+=gmake instead of this dependency.")
	}

	cv.WithValue(pattern).DependencyPattern()
}

func (cv *VartypeCheck) DistSuffix() {
	if cv.Value == ".tar.gz" && !hasPrefix(cv.MkComment, "#") {
		cv.Notef("%s is \".tar.gz\" by default, so this definition may be redundant.", cv.Varname)
		cv.Explain(
			"To check whether the definition is really redundant:",
			"",
			sprintf("\t1. run %q", bmake("show-var VARNAME="+cv.Varname)),
			"\t2. remove this definition",
			sprintf("\t3. run %q again", bmake("show-var VARNAME="+cv.Varname)),
			"",
			"If the values from step 1 and step 3 really differ, add a comment to this line",
			"in the Makefile that this (apparently redundant) definition is really needed.")
	}
}

func (cv *VartypeCheck) EmulPlatform() {
	const rePart = `(?:\[[^\]]+\]|[^-\[])+`
	const rePair = `^(` + rePart + `)-(` + rePart + `)$`
	if m, opsysPattern, archPattern := match2(cv.Value, rePair); m {
		opsysCv := cv.WithVarnameValue("the operating system part of "+cv.Varname, opsysPattern)
		BtEmulOpsys.checker(opsysCv)

		archCv := cv.WithVarnameValue("the hardware architecture part of "+cv.Varname, archPattern)
		BtEmulArch.checker(archCv)
	} else {
		cv.Warnf("%q is not a valid emulation platform.", cv.Value)
		cv.Explain(
			"An emulation platform has the form <OPSYS>-<MACHINE_ARCH>.",
			"OPSYS is the lower-case name of the operating system, and",
			"MACHINE_ARCH is the hardware architecture.",
			"",
			"Examples:",
			"* linux-i386",
			"* irix-mipsel")
	}
}

// Enum checks an enumeration for valid values.
//
// The given allowedValues contains all allowed enum values.
// The given basicType is only provided to lazily access the allowed enum values as a sorted list.
func (cv *VartypeCheck) Enum(allowedValues map[string]bool, basicType *BasicType) {
	if cv.Op == opUseMatch {
		if !allowedValues[cv.Value] && cv.Value == cv.ValueNoVar {
			canMatch := false
			for value := range allowedValues {
				if ok, err := path.Match(cv.Value, value); err != nil {
					cv.Warnf("Invalid match pattern %q.", cv.Value)
					return
				} else if ok {
					canMatch = true
				}
			}
			if !canMatch {
				cv.Warnf("The pattern %q cannot match any of { %s } for %s.",
					cv.Value, basicType.AllowedEnums(), cv.Varname)
			}
		}
		return
	}

	if cv.Value == cv.ValueNoVar && !allowedValues[cv.Value] {
		cv.Warnf("%q is not valid for %s. Use one of { %s } instead.",
			cv.Value, cv.Varname, basicType.AllowedEnums())
	}
}

func (cv *VartypeCheck) FetchURL() {
	fetchURL := cv.Value
	url := strings.TrimPrefix(fetchURL, "-")
	hyphen := condStr(len(fetchURL) > len(url), "-", "")
	hyphenSubst := condStr(hyphen != "", ":S,^,-,", "")

	cv.WithValue(url).URL()

	trimURL := url[len(url)-len(replaceAll(url, `^\w+://`, "")):]
	protoLen := len(url) - len(trimURL)

	for trimSiteURL, siteName := range G.Pkgsrc.MasterSiteURLToVar {
		if !hasPrefix(trimURL, trimSiteURL) {
			continue
		}
		if siteName == "MASTER_SITE_GITHUB" &&
			hasPrefix(cv.Varname, "SITES.") {
			continue
		}

		subdir := trimURL[len(trimSiteURL):]
		if hasPrefix(trimURL, "github.com/") {
			subdir = strings.SplitAfter(subdir, "/")[0]
			commonPrefix := hyphen + url[:protoLen+len(trimSiteURL)+len(subdir)]
			cv.Warnf("Please use ${%s%s:=%s} instead of %q and run %q for further instructions.",
				siteName, hyphenSubst, subdir, commonPrefix, bmakeHelp("github"))
		} else {
			cv.Warnf("Please use ${%s%s:=%s} instead of %q.", siteName, hyphenSubst, subdir, hyphen+url)
		}
		return
	}

	tokens := cv.MkLine.Tokenize(url, false)
	for _, token := range tokens {
		varUse := token.Varuse
		if varUse == nil {
			continue
		}

		name := varUse.varname
		if !hasPrefix(name, "MASTER_SITE_") {
			continue
		}

		if G.Pkgsrc.MasterSiteVarToURL[name] == "" {
			if cv.MkLines.pkg == nil || !cv.MkLines.pkg.vars.IsDefined(name) {
				cv.Errorf("The site %s does not exist.", name)
			}
		}

		if len(varUse.modifiers) != 1 || !varUse.modifiers[0].HasPrefix("=") {
			continue
		}

		subdir := varUse.modifiers[0].String()[1:]
		if !hasSuffix(subdir, "/") {
			cv.Errorf("The subdirectory in %s must end with a slash.", name)
		}
	}

	switch {
	case cv.Op == opUseMatch,
		hasSuffix(fetchURL, "/"),
		hasSuffix(fetchURL, "="),
		hasSuffix(fetchURL, ":"),
		hasPrefix(fetchURL, "-"),
		tokens[len(tokens)-1].Varuse != nil:
		break

	default:
		cv.Warnf("The fetch URL %q should end with a slash.", fetchURL)
		cv.Explain(
			"The filename from DISTFILES is appended directly to this base URL.",
			"Therefore it should typically end with a slash, or sometimes with",
			"an equals sign or a colon.",
			"",
			"To specify a full URL directly, prefix it with a hyphen, such as in",
			"-https://example.org/distfile-1.0.tar.gz.")
	}
}

// Filename checks that filenames use only limited special characters.
//
// See http://www.opengroup.org/onlinepubs/009695399/basedefs/xbd_chap03.html#tag_03_169
func (cv *VartypeCheck) Filename() {
	valid := regex.Pattern(condStr(
		cv.Op == opUseMatch,
		`[%*+,\-.0-9?@A-Z\[\]_a-z~]`,
		`[%+,\-.0-9@A-Z_a-z~]`))

	invalid := replaceAll(cv.ValueNoVar, valid, "")
	if invalid == "" {
		return
	}

	cv.Warnf(
		condStr(cv.Op == opUseMatch,
			"The filename pattern %q contains the invalid character%s %q.",
			"The filename %q contains the invalid character%s %q."),
		cv.Value,
		condStr(len(invalid) > 1, "s", ""),
		invalid)
}

func (cv *VartypeCheck) FilePattern() {

	invalid := replaceAll(cv.ValueNoVar, `[%*+,\-.0-9?@A-Z\[\]_a-z~]`, "")
	if invalid == "" {
		return
	}

	cv.Warnf("The filename pattern %q contains the invalid character%s %q.",
		cv.Value,
		condStr(len(invalid) > 1, "s", ""),
		invalid)
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

// GitTag checks for a fixed reference to a Git commit.
//
// https://git-scm.com/docs/gitrevisions
func (cv *VartypeCheck) GitTag() {
	tag := cv.ValueNoVar

	valid := textproc.NewByteSet("0-9A-Za-z-+._/")
	invalid := invalidCharacters(tag, valid)
	if invalid != "" {
		cv.Warnf("Invalid characters %q in Git tag.", invalid)
		return
	}

	if tag == "master" || hasPrefix(tag, "refs/heads/") {
		cv.Warnf("The Git tag %q refers to a moving target.", tag)
		return
	}

	if len(tag) < 7 && matches(tag, `^[A-Fa-f0-9]+$`) {
		cv.Warnf("The git commit name %q is too short to be reliable.", tag)
	}
}

func (cv *VartypeCheck) GoModuleFile() {
	tag := cv.ValueNoVar

	valid := textproc.NewByteSet("!0-9@A-Za-z-+._/")
	invalid := invalidCharacters(tag, valid)
	if invalid != "" {
		cv.Warnf("Invalid characters %q in Go modules filename.", invalid)
		return
	}
}

func (cv *VartypeCheck) Homepage() {
	cv.URL()

	ck := NewHomepageChecker(cv.Value, cv.ValueNoVar, cv.MkLine, cv.MkLines)
	ck.Check()
}

// IdentifierDirect checks for valid identifiers in various contexts,
// limiting the valid characters to A-Za-z0-9_.
func (cv *VartypeCheck) IdentifierDirect() {
	if cv.Op == opUseMatch {
		if cv.Value == cv.ValueNoVar && !matches(cv.Value, `^[\w*\-?\[\]]+$`) {
			cv.Warnf("Invalid identifier pattern %q for %s.", cv.Value, cv.Varname)
		}
		return
	}

	if cv.Value != cv.ValueNoVar {
		cv.Errorf("Identifiers for %s must not refer to other variables.", cv.Varname)
		return
	}

	if !matches(cv.ValueNoVar, `^[+\-.\w]+$`) {
		cv.Warnf("Invalid identifier %q.", cv.Value)
	}
}

// IdentifierIndirect checks for valid identifiers in various contexts,
// limiting the valid characters to A-Za-z0-9_.
func (cv *VartypeCheck) IdentifierIndirect() {
	if cv.Value == cv.ValueNoVar {
		cv.IdentifierDirect()
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
	case ldflag == "-P",
		ldflag == "-E",
		hasPrefix(ldflag, "-D"),
		hasPrefix(ldflag, "-U"),
		hasPrefix(ldflag, "-I"):
		cv.Warnf("%q is a compiler flag and belongs on CFLAGS, CPPFLAGS, CXXFLAGS or FFLAGS instead of %s.", cv.Value, cv.Varname)
	}
}

func (cv *VartypeCheck) License() {
	(&LicenseChecker{cv.MkLines, cv.MkLine}).Check(cv.Value, cv.Op)
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
		BtMachineGnuArch.checker(archCv)

		_ = vendorPattern

		opsysCv := cv.WithVarnameValueMatch(
			"the operating system part of "+cv.Varname,
			opsysPattern)
		BtMachineGnuPlatformOpsys.checker(opsysCv)

	} else {
		cv.Warnf("%q is not a valid platform pattern.", cv.Value)
		cv.Explain(
			"A platform pattern has the form <OPSYS>-<OS_VERSION>-<MACHINE_ARCH>.",
			"Each of these components may use wildcards.",
			"",
			"Examples:",
			"* NetBSD-[456].*-i386",
			"* *-*-*",
			"* Linux-*-*")
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
		// This is cheated, but the dynamically loaded enums are not
		// provided in a type registry where they could be looked up
		// by a name. The following line therefore assumes that OPSYS
		// is an operating system name, which sounds like a safe bet.
		btOpsys := G.Pkgsrc.vartypes.types["OPSYS"].basicType

		opsysCv := cv.WithVarnameValueMatch("the operating system part of "+cv.Varname, opsysPattern)
		btOpsys.checker(opsysCv)

		versionCv := cv.WithVarnameValueMatch("the version part of "+cv.Varname, versionPattern)
		versionCv.Version()

		archCv := cv.WithVarnameValueMatch("the hardware architecture part of "+cv.Varname, archPattern)
		BtMachineArch.checker(archCv)

	} else {
		cv.Warnf("%q is not a valid platform pattern.", cv.Value)
		cv.Explain(
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

func (cv *VartypeCheck) MakeTarget() {
	if cv.Op == opUseMatch || cv.ValueNoVar != cv.Value {
		return
	}

	if !matches(cv.ValueNoVar, `^[+\-.\w/]+$`) {
		cv.Warnf("Invalid make target %q.", cv.Value)
	}
}

// Message is a plain string. When defining a message variable, it should
// not be enclosed in quotes since that is the job of the code that uses
// the message.
//
// Lists of messages use a different type since they need the quotes
// around each message; see PKG_FAIL_REASON.
func (cv *VartypeCheck) Message() {
	varname, value := cv.Varname, cv.Value

	if matches(value, `^[\"'].*[\"']$`) {
		cv.Warnf("%s should not be quoted.", varname)
		cv.Explain(
			"The quoting is only needed for variables which are interpreted as",
			"multiple words (or, generally speaking, a list of something).",
			"A single text message does not belong to this class,",
			"since it is only printed as a whole.")
	}
}

// Option checks whether a single package option from an options.mk file
// conforms to the naming conventions.
//
// This check only handles option names, as in PKG_SUPPORTED_OPTIONS or
// PKG_SUGGESTED_OPTIONS. It does not handle option selections, which may
// pre prefixed with a hyphen to disable the option. Option selections
// are all user-settable and therefore are out of scope for pkglint.
func (cv *VartypeCheck) Option() {
	value := cv.Value

	if value != cv.ValueNoVar {
		return
	}

	validName := regex.Pattern(`^([a-z][-0-9a-z_+]*)$`)
	if cv.Op == opUseMatch {
		validName = `^([a-z][*+\-0-9?\[\]_a-z]*)$`
	}

	m, optname := match1(value, validName)
	if !m {
		cv.Errorf("Invalid option name %q. Option names must start with a lowercase letter and be all-lowercase.", value)
		return
	}

	if !cv.MkLines.once.FirstTimeSlice("option:", optname) {
		return
	}

	if contains(optname, "_") {
		cv.Warnf("Use of the underscore character in option names is deprecated.")
		return
	}

	if !strings.ContainsAny(optname, "*?[") {
		if _, found := G.Pkgsrc.PkgOptions[optname]; !found {
			cv.Warnf("Undocumented option %q.", optname)
			cv.Explain(
				"This option is not documented in the mk/defaults/options.description file.",
				"Please think of a brief but precise description and either",
				"update that file yourself or suggest a description for this option",
				"on the tech-pkg@NetBSD.org mailing list.")
		}
	}
}

// Pathlist checks variables like the PATH environment variable.
func (cv *VartypeCheck) Pathlist() {
	value := cv.Value

	// Sometimes, variables called PATH contain a single pathname,
	// especially those with auto-guessed type from MkLine.VariableType.
	if !contains(value, ":") && cv.Guessed {
		cv.Pathname()
		return
	}

	for _, dir := range cv.MkLine.ValueSplit(value, ":") {

		dirNoVar := cv.MkLine.WithoutMakeVariables(dir)
		if !matches(dirNoVar, `^[-0-9A-Za-z._~+%/]*$`) {
			cv.Warnf("%q is not a valid pathname.", dir)
		}

		if !hasPrefix(dir, "/") && !hasPrefix(dir, "${") {
			cv.Errorf("The component %q of %s must be an absolute path.", dir, cv.Varname)
			cv.Explain(
				"Relative paths in the PATH variable are a security risk.",
				"They also make the execution unreliable since they are",
				"evaluated relative to the current directory of the process,",
				"which means that after a \"cd\", different commands might be run.")
		}
	}
}

// PathPattern is a shell pattern for pathnames, possibly including slashes.
//
// Spaces, backslashes and quotes are rarely needed but still allowed.
// Without these characters, the patterns would need to use '?', which does
// not represent the intended patterns exactly.
//
// See FilePattern.
func (cv *VartypeCheck) PathPattern() {
	invalid := replaceAll(cv.ValueNoVar, `[ "%'*+,\-./0-9?@A-Z\[\\\]_a-z~]`, "")
	if invalid == "" {
		return
	}

	cv.Warnf("The pathname pattern %q contains the invalid character%s %q.",
		cv.Value,
		condStr(len(invalid) > 1, "s", ""),
		invalid)
}

// Pathname checks for pathnames.
//
// Like Filename, but including slashes.
//
// See http://www.opengroup.org/onlinepubs/009695399/basedefs/xbd_chap03.html#tag_03_266
func (cv *VartypeCheck) Pathname() {
	valid := regex.Pattern(condStr(
		cv.Op == opUseMatch,
		`[!%*+,\-./0-9?@A-Z\[\]_a-z~]`,
		`[!%+,\-./0-9@A-Z_a-z~]`))
	invalid := replaceAll(cv.ValueNoVar, valid, "")
	if invalid == "" {
		return
	}

	cv.Warnf(
		condStr(cv.Op == opUseMatch,
			"The pathname pattern %q contains the invalid character%s %q.",
			"The pathname %q contains the invalid character%s %q."),
		cv.Value,
		condStr(len(invalid) > 1, "s", ""),
		invalid)
}

// PathnameSpace is like Pathname, but may contain spaces as well.
// Because the spaces must be quoted, backslashes and quotes are allowed as
// well.
func (cv *VartypeCheck) PathnameSpace() {
	valid := regex.Pattern(condStr(
		cv.Op == opUseMatch,
		`[ "%'*+,\-./0-9?@A-Z\[\\\]_a-z~]`,
		`[ "%'+,\-./0-9@A-Z\\_a-z~]`))
	invalid := replaceAll(cv.ValueNoVar, valid, "")
	if invalid == "" {
		return
	}

	cv.Warnf(
		condStr(cv.Op == opUseMatch,
			"The pathname pattern %q contains the invalid character%s %q.",
			"The pathname %q contains the invalid character%s %q."),
		cv.Value,
		condStr(len(invalid) > 1, "s", ""),
		invalid)
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

	if cv.Op != opUseMatch && value == cv.ValueNoVar && !matchesPkgname(value) {
		cv.Warnf("%q is not a valid package name.", value)
		cv.Explain(
			"A valid package name has the form packagename-version, where version",
			"consists only of digits, letters and dots.")
	}

	if matches(value, `nb\d+$`) {
		cv.Errorf("The \"nb\" part of the version number belongs in PKGREVISION.")
	}
}

func (cv *VartypeCheck) PkgOptionsVar() {
	cv.VariableName()

	// TODO: Replace regex with proper VarUse.
	if matches(cv.Value, `\$\{PKGBASE[:\}]`) {
		cv.Errorf("PKGBASE must not be used in PKG_OPTIONS_VAR.")
		cv.Explain(
			"PKGBASE is defined in bsd.pkg.mk, which is included as the",
			"very last file, but PKG_OPTIONS_VAR is evaluated earlier.",
			"Use ${PKGNAME:C/-[0-9].*//} instead.")
	}

	// PR 46570, item "6. It should complain in PKG_OPTIONS_VAR is wrong"
	if !hasPrefix(cv.Value, "PKG_OPTIONS.") {
		cv.Errorf("PKG_OPTIONS_VAR must be of the form %q, not %q.", "PKG_OPTIONS.*", cv.Value)
	}
}

// Pkgpath checks a directory name relative to the top-level pkgsrc directory.
//
// Despite its name, it is more similar to RelativePkgDir than to RelativePkgPath.
func (cv *VartypeCheck) Pkgpath() {
	cv.Pathname()

	value := cv.Value
	if value != cv.ValueNoVar || cv.Op == opUseMatch {
		return
	}

	pkgpath := NewPkgsrcPath(NewPath(value))
	if !G.Wip && pkgpath.HasPrefixPath("wip") {
		cv.Errorf("A main pkgsrc package must not depend on a pkgsrc-wip package.")
	}

	pkgdir := G.Pkgsrc.File(pkgpath)
	if !pkgdir.JoinNoClean("Makefile").IsFile() {
		cv.Errorf("There is no package in %q.",
			cv.MkLine.Rel(pkgdir))
		return
	}

	if !matches(value, `^([^./][^/]*/[^./][^/]*)$`) {
		cv.Errorf("%q is not a valid path to a package.", pkgpath.String())
		cv.Explain(
			"A path to a package has the form \"category/pkgbase\".",
			"It is relative to the pkgsrc root.")
	}
}

func (cv *VartypeCheck) Pkgrevision() {
	if !matches(cv.Value, `^[1-9]\d*$`) {
		cv.Errorf("%s must be a positive integer number.", cv.Varname)
	}
	if cv.MkLine.Basename != "Makefile" {
		cv.Errorf("%s only makes sense directly in the package Makefile.", cv.Varname)
		cv.Explain(
			"Usually, different packages using the same Makefile.common have",
			"different dependencies and will be bumped at different times (e.g.",
			"for shlib major bumps) and thus the PKGREVISIONs must be in the",
			"separate Makefiles.",
			"There is no practical way of having this information in a commonly used Makefile.")
	}
}

// PlistIdentifier checks for valid condition identifiers in PLIST_VARS.
//
// These identifiers are interpreted as regular expressions by
// mk/plist/plist-subst.mk, therefore they are limited to very
// few characters.
func (cv *VartypeCheck) PlistIdentifier() {
	cond := cv.Value
	if cond != cv.ValueNoVar {
		return
	}

	if cv.Op == opUseMatch {
		invalidPatternChars := textproc.NewByteSet("A-Za-z0-9-_*?[]")
		invalid := invalidCharacters(cond, invalidPatternChars)
		if invalid != "" {
			cv.Warnf("PLIST identifier pattern %q contains invalid characters (%s).",
				cond, invalid)
			cv.Explain(
				"PLIST identifiers must consist of [A-Za-z0-9-_] only.",
				"In patterns, the characters *?[] are allowed additionally.")
		}
		return
	}

	invalidChars := textproc.NewByteSet("A-Za-z0-9-_")
	invalid := invalidCharacters(cond, invalidChars)
	if invalid != "" {
		cv.Errorf("PLIST identifier %q contains invalid characters (%s).",
			cond, invalid)
		cv.Explain(
			"PLIST identifiers must consist of [A-Za-z0-9-_] only.")
		return
	}

	if cv.MkLines.pkg != nil && !cv.MkLines.pkg.Plist.Conditions[cond] {
		cv.Warnf("PLIST identifier %q is not used in any PLIST file.", cond)
		cv.Explain(
			"For every identifier that is added to PLIST_VARS,",
			"there should be a corresponding ${PLIST.identifier}",
			"in any of the PLIST files of the package.")
	}
}

// PrefixPathname checks for a pathname relative to ${PREFIX}.
func (cv *VartypeCheck) PrefixPathname() {
	if NewPath(cv.Value).IsAbs() {
		cv.Errorf("The pathname %q in %s must be relative to ${PREFIX}.",
			cv.Value, cv.Varname)
		return
	}

	cv.MkLine.ForEachUsedText(cv.Value, VucRunTime, func(varUse *MkVarUse, time VucTime) {
		varname := varUse.varname
		if varname == "PKG_SYSCONFDIR" || varname == "VARBASE" {
			cv.Errorf("%s must not be used in %s since it is not relative to PREFIX.",
				varname, cv.Varname)
		}
	})

	if hasPrefix(cv.Value, "man/") && cv.Varname != "INSTALLATION_DIRS" {
		from := "${PKGMANDIR}/" + cv.Value[4:]
		fix := cv.Autofix()
		fix.Warnf("Please use %q instead of %q.", from, cv.Value)
		fix.Replace(cv.Value, from)
		fix.Apply()
	}
}

func (cv *VartypeCheck) PythonDependency() {
	if cv.Value != cv.ValueNoVar {
		cv.Warnf("Python dependencies should not contain variables.")
	} else if !matches(cv.ValueNoVar, `^[+\-.0-9A-Z_a-z]+(?:|:link|:build|:test|:tool)$`) {
		cv.Warnf("Invalid Python dependency %q.", cv.Value)
		cv.Explain(
			"Python dependencies must be an identifier for a package, as",
			"specified in lang/python/versioned_dependencies.mk.",
			"This identifier may be followed by:",
			"\t:tool for a tool dependency,",
			"\t:build for a build-time only dependency,",
			"\t:test for a test-only dependency,",
			"\t:link for a run-time dependency.")
	}
}

func (cv *VartypeCheck) RPkgName() {
	if cv.Op == opUseMatch {
		return
	}

	if cv.Value != cv.ValueNoVar {
		cv.Warnf("The R package name should not contain variables.")
		return
	}

	if hasPrefix(cv.Value, "R-") {
		cv.Warnf("The %s does not need the %q prefix.", cv.Varname, "R-")
	}

	invalid := replaceAll(cv.Value, `[\w\-.+]`, "")
	if invalid != "" {
		cv.Warnf("The R package name contains the invalid characters %q.", invalid)
	}
}

func (cv *VartypeCheck) RPkgVer() {
	value := cv.Value
	if cv.Op != opUseMatch && value == cv.ValueNoVar && !matches(value, `^\d[\w-.]*$`) {
		cv.Warnf("Invalid R version number %q.", value)
	}
}

// RelativePkgDir refers from one package directory to another package
// directory, e.g. ../../category/pkgbase.
func (cv *VartypeCheck) RelativePkgDir() {
	if NewPath(cv.Value).IsAbs() {
		cv.Errorf("The path %q must be relative.", cv.Value)
		return
	}

	ck := MkLineChecker{cv.MkLines, cv.MkLine}
	packagePath := NewPackagePathString(cv.Value)
	ck.CheckRelativePkgdir(packagePath.AsRelPath(), packagePath)
}

// RelativePkgPath refers from one package directory to another file
// or directory, e.g. ../../category/pkgbase,
// ../../category/pkgbase/Makefile.
//
// See RelativePkgDir, which requires a directory, not a file.
func (cv *VartypeCheck) RelativePkgPath() {
	if NewPath(cv.Value).IsAbs() {
		cv.Errorf("The path %q must be relative.", cv.Value)
		return
	}

	packagePath := NewPackagePathString(cv.Value)
	ck := MkLineChecker{cv.MkLines, cv.MkLine}
	ck.CheckRelativePath(packagePath, packagePath.AsRelPath(), true)
}

func (cv *VartypeCheck) Restricted() {
	if cv.Value != "${RESTRICTED}" {
		cv.Warnf("The only valid value for %s is ${RESTRICTED}.", cv.Varname)
		cv.Explain(
			"These variables are used to control which files may be mirrored on",
			"FTP servers or CD-ROM collections.",
			"They are not intended to mark",
			"packages whose only MASTER_SITES are on ftp.NetBSD.org.")
	}
}

func (cv *VartypeCheck) SedCommands() {
	tokens, rest := splitIntoShellTokens(cv.MkLine.Line, cv.Value)
	if rest != "" {
		if contains(cv.MkLine.Text, "#") {
			cv.Errorf("Invalid shell words %q in sed commands.", rest)
			cv.Explain(
				"When sed commands have embedded \"#\" characters, they need to be",
				"escaped with a backslash, otherwise make(1) will interpret them as a",
				"comment, even if they occur in single or double quotes or whatever.")
		}
		return
	}

	ntokens := len(tokens)
	ncommands := 0
	extended := false

	checkSedCommand := func(quotedCommand string) {
		// TODO: Remember the extended flag for the whole file, especially
		//  for SUBST_SED.* variables.
		if !extended {
			command := cv.MkLine.UnquoteShell(quotedCommand, true)
			if !hasPrefix(command, "s") {
				return
			}

			// The :C modifier is similar enough for parsing.
			ok, _, from, _, _ := MkVarUseModifier("C" + command[1:]).MatchSubst()
			if !ok {
				return
			}

			cv.WithValue(from).BasicRegularExpression()
		}
	}

	for i := 0; i < ntokens; i++ {
		token := tokens[i]

		switch {
		case token == "-e":
			if i+1 >= ntokens {
				cv.Errorf("The -e option to sed requires an argument.")
				break
			}

			// Check the real sed command here.
			i++
			ncommands++
			if ncommands > 1 {
				cv.Warnf("Each sed command should appear in an assignment of its own.")
				cv.Explain(
					"For example, instead of",
					"    SUBST_SED.foo+=        -e s,command1,, -e s,command2,,",
					"use",
					"    SUBST_SED.foo+=        -e s,command1,,",
					"    SUBST_SED.foo+=        -e s,command2,,",
					"",
					"This way, short sed commands cannot be hidden at the end of a line.")
			}

			checkSedCommand(tokens[i])

		case token == "-E":
			// Switch to extended regular expressions mode.
			extended = true

		case token == "-n":
			// Don't print lines per default.

		case matches(token, `^["']?(\d+|/.*/)?s`):
			// TODO: "prefix with" instead of "use".
			cv.Notef("Please always use \"-e\" in sed commands, even if there is only one substitution.")
			checkSedCommand(token)

		default:
			cv.Warnf("Unknown sed command %q.", token)
		}
	}
}

func (cv *VartypeCheck) ShellCommand() {
	if cv.Op == opUseMatch || cv.Op == opUseCompare || cv.Op == opAssignAppend {
		return
	}
	setE := true
	ck := NewShellLineChecker(cv.MkLines, cv.MkLine)
	ck.checkVarUse = false
	ck.CheckShellCommand(cv.Value, &setE, RunTime)
}

// ShellCommands checks for zero or more shell commands, each terminated with a semicolon.
func (cv *VartypeCheck) ShellCommands() {
	ck := NewShellLineChecker(cv.MkLines, cv.MkLine)
	ck.checkVarUse = false
	ck.CheckShellCommands(cv.Value, RunTime)
}

func (cv *VartypeCheck) ShellWord() {
	ck := NewShellLineChecker(cv.MkLines, cv.MkLine)
	ck.checkVarUse = false
	ck.CheckWord(cv.Value, true, RunTime)
}

func (cv *VartypeCheck) Stage() {
	if !matches(cv.Value, `^(?:pre|do|post)-(?:extract|patch|configure|build|test|install)`) {
		cv.Warnf("Invalid stage name %q. Use one of {pre,do,post}-{extract,patch,configure,build,test,install}.", cv.Value)
	}
}

// ToolDependency checks for tool dependencies like "awk", "m4:pkgsrc", "digest:bootstrap".
func (cv *VartypeCheck) ToolDependency() {
	if m, toolname, tooldep := match2(cv.Value, `^([-\w]+|\[)(?::(\w+))?$`); m {
		if tool, _ := G.Tool(cv.MkLines, toolname, RunTime); tool == nil {
			cv.Errorf("Unknown tool %q.", toolname)
		}

		switch tooldep {
		case "", "bootstrap", "build", "pkgsrc", "run", "test":
		default:
			cv.Errorf("Invalid tool dependency %q. Use one of \"bootstrap\", \"build\", \"pkgsrc\", \"run\" or \"test\".", tooldep)
		}

	} else if cv.Op != opUseMatch && cv.Value == cv.ValueNoVar {
		cv.Errorf("Invalid tool dependency %q.", cv.Value)
		cv.Explain(
			"A tool dependency typically looks like \"sed\" or \"sed:run\".")
	}
}

// ToolName checks for a tool name without any trailing ":pkgsrc" or ":run".
func (cv *VartypeCheck) ToolName() {
	name := cv.Value
	nameNoVar := cv.ValueNoVar

	if contains(nameNoVar, ":") {
		cv.Errorf("%s accepts only plain tool names, without any colon.", cv.Varname)
		return
	}
	if name != nameNoVar {
		return
	}

	if !matches(name, `^([-\w]+|\[)$`) {
		cv.Errorf("Invalid tool name %q.", name)
		cv.Explain(
			"Tool names must consist of letters, digits, underscores and hyphens only.")
		return
	}
}

// Unknown doesn't check for anything.
//
// Used for:
//  - infrastructure variables that are not in vardefs.go
//  - other variables whose type is unknown or not interesting enough to
//    warrant the creation of a specialized type
func (cv *VartypeCheck) Unknown() {
	// Do nothing.
}

func (cv *VartypeCheck) URL() {
	value := cv.Value

	if value == "" && hasPrefix(cv.MkComment, "#") {
		// Ok

	} else if containsVarUse(value) {
		// No further checks

	} else if m, host := match1(value, `^(?:https?|ftp|gopher)://([-0-9A-Za-z.]+)(?::\d+)?/[-#%&+,./0-9:;=?@A-Z_a-z~]*$`); m {
		if matches(host, `(?i)\.NetBSD\.org$`) && !matches(host, `\.NetBSD\.org$`) {
			prefix := host[:len(host)-len(".NetBSD.org")]
			fix := cv.Autofix()
			fix.Warnf("Please write NetBSD.org instead of %s.", host)
			fix.Replace(host, prefix+".NetBSD.org")
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
	value := cv.Value
	if value != cv.ValueNoVar {
		return
	}
	invalid := invalidCharacters(value, textproc.NewByteSet("-0-9_a-z"))
	if invalid != "" {
		cv.Warnf("User or group name %q contains invalid characters: %s",
			value, invalid)
		return
	}

	if hasPrefix(value, "-") {
		cv.Errorf("User or group name %q must not start with a hyphen.", value)
	}
	if hasSuffix(value, "-") {
		cv.Errorf("User or group name %q must not end with a hyphen.", value)
	}
}

// VariableName checks that the value is a valid variable name to be used in Makefiles.
func (cv *VartypeCheck) VariableName() {
	// TODO: sync with MkParser.Varname
	if cv.Value == cv.ValueNoVar && !matches(cv.Value, `^[A-Z_][0-9A-Z_]*(?:[.].*)?$`) {
		cv.Warnf("%q is not a valid variable name.", cv.Value)
		cv.Explain(
			"Variable names are restricted to only uppercase letters and the",
			"underscore in the basename, and arbitrary characters in the",
			"parameterized part, following the dot.",
			"",
			"Examples:",
			"* PKGNAME",
			"* PKG_OPTIONS.gtk+-2.0")
	}
}

func (cv *VartypeCheck) VariableNamePattern() {
	if cv.Value != cv.ValueNoVar {
		return
	}

	// TODO: sync with MkParser.Varname
	if matches(cv.Value, `^[*A-Z_.][*0-9A-Z_]*(?:[.].*)?$`) {
		return
	}

	cv.Warnf("%q is not a valid variable name pattern.", cv.Value)
	cv.Explain(
		"Variable names are restricted to only uppercase letters and the",
		"underscore in the basename, and arbitrary characters in the",
		"parameterized part, following the dot.",
		"",
		"In addition to these characters, variable name patterns may use",
		"the * placeholder.",
		"",
		"Examples:",
		"* PKGNAME",
		"* PKG_OPTIONS.gtk+-2.0")
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
				cv.Explain(
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
	switch {
	case hasPrefix(cmd, "rm:-"),
		matches(cmd, `^(R|l|rpath):([^:]+):(.+)$`),
		matches(cmd, `^'?(opt|rename|rm-optarg|rmdir):.*$`),
		cmd == "-e",
		matches(cmd, `^["']?s[|:,]`):
		break

	default:
		cv.Warnf("Unknown wrapper transform command %q.", cmd)
	}
}

func (cv *VartypeCheck) WrkdirSubdirectory() {
	cv.Pathname()

	if hasPrefix(cv.Value, "${WRKDIR}/") && cv.MkLines.pkg != nil {
		distname := cv.MkLines.pkg.redundant.get("DISTNAME").vari
		if distname.IsConstant() && cv.Value[10:] == distname.ConstantValue() {
			fix := cv.Autofix()
			fix.Notef("Setting WRKSRC to %q is redundant.", cv.Value)
			fix.Delete()
			fix.Apply()

			// XXX: Resetting the Line and MkLine should be handled universally
			//  by Autofix. Without this hack, pkglint would crash later when
			//  aligning the variable assignments.
			cv.MkLine.Line.Text = ""
			cv.MkLine.data = mkLineEmpty{}
		}
	}
}

// WrksrcPathPattern is a shell pattern for existing pathnames, possibly including slashes.
func (cv *VartypeCheck) WrksrcPathPattern() {
	cv.PathPattern()

	if hasPrefix(cv.Value, "${WRKSRC}/") {
		fix := cv.Autofix()
		fix.Notef("The pathname patterns in %s don't need to mention ${WRKSRC}.", cv.Varname)
		fix.Explain(
			"These pathname patters are interpreted relative to ${WRKSRC} by definition.",
			"Therefore that part can be left out.")
		fix.Replace("${WRKSRC}/", "")
		fix.Apply()
	}
}

// WrksrcSubdirectory checks a directory relative to ${WRKSRC},
// for use in CONFIGURE_DIRS and similar variables.
func (cv *VartypeCheck) WrksrcSubdirectory() {
	if m, _, rest := match2(cv.Value, `^(\$\{WRKSRC\})(?:/(.*))?`); m {
		if rest == "" {
			rest = "."
		}

		fix := cv.Autofix()
		fix.Notef("You can use %q instead of %q.", rest, cv.Value)
		fix.Explain(
			"These directories are interpreted relative to ${WRKSRC}.")
		fix.Replace(cv.Value, rest)
		fix.Apply()

	} else if cv.ValueNoVar == "" {
		// The value of another variable

	} else if !matches(cv.ValueNoVar, `^(?:\.|[0-9A-Za-z_@][-0-9A-Za-z_@./+]*)$`) {
		cv.Warnf("%q is not a valid subdirectory of ${WRKSRC}.", cv.Value)
		cv.Explain(
			"WRKSRC should be defined so that there is no need to do anything",
			"outside of this directory.",
			"",
			"Example:",
			"",
			"\tWRKSRC=\t\t${WRKDIR}",
			"\tCONFIGURE_DIRS=\t${WRKSRC}/lib ${WRKSRC}/src",
			"\tBUILD_DIRS=\t${WRKSRC}/lib ${WRKSRC}/src ${WRKSRC}/cmd",
			"",
			seeGuide("Directories used during the build process", "build.builddirs"))
	}

	// TODO: Check for ${WRKSRC}/.. or a simple .., like in checkTextWrksrcDotDot.
}

func (cv *VartypeCheck) Yes() {
	switch cv.Op {
	case opUseMatch:
		cv.Warnf("%s should only be used in a \".if defined(...)\" condition.", cv.Varname)
		cv.Explain(
			"This variable can have only two values: defined or undefined.",
			"When it is defined, it means \"yes\", even when its value is",
			"\"no\" or the empty string.",
			"",
			"Therefore, it should not be checked by comparing its value",
			"but using \".if defined(VARNAME)\" alone.")

	default:
		if cv.Value != "YES" && cv.Value != "yes" {
			cv.Warnf("%s should be set to YES or yes.", cv.Varname)
			cv.Explain(
				"This variable means \"yes\" if it is defined, and \"no\" if it is undefined.",
				"Even when it has the value \"no\", this means \"yes\".",
				"Therefore when it is defined, its value should correspond to its meaning.")
		}
	}
}

// YesNo checks for variables that can be set to either yes or no. Undefined
// means no.
//
// Most of these variables use the lowercase yes/no variant. Some use the
// uppercase YES/NO, and the mixed forms Yes/No are practically never seen.
// Testing these variables using the however-mixed pattern is done solely
// because writing this pattern is shorter than repeating the variable name.
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
			break
		default:
			cv.Warnf("%s should be matched against %q or %q, not %q.", cv.Varname, yes1, no1, cv.Value)
		}
	} else if cv.Op == opUseCompare {
		cv.Warnf("%s should be matched against %q or %q, not compared with %q.", cv.Varname, yes1, no1, cv.Value)
		cv.Explain(
			"The yes/no value can be written in either upper or lower case, and",
			"both forms are actually used.",
			"As long as this is the case, when checking the variable value,",
			"both must be accepted.")
	} else if !matches(cv.Value, `^(?:YES|yes|NO|no)$`) {
		cv.Warnf("%s should be set to YES, yes, NO, or no.", cv.Varname)
	}
}

func (cv *VartypeCheck) YesNoIndirectly() {
	if cv.ValueNoVar != "" {
		cv.YesNo()
	}
}
