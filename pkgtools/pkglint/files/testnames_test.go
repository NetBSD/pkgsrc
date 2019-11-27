package pkglint

import (
	"gopkg.in/check.v1"
	"netbsd.org/pkglint/intqa"
)

// Ensures that all test names follow a common naming scheme:
//
//  Test_${Type}_${Method}__${description_using_underscores}
func (s *Suite) Test__qa(c *check.C) {
	ck := intqa.NewQAChecker(c.Errorf)
	ck.Configure("*", "*", "*", -intqa.EMissingTest)
	ck.Configure("path.go", "*", "*", +intqa.EMissingTest)
	ck.Configure("*yacc.go", "*", "*", intqa.ENone)
	ck.Configure("*", "*", "", -intqa.EMissingTest)
	ck.Check()
}
