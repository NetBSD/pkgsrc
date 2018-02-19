package main

// MkToken represents a contiguous string from a Makefile.
// It is either a literal string or a variable use.
//
// Example (3 tokens): /usr/share/${PKGNAME}/data
type MkToken struct {
	Text   string // Used for both literals and varuses.
	Varuse *MkVarUse
}

// MkVarUse represents a reference to a Make variable, with optional modifiers.
//
// Example: ${PKGNAME}
// Example: ${PKGNAME:S/from/to/}
type MkVarUse struct {
	varname   string
	modifiers []string // E.g. "Q", "S/from/to/"
}

func (vu *MkVarUse) Mod() string {
	mod := ""
	for _, modifier := range vu.modifiers {
		mod += ":" + modifier
	}
	return mod
}

// Whether the varname is interpreted as a variable name (the usual case)
// or as a full expression (rare).
func (vu *MkVarUse) IsExpression() bool {
	if len(vu.modifiers) == 0 {
		return false
	}
	mod := vu.modifiers[0]
	return mod == "L" || hasPrefix(mod, "?")
}

func (vu *MkVarUse) IsQ() bool {
	mlen := len(vu.modifiers)
	return mlen > 0 && vu.modifiers[mlen-1] == "Q"
}
