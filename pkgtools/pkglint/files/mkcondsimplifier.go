package pkglint

import (
	"netbsd.org/pkglint/textproc"
	"strings"
)

// MkCondSimplifier replaces unnecessarily complex conditions with simpler yet
// equivalent conditions.
type MkCondSimplifier struct {
	MkLines *MkLines
	MkLine  *MkLine
}

// SimplifyVarUse replaces an unnecessarily complex condition with
// a simpler condition that's still equivalent.
//
// * fromEmpty is true for the form empty(VAR...), and false for ${VAR...}.
//
// * neg is true for the form !empty(VAR...), and false for empty(VAR...).
func (s *MkCondSimplifier) SimplifyVarUse(varuse *MkVarUse, fromEmpty bool, neg bool) {
	if s.simplifyYesNo(varuse, fromEmpty, neg) {
		return
	}
	s.simplifyMatch(varuse, fromEmpty, neg)
	s.simplifyWord(varuse, fromEmpty, neg)
}

// simplifyWord simplifies a condition like '${VAR:Mword}' in the common case
// where VAR is a single-word variable. This case can be written without any
// list operators, as '${VAR} == word'.
func (s *MkCondSimplifier) simplifyWord(varuse *MkVarUse, fromEmpty bool, neg bool) {
	varname := varuse.varname
	modifiers := varuse.modifiers

	n := len(modifiers)
	if n == 0 {
		return
	}
	modsExceptLast := NewMkVarUse("", modifiers[:n-1]...).Mod()
	vartype := G.Pkgsrc.VariableType(s.MkLines, varname)
	if vartype == nil || vartype.IsList() {
		return
	}

	// replace constructs the state before and after the autofix.
	// The before state is constructed to ensure that only very simple
	// patterns get replaced automatically.
	//
	// Before putting any cases involving special characters into
	// production, there need to be more tests for the edge cases.
	replace := func(positive bool, pattern string) (bool, string, string) {
		defined := s.isDefined(varname, vartype)
		if !defined && !positive {
			// TODO: This is a double negation, maybe even triple.
			//  There is an :N pattern, and the variable may be undefined.
			//  If it is indeed undefined, should the whole condition
			//  evaluate to true or false?
			//  The cases to be distinguished are: undefined, empty, filled.

			// For now, be conservative and don't suggest anything wrong.
			return false, "", ""
		}
		uMod := condStr(!defined && !varuse.HasModifier("U"), ":U", "")

		op := condStr(neg == positive, "==", "!=")

		from := sprintf("%s%s%s%s%s%s%s",
			condStr(neg != fromEmpty, "", "!"),
			condStr(fromEmpty, "empty(", "${"),
			varname,
			modsExceptLast,
			condStr(positive, ":M", ":N"),
			pattern,
			condStr(fromEmpty, ")", "}"))

		needsQuotes := textproc.NewLexer(pattern).NextBytesSet(mkCondStringLiteralUnquoted) != pattern ||
			pattern == "" ||
			matches(pattern, `^\d+\.?\d*$`)
		quote := condStr(needsQuotes, "\"", "")

		to := sprintf(
			"${%s%s%s} %s %s%s%s",
			varname, uMod, modsExceptLast, op, quote, pattern, quote)

		return true, from, to
	}

	modifier := modifiers[n-1]
	ok, positive, pattern, exact := modifier.MatchMatch()
	if !ok || !positive && n != 1 {
		return
	}
	if !exact {
		return
	}
	if textproc.NewLexer(pattern).NextBytesSet(mkCondModifierPatternLiteral) != pattern {
		return
	}

	ok, from, to := replace(positive, pattern)
	if !ok {
		return
	}

	fix := s.MkLine.Autofix()
	fix.Notef("%s can be compared using the simpler \"%s\" "+
		"instead of matching against %q.",
		varname, to, ":"+modifier.String()) // TODO: Quoted
	fix.Explain(
		"This variable has a single value, not a list of values.",
		"Therefore it feels strange to apply list operators like :M and :N onto it.",
		"A more direct approach is to use the == and != operators.",
		"",
		"An entirely different case is when the pattern contains",
		"wildcards like *, ?, [].",
		"In such a case, using the :M or :N modifiers is useful and preferred.")
	fix.Replace(from, to)
	fix.Apply()
}

// simplifyYesNo replaces conditions of the form '${VAR:M[yY][eE][sS]}' with
// the equivalent ${VAR:tl} == yes.
func (s *MkCondSimplifier) simplifyYesNo(varuse *MkVarUse, fromEmpty bool, neg bool) (done bool) {

	// TODO: Merge the common code from simplifyWord and simplifyYesNo.
	//  Even better would be to manipulate the conditions in an AST
	//  instead of working directly with strings, but as of November 2022,
	//  that is not implemented yet.
	//  .
	//  Another useful feature would be to chain multiple autofixes
	//  together, but to do that, pkglint needs to be able to convert an
	//  AST back into the source code form.

	toLower := func(p string) string {
		var sb strings.Builder
		upper := textproc.Upper
		lower := textproc.Lower
		for ; len(p) >= 4 && p[0] == '[' && p[3] == ']'; p = p[4:] {
			if upper.Contains(p[1]) && p[2] == p[1]-'A'+'a' {
				sb.WriteByte(p[2])
			} else if lower.Contains(p[1]) && p[2] == p[1]-'a'+'A' {
				sb.WriteByte(p[1])
			} else {
				return ""
			}
		}
		if p != "" {
			return ""
		}
		return sb.String()
	}

	varname := varuse.varname
	modifiers := varuse.modifiers

	n := len(modifiers)
	if n == 0 {
		return
	}
	modsExceptLast := NewMkVarUse("", modifiers[:n-1]...).Mod()
	vartype := G.Pkgsrc.VariableType(s.MkLines, varname)
	if vartype == nil || vartype.IsList() {
		return
	}

	// replace constructs the state before and after the autofix.
	replace := func(positive bool, pattern, lower string) (bool, string, string) {
		defined := s.isDefined(varname, vartype)
		if !defined && !positive {
			// Too many negations; maybe handle this case later.
			return false, "", ""
		}
		uMod := condStr(!defined && !varuse.HasModifier("U"), ":U", "")

		op := condStr(neg == positive, "==", "!=")

		from := sprintf("%s%s%s%s%s%s%s",
			condStr(neg != fromEmpty, "", "!"),
			condStr(fromEmpty, "empty(", "${"),
			varname,
			modsExceptLast,
			condStr(positive, ":M", ":N"),
			pattern,
			condStr(fromEmpty, ")", "}"))

		to := sprintf(
			"${%s%s%s:tl} %s %s",
			varname, uMod, modsExceptLast, op, lower)

		return true, from, to
	}

	modifier := modifiers[n-1]
	ok, positive, pattern, exact := modifier.MatchMatch()
	if !ok || !positive && n != 1 || exact {
		return
	}
	lower := toLower(pattern)
	if lower == "" {
		return
	}

	ok, from, to := replace(positive, pattern, lower)
	if !ok {
		return
	}

	fix := s.MkLine.Autofix()
	fix.Notef("\"%s\" can be simplified to \"%s\".", from, to)
	fix.Replace(from, to)
	fix.Apply()
	return true
}

// simplifyMatch replaces:
//
//	!empty(VAR:M*.c) with ${VAR:M*.c}
//	empty(VAR:M*.c) with !${VAR:M*.c}
//
// * fromEmpty is true for the form empty(VAR...), and false for ${VAR...}.
//
// * neg is true for the form !empty(VAR...), and false for empty(VAR...).
func (s *MkCondSimplifier) simplifyMatch(varuse *MkVarUse, fromEmpty bool, neg bool) {
	varname := varuse.varname
	modifiers := varuse.modifiers

	n := len(modifiers)
	if n == 0 {
		return
	}
	modsExceptLast := NewMkVarUse("", modifiers[:n-1]...).Mod()
	vartype := G.Pkgsrc.VariableType(s.MkLines, varname)

	modifier := modifiers[n-1]
	ok, positive, pattern, exact := modifier.MatchMatch()
	if !ok || !positive && n != 1 {
		return
	}

	if !fromEmpty {
		return // Already using the simple form.
	}

	// Only simplify the form ':M' for now, but not ':N'.
	// The form ':M' is much more popular than ':N'.
	if !positive {
		return
	}

	// For now, only suggest the replacement if the pattern
	// actually contains wildcards. This mainly affects
	// PKG_OPTIONS in the second part of options.mk files.
	// There are many of these, and the pkgsrc developers got
	// used to using '!empty' for them.
	if exact {
		return
	}

	// TODO: Even if the variable type is not known,
	//  the RedundantScope may know that the variable is always
	//  defined at this point, so that the variable expression
	//  does not need the modifier ':U'.
	//  Example: doc/guide/Makefile.common, _GUIDE_OUTPUTS.
	if vartype == nil {
		return
	}

	// For now, only handle cases where the variable is guaranteed to be
	// defined, to avoid having to place an additional ':U' modifier in the
	// expression.
	if !s.isDefined(varname, vartype) {
		return
	}

	// For now, restrict replacements to very simple patterns with only few
	// special characters.
	//
	// Before generalizing this to arbitrary strings, there has to be
	// a proper code generator for these conditions that handles all
	// possible escaping.
	//
	// The same reasoning applies to the variable name, even though the
	// variable name typically only uses a restricted character set.
	if !matches(varuse.Mod(), `^[*.:\w\[\]]+$`) {
		return
	}

	fixedPart := varname + modsExceptLast + ":M" + pattern
	from := condStr(neg, "!", "") + "empty(" + fixedPart + ")"
	to := condStr(neg, "", "!") + "${" + fixedPart + "}"

	fix := s.MkLine.Autofix()
	fix.Notef("%q can be simplified to %q.", from, to)
	fix.Explain(
		"This variable is guaranteed to be defined at this point.",
		"Therefore it may occur on the left-hand side of a comparison",
		"and doesn't have to be guarded by the function 'empty'.")
	fix.Replace(from, to)
	fix.Apply()
}

// isDefined determines whether the variable is guaranteed to be defined at
// this point of reading the makefile. If it is defined, conditions do not
// need the ':U' modifier.
func (s *MkCondSimplifier) isDefined(varname string, vartype *Vartype) bool {
	if vartype.IsAlwaysInScope() && vartype.IsDefinedIfInScope() {
		return true
	}

	// For run time expressions, such as ${${VAR} == value:?yes:no},
	// the scope would need to be changed to ck.MkLines.allVars.
	if s.MkLines.checkAllData.vars.IsDefined(varname) {
		return true
	}

	return s.MkLines.Tools.SeenPrefs &&
		vartype.Union().Contains(aclpUseLoadtime) &&
		vartype.IsDefinedIfInScope()
}
