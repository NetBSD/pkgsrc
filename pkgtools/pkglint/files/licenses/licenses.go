package licenses

import (
	"netbsd.org/pkglint/textproc"
	"strings"
)

// Condition describes the syntax of a complex license condition.
// It has either Name or Paren or Children set.
// In the Children case, either And or Or specify the operators used.
// Only malformed license conditions can have both And and Or set.
type Condition struct {
	Name     string       `json:",omitempty"` // A license name, such as gnu-gpl-v2
	Paren    *Condition   `json:",omitempty"` // A parenthesized expression
	And      bool         `json:",omitempty"` // license1 AND license2
	Or       bool         `json:",omitempty"` // license1 OR license2
	Children []*Condition `json:",omitempty"` // The operands of And and Or
}

func Parse(licenses string) *Condition {
	lexer := &licenseLexer{lexer: textproc.NewLexer(licenses)}
	result := liyyNewParser().Parse(lexer)
	if result != 0 || !lexer.lexer.EOF() {
		return nil
	}

	cond := lexer.result
	if !cond.And && !cond.Or && cond.Name == "" && len(cond.Children) == 1 {
		cond = cond.Children[0]
	}
	return cond
}

func (cond *Condition) String() string {
	if cond.Name != "" {
		return cond.Name
	}
	if cond.Paren != nil {
		return "(" + cond.Paren.String() + ")"
	}
	var s strings.Builder
	separator := [...]string{"", " AND ", " OR ", " MIXED "}[b2i(cond.And)+2*b2i(cond.Or)]
	for i, child := range cond.Children {
		if i != 0 {
			s.WriteString(separator)
		}
		s.WriteString(child.String())
	}
	return s.String()
}

func (cond *Condition) Walk(callback func(*Condition)) {
	if cond.Paren != nil {
		cond.Paren.Walk(callback)
	}
	for _, child := range cond.Children {
		child.Walk(callback)
	}
	callback(cond)
}

//go:generate goyacc -p liyy -o licensesyacc.go -v licensesyacc.log licenses.y

type licenseLexer struct {
	lexer  *textproc.Lexer
	result *Condition
	error  string
}

var licenseNameChars = textproc.NewByteSet("A-Za-z0-9---.")

func (lexer *licenseLexer) Lex(llval *liyySymType) int {
	repl := lexer.lexer
	repl.NextHspace()
	switch {
	case repl.EOF():
		return 0
	case repl.NextByte('('):
		return ltOPEN
	case repl.NextByte(')'):
		return ltCLOSE
	}

	word := repl.NextBytesSet(licenseNameChars)
	switch word {
	case "AND":
		return ltAND
	case "OR":
		return ltOR
	case "":
		return -1
	default:
		llval.Node = &Condition{Name: word}
		return ltNAME
	}
}

func (lexer *licenseLexer) Error(s string) {
	lexer.error = s
}

func b2i(x bool) int {
	if x {
		return 1
	}
	return 0
}
