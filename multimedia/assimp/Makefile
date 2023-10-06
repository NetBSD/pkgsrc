# $NetBSD: Makefile,v 1.11 2023/10/06 16:52:21 adam Exp $

DISTNAME=	assimp-5.3.1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=assimp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	http://www.assimp.org/
COMMENT=	Library to import various 3D model formats
LICENSE=	modified-bsd

USE_CXX_FEATURES+=	c++17
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE=	assimp.pc.in

CMAKE_CONFIGURE_ARGS+=	-DASSIMP_BUILD_ZLIB=OFF

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
