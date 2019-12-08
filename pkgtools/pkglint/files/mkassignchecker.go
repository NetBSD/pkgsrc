package pkglint

import (
	"strconv"
	"strings"
)

// MkAssignChecker checks a variable assignment line in a Makefile.
type MkAssignChecker struct {
	MkLine  *MkLine
	MkLines *MkLines
}

func NewMkAssignChecker(mkLine *MkLine, mkLines *MkLines) *MkAssignChecker {
	return &MkAssignChecker{MkLine: mkLine, MkLines: mkLines}
}

func (ck *MkAssignChecker) checkVarassign() {
	ck.checkVarassignLeft()
	ck.checkVarassignOp()
	ck.checkVarassignRight()
}

// checkVarassignLeft checks everything to the left of the assignment operator.
func (ck *MkAssignChecker) checkVarassignLeft() {
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

	NewMkLineChecker(ck.MkLines, ck.MkLine).checkTextVarUse(
		ck.MkLine.Varname(),
		NewVartype(BtVariableName, NoVartypeOptions, NewACLEntry("*", aclpAll)),
		VucLoadTime)
}

// checkVarassignLeftNotUsed checks whether the left-hand side of a variable
// assignment is not used. If it is unused and also doesn't have a predefined
// data type, it may be a spelling mistake.
func (ck *MkAssignChecker) checkVarassignLeftNotUsed() {
	varname := ck.MkLine.Varname()
	varcanon := varnameCanon(varname)

	if ck.MkLine.Op() == opAssignEval && varname == strings.ToLower(varname) {
		if trace.Tracing {
			trace.Step1("%s might be unused unless it is an argument to a procedure file.", varname)
		}
		return
	}

	if ck.MkLines.vars.IsUsedSimilar(varname) {
		return
	}

	if G.Pkg != nil && G.Pkg.vars.IsUsedSimilar(varname) {
		return
	}

	vartypes := G.Pkgsrc.vartypes
	if vartypes.IsDefinedExact(varname) || vartypes.IsDefinedExact(varcanon) {
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

func (ck *MkAssignChecker) checkVarassignLeftDeprecated() {
	varname := ck.MkLine.Varname()
	if fix := G.Pkgsrc.Deprecated[varname]; fix != "" {
		ck.MkLine.Warnf("Definition of %s is deprecated. %s", varname, fix)
	} else if fix = G.Pkgsrc.Deprecated[varnameCanon(varname)]; fix != "" {
		ck.MkLine.Warnf("Definition of %s is deprecated. %s", varname, fix)
	}
}

func (ck *MkAssignChecker) checkVarassignLeftBsdPrefs() {
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
		ck.MkLines.Tools.SeenPrefs {
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
	if vartype != nil && vartype.IsPackageSettable() {
		return
	}

	if !ck.MkLines.once.FirstTime("include bsd.prefs.mk before using ?=") {
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
func (ck *MkAssignChecker) checkVarassignLeftUserSettable() bool {
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
	if vartype.IsPackageSettable() {
		return true
	}

	switch {
	case mkline.HasComment():
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

// checkVarassignLeftPermissions checks the permissions for the left-hand side
// of a variable assignment line.
//
// See checkPermissions.
func (ck *MkAssignChecker) checkVarassignLeftPermissions() {
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

	needed := aclpSet
	switch op {
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

		// XXX: explainPermissions doesn't really belong to MkVarUseChecker.
		(&MkVarUseChecker{nil, nil, ck.MkLines, mkline}).
			explainPermissions(varname, vartype)
	}
}

func (ck *MkAssignChecker) checkVarassignLeftRationale() {
	if !G.Opts.WarnExtra {
		return
	}

	mkline := ck.MkLine
	vartype := G.Pkgsrc.VariableType(ck.MkLines, mkline.Varname())
	if vartype == nil || !vartype.NeedsRationale() {
		return
	}

	if mkline.HasRationale() {
		return
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

func (ck *MkAssignChecker) checkVarassignOp() {
	ck.checkVarassignOpShell()
}

func (ck *MkAssignChecker) checkVarassignOpShell() {
	mkline := ck.MkLine

	switch {
	case mkline.Op() != opAssignShell:
		return

	case mkline.HasComment():
		return

	case mkline.Basename == "builtin.mk":
		// These are typically USE_BUILTIN.* and BUILTIN_VERSION.*.
		// Authors of builtin.mk files usually know what they're doing.
		return

	case G.Pkg == nil || G.Pkg.vars.IsUsedAtLoadTime(mkline.Varname()):
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
func (ck *MkAssignChecker) checkVarassignRight() {
	mkline := ck.MkLine
	varname := mkline.Varname()
	op := mkline.Op()
	value := mkline.Value()
	comment := condStr(mkline.HasComment(), "#", "") + mkline.Comment()

	if trace.Tracing {
		defer trace.Call(varname, op, value)()
	}

	mkLineChecker := NewMkLineChecker(ck.MkLines, ck.MkLine)
	mkLineChecker.checkText(value)
	mkLineChecker.checkVartype(varname, op, value, comment)

	ck.checkVarassignMisc()

	ck.checkVarassignRightVaruse()
}

func (ck *MkAssignChecker) checkVarassignRightCategory() {
	mkline := ck.MkLine
	if mkline.Op() != opAssign && mkline.Op() != opAssignDefault {
		return
	}

	categories := mkline.ValueFields(mkline.Value())
	actual := categories[0]
	expected := G.Pkgsrc.ToRel(mkline.Filename).DirNoClean().DirNoClean().Base()

	if expected == "wip" || actual == expected {
		return
	}

	fix := mkline.Autofix()
	fix.Warnf("The primary category should be %q, not %q.", expected, actual)
	fix.Explain(
		"The primary category of a package should be its location in the",
		"pkgsrc directory tree, to make it easy to find the package.",
		"All other categories may be added after this primary category.")
	if len(categories) > 1 && categories[1] == expected {
		fix.Replace(categories[0]+" "+categories[1], categories[1]+" "+categories[0])
	}
	fix.Apply()
}

func (ck *MkAssignChecker) checkVarassignMisc() {
	mkline := ck.MkLine
	varname := mkline.Varname()
	value := mkline.Value()

	if contains(value, "/etc/rc.d") && mkline.Varname() != "RPMIGNOREPATH" {
		mkline.Warnf("Please use the RCD_SCRIPTS mechanism to install rc.d scripts automatically to ${RCD_SCRIPTS_EXAMPLEDIR}.")
	}

	if varname == "PYTHON_VERSIONS_ACCEPTED" {
		ck.checkVarassignDecreasingVersions()
	}

	if mkline.Comment() == " defined" && !hasSuffix(varname, "_MK") && !hasSuffix(varname, "_COMMON") {
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

	ck.checkVarassignMiscRedundantInstallationDirs()
}

func (ck *MkAssignChecker) checkVarassignDecreasingVersions() {
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

func (ck *MkAssignChecker) checkVarassignMiscRedundantInstallationDirs() {
	mkline := ck.MkLine
	varname := mkline.Varname()

	switch {
	case G.Pkg == nil,
		varname != "INSTALLATION_DIRS",
		!matches(G.Pkg.vars.LastValue("AUTO_MKDIRS"), `^[Yy][Ee][Ss]$`):
		return
	}

	for _, dir := range mkline.ValueFields(mkline.Value()) {
		if NewPath(dir).IsAbs() {
			continue
		}

		rel := NewRelPathString(dir)
		if G.Pkg.Plist.Dirs[rel] != nil {
			mkline.Notef("The directory %q is redundant in %s.", rel, varname)
			mkline.Explain(
				"This package defines AUTO_MKDIR, and the directory is contained in the PLIST.",
				"Therefore it will be created anyway.")
		}
	}
}

// checkVarassignRightVaruse checks that in a variable assignment,
// each variable used on the right-hand side of the assignment operator
// has the correct data type and quoting.
func (ck *MkAssignChecker) checkVarassignRightVaruse() {
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
		mkLineChecker := NewMkLineChecker(ck.MkLines, ck.MkLine)
		mkLineChecker.checkTextVarUse(ck.MkLine.Value(), vartype, time)
	}
}

// checkVarassignVaruseShell is very similar to checkVarassignRightVaruse, they just differ
// in the way they determine isWordPart.
func (ck *MkAssignChecker) checkVarassignVaruseShell(vartype *Vartype, time VucTime) {
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
			NewMkVarUseChecker(varuse, ck.MkLines, mkline).Check(&vuc)
		}
	}
}
