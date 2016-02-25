# $NetBSD: Makefile,v 1.10 2016/02/25 14:42:56 jperkin Exp $

GCC_PKGNAME=	gcc49
.include	"version.mk"

DISTNAME=	gcc-${GCC49_DIST_VERSION}
PKGNAME=	${GCC_PKGNAME}-${GCC49_DIST_VERSION}

## When bumping the PKGREVISION of this package the PKGREVISION of
## lang/gcc49-libs needs to be bump to be at least 1 more than the
## PKGREVISION of this package!
PKGREVISION=	1

CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=gcc/gcc-${GCC49_DIST_VERSION}/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gcc.gnu.org/
COMMENT=	The GNU Compiler Collection (GCC) - 4.9 Release Series
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

DISTFILES=		${DEFAULT_DISTFILES}
EXTRACT_ONLY=		${DEFAULT_DISTFILES}

NOT_FOR_PLATFORM=	Interix-*-*

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake makeinfo sed:run

GNU_CONFIGURE=		yes
## Build outside ${WRKSRC}
OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	../${DISTNAME}/configure
GCC_SUBPREFIX=		${GCC_PKGNAME}
GCC_PREFIX=		${PREFIX}/${GCC_SUBPREFIX}
GCC_TARGET_MACHINE?=	${MACHINE_GNU_PLATFORM}
GNU_CONFIGURE_PREFIX=	${GCC_PREFIX}
INFO_FILES=		yes

UNLIMIT_RESOURCES+=	datasize
UNLIMIT_RESOURCES+=	stacksize

SUBST_CLASSES+=		vars
SUBST_STAGE.vars=	pre-configure
SUBST_FILES.vars=	gcc/Makefile.in
SUBST_VARS.vars=	GCC_TARGET_MACHINE

.include "../../mk/bsd.prefs.mk"

LANGS=			c

# In some cases LINKER_RPATH_FLAG needs a trailing space.
LINKER_RPATH_FLAG:=	${LINKER_RPATH_FLAG:S/-rpath/& /}

## The Library rpath to use in end programs.
LDFLAGS_FOR_TARGET=	${LDFLAGS:M${COMPILER_RPATH_FLAG}*:N*/usr/lib*}

# The "-static-libstdc++ -static-libgcc" flags are normally added to the
# boot-ldflags by configure but because we are supply the boot-ldflags
# we mash supply them.
BOOT_LDFLAGS=		-static-libstdc++ -static-libgcc ${LDFLAGS_FOR_TARGET}
# Needed on Darwin when LDFLAGS point to a SDK
BOOT_LDFLAGS+=		${LDFLAGS:M-Wl,-syslibroot*}

# Ignore missing rpaths in "fake" library.
CHECK_SHLIBS_SKIP+=	${GCC_PKGNAME}/lib*/libgcj_bc.so*

## For target librarys and libjava programs.
CONFIGURE_ENV+=		LDFLAGS_FOR_TARGET=${LDFLAGS_FOR_TARGET:Q}

CONFIGURE_ARGS+=	--enable-languages=${LANGS:Q}
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-long-long
CONFIGURE_ARGS+=	--with-local-prefix=${GCC_PREFIX:Q}
CONFIGURE_ARGS+=	--enable-libssp
CONFIGURE_ARGS+=	--enable-threads=posix
CONFIGURE_ARGS+=	--with-boot-ldflags=${BOOT_LDFLAGS:Q}

CONFIGURE_ARGS.NetBSD+=	--with-gnu-ld --with-ld=/usr/bin/ld
CONFIGURE_ARGS.NetBSD+=	--with-gnu-as --with-as=/usr/bin/as
MAKE_ENV.NetBSD+=	ac_cv_func_clock_gettime=yes
MAKE_ENV.NetBSD+=	ac_cv_func_gethostbyname_r=no

CONFIGURE_ARGS.DragonFly+=	--disable-bootstrap

# See ${WRKSRC}/libgcc/config/t-slibgcc-darwin: It uses strip(1) to
# create a stub library, not just to remove symbols, so we must not
# let strip(1) be a no-op regardless of ${INSTALL_UNSTRIPPED} or the
# build fails for missing files.
CONFIGURE_ARGS.Darwin+=	STRIP_FOR_TARGET=${TOOLS_PLATFORM.strip}

.if !empty(MACHINE_PLATFORM:MDarwin-[0-8].*-*)
CONFIGURE_ARGS+=       --with-dwarf2
CONFIGURE_ARGS+=       --disable-libitm
.endif

.if !empty(MACHINE_PLATFORM:MDarwin-[0-8].*-powerpc)
CONFIGURE_ARGS+=       --disable-multilib
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-*-i386) || !empty(MACHINE_PLATFORM:MLinux-*-i386)
CONFIGURE_ARGS+=	--with-arch=i486 --with-tune=i486
.endif

# Disable fixincludes on SmartOS, header changes result in broken includes
# being generated, see https://github.com/joyent/pkgsrc/issues/270
.if ${OS_VARIANT} == "SmartOS"
SUBST_CLASSES+=		fixinc
SUBST_STAGE.fixinc=	pre-configure
SUBST_FILES.fixinc=	gcc/Makefile.in
SUBST_SED.fixinc=	-e "s,\./fixinc.sh,-c true,"
.endif

.include "options.mk"

# ${WRKSRC}/fixincludes/ looks for sed and compiles the path to sed into
# a binary so we need to make sure we give it the installed sed and not
# the tool wrapped one.
MAKE_ENV+=		ac_cv_path_SED=${TOOLS_SED}
MAKE_ENV+=		lt_cv_path_SED=${TOOLS_SED}

.if !empty(MACHINE_PLATFORM:MSunOS-5.1[123456789]-*)
# Causes multilib build problems with specific compiler combinations
MAKE_ENV+=		gcc_cv_ld_as_needed=no
# Determine whether to use binutils
.  if exists(/usr/sfw/bin/gobjdump)
CONFIGURE_ENV+=		OBJDUMP=/usr/sfw/bin/gobjdump
.  endif
.  if exists(/usr/bin/ld)
CONFIGURE_ARGS+=	--without-gnu-ld --with-ld=/usr/bin/ld
.  else
CONFIGURE_ARGS+=	--without-gnu-ld --with-ld=/usr/ccs/bin/ld
.  endif
.  if exists(/usr/sfw/bin/gas)
CONFIGURE_ARGS+=	--with-gnu-as --with-as=/usr/sfw/bin/gas
.  elif exists(/usr/ccs/bin/as)
CONFIGURE_ARGS+=	--without-gnu-as --with-as=/usr/ccs/bin/as
.  else
BUILDLINK_DEPMETHOD.binutils=	full
.    include "../../devel/binutils/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gnu-as --with-as=${PREFIX}/bin/gas
.  endif
.elif !empty(MACHINE_PLATFORM:MSunOS-5.10-*)
.  if exists(/usr/sfw/bin/gobjdump)
CONFIGURE_ENV+=		OBJDUMP=/usr/sfw/bin/gobjdump
.  endif
BUILDLINK_API_DEPENDS.binutils+=	binutils>=2.23
BUILDLINK_DEPMETHOD.binutils=	full
.  include "../../devel/binutils/buildlink3.mk"
CONFIGURE_ENV+=		OBJCOPY=${PREFIX}/bin/gobjcopy
CONFIGURE_ARGS+=	--with-gnu-as --with-as=${PREFIX}/bin/gas
CONFIGURE_ARGS+=	--without-gnu-ld --with-ld=/usr/ccs/bin/ld
.endif

pre-configure:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

TEST_TARGET=	-k check || ${TRUE}
pre-test:
	${RUN} 							\
	if runtest --version >/dev/null 2>/dev/null ; then	\
		: ;						\
	else							\
	  ${ECHO} "ERROR: Please install devel/dejagnu in order to run the test suite." ; \
	  exit 1 ;						\
	fi
post-test:
	${RUN} cd ${WRKSRC} && cd ${OBJDIR} &&		\
	${SHELL} ${WRKSRC}/contrib/test_summary >${WRKDIR}/test_summary.log
	@${INFO_MSG} "Test summary are available in ${WRKDIR}/test_summary.log"

post-install:
	${TEST} -f ${DESTDIR}${GCC_PREFIX}/bin/cc || \
		( cd ${DESTDIR}${GCC_PREFIX}/bin ; ${LN} -f gcc cc )
.if !empty(PKG_OPTIONS:Mgcc-java)
	${RM} -f ${DESTDIR}${JAVA_HOME}/bin/javadoc
	${RM} -f ${DESTDIR}${JAVA_HOME}/jre/lib/${JAVA_ARCH}/libjawt.so
.endif
.if !empty(MACHINE_PLATFORM:MSunOS-*-*86*) && ${OS_VERSION} != "5.11"
	${SH} files/values.c ${DESTDIR}${GCC_PREFIX}/bin/gcc -m32 || ${TRUE}
	${SH} files/values.c ${DESTDIR}${GCC_PREFIX}/bin/gcc -m64 || ${TRUE}
.endif

GENERATE_PLIST+= \
	cd ${DESTDIR}${PREFIX} && 					\
	${FIND} ${GCC_SUBPREFIX} \( -type f -o -type l \) -print | ${SORT} ;

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
