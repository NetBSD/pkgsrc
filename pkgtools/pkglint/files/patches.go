package main

// Checks for patch files.

import (
	"netbsd.org/pkglint/line"
	"netbsd.org/pkglint/textproc"
	"netbsd.org/pkglint/trace"
	"path"
	"strings"
)

func ChecklinesPatch(lines []line.Line) {
	if trace.Tracing {
		defer trace.Call1(lines[0].Filename())()
	}

	(&PatchChecker{lines, textproc.NewExpecter(lines), false, false}).Check()
}

type PatchChecker struct {
	lines             []line.Line
	exp               *textproc.Expecter
	seenDocumentation bool
	previousLineEmpty bool
}

const (
	rePatchUniFileDel = `^---\s(\S+)(?:\s+(.*))?$`
	rePatchUniFileAdd = `^\+\+\+\s(\S+)(?:\s+(.*))?$`
	rePatchUniHunk    = `^@@ -(\d+)(?:,(\d+))? \+(\d+)(?:,(\d+))? @@(.*)$`
)

func (ck *PatchChecker) Check() {
	if trace.Tracing {
		defer trace.Call0()()
	}

	if (LineChecker{ck.lines[0]}).CheckRcsid(``, "") {
		ck.exp.Advance()
	}
	ck.previousLineEmpty = ck.exp.ExpectEmptyLine(G.opts.WarnSpace)

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

		if ck.exp.AdvanceIfMatches(`^\*\*\*\s(\S+)(.*)$`) {
			if ck.exp.AdvanceIfMatches(`^---\s(\S+)(.*)$`) {
				ck.checkBeginDiff(line, patchedFiles)
				line.Warnf("Please use unified diffs (diff -u) for patches.")
				return
			}

			ck.exp.StepBack()
		}

		ck.exp.Advance()
		ck.previousLineEmpty = ck.isEmptyLine(line.Text())
		if !ck.previousLineEmpty {
			ck.seenDocumentation = true
		}
	}

	if patchedFiles > 1 {
		NewLineWhole(ck.lines[0].Filename()).Warnf("Contains patches for %d files, should be only one.", patchedFiles)
	} else if patchedFiles == 0 {
		NewLineWhole(ck.lines[0].Filename()).Errorf("Contains no patch.")
	}

	ChecklinesTrailingEmptyLines(ck.lines)
	SaveAutofixChanges(ck.lines)
}

// See http://www.gnu.org/software/diffutils/manual/html_node/Detailed-Unified.html
func (ck *PatchChecker) checkUnifiedDiff(patchedFile string) {
	if trace.Tracing {
		defer trace.Call0()()
	}

	patchedFileType := guessFileType(ck.exp.CurrentLine(), patchedFile)
	if trace.Tracing {
		trace.Stepf("guessFileType(%q) = %s", patchedFile, patchedFileType)
	}

	hasHunks := false
	for ck.exp.AdvanceIfMatches(rePatchUniHunk) {
		hasHunks = true
		linesToDel := toInt(ck.exp.Group(2), 1)
		linesToAdd := toInt(ck.exp.Group(4), 1)
		if trace.Tracing {
			trace.Stepf("hunk -%d +%d", linesToDel, linesToAdd)
		}
		ck.checktextUniHunkCr()

		for linesToDel > 0 || linesToAdd > 0 || hasPrefix(ck.exp.CurrentLine().Text(), "\\") {
			line := ck.exp.CurrentLine()
			ck.exp.Advance()
			text := line.Text()
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
				// \ No newline at end of file
			default:
				line.Errorf("Invalid line in unified patch hunk")
				return
			}
		}
	}
	if !hasHunks {
		ck.exp.CurrentLine().Errorf("No patch hunks for %q.", patchedFile)
	}
	if !ck.exp.EOF() {
		line := ck.exp.CurrentLine()
		if !ck.isEmptyLine(line.Text()) && !matches(line.Text(), rePatchUniFileDel) {
			line.Warnf("Empty line or end of file expected.")
			Explain(
				"This empty line makes the end of the patch clearly visible.",
				"Otherwise the reader would have to count lines to see where",
				"the patch ends.")
		}
	}
}

func (ck *PatchChecker) checkBeginDiff(line line.Line, patchedFiles int) {
	if trace.Tracing {
		defer trace.Call0()()
	}

	if !ck.seenDocumentation && patchedFiles == 0 {
		line.Errorf("Each patch must be documented.")
		Explain(
			"Pkgsrc tries to have as few patches as possible.  Therefore, each",
			"patch must document why it is necessary.  Typical reasons are",
			"portability or security.",
			"",
			"Patches that are related to a security issue should mention the",
			"corresponding CVE identifier.",
			"",
			"Each patch should be sent to the upstream maintainers of the",
			"package, so that they can include it in future versions.  After",
			"submitting a patch upstream, the corresponding bug report should",
			"be mentioned in this file, to prevent duplicate work.")
	}
	if G.opts.WarnSpace && !ck.previousLineEmpty {
		if !line.AutofixInsertBefore("") {
			line.Notef("Empty line expected.")
		}
	}
}

func (ck *PatchChecker) checklineContext(text string, patchedFileType FileType) {
	if trace.Tracing {
		defer trace.Call2(text, patchedFileType.String())()
	}

	if G.opts.WarnExtra {
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
		checklineOtherAbsolutePathname(line, addedText)
	case ftSource:
		checklineSourceAbsolutePathname(line, addedText)
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
		checklineOtherAbsolutePathname(line, addedText)
	}
}

func (ck *PatchChecker) checktextUniHunkCr() {
	if trace.Tracing {
		defer trace.Call0()()
	}

	line := ck.exp.PreviousLine()
	if hasSuffix(line.Text(), "\r") {
		if !line.AutofixReplace("\r\n", "\n") {
			line.Errorf("The hunk header must not end with a CR character.")
			Explain(
				"The MacOS X patch utility cannot handle these.")
		}
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
func guessFileType(line line.Line, fname string) (fileType FileType) {
	if trace.Tracing {
		defer trace.Call(fname, "=>", &fileType)()
	}

	basename := path.Base(fname)
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
		trace.Step1("Unknown file type for %q", fname)
	}
	return ftUnknown
}

func checkwordAbsolutePathname(line line.Line, word string) {
	if trace.Tracing {
		defer trace.Call1(word)()
	}

	switch {
	case matches(word, `^/dev/(?:null|tty|zero)$`):
		// These are defined by POSIX.
	case word == "/bin/sh":
		// This is usually correct, although on Solaris, it's pretty feature-crippled.
	case matches(word, `^/s\W`):
		// Probably a sed(1) command
	case matches(word, `^/(?:[a-z]|\$[({])`):
		// Absolute paths probably start with a lowercase letter.
		line.Warnf("Found absolute pathname: %s", word)
		Explain(
			"Absolute pathnames are often an indicator for unportable code.  As",
			"pkgsrc aims to be a portable system, absolute pathnames should be",
			"avoided whenever possible.",
			"",
			"A special variable in this context is ${DESTDIR}, which is used in",
			"GNU projects to specify a different directory for installation than",
			"what the programs see later when they are executed.  Usually it is",
			"empty, so if anything after that variable starts with a slash, it is",
			"considered an absolute pathname.")
	}
}

// Looks for strings like "/dev/cd0" appearing in source code
func checklineSourceAbsolutePathname(line line.Line, text string) {
	if !strings.ContainsAny(text, "\"'") {
		return
	}
	if matched, before, _, str := match3(text, `^(.*)(["'])(/\w[^"']*)["']`); matched {
		if trace.Tracing {
			trace.Step2("checklineSourceAbsolutePathname: before=%q, str=%q", before, str)
		}

		switch {
		case matches(before, `[A-Z_]\s*$`):
			// ok; C example: const char *echo_cmd = PREFIX "/bin/echo";

		case matches(before, `\+\s*$`):
			// ok; Python example: libdir = prefix + '/lib'

		default:
			checkwordAbsolutePathname(line, str)
		}
	}
}

func checklineOtherAbsolutePathname(line line.Line, text string) {
	if trace.Tracing {
		defer trace.Call1(text)()
	}

	if hasPrefix(text, "#") && !hasPrefix(text, "#!") {
		// Don't warn for absolute pathnames in comments, except for shell interpreters.

	} else if m, before, path, _ := match3(text, `^(.*?)((?:/[\w.]+)*/(?:bin|dev|etc|home|lib|mnt|opt|proc|sbin|tmp|usr|var)\b[\w./\-]*)(.*)$`); m {
		switch {
		case hasSuffix(before, "@"): // Example: @PREFIX@/bin
		case matches(before, `[)}]$`) && !matches(before, `DESTDIR[)}]$`): // Example: ${prefix}/bin
		case matches(before, `\+\s*["']$`): // Example: prefix + '/lib'
		case matches(before, `\$\w$`): // Example: libdir=$prefix/lib
		case hasSuffix(before, "."): // Example: ../dir
		// XXX new: case matches(before, `s.$`): // Example: sed -e s,/usr,@PREFIX@,
		default:
			if trace.Tracing {
				trace.Step1("before=%q", before)
			}
			checkwordAbsolutePathname(line, path)
		}
	}
}
