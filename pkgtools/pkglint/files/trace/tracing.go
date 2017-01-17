// Package trace traces function calls and steps in-between.
package trace

import (
	"fmt"
	"io"
	"reflect"
	"runtime"
	"strings"
)

var (
	Tracing bool
	Out     io.Writer
)

var traceDepth int

func Ref(rv interface{}) ref {
	return ref{rv}
}

func (r ref) String() string {
	ptr := reflect.ValueOf(r.intf)
	ref := reflect.Indirect(ptr)
	return fmt.Sprintf("%v", ref)
}

func Stepf(format string, args ...interface{}) {
	if Tracing {
		msg := fmt.Sprintf(format, args...)
		io.WriteString(Out, fmt.Sprintf("TRACE: %s  %s\n", traceIndent(), msg))
	}
}

func Step1(format string, arg0 string) {
	Stepf(format, arg0)
}

func Step2(format string, arg0, arg1 string) {
	Stepf(format, arg0, arg1)
}

func Call0() func() {
	return traceCall()
}

func Call1(arg1 string) func() {
	return traceCall(arg1)
}

func Call2(arg1, arg2 string) func() {
	return traceCall(arg1, arg2)
}

func Call(args ...interface{}) func() {
	return traceCall(args...)
}

type ref struct {
	intf interface{}
}

// http://stackoverflow.com/questions/13476349/check-for-nil-and-nil-interface-in-go
func isNil(a interface{}) bool {
	defer func() {
		recover()
	}()
	return a == nil || reflect.ValueOf(a).IsNil()
}

func argsStr(args ...interface{}) string {
	argsStr := ""
	for i, arg := range args {
		if i != 0 {
			argsStr += ", "
		}
		if str, ok := arg.(fmt.Stringer); ok && !isNil(str) {
			argsStr += str.String()
		} else {
			argsStr += fmt.Sprintf("%#v", arg)
		}
	}
	return argsStr
}

func traceIndent() string {
	indent := ""
	for i := 0; i < traceDepth; i++ {
		indent += fmt.Sprintf("%d ", i+1)
	}
	return indent
}

func traceCall(args ...interface{}) func() {
	if !Tracing {
		panic("Internal pkglint error: calls to trace.Call must only occur in tracing mode")
	}

	funcname := "?"
	if pc, _, _, ok := runtime.Caller(2); ok {
		if fn := runtime.FuncForPC(pc); fn != nil {
			funcname = strings.TrimPrefix(fn.Name(), "netbsd.org/pkglint.")
		}
	}
	indent := traceIndent()
	io.WriteString(Out, fmt.Sprintf("TRACE: %s+ %s(%s)\n", indent, funcname, argsStr(args...)))
	traceDepth++

	return func() {
		traceDepth--
		io.WriteString(Out, fmt.Sprintf("TRACE: %s- %s(%s)\n", indent, funcname, argsStr(args...)))
	}
}
