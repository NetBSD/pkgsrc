package pkglint

import (
	"netbsd.org/pkglint/regex"
	"os"
	"path"
	"path/filepath"
	"strconv"
	"strings"
)

// MkLineChecker provides checks for a single line from a Makefile fragment.
type MkLineChecker struct {
	MkLines *MkLines
	MkLine  *MkLine
}

func (ck MkLineChecker) Check() {
	mkline := ck.MkLine

	LineChecker{mkline.Line}.CheckTrailingWhitespace()
	LineChecker{mkline.Line}.CheckValidCharacters()

	switch {
	case mkline.IsVarassign():
		ck.checkVarassign()

	case mkline.IsShellCommand():
		ck.checkShellCommand()

	case mkline.IsComment():
		ck.checkComment()

	case mkline.IsInclude():
		ck.checkInclude()
	}
}

func (ck MkLineChecker) checkComment() {
	mkline := ck.MkLine

	if hasPrefix(mkline.Text, "# url2pkg-marker") {
		mkline.Errorf("This comment indicates unfinished work (url2pkg).")
	}
}

func (ck MkLineChecker) checkShellCommand() {
	mkline := ck.MkLine

	shellCommand := mkline.ShellCommand()
	if G.Opts.WarnSpace && hasPrefix(mkline.Text, "\t\t") {
		fix := mkline.Autofix()
		fix.Notef("Shell programs should be indented with a single tab.")
		fix.Explain(
			"The first tab in the line marks the line as a shell command.",
			"Since every line of shell commands starts with a completely new shell environment,",
			"there is no need to indent some of the commands,",
			"or to use more horizontal space than necessary.")
		fix.ReplaceRegex(`^\t\t+`, "\t", 1)
		fix.Apply()
	}

	ck.checkText(shellCommand)
	NewShellLineChecker(ck.MkLines, mkline).CheckShellCommandLine(shellCommand)
}

func (ck MkLineChecker) checkInclude() {
	if trace.Tracing {
		defer trace.Call0()()
	}

	mkline := ck.MkLine
	if mkline.Indent() != "" {
		ck.checkDirectiveIndentation(ck.MkLines.indentation.Depth("include"))
	}

	includedFile := mkline.IncludedFile()
	mustExist := mkline.MustExist()
	if trace.Tracing {
		trace.Step2("includingFile=%s includedFile=%s", mkline.Filename, includedFile)
	}
	ck.CheckRelativePath(includedFile, mustExist)

	switch {
	case hasSuffix(includedFile, "/Makefile"):
		mkline.Errorf("Other Makefiles must not be included directly.")
		mkline.Explain(
			"To include portions of another Makefile, extract the common parts",
			"and put them into a Makefile.common or a Makefile fragment called",
			"module.mk or similar.",
			"After that, both this one and the other package should include the newly created file.")

	case IsPrefs(includedFile):
		if mkline.Basename == "buildlink3.mk" && includedFile == "../../mk/bsd.prefs.mk" {
			fix := mkline.Autofix()
			fix.Notef("For efficiency reasons, please include bsd.fast.prefs.mk instead of bsd.prefs.mk.")
			fix.Replace("bsd.prefs.mk", "bsd.fast.prefs.mk")
			fix.Apply()
		}

	case hasSuffix(includedFile, "pkgtools/x11-links/buildlink3.mk"):
		fix := mkline.Autofix()
		fix.Errorf("%s must not be included directly. Include \"../../mk/x11.buildlink3.mk\" instead.", includedFile)
		fix.Replace("pkgtools/x11-links/buildlink3.mk", "mk/x11.buildlink3.mk")
		fix.Apply()

	case hasSuffix(includedFile, "graphics/jpeg/buildlink3.mk"):
		fix := mkline.Autofix()
		fix.Errorf("%s must not be included directly. Include \"../../mk/jpeg.buildlink3.mk\" instead.", includedFile)
		fix.Replace("graphics/jpeg/buildlink3.mk", "mk/jpeg.buildlink3.mk")
		fix.Apply()

	case hasSuffix(includedFile, "/intltool/buildlink3.mk"):
		mkline.Warnf("Please write \"USE_TOOLS+= intltool\" instead of this line.")

	case hasSuffix(includedFile, "/builtin.mk"):
		if mkline.Basename != "hacks.mk" {
			fix := mkline.Autofix()
			fix.Errorf("%s must not be included directly. Include \"%s/buildlink3.mk\" instead.", includedFile, path.Dir(includedFile))
			fix.Replace("builtin.mk", "buildlink3.mk")
			fix.Apply()
		}
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

	switch {
	case needsArgument && args == "":
		mkline.Errorf("\".%s\" requires arguments.", directive)

	case !needsArgument && args != "":
		if directive == "else" {
			mkline.Errorf("\".%s\" does not take arguments. If you meant \"else if\", use \".elif\".", directive)
		} else {
			mkline.Errorf("\".%s\" does not take arguments.", directive)
		}

	case directive == "if" || directive == "elif":
		ck.checkDirectiveCond()

	case directive == "ifdef" || directive == "ifndef":
		mkline.Warnf("The \".%s\" directive is deprecated. Please use \".if %sdefined(%s)\" instead.",
			directive, ifelseStr(directive == "ifdef", "", "!"), args)

	case directive == "for":
		ck.checkDirectiveFor(forVars, ind)

	case directive == "undef":
		for _, varname := range mkline.Fields() {
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

	if ind.Empty() {
		mkline.Errorf("Unmatched .%s.", directive)
		return
	}

	if comment == "" {
		return
	}

	if directive == "endif" {
		if args := ind.Args(); !contains(args, comment) {
			mkline.Warnf("Comment %q does not match condition %q.", comment, args)
		}
	}

	if directive == "endfor" {
		if args := ind.Args(); !contains(args, comment) {
			mkline.Warnf("Comment %q does not match loop %q.", comment, args)
		}
	}
}

func (ck MkLineChecker) checkDirectiveFor(forVars map[string]bool, indentation *Indentation) {
	mkline := ck.MkLine
	args := mkline.Args()

	if m, vars, _ := match2(args, `^([^\t ]+(?:[\t ]*[^\t ]+)*?)[\t ]+in[\t ]+(.*)$`); m {
		for _, forvar := range strings.Fields(vars) {
			indentation.AddVar(forvar)
			if !G.Infrastructure && hasPrefix(forvar, "_") {
				mkline.Warnf("Variable names starting with an underscore (%s) are reserved for internal pkgsrc use.", forvar)
			}

			if matches(forvar, `^[_a-z][_a-z0-9]*$`) {
				// Fine.
			} else if matches(forvar, `^[A-Z_a-z][0-9A-Z_a-z]*$`) {
				mkline.Warnf("The variable name %q in the .for loop should not contain uppercase letters.", forvar)
			} else {
				mkline.Errorf("Invalid variable name %q.", forvar)
			}

			forVars[forvar] = true
		}

		// XXX: The type BtUnknown is very unspecific here. For known variables
		// or constant values this could probably be improved.
		//
		// The guessed flag could also be determined more correctly. As of November 2018,
		// running pkglint over the whole pkgsrc tree did not produce any different result
		// whether guessed was true or false.
		forLoopType := NewVartype(btForLoop, List, NewACLEntry("*", aclpAllRead))
		forLoopContext := VarUseContext{forLoopType, VucLoadTime, VucQuotPlain, false}
		mkline.ForEachUsed(func(varUse *MkVarUse, time VucTime) {
			ck.CheckVaruse(varUse, &forLoopContext)
		})
	}
}

func (ck MkLineChecker) checkDirectiveIndentation(expectedDepth int) {
	if !G.Opts.WarnSpace {
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
	targets := ck.MkLine.ValueFields(mkline.Targets())
	sources := ck.MkLine.ValueFields(mkline.Sources())

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
			// This is deliberate, see the explanation below.

		} else if !allowedTargets[target] {
			mkline.Warnf("Undeclared target %q.", target)
			mkline.Explain(
				"To define a custom target in a package, declare it like this:",
				"",
				"\t.PHONY: my-target",
				"",
				"To define a custom target that creates a file (should be rarely needed),",
				"declare it like this:",
				"",
				"\t${.CURDIR}/my-file:")
		}
	}
}

// checkVarassignLeftPermissions checks the permissions for the left-hand side
// of a variable assignment line.
//
// See checkVarusePermissions.
func (ck MkLineChecker) checkVarassignLeftPermissions() {
	if !G.Opts.WarnPerm {
		return
	}
	if G.Infrastructure {
		// As long as vardefs.go doesn't explicitly define permissions for
		// infrastructure files, skip the check completely. This avoids
		// many wrong warnings.
		return
	}
	if trace.Tracing {
		defer trace.Call0()()
	}

	mkline := ck.MkLine
	if ck.MkLine.Basename == "hacks.mk" {
		return
	}

	varname := mkline.Varname()
	op := mkline.Op()
	vartype := G.Pkgsrc.VariableType(ck.MkLines, varname)
	if vartype == nil {
		return
	}

	perms := vartype.EffectivePermissions(mkline.Basename)

	// E.g. USE_TOOLS:= ${USE_TOOLS:Nunwanted-tool}
	if op == opAssignEval && perms&aclpAppend != 0 {
		tokens, _ := mkline.ValueTokens()
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
	default:
		alternativeActions := perms & aclpAllWrite
		alternativeFiles := vartype.AlternativeFiles(needed)
		switch {
		case alternativeActions != 0 && alternativeFiles != "":
			mkline.Warnf("The variable %s should not be %s (only %s) in this file; it would be ok in %s.",
				varname, needed.HumanString(), alternativeActions.HumanString(), alternativeFiles)
		case alternativeFiles != "":
			mkline.Warnf("The variable %s should not be %s in this file; it would be ok in %s.",
				varname, needed.HumanString(), alternativeFiles)
		case alternativeActions != 0:
			mkline.Warnf("The variable %s should not be %s (only %s) in this file.",
				varname, needed.HumanString(), alternativeActions.HumanString())
		default:
			mkline.Warnf("The variable %s should not be %s by any package.",
				varname, needed.HumanString())
		}
		ck.explainPermissions(varname, vartype)
	}
}

func (ck MkLineChecker) explainPermissions(varname string, vartype *Vartype, intro ...string) {
	if !G.Logger.Opts.Explain {
		return
	}

	// TODO: Starting with the second explanation, omit the common part. Instead, only list the permission rules.

	var expl []string

	if len(intro) > 0 {
		expl = append(expl, intro...)
		expl = append(expl, "")
	}

	expl = append(expl,
		"The allowed actions for a variable are determined based on the file",
		"name in which the variable is used or defined.",
		sprintf("The rules for %s are:", varname),
		"")

	for _, rule := range vartype.aclEntries {
		perms := rule.permissions.HumanString()

		files := rule.matcher.originalPattern
		if files == "*" {
			files = "any file"
		}

		if perms != "" {
			expl = append(expl, sprintf("* in %s, it may be %s", files, perms))
		} else {
			expl = append(expl, sprintf("* in %s, it should not be accessed at all", files))
		}
	}

	expl = append(expl,
		"",
		"If these rules seem to be incorrect, please ask on the tech-pkg@NetBSD.org mailing list.")

	ck.MkLine.Explain(expl...)
}

func (ck MkLineChecker) checkVarassignLeftRationale() {
	if !G.Opts.WarnExtra {
		return
	}

	isRationale := func(mkline *MkLine) bool {
		return mkline.IsComment() &&
			!hasPrefix(mkline.Text, "# $") &&
			!mkline.IsCommentedVarassign()
	}

	needsRationale := func(mkline *MkLine) bool {
		if !mkline.IsVarassign() && !mkline.IsCommentedVarassign() {
			return false
		}
		vartype := G.Pkgsrc.VariableType(ck.MkLines, mkline.Varname())
		return vartype != nil && vartype.NeedsRationale()
	}

	mkline := ck.MkLine
	if !needsRationale(mkline) {
		return
	}

	if mkline.VarassignComment() != "" {
		return
	}

	// Check whether there is a comment directly above.
	for i, other := range ck.MkLines.mklines {
		if other == mkline && i > 0 {
			aboveIndex := i - 1
			for aboveIndex > 0 && needsRationale(ck.MkLines.mklines[aboveIndex]) {
				aboveIndex--
			}

			if isRationale(ck.MkLines.mklines[aboveIndex]) {
				return
			}
		}
	}

	mkline.Warnf("Setting variable %s should have a rationale.", mkline.Varname())
	mkline.Explain(
		"Since this variable prevents the package from being built in some situations,",
		"the reasons for this restriction should be documented.",
		"Otherwise it becomes too difficult to check whether these restrictions still apply",
		"when the package is updated by someone else later.",
		"",
		"To add the rationale, put it in a comment at the end of this line,",
		"or in a separate comment in the line above.",
		"The rationale should try to answer these questions:",
		"",
		"* which specific aspects of the package are affected?",
		"* if it's a dependency, is the dependency too old or too new?",
		"* in which situations does a crash occur, if any?",
		"* has it been reported upstream?")
}

// CheckVaruse checks a single use of a variable in a specific context.
func (ck MkLineChecker) CheckVaruse(varuse *MkVarUse, vuc *VarUseContext) {
	mkline := ck.MkLine
	if trace.Tracing {
		defer trace.Call(mkline, varuse, vuc)()
	}

	if varuse.IsExpression() {
		return
	}

	varname := varuse.varname
	vartype := G.Pkgsrc.VariableType(ck.MkLines, varname)

	ck.checkVaruseUndefined(vartype, varname)
	ck.checkVaruseModifiers(varuse, vartype)
	ck.checkVarUseVarname(varuse)
	ck.checkVarusePermissions(varname, vartype, vuc)
	ck.checkVarUseQuoting(varuse, vartype, vuc)
	ck.checkVarUseBuildDefs(varname)
	ck.checkVaruseDeprecated(varuse)
	ck.checkTextVarUse(varname, vartype, vuc.time)
}

func (ck MkLineChecker) checkVarUseVarname(varuse *MkVarUse) {
	if varuse.varname == "@" {
		ck.MkLine.Warnf("Please use %q instead of %q.", "${.TARGET}", "$@")
		ck.MkLine.Explain(
			"It is more readable and prevents confusion with the shell variable",
			"of the same name.")
	}

	if varuse.varname == "LOCALBASE" && !G.Infrastructure {
		fix := ck.MkLine.Autofix()
		fix.Warnf("Please use PREFIX instead of LOCALBASE.")
		fix.ReplaceRegex(`\$\{LOCALBASE\b`, "${PREFIX", 1)
		fix.Apply()
	}
}

func (ck MkLineChecker) checkVarUseBuildDefs(varname string) {
	if !(G.Pkgsrc.UserDefinedVars.Defined(varname) && !G.Pkgsrc.IsBuildDef(varname)) {
		return
	}

	if !(!ck.MkLines.buildDefs[varname] && ck.MkLines.once.FirstTimeSlice("BUILD_DEFS", varname)) {
		return
	}

	ck.MkLine.Warnf("The user-defined variable %s is used but not added to BUILD_DEFS.", varname)
	ck.MkLine.Explain(
		"When a pkgsrc package is built, many things can be configured by the",
		"pkgsrc user in the mk.conf file.",
		"All these configurations should be recorded in the binary package",
		"so the package can be reliably rebuilt.",
		"The BUILD_DEFS variable contains a list of all these",
		"user-settable variables, so please add your variable to it, too.")
}

func (ck MkLineChecker) checkVaruseUndefined(vartype *Vartype, varname string) {
	switch {

	case !G.Opts.WarnExtra:
		return

	case vartype != nil && !vartype.Guessed():
		// Well-known variables are probably defined by the infrastructure.
		return

	case ck.MkLines.vars.DefinedSimilar(varname):
		return

	case ck.MkLines.forVars[varname]:
		return

	case ck.MkLines.vars.Mentioned(varname) != nil:
		return

	case G.Pkg != nil && G.Pkg.vars.DefinedSimilar(varname):
		return

	case containsVarRef(varname):
		return

	case G.Pkgsrc.vartypes.DefinedCanon(varname):
		return

	case !ck.MkLines.once.FirstTimeSlice("used but not defined: ", varname):
		return
	}

	ck.MkLine.Warnf("%s is used but not defined.", varname)
}

func (ck MkLineChecker) checkVaruseModifiers(varuse *MkVarUse, vartype *Vartype) {
	mods := varuse.modifiers
	if len(mods) == 0 {
		return
	}

	ck.checkVaruseModifiersSuffix(varuse, vartype)
	ck.checkVaruseModifiersRange(varuse)

	// TODO: Add checks for a single modifier, among them:
	// TODO: Suggest to replace ${VAR:@l@-l${l}@} with the simpler ${VAR:S,^,-l,}.
	// TODO: Suggest to replace ${VAR:@l@${l}suffix@} with the simpler ${VAR:=suffix}.
	// TODO: Investigate why :Q is not checked at this exact place.
}

func (ck MkLineChecker) checkVaruseModifiersSuffix(varuse *MkVarUse, vartype *Vartype) {
	if varuse.modifiers[0].IsSuffixSubst() && vartype != nil && !vartype.List() {
		ck.MkLine.Warnf("The :from=to modifier should only be used with lists, not with %s.", varuse.varname)
		ck.MkLine.Explain(
			"Instead of (for example):",
			"\tMASTER_SITES=\t${HOMEPAGE:=repository/}",
			"",
			"Write:",
			"\tMASTER_SITES=\t${HOMEPAGE}repository/",
			"",
			"This is a clearer expression of the same thought.")
	}
}

// checkVaruseModifiersRange suggests to replace
// ${VAR:S,^,__magic__,1:M__magic__*:S,^__magic__,,} with the simpler ${VAR:[1]}.
func (ck MkLineChecker) checkVaruseModifiersRange(varuse *MkVarUse) {
	mods := varuse.modifiers

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

// checkVarusePermissions checks the permissions when a variable is used,
// be it in a variable assignment, in a shell command, a conditional, or
// somewhere else.
//
// See checkVarassignLeftPermissions.
func (ck MkLineChecker) checkVarusePermissions(varname string, vartype *Vartype, vuc *VarUseContext) {
	if !G.Opts.WarnPerm {
		return
	}
	if G.Infrastructure {
		// As long as vardefs.go doesn't explicitly define permissions for
		// infrastructure files, skip the check completely. This avoids
		// many wrong warnings.
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

	if vartype.Guessed() {
		return
	}

	// Do not warn about unknown infrastructure variables.
	// These have all permissions to prevent warnings when they are used.
	// But when other variables are assigned to them it would seem as if
	// these other variables could become evaluated at load time.
	// And this is something that most variables do not allow.
	if vuc.vartype != nil && vuc.vartype.basicType == BtUnknown {
		return
	}

	basename := ck.MkLine.Basename
	if basename == "hacks.mk" {
		return
	}

	effPerms := vartype.EffectivePermissions(basename)
	if effPerms.Contains(aclpUseLoadtime) {
		// Since the variable may be used at load time, it probably
		// may be used at run time as well. If it weren't, that would
		// be a rather strange permissions set.
		return
	}

	// At this point the variable must not be used at load time.
	// Now determine whether it is directly used at load time because
	// the context already says so or, a little trickier, if it might
	// be used at load time somewhere in the future because it is
	// assigned to another variable, and that variable is allowed
	// to be used at load time.
	directly := vuc.time == VucLoadTime
	indirectly := !directly && vuc.vartype != nil &&
		vuc.vartype.Union().Contains(aclpUseLoadtime)

	if !directly && !indirectly && effPerms.Contains(aclpUse) {
		// At this point the variable is either used at run time, or the
		// time is not known.
		return
	}

	if directly || indirectly {
		// At this point the variable is used at load time although that
		// is not allowed by the permissions. The variable could be a tool
		// variable, and these tool variables have special rules.
		tool := G.ToolByVarname(ck.MkLines, varname)
		if tool != nil {

			// Whether a tool variable may be used at load time depends on
			// whether bsd.prefs.mk has been included before. That file
			// examines the tools that have been added to USE_TOOLS up to
			// this point and makes their variables available for use at
			// load time.
			if !tool.UsableAtLoadTime(ck.MkLines.Tools.SeenPrefs) {
				ck.warnVaruseToolLoadTime(varname, tool)
			}
			return
		}
	}

	if ck.MkLines.once.FirstTimeSlice("checkVarusePermissions", varname) {
		ck.warnVarusePermissions(vuc.vartype, varname, vartype, directly, indirectly)
	}
}

func (ck MkLineChecker) warnVarusePermissions(
	vucVartype *Vartype, varname string, vartype *Vartype, directly, indirectly bool) {

	mkline := ck.MkLine

	anyPerms := vartype.Union()
	if !anyPerms.Contains(aclpUse) && !anyPerms.Contains(aclpUseLoadtime) {
		mkline.Warnf("%s should not be used in any file; it is a write-only variable.", varname)
		ck.explainPermissions(varname, vartype)
		return
	}

	if indirectly {
		// Some of the guessed variables may be used at load time. But since the
		// variable type and these permissions are guessed, pkglint should not
		// issue the following warning, since it is often wrong.
		if vucVartype.Guessed() {
			return
		}

		mkline.Warnf("%s should not be used indirectly at load time (via %s).",
			varname, mkline.Varname())
		ck.explainPermissions(varname, vartype,
			"The variable on the left-hand side may be evaluated at load time,",
			"but the variable on the right-hand side should not.",
			"Because of the assignment in this line, the variable might be",
			"used indirectly at load time, before it is guaranteed to be",
			"properly initialized.")
		return
	}

	needed := aclpUse
	if directly {
		needed = aclpUseLoadtime
	}
	alternativeFiles := vartype.AlternativeFiles(needed)

	loadTimeExplanation := func() []string {
		return []string{
			"Many variables, especially lists of something, get their values incrementally.",
			"Therefore it is generally unsafe to rely on their",
			"value until it is clear that it will never change again.",
			"This point is reached when the whole package Makefile is loaded and",
			"execution of the shell commands starts; in some cases earlier.",
			"",
			"Additionally, when using the \":=\" operator, each $$ is replaced",
			"with a single $, so variables that have references to shell",
			"variables or regular expressions are modified in a subtle way."}
	}

	switch {
	case alternativeFiles == "" && directly:
		mkline.Warnf("%s should not be used at load time in any file.", varname)
		ck.explainPermissions(varname, vartype, loadTimeExplanation()...)

	case alternativeFiles == "":
		mkline.Warnf("%s should not be used in any file.", varname)
		ck.explainPermissions(varname, vartype, loadTimeExplanation()...)

	case directly:
		mkline.Warnf(
			"%s should not be used at load time in this file; "+
				"it would be ok in %s.",
			varname, alternativeFiles)
		ck.explainPermissions(varname, vartype, loadTimeExplanation()...)

	default:
		mkline.Warnf(
			"%s should not be used in this file; it would be ok in %s.",
			varname, alternativeFiles)
		ck.explainPermissions(varname, vartype)
	}
}

// warnVaruseToolLoadTime logs a warning that the tool ${varname}
// should not be used at load time.
func (ck MkLineChecker) warnVaruseToolLoadTime(varname string, tool *Tool) {
	// TODO: While using a tool by its variable name may be ok at load time,
	//  doing the same with the plain name of a tool is never ok.
	//  "VAR!= cat" is never guaranteed to call the correct cat.
	//  Even for shell builtins like echo and printf, bmake may decide
	//  to skip the shell and execute the commands via execve, which
	//  means that even echo is not a shell-builtin anymore.

	// TODO: Replace "parse time" with "load time" everywhere.

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
	ck.MkLine.Explain(
		"To use a tool at load time, it must be declared in the package",
		"Makefile by adding it to USE_TOOLS.",
		"After that, bsd.prefs.mk must be included.",
		"Adding the tool to USE_TOOLS at any later time has no effect,",
		"which means that the tool can only be used at run time.",
		"That's the rule for the package Makefiles.",
		"",
		"Since any other .mk file can be included from anywhere else, there",
		"is no guarantee that the tool is properly defined for using it at",
		"load time (see above for the tricky rules).",
		"Therefore the tools can only be used at run time,",
		"except in the package Makefile itself.")
}

// checkVarUseWords checks whether a variable use of the form ${VAR}
// or ${VAR:modifiers} is allowed in a certain context.
func (ck MkLineChecker) checkVarUseQuoting(varUse *MkVarUse, vartype *Vartype, vuc *VarUseContext) {
	if !G.Opts.WarnQuoting || vuc.quoting == VucQuotUnknown {
		return
	}

	needsQuoting := ck.MkLine.VariableNeedsQuoting(ck.MkLines, varUse, vartype, vuc)
	if needsQuoting == unknown {
		return
	}

	varname := varUse.varname
	mod := varUse.Mod()

	// In GNU configure scripts, a few variables need to be passed through
	// the :M* operator before they reach the configure scripts. Otherwise
	// the leading or trailing spaces will lead to strange caching errors
	// since the GNU configure scripts cannot handle these space characters.
	//
	// When doing checks outside a package, the :M* operator is needed for safety.
	needMstar := (G.Pkg == nil || G.Pkg.vars.Defined("GNU_CONFIGURE")) &&
		matches(varname, `^(?:.*_)?(?:CFLAGS|CPPFLAGS|CXXFLAGS|FFLAGS|LDFLAGS|LIBS)$`)

	mkline := ck.MkLine
	if mod == ":M*:Q" && !needMstar {
		if !vartype.Guessed() {
			mkline.Notef("The :M* modifier is not needed here.")
		}

	} else if needsQuoting == yes {
		modNoQ := strings.TrimSuffix(mod, ":Q")
		modNoM := strings.TrimSuffix(modNoQ, ":M*")
		correctMod := modNoM + ifelseStr(needMstar, ":M*:Q", ":Q")
		if correctMod == mod+":Q" && vuc.IsWordPart && !vartype.IsShell() {

			isSingleWordConstant := func() bool {
				if G.Pkg == nil {
					return false
				}

				varinfo := G.Pkg.redundant.vars[varname]
				if varinfo == nil || !varinfo.vari.Constant() {
					return false
				}

				value := varinfo.vari.ConstantValue()
				return len(mkline.ValueFields(value)) == 1
			}

			if vartype.List() && isSingleWordConstant() {
				// Do not warn in this special case, which typically occurs
				// for BUILD_DIRS or similar package-settable variables.

			} else if vartype.List() {
				mkline.Warnf("The list variable %s should not be embedded in a word.", varname)
				mkline.Explain(
					"When a list variable has multiple elements, this expression expands",
					"to something unexpected:",
					"",
					"Example: ${MASTER_SITE_SOURCEFORGE}directory/ expands to",
					"",
					"\thttps://mirror1.sf.net/ https://mirror2.sf.net/directory/",
					"",
					"The first URL is missing the directory.",
					"To fix this, write",
					"\t${MASTER_SITE_SOURCEFORGE:=directory/}.",
					"",
					"Example: -l${LIBS} expands to",
					"",
					"\t-llib1 lib2",
					"",
					"The second library is missing the -l.",
					"To fix this, write ${LIBS:S,^,-l,}.")
			} else {
				mkline.Warnf("The variable %s should be quoted as part of a shell word.", varname)
				mkline.Explain(
					"This variable can contain spaces or other special characters.",
					"Therefore it should be quoted by replacing ${VAR} with ${VAR:Q}.")
			}

		} else if mod != correctMod {
			if vuc.quoting == VucQuotPlain {
				fix := mkline.Autofix()
				fix.Warnf("Please use ${%s%s} instead of ${%s%s}.", varname, correctMod, varname, mod)
				fix.Explain(
					seeGuide("Echoing a string exactly as-is", "echo-literal"))
				fix.Replace("${"+varname+mod+"}", "${"+varname+correctMod+"}")
				fix.Anyway()
				fix.Apply()
			} else {
				mkline.Warnf("Please use ${%s%s} instead of ${%s%s} and make sure"+
					" the variable appears outside of any quoting characters.", varname, correctMod, varname, mod)
				mkline.Explain(
					"The :Q modifier only works reliably when it is used outside of any",
					"quoting characters like 'single' or \"double\" quotes or `backticks`.",
					"",
					"Examples:",
					"Instead of CFLAGS=\"${CFLAGS:Q}\",",
					"     write CFLAGS=${CFLAGS:Q}.",
					"Instead of 's,@CFLAGS@,${CFLAGS:Q},',",
					"     write 's,@CFLAGS@,'${CFLAGS:Q}','.",
					"",
					seeGuide("Echoing a string exactly as-is", "echo-literal"))
			}

		} else if vuc.quoting != VucQuotPlain {
			mkline.Warnf("Please move ${%s%s} outside of any quoting characters.", varname, mod)
			mkline.Explain(
				"The :Q modifier only works reliably when it is used outside of any",
				"quoting characters like 'single' or \"double\" quotes or `backticks`.",
				"",
				"Examples:",
				"Instead of CFLAGS=\"${CFLAGS:Q}\",",
				"     write CFLAGS=${CFLAGS:Q}.",
				"Instead of 's,@CFLAGS@,${CFLAGS:Q},',",
				"     write 's,@CFLAGS@,'${CFLAGS:Q}','.",
				"",
				seeGuide("Echoing a string exactly as-is", "echo-literal"))
		}
	}

	if hasSuffix(mod, ":Q") && needsQuoting != yes {
		bad := "${" + varname + mod + "}"
		good := "${" + varname + strings.TrimSuffix(mod, ":Q") + "}"

		fix := mkline.Line.Autofix()
		fix.Notef("The :Q operator isn't necessary for ${%s} here.", varname)
		fix.Explain(
			"Many variables in pkgsrc do not need the :Q operator since they",
			"are not expected to contain whitespace or other special characters.",
			"Examples for these \"safe\" variables are:",
			"",
			"\t* filenames",
			"\t* directory names",
			"\t* user and group names",
			"\t* tool names and tool paths",
			"\t* variable names",
			"\t* package names (but not dependency patterns like pkg>=1.2)")
		fix.Replace(bad, good)
		fix.Apply()
	}
}

func (ck MkLineChecker) checkVaruseDeprecated(varuse *MkVarUse) {
	varname := varuse.varname
	instead := G.Pkgsrc.Deprecated[varname]
	if instead == "" {
		instead = G.Pkgsrc.Deprecated[varnameCanon(varname)]
	}
	if instead != "" {
		ck.MkLine.Warnf("Use of %q is deprecated. %s", varname, instead)
	}
}

func (ck MkLineChecker) checkVarassignDecreasingVersions() {
	mkline := ck.MkLine
	strVersions := mkline.Fields()
	intVersions := make([]int, len(strVersions))
	for i, strVersion := range strVersions {
		iver, err := strconv.Atoi(strVersion)
		if err != nil || !(iver > 0) {
			mkline.Errorf("Value %q for %s must be a positive integer.", strVersion, mkline.Varname())
			return
		}
		intVersions[i] = iver
	}

	for i, ver := range intVersions {
		if i > 0 && ver >= intVersions[i-1] {
			mkline.Warnf("The values for %s should be in decreasing order (%d before %d).",
				mkline.Varname(), ver, intVersions[i-1])
			mkline.Explain(
				"If they aren't, it may be possible that needless versions of",
				"packages are installed.")
		}
	}
}

func (ck MkLineChecker) checkVarassign() {
	ck.checkVarassignLeft()
	ck.checkVarassignOp()
	ck.checkVarassignRight()
}

// checkVarassignLeft checks everything to the left of the assignment operator.
func (ck MkLineChecker) checkVarassignLeft() {
	varname := ck.MkLine.Varname()
	if hasPrefix(varname, "_") && !G.Infrastructure && G.Pkgsrc.vartypes.Canon(varname) == nil {
		ck.MkLine.Warnf("Variable names starting with an underscore (%s) are reserved for internal pkgsrc use.", varname)
	}

	ck.checkVarassignLeftNotUsed()
	ck.checkVarassignLeftDeprecated()
	ck.checkVarassignLeftBsdPrefs()
	if !ck.checkVarassignLeftUserSettable() {
		ck.checkVarassignLeftPermissions()
	}
	ck.checkVarassignLeftRationale()

	ck.checkTextVarUse(
		ck.MkLine.Varname(),
		NewVartype(BtVariableName, NoVartypeOptions, NewACLEntry("*", aclpAll)),
		VucLoadTime)
}

func (ck MkLineChecker) checkVarassignOp() {
	ck.checkVarassignOpShell()
}

func (ck MkLineChecker) checkVarassignOpShell() {
	mkline := ck.MkLine

	switch {
	case mkline.Op() != opAssignShell:
		return

	case mkline.VarassignComment() != "":
		return

	case mkline.Basename == "builtin.mk":
		// These are typically USE_BUILTIN.* and BUILTIN_VERSION.*.
		// Authors of builtin.mk files usually know what they're doing.
		return

	case G.Pkg == nil || G.Pkg.vars.UsedAtLoadTime(mkline.Varname()):
		return
	}

	mkline.Notef("Consider the :sh modifier instead of != for %q.", mkline.Value())
	mkline.Explain(
		"For variable assignments using the != operator, the shell command",
		"is run every time the file is parsed.",
		"In some cases this is too early, and the command may not yet be installed.",
		"In other cases the command is executed more often than necessary.",
		"Most commands don't need to be executed for \"make clean\", for example.",
		"",
		"The :sh modifier defers execution until the variable value is actually needed.",
		"On the other hand, this means the command is executed each time the variable",
		"is evaluated.",
		"",
		"Example:",
		"",
		"\tEARLY_YEAR!=    date +%Y",
		"",
		"\tLATE_YEAR_CMD=  date +%Y",
		"\tLATE_YEAR=      ${LATE_YEAR_CMD:sh}",
		"",
		"\t# or, in a single line:",
		"\tLATE_YEAR=      ${date +%Y:L:sh}",
		"",
		"To suppress this note, provide an explanation in a comment at the end",
		"of the line, or force the variable to be evaluated at load time,",
		"by using it at the right-hand side of the := operator, or in an .if",
		"or .for directive.")
}

// checkVarassignLeft checks everything to the right of the assignment operator.
func (ck MkLineChecker) checkVarassignRight() {
	mkline := ck.MkLine
	varname := mkline.Varname()
	op := mkline.Op()
	value := mkline.Value()
	comment := mkline.VarassignComment()

	if trace.Tracing {
		defer trace.Call(varname, op, value)()
	}

	ck.checkText(value)
	ck.checkVartype(varname, op, value, comment)

	ck.checkVarassignMisc()

	ck.checkVarassignRightVaruse()
}

func (ck MkLineChecker) checkVarassignLeftDeprecated() {
	varname := ck.MkLine.Varname()
	if fix := G.Pkgsrc.Deprecated[varname]; fix != "" {
		ck.MkLine.Warnf("Definition of %s is deprecated. %s", varname, fix)
	} else if fix = G.Pkgsrc.Deprecated[varnameCanon(varname)]; fix != "" {
		ck.MkLine.Warnf("Definition of %s is deprecated. %s", varname, fix)
	}
}

// checkVarassignLeftNotUsed checks whether the left-hand side of a variable
// assignment is not used. If it is unused and also doesn't have a predefined
// data type, it may be a spelling mistake.
func (ck MkLineChecker) checkVarassignLeftNotUsed() {
	varname := ck.MkLine.Varname()
	varcanon := varnameCanon(varname)

	if ck.MkLine.Op() == opAssignEval && varname == strings.ToLower(varname) {
		if trace.Tracing {
			trace.Step1("%s might be unused unless it is an argument to a procedure file.", varname)
		}
		return
	}

	if ck.MkLines.vars.UsedSimilar(varname) {
		return
	}

	if G.Pkg != nil && G.Pkg.vars.UsedSimilar(varname) {
		return
	}

	vartypes := G.Pkgsrc.vartypes
	if vartypes.DefinedExact(varname) || vartypes.DefinedExact(varcanon) {
		return
	}

	deprecated := G.Pkgsrc.Deprecated
	if deprecated[varname] != "" || deprecated[varcanon] != "" {
		return
	}

	if !ck.MkLines.once.FirstTimeSlice("defined but not used: ", varname) {
		return
	}

	ck.MkLine.Warnf("%s is defined but not used.", varname)
	ck.MkLine.Explain(
		"This might be a simple typo.",
		"",
		"If a package provides a file containing several related variables",
		"(such as module.mk, app.mk, extension.mk), that file may define",
		"variables that look unused since they are only used by other packages.",
		"These variables should be documented at the head of the file;",
		"see mk/subst.mk for an example of such a documentation comment.")
}

// checkVarassignRightVaruse checks that in a variable assignment,
// each variable used on the right-hand side of the assignment operator
// has the correct data type and quoting.
func (ck MkLineChecker) checkVarassignRightVaruse() {
	if trace.Tracing {
		defer trace.Call0()()
	}

	mkline := ck.MkLine
	op := mkline.Op()

	time := VucRunTime
	if op == opAssignEval || op == opAssignShell {
		time = VucLoadTime
	}

	vartype := G.Pkgsrc.VariableType(ck.MkLines, mkline.Varname())
	if op == opAssignShell {
		vartype = shellCommandsType
	}

	if vartype != nil && vartype.IsShell() {
		ck.checkVarassignVaruseShell(vartype, time)
	} else { // XXX: This else looks as if it should be omitted.
		ck.checkTextVarUse(ck.MkLine.Value(), vartype, time)
	}
}

func (ck MkLineChecker) checkTextVarUse(text string, vartype *Vartype, time VucTime) {
	if !contains(text, "$") {
		return
	}

	if trace.Tracing {
		defer trace.Call(vartype, time)()
	}

	tokens := NewMkParser(nil, text, false).MkTokens()
	for i, token := range tokens {
		if token.Varuse != nil {
			spaceLeft := i-1 < 0 || matches(tokens[i-1].Text, `[\t ]$`)
			spaceRight := i+1 >= len(tokens) || matches(tokens[i+1].Text, `^[\t ]`)
			isWordPart := !(spaceLeft && spaceRight)
			vuc := VarUseContext{vartype, time, VucQuotPlain, isWordPart}
			ck.CheckVaruse(token.Varuse, &vuc)
		}
	}
}

// checkVarassignVaruseShell is very similar to checkVarassignRightVaruse, they just differ
// in the way they determine isWordPart.
func (ck MkLineChecker) checkVarassignVaruseShell(vartype *Vartype, time VucTime) {
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
			wordPart := isWordPart(atoms, i)
			vuc := VarUseContext{vartype, time, atom.Quoting.ToVarUseContext(), wordPart}
			ck.CheckVaruse(varuse, &vuc)
		}
	}
}

func (ck MkLineChecker) checkVarassignMisc() {
	mkline := ck.MkLine
	varname := mkline.Varname()
	value := mkline.Value()

	if contains(value, "/etc/rc.d") && mkline.Varname() != "RPMIGNOREPATH" {
		mkline.Warnf("Please use the RCD_SCRIPTS mechanism to install rc.d scripts automatically to ${RCD_SCRIPTS_EXAMPLEDIR}.")
	}

	if varname == "PYTHON_VERSIONS_ACCEPTED" {
		ck.checkVarassignDecreasingVersions()
	}

	if mkline.VarassignComment() == "# defined" && !hasSuffix(varname, "_MK") && !hasSuffix(varname, "_COMMON") {
		mkline.Notef("Please use \"# empty\", \"# none\" or \"# yes\" instead of \"# defined\".")
		mkline.Explain(
			"The value #defined says something about the state of the variable,",
			"but not what that _means_.",
			"In some cases a variable that is defined",
			"means \"yes\", in other cases it is an empty list (which is also",
			"only the state of the variable), whose meaning could be described",
			"with \"none\".",
			"It is this meaning that should be described.")
	}

	switch varname {
	case "DIST_SUBDIR", "WRKSRC", "MASTER_SITES":
		// TODO: Replace regex with proper VarUse.
		if m, revVarname := match1(value, `\$\{(PKGNAME|PKGVERSION)[:\}]`); m {
			mkline.Warnf("%s should not be used in %s as it includes the PKGREVISION. "+
				"Please use %[1]s_NOREV instead.", revVarname, varname)
		}
	}

	if hasPrefix(varname, "SITES_") {
		mkline.Warnf("SITES_* is deprecated. Please use SITES.* instead.")
		// No autofix since it doesn't occur anymore.
	}

	if varname == "PKG_SKIP_REASON" && ck.MkLines.indentation.DependsOn("OPSYS") {
		// TODO: Provide autofix for simple cases, like ".if ${OPSYS} == SunOS".
		mkline.Notef("Consider setting NOT_FOR_PLATFORM instead of " +
			"PKG_SKIP_REASON depending on ${OPSYS}.")
	}
}

func (ck MkLineChecker) checkVarassignLeftBsdPrefs() {
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
		ck.MkLines.Tools.SeenPrefs ||
		!ck.MkLines.once.FirstTime("include bsd.prefs.mk before using ?=") {
		return
	}

	// Package-settable variables may use the ?= operator before including
	// bsd.prefs.mk in situations like the following:
	//
	//  Makefile:  LICENSE=       package-license
	//             .include "module.mk"
	//  module.mk: LICENSE?=      default-license
	//
	vartype := G.Pkgsrc.VariableType(nil, mkline.Varname())
	if vartype != nil && vartype.PackageSettable() {
		return
	}

	mkline.Warnf("Please include \"../../mk/bsd.prefs.mk\" before using \"?=\".")
	mkline.Explain(
		"The ?= operator is used to provide a default value to a variable.",
		"In pkgsrc, many variables can be set by the pkgsrc user in the",
		"mk.conf file.",
		"This file must be included explicitly.",
		"If a ?= operator appears before mk.conf has been included,",
		"it will not care about the user's preferences,",
		"which can result in unexpected behavior.",
		"",
		"The easiest way to include the mk.conf file is by including the",
		"bsd.prefs.mk file, which will take care of everything.")
}

// checkVarassignLeftUserSettable checks whether a package defines a
// variable that is marked as user-settable since it is defined in
// mk/defaults/mk.conf.
func (ck MkLineChecker) checkVarassignLeftUserSettable() bool {
	mkline := ck.MkLine
	varname := mkline.Varname()

	defaultMkline := G.Pkgsrc.UserDefinedVars.Mentioned(varname)
	if defaultMkline == nil {
		return false
	}
	defaultValue := defaultMkline.Value()

	// A few of the user-settable variables can also be set by packages.
	// That's an unfortunate situation since there is no definite source
	// of truth, but luckily only a few variables make use of it.
	vartype := G.Pkgsrc.VariableType(ck.MkLines, varname)
	if vartype.PackageSettable() {
		return true
	}

	switch {
	case mkline.VarassignComment() != "":
		// Assume that the comment contains a rationale for disabling
		// this particular check.

	case mkline.Op() == opAssignAppend:
		mkline.Warnf("Packages should not append to user-settable %s.", varname)

	case defaultValue != mkline.Value():
		mkline.Warnf(
			"Package sets user-defined %q to %q, which differs "+
				"from the default value %q from mk/defaults/mk.conf.",
			varname, mkline.Value(), defaultValue)

	case defaultMkline.IsCommentedVarassign():
		// Since the variable assignment is commented out in
		// mk/defaults/mk.conf, the package has to define it.

	default:
		mkline.Notef("Redundant definition for %s from mk/defaults/mk.conf.", varname)
		if !ck.MkLines.Tools.SeenPrefs {
			mkline.Explain(
				"Instead of defining the variable redundantly, it suffices to include",
				"../../mk/bsd.prefs.mk, which provides all user-settable variables.")
		}
	}

	return true
}

func (ck MkLineChecker) checkVartype(varname string, op MkOperator, value, comment string) {
	if trace.Tracing {
		defer trace.Call(varname, op, value, comment)()
	}

	mkline := ck.MkLine
	vartype := G.Pkgsrc.VariableType(ck.MkLines, varname)

	if op == opAssignAppend {
		// XXX: MayBeAppendedTo also depends on the current file, see checkVarusePermissions.
		// These checks may be combined.
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

	case !vartype.List():
		ck.CheckVartypeBasic(varname, vartype.basicType, op, value, comment, vartype.Guessed())

	case value == "":
		break

	default:
		words := mkline.ValueFields(value)
		for _, word := range words {
			ck.CheckVartypeBasic(varname, vartype.basicType, op, word, comment, vartype.Guessed())
		}
	}
}

// CheckVartypeBasic checks a single list element of the given type.
//
// For some variables (like `BuildlinkDepth`), `op` influences the valid values.
// The `comment` parameter comes from a variable assignment, when a part of the line is commented out.
func (ck MkLineChecker) CheckVartypeBasic(varname string, checker *BasicType, op MkOperator, value, comment string, guessed bool) {
	if trace.Tracing {
		defer trace.Call(varname, checker.name, op, value, comment, guessed)()
	}

	mkline := ck.MkLine
	valueNoVar := mkline.WithoutMakeVariables(value)
	ctx := VartypeCheck{ck.MkLines, mkline, varname, op, value, valueNoVar, comment, guessed}
	checker.checker(&ctx)
}

// checkText checks the given text (which is typically the right-hand side of a variable
// assignment or a shell command).
//
// Note: checkTextVarUse cannot be called here since it needs to know the context where it is included.
// Maybe that context should be added here as parameters.
func (ck MkLineChecker) checkText(text string) {
	if trace.Tracing {
		defer trace.Call1(text)()
	}

	ck.checkTextWrksrcDotDot(text)
	ck.checkTextRpath(text)
}

func (ck MkLineChecker) checkTextWrksrcDotDot(text string) {
	if contains(text, "${WRKSRC}/..") {
		ck.MkLine.Warnf("Building the package should take place entirely inside ${WRKSRC}, not \"${WRKSRC}/..\".")
		ck.MkLine.Explain(
			"WRKSRC should be defined so that there is no need to do anything",
			"outside of this directory.",
			"",
			"Example:",
			"",
			"\tWRKSRC=\t${WRKDIR}",
			"\tCONFIGURE_DIRS=\t${WRKSRC}/lib ${WRKSRC}/src",
			"\tBUILD_DIRS=\t${WRKSRC}/lib ${WRKSRC}/src ${WRKSRC}/cmd",
			"",
			seeGuide("Directories used during the build process", "build.builddirs"))
	}
}

// checkTextPath checks for literal -Wl,--rpath options.
//
// Note: A simple -R is not detected, as the rate of false positives is too high.
func (ck MkLineChecker) checkTextRpath(text string) {
	if m, flag := match1(text, `(-Wl,--rpath,|-Wl,-rpath-link,|-Wl,-rpath,|-Wl,-R\b)`); m {
		ck.MkLine.Warnf("Please use ${COMPILER_RPATH_FLAG} instead of %q.", flag)
	}
}

func (ck MkLineChecker) checkDirectiveCond() {
	mkline := ck.MkLine
	if trace.Tracing {
		defer trace.Call1(mkline.Args())()
	}

	p := NewMkParser(nil, mkline.Args(), false) // No emitWarnings here, see the code below.
	cond := p.MkCond()
	if !p.EOF() {
		mkline.Warnf("Invalid condition, unrecognized part: %q.", p.Rest())
		return
	}

	checkVarUse := func(varuse *MkVarUse) {
		var vartype *Vartype // TODO: Insert a better type guess here.
		vuc := VarUseContext{vartype, VucLoadTime, VucQuotPlain, false}
		ck.CheckVaruse(varuse, &vuc)
	}

	// Skip subconditions that have already been handled as part of the !(...).
	done := make(map[interface{}]bool)

	checkNotEmpty := func(not *MkCond) {
		empty := not.Empty
		if empty != nil {
			ck.checkDirectiveCondEmpty(empty, true, true, not == cond.Not)
			done[empty] = true
		}

		varUse := not.Var
		if varUse != nil {
			ck.checkDirectiveCondEmpty(varUse, false, false, not == cond.Not)
			done[varUse] = true
		}
	}

	checkEmpty := func(empty *MkVarUse) {
		if !done[empty] {
			ck.checkDirectiveCondEmpty(empty, true, false, empty == cond.Empty)
		}
	}

	checkVar := func(varUse *MkVarUse) {
		if !done[varUse] {
			ck.checkDirectiveCondEmpty(varUse, false, true, varUse == cond.Var)
		}
	}

	cond.Walk(&MkCondCallback{
		Not:           checkNotEmpty,
		Empty:         checkEmpty,
		Var:           checkVar,
		CompareVarStr: ck.checkDirectiveCondCompareVarStr,
		VarUse:        checkVarUse})
}

// checkDirectiveCondEmpty checks a condition of the form empty(VAR),
// empty(VAR:Mpattern) or ${VAR:Mpattern} in an .if directive.
func (ck MkLineChecker) checkDirectiveCondEmpty(varuse *MkVarUse, fromEmpty bool, notEmpty bool, toplevel bool) {
	varname := varuse.varname
	if matches(varname, `^\$.*:[MN]`) {
		ck.MkLine.Warnf("The empty() function takes a variable name as parameter, not a variable expression.")
		ck.MkLine.Explain(
			"Instead of empty(${VARNAME:Mpattern}), you should write either of the following:",
			"",
			"\tempty(VARNAME:Mpattern)",
			"\t${VARNAME:Mpattern} == \"\"",
			"",
			"Instead of !empty(${VARNAME:Mpattern}), you should write either of the following:",
			"",
			"\t!empty(VARNAME:Mpattern)",
			"\t${VARNAME:Mpattern}")
	}

	ck.simplifyCondition(varuse, fromEmpty, notEmpty, toplevel)
}

// simplifyCondition replaces an unnecessarily complex condition with
// a simpler condition that's still equivalent.
//
// * fromEmpty is true for the form empty(VAR...), and false for ${VAR...}.
//
// * notEmpty is true for the form !empty(VAR...), and false for empty(VAR...).
// It also applies to the ${VAR} form.
//
// * toplevel is true for ${VAR...} and false for ${VAR...} && ${VAR2...}.
func (ck MkLineChecker) simplifyCondition(varuse *MkVarUse, fromEmpty bool, notEmpty bool, toplevel bool) {

	// replace constructs the state before and after the autofix.
	// The before state is constructed to ensure that only very simple
	// patterns get replaced automatically.
	//
	// Before putting any cases involving special characters into
	// production, there need to be more tests for the edge cases.
	replace := func(varname string, m bool, pattern string) (string, string) {
		op := ifelseStr(notEmpty == m, "==", "!=")

		from := "" +
			ifelseStr(notEmpty != fromEmpty, "", "!") +
			ifelseStr(fromEmpty, "empty(", "${") +
			varname +
			ifelseStr(m, ":M", ":N") +
			pattern +
			ifelseStr(fromEmpty, ")", "}")

		to := "${" + varname + "} " + op + " " + pattern

		// TODO: Check in more cases whether the parentheses are really necessary.
		//  In a !!${VAR} expression, parentheses are necessary.
		needParen := !toplevel
		if needParen {
			to = "(" + to + ")"
		}

		return from, to
	}

	varname := varuse.varname
	modifiers := varuse.modifiers

	for _, modifier := range modifiers {
		if m, positive, pattern := modifier.MatchMatch(); m && (positive || len(modifiers) == 1) {
			ck.checkVartype(varname, opUseMatch, pattern, "")

			vartype := G.Pkgsrc.VariableType(ck.MkLines, varname)
			if matches(pattern, `^[\w-/]+$`) && vartype != nil && !vartype.List() {

				fix := ck.MkLine.Autofix()
				fix.Notef("%s should be compared using %s instead of matching against %q.",
					varname, ifelseStr(positive == notEmpty, "==", "!="), ":"+modifier.Text)
				fix.Explain(
					"This variable has a single value, not a list of values.",
					"Therefore it feels strange to apply list operators like :M and :N onto it.",
					"A more direct approach is to use the == and != operators.",
					"",
					"An entirely different case is when the pattern contains wildcards like ^, *, $.",
					"In such a case, using the :M or :N modifiers is useful and preferred.")
				fix.Replace(replace(varname, positive, pattern))
				fix.Anyway()
				fix.Apply()
			}
		}
	}
}

func (ck MkLineChecker) checkCompareVarStr(varname, op, value string) {
	ck.checkVartype(varname, opUseCompare, value, "")

	if varname == "PKGSRC_COMPILER" {
		ck.MkLine.Warnf("Use ${PKGSRC_COMPILER:%s%s} instead of the %s operator.", ifelseStr(op == "==", "M", "N"), value, op)
		ck.MkLine.Explain(
			"The PKGSRC_COMPILER can be a list of chained compilers, e.g. \"ccache distcc clang\".",
			"Therefore, comparing it using == or != leads to wrong results in these cases.")
	}
}

func (ck MkLineChecker) checkDirectiveCondCompareVarStr(varuse *MkVarUse, op string, str string) {
	varname := varuse.varname
	varmods := varuse.modifiers
	switch len(varmods) {
	case 0:
		ck.checkCompareVarStr(varname, op, str)

	case 1:
		if m, _, pattern := varmods[0].MatchMatch(); m {
			ck.checkVartype(varname, opUseMatch, pattern, "")

			// After applying the :M or :N modifier, every expression may end up empty,
			// regardless of its data type. Therefore there's no point in type-checking that case.
			if str != "" {
				ck.checkVartype(varname, opUseCompare, str, "")
			}
		}

	default:
		// This case covers ${VAR:Mfilter:O:u} or similar uses in conditions.
		// To check these properly, pkglint first needs to know the most common
		// modifiers and how they interact.
		// As of March 2019, the modifiers are not modeled.
		// The following tracing statement makes it easy to discover these cases,
		// in order to decide whether checking them is worthwhile.
		if trace.Tracing {
			trace.Stepf("checkCompareVarStr ${%s%s} %s %s",
				varuse.varname, varuse.Mod(), op, str)
		}
	}
}

// CheckRelativePkgdir checks a reference from one pkgsrc package to another.
// These references should always have the form ../../category/package.
//
// When used in DEPENDS or similar variables, these directories could theoretically
// also be relative to the pkgsrc root, which would save a few keystrokes.
// This, however, is not implemented in pkgsrc and suggestions regarding this topic
// have not been made in the last two decades on the public mailing lists.
// While being a bit redundant, the current scheme works well.
//
// When used in .include directives, the relative package directories must be written
// with the leading ../.. anyway, so the benefit might not be too big at all.
func (ck MkLineChecker) CheckRelativePkgdir(pkgdir string) {
	if trace.Tracing {
		defer trace.Call1(pkgdir)()
	}

	mkline := ck.MkLine
	ck.CheckRelativePath(pkgdir+"/Makefile", true)
	pkgdir = mkline.ResolveVarsInRelativePath(pkgdir)

	if !matches(pkgdir, `^\.\./\.\./([^./][^/]*/[^./][^/]*)$`) && !containsVarRef(pkgdir) {
		mkline.Warnf("%q is not a valid relative package directory.", pkgdir)
		mkline.Explain(
			"A relative pathname always starts with \"../../\", followed",
			"by a category, a slash and a the directory name of the package.",
			"For example, \"../../misc/screen\" is a valid relative pathname.")
	}
}

// CheckRelativePath checks a relative path that leads to the directory of another package
// or to a subdirectory thereof or a file within there.
func (ck MkLineChecker) CheckRelativePath(relativePath string, mustExist bool) {
	if trace.Tracing {
		defer trace.Call(relativePath, mustExist)()
	}

	mkline := ck.MkLine
	if !G.Wip && contains(relativePath, "/wip/") {
		mkline.Errorf("A main pkgsrc package must not depend on a pkgsrc-wip package.")
	}

	resolvedPath := mkline.ResolveVarsInRelativePath(relativePath)
	if containsVarRef(resolvedPath) {
		return
	}

	if filepath.IsAbs(resolvedPath) {
		mkline.Errorf("The path %q must be relative.", resolvedPath)
		return
	}

	abs := path.Dir(mkline.Filename) + "/" + resolvedPath
	if _, err := os.Stat(abs); err != nil {
		if mustExist && !ck.MkLines.indentation.HasExists(resolvedPath) {
			mkline.Errorf("Relative path %q does not exist.", resolvedPath)
		}
		return
	}

	switch {
	case !hasPrefix(resolvedPath, "../"):
		break

	case hasPrefix(resolvedPath, "../../mk/"):
		// From a package to the infrastructure.

	case matches(resolvedPath, `^\.\./\.\./[^./][^/]*/[^/]`):
		// From a package to another package.

	case hasPrefix(resolvedPath, "../mk/") && relpath(path.Dir(mkline.Filename), G.Pkgsrc.File(".")) == "..":
		// For category Makefiles.
		// TODO: Or from a pkgsrc wip package to wip/mk.

	case matches(resolvedPath, `^\.\./[^./][^/]*/[^/]`):
		if G.Wip && contains(resolvedPath, "/mk/") {
			mkline.Warnf("References to the pkgsrc-wip infrastructure should look like \"../../wip/mk\", not \"../mk\".")
		} else {
			mkline.Warnf("References to other packages should look like \"../../category/package\", not \"../package\".")
		}
		mkline.ExplainRelativeDirs()
	}
}
