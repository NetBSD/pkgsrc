package main

// Checks for patch files.

import (
	"path"
	"strings"
)

type FileType int

const (
	ftSource FileType = iota
	ftShell
	ftMakefile
	ftText
	ftConfigure
	ftIgnore
	ftUnknown
)

// This is used to select the proper subroutine for detecting absolute pathnames.
func guessFileType(line *Line, fname string) FileType {
	basename := path.Base(fname)
	basename = strings.TrimSuffix(basename, ".in") // doesn’t influence the content type
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

	_ = G.opts.DebugMisc && line.debugf("Unknown file type for %q", fname)
	return ftUnknown
}

func checkwordAbsolutePathname(line *Line, word string) {
	defer tracecall("checkwordAbsolutePathname", word)()

	switch {
	case matches(word, `^/dev/(?:null|tty|zero)$`):
		// These are defined by POSIX.
	case word == "/bin/sh":
		// This is usually correct, although on Solaris, it's pretty feature-crippled.
	case matches(word, `^/(?:[a-z]|\$[({])`):
		// Absolute paths probably start with a lowercase letter.
		line.warnf("Found absolute pathname: %s", word)
		line.explain(
			"Absolute pathnames are often an indicator for unportable code. As",
			"pkgsrc aims to be a portable system, absolute pathnames should be",
			"avoided whenever possible.",
			"",
			"A special variable in this context is ${DESTDIR}, which is used in GNU",
			"projects to specify a different directory for installation than what",
			"the programs see later when they are executed. Usually it is empty, so",
			"if anything after that variable starts with a slash, it is considered",
			"an absolute pathname.")
	}
}

// Looks for strings like "/dev/cd0" appearing in source code
func checklineSourceAbsolutePathname(line *Line, text string) {
	if matched, before, _, str := match3(text, `(.*)(["'])(/\w[^"']*)["']`); matched {
		_ = G.opts.DebugMisc && line.debugf("checklineSourceAbsolutePathname: before=%q, str=%q", before, str)

		switch {
		case matches(before, `[A-Z_]+\s*$`):
			// ok; C example: const char *echo_cmd = PREFIX "/bin/echo";

		case matches(before, `\+\s*$`):
			// ok; Python example: libdir = prefix + '/lib'

		default:
			checkwordAbsolutePathname(line, str)
		}
	}
}

func checklineOtherAbsolutePathname(line *Line, text string) {
	defer tracecall("checklineOtherAbsolutePathname", text)()

	if hasPrefix(text, "#") && !hasPrefix(text, "#!") {
		// Don't warn for absolute pathnames in comments, except for shell interpreters.

	} else if m, before, path, _ := match3(text, `^(.*?)((?:/[\w.]+)*/(?:bin|dev|etc|home|lib|mnt|opt|proc|sbin|tmp|usr|var)\b[\w./\-]*)(.*)$`); m {
		switch {
		case hasSuffix(before, "@"): // Example: @PREFIX@/bin
		case matches(before, `[)}]$`): // Example: ${prefix}/bin
		case matches(before, `\+\s*["']$`): // Example: prefix + '/lib'
		case matches(before, `\w$`): // Example: libdir=$prefix/lib
		case hasSuffix(before, "."): // Example: ../dir
		// XXX new: case matches(before, `s.$`): // Example: sed -e s,/usr,@PREFIX@,
		default:
			_ = G.opts.DebugMisc && line.debugf("before=%q", before)
			checkwordAbsolutePathname(line, path)
		}
	}
}

const (
	rePatchNonempty         = `^(.+)$`
	rePatchEmpty            = `^$`
	rePatchTextError        = `\*\*\* Error code`
	rePatchCtxFileDel       = `^\*\*\*\s(\S+)(.*)$`
	rePatchCtxFileAdd       = `^---\s(\S+)(.*)$`
	rePatchCtxHunk          = `^\*{15}(.*)$`
	rePatchCtxHunkDel       = `^\*\*\*\s(\d+)(?:,(\d+))?\s\*\*\*\*$`
	rePatchCtxHunkAdd       = `^-{3}\s(\d+)(?:,(\d+))?\s----$`
	rePatchCtxLineDel       = `^(?:-\s(.*))?$`
	rePatchCtxLineMod       = `^(?:!\s(.*))?$`
	rePatchCtxLineAdd       = `^(?:\+\s(.*))?$`
	rePatchCtxLineContext   = `^(?:\s\s(.*))?$`
	rePatchUniFileDel       = `^---\s(\S+)(?:\s+(.*))?$`
	rePatchUniFileAdd       = `^\+\+\+\s(\S+)(?:\s+(.*))?$`
	rePatchUniHunk          = `^@@\s-(?:(\d+),)?(\d+)\s\+(?:(\d+),)?(\d+)\s@@(.*)$`
	rePatchUniLineDel       = `^-(.*)$`
	rePatchUniLineAdd       = `^\+(.*)$`
	rePatchUniLineContext   = `^\s(.*)$`
	rePatchUniLineNoNewline = `^\\ No newline at end of file$`
)

type PatchState string

const (
	pstOutside PatchState = "pstOutside" // Outside of a diff

	pstCtxFileAdd  PatchState = "pstCtxFileAdd"  // After the DeleteFile line of a context diff
	pstCtxHunk     PatchState = "pstCtxHunk"     // After the AddFile line of a context diff
	pstCtxHunkDel  PatchState = "pstCtxHunkDel"  //
	pstCtxLineDel0 PatchState = "pstCtxLineDel0" //
	pstCtxLineDel  PatchState = "pstCtxLineDel"  //
	pstCtxLineAdd0 PatchState = "pstCtxLineAdd0" //
	pstCtxLineAdd  PatchState = "pstCtxLineAdd"  //

	pstUniFileDelErr PatchState = "pstUniFileDelErr" // Sometimes, the DeleteFile and AddFile are reversed
	pstUniFileAdd    PatchState = "pstUniFileAdd"    // After the DeleteFile line of a unified diff
	pstUniHunk       PatchState = "pstUniHunk"       // After the AddFile line of a unified diff
	pstUniLine       PatchState = "pstUniLine"       // After reading the hunk header
)

func ptNop(ctx *CheckPatchContext) {}
func ptUniFileAdd(ctx *CheckPatchContext) {
	ctx.currentFilename = ctx.m[1]
	ctx.currentFiletype = new(FileType)
	*ctx.currentFiletype = guessFileType(ctx.line, ctx.currentFilename)
	_ = G.opts.DebugPatches && ctx.line.debugf("filename=%q filetype=%v", ctx.currentFilename, *ctx.currentFiletype)
	ctx.patchedFiles++
	ctx.hunks = 0
}

type transition struct {
	re     string
	next   PatchState
	action func(*CheckPatchContext)
}

func (ctx *CheckPatchContext) checkOutside() {
	text := ctx.line.text
	if G.opts.WarnSpace && text != "" && ctx.needEmptyLineNow {
		ctx.line.notef("Empty line expected.")
		ctx.line.insertBefore("\n")
	}
	ctx.needEmptyLineNow = false
	if text != "" {
		ctx.seenComment = true
	}
	ctx.prevLineWasEmpty = text == ""
}

func (ctx *CheckPatchContext) checkBeginDiff() {
	if G.opts.WarnSpace && !ctx.prevLineWasEmpty {
		ctx.line.notef("Empty line expected.")
		ctx.line.insertBefore("\n")
	}
	if !ctx.seenComment {
		ctx.line.errorf("Each patch must be documented.")
		ctx.line.explain(
			"Each patch must document why it is necessary. If it has been applied",
			"because of a security issue, a reference to the CVE should be mentioned",
			"as well.",
			"",
			"Since it is our goal to have as few patches as possible, all patches",
			"should be sent to the upstream maintainers of the package. After you",
			"have done so, you should add a reference to the bug report containing",
			"the patch.")
	}
	ctx.checkOutside()
}

var patchTransitions = map[PatchState][]transition{
	pstOutside: {
		{rePatchEmpty, pstOutside, (*CheckPatchContext).checkOutside},
		{rePatchTextError, pstOutside, (*CheckPatchContext).checkOutside},
		{rePatchCtxFileDel, pstCtxFileAdd, func(ctx *CheckPatchContext) {
			ctx.checkBeginDiff()
			ctx.line.warnf("Please use unified diffs (diff -u) for patches.")
		}},
		{rePatchUniFileDel, pstUniFileAdd, (*CheckPatchContext).checkBeginDiff},
		{rePatchUniFileAdd, pstUniFileDelErr, ptUniFileAdd},
		{rePatchNonempty, pstOutside, (*CheckPatchContext).checkOutside},
	},

	pstUniFileDelErr: {
		{rePatchUniFileDel, pstUniHunk, func(ctx *CheckPatchContext) {
			ctx.line.warnf("Unified diff headers should be first ---, then +++.")
		}},
		{"", pstOutside, ptNop},
	},

	pstCtxFileAdd: {
		{rePatchCtxFileAdd, pstCtxHunk, func(ctx *CheckPatchContext) {
			ctx.currentFilename = ctx.m[1]
			ctx.currentFiletype = new(FileType)
			*ctx.currentFiletype = guessFileType(ctx.line, ctx.currentFilename)
			_ = G.opts.DebugPatches && ctx.line.debugf("filename=%q filetype=%v", ctx.currentFilename, *ctx.currentFiletype)
			ctx.patchedFiles++
			ctx.hunks = 0
		}},
	},

	pstCtxHunk: {
		{rePatchCtxHunk, pstCtxHunkDel, func(ctx *CheckPatchContext) {
			ctx.hunks++
		}},
		{"", pstOutside, ptNop},
	},

	pstCtxHunkDel: {
		{rePatchCtxHunkDel, pstCtxLineDel0, func(ctx *CheckPatchContext) {
			if ctx.m[2] != "" {
				ctx.dellines = 1 + toInt(ctx.m[2]) - toInt(ctx.m[1])
			} else {
				ctx.dellines = toInt(ctx.m[1])
			}
		}},
	},

	pstCtxLineDel0: {
		{rePatchCtxLineContext, pstCtxLineDel, func(ctx *CheckPatchContext) {
			ctx.checkHunkLine(1, 0, pstCtxLineDel0)
		}},
		{rePatchCtxLineDel, pstCtxLineDel, func(ctx *CheckPatchContext) {
			ctx.checkHunkLine(1, 0, pstCtxLineDel0)
		}},
		{rePatchCtxLineMod, pstCtxLineDel, func(ctx *CheckPatchContext) {
			ctx.checkHunkLine(1, 0, pstCtxLineDel0)
		}},
		{rePatchCtxHunkAdd, pstCtxLineAdd0, func(ctx *CheckPatchContext) {
			ctx.dellines = 0
			if 2 < len(ctx.m) {
				ctx.addlines = 1 + toInt(ctx.m[2]) - toInt(ctx.m[1])
			} else {
				ctx.addlines = toInt(ctx.m[1])
			}
		}},
	},

	pstCtxLineDel: {
		{rePatchCtxLineContext, pstCtxLineDel, func(ctx *CheckPatchContext) {
			ctx.checkHunkLine(1, 0, pstCtxLineDel0)
		}},
		{rePatchCtxLineDel, pstCtxLineDel, func(ctx *CheckPatchContext) {
			ctx.checkHunkLine(1, 0, pstCtxLineDel0)
		}},
		{rePatchCtxLineMod, pstCtxLineDel, func(ctx *CheckPatchContext) {
			ctx.checkHunkLine(1, 0, pstCtxLineDel0)
		}},
		{"", pstCtxLineDel0, func(ctx *CheckPatchContext) {
			if ctx.dellines != 0 {
				ctx.line.warnf("Invalid number of deleted lines (%d missing).", ctx.dellines)
			}
		}},
	},

	pstCtxLineAdd0: {
		{rePatchCtxLineContext, pstCtxLineAdd, func(ctx *CheckPatchContext) {
			ctx.checkHunkLine(0, 1, pstCtxHunk)
		}},
		{rePatchCtxLineMod, pstCtxLineAdd, func(ctx *CheckPatchContext) {
			ctx.checkHunkLine(0, 1, pstCtxHunk)
		}},
		{rePatchCtxLineAdd, pstCtxLineAdd, func(ctx *CheckPatchContext) {
			ctx.checkHunkLine(0, 1, pstCtxHunk)
		}},
		{"", pstCtxHunk, ptNop},
	},

	pstCtxLineAdd: {
		{rePatchCtxLineContext, pstCtxLineAdd, func(ctx *CheckPatchContext) {
			ctx.checkHunkLine(0, 1, pstCtxHunk)
		}},
		{rePatchCtxLineMod, pstCtxLineAdd, func(ctx *CheckPatchContext) {
			ctx.checkHunkLine(0, 1, pstCtxHunk)
		}},
		{rePatchCtxLineAdd, pstCtxLineAdd, func(ctx *CheckPatchContext) {
			ctx.checkHunkLine(0, 1, pstCtxHunk)
		}},
		{"", pstCtxLineAdd0, func(ctx *CheckPatchContext) {
			if ctx.addlines != 0 {
				ctx.line.warnf("Invalid number of added lines (%d missing).", ctx.addlines)
			}
		}},
	},

	pstUniFileAdd: {
		{rePatchUniFileAdd, pstUniHunk, ptUniFileAdd},
	},

	pstUniHunk: {
		{rePatchUniHunk, pstUniLine, func(ctx *CheckPatchContext) {
			m := ctx.m
			if m[1] != "" {
				ctx.dellines = toInt(m[2])
			} else {
				ctx.dellines = 1
			}
			if m[3] != "" {
				ctx.addlines = toInt(m[4])
			} else {
				ctx.addlines = 1
			}
			ctx.checkText(ctx.line.text)
			if hasSuffix(ctx.line.text, "\r") {
				ctx.line.errorf("The hunk header must not end with a CR character.")
				ctx.line.explain(
					"The MacOS X patch utility cannot handle these.")
				ctx.line.replace("\r\n", "\n")
			}
			ctx.hunks++
			if m[1] != "" && m[1] != "1" {
				ctx.contextScanningLeading = new(bool)
				*ctx.contextScanningLeading = true
			} else {
				ctx.contextScanningLeading = nil
			}
			ctx.leadingContextLines = 0
			ctx.trailingContextLines = 0
		}},
		{"", pstOutside, func(ctx *CheckPatchContext) {
			if ctx.hunks == 0 {
				ctx.line.warnf("No hunks for file %q.", ctx.currentFilename)
			}
		}},
	},

	pstUniLine: {
		{rePatchUniLineDel, pstUniLine, func(ctx *CheckPatchContext) {
			ctx.checkHunkLine(1, 0, pstUniHunk)
		}},
		{rePatchUniLineAdd, pstUniLine, func(ctx *CheckPatchContext) {
			ctx.checkHunkLine(0, 1, pstUniHunk)
		}},
		{rePatchUniLineContext, pstUniLine, func(ctx *CheckPatchContext) {
			ctx.checkHunkLine(1, 1, pstUniHunk)
		}},
		{rePatchUniLineNoNewline, pstUniLine, func(ctx *CheckPatchContext) {
		}},
		{rePatchEmpty, pstUniLine, func(ctx *CheckPatchContext) {
			if G.opts.WarnSpace {
				ctx.line.notef("Leading white-space missing in hunk.")
				ctx.line.replaceRegex(`^`, " ")
			}
			ctx.checkHunkLine(1, 1, pstUniHunk)
		}},
		{"", pstUniHunk, func(ctx *CheckPatchContext) {
			if ctx.dellines != 0 || ctx.addlines != 0 {
				ctx.line.warnf("Unexpected end of hunk (-%d,+%d expected).", ctx.dellines, ctx.addlines)
			}
		}},
	},
}

func checklinesPatch(lines []*Line) {
	defer tracecall("checklinesPatch", lines[0].fname)()

	checklineRcsid(lines[0], ``, "")

	ctx := CheckPatchContext{state: pstOutside, needEmptyLineNow: true}
	for lineno := 1; lineno < len(lines); {
		line := lines[lineno]
		text := line.text
		ctx.line = line

		_ = G.opts.DebugPatches &&
			line.debugf("state=%s hunks=%d del=%d add=%d text=%s",
				ctx.state, ctx.hunks, ctx.dellines, ctx.addlines, text)

		found := false
		for _, t := range patchTransitions[ctx.state] {
			if t.re == "" {
				ctx.m = ctx.m[:0]
			} else if ctx.m = match(text, t.re); ctx.m == nil {
				continue
			}

			ctx.redostate = nil
			ctx.nextstate = t.next
			t.action(&ctx)
			if ctx.redostate != nil {
				ctx.state = *ctx.redostate
			} else {
				ctx.state = ctx.nextstate
				if t.re != "" {
					lineno++
				}
			}
			found = true
			break
		}

		if !found {
			ctx.line.errorf("Internal pkglint error: checklinesPatch state=%s", ctx.state)
			ctx.state = pstOutside
			lineno++
		}
	}

	fname := lines[0].fname
	for ctx.state != pstOutside {
		_ = G.opts.DebugPatches &&
			debugf(fname, "EOF", "state=%s hunks=%d del=%d add=%d",
				ctx.state, ctx.hunks, ctx.dellines, ctx.addlines)

		found := false
		for _, t := range patchTransitions[ctx.state] {
			if t.re == "" {
				ctx.m = ctx.m[:0]
				ctx.redostate = nil
				ctx.nextstate = t.next
				t.action(&ctx)
				if ctx.redostate != nil {
					ctx.state = *ctx.redostate
				} else {
					ctx.state = ctx.nextstate
				}
				found = true
			}
		}

		if !found {
			ctx.line.errorf("Internal pkglint error: checklinesPatch state=%s", ctx.state)
			break
		}
	}

	if ctx.patchedFiles > 1 {
		warnf(fname, noLines, "Contains patches for %d files, should be only one.", ctx.patchedFiles)
	} else if ctx.patchedFiles == 0 {
		errorf(fname, noLines, "Contains no patch.")
	}

	checklinesTrailingEmptyLines(lines)
	saveAutofixChanges(lines)
}

type CheckPatchContext struct {
	state                  PatchState
	redostate              *PatchState
	nextstate              PatchState
	dellines               int
	addlines               int
	hunks                  int
	seenComment            bool
	needEmptyLineNow       bool
	prevLineWasEmpty       bool
	currentFilename        string
	currentFiletype        *FileType
	patchedFiles           int
	leadingContextLines    int
	trailingContextLines   int
	contextScanningLeading *bool
	line                   *Line
	m                      []string
}

func (ctx *CheckPatchContext) expectEmptyLine() {
	if G.opts.WarnSpace {
		ctx.line.notef("Empty line expected.")
		ctx.line.insertBefore("\n")
	}
}

func (ctx *CheckPatchContext) useUnifiedDiffs() {
	ctx.line.warnf("Please use unified diffs (diff -u) for patches.")
}

func (ctx *CheckPatchContext) checkText(text string) {
	if m, tagname := match1(text, `\$(Author|Date|Header|Id|Locker|Log|Name|RCSfile|Revision|Source|State|NetBSD)(?::[^\$]*)?\$`); m {
		if matches(text, rePatchUniHunk) {
			ctx.line.warnf("Found RCS tag \"$%s$\". Please remove it.", tagname)
		} else {
			ctx.line.warnf("Found RCS tag \"$%s$\". Please remove it by reducing the number of context lines using pkgdiff or \"diff -U[210]\".", tagname)
		}
	}
}

func (ctx *CheckPatchContext) checkContents() {
	if 1 < len(ctx.m) {
		ctx.checkText(ctx.m[1])
	}
}

func (ctx *CheckPatchContext) checkAddedContents() {
	if !(1 < len(ctx.m)) {
		return
	}

	line := ctx.line
	addedText := ctx.m[1]

	switch *ctx.currentFiletype {
	case ftShell:
	case ftMakefile:
		// This check is not as accurate as the similar one in MkLine.checkShelltext.
		shellwords, _ := splitIntoShellwords(line, addedText)
		for _, shellword := range shellwords {
			if !hasPrefix(shellword, "#") {
				NewMkLine(line).checkAbsolutePathname(shellword)
			}
		}
	case ftSource:
		checklineSourceAbsolutePathname(line, addedText)
	case ftConfigure:
		if matches(addedText, `: Avoid regenerating within pkgsrc$`) {
			line.errorf("This code must not be included in patches.")
			line.explain(
				"It is generated automatically by pkgsrc after the patch phase.",
				"",
				"For more details, look for \"configure-scripts-override\" in",
				"mk/configure/gnu-configure.mk.")
		}
	case ftIgnore:
		break
	default:
		checklineOtherAbsolutePathname(line, addedText)
	}
}

func (ctx *CheckPatchContext) checkHunkEnd(deldelta, adddelta int, newstate PatchState) {
	if deldelta > 0 && ctx.dellines == 0 {
		ctx.redostate = &newstate
		if ctx.addlines > 0 {
			ctx.line.errorf("Expected %d more lines to be added.", ctx.addlines)
		}
		return
	}

	if adddelta > 0 && ctx.addlines == 0 {
		ctx.redostate = &newstate
		if ctx.dellines > 0 {
			ctx.line.errorf("Expected %d more lines to be deleted.", ctx.dellines)
		}
		return
	}

	if ctx.contextScanningLeading != nil {
		if deldelta != 0 && adddelta != 0 {
			if *ctx.contextScanningLeading {
				ctx.leadingContextLines++
			} else {
				ctx.trailingContextLines++
			}
		} else {
			if *ctx.contextScanningLeading {
				*ctx.contextScanningLeading = false
			} else {
				ctx.trailingContextLines = 0
			}
		}
	}

	if deldelta > 0 {
		ctx.dellines -= deldelta
	}
	if adddelta > 0 {
		ctx.addlines -= adddelta
	}

	if ctx.dellines == 0 && ctx.addlines == 0 {
		if ctx.contextScanningLeading != nil {
			if ctx.leadingContextLines != ctx.trailingContextLines {
				_ = G.opts.DebugPatches && ctx.line.warnf(
					"The hunk that ends here does not have as many leading (%d) as trailing (%d) lines of context.",
					ctx.leadingContextLines, ctx.trailingContextLines)
			}
		}
		ctx.nextstate = newstate
	}
}

func (ctx *CheckPatchContext) checkHunkLine(deldelta, adddelta int, newstate PatchState) {
	ctx.checkContents()
	ctx.checkHunkEnd(deldelta, adddelta, newstate)

	// If -Wextra is given, the context lines are checked for
	// absolute paths and similar things. If it is not given,
	// only those lines that really add something to the patched
	// file are checked.
	if adddelta > 0 && (deldelta == 0 || G.opts.WarnExtra) {
		ctx.checkAddedContents()
	}
}
