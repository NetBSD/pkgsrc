# $NetBSD: Makefile,v 1.13 2023/12/11 10:10:16 wiz Exp $

DISTNAME=	zxing-cpp-2.2.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=nu-book/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/nu-book/zxing-cpp/
COMMENT=	1D/2D barcode reader/writer library in C++
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DBUILD_EXAMPLES=OFF
# Blackbox tests target pulls fmtlib with git command.
CMAKE_ARGS+=	-DBUILD_BLACKBOX_TESTS=OFF

USE_CXX_FEATURES+=	c++17

PKGCONFIG_OVERRIDE+=	zxing.pc.in

# Install private header file to fix build failure of misc/libreoffice-7.3.4.2.
post-install:
	${INSTALL_DATA} ${WRKSRC}/core/src/BitArray.h \
		${DESTDIR}${PREFIX}/include/ZXing

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
