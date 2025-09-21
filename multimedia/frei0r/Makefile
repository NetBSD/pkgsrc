# $NetBSD: Makefile,v 1.13 2025/09/21 15:11:41 wiz Exp $

DISTNAME=	frei0r-2.3.3
PKGREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=dyne/}
GITHUB_PROJECT=	frei0r
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://frei0r.dyne.org/
COMMENT=	Collection of free and portable video plugins
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"
# Not in pkgsrc yet
CMAKE_CONFIGURE_ARGS+=	-DWITHOUT_GAVL=ON
# Not compatible with latest version
#CMAKE_CONFIGURE_ARGS+=	-DWITHOUT_OPENCV=ON

.include "../../devel/cmake/build.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/opencv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
