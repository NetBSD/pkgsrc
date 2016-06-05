package main

import (
	"io"
	"regexp"
)

type GlobalVars struct {
	opts       CmdOpts    //
	globalData GlobalData //
	Pkg        *Package   // The package that is currently checked.
	Mk         *MkLines   // The Makefile (or fragment) that is currently checked.

	Todo           []string // The files or directories that still need to be checked.
	CurrentDir     string   // The currently checked directory, relative to the cwd
	CurPkgsrcdir   string   // The pkgsrc directory, relative to currentDir
	Wip            bool     // Is the currently checked directory from pkgsrc-wip?
	Infrastructure bool     // Is the currently checked item from the pkgsrc infrastructure?
	Testing        bool     // Is pkglint in self-testing mode (only during development)?

	Hash         map[string]*Hash // Maps "alg:fname" => hash (inter-package check).
	UsedLicenses map[string]bool  // Maps "license name" => true (inter-package check).

	errors                int
	warnings              int
	logged                map[string]bool
	explanationsAvailable bool
	explanationsGiven     map[string]bool
	autofixAvailable      bool
	traceDepth            int
	logOut                io.Writer
	logErr                io.Writer
	debugOut              io.Writer

	res       map[string]*regexp.Regexp
	rematch   *Histogram
	renomatch *Histogram
	retime    *Histogram
	loghisto  *Histogram
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
	LogVerbose,
	Profiling,
	Quiet,
	Recursive,
	Debug,
	PrintAutofix,
	PrintSource,
	PrintVersion bool

	args []string
}

type Hash struct {
	hash string
	line *Line
}

var G GlobalVars
