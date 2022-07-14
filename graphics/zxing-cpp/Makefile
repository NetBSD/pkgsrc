# $NetBSD: Makefile,v 1.4 2022/07/14 13:23:34 wiz Exp $

DISTNAME=	zxing-cpp-1.4.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=nu-book/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/nu-book/zxing-cpp/
COMMENT=	1D/2D barcode reader/writer library in C++
LICENSE=	apache-2.0

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c++11

CMAKE_ARGS+=	-DBUILD_EXAMPLES=OFF
# Blackbox tests target pulls fmtlib with git command.
CMAKE_ARGS+=	-DBUILD_BLACKBOX_TESTS=OFF

PKGCONFIG_OVERRIDE+=	zxing.pc.in

.include "../../mk/bsd.pkg.mk"
