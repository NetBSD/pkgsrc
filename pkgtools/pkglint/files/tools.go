package main

import (
	"netbsd.org/pkglint/trace"
	"sort"
	"strings"
)

// Tool is one of the many standard shell utilities that are typically
// provided by the operating system, or, if missing, are installed via
// pkgsrc.
//
// See `mk/tools/`.
type Tool struct {
	Name             string // e.g. "sed", "gzip"
	Varname          string // e.g. "SED", "GZIP_CMD"
	MustUseVarForm   bool   // True for `echo`, because of many differing implementations.
	Predefined       bool   // This tool is used by the pkgsrc infrastructure, therefore the package does not need to add it to `USE_TOOLS` explicitly.
	UsableAtLoadTime bool   // May be used after including `bsd.prefs.mk`.
}

type ToolRegistry struct {
	byName    map[string]*Tool
	byVarname map[string]*Tool
}

func NewToolRegistry() ToolRegistry {
	return ToolRegistry{make(map[string]*Tool), make(map[string]*Tool)}
}

// Register registers the tool by its name.
// The tool may then be used by this name (e.g. "awk"),
// but not by a corresponding variable (e.g. ${AWK}).
// The toolname may include the scope (:pkgsrc, :run, etc.).
func (tr *ToolRegistry) Register(toolname string, mkline MkLine) *Tool {
	name := strings.SplitN(toolname, ":", 2)[0]
	tr.validateToolName(name, mkline)

	tool := tr.byName[name]
	if tool == nil {
		tool = &Tool{Name: name}
		tr.byName[name] = tool
	}
	return tool
}

func (tr *ToolRegistry) RegisterVarname(toolname, varname string, mkline MkLine) *Tool {
	tool := tr.Register(toolname, mkline)
	tool.Varname = varname
	tr.byVarname[varname] = tool
	return tool
}

func (tr *ToolRegistry) RegisterTool(tool *Tool, mkline MkLine) {
	tr.validateToolName(tool.Name, mkline)

	if tool.Name != "" && tr.byName[tool.Name] == nil {
		tr.byName[tool.Name] = tool
	}
	if tool.Varname != "" && tr.byVarname[tool.Varname] == nil {
		tr.byVarname[tool.Varname] = tool
	}
}

func (tr *ToolRegistry) FindByCommand(cmd *ShToken) *Tool {
	if tool := tr.byName[cmd.MkText]; tool != nil {
		return tool
	}
	if len(cmd.Atoms) == 1 {
		if varuse := cmd.Atoms[0].VarUse(); varuse != nil {
			if tool := tr.byVarname[varuse.varname]; tool != nil {
				return tool
			}
		}
	}
	return nil
}

func (tr *ToolRegistry) Trace() {
	if trace.Tracing {
		defer trace.Call0()()
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

// ParseToolLine parses a tool definition from the pkgsrc infrastructure,
// e.g. in mk/tools/replace.mk.
func (tr *ToolRegistry) ParseToolLine(mkline MkLine) {
	if mkline.IsVarassign() {
		varname := mkline.Varname()
		value := mkline.Value()
		if varname == "TOOLS_CREATE" && (value == "[" || matches(value, `^?[-\w.]+$`)) {
			tr.Register(value, mkline)

		} else if m, toolname := match1(varname, `^_TOOLS_VARNAME\.([-\w.]+|\[)$`); m {
			tr.RegisterVarname(toolname, value, mkline)

		} else if m, toolname = match1(varname, `^(?:TOOLS_PATH|_TOOLS_DEPMETHOD)\.([-\w.]+|\[)$`); m {
			tr.Register(toolname, mkline)

		} else if m, toolname = match1(varname, `^_TOOLS\.(.*)`); m {
			tr.Register(toolname, mkline)
			for _, tool := range splitOnSpace(value) {
				tr.Register(tool, mkline)
			}
		}
	}
}

func (tr *ToolRegistry) ByVarname(varname string) *Tool {
	return tr.byVarname[varname]
}

func (tr *ToolRegistry) ByName(name string) *Tool {
	return tr.byName[name]
}

func (tr *ToolRegistry) ForEach(action func(tool *Tool)) {
	for _, tool := range tr.byName {
		action(tool)
	}
}

func (tr *ToolRegistry) validateToolName(toolName string, mkline MkLine) {
	if toolName != "echo -n" && !matches(toolName, `^([-a-z0-9.]+|\[)$`) {
		mkline.Errorf("Invalid tool name %q.", toolName)
	}
}
