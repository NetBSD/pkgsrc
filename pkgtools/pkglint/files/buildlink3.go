package main

import (
	"netbsd.org/pkglint/pkgver"
	"strings"
)

type Buildlink3Checker struct {
	mklines          MkLines
	pkgbase          string
	pkgbaseLine      MkLine
	abiLine, apiLine MkLine
	abi, api         *DependencyPattern
}

func ChecklinesBuildlink3Mk(mklines MkLines) {
	(&Buildlink3Checker{mklines: mklines}).Check()
}

func (ck *Buildlink3Checker) Check() {
	mklines := ck.mklines
	if trace.Tracing {
		defer trace.Call1(mklines.lines.FileName)()
	}

	mklines.Check()

	exp := NewMkExpecter(mklines)

	for exp.AdvanceIf(MkLine.IsComment) {
		line := exp.PreviousLine()
		// See pkgtools/createbuildlink/files/createbuildlink
		if hasPrefix(line.Text, "# XXX This file was created automatically") {
			line.Errorf("This comment indicates unfinished work (url2pkg).")
		}
	}

	exp.ExpectEmptyLine()

	if exp.AdvanceIfMatches(`^BUILDLINK_DEPMETHOD\.([^\t ]+)\?=.*$`) {
		exp.PreviousLine().Warnf("This line belongs inside the .ifdef block.")
		for exp.AdvanceIfEquals("") {
		}
	}

	if !ck.checkFirstParagraph(exp) {
		return
	}
	if !ck.checkSecondParagraph(exp) {
		return
	}
	if !ck.checkMainPart(exp) {
		return
	}

	// Fourth paragraph: Cleanup, corresponding to the first paragraph.
	if !exp.ExpectText("BUILDLINK_TREE+=\t-" + ck.pkgbase) {
		return
	}

	if !exp.EOF() {
		exp.CurrentLine().Warnf("The file should end here.")
	}

	if G.Pkg != nil {
		// TODO: Commenting this line doesn't make any test fail, but it should.
		G.Pkg.checklinesBuildlink3Inclusion(mklines)
	}

	mklines.SaveAutofixChanges()
}

func (ck *Buildlink3Checker) checkFirstParagraph(exp *MkExpecter) bool {

	// First paragraph: Introduction of the package identifier
	if !exp.AdvanceIfMatches(`^BUILDLINK_TREE\+=[\t ]*([^\t ]+)$`) {
		exp.CurrentLine().Warnf("Expected a BUILDLINK_TREE line.")
		return false
	}

	pkgbase := exp.Group(1)
	pkgbaseLine := exp.PreviousMkLine()

	if containsVarRef(pkgbase) {
		ck.checkVaruseInPkgbase(pkgbase, pkgbaseLine)
	}
	exp.ExpectEmptyLine()
	ck.pkgbase = pkgbase
	ck.pkgbaseLine = pkgbaseLine
	return true
}

// checkSecondParagraph checks the multiple inclusion protection and
// introduces the uppercase package identifier.
func (ck *Buildlink3Checker) checkSecondParagraph(exp *MkExpecter) bool {
	pkgbase := ck.pkgbase
	pkgbaseLine := ck.pkgbaseLine

	if !exp.AdvanceIfMatches(`^\.if !defined\(([^\t ]+)_BUILDLINK3_MK\)$`) {
		return false
	}
	pkgupperLine, pkgupper := exp.PreviousMkLine(), exp.Group(1)

	if !exp.ExpectText(pkgupper + "_BUILDLINK3_MK:=") {
		return false
	}
	exp.ExpectEmptyLine()

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
func (ck *Buildlink3Checker) checkMainPart(exp *MkExpecter) bool {
	pkgbase := ck.pkgbase

	// The first .if is from the second paragraph.
	indentLevel := 1

	for !exp.EOF() && indentLevel > 0 {
		mkline := exp.CurrentMkLine()
		exp.Advance()

		switch {
		case mkline.IsVarassign():
			ck.checkVarassign(exp, mkline, pkgbase)

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
		exp.CurrentLine().Warnf("Definition of BUILDLINK_API_DEPENDS is missing.")
	}
	exp.ExpectEmptyLine()
	return true
}

func (ck *Buildlink3Checker) checkVarassign(exp *MkExpecter, mkline MkLine, pkgbase string) {
	varname, value := mkline.Varname(), mkline.Value()
	doCheck := false

	if varname == "BUILDLINK_ABI_DEPENDS."+pkgbase {
		ck.abiLine = mkline
		parser := NewParser(mkline.Line, value, false)
		if dp := parser.Dependency(); dp != nil && parser.EOF() {
			ck.abi = dp
		}
		doCheck = true
	}

	if varname == "BUILDLINK_API_DEPENDS."+pkgbase {
		ck.apiLine = mkline
		parser := NewParser(mkline.Line, value, false)
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

func (ck *Buildlink3Checker) checkVaruseInPkgbase(pkgbase string, pkgbaseLine MkLine) {
	checkSpecificVar := func(varuse, simple string) bool {
		if contains(pkgbase, varuse) {
			pkgbaseLine.Warnf("Please use %q instead of %q (also in other variables in this file).", simple, varuse)
			return true
		}
		return false
	}

	warned := checkSpecificVar("${PYPKGPREFIX}", "py") ||
		checkSpecificVar("${RUBY_BASE}", "ruby") ||
		checkSpecificVar("${RUBY_PKGPREFIX}", "ruby") ||
		checkSpecificVar("${PHP_PKG_PREFIX}", "php")

	if !warned {
		if m, varuse := match1(pkgbase, `(\$\{\w+\})`); m {
			pkgbaseLine.Warnf("Please replace %q with a simple string (also in other variables in this file).", varuse)
			warned = true
		}
	}

	if warned {
		Explain(
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
