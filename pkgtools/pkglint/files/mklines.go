package pkglint

import "strings"

// MkLines contains data for the Makefile (or *.mk) that is currently checked.
type MkLines struct {
	mklines []*MkLine
	lines   *Lines

	// The package that provides further context for cross-checks,
	// such as the conditionally included files.
	//
	// This package should be used mostly as a read-only storage of context
	// information. To keep the code understandable, only few things should
	// be changed, if at all. This is exactly the reason that the
	// extraScope has been moved to a separate variable.
	//
	// XXX: Maybe split this field into two: pkg and pkgForModification.
	pkg *Package

	// The extra scope in which all variable assignments are recorded.
	// In most cases this is nil.
	//
	// When loading the package Makefile with all its included files,
	// it is set to pkg.vars.
	extraScope *Scope

	allVars       Scope              // The variables after loading the complete file
	buildDefs     map[string]bool    // Variables that are registered in BUILD_DEFS, to ensure that all user-defined variables are added to it.
	plistVarAdded map[string]*MkLine // Identifiers that are added to PLIST_VARS.
	plistVarSet   map[string]*MkLine // Identifiers for which PLIST.${id} is defined.
	plistVarSkip  bool               // True if any of the PLIST_VARS identifiers refers to a variable.
	Tools         *Tools             // Tools defined in file scope.
	indentation   *Indentation       // Indentation depth of preprocessing directives; only available during MkLines.ForEach.
	once          Once

	// TODO: Consider extracting plistVarAdded, plistVarSet, plistVarSkip into an own type.
	// TODO: Describe where each of the above fields is valid.

	checkAllData mklinesCheckAll
}

type mklinesCheckAll struct {
	// Current make(1) target
	target string

	vars Scope

	// The variables currently used in .for loops
	forVars map[string]bool

	// Custom action that is run after checking each line
	postLine func(mkline *MkLine)
}

func NewMkLines(lines *Lines, pkg *Package, extraScope *Scope) *MkLines {
	mklines := make([]*MkLine, lines.Len())
	for i, line := range lines.Lines {
		mklines[i] = NewMkLineParser().Parse(line)
	}

	tools := NewTools()
	tools.Fallback(G.Pkgsrc.Tools)

	return &MkLines{
		mklines,
		lines,
		pkg,
		extraScope,
		NewScope(),
		make(map[string]bool),
		make(map[string]*MkLine),
		make(map[string]*MkLine),
		false,
		tools,
		nil,
		Once{},
		mklinesCheckAll{
			target:   "",
			vars:     NewScope(),
			forVars:  make(map[string]bool),
			postLine: nil}}
}

// TODO: Consider defining an interface MkLinesChecker (different name, though, since this one confuses even me)
//  that checks a single topic, like:
//
//  * PlistVars
//  * ForLoops
//  * MakeTargets
//  * Tools
//  * Indentation
//  * LoadTimeVarUse
//  * Subst
//  * VarAlign
//
// These could be run in parallel to get the diagnostics strictly from top to bottom.
// Some of the checkers will probably depend on one another.
//
// The driving code for these checkers could look like:
//
//  ck.Init
//  ck.BeforeLine
//  ck.Line
//  ck.AfterLine
//  ck.Finish

func (mklines *MkLines) Check() {
	if trace.Tracing {
		defer trace.Call(mklines.lines.Filename)()
	}

	// In the first pass, all additions to BUILD_DEFS and USE_TOOLS
	// are collected to make the order of the definitions irrelevant.
	mklines.collectRationale()
	mklines.collectUsedVariables()
	mklines.collectVariables()
	mklines.collectPlistVars()
	if mklines.pkg != nil {
		mklines.pkg.collectConditionalIncludes(mklines)
	}

	// In the second pass, the actual checks are done.
	mklines.checkAll()

	SaveAutofixChanges(mklines.lines)
}

func (mklines *MkLines) collectRationale() {

	isUseful := func(mkline *MkLine) bool {
		comment := trimHspace(mkline.Comment())
		return comment != "" && !hasPrefix(comment, "$NetBSD")
	}

	isRealComment := func(mkline *MkLine) bool {
		return mkline.IsComment() && !mkline.IsCommentedVarassign()
	}

	var rat strings.Builder
	for _, mkline := range mklines.mklines {
		if isRealComment(mkline) && isUseful(mkline) {
			rat.WriteString(mkline.Comment())
			rat.WriteString("\n")
		}

		var lineRat strings.Builder
		lineRat.WriteString(rat.String())
		if isUseful(mkline) {
			lineRat.WriteString(mkline.Comment())
			lineRat.WriteString("\n")
		}

		mkline.splitResult.rationale = lineRat.String()
		if mkline.IsEmpty() {
			rat.Reset()
		}
	}
}

func (mklines *MkLines) collectUsedVariables() {
	for _, mkline := range mklines.mklines {
		mkline.ForEachUsed(func(varUse *MkVarUse, time VucTime) {
			mklines.UseVar(mkline, varUse.varname, time)
		})
	}

	mklines.collectDocumentedVariables()
}

// UseVar remembers that the given variable is used in the given line.
// This controls the "defined but not used" warning.
func (mklines *MkLines) UseVar(mkline *MkLine, varname string, time VucTime) {
	mklines.allVars.Use(varname, mkline, time)
	if mklines.extraScope != nil {
		mklines.extraScope.Use(varname, mkline, time)
	}
}

// collectDocumentedVariables collects the variables that are mentioned in the human-readable
// documentation of the Makefile fragments from the pkgsrc infrastructure.
//
// Loosely based on mk/help/help.awk, revision 1.28, but much simpler.
func (mklines *MkLines) collectDocumentedVariables() {
	scope := NewScope()
	commentLines := 0
	relevant := true

	// TODO: Correctly interpret declarations like "package-settable variables:" and
	//  "user-settable variables", as well as "default: ...", "allowed: ...",
	//  "list of" and other types.

	finish := func() {
		// The commentLines include the the line containing the variable name,
		// leaving 2 of these 3 lines for the actual documentation.
		if commentLines >= 3 && relevant {
			scope.forEach(func(varname string, data *scopeVar) {
				mklines.allVars.Define(varname, data.used)
				mklines.allVars.Use(varname, data.used, VucRunTime)
			})
		}

		scope = NewScope()
		commentLines = 0
		relevant = true
	}

	for _, mkline := range mklines.mklines {
		text := mkline.Text
		switch {
		case hasPrefix(text, "#"):
			words := strings.Fields(text)
			if len(words) <= 1 {
				break
			}

			commentLines++

			parser := NewMkLexer(words[1], nil)
			varname := parser.Varname()
			if len(varname) < 3 {
				break
			}
			if hasSuffix(varname, ".") {
				if !parser.lexer.SkipRegexp(regcomp(`^<\w+>`)) {
					break
				}
				varname += "*"
			}
			parser.lexer.SkipByte(':')

			varcanon := varnameCanon(varname)
			if varcanon == strings.ToUpper(varcanon) && matches(varcanon, `[A-Z]`) && parser.EOF() {
				scope.Define(varcanon, mkline)
				scope.Use(varcanon, mkline, VucRunTime)
			}

			if words[1] == "Copyright" {
				relevant = false
			}

		case mkline.IsEmpty():
			finish()
		}
	}

	finish()
}

func (mklines *MkLines) collectVariables() {
	mklines.ForEach(mklines.collectVariable)
}

func (mklines *MkLines) collectVariable(mkline *MkLine) {
	mklines.Tools.ParseToolLine(mklines, mkline, false, true)

	if !mkline.IsVarassignMaybeCommented() {
		return
	}

	mklines.defineVar(mkline, mkline.Varname())

	varcanon := mkline.Varcanon()
	switch varcanon {
	case
		"BUILD_DEFS",
		"PKG_GROUPS_VARS", // see mk/misc/unprivileged.mk
		"PKG_USERS_VARS":  // see mk/misc/unprivileged.mk
		for _, varname := range mkline.Fields() {
			mklines.buildDefs[varname] = true
			if trace.Tracing {
				trace.Step1("%q is added to BUILD_DEFS.", varname)
			}
		}

	case
		"BUILTIN_FIND_FILES_VAR",
		"BUILTIN_FIND_HEADERS_VAR":
		for _, varname := range mkline.Fields() {
			mklines.allVars.Define(varname, mkline)
		}

	case "PLIST_VARS":
		for _, id := range mkline.ValueFields(resolveVariableRefs(mkline.Value(), mklines, nil)) {
			if trace.Tracing {
				trace.Step1("PLIST.%s is added to PLIST_VARS.", id)
			}

			if containsVarUse(id) {
				mklines.UseVar(mkline, "PLIST.*", mkline.Op().Time())
				mklines.plistVarSkip = true
			} else {
				mklines.UseVar(mkline, "PLIST."+id, mkline.Op().Time())
			}
		}

	case "SUBST_VARS.*":
		for _, substVar := range mkline.Fields() {
			mklines.UseVar(mkline, varnameCanon(substVar), mkline.Op().Time())
			if trace.Tracing {
				trace.Step1("varuse %s", substVar)
			}
		}

	case "OPSYSVARS":
		for _, opsysVar := range mkline.Fields() {
			mklines.UseVar(mkline, opsysVar+".*", mkline.Op().Time())
			mklines.defineVar(mkline, opsysVar)
		}
	}
}

// ForEach calls the action for each line, until the action returns false.
// It keeps track of the indentation (see MkLines.indentation)
// and all conditional variables (see Indentation.IsConditional).
func (mklines *MkLines) ForEach(action func(mkline *MkLine)) {
	mklines.ForEachEnd(
		func(mkline *MkLine) bool { action(mkline); return true },
		func(mkline *MkLine) {})
}

// ForEachEnd calls the action for each line, until the action returns false.
// It keeps track of the indentation and all conditional variables.
// At the end, atEnd is called with the last line as its argument.
func (mklines *MkLines) ForEachEnd(action func(mkline *MkLine) bool, atEnd func(lastMkline *MkLine)) bool {

	// XXX: To avoid looping over the lines multiple times, it would
	// be nice to have an interface LinesChecker that checks a single topic.
	// Multiple of these line checkers could be run in parallel, so that
	// the diagnostics appear in the correct order, from top to bottom.

	// ForEachEnd must not be called within itself.
	assert(mklines.indentation == nil)

	mklines.indentation = NewIndentation()
	mklines.Tools.SeenPrefs = false

	result := true
	for _, mkline := range mklines.mklines {
		mklines.indentation.TrackBefore(mkline)
		if !action(mkline) {
			result = false
			break
		}
		mklines.indentation.TrackAfter(mkline)
	}

	if len(mklines.mklines) > 0 {
		atEnd(mklines.mklines[len(mklines.mklines)-1])
	}
	mklines.indentation = nil

	return result
}

// defineVar marks a variable as defined in both the current package and the current file.
func (mklines *MkLines) defineVar(mkline *MkLine, varname string) {
	mklines.allVars.Define(varname, mkline)
	if mklines.extraScope != nil {
		mklines.extraScope.Define(varname, mkline)
	}
}

func (mklines *MkLines) collectPlistVars() {
	// TODO: The PLIST_VARS code above looks very similar.
	for _, mkline := range mklines.mklines {
		if mkline.IsVarassign() {
			switch mkline.Varcanon() {
			case "PLIST_VARS":
				for _, id := range mkline.ValueFields(resolveVariableRefs(mkline.Value(), mklines, nil)) {
					if containsVarUse(id) {
						mklines.plistVarSkip = true
					} else {
						mklines.plistVarAdded[id] = mkline
					}
				}
			case "PLIST.*":
				id := mkline.Varparam()
				if containsVarUse(id) {
					mklines.plistVarSkip = true
				} else {
					mklines.plistVarSet[id] = mkline
				}
			}
		}
	}
}

func (mklines *MkLines) checkAll() {
	// checkAll must only be called once, even during tests, since it
	// doesn't clean up all its effects on mklines.
	assert(mklines.once.FirstTime("checkAll"))

	allowedTargets := map[string]bool{
		"pre-fetch": true, "do-fetch": true, "post-fetch": true,
		"pre-extract": true, "do-extract": true, "post-extract": true,
		"pre-patch": true, "do-patch": true, "post-patch": true,
		"pre-tools": true, "do-tools": true, "post-tools": true,
		"pre-wrapper": true, "do-wrapper": true, "post-wrapper": true,
		"pre-configure": true, "do-configure": true, "post-configure": true,
		"pre-build": true, "do-build": true, "post-build": true,
		"pre-test": true, "do-test": true, "post-test": true,
		"pre-install": true, "do-install": true, "post-install": true,
		"pre-package": true, "do-package": true, "post-package": true,
		"pre-clean": true, "do-clean": true, "post-clean": true}

	mklines.lines.CheckCvsID(0, `#[\t ]+`, "# ")

	substContext := NewSubstContext(mklines.pkg)
	var varalign VaralignBlock
	vargroupsChecker := NewVargroupsChecker(mklines)
	isHacksMk := mklines.lines.BaseName == "hacks.mk"

	if trace.Tracing {
		trace.Stepf("Starting main checking loop")
	}
	mklines.ForEachEnd(
		func(mkline *MkLine) bool {
			if isHacksMk {
				// Needs to be set here because it is reset in MkLines.ForEach.
				mklines.Tools.SeenPrefs = true
			}
			mklines.checkLine(mkline, vargroupsChecker, &varalign, substContext, allowedTargets)
			return true
		},
		func(mkline *MkLine) {
			// This check is not done by ForEach because ForEach only
			// manages the iteration, not the actual checks.
			mklines.indentation.CheckFinish(mklines.lines.Filename)
			vargroupsChecker.Finish()
		})

	substContext.Finish(mklines.EOFLine())
	varalign.Finish()

	CheckLinesTrailingEmptyLines(mklines.lines)
}

func (mklines *MkLines) checkLine(
	mkline *MkLine,
	vargroupsChecker *VargroupsChecker,
	varalign *VaralignBlock,
	substContext *SubstContext,
	allowedTargets map[string]bool) {

	ck := MkLineChecker{mklines, mkline}
	ck.Check()
	vargroupsChecker.Check(mkline)

	varalign.Process(mkline)
	mklines.Tools.ParseToolLine(mklines, mkline, false, false)
	substContext.Process(mkline)

	switch {

	case mkline.IsVarassign():
		mklines.checkAllData.target = ""
		mkline.Tokenize(mkline.Value(), true) // Just for the side-effect of the warnings.

		mklines.checkVarassignPlist(mkline)
		varname := mkline.Varname()
		mklines.checkAllData.vars.Define(varname, mkline)

	case mkline.IsInclude():
		mklines.checkAllData.target = ""
		if mklines.pkg != nil {
			mklines.pkg.checkIncludeConditionally(mkline, mklines.indentation)
		}

	case mkline.IsDirective():
		ck.checkDirective(mklines.checkAllData.forVars, mklines.indentation)

	case mkline.IsDependency():
		ck.checkDependencyRule(allowedTargets)
		mklines.checkAllData.target = mkline.Targets()

	case mkline.IsShellCommand():
		mkline.Tokenize(mkline.ShellCommand(), true) // Just for the side-effect of the warnings.
	}

	if mklines.checkAllData.postLine != nil {
		mklines.checkAllData.postLine(mkline)
	}
}

func (mklines *MkLines) checkVarassignPlist(mkline *MkLine) {
	switch mkline.Varcanon() {
	case "PLIST_VARS":
		for _, id := range mkline.ValueFields(resolveVariableRefs(mkline.Value(), mklines, nil)) {
			if !mklines.plistVarSkip && mklines.plistVarSet[id] == nil {
				mkline.Warnf("%q is added to PLIST_VARS, but PLIST.%s is not defined in this file.", id, id)
			}
		}

	case "PLIST.*":
		id := mkline.Varparam()
		if !mklines.plistVarSkip && mklines.plistVarAdded[id] == nil {
			mkline.Warnf("PLIST.%s is defined, but %q is not added to PLIST_VARS in this file.", id, id)
		}
	}
}

// CheckUsedBy checks that this file (a Makefile.common) has the given
// relativeName in one of the "# used by" comments at the beginning of the file.
func (mklines *MkLines) CheckUsedBy(relativeName PkgsrcPath) {
	lines := mklines.lines
	if lines.Len() < 3 {
		return
	}

	paras := mklines.SplitToParagraphs()

	expected := "# used by " + relativeName.String()
	found := false
	var usedParas []*Paragraph

	determineUsedParas := func() {
		for _, para := range paras {
			var hasUsedBy bool
			var hasOther bool
			var conflict *MkLine

			para.ForEach(func(mkline *MkLine) {
				if ok, _ := mkline.IsCvsID(`#[\t ]+`); ok {
					return
				}
				if hasPrefix(mkline.Text, "# used by ") && len(strings.Fields(mkline.Text)) == 4 {
					if mkline.Text == expected {
						found = true
					}
					hasUsedBy = true
					if hasOther && conflict == nil {
						conflict = mkline
					}
				} else {
					hasOther = true
					if hasUsedBy && conflict == nil {
						conflict = mkline
					}
				}
			})

			if conflict != nil {
				conflict.Warnf("The \"used by\" lines should be in a separate paragraph.")
			} else if hasUsedBy {
				usedParas = append(usedParas, para)
			}
		}
	}
	determineUsedParas()

	if len(usedParas) > 1 {
		usedParas[1].FirstLine().Warnf("There should only be a single \"used by\" paragraph per file.")
	}

	var prevLine *MkLine
	if len(usedParas) > 0 {
		prevLine = usedParas[0].LastLine()
	} else {
		prevLine = paras[0].LastLine()
		if paras[0].to > 1 {
			fix := prevLine.Autofix()
			fix.Notef(SilentAutofixFormat)
			fix.InsertBelow("")
			fix.Apply()
		}
	}

	// TODO: Sort the comments.
	// TODO: Discuss whether these comments are actually helpful.
	// TODO: Remove lines that don't apply anymore.

	if !found {
		fix := prevLine.Autofix()
		fix.Warnf("Please add a line %q here.", expected)
		fix.Explain(
			"Since Makefile.common files usually don't have any comments and",
			"therefore not a clearly defined purpose, they should at least",
			"contain references to all files that include them, so that it is",
			"easier to see what effects future changes may have.",
			"",
			"If there are more than five packages that use a Makefile.common,",
			"that file should have a clearly defined and documented purpose,",
			"and the filename should reflect that purpose.",
			"Typical names are module.mk, plugin.mk or version.mk.")
		fix.InsertBelow(expected)
		fix.Apply()
	}

	SaveAutofixChanges(lines)
}

func (mklines *MkLines) SplitToParagraphs() []*Paragraph {
	var paras []*Paragraph

	lines := mklines.mklines
	isEmpty := func(i int) bool {
		if lines[i].IsEmpty() {
			return true
		}
		return lines[i].IsComment() &&
			lines[i].Text == "#" &&
			(i == 0 || lines[i-1].IsComment()) &&
			(i == len(lines)-1 || lines[i+1].IsComment())
	}

	i := 0
	for i < len(lines) {
		from := i
		for from < len(lines) && isEmpty(from) {
			from++
		}

		to := from
		for to < len(lines) && !isEmpty(to) {
			to++
		}

		if from != to {
			paras = append(paras, NewParagraph(mklines, from, to))
		}
		i = to
	}

	return paras
}

// ExpandLoopVar searches the surrounding .for loops for the given
// variable and returns a slice containing all its values, fully
// expanded.
//
// It can only be used during an active ForEach call.
func (mklines *MkLines) ExpandLoopVar(varname string) []string {

	// From the inner loop to the outer loop, just in case
	// that two loops should ever use the same variable.
	for i := len(mklines.indentation.levels) - 1; i >= 0; i-- {
		ind := mklines.indentation.levels[i]

		mkline := ind.mkline
		if mkline.Directive() != "for" {
			continue
		}

		// TODO: If needed, add support for multi-variable .for loops.
		resolved := resolveVariableRefs(mkline.Args(), mklines, nil)
		words := mkline.ValueFields(resolved)
		if len(words) >= 3 && words[0] == varname && words[1] == "in" {
			return words[2:]
		}
	}

	return nil
}

// IsUnreachable determines whether the given line is unreachable because a
// condition on the way to that line is not satisfied.
// If unsure, returns false.
func (mklines *MkLines) IsUnreachable(mkline *MkLine) bool {
	// To make this code as simple as possible, the code should operate
	// on a high-level AST, where the nodes are If, For and BasicBlock.
	//
	// See lang/ghc*/bootstrap.mk for good examples how pkglint should
	// treat variable assignments. It's getting complicated.
	return false
}

func (mklines *MkLines) SaveAutofixChanges() {
	mklines.lines.SaveAutofixChanges()
}

func (mklines *MkLines) EOFLine() *MkLine {
	return NewMkLineParser().Parse(mklines.lines.EOFLine())
}

// Whole returns a virtual line that can be used for issuing diagnostics
// and explanations, but not for text replacements.
func (mklines *MkLines) Whole() *Line { return mklines.lines.Whole() }
