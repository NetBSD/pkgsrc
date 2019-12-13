package pkglint

import "netbsd.org/pkglint/textproc"

// SubstContext records the state of a block of variable assignments
// that make up a SUBST class (see `mk/subst.mk`).
type SubstContext struct {
	queuedIds []string
	id        string
	doneIds   map[string]bool

	foreignAllowed map[string]struct{}
	foreign        []*MkLine

	conds []*substCond

	once Once
}

func NewSubstContext() *SubstContext {
	ctx := SubstContext{}
	ctx.reset()
	return &ctx
}

func (ctx *SubstContext) Process(mkline *MkLine) {
	switch {
	case mkline.IsEmpty():
		ctx.finishClass(mkline)
	case mkline.IsVarassign():
		ctx.varassign(mkline)
	case mkline.IsDirective():
		ctx.directive(mkline)
	}
}

func (ctx *SubstContext) Finish(diag Diagnoser) {
	ctx.finishClass(diag)
	ctx.finishFile(diag)
}

func (ctx *SubstContext) varassign(mkline *MkLine) {
	varcanon := mkline.Varcanon()
	if varcanon == "SUBST_CLASSES" || varcanon == "SUBST_CLASSES.*" {
		ctx.varassignClasses(mkline)
		return
	}

	if ctx.isForeign(mkline.Varcanon()) {
		if ctx.isActive() {
			ctx.rememberForeign(mkline)
		}
		return
	}

	if !ctx.isActive() {
		if !ctx.varassignOutsideBlock(mkline) {
			return
		}
	}

	if hasPrefix(mkline.Varname(), "SUBST_") && !ctx.isActiveId(mkline.Varparam()) {
		if !ctx.varassignDifferentClass(mkline) {
			return
		}
	}

	switch varcanon {
	case "SUBST_STAGE.*":
		ctx.varassignStage(mkline)
	case "SUBST_MESSAGE.*":
		ctx.varassignMessages(mkline)
	case "SUBST_FILES.*":
		ctx.varassignFiles(mkline)
	case "SUBST_SED.*":
		ctx.varassignSed(mkline)
	case "SUBST_VARS.*":
		ctx.varassignVars(mkline)
	case "SUBST_FILTER_CMD.*":
		ctx.varassignFilterCmd(mkline)
	}
}

func (ctx *SubstContext) varassignClasses(mkline *MkLine) {
	classes := mkline.ValueFields(mkline.WithoutMakeVariables(mkline.Value()))
	if len(classes) == 0 {
		return
	}

	if len(classes) > 1 {
		mkline.Notef("Please add only one class at a time to SUBST_CLASSES.")
		mkline.Explain(
			"This way, each substitution class forms a block in the package Makefile,",
			"and to delete this block, it is not necessary to look anywhere else.")
	}
	for _, class := range classes {
		ctx.queue(class)
	}

	id := classes[0]
	if ctx.isActive() && !ctx.isActiveId(id) {
		id := ctx.activeId() // since ctx.condEndif may reset it

		for ctx.isConditional() {
			// This will be confusing for the outer SUBST block,
			// but since that block is assumed to be finished,
			// this doesn't matter.
			ctx.condEndif(mkline)
		}

		complete := ctx.isComplete() // since ctx.finishClass will reset it
		ctx.finishClass(mkline)
		if !complete {
			mkline.Warnf("Subst block %q should be finished before adding the next class to SUBST_CLASSES.", id)
		}
	}

	ctx.setActiveId(id)

	return
}

// varassignOutsideBlock handles variable assignments of SUBST variables that
// appear without a directly corresponding SUBST block.
func (ctx *SubstContext) varassignOutsideBlock(mkline *MkLine) (continueWithNewId bool) {
	varparam := mkline.Varparam()

	if ctx.isListCanon(mkline.Varcanon()) && ctx.isDone(varparam) {
		if mkline.Op() != opAssignAppend {
			mkline.Warnf("Late additions to a SUBST variable should use the += operator.")
		}
		return
	}
	if containsWord(mkline.Rationale(), varparam) {
		return
	}

	if ctx.start(varparam) {
		return true
	}

	if ctx.once.FirstTime(varparam) {
		mkline.Warnf("Before defining %s, the SUBST class "+
			"should be declared using \"SUBST_CLASSES+= %s\".",
			mkline.Varname(), varparam)
	}
	return
}

func (ctx *SubstContext) varassignDifferentClass(mkline *MkLine) (ok bool) {
	varname := mkline.Varname()
	varparam := mkline.Varparam()

	if !ctx.isComplete() {
		mkline.Warnf("Variable %q does not match SUBST class %q.", varname, ctx.activeId())
		return false
	}

	ctx.finishClass(mkline)

	ctx.start(varparam)
	return true
}

func (ctx *SubstContext) varassignStage(mkline *MkLine) {
	if ctx.isConditional() {
		mkline.Warnf("%s should not be defined conditionally.", mkline.Varname())
	}

	ctx.dupString(mkline, ssStage)

	value := mkline.Value()
	if value == "pre-patch" || value == "post-patch" {
		fix := mkline.Autofix()
		fix.Warnf("Substitutions should not happen in the patch phase.")
		fix.Explain(
			"Performing substitutions during post-patch breaks tools such as",
			"mkpatches, making it very difficult to regenerate correct patches",
			"after making changes, and often leading to substituted string",
			"replacements being committed.",
			"",
			"Instead of pre-patch, use post-extract.",
			"Instead of post-patch, use pre-configure.")
		fix.Replace("pre-patch", "post-extract")
		fix.Replace("post-patch", "pre-configure")
		fix.Apply()
	}

	if G.Pkg != nil && (value == "pre-configure" || value == "post-configure") {
		if noConfigureLine := G.Pkg.vars.FirstDefinition("NO_CONFIGURE"); noConfigureLine != nil {
			mkline.Warnf("SUBST_STAGE %s has no effect when NO_CONFIGURE is set (in %s).",
				value, mkline.RelMkLine(noConfigureLine))
			mkline.Explain(
				"To fix this properly, remove the definition of NO_CONFIGURE.")
		}
	}
}

func (ctx *SubstContext) varassignMessages(mkline *MkLine) {
	varname := mkline.Varname()

	if ctx.isConditional() {
		mkline.Warnf("%s should not be defined conditionally.", varname)
	}

	ctx.dupString(mkline, ssMessage)
}

func (ctx *SubstContext) varassignFiles(mkline *MkLine) {
	ctx.dupList(mkline, ssFiles, ssNone)
}

func (ctx *SubstContext) varassignSed(mkline *MkLine) {
	ctx.dupList(mkline, ssSed, ssNone)
	ctx.seen().set(ssTransform)

	ctx.suggestSubstVars(mkline)
}

func (ctx *SubstContext) varassignVars(mkline *MkLine) {
	ctx.dupList(mkline, ssVars, ssVarsAutofix)
	ctx.seen().set(ssTransform)

	for _, substVar := range mkline.Fields() {
		ctx.allowVar(substVar)
	}
}

func (ctx *SubstContext) varassignFilterCmd(mkline *MkLine) {
	ctx.dupString(mkline, ssFilterCmd)
	ctx.seen().set(ssTransform)
}

func (ctx *SubstContext) dupList(mkline *MkLine, part substSeen, autofixPart substSeen) {
	if ctx.seenInBranch(part) && mkline.Op() != opAssignAppend {
		ctx.fixOperatorAppend(mkline, ctx.seenInBranch(autofixPart))
	}
	ctx.seen().set(part)
}

func (ctx *SubstContext) dupString(mkline *MkLine, part substSeen) {
	if ctx.seenInBranch(part) {
		mkline.Warnf("Duplicate definition of %q.", mkline.Varname())
	}
	ctx.seen().set(part)
}

func (ctx *SubstContext) fixOperatorAppend(mkline *MkLine, dueToAutofix bool) {
	before := mkline.ValueAlign()
	after := alignWith(mkline.Varname()+"+=", before)

	fix := mkline.Autofix()
	if dueToAutofix {
		fix.Notef(SilentAutofixFormat)
	} else {
		fix.Warnf("All but the first assignment to %q should use the \"+=\" operator.",
			mkline.Varname())
	}
	fix.Replace(before, after)
	fix.Apply()
}

func (ctx *SubstContext) suggestSubstVars(mkline *MkLine) {

	tokens, _ := splitIntoShellTokens(mkline.Line, mkline.Value())
	for _, token := range tokens {
		varname := ctx.extractVarname(mkline.UnquoteShell(token, false))
		if varname == "" {
			continue
		}

		id := ctx.activeId()
		varop := sprintf("SUBST_VARS.%s%s%s",
			id,
			condStr(hasSuffix(id, "+"), " ", ""),
			condStr(ctx.seenInBranch(ssVars), "+=", "="))

		fix := mkline.Autofix()
		fix.Notef("The substitution command %q can be replaced with \"%s %s\".",
			token, varop, varname)
		fix.Explain(
			"Replacing @VAR@ with ${VAR} is such a typical pattern that pkgsrc has built-in support for it,",
			"requiring only the variable name instead of the full sed command.")
		if !mkline.HasComment() && len(tokens) == 2 && tokens[0] == "-e" {
			fix.Replace(mkline.Text, alignWith(varop, mkline.ValueAlign())+varname)
		}
		fix.Apply()

		// At this point the number of SUBST_SED assignments is one
		// less than before. Therefore it is possible to adjust the
		// assignment operators on them. It's probably not worth the
		// effort, though.

		ctx.seen().set(ssVars | ssVarsAutofix)
	}
}

// extractVarname extracts the variable name from a sed command of the form
// s,@VARNAME@,${VARNAME}, and some related variants thereof.
func (*SubstContext) extractVarname(token string) string {
	parser := NewMkLexer(token, nil)
	lexer := parser.lexer
	if !lexer.SkipByte('s') {
		return ""
	}

	separator := lexer.NextByteSet(textproc.XPrint) // Really any character works
	if separator == -1 {
		return ""
	}

	if !lexer.SkipByte('@') {
		return ""
	}

	varname := parser.Varname()
	if !lexer.SkipByte('@') || !lexer.SkipByte(byte(separator)) {
		return ""
	}

	varuse := parser.VarUse()
	if varuse == nil || varuse.varname != varname {
		return ""
	}

	switch varuse.Mod() {
	case "", ":Q":
		break
	default:
		return ""
	}

	if !lexer.SkipByte(byte(separator)) {
		return ""
	}

	return varname
}

func (*SubstContext) isForeign(varcanon string) bool {
	switch varcanon {
	case
		"SUBST_STAGE.*",
		"SUBST_MESSAGE.*",
		"SUBST_FILES.*",
		"SUBST_SED.*",
		"SUBST_VARS.*",
		"SUBST_FILTER_CMD.*":
		return false
	}
	return true
}

func (*SubstContext) isListCanon(varcanon string) bool {
	switch varcanon {
	case
		"SUBST_FILES.*",
		"SUBST_SED.*",
		"SUBST_VARS.*":
		return true
	}
	return false
}

func (ctx *SubstContext) directive(mkline *MkLine) {
	dir := mkline.Directive()
	switch dir {
	case "if":
		ctx.condIf()

	case "elif", "else":
		ctx.condElse(mkline, dir)

	case "endif":
		ctx.condEndif(mkline)
	}
}

func (ctx *SubstContext) condIf() {
	top := substCond{total: ssAll}
	ctx.conds = append(ctx.conds, &top)
}

func (ctx *SubstContext) condElse(mkline *MkLine, dir string) {
	top := ctx.cond()
	top.total.retain(top.curr)
	if !ctx.isConditional() {
		ctx.finishClass(mkline)
	}
	top.curr = ssNone
	top.seenElse = dir == "else"
}

func (ctx *SubstContext) condEndif(diag Diagnoser) {
	top := ctx.cond()
	top.total.retain(top.curr)
	if !ctx.isConditional() {
		ctx.finishClass(diag)
	}
	if !top.seenElse {
		top.total = ssNone
	}
	if len(ctx.conds) > 1 {
		ctx.conds = ctx.conds[:len(ctx.conds)-1]
	}
	ctx.seen().union(top.total)
}

func (ctx *SubstContext) finishClass(diag Diagnoser) {
	if !ctx.isActive() {
		return
	}

	if ctx.seen().get(ssAll) {
		ctx.checkBlockComplete(diag)
		ctx.checkForeignVariables()
	} else {
		ctx.markAsNotDone()
	}

	ctx.reset()
}

func (ctx *SubstContext) checkBlockComplete(diag Diagnoser) {
	id := ctx.activeId()
	seen := ctx.seen()
	if !seen.get(ssStage) {
		diag.Warnf("Incomplete SUBST block: SUBST_STAGE.%s missing.", id)
	}
	if !seen.get(ssFiles) {
		diag.Warnf("Incomplete SUBST block: SUBST_FILES.%s missing.", id)
	}
	if !seen.get(ssTransform) {
		diag.Warnf("Incomplete SUBST block: SUBST_SED.%[1]s, SUBST_VARS.%[1]s or SUBST_FILTER_CMD.%[1]s missing.", id)
	}
}

func (ctx *SubstContext) checkForeignVariables() {
	ctx.forEachForeignVar(func(mkline *MkLine) {
		mkline.Warnf("Foreign variable %q in SUBST block.", mkline.Varname())
	})
}

func (ctx *SubstContext) finishFile(diag Diagnoser) {
	for _, id := range ctx.queuedIds {
		if id != "" && !ctx.isDone(id) {
			ctx.warnUndefinedBlock(diag, id)
		}
	}
}

func (*SubstContext) warnUndefinedBlock(diag Diagnoser, id string) {
	diag.Warnf("Missing SUBST block for %q.", id)
	diag.Explain(
		"After adding a SUBST class to SUBST_CLASSES,",
		"the remaining SUBST variables should be defined in the same file.",
		"",
		"See mk/subst.mk for the comprehensive documentation.")
}

// In the paragraph of a SUBST block, there should be only variables
// that actually belong to the SUBST block.
//
// In addition, variables that are mentioned in SUBST_VARS may also
// be defined there because they closely relate to the SUBST block.

func (ctx *SubstContext) allowVar(varname string) {
	if ctx.foreignAllowed == nil {
		ctx.foreignAllowed = make(map[string]struct{})
	}
	ctx.foreignAllowed[varname] = struct{}{}
}

func (ctx *SubstContext) rememberForeign(mkline *MkLine) {
	ctx.foreign = append(ctx.foreign, mkline)
}

// forEachForeignVar performs the given action for each variable that
// is defined in the SUBST block and is not mentioned in SUBST_VARS.
func (ctx *SubstContext) forEachForeignVar(action func(*MkLine)) {
	for _, foreign := range ctx.foreign {
		if _, ok := ctx.foreignAllowed[foreign.Varname()]; !ok {
			action(foreign)
		}
	}
}

func (ctx *SubstContext) reset() {
	ctx.id = ""
	ctx.foreignAllowed = nil
	ctx.foreign = nil
	ctx.conds = []*substCond{{seenElse: true}}
}

func (ctx *SubstContext) isActive() bool { return ctx.id != "" }

func (ctx *SubstContext) isActiveId(id string) bool { return ctx.id == id }

func (ctx *SubstContext) activeId() string {
	assert(ctx.isActive())
	return ctx.id
}

func (ctx *SubstContext) setActiveId(id string) {
	ctx.id = id
	ctx.cond().top = true
	ctx.markAsDone(id)
}

func (ctx *SubstContext) queue(id string) {
	ctx.queuedIds = append(ctx.queuedIds, id)
}

func (ctx *SubstContext) start(id string) bool {
	for i, queuedId := range ctx.queuedIds {
		if queuedId == id {
			ctx.queuedIds[i] = ""
			ctx.setActiveId(id)
			return true
		}
	}
	return false
}

func (ctx *SubstContext) markAsDone(id string) {
	if ctx.doneIds == nil {
		ctx.doneIds = map[string]bool{}
	}
	ctx.doneIds[id] = true
}

func (ctx *SubstContext) markAsNotDone() {
	ctx.doneIds[ctx.id] = false
}

func (ctx *SubstContext) isDone(varparam string) bool {
	return ctx.doneIds[varparam]
}

func (ctx *SubstContext) isComplete() bool {
	return ctx.seen().hasAll(ssStage | ssFiles | ssTransform)
}

// isConditional returns whether the current line is at a deeper conditional
// level than the assignment where the corresponding class ID is added to
// SUBST_CLASSES.
//
// TODO: Adjust the implementation to this description.
func (ctx *SubstContext) isConditional() bool {
	return !ctx.cond().top
}

// cond returns information about the parts of the SUBST block that
// have already been seen in the current leaf branch of the conditionals.
func (ctx *SubstContext) seen() *substSeen {
	return &ctx.cond().curr
}

// cond returns information about the current branch of conditionals.
func (ctx *SubstContext) cond() *substCond {
	return ctx.conds[len(ctx.conds)-1]
}

// Returns true if the given flag from substSeen has been seen
// somewhere in the conditional path of the current line.
func (ctx *SubstContext) seenInBranch(part substSeen) bool {
	for _, cond := range ctx.conds {
		if cond.curr.get(part) {
			return true
		}
	}
	return false
}

type substCond struct {
	// Tells whether a SUBST block has started at this conditional level.
	// All variable assignments that belong to this class must happen at
	// this conditional level or below it.
	//
	// TODO: For Test_SubstContext_Directive__conditional_complete,
	//  this needs to be changed to the set of classes that have been
	//  added to SUBST_CLASSES at this level.
	top bool

	// Collects the parts of the SUBST block that have been defined in all
	// branches that have been parsed completely.
	total substSeen

	// Collects the parts of the SUBST block that are defined in the current
	// branch of the conditional. At the end of the branch, they are merged
	// into the total.
	curr substSeen

	// Marks whether the current conditional statement has
	// an .else branch. If it doesn't, this means that all variables
	// are potentially unset in that branch.
	seenElse bool
}

// substSeen contains all variables that depend on a particular SUBST
// class ID. These variables can be set in conditional branches, and
// pkglint keeps track whether they are set in all branches or only
// in some of them.
type substSeen uint8

const (
	ssStage substSeen = 1 << iota
	ssMessage
	ssFiles
	ssSed
	ssVars
	ssVarsAutofix
	ssFilterCmd
	ssTransform

	ssAll  substSeen = 1<<iota - 1
	ssNone substSeen = 0
)

func (s *substSeen) set(part substSeen)          { *s |= part }
func (s *substSeen) get(part substSeen) bool     { return *s&part != 0 }
func (s *substSeen) hasAll(other substSeen) bool { return *s&other == other }
func (s *substSeen) union(other substSeen)       { *s |= other }
func (s *substSeen) retain(other substSeen)      { *s &= other }
