package main

import "netbsd.org/pkglint/trace"

func ChecklinesOptionsMk(mklines *MkLines) {
	if trace.Tracing {
		defer trace.Call1(mklines.lines[0].Filename)()
	}

	mklines.Check()

	exp := NewMkExpecter(mklines)
	exp.AdvanceWhile(func(mkline MkLine) bool { return mkline.IsComment() || mkline.IsEmpty() })

	if exp.EOF() || !(exp.CurrentMkLine().IsVarassign() && exp.CurrentMkLine().Varname() == "PKG_OPTIONS_VAR") {
		exp.CurrentLine().Warnf("Expected definition of PKG_OPTIONS_VAR.")
		Explain(
			"The input variables in an options.mk file should always be",
			"mentioned in the same order: PKG_OPTIONS_VAR, ",
			"PKG_SUPPORTED_OPTIONS, PKG_SUGGESTED_OPTIONS.  This way, the",
			"options.mk files have the same structure and are easy to understand.")
		return
	}
	exp.Advance()

	declaredOptions := make(map[string]MkLine)
	handledOptions := make(map[string]MkLine)
	var optionsInDeclarationOrder []string

	// The conditionals are typically for OPSYS and MACHINE_ARCH.
loop:
	for ; !exp.EOF(); exp.Advance() {
		mkline := exp.CurrentMkLine()
		switch {
		case mkline.IsComment():
		case mkline.IsEmpty():
		case mkline.IsVarassign():
			varname := mkline.Varname()
			if varname == "PKG_SUPPORTED_OPTIONS" || hasPrefix(varname, "PKG_OPTIONS_GROUP.") {
				for _, option := range splitOnSpace(mkline.Value()) {
					if option == mkline.WithoutMakeVariables(option) {
						declaredOptions[option] = mkline
						optionsInDeclarationOrder = append(optionsInDeclarationOrder, option)
					}
				}
			}
		case mkline.IsCond():
		case mkline.IsInclude():
			includedFile := mkline.IncludeFile()
			switch {
			case matches(includedFile, `/[^/]+\.buildlink3\.mk$`):
			case matches(includedFile, `/[^/]+\.builtin\.mk$`):
			case includedFile == "../../mk/bsd.prefs.mk":
			case includedFile == "../../mk/bsd.fast.prefs.mk":

			case includedFile == "../../mk/bsd.options.mk":
				exp.Advance()
				break loop
			}
		default:
			exp.CurrentLine().Warnf("Expected inclusion of \"../../mk/bsd.options.mk\".")
			Explain(
				"After defining the input variables (PKG_OPTIONS_VAR, etc.),",
				"bsd.options.mk should be included to do the actual processing.",
				"No other actions should take place in this part of the file",
				"in order to have the same structure in all options.mk files.")
			return
		}
	}

	for ; !exp.EOF(); exp.Advance() {
		mkline := exp.CurrentMkLine()
		if mkline.IsCond() && mkline.Directive() == "if" {
			cond := NewMkParser(mkline.Line, mkline.Args(), false).MkCond()
			if cond != nil {
				cond.Visit("empty", func(t *Tree) {
					varuse := t.args[0].(MkVarUse)
					if varuse.varname == "PKG_OPTIONS" && len(varuse.modifiers) == 1 && hasPrefix(varuse.modifiers[0], "M") {
						option := varuse.modifiers[0][1:]
						handledOptions[option] = mkline
						optionsInDeclarationOrder = append(optionsInDeclarationOrder, option)
					}
				})
			}
		}
	}

	for _, option := range optionsInDeclarationOrder {
		declared := declaredOptions[option]
		handled := handledOptions[option]
		if declared != nil && handled == nil {
			declared.Warnf("Option %q should be handled below in an .if block.", option)
			Explain(
				"If an option is not processed in this file, it may either be a",
				"typo, or the option does not have any effect.")
		}
		if declared == nil && handled != nil {
			handled.Warnf("Option %q is handled but not declared above.", option)
			Explain(
				"This block of code will never be run since PKG_OPTIONS cannot",
				"contain this value.  This is most probably a typo.")
		}
	}

	SaveAutofixChanges(mklines.lines)
}
