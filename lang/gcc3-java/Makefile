# $NetBSD: Makefile,v 1.2 2003/07/06 12:31:59 grant Exp $
#

DISTNAME=		gcc-3.3
PKGNAME=		gcc3-java-3.3
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/gcc-3.3/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/gcc/gcc.html
COMMENT=		GNU Compiler Collection

NOT_FOR_PLATFORM=	Darwin-*-*
DEPENDS+=	gcc3-c++-3.3:../../lang/gcc3-c++

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
USE_GMAKE=		YES

HAS_CONFIGURE=		YES

CONFIGURE_ARGS+=	--infodir=${PREFIX}/info
CONFIGURE_ARGS+=	--prefix=${GCC_PREFIX}
CONFIGURE_ARGS+=	--enable-languages="java"
CONFIGURE_ARGS+=	--with-system-zlib
UNLIMIT_RESOURCES=	datasize

TEXINFO_REQD=		4.2

INFO_FILES=		gcj.info

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD" && exists(/usr/include/pthread.h)
GCC_PLATFORM=	${MACHINE_GNU_ARCH}--netbsdelf2.0
PTHREAD_OPTS+=		require native
.include "../../mk/pthread.buildlink2.mk"
CPPFLAGS+=	-I${BUILDLINK_DIR}/include
CFLAGS+=	-I${BUILDLINK_DIR}/include
.else
GCC_PLATFORM=	${MACHINE_GNU_PLATFORM}
.endif
CONFIGURE_ARGS+=	--host=${GCC_PLATFORM}
PLIST_SUBST+=	GCC_PLATFORM=${GCC_PLATFORM}

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--enable-shared
.else
.  if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--enable-shared
.  else
CONFIGURE_ARGS+=	--disable-shared
.  endif
.  if ${CC:M*gcc*} == ""
ALL_TARGET=		bootstrap
.  endif
.endif

GCC_PREFIX=	${PREFIX}/gcc3
GCC_VERSION=	${PKGVERSION:C|nb*||}
GCC_ARCHDIR=	${GCC_PREFIX}/lib/gcc-lib/${GCC_PLATFORM}/${GCC_VERSION}

pre-configure:
	${MKDIR} ${BUILD_DIRS}
	cd ${WRKSRC} && contrib/gcc_update --touch

do-build:
	${LN} -sf ${GCC_PREFIX}/bin/gcc ${WRKSRC}/gcc/xgcc
	(cd ${WRKSRC}/gcc && ${GMAKE} java)
	(${ULIMIT_CMD_datasize}; cd ${WRKSRC} && ${GMAKE} all-target-libjava)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gcc/jc1 ${GCC_ARCHDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gcc/gcj ${GCC_ARCHDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gcc/jvgenmain ${GCC_ARCHDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gcc/gcjh ${GCC_ARCHDIR}
	(cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		java.install-common java.install-info)
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		install-target-libjava)

.include "../../lang/gcc3-c/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"

# On NetBSD, the gcc-2.95.3 for:
#
#     alpha
#
# have an optimization bug when compiling with -O2 that is tickled by:
#
#   java/parse.o
#
# note that we don't override CFLAGS and CPPFLAGS because we want the
# crosscompiled compiler to be build with optimization.  This only
# disables optimization for the stage 1 build.
#
.if ${OPSYS} == "NetBSD"
.  if ${MACHINE_ARCH} == "alpha"
CONFIG_CFLAGS=	${CFLAGS:C/-O[0-9]*//g}
CONFIG_CPPFLAGS=	${CPPFLAGS:C/-O[0-9]*//g}
CONFIGURE_ENV+=	CFLAGS="${CONFIG_CFLAGS}" CPPFLAGS="${CONFIG_CPPFLAGS}"
.  endif
.endif
