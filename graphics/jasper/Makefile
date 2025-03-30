# $NetBSD: Makefile,v 1.83 2025/03/30 07:50:23 wiz Exp $

DISTNAME=	jasper-4.2.4
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=jasper-software/}
GITHUB_RELEASE=	version-${PKGVERSION_NOREV}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://jasper-software.github.io/jasper/
COMMENT=	Software-based reference implementation of the JPEG-2000 codec
LICENSE=	modified-bsd

USE_LANGUAGES=		c c++
FORCE_C_STD=		c99
USE_TOOLS+=		bash:test
CMAKE_CONFIGURE_ARGS+=	-DALLOW_IN_SOURCE_BUILD=ON
CMAKE_CONFIGURE_ARGS+=	-DJAS_ENABLE_DOC=OFF

PKGCONFIG_OVERRIDE=	build/pkgconfig/jasper.pc.in
REPLACE_BASH=		test/bin/*
TEST_ENV+=		DYLD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/src/libjasper
TEST_TARGET=		test

CFLAGS+=	-D_POSIX_C_SOURCE=200112L	# nanosleep(2)
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
