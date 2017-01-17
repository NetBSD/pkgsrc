%{
package licenses
%}

%token <Node> ltNAME
%token ltAND ltOR ltOPEN ltCLOSE

%union {
	Node *Condition
}

%type <Node> start list node

%%

start : list {
	liyylex.(*licenseLexer).result = $$
}

list : node {
	$$ = &Condition{Children: []*Condition{$1}}
}
list : list ltAND node {
	$$.Children = append($$.Children, $3)
	$$.And = true
}
list : list ltOR node {
	$$.Children = append($$.Children, $3)
	$$.Or = true
}

node : ltNAME {
	$$ = $1
}
node : ltOPEN list ltCLOSE {
	$$ = &Condition{Paren: $2}
}
