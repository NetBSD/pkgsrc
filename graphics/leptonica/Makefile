# $NetBSD: Makefile,v 1.28 2024/01/31 22:45:33 wiz Exp $

DISTNAME=	leptonica-1.84.1
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=danbloomberg/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.leptonica.org/
COMMENT=	Software for image processing and image analysis applications
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
CMAKE_ARGS+=	-DBUILD_PROG=ON
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON

USE_CC_FEATURES=	c17

# Silence console messages
CPPFLAGS+=		-DNO_CONSOLE_IO=1

# Pass a SunOS that the build relies on
CPPFLAGS.SunOS+=	-D__SOLARIS__=1

.include "../../devel/cmake/build.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
