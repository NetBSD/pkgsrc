# $NetBSD: Makefile,v 1.5 2024/08/25 06:18:49 wiz Exp $

DISTNAME=	box2d-2.4.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=erincatto/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/erincatto/box2d/
COMMENT=	2D physics engine for games
LICENSE=	mit

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DBOX2D_BUILD_UNIT_TESTS=OFF
CMAKE_CONFIGURE_ARGS+=	-DBOX2D_BUILD_TESTBED=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON

.include "../../devel/cmake/build.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
