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
	forVars        map[string]bool   // The variables currently used in .for loops
	target         string            // Current make(1) target
	vardef         map[string]MkLine // varname => line; for all variables that are defined in the current file
	varuse         map[string]MkLine // varname => line; for all variables that are used in the current file
	buildDefs      map[string]bool   // Variables that are registered in BUILD_DEFS, to ensure that all user-defined variables are added to it.
	plistVars      map[string]bool   // Variables that are registered in PLIST_VARS, to ensure that all user-defined variables are added to it.
	tools          map[string]bool   // Set of tools that are declared to be used.
	toolRegistry   ToolRegistry      // Tools defined in file scope.
	SeenBsdPrefsMk bool
	indentation    Indentation // Indentation depth of preprocessing directives
}

func NewMkLines(lines []Line) *MkLines {
	mklines := make([]MkLine, len(lines))
	for i, line := range lines {
		mklines[i] = NewMkLine(line)
	}
	tools := make(map[string]bool)
	for toolname, tool := range G.globalData.Tools.byName {
		if tool.Predefined {
			tools[toolname] = true
		}
	}

	return &MkLines{
		mklines,
		lines,
		make(map[string]bool),
		"",
		make(map[string]MkLine),
		make(map[string]MkLine),
		make(map[string]bool),
		make(map[string]bool),
		tools,
		NewToolRegistry(),
		false,
		Indentation{}}
}

func (mklines *MkLines) DefineVar(mkline MkLine, varname string) {
	if mklines.vardef[varname] == nil {
		mklines.vardef[varname] = mkline
	}
	varcanon := varnameCanon(varname)
	if mklines.vardef[varcanon] == nil {
		mklines.vardef[varcanon] = mkline
	}
}

func (mklines *MkLines) UseVar(mkline MkLine, varname string) {
	varcanon := varnameCanon(varname)
	mklines.varuse[varname] = mkline
	mklines.varuse[varcanon] = mkline
	if G.Pkg != nil {
		G.Pkg.varuse[varname] = mkline
		G.Pkg.varuse[varcanon] = mkline
	}
}

func (mklines *MkLines) VarValue(varname string) (value string, found bool) {
	if mkline := mklines.vardef[varname]; mkline != nil {
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

	// In the second pass, the actual checks are done.

	CheckLineRcsid(mklines.lines[0], `#\s+`, "# ")

	substcontext := NewSubstContext()
	var varalign VaralignBlock
	indentation := &mklines.indentation
	indentation.Push(0)
	for _, mkline := range mklines.mklines {
		ck := MkLineChecker{mkline}
		ck.Check()
		varalign.Check(mkline)

		switch {
		case mkline.IsEmpty():
			substcontext.Finish(mkline)

		case mkline.IsVarassign():
			mklines.target = ""
			substcontext.Varassign(mkline)

		case mkline.IsInclude():
			mklines.target = ""
			switch path.Base(mkline.Includefile()) {
			case "bsd.prefs.mk", "bsd.fast.prefs.mk", "bsd.builtin.mk":
				mklines.setSeenBsdPrefsMk()
			}
			if G.Pkg != nil {
				G.Pkg.CheckInclude(mkline, indentation)
			}

		case mkline.IsCond():
			ck.checkCond(mklines.forVars, indentation)
			substcontext.Conditional(mkline)

		case mkline.IsDependency():
			ck.checkDependencyRule(allowedTargets)
			mklines.target = mkline.Targets()
		}
	}
	lastMkline := mklines.mklines[len(mklines.mklines)-1]
	substcontext.Finish(lastMkline)
	varalign.Finish()

	ChecklinesTrailingEmptyLines(mklines.lines)

	if indentation.Len() != 1 && indentation.Depth() != 0 {
		lastMkline.Errorf("Directive indentation is not 0, but %d.", indentation.Depth())
	}

	SaveAutofixChanges(mklines.lines)
}

func (mklines *MkLines) DetermineDefinedVariables() {
	if trace.Tracing {
		defer trace.Call0()()
	}

	for _, mkline := range mklines.mklines {
		if !mkline.IsVarassign() {
			continue
		}

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
			for _, id := range splitOnSpace(mkline.Value()) {
				mklines.plistVars["PLIST."+id] = true
				if trace.Tracing {
					trace.Step1("PLIST.%s is added to PLIST_VARS.", id)
				}
				mklines.UseVar(mkline, "PLIST."+id)
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

		mklines.toolRegistry.ParseToolLine(mkline.Line)
	}
}

func (mklines *MkLines) DetermineUsedVariables() {
	for _, mkline := range mklines.mklines {
		varnames := mkline.DetermineUsedVariables()
		for _, varname := range varnames {
			mklines.UseVar(mkline, varname)
		}
	}
}

func (mklines *MkLines) setSeenBsdPrefsMk() {
	if !mklines.SeenBsdPrefsMk {
		mklines.SeenBsdPrefsMk = true
		if trace.Tracing {
			trace.Stepf("Mk.setSeenBsdPrefsMk")
		}
	}
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
	varnameOpWidth int    // Screen width of varnameOp + space
	space          string // Whitespace between varnameOp and the variable value
	totalWidth     int    // Screen width of varnameOp + space
	continuation   bool   // A continuation line with no value in the first line.
}

func (va *VaralignBlock) Check(mkline MkLine) {
	switch {
	case !G.opts.WarnSpace:
		return

	case mkline.IsComment():
		return

	case mkline.IsCond():
		return

	case mkline.IsEmpty():
		va.Finish()
		return

	case !mkline.IsVarassign():
		trace.Stepf("Skipping")
		va.skip = true
		return

	case mkline.Op() == opAssignEval && matches(mkline.Varname(), `^[a-z]`):
		// Arguments to procedures do not take part in block alignment.
		return

	case mkline.Value() == "" && mkline.VarassignComment() == "":
		// Multiple-inclusion guards usually appear in a block of
		// their own and therefore do not need alignment.
		return
	}

	continuation := false
	if mkline.IsMultiline() {
		// Interpreting the continuation marker as variable value
		// is cheating, but works well.
		m, _, _, _, _, value, _, _ := MatchVarassign(mkline.raw[0].orignl)
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
	longest := 0
	secondLongest := 0
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
			"and conditionals, it is not checked at all.")
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
