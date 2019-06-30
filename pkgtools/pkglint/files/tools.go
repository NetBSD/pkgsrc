package pkglint

import (
	"sort"
	"strings"
)

// Tool is one of the many standard shell utilities that are typically
// provided by the operating system, or, if missing, are installed via
// pkgsrc.
//
// See `mk/tools/`.
type Tool struct {
	Name    string // e.g. "sed", "gzip"
	Varname string // e.g. "SED", "GZIP_CMD"

	// Some of the very simple tools (echo, printf, test) differ in their implementations.
	//
	// When bmake encounters a "simple" command line, it bypasses the
	// call to a shell (see devel/bmake/files/compat.c:/useShell/).
	// Therefore, sometimes the shell builtin is run, and sometimes the
	// native tool.
	//
	// In particular, this decision depends on PKG_DEBUG_LEVEL
	// since that variable adds a semicolon to the command line, which is
	// considered one of the characters that force the commands being
	// executed by the shell. As of December 2018, the list of special characters
	// is "~#=|^(){};&<>*?[]:$`\\\n".
	//
	// To work around this tricky situation, pkglint warns when these shell builtins
	// are used by their simple names (echo, test) instead of the variable form
	// (${ECHO}, ${TEST}).
	MustUseVarForm bool
	Validity       Validity
	Aliases        []string
}

func (tool *Tool) String() string {
	aliases := ""
	if len(tool.Aliases) > 0 {
		aliases = ":" + strings.Join(tool.Aliases, ",")
	}

	varForm := ifelseStr(tool.MustUseVarForm, "var", "")

	return sprintf("%s:%s:%s:%s%s",
		tool.Name, tool.Varname, varForm, tool.Validity, aliases)
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
//                            # above), it doesn't work. As of January 2019,
//                            # pkglint cannot reliably distinguish these cases.
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
	byName    map[string]*Tool // "sed" => tool
	byVarname map[string]*Tool // "GREP_CMD" => tool
	fallback  *Tools

	// Determines the effect of adding the tool to USE_TOOLS.
	//
	// As long as bsd.prefs.mk has definitely not been included by the current file,
	// tools added to USE_TOOLS are available at load time, but only after bsd.prefs.mk
	// has been included.
	//
	// Adding a tool to USE_TOOLS _after_ bsd.prefs.mk has been included, on the other
	// hand, only makes the tool available at run time.
	SeenPrefs bool

	// For example, "sed" is an alias of "gsed".
	//
	// This means when gsed is added to USE_TOOLS, sed is implicitly added as well.
	AliasOf map[string]string
}

func NewTools() *Tools {
	return &Tools{
		make(map[string]*Tool),
		make(map[string]*Tool),
		nil,
		false,
		make(map[string]string)}
}

// Define registers the tool by its name and the corresponding
// variable name (if nonempty). Depending on the given mkline,
// it may be added to USE_TOOLS automatically.
//
// After this tool is added to USE_TOOLS, it may be used by this name
// (e.g. "awk") or by its variable (e.g. ${AWK}).
func (tr *Tools) Define(name, varname string, mkline *MkLine) *Tool {
	if trace.Tracing {
		trace.Stepf("Tools.Define: %q %q in %s", name, varname, mkline)
	}

	if !tr.IsValidToolName(name) {
		mkline.Errorf("Invalid tool name %q.", name)
		return nil
	}

	validity := tr.validity(mkline.Basename, false)
	return tr.def(name, varname, false, validity, nil)
}

func (tr *Tools) def(name, varname string, mustUseVarForm bool, validity Validity, aliases []string) *Tool {
	assert(tr.IsValidToolName(name))

	fresh := Tool{name, varname, mustUseVarForm, validity, aliases}

	tool := tr.byName[name]
	if tool == nil {
		tool = &fresh
		tr.byName[name] = tool
	} else {
		tr.merge(tool, &fresh)
	}

	if tr.fallback != nil {
		if fallback := tr.fallback.ByName(name); fallback != nil {
			tr.merge(tool, fallback)
		}
	}

	if varname != "" {
		if existing := tr.byVarname[varname]; existing == nil || len(existing.Name) > len(name) {
			tr.byVarname[varname] = tool
		}
	}

	for _, alias := range aliases {
		tr.AliasOf[alias] = name
	}

	return tool
}

func (tr *Tools) merge(target, source *Tool) {
	if target.Varname == "" && source.Varname != "" {
		target.Varname = source.Varname
	}
	if !target.MustUseVarForm && source.MustUseVarForm {
		target.MustUseVarForm = true
	}
	if source.Validity > target.Validity {
		target.Validity = source.Validity
	}
}

func (tr *Tools) Trace() {
	if trace.Tracing {
		defer trace.Call0()()
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

	if tr.fallback != nil {
		tr.fallback.Trace()
	}
}

// ParseToolLine updates the tool definitions according to the given
// line from a Makefile.
//
// If fromInfrastructure is true, the tool is defined even when it is only
// added to USE_TOOLS (which normally doesn't define anything). This way,
// pkglint also finds those tools whose definitions are too difficult to
// parse from the code.
//
// If addToUseTools is true, a USE_TOOLS line makes a tool immediately
// usable. This should only be done if the current line is unconditional.
func (tr *Tools) ParseToolLine(mklines *MkLines, mkline *MkLine, fromInfrastructure bool, addToUseTools bool) {
	switch {

	case mkline.IsVarassign():
		varparam := mkline.Varparam()
		value := mkline.Value()

		switch mkline.Varcanon() {
		case "TOOLS_CREATE":
			for _, name := range mkline.ValueFields(value) {
				if tr.IsValidToolName(name) {
					tr.def(name, "", false, AtRunTime, nil)
				}
			}

		case "_TOOLS_VARNAME.*":
			if !containsVarRef(varparam) {
				tr.Define(varparam, value, mkline)
			}

		case "TOOLS_PATH.*", "_TOOLS_DEPMETHOD.*":
			if !containsVarRef(varparam) {
				tr.Define(varparam, "", mkline)
			}

		case "TOOLS_ALIASES.*":
			if containsVarRef(varparam) {
				break
			}

			tool := tr.def(varparam, "", false, Nowhere, nil)

			for _, alias := range mkline.ValueFields(value) {
				if tr.IsValidToolName(alias) {
					tr.addAlias(tool, alias)
				} else {
					varUse := ToVarUse(alias)
					if varUse != nil {
						for _, subAlias := range mklines.ExpandLoopVar(varUse.varname) {
							if tr.IsValidToolName(subAlias) {
								tr.addAlias(tool, subAlias)
							}
						}
					}
				}
			}

		case "_TOOLS.*":
			if !containsVarRef(varparam) {
				tr.Define(varparam, "", mkline)
				for _, tool := range mkline.ValueFields(value) {
					tr.Define(tool, "", mkline)
				}
			}

		case "USE_TOOLS":
			tr.parseUseTools(mkline, fromInfrastructure, addToUseTools)
		}

	case mkline.IsInclude():
		if IsPrefs(mkline.IncludedFile()) {
			tr.SeenPrefs = true
		}
	}
}

func (tr *Tools) addAlias(tool *Tool, alias string) {
	tool.Aliases = append(tool.Aliases, alias)
	tr.AliasOf[alias] = tool.Name
}

// parseUseTools interprets a "USE_TOOLS+=" line from a Makefile fragment.
// It determines the validity of the tool, i.e. in which places it may be used.
//
// If createIfAbsent is true and the tool is unknown, it is registered.
// This can be done only in the pkgsrc infrastructure files, where the
// actual definition is assumed to be in some other file. In packages
// though, this assumption cannot be made and pkglint needs to be strict.
func (tr *Tools) parseUseTools(mkline *MkLine, createIfAbsent bool, addToUseTools bool) {
	value := mkline.Value()
	if containsVarRef(value) {
		return
	}

	validity := tr.validity(mkline.Basename, addToUseTools)
	for _, dep := range mkline.ValueFields(value) {
		name := strings.Split(dep, ":")[0]
		if createIfAbsent || tr.ByName(name) != nil {
			tr.def(name, "", false, validity, nil)
			for _, implicitName := range tr.implicitTools(name) {
				tr.def(implicitName, "", false, validity, nil)
			}
		}
	}
}

func (tr *Tools) implicitTools(toolName string) []string {

	// See mk/tools/autoconf.mk:/^\.if !defined/

	if toolName == "autoconf213" {
		return []string{
			"autoconf-2.13", "autoheader-2.13", "autoreconf-2.13",
			"autoscan-2.13", "autoupdate-2.13", "ifnames-2.13",
			"autoconf",
			"autoheader", "autom4te", "autoreconf",
			"autoscan", "autoupdate", "ifnames"}
	}

	if toolName == "autoconf" {
		return []string{
			"autoheader", "autom4te", "autoreconf",
			"autoscan", "autoupdate", "ifnames"}
	}

	return nil
}

func (tr *Tools) validity(basename string, useTools bool) Validity {
	switch {
	case IsPrefs(basename): // IsPrefs is not 100% accurate here but good enough
		return AfterPrefsMk
	case basename == "Makefile" && !tr.SeenPrefs:
		return AfterPrefsMk
	case useTools:
		return AtRunTime
	default:
		return Nowhere
	}
}

func (tr *Tools) ByName(name string) *Tool {
	tool := tr.byName[name]
	if tool == nil && tr.fallback != nil {
		fallback := tr.fallback.ByName(name)
		if fallback != nil {
			tool = tr.def(fallback.Name, fallback.Varname, fallback.MustUseVarForm, fallback.Validity, fallback.Aliases)
		}
	}
	tr.adjustValidity(tool)
	return tool
}

func (tr *Tools) ByVarname(varname string) *Tool {
	tool := tr.byVarname[varname]
	if tool == nil && tr.fallback != nil {
		fallback := tr.fallback.ByVarname(varname)
		if fallback != nil {
			tool = tr.def(fallback.Name, fallback.Varname, fallback.MustUseVarForm, fallback.Validity, fallback.Aliases)
		}
	}
	tr.adjustValidity(tool)
	return tool
}

// TODO: Tools.ByCommand (name or ${VARNAME})

func (tr *Tools) Usable(tool *Tool, time ToolTime) bool {
	if time == LoadTime {
		return tool.UsableAtLoadTime(tr.SeenPrefs)
	} else {
		return tool.UsableAtRunTime()
	}
}

func (tr *Tools) Fallback(other *Tools) {
	assert(tr.fallback == nil) // Must only be called once.
	tr.fallback = other
}

func (tr *Tools) IsValidToolName(name string) bool {
	return name == "[" || name == "echo -n" || matches(name, `^[-0-9a-z.]+$`)
}

func (tr *Tools) adjustValidity(tool *Tool) {
	if tool == nil {
		return
	}

	aliasName := tr.AliasOf[tool.Name]
	if aliasName == "" {
		return
	}

	alias := tr.ByName(tr.AliasOf[tool.Name])
	if alias.Validity > tool.Validity {
		tool.Validity = alias.Validity
	}
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
