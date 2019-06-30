package pkglint

func CheckLinesOptionsMk(mklines *MkLines) {
	ck := OptionsLinesChecker{
		mklines,
		make(map[string]*MkLine),
		make(map[string]*MkLine),
		nil}

	ck.Check()
}

// OptionsLinesChecker checks an options.mk file of a pkgsrc package.
//
// See mk/bsd.options.mk for a detailed description.
type OptionsLinesChecker struct {
	mklines *MkLines

	declaredOptions           map[string]*MkLine
	handledOptions            map[string]*MkLine
	optionsInDeclarationOrder []string
}

func (ck *OptionsLinesChecker) Check() {
	mklines := ck.mklines

	mklines.Check()

	mlex := NewMkLinesLexer(mklines)
	mlex.SkipWhile(func(mkline *MkLine) bool { return mkline.IsComment() || mkline.IsEmpty() })

	if !ck.lookingAtPkgOptionsVar(mlex) {
		return
	}
	mlex.Skip()

	upper := true
	for !mlex.EOF() && upper {
		upper = ck.handleUpperLine(mlex.CurrentMkLine())
		mlex.Skip()
	}

	for !mlex.EOF() {
		ck.handleLowerLine(mlex.CurrentMkLine())
		mlex.Skip()
	}

	ck.checkOptionsMismatch()

	mklines.SaveAutofixChanges()
}

func (ck *OptionsLinesChecker) lookingAtPkgOptionsVar(mlex *MkLinesLexer) bool {
	if !mlex.EOF() {
		mkline := mlex.CurrentMkLine()
		if mkline.IsVarassign() && mkline.Varname() == "PKG_OPTIONS_VAR" {
			return true
		}
	}

	line := mlex.CurrentLine()
	line.Warnf("Expected definition of PKG_OPTIONS_VAR.")
	line.Explain(
		"The input variables in an options.mk file should always be",
		"mentioned in the same order: PKG_OPTIONS_VAR,",
		"PKG_SUPPORTED_OPTIONS, PKG_SUGGESTED_OPTIONS.",
		"This way, the options.mk files have the same structure and are easy to understand.")
	return false
}

// checkLineUpper checks a line from the upper part of an options.mk file,
// before bsd.options.mk is included.
func (ck *OptionsLinesChecker) handleUpperLine(mkline *MkLine) bool {
	switch {
	case mkline.IsComment():
		break
	case mkline.IsEmpty():
		break

	case mkline.IsVarassign():
		switch mkline.Varcanon() {
		case "PKG_SUPPORTED_OPTIONS", "PKG_OPTIONS_GROUP.*", "PKG_OPTIONS_SET.*":
			for _, option := range mkline.ValueFields(mkline.Value()) {
				if !containsVarRef(option) {
					ck.declaredOptions[option] = mkline
					ck.optionsInDeclarationOrder = append(ck.optionsInDeclarationOrder, option)
				}
			}
		}

	case mkline.IsDirective():
		// The conditionals are typically for OPSYS and MACHINE_ARCH.

	case mkline.IsInclude():
		if mkline.IncludedFile() == "../../mk/bsd.options.mk" {
			return false
		}

	default:
		line := mkline
		line.Warnf("Expected inclusion of \"../../mk/bsd.options.mk\".")
		line.Explain(
			"After defining the input variables (PKG_OPTIONS_VAR, etc.),",
			"bsd.options.mk should be included to do the actual processing.",
			"No other actions should take place in this part of the file",
			"in order to have the same structure in all options.mk files.")
		return false
	}

	return true
}

func (ck *OptionsLinesChecker) handleLowerLine(mkline *MkLine) {
	if mkline.IsDirective() {
		directive := mkline.Directive()
		if directive == "if" || directive == "elif" {
			cond := mkline.Cond()
			if cond != nil {
				ck.handleLowerCondition(mkline, cond)
			}
		}
	}
}

func (ck *OptionsLinesChecker) handleLowerCondition(mkline *MkLine, cond *MkCond) {

	recordUsedOption := func(varuse *MkVarUse) {
		if varuse.varname == "PKG_OPTIONS" && len(varuse.modifiers) == 1 {
			if m, positive, pattern := varuse.modifiers[0].MatchMatch(); m && positive {
				option := pattern
				if !containsVarRef(option) {
					ck.handledOptions[option] = mkline
					ck.optionsInDeclarationOrder = append(ck.optionsInDeclarationOrder, option)
				}
			}
		}
	}

	cond.Walk(&MkCondCallback{
		Empty: recordUsedOption,
		Var:   recordUsedOption})

	if cond.Empty != nil && cond.Empty.varname == "PKG_OPTIONS" && mkline.HasElseBranch() {
		mkline.Notef("The positive branch of the .if/.else should be the one where the option is set.")
		mkline.Explain(
			"For consistency among packages, the upper branch of this",
			".if/.else statement should always handle the case where the",
			"option is activated.",
			"A missing exclamation mark at this point can easily be overlooked.",
			"",
			"If that seems too much to type and the exclamation mark",
			"seems wrong for a positive test, switch the blocks nevertheless",
			"and write the condition like this, which has the same effect",
			"as the !empty(...).",
			"",
			"\t.if ${PKG_OPTIONS.packagename:Moption}")
	}
}

func (ck *OptionsLinesChecker) checkOptionsMismatch() {
	for _, option := range ck.optionsInDeclarationOrder {
		declared := ck.declaredOptions[option]
		handled := ck.handledOptions[option]

		switch {
		case handled == nil:
			declared.Warnf("Option %q should be handled below in an .if block.", option)
			declared.Explain(
				"If an option is not processed in this file, it may either be a",
				"typo, or the option does not have any effect.")

		case declared == nil:
			handled.Warnf("Option %q is handled but not added to PKG_SUPPORTED_OPTIONS.", option)
			handled.Explain(
				"This block of code will never be run since PKG_OPTIONS cannot",
				"contain this value.",
				"This is most probably a typo.")
		}
	}
}
