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
	if G.ipcUsedLicenses == nil {
		return
	}

	licensedir := G.globalData.pkgsrcdir + "/licenses"
	files, _ := ioutil.ReadDir(licensedir)
	for _, licensefile := range files {
		licensename := licensefile.Name()
		licensepath := licensedir + "/" + licensename
		if fileExists(licensepath) {
			if !G.ipcUsedLicenses[licensename] {
				warnf(licensepath, noLines, "This license seems to be unused.")
			}
		}
	}
}

func checklineLicense(line *Line, value string) {
	licenses := parseLicenses(value)
	for _, license := range licenses {
		var licenseFile string
		if pkg := G.pkgContext; pkg != nil {
			if licenseFileValue, ok := pkg.varValue("LICENSE_FILE"); ok {
				licenseFile = G.currentDir + "/" + resolveVarsInRelativePath(licenseFileValue, false)
			}
		}
		if licenseFile == "" {
			licenseFile = G.globalData.pkgsrcdir + "/licenses/" + license
			if G.ipcUsedLicenses != nil {
				G.ipcUsedLicenses[license] = true
			}
		}

		if !fileExists(licenseFile) {
			line.warnf("License file %s does not exist.", cleanpath(licenseFile))
		}

		switch license {
		case "fee-based-commercial-use",
			"no-commercial-use",
			"no-profit",
			"no-redistribution",
			"shareware":
			line.warnf("License %q is deprecated.", license)
		}
	}
}
