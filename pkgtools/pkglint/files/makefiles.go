package main

import (
	"path"
	"strings"
)

const (
	reMkDependency = `^([^\s:]+(?:\s*[^\s:]+)*)(\s*):\s*([^#]*?)(?:\s*#.*)?$`
	reMkSysinclude = `^\.\s*s?include\s+<([^>]+)>\s*(?:#.*)?$`
)

func readMakefile(fname string, mainLines *[]*Line, allLines *[]*Line) bool {
	defer tracecall("readMakefile", fname)()

	fileLines := LoadNonemptyLines(fname, true)
	if fileLines == nil {
		return false
	}

	ParselinesMk(fileLines)
	isMainMakefile := len(*mainLines) == 0

	for _, line := range fileLines {
		text := line.text

		if isMainMakefile {
			*mainLines = append(*mainLines, line)
		}
		*allLines = append(*allLines, line)

		var includeFile, incDir, incBase string
		if hasPrefix(text, ".") && hasSuffix(text, "\"") {
			if m, inc := match1(text, `^\.\s*include\s+\"(.*)\"$`); m {
				includeFile = resolveVariableRefs(resolveVarsInRelativePath(inc, true))
				if containsVarRef(includeFile) {
					if !contains(fname, "/mk/") {
						line.notef("Skipping include file %q. This may result in false warnings.", includeFile)
					}
					includeFile = ""
				}
				incDir, incBase = path.Split(includeFile)
			}
		}

		if includeFile != "" {
			if path.Base(fname) != "buildlink3.mk" {
				if m, bl3File := match1(includeFile, `^\.\./\.\./(.*)/buildlink3\.mk$`); m {
					G.pkgContext.bl3[bl3File] = line
					_ = G.opts.DebugMisc && line.debugf("Buildlink3 file in package: %q", bl3File)
				}
			}
		}

		if includeFile != "" && G.pkgContext.included[includeFile] == nil {
			G.pkgContext.included[includeFile] = line

			if matches(includeFile, `^\.\./[^./][^/]*/[^/]+`) {
				line.warnf("References to other packages should look like \"../../category/package\", not \"../package\".")
				explainRelativeDirs(line)
			}

			if !hasPrefix(incDir, "../../mk/") && incBase != "buildlink3.mk" && incBase != "builtin.mk" && incBase != "options.mk" {
				_ = G.opts.DebugInclude && line.debugf("Including %q sets seenMakefileCommon.", includeFile)
				G.pkgContext.seenMakefileCommon = true
			}

			if !contains(incDir, "/mk/") {
				dirname, _ := path.Split(fname)
				dirname = cleanpath(dirname)

				// Only look in the directory relative to the
				// current file and in the current working directory.
				// Pkglint doesn’t have an include dir list, like make(1) does.
				if !fileExists(dirname + "/" + includeFile) {
					dirname = G.currentDir
				}
				if !fileExists(dirname + "/" + includeFile) {
					line.errorf("Cannot read %q.", dirname+"/"+includeFile)
					return false
				}

				_ = G.opts.DebugInclude && line.debugf("Including %q.", dirname+"/"+includeFile)
				lengthBeforeInclude := len(*allLines)
				if !readMakefile(dirname+"/"+includeFile, mainLines, allLines) {
					return false
				}

				if incBase == "Makefile.common" && incDir != "" {
					makefileCommonLines := (*allLines)[lengthBeforeInclude:]
					checkForUsedComment(makefileCommonLines, relpath(G.globalData.pkgsrcdir, fname))
				}
			}
		}

		if line.extra["is_varassign"] != nil {
			varname, op, value := line.extra["varname"].(string), line.extra["op"].(string), line.extra["value"].(string)

			if op != "?=" || G.pkgContext.vardef[varname] == nil {
				_ = G.opts.DebugMisc && line.debugf("varassign(%q, %q, %q)", varname, op, value)
				G.pkgContext.vardef[varname] = line
			}
		}
	}

	return true
}

func checkForUsedComment(lines []*Line, relativeName string) {
	if len(lines) < 3 {
		return
	}

	expected := "# used by " + relativeName
	for _, line := range lines {
		if line.text == expected {
			return
		}
	}

	i := 0
	for i < 2 && matches(lines[i].text, `^\s*#(.*)$`) {
		i++
	}

	insertLine := lines[i]
	insertLine.warnf("Please add a line %q here.", expected)
	insertLine.explain(
		"Since Makefile.common files usually don't have any comments and",
		"therefore not a clearly defined interface, they should at least contain",
		"references to all files that include them, so that it is easier to see",
		"what effects future changes may have.",
		"",
		"If there are more than five packages that use a Makefile.common,",
		"you should think about giving it a proper name (maybe plugin.mk) and",
		"documenting its interface.")
	insertLine.insertBefore(expected)
	saveAutofixChanges(lines)
}

func resolveVarsInRelativePath(relpath string, adjustDepth bool) string {

	tmp := relpath
	tmp = strings.Replace(tmp, "${PKGSRCDIR}", G.curPkgsrcdir, -1)
	tmp = strings.Replace(tmp, "${.CURDIR}", ".", -1)
	tmp = strings.Replace(tmp, "${.PARSEDIR}", ".", -1)
	tmp = strings.Replace(tmp, "${LUA_PKGSRCDIR}", "../../lang/lua52", -1)
	tmp = strings.Replace(tmp, "${PHPPKGSRCDIR}", "../../lang/php54", -1)
	tmp = strings.Replace(tmp, "${SUSE_DIR_PREFIX}", "suse100", -1)
	tmp = strings.Replace(tmp, "${PYPKGSRCDIR}", "../../lang/python27", -1)
	if G.pkgContext != nil {
		tmp = strings.Replace(tmp, "${FILESDIR}", G.pkgContext.filesdir, -1)
	}
	if G.pkgContext != nil {
		tmp = strings.Replace(tmp, "${PKGDIR}", G.pkgContext.pkgdir, -1)
	}

	if adjustDepth {
		if m, pkgpath := match1(tmp, `^\.\./\.\./([^.].*)$`); m {
			tmp = G.curPkgsrcdir + "/" + pkgpath
		}
	}

	_ = G.opts.DebugMisc && dummyLine.debugf("resolveVarsInRelativePath: %q => %q", relpath, tmp)
	return tmp
}

func parselineMk(line *Line) {
	defer tracecall("parselineMk", line.text)()

	text := line.text

	if m, varname, op, value, comment := matchVarassign(text); m {
		value = strings.Replace(value, "\\#", "#", -1)
		varparam := varnameParam(varname)

		line.extra["is_varassign"] = true
		line.extra["varname"] = varname
		line.extra["varcanon"] = varnameCanon(varname)
		line.extra["varparam"] = varparam
		line.extra["op"] = op
		line.extra["value"] = value
		line.extra["comment"] = comment
		return
	}

	if hasPrefix(text, "\t") {
		line.extra["is_shellcmd"] = true
		line.extra["shellcmd"] = text[1:]
		return
	}

	if index := strings.IndexByte(text, '#'); index != -1 && strings.TrimSpace(text[:index]) == "" {
		line.extra["is_comment"] = true
		line.extra["comment"] = text[index+1:]
		return
	}

	if strings.TrimSpace(text) == "" {
		line.extra["is_empty"] = true
		return
	}

	if m, indent, directive, args := match3(text, reMkCond); m {
		line.extra["is_cond"] = true
		line.extra["indent"] = indent
		line.extra["directive"] = directive
		line.extra["args"] = args
		return
	}

	if m, _, includefile := match2(text, reMkInclude); m {
		line.extra["is_include"] = true
		line.extra["includefile"] = includefile
		return
	}

	if m, includefile, comment := match2(text, reMkSysinclude); m {
		line.extra["is_sysinclude"] = true
		line.extra["includefile"] = includefile
		line.extra["comment"] = comment
		return
	}

	if m, targets, whitespace, sources := match3(text, reMkDependency); m {
		line.extra["is_dependency"] = true
		line.extra["targets"] = targets
		line.extra["sources"] = sources
		if whitespace != "" {
			line.warnf("Space before colon in dependency line.")
		}
		return
	}

	if matches(text, `^(<<<<<<<|=======|>>>>>>>)`) {
		return
	}

	line.errorf("Unknown Makefile line format.")
}

func ParselinesMk(lines []*Line) {
	for _, line := range lines {
		parselineMk(line)
	}
}

func checklineMkText(line *Line, text string) {
	defer tracecall("checklineMkText", text)()

	if m, varname := match1(text, `^(?:[^#]*[^\$])?\$(\w+)`); m {
		line.warnf("$%s is ambiguous. Use ${%s} if you mean a Makefile variable or $$%s if you mean a shell variable.", varname, varname, varname)
	}

	if line.lines == "1" {
		checklineRcsid(line, `# `, "# ")
	}

	if contains(text, "${WRKSRC}/../") {
		line.warnf("Using \"${WRKSRC}/..\" is conceptually wrong. Please use a combination of WRKSRC, CONFIGURE_DIRS and BUILD_DIRS instead.")
		line.explain(
			"You should define WRKSRC such that all of CONFIGURE_DIRS, BUILD_DIRS",
			"and INSTALL_DIRS are subdirectories of it.")
	}

	// Note: A simple -R is not detected, as the rate of false positives is too high.
	if m, flag := match1(text, `\b(-Wl,--rpath,|-Wl,-rpath-link,|-Wl,-rpath,|-Wl,-R)\b`); m {
		line.warnf("Please use ${COMPILER_RPATH_FLAG} instead of %q.", flag)
	}

	rest := text
	for {
		m, r := replaceFirst(rest, `(?:^|[^$])\$\{([-A-Z0-9a-z_]+)(\.[\-0-9A-Z_a-z]+)?(?::[^\}]+)?\}`, "")
		if m == nil {
			break
		}
		rest = r

		varbase, varext := m[1], m[2]
		varname := varbase + varext
		varcanon := varnameCanon(varname)
		instead := G.globalData.deprecated[varname]
		if instead == "" {
			instead = G.globalData.deprecated[varcanon]
		}
		if instead != "" {
			line.warnf("Use of %q is deprecated. %s", varname, instead)
		}
	}
}

func ChecklinesMk(lines []*Line) {
	defer tracecall("ChecklinesMk", lines[0].fname)()

	allowedTargets := make(map[string]bool)
	substcontext := new(SubstContext)

	ctx := newMkContext()
	G.mkContext = ctx
	defer func() { G.mkContext = nil }()

	determineUsedVariables(lines)

	prefixes := splitOnSpace("pre do post")
	actions := splitOnSpace("fetch extract patch tools wrapper configure build test install package clean")
	for _, prefix := range prefixes {
		for _, action := range actions {
			allowedTargets[prefix+"-"+action] = true
		}
	}

	// In the first pass, all additions to BUILD_DEFS and USE_TOOLS
	// are collected to make the order of the definitions irrelevant.

	for _, line := range lines {
		if line.extra["is_varassign"] == nil {
			continue
		}

		varcanon := line.extra["varcanon"].(string)
		switch varcanon {
		case "BUILD_DEFS", "PKG_GROUPS_VARS", "PKG_USERS_VARS":
			for _, varname := range splitOnSpace(line.extra["value"].(string)) {
				G.mkContext.buildDefs[varname] = true
				_ = G.opts.DebugMisc && line.debugf("%q is added to BUILD_DEFS.", varname)
			}

		case "PLIST_VARS":
			for _, id := range splitOnSpace(line.extra["value"].(string)) {
				G.mkContext.plistVars["PLIST."+id] = true
				_ = G.opts.DebugMisc && line.debugf("PLIST.%s is added to PLIST_VARS.", id)
				useVar(line, "PLIST."+id)
			}

		case "USE_TOOLS":
			for _, tool := range splitOnSpace(line.extra["value"].(string)) {
				tool = strings.Split(tool, ":")[0]
				G.mkContext.tools[tool] = true
				_ = G.opts.DebugMisc && line.debugf("%s is added to USE_TOOLS.", tool)
			}

		case "SUBST_VARS.*":
			for _, svar := range splitOnSpace(line.extra["value"].(string)) {
				useVar(line, varnameCanon(svar))
				_ = G.opts.DebugMisc && line.debugf("varuse %s", svar)
			}

		case "OPSYSVARS":
			for _, osvar := range splitOnSpace(line.extra["value"].(string)) {
				useVar(line, osvar+".*")
				defineVar(line, osvar)
			}
		}
	}

	// In the second pass, the actual checks are done.

	checklineRcsid(lines[0], `#\s+`, "# ")

	for _, line := range lines {
		text := line.text

		checklineTrailingWhitespace(line)

		if line.extra["is_empty"] != nil {
			substcontext.Finish(line)

		} else if line.extra["is_comment"] != nil {
			// No further checks.

		} else if m, varname, op, value, comment := matchVarassign(text); m {
			ChecklineMkVaralign(line)
			checklineMkVarassign(line, varname, op, value, comment)
			substcontext.Varassign(line, varname, op, value)

		} else if hasPrefix(text, "\t") {
			checklineMkShellcmd(line, text[1:])

		} else if m, include, includefile := match2(text, reMkInclude); m {
			_ = G.opts.DebugInclude && line.debugf("includefile=%s", includefile)
			checklineRelativePath(line, includefile, include == "include")

			if hasSuffix(includefile, "../Makefile") {
				line.errorf("Other Makefiles must not be included directly.")
				line.explain(
					"If you want to include portions of another Makefile, extract",
					"the common parts and put them into a Makefile.common. After",
					"that, both this one and the other package should include the",
					"Makefile.common.")
			}

			if includefile == "../../mk/bsd.prefs.mk" {
				if path.Base(line.fname) == "buildlink3.mk" {
					line.notef("For efficiency reasons, please include bsd.fast.prefs.mk instead of bsd.prefs.mk.")
				}
				if G.pkgContext != nil {
					G.pkgContext.seen_bsd_prefs_mk = true
				}
			} else if includefile == "../../mk/bsd.fast.prefs.mk" {
				if G.pkgContext != nil {
					G.pkgContext.seen_bsd_prefs_mk = true
				}
			}

			if matches(includefile, `/x11-links/buildlink3\.mk$`) {
				line.errorf("%s must not be included directly. Include \"../../mk/x11.buildlink3.mk\" instead.", includefile)
			}
			if matches(includefile, `/jpeg/buildlink3\.mk$`) {
				line.errorf("%s must not be included directly. Include \"../../mk/jpeg.buildlink3.mk\" instead.", includefile)
			}
			if matches(includefile, `/intltool/buildlink3\.mk$`) {
				line.warnf("Please write \"USE_TOOLS+= intltool\" instead of this line.")
			}
			if m, dir := match1(includefile, `(.*)/builtin\.mk$`); m {
				line.errorf("%s must not be included directly. Include \"%s/buildlink3.mk\" instead.", includefile, dir)
			}

		} else if matches(text, reMkSysinclude) {

		} else if m, indent, directive, args := match3(text, reMkCond); m {
			if matches(directive, `^(?:endif|endfor|elif|else)$`) {
				if len(ctx.indentation) > 1 {
					ctx.popIndent()
				} else {
					line.errorf("Unmatched .%s.", directive)
				}
			}

			// Check the indentation
			if indent != strings.Repeat(" ", ctx.indentDepth()) {
				_ = G.opts.WarnSpace && line.notef("This directive should be indented by %d spaces.", ctx.indentDepth())
			}

			if directive == "if" && matches(args, `^!defined\([\w]+_MK\)$`) {
				ctx.pushIndent(ctx.indentDepth())

			} else if matches(directive, `^(?:if|ifdef|ifndef|for|elif|else)$`) {
				ctx.pushIndent(ctx.indentDepth() + 2)
			}

			reDirectivesWithArgs := `^(?:if|ifdef|ifndef|elif|for|undef)$`
			if matches(directive, reDirectivesWithArgs) && args == "" {
				line.errorf("\".%s\" requires arguments.", directive)

			} else if !matches(directive, reDirectivesWithArgs) && args != "" {
				line.errorf("\".%s\" does not take arguments.", directive)

				if directive == "else" {
					line.notef("If you meant \"else if\", use \".elif\".")
				}

			} else if directive == "if" || directive == "elif" {
				checklineMkIf(line, args)

			} else if directive == "ifdef" || directive == "ifndef" {
				if matches(args, `\s`) {
					line.errorf("The \".%s\" directive can only handle _one_ argument.", directive)
				} else {
					line.warnf("The \".%s\" directive is deprecated. Please use \".if %sdefined(%s)\" instead.",
						directive, ifelseStr(directive == "ifdef", "", "!"), args)
				}

			} else if directive == "for" {
				if m, vars, values := match2(args, `^(\S+(?:\s*\S+)*?)\s+in\s+(.*)$`); m {
					for _, forvar := range splitOnSpace(vars) {
						if !G.isInfrastructure && hasPrefix(forvar, "_") {
							line.warnf("Variable names starting with an underscore (%s) are reserved for internal pkgsrc use.", forvar)
						}

						if matches(forvar, `^[_a-z][_a-z0-9]*$`) {
							// Fine.
						} else if matches(forvar, `[A-Z]`) {
							line.warnf(".for variable names should not contain uppercase letters.")
						} else {
							line.errorf("Invalid variable name %q.", forvar)
						}

						ctx.forVars[forvar] = true
					}

					// Check if any of the value's types is not guessed.
					guessed := guGuessed
					for _, value := range splitOnSpace(values) {
						if m, vname := match1(value, `^\$\{(.*)\}`); m {
							vartype := getVariableType(line, vname)
							if vartype != nil && !vartype.guessed {
								guessed = guNotGuessed
							}
						}
					}

					forLoopType := &Vartype{lkSpace, CheckvarUnchecked, []AclEntry{{"*", "pu"}}, guessed}
					forLoopContext := &VarUseContext{
						vucTimeParse,
						forLoopType,
						vucQuotFor,
						vucExtentWord,
					}
					for _, fvar := range extractUsedVariables(line, values) {
						checklineMkVaruse(line, fvar, "", forLoopContext)
					}
				}

			} else if directive == "undef" && args != "" {
				for _, uvar := range splitOnSpace(args) {
					if ctx.forVars[uvar] {
						line.notef("Using \".undef\" after a \".for\" loop is unnecessary.")
					}
				}
			}

		} else if m, targets, _, dependencies := match3(text, reMkDependency); m {
			_ = G.opts.DebugMisc && line.debugf("targets=%q, dependencies=%q", targets, dependencies)
			ctx.target = targets

			for _, source := range splitOnSpace(dependencies) {
				if source == ".PHONY" {
					for _, target := range splitOnSpace(targets) {
						allowedTargets[target] = true
					}
				}
			}

			for _, target := range splitOnSpace(targets) {
				if target == ".PHONY" {
					for _, dep := range splitOnSpace(dependencies) {
						allowedTargets[dep] = true
					}

				} else if target == ".ORDER" {
					// TODO: Check for spelling mistakes.

				} else if !allowedTargets[target] {
					line.warnf("Unusual target %q.", target)
					line.explain(
						"If you want to define your own targets, you can \"declare\"",
						"them by inserting a \".PHONY: my-target\" line before this line. This",
						"will tell make(1) to not interpret this target's name as a filename.")
				}
			}

		} else if m, directive := match1(text, `^\.\s*(\S*)`); m {
			line.errorf("Unknown directive \".%s\".", directive)

		} else if hasPrefix(text, " ") {
			line.warnf("Makefile lines should not start with space characters.")
			line.explain(
				"If you want this line to contain a shell program, use a tab",
				"character for indentation. Otherwise please remove the leading",
				"white-space.")

		} else {
			_ = G.opts.DebugMisc && line.debugf("Unknown line format")
		}
	}
	substcontext.Finish(lines[len(lines)-1])

	checklinesTrailingEmptyLines(lines)

	if len(ctx.indentation) != 1 {
		lines[len(lines)-1].errorf("Directive indentation is not 0, but %d.", ctx.indentDepth())
	}

	G.mkContext = nil
}
