// Package trace traces function calls and steps in-between.
package trace

import (
	"fmt"
	"io"
	"reflect"
	"runtime"
	"strings"
)

// Tracer produces a hierarchical structure of log events.
type Tracer struct {
	Tracing bool
	Out     io.Writer
	depth   int
}

// Result marks an argument of Tracer.Call as a result of that function.
// It is only logged when exiting from the function but not when entering it.
type Result struct {
	pointer interface{}
}

func (t *Tracer) Stepf(format string, args ...interface{}) {
	if t.Tracing {
		msg := fmt.Sprintf(format, args...)
		_, _ = io.WriteString(t.Out, fmt.Sprintf("TRACE: %s  %s\n", t.traceIndent(), msg))
	}
}

func (t *Tracer) Step1(format string, arg0 string) {
	t.Stepf(format, arg0)
}

func (t *Tracer) Step2(format string, arg0, arg1 string) {
	t.Stepf(format, arg0, arg1)
}

// Call0 is used to trace a no-arguments function call.
//
// Usage:
//  if trace.Tracing {
//      defer trace.Call0()()
//  }
func (t *Tracer) Call0() func() {
	return t.traceCall()
}

// Call1 is used to trace a function call with a single string argument.
//
// Usage:
//  if trace.Tracing {
//      defer trace.Call1(str1)()
//  }
func (t *Tracer) Call1(arg1 string) func() {
	return t.traceCall(arg1)
}

// Call2 is used to trace a function call with 2 string arguments.
//
// Usage:
//  if trace.Tracing {
//      defer trace.Call2(str1, str2)()
//  }
func (t *Tracer) Call2(arg1, arg2 string) func() {
	return t.traceCall(arg1, arg2)
}

// Call records a function call in the tracing log, both when entering and
// when leaving the function.
//
// Usage:
//  if trace.Tracing {
//      defer trace.Call(arg1, arg2, trace.Result(result1), trace.Result(result2))()
// }
func (t *Tracer) Call(args ...interface{}) func() {
	return t.traceCall(args...)
}

// https://stackoverflow.com/questions/13476349/check-for-nil-and-nil-interface-in-go
func isNil(a interface{}) bool {
	defer func() {
		_ = recover()
	}()
	return a == nil || reflect.ValueOf(a).IsNil()
}

func argsStr(args []interface{}) string {
	var rv strings.Builder
	for _, arg := range args {
		if rv.Len() > 0 {
			rv.WriteString(", ")
		}
		if str, ok := arg.(fmt.Stringer); ok && !isNil(str) {
			rv.WriteString(str.String())
		} else {
			_, _ = fmt.Fprintf(&rv, "%#v", arg)
		}
	}
	return rv.String()
}

func (t *Tracer) traceIndent() string {
	var indent strings.Builder
	for i := 0; i < t.depth; i++ {
		_, _ = fmt.Fprintf(&indent, "%d ", i+1)
	}
	return indent.String()
}

func (t *Tracer) traceCall(args ...interface{}) func() {
	if !t.Tracing {
		panic("Internal pkglint error: calls to trace.Call must only occur in tracing mode")
	}

	functionName := "?"
	if pc, _, _, ok := runtime.Caller(2); ok {
		if fn := runtime.FuncForPC(pc); fn != nil {
			functionName = strings.TrimPrefix(fn.Name(), "netbsd.org/pkglint.")
		}
	}
	indent := t.traceIndent()
	_, _ = fmt.Fprintf(t.Out, "TRACE: %s+ %s(%s)\n", indent, functionName, argsStr(withoutResults(args)))
	t.depth++

	return func() {
		t.depth--
		_, _ = fmt.Fprintf(t.Out, "TRACE: %s- %s(%s)\n", indent, functionName, argsStr(withResults(args)))
	}
}

// Result marks an argument as a result and is only logged when the function returns.
//
// Usage: defer trace.Call(arg1, arg2, tracing.Result(&result1), tracing.Result(&result2))()
func (t *Tracer) Result(rv interface{}) Result {
	if reflect.ValueOf(rv).Kind() != reflect.Ptr {
		panic(fmt.Sprintf("Result must be called with a pointer to the result, not %#v.", rv))
	}
	return Result{rv}
}

func withoutResults(args []interface{}) []interface{} {
	for i, arg := range args {
		if _, ok := arg.(Result); ok {
			return args[0:i]
		}
	}
	return args
}

func withResults(args []interface{}) []interface{} {
	for i, arg := range args {
		if _, ok := arg.(Result); ok {
			var awr []interface{}
			awr = append(awr, args[0:i]...)
			awr = append(awr, "=>")
			for _, res := range args[i:] {
				pointer := reflect.ValueOf(res.(Result).pointer)
				actual := reflect.Indirect(pointer).Interface()
				awr = append(awr, actual)
			}
			return awr
		}
	}
	return args
}
