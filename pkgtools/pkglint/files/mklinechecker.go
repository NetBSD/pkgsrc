package pkglint

import (
	"netbsd.org/pkglint/textproc"
	"strings"
)

// MkLineChecker provides checks for a single line from a Makefile fragment.
type MkLineChecker struct {
	MkLines *MkLines
	MkLine  *MkLine
}

func NewMkLineChecker(mkLines *MkLines, mkLine *MkLine) MkLineChecker {
	return MkLineChecker{MkLines: mkLines, MkLine: mkLine}
}

func (ck MkLineChecker) Check() {
	mkline := ck.MkLine

	LineChecker{mkline.Line}.CheckTrailingWhitespace()
	LineChecker{mkline.Line}.CheckValidCharacters()
	ck.checkEmptyContinuation()

	switch {
	case mkline.IsVarassign():
		NewMkAssignChecker(mkline, ck.MkLines).check()

	case mkline.IsShellCommand():
		ck.checkShellCommand()

	case mkline.IsComment():
		ck.checkComment()

	case mkline.IsInclude():
		ck.checkInclude()
	}
}

func (ck MkLineChecker) checkEmptyContinuation() {
	if !ck.MkLine.IsMultiline() {
		return
	}

	line := ck.MkLine.Line
	lastRawIndex := len(line.raw) - 1
	if line.raw[lastRawIndex].Orig() == "" {
		lastLine := NewLine(line.Filename(), line.Location.Lineno(lastRawIndex), "", line.raw[lastRawIndex])
		lastLine.Warnf("This line looks empty but continues the previous line.")
		lastLine.Explain(
			"This line should be indented like other continuation lines,",
			"and to make things clear, should be a comment line.")
	}
}

func (ck MkLineChecker) checkTextVarUse(text string, vartype *Vartype, time VucTime) {
	if !contains(text, "$") {
		return
	}

	if trace.Tracing {
		defer trace.Call(vartype, time)()
	}

	tokens, _ := NewMkLexer(text, nil).MkTokens()
	for i, token := range tokens {
		if token.Varuse == nil {
			continue
		}
		spaceLeft := i-1 < 0 || matches(tokens[i-1].Text, `[\t ]$`)
		spaceRight := i+1 >= len(tokens) || matches(tokens[i+1].Text, `^[\t ]`)
		isWordPart := !(spaceLeft && spaceRight)
		vuc := VarUseContext{vartype, time, VucQuotPlain, isWordPart}
		NewMkVarUseChecker(token.Varuse, ck.MkLines, ck.MkLine).Check(&vuc)
	}
}

// checkText checks the given text (which is typically the right-hand side of a variable
// assignment or a shell command).
//
// Note: checkTextVarUse cannot be called here since it needs to know the context where it is included.
// Maybe that context should be added here as parameters.
func (ck MkLineChecker) checkText(text string) {
	if trace.Tracing {
		defer trace.Call1(text)()
	}

	ck.checkTextWrksrcDotDot(text)
	ck.checkTextRpath(text)
}

func (ck MkLineChecker) checkTextWrksrcDotDot(text string) {
	if contains(text, "${WRKSRC}/..") {
		ck.MkLine.Warnf("Building the package should take place entirely inside ${WRKSRC}, not \"${WRKSRC}/..\".")
		ck.MkLine.Explain(
			"WRKSRC should be defined so that there is no need to do anything",
			"outside of this directory.",
			"",
			"Example:",
			"",
			"\tWRKSRC=\t\t${WRKDIR}",
			"\tCONFIGURE_DIRS=\t${WRKSRC}/lib ${WRKSRC}/src",
			"\tBUILD_DIRS=\t${WRKSRC}/lib ${WRKSRC}/src ${WRKSRC}/cmd",
			"",
			seeGuide("Directories used during the build process", "build.builddirs"))
	}
}

// checkTextPath checks for literal -Wl,--rpath options.
//
// Note: A simple -R is not detected, as the rate of false positives is too high.
func (ck MkLineChecker) checkTextRpath(text string) {
	mkline := ck.MkLine

	if mkline.IsVarassign() && mkline.Varname() == "BUILDLINK_TRANSFORM" &&
		hasPrefix(mkline.Value(), "rm:") {

		return
	}

	if m, flag := match1(text, `(-Wl,--rpath,|-Wl,-rpath-link,|-Wl,-rpath,|-Wl,-R\b)`); m {
		mkline.Warnf("Please use ${COMPILER_RPATH_FLAG} instead of %q.", flag)
	}
}

// checkVartype checks the type of the given variable, when it is assigned the given value,
// or if op is either opUseCompare or opUseMatch, when it is compared to the given value.
//
// comment is an empty string for no comment, or "#" + the actual comment otherwise.
func (ck MkLineChecker) checkVartype(varname string, op MkOperator, value, comment string) {
	if trace.Tracing {
		defer trace.Call(varname, op, value, comment)()
	}

	mkline := ck.MkLine
	vartype := G.Pkgsrc.VariableType(ck.MkLines, varname)

	if op == opAssignAppend {
		// XXX: MayBeAppendedTo also depends on the current file, see MkVarUseChecker.checkPermissions.
		// These checks may be combined.
		if vartype != nil && !vartype.MayBeAppendedTo() {
			mkline.Warnf("The \"+=\" operator should only be used with lists, not with %s.", varname)
		}
	}

	switch {
	case vartype == nil:
		if trace.Tracing {
			trace.Step1("Unchecked variable assignment for %s.", varname)
		}

	case op == opAssignShell:
		if trace.Tracing {
			trace.Step1("Unchecked use of !=: %q", value)
		}

	case !vartype.IsList():
		ck.CheckVartypeBasic(varname, vartype.basicType, op, value, comment, vartype.IsGuessed())

	case value == "":
		break

	default:
		words := mkline.ValueFields(value)
		if len(words) > 1 && vartype.IsOnePerLine() {
			mkline.Warnf("%s should only get one item per line.", varname)
			mkline.Explain(
				"Use the += operator to append each of the items.",
				"",
				"Or, enclose the words in quotes to group them.")
		}
		if vartype.basicType == BtCategory {
			mkAssignChecker := NewMkAssignChecker(mkline, ck.MkLines)
			mkAssignChecker.checkRightCategory()
		}
		for _, word := range words {
			ck.CheckVartypeBasic(varname, vartype.basicType, op, word, comment, vartype.IsGuessed())
		}
	}
}

// CheckVartypeBasic checks a single list element of the given type.
//
// For some variables (like `BuildlinkDepth`), `op` influences the valid values.
// The `comment` parameter comes from a variable assignment, when a part of the line is commented out.
func (ck MkLineChecker) CheckVartypeBasic(varname string, checker *BasicType, op MkOperator, value, comment string, guessed bool) {
	if trace.Tracing {
		defer trace.Call(varname, checker.name, op, value, comment, guessed)()
	}

	mkline := ck.MkLine
	valueNoVar := mkline.WithoutMakeVariables(value)
	ctx := VartypeCheck{ck.MkLines, mkline, varname, op, value, valueNoVar, comment, guessed}
	checker.checker(&ctx)
}

func (ck MkLineChecker) checkShellCommand() {
	mkline := ck.MkLine

	shellCommand := mkline.ShellCommand()
	if hasPrefix(mkline.Text, "\t\t") {
		lexer := textproc.NewLexer(mkline.RawText(0))
		tabs := lexer.NextBytesFunc(func(b byte) bool { return b == '\t' })

		fix := mkline.Autofix()
		fix.Notef("Shell programs should be indented with a single tab.")
		fix.Explain(
			"The first tab in the line marks the line as a shell command.",
			"Since every line of shell commands starts with a completely new shell environment,",
			"there is no need to indent some of the commands,",
			"or to use more horizontal space than necessary.")

		for i := range mkline.raw {
			if hasPrefix(mkline.RawText(i), tabs) {
				fix.ReplaceAt(i, 0, tabs, "\t")
			}
		}
		fix.Apply()
	}

	ck.checkText(shellCommand)
	NewShellLineChecker(ck.MkLines, mkline).CheckShellCommandLine(shellCommand)
}

func (ck MkLineChecker) checkComment() {
	mkline := ck.MkLine

	if hasPrefix(mkline.Text, "# url2pkg-marker") {
		mkline.Errorf("This comment indicates unfinished work (url2pkg).")
	}
}

func (ck MkLineChecker) checkInclude() {
	if trace.Tracing {
		defer trace.Call0()()
	}

	mkline := ck.MkLine
	if mkline.Indent() != "" {
		ck.checkDirectiveIndentation(ck.MkLines.indentation.Depth("include"))
	}

	includedFile := mkline.IncludedFile()
	mustExist := mkline.MustExist()
	if trace.Tracing {
		trace.Stepf("includingFile=%s includedFile=%s", mkline.Filename(), includedFile)
	}
	ck.CheckRelativePath(NewPackagePath(includedFile), includedFile, mustExist)

	switch {
	case includedFile.HasBase("Makefile"):
		mkline.Errorf("Other Makefiles must not be included directly.")
		mkline.Explain(
			"To include portions of another Makefile, extract the common parts",
			"and put them into a Makefile.common or a Makefile fragment called",
			"module.mk or similar.",
			"After that, both this one and the other package should include the newly created file.")

	case mkline.Basename != "Makefile" && includedFile.HasBase("bsd.pkg.mk"):
		mkline.Errorf("The file bsd.pkg.mk must only be included by package Makefiles, not by other Makefile fragments.")

	case mkline.Basename == "buildlink3.mk" && includedFile.HasBase("bsd.prefs.mk"):
		fix := mkline.Autofix()
		fix.Notef("For efficiency reasons, please include bsd.fast.prefs.mk instead of bsd.prefs.mk.")
		fix.Replace("bsd.prefs.mk", "bsd.fast.prefs.mk")
		fix.Apply()

	case includedFile.HasSuffixPath("pkgtools/x11-links/buildlink3.mk"):
		fix := mkline.Autofix()
		fix.Errorf("%q must not be included directly. Include \"../../mk/x11.buildlink3.mk\" instead.", includedFile)
		fix.Replace("pkgtools/x11-links/buildlink3.mk", "mk/x11.buildlink3.mk")
		fix.Apply()

	case includedFile.HasSuffixPath("graphics/jpeg/buildlink3.mk"):
		fix := mkline.Autofix()
		fix.Errorf("%q must not be included directly. Include \"../../mk/jpeg.buildlink3.mk\" instead.", includedFile)
		fix.Replace("graphics/jpeg/buildlink3.mk", "mk/jpeg.buildlink3.mk")
		fix.Apply()

	case includedFile.HasSuffixPath("intltool/buildlink3.mk"):
		mkline.Warnf("Please write \"USE_TOOLS+= intltool\" instead of this line.")
	}

	ck.checkIncludeBuiltin()
}

func (ck MkLineChecker) checkIncludeBuiltin() {
	mkline := ck.MkLine

	includedFile := mkline.IncludedFile()
	switch {
	case includedFile == "builtin.mk",
		!includedFile.HasSuffixPath("builtin.mk"),
		mkline.Basename == "hacks.mk",
		mkline.HasRationale("builtin", "include", "included", "including"):
		return
	}

	includeInstead := includedFile.Dir().JoinNoClean("buildlink3.mk")

	fix := mkline.Autofix()
	fix.Errorf("%q must not be included directly. Include %q instead.",
		includedFile, includeInstead)
	fix.Replace("builtin.mk", "buildlink3.mk")
	fix.Apply()
}

func (ck MkLineChecker) checkDirectiveIndentation(expectedDepth int) {
	mkline := ck.MkLine
	indent := mkline.Indent()
	if expected := strings.Repeat(" ", expectedDepth); indent != expected {
		fix := mkline.Autofix()
		fix.Notef("This directive should be indented by %d spaces.", expectedDepth)
		if hasPrefix(mkline.RawText(0), "."+indent) {
			fix.ReplaceAt(0, 0, "."+indent, "."+expected)
		}
		fix.Apply()
	}
}

// CheckRelativePath checks a relative path that leads to the directory of another package
// or to a subdirectory thereof or a file within there.
func (ck MkLineChecker) CheckRelativePath(pp PackagePath, rel RelPath, mustExist bool) {
	// TODO: Not every path is relative to the package directory.
	if trace.Tracing {
		defer trace.Call(rel, mustExist)()
	}

	mkline := ck.MkLine
	if !G.Wip && rel.ContainsPath("wip") {
		mkline.Errorf("A main pkgsrc package must not depend on a pkgsrc-wip package.")
	}

	resolvedPath := mkline.ResolveVarsInRelativePath(pp, ck.MkLines.pkg)
	if containsVarUse(resolvedPath.String()) {
		return
	}

	abs := G.Pkgsrc.FilePkg(resolvedPath)
	if abs.IsEmpty() {
		abs = mkline.File(resolvedPath.AsRelPath())
	}
	if !abs.Exists() {
		pkgsrcPath := G.Pkgsrc.Rel(ck.MkLine.File(resolvedPath.AsRelPath()))
		if mustExist && !ck.MkLines.indentation.HasExists(pkgsrcPath) {
			mkline.Errorf("Relative path %q does not exist.", rel)
		}
		return
	}

	switch {
	case !resolvedPath.HasPrefixPath(".."):
		break

	case resolvedPath.HasPrefixPath("../../mk"):
		// From a package to the infrastructure.

	case matches(resolvedPath.String(), `^\.\./\.\./[^./][^/]*/[^/]`):
		// From a package to another package.

	case resolvedPath.HasPrefixPath("../mk") && G.Pkgsrc.Rel(mkline.Filename()).Count() == 2:
		// For category Makefiles.
		// TODO: Or from a pkgsrc wip package to wip/mk.

	case matches(resolvedPath.String(), `^\.\./[^./][^/]*/[^/]`):
		if G.Wip && resolvedPath.ContainsPath("mk") {
			mkline.Warnf("References to the pkgsrc-wip infrastructure should look like \"../../wip/mk\", not \"../mk\".")
		} else {
			mkline.Warnf("References to other packages should look like \"../../category/package\", not \"../package\".")
		}
		mkline.ExplainRelativeDirs()
	}
}

// CheckRelativePkgdir checks a reference from one pkgsrc package to another.
// These references should always have the form ../../category/package.
//
// When used in DEPENDS or similar variables, these directories could theoretically
// also be relative to the pkgsrc root, which would save a few keystrokes.
// This, however, is not implemented in pkgsrc and suggestions regarding this topic
// have not been made in the last two decades on the public mailing lists.
// While being a bit redundant, the current scheme works well.
//
// When used in .include directives, the relative package directories must be written
// with the leading ../.. anyway, so the benefit might not be too big at all.
func (ck MkLineChecker) CheckRelativePkgdir(rel RelPath, pkgdir PackagePath) {
	// TODO: Not every path is relative to the package directory.
	if trace.Tracing {
		defer trace.Call(pkgdir)()
	}

	mkline := ck.MkLine
	makefile := pkgdir.JoinNoClean("Makefile")
	ck.CheckRelativePath(makefile, makefile.AsRelPath(), true)

	if hasSuffix(pkgdir.String(), "/") {
		mkline.Errorf("Relative package directories like %q must not end with a slash.", pkgdir.String())
		mkline.Explain(
			"This causes problems with bulk builds, at least with limited builds,",
			"as the trailing slash in a package directory name causes pbulk-scan",
			"to fail with \"Invalid path from master\" and leads to a hung scan phase.")
	} else if pkgdir.AsPath() != pkgdir.AsPath().Clean() {
		mkline.Errorf("Relative package directories like %q must be canonical.",
			pkgdir.String())
		mkline.Explain(
			"The canonical form of a package path is \"../../category/package\".")
	}

	// This strips any trailing slash.
	pkgdir = mkline.ResolveVarsInRelativePath(pkgdir, ck.MkLines.pkg)

	if !matches(pkgdir.String(), `^\.\./\.\./([^./][^/]*/[^./][^/]*)$`) && !containsVarUse(pkgdir.String()) {
		mkline.Warnf("%q is not a valid relative package directory.", rel)
		mkline.Explain(
			"A relative pathname always starts with \"../../\", followed",
			"by a category, a slash and a the directory name of the package.",
			"For example, \"../../misc/screen\" is a valid relative pathname.")
	}
}

func (ck MkLineChecker) checkDirective(forVars map[string]bool, ind *Indentation) {
	mkline := ck.MkLine

	directive := mkline.Directive()
	args := mkline.Args()

	expectedDepth := ind.Depth(directive)
	ck.checkDirectiveIndentation(expectedDepth)

	if directive == "endfor" || directive == "endif" {
		ck.checkDirectiveEnd(ind)
	}

	needsArgument := false
	switch directive {
	case
		"if", "ifdef", "ifndef", "elif",
		"for", "undef",
		"error", "warning", "info",
		"export", "export-env", "unexport", "unexport-env":
		needsArgument = true
	}

	switch {
	case needsArgument && args == "":
		mkline.Errorf("\".%s\" requires arguments.", directive)

	case !needsArgument && args != "":
		if directive == "else" {
			mkline.Errorf("\".%s\" does not take arguments. If you meant \"else if\", use \".elif\".", directive)
		} else {
			mkline.Errorf("\".%s\" does not take arguments.", directive)
		}

	case directive == "if" || directive == "elif":
		mkCondChecker := NewMkCondChecker(mkline, ck.MkLines)
		mkCondChecker.Check()

	case directive == "ifdef" || directive == "ifndef":
		mkline.Warnf("The \".%s\" directive is deprecated. Please use \".if %sdefined(%s)\" instead.",
			directive, condStr(directive == "ifdef", "", "!"), args)

	case directive == "for":
		ck.checkDirectiveFor(forVars, ind)

	case directive == "undef":
		for _, varname := range mkline.Fields() {
			if forVars[varname] {
				mkline.Notef("Using \".undef\" after a \".for\" loop is unnecessary.")
			}
		}
	}
}

func (ck MkLineChecker) checkDirectiveEnd(ind *Indentation) {
	mkline := ck.MkLine
	directive := mkline.Directive()
	comment := mkline.DirectiveComment()

	if ind.IsEmpty() {
		mkline.Errorf("Unmatched .%s.", directive)
		return
	}

	if comment == "" {
		return
	}

	if directive == "endif" {
		if args, argsLine := ind.Args(); !contains(args, comment) {
			mkline.Warnf("Comment %q does not match condition %q in %s.",
				comment, args, mkline.RelMkLine(argsLine))
		}
	}

	if directive == "endfor" {
		if args, argsLine := ind.Args(); !contains(args, comment) {
			mkline.Warnf("Comment %q does not match loop %q in %s.",
				comment, args, mkline.RelMkLine(argsLine))
		}
	}
}

func (ck MkLineChecker) checkDirectiveFor(forVars map[string]bool, indentation *Indentation) {
	mkline := ck.MkLine
	args := mkline.Args()

	if m, vars, _ := match2(args, `^([^\t ]+(?:[\t ]*[^\t ]+)*?)[\t ]+in[\t ]+(.*)$`); m {
		for _, forvar := range strings.Fields(vars) {
			indentation.AddVar(forvar)
			if !G.Infrastructure && hasPrefix(forvar, "_") {
				mkline.Warnf("Variable names starting with an underscore (%s) are reserved for internal pkgsrc use.", forvar)
			}

			if matches(forvar, `^[_a-z][_a-z0-9]*$`) {
				// Fine.
			} else if matches(forvar, `^[A-Z_a-z][0-9A-Z_a-z]*$`) {
				mkline.Warnf("The variable name %q in the .for loop should not contain uppercase letters.", forvar)
			} else {
				mkline.Errorf("Invalid variable name %q.", forvar)
			}

			forVars[forvar] = true
		}

		// The guessed flag could be determined more correctly.
		// As of January 2020, running pkglint over the whole pkgsrc
		// tree did not produce any different result whether guessed
		// was true or false.
		forLoopType := NewVartype(btForLoop, List, NewACLEntry("*", aclpAllRead))
		forLoopContext := VarUseContext{forLoopType, VucLoadTime, VucQuotPlain, false}
		mkline.ForEachUsed(func(varUse *MkVarUse, time VucTime) {
			NewMkVarUseChecker(varUse, ck.MkLines, mkline).Check(&forLoopContext)
		})
	}
}

func (ck MkLineChecker) checkDependencyRule(allowedTargets map[string]bool) {
	mkline := ck.MkLine
	targets := mkline.ValueFields(mkline.Targets())
	sources := mkline.ValueFields(mkline.Sources())

	for _, source := range sources {
		if source == ".PHONY" {
			for _, target := range targets {
				allowedTargets[target] = true
			}
		}
	}
	for _, target := range targets {
		if target == ".PHONY" {
			for _, source := range sources {
				allowedTargets[source] = true
			}
		}
	}

	for _, target := range targets {
		ck.checkDependencyTarget(target, allowedTargets)
	}
}

func (ck MkLineChecker) checkDependencyTarget(target string, allowedTargets map[string]bool) {
	if target == ".PHONY" || target == ".ORDER" || allowedTargets[target] {
		return
	}
	if NewMkLexer(target, nil).VarUse() != nil {
		return
	}

	mkline := ck.MkLine
	mkline.Warnf("Undeclared target %q.", target)
	mkline.Explain(
		"To define a custom target in a package, declare it like this:",
		"",
		"\t.PHONY: my-target",
		"",
		"To define a custom target that creates a file (should be rarely needed),",
		"declare it like this:",
		"",
		"\t${.CURDIR}/my-file:")
}
