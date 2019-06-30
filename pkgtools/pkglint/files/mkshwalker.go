package pkglint

import (
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
		Case               func(caseClause *MkShCase)
		CaseItem           func(caseItem *MkShCaseItem)
		FunctionDefinition func(funcdef *MkShFunctionDefinition)
		If                 func(ifClause *MkShIf)
		Loop               func(loop *MkShLoop)
		Words              func(words []*ShToken)
		Word               func(word *ShToken)
		Redirects          func(redirects []*MkShRedirection)
		Redirect           func(redirect *MkShRedirection)
		For                func(forClause *MkShFor)

		// For variable definition in a for loop.
		Varname func(varname string)
	}

	// Context[0] is the currently visited element,
	// Context[1] is its immediate parent element, and so on.
	// This is useful when the check for a CaseItem needs to look at the enclosing Case.
	Context []MkShWalkerPathElement
}

type MkShWalkerPathElement struct {

	// For fields that can be repeated, this is the index as seen from the parent element.
	// For fields that cannot be repeated, it is -1.
	//
	// For example, in the SimpleCommand "var=value cmd arg1 arg2",
	// there are multiple child elements of type Words.
	//
	// The first Words are the variable assignments, which have index 0.
	//
	// The command "cmd" has type Word, therefore it cannot be confused
	// with either of the Words lists and has index -1.
	//
	// The second Words are the arguments, which have index 1.
	// In this example, there are two arguments, so when visiting the
	// arguments individually, arg1 will have index 0 and arg2 will have index 1.
	//
	// TODO: It might be worth defining negative indexes to correspond
	//  to the fields "Cond", "Action", "Else", etc.
	Index int

	Element interface{}
}

func NewMkShWalker() *MkShWalker {
	return &MkShWalker{}
}

// Path returns a representation of the path in the AST that is
// currently visited.
//
// It is used for debugging only.
//
// See Test_MkShWalker_Walk, Callback.SimpleCommand for examples.
func (w *MkShWalker) Path() string {
	var path []string
	for _, level := range w.Context {
		elementType := reflect.TypeOf(level.Element)
		typeName := elementType.Elem().Name()
		if typeName == "" {
			typeName = "[]" + elementType.Elem().Elem().Name()
		}
		abbreviated := strings.TrimPrefix(typeName, "MkSh")
		if level.Index == -1 {
			// TODO: This form should also be used if index == 0 and len == 1.
			path = append(path, abbreviated)
		} else {
			path = append(path, sprintf("%s[%d]", abbreviated, level.Index))
		}
	}
	return strings.Join(path, ".")
}

// Walk calls the given callback for each node of the parsed shell program,
// in visiting order from large to small.
func (w *MkShWalker) Walk(list *MkShList) {
	w.walkList(-1, list)

	// The calls to w.push and w.pop must be balanced.
	assert(len(w.Context) == 0)
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
		w.walkRedirects(command.Redirects)
	case command.FuncDef != nil:
		w.walkFunctionDefinition(-1, command.FuncDef)
		w.walkRedirects(command.Redirects)
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
	w.walkWords(1, command.Args)
	w.walkRedirects(command.Redirections)

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

func (w *MkShWalker) walkCase(caseClause *MkShCase) {
	w.push(-1, caseClause)

	if callback := w.Callback.Case; callback != nil {
		callback(caseClause)
	}

	w.walkWord(-1, caseClause.Word)
	for i, caseItem := range caseClause.Cases {
		w.push(i, caseItem)
		if callback := w.Callback.CaseItem; callback != nil {
			callback(caseItem)
		}
		w.walkWords(-1, caseItem.Patterns)
		w.walkList(-1, caseItem.Action)
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

func (w *MkShWalker) walkIf(ifClause *MkShIf) {
	w.push(-1, ifClause)

	if callback := w.Callback.If; callback != nil {
		callback(ifClause)
	}

	// TODO: Replace these indices with proper field names; see MkShWalkerPathElement.Index.
	for i, cond := range ifClause.Conds {
		w.walkList(2*i, cond)
		w.walkList(2*i+1, ifClause.Actions[i])
	}
	if ifClause.Else != nil {
		w.walkList(2*len(ifClause.Conds), ifClause.Else)
	}

	w.pop()
}

func (w *MkShWalker) walkLoop(loop *MkShLoop) {
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

func (w *MkShWalker) walkRedirects(redirects []*MkShRedirection) {
	if len(redirects) == 0 {
		return
	}

	w.push(-1, redirects)

	if callback := w.Callback.Redirects; callback != nil {
		callback(redirects)
	}

	for i, redirect := range redirects {
		w.push(i, redirect)
		if callback := w.Callback.Redirect; callback != nil {
			callback(redirect)
		}

		w.walkWord(i, redirect.Target)
		w.pop()
	}

	w.pop()
}

func (w *MkShWalker) walkFor(forClause *MkShFor) {
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
