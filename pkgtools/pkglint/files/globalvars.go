package main

import (
	"io"
	"regexp"
)

type GlobalVars struct {
	opts       CmdOpts
	globalData GlobalData
	pkgContext *PkgContext
	mkContext  *MkContext

	todo             []string // The items that still need to be checked.
	currentDir       string   // The currently checked directory, relative to the cwd
	curPkgsrcdir     string   // The pkgsrc directory, relative to currentDir
	isWip            bool     // Is the currently checked directory from pkgsrc-wip?
	isInfrastructure bool     // Is the currently checked item from the pkgsrc infrastructure?

	ipcDistinfo     map[string]*Hash // Maps "alg:fname" => "checksum".
	ipcUsedLicenses map[string]bool  // Maps "license name" => true

	errors                int
	warnings              int
	explanationsAvailable bool
	explanationsGiven     map[string]bool
	autofixAvailable      bool
	traceDepth            int
	logOut                io.Writer
	logErr                io.Writer
	traceOut              io.Writer

	res       map[string]*regexp.Regexp
	rematch   *Histogram
	renomatch *Histogram
}

type CmdOpts struct {
	CheckAlternatives,
	CheckBuildlink3,
	CheckDescr,
	CheckDistinfo,
	CheckExtra,
	CheckGlobal,
	CheckInstall,
	CheckMakefile,
	CheckMessage,
	CheckMk,
	CheckPatches,
	CheckPlist bool

	DebugInclude,
	DebugMisc,
	DebugPatches,
	DebugQuoting,
	DebugShell,
	DebugTools,
	DebugTrace,
	DebugUnchecked,
	DebugUnused,
	DebugVartypes,
	DebugVaruse bool

	WarnAbsname,
	WarnDirectcmd,
	WarnExtra,
	WarnOrder,
	WarnPerm,
	WarnPlistDepr,
	WarnPlistSort,
	WarnQuoting,
	WarnSpace,
	WarnStyle,
	WarnTypes bool

	Explain,
	Autofix,
	GccOutput,
	PrintHelp,
	DumpMakefile,
	Import,
	Profiling,
	Quiet,
	Recursive,
	PrintAutofix,
	PrintSource,
	PrintVersion bool

	args []string
}

type Hash struct {
	hash string
	line *Line
}

var G *GlobalVars
