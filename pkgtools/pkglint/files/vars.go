package main

type NeedsQuoting int

const (
	nqNo NeedsQuoting = iota
	nqYes
	nqDoesntMatter
	nqDontKnow
)

func variableNeedsQuoting(line *Line, varname string, vuc *VarUseContext) NeedsQuoting {
	defer tracecall("variableNeedsQuoting", varname, *vuc)()

	vartype := getVariableType(line, varname)
	if vartype == nil || vuc.vartype == nil {
		return nqDontKnow
	}

	isPlainWord := vartype.checker.IsEnum()
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
		isPlainWord = true
	}
	if isPlainWord {
		if vartype.kindOfList == lkNone {
			return nqDoesntMatter
		}
		if vartype.kindOfList == lkShell && vuc.extent != vucExtentWordpart {
			return nqNo
		}
	}

	// In .for loops, the :Q operator is always misplaced, since
	// the items are broken up at white-space, not as shell words
	// like in all other parts of make(1).
	if vuc.shellword == vucQuotFor {
		return nqNo
	}

	// Determine whether the context expects a list of shell words or not.
	wantList := vuc.vartype.isConsideredList() && (vuc.shellword == vucQuotBackt || vuc.extent != vucExtentWordpart)
	haveList := vartype.isConsideredList()

	_ = G.opts.DebugQuoting && line.debugf(
		"variableNeedsQuoting: varname=%q, context=%v, type=%v, wantList=%v, haveList=%v",
		varname, vuc, vartype, wantList, haveList)

	// A shell word may appear as part of a shell word, for example COMPILER_RPATH_FLAG.
	if vuc.extent == vucExtentWordpart && vuc.shellword == vucQuotPlain {
		if vartype.kindOfList == lkNone && vartype.checker.name == "ShellWord" {
			return nqNo
		}
	}

	// Assuming the tool definitions don't include very special characters,
	// so they can safely be used inside any quotes.
	if G.globalData.varnameToToolname[varname] != "" {
		shellword := vuc.shellword
		switch {
		case shellword == vucQuotPlain && vuc.extent != vucExtentWordpart:
			return nqNo
		case shellword == vucQuotBackt:
			return nqNo
		case shellword == vucQuotDquot || shellword == vucQuotSquot:
			return nqDoesntMatter
		}
	}

	// Variables that appear as parts of shell words generally need
	// to be quoted. An exception is in the case of backticks,
	// because the whole backticks expression is parsed as a single
	// shell word by pkglint.
	if vuc.extent == vucExtentWordpart && vuc.shellword != vucQuotBackt {
		return nqYes
	}

	// Assigning lists to lists does not require any quoting, though
	// there may be cases like "CONFIGURE_ARGS+= -libs ${LDFLAGS:Q}"
	// where quoting is necessary.
	if wantList && haveList {
		return nqDoesntMatter
	}

	if wantList != haveList {
		return nqYes
	}

	_ = G.opts.DebugQuoting && line.debugf("Don't know whether :Q is needed for %q", varname)
	return nqDontKnow
}
