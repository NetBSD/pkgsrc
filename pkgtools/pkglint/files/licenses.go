package main

import (
	"io/ioutil"
)

//go:generate go tool yacc -p liyy -o licenseyacc.go -v licenseyacc.log license.y

// LicenseCondition describes a complex license condition.
// It has either `Name` or `Main` set.
type LicenseCondition struct {
	Name string
	Main *LicenseCondition
	And  []*LicenseCondition
	Or   []*LicenseCondition
}

func (lc *LicenseCondition) Walk(callback func(*LicenseCondition)) {
	callback(lc)
	if lc.Main != nil {
		lc.Main.Walk(callback)
	}
	for _, and := range lc.And {
		and.Walk(callback)
	}
	for _, or := range lc.Or {
		or.Walk(callback)
	}
}

type licenseLexer struct {
	repl   *PrefixReplacer
	result *LicenseCondition
	error  string
}

func (lexer *licenseLexer) Lex(llval *liyySymType) int {
	repl := lexer.repl
	repl.AdvanceHspace()
	switch {
	case repl.rest == "":
		return 0
	case repl.AdvanceStr("("):
		return ltOPEN
	case repl.AdvanceStr(")"):
		return ltCLOSE
	case repl.AdvanceRegexp(`^[\w-.]+`):
		word := repl.m[0]
		switch word {
		case "AND":
			return ltAND
		case "OR":
			return ltOR
		default:
			llval.Node = &LicenseCondition{Name: word}
			return ltNAME
		}
	}
	return -1
}

func (lexer *licenseLexer) Error(s string) {
	lexer.error = s
}

func parseLicenses(licenses string) *LicenseCondition {
	expanded := resolveVariableRefs(licenses) // For ${PERL5_LICENSE}
	lexer := &licenseLexer{repl: NewPrefixReplacer(expanded)}
	result := liyyNewParser().Parse(lexer)
	if result == 0 {
		return lexer.result
	}
	return nil
}

func checkToplevelUnusedLicenses() {
	if G.UsedLicenses == nil {
		return
	}

	licensedir := G.globalData.Pkgsrcdir + "/licenses"
	files, _ := ioutil.ReadDir(licensedir)
	for _, licensefile := range files {
		licensename := licensefile.Name()
		licensepath := licensedir + "/" + licensename
		if fileExists(licensepath) {
			if !G.UsedLicenses[licensename] {
				NewLineWhole(licensepath).Warn0("This license seems to be unused.")
			}
		}
	}
}

type LicenseChecker struct {
	MkLine *MkLine
}

func (lc *LicenseChecker) Check(value string, op MkOperator) {
	licenses := parseLicenses(ifelseStr(op == opAssignAppend, "append-placeholder ", "") + value)

	if licenses == nil {
		if op == opAssign {
			lc.MkLine.Line.Error1("Parse error for license condition %q.", value)
		} else {
			lc.MkLine.Line.Error1("Parse error for appended license condition %q.", value)
		}
		return
	}

	licenses.Walk(lc.checkNode)
}

func (lc *LicenseChecker) checkNode(cond *LicenseCondition) {
	license := cond.Name
	if license == "" || license == "append-placeholder" {
		return
	}

	var licenseFile string
	if G.Pkg != nil {
		if licenseFileValue, ok := G.Pkg.varValue("LICENSE_FILE"); ok {
			licenseFile = G.CurrentDir + "/" + resolveVarsInRelativePath(licenseFileValue, false)
		}
	}
	if licenseFile == "" {
		licenseFile = G.globalData.Pkgsrcdir + "/licenses/" + license
		if G.UsedLicenses != nil {
			G.UsedLicenses[license] = true
		}
	}

	if !fileExists(licenseFile) {
		lc.MkLine.Warn1("License file %s does not exist.", cleanpath(licenseFile))
	}

	switch license {
	case "fee-based-commercial-use",
		"no-commercial-use",
		"no-profit",
		"no-redistribution",
		"shareware":
		lc.MkLine.Error1("License %q must not be used.", license)
		Explain(
			"Instead of using these deprecated licenses, extract the actual",
			"license from the package into the pkgsrc/licenses/ directory",
			"and define LICENSE to that file name.  See the pkgsrc guide,",
			"keyword LICENSE, for more information.")
	}

	if len(cond.And) > 0 && len(cond.Or) > 0 {
		lc.MkLine.Line.Error0("AND and OR operators in license conditions can only be combined using parentheses.")
		Explain(
			"Examples for valid license conditions are:",
			"",
			"\tlicense1 AND license2 AND (license3 OR license4)",
			"\t(((license1 OR license2) AND (license3 OR license4)))")
	}
}
