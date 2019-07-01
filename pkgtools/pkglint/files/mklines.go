package pkglint

import (
	"strings"
)

// MkLines contains data for the Makefile (or *.mk) that is currently checked.
type MkLines struct {
	mklines       []*MkLine
	lines         *Lines
	target        string             // Current make(1) target; only available during checkAll
	vars          Scope              //
	buildDefs     map[string]bool    // Variables that are registered in BUILD_DEFS, to ensure that all user-defined variables are added to it.
	plistVarAdded map[string]*MkLine // Identifiers that are added to PLIST_VARS.
	plistVarSet   map[string]*MkLine // Identifiers for which PLIST.${id} is defined.
	plistVarSkip  bool               // True if any of the PLIST_VARS identifiers refers to a variable.
	Tools         *Tools             // Tools defined in file scope.
	indentation   *Indentation       // Indentation depth of preprocessing directives; only available during MkLines.ForEach.
	forVars       map[string]bool    // The variables currently used in .for loops; only available during MkLines.checkAll.
	once          Once

	// TODO: Consider extracting plistVarAdded, plistVarSet, plistVarSkip into an own type.
	// TODO: Describe where each of the above fields is valid.
}

func NewMkLines(lines *Lines) *MkLines {
	mklines := make([]*MkLine, lines.Len())
	for i, line := range lines.Lines {
		mklines[i] = MkLineParser{}.Parse(line)
	}

	tools := NewTools()
	tools.Fallback(G.Pkgsrc.Tools)

	return &MkLines{
		mklines,
		lines,
		"",
		NewScope(),
		make(map[string]bool),
		make(map[string]*MkLine),
		make(map[string]*MkLine),
		false,
		tools,
		nil,
		make(map[string]bool),
		Once{}}
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

// UseVar remembers that the given variable is used in the given line.
// This controls the "defined but not used" warning.
func (mklines *MkLines) UseVar(mkline *MkLine, varname string, time VucTime) {
	mklines.vars.Use(varname, mkline, time)
	if G.Pkg != nil {
		G.Pkg.vars.Use(varname, mkline, time)
	}
}

func (mklines *MkLines) Check() {
	if trace.Tracing {
		defer trace.Call1(mklines.lines.Filename)()
	}

	// In the first pass, all additions to BUILD_DEFS and USE_TOOLS
	// are collected to make the order of the definitions irrelevant.
	mklines.collectUsedVariables()
	mklines.collectDefinedVariables()
	mklines.collectPlistVars()
	mklines.collectElse()

	// In the second pass, the actual checks are done.
	mklines.checkAll()

	SaveAutofixChanges(mklines.lines)
}

func (mklines *MkLines) checkAll() {
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

	substContext := NewSubstContext()
	var varalign VaralignBlock
	isHacksMk := mklines.lines.BaseName == "hacks.mk"

	lineAction := func(mkline *MkLine) bool {
		if isHacksMk {
			// Needs to be set here because it is reset in MkLines.ForEach.
			mklines.Tools.SeenPrefs = true
		}

		ck := MkLineChecker{mklines, mkline}
		ck.Check()

		varalign.Process(mkline)
		mklines.Tools.ParseToolLine(mklines, mkline, false, false)
		substContext.Process(mkline)

		switch {

		case mkline.IsVarassign():
			mklines.target = ""
			mkline.Tokenize(mkline.Value(), true) // Just for the side-effect of the warnings.

			mklines.checkVarassignPlist(mkline)

		case mkline.IsInclude():
			mklines.target = ""
			if G.Pkg != nil {
				G.Pkg.checkIncludeConditionally(mkline, mklines.indentation)
			}

		case mkline.IsDirective():
			ck.checkDirective(mklines.forVars, mklines.indentation)

		case mkline.IsDependency():
			ck.checkDependencyRule(allowedTargets)
			mklines.target = mkline.Targets()

		case mkline.IsShellCommand():
			mkline.Tokenize(mkline.ShellCommand(), true) // Just for the side-effect of the warnings.
		}

		return true
	}

	atEnd := func(mkline *MkLine) {
		mklines.indentation.CheckFinish(mklines.lines.Filename)
	}

	if trace.Tracing {
		trace.Stepf("Starting main checking loop")
	}
	mklines.ForEachEnd(lineAction, atEnd)

	substContext.Finish(mklines.EOFLine())
	varalign.Finish()

	CheckLinesTrailingEmptyLines(mklines.lines)
}

func (mklines *MkLines) checkVarassignPlist(mkline *MkLine) {
	switch mkline.Varcanon() {
	case "PLIST_VARS":
		for _, id := range mkline.ValueFields(resolveVariableRefs(mklines, mkline.Value())) {
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
func (mklines *MkLines) ForEachEnd(action func(mkline *MkLine) bool, atEnd func(lastMkline *MkLine)) {

	// XXX: To avoid looping over the lines multiple times, it would
	// be nice to have an interface LinesChecker that checks a single topic.
	// Multiple of these line checkers could be run in parallel, so that
	// the diagnostics appear in the correct order, from top to bottom.

	mklines.indentation = NewIndentation()
	mklines.Tools.SeenPrefs = false

	for _, mkline := range mklines.mklines {
		mklines.indentation.TrackBefore(mkline)
		if !action(mkline) {
			break
		}
		mklines.indentation.TrackAfter(mkline)
	}

	if len(mklines.mklines) > 0 {
		atEnd(mklines.mklines[len(mklines.mklines)-1])
	}
	mklines.indentation = nil
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
		resolved := resolveVariableRefs(mklines, mkline.Args())
		words := mkline.ValueFields(resolved)
		if len(words) >= 3 && words[0] == varname && words[1] == "in" {
			return words[2:]
		}
	}

	return nil
}

func (mklines *MkLines) collectDefinedVariables() {
	// FIXME: This method has a wrong name. It collects not only the defined
	//  variables but also the used ones.

	if trace.Tracing {
		defer trace.Call0()()
	}

	mklines.ForEach(func(mkline *MkLine) {
		mklines.Tools.ParseToolLine(mklines, mkline, false, true)

		if !mkline.IsVarassign() && !mkline.IsCommentedVarassign() {
			return
		}

		mklines.defineVar(G.Pkg, mkline, mkline.Varname())

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
				mklines.vars.Define(varname, mkline)
			}

		case "PLIST_VARS":
			for _, id := range mkline.ValueFields(resolveVariableRefs(mklines, mkline.Value())) {
				if trace.Tracing {
					trace.Step1("PLIST.%s is added to PLIST_VARS.", id)
				}

				if containsVarRef(id) {
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
				mklines.defineVar(G.Pkg, mkline, opsysVar)
			}
		}
	})
}

// defineVar marks a variable as defined in both the current package and the current file.
func (mklines *MkLines) defineVar(pkg *Package, mkline *MkLine, varname string) {
	mklines.vars.Define(varname, mkline)
	if pkg != nil {
		pkg.vars.Define(varname, mkline)
	}
}

func (mklines *MkLines) collectPlistVars() {
	// TODO: The PLIST_VARS code above looks very similar.
	for _, mkline := range mklines.mklines {
		if mkline.IsVarassign() {
			switch mkline.Varcanon() {
			case "PLIST_VARS":
				for _, id := range mkline.ValueFields(resolveVariableRefs(mklines, mkline.Value())) {
					if containsVarRef(id) {
						mklines.plistVarSkip = true
					} else {
						mklines.plistVarAdded[id] = mkline
					}
				}
			case "PLIST.*":
				id := mkline.Varparam()
				if containsVarRef(id) {
					mklines.plistVarSkip = true
				} else {
					mklines.plistVarSet[id] = mkline
				}
			}
		}
	}
}

func (mklines *MkLines) collectElse() {
	// Make a dry-run over the lines, which sets data.elseLine (in mkline.go) as a side-effect.
	mklines.ForEach(func(mkline *MkLine) {})
	// TODO: Check whether this ForEach is redundant because it is already run somewhere else.
}

func (mklines *MkLines) collectUsedVariables() {
	for _, mkline := range mklines.mklines {
		mkline.ForEachUsed(func(varUse *MkVarUse, time VucTime) {
			mklines.UseVar(mkline, varUse.varname, time)
		})
	}

	mklines.collectDocumentedVariables()
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
			for varname, mkline := range scope.used {
				mklines.vars.Define(varname, mkline)
				mklines.vars.Use(varname, mkline, VucRunTime)
			}
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

			parser := NewMkParser(nil, words[1], false)
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

// CheckUsedBy checks that this file (a Makefile.common) has the given
// relativeName in one of the "# used by" comments at the beginning of the file.
func (mklines *MkLines) CheckUsedBy(relativeName string) {
	lines := mklines.lines
	if lines.Len() < 3 {
		return
	}

	paras := mklines.SplitToParagraphs()

	expected := "# used by " + relativeName
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
			fix.InsertAfter("")
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
		fix.InsertAfter(expected)
		fix.Apply()
	}

	SaveAutofixChanges(lines)
}

func (mklines *MkLines) SaveAutofixChanges() {
	mklines.lines.SaveAutofixChanges()
}

func (mklines *MkLines) EOFLine() *MkLine {
	return MkLineParser{}.Parse(mklines.lines.EOFLine())
}

// VaralignBlock checks that all variable assignments from a paragraph
// use the same indentation depth for their values.
// It also checks that the indentation uses tabs instead of spaces.
//
// In general, all values should be aligned using tabs.
// As an exception, very long lines may be aligned with a single space.
// A typical example is a SITES.very-long-file-name.tar.gz variable
// between HOMEPAGE and DISTFILES.
type VaralignBlock struct {
	infos []*varalignBlockInfo
	skip  bool
}

type varalignBlockInfo struct {
	mkline         *MkLine
	varnameOp      string // Variable name + assignment operator
	varnameOpWidth int    // Screen width of varnameOp
	space          string // Whitespace between varnameOp and the variable value
	totalWidth     int    // Screen width of varnameOp + space
	continuation   bool   // A continuation line with no value in the first line.
}

func (va *VaralignBlock) Process(mkline *MkLine) {
	switch {
	case !G.Opts.WarnSpace:
		return

	case mkline.IsEmpty():
		va.Finish()
		return

	case mkline.IsVarassign(), mkline.IsCommentedVarassign():
		va.processVarassign(mkline)

	case mkline.IsComment(), mkline.IsDirective():
		return

	default:
		trace.Stepf("Skipping")
		va.skip = true
		return
	}
}

func (va *VaralignBlock) processVarassign(mkline *MkLine) {
	switch {
	case mkline.Op() == opAssignEval && matches(mkline.Varname(), `^[a-z]`):
		// Arguments to procedures do not take part in block alignment.
		//
		// Example:
		// pkgpath := ${PKGPATH}
		return

	case mkline.Value() == "" && mkline.VarassignComment() == "":
		// Multiple-inclusion guards usually appear in a block of
		// their own and therefore do not need alignment.
		//
		// Example:
		// .if !defined(INCLUSION_GUARD_MK)
		// INCLUSION_GUARD_MK:=
		// # ...
		// .endif
		return
	}

	continuation := false
	if mkline.IsMultiline() {
		// Parsing the continuation marker as variable value is cheating but works well.
		text := strings.TrimSuffix(mkline.raw[0].orignl, "\n")
		data := MkLineParser{}.split(nil, text)
		m, a := MkLineParser{}.MatchVarassign(mkline.Line, text, data)
		assert(m)
		continuation = a.value == "\\"
	}

	valueAlign := mkline.ValueAlign()
	varnameOp := strings.TrimRight(valueAlign, " \t")
	space := valueAlign[len(varnameOp):]

	width := tabWidth(valueAlign)
	va.infos = append(va.infos, &varalignBlockInfo{mkline, varnameOp, tabWidth(varnameOp), space, width, continuation})
}

func (va *VaralignBlock) Finish() {
	infos := va.infos
	skip := va.skip
	*va = VaralignBlock{}

	if len(infos) == 0 || skip {
		return
	}

	if trace.Tracing {
		defer trace.Call(infos[0].mkline.Line)()
	}

	newWidth := va.optimalWidth(infos)
	if newWidth == 0 {
		return
	}

	for _, info := range infos {
		va.realign(info.mkline, info.varnameOp, info.space, info.continuation, newWidth)
	}
}

// optimalWidth computes the minimum necessary screen width for the
// variable assignment lines. There may be a single line sticking out
// from the others (called outlier). This is to prevent a single SITES.*
// variable from forcing the rest of the paragraph to be indented too
// far to the right.
func (va *VaralignBlock) optimalWidth(infos []*varalignBlockInfo) int {
	longest := 0       // The longest seen varnameOpWidth
	secondLongest := 0 // The second-longest seen varnameOpWidth
	for _, info := range infos {
		if info.continuation {
			continue
		}

		width := info.varnameOpWidth
		if width >= longest {
			secondLongest = longest
			longest = width
		} else if width > secondLongest {
			secondLongest = width
		}
	}

	// Minimum required width of varnameOp, without the trailing whitespace.
	minVarnameOpWidth := longest
	outlier := 0
	if secondLongest != 0 && secondLongest/8+1 < longest/8 {
		minVarnameOpWidth = secondLongest
		outlier = longest
	}

	// Widths of the current indentation (including whitespace)
	minTotalWidth := 0
	maxTotalWidth := 0
	for _, info := range infos {
		if info.continuation {
			continue
		}

		if width := info.totalWidth; info.varnameOpWidth != outlier {
			if minTotalWidth == 0 || width < minTotalWidth {
				minTotalWidth = width
			}
			maxTotalWidth = imax(maxTotalWidth, width)
		}
	}

	if trace.Tracing {
		trace.Stepf("Indentation including whitespace is between %d and %d.",
			minTotalWidth, maxTotalWidth)
		trace.Stepf("Minimum required indentation is %d + 1.", minVarnameOpWidth)
		if outlier != 0 {
			trace.Stepf("The outlier is at indentation %d.", outlier)
		}
	}

	if minTotalWidth > minVarnameOpWidth && minTotalWidth == maxTotalWidth && minTotalWidth%8 == 0 {
		// The whole paragraph is already indented to the same width.
		return minTotalWidth
	}

	if minVarnameOpWidth == 0 {
		// Only continuation lines in this paragraph.
		return 0
	}

	return (minVarnameOpWidth & -8) + 8
}

func (va *VaralignBlock) realign(mkline *MkLine, varnameOp, oldSpace string, continuation bool, newWidth int) {
	hasSpace := contains(oldSpace, " ")

	newSpace := ""
	for tabWidth(varnameOp+newSpace) < newWidth {
		newSpace += "\t"
	}
	// Indent the outlier with a space instead of a tab to keep the line short.
	if newSpace == "" {
		if hasPrefix(oldSpace, "\t") {
			// Even though it is an outlier, it uses a tab and therefore
			// didn't seem to be too long to the original developer.
			// Therefore, leave it as-is but still fix any continuation lines.
			newSpace = oldSpace
		} else {
			newSpace = " "
		}
	}

	va.realignInitialLine(mkline, varnameOp, oldSpace, newSpace, hasSpace, newWidth)
	if mkline.IsMultiline() {
		va.realignContinuationLines(mkline, newWidth)
	}
}

func (va *VaralignBlock) realignInitialLine(mkline *MkLine, varnameOp string, oldSpace string, newSpace string, hasSpace bool, newWidth int) {
	wrongColumn := tabWidth(varnameOp+oldSpace) != tabWidth(varnameOp+newSpace)

	fix := mkline.Autofix()

	switch {
	case hasSpace && wrongColumn:
		fix.Notef("This variable value should be aligned with tabs, not spaces, to column %d.", newWidth+1)
	case hasSpace && oldSpace != newSpace:
		fix.Notef("Variable values should be aligned with tabs, not spaces.")
	case wrongColumn:
		fix.Notef("This variable value should be aligned to column %d.", newWidth+1)
	default:
		return
	}

	if wrongColumn {
		fix.Explain(
			"Normally, all variable values in a block should start at the same column.",
			"This provides orientation, especially for sequences",
			"of variables that often appear in the same order.",
			"For these it suffices to look at the variable values only.",
			"",
			"There are some exceptions to this rule:",
			"",
			"Definitions for long variable names may be indented with a single space instead of tabs,",
			"but only if they appear in a block that is otherwise indented using tabs.",
			"",
			"Variable definitions that span multiple lines are not checked for alignment at all.",
			"",
			"When the block contains something else than variable definitions",
			"and directives like .if or .for, it is not checked at all.")
	}

	fix.ReplaceAfter(varnameOp, oldSpace, newSpace)
	fix.Apply()
}

func (va *VaralignBlock) realignContinuationLines(mkline *MkLine, newWidth int) {
	indentation := strings.Repeat("\t", newWidth/8) + strings.Repeat(" ", newWidth%8)
	fix := mkline.Autofix()
	fix.Notef("This line should be aligned with %q.", indentation)
	fix.Realign(mkline, newWidth)
	fix.Apply()
}
