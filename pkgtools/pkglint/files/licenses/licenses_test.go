package licenses

import (
	"encoding/json"
	"gopkg.in/check.v1"
	"netbsd.org/pkglint/regex"
	"strings"
	"testing"
)

type Suite struct{}

func (s *Suite) Test_Parse(c *check.C) {
	res := regex.NewRegistry()
	checkParse := func(cond string, expected string) {
		c.Check(toJSON(Parse(cond, &res)), check.Equals, expected)
	}
	checkParseDeep := func(cond string, expected *Condition) {
		c.Check(Parse(cond, &res), check.DeepEquals, expected)
	}

	checkParseDeep("gnu-gpl-v2", NewSingleton(NewName("gnu-gpl-v2")))

	checkParse("gnu-gpl-v2", "{Children:[{Name:gnu-gpl-v2}]}")
	checkParse("a AND b", "{And:true,Children:[{Name:a},{Name:b}]}")
	checkParse("a OR b", "{Or:true,Children:[{Name:a},{Name:b}]}")

	checkParse("a OR (b AND c)", "{Or:true,Children:[{Name:a},{Paren:{And:true,Children:[{Name:b},{Name:c}]}}]}")
	checkParse("(a OR b) AND c", "{And:true,Children:[{Paren:{Or:true,Children:[{Name:a},{Name:b}]}},{Name:c}]}")

	checkParse("a AND b AND c AND d", "{And:true,Children:[{Name:a},{Name:b},{Name:c},{Name:d}]}")
	checkParseDeep(
		"a AND b AND c AND d",
		NewAnd(NewName("a"), NewName("b"), NewName("c"), NewName("d")))

	checkParse("a OR b OR c OR d", "{Or:true,Children:[{Name:a},{Name:b},{Name:c},{Name:d}]}")
	checkParseDeep(
		"a OR b OR c OR d",
		NewOr(NewName("a"), NewName("b"), NewName("c"), NewName("d")))

	checkParse("(a OR b) AND (c AND d)", "{And:true,Children:[{Paren:{Or:true,Children:[{Name:a},{Name:b}]}},{Paren:{And:true,Children:[{Name:c},{Name:d}]}}]}")
	checkParseDeep(
		"(a OR b) AND (c AND d)",
		NewAnd(
			NewParen(NewOr(NewName("a"), NewName("b"))),
			NewParen(NewAnd(NewName("c"), NewName("d")))))

	checkParse("a AND b OR c AND d", "{And:true,Or:true,Children:[{Name:a},{Name:b},{Name:c},{Name:d}]}")
	checkParse("((a AND (b AND c)))", "{Children:[{Paren:{Children:[{Paren:{And:true,Children:[{Name:a},{Paren:{And:true,Children:[{Name:b},{Name:c}]}}]}}]}}]}")

	c.Check(Parse("a AND b OR c AND d", &res).String(), check.Equals, "a MIXED b MIXED c MIXED d")

	c.Check(Parse("AND artistic", &res), check.IsNil)

	c.Check(Parse("invalid/character", &res), check.IsNil)
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

func (s *Suite) Test_Walk(c *check.C) {
	res := regex.NewRegistry()

	condition := Parse("(a OR b) AND (c AND d)", &res)

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

func NewName(name string) *Condition {
	return &Condition{Name: name}
}
func NewParen(child *Condition) *Condition {
	return &Condition{Paren: child}
}
func NewSingleton(child *Condition) *Condition {
	return &Condition{Children: []*Condition{child}}
}
func NewAnd(parts ...*Condition) *Condition {
	return &Condition{Children: parts, And: true}
}
func NewOr(parts ...*Condition) *Condition {
	return &Condition{Children: parts, Or: true}
}

func toJSON(cond *Condition) string {
	json, _ := json.Marshal(cond)
	return strings.Replace(string(json), "\"", "", -1)
}

func Test(t *testing.T) {
	check.Suite(new(Suite))
	check.TestingT(t)
}
