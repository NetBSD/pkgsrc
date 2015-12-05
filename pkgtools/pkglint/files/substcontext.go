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

	line:=mkline.line
	varname := line.extra["varname"].(string)
	op := line.extra["op"].(string)
	value := line.extra["value"].(string)
	if varname == "SUBST_CLASSES" {
		classes := splitOnSpace(value)
		if len(classes) > 1 {
			line.warnf("Please add only one class at a time to SUBST_CLASSES.")
		}
		if ctx.id != "" {
			line.warnf("SUBST_CLASSES should only appear once in a SUBST block.")
		}
		ctx.id = classes[0]
		return
	}

	m, varbase, varparam := match2(varname, `^(SUBST_(?:STAGE|MESSAGE|FILES|SED|VARS|FILTER_CMD))\.([\-\w_]+)$`)
	if !m {
		if ctx.id != "" {
			line.warnf("Foreign variable %q in SUBST block.", varname)
		}
		return
	}

	if ctx.id == "" {
		line.warnf("SUBST_CLASSES should come before the definition of %q.", varname)
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
			line.warnf("Variable %q does not match SUBST class %q.", varname, ctx.id)
		}
		return
	}

	switch varbase {
	case "SUBST_STAGE":
		ctx.dup(line, &ctx.stage, varname, value)
	case "SUBST_MESSAGE":
		ctx.dup(line, &ctx.message, varname, value)
	case "SUBST_FILES":
		ctx.duplist(line, &ctx.files, varname, op, value)
	case "SUBST_SED":
		ctx.duplist(line, &ctx.sed, varname, op, value)
	case "SUBST_FILTER_CMD":
		ctx.dup(line, &ctx.filterCmd, varname, value)
	case "SUBST_VARS":
		ctx.duplist(line, &ctx.vars, varname, op, value)
	default:
		line.warnf("Foreign variable %q in SUBST block.", varname)
	}
}

func (ctx *SubstContext) IsComplete() bool {
	return ctx.id != "" &&
		ctx.stage != "" &&
		len(ctx.files) != 0 &&
		(len(ctx.sed) != 0 || len(ctx.vars) != 0 || ctx.filterCmd != "")
}

func (ctx *SubstContext) Finish(mkline *MkLine) {
	line:=mkline.line
	if ctx.id == "" || !G.opts.WarnExtra {
		return
	}
	if ctx.stage == "" {
		line.warnf("Incomplete SUBST block: %s missing.", ctx.varname("SUBST_STAGE"))
	}
	if len(ctx.files) == 0 {
		line.warnf("Incomplete SUBST block: %s missing.", ctx.varname("SUBST_FILES"))
	}
	if len(ctx.sed) == 0 && len(ctx.vars) == 0 && ctx.filterCmd == "" {
		line.warnf("Incomplete SUBST block: %s, %s or %s missing.",
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
	if ctx.id != "" {
		return varbase + "." + ctx.id
	} else {
		return varbase
	}
}

func (ctx *SubstContext) dup(line *Line, pstr *string, varname, value string) {
	if *pstr != "" {
		line.warnf("Duplicate definition of %q.", varname)
	}
	*pstr = value
}

func (ctx *SubstContext) duplist(line *Line, plist *[]string, varname, op, value string) {
	if len(*plist) > 0 && op != "+=" {
		line.warnf("All but the first %q lines should use the \"+=\" operator.", varname)
	}
	*plist = append(*plist, value)
}
