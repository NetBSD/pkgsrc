package licenses

import (
	"encoding/json"
	"gopkg.in/check.v1"
	"netbsd.org/pkglint/intqa"
	"netbsd.org/pkglint/textproc"
	"strings"
	"testing"
)

type Suite struct{}

func (s *Suite) Test_Parse(c *check.C) {
	test := func(cond string, expected string) {
		c.Check(toJSON(Parse(cond)), check.Equals, expected)
	}

	testDeep := func(cond string, expected *Condition) {
		c.Check(Parse(cond), check.DeepEquals, expected)
	}

	testDeep("gnu-gpl-v2", NewName("gnu-gpl-v2"))

	test("gnu-gpl-v2", "{Name:gnu-gpl-v2}")
	test("citrix_ica-license", "{Name:citrix_ica-license}")

	test("a AND b", "{And:true,Children:[{Name:a},{Name:b}]}")
	test("a OR b", "{Or:true,Children:[{Name:a},{Name:b}]}")

	test("a OR (b AND c)", "{Or:true,Children:[{Name:a},{Paren:{And:true,Children:[{Name:b},{Name:c}]}}]}")
	test("(a OR b) AND c", "{And:true,Children:[{Paren:{Or:true,Children:[{Name:a},{Name:b}]}},{Name:c}]}")

	test("a AND b AND c AND d", "{And:true,Children:[{Name:a},{Name:b},{Name:c},{Name:d}]}")
	testDeep(
		"a AND b AND c AND d",
		NewAnd(NewName("a"), NewName("b"), NewName("c"), NewName("d")))

	test("a OR b OR c OR d", "{Or:true,Children:[{Name:a},{Name:b},{Name:c},{Name:d}]}")
	testDeep(
		"a OR b OR c OR d",
		NewOr(NewName("a"), NewName("b"), NewName("c"), NewName("d")))

	test("(a OR b) AND (c AND d)", "{And:true,Children:[{Paren:{Or:true,Children:[{Name:a},{Name:b}]}},{Paren:{And:true,Children:[{Name:c},{Name:d}]}}]}")
	testDeep(
		"(a OR b) AND (c AND d)",
		NewAnd(
			NewParen(NewOr(NewName("a"), NewName("b"))),
			NewParen(NewAnd(NewName("c"), NewName("d")))))

	test("a AND b OR c AND d", "{And:true,Or:true,Children:[{Name:a},{Name:b},{Name:c},{Name:d}]}")
	test("((a AND (b AND c)))", "{Paren:{Children:[{Paren:{And:true,Children:[{Name:a},{Paren:{And:true,Children:[{Name:b},{Name:c}]}}]}}]}}")

	c.Check(Parse("a AND b OR c AND d").String(), check.Equals, "a MIXED b MIXED c MIXED d")

	c.Check(Parse("AND artistic"), check.IsNil)

	c.Check(Parse("invalid/character"), check.IsNil)
}

func (s *Suite) Test_Condition_String(c *check.C) {
	c.Check(
		NewName("a").String(),
		check.Equals,
		"a")

	c.Check(
		NewAnd(NewName("a"), NewName("b")).String(),
		check.Equals,
		"a AND b")

	c.Check(
		NewOr(NewName("a"), NewName("b")).String(),
		check.Equals,
		"a OR b")

	c.Check(
		NewAnd(
			NewParen(NewOr(NewName("a"), NewName("b"))),
			NewParen(NewOr(NewName("c"), NewName("d")))).String(),
		check.Equals,
		"(a OR b) AND (c OR d)")

	mixed := NewAnd(NewName("a"), NewName("b"), NewName("c"))
	mixed.Or = true
	c.Check(mixed.String(), check.Equals, "a MIXED b MIXED c")
}

func (s *Suite) Test_Condition_Walk(c *check.C) {
	condition := Parse("(a OR b) AND (c AND d)")

	var out []string
	condition.Walk(func(condition *Condition) {
		switch {
		case condition.Name != "":
			out = append(out, condition.Name)
		case condition.Paren != nil:
			out = append(out, "()")
		case condition.And && condition.Or:
			out = append(out, "MIXED")
		case condition.And:
			out = append(out, "AND")
		case condition.Or:
			out = append(out, "OR")
		default:
			panic("unexpected")
		}
	})

	c.Check(out, check.DeepEquals, []string{"a", "b", "OR", "()", "c", "d", "AND", "()", "AND"})
}

func (s *Suite) Test_licenseLexer_Lex(c *check.C) {

	test := func(text string, tokenType int) {
		lexer := &licenseLexer{lexer: textproc.NewLexer(text)}
		var token liyySymType
		lex := lexer.Lex(&token)
		c.Check(lex, check.Equals, tokenType)
	}
	testName := func(text string, name string) {
		lexer := &licenseLexer{lexer: textproc.NewLexer(text)}
		var token liyySymType
		lex := lexer.Lex(&token)
		c.Check(lex, check.Equals, ltNAME)
		c.Check(token.Node.Name, check.Equals, name)
	}

	test("", 0)
	test("(", ltOPEN)
	test(")", ltCLOSE)
	test("AND", ltAND)
	test("OR", ltOR)
	test("?", -1)
	test("license-name", ltNAME)
	test("license_name", ltNAME)

	test("AND rest", ltAND)
	test("AND-rest", ltNAME)

	testName("license-name", "license-name")
	testName("license_name", "license_name")
	testName("AND-rest", "AND-rest")
}

func NewName(name string) *Condition {
	return &Condition{Name: name}
}
func NewParen(child *Condition) *Condition {
	return &Condition{Paren: child}
}
func NewAnd(parts ...*Condition) *Condition {
	return &Condition{Children: parts, And: true}
}
func NewOr(parts ...*Condition) *Condition {
	return &Condition{Children: parts, Or: true}
}

func toJSON(cond *Condition) string {
	jsonStr, _ := json.Marshal(cond)
	return strings.Replace(string(jsonStr), "\"", "", -1)
}

func Test(t *testing.T) {
	check.Suite(new(Suite))
	check.TestingT(t)
}

func (s *Suite) Test__qa(c *check.C) {
	ck := intqa.NewQAChecker(c.Errorf)
	ck.Configure("*", "*", "*", -intqa.EMissingTest)
	ck.Check()
}
