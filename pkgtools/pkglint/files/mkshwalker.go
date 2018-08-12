package main

type MkShWalker struct {
}

func NewMkShWalker() *MkShWalker {
	return &MkShWalker{}
}

// Walk calls the given callback for each node of the parsed shell program,
// in visiting order from large to small.
func (w *MkShWalker) Walk(list *MkShList, callback *MkShWalkCallback) {
	w.walkList(list, callback)
}

func (w *MkShWalker) walkList(list *MkShList, callback *MkShWalkCallback) {
	if callback.List != nil {
		callback.List(list)
	}

	for _, andor := range list.AndOrs {
		w.walkAndOr(andor, callback)
	}
}

func (w *MkShWalker) walkAndOr(andor *MkShAndOr, callback *MkShWalkCallback) {
	if callback.AndOr != nil {
		callback.AndOr(andor)
	}

	for _, pipeline := range andor.Pipes {
		w.walkPipeline(pipeline, callback)
	}
}

func (w *MkShWalker) walkPipeline(pipeline *MkShPipeline, callback *MkShWalkCallback) {
	if callback.Pipeline != nil {
		callback.Pipeline(pipeline)
	}

	for _, command := range pipeline.Cmds {
		w.walkCommand(command, callback)
	}
}

func (w *MkShWalker) walkCommand(command *MkShCommand, callback *MkShWalkCallback) {
	if callback.Command != nil {
		callback.Command(command)
	}

	switch {
	case command.Simple != nil:
		w.walkSimpleCommand(command.Simple, callback)
	case command.Compound != nil:
		w.walkCompoundCommand(command.Compound, callback)
		w.walkRedirects(command.Redirects, callback)
	case command.FuncDef != nil:
		w.walkFunctionDefinition(command.FuncDef, callback)
		w.walkRedirects(command.Redirects, callback)
	}
}

func (w *MkShWalker) walkSimpleCommand(command *MkShSimpleCommand, callback *MkShWalkCallback) {
	if callback.SimpleCommand != nil {
		callback.SimpleCommand(command)
	}

	w.walkWords(command.Assignments, callback)
	if command.Name != nil {
		w.walkWord(command.Name, callback)
	}
	w.walkWords(command.Args, callback)
	w.walkRedirects(command.Redirections, callback)
}

func (w *MkShWalker) walkCompoundCommand(command *MkShCompoundCommand, callback *MkShWalkCallback) {
	if callback.CompoundCommand != nil {
		callback.CompoundCommand(command)
	}

	switch {
	case command.Brace != nil:
		w.walkList(command.Brace, callback)
	case command.Case != nil:
		w.walkCase(command.Case, callback)
	case command.For != nil:
		w.walkFor(command.For, callback)
	case command.If != nil:
		w.walkIf(command.If, callback)
	case command.Loop != nil:
		w.walkLoop(command.Loop, callback)
	case command.Subshell != nil:
		w.walkList(command.Subshell, callback)
	}
}

func (w *MkShWalker) walkCase(caseClause *MkShCaseClause, callback *MkShWalkCallback) {
	if callback.Case != nil {
		callback.Case(caseClause)
	}

	w.walkWord(caseClause.Word, callback)
	for _, caseItem := range caseClause.Cases {
		if callback.CaseItem != nil {
			callback.CaseItem(caseItem)
		}
		w.walkWords(caseItem.Patterns, callback)
		w.walkList(caseItem.Action, callback)
	}
}

func (w *MkShWalker) walkFunctionDefinition(funcdef *MkShFunctionDefinition, callback *MkShWalkCallback) {
	if callback.FunctionDefinition != nil {
		callback.FunctionDefinition(funcdef)
	}

	w.walkCompoundCommand(funcdef.Body, callback)
}

func (w *MkShWalker) walkIf(ifClause *MkShIfClause, callback *MkShWalkCallback) {
	if callback.If != nil {
		callback.If(ifClause)
	}

	for i, cond := range ifClause.Conds {
		w.walkList(cond, callback)
		w.walkList(ifClause.Actions[i], callback)
	}
	if ifClause.Else != nil {
		w.walkList(ifClause.Else, callback)
	}
}

func (w *MkShWalker) walkLoop(loop *MkShLoopClause, callback *MkShWalkCallback) {
	if callback.Loop != nil {
		callback.Loop(loop)
	}

	w.walkList(loop.Cond, callback)
	w.walkList(loop.Action, callback)
}

func (w *MkShWalker) walkWords(words []*ShToken, callback *MkShWalkCallback) {
	if len(words) != 0 {
		if callback.Words != nil {
			callback.Words(words)
		}

		for _, word := range words {
			w.walkWord(word, callback)
		}
	}
}

func (w *MkShWalker) walkWord(word *ShToken, callback *MkShWalkCallback) {
	if callback.Word != nil {
		callback.Word(word)
	}
}

func (w *MkShWalker) walkRedirects(redirects []*MkShRedirection, callback *MkShWalkCallback) {
	if len(redirects) != 0 {
		if callback.Redirects != nil {
			callback.Redirects(redirects)
		}

		for _, redirect := range redirects {
			if callback.Redirect != nil {
				callback.Redirect(redirect)
			}

			w.walkWord(redirect.Target, callback)
		}
	}
}

func (w *MkShWalker) walkFor(forClause *MkShForClause, callback *MkShWalkCallback) {
	if callback.For != nil {
		callback.For(forClause)
	}
	if callback.Varname != nil {
		callback.Varname(forClause.Varname)
	}

	w.walkWords(forClause.Values, callback)
	w.walkList(forClause.Body, callback)
}

type MkShWalkCallback struct {
	List               func(list *MkShList)
	AndOr              func(andor *MkShAndOr)
	Pipeline           func(pipeline *MkShPipeline)
	Command            func(command *MkShCommand)
	SimpleCommand      func(command *MkShSimpleCommand)
	CompoundCommand    func(command *MkShCompoundCommand)
	Case               func(caseClause *MkShCaseClause)
	CaseItem           func(caseItem *MkShCaseItem)
	FunctionDefinition func(funcdef *MkShFunctionDefinition)
	If                 func(ifClause *MkShIfClause)
	Loop               func(loop *MkShLoopClause)
	Words              func(words []*ShToken)
	Word               func(word *ShToken)
	Redirects          func(redirects []*MkShRedirection)
	Redirect           func(redirect *MkShRedirection)
	For                func(forClause *MkShForClause)
	Varname            func(varname string)
}

func NewMkShWalkCallback() *MkShWalkCallback {
	return &MkShWalkCallback{}
}
