package pkglint

import (
	"path"
	"strings"
)

// VargroupsChecker checks that the _VARGROUPS section of an infrastructure
// file matches the rest of the file content:
//
// - All variables that are used in the file should also be declared as used.
//
// - All variables that are declared to be used should actually be used.
//
// See mk/misc/show.mk, keyword _VARGROUPS.
type VargroupsChecker struct {
	mklines *MkLines
	group   string

	registered map[string]*MkLine
	userVars   map[string]*MkLine
	pkgVars    map[string]*MkLine
	sysVars    map[string]*MkLine
	defVars    map[string]*MkLine
	useVars    map[string]*MkLine
	ignVars    map[string]*MkLine
	sortedVars map[string]*MkLine
	listedVars map[string]*MkLine

	userPrivate string
	pkgPrivate  string
	sysPrivate  string
	defPrivate  string
	usePrivate  string

	undefinedVars map[string]*MkLine
	unusedVars    map[string]*MkLine
}

func NewVargroupsChecker(mklines *MkLines) *VargroupsChecker {
	ck := VargroupsChecker{mklines: mklines}
	ck.group = trimHspace(mklines.allVars.LastValue("_VARGROUPS"))
	ck.collect()
	return &ck
}

func (ck *VargroupsChecker) collect() {
	if ck.group == "" {
		return
	}

	ck.registered = make(map[string]*MkLine)
	ck.userVars = make(map[string]*MkLine)
	ck.pkgVars = make(map[string]*MkLine)
	ck.sysVars = make(map[string]*MkLine)
	ck.defVars = make(map[string]*MkLine)
	ck.useVars = make(map[string]*MkLine)
	ck.ignVars = make(map[string]*MkLine)
	ck.sortedVars = make(map[string]*MkLine)
	ck.listedVars = make(map[string]*MkLine)

	ck.mklines.ForEach(func(mkline *MkLine) {
		if mkline.IsVarassign() {
			ck.collectVarassign(mkline)
		}
	})

	ck.undefinedVars = copyStringMkLine(ck.defVars)
	ck.unusedVars = copyStringMkLine(ck.useVars)
}

func (ck *VargroupsChecker) collectVarassign(mkline *MkLine) {
	switch varnameCanon(mkline.Varname()) {
	case "_USER_VARS.*":
		ck.appendTo(ck.userVars, mkline, true, &ck.userPrivate)
	case "_PKG_VARS.*":
		ck.appendTo(ck.pkgVars, mkline, true, &ck.pkgPrivate)
	case "_SYS_VARS.*":
		ck.appendTo(ck.sysVars, mkline, true, &ck.sysPrivate)
	case "_DEF_VARS.*":
		ck.appendTo(ck.defVars, mkline, false, &ck.defPrivate)
	case "_USE_VARS.*":
		ck.appendTo(ck.useVars, mkline, false, &ck.usePrivate)
	case "_IGN_VARS.*":
		ck.appendTo(ck.ignVars, mkline, false, nil)
	case "_SORTED_VARS.*":
		ck.appendToStyle(ck.sortedVars, mkline)
	case "_LISTED_VARS.*":
		ck.appendToStyle(ck.listedVars, mkline)
	}
}

func (ck *VargroupsChecker) appendToStyle(vars map[string]*MkLine, mkline *MkLine) {
	ck.checkGroupName(mkline)

	for _, varname := range mkline.ValueFieldsLiteral() {
		vars[varname] = mkline
	}
}

func (ck *VargroupsChecker) appendTo(vars map[string]*MkLine, mkline *MkLine, publicGroup bool, firstPrivate *string) {
	ck.checkGroupName(mkline)

	for _, varname := range mkline.ValueFieldsLiteral() {
		ck.appendToVar(varname, mkline, publicGroup, vars, firstPrivate)
	}
}

func (ck *VargroupsChecker) appendToVar(varname string, mkline *MkLine, publicGroup bool, vars map[string]*MkLine, firstPrivate *string) {
	private := hasPrefix(varname, "_")
	if publicGroup && private {
		mkline.Warnf("%s should list only variables that start with a letter, not %q.",
			mkline.Varname(), varname)
	}

	if firstPrivate != nil {
		if *firstPrivate != "" && !private {
			mkline.Warnf("The public variable %s should be listed before the private variable %s.",
				varname, *firstPrivate)
		}
		if private && *firstPrivate == "" {
			*firstPrivate = varname
		}
	}

	if ck.registered[varname] != nil {
		mkline.Warnf("Duplicate variable name %s, already appeared in %s.",
			varname, mkline.RelMkLine(ck.registered[varname]))
	} else {
		ck.registered[varname] = mkline
	}

	vars[varname] = mkline
}

func (ck *VargroupsChecker) checkGroupName(mkline *MkLine) {
	varname := mkline.Varname()
	if varnameParam(varname) != ck.group {
		mkline.Warnf("Expected %s.%s, but found %q.",
			varnameBase(varname), ck.group, varnameParam(varname))
	}
}

// CheckVargroups checks that each variable that is used or defined
// somewhere in the file is also registered in the _VARGROUPS section,
// in order to make it discoverable by "bmake show-all".
//
// This check is intended mainly for infrastructure files and similar
// support files, such as lang/*/module.mk.
func (ck *VargroupsChecker) Check(mkline *MkLine) {
	if ck.group == "" {
		return
	}

	ck.checkDef(mkline)
	ck.checkUse(mkline)
}

func (ck *VargroupsChecker) checkDef(mkline *MkLine) {
	if !mkline.IsVarassignMaybeCommented() {
		return
	}

	varname := mkline.Varname()
	delete(ck.undefinedVars, varname)
	if ck.ignore(varname) {
		return
	}

	if ck.mklines.once.FirstTimeSlice("_VARGROUPS", "def", varname) {
		mkline.Warnf("Variable %s is defined but not mentioned in the _VARGROUPS section.", varname)
	}
}

func (ck *VargroupsChecker) checkUse(mkline *MkLine) {
	mkline.ForEachUsed(func(varUse *MkVarUse, _ VucTime) { ck.checkUseVar(mkline, varUse) })
}

func (ck *VargroupsChecker) checkUseVar(mkline *MkLine, varUse *MkVarUse) {
	varname := varUse.varname
	delete(ck.unusedVars, varname)

	if ck.ignore(varname) {
		return
	}

	if ck.mklines.once.FirstTimeSlice("_VARGROUPS", "use", varname) {
		mkline.Warnf("Variable %s is used but not mentioned in the _VARGROUPS section.", varname)
	}
}

func (ck *VargroupsChecker) ignore(varname string) bool {
	switch {
	case containsVarUse(varname),
		hasSuffix(varname, "_MK"),
		ck.registered[varname] != nil,
		G.Pkgsrc.Tools.ExistsVar(varname),
		ck.isVargroups(varname),
		varname == strings.ToLower(varname),
		ck.isShellCommand(varname),
		varname == ".TARGET",
		varname == "BUILD_DEFS",
		varname == "BUILD_DEFS_EFFECTS",
		varname == "PKG_FAIL_REASON",
		varname == "TOUCH_FLAGS":
		return true
	}

	for pattern := range ck.ignVars {
		matched, err := path.Match(pattern, varname)
		if err == nil && matched {
			return true
		}
	}

	return false
}

func (ck *VargroupsChecker) isShellCommand(varname string) bool {
	vartype := G.Pkgsrc.VariableType(ck.mklines, varname)
	return vartype != nil && vartype.basicType == BtShellCommand
}

func (ck *VargroupsChecker) isVargroups(varname string) bool {
	if !hasPrefix(varname, "_") {
		return false
	}

	switch varnameCanon(varname) {
	case "_VARGROUPS",
		"_USER_VARS.*",
		"_PKG_VARS.*",
		"_SYS_VARS.*",
		"_DEF_VARS.*",
		"_USE_VARS.*",
		"_IGN_VARS.*",
		"_LISTED_VARS.*",
		"_SORTED_VARS.*":
		return true
	}
	return false
}

func (ck *VargroupsChecker) Finish() {
	if ck.group == "" {
		return
	}

	forEachStringMkLine(ck.undefinedVars, func(varname string, mkline *MkLine) {
		mkline.Warnf("The variable %s is not actually defined in this file.", varname)
	})
	forEachStringMkLine(ck.unusedVars, func(varname string, mkline *MkLine) {
		mkline.Warnf("The variable %s is not actually used in this file.", varname)
	})
}
