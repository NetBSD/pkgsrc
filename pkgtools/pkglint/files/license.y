%{
package main
%}

%token <Node> ltNAME
%token ltAND ltOR ltOPEN ltCLOSE

%union {
	Node *LicenseCondition
}

%type <Node> start list condition

%%

start : list {
	liyylex.(*licenseLexer).result = $$
}

list : condition {
	$$ = $1
}
list : list ltAND condition {
	$$.And = append($$.And, $3)
}
list : list ltOR condition {
	$$.Or = append($$.Or, $3)
}

condition : ltNAME {
	$$ = $1
}
condition : ltOPEN list ltCLOSE {
	$$ = &LicenseCondition{Main: $2}
}
