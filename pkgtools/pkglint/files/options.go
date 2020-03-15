package pkglint

func CheckLinesOptionsMk(mklines *MkLines, buildlinkID string) {
	ck := OptionsLinesChecker{
		mklines,
		buildlinkID,
		false,
		make(map[string]*MkLine),
		false,
		make(map[string]*MkLine),
		nil}

	ck.Check()
}

// OptionsLinesChecker checks an options.mk file of a pkgsrc package.
//
// See mk/bsd.options.mk for a detailed description.
type OptionsLinesChecker struct {
	mklines     *MkLines
	buildlinkID string

	declaredArbitrary         bool
	declaredOptions           map[string]*MkLine
	handledArbitrary          bool
	handledOptions            map[string]*MkLine
	optionsInDeclarationOrder []string
}

func (ck *OptionsLinesChecker) Check() {
	mklines := ck.mklines

	mklines.Check()

	ck.collect()

	ck.checkOptionsMismatch()

	mklines.SaveAutofixChanges()
}

func (ck *OptionsLinesChecker) collect() {
	seenPkgOptionsVar := false
	seenInclude := false

	ck.mklines.ForEach(func(mkline *MkLine) {
		if mkline.IsEmpty() || mkline.IsComment() {
			return
		}

		if !seenInclude {
			if !seenPkgOptionsVar && mkline.IsVarassign() && mkline.Varname() == "PKG_OPTIONS_VAR" {
				seenPkgOptionsVar = true
				buildlinkID := ck.buildlinkID
				optionsID := varnameParam(mkline.Value())
				if buildlinkID != "" && optionsID != "" && buildlinkID != optionsID {
					mkline.Warnf("The buildlink3 identifier %q should be the same as the options identifier %q.",
						buildlinkID, optionsID)
					mkline.Explain(
						"Having different identifiers refer to the same package",
						"is confusing for the pkgsrc user.",
						"The pkgsrc infrastructure doesn't care though",
						"if the identifiers in PKG_OPTIONS.* and PKG_BUILD_OPTIONS.*",
						"are the same or not.")
				}
			}
			seenInclude = mkline.IsInclude() && mkline.IncludedFile() == "../../mk/bsd.options.mk"
		}

		if !seenInclude {
			ck.handleUpperLine(mkline, seenPkgOptionsVar)
		} else {
			ck.handleLowerLine(mkline)
		}
	})

	if !seenPkgOptionsVar {
		ck.mklines.Whole().Errorf("Each options.mk file must define PKG_OPTIONS_VAR.")
	}

	if !seenInclude {
		file := ck.mklines.Whole()
		file.Errorf("Each options.mk file must .include \"../../mk/bsd.options.mk\".")
		file.Explain(
			"After defining the input variables (PKG_OPTIONS_VAR, etc.),",
			"bsd.options.mk must be included to do the actual processing.")
	}
}

// handleUpperLine checks a line from the upper part of an options.mk file,
// before bsd.options.mk is included.
func (ck *OptionsLinesChecker) handleUpperLine(mkline *MkLine, seenPkgOptionsVar bool) {

	declare := func(option string) {
		if containsVarUse(option) {
			ck.declaredArbitrary = true
		} else {
			ck.declaredOptions[option] = mkline
			ck.optionsInDeclarationOrder = append(ck.optionsInDeclarationOrder, option)
		}
	}

	if !mkline.IsVarassign() {
		return
	}

	switch mkline.Varcanon() {
	case "PKG_SUPPORTED_OPTIONS",
		"PKG_SUPPORTED_OPTIONS.*",
		"PKG_OPTIONS_GROUP.*",
		"PKG_OPTIONS_SET.*":
		if !seenPkgOptionsVar {
			ck.warnVarorder(mkline)
		}

		for _, option := range mkline.ValueFields(mkline.Value()) {
			if optionVarUse := ToVarUse(option); optionVarUse != nil {
				forVars := ck.mklines.ExpandLoopVar(optionVarUse.varname)
				for _, option := range forVars {
					declare(option)
				}
				if len(forVars) == 0 {
					for _, option := range mkline.ValueFields(resolveVariableRefs(option, ck.mklines, nil)) {
						declare(option)
					}
				}
			} else {
				declare(option)
			}
		}
	}
}

func (ck *OptionsLinesChecker) handleLowerLine(mkline *MkLine) {
	if !mkline.IsDirective() {
		return
	}

	directive := mkline.Directive()
	if directive != "if" && directive != "elif" {
		return
	}

	cond := mkline.Cond()
	if cond == nil {
		return
	}

	ck.handleLowerCondition(mkline, cond)
}

func (ck *OptionsLinesChecker) handleLowerCondition(mkline *MkLine, cond *MkCond) {

	recordOption := func(option string) {
		if containsVarUse(option) {
			ck.handledArbitrary = true
			return
		}

		ck.handledOptions[option] = mkline
		ck.optionsInDeclarationOrder = append(ck.optionsInDeclarationOrder, option)
	}

	recordVarUse := func(varuse *MkVarUse) {
		if varuse.varname != "PKG_OPTIONS" || len(varuse.modifiers) != 1 {
			return
		}

		m, positive, pattern, exact := varuse.modifiers[0].MatchMatch()
		if !m || !positive {
			return
		}

		if optionVarUse := ToVarUse(pattern); optionVarUse != nil {
			for _, option := range ck.mklines.ExpandLoopVar(optionVarUse.varname) {
				recordOption(option)
			}

		} else if exact {
			recordOption(pattern)

		} else {
			matched := false
			for declaredOption := range ck.declaredOptions {
				if pathMatches(pattern, declaredOption) {
					matched = true
					recordOption(declaredOption)
				}
			}
			if !matched {
				ck.handledArbitrary = true
			}
		}
	}

	cond.Walk(&MkCondCallback{
		Empty: recordVarUse,
		Var:   recordVarUse})

	if cond.Empty != nil && cond.Empty.varname == "PKG_OPTIONS" && mkline.HasElseBranch() {
		mkline.Warnf("The positive branch of the .if/.else " +
			"should be the one where the option is set.")
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
			"\t.if ${PKG_OPTIONS:Moption}")
	}
}

func (ck *OptionsLinesChecker) checkOptionsMismatch() {
	for _, option := range ck.optionsInDeclarationOrder {
		declared := ck.declaredOptions[option]
		handled := ck.handledOptions[option]

		switch {
		case handled == nil && !ck.handledArbitrary:
			declared.Warnf("Option %q should be handled below in an .if block.", option)
			declared.Explain(
				"If an option is not processed in this file, it may either be a",
				"typo, or the option does not have any effect.")

		case declared == nil && !ck.declaredArbitrary:
			handled.Warnf("Option %q is handled but not added to PKG_SUPPORTED_OPTIONS.", option)
			handled.Explain(
				"This block of code will never be run since PKG_OPTIONS cannot",
				"contain this value.",
				"This is most probably a typo.")
		}
	}
}

func (ck *OptionsLinesChecker) warnVarorder(mkline *MkLine) {
	mkline.Warnf("Expected definition of PKG_OPTIONS_VAR.")
	mkline.Explain(
		"The input variables in an options.mk file should always be",
		"mentioned in the same order: PKG_OPTIONS_VAR,",
		"PKG_SUPPORTED_OPTIONS, PKG_SUGGESTED_OPTIONS.",
		"",
		"This way, the options.mk files have the same structure and are easy to understand.")
}
