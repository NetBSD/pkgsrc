package main

// Checks for patch files.

import (
	"path"
	"strings"
)

func ChecklinesPatch(lines Lines) {
	if trace.Tracing {
		defer trace.Call1(lines.FileName)()
	}

	(&PatchChecker{lines, NewExpecter(lines), false, false}).Check()
}

type PatchChecker struct {
	lines             Lines
	exp               *Expecter
	seenDocumentation bool
	previousLineEmpty bool
}

const (
	rePatchUniFileDel = `^---[\t ]([^\t ]+)(?:[\t ]+(.*))?$`
	rePatchUniFileAdd = `^\+\+\+[\t ]([^\t ]+)(?:[\t ]+(.*))?$`
	rePatchUniHunk    = `^@@ -(\d+)(?:,(\d+))? \+(\d+)(?:,(\d+))? @@(.*)$`
)

func (ck *PatchChecker) Check() {
	if trace.Tracing {
		defer trace.Call0()()
	}

	if CheckLineRcsid(ck.lines.Lines[0], ``, "") {
		ck.exp.Advance()
	}
	if ck.exp.EOF() {
		ck.lines.Lines[0].Errorf("Patch files must not be empty.")
		return
	}

	ck.previousLineEmpty = ck.exp.ExpectEmptyLine()

	patchedFiles := 0
	for !ck.exp.EOF() {
		line := ck.exp.CurrentLine()
		if ck.exp.AdvanceIfMatches(rePatchUniFileDel) {
			if ck.exp.AdvanceIfMatches(rePatchUniFileAdd) {
				ck.checkBeginDiff(line, patchedFiles)
				ck.checkUnifiedDiff(ck.exp.Group(1))
				patchedFiles++
				continue
			}

			ck.exp.StepBack()
		}

		if ck.exp.AdvanceIfMatches(rePatchUniFileAdd) {
			patchedFile := ck.exp.Group(1)
			if ck.exp.AdvanceIfMatches(rePatchUniFileDel) {
				ck.checkBeginDiff(line, patchedFiles)
				ck.exp.PreviousLine().Warnf("Unified diff headers should be first ---, then +++.")
				ck.checkUnifiedDiff(patchedFile)
				patchedFiles++
				continue
			}

			ck.exp.StepBack()
		}

		if ck.exp.AdvanceIfMatches(`^\*\*\*[\t ]([^\t ]+)(.*)$`) {
			if ck.exp.AdvanceIfMatches(`^---[\t ]([^\t ]+)(.*)$`) {
				ck.checkBeginDiff(line, patchedFiles)
				line.Warnf("Please use unified diffs (diff -u) for patches.")
				return
			}

			ck.exp.StepBack()
		}

		ck.exp.Advance()
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

	ChecklinesTrailingEmptyLines(ck.lines)
	sha1Before, err := computePatchSha1Hex(ck.lines.FileName)
	if SaveAutofixChanges(ck.lines) && G.Pkg != nil && err == nil {
		sha1After, err := computePatchSha1Hex(ck.lines.FileName)
		if err == nil {
			AutofixDistinfo(sha1Before, sha1After)
		}
	}
}

// See http://www.gnu.org/software/diffutils/manual/html_node/Detailed-Unified.html
func (ck *PatchChecker) checkUnifiedDiff(patchedFile string) {
	if trace.Tracing {
		defer trace.Call0()()
	}

	patchedFileType := guessFileType(patchedFile)
	if trace.Tracing {
		trace.Stepf("guessFileType(%q) = %s", patchedFile, patchedFileType)
	}

	hasHunks := false
	for ck.exp.AdvanceIfMatches(rePatchUniHunk) {
		text := ck.exp.m[0]
		hasHunks = true
		linesToDel := toInt(ck.exp.Group(2), 1)
		linesToAdd := toInt(ck.exp.Group(4), 1)
		if trace.Tracing {
			trace.Stepf("hunk -%d +%d", linesToDel, linesToAdd)
		}
		ck.checktextUniHunkCr()
		ck.checktextRcsid(text)

		for !ck.exp.EOF() && (linesToDel > 0 || linesToAdd > 0 || hasPrefix(ck.exp.CurrentLine().Text, "\\")) {
			line := ck.exp.CurrentLine()
			ck.exp.Advance()
			text := line.Text
			switch {
			case text == "":
				linesToDel--
				linesToAdd--
			case hasPrefix(text, " "), hasPrefix(text, "\t"):
				linesToDel--
				linesToAdd--
				ck.checklineContext(text[1:], patchedFileType)
			case hasPrefix(text, "-"):
				linesToDel--
			case hasPrefix(text, "+"):
				linesToAdd--
				ck.checklineAdded(text[1:], patchedFileType)
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
			line := ck.exp.PreviousLine()
			line.Warnf("Premature end of patch hunk (expected %d lines to be deleted and %d lines to be added).",
				linesToDel, linesToAdd)
		}
	}
	if !hasHunks {
		ck.exp.CurrentLine().Errorf("No patch hunks for %q.", patchedFile)
	}
	if !ck.exp.EOF() {
		line := ck.exp.CurrentLine()
		if !ck.isEmptyLine(line.Text) && !matches(line.Text, rePatchUniFileDel) {
			line.Warnf("Empty line or end of file expected.")
			Explain(
				"This line is not part of the patch anymore, although it may",
				"look so.  To make this situation clear, there should be an",
				"empty line before this line.  If the line doesn't contain",
				"useful information, it should be removed.")
		}
	}
}

func (ck *PatchChecker) checkBeginDiff(line Line, patchedFiles int) {
	if trace.Tracing {
		defer trace.Call0()()
	}

	if !ck.seenDocumentation && patchedFiles == 0 {
		line.Errorf("Each patch must be documented.")
		Explain(
			"Pkgsrc tries to have as few patches as possible.  Therefore, each",
			"patch must document why it is necessary.  Typical reasons are",
			"portability or security.  A typical documented patch looks like",
			"this:",
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
			"package, so that they can include it in future versions.  After",
			"submitting a patch upstream, the corresponding bug report should",
			"be mentioned in this file, to prevent duplicate work.")
	}
	if G.Opts.WarnSpace && !ck.previousLineEmpty {
		fix := line.Autofix()
		fix.Notef("Empty line expected.")
		fix.InsertBefore("")
		fix.Apply()
	}
}

func (ck *PatchChecker) checklineContext(text string, patchedFileType FileType) {
	if trace.Tracing {
		defer trace.Call2(text, patchedFileType.String())()
	}

	if G.Opts.WarnExtra {
		ck.checklineAdded(text, patchedFileType)
	} else {
		ck.checktextRcsid(text)
	}
}

func (ck *PatchChecker) checklineAdded(addedText string, patchedFileType FileType) {
	if trace.Tracing {
		defer trace.Call2(addedText, patchedFileType.String())()
	}

	ck.checktextRcsid(addedText)

	line := ck.exp.PreviousLine()
	switch patchedFileType {
	case ftShell, ftIgnore:
		break
	case ftMakefile:
		ck.checklineOtherAbsolutePathname(line, addedText)
	case ftSource:
		ck.checklineSourceAbsolutePathname(line, addedText)
	case ftConfigure:
		if hasSuffix(addedText, ": Avoid regenerating within pkgsrc") {
			line.Errorf("This code must not be included in patches.")
			Explain(
				"It is generated automatically by pkgsrc after the patch phase.",
				"",
				"For more details, look for \"configure-scripts-override\" in",
				"mk/configure/gnu-configure.mk.")
		}
	default:
		ck.checklineOtherAbsolutePathname(line, addedText)
	}
}

func (ck *PatchChecker) checktextUniHunkCr() {
	if trace.Tracing {
		defer trace.Call0()()
	}

	line := ck.exp.PreviousLine()
	if hasSuffix(line.Text, "\r") {
		fix := line.Autofix()
		fix.Errorf("The hunk header must not end with a CR character.")
		fix.Explain(
			"The MacOS X patch utility cannot handle these.")
		fix.Replace("\r\n", "\n")
		fix.Apply()
	}
}

func (ck *PatchChecker) checktextRcsid(text string) {
	if strings.IndexByte(text, '$') == -1 {
		return
	}
	if m, tagname := match1(text, `\$(Author|Date|Header|Id|Locker|Log|Name|RCSfile|Revision|Source|State|NetBSD)(?::[^\$]*)?\$`); m {
		if matches(text, rePatchUniHunk) {
			ck.exp.PreviousLine().Warnf("Found RCS tag \"$%s$\". Please remove it.", tagname)
		} else {
			ck.exp.PreviousLine().Warnf("Found RCS tag \"$%s$\". Please remove it by reducing the number of context lines using pkgdiff or \"diff -U[210]\".", tagname)
		}
	}
}

func (ck *PatchChecker) isEmptyLine(text string) bool {
	return text == "" ||
		hasPrefix(text, "index ") ||
		hasPrefix(text, "Index: ") ||
		hasPrefix(text, "diff ") ||
		hasPrefix(text, "=============")
}

type FileType uint8

const (
	ftSource FileType = iota
	ftShell
	ftMakefile
	ftText
	ftConfigure
	ftIgnore
	ftUnknown
)

func (ft FileType) String() string {
	return [...]string{
		"source code",
		"shell code",
		"Makefile",
		"text file",
		"configure file",
		"ignored",
		"unknown",
	}[ft]
}

// This is used to select the proper subroutine for detecting absolute pathnames.
func guessFileType(fileName string) (fileType FileType) {
	if trace.Tracing {
		defer trace.Call(fileName, trace.Result(&fileType))()
	}

	basename := path.Base(fileName)
	basename = strings.TrimSuffix(basename, ".in") // doesn't influence the content type
	ext := strings.ToLower(strings.TrimLeft(path.Ext(basename), "."))

	switch {
	case matches(basename, `^I?[Mm]akefile|\.ma?k$`):
		return ftMakefile
	case basename == "configure" || basename == "configure.ac":
		return ftConfigure
	}

	switch ext {
	case "m4", "sh":
		return ftShell
	case "c", "cc", "cpp", "cxx", "el", "h", "hh", "hpp", "l", "pl", "pm", "py", "s", "t", "y":
		return ftSource
	case "conf", "html", "info", "man", "po", "tex", "texi", "texinfo", "txt", "xml":
		return ftText
	case "":
		return ftUnknown
	}

	if trace.Tracing {
		trace.Step1("Unknown file type for %q", fileName)
	}
	return ftUnknown
}

// Looks for strings like "/dev/cd0" appearing in source code
func (ck *PatchChecker) checklineSourceAbsolutePathname(line Line, text string) {
	if !strings.ContainsAny(text, "\"'") {
		return
	}
	if matched, before, _, str := match3(text, `^(.*)(["'])(/\w[^"']*)["']`); matched {
		if trace.Tracing {
			trace.Step2("checklineSourceAbsolutePathname: before=%q, str=%q", before, str)
		}

		switch {
		case matches(before, `[A-Z_][\t ]*$`):
			// ok; C example: const char *echo_cmd = PREFIX "/bin/echo";

		case matches(before, `\+[\t ]*$`):
			// ok; Python example: libdir = prefix + '/lib'

		default:
			CheckwordAbsolutePathname(line, str)
		}
	}
}

func (ck *PatchChecker) checklineOtherAbsolutePathname(line Line, text string) {
	if trace.Tracing {
		defer trace.Call1(text)()
	}

	if hasPrefix(text, "#") && !hasPrefix(text, "#!") {
		// Don't warn for absolute pathnames in comments, except for shell interpreters.

	} else if m, before, path, _ := match3(text, `^(.*?)((?:/[\w.]+)*/(?:bin|dev|etc|home|lib|mnt|opt|proc|sbin|tmp|usr|var)\b[\w./\-]*)(.*)$`); m {
		switch {
		case matches(before, `[\w).@}]$`) && !matches(before, `DESTDIR.$`):
			// Example: $prefix/bin
			// Example: $(prefix)/bin
			// Example: ../bin
			// Example: @prefix@/bin
			// Example: ${prefix}/bin

		case matches(before, `\+[\t ]*["']$`):
			// Example: prefix + '/lib'

		// XXX new: case matches(before, `\bs.$`): // Example: sed -e s,/usr,@PREFIX@,

		default:
			if trace.Tracing {
				trace.Step1("before=%q", before)
			}
			CheckwordAbsolutePathname(line, path)
		}
	}
}
