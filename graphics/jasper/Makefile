# $NetBSD: Makefile,v 1.71 2023/11/06 13:44:30 wiz Exp $

DISTNAME=	jasper-4.1.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=jasper-software/}
GITHUB_RELEASE=	version-${PKGVERSION_NOREV}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://jasper-software.github.io/jasper/
COMMENT=	Software-based reference implementation of the JPEG-2000 codec
LICENSE=	modified-bsd

USE_LANGUAGES=	c99 c++
USE_TOOLS+=	bash:test
CMAKE_ARGS+=	-DALLOW_IN_SOURCE_BUILD=ON
CMAKE_ARGS+=	-DJAS_ENABLE_DOC=OFF

PKGCONFIG_OVERRIDE=	build/jasper.pc.in
REPLACE_BASH=		test/bin/*
TEST_ENV+=		DYLD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/src/libjasper
#TEST_ENV+=		DYLD_LIBRARY_PATH=${DESTDIR}${PREFIX}/lib
TEST_TARGET=		test

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
