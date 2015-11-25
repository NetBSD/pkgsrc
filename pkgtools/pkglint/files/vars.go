package main

type NeedsQuoting int

const (
	NQ_NO NeedsQuoting = iota
	NQ_YES
	NQ_DOESNT_MATTER
	NQ_DONT_KNOW
)

func variableNeedsQuoting(line *Line, varname string, vuc *VarUseContext) NeedsQuoting {
	defer tracecall("variableNeedsQuoting", varname, *vuc)()

	vartype := getVariableType(line, varname)
	if vartype == nil || vuc.vartype == nil {
		return NQ_DONT_KNOW
	}

	cond := vartype.checker.IsEnum()
	switch vartype.checker.name {
	case "DistSuffix",
		"FileMode", "Filename",
		"Identifier",
		"Option",
		"Pathname", "PkgName", "PkgOptionsVar", "PkgRevision",
		"RelativePkgDir", "RelativePkgPath",
		"UserGroupName",
		"Varname", "Version",
		"WrkdirSubdirectory":
		cond = true
	}
	if cond {
		if vartype.kindOfList == LK_NONE {
			return NQ_DOESNT_MATTER
		}
		if vartype.kindOfList == LK_SHELL && vuc.extent != VUC_EXT_WORDPART {
			return NQ_NO
		}
	}

	// In .for loops, the :Q operator is always misplaced, since
	// the items are broken up at white-space, not as shell words
	// like in all other parts of make(1).
	if vuc.shellword == VUC_SHW_FOR {
		return NQ_NO
	}

	// Determine whether the context expects a list of shell words or not.
	wantList := vuc.vartype.isConsideredList() && (vuc.shellword == VUC_SHW_BACKT || vuc.extent != VUC_EXT_WORDPART)
	haveList := vartype.isConsideredList()

	_ = G.opts.DebugQuoting && line.debugf(
		"variableNeedsQuoting: varname=%q, context=%v, type=%v, wantList=%v, haveList=%v",
		varname, vuc, vartype, wantList, haveList)

	// A shell word may appear as part of a shell word, for example COMPILER_RPATH_FLAG.
	if vuc.extent == VUC_EXT_WORDPART && vuc.shellword == VUC_SHW_PLAIN {
		if vartype.kindOfList == LK_NONE && vartype.checker.name == "ShellWord" {
			return NQ_NO
		}
	}

	// Assuming the tool definitions don't include very special characters,
	// so they can safely be used inside any quotes.
	if G.globalData.varnameToToolname[varname] != "" {
		shellword := vuc.shellword
		switch {
		case shellword == VUC_SHW_PLAIN && vuc.extent != VUC_EXT_WORDPART:
			return NQ_NO
		case shellword == VUC_SHW_BACKT:
			return NQ_NO
		case shellword == VUC_SHW_DQUOT || shellword == VUC_SHW_SQUOT:
			return NQ_DOESNT_MATTER
		}
	}

	// Variables that appear as parts of shell words generally need
	// to be quoted. An exception is in the case of backticks,
	// because the whole backticks expression is parsed as a single
	// shell word by pkglint.
	if vuc.extent == VUC_EXT_WORDPART && vuc.shellword != VUC_SHW_BACKT {
		return NQ_YES
	}

	// Assigning lists to lists does not require any quoting, though
	// there may be cases like "CONFIGURE_ARGS+= -libs ${LDFLAGS:Q}"
	// where quoting is necessary.
	if wantList && haveList {
		return NQ_DOESNT_MATTER
	}

	if wantList != haveList {
		return NQ_YES
	}

	_ = G.opts.DebugQuoting && line.debugf("Don't know whether :Q is needed for %q", varname)
	return NQ_DONT_KNOW
}
