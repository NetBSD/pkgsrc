package main

import (
	"netbsd.org/pkglint/regex"
	"netbsd.org/pkglint/trace"
	"path"
	"sort"
	"strings"
)

func ChecklinesPlist(lines []Line) {
	if trace.Tracing {
		defer trace.Call1(lines[0].Filename)()
	}

	CheckLineRcsid(lines[0], `@comment `, "@comment ")

	if len(lines) == 1 {
		lines[0].Warnf("PLIST files shouldn't be empty.")
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
		"",
		Once{}}
	ck.Check(lines)
}

type PlistChecker struct {
	allFiles  map[string]*PlistLine
	allDirs   map[string]*PlistLine
	lastFname string
	once      Once
}

type PlistLine struct {
	line      Line
	condition string // e.g. PLIST.docs
	text      string // Like line.text, without the condition
}

func (ck *PlistChecker) Check(plainLines []Line) {
	plines := ck.NewLines(plainLines)
	ck.collectFilesAndDirs(plines)

	if fname := plines[0].line.Filename; path.Base(fname) == "PLIST.common_end" {
		commonLines := Load(strings.TrimSuffix(fname, "_end"), NotEmpty)
		if commonLines != nil {
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

func (ck *PlistChecker) NewLines(lines []Line) []*PlistLine {
	plines := make([]*PlistLine, len(lines))
	for i, line := range lines {
		condition, text := "", line.Text
		if hasPrefix(text, "${PLIST.") {
			if m, cond, rest := match2(text, `^(?:\$\{(PLIST\.[\w-.]+)\})+(.*)`); m {
				condition, text = cond, rest
			}
		}
		plines[i] = &PlistLine{line, condition, text}
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
				if prev := ck.allFiles[text]; prev == nil || pline.condition < prev.condition {
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
	} else if text == "" {
		fix := pline.line.Autofix()
		fix.Warnf("PLISTs should not contain empty lines.")
		fix.Delete()
		fix.Apply()
	} else {
		pline.line.Warnf("Unknown line type.")
	}
}

func (ck *PlistChecker) checkpath(pline *PlistLine) {
	line, text := pline.line, pline.text
	sdirname, basename := path.Split(text)
	dirname := strings.TrimSuffix(sdirname, "/")

	ck.checkSorted(pline)
	ck.checkDuplicate(pline)

	if contains(basename, "${IMAKE_MANNEWSUFFIX}") {
		pline.warnImakeMannewsuffix()
	}
	if hasPrefix(text, "${PKGMANDIR}/") {
		fix := pline.line.Autofix()
		fix.Notef("PLIST files should mention \"man/\" instead of \"${PKGMANDIR}\".")
		fix.Explain(
			"The pkgsrc infrastructure takes care of replacing the correct value",
			"when generating the actual PLIST for the package.")
		fix.Replace("${PKGMANDIR}/", "man/")
		fix.Apply()

		pline.text = strings.Replace(pline.text, "${PKGMANDIR}/", "man/", 1)
	}

	topdir := ""
	if firstSlash := strings.IndexByte(text, '/'); firstSlash != -1 {
		topdir = text[:firstSlash]
	}

	switch topdir {
	case "bin":
		ck.checkpathBin(pline, dirname, basename)
	case "doc":
		line.Errorf("Documentation must be installed under share/doc, not doc.")
	case "etc":
		ck.checkpathEtc(pline, dirname, basename)
	case "info":
		ck.checkpathInfo(pline, dirname, basename)
	case "lib":
		ck.checkpathLib(pline, dirname, basename)
	case "man":
		ck.checkpathMan(pline)
	case "share":
		ck.checkpathShare(pline)
	}

	if contains(text, "${PKGLOCALEDIR}") && G.Pkg != nil && !G.Pkg.vars.Defined("USE_PKGLOCALEDIR") {
		line.Warnf("PLIST contains ${PKGLOCALEDIR}, but USE_PKGLOCALEDIR was not found.")
	}

	if contains(text, "/CVS/") {
		line.Warnf("CVS files should not be in the PLIST.")
	}
	if hasSuffix(text, ".orig") {
		line.Warnf(".orig files should not be in the PLIST.")
	}
	if hasSuffix(text, "/perllocal.pod") {
		line.Warnf("perllocal.pod files should not be in the PLIST.")
		Explain(
			"This file is handled automatically by the INSTALL/DEINSTALL scripts,",
			"since its contents changes frequently.")
	}
	if contains(text, ".egg-info/") {
		line.Warnf("Include \"../../lang/python/egg.mk\" instead of listing .egg-info files directly.")
	}
}

func (ck *PlistChecker) checkSorted(pline *PlistLine) {
	if text := pline.text; G.opts.WarnPlistSort && hasAlnumPrefix(text) && !containsVarRef(text) {
		if ck.lastFname != "" {
			if ck.lastFname > text && !G.opts.Autofix {
				pline.line.Warnf("%q should be sorted before %q.", text, ck.lastFname)
				Explain(
					"The files in the PLIST should be sorted alphabetically.",
					"To fix this, run \"pkglint -F PLIST\".")
			}
		}
		ck.lastFname = text
	}
}

func (ck *PlistChecker) checkDuplicate(pline *PlistLine) {
	text := pline.text
	if !hasAlnumPrefix(text) || containsVarRef(text) {
		return
	}

	prev := ck.allFiles[text]
	if prev == pline || prev.condition != "" {
		return
	}

	fix := pline.line.Autofix()
	fix.Errorf("Duplicate filename %q, already appeared in %s.",
		text, prev.line.ReferenceFrom(pline.line))
	fix.Delete()
	fix.Apply()
}

func (ck *PlistChecker) checkpathBin(pline *PlistLine, dirname, basename string) {
	if contains(dirname, "/") {
		pline.line.Warnf("The bin/ directory should not have subdirectories.")
		Explain(
			"The programs in bin/ are collected there to be executable by the",
			"user without having to type an absolute path.  This advantage does",
			"not apply to programs in subdirectories of bin/.  These programs",
			"should rather be placed in libexec/PKGBASE.")
		return
	}
}

func (ck *PlistChecker) checkpathEtc(pline *PlistLine, dirname, basename string) {
	if hasPrefix(pline.text, "etc/rc.d/") {
		pline.line.Errorf("RCD_SCRIPTS must not be registered in the PLIST. Please use the RCD_SCRIPTS framework.")
		return
	}

	pline.line.Errorf("Configuration files must not be registered in the PLIST. " +
		"Please use the CONF_FILES framework, which is described in mk/pkginstall/bsd.pkginstall.mk.")
}

func (ck *PlistChecker) checkpathInfo(pline *PlistLine, dirname, basename string) {
	if pline.text == "info/dir" {
		pline.line.Errorf("\"info/dir\" must not be listed. Use install-info to add/remove an entry.")
		return
	}

	if G.Pkg != nil && !G.Pkg.vars.Defined("INFO_FILES") {
		pline.line.Warnf("Packages that install info files should set INFO_FILES.")
	}
}

func (ck *PlistChecker) checkpathLib(pline *PlistLine, dirname, basename string) {
	switch {
	case G.Pkg != nil && G.Pkg.EffectivePkgbase != "" && hasPrefix(pline.text, "lib/"+G.Pkg.EffectivePkgbase+"/"):
		return

	case pline.text == "lib/charset.alias" && (G.Pkg == nil || G.Pkg.Pkgpath != "converters/libiconv"):
		pline.line.Errorf("Only the libiconv package may install lib/charset.alias.")
		return

	case hasPrefix(pline.text, "lib/locale/"):
		pline.line.Errorf("\"lib/locale\" must not be listed. Use ${PKGLOCALEDIR}/locale and set USE_PKGLOCALEDIR instead.")
		return
	}

	switch ext := path.Ext(basename); ext {
	case ".a", ".la", ".so":
		if ext == "la" {
			if G.Pkg != nil && !G.Pkg.vars.Defined("USE_LIBTOOL") {
				pline.line.Warnf("Packages that install libtool libraries should define USE_LIBTOOL.")
			}
		}
	}

	if contains(basename, ".a") || contains(basename, ".so") {
		if m, noext := match1(pline.text, `^(.*)(?:\.a|\.so[0-9.]*)$`); m {
			if laLine := ck.allFiles[noext+".la"]; laLine != nil {
				pline.line.Warnf("Redundant library found. The libtool library is in %s.",
					laLine.line.ReferenceFrom(pline.line))
			}
		}
	}
}

func (ck *PlistChecker) checkpathMan(pline *PlistLine) {
	line := pline.line

	m, catOrMan, section, manpage, ext, gz := regex.Match5(pline.text, `^man/(cat|man)(\w+)/(.*?)\.(\w+)(\.gz)?$`)
	if !m {
		// maybe: line.Warnf("Invalid filename %q for manual page.", text)
		return
	}

	if !matches(section, `^[\dln]$`) {
		line.Warnf("Unknown section %q for manual page.", section)
	}

	if catOrMan == "cat" && ck.allFiles["man/man"+section+"/"+manpage+"."+section] == nil {
		line.Warnf("Preformatted manual page without unformatted one.")
	}

	if catOrMan == "cat" {
		if ext != "0" {
			line.Warnf("Preformatted manual pages should end in \".0\".")
		}
	} else {
		if !hasPrefix(ext, section) {
			line.Warnf("Mismatch between the section (%s) and extension (%s) of the manual page.", section, ext)
		}
	}

	if gz != "" {
		fix := line.Autofix()
		fix.Notef("The .gz extension is unnecessary for manual pages.")
		fix.Explain(
			"Whether the manual pages are installed in compressed form or not is",
			"configured by the pkgsrc user.  Compression and decompression takes",
			"place automatically, no matter if the .gz extension is mentioned in",
			"the PLIST or not.")
		fix.ReplaceRegex(`\.gz\n`, "\n", 1)
		fix.Apply()
	}
}

func (ck *PlistChecker) checkpathShare(pline *PlistLine) {
	line, text := pline.line, pline.text
	switch {
	case hasPrefix(text, "share/icons/") && G.Pkg != nil:
		if hasPrefix(text, "share/icons/hicolor/") && G.Pkg.Pkgpath != "graphics/hicolor-icon-theme" {
			f := "../../graphics/hicolor-icon-theme/buildlink3.mk"
			if G.Pkg.included[f] == nil && ck.once.FirstTime("hicolor-icon-theme") {
				line.Errorf("Packages that install hicolor icons must include %q in the Makefile.", f)
			}
		}

		if hasPrefix(text, "share/icons/gnome") && G.Pkg.Pkgpath != "graphics/gnome-icon-theme" {
			f := "../../graphics/gnome-icon-theme/buildlink3.mk"
			if G.Pkg.included[f] == nil {
				line.Errorf("The package Makefile must include %q.", f)
				Explain(
					"Packages that install GNOME icons must maintain the icon theme",
					"cache.")
			}
		}

		if contains(text[12:], "/") && !G.Pkg.vars.Defined("ICON_THEMES") && ck.once.FirstTime("ICON_THEMES") {
			line.Warnf("Packages that install icon theme files should set ICON_THEMES.")
		}

	case hasPrefix(text, "share/doc/html/"):
		if G.opts.WarnPlistDepr {
			line.Warnf("Use of \"share/doc/html\" is deprecated. Use \"share/doc/${PKGBASE}\" instead.")
		}

	case G.Pkg != nil && G.Pkg.EffectivePkgbase != "" && (hasPrefix(text, "share/doc/"+G.Pkg.EffectivePkgbase+"/") ||
		hasPrefix(text, "share/examples/"+G.Pkg.EffectivePkgbase+"/")):
		// Fine.

	case text == "share/icons/hicolor/icon-theme.cache" && G.Pkg != nil && G.Pkg.Pkgpath != "graphics/hicolor-icon-theme":
		line.Errorf("This file must not appear in any PLIST file.")
		Explain(
			"Remove this line and add the following line to the package Makefile.",
			"",
			".include \"../../graphics/hicolor-icon-theme/buildlink3.mk\"")

	case hasPrefix(text, "share/info/"):
		line.Warnf("Info pages should be installed into info/, not share/info/.")
		Explain(
			"To fix this, you should add INFO_FILES=yes to the package Makefile.")

	case hasPrefix(text, "share/locale/") && hasSuffix(text, ".mo"):
		// Fine.

	case hasPrefix(text, "share/man/"):
		line.Warnf("Man pages should be installed into man/, not share/man/.")
	}
}

func (pline *PlistLine) CheckTrailingWhitespace() {
	if hasSuffix(pline.text, " ") || hasSuffix(pline.text, "\t") {
		pline.line.Errorf("pkgsrc does not support filenames ending in white-space.")
		Explain(
			"Each character in the PLIST is relevant, even trailing white-space.")
	}
}

func (pline *PlistLine) CheckDirective(cmd, arg string) {
	line := pline.line

	if cmd == "unexec" {
		if m, dir := match1(arg, `^(?:rmdir|\$\{RMDIR\} \%D/)(.*)`); m {
			if !contains(dir, "true") && !contains(dir, "${TRUE}") {
				pline.line.Warnf("Please remove this line. It is no longer necessary.")
			}
		}
	}

	switch cmd {
	case "exec", "unexec":
		switch {
		case contains(arg, "install-info"),
			contains(arg, "${INSTALL_INFO}"):
			line.Warnf("@exec/unexec install-info is deprecated.")
		case contains(arg, "ldconfig") && !contains(arg, "/usr/bin/true"):
			pline.line.Errorf("ldconfig must be used with \"||/usr/bin/true\".")
		}

	case "comment":
		// Nothing to do.

	case "dirrm":
		line.Warnf("@dirrm is obsolete. Please remove this line.")
		Explain(
			"Directories are removed automatically when they are empty.",
			"When a package needs an empty directory, it can use the @pkgdir",
			"command in the PLIST")

	case "imake-man":
		args := splitOnSpace(arg)
		switch {
		case len(args) != 3:
			line.Warnf("Invalid number of arguments for imake-man.")
		case args[2] == "${IMAKE_MANNEWSUFFIX}":
			pline.warnImakeMannewsuffix()
		}

	case "pkgdir":
		// Nothing to check.

	default:
		line.Warnf("Unknown PLIST directive \"@%s\".", cmd)
	}
}

func (pline *PlistLine) warnImakeMannewsuffix() {
	pline.line.Warnf("IMAKE_MANNEWSUFFIX is not meant to appear in PLISTs.")
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
	header     []*PlistLine // Does not take part in sorting
	middle     []*PlistLine // Only this part is sorted
	footer     []*PlistLine // Does not take part in sorting, typically contains @exec or @pkgdir
	unsortable Line         // Some lines so difficult to sort that only humans can do that
	changed    bool         // Whether the sorting actually changed something
	autofixed  bool         // Whether the newly sorted file has been written to disk
}

func NewPlistLineSorter(plines []*PlistLine) *plistLineSorter {
	headerEnd := 0
	for headerEnd < len(plines) && hasPrefix(plines[headerEnd].text, "@comment") {
		headerEnd++
	}

	footerStart := len(plines)
	for footerStart > headerEnd && hasPrefix(plines[footerStart-1].text, "@") {
		footerStart--
	}

	header := plines[0:headerEnd]
	middle := plines[headerEnd:footerStart]
	footer := plines[footerStart:]
	var unsortable Line

	for _, pline := range middle {
		if unsortable == nil && (hasPrefix(pline.text, "@") || contains(pline.text, "$")) {
			unsortable = pline.line
		}
	}
	return &plistLineSorter{header, middle, footer, unsortable, false, false}
}

func (s *plistLineSorter) Sort() {
	if line := s.unsortable; line != nil {
		if G.opts.PrintAutofix || G.opts.Autofix {
			line.Notef("This line prevents pkglint from sorting the PLIST automatically.")
		}
		return
	}

	if !shallBeLogged("%q should be sorted before %q.") {
		return
	}
	if len(s.middle) == 0 {
		return
	}
	firstLine := s.middle[0].line

	sort.SliceStable(s.middle, func(i, j int) bool {
		mi := s.middle[i]
		mj := s.middle[j]
		less := mi.text < mj.text || (mi.text == mj.text &&
			mi.condition < mj.condition)
		if (i < j) != less {
			s.changed = true
		}
		return less
	})

	if !s.changed {
		return
	}

	fix := firstLine.Autofix()
	fix.Notef("Silent-Magic-Diagnostic")
	fix.Describef(int(firstLine.firstLine), "Sorting the whole file.")
	fix.Apply()

	var lines []Line
	for _, pline := range s.header {
		lines = append(lines, pline.line)
	}
	for _, pline := range s.middle {
		lines = append(lines, pline.line)
	}
	for _, pline := range s.footer {
		lines = append(lines, pline.line)
	}

	s.autofixed = SaveAutofixChanges(lines)
}
