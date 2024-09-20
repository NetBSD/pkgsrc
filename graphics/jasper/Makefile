# $NetBSD: Makefile,v 1.81 2024/09/20 07:04:56 tnn Exp $

DISTNAME=	jasper-4.2.4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=jasper-software/}
GITHUB_RELEASE=	version-${PKGVERSION_NOREV}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://jasper-software.github.io/jasper/
COMMENT=	Software-based reference implementation of the JPEG-2000 codec
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++
FORCE_C_STD=	c99
USE_TOOLS+=	bash:test
CMAKE_CONFIGURE_ARGS+=	-DALLOW_IN_SOURCE_BUILD=ON
CMAKE_CONFIGURE_ARGS+=	-DJAS_ENABLE_DOC=OFF

PKGCONFIG_OVERRIDE=	build/jasper.pc.in
REPLACE_BASH=		test/bin/*
TEST_ENV+=		DYLD_LIBRARY_PATH=${WRKSRC}/${CMAKE_BUILD_DIR}/src/libjasper
TEST_TARGET=		test

CFLAGS+=	-D_POSIX_C_SOURCE=200112L	# nanosleep(2)
CFLAGS.Darwin+=	-D_DARWIN_C_SOURCE=1

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
