package main

import (
	"netbsd.org/pkglint/regex"
	"strings"
)

// MkShList is a list of shell commands, separated by newlines or semicolons.
//
// Example: cd $dir && echo "In $dir"; cd ..; ls -l
type MkShList struct {
	AndOrs     []*MkShAndOr
	Separators []MkShSeparator // One less entry than in AndOrs.
}

func NewMkShList() *MkShList {
	return &MkShList{nil, nil}
}

func (list *MkShList) AddAndOr(andor *MkShAndOr) *MkShList {
	list.AndOrs = append(list.AndOrs, andor)
	return list
}

func (list *MkShList) AddSeparator(separator MkShSeparator) *MkShList {
	list.Separators = append(list.Separators, separator)
	return list
}

// MkShAndOr is a group of commands that are connected with && or ||
// conditions.
//
// Example: cd $dir && echo "In $dir" || echo "Cannot cd into $dir"
type MkShAndOr struct {
	Pipes []*MkShPipeline
	Ops   []string // Each element is either "&&" or "||"
}

func NewMkShAndOr(pipeline *MkShPipeline) *MkShAndOr {
	return &MkShAndOr{[]*MkShPipeline{pipeline}, nil}
}

func (andor *MkShAndOr) Add(op string, pipeline *MkShPipeline) *MkShAndOr {
	andor.Pipes = append(andor.Pipes, pipeline)
	andor.Ops = append(andor.Ops, op)
	return andor
}

// MkShPipeline is a group of commands, connected by pipelines.
//
// Example: grep word file | sed s,^,---,
type MkShPipeline struct {
	Negated bool
	Cmds    []*MkShCommand
}

func NewMkShPipeline(negated bool, cmds ...*MkShCommand) *MkShPipeline {
	return &MkShPipeline{negated, cmds}
}

func (pipe *MkShPipeline) Add(cmd *MkShCommand) *MkShPipeline {
	pipe.Cmds = append(pipe.Cmds, cmd)
	return pipe
}

// MkShCommand is a simple or compound shell command.
//
// Example: LC_ALL=C sort */*.c > sorted
// Example: dir() { ls -l "$@"; }
// Example: { echo "first"; echo "second"; }
type MkShCommand struct {
	Simple    *MkShSimpleCommand
	Compound  *MkShCompoundCommand
	FuncDef   *MkShFunctionDefinition
	Redirects []*MkShRedirection // For Compound and FuncDef
}

// MkShCompoundCommand is a group of commands.
//
// Example: { echo "first"; echo "second"; }
// Example: for f in *.c; do compile "$f"; done
// Example: if [ -f "$file" ]; then echo "It exists"; fi
// Example: while sleep 1; do printf .; done
type MkShCompoundCommand struct {
	Brace    *MkShList
	Subshell *MkShList
	For      *MkShForClause
	Case     *MkShCaseClause
	If       *MkShIfClause
	Loop     *MkShLoopClause
}

// MkShForClause is a "for" loop.
//
// Example: for f in *.c; do compile "$f"; done
type MkShForClause struct {
	Varname string
	Values  []*ShToken
	Body    *MkShList
}

// MkShCaseClause is a "case" statement, including all its branches.
//
// Example: case $fileName in *.c) echo "C source" ;; esac
type MkShCaseClause struct {
	Word  *ShToken
	Cases []*MkShCaseItem
}

// MkShCaseItem is one branch of a "case" statement.
//
// Example: *.c) echo "C source" ;;
type MkShCaseItem struct {
	Patterns  []*ShToken
	Action    *MkShList
	Separator MkShSeparator
}

// MkShIfClause is a conditional statement, possibly having
// many branches.
//
// Example: if [ -f "$file" ]; then echo "It exists"; fi
type MkShIfClause struct {
	Conds   []*MkShList
	Actions []*MkShList
	Else    *MkShList
}

func (cl *MkShIfClause) Prepend(cond *MkShList, action *MkShList) {
	cl.Conds = append([]*MkShList{cond}, cl.Conds...)
	cl.Actions = append([]*MkShList{action}, cl.Actions...)
}

// MkShLoopClause is a "while" or "until" loop.
//
// Example: while sleep 1; do printf .; done
type MkShLoopClause struct {
	Cond   *MkShList
	Action *MkShList
	Until  bool
}

// MkShFunctionDefinition is the definition of a shell function.
//
// Example: dir() { ls -l "$@"; }
type MkShFunctionDefinition struct {
	Name string
	Body *MkShCompoundCommand
}

// MkShSimpleCommand is a shell command that does not involve any
// pipeline or conditionals.
//
// Example: LC_ALL=C sort */*.c > sorted
type MkShSimpleCommand struct {
	Assignments  []*ShToken
	Name         *ShToken
	Args         []*ShToken
	Redirections []*MkShRedirection
}

func NewStrCommand(cmd *MkShSimpleCommand) *StrCommand {
	strcmd := &StrCommand{
		make([]string, len(cmd.Assignments)),
		"",
		make([]string, len(cmd.Args))}
	for i, assignment := range cmd.Assignments {
		strcmd.Assignments[i] = assignment.MkText
	}
	if cmd.Name != nil {
		strcmd.Name = cmd.Name.MkText
	}
	for i, arg := range cmd.Args {
		strcmd.Args[i] = arg.MkText
	}
	return strcmd
}

// StrCommand is structurally similar to MkShSimpleCommand, but all
// components are converted to strings to allow for simpler checks,
// especially for analyzing command line options.
//
// Example: LC_ALL=C sort */*.c > sorted
type StrCommand struct {
	Assignments []string
	Name        string
	Args        []string
}

// HasOption checks whether one of the arguments is exactly the given opt.
func (c *StrCommand) HasOption(opt string) bool {
	for _, arg := range c.Args {
		if arg == opt {
			return true
		}
	}
	return false
}

func (c *StrCommand) AnyArgMatches(pattern regex.Pattern) bool {
	for _, arg := range c.Args {
		if matches(arg, pattern) {
			return true
		}
	}
	return false
}

func (c *StrCommand) String() string {
	var strs []string
	for _, assignment := range c.Assignments {
		strs = append(strs, assignment)
	}
	if c.Name != "" {
		strs = append(strs, c.Name)
	}
	for _, arg := range c.Args {
		strs = append(strs, arg)
	}
	return strings.Join(strs, " ")
}

// MkShRedirection is a single file descriptor redirection.
//
// Example: > sorted
// Example: 2>&1
type MkShRedirection struct {
	Fd     int      // Or -1
	Op     string   // See io_file in shell.y for possible values
	Target *ShToken // The file name or &fd
}

type MkShSeparator uint8

const (
	sepNone       MkShSeparator = iota
	sepSemicolon                // ;
	sepBackground               // &
	sepNewline                  // \n
)
