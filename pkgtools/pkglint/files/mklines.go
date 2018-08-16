package main

import (
	"netbsd.org/pkglint/trace"
	"path"
	"strings"
)

// MkLines contains data for the Makefile (or *.mk) that is currently checked.
type MkLines struct {
	mklines        []MkLine
	lines          []Line
	forVars        map[string]bool // The variables currently used in .for loops
	target         string          // Current make(1) target
	vars           Scope
	buildDefs      map[string]bool   // Variables that are registered in BUILD_DEFS, to ensure that all user-defined variables are added to it.
	plistVarAdded  map[string]MkLine // Identifiers that are added to PLIST_VARS.
	plistVarSet    map[string]MkLine // Identifiers for which PLIST.${id} is defined.
	plistVarSkip   bool              // True if any of the PLIST_VARS identifiers refers to a variable.
	tools          map[string]bool   // Set of tools that are declared to be used.
	toolRegistry   ToolRegistry      // Tools defined in file scope.
	SeenBsdPrefsMk bool
	indentation    *Indentation // Indentation depth of preprocessing directives; only available during MkLines.ForEach.
	Once
	// XXX: Why both tools and toolRegistry?
}

func NewMkLines(lines []Line) *MkLines {
	mklines := make([]MkLine, len(lines))
	for i, line := range lines {
		mklines[i] = NewMkLine(line)
	}
	tools := make(map[string]bool)
	G.Pkgsrc.Tools.ForEach(func(tool *Tool) {
		if tool.Predefined {
			tools[tool.Name] = true
		}
	})

	return &MkLines{
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
		NewToolRegistry(),
		false,
		nil,
		Once{}}
}

func (mklines *MkLines) UseVar(mkline MkLine, varname string) {
	mklines.vars.Use(varname, mkline)
	if G.Pkg != nil {
		G.Pkg.vars.Use(varname, mkline)
	}
}

func (mklines *MkLines) VarValue(varname string) (value string, found bool) {
	if mkline := mklines.vars.FirstDefinition(varname); mkline != nil {
		return mkline.Value(), true
	}
	return "", false
}

func (mklines *MkLines) Check() {
	if trace.Tracing {
		defer trace.Call1(mklines.lines[0].Filename)()
	}

	G.Mk = mklines
	defer func() { G.Mk = nil }()

	allowedTargets := make(map[string]bool)
	prefixes := [...]string{"pre", "do", "post"}
	actions := [...]string{"fetch", "extract", "patch", "tools", "wrapper", "configure", "build", "test", "install", "package", "clean"}
	for _, prefix := range prefixes {
		for _, action := range actions {
			allowedTargets[prefix+"-"+action] = true
		}
	}

	// In the first pass, all additions to BUILD_DEFS and USE_TOOLS
	// are collected to make the order of the definitions irrelevant.
	mklines.DetermineUsedVariables()
	mklines.DetermineDefinedVariables()
	mklines.collectPlistVars()
	mklines.collectElse()

	// In the second pass, the actual checks are done.

	CheckLineRcsid(mklines.lines[0], `#\s+`, "# ")

	substcontext := NewSubstContext()
	var varalign VaralignBlock
	lastMkline := mklines.mklines[len(mklines.mklines)-1]

	lineAction := func(mkline MkLine) bool {
		ck := MkLineChecker{mkline}
		ck.Check()
		varalign.Check(mkline)

		switch {
		case mkline.IsEmpty():
			substcontext.Finish(mkline)

		case mkline.IsVarassign():
			mklines.target = ""
			mkline.Tokenize(mkline.Value()) // Just for the side-effect of the warning.
			substcontext.Varassign(mkline)

			switch mkline.Varcanon() {
			case "PLIST_VARS":
				value := mkline.ValueSplit(resolveVariableRefs(mkline.Value()), "")
				for _, id := range value {
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
			switch path.Base(mkline.IncludeFile()) {
			case "bsd.prefs.mk", "bsd.fast.prefs.mk", "bsd.builtin.mk":
				mklines.setSeenBsdPrefsMk()
			}
			if G.Pkg != nil {
				G.Pkg.CheckInclude(mkline, mklines.indentation)
			}

		case mkline.IsDirective():
			ck.checkDirective(mklines.forVars, mklines.indentation)
			substcontext.Directive(mkline)

		case mkline.IsDependency():
			ck.checkDependencyRule(allowedTargets)
			mklines.target = mkline.Targets()

		case mkline.IsShellCommand():
			mkline.Tokenize(mkline.ShellCommand())
		}

		return true
	}

	atEnd := func(mkline MkLine) {
		ind := mklines.indentation
		if ind.Len() != 1 && ind.Depth("") != 0 {
			mkline.Errorf("Directive indentation is not 0, but %d.", ind.Depth(""))
		}
	}

	mklines.ForEach(lineAction, atEnd)

	substcontext.Finish(lastMkline)
	varalign.Finish()

	ChecklinesTrailingEmptyLines(mklines.lines)

	SaveAutofixChanges(mklines.lines)
}

// ForEach calls the action for each line, until the action returns false.
// It keeps track of the indentation and all conditional variables.
func (mklines *MkLines) ForEach(action func(mkline MkLine) bool, atEnd func(mkline MkLine)) {
	mklines.indentation = NewIndentation()

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

func (mklines *MkLines) DetermineDefinedVariables() {
	if trace.Tracing {
		defer trace.Call0()()
	}

	for _, mkline := range mklines.mklines {
		if !mkline.IsVarassign() {
			continue
		}

		defineVar(mkline, mkline.Varname())

		varcanon := mkline.Varcanon()
		switch varcanon {
		case "BUILD_DEFS", "PKG_GROUPS_VARS", "PKG_USERS_VARS":
			for _, varname := range splitOnSpace(mkline.Value()) {
				mklines.buildDefs[varname] = true
				if trace.Tracing {
					trace.Step1("%q is added to BUILD_DEFS.", varname)
				}
			}

		case "PLIST_VARS":
			value := mkline.ValueSplit(resolveVariableRefs(mkline.Value()), "")
			for _, id := range value {
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

		case "USE_TOOLS":
			tools := mkline.Value()
			if matches(tools, `\bautoconf213\b`) {
				tools += " autoconf autoheader-2.13 autom4te-2.13 autoreconf-2.13 autoscan-2.13 autoupdate-2.13 ifnames-2.13"
			}
			if matches(tools, `\bautoconf\b`) {
				tools += " autoheader autom4te autoreconf autoscan autoupdate ifnames"
			}
			for _, tool := range splitOnSpace(tools) {
				tool = strings.Split(tool, ":")[0]
				mklines.tools[tool] = true
				if trace.Tracing {
					trace.Step1("%s is added to USE_TOOLS.", tool)
				}
			}

		case "SUBST_VARS.*":
			for _, svar := range splitOnSpace(mkline.Value()) {
				mklines.UseVar(mkline, varnameCanon(svar))
				if trace.Tracing {
					trace.Step1("varuse %s", svar)
				}
			}

		case "OPSYSVARS":
			for _, osvar := range splitOnSpace(mkline.Value()) {
				mklines.UseVar(mkline, osvar+".*")
				defineVar(mkline, osvar)
			}
		}

		mklines.toolRegistry.ParseToolLine(mkline)
	}
}

func (mklines *MkLines) collectPlistVars() {
	for _, mkline := range mklines.mklines {
		if mkline.IsVarassign() {
			switch mkline.Varcanon() {
			case "PLIST_VARS":
				value := mkline.ValueSplit(resolveVariableRefs(mkline.Value()), "")
				for _, id := range value {
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

func (mklines *MkLines) collectElse() {
	// Make a dry-run over the lines, which sets data.elseLine (in mkline.go) as a side-effect.
	mklines.ForEach(
		func(mkline MkLine) bool { return true },
		func(mkline MkLine) {})
}

func (mklines *MkLines) DetermineUsedVariables() {
	for _, mkline := range mklines.mklines {
		varnames := mkline.DetermineUsedVariables()
		for _, varname := range varnames {
			mklines.UseVar(mkline, varname)
		}
	}
	mklines.determineDocumentedVariables()
}

// Loosely based on mk/help/help.awk, revision 1.28
func (mklines *MkLines) determineDocumentedVariables() {
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
		words := splitOnSpace(text)

		if 1 < len(words) && words[0] == "#" {
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
		}

		if text == "" {
			finish()
		}
	}

	finish()
}

func (mklines *MkLines) setSeenBsdPrefsMk() {
	if !mklines.SeenBsdPrefsMk {
		mklines.SeenBsdPrefsMk = true
		if trace.Tracing {
			trace.Stepf("Mk.setSeenBsdPrefsMk")
		}
	}
}

func (mklines *MkLines) CheckRedundantVariables() {
	scope := NewRedundantScope()
	isRelevant := func(old, new MkLine) bool {
		if path.Base(old.Filename) != "Makefile" && path.Base(new.Filename) == "Makefile" {
			return false
		}
		if new.Op() == opAssignEval {
			return false
		}
		return true
	}
	scope.OnIgnore = func(old, new MkLine) {
		if isRelevant(old, new) && old.Value() == new.Value() {
			old.Notef("Definition of %s is redundant because of %s.", new.Varname(), new.ReferenceFrom(old.Line))
		}
	}
	scope.OnOverwrite = func(old, new MkLine) {
		if isRelevant(old, new) {
			old.Warnf("Variable %s is overwritten in %s.", new.Varname(), new.ReferenceFrom(old.Line))
			Explain(
				"The variable definition in this line does not have an effect since",
				"it is overwritten elsewhere.  This typically happens because of a",
				"typo (writing = instead of +=) or because the line that overwrites",
				"is in another file that is used by several packages.")
		}
	}

	mklines.ForEach(
		func(mkline MkLine) bool {
			scope.Handle(mkline)
			return true
		},
		func(mkline MkLine) {})
}

func (mklines *MkLines) SaveAutofixChanges() {
	SaveAutofixChanges(mklines.lines)
}

// VaralignBlock checks that all variable assignments from a paragraph
// use the same indentation depth for their values.
// It also checks that the indentation uses tabs instead of spaces.
//
// In general, all values should be aligned using tabs.
// As an exception, very long lines may be aligned with a single space.
// A typical example is a SITES.very-long-filename.tar.gz variable
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
	case !G.opts.WarnSpace:
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
		// is cheating, but works well.
		m, _, _, _, _, _, value, _, _ := MatchVarassign(mkline.raw[0].orignl)
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
			// Therefore, leave it as-is, but still fix any continuation lines.
			newSpace = oldSpace
		} else {
			newSpace = " "
		}
	}

	fix := mkline.Autofix()
	wrongColumn := tabWidth(varnameOp+oldSpace) != tabWidth(varnameOp+newSpace)
	switch {
	case hasSpace && wrongColumn:
		fix.Notef("This variable value should be aligned with tabs, not spaces, to column %d.", newWidth+1)
	case hasSpace && oldSpace != newSpace:
		fix.Notef("Variable values should be aligned with tabs, not spaces.")
	case wrongColumn:
		fix.Notef("This variable value should be aligned to column %d.", newWidth+1)
	default:
		fix.Notef("Silent-Magic-Diagnostic")
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

	if mkline.IsMultiline() {
		indentation := strings.Repeat("\t", newWidth/8) + strings.Repeat(" ", newWidth%8)
		fix := mkline.Autofix()
		fix.Notef("This line should be aligned with %q.", indentation)
		fix.Realign(mkline, newWidth)
		fix.Apply()
	}
}
