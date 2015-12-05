package main

// Checks concerning single lines in Makefiles.

import (
	"strconv"
	"strings"
)

func checklineMkVardef(line *Line, varname, op string) {
	defer tracecall("checklineMkVardef", varname, op)()

	defineVar(line, varname)

	if !G.opts.WarnPerm {
		return
	}

	perms := getVariablePermissions(line, varname)
	var needed string
	switch op {
	case "=":
		needed = "s"
	case "!=":
		needed = "s"
	case "?=":
		needed = "d"
	case "+=":
		needed = "a"
	case ":=":
		needed = "s"
	}

	if !contains(perms, needed) {
		// XXX: line.warnf("Permission %q requested for %s, but only { %s } is allowed.",
		line.warnf("Permission [%s] requested for %s, but only [%s] is allowed.",
			ReadableVartypePermissions(needed), varname, ReadableVartypePermissions(perms))
		line.explain(
			"Pkglint restricts the allowed actions on variables based on the filename.",
			"",
			"The available permissions are:",
			"\tappend       append something using +=",
			"\tdefault      set a default value using ?=",
			"\tpreprocess   use a variable during preprocessing (e.g. .if, .for)",
			"\truntime      use a variable at runtime",
			"\t             (when the shell commands are run)",
			"\tset          set a variable using :=, =, !=",
			"\t             (which happens during preprocessing)",
			"",
			"A \"?\" means that pkglint doesn't know which permissions are allowed",
			"and which are not.")
	}
}

func checklineMkVaruse(line *Line, varname string, mod string, vuc *VarUseContext) {
	defer tracecall("checklineMkVaruse", line, varname, mod, *vuc)()

	vartype := getVariableType(line, varname)
	if G.opts.WarnExtra &&
		(vartype == nil || vartype.guessed == guGuessed) &&
		!varIsUsed(varname) &&
		(G.mkContext == nil || !G.mkContext.forVars[varname]) {
		line.warnf("%s is used but not defined. Spelling mistake?", varname)
	}

	if G.opts.WarnPerm {
		checklineMkVarusePerm(line, varname, vuc)
	}

	if varname == "LOCALBASE" && !G.isInfrastructure {
		checklineMkVaruseLocalbase(line)
	}

	needsQuoting := variableNeedsQuoting(line, varname, vuc)

	if vuc.shellword == vucQuotFor {
		checklineMkVaruseFor(line, varname, vartype, needsQuoting)
	}

	if G.opts.WarnQuoting && vuc.shellword != vucQuotUnknown && needsQuoting != nqDontKnow {
		checklineMkVaruseShellword(line, varname, vartype, vuc, mod, needsQuoting)
	}

	if G.globalData.userDefinedVars[varname] != nil && !G.globalData.systemBuildDefs[varname] && !G.mkContext.buildDefs[varname] {
		line.warnf("The user-defined variable %s is used but not added to BUILD_DEFS.", varname)
		line.explain(
			"When a pkgsrc package is built, many things can be configured by the",
			"pkgsrc user in the mk.conf file. All these configurations should be",
			"recorded in the binary package, so the package can be reliably rebuilt.",
			"The BUILD_DEFS variable contains a list of all these user-settable",
			"variables, so please add your variable to it, too.")
	}
}

func checklineMkVarusePerm(line *Line, varname string, vuc *VarUseContext) {
	perms := getVariablePermissions(line, varname)

	isLoadTime := false // Will the variable be used at load time?

	// Might the variable be used indirectly at load time, for example
	// by assigning it to another variable which then gets evaluated?
	isIndirect := false

	switch {
	case vuc.vartype != nil && vuc.vartype.guessed == guGuessed:
		// Don't warn about unknown variables.

	case vuc.time == vucTimeParse && !contains(perms, "p"):
		isLoadTime = true

	case vuc.vartype != nil && contains(vuc.vartype.union(), "p") && !contains(perms, "p"):
		isLoadTime = true
		isIndirect = true
	}

	if isLoadTime && !isIndirect {
		line.warnf("%s should not be evaluated at load time.", varname)
		line.explain(
			"Many variables, especially lists of something, get their values",
			"incrementally. Therefore it is generally unsafe to rely on their value",
			"until it is clear that it will never change again. This point is",
			"reached when the whole package Makefile is loaded and execution of the",
			"shell commands starts, in some cases earlier.",
			"",
			"Additionally, when using the \":=\" operator, each $$ is replaced",
			"with a single $, so variables that have references to shell variables",
			"or regular expressions are modified in a subtle way.")
	}

	if isLoadTime && isIndirect {
		line.warnf("%s should not be evaluated indirectly at load time.", varname)
		line.explain(
			"The variable on the left-hand side may be evaluated at load time, but",
			"the variable on the right-hand side may not. Due to this assignment, it",
			"might be used indirectly at load-time, when it is not guaranteed to be",
			"properly defined.")
	}

	if !contains(perms, "p") && !contains(perms, "u") {
		line.warnf("%s may not be used in this file.", varname)
	}
}

func checklineMkVaruseLocalbase(line *Line) {
	line.warnf("The LOCALBASE variable should not be used by packages.")
	line.explain(
		// from jlam via private mail.
		"Currently, LOCALBASE is typically used in these cases:",
		"",
		"(1) To locate a file or directory from another package.",
		"(2) To refer to own files after installation.",
		"",
		"In the first case, the example is:",
		"",
		"	STRLIST=        ${LOCALBASE}/bin/strlist",
		"	do-build:",
		"		cd ${WRKSRC} && ${STRLIST} *.str",
		"",
		"This should really be:",
		"",
		"	EVAL_PREFIX=    STRLIST_PREFIX=strlist",
		"	STRLIST=        ${STRLIST_PREFIX}/bin/strlist",
		"	do-build:",
		"		cd ${WRKSRC} && ${STRLIST} *.str",
		"",
		"In the second case, the example is:",
		"",
		"	CONFIGURE_ENV+= --with-datafiles=${LOCALBASE}/share/battalion",
		"",
		"This should really be:",
		"",
		"	CONFIGURE_ENV+= --with-datafiles=${PREFIX}/share/battalion")
}

func checklineMkVaruseFor(line *Line, varname string, vartype *Vartype, needsQuoting NeedsQuoting) {
	switch {
	case vartype == nil:
		// Cannot check anything here.

	case vartype.kindOfList == lkSpace:
		// Fine

	case needsQuoting == nqDoesntMatter || needsQuoting == nqNo:
		// Fine, this variable is not supposed to contain special characters.

	default:
		line.warnf("The variable %s should not be used in .for loops.", varname)
		line.explain(
			"The .for loop splits its argument at sequences of white-space, as",
			"opposed to all other places in make(1), which act like the shell.",
			"Therefore only variables that are specifically designed to match this",
			"requirement should be used here.")
	}
}

func checklineMkVaruseShellword(line *Line, varname string, vartype *Vartype, vuc *VarUseContext, mod string, needsQuoting NeedsQuoting) {

	// In GNU configure scripts, a few variables need to be
	// passed through the :M* operator before they reach the
	// configure scripts.
	//
	// When doing checks outside a package, the :M* operator is needed for safety.
	needMstar := matches(varname, `^(?:.*_)?(?:CFLAGS||CPPFLAGS|CXXFLAGS|FFLAGS|LDFLAGS|LIBS)$`) &&
		(G.pkgContext == nil || G.pkgContext.vardef["GNU_CONFIGURE"] != nil)

	strippedMod := mod
	if m, stripped := match1(mod, `(.*?)(?::M\*)?(?::Q)?$`); m {
		strippedMod = stripped
	}
	correctMod := strippedMod + ifelseStr(needMstar, ":M*:Q", ":Q")

	if mod == ":M*:Q" && !needMstar {
		line.notef("The :M* modifier is not needed here.")

	} else if mod != correctMod && needsQuoting == nqYes {
		if vuc.shellword == vucQuotPlain {
			line.warnf("Please use ${%s%s} instead of ${%s%s}.", varname, correctMod, varname, mod)
		} else {
			line.warnf("Please use ${%s%s} instead of ${%s%s} and make sure the variable appears outside of any quoting characters.", varname, correctMod, varname, mod)
		}
		line.explain(
			"See the pkgsrc guide, section \"quoting guideline\", for details.")
	}

	if hasSuffix(mod, ":Q") {
		expl := []string{
			"Many variables in pkgsrc do not need the :Q operator, since they",
			"are not expected to contain white-space or other special characters.",
			"",
			"Another case is when a variable of type ShellWord appears in a context",
			"that expects a shell word, it does not need to have a :Q operator. Even",
			"when it is concatenated with another variable, it still stays _one_ word.",
			"",
			"Example:",
			"\tWORD1=  Have\\ fun             # 1 word",
			"\tWORD2=  \"with BSD Make\"       # 1 word, too",
			"",
			"\tdemo:",
			"\t\techo ${WORD1}${WORD2} # still 1 word",
		}

		switch needsQuoting {
		case nqNo:
			line.warnf("The :Q operator should not be used for ${%s} here.", varname)
			line.explain(expl...)
		case nqDoesntMatter:
			line.notef("The :Q operator isn't necessary for ${%s} here.", varname)
			line.explain(expl...)
		}
	}
}

func checklineMkDecreasingOrder(line *Line, varname, value string) {
	defer tracecall("checklineMkDecreasingOrder", varname, value)()

	strversions := splitOnSpace(value)
	intversions := make([]int, len(strversions))
	for i, strversion := range strversions {
		iver, err := strconv.Atoi(strversion)
		if err != nil || !(iver > 0) {
			line.errorf("All values for %s must be positive integers.", varname)
			return
		}
		intversions[i] = iver
	}

	for i, ver := range intversions {
		if i > 0 && ver >= intversions[i-1] {
			line.warnf("The values for %s should be in decreasing order.", varname)
			line.explain(
				"If they aren't, it may be possible that needless versions of packages",
				"are installed.")
		}
	}
}

func checklineMkVarassign(line *Line, varname, op, value, comment string) {
	defer tracecall("checklineMkVarassign", varname, op, value)()

	varbase := varnameBase(varname)
	varcanon := varnameCanon(varname)

	checklineMkVardef(line, varname, op)

	if G.opts.WarnExtra && op == "?=" && G.pkgContext != nil && !G.pkgContext.seen_bsd_prefs_mk {
		switch varbase {
		case "BUILDLINK_PKGSRCDIR", "BUILDLINK_DEPMETHOD", "BUILDLINK_ABI_DEPENDS":
			// FIXME: What about these ones? They occur quite often.

		default:
			line.warnf("Please include \"../../mk/bsd.prefs.mk\" before using \"?=\".")
			line.explain(
				"The ?= operator is used to provide a default value to a variable. In",
				"pkgsrc, many variables can be set by the pkgsrc user in the mk.conf",
				"file. This file must be included explicitly. If a ?= operator appears",
				"before mk.conf has been included, it will not care about the user's",
				"preferences, which can result in unexpected behavior. The easiest way",
				"to include the mk.conf file is by including the bsd.prefs.mk file,",
				"which will take care of everything.")
		}
	}

	checklineMkText(line, value)
	checklineMkVartype(line, varname, op, value, comment)

	// If the variable is not used and is untyped, it may be a spelling mistake.
	if op == ":=" && varname == strings.ToLower(varname) {
		_ = G.opts.DebugUnchecked && line.debugf("%s might be unused unless it is an argument to a procedure file.", varname)

	} else if !varIsUsed(varname) {
		if vartypes := G.globalData.vartypes; vartypes[varname] != nil || vartypes[varcanon] != nil {
			// Ok
		} else if deprecated := G.globalData.deprecated; deprecated[varname] != "" || deprecated[varcanon] != "" {
			// Ok
		} else {
			line.warnf("%s is defined but not used. Spelling mistake?", varname)
		}
	}

	if matches(value, `/etc/rc\.d`) {
		line.warnf("Please use the RCD_SCRIPTS mechanism to install rc.d scripts automatically to ${RCD_SCRIPTS_EXAMPLEDIR}.")
	}

	if hasPrefix(varname, "_") && !G.isInfrastructure {
		line.warnf("Variable names starting with an underscore (%s) are reserved for internal pkgsrc use.", varname)
	}

	if varname == "PERL5_PACKLIST" && G.pkgContext != nil {
		if m, p5pkgname := match1(G.pkgContext.effectivePkgbase, `^p5-(.*)`); m {
			guess := "auto/" + strings.Replace(p5pkgname, "-", "/", -1) + "/.packlist"

			ucvalue, ucguess := strings.ToUpper(value), strings.ToUpper(guess)
			if ucvalue != ucguess && ucvalue != "${PERL5_SITEARCH}/"+ucguess {
				line.warnf("Unusual value for PERL5_PACKLIST -- %q expected.", guess)
			}
		}
	}

	if varname == "CONFIGURE_ARGS" && matches(value, `=\$\{PREFIX\}/share/kde`) {
		line.notef("Please .include \"../../meta-pkgs/kde3/kde3.mk\" instead of this line.")
		line.explain(
			"That file probably does many things automatically and consistently that",
			"this package also does. When using kde3.mk, you can probably also leave",
			"out some explicit dependencies.")
	}

	if varname == "EVAL_PREFIX" {
		if m, evalVarname := match1(value, `^([\w_]+)=`); m {

			// The variables mentioned in EVAL_PREFIX will later be
			// defined by find-prefix.mk. Therefore, they are marked
			// as known in the current file.
			G.mkContext.vardef[evalVarname] = line
		}
	}

	if varname == "PYTHON_VERSIONS_ACCEPTED" {
		checklineMkDecreasingOrder(line, varname, value)
	}

	if comment == "# defined" && !matches(varname, `.*(?:_MK|_COMMON)$`) {
		line.notef("Please use \"# empty\", \"# none\" or \"yes\" instead of \"# defined\".")
		line.explain(
			"The value #defined says something about the state of the variable, but",
			"not what that _means_. In some cases a variable that is defined means",
			"\"yes\", in other cases it is an empty list (which is also only the",
			"state of the variable), whose meaning could be described with \"none\".",
			"It is this meaning that should be described.")
	}

	if m, revvarname := match1(value, `\$\{(PKGNAME|PKGVERSION)[:\}]`); m {
		if varname == "DIST_SUBDIR" || varname == "WRKSRC" {
			line.warnf("%s should not be used in %s, as it includes the PKGREVISION. Please use %s_NOREV instead.", revvarname, varname, revvarname)
		}
	}

	if fix := G.globalData.deprecated[varname]; fix != "" {
		line.warnf("Definition of %s is deprecated. %s", varname, fix)
	} else if fix := G.globalData.deprecated[varcanon]; fix != "" {
		line.warnf("Definition of %s is deprecated. %s", varname, fix)
	}

	if hasPrefix(varname, "SITES_") {
		line.warnf("SITES_* is deprecated. Please use SITES.* instead.")
	}

	if matches(value, `^[^=]@comment`) {
		line.warnf("Please don't use @comment in %s.", varname)
		line.explain(
			"Here you are defining a variable containing @comment. As this value",
			"typically includes a space as the last character you probably also used",
			"quotes around the variable. This can lead to confusion when adding this",
			"variable to PLIST_SUBST, as all other variables are quoted using the :Q",
			"operator when they are appended. As it is hard to check whether a",
			"variable that is appended to PLIST_SUBST is already quoted or not, you",
			"should not have pre-quoted variables at all.",
			"",
			"To solve this, you should directly use PLIST_SUBST+= ${varname}=${value}",
			"or use any other variable for collecting the list of PLIST substitutions",
			"and later append that variable with PLIST_SUBST+= ${MY_PLIST_SUBST}.")
	}

	// Mark the variable as PLIST condition. This is later used in checkfile_PLIST.
	if G.pkgContext != nil && G.pkgContext.plistSubstCond != nil {
		if m, plistVarname := match1(value, `(.+)=.*@comment.*`); m {
			G.pkgContext.plistSubstCond[plistVarname] = true
		}
	}

	time := vucTimeRun
	switch op {
	case ":=", "!=":
		time = vucTimeParse
	}

	usedVars := extractUsedVariables(line, value)
	vuc := &VarUseContext{
		time,
		getVariableType(line, varname),
		vucQuotUnknown,
		vucExtentUnknown}
	for _, usedVar := range usedVars {
		checklineMkVaruse(line, usedVar, "", vuc)
	}
}

const reVarnamePlural = "^(?:" +
	".*S" +
	"|.*LIST" +
	"|.*_AWK" +
	"|.*_ENV" +
	"|.*_OVERRIDE" +
	"|.*_PREREQ" +
	"|.*_REQD" +
	"|.*_SED" +
	"|.*_SKIP" +
	"|.*_SRC" +
	"|.*_SUBST" +
	"|.*_TARGET" +
	"|.*_TMPL" +
	"|BROKEN_EXCEPT_ON_PLATFORM" +
	"|BROKEN_ON_PLATFORM" +
	"|BUILDLINK_DEPMETHOD" +
	"|BUILDLINK_LDADD" +
	"|BUILDLINK_TRANSFORM" +
	"|COMMENT" +
	"|CRYPTO" +
	"|DEINSTALL_TEMPLATE" +
	"|EVAL_PREFIX" +
	"|EXTRACT_ONLY" +
	"|FETCH_MESSAGE" +
	"|FIX_RPATH" +
	"|GENERATE_PLIST" +
	"|INSTALL_TEMPLATE" +
	"|INTERACTIVE_STAGE" +
	"|LICENSE" +
	"|MASTER_SITE_.*" +
	"|MASTER_SORT_REGEX" +
	"|NOT_FOR_COMPILER" +
	"|NOT_FOR_PLATFORM" +
	"|ONLY_FOR_COMPILER" +
	"|ONLY_FOR_PLATFORM" +
	"|PERL5_PACKLIST" +
	"|PLIST_CAT" +
	"|PLIST_PRE" +
	"|PKG_FAIL_REASON" +
	"|PKG_SKIP_REASON" +
	"|PREPEND_PATH" +
	"|PYTHON_VERSIONS_INCOMPATIBLE" +
	"|REPLACE_INTERPRETER" +
	"|REPLACE_PERL" +
	"|REPLACE_RUBY" +
	"|RESTRICTED" +
	"|SITES_.*" +
	"|TOOLS_ALIASES\\.*" +
	"|TOOLS_BROKEN" +
	"|TOOLS_CREATE" +
	"|TOOLS_GNU_MISSING" +
	"|TOOLS_NOOP" +
	")$"

func checklineMkVartype(line *Line, varname, op, value, comment string) {
	defer tracecall("checklineMkVartype", varname, op, value, comment)()

	if !G.opts.WarnTypes {
		return
	}

	varbase := varnameBase(varname)
	vartype := getVariableType(line, varname)

	if op == "+=" {
		if vartype != nil {
			if !vartype.mayBeAppendedTo() {
				line.warnf("The \"+=\" operator should only be used with lists.")
			}
		} else if !matches(varbase, `^_`) && !matches(varbase, reVarnamePlural) {
			line.warnf("As %s is modified using \"+=\", its name should indicate plural.", varname)
		}
	}

	switch {
	case vartype == nil:
		// Cannot check anything if the type is not known.
		_ = G.opts.DebugUnchecked && line.debugf("Unchecked variable assignment for %s.", varname)

	case op == "!=":
		_ = G.opts.DebugMisc && line.debugf("Use of !=: %q", value)

	case vartype.kindOfList == lkNone:
		checklineMkVartypePrimitive(line, varname, vartype.checker, op, value, comment, vartype.isConsideredList(), vartype.guessed)

	default:
		var words []string
		if vartype.kindOfList == lkSpace {
			words = splitOnSpace(value)
		} else {
			words, _ = splitIntoShellwords(line, value)
		}

		for _, word := range words {
			checklineMkVartypePrimitive(line, varname, vartype.checker, op, word, comment, true, vartype.guessed)
			if vartype.kindOfList != lkSpace {
				checklineMkShellword(line, word, true)
			}
		}
	}
}

// The `op` parameter is one of `=`, `+=`, `:=`, `!=`, `?=`, `use`, `pp-use`, ``.
// For some variables (like BuildlinkDepth), the operator influences the valid values.
// The `comment` parameter comes from a variable assignment, when a part of the line is commented out.
func checklineMkVartypePrimitive(line *Line, varname string, checker *VarChecker, op, value, comment string, isList bool, guessed Guessed) {
	defer tracecall("checklineMkVartypePrimitive", varname, op, value, comment, isList, guessed)()

	ctx := &VartypeCheck{line, varname, op, value, "", comment, isList, guessed == guGuessed}
	ctx.valueNovar = withoutMakeVariables(line, value, isList)

	checker.checker(ctx)
}

func withoutMakeVariables(line *Line, value string, qModifierAllowed bool) string {
	valueNovar := value
	for {
		var m []string
		if m, valueNovar = replaceFirst(valueNovar, `\$\{([^{}]*)\}`, ""); m != nil {
			varuse := m[1]
			if !qModifierAllowed && hasSuffix(varuse, ":Q") {
				line.warnf("The :Q operator should only be used in lists and shell commands.")
			}
		} else {
			return valueNovar
		}
	}
}

func ChecklineMkVaralign(line *Line) {
	text := line.text
	if m := regcomp(reVarassign).FindStringSubmatchIndex(text); m != nil {
		varname := text[m[2]:m[3]]
		space1 := text[m[3]:m[4]]
		op := text[m[4]:m[5]]
		align := text[m[5]:m[6]]

		if G.opts.WarnSpace && align != " " && strings.Trim(align, "\t") != "" {
			line.notef("Alignment of variable values should be done with tabs, not spaces.")
			prefix := varname + space1 + op
			alignedWidth := tabLength(prefix + align)
			tabs := ""
			for tabLength(prefix+tabs) < alignedWidth {
				tabs += "\t"
			}
			line.replace(prefix+align, prefix+tabs)
		}
	}
}
