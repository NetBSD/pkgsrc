package main

// PkgContext contains data for the package that is currently checked.
type PkgContext struct {
	pkgpath              string // e.g. "category/pkgdir"
	pkgdir               string // PKGDIR from the package Makefile
	filesdir             string // FILESDIR from the package Makefile
	patchdir             string // PATCHDIR from the package Makefile
	distinfoFile         string // DISTINFO_FILE from the package Makefile
	effectivePkgname     string // PKGNAME or DISTNAME from the package Makefile
	effectivePkgbase     string // The effective PKGNAME without the version
	effectivePkgversion  string // The version part of the effective PKGNAME
	effectivePkgnameLine *Line  // The origin of the three effective_* values
	seenBsdPrefsMk       bool   // Has bsd.prefs.mk already been included?

	vardef             map[string]*Line // varname => line
	varuse             map[string]*Line // varname => line
	bl3                map[string]*Line // buildlink3.mk name => line; contains only buildlink3.mk files that are directly included.
	plistSubstCond     map[string]bool  // varname => true; list of all variables that are used as conditionals (@comment or nothing) in PLISTs.
	included           map[string]*Line // fname => line
	seenMakefileCommon bool             // Does the package have any .includes?
}

func newPkgContext(pkgpath string) *PkgContext {
	ctx := &PkgContext{}
	ctx.pkgpath = pkgpath
	ctx.vardef = make(map[string]*Line)
	ctx.varuse = make(map[string]*Line)
	ctx.bl3 = make(map[string]*Line)
	ctx.plistSubstCond = make(map[string]bool)
	ctx.included = make(map[string]*Line)
	for varname, line := range G.globalData.userDefinedVars {
		ctx.vardef[varname] = line
	}
	return ctx
}

func (ctx *PkgContext) defineVar(line *Line, varname string) {
	if line.extra["value"] == nil {
		line.errorf("Internal pkglint error: novalue")
		return
	}
	if ctx.vardef[varname] == nil {
		ctx.vardef[varname] = line
	}
	varcanon := varnameCanon(varname)
	if ctx.vardef[varcanon] == nil {
		ctx.vardef[varcanon] = line
	}
}
func (ctx *PkgContext) varValue(varname string) (string, bool) {
	if line := ctx.vardef[varname]; line != nil {
		if value := line.extra["value"]; value != nil {
			return value.(string), true
		} else {
			line.errorf("Internal pkglint error: novalue")
		}
	}
	return "", false
}
