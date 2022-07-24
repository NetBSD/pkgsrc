package pkglint

import (
	"netbsd.org/pkglint/regex"
	"regexp"
	"strings"
)

// MkToken represents a contiguous string from a Makefile.
// It is either a literal string or a variable use.
//
// Example: /usr/share/${PKGNAME}/data consists of 3 tokens:
//  1. MkToken{Text: "/usr/share/"}
//  2. MkToken{Text: "${PKGNAME}", Varuse: NewMkVarUse("PKGNAME")}
//  3. MkToken{Text: "/data"}
//
type MkToken struct {
	Text   string    // Used for both literal text and variable uses
	Varuse *MkVarUse // For literal text, it is nil
}

// MkVarUse represents a reference to a Make variable, with optional modifiers.
//
// For nested variable expressions, the variable name can contain references
// to other variables. For example, ${TOOLS.${t}} is a MkVarUse with varname
// "TOOLS.${t}" and no modifiers.
//
// Example: ${PKGNAME}
//
// Example: ${PKGNAME:S/from/to/}
type MkVarUse struct {
	varname   string             // E.g. "PKGNAME", or "${BUILD_DEFS}"
	modifiers []MkVarUseModifier // E.g. "Q", "S/from/to/"
}

func NewMkVarUse(varname string, modifiers ...MkVarUseModifier) *MkVarUse {
	return &MkVarUse{varname, modifiers}
}

func (vu *MkVarUse) String() string { return sprintf("${%s%s}", vu.varname, vu.Mod()) }

// MkVarUseModifier stores the text of the modifier, without the initial colon.
// Examples: "Q", "S,from,to,g"
type MkVarUseModifier string

func (m MkVarUseModifier) String() string {
	return string(m)
}

func (m MkVarUseModifier) Quoted() string {
	return strings.Replace(string(m), ":", "\\:", -1)
}

func (m MkVarUseModifier) HasPrefix(prefix string) bool {
	return hasPrefix(m.String(), prefix)
}

func (m MkVarUseModifier) IsQ() bool { return m == "Q" }

func (m MkVarUseModifier) IsSuffixSubst() bool {
	// XXX: There are other cases
	return m.HasPrefix("=")
}

func (m MkVarUseModifier) MatchSubst() (ok bool, regex bool, from string, to string, options string) {
	p := NewMkLexer(m.String(), nil)
	return p.varUseModifierSubst('}')
}

// Subst evaluates an S/from/to/ modifier.
//
// Example:
//  MkVarUseModifier{"S,name,file,g"}.Subst("distname-1.0") => "distfile-1.0"
func (m MkVarUseModifier) Subst(str string) (bool, string) {
	// XXX: The call to MatchSubst is usually redundant because MatchSubst
	//  is typically called directly before calling Subst.
	//  This comes from a time when there was no boolean return value.
	ok, isRegex, from, to, options := m.MatchSubst()
	if !ok {
		return false, ""
	}

	leftAnchor := hasPrefix(from, "^")
	if leftAnchor {
		from = from[1:]
	}

	rightAnchor := hasSuffix(from, "$")
	if rightAnchor {
		from = from[:len(from)-1]
	}

	if isRegex && matches(from, `^[\w-]+$`) && matches(to, `^[^&$\\]*$`) {
		// The "from" pattern is so simple that it doesn't matter whether
		// the modifier is :S or :C, therefore treat it like the simpler :S.
		isRegex = false
	}

	if isRegex {
		// XXX: Maybe implement regular expression substitutions later.
		return false, ""
	}

	ok, result := m.EvalSubst(str, leftAnchor, from, rightAnchor, to, options)
	if trace.Tracing && ok && result != str {
		trace.Stepf("Subst: %q %q => %q", str, m.String(), result)
	}
	return ok, result
}

// mkopSubst evaluates make(1)'s :S substitution operator.
// It does not resolve any variables.
func (MkVarUseModifier) EvalSubst(s string, left bool, from string, right bool, to string, flags string) (ok bool, result string) {

	if containsVarRefLong(from) || containsVarRefLong(to) {
		return false, ""
	}

	re := regex.Pattern(condStr(left, "^", "") + regexp.QuoteMeta(from) + condStr(right, "$", ""))
	done := false
	gflag := contains(flags, "g")
	return true, replaceAllFunc(s, re, func(match string) string {
		if gflag || !done {
			done = !gflag
			return to
		}
		return match
	})
}

// MatchMatch tries to match the modifier to a :M or a :N pattern matching.
// Examples:
//  modifier    => ok     positive pattern    exact
//  ------------------------------------------------
//  :Mpattern   => true,  true,    "pattern", true
//  :M*         => true,  true,    "*",       false
//  :M${VAR}    => true,  true,    "${VAR}",  false
//  :Npattern   => true,  false,   "pattern", true
//  :X          => false
func (m MkVarUseModifier) MatchMatch() (ok bool, positive bool, pattern string, exact bool) {
	if m.HasPrefix("M") || m.HasPrefix("N") {
		str := m.String()
		// See devel/bmake/files/str.c:^Str_Match
		exact := !strings.ContainsAny(str[1:], "*?[\\$")
		return true, str[0] == 'M', str[1:], exact
	}
	return false, false, "", false
}

func (m MkVarUseModifier) IsToLower() bool { return m == "tl" }

// ChangesList returns true if applying this modifier to a variable
// may change the expression from a list type to a non-list type
// or vice versa.
func (m MkVarUseModifier) ChangesList() bool {
	text := m.String()

	// See MkParser.varUseModifier for the meaning of these modifiers.
	switch text[0] {

	case 'E', 'H', 'M', 'N', 'O', 'R', 'T':
		return false

	case 'C', 'Q', 'S':
		// For the :C and :S modifiers, a more detailed analysis could reveal
		// cases that don't change the structure, such as :S,a,b,g or
		// :C,[0-9A-Za-z_],.,g, but not :C,x,,g.
		return true
	}

	switch text {

	case "tl", "tu":
		return false

	case "sh", "tW", "tw":
		return true
	}

	// If in doubt, be pessimistic. As of March 2019, the only code that
	// actually uses this function doesn't issue a possibly wrong warning
	// in such a case.
	return true
}

func (vu *MkVarUse) Mod() string {
	var mod strings.Builder
	for _, modifier := range vu.modifiers {
		mod.WriteString(":")
		mod.WriteString(modifier.String())
	}
	return mod.String()
}

// IsExpression returns whether the varname is interpreted as an expression
// instead of a variable name (rare, only the modifiers :? and :L do this).
func (vu *MkVarUse) IsExpression() bool {
	if len(vu.modifiers) == 0 {
		return false
	}
	mod := vu.modifiers[0]
	return mod.String() == "L" || mod.HasPrefix("?")
}

func (vu *MkVarUse) IsQ() bool {
	mlen := len(vu.modifiers)
	return mlen > 0 && vu.modifiers[mlen-1].IsQ()
}

func (vu *MkVarUse) HasModifier(prefix string) bool {
	for _, mod := range vu.modifiers {
		if mod.HasPrefix(prefix) {
			return true
		}
	}
	return false
}
