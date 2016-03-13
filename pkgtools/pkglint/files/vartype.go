package main

import (
	"path"
	"strings"
)

// Vartype is a combination of a data type and a permission specification.
// See vardefs.go for examples, and vartypecheck.go for the implementation.
type Vartype struct {
	kindOfList KindOfList
	checker    *VarChecker
	aclEntries []AclEntry
	guessed    bool
}

type KindOfList uint8

const (
	lkNone  KindOfList = iota // Plain data type
	lkSpace                   // List entries are separated by whitespace; used in .for loops.
	lkShell                   // List entries are shell words; used in the :M, :S modifiers.
)

type AclEntry struct {
	glob        string // Examples: "Makefile", "*.mk"
	permissions AclPermissions
}

type AclPermissions uint8

const (
	aclpSet         AclPermissions = 1 << iota // VAR = value
	aclpSetDefault                             // VAR ?= value
	aclpAppend                                 // VAR += value
	aclpUseLoadtime                            // OTHER := ${VAR}, OTHER != ${VAR}
	aclpUse                                    // OTHER = ${VAR}
	aclpUnknown
	aclpAll        AclPermissions = aclpAppend | aclpSetDefault | aclpSet | aclpUseLoadtime | aclpUse
	aclpAllRuntime AclPermissions = aclpAppend | aclpSetDefault | aclpSet | aclpUse
	aclpAllWrite   AclPermissions = aclpSet | aclpSetDefault | aclpAppend
	aclpAllRead    AclPermissions = aclpUseLoadtime | aclpUse
)

func (perms AclPermissions) Contains(subset AclPermissions) bool {
	return perms&subset == subset
}

func (perms AclPermissions) String() string {
	if perms == 0 {
		return "none"
	}
	result := "" +
		ifelseStr(perms.Contains(aclpSet), "set, ", "") +
		ifelseStr(perms.Contains(aclpSetDefault), "set-default, ", "") +
		ifelseStr(perms.Contains(aclpAppend), "append, ", "") +
		ifelseStr(perms.Contains(aclpUseLoadtime), "use-loadtime, ", "") +
		ifelseStr(perms.Contains(aclpUse), "use, ", "") +
		ifelseStr(perms.Contains(aclpUnknown), "unknown, ", "")
	return strings.TrimRight(result, ", ")
}

func (perms AclPermissions) HumanString() string {
	result := "" +
		ifelseStr(perms.Contains(aclpSet), "set, ", "") +
		ifelseStr(perms.Contains(aclpSetDefault), "given a default value, ", "") +
		ifelseStr(perms.Contains(aclpAppend), "appended to, ", "") +
		ifelseStr(perms.Contains(aclpUseLoadtime), "used at load time, ", "") +
		ifelseStr(perms.Contains(aclpUse), "used, ", "")
	return strings.TrimRight(result, ", ")
}

func (vt *Vartype) EffectivePermissions(fname string) AclPermissions {
	for _, aclEntry := range vt.aclEntries {
		if m, _ := path.Match(aclEntry.glob, path.Base(fname)); m {
			return aclEntry.permissions
		}
	}
	return aclpUnknown
}

// Returns the union of all possible permissions. This can be used to
// check whether a variable may be defined or used at all, or if it is
// read-only.
func (vt *Vartype) Union() AclPermissions {
	var permissions AclPermissions
	for _, aclEntry := range vt.aclEntries {
		permissions |= aclEntry.permissions
	}
	return permissions
}

func (vt *Vartype) AllowedFiles(perms AclPermissions) string {
	files := make([]string, 0, len(vt.aclEntries))
	for _, aclEntry := range vt.aclEntries {
		if aclEntry.permissions.Contains(perms) {
			files = append(files, aclEntry.glob)
		}
	}
	return strings.Join(files, ", ")
}

// Returns whether the type is considered a shell list.
// This distinction between “real lists” and “considered a list” makes
// the implementation of checklineMkVartype easier.
func (vt *Vartype) IsConsideredList() bool {
	switch vt.kindOfList {
	case lkShell:
		return true
	case lkSpace:
		return false
	}
	switch vt.checker {
	case CheckvarAwkCommand, CheckvarSedCommands, CheckvarShellCommand, CheckvarShellCommands:
		return true
	}
	return false
}

func (vt *Vartype) MayBeAppendedTo() bool {
	return vt.kindOfList != lkNone || vt.IsConsideredList()
}

func (vt *Vartype) String() string {
	switch vt.kindOfList {
	case lkNone:
		return vt.checker.name
	case lkSpace:
		return "SpaceList of " + vt.checker.name
	case lkShell:
		return "ShellList of " + vt.checker.name
	default:
		panic("Unknown list type")
	}
}

type VarChecker struct {
	name    string
	checker func(*VartypeCheck)
}

func (vc *VarChecker) IsEnum() bool {
	return hasPrefix(vc.name, "enum: ")
}
func (vc *VarChecker) HasEnum(value string) bool {
	return !contains(value, " ") && contains(vc.name, " "+value+" ")
}
func (vc *VarChecker) AllowedEnums() string {
	return vc.name[6 : len(vc.name)-1]
}

var (
	CheckvarAwkCommand             = &VarChecker{"AwkCommand", (*VartypeCheck).AwkCommand}
	CheckvarBasicRegularExpression = &VarChecker{"BasicRegularExpression", (*VartypeCheck).BasicRegularExpression}
	CheckvarBuildlinkDepmethod     = &VarChecker{"BuildlinkDepmethod", (*VartypeCheck).BuildlinkDepmethod}
	CheckvarCategory               = &VarChecker{"Category", (*VartypeCheck).Category}
	CheckvarCFlag                  = &VarChecker{"CFlag", (*VartypeCheck).CFlag}
	CheckvarComment                = &VarChecker{"Comment", (*VartypeCheck).Comment}
	CheckvarDependency             = &VarChecker{"Dependency", (*VartypeCheck).Dependency}
	CheckvarDependencyWithPath     = &VarChecker{"DependencyWithPath", (*VartypeCheck).DependencyWithPath}
	CheckvarDistSuffix             = &VarChecker{"DistSuffix", (*VartypeCheck).DistSuffix}
	CheckvarEmulPlatform           = &VarChecker{"EmulPlatform", (*VartypeCheck).EmulPlatform}
	CheckvarFetchURL               = &VarChecker{"FetchURL", (*VartypeCheck).FetchURL}
	CheckvarFilename               = &VarChecker{"Filename", (*VartypeCheck).Filename}
	CheckvarFilemask               = &VarChecker{"Filemask", (*VartypeCheck).Filemask}
	CheckvarFileMode               = &VarChecker{"FileMode", (*VartypeCheck).FileMode}
	CheckvarIdentifier             = &VarChecker{"Identifier", (*VartypeCheck).Identifier}
	CheckvarInteger                = &VarChecker{"Integer", (*VartypeCheck).Integer}
	CheckvarLdFlag                 = &VarChecker{"LdFlag", (*VartypeCheck).LdFlag}
	CheckvarLicense                = &VarChecker{"License", (*VartypeCheck).License}
	CheckvarMailAddress            = &VarChecker{"MailAddress", (*VartypeCheck).MailAddress}
	CheckvarMessage                = &VarChecker{"Message", (*VartypeCheck).Message}
	CheckvarOption                 = &VarChecker{"Option", (*VartypeCheck).Option}
	CheckvarPathlist               = &VarChecker{"Pathlist", (*VartypeCheck).Pathlist}
	CheckvarPathmask               = &VarChecker{"Pathmask", (*VartypeCheck).Pathmask}
	CheckvarPathname               = &VarChecker{"Pathname", (*VartypeCheck).Pathname}
	CheckvarPerl5Packlist          = &VarChecker{"Perl5Packlist", (*VartypeCheck).Perl5Packlist}
	CheckvarPkgName                = &VarChecker{"PkgName", (*VartypeCheck).PkgName}
	CheckvarPkgPath                = &VarChecker{"PkgPath", (*VartypeCheck).PkgPath}
	CheckvarPkgOptionsVar          = &VarChecker{"PkgOptionsVar", (*VartypeCheck).PkgOptionsVar}
	CheckvarPkgRevision            = &VarChecker{"PkgRevision", (*VartypeCheck).PkgRevision}
	CheckvarPlatformPattern        = &VarChecker{"PlatformPattern", (*VartypeCheck).PlatformPattern}
	CheckvarPrefixPathname         = &VarChecker{"PrefixPathname", (*VartypeCheck).PrefixPathname}
	CheckvarPythonDependency       = &VarChecker{"PythonDependency", (*VartypeCheck).PythonDependency}
	CheckvarRelativePkgDir         = &VarChecker{"RelativePkgDir", (*VartypeCheck).RelativePkgDir}
	CheckvarRelativePkgPath        = &VarChecker{"RelativePkgPath", (*VartypeCheck).RelativePkgPath}
	CheckvarRestricted             = &VarChecker{"Restricted", (*VartypeCheck).Restricted}
	CheckvarSedCommand             = &VarChecker{"SedCommand", (*VartypeCheck).SedCommand}
	CheckvarSedCommands            = &VarChecker{"SedCommands", nil}
	CheckvarShellCommand           = &VarChecker{"ShellCommand", nil}
	CheckvarShellCommands          = &VarChecker{"ShellCommands", nil}
	CheckvarShellWord              = &VarChecker{"ShellWord", nil}
	CheckvarStage                  = &VarChecker{"Stage", (*VartypeCheck).Stage}
	CheckvarString                 = &VarChecker{"String", (*VartypeCheck).String}
	CheckvarTool                   = &VarChecker{"Tool", (*VartypeCheck).Tool}
	CheckvarUnchecked              = &VarChecker{"Unchecked", (*VartypeCheck).Unchecked}
	CheckvarURL                    = &VarChecker{"URL", (*VartypeCheck).URL}
	CheckvarUserGroupName          = &VarChecker{"UserGroupName", (*VartypeCheck).UserGroupName}
	CheckvarVarname                = &VarChecker{"Varname", (*VartypeCheck).Varname}
	CheckvarVersion                = &VarChecker{"Version", (*VartypeCheck).Version}
	CheckvarWrapperReorder         = &VarChecker{"WrapperReorder", (*VartypeCheck).WrapperReorder}
	CheckvarWrapperTransform       = &VarChecker{"WrapperTransform", (*VartypeCheck).WrapperTransform}
	CheckvarWrkdirSubdirectory     = &VarChecker{"WrkdirSubdirectory", (*VartypeCheck).WrkdirSubdirectory}
	CheckvarWrksrcSubdirectory     = &VarChecker{"WrksrcSubdirectory", (*VartypeCheck).WrksrcSubdirectory}
	CheckvarYes                    = &VarChecker{"Yes", (*VartypeCheck).Yes}
	CheckvarYesNo                  = &VarChecker{"YesNo", (*VartypeCheck).YesNo}
	CheckvarYesNoIndirectly        = &VarChecker{"YesNoIndirectly", (*VartypeCheck).YesNoIndirectly}
)

func init() { // Necessary due to circular dependency
	CheckvarSedCommands.checker = (*VartypeCheck).SedCommands
	CheckvarShellCommand.checker = (*VartypeCheck).ShellCommand
	CheckvarShellCommands.checker = (*VartypeCheck).ShellCommands
	CheckvarShellWord.checker = (*VartypeCheck).ShellWord
}
