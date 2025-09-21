# $NetBSD: Makefile,v 1.19 2025/09/21 15:11:39 wiz Exp $

DISTNAME=	nvidia-texture-tools-2.1.0
PKGREVISION=	14
CATEGORIES=	graphics
# NOTE: abandoned upstream, archived.
MASTER_SITES=	${MASTER_SITE_GITHUB:=castano/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/castano/nvidia-texture-tools/wiki
COMMENT=	Texture processing tools with support for Direct3D 10 and 11 formats
LICENSE=	mit

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DNVTT_SHARED=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../devel/cmake/build.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
