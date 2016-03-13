package main

import (
	"strings"
)

func ChecklinesBuildlink3Mk(mklines *MkLines) {
	if G.opts.DebugTrace {
		defer tracecall1(mklines.lines[0].Fname)()
	}

	mklines.Check()

	exp := NewExpecter(mklines.lines)

	for exp.AdvanceIfPrefix("#") {
		line := exp.PreviousLine()
		// See pkgtools/createbuildlink/files/createbuildlink
		if hasPrefix(line.Text, "# XXX This file was created automatically") {
			line.Error0("This comment indicates unfinished work (url2pkg).")
		}
	}

	exp.ExpectEmptyLine()

	if exp.AdvanceIfMatches(`^BUILDLINK_DEPMETHOD\.(\S+)\?=.*$`) {
		exp.PreviousLine().Warn0("This line belongs inside the .ifdef block.")
		for exp.AdvanceIfEquals("") {
		}
	}

	pkgbaseLine, pkgbase := exp.CurrentLine(), ""
	var abiLine, apiLine *Line
	var abi, api *DependencyPattern

	// First paragraph: Introduction of the package identifier
	if !exp.AdvanceIfMatches(`^BUILDLINK_TREE\+=\s*(\S+)$`) {
		exp.CurrentLine().Warn0("Expected a BUILDLINK_TREE line.")
		return
	}
	pkgbase = exp.m[1]
	if containsVarRef(pkgbase) {
		warned := false
		for _, pair := range []struct{ varuse, simple string }{
			{"${PYPKGPREFIX}", "py"},
			{"${RUBY_BASE}", "ruby"},
			{"${RUBY_PKGPREFIX}", "ruby"},
			{"${PHP_PKG_PREFIX}", "php"},
		} {
			if contains(pkgbase, pair.varuse) && !pkgbaseLine.AutofixReplace(pair.varuse, pair.simple) {
				pkgbaseLine.Warn2("Please use %q instead of %q.", pair.simple, pair.varuse)
				warned = true
			}
		}
		if !warned {
			if m, varuse := match1(pkgbase, `(\$\{\w+\})`); m {
				pkgbaseLine.Warn1("Please replace %q with a simple string.", varuse)
				warned = true
			}
		}
		if warned {
			Explain(
				"Having variable package names in the BUILDLINK_TREE is not",
				"necessary, since other packages depend on this package only for",
				"a specific version of Python, Ruby or PHP.  Since these",
				"package identifiers are only used at build time, they should",
				"not include the specific version of the language interpreter.")
		}
	}

	exp.ExpectEmptyLine()

	// Second paragraph: multiple inclusion protection and introduction
	// of the uppercase package identifier.
	if !exp.AdvanceIfMatches(`^\.if !defined\((\S+)_BUILDLINK3_MK\)$`) {
		return
	}
	pkgupperLine, pkgupper := exp.PreviousLine(), exp.m[1]

	if !exp.ExpectText(pkgupper + "_BUILDLINK3_MK:=") {
		return
	}
	exp.ExpectEmptyLine()

	// See pkgtools/createbuildlink/files/createbuildlink, keyword PKGUPPER
	ucPkgbase := strings.ToUpper(strings.Replace(pkgbase, "-", "_", -1))
	if ucPkgbase != pkgupper && !containsVarRef(pkgbase) {
		pkgupperLine.Errorf("Package name mismatch between multiple-inclusion guard %q (expected %q) and package name %q (from %s).",
			pkgupper, ucPkgbase, pkgbase, pkgbaseLine.ReferenceFrom(pkgupperLine))
	}
	if G.Pkg != nil {
		if mkbase := G.Pkg.EffectivePkgbase; mkbase != "" && mkbase != pkgbase {
			pkgbaseLine.Errorf("Package name mismatch between %q in this file and %q from %s.",
				pkgbase, mkbase, G.Pkg.EffectivePkgnameLine.Line.ReferenceFrom(pkgbaseLine))
		}
	}

	// Third paragraph: Package information.
	indentLevel := 1 // The first .if is from the second paragraph.
	for {
		if exp.EOF() {
			exp.CurrentLine().Warn0("Expected .endif")
			return
		}

		line := exp.CurrentLine()
		mkline := mklines.mklines[exp.index]

		if mkline.IsVarassign() {
			exp.Advance()
			varname, value := mkline.Varname(), mkline.Value()
			doCheck := false

			const (
				reDependencyCmp      = `^((?:\$\{[\w_]+\}|[\w_\.+]|-[^\d])+)[<>]=?(\d[^-*?\[\]]*)$`
				reDependencyWildcard = `^(-(?:\[0-9\]\*|\d[^-]*)$`
			)

			if varname == "BUILDLINK_ABI_DEPENDS."+pkgbase {
				abiLine = line
				parser := NewParser(line, value)
				if dp := parser.Dependency(); dp != nil && parser.EOF() {
					abi = dp
				}
				doCheck = true
			}
			if varname == "BUILDLINK_API_DEPENDS."+pkgbase {
				apiLine = line
				parser := NewParser(line, value)
				if dp := parser.Dependency(); dp != nil && parser.EOF() {
					api = dp
				}
				doCheck = true
			}
			if doCheck && abi != nil && api != nil && abi.pkgbase != api.pkgbase && !hasPrefix(api.pkgbase, "{") {
				abiLine.Warnf("Package name mismatch between ABI %q and API %q (from %s).",
					abi.pkgbase, api.pkgbase, apiLine.ReferenceFrom(abiLine))
			}
			if doCheck {
				if abi != nil && abi.lower != "" && !containsVarRef(abi.lower) {
					if api != nil && api.lower != "" && !containsVarRef(api.lower) {
						if pkgverCmp(abi.lower, api.lower) < 0 {
							abiLine.Warnf("ABI version %q should be at least API version %q (see %s).",
								abi.lower, api.lower, apiLine.ReferenceFrom(abiLine))
						}
					}
				}
			}

			if varparam := mkline.Varparam(); varparam != "" && varparam != pkgbase {
				if hasPrefix(varname, "BUILDLINK_") && mkline.Varcanon() != "BUILDLINK_API_DEPENDS.*" {
					line.Warn2("Only buildlink variables for %q, not %q may be set in this file.", pkgbase, varparam)
				}
			}

			if varname == "pkgbase" {
				exp.AdvanceIfMatches(`^\.\s*include "../../mk/pkg-build-options\.mk"$`)
			}

		} else if exp.AdvanceIfEquals("") || exp.AdvanceIfPrefix("#") {
			// Comments and empty lines are fine here.

		} else if exp.AdvanceIfMatches(`^\.\s*include "\.\./\.\./([^/]+/[^/]+)/buildlink3\.mk"$`) ||
			exp.AdvanceIfMatches(`^\.\s*include "\.\./\.\./mk/(\S+)\.buildlink3\.mk"$`) {
			// TODO: Maybe check dependency lines.

		} else if exp.AdvanceIfMatches(`^\.if\s`) {
			indentLevel++

		} else if exp.AdvanceIfMatches(`^\.endif.*$`) {
			indentLevel--
			if indentLevel == 0 {
				break
			}

		} else {
			if G.opts.DebugUnchecked {
				exp.CurrentLine().Debugf("Unchecked line in third paragraph.")
			}
			exp.Advance()
		}
	}
	if apiLine == nil {
		exp.CurrentLine().Warn0("Definition of BUILDLINK_API_DEPENDS is missing.")
	}
	exp.ExpectEmptyLine()

	// Fourth paragraph: Cleanup, corresponding to the first paragraph.
	if !exp.ExpectText("BUILDLINK_TREE+=\t-" + pkgbase) {
		return
	}

	if !exp.EOF() {
		exp.CurrentLine().Warn0("The file should end here.")
	}

	if G.Pkg != nil {
		G.Pkg.checklinesBuildlink3Inclusion(mklines)
	}

	SaveAutofixChanges(mklines.lines)
}
