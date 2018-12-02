package main

import (
	"netbsd.org/pkglint/regex"
	"netbsd.org/pkglint/textproc"
	"strings"
)

// MkParser wraps a Parser and provides methods for parsing
// things related to Makefiles.
type MkParser struct {
	*Parser
}

// NewMkParser creates a new parser for the given text.
// If emitWarnings is false, line may be nil.
func NewMkParser(line Line, text string, emitWarnings bool) *MkParser {
	G.Assertf((line != nil) == emitWarnings, "line must be given iff emitWarnings is set")
	return &MkParser{NewParser(line, text, emitWarnings)}
}

func (p *MkParser) MkTokens() []*MkToken {
	lexer := p.lexer

	var tokens []*MkToken
	for !p.EOF() {
		// FIXME: Aren't the comments already gone at this stage?
		if lexer.SkipByte('#') {
			lexer.Skip(len(lexer.Rest()))
		}

		mark := lexer.Mark()
		if varuse := p.VarUse(); varuse != nil {
			tokens = append(tokens, &MkToken{Text: lexer.Since(mark), Varuse: varuse})
			continue
		}

	again:
		dollar := strings.IndexByte(lexer.Rest(), '$')
		if dollar == -1 {
			dollar = len(lexer.Rest())
		}
		lexer.Skip(dollar)
		if lexer.SkipString("$$") {
			goto again
		}
		text := lexer.Since(mark)
		if text != "" {
			tokens = append(tokens, &MkToken{Text: text})
			continue
		}

		break
	}
	return tokens
}

func (p *MkParser) VarUse() *MkVarUse {
	lexer := p.lexer

	if lexer.PeekByte() != '$' {
		return nil
	}

	mark := lexer.Mark()
	lexer.Skip(1)

	if lexer.SkipByte('{') || lexer.SkipByte('(') {
		usingRoundParen := lexer.Since(mark)[1] == '('
		closing := byte('}')
		if usingRoundParen {
			closing = ')'
		}

		varnameMark := lexer.Mark()
		varname := p.Varname()
		if varname != "" {
			modifiers := p.VarUseModifiers(varname, closing)
			if lexer.SkipByte(closing) {
				if usingRoundParen && p.EmitWarnings {
					parenVaruse := lexer.Since(mark)
					bracesVaruse := "${" + parenVaruse[2:len(parenVaruse)-1] + "}"
					fix := p.Line.Autofix()
					fix.Warnf("Please use curly braces {} instead of round parentheses () for %s.", varname)
					fix.Replace(parenVaruse, bracesVaruse)
					fix.Apply()
				}
				return &MkVarUse{varname, modifiers}
			}
		}

		for p.VarUse() != nil || lexer.SkipRegexp(G.res.Compile(regex.Pattern(`^([^$:`+string(closing)+`]|\$\$)+`))) {
		}
		rest := p.Rest()
		if hasPrefix(rest, ":L") || hasPrefix(rest, ":?") {
			varexpr := lexer.Since(varnameMark)
			modifiers := p.VarUseModifiers(varexpr, closing)
			if lexer.SkipByte(closing) {
				return &MkVarUse{varexpr, modifiers}
			}
		}
		lexer.Reset(mark)
	}

	if lexer.SkipByte('@') {
		return &MkVarUse{"@", nil}
	}
	if lexer.SkipByte('<') {
		return &MkVarUse{"<", nil}
	}
	if varname := lexer.NextBytesSet(textproc.AlnumU); varname != "" {
		if p.EmitWarnings {
			p.Line.Warnf("$%[1]s is ambiguous. Use ${%[1]s} if you mean a Makefile variable or $$%[1]s if you mean a shell variable.", varname)
		}
		return &MkVarUse{varname, nil}
	}

	lexer.Reset(mark)
	return nil
}

func (p *MkParser) VarUseModifiers(varname string, closing byte) []MkVarUseModifier {
	lexer := p.lexer

	var modifiers []MkVarUseModifier
	appendModifier := func(s string) { modifiers = append(modifiers, MkVarUseModifier{s}) }
	mayOmitColon := false
loop:
	for lexer.SkipByte(':') || mayOmitColon {
		mayOmitColon = false
		modifierMark := lexer.Mark()

		switch lexer.PeekByte() {
		case 'E', 'H', 'L', 'O', 'Q', 'R', 'T', 's', 't', 'u':
			if lexer.SkipRegexp(G.res.Compile(`^(E|H|L|Ox?|Q|R|T|sh|tA|tW|tl|tu|tw|u)`)) {
				appendModifier(lexer.Since(modifierMark))
				continue
			}
			if lexer.SkipString("ts") {
				rest := lexer.Rest()
				if len(rest) >= 2 && (rest[1] == closing || rest[1] == ':') {
					lexer.Skip(1)
				} else if len(rest) >= 1 && (rest[0] == closing || rest[0] == ':') {
				} else if lexer.SkipRegexp(G.res.Compile(`^\\\d+`)) {
				} else {
					break loop
				}
				appendModifier(lexer.Since(modifierMark))
				continue
			}

		case '=', 'D', 'M', 'N', 'U':
			lexer.Skip(1)
			re := G.res.Compile(regex.Pattern(ifelseStr(closing == '}', `^([^$:\\}]|\$\$|\\.)+`, `^([^$:\\)]|\$\$|\\.)+`)))
			for p.VarUse() != nil || lexer.SkipRegexp(re) {
			}
			arg := lexer.Since(modifierMark)
			appendModifier(strings.Replace(arg, "\\:", ":", -1))
			continue

		case 'C', 'S':
			// bmake allows _any_ separator, even letters.
			lexer.Skip(1)
			if m := lexer.NextRegexp(G.res.Compile(`^[%,/:;@^|]`)); m != nil {
				separator := m[0][0]
				lexer.SkipByte('^')
				skipOther := func() {
					for p.VarUse() != nil ||
						lexer.SkipString("$$") ||
						(len(lexer.Rest()) >= 2 && lexer.PeekByte() == '\\' && lexer.Skip(2)) ||
						lexer.NextBytesFunc(func(b byte) bool { return b != separator && b != '$' && b != closing && b != '\\' }) != "" {

					}
				}
				skipOther()
				lexer.SkipByte('$')
				if lexer.SkipByte(separator) {
					skipOther()
					if lexer.SkipByte(separator) {
						lexer.SkipRegexp(G.res.Compile(`^[1gW]`)) // FIXME: Multiple modifiers may be mentioned
						appendModifier(lexer.Since(modifierMark))
						mayOmitColon = true
						continue
					}
				}
			}

		case '@':
			if m := lexer.NextRegexp(G.res.Compile(`^@([\w.]+)@`)); m != nil {
				loopvar := m[1]
				re := G.res.Compile(regex.Pattern(ifelseStr(closing == '}', `^([^$:@}\\]|\\.)+`, `^([^$:@)\\]|\\.)+`)))
				for p.VarUse() != nil || lexer.SkipString("$$") || lexer.SkipRegexp(re) {
				}
				if !lexer.SkipByte('@') && p.EmitWarnings {
					p.Line.Warnf("Modifier ${%s:@%s@...@} is missing the final \"@\".", varname, loopvar)
				}
				appendModifier(lexer.Since(modifierMark))
				continue
			}

		case '[':
			if lexer.SkipRegexp(G.res.Compile(`^\[(?:[-.\d]+|#)\]`)) {
				appendModifier(lexer.Since(modifierMark))
				continue
			}

		case '?':
			lexer.Skip(1)
			re := G.res.Compile(regex.Pattern(`^([^$:` + string(closing) + `]|\$\$)+`))
			for p.VarUse() != nil || lexer.SkipRegexp(re) {
			}
			if lexer.SkipByte(':') {
				for p.VarUse() != nil || lexer.SkipRegexp(re) {
				}
				appendModifier(lexer.Since(modifierMark))
				continue
			}
		}

		lexer.Reset(modifierMark)
		// FIXME: Why skip over unknown modifiers here? This accepts :S,a,b,c,d,e,f but shouldn't.
		re := G.res.Compile(regex.Pattern(`^([^:$` + string(closing) + `]|\$\$)+`))
		for p.VarUse() != nil || lexer.SkipRegexp(re) {
		}
		if suffixSubst := lexer.Since(modifierMark); contains(suffixSubst, "=") {
			appendModifier(suffixSubst)
			continue
		}
	}
	return modifiers
}

// MkCond parses a condition like ${OPSYS} == "NetBSD".
// See devel/bmake/files/cond.c.
func (p *MkParser) MkCond() MkCond {
	and := p.mkCondAnd()
	if and == nil {
		return nil
	}

	ands := []MkCond{and}
	for {
		mark := p.lexer.Mark()
		p.lexer.SkipHspace()
		if !(p.lexer.SkipString("||")) {
			break
		}
		next := p.mkCondAnd()
		if next == nil {
			p.lexer.Reset(mark)
			break
		}
		ands = append(ands, next)
	}
	if len(ands) == 1 {
		return and
	}
	return &mkCond{Or: ands}
}

func (p *MkParser) mkCondAnd() MkCond {
	atom := p.mkCondAtom()
	if atom == nil {
		return nil
	}

	atoms := []MkCond{atom}
	for {
		mark := p.lexer.Mark()
		p.lexer.SkipHspace()
		if p.lexer.NextString("&&") == "" {
			break
		}
		next := p.mkCondAtom()
		if next == nil {
			p.lexer.Reset(mark)
			break
		}
		atoms = append(atoms, next)
	}
	if len(atoms) == 1 {
		return atom
	}
	return &mkCond{And: atoms}
}

func (p *MkParser) mkCondAtom() MkCond {
	if trace.Tracing {
		defer trace.Call1(p.Rest())()
	}

	lexer := p.lexer
	mark := lexer.Mark()
	lexer.SkipHspace()
	switch {
	case lexer.SkipByte('!'):
		cond := p.mkCondAtom()
		if cond != nil {
			return &mkCond{Not: cond}
		}

	case lexer.SkipByte('('):
		cond := p.MkCond()
		if cond != nil {
			lexer.SkipHspace()
			if lexer.SkipByte(')') {
				return cond
			}
		}

	case 'a' <= lexer.PeekByte() && lexer.PeekByte() <= 'z':
		return p.mkCondFunc()

	default:
		lhs := p.VarUse()
		mark := lexer.Mark()
		if lhs == nil && lexer.SkipByte('"') {
			if quotedLHS := p.VarUse(); quotedLHS != nil && lexer.SkipByte('"') {
				lhs = quotedLHS
			} else {
				lexer.Reset(mark)
			}
		}
		if lhs != nil {
			if m := lexer.NextRegexp(G.res.Compile(`^[\t ]*(<|<=|==|!=|>=|>)[\t ]*(\d+(?:\.\d+)?)`)); m != nil {
				return &mkCond{CompareVarNum: &MkCondCompareVarNum{lhs, m[1], m[2]}}
			}
			if m := lexer.NextRegexp(G.res.Compile(`^[\t ]*(<|<=|==|!=|>=|>)[\t ]*`)); m != nil {
				op := m[1]
				if op == "==" || op == "!=" {
					if mrhs := lexer.NextRegexp(G.res.Compile(`^"([^"\$\\]*)"`)); mrhs != nil {
						return &mkCond{CompareVarStr: &MkCondCompareVarStr{lhs, op, mrhs[1]}}
					}
				}
				if str := lexer.NextBytesSet(textproc.AlnumU); str != "" {
					return &mkCond{CompareVarStr: &MkCondCompareVarStr{lhs, op, str}}
				} else if rhs := p.VarUse(); rhs != nil {
					return &mkCond{CompareVarVar: &MkCondCompareVarVar{lhs, op, rhs}}
				} else if lexer.PeekByte() == '"' {
					mark := lexer.Mark()
					if lexer.SkipByte('"') {
						if quotedRHS := p.VarUse(); quotedRHS != nil {
							if lexer.SkipByte('"') {
								return &mkCond{CompareVarVar: &MkCondCompareVarVar{lhs, op, quotedRHS}}
							}
						}
					}
					lexer.Reset(mark)
				}
			} else {
				return &mkCond{Not: &mkCond{Empty: lhs}} // See devel/bmake/files/cond.c:/\* For \.if \$/
			}
		}
		if m := lexer.NextRegexp(G.res.Compile(`^\d+(?:\.\d+)?`)); m != nil {
			return &mkCond{Num: m[0]}
		}
	}
	lexer.Reset(mark)
	return nil
}

func (p *MkParser) mkCondFunc() *mkCond {
	lexer := p.lexer
	mark := lexer.Mark()

	funcName := lexer.NextBytesFunc(func(b byte) bool { return 'a' <= b && b <= 'z' })
	lexer.SkipHspace()
	if !lexer.SkipByte('(') {
		return nil
	}

	switch funcName {
	case "defined":
		varname := p.Varname()
		if varname != "" && lexer.SkipByte(')') {
			return &mkCond{Defined: varname}
		}

	case "empty":
		if varname := p.Varname(); varname != "" {
			modifiers := p.VarUseModifiers(varname, ')')
			if lexer.SkipByte(')') {
				return &mkCond{Empty: &MkVarUse{varname, modifiers}}
			}
		}

	case "commands", "exists", "make", "target":
		argMark := lexer.Mark()
		for p.VarUse() != nil || lexer.NextBytesFunc(func(b byte) bool { return b != '$' && b != ')' }) != "" {
		}
		arg := lexer.Since(argMark)
		if lexer.SkipByte(')') {
			return &mkCond{Call: &MkCondCall{funcName, arg}}
		}
	}

	lexer.Reset(mark)
	return nil
}

func (p *MkParser) Varname() string {
	lexer := p.lexer

	mark := lexer.Mark()
	lexer.SkipByte('.')
	for p.VarUse() != nil || lexer.NextBytesSet(VarnameBytes) != "" {
	}
	return lexer.Since(mark)
}

type MkCond = *mkCond

type mkCond struct {
	Or  []*mkCond
	And []*mkCond
	Not *mkCond

	Defined       string
	Empty         *MkVarUse
	CompareVarNum *MkCondCompareVarNum
	CompareVarStr *MkCondCompareVarStr
	CompareVarVar *MkCondCompareVarVar
	Call          *MkCondCall
	Num           string
}
type MkCondCompareVarNum struct {
	Var *MkVarUse
	Op  string // One of <, <=, ==, !=, >=, >.
	Num string
}
type MkCondCompareVarStr struct {
	Var *MkVarUse
	Op  string // One of ==, !=.
	Str string
}
type MkCondCompareVarVar struct {
	Left  *MkVarUse
	Op    string // One of <, <=, ==, !=, >=, >.
	Right *MkVarUse
}
type MkCondCall struct {
	Name string
	Arg  string
}

type MkCondCallback struct {
	Defined       func(varname string)
	Empty         func(empty *MkVarUse)
	CompareVarNum func(varuse *MkVarUse, op string, num string)
	CompareVarStr func(varuse *MkVarUse, op string, str string)
	CompareVarVar func(left *MkVarUse, op string, right *MkVarUse)
	Call          func(name string, arg string)
	VarUse        func(varuse *MkVarUse)
}

func (cond *mkCond) Walk(callback *MkCondCallback) {
	(&MkCondWalker{}).Walk(cond, callback)
}

type MkCondWalker struct{}

func (w *MkCondWalker) Walk(cond MkCond, callback *MkCondCallback) {
	switch {
	case cond.Or != nil:
		for _, or := range cond.Or {
			w.Walk(or, callback)
		}
	case cond.And != nil:
		for _, and := range cond.And {
			w.Walk(and, callback)
		}
	case cond.Not != nil:
		w.Walk(cond.Not, callback)

	case cond.Defined != "":
		if callback.Defined != nil {
			callback.Defined(cond.Defined)
		}
		if callback.VarUse != nil {
			callback.VarUse(&MkVarUse{cond.Defined, nil})
		}
	case cond.Empty != nil:
		if callback.Empty != nil {
			callback.Empty(cond.Empty)
		}
		if callback.VarUse != nil {
			callback.VarUse(cond.Empty)
		}
	case cond.CompareVarVar != nil:
		if callback.CompareVarVar != nil {
			cvv := cond.CompareVarVar
			callback.CompareVarVar(cvv.Left, cvv.Op, cvv.Right)
		}
		if callback.VarUse != nil {
			cvv := cond.CompareVarVar
			callback.VarUse(cvv.Left)
			callback.VarUse(cvv.Right)
		}
	case cond.CompareVarStr != nil:
		if callback.CompareVarStr != nil {
			cvs := cond.CompareVarStr
			callback.CompareVarStr(cvs.Var, cvs.Op, cvs.Str)
		}
		if callback.VarUse != nil {
			callback.VarUse(cond.CompareVarStr.Var)
		}
	case cond.CompareVarNum != nil:
		if callback.CompareVarNum != nil {
			cvn := cond.CompareVarNum
			callback.CompareVarNum(cvn.Var, cvn.Op, cvn.Num)
		}
		if callback.VarUse != nil {
			callback.VarUse(cond.CompareVarNum.Var)
		}
	case cond.Call != nil:
		if callback.Call != nil {
			call := cond.Call
			callback.Call(call.Name, call.Arg)
		}
	}
}
