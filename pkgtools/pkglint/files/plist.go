package main

import (
	"path"
	"sort"
	"strings"
)

func ChecklinesPlist(lines []*Line) {
	if G.opts.Debug {
		defer tracecall1(lines[0].Fname)()
	}

	lines[0].CheckRcsid(`@comment `, "@comment ")

	if len(lines) == 1 {
		lines[0].Warn0("PLIST files shouldn't be empty.")
		Explain(
			"One reason for empty PLISTs is that this is a newly created package",
			"and that the author didn't run \"bmake print-PLIST\" after installing",
			"the files.",
			"",
			"Another reason, common for Perl packages, is that the final PLIST is",
			"automatically generated.  Since the source PLIST is not used at all,",
			"you can remove it.",
			"",
			"Meta packages also don't need a PLIST file.")
	}

	ck := &PlistChecker{
		make(map[string]*PlistLine),
		make(map[string]*PlistLine),
		""}
	ck.Check(lines)
}

type PlistChecker struct {
	allFiles  map[string]*PlistLine
	allDirs   map[string]*PlistLine
	lastFname string
}

type PlistLine struct {
	line        *Line
	conditional string // e.g. PLIST.docs
	text        string // Like line.text, without the conditional
}

func (ck *PlistChecker) Check(plainLines []*Line) {
	plines := ck.NewLines(plainLines)
	ck.collectFilesAndDirs(plines)

	if fname := plines[0].line.Fname; path.Base(fname) == "PLIST.common_end" {
		commonLines, err := readLines(strings.TrimSuffix(fname, "_end"), false)
		if err == nil {
			ck.collectFilesAndDirs(ck.NewLines(commonLines))
		}
	}

	for _, pline := range plines {
		ck.checkline(pline)
		pline.CheckTrailingWhitespace()
	}
	ChecklinesTrailingEmptyLines(plainLines)

	if G.opts.WarnPlistSort {
		sorter := NewPlistLineSorter(plines)
		sorter.Sort()
		if !sorter.autofixed {
			SaveAutofixChanges(plainLines)
		}
	} else {
		SaveAutofixChanges(plainLines)
	}
}

func (ck *PlistChecker) NewLines(lines []*Line) []*PlistLine {
	plines := make([]*PlistLine, len(lines))
	for i, line := range lines {
		conditional, text := "", line.Text
		if hasPrefix(text, "${PLIST.") {
			if m, cond, rest := match2(text, `^\$\{(PLIST\.[\w-.]+)\}(.*)`); m {
				conditional, text = cond, rest
			}
		}
		plines[i] = &PlistLine{line, conditional, text}
	}
	return plines
}

func (ck *PlistChecker) collectFilesAndDirs(plines []*PlistLine) {
	for _, pline := range plines {
		if text := pline.text; len(text) > 0 {
			first := text[0]
			switch {
			case 'a' <= first && first <= 'z',
				first == '$',
				'A' <= first && first <= 'Z',
				'0' <= first && first <= '9':
				if ck.allFiles[text] == nil {
					ck.allFiles[text] = pline
				}
				for dir := path.Dir(text); dir != "."; dir = path.Dir(dir) {
					ck.allDirs[dir] = pline
				}
			case first == '@':
				if m, dirname := match1(text, `^@exec \$\{MKDIR\} %D/(.*)$`); m {
					for dir := dirname; dir != "."; dir = path.Dir(dir) {
						ck.allDirs[dir] = pline
					}
				}
			}

		}
	}
}

func (ck *PlistChecker) checkline(pline *PlistLine) {
	text := pline.text
	if hasAlnumPrefix(text) {
		ck.checkpath(pline)
	} else if m, cmd, arg := match2(text, `^(?:\$\{[\w.]+\})?@([a-z-]+)\s+(.*)`); m {
		pline.CheckDirective(cmd, arg)
	} else if hasPrefix(text, "$") {
		ck.checkpath(pline)
	} else {
		pline.line.Warn0("Unknown line type.")
	}
}

func (ck *PlistChecker) checkpath(pline *PlistLine) {
	line, text := pline.line, pline.text
	sdirname, basename := path.Split(text)
	dirname := strings.TrimSuffix(sdirname, "/")

	ck.checkSorted(pline)

	if contains(basename, "${IMAKE_MANNEWSUFFIX}") {
		pline.warnImakeMannewsuffix()
	}

	topdir := ""
	if firstSlash := strings.IndexByte(text, '/'); firstSlash != -1 {
		topdir = text[:firstSlash]
	}

	switch topdir {
	case "bin":
		ck.checkpathBin(pline, dirname, basename)
	case "doc":
		line.Error0("Documentation must be installed under share/doc, not doc.")
	case "etc":
		ck.checkpathEtc(pline, dirname, basename)
	case "info":
		ck.checkpathInfo(pline, dirname, basename)
	case "lib":
		ck.checkpathLib(pline, dirname, basename)
	case "man":
		ck.checkpathMan(pline)
	case "sbin":
		ck.checkpathSbin(pline)
	case "share":
		ck.checkpathShare(pline)
	}

	if contains(text, "${PKGLOCALEDIR}") && G.Pkg != nil && G.Pkg.vardef["USE_PKGLOCALEDIR"] == nil {
		line.Warn0("PLIST contains ${PKGLOCALEDIR}, but USE_PKGLOCALEDIR was not found.")
	}

	if contains(text, "/CVS/") {
		line.Warn0("CVS files should not be in the PLIST.")
	}
	if hasSuffix(text, ".orig") {
		line.Warn0(".orig files should not be in the PLIST.")
	}
	if hasSuffix(text, "/perllocal.pod") {
		line.Warn0("perllocal.pod files should not be in the PLIST.")
		Explain2(
			"This file is handled automatically by the INSTALL/DEINSTALL scripts,",
			"since its contents changes frequently.")
	}
}

func (ck *PlistChecker) checkSorted(pline *PlistLine) {
	if text := pline.text; G.opts.WarnPlistSort && hasAlnumPrefix(text) && !containsVarRef(text) {
		if ck.lastFname != "" {
			if ck.lastFname > text && !G.opts.Autofix {
				pline.line.Warn2("%q should be sorted before %q.", text, ck.lastFname)
				Explain2(
					"The files in the PLIST should be sorted alphabetically.",
					"To fix this, run \"pkglint -F PLIST\".")
			}
			if prev := ck.allFiles[text]; prev != nil && prev != pline {
				if !pline.line.AutofixDelete() {
					pline.line.Errorf("Duplicate filename %q, already appeared in %s.", text, prev.line.ReferenceFrom(pline.line))
				}
			}
		}
		ck.lastFname = text
	}
}

func (ck *PlistChecker) checkpathBin(pline *PlistLine, dirname, basename string) {
	if contains(dirname, "/") {
		pline.line.Warn0("The bin/ directory should not have subdirectories.")
		return
	}

	if G.opts.WarnExtra &&
		ck.allFiles["man/man1/"+basename+".1"] == nil &&
		ck.allFiles["man/man6/"+basename+".6"] == nil &&
		ck.allFiles["${IMAKE_MAN_DIR}/"+basename+".${IMAKE_MANNEWSUFFIX}"] == nil {
		pline.line.Warn1("Manual page missing for bin/%s.", basename)
		Explain(
			"All programs that can be run directly by the user should have a",
			"manual page for quick reference.  The programs in the bin/ directory",
			"should have corresponding manual pages in section 1 (filename",
			"program.1), while the programs in the sbin/ directory have their",
			"manual pages in section 8.")
	}
}

func (ck *PlistChecker) checkpathEtc(pline *PlistLine, dirname, basename string) {
	if hasPrefix(pline.text, "etc/rc.d/") {
		pline.line.Error0("RCD_SCRIPTS must not be registered in the PLIST. Please use the RCD_SCRIPTS framework.")
		return
	}

	pline.line.Error0("Configuration files must not be registered in the PLIST. " +
		"Please use the CONF_FILES framework, which is described in mk/pkginstall/bsd.pkginstall.mk.")
}

func (ck *PlistChecker) checkpathInfo(pline *PlistLine, dirname, basename string) {
	if pline.text == "info/dir" {
		pline.line.Error0("\"info/dir\" must not be listed. Use install-info to add/remove an entry.")
		return
	}

	if G.Pkg != nil && G.Pkg.vardef["INFO_FILES"] == nil {
		pline.line.Warn0("Packages that install info files should set INFO_FILES.")
	}
}

func (ck *PlistChecker) checkpathLib(pline *PlistLine, dirname, basename string) {
	switch {
	case G.Pkg != nil && G.Pkg.EffectivePkgbase != "" && hasPrefix(pline.text, "lib/"+G.Pkg.EffectivePkgbase+"/"):
		return

	case hasPrefix(pline.text, "lib/locale/"):
		pline.line.Error0("\"lib/locale\" must not be listed. Use ${PKGLOCALEDIR}/locale and set USE_PKGLOCALEDIR instead.")
		return
	}

	switch ext := path.Ext(basename); ext {
	case ".a", ".la", ".so":
		if G.opts.WarnExtra && dirname == "lib" && !hasPrefix(basename, "lib") {
			pline.line.Warn1("Library filename %q should start with \"lib\".", basename)
		}
		if ext == "la" {
			if G.Pkg != nil && G.Pkg.vardef["USE_LIBTOOL"] == nil {
				pline.line.Warn0("Packages that install libtool libraries should define USE_LIBTOOL.")
			}
		}
	}

	if contains(basename, ".a") || contains(basename, ".so") {
		if m, noext := match1(pline.text, `^(.*)(?:\.a|\.so[0-9.]*)$`); m {
			if laLine := ck.allFiles[noext+".la"]; laLine != nil {
				pline.line.Warn1("Redundant library found. The libtool library is in %s.", laLine.line.ReferenceFrom(pline.line))
			}
		}
	}
}

func (ck *PlistChecker) checkpathMan(pline *PlistLine) {
	line := pline.line

	m, catOrMan, section, manpage, ext, gz := match5(pline.text, `^man/(cat|man)(\w+)/(.*?)\.(\w+)(\.gz)?$`)
	if !m {
		// maybe: line.warn1("Invalid filename %q for manual page.", text)
		return
	}

	if !matches(section, `^[\dln]$`) {
		line.Warn1("Unknown section %q for manual page.", section)
	}

	if catOrMan == "cat" && ck.allFiles["man/man"+section+"/"+manpage+"."+section] == nil {
		line.Warn0("Preformatted manual page without unformatted one.")
	}

	if catOrMan == "cat" {
		if ext != "0" {
			line.Warn0("Preformatted manual pages should end in \".0\".")
		}
	} else {
		if !hasPrefix(ext, section) {
			line.Warn2("Mismatch between the section (%s) and extension (%s) of the manual page.", section, ext)
		}
	}

	if gz != "" {
		line.Note0("The .gz extension is unnecessary for manual pages.")
		Explain4(
			"Whether the manual pages are installed in compressed form or not is",
			"configured by the pkgsrc user.  Compression and decompression takes",
			"place automatically, no matter if the .gz extension is mentioned in",
			"the PLIST or not.")
	}
}

func (ck *PlistChecker) checkpathSbin(pline *PlistLine) {
	binname := pline.text[5:]

	if ck.allFiles["man/man8/"+binname+".8"] == nil && G.opts.WarnExtra {
		pline.line.Warn1("Manual page missing for sbin/%s.", binname)
		Explain(
			"All programs that can be run directly by the user should have a",
			"manual page for quick reference.  The programs in the sbin/",
			"directory should have corresponding manual pages in section 8",
			"(filename program.8), while the programs in the bin/ directory",
			"have their manual pages in section 1.")
	}
}

func (ck *PlistChecker) checkpathShare(pline *PlistLine) {
	line, text := pline.line, pline.text
	switch {
	// Disabled due to PR 46570, item "10. It should stop".
	case false && hasPrefix(text, "share/applications/") && hasSuffix(text, ".desktop"):
		f := "../../sysutils/desktop-file-utils/desktopdb.mk"
		if G.opts.WarnExtra && G.Pkg != nil && G.Pkg.included[f] == nil {
			line.Warn1("Packages that install a .desktop entry should .include %q.", f)
			Explain3(
				"If *.desktop files contain MimeType keys, the global MIME type",
				"registry must be updated by desktop-file-utils.  Otherwise, this",
				"warning is harmless.")
		}

	case hasPrefix(text, "share/icons/hicolor/") && G.Pkg != nil && G.Pkg.Pkgpath != "graphics/hicolor-icon-theme":
		f := "../../graphics/hicolor-icon-theme/buildlink3.mk"
		if G.Pkg.included[f] == nil {
			line.Error1("Packages that install hicolor icons must include %q in the Makefile.", f)
		}

	case hasPrefix(text, "share/icons/gnome") && G.Pkg != nil && G.Pkg.Pkgpath != "graphics/gnome-icon-theme":
		f := "../../graphics/gnome-icon-theme/buildlink3.mk"
		if G.Pkg.included[f] == nil {
			line.Error1("The package Makefile must include %q.", f)
			Explain2(
				"Packages that install GNOME icons must maintain the icon theme",
				"cache.")
		}

	case hasPrefix(text, "share/doc/html/"):
		if G.opts.WarnPlistDepr {
			line.Warn0("Use of \"share/doc/html\" is deprecated. Use \"share/doc/${PKGBASE}\" instead.")
		}

	case G.Pkg != nil && G.Pkg.EffectivePkgbase != "" && (hasPrefix(text, "share/doc/"+G.Pkg.EffectivePkgbase+"/") ||
		hasPrefix(text, "share/examples/"+G.Pkg.EffectivePkgbase+"/")):
		// Fine.

	case text == "share/icons/hicolor/icon-theme.cache" && G.Pkg != nil && G.Pkg.Pkgpath != "graphics/hicolor-icon-theme":
		line.Error0("This file must not appear in any PLIST file.")
		Explain3(
			"Remove this line and add the following line to the package Makefile.",
			"",
			".include \"../../graphics/hicolor-icon-theme/buildlink3.mk\"")

	case hasPrefix(text, "share/info/"):
		line.Warn0("Info pages should be installed into info/, not share/info/.")
		Explain1(
			"To fix this, you should add INFO_FILES=yes to the package Makefile.")

	case hasPrefix(text, "share/locale/") && hasSuffix(text, ".mo"):
		// Fine.

	case hasPrefix(text, "share/man/"):
		line.Warn0("Man pages should be installed into man/, not share/man/.")
	}
}

func (pline *PlistLine) CheckTrailingWhitespace() {
	if hasSuffix(pline.text, " ") || hasSuffix(pline.text, "\t") {
		pline.line.Error0("pkgsrc does not support filenames ending in white-space.")
		Explain1(
			"Each character in the PLIST is relevant, even trailing white-space.")
	}
}

func (pline *PlistLine) CheckDirective(cmd, arg string) {
	line := pline.line

	if cmd == "unexec" {
		if m, arg := match1(arg, `^(?:rmdir|\$\{RMDIR\} \%D/)(.*)`); m {
			if !contains(arg, "true") && !contains(arg, "${TRUE}") {
				pline.line.Warn0("Please remove this line. It is no longer necessary.")
			}
		}
	}

	switch cmd {
	case "exec", "unexec":
		switch {
		case contains(arg, "install-info"),
			contains(arg, "${INSTALL_INFO}"):
			line.Warn0("@exec/unexec install-info is deprecated.")
		case contains(arg, "ldconfig") && !contains(arg, "/usr/bin/true"):
			pline.line.Error0("ldconfig must be used with \"||/usr/bin/true\".")
		}

	case "comment":
		// Nothing to do.

	case "dirrm":
		line.Warn0("@dirrm is obsolete. Please remove this line.")
		Explain3(
			"Directories are removed automatically when they are empty.",
			"When a package needs an empty directory, it can use the @pkgdir",
			"command in the PLIST")

	case "imake-man":
		args := splitOnSpace(arg)
		switch {
		case len(args) != 3:
			line.Warn0("Invalid number of arguments for imake-man.")
		case args[2] == "${IMAKE_MANNEWSUFFIX}":
			pline.warnImakeMannewsuffix()
		}

	case "pkgdir":
		// Nothing to check.

	default:
		line.Warn1("Unknown PLIST directive \"@%s\".", cmd)
	}
}

func (pline *PlistLine) warnImakeMannewsuffix() {
	pline.line.Warn0("IMAKE_MANNEWSUFFIX is not meant to appear in PLISTs.")
	Explain(
		"This is the result of a print-PLIST call that has not been edited",
		"manually by the package maintainer.  Please replace the",
		"IMAKE_MANNEWSUFFIX with:",
		"",
		"\tIMAKE_MAN_SUFFIX for programs,",
		"\tIMAKE_LIBMAN_SUFFIX for library functions,",
		"\tIMAKE_FILEMAN_SUFFIX for file formats,",
		"\tIMAKE_GAMEMAN_SUFFIX for games,",
		"\tIMAKE_MISCMAN_SUFFIX for other man pages.")
}

type plistLineSorter struct {
	first     *PlistLine
	plines    []*PlistLine
	lines     []*Line
	after     map[*PlistLine][]*Line
	swapped   bool
	autofixed bool
}

func NewPlistLineSorter(plines []*PlistLine) *plistLineSorter {
	s := &plistLineSorter{first: plines[0], after: make(map[*PlistLine][]*Line)}
	prev := plines[0]
	for _, pline := range plines[1:] {
		if hasPrefix(pline.text, "@") || contains(pline.text, "$") {
			s.after[prev] = append(s.after[prev], pline.line)
		} else {
			s.plines = append(s.plines, pline)
			s.lines = append(s.lines, pline.line)
			prev = pline
		}
	}
	return s
}

func (s *plistLineSorter) Len() int {
	return len(s.plines)
}
func (s *plistLineSorter) Less(i, j int) bool {
	return s.plines[i].text < s.plines[j].text
}
func (s *plistLineSorter) Swap(i, j int) {
	s.swapped = true
	s.lines[i], s.lines[j] = s.lines[j], s.lines[i]
	s.plines[i], s.plines[j] = s.plines[j], s.plines[i]
}

func (s *plistLineSorter) Sort() {
	sort.Stable(s)

	if !s.swapped {
		return
	}

	firstLine := s.first.line
	firstLine.RememberAutofix("Sorting the whole file.")
	firstLine.logAutofix()
	firstLine.changed = true // Otherwise the changes won’t be saved
	lines := []*Line{firstLine}
	lines = append(lines, s.after[s.first]...)
	for _, pline := range s.plines {
		lines = append(lines, pline.line)
		lines = append(lines, s.after[pline]...)
	}
	s.autofixed = SaveAutofixChanges(lines)
}
