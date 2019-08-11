# $NetBSD: Makefile,v 1.7 2019/08/11 13:22:04 wiz Exp $

PKGNAME=	libaom-1.0.0
PKGREVISION=	2
DISTNAME=	aom-d14c5bb4f336ef1842046089849dee4a301fbbf0
CATEGORIES=	multimedia
#MASTER_SITES=	-https://aomedia.googlesource.com/aom/+archive/d14c5bb4f336ef1842046089849dee4a301fbbf0.tar.gz
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://aomedia.googlesource.com/aom/+archive/
COMMENT=	Library for using AV1, video coding format
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}
USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	perl

SUBST_CLASSES+=		version
SUBST_FILES.version=	build/cmake/version.cmake
SUBST_STAGE.version=	pre-configure
SUBST_VARS.version=	PKGVERSION_NOREV

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	../
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON
CMAKE_ARGS+=	-DCMAKE_COLOR_MAKEFILE:BOOL=ON
CMAKE_ARGS+=	-DENABLE_DECODE_PERF_TESTS:BOOL=OFF
CMAKE_ARGS+=	-DENABLE_EXAMPLES:BOOL=ON
CMAKE_ARGS+=	-DENABLE_DOCS:BOOL=OFF
CMAKE_ARGS+=	-DENABLE_GOMA:BOOL=OFF
CMAKE_ARGS+=	-DENABLE_NASM:BOOL=ON
CMAKE_ARGS+=	-DENABLE_TESTS:BOOL=OFF
CMAKE_ARGS+=	-DENABLE_TOOLS:BOOL=OFF
CMAKE_ARGS+=	-DENABLE_WERROR:BOOL=OFF

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-*-*arm*) \
  || !empty(MACHINE_PLATFORM:MNetBSD-*-aarch64)
CMAKE_ARGS+=	-DCONFIG_RUNTIME_CPU_DETECT=0
.endif

.if ${MACHINE_ARCH} == x86_64 || ${MACHINE_ARCH} == i386
BUILD_DEPENDS+=	nasm>=2.13:../../devel/nasm
.endif

.include "../../mk/bsd.pkg.mk"
