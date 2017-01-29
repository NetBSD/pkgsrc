package main

import (
	"io/ioutil"
	"netbsd.org/pkglint/licenses"
)

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
				NewLineWhole(licensepath).Warnf("This license seems to be unused.")
			}
		}
	}
}

type LicenseChecker struct {
	MkLine MkLine
}

func (lc *LicenseChecker) Check(value string, op MkOperator) {
	expanded := resolveVariableRefs(value) // For ${PERL5_LICENSE}
	licenses := licenses.Parse(ifelseStr(op == opAssignAppend, "append-placeholder ", "") + expanded)

	if licenses == nil {
		if op == opAssign {
			lc.MkLine.Errorf("Parse error for license condition %q.", value)
		} else {
			lc.MkLine.Errorf("Parse error for appended license condition %q.", value)
		}
		return
	}

	licenses.Walk(lc.checkNode)
}

func (lc *LicenseChecker) checkLicenseName(license string) {
	var licenseFile string
	if G.Pkg != nil {
		if licenseFileValue, ok := G.Pkg.varValue("LICENSE_FILE"); ok {
			licenseFile = G.CurrentDir + "/" + lc.MkLine.ResolveVarsInRelativePath(licenseFileValue, false)
		}
	}
	if licenseFile == "" {
		licenseFile = G.globalData.Pkgsrcdir + "/licenses/" + license
		if G.UsedLicenses != nil {
			G.UsedLicenses[license] = true
		}
	}

	if !fileExists(licenseFile) {
		lc.MkLine.Warnf("License file %s does not exist.", cleanpath(licenseFile))
	}

	switch license {
	case "fee-based-commercial-use",
		"no-commercial-use",
		"no-profit",
		"no-redistribution",
		"shareware":
		lc.MkLine.Errorf("License %q must not be used.", license)
		Explain(
			"Instead of using these deprecated licenses, extract the actual",
			"license from the package into the pkgsrc/licenses/ directory",
			"and define LICENSE to that file name.  See the pkgsrc guide,",
			"keyword LICENSE, for more information.")
	}
}

func (lc *LicenseChecker) checkNode(cond *licenses.Condition) {
	if license := cond.Name; license != "" && license != "append-placeholder" {
		lc.checkLicenseName(license)
		return
	}

	if cond.And && cond.Or {
		lc.MkLine.Errorf("AND and OR operators in license conditions can only be combined using parentheses.")
		Explain(
			"Examples for valid license conditions are:",
			"",
			"\tlicense1 AND license2 AND (license3 OR license4)",
			"\t(((license1 OR license2) AND (license3 OR license4)))")
	}
}
