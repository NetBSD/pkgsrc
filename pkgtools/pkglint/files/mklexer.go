package pkglint

import (
	"netbsd.org/pkglint/regex"
	"netbsd.org/pkglint/textproc"
	"strings"
)

// MkLexer splits a text into a sequence of variable uses
// and plain text.
//
// The actual parsing algorithm in devel/bmake/files/var.c differs from
// pkglint's parser in many ways and produces different results in
// almost all edge cases. See devel/bmake/files/var.c:/'\\\\'/.
//
// The pkglint parser had been built from scratch using naive assumptions
// about how bmake parses these expressions. These assumptions do not hold
// a strict test, but luckily the pkgsrc package developers don't explore
// these edge cases anyway.
type MkLexer struct {
	lexer *textproc.Lexer
	diag  Autofixer
}

func NewMkLexer(text string, diag Autofixer) *MkLexer {
	return &MkLexer{textproc.NewLexer(text), diag}
}

// MkTokens splits a text like in the following example:
//  Text${VAR:Mmodifier}${VAR2}more text${VAR3}
// into tokens like these:
//  Text
//  ${VAR:Mmodifier}
//  ${VAR2}
//  more text
//  ${VAR3}
func (p *MkLexer) MkTokens() ([]*MkToken, string) {
	lexer := p.lexer

	var tokens []*MkToken
	for !lexer.EOF() {
		token := p.MkToken()
		if token == nil {
			break
		}
		tokens = append(tokens, token)
	}
	return tokens, lexer.Rest()
}

func (p *MkLexer) MkToken() *MkToken {
	lexer := p.lexer

	mark := lexer.Mark()
	if varuse := p.VarUse(); varuse != nil {
		return &MkToken{Text: lexer.Since(mark), Varuse: varuse}
	}

	for lexer.SkipBytesFunc(func(b byte) bool { return b != '$' }) || lexer.SkipString("$$") {
	}
	text := lexer.Since(mark)
	if text != "" {
		return &MkToken{Text: text}
	}
	return nil
}

// VarUse parses a variable expression like ${VAR}, $@, ${VAR:Mpattern:Ox}.
func (p *MkLexer) VarUse() *MkVarUse {
	rest := p.lexer.Rest()
	if len(rest) < 2 || rest[0] != '$' {
		return nil
	}

	switch rest[1] {
	case '{', '(':
		return p.varUseBrace(rest[1] == '(')

	case '$':
		// This is an escaped dollar character and not a variable use.
		return nil

	case '>', '!', '<', '%', '?', '*', '@', ' ':
		// These variable names are known to exist.
		//
		// Many others are also possible but not used in practice.
		// In particular, when parsing the :C or :S modifier,
		// the $ must not be interpreted as a variable name,
		// even when it looks like $/ could refer to the "/" variable.
		//
		// Example:
		//  ${:U }= space
		//  ${:U"}= quot
		//
		//  all:
		//	    @echo ${ } $ d, ${"} $"ed   # space spaced, quote quoted
		//
		// TODO: Find out whether $" is a variable use when it appears in the :M modifier.
		p.lexer.Skip(2)
		return NewMkVarUse(rest[1:2])

	default:
		return p.varUseAlnum()
	}
}

// varUseBrace parses:
//  ${VAR}
//  ${arbitrary text:L}
//  ${variable with invalid chars}
//  $(PARENTHESES)
//  ${VAR:Mpattern:C,:,colon,g:Q:Q:Q}
func (p *MkLexer) varUseBrace(usingRoundParen bool) *MkVarUse {
	lexer := p.lexer

	beforeDollar := lexer.Mark()
	lexer.Skip(2)

	closing := byte('}')
	if usingRoundParen {
		closing = ')'
	}

	beforeVarname := lexer.Mark()
	varname := p.Varname()
	p.varUseText(closing)
	varExpr := lexer.Since(beforeVarname)

	modifiers := p.VarUseModifiers(varExpr, closing)

	closed := lexer.SkipByte(closing)

	if p.diag != nil {
		if !closed {
			p.Warnf("Missing closing %q for %q.", string(rune(closing)), varExpr)
		}

		if usingRoundParen && closed {
			parenVaruse := lexer.Since(beforeDollar)
			edit := []byte(parenVaruse)
			edit[1] = '{'
			edit[len(edit)-1] = '}'
			bracesVaruse := string(edit)

			fix := p.Autofix()
			fix.Warnf("Please use curly braces {} instead of round parentheses () for %s.", varExpr)
			fix.Replace(parenVaruse, bracesVaruse)
			fix.Apply()
		}

		if len(varExpr) > len(varname) && !NewMkVarUse(varExpr, modifiers...).IsExpression() {
			p.Warnf("Invalid part %q after variable name %q.", varExpr[len(varname):], varname)
		}
	}

	return NewMkVarUse(varExpr, modifiers...)
}

func (p *MkLexer) Varname() string {
	lexer := p.lexer

	mark := lexer.Mark()
	lexer.SkipByte('.')
	for lexer.NextBytesSet(VarbaseBytes) != "" || p.VarUse() != nil {
	}
	if lexer.SkipByte('.') || hasPrefix(lexer.Since(mark), "SITES_") {
		for lexer.NextBytesSet(VarparamBytes) != "" || p.VarUse() != nil {
		}
	}
	return lexer.Since(mark)
}

// varUseText parses any text up to the next colon or closing mark.
// Nested variable uses are parsed as well.
//
// This is used for the :L and :? modifiers since they accept arbitrary
// text as the "variable name" and effectively interpret it as the variable
// value instead.
//
// See devel/bmake/files/var.c:/^VarGetPattern/
func (p *MkLexer) varUseText(closing byte) string {
	lexer := p.lexer
	start := lexer.Mark()
	re := regcomp(regex.Pattern(condStr(closing == '}', `^([^$:\\}]|\$\$|\\.)+`, `^([^$:\\)]|\$\$|\\.)+`)))
	for p.VarUse() != nil || lexer.SkipRegexp(re) {
	}
	return lexer.Since(start)
}

// varUseText parses any text up to the closing mark, including any colons.
//
// This is used for the :from=to modifier.
//
// See devel/bmake/files/var.c:/eqFound = FALSE/
func (p *MkLexer) varUseModifierSysV(closing byte) (string, string) {
	lexer := p.lexer
	start := lexer.Mark()
	re := regcomp(regex.Pattern(condStr(closing == '}', `^([^$\\}]|\$\$|\\.)+`, `^([^$\\)]|\$\$|\\.)+`)))

	noVars := NewLazyStringBuilder(lexer.Rest())
	// pkglint deviates from bmake here by properly parsing nested
	// variables. bmake only counts opening and closing characters.
	for {
		if p.VarUse() != nil {
			continue
		}
		m := lexer.NextRegexp(re)
		if len(m) == 0 {
			break
		}
		noVars.WriteString(m[0])
	}
	return lexer.Since(start), noVars.String()
}

// VarUseModifiers parses the modifiers of a variable being used, such as :Q, :Mpattern.
//
// See the bmake manual page.
func (p *MkLexer) VarUseModifiers(varname string, closing byte) []MkVarUseModifier {
	lexer := p.lexer

	var modifiers []MkVarUseModifier
	// The :S and :C modifiers may be chained without using the : as separator.
	mayOmitColon := false

	for lexer.SkipByte(':') || mayOmitColon {
		modifier := p.varUseModifier(varname, closing)
		if modifier != "" {
			modifiers = append(modifiers, MkVarUseModifier{modifier})
		}
		mayOmitColon = modifier != "" && (modifier[0] == 'S' || modifier[0] == 'C')
	}
	return modifiers
}

// varUseModifier parses a single variable modifier such as :Q or :S,from,to,.
// The actual parsing starts after the leading colon.
func (p *MkLexer) varUseModifier(varname string, closing byte) string {
	lexer := p.lexer
	mark := lexer.Mark()

	switch lexer.PeekByte() {
	case 'E', 'H', 'L', 'O', 'Q', 'R', 'T', 's', 't', 'u':
		mod := lexer.NextBytesSet(textproc.Alnum)

		switch mod {
		case
			"E",  // Extension, e.g. path/file.suffix => suffix
			"H",  // Head, e.g. dir/subdir/file.suffix => dir/subdir
			"L",  // XXX: Shouldn't this be handled specially?
			"O",  // Order alphabetically
			"Ox", // Shuffle
			"Q",  // Quote shell meta-characters
			"R",  // Strip the file suffix, e.g. path/file.suffix => file
			"T",  // Basename, e.g. path/file.suffix => file.suffix
			"sh", // Evaluate the variable value as shell command
			"tA", // Try to convert to absolute path
			"tW", // Causes the value to be treated as a single word
			"tl", // To lowercase
			"tu", // To uppercase
			"tw", // Causes the value to be treated as list of words
			"u":  // Remove adjacent duplicate words (like uniq(1))
			return mod
		}

		if hasPrefix(mod, "ts") {
			return p.varUseModifierTs(mod, closing, lexer, varname, mark)
		}

	case 'D', 'U':
		return p.varUseText(closing)

	case 'M', 'N':
		return p.varUseModifierMatch(closing)

	case 'C', 'S':
		if ok, _, _, _, _ := p.varUseModifierSubst(closing); ok {
			return lexer.Since(mark)
		}

	case '@':
		if p.varUseModifierAt(lexer, varname) {
			return lexer.Since(mark)
		}

	case '[':
		if lexer.SkipRegexp(regcomp(`^\[(?:[-.\d]+|#)\]`)) {
			return lexer.Since(mark)
		}

	case '?':
		lexer.Skip(1)
		p.varUseText(closing)
		if lexer.SkipByte(':') {
			p.varUseText(closing)
			return lexer.Since(mark)
		}

	case ':':
		lexer.Skip(1)
		if !lexer.SkipRegexp(regcomp(`^[!+?]?=`)) {
			break
		}

		// The corresponding code in bmake is much more complicated
		// because it evaluates the expression immediately instead of
		// only parsing it.
		//
		// This modifier should not be used at all since it hides
		// variable assignments deep in a line.
		//
		// It could also happen that the assignment happens in an
		// indirect variable reference, which is even more unexpected.
		if varname == "" {
			p.Errorf("Assignment to the empty variable is not possible.")
			break
		}

		p.Errorf("Assignment modifiers like %q must not be used at all.",
			lexer.Since(mark))
		p.Explain(
			"These modifiers modify other variables when they are evaluated.",
			"This makes it more difficult to understand them since all the",
			"other modifiers only affect the one expression that is being",
			"evaluated, without any long-lasting side effects.",
			"",
			"A similarly unpredictable mechanism are shell commands,",
			"but even these have only local consequences.")

		p.varUseText(closing)
		return lexer.Since(mark)
	}

	// ${SOURCES:%.c=%.o}
	lexer.Reset(mark)
	modifier, modifierNoVar := p.varUseModifierSysV(closing)
	if contains(modifier, "=") {
		if contains(modifierNoVar, ":") {
			unrealModifier := modifier[strings.Index(modifier, ":"):]
			p.Warnf("The text %q looks like a modifier but isn't.", unrealModifier)
			p.Explain(
				"The :from=to modifier consumes all the text until the end of the variable.",
				"There cannot be any further modifiers after it.")
		}
		return modifier
	}

	// ${:!uname -a!:[2]}
	lexer.Reset(mark)
	modifier = p.varUseText(closing)
	if hasPrefix(modifier, "!") && hasSuffix(modifier, "!") {
		return modifier
	}

	if modifier != "" {
		p.Warnf("Invalid variable modifier %q for %q.", modifier, varname)
	}

	return ""
}

// varUseModifierTs parses the :ts modifier.
//
// The API of this method is tricky.
// It is only extracted from varUseModifier to make the latter smaller.
func (p *MkLexer) varUseModifierTs(
	mod string, closing byte, lexer *textproc.Lexer, varname string,
	mark textproc.LexerMark) string {

	// See devel/bmake/files/var.c:/case 't'
	sep := mod[2:] + p.varUseText(closing)
	switch {
	case sep == "":
		lexer.SkipString(":")
	case len(sep) == 1:
		break
	case matches(sep, `^\\\d+`):
		break
	default:
		p.Warnf("Invalid separator %q for :ts modifier of %q.", sep, varname)
		p.Explain(
			"The separator for the :ts modifier must be either a single character",
			"or an escape sequence like \\t or \\n or an octal or decimal escape",
			"sequence; see the bmake man page for further details.")
	}
	return lexer.Since(mark)
}

// varUseModifierMatch parses an :M or :N pattern.
//
// See devel/bmake/files/var.c:/^ApplyModifiers/, case 'M'.
func (p *MkLexer) varUseModifierMatch(closing byte) string {
	lexer := p.lexer
	mark := lexer.Mark()
	lexer.Skip(1)
	opening := byte(condInt(closing == '}', '{', '('))
	_ = opening

	nest := 1
	seenBackslash := false
	for !lexer.EOF() {
		ch := lexer.PeekByte()
		if ch == ':' && nest == 1 {
			break
		}

		if ch == '\\' {
			seenBackslash = true
			lexer.Skip(1)
			_ = lexer.SkipByte(':') || lexer.SkipByte(opening) || lexer.SkipByte(closing)
			continue
		}

		if ch == '(' || ch == '{' {
			nest++
		} else if ch == ')' || ch == '}' {
			nest--
			if nest == 0 {
				break
			}
		}
		lexer.Skip(1)
	}

	arg := lexer.Since(mark)
	if seenBackslash {
		re := regex.Pattern(condStr(closing == '}', `\\([:}])`, `\\([:)])`))
		arg = replaceAll(arg, re, "$1")
	}
	return arg
}

// varUseModifierSubst parses a :S,from,to, or a :C,from,to, modifier.
func (p *MkLexer) varUseModifierSubst(closing byte) (ok bool, regex bool, from string, to string, options string) {
	lexer := p.lexer
	regex = lexer.SkipByte('C')
	if !regex && !lexer.SkipByte('S') {
		return
	}

	sep := lexer.PeekByte() // bmake allows _any_ separator, even letters.
	if sep == -1 || byte(sep) == closing {
		return
	}

	lexer.Skip(1)
	separator := byte(sep)

	unescape := func(s string) string {
		return strings.Replace(s, "\\"+string(separator), string(separator), -1)
	}

	isOther := func(b byte) bool {
		return b != separator && b != '$' && b != '\\'
	}

	skipOther := func() {
		for {
			switch {

			case p.VarUse() != nil:
				break

			case lexer.SkipString("$$"):
				break

			case len(lexer.Rest()) >= 2 && lexer.PeekByte() == '\\' && separator != '\\':
				_ = lexer.Skip(2)

			case lexer.SkipBytesFunc(isOther):
				break

			default:
				return
			}
		}
	}

	fromStart := lexer.Mark()
	lexer.SkipByte('^')
	skipOther()
	lexer.SkipByte('$')
	from = unescape(lexer.Since(fromStart))

	if !lexer.SkipByte(separator) {
		return
	}

	toStart := lexer.Mark()
	skipOther()
	to = unescape(lexer.Since(toStart))

	if !lexer.SkipByte(separator) {
		return
	}

	optionsStart := lexer.Mark()
	lexer.SkipBytesFunc(func(b byte) bool { return b == '1' || b == 'g' || b == 'W' })
	options = lexer.Since(optionsStart)

	ok = true
	return
}

// varUseModifierAt parses a variable modifier like ":@v@echo ${v};@",
// which expands the variable value in a loop.
func (p *MkLexer) varUseModifierAt(lexer *textproc.Lexer, varname string) bool {
	lexer.Skip(1 /* the initial @ */)

	loopVar := lexer.NextBytesSet(AlnumDot)
	if loopVar == "" || !lexer.SkipByte('@') {
		return false
	}

	re := regcomp(`^([^$@\\]|\\.)+`)
	for p.VarUse() != nil || lexer.SkipString("$$") || lexer.SkipRegexp(re) {
	}

	if !lexer.SkipByte('@') {
		p.Warnf("Modifier ${%s:@%s@...@} is missing the final \"@\".", varname, loopVar)
	}

	return true
}

func (p *MkLexer) varUseAlnum() *MkVarUse {
	lexer := p.lexer

	apparentVarname := textproc.NewLexer(lexer.Rest()[1:]).NextBytesSet(textproc.AlnumU)
	if apparentVarname == "" {
		return nil
	}

	lexer.Skip(2)

	if len(apparentVarname) > 1 {
		p.Errorf("$%[1]s is ambiguous. Use ${%[1]s} if you mean a Make variable or $$%[1]s if you mean a shell variable.",
			apparentVarname)
		p.Explain(
			"Only the first letter after the dollar is the variable name.",
			"Everything following it is normal text, even if it looks like a variable name to human readers.")
	} else {
		p.Warnf("$%[1]s is ambiguous. Use ${%[1]s} if you mean a Make variable or $$%[1]s if you mean a shell variable.", apparentVarname)
		p.Explain(
			"In its current form, this variable is parsed as a Make variable.",
			"For human readers though, $x looks more like a shell variable than a Make variable,",
			"since Make variables are usually written using braces (BSD-style) or parentheses (GNU-style).")
	}

	return NewMkVarUse(apparentVarname[:1])
}

func (p *MkLexer) EOF() bool {
	return p.lexer.EOF()
}

func (p *MkLexer) Rest() string {
	return p.lexer.Rest()
}

func (p *MkLexer) Errorf(format string, args ...interface{}) {
	if p.HasDiag() {
		p.diag.Errorf(format, args...)
	}
}

func (p *MkLexer) Warnf(format string, args ...interface{}) {
	if p.HasDiag() {
		p.diag.Warnf(format, args...)
	}
}

func (p *MkLexer) Notef(format string, args ...interface{}) {
	if p.HasDiag() {
		p.diag.Notef(format, args...)
	}
}

func (p *MkLexer) Explain(explanation ...string) {
	if p.HasDiag() {
		p.diag.Explain(explanation...)
	}
}

// Autofix must only be called if HasDiag returns true.
func (p *MkLexer) Autofix() *Autofix {
	return p.diag.Autofix()
}

func (p *MkLexer) HasDiag() bool { return p.diag != nil }
