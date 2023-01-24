# $NetBSD: Makefile,v 1.8 2023/01/24 18:36:28 wiz Exp $

DISTNAME=	zxing-cpp-1.4.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=nu-book/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/nu-book/zxing-cpp/
COMMENT=	1D/2D barcode reader/writer library in C++
LICENSE=	apache-2.0

USE_LANGUAGES=	c++11

CMAKE_ARGS+=	-DBUILD_EXAMPLES=OFF
# Blackbox tests target pulls fmtlib with git command.
CMAKE_ARGS+=	-DBUILD_BLACKBOX_TESTS=OFF

PKGCONFIG_OVERRIDE+=	zxing.pc.in

# Install private header file to fix build failure of misc/libreoffice-7.3.4.2.
post-install:
	${INSTALL_DATA} ${WRKSRC}/core/src/BitArray.h \
		${DESTDIR}${PREFIX}/include/ZXing

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
