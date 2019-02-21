package pkglint

import (
	"netbsd.org/pkglint/textproc"
	"path"
	"sort"
	"strings"
)

func CheckLinesPlist(lines Lines) {
	if trace.Tracing {
		defer trace.Call1(lines.FileName)()
	}

	lines.CheckRcsID(0, `@comment `, "@comment ")

	if lines.Len() == 1 {
		lines.Lines[0].Warnf("PLIST files shouldn't be empty.")
		G.Explain(
			"One reason for empty PLISTs is that this is a newly created package",
			sprintf("and that the author didn't run %q after installing the files.", bmake("print-PLIST")),
			"",
			"For most Perl packages, the final PLIST is generated automatically.",
			"Since the source PLIST is not used at all, it can be removed for these packages.",
			"",
			"Meta packages also don't need a PLIST file",
			"since their only purpose is to declare dependencies.")
	}

	ck := PlistChecker{
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
	Line
	conditions []string // e.g. PLIST.docs
	text       string   // Line.Text without any conditions of the form ${PLIST.cond}
}

func (ck *PlistChecker) Check(plainLines Lines) {
	plines := ck.NewLines(plainLines)
	ck.collectFilesAndDirs(plines)

	if plines[0].Basename == "PLIST.common_end" {
		commonLines := Load(strings.TrimSuffix(plines[0].Filename, "_end"), NotEmpty)
		if commonLines != nil {
			ck.collectFilesAndDirs(ck.NewLines(commonLines))
		}
	}

	for _, pline := range plines {
		ck.checkLine(pline)
		pline.CheckTrailingWhitespace()
	}
	CheckLinesTrailingEmptyLines(plainLines)

	sorter := NewPlistLineSorter(plines)
	sorter.Sort()
	if !sorter.autofixed {
		SaveAutofixChanges(plainLines)
	}
}

func (ck *PlistChecker) NewLines(lines Lines) []*PlistLine {
	plines := make([]*PlistLine, lines.Len())
	for i, line := range lines.Lines {
		var conditions []string
		text := line.Text

		for hasPrefix(text, "${PLIST.") /* just for performance */ {
			if m, cond, rest := match2(text, `^(?:\$\{(PLIST\.[\w-.]+)\})(.*)`); m {
				conditions = append(conditions, cond)
				text = rest
			} else {
				break
			}
		}

		plines[i] = &PlistLine{line, conditions, text}
	}
	return plines
}

var plistLineStart = textproc.NewByteSet("$0-9A-Za-z")

func (ck *PlistChecker) collectFilesAndDirs(plines []*PlistLine) {

	for _, pline := range plines {
		if text := pline.text; len(text) > 0 {
			first := text[0]
			switch {
			case plistLineStart.Contains(first):
				if prev := ck.allFiles[text]; prev == nil || stringSliceLess(pline.conditions, prev.conditions) {
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

func (ck *PlistChecker) checkLine(pline *PlistLine) {
	text := pline.text

	if text == "" {
		fix := pline.Autofix()
		fix.Warnf("PLISTs should not contain empty lines.")
		fix.Delete()
		fix.Apply()

	} else if textproc.AlnumU.Contains(text[0]) || text[0] == '$' {
		ck.checkPath(pline)

	} else if m, cmd, arg := match2(text, `^@([a-z-]+)[\t ]*(.*)`); m {
		pline.CheckDirective(cmd, arg)

	} else {
		pline.Warnf("Invalid line type: %s", pline.Line.Text)
	}
}

func (ck *PlistChecker) checkPath(pline *PlistLine) {
	text := pline.text
	dirSlash, basename := path.Split(text)
	dirname := strings.TrimSuffix(dirSlash, "/")

	ck.checkSorted(pline)
	ck.checkDuplicate(pline)

	if contains(basename, "${IMAKE_MANNEWSUFFIX}") {
		pline.warnImakeMannewsuffix()
	}

	if hasPrefix(text, "${PKGMANDIR}/") {
		fix := pline.Autofix()
		fix.Notef("PLIST files should use \"man/\" instead of \"${PKGMANDIR}\".")
		fix.Explain(
			"The pkgsrc infrastructure takes care of replacing the correct value",
			"when generating the actual PLIST for the package.")
		fix.Replace("${PKGMANDIR}/", "man/")
		fix.Apply()

		// Since the autofix only applies to the Line, the PlistLine needs to be updated manually.
		pline.text = strings.Replace(pline.text, "${PKGMANDIR}/", "man/", 1)
	}

	topdir := strings.SplitN(text, "/", 2)[0]

	switch topdir {
	case "bin":
		ck.checkPathBin(pline, dirname, basename)
	case "doc":
		pline.Errorf("Documentation must be installed under share/doc, not doc.")
	case "etc":
		ck.checkPathEtc(pline, dirname, basename)
	case "info":
		ck.checkPathInfo(pline, dirname, basename)
	case "lib":
		ck.checkPathLib(pline, dirname, basename)
	case "man":
		ck.checkPathMan(pline)
	case "share":
		ck.checkPathShare(pline)
	}

	if contains(text, "${PKGLOCALEDIR}") && G.Pkg != nil && !G.Pkg.vars.Defined("USE_PKGLOCALEDIR") {
		pline.Warnf("PLIST contains ${PKGLOCALEDIR}, but USE_PKGLOCALEDIR is not set in the package Makefile.")
	}

	if contains(text, "/CVS/") {
		pline.Warnf("CVS files should not be in the PLIST.")
	}
	if hasSuffix(text, ".orig") {
		pline.Warnf(".orig files should not be in the PLIST.")
	}
	if hasSuffix(text, "/perllocal.pod") {
		pline.Warnf("The perllocal.pod file should not be in the PLIST.")
		G.Explain(
			"This file is handled automatically by the INSTALL/DEINSTALL scripts",
			"since its contents depends on more than one package.")
	}
	if contains(text, ".egg-info/") {
		pline.Warnf("Include \"../../lang/python/egg.mk\" instead of listing .egg-info files directly.")
	}
}

func (ck *PlistChecker) checkSorted(pline *PlistLine) {
	if text := pline.text; hasAlnumPrefix(text) && !containsVarRef(text) {
		if ck.lastFname != "" {
			if ck.lastFname > text && !G.Logger.Opts.Autofix {
				pline.Warnf("%q should be sorted before %q.", text, ck.lastFname)
				G.Explain(
					"The files in the PLIST should be sorted alphabetically.",
					"This allows human readers to quickly see whether a file is included or not.")
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
	if prev == pline || len(prev.conditions) > 0 {
		return
	}

	fix := pline.Autofix()
	fix.Errorf("Duplicate filename %q, already appeared in %s.", text, pline.RefTo(prev.Line))
	fix.Delete()
	fix.Apply()
}

func (ck *PlistChecker) checkPathBin(pline *PlistLine, dirname, basename string) {
	if contains(dirname, "/") {
		pline.Warnf("The bin/ directory should not have subdirectories.")
		G.Explain(
			"The programs in bin/ are collected there to be executable by the",
			"user without having to type an absolute path.",
			"This advantage does not apply to programs in subdirectories of bin/.",
			"These programs should rather be placed in libexec/PKGBASE.")
		return
	}
}

func (ck *PlistChecker) checkPathEtc(pline *PlistLine, dirname, basename string) {
	if hasPrefix(pline.text, "etc/rc.d/") {
		pline.Errorf("RCD_SCRIPTS must not be registered in the PLIST.")
		pline.Explain(
			"Please use the RCD_SCRIPTS framework, which is described in mk/pkginstall/bsd.pkginstall.mk.")
		return
	}

	pline.Errorf("Configuration files must not be registered in the PLIST.")
	pline.Explain(
		"Please use the CONF_FILES framework, which is described in mk/pkginstall/bsd.pkginstall.mk.")
}

func (ck *PlistChecker) checkPathInfo(pline *PlistLine, dirname, basename string) {
	if pline.text == "info/dir" {
		pline.Errorf("\"info/dir\" must not be listed. Use install-info to add/remove an entry.")
		return
	}

	if G.Pkg != nil && !G.Pkg.vars.Defined("INFO_FILES") {
		pline.Warnf("Packages that install info files should set INFO_FILES in the Makefile.")
	}
}

func (ck *PlistChecker) checkPathLib(pline *PlistLine, dirname, basename string) {
	switch {
	case G.Pkg != nil && G.Pkg.EffectivePkgbase != "" && hasPrefix(pline.text, "lib/"+G.Pkg.EffectivePkgbase+"/"):
		return

	case pline.text == "lib/charset.alias" && (G.Pkg == nil || G.Pkg.Pkgpath != "converters/libiconv"):
		pline.Errorf("Only the libiconv package may install lib/charset.alias.")
		return

	case hasPrefix(pline.text, "lib/locale/"):
		pline.Errorf("\"lib/locale\" must not be listed. Use ${PKGLOCALEDIR}/locale and set USE_PKGLOCALEDIR instead.")
		return
	}

	switch ext := path.Ext(basename); ext {
	case ".la":
		if G.Pkg != nil && !G.Pkg.vars.Defined("USE_LIBTOOL") && ck.once.FirstTime("USE_LIBTOOL") {
			pline.Warnf("Packages that install libtool libraries should define USE_LIBTOOL.")
		}
	}

	if contains(basename, ".a") || contains(basename, ".so") {
		if m, noext := match1(pline.text, `^(.*)(?:\.a|\.so[0-9.]*)$`); m {
			if laLine := ck.allFiles[noext+".la"]; laLine != nil {
				pline.Warnf("Redundant library found. The libtool library is in %s.", pline.RefTo(laLine.Line))
			}
		}
	}
}

func (ck *PlistChecker) checkPathMan(pline *PlistLine) {
	m, catOrMan, section, manpage, ext, gz := match5(pline.text, `^man/(cat|man)(\w+)/(.*?)\.(\w+)(\.gz)?$`)
	if !m {
		// maybe: line.Warnf("Invalid filename %q for manual page.", text)
		return
	}

	if !matches(section, `^[0-9ln]$`) {
		pline.Warnf("Unknown section %q for manual page.", section)
	}

	if catOrMan == "cat" && ck.allFiles["man/man"+section+"/"+manpage+"."+section] == nil {
		pline.Warnf("Preformatted manual page without unformatted one.")
	}

	if catOrMan == "cat" {
		if ext != "0" {
			pline.Warnf("Preformatted manual pages should end in \".0\".")
		}
	} else {
		if !hasPrefix(ext, section) {
			pline.Warnf("Mismatch between the section (%s) and extension (%s) of the manual page.", section, ext)
		}
	}

	if gz != "" {
		fix := pline.Autofix()
		fix.Notef("The .gz extension is unnecessary for manual pages.")
		fix.Explain(
			"Whether the manual pages are installed in compressed form or not is",
			"configured by the pkgsrc user.",
			"Compression and decompression takes place automatically,",
			"no matter if the .gz extension is mentioned in the PLIST or not.")
		fix.ReplaceRegex(`\.gz\n`, "\n", 1)
		fix.Apply()
	}
}

func (ck *PlistChecker) checkPathShare(pline *PlistLine) {
	text := pline.text
	switch {
	case hasPrefix(text, "share/icons/") && G.Pkg != nil:
		if hasPrefix(text, "share/icons/hicolor/") && G.Pkg.Pkgpath != "graphics/hicolor-icon-theme" {
			f := "../../graphics/hicolor-icon-theme/buildlink3.mk"
			if G.Pkg.included[f] == nil && ck.once.FirstTime("hicolor-icon-theme") {
				pline.Errorf("Packages that install hicolor icons must include %q in the Makefile.", f)
			}
		}

		if text == "share/icons/hicolor/icon-theme.cache" && G.Pkg.Pkgpath != "graphics/hicolor-icon-theme" {
			pline.Errorf("The file icon-theme.cache must not appear in any PLIST file.")
			G.Explain(
				"Remove this line and add the following line to the package Makefile.",
				"",
				".include \"../../graphics/hicolor-icon-theme/buildlink3.mk\"")
		}

		if hasPrefix(text, "share/icons/gnome") && G.Pkg.Pkgpath != "graphics/gnome-icon-theme" {
			f := "../../graphics/gnome-icon-theme/buildlink3.mk"
			if G.Pkg.included[f] == nil {
				pline.Errorf("The package Makefile must include %q.", f)
				G.Explain(
					"Packages that install GNOME icons must maintain the icon theme",
					"cache.")
			}
		}

		if contains(text[12:], "/") && !G.Pkg.vars.Defined("ICON_THEMES") && ck.once.FirstTime("ICON_THEMES") {
			pline.Warnf("Packages that install icon theme files should set ICON_THEMES.")
		}

	case hasPrefix(text, "share/doc/html/"):
		pline.Warnf("Use of \"share/doc/html\" is deprecated. Use \"share/doc/${PKGBASE}\" instead.")

	case G.Pkg != nil && G.Pkg.EffectivePkgbase != "" && (hasPrefix(text, "share/doc/"+G.Pkg.EffectivePkgbase+"/") ||
		hasPrefix(text, "share/examples/"+G.Pkg.EffectivePkgbase+"/")):
		// Fine.

	case hasPrefix(text, "share/info/"):
		pline.Warnf("Info pages should be installed into info/, not share/info/.")
		G.Explain(
			"To fix this, add INFO_FILES=yes to the package Makefile.")

	case hasPrefix(text, "share/man/"):
		pline.Warnf("Man pages should be installed into man/, not share/man/.")
	}
}

func (pline *PlistLine) CheckTrailingWhitespace() {
	if hasSuffix(pline.text, " ") || hasSuffix(pline.text, "\t") {
		pline.Errorf("Pkgsrc does not support filenames ending in whitespace.")
		G.Explain(
			"Each character in the PLIST is relevant, even trailing whitespace.")
	}
}

func (pline *PlistLine) CheckDirective(cmd, arg string) {
	if cmd == "unexec" {
		if m, dir := match1(arg, `^(?:rmdir|\$\{RMDIR\} %D/)(.*)`); m {
			if !contains(dir, "true") && !contains(dir, "${TRUE}") {
				fix := pline.Autofix()
				fix.Warnf("Please remove this line. It is no longer necessary.")
				fix.Delete()
				fix.Apply()
			}
		}
	}

	switch cmd {
	case "exec", "unexec":
		switch {
		case contains(arg, "ldconfig") && !contains(arg, "/usr/bin/true"):
			pline.Errorf("The ldconfig command must be used with \"||/usr/bin/true\".")
		}

	case "comment":
		// Nothing to check.

	case "dirrm":
		pline.Warnf("@dirrm is obsolete. Please remove this line.")
		G.Explain(
			"Directories are removed automatically when they are empty.",
			"When a package needs an empty directory, it can use the @pkgdir",
			"command in the PLIST.")

	case "imake-man":
		args := strings.Fields(arg)
		switch {
		case len(args) != 3:
			pline.Warnf("Invalid number of arguments for imake-man, should be 3.")
		case args[2] == "${IMAKE_MANNEWSUFFIX}":
			pline.warnImakeMannewsuffix()
		}

	case "pkgdir":
		// Nothing to check.

	default:
		pline.Warnf("Unknown PLIST directive \"@%s\".", cmd)
	}
}

func (pline *PlistLine) warnImakeMannewsuffix() {
	pline.Warnf("IMAKE_MANNEWSUFFIX is not meant to appear in PLISTs.")
	G.Explain(
		"This is the result of a print-PLIST call that has not been edited",
		"manually by the package maintainer.",
		"Please replace the IMAKE_MANNEWSUFFIX with:",
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
	unsortable Line         // Some lines are so difficult to sort that only humans can do that
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
			unsortable = pline.Line
		}
	}
	return &plistLineSorter{header, middle, footer, unsortable, false, false}
}

func (s *plistLineSorter) Sort() {
	if line := s.unsortable; line != nil {
		if G.Logger.IsAutofix() {
			trace.Stepf("%s: This line prevents pkglint from sorting the PLIST automatically.", line)
		}
		return
	}

	if !G.shallBeLogged("%q should be sorted before %q.") {
		return
	}
	if len(s.middle) == 0 {
		return
	}
	firstLine := s.middle[0].Line

	sort.SliceStable(s.middle, func(i, j int) bool {
		mi := s.middle[i]
		mj := s.middle[j]
		less := mi.text < mj.text ||
			(mi.text == mj.text && stringSliceLess(mi.conditions, mj.conditions))
		if (i < j) != less {
			s.changed = true
		}
		return less
	})

	if !s.changed {
		return
	}

	fix := firstLine.Autofix()
	fix.Notef(SilentAutofixFormat)
	fix.Describef(int(firstLine.firstLine), "Sorting the whole file.")
	fix.Apply()

	var lines []Line
	for _, pline := range s.header {
		lines = append(lines, pline.Line)
	}
	for _, pline := range s.middle {
		lines = append(lines, pline.Line)
	}
	for _, pline := range s.footer {
		lines = append(lines, pline.Line)
	}

	s.autofixed = SaveAutofixChanges(NewLines(lines[0].Filename, lines))
}
