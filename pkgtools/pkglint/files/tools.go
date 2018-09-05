package main

import (
	"netbsd.org/pkglint/trace"
	"path"
	"sort"
	"strings"
)

// Tool is one of the many standard shell utilities that are typically
// provided by the operating system, or, if missing, are installed via
// pkgsrc.
//
// See `mk/tools/`.
type Tool struct {
	Name           string // e.g. "sed", "gzip"
	Varname        string // e.g. "SED", "GZIP_CMD"
	MustUseVarForm bool   // True for `echo`, because of many differing implementations.
	Validity       Validity
}

func (tool *Tool) SetValidity(validity Validity, traceName string) {
	if trace.Tracing && validity != tool.Validity {
		trace.Stepf("%s: Setting validity of %q to %s", traceName, tool.Name, validity)
	}
	tool.Validity = validity
}

// UsableAtLoadTime means that the tool may be used by its variable
// name after bsd.prefs.mk has been included.
//
// Additionally, all allowed cases from UsableAtRunTime are allowed.
//
//  VAR:=   ${TOOL}           # Not allowed since bsd.prefs.mk is not
//                            # included yet.
//
//  .include "../../bsd.prefs.mk"
//
//  VAR:=   ${TOOL}           # Allowed.
//  VAR!=   ${TOOL}           # Allowed.
//
//  VAR=    ${${TOOL}:sh}     # Allowed; the :sh modifier is evaluated
//                            # lazily, but when VAR should ever be
//                            # evaluated at load time, this still means
//                            # load time.
//
//  .if ${TOOL:T} == "tool"   # Allowed.
//  .endif
func (tool *Tool) UsableAtLoadTime(seenPrefs bool) bool {
	return seenPrefs && tool.Validity == AfterPrefsMk
}

// UsableAtRunTime means that the tool may be used by its simple name
// in all {pre,do,post}-* targets, and by its variable name in all
// runtime contexts.
//
//  VAR:=   ${TOOL}           # Not allowed; TOOL might not be initialized yet.
//  VAR!=   ${TOOL}           # Not allowed; TOOL might not be initialized yet.
//
//  VAR=    ${${TOOL}:sh}     # Probably ok; the :sh modifier is evaluated at
//                            # run time. But if VAR should ever be evaluated
//                            # at load time (see the "Not allowed" cases
//                            # above), it doesn't work. Currently pkglint
//                            # cannot detect these cases reliably.
//
//  own-target:
//          ${TOOL}           # Allowed.
//          tool              # Not allowed because the PATH might not be set
//                            # up for this target.
//
//  pre-configure:
//          ${TOOL}           # Allowed.
//          tool              # Allowed.
func (tool *Tool) UsableAtRunTime() bool {
	return tool.Validity == AtRunTime || tool.Validity == AfterPrefsMk
}

// Tools collects all tools for a certain scope (global or file)
// and remembers whether these tools are defined at all,
// and whether they are declared to be used via USE_TOOLS.
type Tools struct {
	TraceName string           // Only for the trace log
	byName    map[string]*Tool // "sed" => tool
	byVarname map[string]*Tool // "GREP_CMD" => tool
	SeenPrefs bool             // Determines the effect of adding the tool to USE_TOOLS
}

func NewTools(traceName string) Tools {
	return Tools{
		traceName,
		make(map[string]*Tool),
		make(map[string]*Tool),
		false}
}

// Define registers the tool by its name and the corresponding
// variable name (if nonempty).
//
// After this tool is added to USE_TOOLS, it may be used by this name
// (e.g. "awk") or by its variable (e.g. ${AWK}).
func (tr *Tools) Define(name, varname string, mkline MkLine) *Tool {
	if trace.Tracing {
		trace.Stepf("Tools.Define for %s: %q %q in %s", tr.TraceName, name, varname, mkline)
	}

	tool := tr.def(name, varname, mkline)
	if varname != "" {
		tool.Varname = varname
	}
	return tool
}

func (tr *Tools) def(name, varname string, mkline MkLine) *Tool {
	if mkline != nil && !tr.IsValidToolName(name) {
		mkline.Errorf("Invalid tool name %q.", name)
	}

	validity := Nowhere
	if mkline != nil {
		if IsPrefs(mkline.Filename) {
			validity = AfterPrefsMk
		} else if path.Base(mkline.Filename) == "bsd.pkg.mk" {
			validity = AtRunTime
		}
	}
	tool := &Tool{name, varname, false, validity}

	if name != "" {
		if existing := tr.byName[name]; existing != nil {
			tool = existing
		} else {
			tr.byName[name] = tool
		}
	}

	if varname != "" {
		if existing := tr.byVarname[varname]; existing == nil || len(existing.Name) > len(name) {
			tr.byVarname[varname] = tool
		}
	}

	return tool
}

func (tr *Tools) Trace() {
	if trace.Tracing {
		defer trace.Call1(tr.TraceName)()
	} else {
		return
	}

	var keys []string
	for k := range tr.byName {
		keys = append(keys, k)
	}
	sort.Strings(keys)

	for _, toolname := range keys {
		trace.Stepf("tool %+v", tr.byName[toolname])
	}
}

// ParseToolLine updates the tool definitions according to the given
// line from a Makefile.
func (tr *Tools) ParseToolLine(mkline MkLine) {
	tr.ParseToolLineCreate(mkline, false)
}

// ParseToolLineCreate updates the tool definitions according to the given
// line from a Makefile, registering the tools if necessary.
func (tr *Tools) ParseToolLineCreate(mkline MkLine, createIfAbsent bool) {
	switch {

	case mkline.IsVarassign():
		varparam := mkline.Varparam()
		value := mkline.Value()

		switch mkline.Varcanon() {
		case "TOOLS_CREATE":
			if tr.IsValidToolName(value) {
				tr.Define(value, "", mkline)
			}

		case "_TOOLS_VARNAME.*":
			if !containsVarRef(varparam) {
				tr.Define(varparam, value, mkline)
			}

		case "TOOLS_PATH.*", "_TOOLS_DEPMETHOD.*":
			if !containsVarRef(varparam) {
				tr.Define(varparam, "", mkline)
			}

		case "_TOOLS.*":
			if !containsVarRef(varparam) {
				tr.Define(varparam, "", mkline)
				for _, tool := range splitOnSpace(value) {
					tr.Define(tool, "", mkline)
				}
			}

		case "USE_TOOLS":
			tr.parseUseTools(mkline, createIfAbsent)
		}

	case mkline.IsInclude():
		if IsPrefs(mkline.IncludeFile()) {
			tr.SeenPrefs = true
		}
	}
}

// parseUseTools interprets a "USE_TOOLS+=" line from a Makefile fragment.
// It determines the validity of the tool, i.e. in which places it may be used.
//
// If createIfAbsent is true and the tools is unknown, it is registered.
func (tr *Tools) parseUseTools(mkline MkLine, createIfAbsent bool) {
	value := mkline.Value()
	if containsVarRef(value) {
		return
	}

	deps := splitOnSpace(value)

	// See mk/tools/autoconf.mk:/^\.if !defined/
	if matches(value, `\bautoconf213\b`) {
		for _, name := range [...]string{"autoconf-2.13", "autoheader-2.13", "autoreconf-2.13", "autoscan-2.13", "autoupdate-2.13", "ifnames-2.13"} {
			if createIfAbsent {
				tr.Define(name, "", mkline)
			}
			deps = append(deps, name)
		}
	}
	if matches(value, `\bautoconf\b`) {
		for _, name := range [...]string{"autoheader", "autom4te", "autoreconf", "autoscan", "autoupdate", "ifnames"} {
			if createIfAbsent {
				tr.Define(name, "", mkline)
			}
			deps = append(deps, name)
		}
	}

	for _, dep := range deps {
		name := strings.Split(dep, ":")[0]
		tool := tr.ByName(name)
		if tool == nil && createIfAbsent {
			tr.Define(name, "", mkline)
		}
		if tool != nil {
			validity := tr.validity(mkline.Filename)
			if validity > tool.Validity {
				tool.SetValidity(validity, tr.TraceName)
			}
		}
	}
}

func (tr *Tools) validity(fileName string) Validity {
	basename := path.Base(fileName)
	if basename == "Makefile" && tr.SeenPrefs {
		return AtRunTime
	}
	if basename == "bsd.prefs.mk" || basename == "Makefile" {
		return AfterPrefsMk
	}
	return AtRunTime
}

func (tr *Tools) ByVarname(varname string) (tool *Tool) { return tr.byVarname[varname] }

func (tr *Tools) ByName(name string) (tool *Tool) { return tr.byName[name] }

func (tr *Tools) Usable(tool *Tool, time ToolTime) bool {
	if time == LoadTime {
		return tool.UsableAtLoadTime(tr.SeenPrefs)
	} else {
		return tool.UsableAtRunTime()
	}
}

func (tr *Tools) AddAll(other Tools) {
	if trace.Tracing {
		defer trace.Call(other.TraceName, "to", tr.TraceName)()
	}

	for _, otherTool := range other.byName {
		if trace.Tracing {
			trace.Stepf("Tools.AddAll %+v", *otherTool)
		}
		tool := tr.def(otherTool.Name, otherTool.Varname, nil)
		tool.MustUseVarForm = tool.MustUseVarForm || otherTool.MustUseVarForm
		if otherTool.Validity > tool.Validity {
			tool.SetValidity(otherTool.Validity, tr.TraceName)
		}
	}
}

func (tr *Tools) IsValidToolName(name string) bool {
	return name == "[" || name == "echo -n" || matches(name, `^[-0-9a-z.]+$`)
}

type Validity uint8

const (
	// Nowhere means that the tool has not been added
	// to USE_TOOLS and therefore cannot be used at all.
	Nowhere Validity = iota

	// AtRunTime means that the tool has been added to USE_TOOLS
	// after including bsd.prefs.mk and therefore cannot be used
	// at load time.
	//
	// The tool may be used as ${TOOL} in all targets.
	// The tool may be used by its plain name in {pre,do,post}-* targets.
	AtRunTime

	// AfterPrefsMk means that the tool has been added to USE_TOOLS
	// before including bsd.prefs.mk and therefore can be used at
	// load time after bsd.prefs.mk has been included.
	//
	// The tool may be used as ${TOOL} everywhere.
	// The tool may be used by its plain name in {pre,do,post}-* targets.
	AfterPrefsMk
)

func (time Validity) String() string {
	return [...]string{"Nowhere", "AtRunTime", "AfterPrefsMk"}[time]
}

type ToolTime uint8

const (
	LoadTime ToolTime = iota
	RunTime
)

func (t ToolTime) String() string { return [...]string{"LoadTime", "RunTime"}[t] }
