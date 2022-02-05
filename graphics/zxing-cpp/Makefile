# $NetBSD: Makefile,v 1.1 2022/02/05 04:34:17 ryoon Exp $

GITHUB_PROJECT=	zxing-cpp
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	zxing-cpp-1.2.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=nu-book/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/nu-book/zxing-cpp/
COMMENT=	1D/2D barcode reader/writer library in C++
LICENSE=	apache-2.0

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c++11

CMAKE_ARGS+=	-DBUILD_EXAMPLES=OFF

PKGCONFIG_OVERRIDE+=	zxing.pc.in

.include "../../mk/bsd.pkg.mk"
