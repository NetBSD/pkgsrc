package pkglint

import "netbsd.org/pkglint/licenses"

type LicenseChecker struct {
	MkLines *MkLines
	MkLine  *MkLine
}

func (lc *LicenseChecker) Check(value string, op MkOperator) {
	expanded := resolveVariableRefs(lc.MkLines, value) // For ${PERL5_LICENSE}
	cond := licenses.Parse(condStr(op == opAssignAppend, "append-placeholder ", "") + expanded)

	if cond == nil {
		if op == opAssign {
			lc.MkLine.Errorf("Parse error for license condition %q.", value)
		} else {
			lc.MkLine.Errorf("Parse error for appended license condition %q.", value)
		}
		return
	}

	cond.Walk(lc.checkNode)
}

func (lc *LicenseChecker) checkName(license string) {
	licenseFile := NewCurrPath("")
	if G.Pkg != nil {
		if mkline := G.Pkg.vars.FirstDefinition("LICENSE_FILE"); mkline != nil {
			rel := mkline.ResolveVarsInRelativePath(NewRelPathString(mkline.Value()))
			licenseFile = G.Pkg.File(NewPackagePath(rel))
		}
	}
	if licenseFile.IsEmpty() {
		licenseFile = G.Pkgsrc.File("licenses").JoinNoClean(NewRelPathString(license))
		G.InterPackage.UseLicense(license)
	}

	if !licenseFile.IsFile() {
		lc.MkLine.Errorf("License file %s does not exist.",
			lc.MkLine.Rel(licenseFile))
		lc.MkLine.Explain(
			sprintf("Run %q to see which licenses the package uses.",
				bmake("guess-license")),
			"",
			sprintf("For more information about licenses, %s.",
				seeGuide("Handling licenses", "handling-licenses")))
	}
}

func (lc *LicenseChecker) checkNode(cond *licenses.Condition) {
	if name := cond.Name; name != "" && name != "append-placeholder" {
		lc.checkName(name)
		return
	}

	if cond.And && cond.Or {
		lc.MkLine.Errorf("AND and OR operators in license conditions can only be combined using parentheses.")
		lc.MkLine.Explain(
			"Examples for valid license conditions are:",
			"",
			"\tlicense1 AND license2 AND (license3 OR license4)",
			"\t(((license1 OR license2) AND (license3 OR license4)))")
	}
}
