package main

import "gopkg.in/check.v1"

func (s *Suite) Test_ChecklinesPlist(c *check.C) {
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
		"share/icons/hicolor/icon2.png", // No additional warning
		"share/tzinfo",
		"share/tzinfo")

	ChecklinesPlist(lines)

	t.CheckOutputLines(
		"ERROR: PLIST:1: Expected \"@comment $"+"NetBSD$\".",
		"WARN: PLIST:1: The bin/ directory should not have subdirectories.",
		"ERROR: PLIST:3: Configuration files must not be registered in the PLIST. "+
			"Please use the CONF_FILES framework, which is described in mk/pkginstall/bsd.pkginstall.mk.",
		"ERROR: PLIST:4: RCD_SCRIPTS must not be registered in the PLIST. Please use the RCD_SCRIPTS framework.",
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
		"ERROR: PLIST:18: Duplicate file name \"share/tzinfo\", already appeared in line 17.")
}

func (s *Suite) Test_ChecklinesPlist__empty(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("PLIST",
		PlistRcsID)

	ChecklinesPlist(lines)

	t.CheckOutputLines(
		"WARN: PLIST:1: PLIST files shouldn't be empty.")
}

func (s *Suite) Test_ChecklinesPlist__common_end(c *check.C) {
	t := s.Init(c)

	t.CreateFileLines("PLIST.common",
		PlistRcsID,
		"bin/common")
	lines := t.SetupFileLines("PLIST.common_end",
		PlistRcsID,
		"sbin/common_end")

	ChecklinesPlist(lines)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_ChecklinesPlist__condition(c *check.C) {
	t := s.Init(c)

	G.Pkg = NewPackage(t.File("category/pkgbase"))
	lines := t.NewLines("PLIST",
		PlistRcsID,
		"${PLIST.bincmds}bin/subdir/command")

	ChecklinesPlist(lines)

	t.CheckOutputLines(
		"WARN: PLIST:2: The bin/ directory should not have subdirectories.")
}

func (s *Suite) Test_ChecklinesPlist__sorting(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wplist-sort")
	lines := t.NewLines("PLIST",
		PlistRcsID,
		"@comment Do not remove",
		"sbin/i386/6c",
		"sbin/program",
		"bin/otherprogram",
		"${PLIST.condition}bin/cat")

	ChecklinesPlist(lines)

	t.CheckOutputLines(
		"WARN: PLIST:5: \"bin/otherprogram\" should be sorted before \"sbin/program\".",
		"WARN: PLIST:6: \"bin/cat\" should be sorted before \"bin/otherprogram\".")
}

func (s *Suite) Test_plistLineSorter_Sort(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("--autofix")
	lines := t.SetupFileLines("PLIST",
		PlistRcsID,
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
	ck := &PlistChecker{nil, nil, "", Once{}}
	plines := ck.NewLines(lines)

	sorter1 := NewPlistLineSorter(plines)
	c.Check(sorter1.unsortable, equals, lines.Lines[5])

	cleanedLines := append(append(lines.Lines[0:5], lines.Lines[6:8]...), lines.Lines[9:]...) // Remove ${UNKNOWN} and @exec

	sorter2 := NewPlistLineSorter((&PlistChecker{nil, nil, "", Once{}}).NewLines(NewLines(lines.FileName, cleanedLines)))

	c.Check(sorter2.unsortable, check.IsNil)

	sorter2.Sort()

	t.CheckOutputLines(
		"AUTOFIX: ~/PLIST:3: Sorting the whole file.")
	t.CheckFileLines("PLIST",
		PlistRcsID,
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

func (s *Suite) Test_PlistChecker_checkpathMan__gz(c *check.C) {
	t := s.Init(c)

	G.Pkg = NewPackage(t.File("category/pkgbase"))
	lines := t.NewLines("PLIST",
		PlistRcsID,
		"man/man3/strerror.3.gz")

	ChecklinesPlist(lines)

	t.CheckOutputLines(
		"NOTE: PLIST:2: The .gz extension is unnecessary for manual pages.")
}

func (s *Suite) Test_PlistChecker_checkpath__PKGMANDIR(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("PLIST",
		PlistRcsID,
		"${PKGMANDIR}/man1/sh.1")

	ChecklinesPlist(lines)

	t.CheckOutputLines(
		"NOTE: PLIST:2: PLIST files should mention \"man/\" instead of \"${PKGMANDIR}\".")
}

func (s *Suite) Test_PlistChecker_checkpath__python_egg(c *check.C) {
	t := s.Init(c)

	lines := t.NewLines("PLIST",
		PlistRcsID,
		"${PYSITELIB}/gdspy-${PKGVERSION}-py${PYVERSSUFFIX}.egg-info/PKG-INFO")

	ChecklinesPlist(lines)

	t.CheckOutputLines(
		"WARN: PLIST:2: Include \"../../lang/python/egg.mk\" instead of listing .egg-info files directly.")
}

func (s *Suite) Test_PlistChecker__autofix(c *check.C) {
	t := s.Init(c)

	lines := t.SetupFileLines("PLIST",
		PlistRcsID,
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
		"@pkgdir        etc/libvirt/qemu/networks/autostart",
		"@pkgdir        etc/logrotate.d",
		"@pkgdir        etc/sasl2")

	ChecklinesPlist(lines)

	t.CheckOutputLines(
		"WARN: ~/PLIST:3: \"lib/libvirt/connection-driver/libvirt_driver_nodedev.la\" "+
			"should be sorted before \"lib/libvirt/connection-driver/libvirt_driver_storage.la\".",
		"WARN: ~/PLIST:4: \"lib/libvirt/connection-driver/libvirt_driver_libxl.la\" "+
			"should be sorted before \"lib/libvirt/connection-driver/libvirt_driver_nodedev.la\".",
		"NOTE: ~/PLIST:6: PLIST files should mention \"man/\" instead of \"${PKGMANDIR}\".")

	t.SetupCommandLine("-Wall", "--autofix")
	ChecklinesPlist(lines)

	t.CheckOutputLines(
		"AUTOFIX: ~/PLIST:6: Replacing \"${PKGMANDIR}/\" with \"man/\".",
		"AUTOFIX: ~/PLIST:2: Sorting the whole file.")
	t.CheckFileLines("PLIST",
		PlistRcsID,
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

	lines := t.SetupFileLines("PLIST",
		PlistRcsID,
		"${PLIST.option1}bin/true",
		"bin/true",
		"${PLIST.option1}bin/true",
		"bin/true",
		"${PLIST.option3}bin/false",
		"${PLIST.option2}bin/false",
		"bin/true")

	ChecklinesPlist(lines)

	t.CheckOutputLines(
		"ERROR: ~/PLIST:2: Duplicate file name \"bin/true\", already appeared in line 3.",
		"ERROR: ~/PLIST:4: Duplicate file name \"bin/true\", already appeared in line 3.",
		"ERROR: ~/PLIST:5: Duplicate file name \"bin/true\", already appeared in line 3.",
		"WARN: ~/PLIST:6: \"bin/false\" should be sorted before \"bin/true\".",
		"ERROR: ~/PLIST:8: Duplicate file name \"bin/true\", already appeared in line 3.")

	t.SetupCommandLine("-Wall", "--autofix")

	ChecklinesPlist(lines)

	t.CheckOutputLines(
		"AUTOFIX: ~/PLIST:2: Deleting this line.",
		"AUTOFIX: ~/PLIST:4: Deleting this line.",
		"AUTOFIX: ~/PLIST:5: Deleting this line.",
		"AUTOFIX: ~/PLIST:8: Deleting this line.",
		"AUTOFIX: ~/PLIST:2: Sorting the whole file.")
	t.CheckFileLines("PLIST",
		PlistRcsID,
		"${PLIST.option2}bin/false",
		"${PLIST.option3}bin/false",
		"bin/true")
}

// When pkglint is run with the --only option, only the matched
// diagnostics must be autofixed. Up to 2018-03-12, the PLIST was
// sorted even if it didn't match the --only pattern.
func (s *Suite) Test_PlistChecker__autofix_with_only(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall", "--autofix", "--only", "matches nothing")

	lines := t.SetupFileLines("PLIST",
		PlistRcsID,
		"sbin/program",
		"bin/program")

	ChecklinesPlist(lines)

	t.CheckOutputEmpty()
	t.CheckFileLines("PLIST",
		PlistRcsID,
		"sbin/program",
		"bin/program")
}

func (s *Suite) Test_PlistChecker__exec_MKDIR(c *check.C) {
	t := s.Init(c)

	lines := t.SetupFileLines("PLIST",
		PlistRcsID,
		"bin/program",
		"@exec ${MKDIR} %D/share/mk/subdir")

	ChecklinesPlist(lines)

	t.CheckOutputEmpty()
}

func (s *Suite) Test_PlistChecker__empty_line(c *check.C) {
	t := s.Init(c)

	lines := t.SetupFileLines("PLIST",
		PlistRcsID,
		"",
		"bin/program")

	ChecklinesPlist(lines)

	t.CheckOutputLines(
		"WARN: ~/PLIST:2: PLISTs should not contain empty lines.")

	t.SetupCommandLine("-Wall", "--autofix")

	ChecklinesPlist(lines)

	t.CheckOutputLines(
		"AUTOFIX: ~/PLIST:2: Deleting this line.")
	t.CheckFileLines("PLIST",
		PlistRcsID,
		"bin/program")
}

func (s *Suite) Test_PlistChecker__unknown_line_type(c *check.C) {
	t := s.Init(c)

	lines := t.SetupFileLines("PLIST",
		PlistRcsID,
		"---unknown",
		"+++unknown")

	ChecklinesPlist(lines)

	t.CheckOutputLines(
		"WARN: ~/PLIST:2: Unknown line type: ---unknown",
		"WARN: ~/PLIST:3: Unknown line type: +++unknown")
}

func (s *Suite) Test_PlistChecker__doc(c *check.C) {
	t := s.Init(c)

	lines := t.SetupFileLines("PLIST",
		PlistRcsID,
		"doc/html/index.html")

	ChecklinesPlist(lines)

	t.CheckOutputLines(
		"ERROR: ~/PLIST:2: Documentation must be installed under share/doc, not doc.")
}

func (s *Suite) Test_PlistChecker__PKGLOCALEDIR(c *check.C) {
	t := s.Init(c)

	lines := t.SetupFileLines("PLIST",
		PlistRcsID,
		"${PKGLOCALEDIR}/file")
	G.Pkg = NewPackage(t.File("category/package"))

	ChecklinesPlist(lines)

	t.CheckOutputLines(
		"WARN: ~/PLIST:2: PLIST contains ${PKGLOCALEDIR}, but USE_PKGLOCALEDIR was not found.")
}

func (s *Suite) Test_PlistChecker__unwanted_entries(c *check.C) {
	t := s.Init(c)

	lines := t.SetupFileLines("PLIST",
		PlistRcsID,
		"share/perllocal.pod",
		"share/pkgbase/CVS/Entries",
		"share/pkgbase/Makefile.orig")
	G.Pkg = NewPackage(t.File("category/package"))

	ChecklinesPlist(lines)

	t.CheckOutputLines(
		"WARN: ~/PLIST:2: perllocal.pod files should not be in the PLIST.",
		"WARN: ~/PLIST:3: CVS files should not be in the PLIST.",
		"WARN: ~/PLIST:4: .orig files should not be in the PLIST.")
}

func (s *Suite) Test_PlistChecker_checkpathInfo(c *check.C) {
	t := s.Init(c)

	lines := t.SetupFileLines("PLIST",
		PlistRcsID,
		"info/gmake.1.info")
	G.Pkg = NewPackage(t.File("category/package"))

	ChecklinesPlist(lines)

	t.CheckOutputLines(
		"WARN: ~/PLIST:2: Packages that install info files should set INFO_FILES in the Makefile.")
}

func (s *Suite) Test_PlistChecker_checkpathLib(c *check.C) {
	t := s.Init(c)

	lines := t.SetupFileLines("PLIST",
		PlistRcsID,
		"lib/charset.alias",
		"lib/liberty-1.0.la",
		"lib/locale/de_DE/liberty.mo",
		"lib/package/liberty-1.0.so")
	G.Pkg = NewPackage(t.File("category/package"))
	G.Pkg.EffectivePkgbase = "package"

	ChecklinesPlist(lines)

	t.CheckOutputLines(
		"ERROR: ~/PLIST:2: Only the libiconv package may install lib/charset.alias.",
		"WARN: ~/PLIST:3: Packages that install libtool libraries should define USE_LIBTOOL.",
		"ERROR: ~/PLIST:4: \"lib/locale\" must not be listed. Use ${PKGLOCALEDIR}/locale and set USE_PKGLOCALEDIR instead.")
}

func (s *Suite) Test_PlistChecker_checkpathMan(c *check.C) {
	t := s.Init(c)

	lines := t.SetupFileLines("PLIST",
		PlistRcsID,
		"man/man1/program.8",
		"man/manx/program.x")

	ChecklinesPlist(lines)

	t.CheckOutputLines(
		"WARN: ~/PLIST:2: Mismatch between the section (1) and extension (8) of the manual page.",
		"WARN: ~/PLIST:3: Unknown section \"x\" for manual page.")
}

func (s *Suite) Test_PlistChecker_checkpathShare(c *check.C) {
	t := s.Init(c)

	lines := t.SetupFileLines("PLIST",
		PlistRcsID,
		"share/doc/html/package/index.html",
		"share/doc/package/index.html",
		"share/icons/hicolor/icon-theme.cache",
		"share/info/program.1.info",
		"share/man/man1/program.1")
	G.Pkg = NewPackage(t.File("category/package"))
	G.Pkg.EffectivePkgbase = "package"

	ChecklinesPlist(lines)

	t.CheckOutputLines(
		"WARN: ~/PLIST:2: Use of \"share/doc/html\" is deprecated. Use \"share/doc/${PKGBASE}\" instead.",
		"ERROR: ~/PLIST:4: Packages that install hicolor icons must include \"../../graphics/hicolor-icon-theme/buildlink3.mk\" in the Makefile.",
		"ERROR: ~/PLIST:4: The file icon-theme.cache must not appear in any PLIST file.",
		"WARN: ~/PLIST:4: Packages that install icon theme files should set ICON_THEMES.",
		"WARN: ~/PLIST:5: Info pages should be installed into info/, not share/info/.",
		"WARN: ~/PLIST:6: Man pages should be installed into man/, not share/man/.")
}

func (s *Suite) Test_PlistLine_CheckTrailingWhitespace(c *check.C) {
	t := s.Init(c)

	lines := t.SetupFileLines("PLIST",
		PlistRcsID,
		"bin/program \t")

	ChecklinesPlist(lines)

	t.CheckOutputLines(
		"ERROR: ~/PLIST:2: pkgsrc does not support filenames ending in white-space.")
}

func (s *Suite) Test_PlistLine_CheckDirective(c *check.C) {
	t := s.Init(c)

	lines := t.SetupFileLines("PLIST",
		PlistRcsID,
		"@unexec rmdir %D/bin",
		"@exec ldconfig",
		"@comment This is a comment",
		"@dirrm %D/bin",
		"@imake-man 1 2 3 4",
		"@imake-man 1 2 ${IMAKE_MANNEWSUFFIX}",
		"@unknown")

	ChecklinesPlist(lines)

	t.CheckOutputLines(
		"WARN: ~/PLIST:2: Please remove this line. It is no longer necessary.",
		"ERROR: ~/PLIST:3: ldconfig must be used with \"||/usr/bin/true\".",
		"WARN: ~/PLIST:5: @dirrm is obsolete. Please remove this line.",
		"WARN: ~/PLIST:6: Invalid number of arguments for imake-man.",
		"WARN: ~/PLIST:7: IMAKE_MANNEWSUFFIX is not meant to appear in PLISTs.",
		"WARN: ~/PLIST:8: Unknown PLIST directive \"@unknown\".")
}

func (s *Suite) Test_plistLineSorter__unsortable(c *check.C) {
	t := s.Init(c)

	t.SetupCommandLine("-Wall", "--show-autofix")
	lines := t.SetupFileLines("PLIST",
		PlistRcsID,
		"bin/program${OPSYS}",
		"@exec true",
		"bin/program1")

	t.EnableTracingToLog()
	ChecklinesPlist(lines)

	t.CheckOutputLines(
		"TRACE: + ChecklinesPlist(\"~/PLIST\")",
		"TRACE: 1 + CheckLineRcsid(\"@comment \", \"@comment \")",
		"TRACE: 1 - CheckLineRcsid(\"@comment \", \"@comment \")",
		"TRACE: 1   ~/PLIST:2: bin/program${OPSYS}: This line prevents pkglint from sorting the PLIST automatically.",
		"TRACE: 1 + SaveAutofixChanges()",
		"TRACE: 1 - SaveAutofixChanges()",
		"TRACE: - ChecklinesPlist(\"~/PLIST\")")
}
