package main

import (
	"io/ioutil"
	"strings"
)

func parseLicenses(licenses string) []string {
	noPerl := strings.Replace(licenses, "${PERL5_LICENSE}", "gnu-gpl-v2 OR artistic", -1)
	noOps := regcomp(`[()]|AND|OR`).ReplaceAllString(noPerl, "") // cheated
	return splitOnSpace(strings.TrimSpace(noOps))
}

func checktoplevelUnusedLicenses() {
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

func checklineLicense(line *MkLine, value string) {
	licenses := parseLicenses(value)
	for _, license := range licenses {
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
			line.Warn1("License file %s does not exist.", cleanpath(licenseFile))
		}

		switch license {
		case "fee-based-commercial-use",
			"no-commercial-use",
			"no-profit",
			"no-redistribution",
			"shareware":
			line.Warn1("License %q is deprecated.", license)
			Explain(
				"Instead of using these deprecated licenses, extract the actual",
				"license from the package into the pkgsrc/licenses/ directory",
				"and define LICENSE to that file name.  See the pkgsrc guide,",
				"keyword LICENSE, for more information.")
		}
	}
}
