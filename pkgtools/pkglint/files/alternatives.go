package pkglint

import (
	"netbsd.org/pkglint/textproc"
	"strings"
)

func CheckFileAlternatives(filename CurrPath) {
	lines := Load(filename, NotEmpty|LogErrors)
	if lines == nil {
		return
	}

	var ck AlternativesChecker
	ck.Check(lines, G.Pkg)
}

type AlternativesChecker struct{}

func (ck *AlternativesChecker) Check(lines *Lines, pkg *Package) {
	var plistFiles map[RelPath]*PlistLine
	if pkg != nil {
		plistFiles = pkg.Plist.Files
	}

	for _, line := range lines.Lines {
		ck.checkLine(line, plistFiles)
	}
}

// checkLine checks a single line for the following format:
//  wrapper alternative [optional arguments]
func (ck *AlternativesChecker) checkLine(line *Line, plistFiles map[RelPath]*PlistLine) {
	// TODO: Add $ to the regex, just for confidence
	m, wrapper, space, alternative := match3(line.Text, `^([^\t ]+)([ \t]+)([^\t ]+)`)
	if !m {
		line.Errorf("Invalid line %q.", line.Text)
		line.Explain(
			sprintf("Run %q for more information.", bmakeHelp("alternatives")))
		return
	}

	if ck.checkWrapperAbs(line, NewPath(wrapper)) && plistFiles != nil {
		ck.checkWrapperPlist(line, NewRelPathString(wrapper), plistFiles)
	}
	if plistFiles != nil {
		ck.checkAlternativePlist(line, alternative, plistFiles)
	}

	ck.checkAlternativeAbs(alternative, line, space)
}

func (ck *AlternativesChecker) checkWrapperAbs(line *Line, wrapper Path) bool {
	if !wrapper.IsAbs() {
		return true
	}

	line.Errorf("Alternative wrapper %q must be relative to PREFIX.", wrapper.String())
	return false
}

func (ck *AlternativesChecker) checkWrapperPlist(line *Line, wrapper RelPath,
	plistFiles map[RelPath]*PlistLine) {

	if plistFiles[wrapper] != nil {
		line.Errorf("Alternative wrapper %q must not appear in the PLIST.", wrapper)
	}
}

func (ck *AlternativesChecker) checkAlternativeAbs(alternative string, line *Line, space string) {
	lex := textproc.NewLexer(alternative)

	if lex.SkipByte('/') || lex.SkipByte('@') {
		return
	}

	fix := line.Autofix()
	fix.Errorf("Alternative implementation %q must be an absolute path.", alternative)
	fix.Explain(
		"It usually starts with @PREFIX@/... to refer to a path inside the installation prefix.")
	if lex.TestByteSet(textproc.Alnum) {
		fix.ReplaceAfter(space, alternative, "@PREFIX@/"+alternative)
	}
	fix.Apply()
}

func (ck *AlternativesChecker) checkAlternativePlist(line *Line, alternative string,
	plistFiles map[RelPath]*PlistLine) {

	relImplementation := strings.Replace(alternative, "@PREFIX@/", "", 1)
	plistName := replaceAll(relImplementation, `@(\w+)@`, "${$1}")
	if NewPath(plistName).IsAbs() {
		// It's possible but unusual to refer to a fixed absolute path.
		// These cannot be mentioned in the PLIST since they are not part of the package.
		return
	}

	rel := NewRelPathString(plistName)
	if plistFiles[rel] != nil || G.Pkg.vars.IsDefined("ALTERNATIVES_SRC") {
		return
	}
	if plistFiles[rel.Replace("${PKGMANDIR}", "man")] != nil {
		return
	}

	if plistName == alternative {
		line.Errorf("Alternative implementation %q must appear in the PLIST.",
			alternative)
	} else {
		line.Errorf("Alternative implementation %q must appear in the PLIST as %q.",
			alternative, plistName)
	}
}
