package main

// SubstContext records the state of a block of variable assignments
// that make up a SUBST class (see `mk/subst.mk`).
type SubstContext struct {
	id        string
	stage     string
	message   string
	files     []string
	sed       []string
	vars      []string
	filterCmd string
}

func (ctx *SubstContext) Varassign(mkline *MkLine) {
	if !G.opts.WarnExtra {
		return
	}

	varname := mkline.Varname()
	op := mkline.Op()
	value := mkline.Value()
	if varname == "SUBST_CLASSES" || hasPrefix(varname, "SUBST_CLASSES.") {
		classes := splitOnSpace(value)
		if len(classes) > 1 {
			mkline.Warn0("Please add only one class at a time to SUBST_CLASSES.")
		}
		if ctx.id != "" && ctx.id != classes[0] {
			mkline.Warn0("SUBST_CLASSES should only appear once in a SUBST block.")
		}
		ctx.id = classes[0]
		return
	}

	m, varbase, varparam := match2(varname, `^(SUBST_(?:STAGE|MESSAGE|FILES|SED|VARS|FILTER_CMD))\.([\-\w_]+)$`)
	if !m {
		if ctx.id != "" {
			mkline.Warn1("Foreign variable %q in SUBST block.", varname)
		}
		return
	}

	if ctx.id == "" {
		mkline.Warn1("SUBST_CLASSES should come before the definition of %q.", varname)
		ctx.id = varparam
	}

	if varparam != ctx.id {
		if ctx.IsComplete() {
			// XXX: This code sometimes produces weird warnings. See
			// meta-pkgs/xorg/Makefile.common 1.41 for an example.
			ctx.Finish(mkline)

			// The following assignment prevents an additional warning,
			// but from a technically viewpoint, it is incorrect.
			ctx.id = varparam
		} else {
			mkline.Warn2("Variable %q does not match SUBST class %q.", varname, ctx.id)
		}
		return
	}

	switch varbase {
	case "SUBST_STAGE":
		ctx.dup(mkline, &ctx.stage, varname, value)
	case "SUBST_MESSAGE":
		ctx.dup(mkline, &ctx.message, varname, value)
	case "SUBST_FILES":
		ctx.duplist(mkline, &ctx.files, varname, op, value)
	case "SUBST_SED":
		ctx.duplist(mkline, &ctx.sed, varname, op, value)
	case "SUBST_FILTER_CMD":
		ctx.dup(mkline, &ctx.filterCmd, varname, value)
	case "SUBST_VARS":
		ctx.duplist(mkline, &ctx.vars, varname, op, value)
	default:
		mkline.Warn1("Foreign variable %q in SUBST block.", varname)
	}
}

func (ctx *SubstContext) IsComplete() bool {
	return ctx.id != "" &&
		ctx.stage != "" &&
		len(ctx.files) != 0 &&
		(len(ctx.sed) != 0 || len(ctx.vars) != 0 || ctx.filterCmd != "")
}

func (ctx *SubstContext) Finish(mkline *MkLine) {
	if ctx.id == "" || !G.opts.WarnExtra {
		return
	}
	if ctx.stage == "" {
		mkline.Warn1("Incomplete SUBST block: %s missing.", ctx.varname("SUBST_STAGE"))
	}
	if len(ctx.files) == 0 {
		mkline.Warn1("Incomplete SUBST block: %s missing.", ctx.varname("SUBST_FILES"))
	}
	if len(ctx.sed) == 0 && len(ctx.vars) == 0 && ctx.filterCmd == "" {
		mkline.Line.Warnf("Incomplete SUBST block: %s, %s or %s missing.",
			ctx.varname("SUBST_SED"), ctx.varname("SUBST_VARS"), ctx.varname("SUBST_FILTER_CMD"))
	}
	ctx.id = ""
	ctx.stage = ""
	ctx.message = ""
	ctx.files = nil
	ctx.sed = nil
	ctx.vars = nil
	ctx.filterCmd = ""
}

func (ctx *SubstContext) varname(varbase string) string {
	switch { // prevent inlining
	}
	if ctx.id != "" {
		return varbase + "." + ctx.id
	} else {
		return varbase
	}
}

func (ctx *SubstContext) dup(mkline *MkLine, pstr *string, varname, value string) {
	if *pstr != "" {
		mkline.Warn1("Duplicate definition of %q.", varname)
	}
	*pstr = value
}

func (ctx *SubstContext) duplist(mkline *MkLine, plist *[]string, varname string, op MkOperator, value string) {
	if len(*plist) > 0 && op != opAssignAppend {
		mkline.Warn1("All but the first %q lines should use the \"+=\" operator.", varname)
	}
	*plist = append(*plist, value)
}
