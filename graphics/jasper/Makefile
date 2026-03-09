# $NetBSD: Makefile,v 1.89 2026/03/09 16:37:33 wiz Exp $

DISTNAME=	jasper-4.2.9
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=jasper-software/}
GITHUB_RELEASE=	version-${PKGVERSION_NOREV}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://jasper-software.github.io/jasper/
COMMENT=	Software-based reference implementation of the JPEG-2000 codec
LICENSE=	modified-bsd

USE_LANGUAGES=		c c++
USE_TOOLS+=		bash:test
CMAKE_CONFIGURE_ARGS+=	-DALLOW_IN_SOURCE_BUILD=ON
CMAKE_CONFIGURE_ARGS+=	-DJAS_ENABLE_DOC=OFF

PKGCONFIG_OVERRIDE=	build/pkgconfig/jasper.pc.in
REPLACE_BASH=		test/bin/*
TEST_ENV+=		DYLD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/src/libjasper
TEST_ENV+=		LD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/src/libjasper
TEST_TARGET=		test

CFLAGS.Darwin+=	-D_DARWIN_C_SOURCE=1

.include "../../mk/bsd.prefs.mk"

.if ${USE_CROSS_COMPILE:tl} == "yes"
CMAKE_CONFIGURE_ARGS+=	-DJAS_CROSSCOMPILING:BOOL=YES
CMAKE_CONFIGURE_ARGS+=	-DJAS_STDC_VERSION:STRING=199901L	# C99
.endif

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
