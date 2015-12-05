package main

import (
	"path"
	"strings"
)

type PlistContext struct {
	allFiles  map[string]*Line
	allDirs   map[string]*Line
	lastFname string
}

func checklinesPlist(lines []*Line) {
	defer tracecall("checklinesPlist", lines[0].fname)()

	checklineRcsid(lines[0], `@comment `, "@comment ")

	if len(lines) == 1 {
		lines[0].warnf("PLIST files shouldn't be empty.")
		lines[0].explain(
			"One reason for empty PLISTs is that this is a newly created package",
			"and that the author didn't run \"bmake print-PLIST\" after installing",
			"the files.",
			"",
			"Another reason, common for Perl packages, is that the final PLIST is",
			"automatically generated. Since the source PLIST is not used at all,",
			"you can remove it.",
			"",
			"Meta packages also don't need a PLIST file.")
	}

	pctx := new(PlistContext)
	pctx.allFiles = make(map[string]*Line)
	pctx.allDirs = make(map[string]*Line)

	var extraLines []*Line
	if fname := lines[0].fname; path.Base(fname) == "PLIST.common_end" {
		commonLines, err := readLines(path.Dir(fname)+"/PLIST.common", false)
		if err == nil {
			extraLines = commonLines
		}
	}

	// Collect all files and directories that appear in the PLIST file.
	for _, line := range append(append([]*Line(nil), extraLines...), lines...) {
		text := line.text

		if hasPrefix(text, "${") {
			if m, varname, rest := match2(text, `^\$\{([\w_]+)\}(.*)`); m {
				if G.pkgContext != nil && G.pkgContext.plistSubstCond[varname] {
					_ = G.opts.DebugMisc && line.debugf("Removed PLIST_SUBST conditional %q.", varname)
					text = rest
				}
			}
		}

		if matches(text, `^[\w$]`) {
			pctx.allFiles[text] = line
			for dir := path.Dir(text); dir != "."; dir = path.Dir(dir) {
				pctx.allDirs[dir] = line
			}
		}

		if hasPrefix(text, "@") {
			if m, dirname := match1(text, `^@exec \$\{MKDIR\} %D/(.*)$`); m {
				for dir := dirname; dir != "."; dir = path.Dir(dir) {
					pctx.allDirs[dir] = line
				}
			}
		}
	}

	for _, line := range lines {
		pline := &PlistLine{line}
		pline.check(pctx)
		pline.checkTrailingWhitespace()
	}

	checklinesTrailingEmptyLines(lines)
	saveAutofixChanges(lines)
}

type PlistLine struct {
	line *Line
}

func (pline *PlistLine) check(pctx *PlistContext) {
	text := pline.line.text
	if hasAlnumPrefix(text) {
		pline.checkPathname(pctx, text)
	} else if m, cmd, arg := match2(text, `^(?:\$\{[\w.]+\})?@([a-z-]+)\s+(.*)`); m {
		pline.checkDirective(cmd, arg)
	} else if hasPrefix(text, "$") {
		pline.checkPathname(pctx, text)
	} else if matches(text, `^\$\{[\w_]+\}$`) {
		// A variable on its own line.
	} else {
		pline.line.warnf("Unknown line type.")
	}
}

func (pline *PlistLine) checkTrailingWhitespace() {
	line := pline.line

	if hasSuffix(line.text, " ") || hasSuffix(line.text, "\t") {
		line.errorf("pkgsrc does not support filenames ending in white-space.")
		line.explain(
			"Each character in the PLIST is relevant, even trailing white-space.")
	}
}

func (pline *PlistLine) checkDirective(cmd, arg string) {
	line := pline.line

	if cmd == "unexec" {
		if m, arg := match1(arg, `^(?:rmdir|\$\{RMDIR\} \%D/)(.*)`); m {
			if !contains(arg, "true") && !contains(arg, "${TRUE}") {
				line.warnf("Please remove this line. It is no longer necessary.")
			}
		}
	}

	switch cmd {
	case "exec", "unexec":
		switch {
		case contains(arg, "install-info"),
			contains(arg, "${INSTALL_INFO}"):
			line.warnf("@exec/unexec install-info is deprecated.")
		case contains(arg, "ldconfig") && !contains(arg, "/usr/bin/true"):
			line.errorf("ldconfig must be used with \"||/usr/bin/true\".")
		}

	case "comment":
		// Nothing to do.

	case "dirrm":
		line.warnf("@dirrm is obsolete. Please remove this line.")
		line.explain(
			"Directories are removed automatically when they are empty.",
			"When a package needs an empty directory, it can use the @pkgdir",
			"command in the PLIST")

	case "imake-man":
		args := splitOnSpace(arg)
		if len(args) != 3 {
			line.warnf("Invalid number of arguments for imake-man.")
		} else {
			if args[2] == "${IMAKE_MANNEWSUFFIX}" {
				pline.warnAboutPlistImakeMannewsuffix()
			}
		}

	case "pkgdir":
		// Nothing to check.

	default:
		line.warnf("Unknown PLIST directive \"@%s\".", cmd)
	}
}

func (pline *PlistLine) checkPathname(pctx *PlistContext, fullname string) {
	line := pline.line
	text := line.text
	sdirname, basename := path.Split(fullname)
	dirname := strings.TrimSuffix(sdirname, "/")

	pline.checkSorted(pctx)

	if contains(basename, "${IMAKE_MANNEWSUFFIX}") {
		pline.warnAboutPlistImakeMannewsuffix()
	}

	switch {
	case hasPrefix(dirname, "bin/"):
		line.warnf("The bin/ directory should not have subdirectories.")

	case dirname == "bin":
		pline.checkpathBin(pctx, basename)

	case hasPrefix(text, "doc/"):
		line.errorf("Documentation must be installed under share/doc, not doc.")

	case hasPrefix(text, "etc/rc.d/"):
		line.errorf("RCD_SCRIPTS must not be registered in the PLIST. Please use the RCD_SCRIPTS framework.")

	case hasPrefix(text, "etc/"):
		f := "mk/pkginstall/bsd.pkginstall.mk"
		line.errorf("Configuration files must not be registered in the PLIST. "+
			"Please use the CONF_FILES framework, which is described in %s.", f)

	case hasPrefix(text, "include/") && matches(text, `^include/.*\.(?:h|hpp)$`):
		// Fine.

	case text == "info/dir":
		line.errorf("\"info/dir\" must not be listed. Use install-info to add/remove an entry.")

	case hasPrefix(text, "info/"):
		if G.pkgContext != nil && G.pkgContext.vardef["INFO_FILES"] == nil {
			line.warnf("Packages that install info files should set INFO_FILES.")
		}

	case G.pkgContext != nil && G.pkgContext.effectivePkgbase != "" && hasPrefix(text, "lib/"+G.pkgContext.effectivePkgbase+"/"):
		// Fine.

	case hasPrefix(text, "lib/locale/"):
		line.errorf("\"lib/locale\" must not be listed. Use ${PKGLOCALEDIR}/locale and set USE_PKGLOCALEDIR instead.")

	case hasPrefix(text, "lib/"):
		pline.checkpathLib(pctx, basename)

	case hasPrefix(text, "man/"):
		pline.checkpathMan(pctx)

	case hasPrefix(text, "sbin/"):
		pline.checkpathSbin(pctx)

	case hasPrefix(text, "share/applications/") && hasSuffix(text, ".desktop"):
		f := "../../sysutils/desktop-file-utils/desktopdb.mk"
		if G.pkgContext != nil && G.pkgContext.included[f] == nil {
			line.warnf("Packages that install a .desktop entry should .include %q.", f)
			line.explain(
				"If *.desktop files contain MimeType keys, the global MIME type registry",
				"must be updated by desktop-file-utils. Otherwise, this warning is harmless.")
		}

	case hasPrefix(text, "share/icons/hicolor/") && G.pkgContext != nil && G.pkgContext.pkgpath != "graphics/hicolor-icon-theme":
		f := "../../graphics/hicolor-icon-theme/buildlink3.mk"
		if G.pkgContext.included[f] == nil {
			line.errorf("Packages that install hicolor icons must include %q in the Makefile.", f)
		}

	case hasPrefix(text, "share/icons/gnome") && G.pkgContext != nil && G.pkgContext.pkgpath != "graphics/gnome-icon-theme":
		f := "../../graphics/gnome-icon-theme/buildlink3.mk"
		if G.pkgContext.included[f] == nil {
			line.errorf("The package Makefile must include %q.", f)
			line.explain(
				"Packages that install GNOME icons must maintain the icon theme cache.")
		}

	case dirname == "share/aclocal" && hasSuffix(basename, ".m4"):
		// Fine.

	case hasPrefix(text, "share/doc/html/"):
		_ = G.opts.WarnPlistDepr && line.warnf("Use of \"share/doc/html\" is deprecated. Use \"share/doc/${PKGBASE}\" instead.")

	case G.pkgContext != nil && G.pkgContext.effectivePkgbase != "" && (hasPrefix(text, "share/doc/"+G.pkgContext.effectivePkgbase+"/") ||
		hasPrefix(text, "share/examples/"+G.pkgContext.effectivePkgbase+"/")):
		// Fine.

	case text == "share/icons/hicolor/icon-theme.cache" && G.pkgContext != nil && G.pkgContext.pkgpath != "graphics/hicolor-icon-theme":
		line.errorf("This file must not appear in any PLIST file.")
		line.explain(
			"Remove this line and add the following line to the package Makefile.",
			"",
			".include \"../../graphics/hicolor-icon-theme/buildlink3.mk\"")

	case hasPrefix(text, "share/info/"):
		line.warnf("Info pages should be installed into info/, not share/info/.")
		line.explain(
			"To fix this, you should add INFO_FILES=yes to the package Makefile.")

	case hasPrefix(text, "share/locale/") && hasSuffix(text, ".mo"):
		// Fine.

	case hasPrefix(text, "share/man/"):
		line.warnf("Man pages should be installed into man/, not share/man/.")

	default:
		_ = G.opts.DebugUnchecked && line.debugf("Unchecked pathname %q.", text)
	}

	if contains(text, "${PKGLOCALEDIR}") && G.pkgContext != nil && G.pkgContext.vardef["USE_PKGLOCALEDIR"] == nil {
		line.warnf("PLIST contains ${PKGLOCALEDIR}, but USE_PKGLOCALEDIR was not found.")
	}

	if contains(text, "/CVS/") {
		line.warnf("CVS files should not be in the PLIST.")
	}
	if hasSuffix(text, ".orig") {
		line.warnf(".orig files should not be in the PLIST.")
	}
	if hasSuffix(text, "/perllocal.pod") {
		line.warnf("perllocal.pod files should not be in the PLIST.")
		line.explain(
			"This file is handled automatically by the INSTALL/DEINSTALL scripts,",
			"since its contents changes frequently.")
	}
}

func (pline *PlistLine) checkSorted(pctx *PlistContext) {
	if text := pline.line.text; G.opts.WarnPlistSort && hasAlnumPrefix(text) && !containsVarRef(text) {
		if pctx.lastFname != "" {
			if pctx.lastFname > text {
				pline.line.warnf("%q should be sorted before %q.", text, pctx.lastFname)
				pline.line.explain(
					"The files in the PLIST should be sorted alphabetically.")
			} else if pctx.lastFname == text {
				pline.line.errorf("Duplicate filename.")
			}
		}
		pctx.lastFname = text
	}
}

func (pline *PlistLine) checkpathBin(pctx *PlistContext, basename string) {
	switch {
	case pctx.allFiles["man/man1/"+basename+".1"] != nil:
	case pctx.allFiles["man/man6/"+basename+".6"] != nil:
	case pctx.allFiles["${IMAKE_MAN_DIR}/"+basename+".${IMAKE_MANNEWSUFFIX}"] != nil:
	default:
		if G.opts.WarnExtra {
			pline.line.warnf("Manual page missing for bin/%s.", basename)
			pline.line.explain(
				"All programs that can be run directly by the user should have a manual",
				"page for quick reference. The programs in the bin/ directory should have",
				"corresponding manual pages in section 1 (filename program.1), not in",
				"section 8.")
		}
	}
}

func (pline *PlistLine) checkpathLib(pctx *PlistContext, basename string) {
	if m, dir, lib, ext := match3(pline.line.text, `^(lib/(?:.*/)*)([^/]+)\.(so|a|la)$`); m {
		if dir == "lib/" && !hasPrefix(lib, "lib") {
			_ = G.opts.WarnExtra && pline.line.warnf("Library filename does not start with \"lib\".")
		}
		if ext == "la" {
			if G.pkgContext != nil && G.pkgContext.vardef["USE_LIBTOOL"] == nil {
				pline.line.warnf("Packages that install libtool libraries should define USE_LIBTOOL.")
			}
		}
	}

	if contains(basename, ".a") || contains(basename, ".so") {
		if m, noext := match1(pline.line.text, `^(.*)(?:\.a|\.so[0-9.]*)$`); m {
			if laLine := pctx.allFiles[noext+".la"]; laLine != nil {
				pline.line.warnf("Redundant library found. The libtool library is in line %s.", laLine)
			}
		}
	}
}

func (pline *PlistLine) checkpathMan(pctx *PlistContext) {
	line := pline.line

	m, catOrMan, section, manpage, ext, gz := match5(pline.line.text, `^man/(cat|man)(\w+)/(.*?)\.(\w+)(\.gz)?$`)
	if !m {
		// maybe: line.warnf("Invalid filename %q for manual page.", text)
		return
	}

	if !matches(section, `^[\dln]$`) {
		line.warnf("Unknown section %q for manual page.", section)
	}

	if catOrMan == "cat" && pctx.allFiles["man/man"+section+"/"+manpage+"."+section] == nil {
		line.warnf("Preformatted manual page without unformatted one.")
	}

	if catOrMan == "cat" {
		if ext != "0" {
			line.warnf("Preformatted manual pages should end in \".0\".")
		}
	} else {
		if section != ext {
			line.warnf("Mismatch between the section (%s) and extension (%s) of the manual page.", section, ext)
		}
	}

	if gz != "" {
		line.notef("The .gz extension is unnecessary for manual pages.")
		line.explain(
			"Whether the manual pages are installed in compressed form or not is",
			"configured by the pkgsrc user. Compression and decompression takes place",
			"automatically, no matter if the .gz extension is mentioned in the PLIST",
			"or not.")
	}
}

func (pline *PlistLine) checkpathSbin(pctx *PlistContext) {
	binname := pline.line.text[5:]

	if pctx.allFiles["man/man8/"+binname+".8"] == nil && G.opts.WarnExtra {
		pline.line.warnf("Manual page missing for sbin/%s.", binname)
		pline.line.explain(
			"All programs that can be run directly by the user should have a manual",
			"page for quick reference. The programs in the sbin/ directory should have",
			"corresponding manual pages in section 8 (filename program.8), not in",
			"section 1.")
	}
}

func (pline *PlistLine) warnAboutPlistImakeMannewsuffix() {
	line := pline.line

	line.warnf("IMAKE_MANNEWSUFFIX is not meant to appear in PLISTs.")
	line.explain(
		"This is the result of a print-PLIST call that has not been edited",
		"manually by the package maintainer. Please replace the",
		"IMAKE_MANNEWSUFFIX with:",
		"",
		"\tIMAKE_MAN_SUFFIX for programs,",
		"\tIMAKE_LIBMAN_SUFFIX for library functions,",
		"\tIMAKE_FILEMAN_SUFFIX for file formats,",
		"\tIMAKE_GAMEMAN_SUFFIX for games,",
		"\tIMAKE_MISCMAN_SUFFIX for other man pages.")
}
