# $NetBSD: Makefile,v 1.211 2013/11/01 14:02:37 jperkin Exp $

.include "license.mk"
.include "Makefile.common"

PKGREVISION=	2
COMMENT=	Practical Extraction and Report Language

CONFLICTS=	perl-base-[0-9]* perl-thread-[0-9]*			\
		p5-CGI-2.66{,nb*} p5-CGI-2.75{,nb*} p5-CGI-2.75.[0-2]	\
		p5-Tie-File-0.96{,nb*}					\
		p5-Memoize-1.01{,nb*}					\
		p5-I18N-LangTags<0.35					\
		p5-Locale-Maketext<1.22					\
		p5-Locale-Maketext-Simple<0.21				\
		p5-Digest<=1.16						\
		p5-Digest-MD5<=2.39					\
		p5-Digest-SHA<2.48

SUPERSEDES+=	p5-Tie-File<0.97
SUPERSEDES+=	p5-Memoize<1.02
SUPERSEDES+=	p5-I18N-LangTags<=0.35
SUPERSEDES+=	p5-Locale-Maketext<=1.15

.include "../../mk/bsd.prefs.mk"

# Determine the Perl API version from the patchlevel.h file from the
# source distribution.
#
PERL5_API_VERS=		${PERL5_API_VERS_cmd:sh}
PERL5_API_VERS_cmd=	\
	if ${TEST} -f ${WRKSRC}/patchlevel.h; then			\
		${AWK} '/\#define[ 	]*PERL_API_REVISION/ { R = $$3 }\
			/\#define[ 	]*PERL_API_VERSION/ { r = "."$$3 } \
			/\#define[ 	]*PERL_API_SUBVERSION/ { s = "."$$3 } \
			END { printf "%s%s%s\n", R, r, s }'		\
			${WRKSRC}/patchlevel.h;				\
	else								\
		${ECHO} "unknown";					\
	fi

.include "dirs.mk"

.include "../../mk/compiler.mk"

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-sde
MAKE_ENV+=		LC_ALL="C"

TEST_TARGET=		test

# Policy.sh generation
# (see comments in files/Policy.sh)
SUBST_CLASSES+=	policysh
SUBST_STAGE.policysh=	pre-configure
SUBST_FILES.policysh=	Policy.sh
SUBST_VARS.policysh+=	MACHINE_ARCH
SUBST_VARS.policysh+=	LOWER_OPSYS
SUBST_VARS.policysh+=	OBJECT_FMT
SUBST_VARS.policysh+=	CC
SUBST_VARS.policysh+=	CFLAGS
SUBST_VARS.policysh+=	LDFLAGS
SUBST_VARS.policysh+=	COMPILER_RPATH_FLAG
SUBST_VARS.policysh+=	PERL5_PREFIX
SUBST_VARS.policysh+=	PERL5_SITEPREFIX
SUBST_VARS.policysh+=	PERL5_VENDORPREFIX
SUBST_VARS.policysh+=	PERL5_PERLBASE
SUBST_VARS.policysh+=	PERL5_SITEBASE
SUBST_VARS.policysh+=	PERL5_SITEBIN
SUBST_VARS.policysh+=	PERL5_VENDORBASE
SUBST_VARS.policysh+=	PERL5_PRIVLIB
SUBST_VARS.policysh+=	PERL5_SITELIB
SUBST_VARS.policysh+=	PERL5_VENDORLIB
SUBST_VARS.policysh+=	PKGMANDIR
SUBST_VARS.policysh+=	LOCALBASE
SUBST_VARS.policysh+=	PTHREAD_LDFLAGS

# Avoid the ${TOOLS_BIN} path getting written to installed files.
SUBST_CLASSES+=		toolsbin
SUBST_STAGE.toolsbin=	pre-configure
SUBST_FILES.toolsbin=	Configure
SUBST_VARS.toolsbin=	TOOLS_RM

.if ${OPSYS} == "Darwin" || ${OPSYS} == "Cygwin"
#
# The Perl build attempts to work around case-insensitivity problems on
# HFS filesystems by using GNUmakefiles, so we need to use GNU make.
#
USE_TOOLS+=	gmake
MAKE_FILE=	GNUmakefile
.endif

#
# For the moment disable the building of a shared libperl.dylib on Darwin
# => 9.0 as it breaks the build.  This should just be considered a temporary
# work around until the actual problem can be fixed as this worked for
# Darwin < 9.0.
#
.if empty(MACHINE_PLATFORM:MDarwin-9.*-*)
CONFIGURE_ARGS+=	-Duseshrplib
.endif

# Perl embeds the full paths to the following tools in several installed
# files, so make sure the paths to the ones in ${TOOLS_DIR} aren't used.
#
USE_TOOLS+=		hostname ln rm sed test
SUBST_VARS.policysh+=	TOOLS_HOSTNAME_CMD
SUBST_VARS.policysh+=	TOOLS_LN
TOOLS_ALIASES.sed+=	${TOOLS_SED:T}
SUBST_VARS.policysh+=	TOOLS_SED
SUBST_VARS.policysh+=	TOOLS_SH
SUBST_VARS.policysh+=	TOOLS_TEST
SUBST_VARS.policysh+=	FALSE

# Nail down the needed libraries for each platform here to avoid hidden
# dependencies.  If this isn't defined, then use the perl defaults for the
# particular operating system.
#
LIBSWANTED.Cygwin=	m crypt dl
LIBSWANTED.Darwin=	m c
LIBSWANTED.DragonFly=	m crypt
LIBSWANTED.FreeBSD=	m crypt
LIBSWANTED.GNUkFreeBSD=	m crypt dl nsl
LIBSWANTED.HPUX=	cl pthread $$libswanted # see Perl's README.hpux
LIBSWANTED.IRIX=	m crypt
LIBSWANTED.Interix=	m dl
LIBSWANTED.Linux=	m crypt dl nsl
LIBSWANTED.MirBSD=	m crypt
LIBSWANTED.NetBSD=	m crypt
LIBSWANTED.OpenBSD=	m crypt
LIBSWANTED.SunOS=	m crypt dl socket nsl
LIBSWANTED.AIX=		m crypt dl socket nsl bind c
LIBSWANTED=		${LIBSWANTED.${OPSYS}}
SUBST_VARS.policysh+=	LIBSWANTED

# Nail down the directories in which the system libraries may be found.
# If this isn't defined, then use the perl defaults for the particular
# operating system.
#
SYSLIBPATH.Cygwin=	/usr/lib
SYSLIBPATH.Darwin=	/usr/lib
SYSLIBPATH.DragonFly=	/usr/lib
SYSLIBPATH.FreeBSD=	/usr/lib
SYSLIBPATH.Haiku=	/boot/common/lib
SYSLIBPATH.Interix=	/usr/lib
SYSLIBPATH.MirBSD=	/usr/lib
SYSLIBPATH.NetBSD=	/usr/lib
SYSLIBPATH.OpenBSD=	/usr/lib
SYSLIBPATH.SunOS=	/usr/lib
SYSLIBPATH.AIX=		/usr/lib
SYSLIBPATH=		${SYSLIBPATH.${OPSYS}}
SUBST_VARS.policysh+=	SYSLIBPATH

.include "../../mk/dlopen.buildlink3.mk"
.include "options.mk"

.if !empty(MACHINE_PLATFORM:MMirBSD*)
SUBST_CLASSES+=			mirbsd-paths
SUBST_STAGE.mirbsd-paths=	pre-configure
SUBST_FILES.mirbsd-paths=	hints/mirbsd.sh
SUBST_SED.mirbsd-paths=		-e 's,/usr/mpkg,${PREFIX},g'
SUBST_MESSAGE.mirbsd-paths=	Do not use non-pkgsrc paths on MirBSD.
.endif

# Replace our perl as the interpreter
REPLACE_PERL+=		cpan/Config-Perl-V/V.pm
REPLACE_PERL+=		cpan/Getopt-Long/lib/Getopt/Long.pm
REPLACE_PERL+=		dist/bignum/lib/Math/BigFloat/Trace.pm
REPLACE_PERL+=		dist/bignum/lib/Math/BigInt/Trace.pm
REPLACE_PERL+=		dist/ExtUtils-ParseXS/lib/ExtUtils/xsubpp
REPLACE_PERL+=		ext/File-DosGlob/lib/File/DosGlob.pm
REPLACE_PERL+=		lib/File/DosGlob.pm
REPLACE_PERL+=		lib/unicore/mktables
REPLACE_PERL+=		lib/version.pm

# And replace a perl interpreter during the pre-install stage
# I think this may be a bootstrap script, so can't use REPLACE_PERL
# because that is acted upon already in the pre-configure stage
SUBST_CLASSES+=		miniperl
SUBST_STAGE.miniperl=	pre-install
SUBST_FILES.miniperl=	lib/ExtUtils/xsubpp
SUBST_SED.miniperl=	-e "1s:\#!./miniperl:\#!${PERL5}:"

.if ${PKGSRC_COMPILER} == "xlc"
SUBST_CLASSES+=		cpprun
SUBST_STAGE.cpprun=	pre-install
SUBST_FILES.cpprun=	lib/Config_heavy.pl
.  if !empty(PKG_OPTIONS:Mthreads)
SUBST_SED.cpprun=	-e "s/cpprun=''/cpprun='cc_r -E'/"
.  else
SUBST_SED.cpprun=	-e "s/cpprun=''/cpprun='cc -E'/"
.  endif
.endif

# Some platforms may want the directory mode not to be 0755.  This
# is, unfortunately, hardcoded in quite a few places in Perl, so
# let's substitute what pkgsrc says instead.
#
SUBST_CLASSES+=		dirmode
SUBST_STAGE.dirmode=	post-patch
SUBST_FILES.dirmode=	installhtml install_lib.pl	\
			dist/ExtUtils-Install/lib/ExtUtils/Install.pm
SUBST_SED.dirmode=	-e "s/755/${PKGDIRMODE}/g;/umask(/d"

post-extract:
		cp ${FILESDIR}/Policy.sh ${WRKSRC}/Policy.sh
		cp ${FILESDIR}/cpan-DB_File-hints-netbsd.pl \
			${WRKSRC}/cpan/DB_File/hints/netbsd.pl

pre-configure:
	cd ${WRKSRC} && find `pwd` -name "*.orig" -type f -exec ${RM} -f {} \;

post-build:
	${SED}	-e "s,@PERL5@,"${PERL5:Q}",g"				\
		-e "s,@SH@,"${SH:Q}",g"					\
		-e "s,@PKGMANDIR@,"${PKGMANDIR}",g"			\
		${FILESDIR}/perllink.in > ${WRKDIR}/perllink.sh

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
PERL5_PACKLIST_DIR_cmd=	. ${WRKSRC}/config.sh;	echo $$installarchlib
PERL5_PACKLIST_DIR=	${PERL5_PACKLIST_DIR_cmd:sh}
PERL5_PACKLIST=		.packlist
PERL5_PACKLIST_DESTDIR=	no
FILES_SUBST+=		PERL5_COMMENT=\#
FILES_SUBST+=		PERL5_PACKLIST=

post-install: perl5-post-install

perl5-post-install:
	${RUN}if ${TEST} -x ${DESTDIR}${PREFIX}/bin/a2p; then		\
		strip ${DESTDIR}${PREFIX}/bin/a2p;			\
	fi
	${INSTALL_SCRIPT} ${WRKDIR}/perllink.sh 			\
		${DESTDIR}${PERL5_PERLBASE}/bin/perllink
	${INSTALL_MAN} ${FILESDIR}/perllink.1				\
		${DESTDIR}${PERL5_PERLBASE}/${PKGMANDIR}/man1/perllink.1
	${RM} -f ${DESTDIR}${PREFIX}/bin/perllink			\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/perllink.1
	${LN} -s ${PERL5_PERLBASE}/bin/perllink 			\
		${DESTDIR}${PREFIX}/bin/perllink
	${LN} -s ${PERL5_PERLBASE}/${PKGMANDIR}/man1/perllink.1		\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/perllink.1
.if ${OPSYS} == "Haiku"
	${CHMOD} a+x ${DESTDIR}${PREFIX}/bin/perl
.endif

.include "packlist.mk"
.include "../../mk/bsd.pkg.mk"
