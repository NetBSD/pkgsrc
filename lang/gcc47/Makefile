# $NetBSD: Makefile,v 1.7 2012/09/13 07:19:11 sbd Exp $

GCC_PKGNAME=		gcc47
.include		"version.mk"

DISTNAME=		gcc-${GCC_DIST_VERSION}
PKGNAME=		${GCC_PKGNAME}-${GCC_DIST_VERSION}
PKGREVISION=		4
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/gcc-${GCC_DIST_VERSION}/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		sbd@NetBSD.org
HOMEPAGE=		http://gcc.gnu.org/
COMMENT=		The GNU Compiler Collection (GCC) - 4.7 Release Series
LICENSE=		gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

DISTFILES=		${DEFAULT_DISTFILES}
EXTRACT_ONLY=		${DEFAULT_DISTFILES}

NOT_FOR_PLATFORM=	Interix-*-*

USE_TOOLS+=		gmake makeinfo sed:run

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
## Build outside ${WRKSRC}
OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	../${DISTNAME}/configure
GCC_SUBPREFIX=		${GCC_PKGNAME}
GCC_PREFIX=		${PREFIX}/${GCC_SUBPREFIX}
GNU_CONFIGURE_PREFIX=	${GCC_PREFIX}
INFO_FILES=		yes

UNLIMIT_RESOURCES+=	datasize
UNLIMIT_RESOURCES+=	stacksize

.include "../../mk/bsd.prefs.mk"

LANGS=			c

## The Library rpath to use in end programs.
LDFLAGS_FOR_TARGET=	${LDFLAGS:M${COMPILER_RPATH_FLAG}*:N*/usr/lib*}

## The "-static-libstdc++ -static-libgcc" flags are normally added to the
## boot-ldflags by configure but because we are supply the boot-ldflags
## we mash supply them.
BOOT_LDFLAGS=		-static-libstdc++ -static-libgcc ${LDFLAGS_FOR_TARGET}

## For target librarys and libjava programs.
CONFIGURE_ENV+=		LDFLAGS_FOR_TARGET=${LDFLAGS_FOR_TARGET:Q}

CONFIGURE_ARGS+=	--enable-languages=${LANGS:Q}
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-long-long
CONFIGURE_ARGS+=	--with-local-prefix=${GCC_PREFIX:Q}
CONFIGURE_ARGS+=	--enable-libssp
CONFIGURE_ARGS+=	--enable-threads=posix
CONFIGURE_ARGS+=	--with-boot-ldflags=${BOOT_LDFLAGS:Q}
.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-gnu-ld --with-ld=/usr/bin/ld
CONFIGURE_ARGS+=	--with-gnu-as --with-as=/usr/bin/as
MAKE_ENV+=		ac_cv_func_clock_gettime=yes
.endif
.if ${OPSYS} == "DragonFly"
CONFIGURE_ARGS+=	--disable-bootstrap
.endif

.include "options.mk"

# ${WRKSRC}/fixincludes/ looks for sed and compiles the path to sed into
# a binary so we need to make sure we give it the installed sed and not
# the tool wrapped one.
MAKE_ENV+=		ac_cv_path_SED=${TOOLS_SED}
MAKE_ENV+=		lt_cv_path_SED=${TOOLS_SED}

# Determine whether to use binutils
.if ${OPSYS} == "SunOS"
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
CONFIGURE_ARGS+=	--with-gnu-as --with-as=${PREFIX}/gnu/bin/as
.  endif
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
