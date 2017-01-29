package main

import (
	"fmt"
	"netbsd.org/pkglint/regex"
	"netbsd.org/pkglint/trace"
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

	LineChecker{mkline}.CheckTrailingWhitespace()
	LineChecker{mkline}.CheckValidCharacters(`[\t -~]`)

	switch {
	case mkline.IsVarassign():
		ck.checkVarassign()

	case mkline.IsShellcmd():
		shellcmd := mkline.Shellcmd()
		ck.checkText(shellcmd)
		NewShellLine(mkline).CheckShellCommandLine(shellcmd)

	case mkline.IsComment():
		if hasPrefix(mkline.Text(), "# url2pkg-marker") {
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
		ck.checkDirectiveIndentation(G.Mk.indentation.Depth())
	}

	includefile := mkline.Includefile()
	mustExist := mkline.MustExist()
	if trace.Tracing {
		trace.Step2("includingFile=%s includefile=%s", mkline.Filename(), includefile)
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

	case includefile == "../../mk/bsd.prefs.mk":
		if path.Base(mkline.Filename()) == "buildlink3.mk" {
			mkline.Notef("For efficiency reasons, please include bsd.fast.prefs.mk instead of bsd.prefs.mk.")
		}
		if G.Pkg != nil {
			G.Pkg.setSeenBsdPrefsMk()
		}

	case includefile == "../../mk/bsd.fast.prefs.mk", includefile == "../../mk/buildlink3/bsd.builtin.mk":
		if G.Pkg != nil {
			G.Pkg.setSeenBsdPrefsMk()
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

func (ck MkLineChecker) checkCond(forVars map[string]bool) {
	mkline := ck.MkLine

	directive := mkline.Directive()
	args := mkline.Args()
	indentation := &G.Mk.indentation

	switch directive {
	case "endif", "endfor":
		if indentation.Len() > 1 {
			indentation.Pop()
		} else {
			mkline.Errorf("Unmatched .%s.", directive)
		}
	}

	expectedDepth := indentation.Depth()
	if directive == "elif" || directive == "else" {
		expectedDepth = indentation.depth[len(indentation.depth)-2]
	}
	ck.checkDirectiveIndentation(expectedDepth)

	if directive == "if" && matches(args, `^!defined\([\w]+_MK\)$`) {
		indentation.Push(indentation.Depth())
	} else if matches(directive, `^(?:if|ifdef|ifndef|for)$`) {
		indentation.Push(indentation.Depth() + 2)
	}

	needsArgument := matches(directive, `^(?:if|ifdef|ifndef|elif|for|undef)$`)
	if needsArgument != (args != "") {
		if needsArgument {
			mkline.Errorf("\".%s\" requires arguments.", directive)
		} else {
			mkline.Errorf("\".%s\" does not take arguments.", directive)
			if directive == "else" {
				mkline.Notef("If you meant \"else if\", use \".elif\".")
			}
		}

	} else if directive == "if" || directive == "elif" {
		ck.CheckCond()

	} else if directive == "ifdef" || directive == "ifndef" {
		mkline.Warnf("The \".%s\" directive is deprecated. Please use \".if %sdefined(%s)\" instead.",
			directive, ifelseStr(directive == "ifdef", "", "!"), args)

	} else if directive == "for" {
		if m, vars, values := match2(args, `^(\S+(?:\s*\S+)*?)\s+in\s+(.*)$`); m {
			for _, forvar := range splitOnSpace(vars) {
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
			for _, value := range splitOnSpace(values) {
				if m, vname := match1(value, `^\$\{(.*)\}`); m {
					vartype := mkline.VariableType(vname)
					if vartype != nil && !vartype.guessed {
						guessed = false
					}
				}
			}

			forLoopType := &Vartype{lkSpace, BtUnknown, []AclEntry{{"*", aclpAllRead}}, guessed}
			forLoopContext := &VarUseContext{forLoopType, vucTimeParse, vucQuotFor, false}
			for _, forLoopVar := range mkline.ExtractUsedVariables(values) {
				ck.CheckVaruse(&MkVarUse{forLoopVar, nil}, forLoopContext)
			}
		}

	} else if directive == "undef" && args != "" {
		for _, uvar := range splitOnSpace(args) {
			if forVars[uvar] {
				mkline.Notef("Using \".undef\" after a \".for\" loop is unnecessary.")
			}
		}
	}
}

func (ck MkLineChecker) checkDirectiveIndentation(expectedDepth int) {
	if G.Mk == nil {
		return
	}
	mkline := ck.MkLine
	indent := mkline.Indent()
	if expected := strings.Repeat(" ", expectedDepth); indent != expected {
		if G.opts.WarnSpace && !mkline.AutofixReplace("."+indent, "."+expected) {
			mkline.Notef("This directive should be indented by %d spaces.", expectedDepth)
		}
	}
}

func (ck MkLineChecker) checkDependencyRule(allowedTargets map[string]bool) {
	mkline := ck.MkLine
	targets := splitOnSpace(mkline.Targets())
	sources := splitOnSpace(mkline.Sources())

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

		} else if !allowedTargets[target] {
			mkline.Warnf("Unusual target %q.", target)
			Explain(
				"If you want to define your own targets, you can \"declare\"",
				"them by inserting a \".PHONY: my-target\" line before this line.  This",
				"will tell make(1) to not interpret this target's name as a filename.")
		}
	}
}

func (ck MkLineChecker) checkVarassignDefPermissions() {
	if !G.opts.WarnPerm {
		return
	}
	if trace.Tracing {
		defer trace.Call()()
	}

	mkline := ck.MkLine
	varname := mkline.Varname()
	op := mkline.Op()
	vartype := mkline.VariableType(varname)
	if vartype == nil {
		if trace.Tracing {
			trace.Step1("No type definition found for %q.", varname)
		}
		return
	}

	perms := vartype.EffectivePermissions(mkline.Filename())
	var needed AclPermissions
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
	vartype := mkline.VariableType(varname)
	if G.opts.WarnExtra &&
		(vartype == nil || vartype.guessed) &&
		!varIsUsed(varname) &&
		!(G.Mk != nil && G.Mk.forVars[varname]) &&
		!containsVarRef(varname) {
		mkline.Warnf("%s is used but not defined. Spelling mistake?", varname)
	}

	ck.CheckVarusePermissions(varname, vartype, vuc)

	if varname == "LOCALBASE" && !G.Infrastructure {
		ck.WarnVaruseLocalbase()
	}

	needsQuoting := mkline.VariableNeedsQuoting(varname, vartype, vuc)

	if vuc.quoting == vucQuotFor {
		ck.checkVaruseFor(varname, vartype, needsQuoting)
	}

	if G.opts.WarnQuoting && vuc.quoting != vucQuotUnknown && needsQuoting != nqDontKnow {
		ck.CheckVaruseShellword(varname, vartype, vuc, varuse.Mod(), needsQuoting)
	}

	if G.globalData.UserDefinedVars[varname] != nil && !G.globalData.SystemBuildDefs[varname] && !G.Mk.buildDefs[varname] {
		mkline.Warnf("The user-defined variable %s is used but not added to BUILD_DEFS.", varname)
		Explain(
			"When a pkgsrc package is built, many things can be configured by the",
			"pkgsrc user in the mk.conf file.  All these configurations should be",
			"recorded in the binary package, so the package can be reliably",
			"rebuilt.  The BUILD_DEFS variable contains a list of all these",
			"user-settable variables, so please add your variable to it, too.")
	}
}

func (ck MkLineChecker) CheckVarusePermissions(varname string, vartype *Vartype, vuc *VarUseContext) {
	if !G.opts.WarnPerm {
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
	perms := vartype.EffectivePermissions(mkline.Filename())

	isLoadTime := false // Will the variable be used at load time?

	// Might the variable be used indirectly at load time, for example
	// by assigning it to another variable which then gets evaluated?
	isIndirect := false

	switch {
	case vuc.vartype != nil && vuc.vartype.guessed:
	// Don't warn about unknown variables.

	case vuc.time == vucTimeParse && !perms.Contains(aclpUseLoadtime):
		isLoadTime = true

	case vuc.vartype != nil && vuc.vartype.Union().Contains(aclpUseLoadtime) && !perms.Contains(aclpUseLoadtime):
		isLoadTime = true
		isIndirect = true
	}

	done := false
	tool := G.globalData.Tools.byVarname[varname]

	if isLoadTime && tool != nil {
		done = tool.Predefined && (G.Mk == nil || G.Mk.SeenBsdPrefsMk || G.Pkg == nil || G.Pkg.SeenBsdPrefsMk)

		if !done && G.Pkg != nil && !G.Pkg.SeenBsdPrefsMk && G.Mk != nil && !G.Mk.SeenBsdPrefsMk {
			mkline.Warnf("To use the tool %q at load time, bsd.prefs.mk has to be included before.", varname)
			done = true
		}

		if !done && G.Pkg != nil {
			usable, defined := G.Pkg.loadTimeTools[tool.Name]
			if usable {
				done = true
			}
			if defined && !usable {
				mkline.Warnf("To use the tool %q at load time, it has to be added to USE_TOOLS before including bsd.prefs.mk.", varname)
				done = true
			}
		}
	}

	if !done && isLoadTime && !isIndirect {
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
		done = true
	}

	if !done && isLoadTime && isIndirect {
		mkline.Warnf("%s should not be evaluated indirectly at load time.", varname)
		Explain(
			"The variable on the left-hand side may be evaluated at load time,",
			"but the variable on the right-hand side may not.  Because of the",
			"assignment in this line, the variable might be used indirectly",
			"at load time, before it is guaranteed to be properly initialized.")
		done = true
	}

	if !perms.Contains(aclpUseLoadtime) && !perms.Contains(aclpUse) {
		needed := aclpUse
		if isLoadTime {
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

func (ck MkLineChecker) WarnVaruseLocalbase() {
	ck.MkLine.Warnf("The LOCALBASE variable should not be used by packages.")
	Explain(
		// from jlam via private mail.
		"Currently, LOCALBASE is typically used in these cases:",
		"",
		"(1) To locate a file or directory from another package.",
		"(2) To refer to own files after installation.",
		"",
		"Example for (1):",
		"",
		"	STRLIST=        ${LOCALBASE}/bin/strlist",
		"	do-build:",
		"		cd ${WRKSRC} && ${STRLIST} *.str",
		"",
		"This should better be:",
		"",
		"	EVAL_PREFIX=    STRLIST_PREFIX=strlist",
		"	STRLIST=        ${STRLIST_PREFIX}/bin/strlist",
		"	do-build:",
		"		cd ${WRKSRC} && ${STRLIST} *.str",
		"",
		"Example for (2):",
		"",
		"	CONFIGURE_ENV+= --with-datafiles=${LOCALBASE}/share/pkgbase",
		"",
		"This should better be:",
		"",
		"	CONFIGURE_ENV+= --with-datafiles=${PREFIX}/share/pkgbase")
}

func (ck MkLineChecker) checkVaruseFor(varname string, vartype *Vartype, needsQuoting NeedsQuoting) {
	if trace.Tracing {
		defer trace.Call(varname, vartype, needsQuoting)()
	}

	if false && // Too many false positives
		vartype != nil &&
		vartype.kindOfList != lkSpace &&
		needsQuoting != nqDoesntMatter {
		ck.MkLine.Warnf("The variable %s should not be used in .for loops.", varname)
		Explain(
			"The .for loop splits its argument at sequences of white-space, as",
			"opposed to all other places in make(1), which act like the shell.",
			"Therefore only variables that are split at whitespace or don't",
			"contain any special characters should be used here.")
	}
}

func (ck MkLineChecker) CheckVaruseShellword(varname string, vartype *Vartype, vuc *VarUseContext, mod string, needsQuoting NeedsQuoting) {
	if trace.Tracing {
		defer trace.Call(varname, vartype, vuc, mod, needsQuoting)()
	}

	// In GNU configure scripts, a few variables need to be
	// passed through the :M* operator before they reach the
	// configure scripts.
	//
	// When doing checks outside a package, the :M* operator is needed for safety.
	needMstar := matches(varname, `^(?:.*_)?(?:CFLAGS||CPPFLAGS|CXXFLAGS|FFLAGS|LDFLAGS|LIBS)$`) &&
		(G.Pkg == nil || G.Pkg.vardef["GNU_CONFIGURE"] != nil)

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

		} else if mod != correctMod {
			if vuc.quoting == vucQuotPlain {
				if !mkline.AutofixReplace("${"+varname+mod+"}", "${"+varname+correctMod+"}") {
					mkline.Warnf("Please use ${%s%s} instead of ${%s%s}.", varname, correctMod, varname, mod)
				}
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
		needExplain := false
		if needsQuoting == nqNo && !mkline.AutofixReplace(bad, good) {
			needExplain = true
			mkline.Warnf("The :Q operator should not be used for ${%s} here.", varname)
		}
		if needsQuoting == nqDoesntMatter && !mkline.AutofixReplace(bad, good) {
			needExplain = true
			mkline.Notef("The :Q operator isn't necessary for ${%s} here.", varname)
		}
		if needExplain {
			Explain(
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
		}
	}
}

func (ck MkLineChecker) checkVarassignPythonVersions(varname, value string) {
	if trace.Tracing {
		defer trace.Call2(varname, value)()
	}

	mkline := ck.MkLine
	strversions := splitOnSpace(value)
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
	ck.checkVarassignDefPermissions()
	ck.checkVarassignBsdPrefs()

	ck.checkText(value)
	ck.CheckVartype(varname, op, value, comment)

	// If the variable is not used and is untyped, it may be a spelling mistake.
	if op == opAssignEval && varname == strings.ToLower(varname) {
		if trace.Tracing {
			trace.Step1("%s might be unused unless it is an argument to a procedure file.", varname)
		}

	} else if !varIsUsed(varname) {
		if vartypes := G.globalData.vartypes; vartypes[varname] != nil || vartypes[varcanon] != nil {
			// Ok
		} else if deprecated := G.globalData.Deprecated; deprecated[varname] != "" || deprecated[varcanon] != "" {
			// Ok
		} else {
			mkline.Warnf("%s is defined but not used. Spelling mistake?", varname)
		}
	}

	ck.checkVarassignSpecific()

	if varname == "EVAL_PREFIX" {
		if m, evalVarname := match1(value, `^([\w_]+)=`); m {

			// The variables mentioned in EVAL_PREFIX will later be
			// defined by find-prefix.mk. Therefore, they are marked
			// as known in the current file.
			G.Mk.vardef[evalVarname] = mkline
		}
	}

	if varname == "USE_TOOLS" {
		for _, fullToolname := range splitOnSpace(value) {
			toolname := strings.Split(fullToolname, ":")[0]
			if G.Pkg != nil {
				if !G.Pkg.SeenBsdPrefsMk {
					G.Pkg.loadTimeTools[toolname] = true
					if trace.Tracing {
						trace.Step1("loadTimeTool %q", toolname)
					}
				} else if !G.Pkg.loadTimeTools[toolname] {
					G.Pkg.loadTimeTools[toolname] = false
					if trace.Tracing {
						trace.Step1("too late for loadTimeTool %q", toolname)
					}
				}
			}
		}
	}

	if fix := G.globalData.Deprecated[varname]; fix != "" {
		mkline.Warnf("Definition of %s is deprecated. %s", varname, fix)
	} else if fix := G.globalData.Deprecated[varcanon]; fix != "" {
		mkline.Warnf("Definition of %s is deprecated. %s", varname, fix)
	}

	ck.checkVarassignPlistComment(varname, value)
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

	vartype := mkline.VariableType(mkline.Varname())
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
	tokens := NewMkParser(mkline, mkline.Value(), false).MkTokens()
	for i, token := range tokens {
		if token.Varuse != nil {
			spaceLeft := i-1 < 0 || matches(tokens[i-1].Text, `\s$`)
			spaceRight := i+1 >= len(tokens) || matches(tokens[i+1].Text, `^\s`)
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
	atoms := NewShTokenizer(mkline, mkline.Value(), false).ShAtoms()
	for i, atom := range atoms {
		if atom.Type == shtVaruse {
			isWordPart := isWordPart(atoms, i)
			vuc := &VarUseContext{vartype, time, atom.Quoting.ToVarUseContext(), isWordPart}
			ck.CheckVaruse(atom.Data.(*MkVarUse), vuc)
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

	if varname == "PERL5_PACKLIST" && G.Pkg != nil {
		if m, p5pkgname := match1(G.Pkg.EffectivePkgbase, `^p5-(.*)`); m {
			guess := "auto/" + strings.Replace(p5pkgname, "-", "/", -1) + "/.packlist"

			ucvalue, ucguess := strings.ToUpper(value), strings.ToUpper(guess)
			if ucvalue != ucguess && ucvalue != "${PERL5_SITEARCH}/"+ucguess {
				mkline.Warnf("Unusual value for PERL5_PACKLIST -- %q expected.", guess)
			}
		}
	}

	if varname == "CONFIGURE_ARGS" && contains(value, "=${PREFIX}/share/kde") {
		mkline.Notef("Please .include \"../../meta-pkgs/kde3/kde3.mk\" instead of this line.")
		Explain(
			"That file does many things automatically and consistently that this",
			"package also does.  When using kde3.mk, you can probably also leave",
			"out some explicit dependencies.")
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
	if G.opts.WarnExtra && mkline.Op() == opAssignDefault && G.Pkg != nil && !G.Pkg.SeenBsdPrefsMk {
		switch mkline.Varcanon() {
		case "BUILDLINK_PKGSRCDIR.*", "BUILDLINK_DEPMETHOD.*", "BUILDLINK_ABI_DEPENDS.*":
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
}

func (ck MkLineChecker) checkVarassignPlistComment(varname, value string) {
	if false && // This is currently neither correct nor helpful
		contains(value, "@comment") && !matches(value, `="@comment "`) {
		ck.MkLine.Warnf("Please don't use @comment in %s.", varname)
		Explain(
			"If you are defining a PLIST conditional here, use one of the",
			"following patterns instead:",
			"",
			"1. The direct way, without intermediate variable",
			"",
			"\tPLIST_SUBST+=\tMY_VAR=\"@comment \"",
			"",
			"2. The indirect way, with a separate variable",
			"",
			"\tPLIST_VARS+=\tMY_VAR",
			"\t.if ...",
			"\tMY_VAR?=\tyes",
			"\t.endif")
	}

	// Mark the variable as PLIST condition. This is later used in checkfile_PLIST.
	if G.Pkg != nil {
		if m, plistVarname := match1(value, `(.+)=.*@comment.*`); m {
			G.Pkg.plistSubstCond[plistVarname] = true
		}
	}
}

func (ck MkLineChecker) CheckVartype(varname string, op MkOperator, value, comment string) {
	if trace.Tracing {
		defer trace.Call(varname, op, value, comment)()
	}

	if !G.opts.WarnTypes {
		return
	}

	mkline := ck.MkLine
	vartype := mkline.VariableType(varname)

	if op == opAssignAppend {
		if vartype != nil && !vartype.MayBeAppendedTo() {
			mkline.Warnf("The \"+=\" operator should only be used with lists.")
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
		for _, word := range splitOnSpace(value) {
			ck.CheckVartypePrimitive(varname, vartype.basicType, op, word, comment, vartype.guessed)
		}

	case vartype.kindOfList == lkShell:
		words, _ := splitIntoMkWords(mkline, value)
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
	ctx := &VartypeCheck{mkline, mkline, varname, op, value, valueNoVar, comment, guessed}
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
	if m, flag := match1(text, `\b(-Wl,--rpath,|-Wl,-rpath-link,|-Wl,-rpath,|-Wl,-R)\b`); m {
		mkline.Warnf("Please use ${COMPILER_RPATH_FLAG} instead of %q.", flag)
	}

	rest := text
	for {
		m, r := regex.ReplaceFirst(rest, `(?:^|[^$])\$\{([-A-Z0-9a-z_]+)(\.[\-0-9A-Z_a-z]+)?(?::[^\}]+)?\}`, "")
		if m == nil {
			break
		}
		rest = r

		varbase, varext := m[1], m[2]
		varname := varbase + varext
		varcanon := varnameCanon(varname)
		instead := G.globalData.Deprecated[varname]
		if instead == "" {
			instead = G.globalData.Deprecated[varcanon]
		}
		if instead != "" {
			mkline.Warnf("Use of %q is deprecated. %s", varname, instead)
		}
	}
}

func (ck MkLineChecker) CheckCond() {
	mkline := ck.MkLine
	if trace.Tracing {
		defer trace.Call1(mkline.Args())()
	}

	p := NewMkParser(mkline, mkline.Args(), false)
	cond := p.MkCond()
	if !p.EOF() {
		mkline.Warnf("Invalid conditional %q.", mkline.Args())
		return
	}

	cond.Visit("empty", func(node *Tree) {
		varuse := node.args[0].(MkVarUse)
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
		for _, modifier := range varuse.modifiers {
			if modifier[0] == 'M' || modifier[0] == 'N' {
				ck.CheckVartype(varname, opUseMatch, modifier[1:], "")
			}
		}
	})

	cond.Visit("compareVarStr", func(node *Tree) {
		varuse := node.args[0].(MkVarUse)
		varname := varuse.varname
		varmods := varuse.modifiers
		value := node.args[2].(string)
		if len(varmods) == 0 {
			ck.checkCompareVarStr(varname, node.args[1].(string), value)
		} else if len(varmods) == 1 && matches(varmods[0], `^[MN]`) && value != "" {
			ck.CheckVartype(varname, opUseMatch, value, "")
		}
	})

	if G.Mk != nil {
		G.Mk.indentation.RememberUsedVariables(cond)
	}
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

func (ck MkLineChecker) CheckValidCharactersInValue(reValid regex.RegexPattern) {
	mkline := ck.MkLine
	rest := regex.Compile(reValid).ReplaceAllString(mkline.Value(), "")
	if rest != "" {
		uni := ""
		for _, c := range rest {
			uni += fmt.Sprintf(" %U", c)
		}
		mkline.Warnf("%s contains invalid characters (%s).", mkline.Varname(), uni[1:])
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
		if !fileExists(G.globalData.Pkgsrcdir + "/" + otherpkgpath + "/Makefile") {
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

func (ck MkLineChecker) CheckRelativePath(path string, mustExist bool) {
	if trace.Tracing {
		defer trace.Call(path, mustExist)()
	}

	mkline := ck.MkLine
	if !G.Wip && contains(path, "/wip/") {
		mkline.Errorf("A main pkgsrc package must not depend on a pkgsrc-wip package.")
	}

	resolvedPath := mkline.ResolveVarsInRelativePath(path, true)
	if containsVarRef(resolvedPath) {
		return
	}

	abs := resolvedPath
	if !hasPrefix(abs, "/") {
		abs = G.CurrentDir + "/" + abs
	}
	if _, err := os.Stat(abs); err != nil {
		if mustExist {
			mkline.Errorf("%q does not exist.", resolvedPath)
		}
		return
	}

	if hasPrefix(path, "../") &&
		!matches(path, `^\.\./\.\./[^/]+/[^/]`) &&
		!(G.CurPkgsrcdir == ".." && hasPrefix(path, "../mk/")) && // For category Makefiles.
		!hasPrefix(path, "../../mk/") {
		mkline.Warnf("Invalid relative path %q.", path)
	}
}
