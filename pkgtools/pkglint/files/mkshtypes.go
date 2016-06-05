package main

import (
	"fmt"
)

type MkShList struct {
	AndOrs     []*MkShAndOr
	Separators []MkShSeparator
}

func NewMkShList() *MkShList {
	return &MkShList{nil, nil}
}

func (list *MkShList) String() string {
	return fmt.Sprintf("MkShList(%v)", list.AndOrs)
}

func (list *MkShList) AddAndOr(andor *MkShAndOr) *MkShList {
	list.AndOrs = append(list.AndOrs, andor)
	return list
}

func (list *MkShList) AddSeparator(separator MkShSeparator) *MkShList {
	list.Separators = append(list.Separators, separator)
	return list
}

type MkShAndOr struct {
	Pipes []*MkShPipeline
	Ops   []string // Either "&&" or "||"
}

func NewMkShAndOr(pipeline *MkShPipeline) *MkShAndOr {
	return &MkShAndOr{[]*MkShPipeline{pipeline}, nil}
}

func (andor *MkShAndOr) String() string {
	return fmt.Sprintf("MkShAndOr(%v)", andor.Pipes)
}

func (andor *MkShAndOr) Add(op string, pipeline *MkShPipeline) *MkShAndOr {
	andor.Pipes = append(andor.Pipes, pipeline)
	andor.Ops = append(andor.Ops, op)
	return andor
}

type MkShPipeline struct {
	Negated bool
	Cmds    []*MkShCommand
}

func NewMkShPipeline(negated bool, cmds ...*MkShCommand) *MkShPipeline {
	return &MkShPipeline{negated, cmds}
}

func (pipe *MkShPipeline) String() string {
	return fmt.Sprintf("MkShPipeline(%v)", pipe.Cmds)
}

func (pipe *MkShPipeline) Add(cmd *MkShCommand) *MkShPipeline {
	pipe.Cmds = append(pipe.Cmds, cmd)
	return pipe
}

type MkShCommand struct {
	Simple    *MkShSimpleCommand
	Compound  *MkShCompoundCommand
	FuncDef   *MkShFunctionDefinition
	Redirects []*MkShRedirection // For Compound and FuncDef
}

func (cmd *MkShCommand) String() string {
	switch {
	case cmd.Simple != nil:
		return cmd.Simple.String()
	case cmd.Compound != nil:
		return cmd.Compound.String()
	case cmd.FuncDef != nil:
		return cmd.FuncDef.String()
	}
	return "MkShCommand(?)"
}

type MkShCompoundCommand struct {
	Brace    *MkShList
	Subshell *MkShList
	For      *MkShForClause
	Case     *MkShCaseClause
	If       *MkShIfClause
	While    *MkShLoopClause
	Until    *MkShLoopClause
}

func (cmd *MkShCompoundCommand) String() string {
	switch {
	case cmd.Brace != nil:
		return cmd.Brace.String()
	case cmd.Subshell != nil:
		return cmd.Subshell.String()
	case cmd.For != nil:
		return cmd.For.String()
	case cmd.Case != nil:
		return cmd.Case.String()
	case cmd.If != nil:
		return cmd.If.String()
	case cmd.While != nil:
		return cmd.While.String()
	case cmd.Until != nil:
		return cmd.Until.String()
	}
	return "MkShCompoundCommand(?)"
}

type MkShForClause struct {
	Varname string
	Values  []*ShToken
	Body    *MkShList
}

func (cl *MkShForClause) String() string {
	return fmt.Sprintf("MkShForClause(%v, %v, %v)", cl.Varname, cl.Values, cl.Body)
}

type MkShCaseClause struct {
	Word  *ShToken
	Cases []*MkShCaseItem
}

func (cl *MkShCaseClause) String() string {
	return fmt.Sprintf("MkShCaseClause(...)")
}

type MkShCaseItem struct {
	Patterns []*ShToken
	Action   *MkShList
}

type MkShIfClause struct {
	Conds   []*MkShList
	Actions []*MkShList
	Else    *MkShList
}

func (cl *MkShIfClause) String() string {
	return "MkShIf(...)"
}

func (cl *MkShIfClause) Prepend(cond *MkShList, action *MkShList) {
	cl.Conds = append([]*MkShList{cond}, cl.Conds...)
	cl.Actions = append([]*MkShList{action}, cl.Actions...)
}

type MkShLoopClause struct {
	Cond   *MkShList
	Action *MkShList
	Until  bool
}

func (cl *MkShLoopClause) String() string {
	return "MkShLoop(...)"
}

type MkShFunctionDefinition struct {
	Name      string
	Body      *MkShCompoundCommand
	Redirects []*MkShRedirection
}

func (def *MkShFunctionDefinition) String() string {
	return "MkShFunctionDef(...)"
}

type MkShSimpleCommand struct {
	Assignments  []*ShToken
	Name         *ShToken
	Args         []*ShToken
	Redirections []*MkShRedirection
}

func (scmd *MkShSimpleCommand) String() string {
	str := "SimpleCommand("
	first := true
	sep := func() {
		if first {
			first = false
		} else {
			str += ", "
		}
	}
	for _, word := range scmd.Assignments {
		sep()
		str += word.MkText
	}
	if word := scmd.Name; word != nil {
		sep()
		str += word.MkText
	}
	for _, word := range scmd.Args {
		sep()
		str += word.MkText
	}
	for _, redirection := range scmd.Redirections {
		sep()
		str += redirection.String()
	}
	return str + ")"
}

type MkShRedirection struct {
	Fd     int // Or -1
	Op     string
	Target *ShToken
}

func (r *MkShRedirection) String() string {
	if r.Fd != -1 {
		return fmt.Sprintf("%d%s%s", r.Fd, r.Op, r.Target.MkText)
	} else {
		return r.Op + r.Target.MkText
	}
}

// One of ";", "&", "\n"
type MkShSeparator string

func (sep *MkShSeparator) String() string {
	return fmt.Sprintf("%q", sep)

}
