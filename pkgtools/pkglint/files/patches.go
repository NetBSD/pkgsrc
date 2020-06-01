package pkglint

// Checks for patch files.

import "strings"

func CheckLinesPatch(lines *Lines, pkg *Package) {
	(&PatchChecker{lines, NewLinesLexer(lines), false, false}).Check(pkg)
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

func (ck *PatchChecker) Check(pkg *Package) {
	if ck.lines.CheckCvsID(0, ``, "") {
		ck.llex.Skip()
	}
	if ck.llex.EOF() {
		ck.lines.Lines[0].Errorf("Patch files must not be empty.")
		return
	}

	ck.previousLineEmpty = ck.llex.SkipEmptyOrNote()

	var patchedFiles []Path
	for !ck.llex.EOF() {
		line := ck.llex.CurrentLine()
		if ck.llex.SkipRegexp(rePatchUniFileDel) {
			if m := ck.llex.NextRegexp(rePatchUniFileAdd); m != nil {
				patchedFile := NewPath(m[1])
				ck.checkBeginDiff(line, len(patchedFiles))
				ck.checkUnifiedDiff(patchedFile)
				patchedFiles = append(patchedFiles, patchedFile)
				continue
			}

			ck.llex.Undo()
		}

		if m := ck.llex.NextRegexp(rePatchUniFileAdd); m != nil {
			patchedFile := NewPath(m[1])
			if ck.llex.SkipRegexp(rePatchUniFileDel) {
				ck.checkBeginDiff(line, len(patchedFiles))
				ck.llex.PreviousLine().Warnf("Unified diff headers should be first ---, then +++.")
				ck.checkUnifiedDiff(patchedFile)
				patchedFiles = append(patchedFiles, patchedFile)
				continue
			}

			ck.llex.Undo()
		}

		if ck.llex.SkipRegexp(`^\*\*\*[\t ]([^\t ]+)(.*)$`) {
			if ck.llex.SkipRegexp(`^---[\t ]([^\t ]+)(.*)$`) {
				ck.checkBeginDiff(line, len(patchedFiles))
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

	nPatched := len(patchedFiles)
	if nPatched > 1 && !matches(ck.lines.Filename.String(), `\bCVE\b`) {
		ck.lines.Whole().Warnf("Contains patches for %d files, should be only one.", nPatched)
	}
	if nPatched == 0 {
		ck.lines.Whole().Errorf("Contains no patch.")
	}
	if len(patchedFiles) == 1 {
		ck.checkCanonicalPatchName(patchedFiles[0])
	}

	CheckLinesTrailingEmptyLines(ck.lines)
	sha1Before := computePatchSha1Hex(ck.lines)
	if SaveAutofixChanges(ck.lines) && pkg != nil {
		linesAfter := Load(ck.lines.Filename, 0)
		sha1After := computePatchSha1Hex(linesAfter)
		pkg.AutofixDistinfo(sha1Before, sha1After)
	}
}

// See https://www.gnu.org/software/diffutils/manual/html_node/Detailed-Unified.html
func (ck *PatchChecker) checkUnifiedDiff(patchedFile Path) {
	isConfigure := ck.isConfigure(patchedFile)

	linesDiff := 0
	hasHunks := false
	for {
		m := ck.llex.NextRegexp(rePatchUniHunk)
		if m == nil {
			break
		}

		text := m[0]
		hasHunks = true
		linenoDel := toInt(m[1], 0)
		linesToDel := toInt(m[2], 1)
		linenoAdd := toInt(m[3], 0)
		linesToAdd := toInt(m[4], 1)
		if linenoDel > 0 && linenoAdd > 0 && linenoDel+linesDiff != linenoAdd {
			line := ck.llex.PreviousLine()
			line.Notef("The difference between the line numbers %d and %d should be %d, not %d.",
				linenoDel, linenoAdd, linesDiff, linenoAdd-linenoDel)
			line.Explain(
				"This only happens when patches are edited manually.",
				"",
				"To fix this, either regenerate the line numbers by first running",
				bmake("patch"),
				"and then \"mkpatches\", or edit the line numbers by hand.",
				"",
				"While here, it's a good idea to make the patch apply really cleanly,",
				"by ensuring that the output from the patch command does not contain",
				"the word \"offset\", like in \"Hunk #11 succeeded at 2598 (offset 10 lines).")
		}
		linesDiff += linesToAdd - linesToDel

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
				ck.checkAddedLine(text[1:])

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
		ck.llex.CurrentLine().Errorf("No patch hunks for %q.", patchedFile.String())
	}

	if !ck.llex.EOF() {
		line := ck.llex.CurrentLine()
		if !ck.isEmptyLine(line.Text) && !matches(line.Text, rePatchUniFileDel) {
			line.Warnf("Empty line or end of file expected.")
			line.Explain(
				"This line is not part of the patch anymore, although it may look so.",
				"To make this situation clear, there should be an",
				"empty line above this line.",
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

	if !ck.previousLineEmpty {
		fix := line.Autofix()
		fix.Notef("Empty line expected.")
		fix.InsertAbove("")
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

func (ck *PatchChecker) checkAddedLine(addedText string) {
	dirs := regcomp(`(?:^|[^.@)}])(/usr/pkg|/var|/etc)([^\w-]|$)`)
	for _, m := range dirs.FindAllStringSubmatchIndex(addedText, -1) {
		before := addedText[:m[2]]
		dir := NewPath(addedText[m[2]:m[3]])
		ck.checkAddedAbsPath(before, dir, addedText[m[4]:])
	}
}

func (ck *PatchChecker) checkAddedAbsPath(before string, dir Path, after string) {
	line := ck.llex.PreviousLine()

	// Remove the #define from C and C++ macros.
	before = replaceAll(before, `^[ \t]*#[ \t]*define[ \t]*\w+[ \t]*(.+)[ \t]*$`, "$1")

	// Remove the "set(VAR" from CMakeLists.txt.
	before = replaceAll(before, `^[ \t]*set\(\w+[ \t]*`, "")

	// Ignore comments in shell programs.
	if m, first := match1(before, `^[ \t]*#[ \t]*(\w*)`); m && first != "define" {
		return
	}

	// Ignore paths inside C-style comments.
	if contains(before, "/*") && contains(after, "*/") {
		return
	}

	// Ignore composed C string literals such as PREFIX "/etc".
	if matches(before, `\w+[ \t]*"$`) {
		return
	}

	// Ignore shell literals such as $PREFIX/etc.
	// But keep compiler options like -I/usr/pkg even though they look
	// like a relative pathname.
	if matches(before, `\w$`) && !matches(before, `(^|[ \t])-(I|L|R|rpath|Wl,-R)$`) {
		return
	}

	switch dir {
	case "/usr/pkg":

		line.Errorf("Patches must not hard-code the pkgsrc PREFIX.")
		line.Explain(
			"Not every pkgsrc installation uses /usr/pkg as its PREFIX.",
			"To keep the PREFIX configurable, the patch files should contain",
			"the placeholder @PREFIX@ instead.",
			"",
			"In the pre-configure stage, this placeholder should then be",
			"replaced with the actual configuration directory",
			"using a SUBST block containing SUBST_VARS.dirs=PREFIX.",
			"See mk/subst.mk for details.")

	case "/var":
		afterPath := NewPath(after)
		if afterPath.HasPrefixPath("/tmp") || afterPath.HasPrefixPath("/shm") {
			break
		}

		line.Errorf("Patches must not hard-code the pkgsrc VARBASE.")
		line.Explain(
			"Not every pkgsrc installation uses /var as its directory",
			"for writable files.",
			"To keep the VARBASE configurable, the patch files should",
			"contain the placeholder @VARBASE@ instead.",
			"",
			"In the pre-configure stage, this placeholder should then be",
			"replaced with the actual configuration directory",
			"using a SUBST block containing SUBST_VARS.dirs=VARBASE.",
			"See mk/subst.mk for details.")

	default:
		line.Errorf("Patches must not hard-code the pkgsrc PKG_SYSCONFDIR.")
		line.Explain(
			"Not every pkgsrc installation uses /etc as its directory",
			"for configuration files.",
			"To keep the PKG_SYSCONFDIR configurable, the patch files should",
			"contain the placeholder @PKG_SYSCONFDIR@ instead.",
			"",
			"In the pre-configure stage, this placeholder should then be",
			"replaced with the actual configuration directory",
			"using a SUBST block containing SUBST_VARS.dirs=PKG_SYSCONFDIR.",
			"See mk/subst.mk for details.")
	}
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

func (ck *PatchChecker) checkCanonicalPatchName(patched Path) {
	patch := ck.lines.BaseName.String()
	if matches(patch, `^patch-[a-z][a-z]$`) {
		// This naming scheme is only accepted for historic reasons.
		// It has has absolutely no benefit.
		return
	}
	if matches(patch, `^patch-[A-Z]+-[0-9]+`) {
		return
	}

	// The patch name only needs to correspond very roughly to the patched file.
	// There are varying schemes in use that transform a filename to a patch name.
	normalize := func(s string) string {
		return strings.ToLower(replaceAll(s, `[^A-Za-z0-9]+`, "*"))
	}

	patchedNorm := normalize(patched.Clean().String())
	patchNorm := normalize(strings.TrimPrefix(patch, "patch-"))
	if patchNorm == patchedNorm {
		return
	}
	if hasSuffix(patchedNorm, patchNorm) && patchNorm == normalize(patched.Base().String()) {
		return
	}

	// See pkgtools/pkgdiff/files/mkpatches, function patch_name.
	canon1 := replaceAll(patched.Clean().String(), `_`, "__")
	canon2 := replaceAll(canon1, `[/\s]`, "_")
	canonicalName := "patch-" + canon2

	ck.lines.Whole().Warnf(
		"The patch file should be named %q to match the patched file %q.",
		canonicalName, patched.String())
}

// isEmptyLine tests whether a line provides essentially no interesting content.
// The focus here is on human-generated content that is intended for other human readers.
// Therefore text that is typical for patch generators is considered empty as well.
func (*PatchChecker) isEmptyLine(text string) bool {
	return text == "" ||
		hasPrefix(text, "index ") ||
		hasPrefix(text, "Index: ") ||
		hasPrefix(text, "diff ") ||
		hasPrefix(text, "=============")
}

func (*PatchChecker) isConfigure(filename Path) bool {
	switch filename.Base() {
	case "configure", "configure.in", "configure.ac":
		return true
	}
	return false
}
