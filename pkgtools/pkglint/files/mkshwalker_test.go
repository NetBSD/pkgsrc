package main

import (
	"gopkg.in/check.v1"
)

func (s *Suite) Test_MkShWalker_Walk(c *check.C) {
	list, err := parseShellProgram(dummyLine, ""+
		"if condition; then action; else case selector in pattern) case-item-action ;; esac; fi; "+
		"set -e; cd ${WRKSRC}/locale; "+
		"for lang in *.po; do "+
		"  [ \"$${lang}\" = \"wxstd.po\" ] && continue; "+
		"  ${TOOLS_PATH.msgfmt} -c -o \"$${lang%.po}.mo\" \"$${lang}\"; "+
		"done")
	if c.Check(err, check.IsNil) && c.Check(list, check.NotNil) {
		var commands []string
		(*MkShWalker).Walk(nil, list, func(node interface{}) {
			if cmd, ok := node.(*MkShSimpleCommand); ok {
				commands = append(commands, NewStrCommand(cmd).String())
			}
		})
		c.Check(commands, deepEquals, []string{
			"[] condition []",
			"[] action []",
			"[] case-item-action []",
			"[] set [-e]",
			"[] cd [${WRKSRC}/locale]",
			"[] [ [\"$${lang}\" = \"wxstd.po\" ]]",
			"[] continue []",
			"[] ${TOOLS_PATH.msgfmt} [-c -o \"$${lang%.po}.mo\" \"$${lang}\"]"})
	}
}
