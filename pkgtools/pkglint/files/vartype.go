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
	guessed    Guessed
}

type KindOfList int

const (
	lkNone  KindOfList = iota // Plain data type
	lkSpace                   // List entries are separated by whitespace; used in .for loops.
	lkShell                   // List entries are shell words; used in the :M, :S modifiers.
)

type AclEntry struct {
	glob        string // Examples: "Makefile", "*.mk"
	permissions string // Some of: "a"ppend, "d"efault, "s"et; "p"reprocessing, "u"se
}

// Whether the type definition is guessed (based on the variable name)
// or explicitly defined (see vardefs.go).
type Guessed bool

const (
	guNotGuessed Guessed = false
	guGuessed    Guessed = true
)

// The allowed actions in this file, or "?" if unknown.
func (vt *Vartype) effectivePermissions(fname string) string {
	for _, aclEntry := range vt.aclEntries {
		if m, _ := path.Match(aclEntry.glob, path.Base(fname)); m {
			return aclEntry.permissions
		}
	}
	return "?"
}

func ReadableVartypePermissions(perms string) string {
	result := ""
	for _, c := range perms {
		switch c {
		case 'a':
			result += "append, "
		case 'd':
			result += "default, "
		case 'p':
			result += "preprocess, "
		case 's':
			result += "set, "
		case 'u':
			result += "runtime, "
		case '?':
			result += "unknown, "
		}
	}
	return strings.TrimRight(result, ", ")
}

// Returns the union of all possible permissions. This can be used to
// check whether a variable may be defined or used at all, or if it is
// read-only.
func (vt *Vartype) union() string {
	var permissions string
	for _, aclEntry := range vt.aclEntries {
		permissions += aclEntry.permissions
	}
	return permissions
}

// Returns whether the type is considered a shell list.
// This distinction between “real lists” and “considered a list” makes
// the implementation of checklineMkVartype easier.
func (vt *Vartype) isConsideredList() bool {
	switch vt.kindOfList {
	case lkShell:
		return true
	case lkSpace:
		return false
	}
	switch vt.checker {
	case CheckvarSedCommands, CheckvarShellCommand:
		return true
	}
	return false
}

func (vt *Vartype) mayBeAppendedTo() bool {
	return vt.kindOfList != lkNone ||
		vt.checker == CheckvarAwkCommand ||
		vt.checker == CheckvarSedCommands
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
	return !matches(value, `\s`) && contains(vc.name, " "+value+" ")
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
	CheckvarPlatformTriple         = &VarChecker{"PlatformTriple", (*VartypeCheck).PlatformTriple}
	CheckvarPrefixPathname         = &VarChecker{"PrefixPathname", (*VartypeCheck).PrefixPathname}
	CheckvarPythonDependency       = &VarChecker{"PythonDependency", (*VartypeCheck).PythonDependency}
	CheckvarRelativePkgDir         = &VarChecker{"RelativePkgDir", (*VartypeCheck).RelativePkgDir}
	CheckvarRelativePkgPath        = &VarChecker{"RelativePkgPath", (*VartypeCheck).RelativePkgPath}
	CheckvarRestricted             = &VarChecker{"Restricted", (*VartypeCheck).Restricted}
	CheckvarSedCommand             = &VarChecker{"SedCommand", (*VartypeCheck).SedCommand}
	CheckvarSedCommands            = &VarChecker{"SedCommands", nil}
	CheckvarShellCommand           = &VarChecker{"ShellCommand", nil}
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
	CheckvarShellWord.checker = (*VartypeCheck).ShellWord
}
