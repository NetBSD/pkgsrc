package pkglint

import (
	"gopkg.in/check.v1"
	"strings"
)

type MkTokenBuilder struct{}

func NewMkTokenBuilder() MkTokenBuilder { return MkTokenBuilder{} }

func (b MkTokenBuilder) VaruseToken(varname string, modifiers ...string) *MkToken {
	var text strings.Builder
	text.WriteString("${")
	text.WriteString(varname)
	for _, modifier := range modifiers {
		text.WriteString(":")
		text.WriteString(modifier)
	}
	text.WriteString("}")
	return &MkToken{Text: text.String(), Varuse: b.VarUse(varname, modifiers...)}
}

func (b MkTokenBuilder) VaruseTextToken(text, varname string, modifiers ...string) *MkToken {
	return &MkToken{Text: text, Varuse: b.VarUse(varname, modifiers...)}
}

func (MkTokenBuilder) TextToken(text string) *MkToken {
	return &MkToken{text, nil}
}

func (MkTokenBuilder) Tokens(tokens ...*MkToken) []*MkToken { return tokens }

func (MkTokenBuilder) VarUse(varname string, modifiers ...string) *MkVarUse {
	var mods []MkVarUseModifier
	for _, modifier := range modifiers {
		mods = append(mods, MkVarUseModifier{modifier})
	}
	return NewMkVarUse(varname, mods...)
}

func (s *Suite) Test_MkVarUseModifier_MatchSubst(c *check.C) {
	t := s.Init(c)

	mod := MkVarUseModifier{"S/from/to/1g"}

	ok, regex, from, to, options := mod.MatchSubst()

	t.CheckEquals(ok, true)
	t.CheckEquals(regex, false)
	t.CheckEquals(from, "from")
	t.CheckEquals(to, "to")
	t.CheckEquals(options, "1g")
}

func (s *Suite) Test_MkVarUseModifier_MatchSubst__backslash(c *check.C) {
	t := s.Init(c)

	mod := MkVarUseModifier{"S/\\//\\:/"}

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

	mod := MkVarUseModifier{"S\\.post1\\\\1"}

	ok, regex, from, to, options := mod.MatchSubst()

	t.CheckEquals(ok, true)
	t.CheckEquals(regex, false)
	t.CheckEquals(from, ".post1")
	t.CheckEquals(to, "")
	t.CheckEquals(options, "1")
}

func (s *Suite) Test_MkVarUseModifier_Subst(c *check.C) {
	t := s.Init(c)

	test := func(mod, str, result string, ok bool) {
		m := MkVarUseModifier{mod}

		actualResult, actualOk := m.Subst(str)

		t.CheckDeepEquals(
			[]interface{}{actualResult, actualOk},
			[]interface{}{result, ok})
	}

	test("???", "anything", "", false)

	test("S,from,to,", "from", "to", true)

	test("C,from,to,", "from", "to", true)

	test("C,syntax error", "anything", "", false)

	// The substitution modifier does not match, therefore
	// the value is returned unmodified, but successful.
	test("C,no_match,replacement,", "value", "value", true)

	// As of December 2019, pkglint doesn't know how to handle
	// complicated :C modifiers.
	test("C,.*,,", "anything", "", false)

	// When given a modifier that is not actually a :S or :C, Subst
	// doesn't do anything.
	test("Mpattern", "anything", "", false)

	test("S,from,to,", "from a to b", "to a to b", true)

	// Since the replacement text is not a simple string, the :C modifier
	// cannot be treated like the :S modifier. The variable could contain
	// one of the special characters that would need to be escaped in the
	// replacement text.
	test("C,from,${VAR},", "from a to b", "", false)

	// As of December 2019, nothing is substituted. If pkglint should ever
	// handle variables in the modifier, this test would need to provide a
	// context in which to resolve the variables. If that happens, the
	// .TARGET variable needs to be set to "target".
	test("S/$@/replaced/", "The target", "The target", true)
	test("S,${PREFIX},/prefix,", "${PREFIX}/dir", "", false)

	// Just for code coverage.
	t.DisableTracing()
	test("S,long,long long,g", "A long story", "A long long story", true)
	t.EnableTracing()

	// And now again with full tracing, to investigate cases where
	// pkglint produces results that are not easily understandable.
	t.EnableTracingToLog()
	test("S,long,long long,g", "A long story", "A long long story", true)
	t.EnableTracing()
	t.CheckOutputLines(
		"TRACE:   Subst: \"A long story\" " +
			"\"S,long,long long,g\" => \"A long long story\"")
}

func (s *Suite) Test_MkVarUseModifier_EvalSubst(c *check.C) {
	t := s.Init(c)

	test := func(s string, left bool, from string, right bool, to string, flags string, ok bool, result string) {
		mod := MkVarUseModifier{}

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

	testFail := func(modifier string) {
		mod := MkVarUseModifier{modifier}
		ok, _, _, _ := mod.MatchMatch()
		t.CheckEquals(ok, false)
	}
	test := func(modifier string, positive bool, pattern string, exact bool) {
		mod := MkVarUseModifier{modifier}
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

func (s *Suite) Test_MkVarUseModifier_ChangesList(c *check.C) {
	t := s.Init(c)

	test := func(modifier string, changes bool) {
		mod := MkVarUseModifier{modifier}
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
