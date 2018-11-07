package main

import (
	"gopkg.in/check.v1"
	"netbsd.org/pkglint/intqa"
)

// Ensures that all test names follow a common naming scheme:
//
//  Test_${Type}_${Method}__${description_using_underscores}
func (s *Suite) Test__test_names(c *check.C) {
	ck := intqa.NewTestNameChecker(c)
	ck.IgnoreFiles("*yacc.go")
	ck.AllowPrefix("Varalign", "mklines_varalign.go")
	ck.AllowPrefix("ShellParser", "mkshparser.go")
	ck.AllowCamelCaseDescriptions(
		"comparing_YesNo_variable_to_string",
		"GitHub",
		"enumFrom",
		"enumFromDirs",
		"dquotBacktDquot",
		"and_getSubdirs",
		"SilentAutofixFormat")
	ck.ShowWarnings(false)
	ck.Check()
}
