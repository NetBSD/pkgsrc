package main

type MkShWalker struct {
}

func (w *MkShWalker) Walk(list *MkShList, callback func(node interface{})) {
	for element := range w.iterate(list) {
		callback(element)
	}
}

func (w *MkShWalker) iterate(list *MkShList) <-chan interface{} {
	elements := make(chan interface{})

	go func() {
		w.walkList(list, elements)
		close(elements)
	}()

	return elements
}

func (w *MkShWalker) walkList(list *MkShList, collector chan<- interface{}) {
	collector <- list

	for _, andor := range list.AndOrs {
		w.walkAndOr(andor, collector)
	}
}

func (w *MkShWalker) walkAndOr(andor *MkShAndOr, collector chan<- interface{}) {
	collector <- andor

	for _, pipeline := range andor.Pipes {
		w.walkPipeline(pipeline, collector)
	}
}

func (w *MkShWalker) walkPipeline(pipeline *MkShPipeline, collector chan<- interface{}) {
	collector <- pipeline

	for _, command := range pipeline.Cmds {
		w.walkCommand(command, collector)
	}
}

func (w *MkShWalker) walkCommand(command *MkShCommand, collector chan<- interface{}) {
	collector <- command

	switch {
	case command.Simple != nil:
		w.walkSimpleCommand(command.Simple, collector)
	case command.Compound != nil:
		w.walkCompoundCommand(command.Compound, collector)
		w.walkRedirects(command.Redirects, collector)
	case command.FuncDef != nil:
		w.walkFunctionDefinition(command.FuncDef, collector)
		w.walkRedirects(command.Redirects, collector)
	}
}

func (w *MkShWalker) walkSimpleCommand(command *MkShSimpleCommand, collector chan<- interface{}) {
	collector <- command

	w.walkWords(command.Assignments, collector)
	if command.Name != nil {
		w.walkWord(command.Name, collector)
	}
	w.walkWords(command.Args, collector)
	w.walkRedirects(command.Redirections, collector)
}

func (w *MkShWalker) walkCompoundCommand(command *MkShCompoundCommand, collector chan<- interface{}) {
	collector <- command

	switch {
	case command.Brace != nil:
		w.walkList(command.Brace, collector)
	case command.Case != nil:
		w.walkCase(command.Case, collector)
	case command.For != nil:
		w.walkFor(command.For, collector)
	case command.If != nil:
		w.walkIf(command.If, collector)
	case command.Loop != nil:
		w.walkLoop(command.Loop, collector)
	case command.Subshell != nil:
		w.walkList(command.Subshell, collector)
	}
}

func (w *MkShWalker) walkCase(caseClause *MkShCaseClause, collector chan<- interface{}) {
	collector <- caseClause

	w.walkWord(caseClause.Word, collector)
	for _, caseItem := range caseClause.Cases {
		collector <- caseItem
		w.walkWords(caseItem.Patterns, collector)
		w.walkList(caseItem.Action, collector)
	}
}

func (w *MkShWalker) walkFunctionDefinition(funcdef *MkShFunctionDefinition, collector chan<- interface{}) {
	collector <- funcdef

	w.walkCompoundCommand(funcdef.Body, collector)
}

func (w *MkShWalker) walkIf(ifClause *MkShIfClause, collector chan<- interface{}) {
	collector <- ifClause
	for i, cond := range ifClause.Conds {
		w.walkList(cond, collector)
		w.walkList(ifClause.Actions[i], collector)
	}
	if ifClause.Else != nil {
		w.walkList(ifClause.Else, collector)
	}
}

func (w *MkShWalker) walkLoop(loop *MkShLoopClause, collector chan<- interface{}) {
	collector <- loop
	w.walkList(loop.Cond, collector)
	w.walkList(loop.Action, collector)
}

func (w *MkShWalker) walkWords(words []*ShToken, collector chan<- interface{}) {
	collector <- words

	for _, word := range words {
		w.walkWord(word, collector)
	}
}

func (w *MkShWalker) walkWord(word *ShToken, collector chan<- interface{}) {
	collector <- word
}

func (w *MkShWalker) walkRedirects(redirects []*MkShRedirection, collector chan<- interface{}) {
	collector <- redirects

	for _, redirect := range redirects {
		collector <- redirect
		w.walkWord(redirect.Target, collector)
	}
}

func (w *MkShWalker) walkFor(forClause *MkShForClause, collector chan<- interface{}) {
	collector <- forClause

	collector <- forClause.Varname
	w.walkWords(forClause.Values, collector)
	w.walkList(forClause.Body, collector)
}
