package pkglint

// Checks for patch files.

import (
	"path"
	"strings"
)

func CheckLinesPatch(lines *Lines) {
	(&PatchChecker{lines, NewLinesLexer(lines), false, false}).Check()
}

type PatchChecker struct {
	lines             *Lines
	llex              *LinesLexer
	seenDocumentation bool
	previousLineEmpty bool
}

const (
	rePatchUniFileDel = `^---[\t ]([^\t ]+)(?:[\t ]+(.*))?$`
	rePatchUniFileAdd = `^\+\+\+[\t ]([^\t ]+)(?:[\t ]+(.*))?$`
	rePatchUniHunk    = `^@@ -(\d+)(?:,(\d+))? \+(\d+)(?:,(\d+))? @@(.*)$`
)

func (ck *PatchChecker) Check() {
	if ck.lines.CheckCvsID(0, ``, "") {
		ck.llex.Skip()
	}
	if ck.llex.EOF() {
		ck.lines.Lines[0].Errorf("Patch files must not be empty.")
		return
	}

	ck.previousLineEmpty = ck.llex.SkipEmptyOrNote()

	patchedFiles := 0
	for !ck.llex.EOF() {
		line := ck.llex.CurrentLine()
		if ck.llex.SkipRegexp(rePatchUniFileDel) {
			if m := ck.llex.NextRegexp(rePatchUniFileAdd); m != nil {
				ck.checkBeginDiff(line, patchedFiles)
				ck.checkUnifiedDiff(m[1])
				patchedFiles++
				continue
			}

			ck.llex.Undo()
		}

		if m := ck.llex.NextRegexp(rePatchUniFileAdd); m != nil {
			patchedFile := m[1]
			if ck.llex.SkipRegexp(rePatchUniFileDel) {
				ck.checkBeginDiff(line, patchedFiles)
				ck.llex.PreviousLine().Warnf("Unified diff headers should be first ---, then +++.")
				ck.checkUnifiedDiff(patchedFile)
				patchedFiles++
				continue
			}

			ck.llex.Undo()
		}

		if ck.llex.SkipRegexp(`^\*\*\*[\t ]([^\t ]+)(.*)$`) {
			if ck.llex.SkipRegexp(`^---[\t ]([^\t ]+)(.*)$`) {
				ck.checkBeginDiff(line, patchedFiles)
				line.Warnf("Please use unified diffs (diff -u) for patches.")
				return
			}

			ck.llex.Undo()
		}

		ck.llex.Skip()
		ck.previousLineEmpty = ck.isEmptyLine(line.Text)
		if !ck.previousLineEmpty {
			ck.seenDocumentation = true
		}
	}

	if patchedFiles > 1 {
		ck.lines.Warnf("Contains patches for %d files, should be only one.", patchedFiles)
	} else if patchedFiles == 0 {
		ck.lines.Errorf("Contains no patch.")
	}

	CheckLinesTrailingEmptyLines(ck.lines)
	sha1Before := computePatchSha1Hex(ck.lines)
	if SaveAutofixChanges(ck.lines) && G.Pkg != nil {
		linesAfter := Load(ck.lines.Filename, 0)
		sha1After := computePatchSha1Hex(linesAfter)
		G.Pkg.AutofixDistinfo(sha1Before, sha1After)
	}
}

// See https://www.gnu.org/software/diffutils/manual/html_node/Detailed-Unified.html
func (ck *PatchChecker) checkUnifiedDiff(patchedFile string) {
	isConfigure := ck.isConfigure(patchedFile)

	hasHunks := false
	for {
		m := ck.llex.NextRegexp(rePatchUniHunk)
		if m == nil {
			break
		}

		text := m[0]
		hasHunks = true
		linesToDel := toInt(m[2], 1)
		linesToAdd := toInt(m[4], 1)

		ck.checktextUniHunkCr()
		ck.checktextCvsID(text)

		for !ck.llex.EOF() && (linesToDel > 0 || linesToAdd > 0 || hasPrefix(ck.llex.CurrentLine().Text, "\\")) {
			line := ck.llex.CurrentLine()
			ck.llex.Skip()

			text := line.Text
			switch {

			case text == "":
				// There should be a space here, but that was a trailing space and
				// has been trimmed down somewhere on its way. Doesn't matter,
				// all the patch programs can handle this situation.
				linesToDel--
				linesToAdd--

			case hasPrefix(text, " "), hasPrefix(text, "\t"):
				linesToDel--
				linesToAdd--
				ck.checktextCvsID(text)

			case hasPrefix(text, "-"):
				linesToDel--

			case hasPrefix(text, "+"):
				linesToAdd--
				ck.checktextCvsID(text)
				ck.checkConfigure(text[1:], isConfigure)

			case hasPrefix(text, "\\"):
				// \ No newline at end of file (or a translation of that message)

			default:
				line.Errorf("Invalid line in unified patch hunk: %s", text)
				return
			}
		}

		// When these two counts are equal, they may refer to context
		// lines that consist only of whitespace and have therefore
		// been lost during transmission. There is no way to detect
		// this by looking only at the patch file.
		if linesToAdd != linesToDel {
			line := ck.llex.PreviousLine()
			line.Warnf("Premature end of patch hunk (expected %d lines to be deleted and %d lines to be added).",
				linesToDel, linesToAdd)
		}
	}

	if !hasHunks {
		ck.llex.CurrentLine().Errorf("No patch hunks for %q.", patchedFile)
	}

	if !ck.llex.EOF() {
		line := ck.llex.CurrentLine()
		if !ck.isEmptyLine(line.Text) && !matches(line.Text, rePatchUniFileDel) {
			line.Warnf("Empty line or end of file expected.")
			line.Explain(
				"This line is not part of the patch anymore, although it may look so.",
				"To make this situation clear, there should be an",
				"empty line before this line.",
				"If the line doesn't contain useful information, it should be removed.")
		}
	}
}

func (ck *PatchChecker) checkBeginDiff(line *Line, patchedFiles int) {
	if !ck.seenDocumentation && patchedFiles == 0 {
		line.Errorf("Each patch must be documented.")
		line.Explain(
			"Pkgsrc tries to have as few patches as possible.",
			"Therefore, each patch must document why it is necessary.",
			"Typical reasons are portability or security.",
			"A typical documented patch looks like this:",
			"",
			"\t$"+"NetBSD$",
			"",
			"\tPortability fixes for GCC 4.8 on Linux.",
			"\tSee https://github.com/org/repo/issues/7",
			"",
			"Patches that are related to a security issue should mention the",
			"corresponding CVE identifier.",
			"",
			"Each patch should be sent to the upstream maintainers of the",
			"package, so that they can include it in future versions.",
			"After submitting a patch upstream, the corresponding bug report should",
			"be mentioned in this file, to prevent duplicate work.")
	}

	if G.Opts.WarnSpace && !ck.previousLineEmpty {
		fix := line.Autofix()
		fix.Notef("Empty line expected.")
		fix.InsertBefore("")
		fix.Apply()
	}
}

func (ck *PatchChecker) checkConfigure(addedText string, isConfigure bool) {
	if !isConfigure {
		return
	}
	if !hasSuffix(addedText, ": Avoid regenerating within pkgsrc") {
		return
	}

	line := ck.llex.PreviousLine()
	line.Errorf("This code must not be included in patches.")
	line.Explain(
		"It is generated automatically by pkgsrc after the patch phase.",
		"",
		"For more details, look for \"configure-scripts-override\" in",
		"mk/configure/gnu-configure.mk.")
}

func (ck *PatchChecker) checktextUniHunkCr() {
	line := ck.llex.PreviousLine()
	if !hasSuffix(line.Text, "\r") {
		return
	}

	// This code has been introduced around 2006.
	// As of 2018, this might be fixed by now.
	fix := line.Autofix()
	fix.Errorf("The hunk header must not end with a CR character.")
	fix.Explain(
		"The MacOS X patch utility cannot handle these.")
	fix.Replace("\r\n", "\n")
	fix.Apply()
}

func (ck *PatchChecker) checktextCvsID(text string) {
	if strings.IndexByte(text, '$') == -1 {
		return
	}
	if m, tagname := match1(text, `\$(Author|Date|Header|Id|Locker|Log|Name|RCSfile|Revision|Source|State|NetBSD)(?::[^\$]*)?\$`); m {
		if matches(text, rePatchUniHunk) {
			ck.llex.PreviousLine().Warnf("Found CVS tag \"$%s$\". Please remove it.", tagname)
		} else {
			ck.llex.PreviousLine().Warnf("Found CVS tag \"$%s$\". Please remove it by reducing the number of context lines using pkgdiff or \"diff -U[210]\".", tagname)
		}
	}
}

// isEmptyLine tests whether a line provides essentially no interesting content.
// The focus here is on human-generated content that is intended for other human readers.
// Therefore text that is typical for patch generators is considered empty as well.
func (ck *PatchChecker) isEmptyLine(text string) bool {
	return text == "" ||
		hasPrefix(text, "index ") ||
		hasPrefix(text, "Index: ") ||
		hasPrefix(text, "diff ") ||
		hasPrefix(text, "=============")
}

func (*PatchChecker) isConfigure(filename string) bool {
	switch path.Base(filename) {
	case "configure", "configure.in", "configure.ac":
		return true
	}
	return false
}
