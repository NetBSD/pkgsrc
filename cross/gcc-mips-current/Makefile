# $NetBSD: Makefile,v 1.16 2019/08/11 13:18:17 wiz Exp $

GCC_DIST_VERSION=	4.9.2
GCC_PKGNAME=		gcc-mips-${GCC_DIST_VERSION}

DISTNAME=	gcc-${GCC_DIST_VERSION}
PKGNAME=	${GCC_PKGNAME}
PKGREVISION=	5
CATEGORIES=	cross lang
MASTER_SITES=	${MASTER_SITE_GNU:=gcc/gcc-${GCC_DIST_VERSION}/}
EXTRACT_SUFX=	.tar.bz2
PLIST_SUBST+=	GCC_DIST_VERSION=${GCC_DIST_VERSION:Q}

MAINTAINER=	martin@NetBSD.org
HOMEPAGE=	http://gcc.gnu.org/
COMMENT=	The GNU Compiler Collection (GCC) - 4.9 for mips (especially playstation2)
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

DISTFILES=		${DEFAULT_DISTFILES}
EXTRACT_ONLY=		${DEFAULT_DISTFILES}

NOT_FOR_PLATFORM=	Interix-*-*

USE_LANGUAGES=		c c++03
USE_TOOLS+=		gmake makeinfo sed:run perl
GNU_CONFIGURE=		yes
## Build outside ${WRKSRC}
OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	../${DISTNAME}/configure
INFO_FILES=		yes

UNLIMIT_RESOURCES+=	datasize
UNLIMIT_RESOURCES+=	stacksize

SUBST_CLASSES+=		vars
SUBST_MESSAGE.vars=	Setting target machine name path in ${SUBST_FILES.vars}
SUBST_STAGE.vars=	pre-configure
SUBST_FILES.vars=	gcc/Makefile.in
SUBST_VARS.vars=	GCC_TARGET_MACHINE

.include "../../mk/bsd.prefs.mk"

LANGS=			c c++

# In some cases LINKER_RPATH_FLAG needs a trailing space.
LINKER_RPATH_FLAG:=	${LINKER_RPATH_FLAG:S/-rpath/& /}

## The Library rpath to use in end programs.
LDFLAGS_FOR_TARGET=	${LDFLAGS:M${COMPILER_RPATH_FLAG}*:N*/usr/lib*}

# GCC does not understand this option; remove it, or stage build will fail
BUILDLINK_TRANSFORM+=	rm:-stdlib=libc++

## For target librarys and libjava programs.
CONFIGURE_ENV+=		LDFLAGS_FOR_TARGET=${LDFLAGS_FOR_TARGET:Q}

# Make sure the target binutils are both in PATH and supplied explicitly
# to configure
.for prg in as ar ld nm strip objcopy objdump ranlib readelf
# CONFIGURE_ENV+=		${prg:tu}_FOR_TARGET=${PREFIX}/bin/${TARGET}-${prg}
CONFIGURE_ARGS+=	--with-${prg}=${PREFIX}/bin/${TARGET}-${prg}
.endfor

CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--disable-libquadmath
CONFIGURE_ARGS+=	--disable-libquadmath-support
CONFIGURE_ARGS+=	--disable-libssp
CONFIGURE_ARGS+=	--disable-libgomp
CONFIGURE_ARGS+=	--disable-libstdc++-v3
CONFIGURE_ARGS+=	--disable-libatomic
CONFIGURE_ARGS+=	--disable-libgcc
CONFIGURE_ARGS+=	--enable-languages=${LANGS:Q}
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-long-long
CONFIGURE_ARGS+=	--with-local-prefix=${PREFIX}
CONFIGURE_ARGS+=	--enable-threads=posix
CONFIGURE_ARGS+=	--with-boot-ldflags=${BOOT_LDFLAGS:M*:Q}

MAKE_ENV.NetBSD+=		ac_cv_func_clock_gettime=yes
CONFIGURE_ARGS.DragonFly+=	--disable-bootstrap

TARGET=			mipsel--netbsd
CONFIGURE_ARGS+=	--target=${TARGET}

# ${WRKSRC}/fixincludes/ looks for sed and compiles the path to sed into
# a binary so we need to make sure we give it the installed sed and not
# the tool wrapped one.
MAKE_ENV+=		ac_cv_path_SED=${TOOLS_SED}
MAKE_ENV+=		lt_cv_path_SED=${TOOLS_SED}

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

CONFIGURE_ARGS+=	--with-gmp=${BUILDLINK_PREFIX.gmp}
CONFIGURE_ARGS+=	--with-mpc=${BUILDLINK_PREFIX.mpcomplex}
CONFIGURE_ARGS+=	--with-mpfr=${BUILDLINK_PREFIX.mpfr}
.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"

.include "../../cross/binutils-mips-current/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
