# $NetBSD: Makefile,v 1.272 2021/08/20 22:06:23 kim Exp $

PKGREVISION= 3
.include "license.mk"
.include "Makefile.common"

COMMENT=	Practical Extraction and Report Language

CONFLICTS+=	perl-base-[0-9]* perl-thread-[0-9]*

# when updating perl, you can remove packages that are included
# in perl core, see
# corelist -diff ${PREV_PKGVERSION} ${PKGVERSION}

SUPERSEDES+=	p5-Tie-File<=0.99
SUPERSEDES+=	p5-Time-HiRes-[0-9]*
SUPERSEDES+=	p5-DB_File-[0-9]*
SUPERSEDES+=	p5-Memoize<=1.03
SUPERSEDES+=	p5-I18N-LangTags<=0.39
SUPERSEDES+=	p5-Locale-Maketext<=1.23
SUPERSEDES+=	p5-experimental<=0.007

# XXX: requires that gcc use an external perl to avoid circular dependencies
USE_GCC_RUNTIME=	yes
USE_LANGUAGES=		c c99

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
CONFIGURE_ARGS+=	-Dldflags=${LDFLAGS:Q}
MAKE_ENV+=		LC_ALL="C"
LDFLAGS.QNX+=		-lm

.if ${OPSYS} == "SunOS"
USE_TOOLS+=	bash
CONFIG_SHELL=	${TOOLS_PATH.bash}
.endif

TEST_TARGET=		test

# Policy.sh generation
# (see comments in files/Policy.sh)
SUBST_CLASSES+=		policysh
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

SUBST_CLASSES+=		pwd
SUBST_STAGE.pwd=	pre-configure
SUBST_FILES.pwd=	dist/PathTools/Cwd.pm
SUBST_SED.pwd+=		-e "s,/bin/pwd,${TOOLS_PLATFORM.pwd},g"

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
TOOLS_ALIASES.sed=	${TOOLS_SED:T}
SUBST_VARS.policysh+=	TOOLS_SED
SUBST_VARS.policysh+=	TOOLS_SH
SUBST_VARS.policysh+=	TOOLS_TEST
SUBST_VARS.policysh+=	FALSE

# Nail down the needed libraries for each platform here to avoid hidden
# dependencies.  If this isn't defined, then use the perl defaults for the
# particular operating system.
#
LIBSWANTED.Bitrig=	m crypt
LIBSWANTED.Cygwin=	m crypt dl
LIBSWANTED.Darwin=	m c
LIBSWANTED.DragonFly=	m crypt
LIBSWANTED.FreeBSD=	m crypt
LIBSWANTED.GNUkFreeBSD=	m crypt dl nsl
LIBSWANTED.Haiku=	network
LIBSWANTED.HPUX=	cl pthread $$libswanted # see Perl's README.hpux
LIBSWANTED.IRIX=	m crypt
LIBSWANTED.Interix=	m dl
LIBSWANTED.Linux=	m crypt dl nsl
LIBSWANTED.Minix=	m crypt c
LIBSWANTED.MirBSD=	m crypt
LIBSWANTED.NetBSD=	m crypt
LIBSWANTED.OpenBSD=	m crypt
LIBSWANTED.SunOS=	m crypt dl socket nsl
LIBSWANTED.AIX=		m crypt dl socket nsl bind c
LIBSWANTED.SCO_SV=	m crypt socket
LIBSWANTED=		${LIBSWANTED.${OPSYS}}
SUBST_VARS.policysh+=	LIBSWANTED

# Nail down the directories in which the system libraries may be found.
# If this isn't defined, then use the perl defaults for the particular
# operating system.
#
SYSLIBPATH.Bitrig=	/usr/lib
SYSLIBPATH.Cygwin=	/usr/lib
SYSLIBPATH.Darwin=	/usr/lib
SYSLIBPATH.DragonFly=	/usr/lib
SYSLIBPATH.FreeBSD=	/usr/lib
SYSLIBPATH.Interix=	/usr/lib
SYSLIBPATH.Minix=	/usr/lib
SYSLIBPATH.MirBSD=	/usr/lib
SYSLIBPATH.NetBSD=	/usr/lib
SYSLIBPATH.OpenBSD=	/usr/lib
SYSLIBPATH.SunOS=	/usr/lib
SYSLIBPATH.AIX=		/usr/lib
SYSLIBPATH.SCO_SV=	/usr/lib
SYSLIBPATH=		${SYSLIBPATH.${OPSYS}:U${COMPILER_LIB_DIRS}}
SUBST_VARS.policysh+=	SYSLIBPATH

.include "../../mk/dlopen.buildlink3.mk"
.include "options.mk"

.if ${MACHINE_PLATFORM} == "MirBSD"
SUBST_CLASSES+=			mirbsd-paths
SUBST_STAGE.mirbsd-paths=	pre-configure
SUBST_FILES.mirbsd-paths=	hints/mirbsd.sh
SUBST_SED.mirbsd-paths=		-e 's,/usr/mpkg,${PREFIX},g'
SUBST_MESSAGE.mirbsd-paths=	Do not use non-pkgsrc paths on MirBSD.
.endif

# Replace our perl as the interpreter
REPLACE_PERL+=		cpan/Config-Perl-V/V.pm
REPLACE_PERL+=		cpan/Getopt-Long/lib/Getopt/Long.pm
REPLACE_PERL+=		cpan/version/lib/version.pm
REPLACE_PERL+=		dist/ExtUtils-ParseXS/lib/ExtUtils/xsubpp
REPLACE_PERL+=		ext/ExtUtils-Miniperl/lib/ExtUtils/Miniperl.pm
REPLACE_PERL+=		ext/File-DosGlob/lib/File/DosGlob.pm
REPLACE_PERL+=		lib/unicore/mktables

.if ${PKGSRC_COMPILER:Mxlc}
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
SUBST_STAGE.dirmode=	pre-configure
SUBST_FILES.dirmode=	install_lib.pl
SUBST_SED.dirmode=	-e "s/755/${PKGDIRMODE}/g;/umask(/d"

post-extract:
	${CP} ${FILESDIR}/Policy.sh ${WRKSRC}/Policy.sh

pre-configure:
	${FIND} ${WRKSRC} -name "*.orig" -type f -exec rm -f {} \;

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

.PHONY: perl5-post-install
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
