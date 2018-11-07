package main

import (
	"strings"
)

// MkLines contains data for the Makefile (or *.mk) that is currently checked.
type MkLines = *MkLinesImpl

type MkLinesImpl struct {
	mklines       []MkLine
	lines         Lines
	forVars       map[string]bool // The variables currently used in .for loops
	target        string          // Current make(1) target
	vars          Scope
	buildDefs     map[string]bool   // Variables that are registered in BUILD_DEFS, to ensure that all user-defined variables are added to it.
	plistVarAdded map[string]MkLine // Identifiers that are added to PLIST_VARS.
	plistVarSet   map[string]MkLine // Identifiers for which PLIST.${id} is defined.
	plistVarSkip  bool              // True if any of the PLIST_VARS identifiers refers to a variable.
	Tools         *Tools            // Tools defined in file scope.
	indentation   *Indentation      // Indentation depth of preprocessing directives; only available during MkLines.ForEach.
	Once
}

func NewMkLines(lines Lines) MkLines {
	mklines := make([]MkLine, lines.Len())
	for i, line := range lines.Lines {
		mklines[i] = NewMkLine(line)
	}

	tools := NewTools(lines.FileName)
	tools.Fallback(G.Pkgsrc.Tools)

	return &MkLinesImpl{
		mklines,
		lines,
		make(map[string]bool),
		"",
		NewScope(),
		make(map[string]bool),
		make(map[string]MkLine),
		make(map[string]MkLine),
		false,
		tools,
		nil,
		Once{}}
}

func (mklines *MkLinesImpl) UseVar(mkline MkLine, varname string) {
	mklines.vars.Use(varname, mkline)
	if G.Pkg != nil {
		G.Pkg.vars.Use(varname, mkline)
	}
}

func (mklines *MkLinesImpl) Check() {
	if trace.Tracing {
		defer trace.Call1(mklines.lines.FileName)()
	}

	G.Mk = mklines
	defer func() { G.Mk = nil }()

	// In the first pass, all additions to BUILD_DEFS and USE_TOOLS
	// are collected to make the order of the definitions irrelevant.
	mklines.DetermineUsedVariables()
	mklines.DetermineDefinedVariables()
	mklines.collectPlistVars()
	mklines.collectElse()

	// In the second pass, the actual checks are done.
	mklines.checkAll()

	SaveAutofixChanges(mklines.lines)
}

func (mklines *MkLinesImpl) checkAll() {
	allowedTargets := func() map[string]bool {
		targets := make(map[string]bool)
		prefixes := [...]string{"pre", "do", "post"}
		actions := [...]string{"fetch", "extract", "patch", "tools", "wrapper", "configure", "build", "test", "install", "package", "clean"}
		for _, prefix := range prefixes {
			for _, action := range actions {
				targets[prefix+"-"+action] = true
			}
		}
		return targets
	}()

	CheckLineRcsid(mklines.lines.Lines[0], `#[\t ]+`, "# ")

	substContext := NewSubstContext()
	var varalign VaralignBlock
	isHacksMk := mklines.lines.BaseName == "hacks.mk"

	lineAction := func(mkline MkLine) bool {
		if isHacksMk {
			mklines.Tools.SeenPrefs = true
		}

		ck := MkLineChecker{mkline}
		ck.Check()
		varalign.Check(mkline)
		mklines.Tools.ParseToolLine(mkline, false, false)

		switch {
		case mkline.IsEmpty():
			substContext.Finish(mkline)

		case mkline.IsVarassign():
			mklines.target = ""
			mkline.Tokenize(mkline.Value(), true) // Just for the side-effect of the warnings.
			substContext.Varassign(mkline)

			switch mkline.Varcanon() {
			case "PLIST_VARS":
				ids := mkline.ValueSplit(resolveVariableRefs(mkline.Value()), "")
				for _, id := range ids {
					if !mklines.plistVarSkip && mklines.plistVarSet[id] == nil {
						mkline.Warnf("%q is added to PLIST_VARS, but PLIST.%s is not defined in this file.", id, id)
					}
				}

			case "PLIST.*":
				id := mkline.Varparam()
				if !mklines.plistVarSkip && mklines.plistVarAdded[id] == nil {
					mkline.Warnf("PLIST.%s is defined, but %q is not added to PLIST_VARS in this file.", id, id)
				}
			}

		case mkline.IsInclude():
			mklines.target = ""
			if G.Pkg != nil {
				G.Pkg.CheckInclude(mkline, mklines.indentation)
			}

		case mkline.IsDirective():
			ck.checkDirective(mklines.forVars, mklines.indentation)
			substContext.Directive(mkline)

		case mkline.IsDependency():
			ck.checkDependencyRule(allowedTargets)
			mklines.target = mkline.Targets()

		case mkline.IsShellCommand():
			mkline.Tokenize(mkline.ShellCommand(), true) // Just for the side-effect of the warnings.
		}

		return true
	}

	atEnd := func(mkline MkLine) {
		mklines.indentation.CheckFinish(mklines.lines.FileName)
	}

	// TODO: Extract this code so that it is clearly visible in the stack trace.
	if trace.Tracing {
		trace.Stepf("Starting main checking loop")
	}
	mklines.ForEachEnd(lineAction, atEnd)

	substContext.Finish(NewMkLine(mklines.lines.EOFLine())) // TODO: mklines.EOFLine()
	varalign.Finish()

	ChecklinesTrailingEmptyLines(mklines.lines)
}

// ForEach calls the action for each line, until the action returns false.
// It keeps track of the indentation (see MkLines.indentation)
// and all conditional variables (see Indentation.IsConditional).
func (mklines *MkLinesImpl) ForEach(action func(mkline MkLine)) {
	mklines.ForEachEnd(
		func(mkline MkLine) bool { action(mkline); return true },
		func(mkline MkLine) {})
}

// ForEachEnd calls the action for each line, until the action returns false.
// It keeps track of the indentation and all conditional variables.
// At the end, atEnd is called with the last line as its argument.
func (mklines *MkLinesImpl) ForEachEnd(action func(mkline MkLine) bool, atEnd func(lastMkline MkLine)) {

	// XXX: To avoid looping over the lines multiple times, it would
	// be nice to have an interface LinesChecker that checks a single thing.
	// Multiple of these line checkers could be run in parallel, so that
	// the diagnostics appear in the correct order, from top to bottom.

	mklines.indentation = NewIndentation()
	mklines.Tools.SeenPrefs = false

	for _, mkline := range mklines.mklines {
		mklines.indentation.TrackBefore(mkline)
		if !action(mkline) {
			break
		}
		mklines.indentation.TrackAfter(mkline)
	}

	atEnd(mklines.mklines[len(mklines.mklines)-1])
	mklines.indentation = nil
}

func (mklines *MkLinesImpl) DetermineDefinedVariables() {
	if trace.Tracing {
		defer trace.Call0()()
	}

	for _, mkline := range mklines.mklines {
		mklines.Tools.ParseToolLine(mkline, false, true)

		if !mkline.IsVarassign() {
			continue
		}

		defineVar(mkline, mkline.Varname())

		varcanon := mkline.Varcanon()
		switch varcanon {
		case
			"BUILD_DEFS",
			"PKG_GROUPS_VARS",
			"PKG_USERS_VARS":
			for _, varname := range fields(mkline.Value()) {
				mklines.buildDefs[varname] = true
				if trace.Tracing {
					trace.Step1("%q is added to BUILD_DEFS.", varname)
				}
			}

		case
			"BUILTIN_FIND_FILES_VAR",
			"BUILTIN_FIND_HEADERS_VAR":
			for _, varname := range fields(mkline.Value()) {
				mklines.vars.Define(varname, mkline)
			}

		case "PLIST_VARS":
			ids := mkline.ValueSplit(resolveVariableRefs(mkline.Value()), "")
			for _, id := range ids {
				if trace.Tracing {
					trace.Step1("PLIST.%s is added to PLIST_VARS.", id)
				}
				if containsVarRef(id) {
					mklines.UseVar(mkline, "PLIST.*")
					mklines.plistVarSkip = true
				} else {
					mklines.UseVar(mkline, "PLIST."+id)
				}
			}

		case "SUBST_VARS.*":
			for _, svar := range fields(mkline.Value()) {
				mklines.UseVar(mkline, varnameCanon(svar))
				if trace.Tracing {
					trace.Step1("varuse %s", svar)
				}
			}

		case "OPSYSVARS":
			for _, osvar := range fields(mkline.Value()) {
				mklines.UseVar(mkline, osvar+".*")
				defineVar(mkline, osvar)
			}
		}
	}
}

func (mklines *MkLinesImpl) collectPlistVars() {
	for _, mkline := range mklines.mklines {
		if mkline.IsVarassign() {
			switch mkline.Varcanon() {
			case "PLIST_VARS":
				ids := mkline.ValueSplit(resolveVariableRefs(mkline.Value()), "")
				for _, id := range ids {
					if containsVarRef(id) {
						mklines.plistVarSkip = true
					} else {
						mklines.plistVarAdded[id] = mkline
					}
				}
			case "PLIST.*":
				id := mkline.Varparam()
				if containsVarRef(id) {
					mklines.plistVarSkip = true
				} else {
					mklines.plistVarSet[id] = mkline
				}
			}
		}
	}
}

func (mklines *MkLinesImpl) collectElse() {
	// Make a dry-run over the lines, which sets data.elseLine (in mkline.go) as a side-effect.
	mklines.ForEach(func(mkline MkLine) {})
}

func (mklines *MkLinesImpl) DetermineUsedVariables() {
	for _, mkline := range mklines.mklines {
		for _, varname := range mkline.DetermineUsedVariables() {
			mklines.UseVar(mkline, varname)
		}
	}

	mklines.determineDocumentedVariables()
}

// Loosely based on mk/help/help.awk, revision 1.28
func (mklines *MkLinesImpl) determineDocumentedVariables() {
	scope := NewScope()
	commentLines := 0
	relevant := true

	finish := func() {
		if commentLines >= 3 && relevant {
			for varname, mkline := range scope.used {
				mklines.vars.Use(varname, mkline)
			}
		}

		scope = NewScope()
		commentLines = 0
		relevant = true
	}

	for _, mkline := range mklines.mklines {
		text := mkline.Text
		switch {
		case hasPrefix(text, "#"):
			words := fields(text)
			if len(words) <= 1 {
				break
			}

			commentLines++

			parser := NewMkParser(mkline.Line, words[1], false)
			varname := parser.Varname()
			if hasSuffix(varname, ".") && parser.repl.AdvanceRegexp(`^<\w+>`) {
				varname += "*"
			}
			parser.repl.AdvanceStr(":")

			varbase := varnameBase(varname)
			if varbase == strings.ToUpper(varbase) && matches(varbase, `[A-Z]`) && parser.EOF() {
				scope.Use(varname, mkline)
			}

			if 1 < len(words) && words[1] == "Copyright" {
				relevant = false
			}

		case mkline.IsEmpty():
			finish()
		}
	}

	finish()
}

func (mklines *MkLinesImpl) CheckRedundantVariables() {
	scope := NewRedundantScope()
	isRelevant := func(old, new MkLine) bool {
		if old.Basename != "Makefile" && new.Basename == "Makefile" {
			return false
		}
		if new.Op() == opAssignEval {
			return false
		}
		return true
	}
	scope.OnIgnore = func(old, new MkLine) {
		if isRelevant(old, new) && old.Value() == new.Value() {
			old.Notef("Definition of %s is redundant because of %s.", new.Varname(), old.RefTo(new))
		}
	}
	scope.OnOverwrite = func(old, new MkLine) {
		if isRelevant(old, new) {
			old.Warnf("Variable %s is overwritten in %s.", new.Varname(), old.RefTo(new))
			Explain(
				"The variable definition in this line does not have an effect since",
				"it is overwritten elsewhere.  This typically happens because of a",
				"typo (writing = instead of +=) or because the line that overwrites",
				"is in another file that is used by several packages.")
		}
	}

	mklines.ForEach(scope.Handle)
}

func (mklines *MkLinesImpl) CheckForUsedComment(relativeName string) {
	lines := mklines.lines
	if lines.Len() < 3 {
		return
	}

	expected := "# used by " + relativeName
	for _, line := range lines.Lines {
		if line.Text == expected {
			return
		}
	}

	i := 0
	for i < 2 && hasPrefix(lines.Lines[i].Text, "#") {
		i++
	}

	fix := lines.Lines[i].Autofix()
	fix.Warnf("Please add a line %q here.", expected)
	fix.Explain(
		"Since Makefile.common files usually don't have any comments and",
		"therefore not a clearly defined interface, they should at least",
		"contain references to all files that include them, so that it is",
		"easier to see what effects future changes may have.",
		"",
		"If there are more than five packages that use a Makefile.common,",
		"you should think about giving it a proper name (maybe plugin.mk) and",
		"documenting its interface.")
	fix.InsertBefore(expected)
	fix.Apply()

	SaveAutofixChanges(lines)
}

func (mklines *MkLinesImpl) SaveAutofixChanges() {
	mklines.lines.SaveAutofixChanges()
}

// VaralignBlock checks that all variable assignments from a paragraph
// use the same indentation depth for their values.
// It also checks that the indentation uses tabs instead of spaces.
//
// In general, all values should be aligned using tabs.
// As an exception, very long lines may be aligned with a single space.
// A typical example is a SITES.very-long-file-name.tar.gz variable
// between HOMEPAGE and DISTFILES.
type VaralignBlock struct {
	infos []*varalignBlockInfo
	skip  bool
}

type varalignBlockInfo struct {
	mkline         MkLine
	varnameOp      string // Variable name + assignment operator
	varnameOpWidth int    // Screen width of varnameOp
	space          string // Whitespace between varnameOp and the variable value
	totalWidth     int    // Screen width of varnameOp + space
	continuation   bool   // A continuation line with no value in the first line.
}

func (va *VaralignBlock) Check(mkline MkLine) {
	switch {
	case !G.Opts.WarnSpace:
		return

	case mkline.IsEmpty():
		va.Finish()
		return

	case mkline.IsCommentedVarassign():
		break

	case mkline.IsComment():
		return

	case mkline.IsDirective():
		return

	case !mkline.IsVarassign():
		trace.Stepf("Skipping")
		va.skip = true
		return
	}

	switch {
	case mkline.Op() == opAssignEval && matches(mkline.Varname(), `^[a-z]`):
		// Arguments to procedures do not take part in block alignment.
		//
		// Example:
		// pkgpath := ${PKGPATH}
		return

	case mkline.Value() == "" && mkline.VarassignComment() == "":
		// Multiple-inclusion guards usually appear in a block of
		// their own and therefore do not need alignment.
		//
		// Example:
		// .if !defined(INCLUSION_GUARD_MK)
		// INCLUSION_GUARD_MK:=
		// # ...
		// .endif
		return
	}

	continuation := false
	if mkline.IsMultiline() {
		// Interpreting the continuation marker as variable value
		// is cheating but works well.
		text := strings.TrimSuffix(mkline.raw[0].orignl, "\n")
		m, _, _, _, _, _, value, _, _ := MatchVarassign(text)
		continuation = m && value == "\\"
	}

	valueAlign := mkline.ValueAlign()
	varnameOp := strings.TrimRight(valueAlign, " \t")
	space := valueAlign[len(varnameOp):]

	width := tabWidth(valueAlign)
	va.infos = append(va.infos, &varalignBlockInfo{mkline, varnameOp, tabWidth(varnameOp), space, width, continuation})
}

func (va *VaralignBlock) Finish() {
	infos := va.infos
	skip := va.skip
	*va = VaralignBlock{}

	if len(infos) == 0 || skip {
		return
	}

	if trace.Tracing {
		defer trace.Call(infos[0].mkline.Line)()
	}

	newWidth := va.optimalWidth(infos)
	if newWidth == 0 {
		return
	}

	for _, info := range infos {
		va.realign(info.mkline, info.varnameOp, info.space, info.continuation, newWidth)
	}
}

// optimalWidth computes the minimum necessary screen width for the
// variable assignment lines. There may be a single line sticking out
// from the others (called outlier). This is to prevent a single SITES.*
// variable from forcing the rest of the paragraph to be indented too
// far to the right.
func (va *VaralignBlock) optimalWidth(infos []*varalignBlockInfo) int {
	longest := 0       // The longest seen varnameOpWidth
	secondLongest := 0 // The second-longest seen varnameOpWidth
	for _, info := range infos {
		if info.continuation {
			continue
		}

		width := info.varnameOpWidth
		if width >= longest {
			secondLongest = longest
			longest = width
		} else if width > secondLongest {
			secondLongest = width
		}
	}

	// Minimum required width of varnameOp, without the trailing whitespace.
	minVarnameOpWidth := longest
	outlier := 0
	if secondLongest != 0 && secondLongest/8+1 < longest/8 {
		minVarnameOpWidth = secondLongest
		outlier = longest
	}

	// Widths of the current indentation (including whitespace)
	minTotalWidth := 0
	maxTotalWidth := 0
	for _, info := range infos {
		if info.continuation {
			continue
		}

		if width := info.totalWidth; info.varnameOpWidth != outlier {
			if minTotalWidth == 0 || width < minTotalWidth {
				minTotalWidth = width
			}
			maxTotalWidth = imax(maxTotalWidth, width)
		}
	}

	if trace.Tracing {
		trace.Stepf("Indentation including whitespace is between %d and %d.",
			minTotalWidth, maxTotalWidth)
		trace.Stepf("Minimum required indentation is %d + 1.",
			minVarnameOpWidth)
		if outlier != 0 {
			trace.Stepf("The outlier is at indentation %d.", outlier)
		}
	}

	if minTotalWidth > minVarnameOpWidth && minTotalWidth == maxTotalWidth && minTotalWidth%8 == 0 {
		return minTotalWidth
	}

	if minVarnameOpWidth == 0 {
		// Only continuation lines in this paragraph.
		return 0
	}

	return (minVarnameOpWidth & -8) + 8
}

func (va *VaralignBlock) realign(mkline MkLine, varnameOp, oldSpace string, continuation bool, newWidth int) {
	hasSpace := contains(oldSpace, " ")

	newSpace := ""
	for tabWidth(varnameOp+newSpace) < newWidth {
		newSpace += "\t"
	}
	// Indent the outlier with a space instead of a tab to keep the line short.
	if newSpace == "" {
		if hasPrefix(oldSpace, "\t") {
			// Even though it is an outlier, it uses a tab and therefore
			// didn't seem to be too long to the original developer.
			// Therefore, leave it as-is but still fix any continuation lines.
			newSpace = oldSpace
		} else {
			newSpace = " "
		}
	}

	va.realignInitialLine(mkline, varnameOp, oldSpace, newSpace, hasSpace, newWidth)
	if mkline.IsMultiline() {
		va.realignContinuationLines(mkline, newWidth)
	}
}

func (va *VaralignBlock) realignInitialLine(mkline MkLine, varnameOp string, oldSpace string, newSpace string, hasSpace bool, newWidth int) {
	wrongColumn := tabWidth(varnameOp+oldSpace) != tabWidth(varnameOp+newSpace)

	fix := mkline.Autofix()

	switch {
	case hasSpace && wrongColumn:
		fix.Notef("This variable value should be aligned with tabs, not spaces, to column %d.", newWidth+1)
	case hasSpace && oldSpace != newSpace:
		fix.Notef("Variable values should be aligned with tabs, not spaces.")
	case wrongColumn:
		fix.Notef("This variable value should be aligned to column %d.", newWidth+1)
	default:
		return
	}

	if wrongColumn {
		fix.Explain(
			"Normally, all variable values in a block should start at the same",
			"column.  There are some exceptions to this rule:",
			"",
			"Definitions for long variable names may be indented with a single",
			"space instead of tabs, but only if they appear in a block that is",
			"otherwise indented using tabs.",
			"",
			"Variable definitions that span multiple lines are not checked for",
			"alignment at all.",
			"",
			"When the block contains something else than variable definitions",
			"and directives like .if or .for, it is not checked at all.")
	}

	fix.ReplaceAfter(varnameOp, oldSpace, newSpace)
	fix.Apply()
}

func (va *VaralignBlock) realignContinuationLines(mkline MkLine, newWidth int) {
	indentation := strings.Repeat("\t", newWidth/8) + strings.Repeat(" ", newWidth%8)
	fix := mkline.Autofix()
	fix.Notef("This line should be aligned with %q.", indentation)
	fix.Realign(mkline, newWidth)
	fix.Apply()
}
