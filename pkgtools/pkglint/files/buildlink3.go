package pkglint

import (
	"netbsd.org/pkglint/pkgver"
	"path"
	"strings"
)

type Buildlink3Checker struct {
	mklines          *MkLines
	pkgbase          string
	pkgbaseLine      *MkLine
	abiLine, apiLine *MkLine
	abi, api         *DependencyPattern
}

func CheckLinesBuildlink3Mk(mklines *MkLines) {
	(&Buildlink3Checker{mklines: mklines}).Check()
}

func (ck *Buildlink3Checker) Check() {
	mklines := ck.mklines
	if trace.Tracing {
		defer trace.Call1(mklines.lines.Filename)()
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
		for llex.SkipString("") {
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

	if G.Pkg != nil {
		G.Pkg.checkLinesBuildlink3Inclusion(mklines)
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

	if containsVarRef(pkgbase) {
		ck.checkVaruseInPkgbase(pkgbase, pkgbaseLine)
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

	base, name := trimCommon(pkgbase, path.Base(path.Dir(mkline.Filename)))
	if base == "" && matches(name, `^(\d*|-cvs|-fossil|-git|-hg|-svn|-devel|-snapshot)$`) {
		return
	}

	mkline.Errorf("Duplicate package identifier %q already appeared in %s.",
		pkgbase, mkline.RefToLocation(*prev))
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
	pkgbaseLine := ck.pkgbaseLine

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
	if ucPkgbase != pkgupper && !containsVarRef(pkgbase) {
		pkgupperLine.Errorf("Package name mismatch between multiple-inclusion guard %q (expected %q) and package name %q (from %s).",
			pkgupper, ucPkgbase, pkgbase, pkgupperLine.RefTo(pkgbaseLine))
	}
	if G.Pkg != nil {
		if mkbase := G.Pkg.EffectivePkgbase; mkbase != "" && mkbase != pkgbase {
			pkgbaseLine.Errorf("Package name mismatch between %q in this file and %q from %s.",
				pkgbase, mkbase, pkgbaseLine.RefTo(G.Pkg.EffectivePkgnameLine))
		}
	}

	return true
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
			ck.checkVarassign(mlex, mkline, pkgbase)

		case mkline.IsDirective() && mkline.Directive() == "if":
			indentLevel++

		case mkline.IsDirective() && mkline.Directive() == "endif":
			indentLevel--
		}
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

func (ck *Buildlink3Checker) checkVarassign(mlex *MkLinesLexer, mkline *MkLine, pkgbase string) {
	varname, value := mkline.Varname(), mkline.Value()
	doCheck := false

	if varname == "BUILDLINK_ABI_DEPENDS."+pkgbase {
		ck.abiLine = mkline
		parser := NewMkParser(nil, value, false)
		if dp := parser.Dependency(); dp != nil && parser.EOF() {
			ck.abi = dp
		}
		doCheck = true
	}

	if varname == "BUILDLINK_API_DEPENDS."+pkgbase {
		ck.apiLine = mkline
		parser := NewMkParser(nil, value, false)
		if dp := parser.Dependency(); dp != nil && parser.EOF() {
			ck.api = dp
		}
		doCheck = true
	}

	if doCheck && ck.abi != nil && ck.api != nil && ck.abi.Pkgbase != ck.api.Pkgbase {
		if !hasPrefix(ck.api.Pkgbase, "{") {
			ck.abiLine.Warnf("Package name mismatch between ABI %q and API %q (from %s).",
				ck.abi.Pkgbase, ck.api.Pkgbase, ck.abiLine.RefTo(ck.apiLine))
		}
	}

	if doCheck {
		if ck.abi != nil && ck.abi.Lower != "" && !containsVarRef(ck.abi.Lower) {
			if ck.api != nil && ck.api.Lower != "" && !containsVarRef(ck.api.Lower) {
				if pkgver.Compare(ck.abi.Lower, ck.api.Lower) < 0 {
					ck.abiLine.Warnf("ABI version %q should be at least API version %q (see %s).",
						ck.abi.Lower, ck.api.Lower, ck.abiLine.RefTo(ck.apiLine))
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

func (ck *Buildlink3Checker) checkVaruseInPkgbase(pkgbase string, pkgbaseLine *MkLine) {
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
