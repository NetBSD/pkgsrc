package main

import (
	"fmt"

	check "gopkg.in/check.v1"
)

func (s *Suite) TestVartypeCheck_AwkCommand(c *check.C) {
	s.UseCommandLine(c, "-Dunchecked")
	runVartypeChecks("PLIST_AWK", opAssignAppend, (*VartypeCheck).AwkCommand,
		"{print $0}",
		"{print $$0}")

	c.Check(s.Output(), equals, ""+
		"ERROR: fname:1: Invalid Makefile syntax at \"$0}\".\n"+
		"DEBUG: fname:1: Unchecked AWK command: \"{print $0}\"\n"+
		"DEBUG: fname:2: Unchecked AWK command: \"{print $$0}\"\n")
}

func (s *Suite) TestVartypeCheck_BasicRegularExpression(c *check.C) {
	runVartypeChecks("REPLACE_FILES.pl", opAssign, (*VartypeCheck).BasicRegularExpression,
		".*\\.pl$",
		".*\\.pl$$")

	c.Check(s.Output(), equals, "ERROR: fname:1: Invalid Makefile syntax at \"$\".\n")
}

func (s *Suite) TestVartypeCheck_BuildlinkDepmethod(c *check.C) {
	runVartypeChecks("BUILDLINK_DEPMETHOD.libc", opAssignDefault, (*VartypeCheck).BuildlinkDepmethod,
		"full",
		"unknown")

	c.Check(s.Output(), equals, "WARN: fname:2: Invalid dependency method \"unknown\". Valid methods are \"build\" or \"full\".\n")
}

func (s *Suite) TestVartypeCheck_Category(c *check.C) {
	s.CreateTmpFile(c, "filesyscategory/Makefile", "# empty\n")
	G.CurrentDir = s.tmpdir
	G.CurPkgsrcdir = "."

	runVartypeChecks("CATEGORIES", opAssign, (*VartypeCheck).Category,
		"chinese",
		"arabic",
		"filesyscategory")

	c.Check(s.Output(), equals, "ERROR: fname:2: Invalid category \"arabic\".\n")
}

func (s *Suite) TestVartypeCheck_CFlag(c *check.C) {
	runVartypeChecks("CFLAGS", opAssignAppend, (*VartypeCheck).CFlag,
		"-Wall",
		"/W3",
		"target:sparc64",
		"-std=c99",
		"-XX:+PrintClassHistogramAfterFullGC",
		"`pkg-config pidgin --cflags`")

	c.Check(s.Output(), equals, ""+
		"WARN: fname:2: Compiler flag \"/W3\" should start with a hyphen.\n"+
		"WARN: fname:3: Compiler flag \"target:sparc64\" should start with a hyphen.\n"+
		"WARN: fname:5: Unknown compiler flag \"-XX:+PrintClassHistogramAfterFullGC\".\n")
}

func (s *Suite) TestVartypeCheck_Comment(c *check.C) {
	runVartypeChecks("COMMENT", opAssign, (*VartypeCheck).Comment,
		"Versatile Programming Language",
		"TODO: Short description of the package",
		"A great package.",
		"some packages need a very very long comment to explain their basic usefulness")

	c.Check(s.Output(), equals, ""+
		"ERROR: fname:2: COMMENT must be set.\n"+
		"WARN: fname:3: COMMENT should not begin with \"A\".\n"+
		"WARN: fname:3: COMMENT should not end with a period.\n"+
		"WARN: fname:4: COMMENT should start with a capital letter.\n"+
		"WARN: fname:4: COMMENT should not be longer than 70 characters.\n")
}

func (s *Suite) TestVartypeCheck_Dependency(c *check.C) {
	runVartypeChecks("CONFLICTS", opAssignAppend, (*VartypeCheck).Dependency,
		"Perl",
		"perl5>=5.22",
		"perl5-*",
		"perl5-5.22.*",
		"perl5-[5.10-5.22]*",
		"py-docs",
		"perl5-5.22.*{,nb*}",
		"libkipi>=0.1.5<4.0",
		"gtk2+>=2.16",
		"perl-5.22",
		"perl-5*",
		"gtksourceview-sharp-2.0-[0-9]*",
		"perl-5.22{,nb*}",
		"perl-5.22{,nb[0-9]*}",
		"mbrola-301h{,nb[0-9]*}",
		"mpg123{,-esound,-nas}>=0.59.18",
		"mysql*-{client,server}-[0-9]*",
		"postgresql8[0-35-9]-${module}-[0-9]*",
		"ncurses-${NC_VERS}{,nb*}",
		"{ssh{,6}-[0-9]*,openssh-[0-9]*}",
		"gnome-control-center>=2.20.1{,nb*}")

	c.Check(s.Output(), equals, ""+
		"WARN: fname:1: Unknown dependency pattern \"Perl\".\n"+
		"WARN: fname:3: Please use \"perl5-[0-9]*\" instead of \"perl5-*\".\n"+
		"WARN: fname:5: Only [0-9]* is allowed in the numeric part of a dependency.\n"+
		"WARN: fname:5: The version pattern \"[5.10-5.22]*\" should not contain a hyphen.\n"+
		"WARN: fname:6: Unknown dependency pattern \"py-docs\".\n"+
		"WARN: fname:10: Please use \"5.22{,nb*}\" instead of \"5.22\" as the version pattern.\n"+
		"WARN: fname:11: Please use \"5.*\" instead of \"5*\" as the version pattern.\n"+
		"WARN: fname:12: The version pattern \"2.0-[0-9]*\" should not contain a hyphen.\n"+
		"WARN: fname:20: The version pattern \"[0-9]*,openssh-[0-9]*}\" should not contain a hyphen.\n"+ // XXX
		"WARN: fname:21: Dependency patterns of the form pkgbase>=1.0 don't need the \"{,nb*}\" extension.\n")
}

func (s *Suite) TestVartypeCheck_DependencyWithPath(c *check.C) {
	s.CreateTmpFile(c, "x11/alacarte/Makefile", "# empty\n")
	s.CreateTmpFile(c, "category/package/Makefile", "# empty\n")
	G.globalData.Pkgsrcdir = s.tmpdir
	G.CurrentDir = s.tmpdir + "/category/package"
	G.CurPkgsrcdir = "../.."

	runVartypeChecks("DEPENDS", opAssignAppend, (*VartypeCheck).DependencyWithPath,
		"Perl",
		"perl5>=5.22:../perl5",
		"perl5>=5.24:../../lang/perl5",
		"broken0.12.1:../../x11/alacarte",
		"broken[0-9]*:../../x11/alacarte",
		"broken[0-9]*../../x11/alacarte",
		"broken>=:../../x11/alacarte",
		"broken=0:../../x11/alacarte",
		"broken=:../../x11/alacarte",
		"broken-:../../x11/alacarte",
		"broken>:../../x11/alacarte",
		"gtk2+>=2.16:../../x11/alacarte")

	c.Check(s.Output(), equals, ""+
		"WARN: fname:1: Unknown dependency pattern with path \"Perl\".\n"+
		"WARN: fname:2: Dependencies should have the form \"../../category/package\".\n"+
		"ERROR: fname:3: \"../../lang/perl5\" does not exist.\n"+
		"ERROR: fname:3: There is no package in \"lang/perl5\".\n"+
		"WARN: fname:3: Please use USE_TOOLS+=perl:run instead of this dependency.\n"+
		"WARN: fname:4: Unknown dependency pattern \"broken0.12.1\".\n"+
		"WARN: fname:5: Unknown dependency pattern \"broken[0-9]*\".\n"+
		"WARN: fname:6: Unknown dependency pattern with path \"broken[0-9]*../../x11/alacarte\".\n"+
		"WARN: fname:7: Unknown dependency pattern \"broken>=\".\n"+
		"WARN: fname:8: Unknown dependency pattern \"broken=0\".\n"+
		"WARN: fname:9: Unknown dependency pattern \"broken=\".\n"+
		"WARN: fname:10: Unknown dependency pattern \"broken-\".\n"+
		"WARN: fname:11: Unknown dependency pattern \"broken>\".\n")
}

func (s *Suite) TestVartypeCheck_DistSuffix(c *check.C) {
	runVartypeChecks("EXTRACT_SUFX", opAssign, (*VartypeCheck).DistSuffix,
		".tar.gz",
		".tar.bz2")

	c.Check(s.Output(), equals, "NOTE: fname:1: EXTRACT_SUFX is \".tar.gz\" by default, so this definition may be redundant.\n")
}

func (s *Suite) TestVartypeCheck_EmulPlatform(c *check.C) {
	runVartypeChecks("EMUL_PLATFORM", opAssign, (*VartypeCheck).EmulPlatform,
		"linux-i386",
		"nextbsd-8087",
		"${LINUX}")

	c.Check(s.Output(), equals, ""+
		"WARN: fname:2: \"nextbsd\" is not valid for the operating system part of EMUL_PLATFORM. Use one of { bitrig bsdos cygwin darwin dragonfly freebsd haiku hpux interix irix linux mirbsd netbsd openbsd osf1 solaris } instead.\n"+
		"WARN: fname:2: \"8087\" is not valid for the hardware architecture part of EMUL_PLATFORM. Use one of { alpha amd64 arc arm arm32 cobalt convex dreamcast hpcmips hpcsh hppa i386 ia64 m68k m88k mips mips64 mips64eb mips64el mipseb mipsel mipsn32 ns32k pc532 pmax powerpc rs6000 s390 sh3eb sh3el sparc sparc64 vax x86_64 } instead.\n"+
		"WARN: fname:3: \"${LINUX}\" is not a valid emulation platform.\n")
}

func (s *Suite) TestVartypeCheck_Enum(c *check.C) {
	runVartypeMatchChecks("JDK", enum("jdk1 jdk2 jdk4").checker,
		"*",
		"jdk*",
		"sun-jdk*",
		"${JDKNAME}")

	c.Check(s.Output(), equals, "WARN: fname:3: The pattern \"sun-jdk*\" cannot match any of { jdk1 jdk2 jdk4 } for JDK.\n")
}

func (s *Suite) TestVartypeCheck_FetchURL(c *check.C) {
	G.globalData.MasterSiteUrls = map[string]string{
		"https://github.com/":         "MASTER_SITE_GITHUB",
		"http://ftp.gnu.org/pub/gnu/": "MASTER_SITE_GNU",
	}
	G.globalData.MasterSiteVars = map[string]bool{
		"MASTER_SITE_GITHUB": true,
		"MASTER_SITE_GNU":    true,
	}

	runVartypeChecks("MASTER_SITES", opAssign, (*VartypeCheck).FetchURL,
		"https://github.com/example/project/",
		"http://ftp.gnu.org/pub/gnu/bison", // Missing a slash at the end
		"${MASTER_SITE_GNU:=bison}",
		"${MASTER_SITE_INVALID:=subdir/}")

	c.Check(s.Output(), equals, ""+
		"WARN: fname:1: Please use ${MASTER_SITE_GITHUB:=example/} instead of \"https://github.com/example/project/\" and run \""+confMake+" help topic=github\" for further tips.\n"+
		"WARN: fname:2: Please use ${MASTER_SITE_GNU:=bison} instead of \"http://ftp.gnu.org/pub/gnu/bison\".\n"+
		"ERROR: fname:3: The subdirectory in MASTER_SITE_GNU must end with a slash.\n"+
		"ERROR: fname:4: MASTER_SITE_INVALID does not exist.\n")

	// PR 46570, keyword gimp-fix-ca
	runVartypeChecks("MASTER_SITES", opAssign, (*VartypeCheck).FetchURL,
		"https://example.org/download.cgi?fname=fname&sha1=12341234")

	c.Check(s.Output(), equals, "")
}

func (s *Suite) TestVartypeCheck_Filename(c *check.C) {
	runVartypeChecks("FNAME", opAssign, (*VartypeCheck).Filename,
		"Filename with spaces.docx",
		"OS/2-manual.txt")

	c.Check(s.Output(), equals, ""+
		"WARN: fname:1: \"Filename with spaces.docx\" is not a valid filename.\n"+
		"WARN: fname:2: A filename should not contain a slash.\n")
}

func (s *Suite) TestVartypeCheck_LdFlag(c *check.C) {
	runVartypeChecks("LDFLAGS", opAssignAppend, (*VartypeCheck).LdFlag,
		"-lc",
		"-L/usr/lib64",
		"`pkg-config pidgin --ldflags`",
		"-unknown")

	c.Check(s.Output(), equals, "WARN: fname:4: Unknown linker flag \"-unknown\".\n")
}

func (s *Suite) TestVartypeCheck_MailAddress(c *check.C) {
	runVartypeChecks("MAINTAINER", opAssign, (*VartypeCheck).MailAddress,
		"pkgsrc-users@netbsd.org")

	c.Check(s.Output(), equals, "WARN: fname:1: Please write \"NetBSD.org\" instead of \"netbsd.org\".\n")
}

func (s *Suite) TestVartypeCheck_Message(c *check.C) {
	runVartypeChecks("SUBST_MESSAGE.id", opAssign, (*VartypeCheck).Message,
		"\"Correct paths\"",
		"Correct paths")

	c.Check(s.Output(), equals, "WARN: fname:1: SUBST_MESSAGE.id should not be quoted.\n")
}

func (s *Suite) TestVartypeCheck_Option(c *check.C) {
	G.globalData.PkgOptions = map[string]string{
		"documented":   "Option description",
		"undocumented": "",
	}

	runVartypeChecks("PKG_OPTIONS.pkgbase", opAssign, (*VartypeCheck).Option,
		"documented",
		"undocumented",
		"unknown")

	c.Check(s.Output(), equals, "WARN: fname:3: Unknown option \"unknown\".\n")
}

func (s *Suite) TestVartypeCheck_Pathlist(c *check.C) {
	runVartypeChecks("PATH", opAssign, (*VartypeCheck).Pathlist,
		"/usr/bin:/usr/sbin:.:${LOCALBASE}/bin")

	c.Check(s.Output(), equals, "WARN: fname:1: All components of PATH (in this case \".\") should be absolute paths.\n")
}

func (s *Suite) TestVartypeCheck_PkgOptionsVar(c *check.C) {
	runVartypeChecks("PKG_OPTIONS_VAR.screen", opAssign, (*VartypeCheck).PkgOptionsVar,
		"PKG_OPTIONS.${PKGBASE}")

	c.Check(s.Output(), equals, "ERROR: fname:1: PKGBASE must not be used in PKG_OPTIONS_VAR.\n")
}

func (s *Suite) TestVartypeCheck_PkgRevision(c *check.C) {
	runVartypeChecks("PKGREVISION", opAssign, (*VartypeCheck).PkgRevision,
		"3a")

	c.Check(s.Output(), equals, ""+
		"WARN: fname:1: PKGREVISION must be a positive integer number.\n"+
		"ERROR: fname:1: PKGREVISION only makes sense directly in the package Makefile.\n")

	runVartypeChecksFname("Makefile", "PKGREVISION", opAssign, (*VartypeCheck).PkgRevision,
		"3")

	c.Check(s.Output(), equals, "")
}

func (s *Suite) TestVartypeCheck_PlatformPattern(c *check.C) {
	runVartypeMatchChecks("ONLY_FOR_PLATFORM", (*VartypeCheck).PlatformPattern,
		"linux-i386",
		"nextbsd-5.0-8087",
		"netbsd-7.0-l*",
		"NetBSD-1.6.2-i386",
		"${LINUX}")

	c.Check(s.Output(), equals, ""+
		"WARN: fname:1: \"linux-i386\" is not a valid platform pattern.\n"+
		"WARN: fname:2: The pattern \"nextbsd\" cannot match any of { Bitrig BSDOS Cygwin Darwin DragonFly FreeBSD Haiku HPUX Interix IRIX Linux MirBSD NetBSD OpenBSD OSF1 QNX SunOS } for the operating system part of ONLY_FOR_PLATFORM.\n"+
		"WARN: fname:2: The pattern \"8087\" cannot match any of { alpha amd64 arc arm arm32 cobalt convex dreamcast hpcmips hpcsh hppa i386 ia64 m68k m88k mips mips64 mips64eb mips64el mipseb mipsel mipsn32 ns32k pc532 pmax powerpc rs6000 s390 sh3eb sh3el sparc sparc64 vax x86_64 } for the hardware architecture part of ONLY_FOR_PLATFORM.\n"+
		"WARN: fname:3: The pattern \"netbsd\" cannot match any of { Bitrig BSDOS Cygwin Darwin DragonFly FreeBSD Haiku HPUX Interix IRIX Linux MirBSD NetBSD OpenBSD OSF1 QNX SunOS } for the operating system part of ONLY_FOR_PLATFORM.\n"+
		"WARN: fname:3: The pattern \"l*\" cannot match any of { alpha amd64 arc arm arm32 cobalt convex dreamcast hpcmips hpcsh hppa i386 ia64 m68k m88k mips mips64 mips64eb mips64el mipseb mipsel mipsn32 ns32k pc532 pmax powerpc rs6000 s390 sh3eb sh3el sparc sparc64 vax x86_64 } for the hardware architecture part of ONLY_FOR_PLATFORM.\n")
}

func (s *Suite) TestVartypeCheck_PythonDependency(c *check.C) {
	runVartypeChecks("PYTHON_VERSIONED_DEPENDENCIES", opAssign, (*VartypeCheck).PythonDependency,
		"cairo",
		"${PYDEP}",
		"cairo,X")

	c.Check(s.Output(), equals, ""+
		"WARN: fname:2: Python dependencies should not contain variables.\n"+
		"WARN: fname:3: Invalid Python dependency \"cairo,X\".\n")
}

func (s *Suite) TestVartypeCheck_Restricted(c *check.C) {
	runVartypeChecks("NO_BIN_ON_CDROM", opAssign, (*VartypeCheck).Restricted,
		"May only be distributed free of charge")

	c.Check(s.Output(), equals, "WARN: fname:1: The only valid value for NO_BIN_ON_CDROM is ${RESTRICTED}.\n")
}

func (s *Suite) TestVartypeCheck_SedCommands(c *check.C) {
	runVartypeChecks("SUBST_SED.dummy", opAssign, (*VartypeCheck).SedCommands,
		"s,@COMPILER@,gcc,g",
		"-e s,a,b, -e a,b,c,",
		"-e \"s,#,comment ,\"",
		"-e \"s,\\#,comment ,\"")

	c.Check(s.Output(), equals, ""+
		"NOTE: fname:1: Please always use \"-e\" in sed commands, even if there is only one substitution.\n"+
		"NOTE: fname:2: Each sed command should appear in an assignment of its own.\n"+
		"ERROR: fname:3: Invalid shell words \"\\\"s,\" in sed commands.\n")
}

func (s *Suite) TestVartypeCheck_ShellCommands(c *check.C) {
	runVartypeChecks("GENERATE_PLIST", opAssign, (*VartypeCheck).ShellCommands,
		"echo bin/program",
		"echo bin/program;")

	c.Check(s.Output(), equals, "WARN: fname:1: This shell command list should end with a semicolon.\n")
}

func (s *Suite) TestVartypeCheck_Stage(c *check.C) {
	runVartypeChecks("SUBST_STAGE.dummy", opAssign, (*VartypeCheck).Stage,
		"post-patch",
		"post-modern",
		"pre-test")

	c.Check(s.Output(), equals, "WARN: fname:2: Invalid stage name \"post-modern\". Use one of {pre,do,post}-{extract,patch,configure,build,test,install}.\n")
}

func (s *Suite) TestVartypeCheck_URL(c *check.C) {
	runVartypeChecks("MASTER_SITES", opAssign, (*VartypeCheck).URL,
		"http://example.org/distfiles/",
		"http://example.org/download?fname=distfile;version=1.0",
		"http://example.org/download?fname=<distfile>;version=<version>")

	c.Check(s.Output(), equals, "WARN: fname:3: \"http://example.org/download?fname=<distfile>;version=<version>\" is not a valid URL.\n")
}

func (s *Suite) TestVartypeCheck_Varname(c *check.C) {
	runVartypeChecks("BUILD_DEFS", opAssign, (*VartypeCheck).Varname,
		"VARBASE",
		"VarBase",
		"PKG_OPTIONS_VAR.pkgbase",
		"${INDIRECT}")

	c.Check(s.Output(), equals, "WARN: fname:2: \"VarBase\" is not a valid variable name.\n")
}

func (s *Suite) TestVartypeCheck_Yes(c *check.C) {
	runVartypeChecks("APACHE_MODULE", opAssign, (*VartypeCheck).Yes,
		"yes",
		"no",
		"${YESVAR}")

	c.Check(s.Output(), equals, ""+
		"WARN: fname:2: APACHE_MODULE should be set to YES or yes.\n"+
		"WARN: fname:3: APACHE_MODULE should be set to YES or yes.\n")

	runVartypeMatchChecks("PKG_DEVELOPER", (*VartypeCheck).Yes,
		"yes",
		"no",
		"${YESVAR}")

	c.Check(s.Output(), equals, ""+
		"WARN: fname:1: PKG_DEVELOPER should only be used in a \".if defined(...)\" conditional.\n"+
		"WARN: fname:2: PKG_DEVELOPER should only be used in a \".if defined(...)\" conditional.\n"+
		"WARN: fname:3: PKG_DEVELOPER should only be used in a \".if defined(...)\" conditional.\n")
}

func (s *Suite) TestVartypeCheck_YesNo(c *check.C) {
	runVartypeChecks("GNU_CONFIGURE", opAssign, (*VartypeCheck).YesNo,
		"yes",
		"no",
		"ja",
		"${YESVAR}")

	c.Check(s.Output(), equals, ""+
		"WARN: fname:3: GNU_CONFIGURE should be set to YES, yes, NO, or no.\n"+
		"WARN: fname:4: GNU_CONFIGURE should be set to YES, yes, NO, or no.\n")
}

func (s *Suite) TestVartypeCheck_YesNoIndirectly(c *check.C) {
	runVartypeChecks("GNU_CONFIGURE", opAssign, (*VartypeCheck).YesNoIndirectly,
		"yes",
		"no",
		"ja",
		"${YESVAR}")

	c.Check(s.Output(), equals, ""+
		"WARN: fname:3: GNU_CONFIGURE should be set to YES, yes, NO, or no.\n")
}

func runVartypeChecks(varname string, op MkOperator, checker func(*VartypeCheck), values ...string) {
	if !contains(op.String(), "=") {
		panic("runVartypeChecks needs an assignment operator")
	}
	for i, value := range values {
		mkline := NewMkLine(NewLine("fname", i+1, varname+op.String()+value, nil))
		valueNovar := mkline.withoutMakeVariables(mkline.Value(), true)
		vc := &VartypeCheck{mkline, mkline.Line, mkline.Varname(), mkline.Op(), mkline.Value(), valueNovar, "", true, false}
		checker(vc)
	}
}

func runVartypeMatchChecks(varname string, checker func(*VartypeCheck), values ...string) {
	for i, value := range values {
		text := fmt.Sprintf(".if ${%s:M%s} == \"\"", varname, value)
		mkline := NewMkLine(NewLine("fname", i+1, text, nil))
		valueNovar := mkline.withoutMakeVariables(value, true)
		vc := &VartypeCheck{mkline, mkline.Line, varname, opUseMatch, value, valueNovar, "", true, false}
		checker(vc)
	}
}

func runVartypeChecksFname(fname, varname string, op MkOperator, checker func(*VartypeCheck), values ...string) {
	for i, value := range values {
		mkline := NewMkLine(NewLine(fname, i+1, varname+op.String()+value, nil))
		valueNovar := mkline.withoutMakeVariables(value, true)
		vc := &VartypeCheck{mkline, mkline.Line, varname, op, value, valueNovar, "", true, false}
		checker(vc)
	}
}
