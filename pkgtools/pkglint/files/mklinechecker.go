package main

import (
	"netbsd.org/pkglint/regex"
	"os"
	"path"
	"strconv"
	"strings"
)

type MkLineChecker struct {
	MkLine MkLine
}

func (ck MkLineChecker) Check() {
	mkline := ck.MkLine

	CheckLineTrailingWhitespace(mkline.Line)
	CheckLineValidCharacters(mkline.Line)

	switch {
	case mkline.IsVarassign():
		ck.checkVarassign()

	case mkline.IsShellCommand():
		shellCommand := mkline.ShellCommand()

		if G.Opts.WarnSpace && hasPrefix(mkline.Text, "\t\t") {
			fix := mkline.Autofix()
			fix.Notef("Shell programs should be indented with a single tab.")
			fix.Explain(
				"The first tab in the line marks the line as a shell command.  Since",
				"every line of shell commands starts with a completely new shell",
				"environment, there is no need to indent some of the commands, or to",
				"use more horizontal space than necessary.")
			fix.ReplaceRegex(`^\t\t+`, "\t", 1)
			fix.Apply()
		}

		ck.checkText(shellCommand)
		NewShellLine(mkline).CheckShellCommandLine(shellCommand)

	case mkline.IsComment():
		if hasPrefix(mkline.Text, "# url2pkg-marker") {
			mkline.Errorf("This comment indicates unfinished work (url2pkg).")
		}

	case mkline.IsInclude():
		ck.checkInclude()
	}
}

func (ck MkLineChecker) checkInclude() {
	if trace.Tracing {
		defer trace.Call0()()
	}

	mkline := ck.MkLine
	if mkline.Indent() != "" {
		ck.checkDirectiveIndentation(G.Mk.indentation.Depth("include"))
	}

	includefile := mkline.IncludeFile()
	mustExist := mkline.MustExist()
	if trace.Tracing {
		trace.Step2("includingFile=%s includefile=%s", mkline.FileName, includefile)
	}
	ck.CheckRelativePath(includefile, mustExist)

	switch {
	case hasSuffix(includefile, "/Makefile"):
		mkline.Errorf("Other Makefiles must not be included directly.")
		Explain(
			"If you want to include portions of another Makefile, extract",
			"the common parts and put them into a Makefile.common.  After",
			"that, both this one and the other package should include the",
			"Makefile.common.")

	case IsPrefs(includefile):
		if mkline.Basename == "buildlink3.mk" && includefile == "../../mk/bsd.prefs.mk" {
			mkline.Notef("For efficiency reasons, please include bsd.fast.prefs.mk instead of bsd.prefs.mk.")
		}

	case hasSuffix(includefile, "/x11-links/buildlink3.mk"):
		mkline.Errorf("%s must not be included directly. Include \"../../mk/x11.buildlink3.mk\" instead.", includefile)

	case hasSuffix(includefile, "/jpeg/buildlink3.mk"):
		mkline.Errorf("%s must not be included directly. Include \"../../mk/jpeg.buildlink3.mk\" instead.", includefile)

	case hasSuffix(includefile, "/intltool/buildlink3.mk"):
		mkline.Warnf("Please write \"USE_TOOLS+= intltool\" instead of this line.")

	case hasSuffix(includefile, "/builtin.mk"):
		mkline.Errorf("%s must not be included directly. Include \"%s/buildlink3.mk\" instead.", includefile, path.Dir(includefile))
	}
}

func (ck MkLineChecker) checkDirective(forVars map[string]bool, ind *Indentation) {
	mkline := ck.MkLine

	directive := mkline.Directive()
	args := mkline.Args()

	expectedDepth := ind.Depth(directive)
	ck.checkDirectiveIndentation(expectedDepth)

	if directive == "endfor" || directive == "endif" {
		ck.checkDirectiveEnd(ind)
	}

	needsArgument := false
	switch directive {
	case
		"if", "ifdef", "ifndef", "elif",
		"for", "undef",
		"error", "warning", "info",
		"export", "export-env", "unexport", "unexport-env":
		needsArgument = true
	}

	if needsArgument && args == "" {
		mkline.Errorf("\".%s\" requires arguments.", directive)

	} else if !needsArgument && args != "" {
		if directive == "else" {
			mkline.Errorf("\".%s\" does not take arguments. If you meant \"else if\", use \".elif\".", directive)
		} else {
			mkline.Errorf("\".%s\" does not take arguments.", directive)
		}

	} else if directive == "if" || directive == "elif" {
		ck.checkDirectiveCond()

	} else if directive == "ifdef" || directive == "ifndef" {
		mkline.Warnf("The \".%s\" directive is deprecated. Please use \".if %sdefined(%s)\" instead.",
			directive, ifelseStr(directive == "ifdef", "", "!"), args)

	} else if directive == "for" {
		ck.checkDirectiveFor(forVars, ind)

	} else if directive == "undef" {
		for _, varname := range fields(args) {
			if forVars[varname] {
				mkline.Notef("Using \".undef\" after a \".for\" loop is unnecessary.")
			}
		}
	}
}

func (ck MkLineChecker) checkDirectiveEnd(ind *Indentation) {
	mkline := ck.MkLine
	directive := mkline.Directive()
	comment := mkline.DirectiveComment()

	if directive == "endif" && comment != "" {
		if condition := ind.Condition(); !contains(condition, comment) {
			mkline.Warnf("Comment %q does not match condition %q.", comment, condition)
		}
	}
	if directive == "endfor" && comment != "" {
		if condition := ind.Condition(); !contains(condition, comment) {
			mkline.Warnf("Comment %q does not match loop %q.", comment, condition)
		}
	}
	if ind.Len() <= 1 {
		mkline.Errorf("Unmatched .%s.", directive)
	}
}

func (ck MkLineChecker) checkDirectiveFor(forVars map[string]bool, indentation *Indentation) {
	mkline := ck.MkLine
	args := mkline.Args()

	if m, vars, values := match2(args, `^([^\t ]+(?:[\t ]*[^\t ]+)*?)[\t ]+in[\t ]+(.*)$`); m {
		for _, forvar := range fields(vars) {
			indentation.AddVar(forvar)
			if !G.Infrastructure && hasPrefix(forvar, "_") {
				mkline.Warnf("Variable names starting with an underscore (%s) are reserved for internal pkgsrc use.", forvar)
			}

			if matches(forvar, `^[_a-z][_a-z0-9]*$`) {
				// Fine.
			} else if matches(forvar, `[A-Z]`) {
				mkline.Warnf(".for variable names should not contain uppercase letters.")
			} else {
				mkline.Errorf("Invalid variable name %q.", forvar)
			}

			forVars[forvar] = true
		}

		// Check if any of the value's types is not guessed.
		guessed := true
		for _, value := range fields(values) {
			if m, vname := match1(value, `^\$\{(.*)\}`); m {
				vartype := G.Pkgsrc.VariableType(vname)
				if vartype != nil && !vartype.guessed {
					guessed = false
				}
			}
		}

		forLoopType := &Vartype{lkSpace, BtUnknown, []ACLEntry{{"*", aclpAllRead}}, guessed}
		forLoopContext := &VarUseContext{forLoopType, vucTimeParse, vucQuotFor, false}
		for _, forLoopVar := range mkline.DetermineUsedVariables() {
			ck.CheckVaruse(&MkVarUse{forLoopVar, nil}, forLoopContext)
		}
	}
}

func (ck MkLineChecker) checkDirectiveIndentation(expectedDepth int) {
	if G.Mk == nil || !G.Opts.WarnSpace {
		return
	}
	mkline := ck.MkLine
	indent := mkline.Indent()
	if expected := strings.Repeat(" ", expectedDepth); indent != expected {
		fix := mkline.Line.Autofix()
		fix.Notef("This directive should be indented by %d spaces.", expectedDepth)
		fix.ReplaceRegex(regex.Pattern(`^\.`+indent), "."+expected, 1)
		fix.Apply()
	}
}

func (ck MkLineChecker) checkDependencyRule(allowedTargets map[string]bool) {
	mkline := ck.MkLine
	targets := fields(mkline.Targets())
	sources := fields(mkline.Sources())

	for _, source := range sources {
		if source == ".PHONY" {
			for _, target := range targets {
				allowedTargets[target] = true
			}
		}
	}

	for _, target := range targets {
		if target == ".PHONY" {
			for _, dep := range sources {
				allowedTargets[dep] = true
			}

		} else if target == ".ORDER" {
			// TODO: Check for spelling mistakes.

		} else if hasPrefix(target, "${.CURDIR}/") {
			// OK, this is intentional

		} else if !allowedTargets[target] {
			mkline.Warnf("Unusual target %q.", target)
			Explain(
				"If you want to define your own target, declare it like this:",
				"",
				"\t.PHONY: my-target",
				"",
				"In the rare case that you actually want a file-based make(1)",
				"target, write it like this:",
				"",
				"\t${.CURDIR}/my-file:")
		}
	}
}

// checkVarassignPermissions checks the permissions for the left-hand side
// of a variable assignment line.
//
// See checkVarusePermissions.
func (ck MkLineChecker) checkVarassignPermissions() {
	if !G.Opts.WarnPerm || G.Infrastructure {
		return
	}
	if trace.Tracing {
		defer trace.Call()()
	}

	mkline := ck.MkLine
	varname := mkline.Varname()
	op := mkline.Op()
	vartype := G.Pkgsrc.VariableType(varname)
	if vartype == nil {
		if trace.Tracing {
			trace.Step1("No type definition found for %q.", varname)
		}
		return
	}

	perms := vartype.EffectivePermissions(mkline.Basename)

	// E.g. USE_TOOLS:= ${USE_TOOLS:Nunwanted-tool}
	if op == opAssignEval && perms&aclpAppend != 0 {
		tokens := mkline.ValueTokens()
		if len(tokens) == 1 && tokens[0].Varuse != nil && tokens[0].Varuse.varname == varname {
			return
		}
	}

	var needed ACLPermissions
	switch op {
	case opAssign, opAssignShell, opAssignEval:
		needed = aclpSet
	case opAssignDefault:
		needed = aclpSetDefault
	case opAssignAppend:
		needed = aclpAppend
	}

	switch {
	case perms.Contains(needed):
		break
	case perms == aclpUnknown:
		if trace.Tracing {
			trace.Step1("Unknown permissions for %q.", varname)
		}
	default:
		alternativeActions := perms & aclpAllWrite
		alternativeFiles := vartype.AllowedFiles(needed)
		switch {
		case alternativeActions != 0 && alternativeFiles != "":
			mkline.Warnf("The variable %s may not be %s (only %s) in this file; it would be ok in %s.",
				varname, needed.HumanString(), alternativeActions.HumanString(), alternativeFiles)
		case alternativeFiles != "":
			mkline.Warnf("The variable %s may not be %s in this file; it would be ok in %s.",
				varname, needed.HumanString(), alternativeFiles)
		case alternativeActions != 0:
			mkline.Warnf("The variable %s may not be %s (only %s) in this file.",
				varname, needed.HumanString(), alternativeActions.HumanString())
		default:
			mkline.Warnf("The variable %s may not be %s by any package.",
				varname, needed.HumanString())
		}
		Explain(
			"The allowed actions for a variable are determined based on the file",
			"name in which the variable is used or defined.  The exact rules are",
			"hard-coded into pkglint.  If they seem to be incorrect, please ask",
			"on the tech-pkg@NetBSD.org mailing list.")
	}
}

func (ck MkLineChecker) CheckVaruse(varuse *MkVarUse, vuc *VarUseContext) {
	mkline := ck.MkLine
	if trace.Tracing {
		defer trace.Call(mkline, varuse, vuc)()
	}

	if varuse.IsExpression() {
		return
	}

	varname := varuse.varname
	vartype := G.Pkgsrc.VariableType(varname)
	switch {
	case !G.Opts.WarnExtra:
	case vartype != nil && !vartype.guessed:
		// Well-known variables are probably defined by the infrastructure.
	case varIsDefinedSimilar(varname):
	case containsVarRef(varname):
	case G.Pkgsrc.vartypes[varname] != nil:
	case G.Pkgsrc.vartypes[varnameCanon(varname)] != nil:
	case G.Mk != nil && !G.Mk.FirstTime("used but not defined: "+varname):

	default:
		mkline.Warnf("%s is used but not defined.", varname)
	}

	ck.checkVaruseMod(varuse, vartype)

	if varuse.varname == "@" {
		ck.MkLine.Warnf("Please use %q instead of %q.", "${.TARGET}", "$@")
		Explain(
			"It is more readable and prevents confusion with the shell variable",
			"of the same name.")
	}

	ck.checkVarusePermissions(varname, vartype, vuc)

	if varname == "LOCALBASE" && !G.Infrastructure {
		ck.MkLine.Warnf("Please use PREFIX instead of LOCALBASE.")
	}

	needsQuoting := mkline.VariableNeedsQuoting(varname, vartype, vuc)

	if G.Opts.WarnQuoting && vuc.quoting != vucQuotUnknown && needsQuoting != nqDontKnow {
		ck.CheckVaruseShellword(varname, vartype, vuc, varuse.Mod(), needsQuoting)
	}

	if G.Pkgsrc.UserDefinedVars.Defined(varname) && !G.Pkgsrc.IsBuildDef(varname) && !G.Mk.buildDefs[varname] {
		mkline.Warnf("The user-defined variable %s is used but not added to BUILD_DEFS.", varname)
		Explain(
			"When a pkgsrc package is built, many things can be configured by the",
			"pkgsrc user in the mk.conf file.  All these configurations should be",
			"recorded in the binary package, so the package can be reliably",
			"rebuilt.  The BUILD_DEFS variable contains a list of all these",
			"user-settable variables, so please add your variable to it, too.")
	}
}

func (ck MkLineChecker) checkVaruseMod(varuse *MkVarUse, vartype *Vartype) {
	mods := varuse.modifiers
	if len(mods) == 0 {
		return
	}

	if mods[0].IsSuffixSubst() && vartype != nil && !vartype.IsConsideredList() {
		ck.MkLine.Warnf("The :from=to modifier should only be used with lists, not with %s.", varuse.varname)
		Explain(
			"Instead of:",
			"\tMASTER_SITES=\t${HOMEPAGE:=repository/}",
			"",
			"Write:",
			"\tMASTER_SITES=\t${HOMEPAGE}repository/",
			"",
			"This is a much clearer expression of the same thought.")
	}

	if len(mods) == 3 {
		if m, _, from, to, options := mods[0].MatchSubst(); m && from == "^" && matches(to, `^\w+$`) && options == "1" {
			magic := to
			if m, positive, pattern := mods[1].MatchMatch(); m && positive && pattern == magic+"*" {
				if m, _, from, to, options = mods[2].MatchSubst(); m && from == "^"+magic && to == "" && options == "" {
					fix := ck.MkLine.Autofix()
					fix.Notef("The modifier %q can be written as %q.", varuse.Mod(), ":[1]")
					fix.Explain(
						"The range modifier is much easier to understand than the",
						"complicated regular expressions, which were needed before",
						"the year 2006.")
					fix.Replace(varuse.Mod(), ":[1]")
					fix.Apply()
				}
			}
		}
	}
}

// checkVarusePermissions checks the permissions for the right-hand side
// of a variable assignment line.
//
// See checkVarassignPermissions.
func (ck MkLineChecker) checkVarusePermissions(varname string, vartype *Vartype, vuc *VarUseContext) {
	if !G.Opts.WarnPerm {
		return
	}
	if trace.Tracing {
		defer trace.Call(varname, vuc)()
	}

	// This is the type of the variable that is being used. Not to
	// be confused with vuc.vartype, which is the type of the
	// context in which the variable is used (often a ShellCommand
	// or, in an assignment, the type of the left hand side variable).
	if vartype == nil {
		if trace.Tracing {
			trace.Step1("No type definition found for %q.", varname)
		}
		return
	}

	mkline := ck.MkLine
	perms := vartype.EffectivePermissions(mkline.Basename)

	// Is the variable used at load time although that is not allowed?
	directly := false
	indirectly := false
	if !perms.Contains(aclpUseLoadtime) { // May not be used at load time.
		if vuc.time == vucTimeParse {
			directly = true
		} else if vuc.vartype != nil && vuc.vartype.Union().Contains(aclpUseLoadtime) {
			indirectly = true
		}
	}

	if (directly || indirectly) && !vartype.guessed {
		if tool := G.ToolByVarname(varname, LoadTime); tool != nil {
			if !tool.UsableAtLoadTime(G.Mk.Tools.SeenPrefs) {
				ck.warnVaruseToolLoadTime(varname, tool)
			}

		} else {
			// Might the variable be used indirectly at load time, for example
			// by assigning it to another variable which then gets evaluated?
			isIndirect := vuc.time != vucTimeParse && // Otherwise it would be directly.
				// The context might be used at load time somewhere.
				vuc.vartype != nil && vuc.vartype.Union().Contains(aclpUseLoadtime)

			ck.warnVaruseLoadTime(varname, isIndirect)
		}
	}

	if !perms.Contains(aclpUseLoadtime) && !perms.Contains(aclpUse) {
		needed := aclpUse
		if directly || indirectly {
			needed = aclpUseLoadtime
		}
		alternativeFiles := vartype.AllowedFiles(needed)
		if alternativeFiles != "" {
			mkline.Warnf("%s may not be used in this file; it would be ok in %s.",
				varname, alternativeFiles)
		} else {
			mkline.Warnf("%s may not be used in any file; it is a write-only variable.", varname)
		}
		Explain(
			"The allowed actions for a variable are determined based on the file",
			"name in which the variable is used or defined.  The exact rules are",
			"hard-coded into pkglint.  If they seem to be incorrect, please ask",
			"on the tech-pkg@NetBSD.org mailing list.")
	}
}

// warnVaruseToolLoadTime logs a warning that the tool ${varname}
// may not be used at load time.
func (ck MkLineChecker) warnVaruseToolLoadTime(varname string, tool *Tool) {
	if tool.Validity == AfterPrefsMk {
		ck.MkLine.Warnf("To use the tool ${%s} at load time, bsd.prefs.mk has to be included before.", varname)
		return
	}

	if ck.MkLine.Basename == "Makefile" {
		pkgsrcTool := G.Pkgsrc.Tools.ByName(tool.Name)
		if pkgsrcTool != nil && pkgsrcTool.Validity == Nowhere {
			// The tool must have been added too late to USE_TOOLS,
			// i.e. after bsd.prefs.mk has been included.
			ck.MkLine.Warnf("To use the tool ${%s} at load time, it has to be added to USE_TOOLS before including bsd.prefs.mk.", varname)
			return
		}
	}

	ck.MkLine.Warnf("The tool ${%s} cannot be used at load time.", varname)
	Explain(
		"To use a tool at load time, it must be declared in the package",
		"Makefile by adding it to USE_TOOLS.  After that, bsd.prefs.mk must",
		"be included.  Adding the tool to USE_TOOLS at any later time has",
		"no effect, which means that the tool can only be used at run time.",
		"That's the rule for the package Makefiles.",
		"",
		"Since any other .mk file can be included from anywhere else, there",
		"is no guarantee that the tool is properly defined for using it at",
		"load time (see above for the tricky rules).  Therefore the tools can",
		"only be used at run time, except in the package Makefile itself.")
}

func (ck MkLineChecker) warnVaruseLoadTime(varname string, isIndirect bool) {
	mkline := ck.MkLine

	if !isIndirect {
		mkline.Warnf("%s should not be evaluated at load time.", varname)
		Explain(
			"Many variables, especially lists of something, get their values",
			"incrementally.  Therefore it is generally unsafe to rely on their",
			"value until it is clear that it will never change again.  This",
			"point is reached when the whole package Makefile is loaded and",
			"execution of the shell commands starts; in some cases earlier.",
			"",
			"Additionally, when using the \":=\" operator, each $$ is replaced",
			"with a single $, so variables that have references to shell",
			"variables or regular expressions are modified in a subtle way.")
		return
	}

	mkline.Warnf("%s should not be evaluated indirectly at load time.", varname)
	Explain(
		"The variable on the left-hand side may be evaluated at load time,",
		"but the variable on the right-hand side may not.  Because of the",
		"assignment in this line, the variable might be used indirectly",
		"at load time, before it is guaranteed to be properly initialized.")
}

// CheckVaruseShellword checks whether a variable use of the form ${VAR}
// or ${VAR:Modifier} is allowed in a certain context.
func (ck MkLineChecker) CheckVaruseShellword(varname string, vartype *Vartype, vuc *VarUseContext, mod string, needsQuoting NeedsQuoting) {
	if trace.Tracing {
		defer trace.Call(varname, vartype, vuc, mod, needsQuoting)()
	}

	// In GNU configure scripts, a few variables need to be
	// passed through the :M* operator before they reach the
	// configure scripts.
	//
	// When doing checks outside a package, the :M* operator is needed for safety.
	needMstar := matches(varname, `^(?:.*_)?(?:CFLAGS|CPPFLAGS|CXXFLAGS|FFLAGS|LDFLAGS|LIBS)$`) &&
		(G.Pkg == nil || G.Pkg.vars.Defined("GNU_CONFIGURE"))

	strippedMod := mod
	if m, stripped := match1(mod, `(.*?)(?::M\*)?(?::Q)?$`); m {
		strippedMod = stripped
	}

	mkline := ck.MkLine
	if mod == ":M*:Q" && !needMstar {
		mkline.Notef("The :M* modifier is not needed here.")

	} else if needsQuoting == nqYes {
		correctMod := strippedMod + ifelseStr(needMstar, ":M*:Q", ":Q")
		if correctMod == mod+":Q" && vuc.IsWordPart && !vartype.IsShell() {
			if vartype.IsConsideredList() {
				mkline.Warnf("The list variable %s should not be embedded in a word.", varname)
				Explain(
					"When a list variable has multiple elements, this expression expands",
					"to something unexpected:",
					"",
					"Example: ${MASTER_SITE_SOURCEFORGE}directory/ expands to",
					"",
					"\thttps://mirror1.sf.net/ https://mirror2.sf.net/directory/",
					"",
					"The first URL is missing the directory.  To fix this, write",
					"\t${MASTER_SITE_SOURCEFORGE:=directory/}.",
					"",
					"Example: -l${LIBS} expands to",
					"",
					"\t-llib1 lib2",
					"",
					"The second library is missing the -l.  To fix this, write",
					"${LIBS:@lib@-l${lib}@}.")
			} else {
				mkline.Warnf("The variable %s should be quoted as part of a shell word.", varname)
				Explain(
					"This variable can contain spaces or other special characters.",
					"Therefore it should be quoted by replacing ${VAR} with ${VAR:Q}.")
			}

		} else if mod != correctMod {
			if vuc.quoting == vucQuotPlain {
				fix := mkline.Line.Autofix()
				fix.Warnf("Please use ${%s%s} instead of ${%s%s}.", varname, correctMod, varname, mod)
				fix.Replace("${"+varname+mod+"}", "${"+varname+correctMod+"}")
				fix.Apply()
			} else {
				mkline.Warnf("Please use ${%s%s} instead of ${%s%s} and make sure"+
					" the variable appears outside of any quoting characters.", varname, correctMod, varname, mod)
			}
			Explain(
				"See the pkgsrc guide, section \"quoting guideline\", for details.")

		} else if vuc.quoting != vucQuotPlain {
			mkline.Warnf("Please move ${%s%s} outside of any quoting characters.", varname, mod)
			Explain(
				"The :Q modifier only works reliably when it is used outside of any",
				"quoting characters.",
				"",
				"Examples:",
				"Instead of CFLAGS=\"${CFLAGS:Q}\",",
				"     write CFLAGS=${CFLAGS:Q}.",
				"Instead of 's,@CFLAGS@,${CFLAGS:Q},',",
				"     write 's,@CFLAGS@,'${CFLAGS:Q}','.")
		}
	}

	if hasSuffix(mod, ":Q") && (needsQuoting == nqNo || needsQuoting == nqDoesntMatter) {
		bad := "${" + varname + mod + "}"
		good := "${" + varname + strings.TrimSuffix(mod, ":Q") + "}"

		fix := mkline.Line.Autofix()
		if needsQuoting == nqNo {
			fix.Warnf("The :Q operator should not be used for ${%s} here.", varname)
		} else {
			fix.Notef("The :Q operator isn't necessary for ${%s} here.", varname)
		}
		fix.Explain(
			"Many variables in pkgsrc do not need the :Q operator, since they",
			"are not expected to contain white-space or other special characters.",
			"Examples for these \"safe\" variables are:",
			"",
			"\t* filenames",
			"\t* directory names",
			"\t* user and group names",
			"\t* tool names and tool paths",
			"\t* variable names",
			"\t* PKGNAME")
		fix.Replace(bad, good)
		fix.Apply()
	}
}

func (ck MkLineChecker) checkVarassignPythonVersions(varname, value string) {
	if trace.Tracing {
		defer trace.Call2(varname, value)()
	}

	mkline := ck.MkLine
	strversions := fields(value)
	intversions := make([]int, len(strversions))
	for i, strversion := range strversions {
		iver, err := strconv.Atoi(strversion)
		if err != nil || !(iver > 0) {
			mkline.Errorf("All values for %s must be positive integers.", varname)
			return
		}
		intversions[i] = iver
	}

	for i, ver := range intversions {
		if i > 0 && ver >= intversions[i-1] {
			mkline.Warnf("The values for %s should be in decreasing order.", varname)
			Explain(
				"If they aren't, it may be possible that needless versions of",
				"packages are installed.")
		}
	}
}

func (ck MkLineChecker) checkVarassign() {
	mkline := ck.MkLine
	varname := mkline.Varname()
	op := mkline.Op()
	value := mkline.Value()
	comment := mkline.VarassignComment()
	varcanon := varnameCanon(varname)

	if trace.Tracing {
		defer trace.Call(varname, op, value)()
	}

	defineVar(mkline, varname)
	ck.checkVarassignPermissions()
	ck.checkVarassignBsdPrefs()

	ck.checkText(value)
	ck.CheckVartype(varname, op, value, comment)

	// If the variable is not used and is untyped, it may be a spelling mistake.
	if op == opAssignEval && varname == strings.ToLower(varname) {
		if trace.Tracing {
			trace.Step1("%s might be unused unless it is an argument to a procedure file.", varname)
		}

	} else if !varIsUsedSimilar(varname) {
		if vartypes := G.Pkgsrc.vartypes; vartypes[varname] != nil || vartypes[varcanon] != nil {
			// Ok
		} else if deprecated := G.Pkgsrc.Deprecated; deprecated[varname] != "" || deprecated[varcanon] != "" {
			// Ok
		} else if G.Mk != nil && !G.Mk.FirstTime("defined but not used: "+varname) {
			// Skip
		} else {
			mkline.Warnf("%s is defined but not used.", varname)
		}
	}

	ck.checkVarassignSpecific()

	if fix := G.Pkgsrc.Deprecated[varname]; fix != "" {
		mkline.Warnf("Definition of %s is deprecated. %s", varname, fix)
	} else if fix = G.Pkgsrc.Deprecated[varcanon]; fix != "" {
		mkline.Warnf("Definition of %s is deprecated. %s", varname, fix)
	}

	ck.checkVarassignVaruse()
}

func (ck MkLineChecker) checkVarassignVaruse() {
	if trace.Tracing {
		defer trace.Call()()
	}

	mkline := ck.MkLine
	op := mkline.Op()

	time := vucTimeRun
	if op == opAssignEval || op == opAssignShell {
		time = vucTimeParse
	}

	vartype := G.Pkgsrc.VariableType(mkline.Varname())
	if op == opAssignShell {
		vartype = shellcommandsContextType
	}

	if vartype != nil && vartype.IsShell() {
		ck.checkVarassignVaruseShell(vartype, time)
	} else {
		ck.checkVarassignVaruseMk(vartype, time)
	}
}

func (ck MkLineChecker) checkVarassignVaruseMk(vartype *Vartype, time vucTime) {
	if trace.Tracing {
		defer trace.Call(vartype, time)()
	}
	mkline := ck.MkLine
	tokens := NewMkParser(mkline.Line, mkline.Value(), false).MkTokens()
	for i, token := range tokens {
		if token.Varuse != nil {
			spaceLeft := i-1 < 0 || matches(tokens[i-1].Text, `[\t ]$`)
			spaceRight := i+1 >= len(tokens) || matches(tokens[i+1].Text, `^[\t ]`)
			isWordPart := !(spaceLeft && spaceRight)
			vuc := &VarUseContext{vartype, time, vucQuotPlain, isWordPart}
			ck.CheckVaruse(token.Varuse, vuc)
		}
	}
}

func (ck MkLineChecker) checkVarassignVaruseShell(vartype *Vartype, time vucTime) {
	if trace.Tracing {
		defer trace.Call(vartype, time)()
	}

	isWordPart := func(tokens []*ShAtom, i int) bool {
		if i-1 >= 0 && tokens[i-1].Type.IsWord() {
			return true
		}
		if i+1 < len(tokens) && tokens[i+1].Type.IsWord() {
			return true
		}
		return false
	}

	mkline := ck.MkLine
	atoms := NewShTokenizer(mkline.Line, mkline.Value(), false).ShAtoms()
	for i, atom := range atoms {
		if varuse := atom.VarUse(); varuse != nil {
			isWordPart := isWordPart(atoms, i)
			vuc := &VarUseContext{vartype, time, atom.Quoting.ToVarUseContext(), isWordPart}
			ck.CheckVaruse(varuse, vuc)
		}
	}
}

func (ck MkLineChecker) checkVarassignSpecific() {
	mkline := ck.MkLine
	varname := mkline.Varname()
	value := mkline.Value()

	if contains(value, "/etc/rc.d") {
		mkline.Warnf("Please use the RCD_SCRIPTS mechanism to install rc.d scripts automatically to ${RCD_SCRIPTS_EXAMPLEDIR}.")
	}

	if hasPrefix(varname, "_") && !G.Infrastructure {
		mkline.Warnf("Variable names starting with an underscore (%s) are reserved for internal pkgsrc use.", varname)
	}

	if varname == "PYTHON_VERSIONS_ACCEPTED" {
		ck.checkVarassignPythonVersions(varname, value)
	}

	if mkline.VarassignComment() == "# defined" && !hasSuffix(varname, "_MK") && !hasSuffix(varname, "_COMMON") {
		mkline.Notef("Please use \"# empty\", \"# none\" or \"yes\" instead of \"# defined\".")
		Explain(
			"The value #defined says something about the state of the variable,",
			"but not what that _means_.  In some cases a variable that is defined",
			"means \"yes\", in other cases it is an empty list (which is also",
			"only the state of the variable), whose meaning could be described",
			"with \"none\".  It is this meaning that should be described.")
	}

	if m, revvarname := match1(value, `\$\{(PKGNAME|PKGVERSION)[:\}]`); m {
		if varname == "DIST_SUBDIR" || varname == "WRKSRC" {
			mkline.Warnf("%s should not be used in %s, as it includes the PKGREVISION. Please use %s_NOREV instead.", revvarname, varname, revvarname)
		}
	}

	if hasPrefix(varname, "SITES_") {
		mkline.Warnf("SITES_* is deprecated. Please use SITES.* instead.")
	}

	if varname == "PKG_SKIP_REASON" && G.Mk.indentation.DependsOn("OPSYS") {
		mkline.Notef("Consider defining NOT_FOR_PLATFORM instead of setting PKG_SKIP_REASON depending on ${OPSYS}.")
	}
}

func (ck MkLineChecker) checkVarassignBsdPrefs() {
	mkline := ck.MkLine

	switch mkline.Varcanon() {
	case "BUILDLINK_PKGSRCDIR.*",
		"BUILDLINK_DEPMETHOD.*",
		"BUILDLINK_ABI_DEPENDS.*",
		"BUILDLINK_INCDIRS.*",
		"BUILDLINK_LIBDIRS.*":
		return
	}

	if !G.Opts.WarnExtra ||
		G.Infrastructure ||
		mkline.Op() != opAssignDefault ||
		G.Mk.Tools.SeenPrefs ||
		!G.Mk.FirstTime("include bsd.prefs.mk before using ?=") {
		return
	}

	mkline.Warnf("Please include \"../../mk/bsd.prefs.mk\" before using \"?=\".")
	Explain(
		"The ?= operator is used to provide a default value to a variable.",
		"In pkgsrc, many variables can be set by the pkgsrc user in the",
		"mk.conf file.  This file must be included explicitly.  If a ?=",
		"operator appears before mk.conf has been included, it will not care",
		"about the user's preferences, which can result in unexpected",
		"behavior.",
		"",
		"The easiest way to include the mk.conf file is by including the",
		"bsd.prefs.mk file, which will take care of everything.")
}

func (ck MkLineChecker) CheckVartype(varname string, op MkOperator, value, comment string) {
	if trace.Tracing {
		defer trace.Call(varname, op, value, comment)()
	}

	if !G.Opts.WarnTypes {
		return
	}

	mkline := ck.MkLine
	vartype := G.Pkgsrc.VariableType(varname)

	if op == opAssignAppend {
		if vartype != nil && !vartype.MayBeAppendedTo() {
			mkline.Warnf("The \"+=\" operator should only be used with lists, not with %s.", varname)
		}
	}

	switch {
	case vartype == nil:
		if trace.Tracing {
			trace.Step1("Unchecked variable assignment for %s.", varname)
		}

	case op == opAssignShell:
		if trace.Tracing {
			trace.Step1("Unchecked use of !=: %q", value)
		}

	case vartype.kindOfList == lkNone:
		ck.CheckVartypePrimitive(varname, vartype.basicType, op, value, comment, vartype.guessed)

	case value == "":
		break

	case vartype.kindOfList == lkSpace:
		for _, word := range fields(value) {
			ck.CheckVartypePrimitive(varname, vartype.basicType, op, word, comment, vartype.guessed)
		}

	case vartype.kindOfList == lkShell:
		words, _ := splitIntoMkWords(mkline.Line, value)
		for _, word := range words {
			ck.CheckVartypePrimitive(varname, vartype.basicType, op, word, comment, vartype.guessed)
		}
	}
}

// For some variables (like `BuildlinkDepth`), `op` influences the valid values.
// The `comment` parameter comes from a variable assignment, when a part of the line is commented out.
func (ck MkLineChecker) CheckVartypePrimitive(varname string, checker *BasicType, op MkOperator, value, comment string, guessed bool) {
	if trace.Tracing {
		defer trace.Call(varname, checker.name, op, value, comment, guessed)()
	}

	mkline := ck.MkLine
	valueNoVar := mkline.WithoutMakeVariables(value)
	ctx := &VartypeCheck{mkline, mkline.Line, varname, op, value, valueNoVar, comment, guessed}
	checker.checker(ctx)
}

func (ck MkLineChecker) checkText(text string) {
	if trace.Tracing {
		defer trace.Call1(text)()
	}

	mkline := ck.MkLine
	if contains(text, "${WRKSRC}/..") {
		mkline.Warnf("Building the package should take place entirely inside ${WRKSRC}, not \"${WRKSRC}/..\".")
		Explain(
			"WRKSRC should be defined so that there is no need to do anything",
			"outside of this directory.",
			"",
			"Example:",
			"",
			"\tWRKSRC=\t${WRKDIR}",
			"\tCONFIGURE_DIRS=\t${WRKSRC}/lib ${WRKSRC}/src",
			"\tBUILD_DIRS=\t${WRKSRC}/lib ${WRKSRC}/src ${WRKSRC}/cmd",
			"",
			"See the pkgsrc guide, section \"Directories used during the build",
			"process\" for more information.")
	}

	// Note: A simple -R is not detected, as the rate of false positives is too high.
	if m, flag := match1(text, `(-Wl,--rpath,|-Wl,-rpath-link,|-Wl,-rpath,|-Wl,-R\b)`); m {
		mkline.Warnf("Please use ${COMPILER_RPATH_FLAG} instead of %q.", flag)
	}

	rest := text
	for {
		m, r := G.res.ReplaceFirst(rest, `(?:^|[^$])\$\{([-A-Z0-9a-z_]+)(\.[\-0-9A-Z_a-z]+)?(?::[^\}]+)?\}`, "")
		if m == nil {
			break
		}
		rest = r

		varbase, varext := m[1], m[2]
		varname := varbase + varext
		varcanon := varnameCanon(varname)
		instead := G.Pkgsrc.Deprecated[varname]
		if instead == "" {
			instead = G.Pkgsrc.Deprecated[varcanon]
		}
		if instead != "" {
			mkline.Warnf("Use of %q is deprecated. %s", varname, instead)
		}
	}
}

func (ck MkLineChecker) checkDirectiveCond() {
	mkline := ck.MkLine
	if trace.Tracing {
		defer trace.Call1(mkline.Args())()
	}

	p := NewMkParser(mkline.Line, mkline.Args(), false) // XXX: Why false?
	cond := p.MkCond()
	if !p.EOF() {
		mkline.Warnf("Invalid condition, unrecognized part: %q.", p.Rest())
		return
	}

	checkEmpty := func(varuse *MkVarUse) {
		varname := varuse.varname
		if matches(varname, `^\$.*:[MN]`) {
			mkline.Warnf("The empty() function takes a variable name as parameter, not a variable expression.")
			Explain(
				"Instead of empty(${VARNAME:Mpattern}), you should write either",
				"of the following:",
				"",
				"\tempty(VARNAME:Mpattern)",
				"\t${VARNAME:Mpattern} == \"\"",
				"",
				"Instead of !empty(${VARNAME:Mpattern}), you should write either",
				"of the following:",
				"",
				"\t!empty(VARNAME:Mpattern)",
				"\t${VARNAME:Mpattern}")
		}

		modifiers := varuse.modifiers
		for _, modifier := range modifiers {
			if m, positive, pattern := modifier.MatchMatch(); m && (positive || len(modifiers) == 1) {
				ck.CheckVartype(varname, opUseMatch, pattern, "")

				vartype := G.Pkgsrc.VariableType(varname)
				if matches(pattern, `^[\w-/]+$`) && vartype != nil && !vartype.IsConsideredList() {
					mkline.Notef("%s should be compared using == instead of the :M or :N modifier without wildcards.", varname)
					Explain(
						"This variable has a single value, not a list of values.  Therefore",
						"it feels strange to apply list operators like :M and :N onto it.",
						"A more direct approach is to use the == and != operators.",
						"",
						"An entirely different case is when the pattern contains wildcards",
						"like ^, *, $.  In such a case, using the :M or :N modifiers is",
						"useful and preferred.")
				}
			}
		}
	}

	checkCompareVarStr := func(varuse *MkVarUse, op string, value string) {
		varname := varuse.varname
		varmods := varuse.modifiers
		if len(varmods) == 0 {
			ck.checkCompareVarStr(varname, op, value)
		} else if len(varmods) == 1 {
			if m, _, _ := varmods[0].MatchMatch(); m && value != "" {
				ck.CheckVartype(varname, opUseMatch, value, "")
			}
		}
	}

	checkVarUse := func(varuse *MkVarUse) {
		var vartype *Vartype // TODO: Insert a better type guess here.
		vuc := &VarUseContext{vartype, vucTimeParse, vucQuotPlain, false}
		ck.CheckVaruse(varuse, vuc)
	}

	NewMkCondWalker().Walk(cond, &MkCondCallback{
		Empty:         checkEmpty,
		CompareVarStr: checkCompareVarStr,
		VarUse:        checkVarUse})
}

func (ck MkLineChecker) checkCompareVarStr(varname, op, value string) {
	ck.CheckVartype(varname, opUseCompare, value, "")

	if varname == "PKGSRC_COMPILER" {
		ck.MkLine.Warnf("Use ${PKGSRC_COMPILER:%s%s} instead of the %s operator.", ifelseStr(op == "==", "M", "N"), value, op)
		Explain(
			"The PKGSRC_COMPILER can be a list of chained compilers, e.g. \"ccache",
			"distcc clang\".  Therefore, comparing it using == or != leads to",
			"wrong results in these cases.")
	}
}

func (ck MkLineChecker) CheckRelativePkgdir(pkgdir string) {
	if trace.Tracing {
		defer trace.Call1(pkgdir)()
	}

	mkline := ck.MkLine
	ck.CheckRelativePath(pkgdir, true)
	pkgdir = mkline.ResolveVarsInRelativePath(pkgdir, false)

	if m, otherpkgpath := match1(pkgdir, `^(?:\./)?\.\./\.\./([^/]+/[^/]+)$`); m {
		if !fileExists(G.Pkgsrc.File(otherpkgpath + "/Makefile")) {
			mkline.Errorf("There is no package in %q.", otherpkgpath)
		}

	} else if !containsVarRef(pkgdir) {
		mkline.Warnf("%q is not a valid relative package directory.", pkgdir)
		Explain(
			"A relative pathname always starts with \"../../\", followed",
			"by a category, a slash and a the directory name of the package.",
			"For example, \"../../misc/screen\" is a valid relative pathname.")
	}
}

func (ck MkLineChecker) CheckRelativePath(relativePath string, mustExist bool) {
	if trace.Tracing {
		defer trace.Call(relativePath, mustExist)()
	}

	mkline := ck.MkLine
	if !G.Wip && contains(relativePath, "/wip/") {
		mkline.Errorf("A main pkgsrc package must not depend on a pkgsrc-wip package.")
	}

	resolvedPath := mkline.ResolveVarsInRelativePath(relativePath, true)
	if containsVarRef(resolvedPath) {
		return
	}

	abs := resolvedPath
	if !hasPrefix(abs, "/") {
		abs = path.Dir(mkline.FileName) + "/" + abs
	}
	if _, err := os.Stat(abs); err != nil {
		if mustExist {
			mkline.Errorf("%q does not exist.", resolvedPath)
		}
		return
	}

	switch {
	case !hasPrefix(relativePath, "../"):
	case hasPrefix(relativePath, "../../mk/"):
		// From a package to the infrastructure.
	case matches(relativePath, `^\.\./\.\./[^/]+/[^/]`):
		// From a package to another package.
	case hasPrefix(relativePath, "../mk/") && relpath(path.Dir(mkline.FileName), G.Pkgsrc.File(".")) == "..":
		// For category Makefiles.
	default:
		mkline.Warnf("Invalid relative path %q.", relativePath)
	}
}
