package pkglint

import (
	"path"
	"sort"
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

type vartypeOptions uint16

const (
	// List is a compound type, consisting of several space-separated elements.
	// Elements can have embedded spaces by enclosing them in double or single
	// quotes, like in the shell.
	//
	// These lists are used in the :M, :S modifiers, in .for loops,
	// and as lists of arbitrary things.
	List vartypeOptions = 1 << iota

	// Guessed means that the variable is not defined by the pkgsrc
	// infrastructure.
	// It follows the common naming convention, therefore its type can be guessed.
	// Sometimes, with files and paths, this leads to wrong decisions.
	Guessed

	// PackageSettable means that the variable can, or in some cases must,
	// be defined by the package.
	// For several of these variables, the pkgsrc infrastructure provides
	// a reasonable default value, either in bsd.prefs.mk or in bsd.pkg.mk.
	PackageSettable

	// UserSettable means that the variable can be defined by the pkgsrc
	// user in mk.conf.
	// Its value is available at load time after bsd.prefs.mk has been included.
	UserSettable

	// SystemProvided means that this variable is provided by either the
	// pkgsrc infrastructure in mk/*, or by <sys.mk>, which is included
	// at the very beginning.
	//
	// TODO: Clearly distinguish between:
	//  * sys.mk
	//  * bsd.prefs.mk
	//  * bsd.pkg.mk
	//  * other parts of the pkgsrc infrastructure
	//  * environment variables
	//  Having all these possibilities as boolean flags is probably not
	//  expressive enough. This is related to the scope and lifetime of
	//  variables and should be modelled separately.
	//
	// See DefinedIfInScope.
	SystemProvided

	// CommandLineProvided means that this variable may be provided in the
	// command line by the pkgsrc user when building a package.
	//
	// Since the values of these variables are not recorded in any file,
	// they must not influence the generated binary packages.
	//
	// See UserSettable.
	CommandLineProvided

	// NeedsRationale marks variables that should always contain a comment
	// describing why they are set. Typical examples are NOT_FOR_* variables.
	NeedsRationale

	// OnePerLine means that when something is appended to this variable,
	// each additional value should be on a line of its own.
	OnePerLine

	// AlwaysInScope is true when the variable is always available.
	//
	// One possibility is that the variable is defined in <sys.mk>,
	// which means that its value is loaded even before the package
	// Makefile is parsed.
	//
	// Another possibility is that the variable is local to a target,
	// such as .TARGET or .IMPSRC.
	//
	// These variables may be used at load time in .if and .for
	// directives even before bsd.prefs.mk is included.
	//
	// XXX: This option is related to the lifetime of the variable.
	//  Other aspects of the lifetime are handled by ACLPermissions,
	//  see aclpUseLoadtime.
	AlwaysInScope

	// DefinedIfInScope is true if the variable is guaranteed to be
	// defined, provided that it is in scope.
	//
	// This means the variable can be used in expressions like ${VAR}
	// without having to add the :U modifier like in ${VAR:U}.
	//
	// This option is independent of the lifetime of the variable,
	// it merely expresses "if the variable is in scope, it is defined".
	// As of December 2019, the lifetime of variables is managed by
	// the ACLPermissions, but is incomplete.
	//
	// TODO: Model the lifetime and scope separately, see SystemProvided.
	//
	// Examples:
	//  MACHINE_PLATFORM (from sys.mk)
	//  PKGPATH (from bsd.prefs.mk)
	//  PREFIX (from bsd.pkg.mk)
	DefinedIfInScope

	// NonemptyIfDefined is true if the variable is guaranteed to be
	// nonempty, provided that the variable is in scope and defined.
	//
	// This is typical for system-provided variables like PKGPATH or
	// MACHINE_PLATFORM, as well as package-settable variables like
	// PKGNAME.
	//
	// This option is independent of the lifetime of the variable,
	// it merely expresses "if the variable is in scope, it is defined".
	// As of December 2019, the lifetime of variables is managed by
	// the ACLPermissions, but is incomplete.
	//
	// TODO: Model the lifetime and scope separately, see SystemProvided.
	//
	// Examples:
	//  MACHINE_PLATFORM (from sys.mk)
	//  PKGPATH (from bsd.prefs.mk)
	//  PREFIX (from bsd.pkg.mk)
	//  PKGNAME (package-settable)
	//  X11_TYPE (user-settable)
	NonemptyIfDefined

	// Unique marks variables where it doesn't make sense to append the same
	// value more than once.
	//
	// A typical example is CATEGORIES.
	Unique

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
		condStr(perms.Contains(aclpSet), "set", ""),
		condStr(perms.Contains(aclpSetDefault), "set-default", ""),
		condStr(perms.Contains(aclpAppend), "append", ""),
		condStr(perms.Contains(aclpUseLoadtime), "use-loadtime", ""),
		condStr(perms.Contains(aclpUse), "use", ""))
}

func (perms ACLPermissions) HumanString() string {
	return joinOxford("or",
		condStr(perms.Contains(aclpSet), "set", ""),
		condStr(perms.Contains(aclpSetDefault), "given a default value", ""),
		condStr(perms.Contains(aclpAppend), "appended to", ""),
		condStr(perms.Contains(aclpUseLoadtime), "used at load time", ""),
		condStr(perms.Contains(aclpUse), "used", ""))
}

func (vt *Vartype) IsList() bool                { return vt.options&List != 0 }
func (vt *Vartype) IsGuessed() bool             { return vt.options&Guessed != 0 }
func (vt *Vartype) IsPackageSettable() bool     { return vt.options&PackageSettable != 0 }
func (vt *Vartype) IsUserSettable() bool        { return vt.options&UserSettable != 0 }
func (vt *Vartype) IsSystemProvided() bool      { return vt.options&SystemProvided != 0 }
func (vt *Vartype) IsCommandLineProvided() bool { return vt.options&CommandLineProvided != 0 }
func (vt *Vartype) NeedsRationale() bool        { return vt.options&NeedsRationale != 0 }
func (vt *Vartype) IsOnePerLine() bool          { return vt.options&OnePerLine != 0 }
func (vt *Vartype) IsAlwaysInScope() bool       { return vt.options&AlwaysInScope != 0 }
func (vt *Vartype) IsDefinedIfInScope() bool    { return vt.options&DefinedIfInScope != 0 }
func (vt *Vartype) IsNonemptyIfDefined() bool   { return vt.options&NonemptyIfDefined != 0 }
func (vt *Vartype) IsUnique() bool              { return vt.options&Unique != 0 }

func (vt *Vartype) EffectivePermissions(basename RelPath) ACLPermissions {
	for _, aclEntry := range vt.aclEntries {
		if aclEntry.matcher.matches(basename.String()) {
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

	positive := joinCambridge("or", pos...)
	if positive == "" {
		return ""
	}

	negative := joinCambridge("or", neg...)
	if negative == "" {
		return positive
	}

	if negative == "*" {
		return positive + " only"
	}

	return positive + ", but not " + negative
}

func (vt *Vartype) MayBeAppendedTo() bool {
	if vt.IsList() {
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
	if vt.IsList() {
		opts = append(opts, "list")
	}
	if vt.IsGuessed() {
		opts = append(opts, "guessed")
	}
	if vt.IsPackageSettable() {
		opts = append(opts, "package-settable")
	}
	if vt.IsUserSettable() {
		opts = append(opts, "user-settable")
	}
	if vt.IsSystemProvided() {
		opts = append(opts, "system-provided")
	}
	if vt.IsCommandLineProvided() {
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
// Variables that can consist only of characters like A-Za-z0-9-._
// don't need the :Q modifier. All others do, for safety reasons.
func (bt *BasicType) NeedsQ() bool {
	switch bt {
	case BtBuildlinkDepmethod,
		BtCategory,
		BtDistSuffix,
		BtEmulPlatform,
		BtFileMode,
		BtFilename,
		BtGitTag,
		BtIdentifierDirect,
		BtIdentifierIndirect,
		BtInteger,
		BtMachineGnuPlatform,
		BtMachinePlatform,
		BtOption,
		BtPathname,
		BtPerl5Packlist,
		BtPkgname,
		BtPkgOptionsVar,
		BtPkgpath,
		BtPkgrevision,
		BtPlistIdentifier,
		BtPrefixPathname,
		BtPythonDependency,
		BtRPkgName,
		BtRPkgVer,
		BtRelativePkgDir,
		BtRelativePkgPath,
		BtStage,
		BtToolDependency, // ok since the [ tool is usually not mentioned.
		BtToolName,       // ok since the [ tool is usually not mentioned.
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
	BtDependencyPattern      = &BasicType{"DependencyPattern", (*VartypeCheck).DependencyPattern}
	BtDependencyWithPath     = &BasicType{"DependencyWithPath", (*VartypeCheck).DependencyWithPath}
	BtDistSuffix             = &BasicType{"DistSuffix", (*VartypeCheck).DistSuffix}
	BtEmulPlatform           = &BasicType{"EmulPlatform", (*VartypeCheck).EmulPlatform}
	BtFetchURL               = &BasicType{"FetchURL", (*VartypeCheck).FetchURL}
	BtFilename               = &BasicType{"Filename", (*VartypeCheck).Filename}
	BtFilePattern            = &BasicType{"FilePattern", (*VartypeCheck).FilePattern}
	BtFileMode               = &BasicType{"FileMode", (*VartypeCheck).FileMode}
	BtGccReqd                = &BasicType{"GccReqd", (*VartypeCheck).GccReqd}
	BtGitTag                 = &BasicType{"GitTag", (*VartypeCheck).GitTag}
	BtGoModuleFile           = &BasicType{"GoModuleFile", (*VartypeCheck).GoModuleFile}
	BtHomepage               = &BasicType{"Homepage", (*VartypeCheck).Homepage}
	BtIdentifierDirect       = &BasicType{"Identifier", (*VartypeCheck).IdentifierDirect}
	BtIdentifierIndirect     = &BasicType{"Identifier", (*VartypeCheck).IdentifierIndirect}
	BtInteger                = &BasicType{"Integer", (*VartypeCheck).Integer}
	BtLdFlag                 = &BasicType{"LdFlag", (*VartypeCheck).LdFlag}
	BtLicense                = &BasicType{"License", (*VartypeCheck).License}
	BtMachineGnuPlatform     = &BasicType{"MachineGnuPlatform", (*VartypeCheck).MachineGnuPlatform}
	BtMachinePlatform        = &BasicType{"MachinePlatform", (*VartypeCheck).MachinePlatform}
	BtMachinePlatformPattern = &BasicType{"MachinePlatformPattern", (*VartypeCheck).MachinePlatformPattern}
	BtMailAddress            = &BasicType{"MailAddress", (*VartypeCheck).MailAddress}
	BtMakeTarget             = &BasicType{"MakeTarget", (*VartypeCheck).MakeTarget}
	BtMessage                = &BasicType{"Message", (*VartypeCheck).Message}
	BtOption                 = &BasicType{"Option", (*VartypeCheck).Option}
	BtPathlist               = &BasicType{"Pathlist", (*VartypeCheck).Pathlist}
	BtPathPattern            = &BasicType{"PathPattern", (*VartypeCheck).PathPattern}
	BtPathname               = &BasicType{"Pathname", (*VartypeCheck).Pathname}
	BtPathnameSpace          = &BasicType{"PathnameSpace", (*VartypeCheck).PathnameSpace}
	BtPerl5Packlist          = &BasicType{"Perl5Packlist", (*VartypeCheck).Perl5Packlist}
	BtPerms                  = &BasicType{"Perms", (*VartypeCheck).Perms}
	BtPkgname                = &BasicType{"Pkgname", (*VartypeCheck).Pkgname}
	BtPkgpath                = &BasicType{"Pkgpath", (*VartypeCheck).Pkgpath}
	BtPkgOptionsVar          = &BasicType{"PkgOptionsVar", (*VartypeCheck).PkgOptionsVar}
	BtPkgrevision            = &BasicType{"Pkgrevision", (*VartypeCheck).Pkgrevision}
	BtPlistIdentifier        = &BasicType{"PlistIdentifier", (*VartypeCheck).PlistIdentifier}
	BtPrefixPathname         = &BasicType{"PrefixPathname", (*VartypeCheck).PrefixPathname}
	BtPythonDependency       = &BasicType{"PythonDependency", (*VartypeCheck).PythonDependency}
	BtRPkgName               = &BasicType{"RPkgName", (*VartypeCheck).RPkgName}
	BtRPkgVer                = &BasicType{"RPkgVer", (*VartypeCheck).RPkgVer}
	BtRelativePkgDir         = &BasicType{"RelativePkgDir", (*VartypeCheck).RelativePkgDir}
	BtRelativePkgPath        = &BasicType{"RelativePkgPath", (*VartypeCheck).RelativePkgPath}
	BtRestricted             = &BasicType{"Restricted", (*VartypeCheck).Restricted}
	BtSedCommands            = &BasicType{"SedCommands", (*VartypeCheck).SedCommands}
	BtShellCommand           = &BasicType{"ShellCommand", nil}  // see func init below
	BtShellCommands          = &BasicType{"ShellCommands", nil} // see func init below
	BtShellWord              = &BasicType{"ShellWord", nil}     // see func init below
	BtStage                  = &BasicType{"Stage", (*VartypeCheck).Stage}
	BtToolDependency         = &BasicType{"ToolDependency", (*VartypeCheck).ToolDependency}
	BtToolName               = &BasicType{"ToolName", (*VartypeCheck).ToolName}
	BtUnknown                = &BasicType{"Unknown", (*VartypeCheck).Unknown}
	BtURL                    = &BasicType{"URL", (*VartypeCheck).URL}
	BtUserGroupName          = &BasicType{"UserGroupName", (*VartypeCheck).UserGroupName}
	BtVariableName           = &BasicType{"VariableName", (*VartypeCheck).VariableName}
	BtVariableNamePattern    = &BasicType{"VariableNamePattern", (*VartypeCheck).VariableNamePattern}
	BtVersion                = &BasicType{"Version", (*VartypeCheck).Version}
	BtWrapperReorder         = &BasicType{"WrapperReorder", (*VartypeCheck).WrapperReorder}
	BtWrapperTransform       = &BasicType{"WrapperTransform", (*VartypeCheck).WrapperTransform}
	BtWrkdirSubdirectory     = &BasicType{"WrkdirSubdirectory", (*VartypeCheck).WrkdirSubdirectory}
	BtWrksrcPathPattern      = &BasicType{"WrksrcPathPattern", (*VartypeCheck).WrksrcPathPattern}
	BtWrksrcSubdirectory     = &BasicType{"WrksrcSubdirectory", (*VartypeCheck).WrksrcSubdirectory}
	BtYes                    = &BasicType{"Yes", (*VartypeCheck).Yes}
	BtYesNo                  = &BasicType{"YesNo", (*VartypeCheck).YesNo}
	BtYesNoIndirectly        = &BasicType{"YesNoIndirectly", (*VartypeCheck).YesNoIndirectly}

	BtMachineArch             = enumFromValues(machineArchValues)
	BtMachineGnuArch          = enumFromValues(machineGnuArchValues)
	BtEmulOpsys               = enumFromValues(emulOpsysValues)
	BtEmulArch                = enumFromValues(machineArchValues) // Just a wild guess.
	BtMachineGnuPlatformOpsys = BtEmulOpsys

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

// TODO: Move these values to VarTypeRegistry.Init and read them from the
//  pkgsrc infrastructure files, as far as possible.
const (
	// See mk/emulator/emulator-vars.mk.
	emulOpsysValues = "" +
		"bitrig bsdos cygwin darwin dragonfly freebsd " +
		"haiku hpux interix irix linux mirbsd netbsd openbsd osf1 solaris sunos"

	// Hardware architectures having the same name in bsd.own.mk and the GNU world.
	// These are best-effort guesses, since they depend on the operating system.
	archValues = "" +
		"aarch64 alpha amd64 arc arm cobalt convex dreamcast i386 " +
		"hpcmips hpcsh hppa hppa64 ia64 " +
		"m68k m88k mips mips64 mips64el mipseb mipsel mipsn32 mlrisc " +
		"ns32k pc532 pmax powerpc powerpc64 rs6000 s390 sparc sparc64 vax x86_64"

	// See mk/bsd.prefs.mk:/^GNU_ARCH\./
	machineArchValues = "" +
		archValues + " " +
		"aarch64eb amd64 arm26 arm32 coldfire earm earmeb earmhf earmhfeb earmv4 earmv4eb earmv5 " +
		"earmv5eb earmv6 earmv6eb earmv6hf earmv6hfeb earmv7 earmv7eb earmv7hf earmv7hfeb evbarm " +
		"i386 i586 i686 m68000 mips mips64eb sh3eb sh3el"

	// See mk/bsd.prefs.mk:/^GNU_ARCH\./
	machineGnuArchValues = "" +
		archValues + " " +
		"aarch64_be arm armeb armv4 armv4eb armv6 armv6eb armv7 armv7eb " +
		"i486 m5407 m68010 mips64 mipsel sh shle x86_64"
)

func enumFromValues(spaceSeparated string) *BasicType {
	values := strings.Fields(spaceSeparated)
	sort.Strings(values)
	seen := make(map[string]bool)
	var unique []string
	for _, value := range values {
		if !seen[value] {
			seen[value] = true
			unique = append(unique, value)
		}
	}
	return enum(strings.Join(unique, " "))
}
