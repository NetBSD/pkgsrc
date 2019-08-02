%{
package pkglint
%}

%token <Word> tkWORD
%token <Word> tkASSIGNMENT_WORD
%token tkNEWLINE
%token <IONum> tkIO_NUMBER
%token tkBACKGROUND
%token tkPIPE tkSEMI
%token tkAND tkOR tkSEMISEMI
%token tkLT tkGT tkLTLT tkGTGT tkLTAND tkGTAND  tkLTGT tkLTLTDASH tkGTPIPE
%token tkIF tkTHEN tkELSE tkELIF tkFI tkDO tkDONE
%token tkCASE tkESAC tkWHILE tkUNTIL tkFOR
%token tkLPAREN tkRPAREN tkLBRACE tkRBRACE tkEXCLAM
%token tkIN

%union {
	IONum int
	List *MkShList
	AndOr *MkShAndOr
	Pipeline *MkShPipeline
	Command *MkShCommand
	CompoundCommand *MkShCompoundCommand
	Separator MkShSeparator
	Simple *MkShSimpleCommand
	FuncDef *MkShFunctionDefinition
	For *MkShFor
	If *MkShIf
	Case *MkShCase
	CaseItem *MkShCaseItem
	Loop *MkShLoop
	Words []*ShToken
	Word *ShToken
	Redirections []*MkShRedirection
	Redirection *MkShRedirection
}

%type <List> start program compound_list brace_group subshell term do_group
%type <AndOr> and_or
%type <Pipeline> pipeline pipe_sequence
%type <Command> command
%type <CompoundCommand> compound_command
%type <Separator> separator separator_op sequential_sep
%type <Simple> simple_command cmd_prefix cmd_suffix
%type <FuncDef> function_definition
%type <For> for_clause
%type <If> if_clause else_part
%type <Case> case_clause case_list case_list_ns
%type <CaseItem> case_item case_item_ns
%type <Loop> while_clause until_clause
%type <Words> wordlist case_selector pattern
%type <Word> filename cmd_word here_end
%type <Redirections> redirect_list
%type <Redirection> io_redirect io_file io_here

%%

start : program {
	shyylex.(*ShellLexer).result = $$
}

program : compound_list {
	$$ = $1
}
program : /* empty */ {
	$$ = &MkShList{}
}

and_or : pipeline {
	$$ = NewMkShAndOr($1)
}
and_or : and_or tkAND linebreak pipeline {
	$$.Add("&&", $4)
}
and_or : and_or tkOR linebreak pipeline {
	$$.Add("||", $4)
}

pipeline : pipe_sequence {
	/* empty */
}
pipeline : tkEXCLAM pipe_sequence {
	$$ = $2
	$$.Negated = true
}

pipe_sequence : command {
	$$ = NewMkShPipeline(false, []*MkShCommand{$1})
}
pipe_sequence : pipe_sequence tkPIPE linebreak command {
	$$.Add($4)
}

command : simple_command {
	$$ = &MkShCommand{Simple: $1}
}
command : compound_command {
	$$ = &MkShCommand{Compound: $1}
}
command : compound_command redirect_list {
	$$ = &MkShCommand{Compound: $1, Redirects: $2}
}
command : function_definition {
	$$ = &MkShCommand{FuncDef: $1}
}
command : function_definition redirect_list {
	$$ = &MkShCommand{FuncDef: $1, Redirects: $2}
}

compound_command : brace_group {
	$$ = &MkShCompoundCommand{Brace: $1}
}
compound_command : subshell {
	$$ = &MkShCompoundCommand{Subshell: $1}
}
compound_command : for_clause {
	$$ = &MkShCompoundCommand{For: $1}
}
compound_command : case_clause {
	$$ = &MkShCompoundCommand{Case: $1}
}
compound_command : if_clause {
	$$ = &MkShCompoundCommand{If: $1}
}
compound_command : while_clause {
	$$ = &MkShCompoundCommand{Loop: $1}
}
compound_command : until_clause {
	$$ = &MkShCompoundCommand{Loop: $1}
}

subshell : tkLPAREN compound_list tkRPAREN {
	$$ = $2
}

compound_list : linebreak term {
	$$ = $2
}
compound_list : linebreak term separator {
	$$ = $2
	$$.AddSeparator($3)
}

term : and_or {
	$$ = NewMkShList()
	$$.AddAndOr($1)
}
term : term separator and_or {
	$$.AddSeparator($2)
	$$.AddAndOr($3)
}

for_clause : tkFOR tkWORD linebreak do_group {
	args := NewShToken("\"$$@\"",
		&ShAtom{shtText, "\"", shqDquot, nil},
		&ShAtom{shtShVarUse, "$$@", shqDquot, "@"},
		&ShAtom{shtText, "\"", shqPlain, nil})
	$$ = &MkShFor{$2.MkText, []*ShToken{args}, $4}
}
for_clause : tkFOR tkWORD linebreak tkIN sequential_sep do_group {
	$$ = &MkShFor{$2.MkText, nil, $6}
}
for_clause : tkFOR tkWORD linebreak tkIN wordlist sequential_sep do_group {
	$$ = &MkShFor{$2.MkText, $5, $7}
}

wordlist : tkWORD {
	$$ = append($$, $1)
}
wordlist : wordlist tkWORD {
	$$ = append($$, $2)
}

case_clause : tkCASE tkWORD linebreak tkIN linebreak case_list tkESAC {
	$$ = $6
	$$.Word = $2
}
case_clause : tkCASE tkWORD linebreak tkIN linebreak case_list_ns tkESAC {
	$$ = $6
	$$.Word = $2
}
case_clause : tkCASE tkWORD linebreak tkIN linebreak tkESAC {
	$$ = &MkShCase{$2, nil}
}

case_list_ns : case_item_ns {
	$$ = &MkShCase{nil, nil}
	$$.Cases = append($$.Cases, $1)
}
case_list_ns : case_list case_item_ns {
	$$.Cases = append($$.Cases, $2)
}

case_list : case_item {
	$$ = &MkShCase{nil, nil}
	$$.Cases = append($$.Cases, $1)
}
case_list : case_list case_item {
	$$.Cases = append($$.Cases, $2)
}

case_selector : tkLPAREN pattern tkRPAREN {
	$$ = $2
}
case_selector : pattern tkRPAREN {
	/* empty */
}

case_item_ns : case_selector linebreak {
	$$ = &MkShCaseItem{$1, &MkShList{}, sepNone, nil}
}
case_item_ns : case_selector linebreak term linebreak {
	$$ = &MkShCaseItem{$1, $3, sepNone, nil}
}
case_item_ns : case_selector linebreak term separator_op linebreak {
	$$ = &MkShCaseItem{$1, $3, $4, nil}
}

case_item : case_selector linebreak tkSEMISEMI linebreak {
	$$ = &MkShCaseItem{$1, &MkShList{}, sepNone, nil}
}
case_item : case_selector compound_list tkSEMISEMI linebreak {
	$$ = &MkShCaseItem{$1, $2, sepNone, nil}
}
case_item : tkWORD {
	$$ = &MkShCaseItem{Var: $1}
}

pattern : tkWORD {
	$$ = nil
	$$ = append($$, $1)
}
pattern : pattern tkPIPE tkWORD {
	$$ = append($$, $3)
}

if_clause : tkIF compound_list tkTHEN compound_list else_part tkFI {
	$$ = $5
	$$.Prepend($2, $4)
}
if_clause : tkIF compound_list tkTHEN compound_list tkFI {
	$$ = &MkShIf{}
	$$.Prepend($2, $4)
}

else_part : tkELIF compound_list tkTHEN compound_list {
	$$ = &MkShIf{}
	$$.Prepend($2, $4)
}
else_part : tkELIF compound_list tkTHEN compound_list else_part {
	$$ = $5
	$$.Prepend($2, $4)
}
else_part : tkELSE compound_list {
	$$ = &MkShIf{nil, nil, $2}
}

while_clause : tkWHILE compound_list do_group {
	$$ = &MkShLoop{$2, $3, false}
}
until_clause : tkUNTIL compound_list do_group {
	$$ = &MkShLoop{$2, $3, true}
}

function_definition : tkWORD tkLPAREN tkRPAREN linebreak compound_command { /* Apply rule 9 */
	$$ = &MkShFunctionDefinition{$1.MkText, $5}
}

brace_group : tkLBRACE compound_list tkRBRACE {
	$$ = $2
}

do_group : tkDO compound_list tkDONE {
	$$ = $2
}

simple_command : cmd_prefix cmd_word cmd_suffix {
	$$.Name = $2
	$$.Args = append($$.Args, $3.Args...)
	$$.Redirections = append($$.Redirections, $3.Redirections...)
}
simple_command : cmd_prefix cmd_word {
	$$.Name = $2
}
simple_command : cmd_prefix {
	/* empty */
}
simple_command : tkWORD cmd_suffix {
	$$ = $2
	$$.Name = $1
}
simple_command : tkWORD {
	$$ = &MkShSimpleCommand{Name: $1}
}

cmd_word : tkWORD { /* Apply rule 7b */
	/* empty */
}

cmd_prefix : io_redirect {
	$$ = &MkShSimpleCommand{}
	$$.Redirections = append($$.Redirections, $1)
}
cmd_prefix : tkASSIGNMENT_WORD {
	$$ = &MkShSimpleCommand{}
	$$.Assignments = append($$.Assignments, $1)
}
cmd_prefix : cmd_prefix io_redirect {
	$$.Redirections = append($$.Redirections, $2)
}
cmd_prefix : cmd_prefix tkASSIGNMENT_WORD {
	$$.Assignments = append($$.Assignments, $2)
}

cmd_suffix : io_redirect {
	$$ = &MkShSimpleCommand{}
	$$.Redirections = append($$.Redirections, $1)
}
cmd_suffix : tkWORD {
	$$ = &MkShSimpleCommand{}
	$$.Args = append($$.Args, $1)
}
cmd_suffix : cmd_suffix io_redirect {
	$$.Redirections = append($$.Redirections, $2)
}
cmd_suffix : cmd_suffix tkWORD {
	$$.Args = append($$.Args, $2)
}

redirect_list : io_redirect {
	$$ = nil
	$$ = append($$, $1)
}
redirect_list : redirect_list io_redirect {
	$$ = append($$, $2)
}

io_redirect : io_file {
	/* empty */
}
io_redirect : tkIO_NUMBER io_file {
	$$ = $2
	$$.Fd = $1
}

io_redirect : io_here {
	/* empty */
}
io_redirect : tkIO_NUMBER io_here {
	$$ = $2
	$$.Fd = $1
}

io_file : tkLT filename {
	$$ = &MkShRedirection{-1, "<", $2}
}
io_file : tkLTAND filename {
	$$ = &MkShRedirection{-1, "<&", $2}
}
io_file : tkGT filename {
	$$ = &MkShRedirection{-1, ">", $2}
}
io_file : tkGTAND filename {
	$$ = &MkShRedirection{-1, ">&", $2}
}
io_file : tkGTGT filename {
	$$ = &MkShRedirection{-1, ">>", $2}
}
io_file : tkLTGT filename {
	$$ = &MkShRedirection{-1, "<>", $2}
}
io_file : tkGTPIPE filename {
	$$ = &MkShRedirection{-1, ">|", $2}
}

filename : tkWORD { /* Apply rule 2 */
	/* empty */
}

io_here : tkLTLT here_end {
	$$ = &MkShRedirection{-1, "<<", $2}
}
io_here : tkLTLTDASH here_end {
	$$ = &MkShRedirection{-1, "<<-", $2}
}

here_end : tkWORD { /* Apply rule 3 */
	/* empty */
}

newline_list : tkNEWLINE {
	/* empty */
}
newline_list : newline_list tkNEWLINE {
	/* empty */
}

linebreak : newline_list {
	/* empty */
}
linebreak : /* empty */ {
	/* empty */
}

separator_op : tkBACKGROUND {
	$$ = sepBackground
}
separator_op : tkSEMI {
	$$ = sepSemicolon
}

separator : separator_op linebreak {
	/* empty */
}
separator : newline_list {
	$$ = sepNewline
}

sequential_sep : tkSEMI linebreak {
	$$ = sepSemicolon
}
sequential_sep : tkNEWLINE linebreak {
	$$ = sepNewline
}
