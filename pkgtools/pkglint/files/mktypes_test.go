package pkglint

import (
	"gopkg.in/check.v1"
	"strings"
)

type MkTokenBuilder struct{}

func NewMkTokenBuilder() MkTokenBuilder { return MkTokenBuilder{} }

func (b MkTokenBuilder) VaruseToken(varname string, modifiers ...MkVarUseModifier) *MkToken {
	var text strings.Builder
	text.WriteString("${")
	text.WriteString(varname)
	for _, modifier := range modifiers {
		text.WriteString(":")
		text.WriteString(modifier.String()) // TODO: Quoted
	}
	text.WriteString("}")
	return &MkToken{Text: text.String(), Varuse: b.VarUse(varname, modifiers...)}
}

func (b MkTokenBuilder) VaruseTextToken(text, varname string, modifiers ...MkVarUseModifier) *MkToken {
	return &MkToken{Text: text, Varuse: b.VarUse(varname, modifiers...)}
}

func (MkTokenBuilder) TextToken(text string) *MkToken {
	return &MkToken{text, nil}
}

func (MkTokenBuilder) Tokens(tokens ...*MkToken) []*MkToken { return tokens }

func (MkTokenBuilder) VarUse(varname string, modifiers ...MkVarUseModifier) *MkVarUse {
	return NewMkVarUse(varname, modifiers...)
}

func (s *Suite) Test_NewMkVarUse(c *check.C) {
	t := s.Init(c)

	use := NewMkVarUse("VARNAME", "Q")

	t.CheckEquals(use.String(), "${VARNAME:Q}")
	t.CheckEquals(use.varname, "VARNAME")
	t.CheckDeepEquals(use.modifiers, []MkVarUseModifier{"Q"})
}

func (s *Suite) Test_MkVarUse_String(c *check.C) {
	t := s.Init(c)

	use := NewMkVarUse("VARNAME", "S,:,colon,", "Q")

	t.CheckEquals(use.String(), "${VARNAME:S,:,colon,:Q}")
}

func (s *Suite) Test_MkVarUseModifier_String(c *check.C) {
	t := s.Init(c)

	test := func(mod MkVarUseModifier, str string) {
		t.CheckEquals(mod.String(), str)
	}

	test("Q", "Q")
	test("S/from/to/1g", "S/from/to/1g")
	test(":", ":")
}

func (s *Suite) Test_MkVarUseModifier_Quoted(c *check.C) {
	t := s.Init(c)

	test := func(mod MkVarUseModifier, quoted string) {
		t.CheckEquals(mod.Quoted(), quoted)
	}

	test("Q", "Q")
	test("S/from/to/1g", "S/from/to/1g")
	test(":", "\\:")
}

func (s *Suite) Test_MkVarUseModifier_HasPrefix(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(MkVarUseModifier("Q").HasPrefix("Q"), true)
	t.CheckEquals(MkVarUseModifier("S/from/to/1g").HasPrefix("Q"), false)
}

func (s *Suite) Test_MkVarUseModifier_IsQ(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(MkVarUseModifier("Q").IsQ(), true)
	t.CheckEquals(MkVarUseModifier("S/from/to/1g").IsQ(), false)
}

func (s *Suite) Test_MkVarUseModifier_IsSuffixSubst(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(MkVarUseModifier("=suffix").IsSuffixSubst(), true)
	t.CheckEquals(MkVarUseModifier("S,=,eq,").IsSuffixSubst(), false)
}

func (s *Suite) Test_MkVarUseModifier_MatchSubst(c *check.C) {
	t := s.Init(c)

	mod := MkVarUseModifier("S/from/to/1g")

	ok, regex, from, to, options := mod.MatchSubst()

	t.CheckEquals(ok, true)
	t.CheckEquals(regex, false)
	t.CheckEquals(from, "from")
	t.CheckEquals(to, "to")
	t.CheckEquals(options, "1g")
}

func (s *Suite) Test_MkVarUseModifier_MatchSubst__backslash(c *check.C) {
	t := s.Init(c)

	mod := MkVarUseModifier("S/\\//\\:/")

	ok, regex, from, to, options := mod.MatchSubst()

	t.CheckEquals(ok, true)
	t.CheckEquals(regex, false)
	t.CheckEquals(from, "/")
	t.CheckEquals(to, "\\:")
	t.CheckEquals(options, "")
}

// Some pkgsrc users really explore the darkest corners of bmake by using
// the backslash as the separator in the :S modifier. Sure, it works, it
// just looks totally unexpected to the average pkgsrc reader.
//
// Using the backslash as separator means that it cannot be used for anything
// else, not even for escaping other characters.
func (s *Suite) Test_MkVarUseModifier_MatchSubst__backslash_as_separator(c *check.C) {
	t := s.Init(c)

	mod := MkVarUseModifier("S\\.post1\\\\1")

	ok, regex, from, to, options := mod.MatchSubst()

	t.CheckEquals(ok, true)
	t.CheckEquals(regex, false)
	t.CheckEquals(from, ".post1")
	t.CheckEquals(to, "")
	t.CheckEquals(options, "1")
}

func (s *Suite) Test_MkVarUseModifier_Subst(c *check.C) {
	t := s.Init(c)

	test := func(mod, str string, ok bool, result string) {
		m := MkVarUseModifier(mod)

		actualOk, actualResult := m.Subst(str)

		t.CheckDeepEquals(
			[]interface{}{actualOk, actualResult},
			[]interface{}{ok, result})
	}

	test("???", "anything", false, "")

	test("S,from,to,", "from", true, "to")

	test("C,from,to,", "from", true, "to")

	test("C,syntax error", "anything", false, "")

	// The substitution modifier does not match, therefore
	// the value is returned unmodified, but successful.
	test("C,no_match,replacement,", "value", true, "value")

	// As of December 2019, pkglint doesn't know how to handle
	// complicated :C modifiers.
	test("C,.*,,", "anything", false, "")

	// When given a modifier that is not actually a :S or :C, Subst
	// doesn't do anything.
	test("Mpattern", "anything", false, "")

	test("S,from,to,", "from a to b", true, "to a to b")

	// Since the replacement text is not a simple string, the :C modifier
	// cannot be treated like the :S modifier. The variable could contain
	// one of the special characters that would need to be escaped in the
	// replacement text.
	test("C,from,${VAR},", "from a to b", false, "")

	// As of December 2019, nothing is substituted. If pkglint should ever
	// handle variables in the modifier, this test would need to provide a
	// context in which to resolve the variables. If that happens, the
	// .TARGET variable needs to be set to "target".
	test("S/$@/replaced/", "The target", true, "The target")
	test("S,${PREFIX},/prefix,", "${PREFIX}/dir", false, "")

	// Just for code coverage.
	t.DisableTracing()
	test("S,long,long long,g", "A long story", true, "A long long story")
	t.EnableTracing()

	// And now again with full tracing, to investigate cases where
	// pkglint produces results that are not easily understandable.
	t.EnableTracingToLog()
	test("S,long,long long,g", "A long story", true, "A long long story")
	t.EnableTracing()
	t.CheckOutputLines(
		"TRACE:   Subst: \"A long story\" " +
			"\"S,long,long long,g\" => \"A long long story\"")
}

func (s *Suite) Test_MkVarUseModifier_EvalSubst(c *check.C) {
	t := s.Init(c)

	test := func(s string, left bool, from string, right bool, to string, flags string, ok bool, result string) {
		mod := MkVarUseModifier("")

		actualOk, actual := mod.EvalSubst(s, left, from, right, to, flags)

		t.CheckEquals(actualOk, ok)
		t.CheckEquals(actual, result)
	}

	// Replace anywhere
	test("pkgname", false, "kgna", false, "ri", "", true, "prime")
	test("pkgname", false, "pkgname", false, "replacement", "", true, "replacement")
	test("aaaaaaa", false, "a", false, "b", "", true, "baaaaaa")

	// Anchored at the beginning
	test("pkgname", true, "kgna", false, "ri", "", true, "pkgname")
	test("pkgname", true, "pkgname", false, "replacement", "", true, "replacement")

	// Anchored at the end
	test("pkgname", false, "kgna", true, "ri", "", true, "pkgname")
	test("pkgname", false, "pkgname", true, "replacement", "", true, "replacement")

	// Anchored at both sides
	test("pkgname", true, "kgna", true, "ri", "", true, "pkgname")
	test("pkgname", false, "pkgname", false, "replacement", "", true, "replacement")

	// Replace all
	test("aaaaa", false, "a", false, "b", "g", true, "bbbbb")
	test("aaaaa", true, "a", false, "b", "g", true, "baaaa")
	test("aaaaa", false, "a", true, "b", "g", true, "aaaab")
	test("aaaaa", true, "a", true, "b", "g", true, "aaaaa")

	// Replacements using variables are trickier to get right.
	test("anything", false, "${VAR}", false, "replacement", "", false, "")
	test("anything", false, "pattern", false, "${VAR}", "", false, "")
	test("echo $$$$", false, "$$", false, "dollar", "", true, "echo dollar$$")
	test("echo $$$$", false, "$$", false, "dollar", "g", true, "echo dollardollar")
}

func (s *Suite) Test_MkVarUseModifier_MatchMatch(c *check.C) {
	t := s.Init(c)

	testFail := func(modifier MkVarUseModifier) {
		mod := modifier
		ok, _, _, _ := mod.MatchMatch()
		t.CheckEquals(ok, false)
	}
	test := func(mod MkVarUseModifier, positive bool, pattern string, exact bool) {
		actualOk, actualPositive, actualPattern, actualExact := mod.MatchMatch()
		t.CheckDeepEquals(
			[]interface{}{actualOk, actualPositive, actualPattern, actualExact},
			[]interface{}{true, positive, pattern, exact})
	}

	testFail("")
	testFail("X")

	test("Mpattern", true, "pattern", true)
	test("M*", true, "*", false)
	test("M${VAR}", true, "${VAR}", false)
	test("Npattern", false, "pattern", true)
}

func (s *Suite) Test_MkVarUseModifier_IsToLower(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(MkVarUseModifier("tl").IsToLower(), true)
	t.CheckEquals(MkVarUseModifier("tu").IsToLower(), false)
}

func (s *Suite) Test_MkVarUseModifier_ChangesList(c *check.C) {
	t := s.Init(c)

	test := func(mod MkVarUseModifier, changes bool) {
		t.CheckEquals(mod.ChangesList(), changes)
	}

	test("C,from,to,", true)
	test("E", false)
	test("H", false)

	// The :M and :N modifiers may reduce the number of words in a
	// variable, but they don't change the interpretation from a list
	// to a non-list.
	test("Mpattern", false)
	test("Npattern", false)

	test("O", false)
	test("Q", true)
	test("R", false)
	test("S,from,to,", true)
	test("T", false)
	test("invalid", true)
	test("sh", true)
	test("tl", false)
	test("tW", true)
	test("tu", false)
	test("tw", true)
}

// Ensures that ChangesList cannot be called with an empty string as modifier.
// Therefore it is safe to index text[0] without a preceding length check.
func (s *Suite) Test_MkVarUseModifier_ChangesList__empty(c *check.C) {
	t := s.Init(c)

	mkline := t.NewMkLine("filename.mk", 123, "\t${VAR:}")

	n := 0
	mkline.ForEachUsed(func(varUse *MkVarUse, time VucTime) {
		n += 100
		for _, mod := range varUse.modifiers {
			mod.ChangesList()
			n++
		}
	})

	t.CheckOutputEmpty()
	t.CheckEquals(n, 100)
}

func (s *Suite) Test_MkVarUse_Mod(c *check.C) {
	t := s.Init(c)

	test := func(varUseText string, mod string) {
		line := t.NewLine("filename.mk", 123, "")
		varUse := NewMkLexer(varUseText, line).VarUse()
		t.CheckOutputEmpty()
		t.CheckEquals(varUse.Mod(), mod)
	}

	test("${varname:Q}", ":Q")
	test("${PATH:ts::Q}", ":ts::Q")
}

func (s *Suite) Test_MkVarUse_IsExpression(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(ToVarUse("${VAR}").IsExpression(), false)
	t.CheckEquals(ToVarUse("${expr:L}").IsExpression(), true)
	t.CheckEquals(ToVarUse("${expr:?then:else}").IsExpression(), true)
}

func (s *Suite) Test_MkVarUse_IsQ(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(ToVarUse("${VAR}").IsQ(), false)
	t.CheckEquals(ToVarUse("${VAR:Q}").IsQ(), true)
	t.CheckEquals(ToVarUse("${VAR:tl}").IsQ(), false)
	t.CheckEquals(ToVarUse("${VAR:tl:Q}").IsQ(), true)
	t.CheckEquals(ToVarUse("${VAR:Q:tl}").IsQ(), false)
}

func (s *Suite) Test_MkVarUse_HasModifier(c *check.C) {
	t := s.Init(c)

	t.CheckEquals(ToVarUse("${VAR}").HasModifier("Q"), false)
	t.CheckEquals(ToVarUse("${VAR:Q}").HasModifier("Q"), true)
	t.CheckEquals(ToVarUse("${VAR:tl}").HasModifier("Q"), false)
	t.CheckEquals(ToVarUse("${VAR:tl}").HasModifier("t"), true)
	t.CheckEquals(ToVarUse("${VAR:tl:Q}").HasModifier("Q"), true)
	t.CheckEquals(ToVarUse("${VAR:Q:tl}").HasModifier("Q"), true)
}
