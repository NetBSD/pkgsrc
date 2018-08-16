package main

import (
	"netbsd.org/pkglint/regex"
	"netbsd.org/pkglint/trace"
	"strings"
)

type MkParser struct {
	*Parser
}

func NewMkParser(line Line, text string, emitWarnings bool) *MkParser {
	return &MkParser{NewParser(line, text, emitWarnings)}
}

func (p *MkParser) MkTokens() []*MkToken {
	repl := p.repl

	var tokens []*MkToken
	for !p.EOF() {
		if repl.AdvanceStr("#") {
			repl.AdvanceRest()
		}

		mark := repl.Mark()
		if varuse := p.VarUse(); varuse != nil {
			tokens = append(tokens, &MkToken{Text: repl.Since(mark), Varuse: varuse})
			continue
		}

	again:
		dollar := strings.IndexByte(repl.Rest(), '$')
		if dollar == -1 {
			dollar = len(repl.Rest())
		}
		repl.Skip(dollar)
		if repl.AdvanceStr("$$") {
			goto again
		}
		text := repl.Since(mark)
		if text != "" {
			tokens = append(tokens, &MkToken{Text: text})
			continue
		}

		break
	}
	return tokens
}

func (p *MkParser) VarUse() *MkVarUse {
	repl := p.repl

	mark := repl.Mark()
	if repl.AdvanceStr("${") || repl.AdvanceStr("$(") {
		usingRoundParen := repl.Since(mark) == "$("
		closing := ifelseStr(usingRoundParen, ")", "}")

		varnameMark := repl.Mark()
		varname := p.Varname()
		if varname != "" {
			modifiers := p.VarUseModifiers(varname, closing)
			if repl.AdvanceStr(closing) {
				if usingRoundParen && p.EmitWarnings {
					parenVaruse := repl.Since(mark)
					bracesVaruse := "${" + parenVaruse[2:len(parenVaruse)-1] + "}"
					fix := p.Line.Autofix()
					fix.Warnf("Please use curly braces {} instead of round parentheses () for %s.", varname)
					fix.Replace(parenVaruse, bracesVaruse)
					fix.Apply()
				}
				return &MkVarUse{varname, modifiers}
			}
		}

		for p.VarUse() != nil || repl.AdvanceRegexp(regex.Pattern(`^([^$:`+closing+`]|\$\$)+`)) {
		}
		rest := p.Rest()
		if hasPrefix(rest, ":L") || hasPrefix(rest, ":?") {
			varexpr := repl.Since(varnameMark)
			modifiers := p.VarUseModifiers(varexpr, closing)
			if repl.AdvanceStr(closing) {
				return &MkVarUse{varexpr, modifiers}
			}
		}
		repl.Reset(mark)
	}

	if repl.AdvanceStr("$@") {
		return &MkVarUse{"@", nil}
	}
	if repl.AdvanceStr("$<") {
		return &MkVarUse{"<", nil}
	}
	if repl.PeekByte() == '$' && repl.AdvanceRegexp(`^\$(\w)`) {
		varname := repl.Group(1)
		if p.EmitWarnings {
			p.Line.Warnf("$%[1]s is ambiguous. Use ${%[1]s} if you mean a Makefile variable or $$%[1]s if you mean a shell variable.", varname)
		}
		return &MkVarUse{varname, nil}
	}
	return nil
}

func (p *MkParser) VarUseModifiers(varname, closing string) []string {
	repl := p.repl

	var modifiers []string
	mayOmitColon := false
loop:
	for repl.AdvanceStr(":") || mayOmitColon {
		mayOmitColon = false
		modifierMark := repl.Mark()

		switch repl.PeekByte() {
		case 'E', 'H', 'L', 'O', 'Q', 'R', 'T', 's', 't', 'u':
			if repl.AdvanceRegexp(`^(E|H|L|Ox?|Q|R|T|sh|tA|tW|tl|tu|tw|u)`) {
				modifiers = append(modifiers, repl.Since(modifierMark))
				continue
			}
			if repl.AdvanceStr("ts") {
				rest := repl.Rest()
				if len(rest) >= 2 && (rest[1] == closing[0] || rest[1] == ':') {
					repl.Skip(1)
				} else if len(rest) >= 1 && (rest[0] == closing[0] || rest[0] == ':') {
				} else if repl.AdvanceRegexp(`^\\\d+`) {
				} else {
					break loop
				}
				modifiers = append(modifiers, repl.Since(modifierMark))
				continue
			}

		case '=', 'D', 'M', 'N', 'U':
			if repl.AdvanceRegexp(`^[=DMNU]`) {
				for p.VarUse() != nil || repl.AdvanceRegexp(regex.Pattern(`^([^$:`+closing+`]|\$\$)+`)) {
				}
				modifiers = append(modifiers, repl.Since(modifierMark))
				continue
			}

		case 'C', 'S':
			if repl.AdvanceRegexp(`^[CS]([%,/:;@^|])`) {
				separator := repl.Group(1)
				repl.AdvanceStr("^")
				re := regex.Pattern(`^([^\` + separator + `$` + closing + `\\]|\$\$|\\.)+`)
				for p.VarUse() != nil || repl.AdvanceRegexp(re) {
				}
				repl.AdvanceStr("$")
				if repl.AdvanceStr(separator) {
					for p.VarUse() != nil || repl.AdvanceRegexp(re) {
					}
					if repl.AdvanceStr(separator) {
						repl.AdvanceRegexp(`^[1gW]`)
						modifiers = append(modifiers, repl.Since(modifierMark))
						mayOmitColon = true
						continue
					}
				}
			}

		case '@':
			if repl.AdvanceRegexp(`^@([\w.]+)@`) {
				loopvar := repl.Group(1)
				for p.VarUse() != nil || repl.AdvanceRegexp(regex.Pattern(`^([^$:@`+closing+`\\]|\$\$|\\.)+`)) {
				}
				if !repl.AdvanceStr("@") && p.EmitWarnings {
					p.Line.Warnf("Modifier ${%s:@%s@...@} is missing the final \"@\".", varname, loopvar)
				}
				modifiers = append(modifiers, repl.Since(modifierMark))
				continue
			}

		case '[':
			if repl.AdvanceRegexp(`^\[(?:[-.\d]+|#)\]`) {
				modifiers = append(modifiers, repl.Since(modifierMark))
				continue
			}

		case '?':
			repl.AdvanceStr("?")
			re := regex.Pattern(`^([^$:` + closing + `]|\$\$)+`)
			for p.VarUse() != nil || repl.AdvanceRegexp(re) {
			}
			if repl.AdvanceStr(":") {
				for p.VarUse() != nil || repl.AdvanceRegexp(re) {
				}
				modifiers = append(modifiers, repl.Since(modifierMark))
				continue
			}
		}

		repl.Reset(modifierMark)
		for p.VarUse() != nil || repl.AdvanceRegexp(regex.Pattern(`^([^:$`+closing+`]|\$\$)+`)) {
		}
		if suffixSubst := repl.Since(modifierMark); contains(suffixSubst, "=") {
			modifiers = append(modifiers, suffixSubst)
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
		mark := p.repl.Mark()
		if !p.repl.AdvanceRegexp(`^\s*\|\|\s*`) {
			break
		}
		next := p.mkCondAnd()
		if next == nil {
			p.repl.Reset(mark)
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
		mark := p.repl.Mark()
		if !p.repl.AdvanceRegexp(`^\s*&&\s*`) {
			break
		}
		next := p.mkCondAtom()
		if next == nil {
			p.repl.Reset(mark)
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

	repl := p.repl
	mark := repl.Mark()
	repl.SkipSpace()
	switch {
	case repl.AdvanceStr("!"):
		cond := p.mkCondAtom()
		if cond != nil {
			return &mkCond{Not: cond}
		}
	case repl.AdvanceStr("("):
		cond := p.MkCond()
		if cond != nil {
			repl.SkipSpace()
			if repl.AdvanceStr(")") {
				return cond
			}
		}
	case repl.AdvanceRegexp(`^defined\s*\(`):
		if varname := p.Varname(); varname != "" {
			if repl.AdvanceStr(")") {
				return &mkCond{Defined: varname}
			}
		}
	case repl.AdvanceRegexp(`^empty\s*\(`):
		if varname := p.Varname(); varname != "" {
			modifiers := p.VarUseModifiers(varname, ")")
			if repl.AdvanceStr(")") {
				return &mkCond{Empty: &MkVarUse{varname, modifiers}}
			}
		}
	case repl.AdvanceRegexp(`^(commands|exists|make|target)\s*\(`):
		funcname := repl.Group(1)
		argMark := repl.Mark()
		for p.VarUse() != nil || repl.AdvanceRegexp(`^[^$)]+`) {
		}
		arg := repl.Since(argMark)
		if repl.AdvanceStr(")") {
			return &mkCond{Call: &MkCondCall{funcname, arg}}
		}
	default:
		lhs := p.VarUse()
		mark := repl.Mark()
		if lhs == nil && repl.AdvanceStr("\"") {
			if quotedLHS := p.VarUse(); quotedLHS != nil && repl.AdvanceStr("\"") {
				lhs = quotedLHS
			} else {
				repl.Reset(mark)
			}
		}
		if lhs != nil {
			if repl.AdvanceRegexp(`^\s*(<|<=|==|!=|>=|>)\s*(\d+(?:\.\d+)?)`) {
				return &mkCond{CompareVarNum: &MkCondCompareVarNum{lhs, repl.Group(1), repl.Group(2)}}
			}
			if repl.AdvanceRegexp(`^\s*(<|<=|==|!=|>=|>)\s*`) {
				op := repl.Group(1)
				if (op == "!=" || op == "==") && repl.AdvanceRegexp(`^"([^"\$\\]*)"`) {
					return &mkCond{CompareVarStr: &MkCondCompareVarStr{lhs, op, repl.Group(1)}}
				} else if repl.AdvanceRegexp(`^\w+`) {
					return &mkCond{CompareVarStr: &MkCondCompareVarStr{lhs, op, repl.Group(0)}}
				} else if rhs := p.VarUse(); rhs != nil {
					return &mkCond{CompareVarVar: &MkCondCompareVarVar{lhs, op, rhs}}
				} else if repl.PeekByte() == '"' {
					mark := repl.Mark()
					if repl.AdvanceStr("\"") {
						if quotedRHS := p.VarUse(); quotedRHS != nil {
							if repl.AdvanceStr("\"") {
								return &mkCond{CompareVarVar: &MkCondCompareVarVar{lhs, op, quotedRHS}}
							}
						}
					}
					repl.Reset(mark)
				}
			} else {
				return &mkCond{Not: &mkCond{Empty: lhs}} // See devel/bmake/files/cond.c:/\* For \.if \$/
			}
		}
		if repl.AdvanceRegexp(`^\d+(?:\.\d+)?`) {
			return &mkCond{Num: repl.Group(0)}
		}
	}
	repl.Reset(mark)
	return nil
}

func (p *MkParser) Varname() string {
	repl := p.repl

	mark := repl.Mark()
	repl.AdvanceStr(".")
	isVarnameChar := func(c byte) bool {
		return 'A' <= c && c <= 'Z' || c == '_' || 'a' <= c && c <= 'z' || '0' <= c && c <= '9' || c == '+' || c == '-' || c == '.' || c == '*'
	}
	for p.VarUse() != nil || repl.AdvanceBytesFunc(isVarnameChar) {
	}
	return repl.Since(mark)
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
}

type MkCondWalker struct{}

func NewMkCondWalker() *MkCondWalker { return &MkCondWalker{} }

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
	case cond.Empty != nil:
		if callback.Empty != nil {
			callback.Empty(cond.Empty)
		}
	case cond.CompareVarVar != nil:
		if callback.CompareVarVar != nil {
			cvv := cond.CompareVarVar
			callback.CompareVarVar(cvv.Left, cvv.Op, cvv.Right)
		}
	case cond.CompareVarStr != nil:
		if callback.CompareVarStr != nil {
			cvs := cond.CompareVarStr
			callback.CompareVarStr(cvs.Var, cvs.Op, cvs.Str)
		}
	case cond.CompareVarNum != nil:
		if callback.CompareVarNum != nil {
			cvn := cond.CompareVarNum
			callback.CompareVarNum(cvn.Var, cvn.Op, cvn.Num)
		}
	case cond.Call != nil:
		if callback.Call != nil {
			call := cond.Call
			callback.Call(call.Name, call.Arg)
		}
	}
}
