package pkglint

import (
	"netbsd.org/pkglint/textproc"
	"strings"
)

func CheckFileAlternatives(filename string) {
	lines := Load(filename, NotEmpty|LogErrors)
	if lines == nil {
		return
	}

	var plist PlistContent
	if G.Pkg != nil {
		plist = G.Pkg.Plist
	}

	checkPlistWrapper := func(line *Line, wrapper string) {
		if plist.Files[wrapper] {
			line.Errorf("Alternative wrapper %q must not appear in the PLIST.", wrapper)
		}
	}

	checkPlistAlternative := func(line *Line, alternative string) {
		relImplementation := strings.Replace(alternative, "@PREFIX@/", "", 1)
		plistName := replaceAll(relImplementation, `@(\w+)@`, "${$1}")
		if plist.Files[plistName] || G.Pkg.vars.Defined("ALTERNATIVES_SRC") {
			return
		}

		switch {

		case hasPrefix(alternative, "/"):
			// It's possible but unusual to refer to a fixed absolute path.
			// These cannot be mentioned in the PLIST since they are not part of the package.
			break

		case plistName == alternative:
			line.Errorf("Alternative implementation %q must appear in the PLIST.", alternative)

		default:
			line.Errorf("Alternative implementation %q must appear in the PLIST as %q.", alternative, plistName)
		}
	}

	for _, line := range lines.Lines {
		m, wrapper, space, alternative := match3(line.Text, `^([^\t ]+)([ \t]+)([^\t ]+)`)
		if !m {
			line.Errorf("Invalid line %q.", line.Text)
			line.Explain(
				sprintf("Run %q for more information.", makeHelp("alternatives")))
			continue
		}

		if plist.Files != nil {
			checkPlistWrapper(line, wrapper)
			checkPlistAlternative(line, alternative)
		}

		switch {
		case hasPrefix(alternative, "/"), hasPrefix(alternative, "@"):
			break

		case textproc.NewLexer(alternative).NextByteSet(textproc.Alnum) != -1:
			fix := line.Autofix()
			fix.Errorf("Alternative implementation %q must be an absolute path.", alternative)
			fix.Explain(
				"It usually starts with @PREFIX@/... to refer to a path inside the installation prefix.")
			fix.ReplaceAfter(space, alternative, "@PREFIX@/"+alternative)
			fix.Apply()

		default:
			line.Errorf("Alternative implementation %q must be an absolute path.", alternative)
			line.Explain(
				"It usually starts with @PREFIX@/... to refer to a path inside the installation prefix.")
		}
	}
}
