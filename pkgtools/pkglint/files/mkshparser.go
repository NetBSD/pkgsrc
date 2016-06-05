package main

import (
	"fmt"
	"strconv"
)

type MkShParser struct {
	tok  *ShTokenizer
	curr *ShToken
}

func NewMkShParser(line *Line, text string, emitWarnings bool) *MkShParser {
	shp := NewShTokenizer(line, text, emitWarnings)
	return &MkShParser{shp, nil}
}

func (p *MkShParser) Program() (retval *MkShList) {
	defer p.trace(&retval)()

	list := p.List()
	if list == nil {
		return nil
	}
	separator := p.Separator()
	if separator == nil {
		return list
	}
	return &MkShList{list.AndOrs, append(list.Separators, *separator)}
}

// ::= AndOr (SeparatorOp AndOr)*
func (p *MkShParser) List() (retval *MkShList) {
	defer p.trace(&retval)()
	ok := false
	defer p.rollback(&ok)()

	var andors []*MkShAndOr
	var seps []MkShSeparator

	if andor := p.AndOr(); andor != nil {
		andors = append(andors, andor)
	} else {
		return nil
	}

next:
	mark := p.mark()
	if sep := p.SeparatorOp(); sep != nil {
		if andor := p.AndOr(); andor != nil {
			andors = append(andors, andor)
			seps = append(seps, *sep)
			goto next
		}
	}
	p.reset(mark)

	ok = true
	return &MkShList{andors, seps}
}

func (p *MkShParser) AndOr() (retval *MkShAndOr) {
	defer p.trace(&retval)()
	ok := false
	defer p.rollback(&ok)

	var pipes []*MkShPipeline
	var ops []string
nextpipe:
	if pipe := p.Pipeline(); pipe != nil {
		pipes = append(pipes, pipe)
		switch op := p.peekText(); op {
		case "&&", "||":
			p.skip()
			p.Linebreak()
			ops = append(ops, op)
			goto nextpipe
		}
	}

	if len(pipes) == len(ops) {
		return nil
	}
	ok = true
	return &MkShAndOr{pipes, ops}
}

// ::= Command (msttPipe Linebreak Command)*
func (p *MkShParser) Pipeline() (retval *MkShPipeline) {
	defer p.trace(&retval)()
	ok := false
	defer p.rollback(&ok)()

	bang := p.eat("!")
	var cmds []*MkShCommand
nextcmd:
	cmd := p.Command()
	if cmd == nil {
		return nil
	}
	cmds = append(cmds, cmd)
	if p.eat("|") {
		p.Linebreak()
		goto nextcmd
	}
	ok = true
	return &MkShPipeline{bang, cmds}
}

func (p *MkShParser) Command() (retval *MkShCommand) {
	defer p.trace(&retval)()

	if simple := p.SimpleCommand(); simple != nil {
		return &MkShCommand{Simple: simple}
	}
	if compound := p.CompoundCommand(); compound != nil {
		redirects := p.RedirectList()
		return &MkShCommand{Compound: compound, Redirects: redirects}
	}
	if funcdef := p.FunctionDefinition(); funcdef != nil {
		return &MkShCommand{FuncDef: funcdef}
	}
	return nil
}

func (p *MkShParser) CompoundCommand() (retval *MkShCompoundCommand) {
	defer p.trace(&retval)()

	if brace := p.BraceGroup(); brace != nil {
		return &MkShCompoundCommand{Brace: brace}
	}
	if subshell := p.Subshell(); subshell != nil {
		return &MkShCompoundCommand{Subshell: subshell}
	}
	if forclause := p.ForClause(); forclause != nil {
		return &MkShCompoundCommand{For: forclause}
	}
	if caseclause := p.CaseClause(); caseclause != nil {
		return &MkShCompoundCommand{Case: caseclause}
	}
	if ifclause := p.IfClause(); ifclause != nil {
		return &MkShCompoundCommand{If: ifclause}
	}
	if whileclause := p.WhileClause(); whileclause != nil {
		return &MkShCompoundCommand{While: whileclause}
	}
	if untilclause := p.UntilClause(); untilclause != nil {
		return &MkShCompoundCommand{Until: untilclause}
	}
	return nil
}

func (p *MkShParser) Subshell() (retval *MkShList) {
	defer p.trace(&retval)()
	ok := false
	defer p.rollback(&ok)()

	if !p.eat("(") {
		return nil
	}
	list := p.CompoundList()
	if list == nil {
		return nil
	}
	if !p.eat(")") {
		return nil
	}
	ok = true
	return list
}

// ::= Newline* AndOr (Separator AndOr)* Separator?
func (p *MkShParser) CompoundList() (retval *MkShList) {
	defer p.trace(&retval)()
	ok := false
	defer p.rollback(&ok)()

	p.Linebreak()
	var andors []*MkShAndOr
	var separators []MkShSeparator
nextandor:
	if andor := p.AndOr(); andor != nil {
		andors = append(andors, andor)
		if sep := p.Separator(); sep != nil {
			separators = append(separators, *sep)
			goto nextandor
		}
	}
	if len(andors) == 0 {
		return nil
	}
	ok = true
	return &MkShList{andors, separators}
}

// ::= "for" msttWORD Linebreak DoGroup
// ::= "for" msttWORD Linebreak "in" SequentialSep DoGroup
// ::= "for" msttWORD Linebreak "in" Wordlist SequentialSep DoGroup
func (p *MkShParser) ForClause() (retval *MkShForClause) {
	defer p.trace(&retval)()
	ok := false
	defer p.rollback(&ok)()

	if !p.eat("for") {
		return nil
	}
	varword := p.Word(false)
	if varword == nil || !matches(varword.MkText, `^[A-Z_a-z][0-9A-Za-z]*`) {
		return nil
	}
	varname := varword.MkText

	var values []*ShToken
	if p.eat("in") {
		values = p.Wordlist()
	} else {
		values = []*ShToken{NewShToken("\"$$@\"",
			NewShAtom(shtWord, "\"", shqDquot),
			NewShAtom(shtWord, "$$@", shqDquot),
			NewShAtom(shtWord, "\"", shqPlain))}
	}
	if values == nil || !p.SequentialSep() {
		return nil
	}

	p.Linebreak()
	body := p.DoGroup()
	if body == nil {
		return nil
	}

	ok = true
	return &MkShForClause{varname, values, body}
}

func (p *MkShParser) Wordlist() (retval []*ShToken) {
	defer p.trace(&retval)()

	var words []*ShToken
nextword:
	word := p.Word(false)
	if word != nil {
		words = append(words, word)
		goto nextword
	}
	return words
}

// ::= "case" msttWORD Linebreak "in" Linebreak CaseItem* "esac"
func (p *MkShParser) CaseClause() (retval *MkShCaseClause) {
	defer p.trace(&retval)()
	ok := false
	defer p.rollback(&ok)()

	if !p.eat("case") {
		return nil
	}

	panic("CaseClause")
	p.Linebreak()
	p.CaseItem()
	return nil
}

// ::= "("? Pattern ")" (CompoundList | Linebreak) msttDSEMI? Linebreak
func (p *MkShParser) CaseItem() (retval *MkShCaseItem) {
	defer p.trace(&retval)()

	panic("CaseItem")
	p.Pattern()
	p.Linebreak()
	p.CompoundList()
	return nil
}

// ::= msttWORD
// ::= Pattern "|" msttWORD
func (p *MkShParser) Pattern() (retval []*ShToken) {
	defer p.trace(&retval)()
	ok := false
	defer p.rollback(&ok)()

	var words []*ShToken
nextword:
	word := p.Word(false)
	if word == nil {
		return nil
	}
	words = append(words, word)
	if p.eat("|") {
		goto nextword

	}
	ok = true
	return words
}

func (p *MkShParser) IfClause() (retval *MkShIfClause) {
	defer p.trace(&retval)()
	ok := false
	defer p.rollback(&ok)()

	var conds []*MkShList
	var actions []*MkShList
	var elseaction *MkShList
	if !p.eat("if") {
		return nil
	}

nextcond:
	cond := p.CompoundList()
	if cond == nil || !p.eat("then") {
		return nil
	}
	action := p.CompoundList()
	if action == nil {
		return nil
	}
	conds = append(conds, cond)
	actions = append(actions, action)
	if p.eat("elif") {
		goto nextcond
	}
	if p.eat("else") {
		elseaction = p.CompoundList()
		if elseaction == nil {
			return nil
		}
	}
	if !p.eat("fi") {
		return nil
	}
	ok = true
	return &MkShIfClause{conds, actions, elseaction}
}

// ::= "while" CompoundList DoGroup
func (p *MkShParser) WhileClause() (retval *MkShLoopClause) {
	defer p.trace(&retval)()
	ok := false
	defer p.rollback(&ok)()

	if !p.eat("while") {
		return nil
	}

	panic("WhileClause")
	p.CompoundList()
	p.DoGroup()
	return nil
}

// ::= "until" CompoundList DoGroup
func (p *MkShParser) UntilClause() (retval *MkShLoopClause) {
	defer p.trace(&retval)()
	ok := false
	defer p.rollback(&ok)()

	if !p.eat("until") {
		return nil
	}

	panic("UntilClause")
	p.CompoundList()
	p.DoGroup()
	return nil
}

// ::= msttNAME "(" ")" Linebreak CompoundCommand Redirect*
func (p *MkShParser) FunctionDefinition() (retval *MkShFunctionDefinition) {
	defer p.trace(&retval)()
	ok := false
	defer p.rollback(&ok)()

	funcname := p.Word(true)
	if funcname == nil || !matches(funcname.MkText, `^[A-Z_a-z][0-9A-Z_a-z]*$`) {
		return nil
	}

	if !p.eat("(") || !p.eat(")") {
		return nil
	}

	p.Linebreak()

	body := p.CompoundCommand()
	if body == nil {
		return nil
	}

	redirects := p.RedirectList()
	ok = true
	return &MkShFunctionDefinition{funcname.MkText, body, redirects}
}

func (p *MkShParser) BraceGroup() (retval *MkShList) {
	defer p.trace(&retval)()
	ok := false
	defer p.rollback(&ok)()

	if !p.eat("{") {
		return nil
	}
	list := p.CompoundList()
	if list == nil {
		return nil
	}
	if !p.eat("}") {
		return nil
	}
	ok = true
	return list
}

func (p *MkShParser) DoGroup() (retval *MkShList) {
	defer p.trace(&retval)()
	ok := false
	defer p.rollback(&ok)()

	if !p.eat("do") {
		return nil
	}
	list := p.CompoundList()
	if list == nil {
		return nil
	}
	if !p.eat("done") {
		return nil
	}
	ok = true
	return list
}

func (p *MkShParser) SimpleCommand() (retval *MkShSimpleCommand) {
	defer p.trace(&retval)()
	ok := false
	defer p.rollback(&ok)()

	var assignments []*ShToken
	var name *ShToken
	var args []*ShToken
	var redirections []*MkShRedirection
	first := true
	seenName := false
nextword:
	if word := p.Word(first); word != nil {
		first = false
		if !seenName && word.IsAssignment() {
			assignments = append(assignments, word)
		} else if !seenName {
			name = word
			seenName = true
		} else {
			args = append(args, word)
		}
		goto nextword
	}
	if len(assignments) == 0 && name == nil && len(args) == 0 && len(redirections) == 0 {
		return nil
	}
	ok = true
	return &MkShSimpleCommand{assignments, name, args, redirections}
}

func (p *MkShParser) RedirectList() (retval []*MkShRedirection) {
	defer p.trace(&retval)()

nextredirect:
	if redirect := p.IoRedirect(); redirect != nil {
		retval = append(retval, redirect)
		goto nextredirect
	}
	return nil
}

func (p *MkShParser) IoRedirect() (retval *MkShRedirection) {
	defer p.trace(&retval)()

	if m, redirect, fdstr, op := match3(p.peekText(), `^((\d*)\s*(<|<&|>|>&|>>|<>|>\||<<|<<-))`); m {
		target := p.peekText()[len(redirect):]
		_, _, _ = fdstr, op, target

		fd, err := strconv.ParseInt(fdstr, 10, 32)
		if err != nil {
			fd = -1
		}
		p.skip()
		targetToken := NewShTokenizer(p.tok.mkp.Line, target, false).ShToken()
		return &MkShRedirection{int(fd), op, targetToken}
	}
	return nil
}

func (p *MkShParser) NewlineList() (retval bool) {
	defer p.trace(&retval)()

	ok := false
	for p.eat("\n") {
		ok = true
	}
	return ok
}

func (p *MkShParser) Linebreak() {
	for p.eat("\n") {
	}
}

func (p *MkShParser) SeparatorOp() (retval *MkShSeparator) {
	defer p.trace(&retval)()

	if p.eat(";") {
		op := MkShSeparator(";")
		return &op
	}
	if p.eat("&") {
		op := MkShSeparator("&")
		return &op
	}
	return nil
}

func (p *MkShParser) Separator() (retval *MkShSeparator) {
	defer p.trace(&retval)()

	op := p.SeparatorOp()
	if op == nil && p.eat("\n") {
		sep := MkShSeparator('\n')
		op = &sep
	}
	if op != nil {
		p.Linebreak()
	}
	return op
}

func (p *MkShParser) SequentialSep() (retval bool) {
	defer p.trace(&retval)()

	if p.peekText() == ";" {
		p.skip()
		p.Linebreak()
		return true
	} else {
		return p.NewlineList()
	}
}

func (p *MkShParser) Word(cmdstart bool) (retval *ShToken) {
	defer p.trace(&retval)()

	if token := p.peek(); token != nil && token.IsWord() {
		if cmdstart {
			switch token.MkText {
			case "while", "until", "for", "do", "done",
				"if", "then", "else", "elif", "fi",
				"{", "}":
				return nil
			}
		}
		p.skip()
		return token
	}
	return nil
}

func (p *MkShParser) EOF() bool {
	return p.peek() == nil
}

func (p *MkShParser) peek() *ShToken {
	if p.curr == nil {
	nexttoken:
		p.curr = p.tok.ShToken()
		if p.curr == nil && !p.tok.parser.EOF() {
			p.tok.mkp.Line.Warnf("Pkglint tokenize error at " + p.tok.parser.Rest())
			p.tok.mkp.Parser.repl.AdvanceRest()
			return nil
		}
		if p.curr != nil && hasPrefix(p.curr.MkText, "#") {
			goto nexttoken
		}
	}
	//traceStep("MkShParser.peek %v rest=%q", p.curr, p.tok.mkp.repl.rest)
	return p.curr
}

func (p *MkShParser) peekText() string {
	if next := p.peek(); next != nil {
		return next.MkText
	}
	return ""
}

func (p *MkShParser) skip() {
	p.curr = nil
}

func (p *MkShParser) eat(s string) bool {
	if p.peek() == nil {
		return false
	}
	if p.peek().MkText == s {
		p.skip()
		return true
	}
	return false
}

func (p *MkShParser) rollback(pok *bool) func() {
	mark := p.mark()
	return func() {
		if !*pok {
			p.reset(mark)
		}
	}
}

func (p *MkShParser) trace(retval interface{}) func() {
	if G.opts.Debug {
		return tracecallInternal(p.peek(), p.restref(), "=>", ref(retval))
	} else {
		return func() {}
	}
}

func (p *MkShParser) mark() MkShParserMark {
	return MkShParserMark{p.tok.parser.repl.Mark(), p.curr}
}

func (p *MkShParser) reset(mark MkShParserMark) {
	p.tok.parser.repl.Reset(mark.rest)
	p.curr = mark.curr
}

func (p *MkShParser) restref() MkShParserRest {
	return MkShParserRest{&p.tok.mkp.repl.rest}
}

func (p *MkShParser) Rest() string {
	return p.peekText() + p.tok.mkp.repl.AdvanceRest()
}

type MkShParserMark struct {
	rest PrefixReplacerMark
	curr *ShToken
}

type MkShParserRest struct {
	restref *string
}

func (rest MkShParserRest) String() string {
	return fmt.Sprintf("rest=%q", *rest.restref)
}
