package main

import (
	"path"
	"strings"
)

// Vartype is a combination of a data type and a permission specification.
// See vardefs.go for examples, and vartypecheck.go for the implementation.
type Vartype struct {
	kindOfList KindOfList
	basicType  *BasicType
	aclEntries []ACLEntry
	guessed    bool
}

type KindOfList uint8

const (
	lkNone  KindOfList = iota // Plain data type
	lkSpace                   // List entries are separated by whitespace; used in .for loops.
	lkShell                   // List entries are shell words; used in the :M, :S modifiers.
)

type ACLEntry struct {
	glob        string // Examples: "Makefile", "*.mk"
	permissions ACLPermissions
}

type ACLPermissions uint8

const (
	aclpSet         ACLPermissions = 1 << iota // VAR = value
	aclpSetDefault                             // VAR ?= value
	aclpAppend                                 // VAR += value
	aclpUseLoadtime                            // OTHER := ${VAR}, OTHER != ${VAR}
	aclpUse                                    // OTHER = ${VAR}
	aclpUnknown
	aclpAll        = aclpAppend | aclpSetDefault | aclpSet | aclpUseLoadtime | aclpUse
	aclpAllRuntime = aclpAppend | aclpSetDefault | aclpSet | aclpUse
	aclpAllWrite   = aclpSet | aclpSetDefault | aclpAppend
	aclpAllRead    = aclpUseLoadtime | aclpUse
)

func (perms ACLPermissions) Contains(subset ACLPermissions) bool {
	return perms&subset == subset
}

func (perms ACLPermissions) String() string {
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

func (perms ACLPermissions) HumanString() string {
	result := "" +
		ifelseStr(perms.Contains(aclpSet), "set, ", "") +
		ifelseStr(perms.Contains(aclpSetDefault), "given a default value, ", "") +
		ifelseStr(perms.Contains(aclpAppend), "appended to, ", "") +
		ifelseStr(perms.Contains(aclpUseLoadtime), "used at load time, ", "") +
		ifelseStr(perms.Contains(aclpUse), "used, ", "")
	return strings.TrimRight(result, ", ")
}

func (vt *Vartype) EffectivePermissions(basename string) ACLPermissions {
	for _, aclEntry := range vt.aclEntries {
		if m, _ := path.Match(aclEntry.glob, basename); m {
			return aclEntry.permissions
		}
	}
	return aclpUnknown
}

// Union returns the union of all possible permissions.
// This can be used to check whether a variable may be defined or used
// at all, or if it is read-only.
func (vt *Vartype) Union() ACLPermissions {
	var permissions ACLPermissions
	for _, aclEntry := range vt.aclEntries {
		permissions |= aclEntry.permissions
	}
	return permissions
}

func (vt *Vartype) AllowedFiles(perms ACLPermissions) string {
	files := make([]string, 0, len(vt.aclEntries))
	for _, aclEntry := range vt.aclEntries {
		if aclEntry.permissions.Contains(perms) {
			files = append(files, aclEntry.glob)
		}
	}
	return strings.Join(files, ", ")
}

// IsConsideredList returns whether the type is considered a shell list.
// This distinction between "real lists" and "considered a list" makes
// the implementation of checklineMkVartype easier.
func (vt *Vartype) IsConsideredList() bool {
	switch vt.kindOfList {
	case lkShell:
		return true
	case lkSpace:
		return false
	}
	switch vt.basicType {
	case BtAwkCommand, BtSedCommands, BtShellCommand, BtShellCommands, BtLicense, BtConfFiles:
		return true
	}
	return false
}

func (vt *Vartype) MayBeAppendedTo() bool {
	return vt.kindOfList != lkNone || vt.IsConsideredList() || vt.basicType == BtComment
}

func (vt *Vartype) String() string {
	listPrefix := [...]string{"", "SpaceList of ", "ShellList of "}[vt.kindOfList]
	guessedSuffix := ifelseStr(vt.guessed, " (guessed)", "")
	return listPrefix + vt.basicType.name + guessedSuffix
}

func (vt *Vartype) IsShell() bool {
	switch vt.basicType {
	case BtCFlag, // Subtype of ShellWord
		BtLdFlag, // Subtype of ShellWord
		BtSedCommands,
		BtShellCommand,
		BtShellCommands,
		BtShellWord:
		return true
	}
	return false
}

// IsBasicSafe returns whether the basic vartype consists only of
// characters that don't need escaping in most contexts, like A-Za-z0-9-_.
func (vt *Vartype) IsBasicSafe() bool {
	switch vt.basicType {
	case BtBuildlinkDepmethod,
		BtCategory,
		BtDistSuffix,
		BtEmulPlatform,
		BtFileMode,
		BtFileName,
		BtIdentifier,
		BtInteger,
		BtMachineGnuPlatform,
		BtMachinePlatform,
		BtOption,
		BtPathname,
		BtPerl5Packlist,
		BtPkgName,
		BtPkgOptionsVar,
		BtPkgPath,
		BtPkgRevision,
		BtPrefixPathname,
		BtPythonDependency,
		BtRelativePkgDir,
		BtRelativePkgPath,
		BtStage,
		BtTool, // Sometimes contains a colon, but that should be ok.
		BtUserGroupName,
		BtVersion,
		BtWrkdirSubdirectory,
		BtYesNo,
		BtYesNoIndirectly:
		return true
	}
	return false
}

func (vt *Vartype) IsPlainString() bool {
	switch vt.basicType {
	case BtComment, BtMessage, BtUnknown:
		return true
	}
	return false
}

type BasicType struct {
	name    string
	checker func(*VartypeCheck)
}

func (bt *BasicType) IsEnum() bool {
	return hasPrefix(bt.name, "enum: ")
}
func (bt *BasicType) HasEnum(value string) bool {
	return !contains(value, " ") && contains(bt.name, " "+value+" ")
}
func (bt *BasicType) AllowedEnums() string {
	return bt.name[6 : len(bt.name)-1]
}

var (
	BtAwkCommand             = &BasicType{"AwkCommand", (*VartypeCheck).AwkCommand}
	BtBasicRegularExpression = &BasicType{"BasicRegularExpression", (*VartypeCheck).BasicRegularExpression}
	BtBuildlinkDepmethod     = &BasicType{"BuildlinkDepmethod", (*VartypeCheck).BuildlinkDepmethod}
	BtCategory               = &BasicType{"Category", (*VartypeCheck).Category}
	BtCFlag                  = &BasicType{"CFlag", (*VartypeCheck).CFlag}
	BtComment                = &BasicType{"Comment", (*VartypeCheck).Comment}
	BtConfFiles              = &BasicType{"ConfFiles", (*VartypeCheck).ConfFiles}
	BtDependency             = &BasicType{"Dependency", (*VartypeCheck).Dependency}
	BtDependencyWithPath     = &BasicType{"DependencyWithPath", (*VartypeCheck).DependencyWithPath}
	BtDistSuffix             = &BasicType{"DistSuffix", (*VartypeCheck).DistSuffix}
	BtEmulPlatform           = &BasicType{"EmulPlatform", (*VartypeCheck).EmulPlatform}
	BtFetchURL               = &BasicType{"FetchURL", (*VartypeCheck).FetchURL}
	BtFileName               = &BasicType{"FileName", (*VartypeCheck).FileName}
	BtFileMask               = &BasicType{"FileMask", (*VartypeCheck).FileMask}
	BtFileMode               = &BasicType{"FileMode", (*VartypeCheck).FileMode}
	BtGccReqd                = &BasicType{"GccReqd", (*VartypeCheck).GccReqd}
	BtHomepage               = &BasicType{"Homepage", (*VartypeCheck).Homepage}
	BtIdentifier             = &BasicType{"Identifier", (*VartypeCheck).Identifier}
	BtInteger                = &BasicType{"Integer", (*VartypeCheck).Integer}
	BtLdFlag                 = &BasicType{"LdFlag", (*VartypeCheck).LdFlag}
	BtLicense                = &BasicType{"License", (*VartypeCheck).License}
	BtMachineGnuPlatform     = &BasicType{"MachineGnuPlatform", (*VartypeCheck).MachineGnuPlatform}
	BtMachinePlatform        = &BasicType{"MachinePlatform", (*VartypeCheck).MachinePlatform}
	BtMachinePlatformPattern = &BasicType{"MachinePlatformPattern", (*VartypeCheck).MachinePlatformPattern}
	BtMailAddress            = &BasicType{"MailAddress", (*VartypeCheck).MailAddress}
	BtMessage                = &BasicType{"Message", (*VartypeCheck).Message}
	BtOption                 = &BasicType{"Option", (*VartypeCheck).Option}
	BtPathlist               = &BasicType{"Pathlist", (*VartypeCheck).Pathlist}
	BtPathmask               = &BasicType{"PathMask", (*VartypeCheck).PathMask}
	BtPathname               = &BasicType{"PathName", (*VartypeCheck).PathName}
	BtPerl5Packlist          = &BasicType{"Perl5Packlist", (*VartypeCheck).Perl5Packlist}
	BtPerms                  = &BasicType{"Perms", (*VartypeCheck).Perms}
	BtPkgName                = &BasicType{"Pkgname", (*VartypeCheck).Pkgname}
	BtPkgPath                = &BasicType{"PkgPath", (*VartypeCheck).PkgPath}
	BtPkgOptionsVar          = &BasicType{"PkgOptionsVar", (*VartypeCheck).PkgOptionsVar}
	BtPkgRevision            = &BasicType{"PkgRevision", (*VartypeCheck).PkgRevision}
	BtPrefixPathname         = &BasicType{"PrefixPathname", (*VartypeCheck).PrefixPathname}
	BtPythonDependency       = &BasicType{"PythonDependency", (*VartypeCheck).PythonDependency}
	BtRelativePkgDir         = &BasicType{"RelativePkgDir", (*VartypeCheck).RelativePkgDir}
	BtRelativePkgPath        = &BasicType{"RelativePkgPath", (*VartypeCheck).RelativePkgPath}
	BtRestricted             = &BasicType{"Restricted", (*VartypeCheck).Restricted}
	BtSedCommand             = &BasicType{"SedCommand", (*VartypeCheck).SedCommand}
	BtSedCommands            = &BasicType{"SedCommands", (*VartypeCheck).SedCommands}
	BtShellCommand           = &BasicType{"ShellCommand", nil}
	BtShellCommands          = &BasicType{"ShellCommands", nil}
	BtShellWord              = &BasicType{"ShellWord", nil}
	BtStage                  = &BasicType{"Stage", (*VartypeCheck).Stage}
	BtTool                   = &BasicType{"Tool", (*VartypeCheck).Tool}
	BtUnknown                = &BasicType{"Unknown", (*VartypeCheck).Unknown}
	BtURL                    = &BasicType{"URL", (*VartypeCheck).URL}
	BtUserGroupName          = &BasicType{"UserGroupName", (*VartypeCheck).UserGroupName}
	BtVariableName           = &BasicType{"VariableName", (*VartypeCheck).VariableName}
	BtVersion                = &BasicType{"Version", (*VartypeCheck).Version}
	BtWrapperReorder         = &BasicType{"WrapperReorder", (*VartypeCheck).WrapperReorder}
	BtWrapperTransform       = &BasicType{"WrapperTransform", (*VartypeCheck).WrapperTransform}
	BtWrkdirSubdirectory     = &BasicType{"WrkdirSubdirectory", (*VartypeCheck).WrkdirSubdirectory}
	BtWrksrcSubdirectory     = &BasicType{"WrksrcSubdirectory", (*VartypeCheck).WrksrcSubdirectory}
	BtYes                    = &BasicType{"Yes", (*VartypeCheck).Yes}
	BtYesNo                  = &BasicType{"YesNo", (*VartypeCheck).YesNo}
	BtYesNoIndirectly        = &BasicType{"YesNoIndirectly", (*VartypeCheck).YesNoIndirectly}
)

func init() { // Necessary due to circular dependency
	BtShellCommand.checker = (*VartypeCheck).ShellCommand
	BtShellCommands.checker = (*VartypeCheck).ShellCommands
	BtShellWord.checker = (*VartypeCheck).ShellWord
}
