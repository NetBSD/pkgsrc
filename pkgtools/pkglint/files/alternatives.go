package main

import (
	"netbsd.org/pkglint/regex"
	"strings"
)

func CheckfileAlternatives(filename string, plistFiles map[string]bool) {
	lines := Load(filename, NotEmpty|LogErrors)
	if lines == nil {
		return
	}

	for _, line := range lines {
		if m, wrapper, space, implementation := match3(line.Text, `^(\S+)([ \t]+)(\S+)`); m {
			if plistFiles != nil {
				if plistFiles[wrapper] {
					line.Errorf("Alternative wrapper %q must not appear in the PLIST.", wrapper)
				}

				relImplementation := strings.Replace(implementation, "@PREFIX@/", "", 1)
				plistName := regex.Compile(`@(\w+)@`).ReplaceAllString(relImplementation, "${$1}")
				if !plistFiles[plistName] && !G.Pkg.vars.Defined("ALTERNATIVES_SRC") {
					if plistName != implementation {
						line.Errorf("Alternative implementation %q must appear in the PLIST as %q.", implementation, plistName)
					} else {
						line.Errorf("Alternative implementation %q must appear in the PLIST.", implementation)
					}
				}
			}

			fix := line.Autofix()
			fix.Notef("@PREFIX@/ can be omitted from the file name.")
			fix.Explain(
				"The alternative implementation is always interpreted relative to",
				"${PREFIX}.")
			fix.ReplaceAfter(space, "@PREFIX@/", "")
			fix.Apply()
		} else {
			line.Errorf("Invalid ALTERNATIVES line %q.", line.Text)
			Explain(
				"Run \"" + confMake + " help topic=alternatives\" for more information.")
		}
	}
}
