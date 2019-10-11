package pkglint

import (
	"gopkg.in/check.v1"
)

func (s *Suite) Test_VartypeCheck_AwkCommand(c *check.C) {
	t := s.Init(c)
	vt := NewVartypeCheckTester(t, BtAwkCommand)

	vt.Varname("PRINT_PLIST_AWK")
	vt.Op(opAssignAppend)
	vt.Values(
		"{print $0}",
		"{print $$0}")
	t.DisableTracing()
	vt.Values(
		"{print $0}",
		"{print $$0}")

	// TODO: In this particular context of AWK programs, $$0 is not a shell variable.
	//  The warning should be adjusted to reflect this.

	vt.Output(
		"WARN: filename.mk:1: $0 is ambiguous. "+
			"Use ${0} if you mean a Make variable or $$0 if you mean a shell variable.",
		"WARN: filename.mk:3: $0 is ambiguous. "+
			"Use ${0} if you mean a Make variable or $$0 if you mean a shell variable.")
}

func (s *Suite) Test_VartypeCheck_BasicRegularExpression(c *check.C) {
	t := s.Init(c)
	vt := NewVartypeCheckTester(t, BtBasicRegularExpression)

	vt.Varname("CHECK_FILES_SKIP")
	vt.Values(
		".*\\.pl$",
		".*\\.pl$$",
		"\u1E9E",
		"\\(capture\\)\\1",
		"\\+")

	vt.Output(
		"WARN: filename.mk:1: Internal pkglint error in MkLine.Tokenize at \"$\".",
		"WARN: filename.mk:5: In a basic regular expression, a backslash followed by \"+\" is undefined.")

	// Check for special characters that appear outside of character classes.
	vt.Values(
		"\u0007",
		" !\"\"\\#$$%&''()*+,-./09:;<=>?",
		"@AZ[\\\\]^_``az{|}~",
		"\t")

	vt.OutputEmpty()

	vt.Values(
		"?",
		"\\?",
		"\\\\?",
		"\\\\\\?")

	vt.Output(
		"WARN: filename.mk:22: In a basic regular expression, a backslash followed by \"?\" is undefined.",
		"WARN: filename.mk:24: In a basic regular expression, a backslash followed by \"?\" is undefined.")

	vt.Values(
		"package-[0-9][0-9.]*",
		"unclosed-[",
		// TODO: Warn about the unclosed character class.
		"backslash-[\\")

	vt.OutputEmpty()

	vt.Values(
		// TODO: Warn about incomplete regular expression escape
		"\\",
		"\\\\")

	vt.OutputEmpty()

	vt.Values(
		"${VAR}*",
		"\\?${VAR}\\/")

	vt.Output(
		"WARN: filename.mk:52: In a basic regular expression, a backslash followed by \"?\" is undefined.",
		"WARN: filename.mk:52: In a basic regular expression, a backslash followed by \"/\" is undefined.")
}

func (s *Suite) Test_VartypeCheck_BuildlinkDepmethod(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtBuildlinkDepmethod)

	vt.Varname("BUILDLINK_DEPMETHOD.libc")
	vt.Op(opAssignDefault)
	vt.Values(
		"full",
		"unknown",
		"${BUILDLINK_DEPMETHOD.kernel}")

	vt.Output(
		"WARN: filename.mk:2: Invalid dependency method \"unknown\". Valid methods are \"build\" or \"full\".")
}

func (s *Suite) Test_VartypeCheck_Category(c *check.C) {
	t := s.Init(c)
	vt := NewVartypeCheckTester(t, BtCategory)

	t.CreateFileLines("filesyscategory/Makefile",
		"# empty")
	t.CreateFileLines("wip/Makefile",
		"# empty")

	vt.Varname("CATEGORIES")
	vt.Values(
		"chinese",
		"arabic",
		"filesyscategory",
		"wip")

	vt.Output(
		"ERROR: filename.mk:2: Invalid category \"arabic\".",
		"ERROR: filename.mk:4: Invalid category \"wip\".")
}

func (s *Suite) Test_VartypeCheck_CFlag(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtCFlag)

	vt.tester.SetUpTool("pkg-config", "", AtRunTime)

	vt.Varname("CFLAGS")
	vt.Op(opAssignAppend)
	vt.Values(
		"-Wall",
		"/W3",
		"target:sparc64",
		"-std=c99",
		"-XX:+PrintClassHistogramAfterFullGC",
		"`pkg-config pidgin --cflags`",
		"-c99",
		"-c",
		"-no-integrated-as",
		"-pthread",
		"`pkg-config`_plus")
	vt.OutputEmpty()

	vt.Values(
		"-L${PREFIX}/lib",
		"-L${PREFIX}/lib64",
		"-lncurses",
		"-DMACRO=\\\"",
		"-DMACRO=\\'")

	vt.Output(
		"WARN: filename.mk:21: \"-L${PREFIX}/lib\" is a linker flag "+
			"and belong to LDFLAGS, LIBS or LDADD instead of CFLAGS.",
		"WARN: filename.mk:22: \"-L${PREFIX}/lib64\" is a linker flag "+
			"and belong to LDFLAGS, LIBS or LDADD instead of CFLAGS.",
		"WARN: filename.mk:23: \"-lncurses\" is a linker flag "+
			"and belong to LDFLAGS, LIBS or LDADD instead of CFLAGS.",
		"WARN: filename.mk:24: Compiler flag \"-DMACRO=\\\\\\\"\" "+
			"has unbalanced double quotes.",
		"WARN: filename.mk:25: Compiler flag \"-DMACRO=\\\\'\" "+
			"has unbalanced single quotes.")

	vt.Op(opUseMatch)
	vt.Values(
		"anything")

	vt.OutputEmpty()
}

func (s *Suite) Test_VartypeCheck_Comment(c *check.C) {
	t := s.Init(c)
	vt := NewVartypeCheckTester(t, BtComment)

	G.Pkg = NewPackage(t.File("category/converter"))
	G.Pkg.EffectivePkgbase = "converter"

	vt.Varname("COMMENT")
	vt.Values(
		"Versatile Programming Language",
		"TODO: Short description of the package",
		"A great package.",
		"some packages need a very very long comment to explain their basic usefulness",
		"\"Quoting the comment is wrong\"",
		"'Quoting the comment is wrong'",
		"Package is a great package",
		"Package is an awesome package",
		"The Big New Package is a great package",
		"Converter converts between measurement units",
		"Converter is a unit converter",
		"\"Official\" office suite",
		"'SQL injection fuzzer")

	vt.Output(
		"ERROR: filename.mk:2: COMMENT must be set.",
		"WARN: filename.mk:3: COMMENT should not begin with \"A\".",
		"WARN: filename.mk:3: COMMENT should not end with a period.",
		"WARN: filename.mk:4: COMMENT should start with a capital letter.",
		"WARN: filename.mk:4: COMMENT should not be longer than 70 characters.",
		"WARN: filename.mk:5: COMMENT should not be enclosed in quotes.",
		"WARN: filename.mk:6: COMMENT should not be enclosed in quotes.",
		"WARN: filename.mk:7: COMMENT should not contain \"is a\".",
		"WARN: filename.mk:8: COMMENT should not contain \"is an\".",
		"WARN: filename.mk:9: COMMENT should not contain \"is a\".",
		"WARN: filename.mk:10: COMMENT should not start with the package name.",
		"WARN: filename.mk:11: COMMENT should not start with the package name.",
		"WARN: filename.mk:11: COMMENT should not contain \"is a\".")
}

func (s *Suite) Test_VartypeCheck_ConfFiles(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtConfFiles)

	vt.Varname("CONF_FILES")
	vt.Op(opAssignAppend)
	vt.Values(
		"single/file",
		"share/etc/config ${PKG_SYSCONFDIR}/etc/config",
		"share/etc/config ${PKG_SYSCONFBASE}/etc/config file",
		"share/etc/config ${PREFIX}/etc/config share/etc/config2 ${VARBASE}/config2",
		"share/etc/bootrc /etc/bootrc")

	vt.Output(
		"WARN: filename.mk:1: Values for CONF_FILES should always be pairs of paths.",
		"WARN: filename.mk:3: Values for CONF_FILES should always be pairs of paths.",
		"WARN: filename.mk:5: The destination file \"/etc/bootrc\" should start with a variable reference.")
}

// See Test_MkParser_Dependency.
func (s *Suite) Test_VartypeCheck_Dependency(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtDependency)

	vt.Varname("CONFLICTS")
	vt.Op(opAssignAppend)

	// comparison operators
	vt.Values(
		"perl5>=5.22",
		"libkipi>=0.1.5<4.0",
		"gtk2+>=2.16")
	vt.OutputEmpty()

	// pattern matching
	vt.Values(
		"perl-5*",
		"perl5-*",
		"perl-5.22",
		"perl5-5.22.*",
		"gtksourceview-sharp-2.0-[0-9]*")
	vt.Output(
		"WARN: filename.mk:11: Please use \"5.*\" instead of \"5*\" as the version pattern.",
		"WARN: filename.mk:12: Please use \"perl5-[0-9]*\" instead of \"perl5-*\".",
		"WARN: filename.mk:13: Please use \"5.22{,nb*}\" instead of \"5.22\" as the version pattern.",
		"WARN: filename.mk:15: The version pattern \"2.0-[0-9]*\" should not contain a hyphen.")

	// nb suffix
	vt.Values(
		"perl5-5.22.*{,nb*}",
		"perl-5.22{,nb*}",
		"perl-5.22{,nb[0-9]*}",
		"mbrola-301h{,nb[0-9]*}",
		"ncurses-${NC_VERS}{,nb*}",
		"gnome-control-center>=2.20.1{,nb*}",
		"gnome-control-center>=2.20.1{,nb[0-9]*}")
	vt.Output(
		"WARN: filename.mk:26: Dependency patterns of the form pkgbase>=1.0 don't need the \"{,nb*}\" extension.",
		"WARN: filename.mk:27: Dependency patterns of the form pkgbase>=1.0 don't need the \"{,nb*}\" extension.")

	// alternative patterns, using braces or brackets
	vt.Values(
		"mpg123{,-esound,-nas}>=0.59.18",
		"mysql*-{client,server}-[0-9]*",
		"{ssh{,6}-[0-9]*,openssh-[0-9]*}",
		"libao-[a-z]*-[0-9]*")
	vt.OutputEmpty()

	// variables
	vt.Values(
		"postgresql8[0-35-9]-${module}-[0-9]*",
		"${_EMACS_CONFLICTS.${_EMACS_FLAVOR}}",
		"${PYPKGPREFIX}-sqlite3",
		"${PYPKGPREFIX}-sqlite3-${VERSION}",
		"${PYPKGPREFIX}-sqlite3-${PYSQLITE_REQD}",
		"${PYPKGPREFIX}-sqlite3>=${PYSQLITE_REQD}",
		"${EMACS_PACKAGE}>=${EMACS_MAJOR}",

		// The "*" is ambiguous. It could either continue the PKGBASE or
		// start the version number.
		"${PKGNAME_NOREV:S/jdk/jre/}*",

		// The canonical form is "{,nb*}" instead of "{nb*,}".
		// Plus, mentioning nb* is not necessary when using >=.
		"dovecot>=${PKGVERSION_NOREV}{nb*,}",

		"oxygen-icons>=${KF5VER}{,nb[0-9]*}",

		// The following pattern should have "]*}" instead of "]}*".
		"ja-vflib-lib-${VFLIB_VERSION}{,nb[0-9]}*",

		// The following pattern uses both ">=" and "*", which doesn't make sense.
		"${PYPKGPREFIX}-sphinx>=1.2.3nb1*",

		"{${NETSCAPE_PREFERRED:C/:/,/g}}-[0-9]*")

	vt.Output(
		"WARN: filename.mk:43: Invalid dependency pattern \"${PYPKGPREFIX}-sqlite3\".",
		// This pattern is invalid because the variable name doesn't contain "VER".
		"WARN: filename.mk:45: Invalid dependency pattern \"${PYPKGPREFIX}-sqlite3-${PYSQLITE_REQD}\".",
		"WARN: filename.mk:48: Invalid dependency pattern \"${PKGNAME_NOREV:S/jdk/jre/}*\".",
		"WARN: filename.mk:49: Invalid dependency pattern \"dovecot>=${PKGVERSION_NOREV}{nb*,}\".",
		"WARN: filename.mk:50: Dependency patterns of the form pkgbase>=1.0 don't need the \"{,nb*}\" extension.",
		"WARN: filename.mk:51: Invalid dependency pattern \"ja-vflib-lib-${VFLIB_VERSION}{,nb[0-9]}*\".",
		"WARN: filename.mk:52: Invalid dependency pattern \"${PYPKGPREFIX}-sphinx>=1.2.3nb1*\".")

	// invalid dependency patterns
	vt.Values(
		"Perl",
		"py-docs",
		"perl5-[5.10-5.22]*",
		"package-1.0|garbage",
		"package>=1.0:../../category/package",
		"package-1.0>=1.0.3",
		// This should be regarded as invalid since the [a-z0-9] might either
		// continue the PKGBASE or start the version number.
		"${RUBY_PKGPREFIX}-theme-[a-z0-9]*")
	vt.Output(
		"WARN: filename.mk:61: Invalid dependency pattern \"Perl\".",
		"WARN: filename.mk:62: Invalid dependency pattern \"py-docs\".",
		"WARN: filename.mk:63: Only [0-9]* is allowed in the numeric part of a dependency.",
		"WARN: filename.mk:63: The version pattern \"[5.10-5.22]*\" should not contain a hyphen.",
		"WARN: filename.mk:64: Invalid dependency pattern \"package-1.0|garbage\".",
		// TODO: Mention that the path should be removed.
		"WARN: filename.mk:65: Invalid dependency pattern \"package>=1.0:../../category/package\".",
		// TODO: Mention that version numbers in a pkgbase must be appended directly, without hyphen.
		"WARN: filename.mk:66: Invalid dependency pattern \"package-1.0>=1.0.3\".",
		"WARN: filename.mk:67: Invalid dependency pattern \"${RUBY_PKGPREFIX}-theme-[a-z0-9]*\".")
}

func (s *Suite) Test_VartypeCheck_DependencyWithPath(c *check.C) {
	t := s.Init(c)
	vt := NewVartypeCheckTester(t, BtDependencyWithPath)

	t.CreateFileLines("category/package/Makefile")
	t.CreateFileLines("databases/py-sqlite3/Makefile")
	t.CreateFileLines("devel/gettext/Makefile")
	t.CreateFileLines("devel/gmake/Makefile")
	t.CreateFileLines("devel/py-module/Makefile")
	t.CreateFileLines("x11/alacarte/Makefile")
	G.Pkg = NewPackage(t.File("category/package"))

	vt.Varname("DEPENDS")
	vt.Op(opAssignAppend)
	vt.File(G.Pkg.File("filename.mk"))
	vt.Values(
		"Perl",
		"perl5>=5.22:../perl5",
		"perl5>=5.24:../../lang/perl5",
		"gtk2+>=2.16:../../x11/alacarte",
		"gettext-[0-9]*:../../devel/gettext",
		"gmake-[0-9]*:../../devel/gmake")

	vt.Output(
		"WARN: ~/category/package/filename.mk:1: Invalid dependency pattern with path \"Perl\".",
		"WARN: ~/category/package/filename.mk:2: Dependency paths should have the form \"../../category/package\".",
		"ERROR: ~/category/package/filename.mk:2: Relative path \"../perl5/Makefile\" does not exist.",
		"WARN: ~/category/package/filename.mk:2: \"../perl5\" is not a valid relative package directory.",
		"WARN: ~/category/package/filename.mk:2: Please use USE_TOOLS+=perl:run instead of this dependency.",
		"ERROR: ~/category/package/filename.mk:3: Relative path \"../../lang/perl5/Makefile\" does not exist.",
		"WARN: ~/category/package/filename.mk:3: Please use USE_TOOLS+=perl:run instead of this dependency.",
		"WARN: ~/category/package/filename.mk:5: Please use USE_TOOLS+=msgfmt instead of this dependency.",
		"WARN: ~/category/package/filename.mk:6: Please use USE_TOOLS+=gmake instead of this dependency.")

	vt.Values(
		"broken0.12.1:../../x11/alacarte", // missing version
		"broken[0-9]*:../../x11/alacarte", // missing version
		"broken[0-9]*../../x11/alacarte",  // missing colon
		"broken>=:../../x11/alacarte",     // incomplete comparison
		"broken=0:../../x11/alacarte",     // invalid comparison operator
		"broken=:../../x11/alacarte",      // incomplete comparison
		"broken-:../../x11/alacarte",      // incomplete pattern
		"broken>:../../x11/alacarte")      // incomplete comparison

	vt.Output(
		"WARN: ~/category/package/filename.mk:11: Invalid dependency pattern \"broken0.12.1\".",
		"WARN: ~/category/package/filename.mk:12: Invalid dependency pattern \"broken[0-9]*\".",
		"WARN: ~/category/package/filename.mk:13: Invalid dependency pattern with path \"broken[0-9]*../../x11/alacarte\".",
		"WARN: ~/category/package/filename.mk:14: Invalid dependency pattern \"broken>=\".",
		"WARN: ~/category/package/filename.mk:15: Invalid dependency pattern \"broken=0\".",
		"WARN: ~/category/package/filename.mk:16: Invalid dependency pattern \"broken=\".",
		"WARN: ~/category/package/filename.mk:17: Invalid dependency pattern \"broken-\".",
		"WARN: ~/category/package/filename.mk:18: Invalid dependency pattern \"broken>\".")

	vt.Values(
		"${PYPKGPREFIX}-sqlite3:../../${MY_PKGPATH.py-sqlite3}",
		"${PYPKGPREFIX}-sqlite3:../../databases/py-sqlite3",
		"${DEPENDS.NetBSD}",
		"${DEPENDENCY_PATTERN.py-sqlite3}:${DEPENDENCY_PATH.py-sqlite}",
		"${PYPKGPREFIX}-module>=0:../../devel/py-module",
		"${EMACS_PACKAGE}>=${EMACS_MAJOR}:${EMACS_PKGDIR}",
		"{${NETSCAPE_PREFERRED:C/:/,/g}}-[0-9]*:../../www/${NETSCAPE_PREFERRED:C/:.*//}")

	vt.Output(
		"WARN: ~/category/package/filename.mk:21: "+
			"Invalid dependency pattern \"${PYPKGPREFIX}-sqlite3\".",
		"WARN: ~/category/package/filename.mk:22: "+
			"Invalid dependency pattern \"${PYPKGPREFIX}-sqlite3\".")
}

func (s *Suite) Test_VartypeCheck_DistSuffix(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtDistSuffix)

	vt.Varname("EXTRACT_SUFX")
	vt.Values(
		".tar.gz",
		".tar.bz2",
		".tar.gz # overrides a definition from a Makefile.common")

	vt.Output(
		"NOTE: filename.mk:1: EXTRACT_SUFX is \".tar.gz\" by default, so this definition may be redundant.")
}

func (s *Suite) Test_VartypeCheck_EmulPlatform(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtEmulPlatform)

	vt.Varname("EMUL_PLATFORM")
	vt.Values(
		"linux-i386",
		"nextbsd-8087",
		"${LINUX}")

	vt.Output(
		"WARN: filename.mk:2: \"nextbsd\" is not valid for the operating system part of EMUL_PLATFORM. "+
			"Use one of "+
			"{ bitrig bsdos cygwin darwin dragonfly freebsd haiku hpux "+
			"interix irix linux mirbsd netbsd openbsd osf1 solaris sunos "+
			"} instead.",
		"WARN: filename.mk:2: \"8087\" is not valid for the hardware architecture part of EMUL_PLATFORM. "+
			"Use one of { "+
			"aarch64 aarch64eb alpha amd64 arc arm arm26 arm32 "+
			"cobalt coldfire convex dreamcast "+
			"earm earmeb earmhf earmhfeb earmv4 earmv4eb earmv5 earmv5eb "+
			"earmv6 earmv6eb earmv6hf earmv6hfeb "+
			"earmv7 earmv7eb earmv7hf earmv7hfeb evbarm "+
			"hpcmips hpcsh hppa hppa64 "+
			"i386 i586 i686 ia64 m68000 m68k m88k "+
			"mips mips64 mips64eb mips64el mipseb mipsel mipsn32 "+
			"mlrisc ns32k pc532 pmax powerpc powerpc64 rs6000 "+
			"s390 sh3eb sh3el sparc sparc64 vax x86_64 "+
			"} instead.",
		"WARN: filename.mk:3: \"${LINUX}\" is not a valid emulation platform.")
}

func (s *Suite) Test_VartypeCheck_Enum(c *check.C) {
	basicType := enum("jdk1 jdk2 jdk4")
	G.Pkgsrc.vartypes.Define("JDK", basicType, UserSettable)
	vt := NewVartypeCheckTester(s.Init(c), basicType)

	vt.Varname("JDK")
	vt.Op(opUseMatch)
	vt.Values(
		"*",
		"jdk*",
		"sun-jdk*",
		"${JDKNAME}",
		"[")

	vt.Output(
		"WARN: filename.mk:3: The pattern \"sun-jdk*\" cannot match any of { jdk1 jdk2 jdk4 } for JDK.",
		"WARN: filename.mk:5: Invalid match pattern \"[\".")
}

func (s *Suite) Test_VartypeCheck_Enum__use_match(c *check.C) {
	t := s.Init(c)

	t.SetUpVartypes()
	t.SetUpCommandLine("-Wall", "--explain")

	mklines := t.NewMkLines("module.mk",
		MkCvsID,
		"",
		".if !empty(MACHINE_ARCH:Mi386) || ${MACHINE_ARCH} == i386",
		".endif",
		".if !empty(PKGSRC_COMPILER:Mclang) || ${PKGSRC_COMPILER} == clang",
		".endif",
		".if ${MACHINE_ARCH:Ni386:Nx86_64:Nsparc64}",
		".endif")

	mklines.Check()

	t.CheckOutputLines(
		"NOTE: module.mk:3: MACHINE_ARCH should be compared using == instead of matching against \":Mi386\".",
		"",
		"\tThis variable has a single value, not a list of values. Therefore it",
		"\tfeels strange to apply list operators like :M and :N onto it. A more",
		"\tdirect approach is to use the == and != operators.",
		"",
		"\tAn entirely different case is when the pattern contains wildcards",
		"\tlike ^, *, $. In such a case, using the :M or :N modifiers is useful",
		"\tand preferred.",
		"",
		"WARN: module.mk:5: Use ${PKGSRC_COMPILER:Mclang} instead of the == operator.",
		"",
		"\tThe PKGSRC_COMPILER can be a list of chained compilers, e.g. \"ccache",
		"\tdistcc clang\". Therefore, comparing it using == or != leads to wrong",
		"\tresults in these cases.",
		"")
}

func (s *Suite) Test_VartypeCheck_FetchURL(c *check.C) {
	t := s.Init(c)

	t.SetUpPackage("category/own-master-site",
		"MASTER_SITE_OWN=\thttps://example.org/")
	t.FinishSetUp()

	vt := NewVartypeCheckTester(t, BtFetchURL)

	t.SetUpMasterSite("MASTER_SITE_GNU", "http://ftp.gnu.org/pub/gnu/")
	t.SetUpMasterSite("MASTER_SITE_GITHUB", "https://github.com/")

	G.Pkg = NewPackage(t.File("category/own-master-site"))
	G.Pkg.load()

	vt.Varname("MASTER_SITES")
	vt.Values(
		"https://github.com/example/project/",
		"http://ftp.gnu.org/pub/gnu/bison", // Missing a slash at the end
		"${MASTER_SITE_GNU:=bison}",
		"${MASTER_SITE_INVALID:=subdir/}",
		"${MASTER_SITE_OWN}",
		"${MASTER_SITE_OWN:=subdir/}")

	vt.Output(
		"WARN: filename.mk:1: Please use ${MASTER_SITE_GITHUB:=example/} "+
			"instead of \"https://github.com/example/\" "+
			"and run \""+confMake+" help topic=github\" for further instructions.",
		"WARN: filename.mk:2: Please use ${MASTER_SITE_GNU:=bison} "+
			"instead of \"http://ftp.gnu.org/pub/gnu/bison\".",
		"ERROR: filename.mk:3: The subdirectory in MASTER_SITE_GNU must end with a slash.",
		"ERROR: filename.mk:4: The site MASTER_SITE_INVALID does not exist.")

	// PR 46570, keyword gimp-fix-ca
	vt.Values(
		"https://example.org/download.cgi?filename=filename&sha1=12341234")

	vt.Output(
		"WARN: filename.mk:11: The fetch URL \"https://example.org/download.cgi" +
			"?filename=filename&sha1=12341234\" should end with a slash.")

	vt.Values(
		"http://example.org/distfiles/",
		"http://example.org/download?filename=distfile;version=1.0",
		"http://example.org/download?filename=<distfile>;version=<version>")

	vt.Output(
		"WARN: filename.mk:22: The fetch URL \"http://example.org/download"+
			"?filename=distfile;version=1.0\" should end with a slash.",
		"WARN: filename.mk:23: \"http://example.org/download"+
			"?filename=<distfile>;version=<version>\" is not a valid URL.",
		"WARN: filename.mk:23: The fetch URL \"http://example.org/download"+
			"?filename=<distfile>;version=<version>\" should end with a slash.")

	vt.Values(
		"${MASTER_SITE_GITHUB:S,^,-,:=project/archive/${DISTFILE}}")

	// No warning that the part after the := must end with a slash,
	// since there is another modifier in the variable use, in this case :S.
	//
	// That modifier adds a hyphen at the beginning (but pkglint doesn't
	// inspect this), therefore the URL is not required to end with a slash anymore.
	vt.OutputEmpty()

	// As of June 2019, the :S modifier is not analyzed since it is unusual.
	vt.Values(
		"${MASTER_SITE_GNU:S,$,subdir,}",
		"${MASTER_SITE_GNU:S,$,subdir/,}")
	vt.OutputEmpty()

	vt.Values(
		"https://github.com/transmission/transmission-releases/raw/master/")
	vt.Output(
		"WARN: filename.mk:51: Please use ${MASTER_SITE_GITHUB:=transmission/} " +
			"instead of \"https://github.com/transmission/\" " +
			"and run \"" + confMake + " help topic=github\" for further instructions.")

	vt.Values(
		"-https://example.org/distfile.tar.gz",
		"-http://ftp.gnu.org/pub/gnu/bash-5.0.tar.gz",
		"-http://ftp.gnu.org/pub/gnu/bash/bash-5.0.tar.gz")

	vt.Output(
		"WARN: filename.mk:62: Please use ${MASTER_SITE_GNU:S,^,-,:=bash-5.0.tar.gz} "+
			"instead of \"-http://ftp.gnu.org/pub/gnu/bash-5.0.tar.gz\".",
		"WARN: filename.mk:63: Please use ${MASTER_SITE_GNU:S,^,-,:=bash/bash-5.0.tar.gz} "+
			"instead of \"-http://ftp.gnu.org/pub/gnu/bash/bash-5.0.tar.gz\".")

	vt.Values(
		"https://example.org/pub",
		"https://example.org/$@", // Doesn't make sense at all.
		"https://example.org/?f=",
		"https://example.org/download:",
		"https://example.org/download?")

	vt.Output(
		"WARN: filename.mk:71: The fetch URL \"https://example.org/pub\" should end with a slash.",
		"WARN: filename.mk:72: \"https://example.org/$@\" is not a valid URL.",
		"WARN: filename.mk:75: The fetch URL \"https://example.org/download?\" should end with a slash.")

	// The transport protocol doesn't matter for matching the MASTER_SITEs.
	// See url2pkg.py, function adjust_site_from_sites_mk.
	vt.Values(
		"http://ftp.gnu.org/pub/gnu/bash/",
		"ftp://ftp.gnu.org/pub/gnu/bash/",
		"https://ftp.gnu.org/pub/gnu/bash/",
		"-http://ftp.gnu.org/pub/gnu/bash/bash-5.0.tar.gz",
		"-ftp://ftp.gnu.org/pub/gnu/bash/bash-5.0.tar.gz",
		"-https://ftp.gnu.org/pub/gnu/bash/bash-5.0.tar.gz")

	vt.Output(
		"WARN: filename.mk:81: Please use ${MASTER_SITE_GNU:=bash/} "+
			"instead of \"http://ftp.gnu.org/pub/gnu/bash/\".",
		"WARN: filename.mk:82: Please use ${MASTER_SITE_GNU:=bash/} "+
			"instead of \"ftp://ftp.gnu.org/pub/gnu/bash/\".",
		"WARN: filename.mk:83: Please use ${MASTER_SITE_GNU:=bash/} "+
			"instead of \"https://ftp.gnu.org/pub/gnu/bash/\".",
		"WARN: filename.mk:84: Please use ${MASTER_SITE_GNU:S,^,-,:=bash/bash-5.0.tar.gz} "+
			"instead of \"-http://ftp.gnu.org/pub/gnu/bash/bash-5.0.tar.gz\".",
		"WARN: filename.mk:85: Please use ${MASTER_SITE_GNU:S,^,-,:=bash/bash-5.0.tar.gz} "+
			"instead of \"-ftp://ftp.gnu.org/pub/gnu/bash/bash-5.0.tar.gz\".",
		"WARN: filename.mk:86: Please use ${MASTER_SITE_GNU:S,^,-,:=bash/bash-5.0.tar.gz} "+
			"instead of \"-https://ftp.gnu.org/pub/gnu/bash/bash-5.0.tar.gz\".")
}

func (s *Suite) Test_VartypeCheck_FetchURL__without_package(c *check.C) {
	t := s.Init(c)

	vt := NewVartypeCheckTester(t, BtFetchURL)

	vt.Varname("MASTER_SITES")
	vt.Values(
		"https://github.com/example/project/",
		"${MASTER_SITE_OWN}")

	vt.Output(
		"ERROR: filename.mk:2: The site MASTER_SITE_OWN does not exist.")
}

func (s *Suite) Test_VartypeCheck_Filename(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtFilename)

	vt.Varname("JAVA_NAME")
	vt.Values(
		"Filename with spaces.docx",
		"OS/2-manual.txt")

	vt.Output(
		"WARN: filename.mk:1: The filename \"Filename with spaces.docx\" contains the invalid characters \"  \".",
		"WARN: filename.mk:2: The filename \"OS/2-manual.txt\" contains the invalid character \"/\".")

	vt.Op(opUseMatch)
	vt.Values(
		"Filename with spaces.docx")

	// There's no guarantee that a filename only contains [A-Za-z0-9.].
	// Therefore there are no useful checks in this situation.
	vt.Output(
		"WARN: filename.mk:11: The filename pattern \"Filename with spaces.docx\" " +
			"contains the invalid characters \"  \".")
}

func (s *Suite) Test_VartypeCheck_FilePattern(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtFilePattern)

	vt.Varname("PKGWILDCARD")
	vt.Values(
		"filename.txt",
		"*.txt",
		"[12345].txt",
		"[0-9].txt",
		"???.txt",
		"FilePattern with spaces.docx",
		"OS/2-manual.txt")

	vt.Output(
		"WARN: filename.mk:6: The filename pattern \"FilePattern with spaces.docx\" "+
			"contains the invalid characters \"  \".",
		"WARN: filename.mk:7: The filename pattern \"OS/2-manual.txt\" "+
			"contains the invalid character \"/\".")

	vt.Op(opUseMatch)
	vt.Values(
		"FilePattern with spaces.docx")

	// There's no guarantee that a filename only contains [A-Za-z0-9.].
	// Therefore it might be necessary to allow all characters here.
	// TODO: Investigate whether this restriction is useful in practice.
	vt.Output(
		"WARN: filename.mk:11: The filename pattern \"FilePattern with spaces.docx\" " +
			"contains the invalid characters \"  \".")
}

func (s *Suite) Test_VartypeCheck_FileMode(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtFileMode)

	vt.Varname("GAMEMODE")
	vt.Values(
		"u+rwx",
		"0600",
		"1234",
		"12345",
		"${OTHER_PERMS}",
		"")

	vt.Output(
		"WARN: filename.mk:1: Invalid file mode \"u+rwx\".",
		"WARN: filename.mk:4: Invalid file mode \"12345\".",
		"WARN: filename.mk:6: Invalid file mode \"\".")

	vt.Op(opUseMatch)
	vt.Values(
		"u+rwx")

	// There's no guarantee that a filename only contains [A-Za-z0-9.].
	// Therefore there are no useful checks in this situation.
	vt.Output(
		"WARN: filename.mk:11: Invalid file mode \"u+rwx\".")
}

func (s *Suite) Test_VartypeCheck_GccReqd(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtGccReqd)

	vt.Varname("GCC_REQD")
	vt.Op(opAssignAppend)
	vt.Values(
		"2.95",
		"3.1.5",
		"4.7",
		"4.8",
		"5.1",
		"6",
		"7.3")
	vt.Output(
		"WARN: filename.mk:5: GCC version numbers should only contain the major version (5).",
		"WARN: filename.mk:7: GCC version numbers should only contain the major version (7).")
}

func (s *Suite) Test_VartypeCheck_Homepage(c *check.C) {
	t := s.Init(c)
	vt := NewVartypeCheckTester(t, BtHomepage)

	vt.Varname("HOMEPAGE")
	vt.Values(
		"http://www.pkgsrc.org/",
		"https://www.pkgsrc.org/",
		"${MASTER_SITES}")

	vt.Output(
		"WARN: filename.mk:3: HOMEPAGE should not be defined in terms of MASTER_SITEs.")

	G.Pkg = NewPackage(t.File("category/package"))

	vt.Values(
		"${MASTER_SITES}")

	// When this assignment occurs while checking a package, but the package
	// doesn't define MASTER_SITES, that variable cannot be expanded, which means
	// the warning cannot refer to its value.
	vt.Output(
		"WARN: filename.mk:11: HOMEPAGE should not be defined in terms of MASTER_SITEs.")

	delete(G.Pkg.vars.firstDef, "MASTER_SITES")
	delete(G.Pkg.vars.lastDef, "MASTER_SITES")
	G.Pkg.vars.Define("MASTER_SITES", t.NewMkLine(G.Pkg.File("Makefile"), 5,
		"MASTER_SITES=\thttps://cdn.NetBSD.org/pub/pkgsrc/distfiles/"))

	vt.Values(
		"${MASTER_SITES}")

	vt.Output(
		"WARN: filename.mk:21: HOMEPAGE should not be defined in terms of MASTER_SITEs. " +
			"Use https://cdn.NetBSD.org/pub/pkgsrc/distfiles/ directly.")

	delete(G.Pkg.vars.firstDef, "MASTER_SITES")
	delete(G.Pkg.vars.lastDef, "MASTER_SITES")
	G.Pkg.vars.Define("MASTER_SITES", t.NewMkLine(G.Pkg.File("Makefile"), 5,
		"MASTER_SITES=\t${MASTER_SITE_GITHUB}"))

	vt.Values(
		"${MASTER_SITES}")

	// When MASTER_SITES itself makes use of another variable, pkglint doesn't
	// resolve that variable and just outputs the simple variant of this warning.
	vt.Output(
		"WARN: filename.mk:31: HOMEPAGE should not be defined in terms of MASTER_SITEs.")

	delete(G.Pkg.vars.firstDef, "MASTER_SITES")
	delete(G.Pkg.vars.lastDef, "MASTER_SITES")
	G.Pkg.vars.Define("MASTER_SITES", t.NewMkLine(G.Pkg.File("Makefile"), 5,
		"MASTER_SITES=\t# none"))

	vt.Values(
		"${MASTER_SITES}")

	// When MASTER_SITES is empty, pkglint cannot extract the first of the URLs
	// for using it in the HOMEPAGE.
	vt.Output(
		"WARN: filename.mk:41: HOMEPAGE should not be defined in terms of MASTER_SITEs.")
}

func (s *Suite) Test_VartypeCheck_Identifier(c *check.C) {
	t := s.Init(c)
	vt := NewVartypeCheckTester(t, BtIdentifier)

	vt.Varname("MYSQL_CHARSET")
	vt.Values(
		"${OTHER_VAR}",
		"identifiers cannot contain spaces",
		"id/cannot/contain/slashes",
		"id-${OTHER_VAR}",
		"")

	vt.Output(
		"WARN: filename.mk:2: Invalid identifier \"identifiers cannot contain spaces\".",
		"WARN: filename.mk:3: Invalid identifier \"id/cannot/contain/slashes\".",
		"WARN: filename.mk:5: Invalid identifier \"\".")

	vt.Op(opUseMatch)
	vt.Values(
		"[A-Z]",
		"[A-Z.]",
		"${PKG_OPTIONS:Moption}",
		"A*B")

	vt.Output(
		"WARN: filename.mk:12: Invalid identifier pattern \"[A-Z.]\" for MYSQL_CHARSET.")
}

func (s *Suite) Test_VartypeCheck_Integer(c *check.C) {
	t := s.Init(c)
	vt := NewVartypeCheckTester(t, BtInteger)

	vt.Varname("MAKE_JOBS")
	vt.Values(
		"${OTHER_VAR}",
		"123",
		"-13",
		"11111111111111111111111111111111111111111111111")

	vt.Output(
		"WARN: filename.mk:1: Invalid integer \"${OTHER_VAR}\".",
		"WARN: filename.mk:3: Invalid integer \"-13\".")
}

func (s *Suite) Test_VartypeCheck_LdFlag(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtLdFlag)

	vt.tester.SetUpTool("pkg-config", "", AtRunTime)

	vt.Varname("LDFLAGS")
	vt.Op(opAssignAppend)
	vt.Values(
		"-lc",
		"-L/usr/lib64",
		"`pkg-config pidgin --ldflags`",
		"-unknown",
		"no-hyphen",
		"-Wl,--rpath,/usr/lib64",
		"-pthread",
		"-static",
		"-static-something",
		"${LDFLAGS.NetBSD}",
		"-l${LIBNCURSES}",
		"`pkg-config`_plus",
		"-DMACRO",
		"-UMACRO",
		"-P",
		"-E",
		"-I${PREFIX}/include")
	vt.Op(opUseMatch)
	vt.Values(
		"anything")

	vt.Output(
		"WARN: filename.mk:6: Please use \"${COMPILER_RPATH_FLAG}\" instead of \"-Wl,--rpath\".",
		"WARN: filename.mk:13: \"-DMACRO\" is a compiler flag "+
			"and belongs on CFLAGS, CPPFLAGS, CXXFLAGS or FFLAGS instead of LDFLAGS.",
		"WARN: filename.mk:14: \"-UMACRO\" is a compiler flag "+
			"and belongs on CFLAGS, CPPFLAGS, CXXFLAGS or FFLAGS instead of LDFLAGS.",
		"WARN: filename.mk:15: \"-P\" is a compiler flag "+
			"and belongs on CFLAGS, CPPFLAGS, CXXFLAGS or FFLAGS instead of LDFLAGS.",
		"WARN: filename.mk:16: \"-E\" is a compiler flag "+
			"and belongs on CFLAGS, CPPFLAGS, CXXFLAGS or FFLAGS instead of LDFLAGS.",
		"WARN: filename.mk:17: \"-I${PREFIX}/include\" is a compiler flag "+
			"and belongs on CFLAGS, CPPFLAGS, CXXFLAGS or FFLAGS instead of LDFLAGS.")
}

func (s *Suite) Test_VartypeCheck_License(c *check.C) {
	t := s.Init(c)

	t.SetUpPkgsrc() // Adds the gnu-gpl-v2 and 2-clause-bsd licenses
	t.SetUpPackage("category/package")
	t.FinishSetUp()

	G.Pkg = NewPackage(t.File("category/package"))

	mklines := t.NewMkLines("perl5.mk",
		MkCvsID,
		"PERL5_LICENSE= gnu-gpl-v2 OR artistic")
	// Also registers the PERL5_LICENSE variable in the package.
	mklines.collectVariables()

	vt := NewVartypeCheckTester(t, BtLicense)

	vt.Varname("LICENSE")
	vt.Values(
		"gnu-gpl-v2",
		"AND mit",
		"${PERL5_LICENSE}", // Is properly resolved, see perl5.mk above.
		"${UNKNOWN_LICENSE}")

	vt.Output(
		"ERROR: filename.mk:2: Parse error for license condition \"AND mit\".",
		"WARN: filename.mk:3: License file ~/licenses/artistic does not exist.",
		"ERROR: filename.mk:4: Parse error for license condition \"${UNKNOWN_LICENSE}\".")

	vt.Op(opAssignAppend)
	vt.Values(
		"gnu-gpl-v2",
		"AND mit")

	vt.Output(
		"ERROR: filename.mk:11: Parse error for appended license condition \"gnu-gpl-v2\".",
		"WARN: filename.mk:12: License file ~/licenses/mit does not exist.")
}

func (s *Suite) Test_VartypeCheck_MachineGnuPlatform(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtMachineGnuPlatform)

	vt.Varname("MACHINE_GNU_PLATFORM")
	vt.Op(opUseMatch)
	vt.Values(
		"x86_64-pc-cygwin",
		"Cygwin-*-amd64",
		"x86_64-*",
		"*-*-*-*",
		"${OTHER_VAR}",
		"x86_64-pc") // Just for code coverage.

	vt.Output(
		"WARN: filename.mk:2: The pattern \"Cygwin\" cannot match any of "+
			"{ aarch64 aarch64_be alpha amd64 arc arm armeb armv4 armv4eb armv6 armv6eb armv7 armv7eb "+
			"cobalt convex dreamcast hpcmips hpcsh hppa hppa64 i386 i486 ia64 m5407 m68010 m68k m88k "+
			"mips mips64 mips64el mipseb mipsel mipsn32 mlrisc ns32k pc532 pmax powerpc powerpc64 "+
			"rs6000 s390 sh shle sparc sparc64 vax x86_64 "+
			"} for the hardware architecture part of MACHINE_GNU_PLATFORM.",
		"WARN: filename.mk:2: The pattern \"amd64\" cannot match any of "+
			"{ bitrig bsdos cygwin darwin dragonfly freebsd haiku hpux interix irix linux mirbsd "+
			"netbsd openbsd osf1 solaris sunos } "+
			"for the operating system part of MACHINE_GNU_PLATFORM.",
		"WARN: filename.mk:4: \"*-*-*-*\" is not a valid platform pattern.",
		"WARN: filename.mk:6: \"x86_64-pc\" is not a valid platform pattern.")
}

func (s *Suite) Test_VartypeCheck_MachinePlatformPattern(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtMachinePlatformPattern)

	vt.Varname("ONLY_FOR_PLATFORM")
	vt.Op(opUseMatch)
	vt.Values(
		"linux-i386",
		"nextbsd-5.0-8087",
		"netbsd-7.0-l*",
		"NetBSD-1.6.2-i386",
		"FreeBSD*",
		"FreeBSD-*",
		"${LINUX}",
		"NetBSD-[0-1]*-*")

	vt.Output(
		"WARN: filename.mk:1: \"linux-i386\" is not a valid platform pattern.",
		"WARN: filename.mk:2: The pattern \"nextbsd\" cannot match any of "+
			"{ AIX BSDOS Bitrig Cygwin Darwin DragonFly FreeBSD FreeMiNT GNUkFreeBSD HPUX Haiku "+
			"IRIX Interix Linux Minix MirBSD NetBSD OSF1 OpenBSD QNX SCO_SV SunOS UnixWare "+
			"} for the operating system part of ONLY_FOR_PLATFORM.",
		"WARN: filename.mk:2: The pattern \"8087\" cannot match any of "+
			"{ aarch64 aarch64eb alpha amd64 arc arm arm26 arm32 "+
			"cobalt coldfire convex dreamcast "+
			"earm earmeb earmhf earmhfeb earmv4 earmv4eb "+
			"earmv5 earmv5eb earmv6 earmv6eb earmv6hf "+
			"earmv6hfeb earmv7 earmv7eb earmv7hf earmv7hfeb evbarm hpcmips hpcsh hppa hppa64 "+
			"i386 i586 i686 ia64 m68000 m68k m88k "+
			"mips mips64 mips64eb mips64el mipseb mipsel mipsn32 "+
			"mlrisc ns32k pc532 pmax powerpc powerpc64 "+
			"rs6000 s390 sh3eb sh3el sparc sparc64 vax x86_64 "+
			"} for the hardware architecture part of ONLY_FOR_PLATFORM.",
		"WARN: filename.mk:3: The pattern \"netbsd\" cannot match any of "+
			"{ AIX BSDOS Bitrig Cygwin Darwin DragonFly FreeBSD FreeMiNT GNUkFreeBSD HPUX Haiku "+
			"IRIX Interix Linux Minix MirBSD NetBSD OSF1 OpenBSD QNX SCO_SV SunOS UnixWare "+
			"} for the operating system part of ONLY_FOR_PLATFORM.",
		"WARN: filename.mk:3: The pattern \"l*\" cannot match any of "+
			"{ aarch64 aarch64eb alpha amd64 arc arm arm26 arm32 "+
			"cobalt coldfire convex dreamcast "+
			"earm earmeb earmhf earmhfeb earmv4 earmv4eb "+
			"earmv5 earmv5eb earmv6 earmv6eb earmv6hf "+
			"earmv6hfeb earmv7 earmv7eb earmv7hf earmv7hfeb evbarm hpcmips hpcsh hppa hppa64 "+
			"i386 i586 i686 ia64 m68000 m68k m88k "+
			"mips mips64 mips64eb mips64el mipseb mipsel mipsn32 "+
			"mlrisc ns32k pc532 pmax powerpc powerpc64 "+
			"rs6000 s390 sh3eb sh3el sparc sparc64 vax x86_64 "+
			"} for the hardware architecture part of ONLY_FOR_PLATFORM.",
		"WARN: filename.mk:5: \"FreeBSD*\" is not a valid platform pattern.",
		"WARN: filename.mk:8: Please use \"[0-1].*\" instead of \"[0-1]*\" as the version pattern.")
}

func (s *Suite) Test_VartypeCheck_MailAddress(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtMailAddress)

	vt.Varname("MAINTAINER")
	vt.Values(
		"pkgsrc-users@netbsd.org",
		"tech-pkg@NetBSD.org",
		"packages@NetBSD.org",
		"user1@example.org,user2@example.org")

	vt.Output(
		"WARN: filename.mk:1: Please write \"NetBSD.org\" instead of \"netbsd.org\".",
		"ERROR: filename.mk:2: This mailing list address is obsolete. Use pkgsrc-users@NetBSD.org instead.",
		"ERROR: filename.mk:3: This mailing list address is obsolete. Use pkgsrc-users@NetBSD.org instead.",
		"WARN: filename.mk:4: \"user1@example.org,user2@example.org\" is not a valid mail address.")
}

func (s *Suite) Test_VartypeCheck_Message(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtMessage)

	vt.Varname("SUBST_MESSAGE.id")
	vt.Values(
		"\"Correct paths\"",
		"Correct paths")

	vt.Output(
		"WARN: filename.mk:1: SUBST_MESSAGE.id should not be quoted.")
}

func (s *Suite) Test_VartypeCheck_Option(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtOption)

	G.Pkgsrc.PkgOptions["documented"] = "Option description"
	G.Pkgsrc.PkgOptions["undocumented"] = ""

	vt.Varname("PKG_OPTIONS.pkgbase")
	vt.Values(
		"documented",
		"undocumented",
		"unknown",
		"underscore_is_deprecated",
		"UPPER")

	vt.Output(
		"WARN: filename.mk:3: Unknown option \"unknown\".",
		"WARN: filename.mk:4: Use of the underscore character in option names is deprecated.",
		"ERROR: filename.mk:5: Invalid option name \"UPPER\". "+
			"Option names must start with a lowercase letter and be all-lowercase.")
}

func (s *Suite) Test_VartypeCheck_Pathlist(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtPathlist)

	vt.Varname("PATH")
	vt.Values(
		"/usr/bin:/usr/sbin:.::${LOCALBASE}/bin:${HOMEPAGE:S,https://,,}:${TMPDIR}:${PREFIX}/!!!",
		"/directory with spaces")

	vt.Output(
		"ERROR: filename.mk:1: The component \".\" of PATH must be an absolute path.",
		"ERROR: filename.mk:1: The component \"\" of PATH must be an absolute path.",
		"WARN: filename.mk:1: \"${PREFIX}/!!!\" is not a valid pathname.",
		"WARN: filename.mk:2: \"/directory with spaces\" is not a valid pathname.")
}

func (s *Suite) Test_VartypeCheck_PathPattern(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtPathPattern)

	vt.Varname("DISTDIRS")
	vt.Values(
		"/home/user/*",
		"src/*&*",
		"src/*/*")

	vt.Output(
		"WARN: filename.mk:2: The pathname pattern \"src/*&*\" contains the invalid character \"&\".")

	vt.Op(opUseMatch)
	vt.Values("any")

	vt.OutputEmpty()
}

func (s *Suite) Test_VartypeCheck_Pathname(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtPathname)

	vt.Varname("EGDIR")
	vt.Values(
		"${PREFIX}/*",
		"${PREFIX}/share/locale",
		"share/locale",
		"/bin")
	vt.Op(opUseMatch)
	vt.Values(
		"anything")

	vt.Output(
		"WARN: filename.mk:1: The pathname \"${PREFIX}/*\" contains the invalid character \"*\".")
}

func (s *Suite) Test_VartypeCheck_Perl5Packlist(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtPerl5Packlist)

	vt.Varname("PERL5_PACKLIST")
	vt.Values(
		"${PKGBASE}",
		"anything else")

	vt.Output(
		"WARN: filename.mk:1: PERL5_PACKLIST should not depend on other variables.")
}

func (s *Suite) Test_VartypeCheck_Perms(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtPerms)

	vt.Varname("CONF_FILES_PERMS")
	vt.Op(opAssignAppend)
	vt.Values(
		"root",
		"${ROOT_USER}",
		"ROOT_USER",
		"${REAL_ROOT_USER}",
		"${ROOT_GROUP}",
		"${REAL_ROOT_GROUP}")

	vt.Output(
		"ERROR: filename.mk:2: ROOT_USER must not be used in permission definitions. Use REAL_ROOT_USER instead.",
		"ERROR: filename.mk:5: ROOT_GROUP must not be used in permission definitions. Use REAL_ROOT_GROUP instead.")
}

func (s *Suite) Test_VartypeCheck_Pkgname(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtPkgname)

	vt.Varname("PKGNAME")
	vt.Values(
		"pkgbase-0",
		"pkgbase-1.0",
		"pkgbase-1.1234567890",
		"pkgbase-1z",
		"pkgbase-client-11a",
		"pkgbase-client-1.a",
		"pkgbase-client-1_20180101",
		"pkgbase-z1",
		"pkgbase-3.1.4.1.5.9.2.6.5.3.5.8.9.7.9")

	vt.Output(
		"WARN: filename.mk:8: \"pkgbase-z1\" is not a valid package name.")

	vt.Values(
		"pkgbase-1.0nb17")

	vt.Output(
		"ERROR: filename.mk:11: The \"nb\" part of the version number belongs in PKGREVISION.")

	vt.Op(opUseMatch)
	vt.Values(
		"pkgbase-[0-9]*")

	vt.OutputEmpty()
}

func (s *Suite) Test_VartypeCheck_PkgOptionsVar(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtPkgOptionsVar)

	vt.Varname("PKG_OPTIONS_VAR")
	vt.Values(
		"PKG_OPTIONS.${PKGBASE}",
		"PKG_OPTIONS.anypkgbase",
		"PKG_OPTS.mc")

	vt.Output(
		"ERROR: filename.mk:1: PKGBASE must not be used in PKG_OPTIONS_VAR.",
		"ERROR: filename.mk:3: PKG_OPTIONS_VAR must be "+
			"of the form \"PKG_OPTIONS.*\", not \"PKG_OPTS.mc\".")
}

func (s *Suite) Test_VartypeCheck_Pkgpath(c *check.C) {
	t := s.Init(c)
	vt := NewVartypeCheckTester(t, BtPkgpath)

	t.CreateFileLines("category/Makefile")
	t.CreateFileLines("category/other-package/Makefile")
	t.CreateFileLines("wip/package/Makefile")
	t.Chdir("category/package")

	vt.Varname("PKGPATH")
	vt.Values(
		"category/other-package",
		"${OTHER_VAR}",
		"invalid",
		"../../invalid/relative",
		"wip/package",
		"category",
		"&&")

	vt.Output(
		"ERROR: filename.mk:3: There is no package in \"../../invalid\".",
		"ERROR: filename.mk:4: There is no package in \"../../../../invalid/relative\".",
		"ERROR: filename.mk:5: A main pkgsrc package must not depend on a pkgsrc-wip package.",
		"ERROR: filename.mk:6: \"category\" is not a valid path to a package.",
		"WARN: filename.mk:7: The pathname \"&&\" contains the invalid characters \"&&\".",
		"ERROR: filename.mk:7: There is no package in \"../../&&\".")

	G.Wip = true

	vt.Values(
		"wip/package")

	vt.OutputEmpty()

	vt.Op(opUseMatch)

	vt.Values(
		"pattern",
		"&special&")

	vt.Output(
		"WARN: filename.mk:22: The pathname pattern \"&special&\" contains the invalid characters \"&&\".")
}

func (s *Suite) Test_VartypeCheck_Pkgrevision(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtPkgrevision)

	vt.Varname("PKGREVISION")
	vt.Values(
		"3a")

	vt.Output(
		"WARN: filename.mk:1: PKGREVISION must be a positive integer number.",
		"ERROR: filename.mk:1: PKGREVISION only makes sense directly in the package Makefile.")

	vt.File("Makefile")
	vt.Values(
		"3")

	vt.OutputEmpty()
}

func (s *Suite) Test_VartypeCheck_PrefixPathname(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtPrefixPathname)

	vt.Varname("PKGMANDIR")
	vt.Values(
		"man/man1",
		"share/locale")

	vt.Output(
		"WARN: filename.mk:1: Please use \"${PKGMANDIR}/man1\" instead of \"man/man1\".")
}

func (s *Suite) Test_VartypeCheck_PythonDependency(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtPythonDependency)

	vt.Varname("PYTHON_VERSIONED_DEPENDENCIES")
	vt.Values(
		"cairo",
		"${PYDEP}",
		"cairo,X")

	vt.Output(
		"WARN: filename.mk:2: Python dependencies should not contain variables.",
		"WARN: filename.mk:3: Invalid Python dependency \"cairo,X\".")
}

func (s *Suite) Test_VartypeCheck_RPkgName(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtRPkgName)

	vt.Varname("R_PKGNAME")
	vt.Values(
		"package",
		"${VAR}",
		"a,b,c",
		"under_score",
		"R-package")

	vt.Output(
		"WARN: filename.mk:2: The R package name should not contain variables.",
		"WARN: filename.mk:3: The R package name contains the invalid characters \",,\".",
		"WARN: filename.mk:5: The R_PKGNAME does not need the \"R-\" prefix.")

	vt.Op(opUseMatch)
	vt.Values(
		"R-package")

	vt.OutputEmpty()
}

func (s *Suite) Test_VartypeCheck_RPkgVer(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtRPkgVer)

	vt.Varname("R_PKGVER")
	vt.Values(
		"1.0",
		"1-2-3",
		"${VERSION}",
		"1-:")

	vt.Output(
		"WARN: filename.mk:4: Invalid R version number \"1-:\".")

	vt.Op(opUseMatch)
	vt.Values(
		"1-:")

	vt.OutputEmpty()
}

func (s *Suite) Test_VartypeCheck_RelativePkgPath(c *check.C) {
	t := s.Init(c)
	vt := NewVartypeCheckTester(t, BtRelativePkgPath)

	t.CreateFileLines("category/other-package/Makefile")
	t.Chdir("category/package")

	vt.Varname("DISTINFO_FILE")
	vt.Values(
		"category/other-package",
		"../../category/other-package",
		"${OTHER_VAR}",
		"invalid",
		"../../invalid/relative")

	vt.Output(
		"ERROR: filename.mk:1: Relative path \"category/other-package\" does not exist.",
		"ERROR: filename.mk:4: Relative path \"invalid\" does not exist.",
		"ERROR: filename.mk:5: Relative path \"../../invalid/relative\" does not exist.")
}

func (s *Suite) Test_VartypeCheck_Restricted(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtRestricted)

	vt.Varname("NO_BIN_ON_CDROM")
	vt.Values(
		"May only be distributed free of charge")

	vt.Output(
		"WARN: filename.mk:1: The only valid value for NO_BIN_ON_CDROM is ${RESTRICTED}.")
}

func (s *Suite) Test_VartypeCheck_SedCommands(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtSedCommands)

	vt.Varname("SUBST_SED.dummy")
	vt.Values(
		"s,@COMPILER@,gcc,g",
		"-e s,a,b, -e a,b,c,",
		"-e \"s,#,comment ,\"",
		"-e \"s,\\#,comment ,\"",
		"-E",
		"-n",
		"-e 1d",
		"1d",
		"-e",
		"-i s,from,to,",
		"-e s,$${unclosedShellVar") // Just for code coverage.

	vt.Output(
		"NOTE: filename.mk:1: Please always use \"-e\" in sed commands, even if there is only one substitution.",
		"NOTE: filename.mk:2: Each sed command should appear in an assignment of its own.",
		"WARN: filename.mk:3: The # character starts a Makefile comment.",
		"ERROR: filename.mk:3: Invalid shell words \"\\\"s,\" in sed commands.",
		"WARN: filename.mk:8: Unknown sed command \"1d\".",
		"ERROR: filename.mk:9: The -e option to sed requires an argument.",
		"WARN: filename.mk:10: Unknown sed command \"-i\".",
		"NOTE: filename.mk:10: Please always use \"-e\" in sed commands, even if there is only one substitution.",
		// TODO: duplicate warning
		"WARN: filename.mk:11: Unclosed shell variable starting at \"$${unclosedShellVar\".",
		"WARN: filename.mk:11: Unclosed shell variable starting at \"$${unclosedShellVar\".")
}

func (s *Suite) Test_VartypeCheck_SedCommands__experimental(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtSedCommands)
	G.Experimental = true

	vt.Varname("SUBST_SED.dummy")

	vt.Values(
		"-e s,???,questions,",
		"-e 's?from?to?g'",
		"-E -e 's,from,to,g'")

	vt.Output(
		"WARN: filename.mk:1: The \"?\" in the word \"s,???,questions,\" may lead to unintended file globbing.")

	vt.Values(
		"-e s,?,replacement,",
		"-e s,\\?,replacement,",
		"-e s,\\\\?,replacement,",
		"-e s,\\\\\\?,replacement,")

	vt.Output(
		"WARN: filename.mk:11: The \"?\" in the word \"s,?,replacement,\" may lead to unintended file globbing.",
		"WARN: filename.mk:13: The \"?\" in the word \"s,\\\\\\\\?,replacement,\" may lead to unintended file globbing.",
		"WARN: filename.mk:13: In a basic regular expression, a backslash followed by \"?\" is undefined.",
		"WARN: filename.mk:14: In a basic regular expression, a backslash followed by \"?\" is undefined.")

	vt.Values(
		"-e s/dir\\\\/file/other-file/")

	// No warning about backslash followed by "/" being undefined.
	vt.OutputEmpty()

	vt.Values(
		"-e 's, ,space,g'",
		"-e 's,\t,tab,g'")

	vt.OutputEmpty()
}

func (s *Suite) Test_VartypeCheck_ShellCommand(c *check.C) {
	t := s.Init(c)
	t.SetUpVartypes()
	vt := NewVartypeCheckTester(t, BtShellCommand)

	vt.Varname("INSTALL_CMD")
	vt.Values(
		"${INSTALL_DATA} -m 0644 ${WRKDIR}/source ${DESTDIR}${PREFIX}/target")

	vt.Op(opUseMatch)
	vt.Values("*")

	vt.OutputEmpty()

	vt.Varname("CC")
	vt.Op(opAssignAppend)
	vt.Values("-ggdb")

	vt.OutputEmpty()
}

func (s *Suite) Test_VartypeCheck_ShellCommands(c *check.C) {
	t := s.Init(c)
	t.SetUpVartypes()
	t.SetUpTool("echo", "ECHO", AtRunTime)
	vt := NewVartypeCheckTester(t, BtShellCommands)

	vt.Varname("GENERATE_PLIST")
	vt.Values(
		"echo bin/program",
		"echo bin/program;")

	vt.Output(
		"WARN: filename.mk:1: This shell command list should end with a semicolon.")
}

func (s *Suite) Test_VartypeCheck_Stage(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtStage)

	vt.Varname("SUBST_STAGE.dummy")
	vt.Values(
		"post-patch",
		"post-modern",
		"pre-test")

	vt.Output(
		"WARN: filename.mk:2: Invalid stage name \"post-modern\". " +
			"Use one of {pre,do,post}-{extract,patch,configure,build,test,install}.")
}

func (s *Suite) Test_VartypeCheck_Tool(c *check.C) {
	t := s.Init(c)
	vt := NewVartypeCheckTester(t, BtTool)

	t.SetUpTool("tool1", "", AtRunTime)
	t.SetUpTool("tool2", "", AtRunTime)
	t.SetUpTool("tool3", "", AtRunTime)

	vt.Varname("USE_TOOLS")
	vt.Op(opAssignAppend)
	vt.Values(
		"tool3:run",
		"tool2:unknown",
		"${t}",
		"mal:formed:tool",
		"unknown")

	vt.Output(
		"ERROR: filename.mk:2: Invalid tool dependency \"unknown\". "+
			"Use one of \"bootstrap\", \"build\", \"pkgsrc\", \"run\" or \"test\".",
		"ERROR: filename.mk:4: Invalid tool dependency \"mal:formed:tool\".",
		"ERROR: filename.mk:5: Unknown tool \"unknown\".")

	vt.Varname("USE_TOOLS.NetBSD")
	vt.Op(opAssignAppend)
	vt.Values(
		"tool3:run",
		"tool2:unknown")

	vt.Output(
		"ERROR: filename.mk:12: Invalid tool dependency \"unknown\". " +
			"Use one of \"bootstrap\", \"build\", \"pkgsrc\", \"run\" or \"test\".")

	vt.Varname("TOOLS_NOOP")
	vt.Op(opAssignAppend)
	vt.Values(
		"gmake:run")

	vt.Varname("TOOLS_NOOP")
	vt.Op(opAssign) // TODO: In a Makefile, this should be equivalent to opAssignAppend.
	vt.Values(
		"gmake:run")

	vt.Output(
		"ERROR: filename.mk:31: Unknown tool \"gmake\".")

	vt.Varname("USE_TOOLS")
	vt.Op(opUseMatch)
	vt.Values(
		"tool1",
		"tool1\\:build",
		"tool1\\:*",
		"${t}\\:build")

	vt.OutputEmpty()
}

func (s *Suite) Test_VartypeCheck_URL(c *check.C) {
	t := s.Init(c)
	vt := NewVartypeCheckTester(t, BtURL)

	vt.Varname("LATEX2HTML_ICONPATH")
	vt.Values(
		"# none",
		"${OTHER_VAR}",
		"https://www.NetBSD.org/",
		"https://www.netbsd.org/",
		"https://www.example.org",
		"ftp://example.org/pub/",
		"gopher://example.org/")

	vt.Output(
		"WARN: filename.mk:4: Please write NetBSD.org instead of www.netbsd.org.",
		"NOTE: filename.mk:5: For consistency, please add a trailing slash to \"https://www.example.org\".")

	vt.Values(
		"",
		"ftp://example.org/<",
		"gopher://example.org/<",
		"http://example.org/<",
		"https://example.org/<",
		"https://www.example.org/path with spaces",
		"httpxs://www.example.org",
		"mailto:someone@example.org",
		"string with spaces")

	vt.Output(
		"WARN: filename.mk:11: \"\" is not a valid URL.",
		"WARN: filename.mk:12: \"ftp://example.org/<\" is not a valid URL.",
		"WARN: filename.mk:13: \"gopher://example.org/<\" is not a valid URL.",
		"WARN: filename.mk:14: \"http://example.org/<\" is not a valid URL.",
		"WARN: filename.mk:15: \"https://example.org/<\" is not a valid URL.",
		"WARN: filename.mk:16: \"https://www.example.org/path with spaces\" is not a valid URL.",
		"WARN: filename.mk:17: \"httpxs://www.example.org\" is not a valid URL. Only ftp, gopher, http, and https URLs are allowed here.",
		"WARN: filename.mk:18: \"mailto:someone@example.org\" is not a valid URL.",
		"WARN: filename.mk:19: \"string with spaces\" is not a valid URL.")

	// Yes, even in 2019, some pkgsrc-wip packages really use a gopher HOMEPAGE.
	vt.Values(
		"gopher://bitreich.org/1/scm/geomyidae")
	vt.OutputEmpty()
}

func (s *Suite) Test_VartypeCheck_UserGroupName(c *check.C) {
	t := s.Init(c)
	vt := NewVartypeCheckTester(t, BtUserGroupName)

	vt.Varname("APACHE_USER")
	vt.Values(
		"user with spaces",
		"typical_username",
		"user123",
		"domain\\user",
		"${OTHER_VAR}")

	vt.Output(
		"WARN: filename.mk:1: Invalid user or group name \"user with spaces\".",
		"WARN: filename.mk:4: Invalid user or group name \"domain\\\\user\".")
}

func (s *Suite) Test_VartypeCheck_VariableName(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtVariableName)

	vt.Varname("BUILD_DEFS")
	vt.Values(
		"VARBASE",
		"VarBase",
		"PKG_OPTIONS_VAR.pkgbase",
		"${INDIRECT}")

	vt.Output(
		"WARN: filename.mk:2: \"VarBase\" is not a valid variable name.")
}

func (s *Suite) Test_VartypeCheck_VariableNamePattern(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtVariableNamePattern)

	vt.Varname("_SORTED_VARS.group")
	vt.Values(
		"VARBASE",
		"VarBase",
		"PKG_OPTIONS_VAR.pkgbase",
		"${INDIRECT}",
		"*_DIRS",
		"VAR.*",
		"***")

	vt.Output(
		"WARN: filename.mk:2: \"VarBase\" is not a valid variable name pattern.")
}

func (s *Suite) Test_VartypeCheck_Version(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtVersion)

	vt.Varname("PERL5_REQD")
	vt.Op(opAssignAppend)
	vt.Values(
		"0",
		"1.2.3.4.5.6",
		"4.1nb17",
		"4.1-SNAPSHOT",
		"4pre7",
		"${VER}")
	vt.Output(
		"WARN: filename.mk:4: Invalid version number \"4.1-SNAPSHOT\".")

	vt.Op(opUseMatch)
	vt.Values(
		"a*",
		"1.2/456",
		"4*",
		"?.??",
		"1.[234]*",
		"1.[2-7].*",
		"[0-9]*")
	vt.Output(
		"WARN: filename.mk:11: Invalid version number pattern \"a*\".",
		"WARN: filename.mk:12: Invalid version number pattern \"1.2/456\".",
		"WARN: filename.mk:13: Please use \"4.*\" instead of \"4*\" as the version pattern.",
		"WARN: filename.mk:15: Please use \"1.[234].*\" instead of \"1.[234]*\" as the version pattern.")
}

func (s *Suite) Test_VartypeCheck_WrapperReorder(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtWrapperReorder)

	vt.Varname("WRAPPER_REORDER_CMDS")
	vt.Op(opAssignAppend)
	vt.Values(
		"reorder:l:first:second",
		"reorder:l:first",
		"omit:first")
	vt.Output(
		"WARN: filename.mk:2: Unknown wrapper reorder command \"reorder:l:first\".",
		"WARN: filename.mk:3: Unknown wrapper reorder command \"omit:first\".")
}

func (s *Suite) Test_VartypeCheck_WrapperTransform(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtWrapperTransform)

	vt.Varname("WRAPPER_TRANSFORM_CMDS")
	vt.Op(opAssignAppend)
	vt.Values(
		"rm:-O3",
		"opt:-option",
		"rename:src:dst",
		"rm-optarg:-option",
		"rmdir:/usr/include",
		"rpath:/usr/lib:/usr/pkg/lib",
		"rpath:/usr/lib",
		"unknown",
		"-e 's,-Wall,-Wall -Wextra,'")
	vt.Output(
		"WARN: filename.mk:7: Unknown wrapper transform command \"rpath:/usr/lib\".",
		"WARN: filename.mk:8: Unknown wrapper transform command \"unknown\".")
}

func (s *Suite) Test_VartypeCheck_WrksrcSubdirectory(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtWrksrcSubdirectory)

	vt.Varname("BUILD_DIRS")
	vt.Op(opAssignAppend)
	vt.Values(
		"${WRKSRC}",
		"${WRKSRC}/",
		"${WRKSRC}/.",
		"${WRKSRC}/subdir",
		"${CONFIGURE_DIRS}",
		"${WRKSRC}/directory with spaces", // This is a list of 3 directories.
		"directory with spaces",           // This is a list of 3 directories.
		"../other",
		"${WRKDIR}/sub",
		"${SRCDIR}/sub")
	vt.Output(
		"NOTE: filename.mk:1: You can use \".\" instead of \"${WRKSRC}\".",
		"NOTE: filename.mk:2: You can use \".\" instead of \"${WRKSRC}/\".",
		"NOTE: filename.mk:3: You can use \".\" instead of \"${WRKSRC}/.\".",
		"NOTE: filename.mk:4: You can use \"subdir\" instead of \"${WRKSRC}/subdir\".",
		"NOTE: filename.mk:6: You can use \"directory\" instead of \"${WRKSRC}/directory\".",
		"WARN: filename.mk:8: \"../other\" is not a valid subdirectory of ${WRKSRC}.",
		"WARN: filename.mk:9: \"${WRKDIR}/sub\" is not a valid subdirectory of ${WRKSRC}.",
		"WARN: filename.mk:10: \"${SRCDIR}/sub\" is not a valid subdirectory of ${WRKSRC}.")
}

func (s *Suite) Test_VartypeCheck_Yes(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtYes)

	vt.Varname("APACHE_MODULE")
	vt.Values(
		"yes",
		"no",
		"${YESVAR}")

	vt.Output(
		"WARN: filename.mk:2: APACHE_MODULE should be set to YES or yes.",
		"WARN: filename.mk:3: APACHE_MODULE should be set to YES or yes.")

	vt.Varname("BUILD_USES_MSGFMT")
	vt.Op(opUseMatch)
	vt.Values(
		"yes",
		"no",
		"${YESVAR}")

	vt.Output(
		"WARN: filename.mk:11: BUILD_USES_MSGFMT should only be used in a \".if defined(...)\" condition.",
		"WARN: filename.mk:12: BUILD_USES_MSGFMT should only be used in a \".if defined(...)\" condition.",
		"WARN: filename.mk:13: BUILD_USES_MSGFMT should only be used in a \".if defined(...)\" condition.")
}

func (s *Suite) Test_VartypeCheck_YesNo(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtYesNo)

	vt.Varname("PKG_DEVELOPER")
	vt.Values(
		"yes",
		"no",
		"ja",
		"${YESVAR}")

	vt.Output(
		"WARN: filename.mk:3: PKG_DEVELOPER should be set to YES, yes, NO, or no.",
		"WARN: filename.mk:4: PKG_DEVELOPER should be set to YES, yes, NO, or no.")
}

func (s *Suite) Test_VartypeCheck_YesNoIndirectly(c *check.C) {
	vt := NewVartypeCheckTester(s.Init(c), BtYesNoIndirectly)

	vt.Varname("IS_BUILTIN.pkgbase")
	vt.Values(
		"yes",
		"no",
		"ja",
		"${YESVAR}")

	vt.Output(
		"WARN: filename.mk:3: IS_BUILTIN.pkgbase should be set to YES, yes, NO, or no.")
}

// VartypeCheckTester helps to test the many different checks in VartypeCheck.
// It keeps track of the current variable, operator, filename, line number,
// so that the test can focus on the interesting details.
type VartypeCheckTester struct {
	tester    *Tester
	basicType *BasicType
	filename  string
	lineno    int
	varname   string
	op        MkOperator
}

// NewVartypeCheckTester starts the test with a filename of "filename", at line 1,
// with "=" as the operator. The variable has to be initialized explicitly.
func NewVartypeCheckTester(t *Tester, basicType *BasicType) *VartypeCheckTester {

	// This is necessary to know whether the variable name is a list type
	// since in such a case each value is split into the list elements.
	if G.Pkgsrc.VariableType(nil, "USE_CWRAPPERS") == nil {
		t.SetUpVartypes()
	}

	return &VartypeCheckTester{t, basicType, "filename.mk", 1, "", opAssign}
}

func (vt *VartypeCheckTester) Varname(varname string) {
	vartype := G.Pkgsrc.VariableType(nil, varname)
	assertNotNil(vartype)
	assert(vartype.basicType == vt.basicType)

	vt.varname = varname
	vt.nextSection()
}

func (vt *VartypeCheckTester) File(filename string) {
	vt.filename = filename
	vt.lineno = 1
}

// Op sets the operator for the following tests.
// The line number is advanced to the next number ending in 1, e.g. 11, 21, 31.
func (vt *VartypeCheckTester) Op(op MkOperator) {
	vt.op = op
	vt.nextSection()
}

// Values feeds each of the values to the actual check.
// Each value is interpreted as if it were written verbatim into a Makefile line.
// That is, # starts a comment.
//
// For the opUseMatch operator, all colons and closing braces must be escaped.
func (vt *VartypeCheckTester) Values(values ...string) {

	toText := func(value string) string {
		op := vt.op
		opStr := op.String()
		varname := vt.varname

		if op == opUseMatch {
			return sprintf(".if ${%s:M%s} == \"\"", varname, value)
		}

		if !contains(opStr, "=") {
			panic("Invalid operator: " + opStr)
		}

		space := condStr(hasSuffix(varname, "+") && opStr == "=", " ", "")
		return varname + space + opStr + value
	}

	test := func(mklines *MkLines, mkline *MkLine, value string) {
		varname := vt.varname
		comment := ""
		if mkline.IsVarassign() {
			mkline.Tokenize(value, true) // Produce some warnings as side-effects.
			comment = mkline.VarassignComment()
		}

		effectiveValue := value
		if mkline.IsVarassign() {
			effectiveValue = mkline.Value()
		}

		vartype := G.Pkgsrc.VariableType(nil, varname)

		// See MkLineChecker.checkVartype.
		var lineValues []string
		if vartype == nil || !vartype.List() {
			lineValues = []string{effectiveValue}
		} else {
			lineValues = mkline.ValueFields(effectiveValue)
		}

		for _, lineValue := range lineValues {
			valueNovar := mkline.WithoutMakeVariables(lineValue)
			vc := VartypeCheck{mklines, mkline, varname, vt.op, lineValue, valueNovar, comment, false}
			vt.basicType.checker(&vc)
		}
	}

	for _, value := range values {
		text := toText(value)

		line := vt.tester.NewLine(vt.filename, vt.lineno, text)
		mklines := NewMkLines(NewLines(vt.filename, []*Line{line}))
		vt.lineno++

		mklines.ForEach(func(mkline *MkLine) { test(mklines, mkline, value) })
	}
}

// Output checks that the output from all previous steps is
// the same as the expectedLines.
func (vt *VartypeCheckTester) Output(expectedLines ...string) {
	vt.tester.CheckOutputLines(expectedLines...)
	vt.nextSection()
}

func (vt *VartypeCheckTester) OutputEmpty() {
	vt.tester.CheckOutputEmpty()
	vt.nextSection()
}

func (vt *VartypeCheckTester) nextSection() {
	if vt.lineno%10 != 1 {
		vt.lineno += 9 - (vt.lineno+8)%10
	}
}
