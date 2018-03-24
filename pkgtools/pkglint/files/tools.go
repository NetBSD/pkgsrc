package main

import (
	"netbsd.org/pkglint/trace"
	"sort"
)

// See `mk/tools/`.
type Tool struct {
	Name             string // e.g. "sed", "gzip"
	Varname          string // e.g. "SED", "GZIP_CMD"
	MustUseVarForm   bool   // True for `echo`, because of many differing implementations.
	Predefined       bool   // This tool is used by the pkgsrc infrastructure, therefore the package does not need to add it to `USE_TOOLS` explicitly.
	UsableAtLoadtime bool   // May be used after including `bsd.prefs.mk`.
}

type ToolRegistry struct {
	byName    map[string]*Tool
	byVarname map[string]*Tool
}

func NewToolRegistry() ToolRegistry {
	return ToolRegistry{make(map[string]*Tool), make(map[string]*Tool)}
}

func (tr *ToolRegistry) Register(toolname string) *Tool {
	tool := tr.byName[toolname]
	if tool == nil {
		tool = &Tool{Name: toolname}
		tr.byName[toolname] = tool
	}
	return tool
}

func (tr *ToolRegistry) RegisterVarname(toolname, varname string) *Tool {
	tool := tr.Register(toolname)
	tool.Varname = varname
	tr.byVarname[varname] = tool
	return tool
}

func (tr *ToolRegistry) RegisterTool(tool *Tool) {
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

func (tr *ToolRegistry) ParseToolLine(line Line) {
	if m, commented, varname, _, _, _, value, _, _ := MatchVarassign(line.Text); m {
		if commented {
			return
		}
		if varname == "TOOLS_CREATE" && (value == "[" || matches(value, `^?[-\w.]+$`)) {
			tr.Register(value)

		} else if m, toolname := match1(varname, `^_TOOLS_VARNAME\.([-\w.]+|\[)$`); m {
			tr.RegisterVarname(toolname, value)

		} else if m, toolname := match1(varname, `^(?:TOOLS_PATH|_TOOLS_DEPMETHOD)\.([-\w.]+|\[)$`); m {
			tr.Register(toolname)

		} else if m, toolname := match1(varname, `_TOOLS\.(.*)`); m {
			tr.Register(toolname)
			for _, tool := range splitOnSpace(value) {
				tr.Register(tool)
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
