# $NetBSD: Makefile,v 1.18 2025/06/08 07:44:54 wiz Exp $

DISTNAME=	assimp-6.0.1
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
CMAKE_CONFIGURE_ARGS+=	-DASSIMP_WARNINGS_AS_ERRORS=OFF

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
