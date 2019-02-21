package pkglint

func CheckLinesOptionsMk(mklines MkLines) {
	if trace.Tracing {
		defer trace.Call1(mklines.lines.FileName)()
	}

	mklines.Check()

	mlex := NewMkLinesLexer(mklines)
	mlex.SkipWhile(func(mkline MkLine) bool { return mkline.IsComment() || mkline.IsEmpty() })

	if mlex.EOF() || !(mlex.CurrentMkLine().IsVarassign() && mlex.CurrentMkLine().Varname() == "PKG_OPTIONS_VAR") {
		mlex.CurrentLine().Warnf("Expected definition of PKG_OPTIONS_VAR.")
		G.Explain(
			"The input variables in an options.mk file should always be",
			"mentioned in the same order: PKG_OPTIONS_VAR,",
			"PKG_SUPPORTED_OPTIONS, PKG_SUGGESTED_OPTIONS.",
			"This way, the options.mk files have the same structure and are easy to understand.")
		return
	}
	mlex.Skip()

	declaredOptions := make(map[string]MkLine)
	handledOptions := make(map[string]MkLine)
	var optionsInDeclarationOrder []string

loop:
	for ; !mlex.EOF(); mlex.Skip() {
		mkline := mlex.CurrentMkLine()
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
						declaredOptions[option] = mkline
						optionsInDeclarationOrder = append(optionsInDeclarationOrder, option)
					}
				}
			}

		case mkline.IsDirective():
			// The conditionals are typically for OPSYS and MACHINE_ARCH.

		case mkline.IsInclude():
			if mkline.IncludedFile() == "../../mk/bsd.options.mk" {
				mlex.Skip()
				break loop
			}

		default:
			mlex.CurrentLine().Warnf("Expected inclusion of \"../../mk/bsd.options.mk\".")
			G.Explain(
				"After defining the input variables (PKG_OPTIONS_VAR, etc.),",
				"bsd.options.mk should be included to do the actual processing.",
				"No other actions should take place in this part of the file",
				"in order to have the same structure in all options.mk files.")
			return
		}
	}

	for ; !mlex.EOF(); mlex.Skip() {
		mkline := mlex.CurrentMkLine()
		if mkline.IsDirective() && (mkline.Directive() == "if" || mkline.Directive() == "elif") {
			cond := mkline.Cond()
			if cond == nil {
				continue
			}

			recordUsedOption := func(varuse *MkVarUse) {
				if varuse.varname == "PKG_OPTIONS" && len(varuse.modifiers) == 1 {
					if m, positive, pattern := varuse.modifiers[0].MatchMatch(); m && positive {
						option := pattern
						if !containsVarRef(option) {
							handledOptions[option] = mkline
							optionsInDeclarationOrder = append(optionsInDeclarationOrder, option)
						}
					}
				}
			}
			cond.Walk(&MkCondCallback{
				Empty: recordUsedOption,
				Var:   recordUsedOption})

			if cond.Empty != nil && mkline.HasElseBranch() {
				mkline.Notef("The positive branch of the .if/.else should be the one where the option is set.")
				G.Explain(
					"For consistency among packages, the upper branch of this",
					".if/.else statement should always handle the case where the",
					"option is activated.",
					"A missing exclamation mark at this point can easily be overlooked.")
			}
		}
	}

	for _, option := range optionsInDeclarationOrder {
		declared := declaredOptions[option]
		handled := handledOptions[option]

		switch {
		case handled == nil:
			declared.Warnf("Option %q should be handled below in an .if block.", option)
			G.Explain(
				"If an option is not processed in this file, it may either be a",
				"typo, or the option does not have any effect.")

		case declared == nil:
			handled.Warnf("Option %q is handled but not added to PKG_SUPPORTED_OPTIONS.", option)
			G.Explain(
				"This block of code will never be run since PKG_OPTIONS cannot",
				"contain this value.",
				"This is most probably a typo.")
		}
	}

	mklines.SaveAutofixChanges()
}
