# $NetBSD: Makefile,v 1.12 2024/02/28 21:35:40 charlotte Exp $

DISTNAME=	assimp-5.3.1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=assimp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
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
