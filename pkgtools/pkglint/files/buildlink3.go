package pkglint

import (
	"netbsd.org/pkglint/pkgver"
	"strings"
)

type Buildlink3Checker struct {
	mklines          *MkLines
	pkgbase          string
	pkgbaseLine      *MkLine
	abiLine, apiLine *MkLine
	abi, api         *DependencyPattern
}

func NewBuildlink3Checker(mklines *MkLines) *Buildlink3Checker {
	return &Buildlink3Checker{mklines: mklines}
}

func (ck *Buildlink3Checker) Check() {
	mklines := ck.mklines
	if trace.Tracing {
		defer trace.Call(mklines.lines.Filename)()
	}

	mklines.Check()

	llex := NewMkLinesLexer(mklines)

	for llex.SkipIf((*MkLine).IsComment) {
		line := llex.PreviousLine()
		// See pkgtools/createbuildlink/files/createbuildlink
		if hasPrefix(line.Text, "# XXX This file was created automatically") {
			line.Errorf("This comment indicates unfinished work (url2pkg).")
		}
	}

	llex.SkipEmptyOrNote()

	if llex.SkipRegexp(`^BUILDLINK_DEPMETHOD\.([^\t ]+)\?=.*$`) {
		llex.PreviousLine().Warnf("This line belongs inside the .ifdef block.")
		for llex.SkipText("") {
		}
	}

	if !ck.checkFirstParagraph(llex) {
		return
	}
	if !ck.checkSecondParagraph(llex) {
		return
	}
	if !ck.checkMainPart(llex) {
		return
	}

	// Fourth paragraph: Cleanup, corresponding to the first paragraph.
	if !llex.SkipContainsOrWarn("BUILDLINK_TREE+=\t-" + ck.pkgbase) {
		return
	}

	if !llex.EOF() {
		llex.CurrentLine().Warnf("The file should end here.")
	}

	pkg := ck.mklines.pkg
	if pkg != nil {
		pkg.checkLinesBuildlink3Inclusion(mklines)
	}

	mklines.SaveAutofixChanges()
}

func (ck *Buildlink3Checker) checkFirstParagraph(mlex *MkLinesLexer) bool {

	// First paragraph: Introduction of the package identifier
	m := mlex.NextRegexp(`^BUILDLINK_TREE\+=[\t ]*([^\t ]+)$`)
	if m == nil {
		mlex.CurrentLine().Warnf("Expected a BUILDLINK_TREE line.")
		return false
	}

	pkgbase := m[1]
	pkgbaseLine := mlex.PreviousMkLine()

	if containsVarUse(pkgbase) {
		ck.checkVaruseInPkgbase(pkgbaseLine)
	}

	ck.checkUniquePkgbase(pkgbase, pkgbaseLine)

	mlex.SkipEmptyOrNote()
	ck.pkgbase = pkgbase
	ck.pkgbaseLine = pkgbaseLine
	return true
}

func (ck *Buildlink3Checker) checkUniquePkgbase(pkgbase string, mkline *MkLine) {
	prev := G.InterPackage.Bl3(pkgbase, &mkline.Location)
	if prev == nil {
		return
	}

	dirname := G.Pkgsrc.Rel(mkline.Filename().Dir()).Base()
	base, name := trimCommon(pkgbase, dirname)
	if base == "" && matches(name, `^(\d*|-cvs|-fossil|-git|-hg|-svn|-devel|-snapshot)$`) {
		return
	}

	mkline.Errorf("Duplicate package identifier %q already appeared in %s.",
		pkgbase, mkline.RelLocation(*prev))
	mkline.Explain(
		"Each buildlink3.mk file must have a unique identifier.",
		"These identifiers are used for multiple-inclusion guards,",
		"and using the same identifier for different packages",
		"(often by copy-and-paste) may change the dependencies",
		"of a package in subtle and unexpected ways.")
}

// checkSecondParagraph checks the multiple inclusion protection and
// introduces the uppercase package identifier.
func (ck *Buildlink3Checker) checkSecondParagraph(mlex *MkLinesLexer) bool {
	pkgbase := ck.pkgbase
	m := mlex.NextRegexp(`^\.if !defined\(([^\t ]+)_BUILDLINK3_MK\)$`)
	if m == nil {
		return false
	}
	pkgupperLine, pkgupper := mlex.PreviousMkLine(), m[1]

	if !mlex.SkipContainsOrWarn(pkgupper + "_BUILDLINK3_MK:=") {
		return false
	}
	mlex.SkipEmptyOrNote()

	// See pkgtools/createbuildlink/files/createbuildlink, keyword PKGUPPER
	ucPkgbase := strings.ToUpper(strings.Replace(pkgbase, "-", "_", -1))
	if ucPkgbase != pkgupper && !containsVarUse(pkgbase) {
		pkgupperLine.Errorf("Package name mismatch between multiple-inclusion guard %q (expected %q) and package name %q (from %s).",
			pkgupper, ucPkgbase, pkgbase, pkgupperLine.RelMkLine(ck.pkgbaseLine))
	}
	ck.checkPkgbaseMismatch(pkgbase)

	return true
}

func (ck *Buildlink3Checker) checkPkgbaseMismatch(bl3base string) {
	pkg := ck.mklines.pkg
	if pkg == nil {
		return
	}

	mkbase := pkg.EffectivePkgbase
	if mkbase == "" || mkbase == bl3base || strings.TrimPrefix(mkbase, "lib") == bl3base {
		return
	}

	if hasPrefix(mkbase, bl3base) && matches(mkbase[len(bl3base):], `^\d+$`) {
		return
	}

	ck.pkgbaseLine.Errorf("Package name mismatch between %q in this file and %q from %s.",
		bl3base, mkbase, ck.pkgbaseLine.RelMkLine(pkg.EffectivePkgnameLine))
}

// Third paragraph: Package information.
func (ck *Buildlink3Checker) checkMainPart(mlex *MkLinesLexer) bool {
	pkgbase := ck.pkgbase

	// The first .if is from the second paragraph.
	indentLevel := 1

	for !mlex.EOF() && indentLevel > 0 {
		mkline := mlex.CurrentMkLine()
		mlex.Skip()

		switch {
		case mkline.IsVarassign():
			ck.checkVarassign(mkline, pkgbase)

		case mkline.IsDirective() && mkline.Directive() == "if":
			indentLevel++

		case mkline.IsDirective() && mkline.Directive() == "endif":
			indentLevel--
		}

		mkline.ForEachUsed(func(varUse *MkVarUse, time VucTime) {
			ck.checkVarUse(varUse, mkline)
		})
	}

	if indentLevel > 0 {
		return false
	}

	if ck.apiLine == nil {
		mlex.CurrentLine().Warnf("Definition of BUILDLINK_API_DEPENDS is missing.")
	}
	mlex.SkipEmptyOrNote()
	return true
}

func (ck *Buildlink3Checker) checkVarUse(varUse *MkVarUse, mkline *MkLine) {
	varname := varUse.varname
	if varname == "PKG_OPTIONS" {
		mkline.Errorf("PKG_OPTIONS is not available in buildlink3.mk files.")
		mkline.Explain(
			"The buildlink3.mk file of a package is only ever included",
			"by other packages, never by the package itself.",
			"Therefore it does not make sense to use the variable PKG_OPTIONS",
			"in this place since it contains the package options of a random",
			"package that happens to include this file.",
			"",
			"To access the options of this package, see mk/pkg-build-options.mk.")
	}

	if varnameBase(varname) == "PKG_BUILD_OPTIONS" {
		param := varnameParam(varname)
		if param != "" && param != ck.pkgbase {
			mkline.Warnf("Wrong PKG_BUILD_OPTIONS, expected %q instead of %q.",
				ck.pkgbase, param)
			mkline.Explain(
				"The variable parameter for PKG_BUILD_OPTIONS must correspond",
				"to the value of \"pkgbase\" above.")
		}
	}
}

func (ck *Buildlink3Checker) checkVarassign(mkline *MkLine, pkgbase string) {
	varname, value := mkline.Varname(), mkline.Value()
	doCheck := false

	if varname == "BUILDLINK_ABI_DEPENDS."+pkgbase {
		ck.abiLine = mkline
		parser := NewMkParser(nil, value)
		if dp := parser.DependencyPattern(); dp != nil && parser.EOF() {
			ck.abi = dp
		}
		doCheck = true
	}

	if varname == "BUILDLINK_API_DEPENDS."+pkgbase {
		ck.apiLine = mkline
		parser := NewMkParser(nil, value)
		if dp := parser.DependencyPattern(); dp != nil && parser.EOF() {
			ck.api = dp
		}
		doCheck = true
	}

	if doCheck && ck.abi != nil && ck.api != nil && ck.abi.Pkgbase != ck.api.Pkgbase {
		if !hasPrefix(ck.api.Pkgbase, "{") {
			ck.abiLine.Warnf("Package name mismatch between ABI %q and API %q (from %s).",
				ck.abi.Pkgbase, ck.api.Pkgbase, ck.abiLine.RelMkLine(ck.apiLine))
		}
	}

	if doCheck {
		if ck.abi != nil && ck.abi.Lower != "" && !containsVarUse(ck.abi.Lower) {
			if ck.api != nil && ck.api.Lower != "" && !containsVarUse(ck.api.Lower) {
				if pkgver.Compare(ck.abi.Lower, ck.api.Lower) < 0 {
					ck.abiLine.Warnf("ABI version %q should be at least API version %q (see %s).",
						ck.abi.Lower, ck.api.Lower, ck.abiLine.RelMkLine(ck.apiLine))
				}
			}
		}
	}

	if varparam := mkline.Varparam(); varparam != "" && varparam != pkgbase {
		if hasPrefix(varname, "BUILDLINK_") && mkline.Varcanon() != "BUILDLINK_API_DEPENDS.*" {
			mkline.Warnf("Only buildlink variables for %q, not %q may be set in this file.", pkgbase, varparam)
		}
	}
}

func (ck *Buildlink3Checker) checkVaruseInPkgbase(pkgbaseLine *MkLine) {
	tokens, _ := pkgbaseLine.ValueTokens()
	for _, token := range tokens {
		if token.Varuse == nil {
			continue
		}

		replacement := ""
		switch token.Varuse.varname {
		case "PYPKGPREFIX":
			replacement = "py"
		case "RUBY_BASE", "RUBY_PKGPREFIX":
			replacement = "ruby"
		case "PHP_PKG_PREFIX":
			replacement = "php"
		}

		if replacement != "" {
			pkgbaseLine.Warnf("Please use %q instead of %q (also in other variables in this file).",
				replacement, token.Text)
		} else {
			pkgbaseLine.Warnf(
				"Please replace %q with a simple string (also in other variables in this file).",
				token.Text)
		}

		pkgbaseLine.Explain(
			"The identifiers in the BUILDLINK_TREE variable should be plain",
			"strings that do not refer to any variable.",
			"",
			"Even for packages that depend on a specific version of a",
			"programming language, the plain name is enough since",
			"the version number of the programming language is stored elsewhere.",
			"Furthermore, these package identifiers are only used at build time,",
			"after the specific version has been decided.")
	}
}
