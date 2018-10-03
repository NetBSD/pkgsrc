package main

import (
	"fmt"
	"reflect"
	"strings"
)

type MkShWalker struct {
	Callback struct {
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
	Context []MkShWalkerPathElement
}

type MkShWalkerPathElement struct {
	Index   int
	Element interface{}
}

func NewMkShWalker() *MkShWalker {
	return &MkShWalker{}
}

// Path returns a representation of the path in the AST that is
// currently visited.
func (w *MkShWalker) Path() string {
	var path []string
	for _, level := range w.Context {
		typeName := reflect.TypeOf(level.Element).Elem().Name()
		abbreviated := strings.Replace(typeName, "MkSh", "", 1)
		if level.Index == -1 {
			path = append(path, abbreviated)
		} else {
			path = append(path, fmt.Sprintf("%s[%d]", abbreviated, level.Index))
		}
	}
	return strings.Join(path, ".")
}

// Walk calls the given callback for each node of the parsed shell program,
// in visiting order from large to small.
func (w *MkShWalker) Walk(list *MkShList) {
	w.walkList(-1, list)

	G.Assertf(len(w.Context) == 0, "MkShWalker.Walk %v", w.Context)
}

func (w *MkShWalker) walkList(index int, list *MkShList) {
	w.push(index, list)

	if callback := w.Callback.List; callback != nil {
		callback(list)
	}

	for i, andor := range list.AndOrs {
		w.walkAndOr(i, andor)
	}

	w.pop()
}

func (w *MkShWalker) walkAndOr(index int, andor *MkShAndOr) {
	w.push(index, andor)

	if callback := w.Callback.AndOr; callback != nil {
		callback(andor)
	}

	for i, pipeline := range andor.Pipes {
		w.walkPipeline(i, pipeline)
	}

	w.pop()
}

func (w *MkShWalker) walkPipeline(index int, pipeline *MkShPipeline) {
	w.push(index, pipeline)

	if callback := w.Callback.Pipeline; callback != nil {
		callback(pipeline)
	}

	for i, command := range pipeline.Cmds {
		w.walkCommand(i, command)
	}

	w.pop()
}

func (w *MkShWalker) walkCommand(index int, command *MkShCommand) {
	w.push(index, command)

	if callback := w.Callback.Command; callback != nil {
		callback(command)
	}

	switch {
	case command.Simple != nil:
		w.walkSimpleCommand(-1, command.Simple)
	case command.Compound != nil:
		w.walkCompoundCommand(-1, command.Compound)
		w.walkRedirects(-1, command.Redirects)
	case command.FuncDef != nil:
		w.walkFunctionDefinition(-1, command.FuncDef)
		w.walkRedirects(-1, command.Redirects)
	}

	w.pop()
}

func (w *MkShWalker) walkSimpleCommand(index int, command *MkShSimpleCommand) {
	w.push(index, command)

	if callback := w.Callback.SimpleCommand; callback != nil {
		callback(command)
	}

	w.walkWords(0, command.Assignments)
	if command.Name != nil {
		w.walkWord(-1, command.Name)
	}
	w.walkWords(2, command.Args)
	w.walkRedirects(-1, command.Redirections)

	w.pop()
}

func (w *MkShWalker) walkCompoundCommand(index int, command *MkShCompoundCommand) {
	w.push(index, command)

	if callback := w.Callback.CompoundCommand; callback != nil {
		callback(command)
	}

	switch {
	case command.Brace != nil:
		w.walkList(-1, command.Brace)
	case command.Case != nil:
		w.walkCase(command.Case)
	case command.For != nil:
		w.walkFor(command.For)
	case command.If != nil:
		w.walkIf(command.If)
	case command.Loop != nil:
		w.walkLoop(command.Loop)
	case command.Subshell != nil:
		w.walkList(-1, command.Subshell)
	}

	w.pop()
}

func (w *MkShWalker) walkCase(caseClause *MkShCaseClause) {
	w.push(-1, caseClause)

	if callback := w.Callback.Case; callback != nil {
		callback(caseClause)
	}

	w.walkWord(0, caseClause.Word)
	for i, caseItem := range caseClause.Cases {
		w.push(i, caseItem)
		if callback := w.Callback.CaseItem; callback != nil {
			callback(caseItem)
		}
		w.walkWords(0, caseItem.Patterns)
		w.walkList(1, caseItem.Action)
		w.pop()
	}

	w.pop()
}

func (w *MkShWalker) walkFunctionDefinition(index int, funcdef *MkShFunctionDefinition) {
	w.push(index, funcdef)

	if callback := w.Callback.FunctionDefinition; callback != nil {
		callback(funcdef)
	}

	w.walkCompoundCommand(-1, funcdef.Body)

	w.pop()
}

func (w *MkShWalker) walkIf(ifClause *MkShIfClause) {
	w.push(-1, ifClause)

	if callback := w.Callback.If; callback != nil {
		callback(ifClause)
	}

	for i, cond := range ifClause.Conds {
		w.walkList(2*i, cond)
		w.walkList(2*i+1, ifClause.Actions[i])
	}
	if ifClause.Else != nil {
		w.walkList(2*len(ifClause.Conds), ifClause.Else)
	}

	w.pop()
}

func (w *MkShWalker) walkLoop(loop *MkShLoopClause) {
	w.push(-1, loop)

	if callback := w.Callback.Loop; callback != nil {
		callback(loop)
	}

	w.walkList(0, loop.Cond)
	w.walkList(1, loop.Action)

	w.pop()
}

func (w *MkShWalker) walkWords(index int, words []*ShToken) {
	if len(words) == 0 {
		return
	}

	w.push(index, words)

	if callback := w.Callback.Words; callback != nil {
		callback(words)
	}

	for i, word := range words {
		w.walkWord(i, word)
	}

	w.pop()
}

func (w *MkShWalker) walkWord(index int, word *ShToken) {
	w.push(index, word)

	if callback := w.Callback.Word; callback != nil {
		callback(word)
	}

	w.pop()
}

func (w *MkShWalker) walkRedirects(index int, redirects []*MkShRedirection) {
	if len(redirects) == 0 {
		return
	}

	w.push(index, redirects)

	if callback := w.Callback.Redirects; callback != nil {
		callback(redirects)
	}

	for i, redirect := range redirects {
		if callback := w.Callback.Redirect; callback != nil {
			callback(redirect)
		}

		w.walkWord(i, redirect.Target)
	}

	w.pop()
}

func (w *MkShWalker) walkFor(forClause *MkShForClause) {
	w.push(-1, forClause)

	if callback := w.Callback.For; callback != nil {
		callback(forClause)
	}
	if callback := w.Callback.Varname; callback != nil {
		callback(forClause.Varname)
	}

	w.walkWords(-1, forClause.Values)
	w.walkList(-1, forClause.Body)

	w.pop()
}

// Current provides access to the element that the walker is currently
// processing, especially its index as seen from its parent element.
func (w *MkShWalker) Current() MkShWalkerPathElement {
	return w.Context[len(w.Context)-1]
}

// Parent returns an ancestor element from the currently visited path.
// Parent(0) is the element that is currently visited,
// Parent(1) is its direct parent, and so on.
func (w *MkShWalker) Parent(steps int) interface{} {
	index := len(w.Context) - 1 - steps
	if index >= 0 {
		return w.Context[index].Element
	}
	return nil
}

func (w *MkShWalker) push(index int, element interface{}) {
	w.Context = append(w.Context, MkShWalkerPathElement{index, element})
}

func (w *MkShWalker) pop() {
	w.Context = w.Context[:len(w.Context)-1]
}
