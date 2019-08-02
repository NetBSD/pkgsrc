package pkglint

import (
	"netbsd.org/pkglint/regex"
	"strings"
)

// MkShList is a list of shell commands, separated by newlines or semicolons.
//
// Example:
//  cd $dir && echo "In $dir"; cd ..; ls -l
type MkShList struct {
	AndOrs []*MkShAndOr

	// The separators after each AndOr.
	// There may be one less entry than in AndOrs.
	Separators []MkShSeparator
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
// The operators && and || have the same precedence and are evaluated
// strictly from left to right.
//
// Example:
//  cd $dir && echo "In $dir" || echo "Cannot cd into $dir"
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

func NewMkShPipeline(negated bool, cmds []*MkShCommand) *MkShPipeline {
	return &MkShPipeline{negated, cmds}
}

func (pipe *MkShPipeline) Add(cmd *MkShCommand) *MkShPipeline {
	pipe.Cmds = append(pipe.Cmds, cmd)
	return pipe
}

// MkShCommand is a simple or compound shell command.
//
// Examples:
//  LC_ALL=C sort */*.c > sorted
//  dir() { ls -l "$@"; }
//  { echo "first"; echo "second"; }
type MkShCommand struct {
	Simple    *MkShSimpleCommand
	Compound  *MkShCompoundCommand
	FuncDef   *MkShFunctionDefinition
	Redirects []*MkShRedirection // For Compound and FuncDef
}

// MkShCompoundCommand is a group of commands.
//
// Examples:
//  { echo "first"; echo "second"; }
//  for f in *.c; do compile "$f"; done
//  if [ -f "$file" ]; then echo "It exists"; fi
//  while sleep 1; do printf .; done
type MkShCompoundCommand struct {
	Brace    *MkShList
	Subshell *MkShList
	For      *MkShFor
	Case     *MkShCase
	If       *MkShIf
	Loop     *MkShLoop
}

// MkShFor is a "for" loop.
//
// Example:
//  for f in *.c; do compile "$f"; done
type MkShFor struct {
	Varname string
	Values  []*ShToken
	Body    *MkShList
}

// MkShCase is a "case" statement, including all its branches.
//
// Example:
//  case $filename in *.c) echo "C source" ;; esac
type MkShCase struct {
	Word  *ShToken
	Cases []*MkShCaseItem
}

// MkShCaseItem is one branch of a "case" statement.
//
// Example:
//  *.c) echo "C source" ;;
type MkShCaseItem struct {
	Patterns  []*ShToken
	Action    *MkShList
	Separator MkShSeparator
	Var       *ShToken // ${PATTERNS:@p@ (${p}) action ;; @}
}

// MkShIf is a conditional statement, possibly having
// many branches.
//
// Example:
//  if [ -f "$file" ]; then echo "It exists"; fi
type MkShIf struct {
	Conds   []*MkShList
	Actions []*MkShList
	Else    *MkShList
}

func (cl *MkShIf) Prepend(cond *MkShList, action *MkShList) {
	cl.Conds = append([]*MkShList{cond}, cl.Conds...)
	cl.Actions = append([]*MkShList{action}, cl.Actions...)
}

// MkShLoop is a "while" or "until" loop.
//
// Example:
//  while sleep 1; do printf .; done
type MkShLoop struct {
	Cond   *MkShList
	Action *MkShList
	Until  bool
}

// MkShFunctionDefinition is the definition of a shell function.
//
// Example:
//  dir() { ls -l "$@"; }
type MkShFunctionDefinition struct {
	Name string
	Body *MkShCompoundCommand
}

// MkShSimpleCommand is a shell command that does not involve any
// pipeline or conditionals.
//
// Example:
//  LC_ALL=C sort */*.c > sorted
type MkShSimpleCommand struct {
	Assignments  []*ShToken
	Name         *ShToken
	Args         []*ShToken
	Redirections []*MkShRedirection
}

// StrCommand is structurally similar to MkShSimpleCommand, but all
// components are converted to strings to allow for simpler checks,
// especially for analyzing command line options.
//
// Example:
//  LC_ALL=C sort */*.c > sorted
type StrCommand struct {
	Assignments []string
	Name        string
	Args        []string
}

func NewStrCommand(cmd *MkShSimpleCommand) *StrCommand {
	strcmd := StrCommand{
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
	return &strcmd
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
	strs := append([]string(nil), c.Assignments...)
	if c.Name != "" {
		strs = append(strs, c.Name)
	}
	strs = append(strs, c.Args...)
	return strings.Join(strs, " ")
}

// MkShRedirection is a single file descriptor redirection.
//
// Examples:
//  > sorted
//  2>&1
type MkShRedirection struct {
	Fd     int      // Or -1
	Op     string   // See io_file in shell.y for possible values
	Target *ShToken // The filename or &fd
}

// MkShSeparator is one of ; & newline.
type MkShSeparator uint8

const (
	sepNone       MkShSeparator = iota
	sepSemicolon                // ;
	sepBackground               // &
	sepNewline                  // \n
)
