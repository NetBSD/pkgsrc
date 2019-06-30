package pkglint

import (
	"path"
	"strings"
)

// Vartype is a combination of a data type and a permission specification.
// See vardefs.go for examples, and vartypecheck.go for the implementation.
type Vartype struct {
	basicType  *BasicType
	options    vartypeOptions
	aclEntries []ACLEntry
}

func NewVartype(basicType *BasicType, options vartypeOptions, aclEntries ...ACLEntry) *Vartype {
	return &Vartype{basicType, options, aclEntries}
}

type vartypeOptions uint8

const (
	// List is a compound type, consisting of several space-separated elements.
	// Elements can have embedded spaces by enclosing them in double or single
	// quotes, like in the shell.
	//
	// These lists are used in the :M, :S modifiers, in .for loops,
	// and as lists of arbitrary things.
	List vartypeOptions = 1 << iota

	Guessed
	PackageSettable
	UserSettable
	SystemProvided
	CommandLineProvided

	// NeedsRationale marks variables that should always contain a comment
	// describing why they are set. Typical examples are NOT_FOR_* variables.
	NeedsRationale

	NoVartypeOptions = 0
)

type ACLEntry struct {
	matcher     *pathMatcher
	permissions ACLPermissions
}

func NewACLEntry(glob string, permissions ACLPermissions) ACLEntry {
	return ACLEntry{newPathMatcher(glob), permissions}
}

type ACLPermissions uint8

const (
	aclpSet         ACLPermissions = 1 << iota // VAR = value
	aclpSetDefault                             // VAR ?= value
	aclpAppend                                 // VAR += value
	aclpUseLoadtime                            // OTHER := ${VAR}, OTHER != ${VAR}
	aclpUse                                    // OTHER = ${VAR}

	aclpNone ACLPermissions = 0

	aclpAllWrite   = aclpSet | aclpSetDefault | aclpAppend
	aclpAllRead    = aclpUseLoadtime | aclpUse
	aclpAll        = aclpAllWrite | aclpAllRead
	aclpAllRuntime = aclpAll &^ aclpUseLoadtime
)

// Contains returns whether each permission of the given subset is
// contained in this permission set.
func (perms ACLPermissions) Contains(subset ACLPermissions) bool {
	return perms&subset == subset
}

func (perms ACLPermissions) String() string {
	if perms == 0 {
		return "none"
	}
	return joinSkipEmpty(", ",
		ifelseStr(perms.Contains(aclpSet), "set", ""),
		ifelseStr(perms.Contains(aclpSetDefault), "set-default", ""),
		ifelseStr(perms.Contains(aclpAppend), "append", ""),
		ifelseStr(perms.Contains(aclpUseLoadtime), "use-loadtime", ""),
		ifelseStr(perms.Contains(aclpUse), "use", ""))
}

func (perms ACLPermissions) HumanString() string {
	return joinSkipEmptyOxford("or",
		ifelseStr(perms.Contains(aclpSet), "set", ""),
		ifelseStr(perms.Contains(aclpSetDefault), "given a default value", ""),
		ifelseStr(perms.Contains(aclpAppend), "appended to", ""),
		ifelseStr(perms.Contains(aclpUseLoadtime), "used at load time", ""),
		ifelseStr(perms.Contains(aclpUse), "used", ""))
}

func (vt *Vartype) List() bool                { return vt.options&List != 0 }
func (vt *Vartype) Guessed() bool             { return vt.options&Guessed != 0 }
func (vt *Vartype) PackageSettable() bool     { return vt.options&PackageSettable != 0 }
func (vt *Vartype) UserSettable() bool        { return vt.options&UserSettable != 0 }
func (vt *Vartype) SystemProvided() bool      { return vt.options&SystemProvided != 0 }
func (vt *Vartype) CommandLineProvided() bool { return vt.options&CommandLineProvided != 0 }
func (vt *Vartype) NeedsRationale() bool      { return vt.options&NeedsRationale != 0 }

func (vt *Vartype) EffectivePermissions(basename string) ACLPermissions {
	for _, aclEntry := range vt.aclEntries {
		if aclEntry.matcher.matches(basename) {
			return aclEntry.permissions
		}
	}
	return aclpNone
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

// AlternativeFiles lists the file patterns in which all of the given
// permissions are allowed, readily formatted to be used in a diagnostic.
//
// If the permission is allowed nowhere, an empty string is returned.
func (vt *Vartype) AlternativeFiles(perms ACLPermissions) string {
	var pos []string
	var neg []string

	merge := func(slice []string) []string {
		di := 0
		for si, early := range slice {
			redundant := false
			for _, late := range slice[si+1:] {
				matched, err := path.Match(late, early)
				assertNil(err, "path.Match")
				if matched {
					redundant = true
					break
				}
			}
			if !redundant {
				slice[di] = early
				di++
			}
		}
		return slice[:di]
	}

	for _, aclEntry := range vt.aclEntries {
		if aclEntry.permissions.Contains(perms) {
			pos = append(pos, aclEntry.matcher.originalPattern)
		} else {
			neg = append(neg, aclEntry.matcher.originalPattern)
		}
	}

	if len(neg) == 0 {
		pos = merge(pos)
	}
	if len(pos) == 0 {
		neg = merge(neg)
	}

	positive := joinSkipEmptyCambridge("or", pos...)
	if positive == "" {
		return ""
	}

	negative := joinSkipEmptyCambridge("or", neg...)
	if negative == "" {
		return positive
	}

	if negative == "*" {
		return positive + " only"
	}

	return positive + ", but not " + negative
}

func (vt *Vartype) MayBeAppendedTo() bool {
	if vt.List() {
		return true
	}

	switch vt.basicType {
	case BtAwkCommand, BtSedCommands, BtShellCommand, BtShellCommands, BtConfFiles:
		return true
	case BtComment, BtLicense:
		return true
	}
	return false
}

func (vt *Vartype) String() string {
	var opts []string
	if vt.List() {
		opts = append(opts, "list")
	}
	if vt.Guessed() {
		opts = append(opts, "guessed")
	}
	if vt.PackageSettable() {
		opts = append(opts, "package-settable")
	}
	if vt.UserSettable() {
		opts = append(opts, "user-settable")
	}
	if vt.SystemProvided() {
		opts = append(opts, "system-provided")
	}
	if vt.CommandLineProvided() {
		opts = append(opts, "command-line-provided")
	}

	optsSuffix := ""
	if len(opts) > 0 {
		optsSuffix = " (" + strings.Join(opts, ", ") + ")"
	}

	return vt.basicType.name + optsSuffix
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

// NeedsQ returns whether variables of this type need the :Q
// modifier to be safely embedded in other variables or shell programs.
//
// Variables that can consists only of characters like A-Za-z0-9-._
// don't need the :Q modifier. All others do, for safety reasons.
func (bt *BasicType) NeedsQ() bool {
	switch bt {
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
		return false
	}
	return !bt.IsEnum()
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

// TODO: Try to implement BasicType.PossibleChars()
// TODO: Try to implement BasicType.CanBeEmpty()
// TODO: Try to implement BasicType.PossibleWords() / PossibleValues()

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
	BtFileName               = &BasicType{"Filename", (*VartypeCheck).Filename}
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
	BtPathname               = &BasicType{"Pathname", (*VartypeCheck).Pathname}
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
	BtVariableNamePattern    = &BasicType{"VariableNamePattern", (*VartypeCheck).VariableNamePattern}
	BtVersion                = &BasicType{"Version", (*VartypeCheck).Version}
	BtWrapperReorder         = &BasicType{"WrapperReorder", (*VartypeCheck).WrapperReorder}
	BtWrapperTransform       = &BasicType{"WrapperTransform", (*VartypeCheck).WrapperTransform}
	BtWrkdirSubdirectory     = &BasicType{"WrkdirSubdirectory", (*VartypeCheck).WrkdirSubdirectory}
	BtWrksrcSubdirectory     = &BasicType{"WrksrcSubdirectory", (*VartypeCheck).WrksrcSubdirectory}
	BtYes                    = &BasicType{"Yes", (*VartypeCheck).Yes}
	BtYesNo                  = &BasicType{"YesNo", (*VartypeCheck).YesNo}
	BtYesNoIndirectly        = &BasicType{"YesNoIndirectly", (*VartypeCheck).YesNoIndirectly}

	btForLoop = &BasicType{".for loop", nil /* never called */}
)

// Necessary due to circular dependencies between the checkers.
//
// The Go compiler is stricter than absolutely necessary for this particular case.
// The following methods are only referred to but not invoked during initialization.
func init() {
	BtShellCommand.checker = (*VartypeCheck).ShellCommand
	BtShellCommands.checker = (*VartypeCheck).ShellCommands
	BtShellWord.checker = (*VartypeCheck).ShellWord
}
