package pkglint

import "strings"

// MkToken represents a contiguous string from a Makefile.
// It is either a literal string or a variable use.
//
// Example: /usr/share/${PKGNAME}/data consists of 3 tokens:
//  1. MkToken{Text: "/usr/share/"}
//  2. MkToken{Text: "${PKGNAME}", Varuse: &MkVarUse{varname: "PKGNAME"}}
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

func (vu *MkVarUse) String() string { return sprintf("${%s%s}", vu.varname, vu.Mod()) }

type MkVarUseModifier struct {
	Text string
}

func (m MkVarUseModifier) IsQ() bool { return m.Text == "Q" }

func (m MkVarUseModifier) IsSuffixSubst() bool {
	// XXX: There are other cases
	return hasPrefix(m.Text, "=")
}

func (m MkVarUseModifier) MatchSubst() (ok bool, regex bool, from string, to string, options string) {
	p := NewMkParser(nil, m.Text, false)
	return p.varUseModifierSubst('}')
}

// Subst evaluates an S/from/to/ modifier.
//
// Example:
//  MkVarUseModifier{"S,name,file,g"}.Subst("distname-1.0") => "distfile-1.0"
func (m MkVarUseModifier) Subst(str string) (string, bool) {
	// XXX: The call to MatchSubst is usually redundant because MatchSubst
	// is typically called directly before calling Subst.
	ok, regex, from, to, options := m.MatchSubst()
	if !ok {
		return "", false
	}

	leftAnchor := hasPrefix(from, "^")
	if leftAnchor {
		from = from[1:]
	}

	rightAnchor := hasSuffix(from, "$")
	if rightAnchor {
		from = from[:len(from)-1]
	}

	if regex && matches(from, `^[\w-]+$`) && matches(to, `^[^&$\\]*$`) {
		// The "from" pattern is so simple that it doesn't matter whether
		// the modifier is :S or :C, therefore treat it like the simpler :S.
		regex = false
	}

	if regex {
		// TODO: Maybe implement regular expression substitutions later.
		return "", false
	}

	result := mkopSubst(str, leftAnchor, from, rightAnchor, to, options)
	if trace.Tracing && result != str {
		trace.Stepf("Subst: %q %q => %q", str, m.Text, result)
	}
	return result, true
}

// MatchMatch tries to match the modifier to a :M or a :N pattern matching.
// Examples:
//  :Mpattern   => true, true, "pattern"
//  :Npattern   => true, false, "pattern"
//  :X          => false
func (m MkVarUseModifier) MatchMatch() (ok bool, positive bool, pattern string) {
	if hasPrefix(m.Text, "M") || hasPrefix(m.Text, "N") {
		return true, m.Text[0] == 'M', m.Text[1:]
	}
	return false, false, ""
}

func (m MkVarUseModifier) IsToLower() bool { return m.Text == "tl" }

// ChangesWords returns true if applying this modifier to a list variable
// may change the number of words in the list, or their boundaries.
func (m MkVarUseModifier) ChangesWords() bool {
	text := m.Text

	// See MkParser.VarUseModifiers for the meaning of these modifiers.
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
		mod.WriteString(modifier.Text)
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
	return mod.Text == "L" || hasPrefix(mod.Text, "?")
}

func (vu *MkVarUse) IsQ() bool {
	mlen := len(vu.modifiers)
	return mlen > 0 && vu.modifiers[mlen-1].IsQ()
}
