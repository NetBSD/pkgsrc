package line

import (
	"fmt"
	"netbsd.org/pkglint/regex"
)

type Line interface {
	fmt.Stringer

	Filename() string
	Linenos() string
	Text() string
	IsMultiline() bool
	IsChanged() bool

	Fatalf(fmt string, args ...interface{})
	Errorf(fmt string, args ...interface{})
	Warnf(fmt string, args ...interface{})
	Notef(fmt string, args ...interface{})
	ReferenceFrom(Line) string

	AutofixReplace(from, to string) bool
	AutofixReplaceRegexp(from regex.RegexPattern, to string) bool
	AutofixInsertBefore(text string) bool
	AutofixDelete() bool
	AutofixMark(reason string)
}

var NewLineEOF func(filename string) Line
