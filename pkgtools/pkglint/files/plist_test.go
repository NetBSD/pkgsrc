package pkglint

import "gopkg.in/check.v1"

func (s *Suite) Test_CheckLinesPlist(c *check.C) {
	t := s.Init(c)

	G.Pkg = NewPackage(t.File("category/pkgbase"))
	lines := t.NewLines("PLIST",
		"bin/i386/6c",
		"bin/program",
		"etc/my.cnf",
		"etc/rc.d/service",
		"@exec ${MKDIR} include/pkgbase",
		"info/dir",
		"lib/c.so",
		"lib/libc.so.6",
		"lib/libc.la",
		"${PLIST.man}man/cat3/strcpy.4",
		"man/man1/imake.${IMAKE_MANNEWSUFFIX}",
		"${PLIST.obsolete}@unexec rmdir /tmp",
		"sbin/clockctl",
		"share/icons/gnome/delete-icon",
		"share/icons/hicolor/icon1.png",
		"share/icons/hicolor/icon2.png", // No additional error for hicolor-icon-theme.
		"share/tzinfo",
		"share/tzinfo")

	CheckLinesPlist(G.Pkg, lines)

	t.CheckOutputLines(
		"ERROR: PLIST:1: Expected \"@comment $"+"NetBSD$\".",
		"WARN: PLIST:1: The bin/ directory should not have subdirectories.",
		"ERROR: PLIST:3: Configuration files must not be registered in the PLIST.",
		"ERROR: PLIST:4: RCD_SCRIPTS must not be registered in the PLIST.",
		"ERROR: PLIST:6: \"info/dir\" must not be listed. Use install-info to add/remove an entry.",
		"WARN: PLIST:8: Redundant library found. The libtool library is in line 9.",
		"WARN: PLIST:9: \"lib/libc.la\" should be sorted before \"lib/libc.so.6\".",
		"WARN: PLIST:9: Packages that install libtool libraries should define USE_LIBTOOL.",
		"WARN: PLIST:10: Preformatted manual page without unformatted one.",
		"WARN: PLIST:10: Preformatted manual pages should end in \".0\".",
		"WARN: PLIST:11: IMAKE_MANNEWSUFFIX is not meant to appear in PLISTs.",
		"WARN: PLIST:12: Please remove this line. It is no longer necessary.",
		"ERROR: PLIST:14: The package Makefile must include \"../../graphics/gnome-icon-theme/buildlink3.mk\".",
		"WARN: PLIST:14: Packages that install icon theme files should set ICON_THEMES.",
		"ERROR: PLIST:15: Packages that install hicolor icons "+
			"must include \"../../graphics/hicolor-icon-theme/buildlink3.mk\" in the Makefile.",
		"ERROR: PLIST:18: Duplicate filename \"share/tzinfo\", already appeared in line 17.")
}

func (s *Suite) Test_CheckLinesPlist__single_file_no_comment(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("PLIST",
		"bin/program")

	CheckLinesPlist(nil, lines)

	t.CheckOutputLines(
		"ERROR: PLIST:1: Expected \"" + PlistCvsID + "\".")
}

// When a PLIST contains multiple libtool libraries, USE_LIBTOOL needs only
// be defined once in the package Makefile. Therefore, a single warning is enough.
func (s *Suite) Test_CheckLinesPlist__multiple_libtool_libraries(c *check.C) {
	t := s.Init(c)

	G.Pkg = NewPackage(t.File("category/pkgbase"))
	lines := t.NewLines("PLIST",
		PlistCvsID,
		"lib/libc.la",
		"lib/libm.la")

	CheckLinesPlist(G.Pkg, lines)

	t.CheckOutputLines(
		"WARN: PLIST:2: Packages that install libtool libraries should define USE_LIBTOOL.")
}

func (s *Suite) Test_CheckLinesPlist__empty(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("PLIST",
		PlistCvsID)

	CheckLinesPlist(nil, lines)

	t.CheckOutputLines(
		"WARN: PLIST:1: PLIST files shouldn't be empty.")
}

func (s *Suite) Test_CheckLinesPlist__common_end(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("PLIST.common",
		PlistCvsID,
		"bin/common")
	lines := t.SetUpFileLines("PLIST.common_end",
		PlistCvsID,
		"sbin/common_end")

	CheckLinesPlist(nil, lines)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_CheckLinesPlist__common_end_without_common(c *check.C) {
	t := s.Init(c)

	lines := t.SetUpFileLines("PLIST.common_end",
		PlistCvsID,
		"sbin/common_end")

	CheckLinesPlist(nil, lines)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_CheckLinesPlist__condition(c *check.C) {
	t := s.Init(c)

	G.Pkg = NewPackage(t.File("category/pkgbase"))
	lines := t.NewLines("PLIST",
		PlistCvsID,
		"${PLIST.bincmds}bin/subdir/command")

	CheckLinesPlist(G.Pkg, lines)

	t.CheckOutputLines(
		"WARN: PLIST:2: The bin/ directory should not have subdirectories.")
}

func (s *Suite) Test_CheckLinesPlist__sorting(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("PLIST",
		PlistCvsID,
		"@comment Do not remove",
		"sbin/i386/6c",
		"sbin/program",
		"bin/otherprogram",
		"${PLIST.condition}bin/cat")

	CheckLinesPlist(nil, lines)

	t.CheckOutputLines(
		"WARN: PLIST:5: \"bin/otherprogram\" should be sorted before \"sbin/program\".",
		"WARN: PLIST:6: \"bin/cat\" should be sorted before \"bin/otherprogram\".")
}

func (s *Suite) Test_CheckLinesPlist__sort_common(c *check.C) {
	t := s.Init(c)

	// TODO: Examine what happens if there is a PLIST.common to be sorted.

	t.CheckOutputEmpty()
}

func (s *Suite) Test_plistLineSorter_Sort(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("--autofix")
	lines := t.SetUpFileLines("PLIST",
		PlistCvsID,
		"@comment Do not remove",
		"A",
		"b",
		"CCC",
		"lib/${UNKNOWN}.la",
		"C",
		"ddd",
		"@exec echo \"after ddd\"", // Makes the PLIST unsortable
		"sbin/program",
		"${PLIST.one}bin/program",
		"man/man1/program.1",
		"${PLIST.two}bin/program2",
		"lib/before.la",
		"${PLIST.linux}${PLIST.x86_64}lib/lib-linux-x86_64.so", // Double condition, see graphics/graphviz
		"lib/after.la",
		"@exec echo \"after lib/after.la\"")
	ck := PlistChecker{nil, nil, nil, "", Once{}, false}
	plines := ck.NewLines(lines)

	sorter1 := NewPlistLineSorter(plines)
	c.Check(sorter1.unsortable, equals, lines.Lines[5])

	cleanedLines := append(append(lines.Lines[0:5], lines.Lines[6:8]...), lines.Lines[9:]...) // Remove ${UNKNOWN} and @exec

	sorter2 := NewPlistLineSorter((&PlistChecker{nil, nil, nil, "", Once{}, false}).
		NewLines(NewLines(lines.Filename, cleanedLines)))

	c.Check(sorter2.unsortable, check.IsNil)

	sorter2.Sort()

	t.CheckOutputLines(
		"AUTOFIX: ~/PLIST:3: Sorting the whole file.")
	t.CheckFileLines("PLIST",
		PlistCvsID,
		"@comment Do not remove", // The header ends here
		"A",
		"C",
		"CCC",
		"b",
		"${PLIST.one}bin/program", // Conditional lines are ignored during sorting
		"${PLIST.two}bin/program2",
		"ddd",
		"lib/after.la",
		"lib/before.la",
		"${PLIST.linux}${PLIST.x86_64}lib/lib-linux-x86_64.so",
		"man/man1/program.1",
		"sbin/program",
		"@exec echo \"after lib/after.la\"") // The footer starts here
}

func (s *Suite) Test_PlistChecker_checkLine(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("PLIST",
		PlistCvsID,
		"bin/program",
		"${PLIST.var}bin/conditional-program",
		"${PLIST.linux}${PLIST.arm}bin/arm-linux-only",
		"${PLIST.linux}${PLIST.arm-64}@exec echo 'This is Linux/arm64'",
		"${PLIST.ocaml-opt}share/ocaml",
		"${PLIST.ocaml-opt}@exec echo 'This is OCaml'",
		"${PLIST.ocaml-opt}@exec echo 'This is OCaml'",
		"${PYSITELIB:S,lib,share}/modifiers don't work in PLISTs",
		"${PLIST.empty}",
		"",
		"$prefix/bin",

		// This line does not count as a PLIST condition since it has
		// a :Q modifier, which does not work in PLISTs. Therefore the
		// ${PLIST.man:Q} is considered part of the filename.
		"${PLIST.man:Q}man/cat3/strlcpy.3",
		"<<<<<<<<< merge conflict")

	CheckLinesPlist(nil, lines)

	t.CheckOutputLines(
		"WARN: PLIST:3: \"bin/conditional-program\" should be sorted before \"bin/program\".",
		"WARN: PLIST:4: \"bin/arm-linux-only\" should be sorted before \"bin/conditional-program\".",
		"WARN: PLIST:10: PLISTs should not contain empty lines.",
		"WARN: PLIST:11: PLISTs should not contain empty lines.",
		"WARN: PLIST:14: Invalid line type: <<<<<<<<< merge conflict")
}

func (s *Suite) Test_PlistChecker_checkPathMan__gz(c *check.C) {
	t := s.Init(c)

	G.Pkg = NewPackage(t.File("category/pkgbase"))
	lines := t.NewLines("PLIST",
		PlistCvsID,
		"man/man3/strerror.3.gz")

	CheckLinesPlist(G.Pkg, lines)

	t.CheckOutputLines(
		"NOTE: PLIST:2: The .gz extension is unnecessary for manual pages.")
}

func (s *Suite) Test_PlistChecker_checkPath__PKGMANDIR(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("PLIST",
		PlistCvsID,
		"${PKGMANDIR}/man1/sh.1")

	CheckLinesPlist(nil, lines)

	t.CheckOutputLines(
		"NOTE: PLIST:2: PLIST files should use \"man/\" instead of \"${PKGMANDIR}\".")
}

func (s *Suite) Test_PlistChecker_checkPath__python_egg(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("PLIST",
		PlistCvsID,
		"${PYSITELIB}/gdspy-${PKGVERSION}-py${PYVERSSUFFIX}.egg-info/PKG-INFO")

	CheckLinesPlist(nil, lines)

	t.CheckOutputLines(
		"WARN: PLIST:2: Include \"../../lang/python/egg.mk\" instead of listing .egg-info files directly.")
}

func (s *Suite) Test_PlistChecker__autofix(c *check.C) {
	t := s.Init(c)

	lines := t.SetUpFileLines("PLIST",
		PlistCvsID,
		"lib/libvirt/connection-driver/libvirt_driver_storage.la",
		"${PLIST.hal}lib/libvirt/connection-driver/libvirt_driver_nodedev.la",
		"${PLIST.xen}lib/libvirt/connection-driver/libvirt_driver_libxl.la",
		"lib/libvirt/lock-driver/lockd.la",
		"${PKGMANDIR}/man1/sh.1",
		"share/augeas/lenses/virtlockd.aug",
		"share/doc/pkgname-1.0/html/32favicon.png",
		"share/doc/pkgname-1.0/html/404.html",
		"share/doc/pkgname-1.0/html/acl.html",
		"share/doc/pkgname-1.0/html/aclpolkit.html",
		"share/doc/pkgname-1.0/html/windows.html",
		"share/examples/libvirt/libvirt.conf",
		"share/locale/zh_CN/LC_MESSAGES/libvirt.mo",
		"share/locale/zh_TW/LC_MESSAGES/libvirt.mo",
		"share/locale/zu/LC_MESSAGES/libvirt.mo",
		"@pkgdir share/examples/libvirt/nwfilter",
		// Directives may contain arbitrary horizontal whitespace.
		"@pkgdir        etc/libvirt/qemu/networks/autostart",
		"@pkgdir        etc/logrotate.d",
		"@pkgdir        etc/sasl2")

	CheckLinesPlist(nil, lines)

	t.CheckOutputLines(
		"WARN: ~/PLIST:3: \"lib/libvirt/connection-driver/libvirt_driver_nodedev.la\" "+
			"should be sorted before \"lib/libvirt/connection-driver/libvirt_driver_storage.la\".",
		"WARN: ~/PLIST:4: \"lib/libvirt/connection-driver/libvirt_driver_libxl.la\" "+
			"should be sorted before \"lib/libvirt/connection-driver/libvirt_driver_nodedev.la\".",
		"NOTE: ~/PLIST:6: PLIST files should use \"man/\" instead of \"${PKGMANDIR}\".")

	t.SetUpCommandLine("-Wall", "--autofix")
	CheckLinesPlist(nil, lines)

	t.CheckOutputLines(
		"AUTOFIX: ~/PLIST:6: Replacing \"${PKGMANDIR}/\" with \"man/\".",
		"AUTOFIX: ~/PLIST:2: Sorting the whole file.")
	t.CheckFileLines("PLIST",
		PlistCvsID,
		"${PLIST.xen}lib/libvirt/connection-driver/libvirt_driver_libxl.la",
		"${PLIST.hal}lib/libvirt/connection-driver/libvirt_driver_nodedev.la",
		"lib/libvirt/connection-driver/libvirt_driver_storage.la",
		"lib/libvirt/lock-driver/lockd.la",
		"man/man1/sh.1",
		"share/augeas/lenses/virtlockd.aug",
		"share/doc/pkgname-1.0/html/32favicon.png",
		"share/doc/pkgname-1.0/html/404.html",
		"share/doc/pkgname-1.0/html/acl.html",
		"share/doc/pkgname-1.0/html/aclpolkit.html",
		"share/doc/pkgname-1.0/html/windows.html",
		"share/examples/libvirt/libvirt.conf",
		"share/locale/zh_CN/LC_MESSAGES/libvirt.mo",
		"share/locale/zh_TW/LC_MESSAGES/libvirt.mo",
		"share/locale/zu/LC_MESSAGES/libvirt.mo",
		"@pkgdir share/examples/libvirt/nwfilter",
		"@pkgdir        etc/libvirt/qemu/networks/autostart",
		"@pkgdir        etc/logrotate.d",
		"@pkgdir        etc/sasl2")
}

// When the same entry appears both with and without a condition,
// the one with the condition can be removed.
// When the same entry appears with several different conditions,
// all of them must stay.
func (s *Suite) Test_PlistChecker__remove_same_entries(c *check.C) {
	t := s.Init(c)

	lines := t.SetUpFileLines("PLIST",
		PlistCvsID,
		"${PLIST.option1}bin/true",
		"bin/true",
		"${PLIST.option1}bin/true",
		"bin/true",
		"${PLIST.option3}bin/false",
		"${PLIST.option2}bin/false",
		"bin/true")

	CheckLinesPlist(nil, lines)

	t.CheckOutputLines(
		"ERROR: ~/PLIST:2: Duplicate filename \"bin/true\", already appeared in line 3.",
		"ERROR: ~/PLIST:4: Duplicate filename \"bin/true\", already appeared in line 3.",
		"ERROR: ~/PLIST:5: Duplicate filename \"bin/true\", already appeared in line 3.",
		"WARN: ~/PLIST:6: \"bin/false\" should be sorted before \"bin/true\".",
		"ERROR: ~/PLIST:8: Duplicate filename \"bin/true\", already appeared in line 3.")

	t.SetUpCommandLine("-Wall", "--autofix")

	CheckLinesPlist(nil, lines)

	t.CheckOutputLines(
		"AUTOFIX: ~/PLIST:2: Deleting this line.",
		"AUTOFIX: ~/PLIST:4: Deleting this line.",
		"AUTOFIX: ~/PLIST:5: Deleting this line.",
		"AUTOFIX: ~/PLIST:8: Deleting this line.",
		"AUTOFIX: ~/PLIST:2: Sorting the whole file.")
	t.CheckFileLines("PLIST",
		PlistCvsID,
		"${PLIST.option2}bin/false",
		"${PLIST.option3}bin/false",
		"bin/true")
}

// When pkglint is run with the --only option, only the matched
// diagnostics must be autofixed. Up to 2018-03-12, the PLIST was
// sorted even if it didn't match the --only pattern.
func (s *Suite) Test_PlistChecker__autofix_with_only(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--autofix", "--only", "matches nothing")

	lines := t.SetUpFileLines("PLIST",
		PlistCvsID,
		"sbin/program",
		"bin/program")

	CheckLinesPlist(nil, lines)

	t.CheckOutputEmpty()
	t.CheckFileLines("PLIST",
		PlistCvsID,
		"sbin/program",
		"bin/program")
}

func (s *Suite) Test_PlistChecker__exec_MKDIR(c *check.C) {
	t := s.Init(c)

	lines := t.SetUpFileLines("PLIST",
		PlistCvsID,
		"bin/program",
		"@exec ${MKDIR} %D/share/mk/subdir")

	CheckLinesPlist(nil, lines)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_PlistChecker__empty_line(c *check.C) {
	t := s.Init(c)

	lines := t.SetUpFileLines("PLIST",
		PlistCvsID,
		"",
		"bin/program")

	CheckLinesPlist(nil, lines)

	t.CheckOutputLines(
		"WARN: ~/PLIST:2: PLISTs should not contain empty lines.")

	t.SetUpCommandLine("-Wall", "--autofix")

	CheckLinesPlist(nil, lines)

	t.CheckOutputLines(
		"AUTOFIX: ~/PLIST:2: Deleting this line.")
	t.CheckFileLines("PLIST",
		PlistCvsID,
		"bin/program")
}

func (s *Suite) Test_PlistChecker__invalid_line_type(c *check.C) {
	t := s.Init(c)

	lines := t.SetUpFileLines("PLIST",
		PlistCvsID,
		"---invalid",
		"+++invalid",
		"<<<<<<<< merge conflict",
		"======== merge conflict",
		">>>>>>>> merge conflict")

	CheckLinesPlist(nil, lines)

	t.CheckOutputLines(
		"WARN: ~/PLIST:2: Invalid line type: ---invalid",
		"WARN: ~/PLIST:3: Invalid line type: +++invalid",
		"WARN: ~/PLIST:4: Invalid line type: <<<<<<<< merge conflict",
		"WARN: ~/PLIST:5: Invalid line type: ======== merge conflict",
		"WARN: ~/PLIST:6: Invalid line type: >>>>>>>> merge conflict")
}

func (s *Suite) Test_PlistChecker_checkPathNonAscii(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--explain")
	lines := t.NewLines("PLIST",
		PlistCvsID,

		"dir1/fr\xFCher", // German, "back then", encoded in ISO 8859-1

		// Subsequent non-ASCII filenames do not generate further messages
		// since these filenames typically appear in groups, and issuing
		// too many warnings quickly gets boring.
		"dir1/\u00C4thernetz", // German

		// This ASCII-only pathname enables the check again.
		"dir2/aaa",
		"dir2/\u0633\u0644\u0627\u0645", // Arabic: salaam

		"dir2/\uC548\uB148", // Korean: annyeong

		// This ASCII-only pathname enables the check again.
		"dir3/ascii-only",

		// Any comment suppresses the check for the next contiguous
		// sequence of non-ASCII filenames.
		"@comment The next file is non-ASCII on purpose.",
		"dir3/\U0001F603", // Smiling face with open mouth

		// This ASCII-only pathname enables the check again.
		"sbin/iconv",

		"sbin/\U0001F603", // Smiling face with open mouth
	)

	CheckLinesPlist(nil, lines)

	t.CheckOutputLines(
		"WARN: PLIST:2: Non-ASCII filename \"dir1/fr<0xFC>her\".",
		"",
		"\tThe great majority of filenames installed by pkgsrc packages are",
		"\tASCII-only. Filenames containing non-ASCII characters can cause",
		"\tvarious problems since their name may already be different when",
		"\tanother character encoding is set in the locale.",
		"",
		"\tTo mark a filename as intentionally non-ASCII, insert a PLIST",
		"\t@comment with a convincing reason directly above this line. That",
		"\tcomment will allow this line and the lines directly below it to",
		"\tcontain non-ASCII filenames.",
		"",
		"WARN: PLIST:5: Non-ASCII filename \"dir2/<U+0633><U+0644><U+0627><U+0645>\".",
		"WARN: PLIST:11: Non-ASCII filename \"sbin/<U+1F603>\".")
}

func (s *Suite) Test_PlistChecker__doc(c *check.C) {
	t := s.Init(c)

	lines := t.SetUpFileLines("PLIST",
		PlistCvsID,
		"doc/html/index.html")

	CheckLinesPlist(nil, lines)

	t.CheckOutputLines(
		"ERROR: ~/PLIST:2: Documentation must be installed under share/doc, not doc.")
}

func (s *Suite) Test_PlistChecker__PKGLOCALEDIR(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.CreateFileLines("category/package/PLIST",
		PlistCvsID,
		"${PKGLOCALEDIR}/file")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputLines(
		"WARN: ~/category/package/PLIST:2: PLIST contains ${PKGLOCALEDIR}, " +
			"but USE_PKGLOCALEDIR is not set in the package Makefile.")
}

func (s *Suite) Test_PlistChecker__PKGLOCALEDIR_with_USE_PKGLOCALEDIR(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"USE_PKGLOCALEDIR=\tyes")
	t.CreateFileLines("category/package/PLIST",
		PlistCvsID,
		"${PKGLOCALEDIR}/file")
	t.FinishSetUp()

	G.Check(t.File("category/package"))
}

func (s *Suite) Test_PlistChecker__PKGLOCALEDIR_without_package(c *check.C) {
	t := s.Init(c)

	lines := t.SetUpFileLines("PLIST",
		PlistCvsID,
		"${PKGLOCALEDIR}/file")

	CheckLinesPlist(nil, lines)

	// When a PLIST file is checked on its own, outside of checking a
	// package, there can be no warning that USE_PKGLOCALEDIR is missing
	// in the package.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_PlistChecker_checkPath__unwanted_entries(c *check.C) {
	t := s.Init(c)

	lines := t.SetUpFileLines("PLIST",
		PlistCvsID,
		"share/perllocal.pod",
		"share/pkgbase/CVS/Entries",
		"share/pkgbase/Makefile.orig")

	CheckLinesPlist(nil, lines)

	t.CheckOutputLines(
		"WARN: ~/PLIST:2: The perllocal.pod file should not be in the PLIST.",
		"WARN: ~/PLIST:3: CVS files should not be in the PLIST.",
		"WARN: ~/PLIST:4: .orig files should not be in the PLIST.")
}

func (s *Suite) Test_PlistChecker_checkPathInfo(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package")
	t.Chdir("category/package")
	t.CreateFileLines("PLIST",
		PlistCvsID,
		"info/gmake.1.info")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputLines(
		"WARN: PLIST:2: Packages that install info files should set INFO_FILES in the Makefile.")
}

func (s *Suite) Test_PlistChecker_checkPathInfo__with_package(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"INFO_FILES=\tyes")
	t.Chdir("category/package")
	t.CreateFileLines("PLIST",
		PlistCvsID,
		"info/gmake.1.info")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputEmpty()
}

func (s *Suite) Test_PlistChecker_checkPathInfo__without_package(c *check.C) {
	t := s.Init(c)

	lines := t.SetUpFileLines("PLIST",
		PlistCvsID,
		"info/gmake.1.info")

	CheckLinesPlist(nil, lines)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_PlistChecker_checkPathLib(c *check.C) {
	t := s.Init(c)

	lines := t.SetUpFileLines("PLIST",
		PlistCvsID,
		"lib/charset.alias",
		"lib/liberty-1.0.a",
		"lib/liberty-1.0.archive",
		"lib/liberty-1.0.la",
		"lib/locale/de_DE/liberty.mo",
		"lib/package/liberty-1.0.so")
	G.Pkg = NewPackage(t.File("category/package"))
	G.Pkg.EffectivePkgbase = "package"

	CheckLinesPlist(G.Pkg, lines)

	t.CheckOutputLines(
		"ERROR: ~/PLIST:2: Only the libiconv package may install lib/charset.alias.",
		"WARN: ~/PLIST:3: Redundant library found. The libtool library is in line 5.",
		"WARN: ~/PLIST:5: Packages that install libtool libraries should define USE_LIBTOOL.",
		"ERROR: ~/PLIST:6: \"lib/locale\" must not be listed. "+
			"Use ${PKGLOCALEDIR}/locale and set USE_PKGLOCALEDIR instead.")
}

func (s *Suite) Test_PlistChecker_checkPathLib__libiconv(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("converters/libiconv")
	t.Chdir("converters/libiconv")
	t.CreateFileLines("PLIST",
		PlistCvsID,
		"lib/charset.alias")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputEmpty()
}

func (s *Suite) Test_PlistChecker_checkPathLib__libtool(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		"USE_LIBTOOL=\tyes")
	t.Chdir("category/package")
	t.CreateFileLines("PLIST",
		PlistCvsID,
		"lib/libname.la")
	t.FinishSetUp()

	G.Check(".")

	t.CheckOutputEmpty()
}

func (s *Suite) Test_PlistChecker_checkPathMan(c *check.C) {
	t := s.Init(c)

	lines := t.SetUpFileLines("PLIST",
		PlistCvsID,
		"man/cat1/formatted.0",
		"man/man1/formatted.1",
		"man/man1/program.8",
		"man/manx/program.x")

	CheckLinesPlist(nil, lines)

	t.CheckOutputLines(
		"WARN: ~/PLIST:4: Mismatch between the section (1) and extension (8) of the manual page.",
		"WARN: ~/PLIST:5: Unknown section \"x\" for manual page.")
}

func (s *Suite) Test_PlistChecker_checkPathShare(c *check.C) {
	t := s.Init(c)

	lines := t.SetUpFileLines("PLIST",
		PlistCvsID,
		"share/doc/html/package/index.html",
		"share/doc/package/index.html",
		"share/icons/hicolor/icon-theme.cache",
		"share/icons/open_24x24.svg",
		"share/info/program.1.info",
		"share/man/man1/program.1")
	G.Pkg = NewPackage(t.File("category/package"))
	G.Pkg.EffectivePkgbase = "package"

	CheckLinesPlist(G.Pkg, lines)

	t.CheckOutputLines(
		"WARN: ~/PLIST:2: Use of \"share/doc/html\" is deprecated. Use \"share/doc/${PKGBASE}\" instead.",
		"ERROR: ~/PLIST:4: Packages that install hicolor icons must include \"../../graphics/hicolor-icon-theme/buildlink3.mk\" in the Makefile.",
		"ERROR: ~/PLIST:4: The file icon-theme.cache must not appear in any PLIST file.",
		"WARN: ~/PLIST:4: Packages that install icon theme files should set ICON_THEMES.",
		"WARN: ~/PLIST:6: Info pages should be installed into info/, not share/info/.",
		"WARN: ~/PLIST:7: Man pages should be installed into man/, not share/man/.")
}

func (s *Suite) Test_PlistChecker_checkPathShareIcons__using_gnome_icon_theme(c *check.C) {
	t := s.Init(c)

	t.CreateFileDummyBuildlink3("graphics/gnome-icon-theme/buildlink3.mk")
	t.SetUpPackage("graphics/gnome-icon-theme-extras",
		"ICON_THEMES=\tyes",
		".include \"../../graphics/gnome-icon-theme/buildlink3.mk\"")
	t.CreateFileLines("graphics/gnome-icon-theme-extras/PLIST",
		PlistCvsID,
		"share/icons/gnome/16x16/devices/media-optical-cd-audio.png",
		"share/icons/gnome/16x16/devices/media-optical-dvd.png")
	t.FinishSetUp()
	t.Chdir(".")

	// This variant is typically run interactively.
	G.Check("graphics/gnome-icon-theme-extras")

	t.CheckOutputEmpty()

	// Note the leading "./".
	// This variant is typical for recursive runs of pkglint.
	G.Check("./graphics/gnome-icon-theme-extras")

	// Up to March 2019, a bug in relpath produced different behavior
	// depending on the leading dot.
	t.CheckOutputEmpty()
}

func (s *Suite) Test_PlistChecker_checkPathShareIcons__gnome_icon_theme_itself(c *check.C) {
	t := s.Init(c)

	t.CreateFileDummyBuildlink3("graphics/gnome-icon-theme/buildlink3.mk",
		"ICON_THEMES=\tyes")
	t.SetUpPackage("graphics/gnome-icon-theme",
		".include \"../../graphics/gnome-icon-theme/buildlink3.mk\"")
	t.CreateFileLines("graphics/gnome-icon-theme/PLIST",
		PlistCvsID,
		"share/icons/gnome/16x16/devices/media-optical-cd-audio.png",
		"share/icons/gnome/16x16/devices/media-optical-dvd.png")
	t.FinishSetUp()
	t.Chdir(".")

	G.Check("graphics/gnome-icon-theme")

	t.CheckOutputEmpty()
}

func (s *Suite) Test_PlistChecker_checkPathShareIcons(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("graphics/hicolor-icon-theme")
	t.CreateFileLines("graphics/hicolor-icon-theme/PLIST",
		PlistCvsID,
		"share/icons/hicolor/icon-theme.cache",
		"share/icons/hicolor/open.svg")
	t.SetUpPackage("graphics/other")
	t.Copy("graphics/hicolor-icon-theme/PLIST", "graphics/other/PLIST")
	t.Chdir(".")
	t.FinishSetUp()

	G.Check("graphics/hicolor-icon-theme")
	G.Check("graphics/other")

	t.CheckOutputLines(
		"WARN: graphics/hicolor-icon-theme/PLIST:2: "+
			"Packages that install icon theme files should set ICON_THEMES.",
		"ERROR: graphics/other/PLIST:2: Packages that install hicolor icons "+
			"must include \"../../graphics/hicolor-icon-theme/buildlink3.mk\" in the Makefile.",
		"ERROR: graphics/other/PLIST:2: The file icon-theme.cache must not appear in any PLIST file.",
		"WARN: graphics/other/PLIST:2: "+
			"Packages that install icon theme files should set ICON_THEMES.")
}

func (s *Suite) Test_PlistChecker_checkPathShareIcons__hicolor_ok(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/package",
		".include \"../../graphics/hicolor-icon-theme/buildlink3.mk\"")
	t.CreateFileLines("category/package/PLIST",
		PlistCvsID,
		"share/icons/hicolor/open.svg")
	t.CreateFileLines("graphics/hicolor-icon-theme/buildlink3.mk",
		MkCvsID,
		"ICON_THEMES=\tyes")
	t.FinishSetUp()

	G.Check(t.File("category/package"))

	t.CheckOutputEmpty()
}

func (s *Suite) Test_PlistLine_CheckTrailingWhitespace(c *check.C) {
	t := s.Init(c)

	lines := t.SetUpFileLines("PLIST",
		PlistCvsID,
		"bin/space ",
		"bin/space-tab \t",
		"bin/tab\t")

	CheckLinesPlist(nil, lines)

	t.CheckOutputLines(
		"ERROR: ~/PLIST:2: Pkgsrc does not support filenames ending in whitespace.",
		"WARN: ~/PLIST:3: Non-ASCII filename \"bin/space-tab \\t\".",
		"ERROR: ~/PLIST:3: Pkgsrc does not support filenames ending in whitespace.",
		"ERROR: ~/PLIST:4: Pkgsrc does not support filenames ending in whitespace.")
}

func (s *Suite) Test_PlistLine_CheckDirective(c *check.C) {
	t := s.Init(c)

	lines := t.SetUpFileLines("PLIST",
		PlistCvsID,
		"@unexec rmdir %D/bin",
		"@unexec rmdir %D/bin || true",
		"@unexec rmdir %D/bin || ${TRUE}",
		"@unexec echo 'uninstalling'",
		"@exec ldconfig",
		"@exec ldconfig || /usr/bin/true",
		"@comment This is a comment",
		"@dirrm %D/bin",
		"@imake-man 1 2 3 4",
		"@imake-man 1 2 ${IMAKE_MANNEWSUFFIX}",
		"@imake-man 1 2 3",
		"@unknown")

	CheckLinesPlist(nil, lines)

	t.CheckOutputLines(
		"WARN: ~/PLIST:2: Please remove this line. It is no longer necessary.",
		"ERROR: ~/PLIST:6: The ldconfig command must be used with \"||/usr/bin/true\".",
		"WARN: ~/PLIST:9: @dirrm is obsolete. Please remove this line.",
		"WARN: ~/PLIST:10: Invalid number of arguments for imake-man, should be 3.",
		"WARN: ~/PLIST:11: IMAKE_MANNEWSUFFIX is not meant to appear in PLISTs.",
		"WARN: ~/PLIST:13: Unknown PLIST directive \"@unknown\".")
}

func (s *Suite) Test_NewPlistLineSorter__only_comments(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("PLIST",
		PlistCvsID,
		"@comment intentionally left empty")

	CheckLinesPlist(nil, lines)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_plistLineSorter__unsortable(c *check.C) {
	t := s.Init(c)

	t.SetUpCommandLine("-Wall", "--show-autofix")
	lines := t.SetUpFileLines("PLIST",
		PlistCvsID,
		"bin/program${OPSYS}",
		"@exec true",
		"bin/program1")

	t.EnableTracingToLog()
	CheckLinesPlist(nil, lines)

	t.CheckOutputLines(
		"TRACE: + CheckLinesPlist(\"~/PLIST\")",
		"TRACE: 1 + (*Lines).CheckCvsID(\"@comment \", \"@comment \")",
		"TRACE: 1 - (*Lines).CheckCvsID(\"@comment \", \"@comment \")",
		"TRACE: 1   ~/PLIST:2: bin/program${OPSYS}: This line prevents pkglint from sorting the PLIST automatically.",
		"TRACE: 1 + SaveAutofixChanges()",
		"TRACE: 1 - SaveAutofixChanges()",
		"TRACE: - CheckLinesPlist(\"~/PLIST\")")
}
