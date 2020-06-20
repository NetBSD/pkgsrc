package pkglint

import "netbsd.org/pkglint/textproc"

// SubstContext records the state of a block of variable assignments
// that make up a SUBST class.
//
// See mk/subst.mk.
type SubstContext struct {
	// points to a block somewhere in scopes.
	active *substBlock

	scopes []*substScope

	once Once
	pkg  *Package
}

func NewSubstContext(pkg *Package) *SubstContext {
	return &SubstContext{nil, []*substScope{newSubstScope()}, Once{}, pkg}
}

func (ctx *SubstContext) Process(mkline *MkLine) {
	switch {
	case mkline.IsEmpty():
		ctx.emptyLine()
	case mkline.IsVarassign():
		ctx.varassign(mkline)
	case mkline.IsDirective():
		ctx.directive(mkline)
	}
}

func (ctx *SubstContext) Finish(diag Diagnoser) {
	// Prevent panics on unbalanced conditionals.
	for len(ctx.scopes) > 1 {
		ctx.leave(diag)
	}

	for _, scope := range ctx.scopes {
		scope.finish(diag)
	}
}

func (ctx *SubstContext) emptyLine() {
	for _, scope := range ctx.scopes {
		scope.emptyLine()
	}
}

func (ctx *SubstContext) varassign(mkline *MkLine) {
	varcanon := mkline.Varcanon()
	if varcanon == "SUBST_CLASSES" || varcanon == "SUBST_CLASSES.*" {
		ctx.varassignClasses(mkline)
		return
	}

	if ctx.isForeign(mkline.Varcanon()) {
		if ctx.isActive() && !ctx.block().seenEmpty {
			ctx.block().rememberForeign(mkline)
		}
		return
	}

	if !ctx.isActive() {
		if !ctx.varassignOutsideBlock(mkline) {
			return
		}
	}

	if mkline.Varparam() != ctx.activeId() {
		if !ctx.varassignDifferentClass(mkline) {
			return
		}
	}

	block := ctx.block()
	block.varassign(mkline, ctx.pkg)
}

func (ctx *SubstContext) varassignClasses(mkline *MkLine) {
	ids := mkline.ValueFieldsLiteral()
	if len(ids) == 0 {
		return
	}

	if len(ids) > 1 {
		mkline.Notef("Please add only one class at a time to SUBST_CLASSES.")
		mkline.Explain(
			"This way, each substitution class forms a block in the package Makefile,",
			"and to delete this block, it is not necessary to look anywhere else.")
	}

	ctx.prepareSubstClasses(mkline)
	ctx.deactivate(mkline)

	for _, id := range ids {
		if ctx.lookup(id) == nil {
			ctx.scopes[len(ctx.scopes)-1].define(id)
		} else if mkline.Varparam() == "" {
			mkline.Errorf("Duplicate SUBST class %q.", id)
		}
	}
}

func (ctx *SubstContext) prepareSubstClasses(mkline *MkLine) {
	for _, scope := range ctx.scopes {
		scope.prepareSubstClasses(mkline)
	}
}

// varassignOutsideBlock handles variable assignments of SUBST variables that
// appear without a directly corresponding SUBST block.
func (ctx *SubstContext) varassignOutsideBlock(mkline *MkLine) (continueWithNewId bool) {
	id := mkline.Varparam()

	if id != "" && ctx.isListCanon(mkline.Varcanon()) && ctx.isDone(id) {
		if mkline.Op() != opAssignAppend {
			mkline.Warnf("Late additions to a SUBST variable should use the += operator.")
		}
		return
	}

	return ctx.activate(mkline, ctx.lookup(id) == nil)
}

func (ctx *SubstContext) varassignDifferentClass(mkline *MkLine) (ok bool) {
	varname := mkline.Varname()
	unknown := ctx.lookup(mkline.Varparam()) == nil
	if unknown && !ctx.block().isComplete() {
		mkline.Warnf("Variable %q does not match SUBST class %q.",
			varname, ctx.activeId())
		if !ctx.block().seenEmpty {
			return false
		}
	}

	return ctx.activate(mkline, unknown)
}

func (ctx *SubstContext) directive(mkline *MkLine) {
	dir := mkline.Directive()
	switch dir {
	case "if":
		ctx.enter()
	case "elif":
		ctx.nextBranch(mkline, false)
	case "else":
		ctx.nextBranch(mkline, true)
	case "endif":
		ctx.leave(mkline)
	}
}

func (ctx *SubstContext) enter() {
	for _, scope := range ctx.scopes {
		scope.enter()
	}
	ctx.scopes = append(ctx.scopes, newSubstScope())
}

func (ctx *SubstContext) nextBranch(diag Diagnoser, isElse bool) {
	if ctx.isActive() && !ctx.block().isConditional() {
		ctx.deactivate(diag)
	}

	for _, scope := range ctx.scopes {
		scope.nextBranch(diag, isElse)
	}
}

func (ctx *SubstContext) leave(diag Diagnoser) {
	ctx.deactivate(diag)

	for _, scope := range ctx.scopes {
		scope.leave(diag)
	}

	if len(ctx.scopes) > 1 {
		ctx.scopes = ctx.scopes[:len(ctx.scopes)-1]
	}
}

func (ctx *SubstContext) activate(mkline *MkLine, deactivate bool) bool {
	id := mkline.Varparam()
	if id == "" {
		mkline.Errorf("Invalid SUBST class %q in variable name.", id)
		return false
	}

	if deactivate {
		ctx.deactivate(mkline)
	}

	if block := ctx.lookup(id); block != nil {
		ctx.active = block
		return true
	}

	if ctx.once.FirstTime(id) && !mkline.HasRationale(id) {
		mkline.Warnf("Before defining %s, the SUBST class "+
			"should be declared using \"SUBST_CLASSES+= %s\".",
			mkline.Varname(), id)
	}
	return false
}

func (ctx *SubstContext) deactivate(diag Diagnoser) {
	if !ctx.isActive() {
		return
	}

	block := ctx.block()
	if !block.isConditional() {
		block.finish(diag)
	}
	ctx.active = nil
}

func (*SubstContext) isForeign(varcanon string) bool {
	// keep in sync with substBlock.varassign

	switch varcanon {
	case
		"SUBST_STAGE.*",
		"SUBST_MESSAGE.*",
		"SUBST_FILES.*",
		"SUBST_SED.*",
		"SUBST_VARS.*",
		"SUBST_FILTER_CMD.*",
		"SUBST_SKIP_TEXT_CHECK.*", // TODO: remove this from subst.mk (unneeded)
		"SUBST_SHOW_DIFF.*",       // TODO: remove this from subst.mk (unneeded)
		"SUBST_NOOP_OK.*":
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

func (ctx *SubstContext) block() *substBlock {
	assertNotNil(ctx.active)
	return ctx.active
}

func (ctx *SubstContext) lookup(id string) *substBlock {
	for i := len(ctx.scopes) - 1; i >= 0; i-- {
		if def := ctx.scopes[i].def(id); def != nil {
			return def
		}
	}
	return nil
}

func (ctx *SubstContext) isDone(id string) bool {
	for _, scope := range ctx.scopes {
		if scope.isDone(id) {
			return true
		}
	}
	return false
}

func (ctx *SubstContext) isActive() bool { return ctx.active != nil }

func (ctx *SubstContext) activeId() string {
	assert(ctx.isActive())
	return ctx.active.id
}

type substScope struct {
	defs []*substBlock
}

func newSubstScope() *substScope {
	return &substScope{nil}
}

func (s *substScope) def(id string) *substBlock {
	for _, def := range s.defs {
		if def.id == id {
			return def
		}
	}
	return nil
}

func (s *substScope) define(id string) {
	assert(s.def(id) == nil)
	s.defs = append(s.defs, newSubstBlock(id))
}

func (s *substScope) isDone(id string) bool {
	def := s.def(id)
	return def != nil && def.done
}

func (s *substScope) emptyLine() {
	for _, block := range s.defs {
		block.seenEmpty = true
	}
}

// finish brings all blocks that are defined in the current scope
// to an end.
func (s *substScope) finish(diag Diagnoser) {
	foreignOk := map[string]bool{}
	for _, def := range s.defs {
		for allowed := range def.foreignAllowed {
			foreignOk[allowed] = true
		}
	}

	for _, block := range s.defs {
		block.finish(diag)

		for _, mkline := range block.foreign {
			if !foreignOk[mkline.Varname()] {
				mkline.Warnf("Foreign variable %q in SUBST block.",
					mkline.Varname())
			}
		}
	}
}

func (s *substScope) prepareSubstClasses(diag Diagnoser) {
	for _, block := range s.defs {
		if block.hasStarted() && !block.isComplete() {
			diag.Warnf("Subst block %q should be finished "+
				"before adding the next class to SUBST_CLASSES.",
				block.id)
		}
	}
}

func (s *substScope) enter() {
	for _, block := range s.defs {
		block.enter()
	}
}

func (s *substScope) nextBranch(diag Diagnoser, isElse bool) {
	for _, block := range s.defs {
		if block.isConditional() {
			block.nextBranch(isElse)
		} else {
			block.finish(diag)
		}
	}
}

func (s *substScope) leave(diag Diagnoser) {
	for _, block := range s.defs {
		if block.isConditional() {
			block.leave()
		} else {
			block.finish(diag)
		}
	}
}

type substBlock struct {
	id string

	// Records which of the SUBST variables have been seen either
	// directly or in a conditional branch.
	conds []*substCond

	// In the paragraph of a SUBST block, there should be only variables
	// that actually belong to the SUBST block.
	//
	// In addition, variables that are mentioned in SUBST_VARS may also
	// be defined there because they closely relate to the SUBST block.
	foreignAllowed map[string]struct{}
	foreign        []*MkLine

	// Whether there has been an empty line between the SUBST_CLASSES
	// line and the current line.
	//
	// Before the empty line, variables that don't obviously belong to
	// this SUBST block generate warnings since they may be typos,
	// such as for a different SUBST block.
	seenEmpty bool

	// Whether the SUBST_CLASSES has already gone out of scope.
	//
	// XXX: When it is out of scope, it should also be unreachable
	//  by any pkglint code. There's something inconsistent here.
	done bool
}

func newSubstBlock(id string) *substBlock {
	assert(id != "")
	return &substBlock{id: id, conds: []*substCond{newSubstCond()}}
}

func (b *substBlock) varassign(mkline *MkLine, pkg *Package) {
	// keep in sync with SubstBlock.isForeign

	switch mkline.Varcanon() {
	case "SUBST_STAGE.*":
		b.varassignStage(mkline, pkg)
	case "SUBST_MESSAGE.*":
		b.varassignMessages(mkline)
	case "SUBST_FILES.*":
		b.varassignFiles(mkline)
	case "SUBST_SED.*":
		b.varassignSed(mkline)
	case "SUBST_VARS.*":
		b.varassignVars(mkline)
	case "SUBST_FILTER_CMD.*":
		b.varassignFilterCmd(mkline)
	}

	b.varassignAllowForeign(mkline)
}

func (b *substBlock) varassignStage(mkline *MkLine, pkg *Package) {
	if b.isConditional() {
		mkline.Warnf("%s should not be defined conditionally.", mkline.Varname())
	}

	b.dupString(mkline, ssStage)

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

	if pkg != nil && (value == "pre-configure" || value == "post-configure") {
		if noConfigureLine := pkg.vars.FirstDefinition("NO_CONFIGURE"); noConfigureLine != nil {
			mkline.Warnf("SUBST_STAGE %s has no effect when NO_CONFIGURE is set (in %s).",
				value, mkline.RelMkLine(noConfigureLine))
			mkline.Explain(
				"To fix this properly, remove the definition of NO_CONFIGURE.")
		}
	}
}

func (b *substBlock) varassignMessages(mkline *MkLine) {
	varname := mkline.Varname()

	if b.isConditional() {
		mkline.Warnf("%s should not be defined conditionally.", varname)
	}

	b.dupString(mkline, ssMessage)
}

func (b *substBlock) varassignFiles(mkline *MkLine) {
	b.dupList(mkline, ssFiles, ssNone)
}

func (b *substBlock) varassignSed(mkline *MkLine) {
	b.dupList(mkline, ssSed, ssNone)
	b.addSeen(ssTransform)

	b.suggestSubstVars(mkline)
}

func (b *substBlock) varassignVars(mkline *MkLine) {
	b.dupList(mkline, ssVars, ssVarsAutofix)
	b.addSeen(ssTransform)

	for _, substVar := range mkline.Fields() {
		b.allowVar(substVar)
	}
}

func (b *substBlock) varassignFilterCmd(mkline *MkLine) {
	b.dupString(mkline, ssFilterCmd)
	b.addSeen(ssTransform)
}

func (b *substBlock) varassignAllowForeign(mkline *MkLine) {
	mkline.ForEachUsed(func(varUse *MkVarUse, time VucTime) {
		b.allowVar(varUse.varname)
	})
}

func (b *substBlock) suggestSubstVars(mkline *MkLine) {

	tokens, _ := splitIntoShellTokens(mkline.Line, mkline.Value())
	for _, token := range tokens {
		varname := b.extractVarname(mkline.UnquoteShell(token, false))
		if varname == "" {
			continue
		}

		id := b.id
		varop := sprintf("SUBST_VARS.%s%s%s",
			id,
			condStr(hasSuffix(id, "+"), " ", ""),
			condStr(b.hasSeen(ssVars), "+=", "="))

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

		b.addSeen(ssVars)
		b.addSeen(ssVarsAutofix)
	}
}

func (b *substBlock) dupString(mkline *MkLine, part substSeen) {
	if b.hasSeen(part) {
		mkline.Warnf("Duplicate definition of %q.", mkline.Varname())
	}
	b.addSeen(part)
}

func (b *substBlock) dupList(mkline *MkLine, part substSeen, autofixPart substSeen) {
	if b.hasSeenAnywhere(part) && mkline.Op() != opAssignAppend {
		b.fixOperatorAppend(mkline, b.hasSeen(autofixPart))
	}
	b.addSeen(part)
}

func (b *substBlock) fixOperatorAppend(mkline *MkLine, dueToAutofix bool) {
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

// extractVarname extracts the variable name from a sed command of the form
// s,@VARNAME@,${VARNAME}, and some related variants thereof.
func (*substBlock) extractVarname(token string) string {
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

func (b *substBlock) isComplete() bool {
	return b.allSeen().hasAll(ssStage | ssFiles | ssTransform)
}

func (b *substBlock) hasSeen(part substSeen) bool {
	for _, cond := range b.conds {
		if cond.hasSeen(part) {
			return true
		}
	}
	return false
}

func (b *substBlock) hasSeenAnywhere(part substSeen) bool {
	for _, cond := range b.conds {
		if cond.hasSeenAnywhere(part) {
			return true
		}
	}
	return false
}

func (b *substBlock) allSeen() substSeen {
	all := ssNone
	for _, cond := range b.conds {
		all.addAll(cond.curr)
	}
	return all
}

func (b *substBlock) addSeen(part substSeen) {
	b.conds[len(b.conds)-1].addSeen(part)
}

func (b *substBlock) rememberForeign(mkline *MkLine) {
	b.foreign = append(b.foreign, mkline)
}

// isConditional returns whether the current line is at a deeper conditional
// level than the corresponding SUBST_CLASSES line.
func (b *substBlock) isConditional() bool { return len(b.conds) > 1 }

func (b *substBlock) allowVar(varname string) {
	if b.foreignAllowed == nil {
		b.foreignAllowed = map[string]struct{}{}
	}
	b.foreignAllowed[varname] = struct{}{}
}

func (b *substBlock) enter() { b.conds = append(b.conds, newSubstCond()) }

func (b *substBlock) nextBranch(isElse bool) {
	cond := b.conds[len(b.conds)-1]
	cond.leaveBranch()
	cond.enterBranch(isElse)
}

func (b *substBlock) leave() {
	assert(b.isConditional())

	n := len(b.conds)
	b.conds[n-2].leaveLevel(b.conds[n-1])
	b.conds = b.conds[:n-1]
}

func (b *substBlock) finish(diag Diagnoser) {
	assert(len(b.conds) == 1)

	if b.done {
		return
	}
	b.done = true

	if !b.hasStarted() {
		diag.Warnf("Missing SUBST block for %q.", b.id)
		return
	}

	if !b.hasSeen(ssStage) {
		diag.Warnf("Incomplete SUBST block: SUBST_STAGE.%s missing.", b.id)
	}
	if !b.hasSeen(ssFiles) {
		diag.Warnf("Incomplete SUBST block: SUBST_FILES.%s missing.", b.id)
	}
	if !b.hasSeen(ssTransform) {
		diag.Warnf(
			"Incomplete SUBST block: SUBST_SED.%[1]s, "+
				"SUBST_VARS.%[1]s or SUBST_FILTER_CMD.%[1]s missing.",
			b.id)
	}
}

func (b *substBlock) hasStarted() bool {
	for _, cond := range b.conds {
		if cond.currAny != ssNone {
			return true
		}
	}
	return false
}

type substCond struct {
	// Collects the parts of the SUBST block that have been defined in all
	// branches that have been parsed completely.
	total    substSeen
	totalAny substSeen

	// Collects the parts of the SUBST block that are defined in the current
	// branch of the conditional. At the end of the branch, they are merged
	// into the total.
	curr    substSeen
	currAny substSeen

	// Marks whether the current conditional statement has
	// an .else branch. If it doesn't, this means that all variables
	// are potentially unset in that branch.
	seenElse bool
}

func newSubstCond() *substCond { return &substCond{total: ssAll} }

func (c *substCond) enterBranch(isElse bool) {
	c.curr = ssNone
	c.currAny = ssNone
	c.seenElse = isElse
}

func (c *substCond) leaveBranch() {
	c.total.retainAll(c.curr)
	c.totalAny.addAll(c.currAny)
	c.curr = ssNone
	c.currAny = ssNone
}

func (c *substCond) leaveLevel(child *substCond) {
	child.leaveBranch()
	if child.seenElse {
		c.curr.addAll(child.total)
	}
	c.currAny.addAll(child.totalAny)
}

func (c *substCond) hasSeen(part substSeen) bool { return c.curr.has(part) }

func (c *substCond) hasSeenAnywhere(part substSeen) bool {
	return c.currAny.has(part)
}

func (c *substCond) addSeen(part substSeen) {
	c.curr.set(part)
	c.currAny.set(part)
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

func (s *substSeen) set(part substSeen) {
	assert(part&(part-1) == 0)
	*s |= part
}

func (s *substSeen) has(part substSeen) bool {
	assert(part&(part-1) == 0)
	return *s&part != 0
}

func (s substSeen) hasAll(other substSeen) bool { return s&other == other }
func (s *substSeen) addAll(other substSeen)     { *s |= other }
func (s *substSeen) retainAll(other substSeen)  { *s &= other }
