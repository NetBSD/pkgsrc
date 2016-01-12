package main

import (
	"path"
	"strings"
)

// MkLines contains data for the Makefile (or *.mk) that is currently checked.
type MkLines struct {
	mklines     []*MkLine
	lines       []*Line
	forVars     map[string]bool    // The variables currently used in .for loops
	indentation []int              // Indentation depth of preprocessing directives
	target      string             // Current make(1) target
	vardef      map[string]*MkLine // varname => line; for all variables that are defined in the current file
	varuse      map[string]*MkLine // varname => line; for all variables that are used in the current file
	buildDefs   map[string]bool    // Variables that are registered in BUILD_DEFS, to ensure that all user-defined variables are added to it.
	plistVars   map[string]bool    // Variables that are registered in PLIST_VARS, to ensure that all user-defined variables are added to it.
	tools       map[string]bool    // Set of tools that are declared to be used.
}

func NewMkLines(lines []*Line) *MkLines {
	mklines := make([]*MkLine, len(lines))
	for i, line := range lines {
		mklines[i] = NewMkLine(line)
	}
	tools := make(map[string]bool)
	for tool := range G.globalData.PredefinedTools {
		tools[tool] = true
	}

	return &MkLines{
		mklines,
		lines,
		make(map[string]bool),
		make([]int, 1),
		"",
		make(map[string]*MkLine),
		make(map[string]*MkLine),
		make(map[string]bool),
		make(map[string]bool),
		tools}
}

func (mklines *MkLines) IndentDepth() int {
	return mklines.indentation[len(mklines.indentation)-1]
}
func (mklines *MkLines) PopIndent() {
	mklines.indentation = mklines.indentation[:len(mklines.indentation)-1]
}
func (mklines *MkLines) PushIndent(indent int) {
	mklines.indentation = append(mklines.indentation, indent)
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
	if G.opts.DebugTrace {
		defer tracecall1(mklines.lines[0].Fname)()
	}

	allowedTargets := make(map[string]bool)
	substcontext := new(SubstContext)

	G.Mk = mklines
	defer func() { G.Mk = nil }()

	mklines.DetermineUsedVariables()

	prefixes := splitOnSpace("pre do post")
	actions := splitOnSpace("fetch extract patch tools wrapper configure build test install package clean")
	for _, prefix := range prefixes {
		for _, action := range actions {
			allowedTargets[prefix+"-"+action] = true
		}
	}

	// In the first pass, all additions to BUILD_DEFS and USE_TOOLS
	// are collected to make the order of the definitions irrelevant.
	mklines.determineDefinedVariables()

	// In the second pass, the actual checks are done.

	mklines.lines[0].CheckRcsid(`#\s+`, "# ")

	for _, mkline := range mklines.mklines {
		mkline.Line.CheckTrailingWhitespace()
		mkline.Line.CheckValidCharacters(`[\t -~]`)

		switch {
		case mkline.IsEmpty():
			substcontext.Finish(mkline)

		case mkline.IsVarassign():
			mklines.target = ""
			mkline.CheckVaralign()
			mkline.CheckVarassign()
			substcontext.Varassign(mkline)

		case mkline.IsShellcmd():
			shellcmd := mkline.Shellcmd()
			mkline.CheckText(shellcmd)
			NewShellLine(mkline).CheckShellCommandLine(shellcmd)

		case mkline.IsInclude():
			mklines.target = ""
			mklines.checklineInclude(mkline)

		case mkline.IsCond():
			mklines.checklineCond(mkline)

		case mkline.IsDependency():
			mklines.checklineDependencyRule(mkline, mkline.Targets(), mkline.Sources(), allowedTargets)
		}
	}
	lastMkline := mklines.mklines[len(mklines.mklines)-1]
	substcontext.Finish(lastMkline)

	ChecklinesTrailingEmptyLines(mklines.lines)

	if len(mklines.indentation) != 1 && mklines.IndentDepth() != 0 {
		lastMkline.Line.Errorf("Directive indentation is not 0, but %d.", mklines.IndentDepth())
	}

	SaveAutofixChanges(mklines.lines)
}

func (mklines *MkLines) determineDefinedVariables() {
	for _, mkline := range mklines.mklines {
		if !mkline.IsVarassign() {
			continue
		}

		varcanon := mkline.Varcanon()
		switch varcanon {
		case "BUILD_DEFS", "PKG_GROUPS_VARS", "PKG_USERS_VARS":
			for _, varname := range splitOnSpace(mkline.Value()) {
				mklines.buildDefs[varname] = true
				if G.opts.DebugMisc {
					mkline.Debug1("%q is added to BUILD_DEFS.", varname)
				}
			}

		case "PLIST_VARS":
			for _, id := range splitOnSpace(mkline.Value()) {
				mklines.plistVars["PLIST."+id] = true
				if G.opts.DebugMisc {
					mkline.Debug1("PLIST.%s is added to PLIST_VARS.", id)
				}
				mklines.UseVar(mkline, "PLIST."+id)
			}

		case "USE_TOOLS":
			for _, tool := range splitOnSpace(mkline.Value()) {
				tool = strings.Split(tool, ":")[0]
				mklines.tools[tool] = true
				if G.opts.DebugMisc {
					mkline.Debug1("%s is added to USE_TOOLS.", tool)
				}
			}

		case "SUBST_VARS.*":
			for _, svar := range splitOnSpace(mkline.Value()) {
				mklines.UseVar(mkline, varnameCanon(svar))
				if G.opts.DebugMisc {
					mkline.Debug1("varuse %s", svar)
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

func (mklines *MkLines) checklineCond(mkline *MkLine) {
	indent, directive, args := mkline.Indent(), mkline.Directive(), mkline.Args()

	switch directive {
	case "endif", "endfor", "elif", "else":
		if len(mklines.indentation) > 1 {
			mklines.PopIndent()
		} else {
			mkline.Error1("Unmatched .%s.", directive)
		}
	}

	// Check the indentation
	if expected := strings.Repeat(" ", mklines.IndentDepth()); indent != expected {
		if G.opts.WarnSpace && !mkline.Line.AutofixReplace("."+indent, "."+expected) {
			mkline.Line.Notef("This directive should be indented by %d spaces.", mklines.IndentDepth())
		}
	}

	if directive == "if" && matches(args, `^!defined\([\w]+_MK\)$`) {
		mklines.PushIndent(mklines.IndentDepth())

	} else if matches(directive, `^(?:if|ifdef|ifndef|for|elif|else)$`) {
		mklines.PushIndent(mklines.IndentDepth() + 2)
	}

	reDirectivesWithArgs := `^(?:if|ifdef|ifndef|elif|for|undef)$`
	if matches(directive, reDirectivesWithArgs) && args == "" {
		mkline.Error1("\".%s\" requires arguments.", directive)

	} else if !matches(directive, reDirectivesWithArgs) && args != "" {
		mkline.Error1("\".%s\" does not take arguments.", directive)

		if directive == "else" {
			mkline.Note0("If you meant \"else if\", use \".elif\".")
		}

	} else if directive == "if" || directive == "elif" {
		mkline.CheckIf()

	} else if directive == "ifdef" || directive == "ifndef" {
		if matches(args, `\s`) {
			mkline.Error1("The \".%s\" directive can only handle _one_ argument.", directive)
		} else {
			mkline.Line.Warnf("The \".%s\" directive is deprecated. Please use \".if %sdefined(%s)\" instead.",
				directive, ifelseStr(directive == "ifdef", "", "!"), args)
		}

	} else if directive == "for" {
		if m, vars, values := match2(args, `^(\S+(?:\s*\S+)*?)\s+in\s+(.*)$`); m {
			for _, forvar := range splitOnSpace(vars) {
				if !G.Infrastructure && hasPrefix(forvar, "_") {
					mkline.Warn1("Variable names starting with an underscore (%s) are reserved for internal pkgsrc use.", forvar)
				}

				if matches(forvar, `^[_a-z][_a-z0-9]*$`) {
					// Fine.
				} else if matches(forvar, `[A-Z]`) {
					mkline.Warn0(".for variable names should not contain uppercase letters.")
				} else {
					mkline.Error1("Invalid variable name %q.", forvar)
				}

				mklines.forVars[forvar] = true
			}

			// Check if any of the value's types is not guessed.
			guessed := true
			for _, value := range splitOnSpace(values) {
				if m, vname := match1(value, `^\$\{(.*)\}`); m {
					vartype := mkline.getVariableType(vname)
					if vartype != nil && !vartype.guessed {
						guessed = false
					}
				}
			}

			forLoopType := &Vartype{lkSpace, CheckvarUnchecked, []AclEntry{{"*", aclpAllRead}}, guessed}
			forLoopContext := &VarUseContext{forLoopType, vucTimeParse, vucQuotFor, vucExtentWord}
			for _, forLoopVar := range mkline.extractUsedVariables(values) {
				mkline.CheckVaruse(forLoopVar, "", forLoopContext)
			}
		}

	} else if directive == "undef" && args != "" {
		for _, uvar := range splitOnSpace(args) {
			if mklines.forVars[uvar] {
				mkline.Note0("Using \".undef\" after a \".for\" loop is unnecessary.")
			}
		}
	}
}

func (mklines *MkLines) checklineDependencyRule(mkline *MkLine, targets, dependencies string, allowedTargets map[string]bool) {
	if G.opts.DebugMisc {
		mkline.Debug2("targets=%q, dependencies=%q", targets, dependencies)
	}
	mklines.target = targets

	for _, source := range splitOnSpace(dependencies) {
		if source == ".PHONY" {
			for _, target := range splitOnSpace(targets) {
				allowedTargets[target] = true
			}
		}
	}

	for _, target := range splitOnSpace(targets) {
		if target == ".PHONY" {
			for _, dep := range splitOnSpace(dependencies) {
				allowedTargets[dep] = true
			}

		} else if target == ".ORDER" {
			// TODO: Check for spelling mistakes.

		} else if !allowedTargets[target] {
			mkline.Warn1("Unusual target %q.", target)
			Explain3(
				"If you want to define your own targets, you can \"declare\"",
				"them by inserting a \".PHONY: my-target\" line before this line.  This",
				"will tell make(1) to not interpret this target's name as a filename.")
		}
	}
}

func (mklines *MkLines) checklineInclude(mkline *MkLine) {
	includefile := mkline.Includefile()
	mustExist := mkline.MustExist()
	if G.opts.DebugInclude {
		mkline.Debug1("includefile=%s", includefile)
	}
	mkline.CheckRelativePath(includefile, mustExist)

	if hasSuffix(includefile, "/Makefile") {
		mkline.Line.Error0("Other Makefiles must not be included directly.")
		Explain4(
			"If you want to include portions of another Makefile, extract",
			"the common parts and put them into a Makefile.common.  After",
			"that, both this one and the other package should include the",
			"Makefile.common.")
	}

	if includefile == "../../mk/bsd.prefs.mk" {
		if path.Base(mkline.Line.Fname) == "buildlink3.mk" {
			mkline.Note0("For efficiency reasons, please include bsd.fast.prefs.mk instead of bsd.prefs.mk.")
		}
		if G.Pkg != nil {
			G.Pkg.SeenBsdPrefsMk = true
		}
	} else if includefile == "../../mk/bsd.fast.prefs.mk" {
		if G.Pkg != nil {
			G.Pkg.SeenBsdPrefsMk = true
		}
	}

	if matches(includefile, `/x11-links/buildlink3\.mk$`) {
		mkline.Error1("%s must not be included directly. Include \"../../mk/x11.buildlink3.mk\" instead.", includefile)
	}
	if matches(includefile, `/jpeg/buildlink3\.mk$`) {
		mkline.Error1("%s must not be included directly. Include \"../../mk/jpeg.buildlink3.mk\" instead.", includefile)
	}
	if matches(includefile, `/intltool/buildlink3\.mk$`) {
		mkline.Warn0("Please write \"USE_TOOLS+= intltool\" instead of this line.")
	}
	if m, dir := match1(includefile, `(.*)/builtin\.mk$`); m {
		mkline.Line.Error2("%s must not be included directly. Include \"%s/buildlink3.mk\" instead.", includefile, dir)
	}
}
