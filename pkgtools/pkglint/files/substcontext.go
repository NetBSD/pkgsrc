package main

// Records the state of a block of variable assignments that make up a SUBST
// class (see mk/subst.mk).
type SubstContext struct {
	id        string
	stage     string
	message   string
	files     []string
	sed       []string
	vars      []string
	filterCmd string
}

func (self *SubstContext) Varassign(line *Line, varname, op, value string) {
	if !G.opts.WarnExtra {
		return
	}

	if varname == "SUBST_CLASSES" {
		classes := splitOnSpace(value)
		if len(classes) > 1 {
			line.warnf("Please add only one class at a time to SUBST_CLASSES.")
		}
		if self.id != "" {
			line.warnf("SUBST_CLASSES should only appear once in a SUBST block.")
		}
		self.id = classes[0]
		return
	}

	m, varbase, varparam := match2(varname, `^(SUBST_(?:STAGE|MESSAGE|FILES|SED|VARS|FILTER_CMD))\.([\-\w_]+)$`)
	if !m {
		if self.id != "" {
			line.warnf("Foreign variable %q in SUBST block.", varname)
		}
		return
	}

	if self.id == "" {
		line.warnf("SUBST_CLASSES should come before the definition of %q.", varname)
		self.id = varparam
	}

	if varparam != self.id {
		if self.IsComplete() {
			// XXX: This code sometimes produces weird warnings. See
			// meta-pkgs/xorg/Makefile.common 1.41 for an example.
			self.Finish(line)

			// The following assignment prevents an additional warning,
			// but from a technically viewpoint, it is incorrect.
			self.id = varparam
		} else {
			line.warnf("Variable %q does not match SUBST class %q.", varname, self.id)
		}
		return
	}

	switch varbase {
	case "SUBST_STAGE":
		self.dup(line, &self.stage, varname, value)
	case "SUBST_MESSAGE":
		self.dup(line, &self.message, varname, value)
	case "SUBST_FILES":
		self.duplist(line, &self.files, varname, op, value)
	case "SUBST_SED":
		self.duplist(line, &self.sed, varname, op, value)
	case "SUBST_FILTER_CMD":
		self.dup(line, &self.filterCmd, varname, value)
	case "SUBST_VARS":
		self.duplist(line, &self.vars, varname, op, value)
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

func (self *SubstContext) Finish(line *Line) {
	if self.id == "" || !G.opts.WarnExtra {
		return
	}
	if self.stage == "" {
		line.warnf("Incomplete SUBST block: %s missing.", self.varname("SUBST_STAGE"))
	}
	if len(self.files) == 0 {
		line.warnf("Incomplete SUBST block: %s missing.", self.varname("SUBST_FILES"))
	}
	if len(self.sed) == 0 && len(self.vars) == 0 && self.filterCmd == "" {
		line.warnf("Incomplete SUBST block: %s, %s or %s missing.",
			self.varname("SUBST_SED"), self.varname("SUBST_VARS"), self.varname("SUBST_FILTER_CMD"))
	}
	self.id = ""
	self.stage = ""
	self.message = ""
	self.files = nil
	self.sed = nil
	self.vars = nil
	self.filterCmd = ""
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
