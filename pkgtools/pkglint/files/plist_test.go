package main

import (
	check "gopkg.in/check.v1"
)

func (s *Suite) Test_ChecklinesPlist(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")
	G.Pkg = NewPackage("category/pkgbase")
	lines := s.NewLines("PLIST",
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
		"share/tzinfo",
		"share/tzinfo")

	ChecklinesPlist(lines)

	s.CheckOutputLines(
		"ERROR: PLIST:1: Expected \"@comment $"+"NetBSD$\".",
		"WARN: PLIST:1: The bin/ directory should not have subdirectories.",
		"WARN: PLIST:2: Manual page missing for bin/program.",
		"ERROR: PLIST:3: Configuration files must not be registered in the PLIST. Please use the CONF_FILES framework, which is described in mk/pkginstall/bsd.pkginstall.mk.",
		"ERROR: PLIST:4: RCD_SCRIPTS must not be registered in the PLIST. Please use the RCD_SCRIPTS framework.",
		"ERROR: PLIST:6: \"info/dir\" must not be listed. Use install-info to add/remove an entry.",
		"WARN: PLIST:7: Library filename \"c.so\" should start with \"lib\".",
		"WARN: PLIST:8: Redundant library found. The libtool library is in line 9.",
		"WARN: PLIST:9: \"lib/libc.la\" should be sorted before \"lib/libc.so.6\".",
		"WARN: PLIST:10: Preformatted manual page without unformatted one.",
		"WARN: PLIST:10: Preformatted manual pages should end in \".0\".",
		"WARN: PLIST:11: IMAKE_MANNEWSUFFIX is not meant to appear in PLISTs.",
		"WARN: PLIST:12: Please remove this line. It is no longer necessary.",
		"WARN: PLIST:13: Manual page missing for sbin/clockctl.",
		"ERROR: PLIST:14: The package Makefile must include \"../../graphics/gnome-icon-theme/buildlink3.mk\".",
		"ERROR: PLIST:16: Duplicate filename \"share/tzinfo\", already appeared in line 15.")
}

func (s *Suite) Test_ChecklinesPlist__empty(c *check.C) {
	s.Init(c)
	lines := s.NewLines("PLIST",
		"@comment $"+"NetBSD$")

	ChecklinesPlist(lines)

	s.CheckOutputLines(
		"WARN: PLIST:1: PLIST files shouldn't be empty.")
}

func (s *Suite) Test_ChecklinesPlist__commonEnd(c *check.C) {
	s.Init(c)
	s.CreateTmpFile("PLIST.common", ""+
		"@comment $"+"NetBSD$\n"+
		"bin/common\n")
	fname := s.CreateTmpFile("PLIST.common_end", ""+
		"@comment $"+"NetBSD$\n"+
		"sbin/common_end\n")

	ChecklinesPlist(LoadExistingLines(fname, false))

	s.CheckOutputEmpty()
}

func (s *Suite) Test_ChecklinesPlist__conditional(c *check.C) {
	s.Init(c)
	G.Pkg = NewPackage("category/pkgbase")
	G.Pkg.plistSubstCond["PLIST.bincmds"] = true
	lines := s.NewLines("PLIST",
		"@comment $"+"NetBSD$",
		"${PLIST.bincmds}bin/subdir/command")

	ChecklinesPlist(lines)

	s.CheckOutputLines(
		"WARN: PLIST:2: The bin/ directory should not have subdirectories.")
}

func (s *Suite) Test_ChecklinesPlist__sorting(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wplist-sort")
	lines := s.NewLines("PLIST",
		"@comment $"+"NetBSD$",
		"@comment Do not remove",
		"sbin/i386/6c",
		"sbin/program",
		"bin/otherprogram",
		"${PLIST.conditional}bin/cat")

	ChecklinesPlist(lines)

	s.CheckOutputLines(
		"WARN: PLIST:5: \"bin/otherprogram\" should be sorted before \"sbin/program\".",
		"WARN: PLIST:6: \"bin/cat\" should be sorted before \"bin/otherprogram\".")
}

func (s *Suite) Test_PlistLineSorter_Sort(c *check.C) {
	s.Init(c)
	s.UseCommandLine("--autofix")
	tmpfile := s.CreateTmpFile("PLIST", "dummy\n")
	lines := s.NewLines(tmpfile,
		"@comment $"+"NetBSD$",
		"@comment Do not remove",
		"A",
		"b",
		"CCC",
		"lib/${UNKNOWN}.la",
		"C",
		"ddd",
		"@exec echo \"after ddd\"",
		"sbin/program",
		"${PLIST.one}bin/program",
		"${PKGMANDIR}/man1/program.1",
		"${PLIST.two}bin/program2",
		"lib/before.la",
		"lib/after.la",
		"@exec echo \"after lib/after.la\"")
	ck := &PlistChecker{nil, nil, ""}
	plines := ck.NewLines(lines)

	NewPlistLineSorter(plines).Sort()

	s.CheckOutputLines(
		"AUTOFIX: ~/PLIST:1: Sorting the whole file.",
		"AUTOFIX: ~/PLIST: Has been auto-fixed. Please re-run pkglint.")
	c.Check(s.LoadTmpFile("PLIST"), equals, ""+
		"@comment $"+"NetBSD$\n"+
		"@comment Do not remove\n"+
		"A\n"+
		"C\n"+
		"CCC\n"+
		"lib/${UNKNOWN}.la\n"+ // Stays below the previous line
		"b\n"+
		"${PLIST.one}bin/program\n"+ // Conditionals are ignored while sorting
		"${PKGMANDIR}/man1/program.1\n"+ // Stays below the previous line
		"${PLIST.two}bin/program2\n"+
		"ddd\n"+
		"@exec echo \"after ddd\"\n"+ // Stays below the previous line
		"lib/after.la\n"+
		"@exec echo \"after lib/after.la\"\n"+
		"lib/before.la\n"+
		"sbin/program\n")
}

func (s *Suite) Test_PlistChecker_checkpathShare_Desktop(c *check.C) {
	// Disabled due to PR 46570, item "10. It should stop".
	return

	s.Init(c)
	s.UseCommandLine("-Wextra")
	G.Pkg = NewPackage("category/pkgpath")

	ChecklinesPlist(s.NewLines("PLIST",
		"@comment $"+"NetBSD$",
		"share/applications/pkgbase.desktop"))

	s.CheckOutputLines(
		"WARN: PLIST:2: Packages that install a .desktop entry should .include \"../../sysutils/desktop-file-utils/desktopdb.mk\".")
}

func (s *Suite) Test_PlistChecker_checkpathMan_gz(c *check.C) {
	s.Init(c)
	G.Pkg = NewPackage("category/pkgbase")

	ChecklinesPlist(s.NewLines("PLIST",
		"@comment $"+"NetBSD$",
		"man/man3/strerror.3.gz"))

	s.CheckOutputLines(
		"NOTE: PLIST:2: The .gz extension is unnecessary for manual pages.")
}

func (s *Suite) TestPlistChecker_checkpath__PKGMANDIR(c *check.C) {
	s.Init(c)
	lines := s.NewLines("PLIST",
		"@comment $"+"NetBSD$",
		"${PKGMANDIR}/man1/sh.1")

	ChecklinesPlist(lines)

	s.CheckOutputLines(
		"NOTE: PLIST:2: PLIST files should mention \"man/\" instead of \"${PKGMANDIR}\".")
}

func (s *Suite) TestPlistChecker_checkpath__python_egg(c *check.C) {
	s.Init(c)
	lines := s.NewLines("PLIST",
		"@comment $"+"NetBSD$",
		"${PYSITELIB}/gdspy-${PKGVERSION}-py${PYVERSSUFFIX}.egg-info/PKG-INFO")

	ChecklinesPlist(lines)

	s.CheckOutputLines(
		"WARN: PLIST:2: Include \"../../lang/python/egg.mk\" instead of listing .egg-info files directly.")
}

func (s *Suite) Test_PlistChecker__autofix(c *check.C) {
	s.Init(c)
	s.UseCommandLine("-Wall")

	fname := s.CreateTmpFileLines("PLIST",
		"@comment $"+"NetBSD$",
		"lib/libvirt/connection-driver/libvirt_driver_storage.la",
		"${PLIST.hal}lib/libvirt/connection-driver/libvirt_driver_nodedev.la",
		"${PLIST.xen}lib/libvirt/connection-driver/libvirt_driver_libxl.la",
		"lib/libvirt/lock-driver/lockd.la",
		"${PKGMANDIR}/man1/sh.1",
		"share/augeas/lenses/virtlockd.aug",
		"share/doc/${PKGNAME}/html/32favicon.png",
		"share/doc/${PKGNAME}/html/404.html",
		"share/doc/${PKGNAME}/html/acl.html",
		"share/doc/${PKGNAME}/html/aclpolkit.html",
		"share/doc/${PKGNAME}/html/windows.html",
		"share/examples/libvirt/libvirt.conf",
		"share/locale/zh_CN/LC_MESSAGES/libvirt.mo",
		"share/locale/zh_TW/LC_MESSAGES/libvirt.mo",
		"share/locale/zu/LC_MESSAGES/libvirt.mo",
		"@pkgdir share/examples/libvirt/nwfilter",
		"@pkgdir        etc/libvirt/qemu/networks/autostart",
		"@pkgdir        etc/logrotate.d",
		"@pkgdir        etc/sasl2")
	lines := LoadExistingLines(fname, false)
	ChecklinesPlist(lines)

	s.CheckOutputLines(
		"WARN: ~/PLIST:3: \"lib/libvirt/connection-driver/libvirt_driver_nodedev.la\" should be sorted before \"lib/libvirt/connection-driver/libvirt_driver_storage.la\".",
		"WARN: ~/PLIST:4: \"lib/libvirt/connection-driver/libvirt_driver_libxl.la\" should be sorted before \"lib/libvirt/connection-driver/libvirt_driver_nodedev.la\".",
		"NOTE: ~/PLIST:6: PLIST files should mention \"man/\" instead of \"${PKGMANDIR}\".")

	s.UseCommandLine("-Wall", "--autofix")
	ChecklinesPlist(lines)

	fixedLines := LoadExistingLines(fname, false)

	s.CheckOutputLines(
		"AUTOFIX: ~/PLIST:6: Replacing \"${PKGMANDIR}/\" with \"man/\".",
		"AUTOFIX: ~/PLIST:1: Sorting the whole file.",
		"AUTOFIX: ~/PLIST: Has been auto-fixed. Please re-run pkglint.")
	c.Check(len(lines), equals, len(fixedLines))
	c.Check(s.LoadTmpFile("PLIST"), equals, ""+
		"@comment $"+"NetBSD$\n"+
		"${PLIST.xen}lib/libvirt/connection-driver/libvirt_driver_libxl.la\n"+
		"${PLIST.hal}lib/libvirt/connection-driver/libvirt_driver_nodedev.la\n"+
		"lib/libvirt/connection-driver/libvirt_driver_storage.la\n"+
		"lib/libvirt/lock-driver/lockd.la\n"+
		"man/man1/sh.1\n"+
		"share/augeas/lenses/virtlockd.aug\n"+
		"share/doc/${PKGNAME}/html/32favicon.png\n"+
		"share/doc/${PKGNAME}/html/404.html\n"+
		"share/doc/${PKGNAME}/html/acl.html\n"+
		"share/doc/${PKGNAME}/html/aclpolkit.html\n"+
		"share/doc/${PKGNAME}/html/windows.html\n"+
		"share/examples/libvirt/libvirt.conf\n"+
		"share/locale/zh_CN/LC_MESSAGES/libvirt.mo\n"+
		"share/locale/zh_TW/LC_MESSAGES/libvirt.mo\n"+
		"share/locale/zu/LC_MESSAGES/libvirt.mo\n"+
		"@pkgdir share/examples/libvirt/nwfilter\n"+
		"@pkgdir        etc/libvirt/qemu/networks/autostart\n"+
		"@pkgdir        etc/logrotate.d\n"+
		"@pkgdir        etc/sasl2\n")
}
