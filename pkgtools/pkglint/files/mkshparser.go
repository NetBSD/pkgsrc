package main

import (
	"fmt"
	"strconv"
)

func parseShellProgram(line Line, program string) (list *MkShList, err error) {
	if trace.Tracing {
		defer trace.Call(program)()
	}

	tokens, rest := splitIntoShellTokens(line, program)
	lexer := NewShellLexer(tokens, rest)
	parser := &shyyParserImpl{}

	succeeded := parser.Parse(lexer)

	if succeeded == 0 && lexer.error == "" {
		return lexer.result, nil
	}
	return nil, &ParseError{append([]string{lexer.current}, lexer.remaining...)}
}

type ParseError struct {
	RemainingTokens []string
}

func (e *ParseError) Error() string {
	return fmt.Sprintf("parse error at %#v", e.RemainingTokens)
}

type ShellLexer struct {
	current        string
	ioredirect     string
	remaining      []string
	atCommandStart bool
	sinceFor       int
	sinceCase      int
	error          string
	result         *MkShList
}

func NewShellLexer(tokens []string, rest string) *ShellLexer {
	return &ShellLexer{
		current:        "",
		ioredirect:     "",
		remaining:      tokens,
		atCommandStart: true,
		error:          rest}
}
func (lex *ShellLexer) Lex(lval *shyySymType) (ttype int) {
	if len(lex.remaining) == 0 {
		return 0
	}

	if trace.Tracing {
		defer func() {
			tname := shyyTokname(shyyTok2[ttype-shyyPrivate])
			switch ttype {
			case tkWORD, tkASSIGNMENT_WORD:
				trace.Stepf("lex %v %q", tname, lval.Word.MkText)
			case tkIO_NUMBER:
				trace.Stepf("lex %v %v", tname, lval.IONum)
			default:
				trace.Stepf("lex %v", tname)
			}
		}()
	}

	token := lex.ioredirect
	lex.ioredirect = ""
	if token == "" {
		token = lex.remaining[0]
		lex.current = token
		lex.remaining = lex.remaining[1:]
	}

	switch token {
	case ";":
		lex.atCommandStart = true
		return tkSEMI
	case ";;":
		lex.atCommandStart = true
		return tkSEMISEMI
	case "\n":
		lex.atCommandStart = true
		return tkNEWLINE
	case "&":
		lex.atCommandStart = true
		return tkBACKGROUND
	case "|":
		lex.atCommandStart = true
		return tkPIPE
	case "(":
		lex.atCommandStart = true
		return tkLPAREN
	case ")":
		lex.atCommandStart = true
		return tkRPAREN
	case "&&":
		lex.atCommandStart = true
		return tkAND
	case "||":
		lex.atCommandStart = true
		return tkOR
	case ">":
		lex.atCommandStart = false
		return tkGT
	case ">&":
		lex.atCommandStart = false
		return tkGTAND
	case "<":
		lex.atCommandStart = false
		return tkLT
	case "<&":
		lex.atCommandStart = false
		return tkLTAND
	case "<>":
		lex.atCommandStart = false
		return tkLTGT
	case ">>":
		lex.atCommandStart = false
		return tkGTGT
	case "<<":
		lex.atCommandStart = false
		return tkLTLT
	case "<<-":
		lex.atCommandStart = false
		return tkLTLTDASH
	case ">|":
		lex.atCommandStart = false
		return tkGTPIPE
	}

	if m, fdstr, op := match2(token, `^(\d+)(<<-|<<|<>|<&|>>|>&|>\||<|>)$`); m {
		fd, _ := strconv.Atoi(fdstr)
		lval.IONum = fd
		lex.ioredirect = op
		return tkIO_NUMBER
	}

	if lex.atCommandStart {
		lex.sinceCase = -1
		lex.sinceFor = -1
		switch token {
		case "if":
			return tkIF
		case "then":
			return tkTHEN
		case "elif":
			return tkELIF
		case "else":
			return tkELSE
		case "fi":
			return tkFI
		case "for":
			lex.atCommandStart = false
			lex.sinceFor = 0
			return tkFOR
		case "while":
			return tkWHILE
		case "until":
			return tkUNTIL
		case "do":
			return tkDO
		case "done":
			return tkDONE
		case "in":
			lex.atCommandStart = false
			return tkIN
		case "case":
			lex.atCommandStart = false
			lex.sinceCase = 0
			return tkCASE
		case "{":
			return tkLBRACE
		case "}":
			return tkRBRACE
		case "!":
			return tkEXCLAM
		}
	}

	if lex.sinceFor >= 0 {
		lex.sinceFor++
	}
	if lex.sinceCase >= 0 {
		lex.sinceCase++
	}

	switch {
	case lex.sinceFor == 2 && token == "in":
		ttype = tkIN
		lex.atCommandStart = false
	case lex.sinceFor == 2 && token == "do":
		ttype = tkDO
		lex.atCommandStart = true
	case lex.sinceCase == 2 && token == "in":
		ttype = tkIN
		lex.atCommandStart = false
	case (lex.atCommandStart || lex.sinceCase == 3) && token == "esac":
		ttype = tkESAC
		lex.atCommandStart = false
	case lex.atCommandStart && matches(token, `^[A-Za-z_]\w*=`):
		ttype = tkASSIGNMENT_WORD
		p := NewShTokenizer(dummyLine, token, false)
		lval.Word = p.ShToken()
	default:
		ttype = tkWORD
		p := NewShTokenizer(dummyLine, token, false)
		lval.Word = p.ShToken()
		lex.atCommandStart = false
	}

	return ttype
}

func (lex *ShellLexer) Error(s string) {
	lex.error = s
}
