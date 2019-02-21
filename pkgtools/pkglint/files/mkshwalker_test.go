package pkglint

import "gopkg.in/check.v1"

func (s *Suite) Test_MkShWalker_Walk(c *check.C) {
	list, err := parseShellProgram(dummyLine, ""+
		"if condition; then action; else case selector in pattern) case-item-action ;; esac; fi; "+
		"set -e; "+
		"cd ${WRKSRC}/locale; "+
		"for lang in *.po; do "+
		"  [ \"$${lang}\" = \"wxstd.po\" ] && continue; "+
		"  ${TOOLS_PATH.msgfmt} -c -o \"$${lang%.po}.mo\" \"$${lang}\"; "+
		"done; "+
		"while :; do fun() { :; } 1>&2; done")

	if c.Check(err, check.IsNil) && c.Check(list, check.NotNil) {
		var commands []string
		add := func(kind string, format string, args ...interface{}) {
			if format != "" && !contains(format, "%") {
				panic(format)
			}
			detail := sprintf(format, args...)
			commands = append(commands, sprintf("%16s %s", kind, detail))
		}

		walker := NewMkShWalker()
		callback := &walker.Callback
		callback.List = func(list *MkShList) { add("List", "with %d andOrs", len(list.AndOrs)) }
		callback.AndOr = func(andor *MkShAndOr) { add("AndOr", "with %d pipelines", len(andor.Pipes)) }
		callback.Pipeline = func(pipeline *MkShPipeline) { add("Pipeline", "with %d commands", len(pipeline.Cmds)) }
		callback.Command = func(command *MkShCommand) { add("Command", "") }
		callback.SimpleCommand = func(command *MkShSimpleCommand) {
			add("SimpleCommand", "%s", NewStrCommand(command).String())
			add("Path", "%s", walker.Path())
		}
		callback.CompoundCommand = func(command *MkShCompoundCommand) { add("CompoundCommand", "") }
		callback.Case = func(caseClause *MkShCase) { add("Case", "with %d items", len(caseClause.Cases)) }
		callback.CaseItem = func(caseItem *MkShCaseItem) { add("CaseItem", "with %d patterns", len(caseItem.Patterns)) }
		callback.FunctionDefinition = func(funcdef *MkShFunctionDefinition) { add("FunctionDef", "for %s", funcdef.Name) }
		callback.If = func(ifClause *MkShIf) { add("If", "with %d then-branches", len(ifClause.Conds)) }
		callback.Loop = func(loop *MkShLoop) { add("Loop", "") }
		callback.Words = func(words []*ShToken) { add("Words", "with %d words", len(words)) }
		callback.Word = func(word *ShToken) { add("Word", "%s", word.MkText) }
		callback.Redirects = func(redirects []*MkShRedirection) { add("Redirects", "with %d redirects", len(redirects)) }
		callback.Redirect = func(redirect *MkShRedirection) { add("Redirect", "%s", redirect.Op) }
		callback.For = func(forClause *MkShFor) { add("For", "variable %s", forClause.Varname) }
		callback.Varname = func(varname string) { add("Varname", "%s", varname) }

		walker.Walk(list)

		// TODO: Provide a reduced AST that omits all "AndOr with 1 pipelines", etc.
		//  It should look like this:
		//
		//  List with 5 andOrs (or generic Commands?)
		//    If with 1 then-branch(es)
		//      SimpleCommand condition
		//      SimpleCommand action
		//    Case with 1 item(s)
		//      ...

		c.Check(commands, deepEquals, []string{
			"            List with 5 andOrs",
			"           AndOr with 1 pipelines",
			"        Pipeline with 1 commands",
			"         Command ",
			" CompoundCommand ",
			"              If with 1 then-branches",
			"            List with 1 andOrs",
			"           AndOr with 1 pipelines",
			"        Pipeline with 1 commands",
			"         Command ",
			"   SimpleCommand condition",
			"            Path List.AndOr[0].Pipeline[0].Command[0].CompoundCommand.If.List[0].AndOr[0].Pipeline[0].Command[0].SimpleCommand",
			"            Word condition",
			"            List with 1 andOrs",
			"           AndOr with 1 pipelines",
			"        Pipeline with 1 commands",
			"         Command ",
			"   SimpleCommand action",
			"            Path List.AndOr[0].Pipeline[0].Command[0].CompoundCommand.If.List[1].AndOr[0].Pipeline[0].Command[0].SimpleCommand",
			"            Word action",
			"            List with 1 andOrs",
			"           AndOr with 1 pipelines",
			"        Pipeline with 1 commands",
			"         Command ",
			" CompoundCommand ",
			"            Case with 1 items",
			"            Word selector",
			"        CaseItem with 1 patterns",
			"           Words with 1 words",
			"            Word pattern",
			"            List with 1 andOrs",
			"           AndOr with 1 pipelines",
			"        Pipeline with 1 commands",
			"         Command ",
			"   SimpleCommand case-item-action",
			"            Path List.AndOr[0].Pipeline[0].Command[0].CompoundCommand.If." +
				"List[2].AndOr[0].Pipeline[0].Command[0].CompoundCommand.Case.CaseItem[0]." +
				"List.AndOr[0].Pipeline[0].Command[0].SimpleCommand",
			"            Word case-item-action",
			"           AndOr with 1 pipelines",
			"        Pipeline with 1 commands",
			"         Command ",
			"   SimpleCommand set -e",
			"            Path List.AndOr[1].Pipeline[0].Command[0].SimpleCommand",
			"            Word set",
			"           Words with 1 words",
			"            Word -e",
			"           AndOr with 1 pipelines",
			"        Pipeline with 1 commands",
			"         Command ",
			"   SimpleCommand cd ${WRKSRC}/locale",
			"            Path List.AndOr[2].Pipeline[0].Command[0].SimpleCommand",
			"            Word cd",
			"           Words with 1 words",
			"            Word ${WRKSRC}/locale",
			"           AndOr with 1 pipelines",
			"        Pipeline with 1 commands",
			"         Command ",
			" CompoundCommand ",
			"             For variable lang",
			"         Varname lang",
			"           Words with 1 words",
			"            Word *.po",
			"            List with 2 andOrs",
			"           AndOr with 2 pipelines",
			"        Pipeline with 1 commands",
			"         Command ",
			"   SimpleCommand [ \"$${lang}\" = \"wxstd.po\" ]",
			"            Path List.AndOr[3].Pipeline[0].Command[0].CompoundCommand.For.List.AndOr[0].Pipeline[0].Command[0].SimpleCommand",
			"            Word [",
			"           Words with 4 words",
			"            Word \"$${lang}\"",
			"            Word =",
			"            Word \"wxstd.po\"",
			"            Word ]",
			"        Pipeline with 1 commands",
			"         Command ",
			"   SimpleCommand continue",
			"            Path List.AndOr[3].Pipeline[0].Command[0].CompoundCommand.For.List.AndOr[0].Pipeline[1].Command[0].SimpleCommand",
			"            Word continue",
			"           AndOr with 1 pipelines",
			"        Pipeline with 1 commands",
			"         Command ",
			"   SimpleCommand ${TOOLS_PATH.msgfmt} -c -o \"$${lang%.po}.mo\" \"$${lang}\"",
			"            Path List.AndOr[3].Pipeline[0].Command[0].CompoundCommand.For.List.AndOr[1].Pipeline[0].Command[0].SimpleCommand",
			"            Word ${TOOLS_PATH.msgfmt}",
			"           Words with 4 words",
			"            Word -c",
			"            Word -o",
			"            Word \"$${lang%.po}.mo\"",
			"            Word \"$${lang}\"",
			"           AndOr with 1 pipelines",
			"        Pipeline with 1 commands",
			"         Command ",
			" CompoundCommand ",
			"            Loop ",
			"            List with 1 andOrs",
			"           AndOr with 1 pipelines",
			"        Pipeline with 1 commands",
			"         Command ",
			"   SimpleCommand :",
			"            Path List.AndOr[4].Pipeline[0].Command[0].CompoundCommand.Loop.List[0].AndOr[0].Pipeline[0].Command[0].SimpleCommand",
			"            Word :",
			"            List with 1 andOrs",
			"           AndOr with 1 pipelines",
			"        Pipeline with 1 commands",
			"         Command ",
			"     FunctionDef for fun",
			" CompoundCommand ",
			"            List with 1 andOrs",
			"           AndOr with 1 pipelines",
			"        Pipeline with 1 commands",
			"         Command ",
			"   SimpleCommand :",
			"            Path List.AndOr[4].Pipeline[0].Command[0].CompoundCommand.Loop." +
				"List[1].AndOr[0].Pipeline[0].Command[0].FunctionDefinition.CompoundCommand." +
				"List.AndOr[0].Pipeline[0].Command[0].SimpleCommand",
			"            Word :",
			"       Redirects with 1 redirects",
			"        Redirect >&",
			"            Word 2"})

		// After parsing, there is not a single level of indentation,
		// therefore even Parent(0) returns nil.
		c.Check(walker.Parent(0), equals, nil)
	}
}
