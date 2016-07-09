package main

import (
	"path"
	"strings"
)

// MkLines contains data for the Makefile (or *.mk) that is currently checked.
type MkLines struct {
	mklines        []*MkLine
	lines          []*Line
	forVars        map[string]bool    // The variables currently used in .for loops
	target         string             // Current make(1) target
	vardef         map[string]*MkLine // varname => line; for all variables that are defined in the current file
	varuse         map[string]*MkLine // varname => line; for all variables that are used in the current file
	buildDefs      map[string]bool    // Variables that are registered in BUILD_DEFS, to ensure that all user-defined variables are added to it.
	plistVars      map[string]bool    // Variables that are registered in PLIST_VARS, to ensure that all user-defined variables are added to it.
	tools          map[string]bool    // Set of tools that are declared to be used.
	SeenBsdPrefsMk bool
	indentation    Indentation // Indentation depth of preprocessing directives
}

func NewMkLines(lines []*Line) *MkLines {
	mklines := make([]*MkLine, len(lines))
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
		make(map[string]*MkLine),
		make(map[string]*MkLine),
		make(map[string]bool),
		make(map[string]bool),
		tools,
		false,
		Indentation{}}
}

func (mklines *MkLines) DefineVar(mkline *MkLine, varname string) {
	if mklines.vardef[varname] == nil {
		mklines.vardef[varname] = mkline
	}
	varcanon := varnameCanon(varname)
	if mklines.vardef[varcanon] == nil {
		mklines.vardef[varcanon] = mkline
	}
}

func (mklines *MkLines) UseVar(mkline *MkLine, varname string) {
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
	if G.opts.Debug {
		defer tracecall1(mklines.lines[0].Fname)()
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
	mklines.determineDefinedVariables()

	// In the second pass, the actual checks are done.

	mklines.lines[0].CheckRcsid(`#\s+`, "# ")

	var substcontext SubstContext
	var varalign VaralignBlock
	indentation := &mklines.indentation
	indentation.Push(0)
	for _, mkline := range mklines.mklines {
		mkline.Check()
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

		case mkline.IsCond():
			mkline.checkCond(mklines.forVars)

		case mkline.IsDependency():
			mkline.checkDependencyRule(allowedTargets)
			mklines.target = mkline.Targets()
		}
	}
	lastMkline := mklines.mklines[len(mklines.mklines)-1]
	substcontext.Finish(lastMkline)
	varalign.Finish()

	ChecklinesTrailingEmptyLines(mklines.lines)

	if indentation.Len() != 1 && indentation.Depth() != 0 {
		lastMkline.Line.Errorf("Directive indentation is not 0, but %d.", indentation.Depth())
	}

	SaveAutofixChanges(mklines.lines)
}

func (mklines *MkLines) determineDefinedVariables() {
	if G.opts.Debug {
		defer tracecall0()()
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
				if G.opts.Debug {
					traceStep1("%q is added to BUILD_DEFS.", varname)
				}
			}

		case "PLIST_VARS":
			for _, id := range splitOnSpace(mkline.Value()) {
				mklines.plistVars["PLIST."+id] = true
				if G.opts.Debug {
					traceStep1("PLIST.%s is added to PLIST_VARS.", id)
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
				if G.opts.Debug {
					traceStep1("%s is added to USE_TOOLS.", tool)
				}
			}

		case "SUBST_VARS.*":
			for _, svar := range splitOnSpace(mkline.Value()) {
				mklines.UseVar(mkline, varnameCanon(svar))
				if G.opts.Debug {
					traceStep1("varuse %s", svar)
				}
			}

		case "OPSYSVARS":
			for _, osvar := range splitOnSpace(mkline.Value()) {
				mklines.UseVar(mkline, osvar+".*")
				defineVar(mkline, osvar)
			}
		}
	}
}

func (mklines *MkLines) DetermineUsedVariables() {
	for _, mkline := range mklines.mklines {
		varnames := mkline.determineUsedVariables()
		for _, varname := range varnames {
			mklines.UseVar(mkline, varname)
		}
	}
}

func (mklines *MkLines) setSeenBsdPrefsMk() {
	if !mklines.SeenBsdPrefsMk {
		mklines.SeenBsdPrefsMk = true
		if G.opts.Debug {
			traceStep("Mk.setSeenBsdPrefsMk")
		}
	}
}

type VaralignBlock struct {
	info []struct {
		mkline *MkLine
		prefix string
		align  string
	}
	skip           bool
	differ         bool
	maxPrefixWidth int
	maxSpaceWidth  int
	maxTabWidth    int
}

func (va *VaralignBlock) Check(mkline *MkLine) {
	if !G.opts.WarnSpace || mkline.Line.IsMultiline() || mkline.IsComment() || mkline.IsCond() {
		return
	}
	if mkline.IsEmpty() {
		va.Finish()
		return
	}
	if !mkline.IsVarassign() {
		va.skip = true
		return
	}

	valueAlign := mkline.ValueAlign()
	prefix := strings.TrimRight(valueAlign, " \t")
	align := valueAlign[len(prefix):]

	va.info = append(va.info, struct {
		mkline *MkLine
		prefix string
		align  string
	}{mkline, prefix, align})

	alignedWidth := tabLength(valueAlign)
	if contains(align, " ") {
		if va.maxSpaceWidth != 0 && alignedWidth != va.maxSpaceWidth {
			va.differ = true
		}
		if alignedWidth > va.maxSpaceWidth {
			va.maxSpaceWidth = alignedWidth
		}
	} else {
		if va.maxTabWidth != 0 && alignedWidth != va.maxTabWidth {
			va.differ = true
		}
		if alignedWidth > va.maxTabWidth {
			va.maxTabWidth = alignedWidth
		}
	}

	va.maxPrefixWidth = imax(va.maxPrefixWidth, tabLength(prefix))
}

func (va *VaralignBlock) Finish() {
	if !va.skip {
		for _, info := range va.info {
			if !info.mkline.Line.IsMultiline() {
				va.fixalign(info.mkline, info.prefix, info.align)
			}
		}
	}
	*va = VaralignBlock{}
}

func (va *VaralignBlock) fixalign(mkline *MkLine, prefix, oldalign string) {
	if mkline.Value() == "" && mkline.Comment() == "" {
		return
	}

	hasSpace := contains(oldalign, " ")
	if hasSpace &&
		va.maxTabWidth != 0 &&
		va.maxSpaceWidth > va.maxTabWidth &&
		tabLength(prefix+oldalign) == va.maxSpaceWidth {
		return
	}

	// Don’t warn about procedure parameters
	if mkline.Op() == opAssignEval && matches(mkline.Varname(), `^[a-z]`) {
		return
	}

	goodWidth := va.maxTabWidth
	if goodWidth == 0 && va.differ {
		goodWidth = va.maxSpaceWidth
	}
	minWidth := va.maxPrefixWidth + 1
	if goodWidth == 0 || minWidth < goodWidth && va.differ {
		goodWidth = minWidth
	}
	goodWidth = (goodWidth + 7) & -8

	newalign := ""
	for tabLength(prefix+newalign) < goodWidth {
		newalign += "\t"
	}
	if newalign == oldalign {
		return
	}

	if !mkline.Line.AutofixReplace(prefix+oldalign, prefix+newalign) {
		wrongColumn := tabLength(prefix+oldalign) != tabLength(prefix+newalign)
		switch {
		case hasSpace && wrongColumn:
			mkline.Line.Notef("This variable value should be aligned with tabs, not spaces, to column %d.", goodWidth+1)
		case hasSpace:
			mkline.Line.Notef("Variable values should be aligned with tabs, not spaces.")
		case wrongColumn:
			mkline.Line.Notef("This variable value should be aligned to column %d.", goodWidth+1)
		}
		if wrongColumn {
			Explain(
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
				"When the block contains something else than variable definitions,",
				"it is not checked at all.")
		}
	}
}
