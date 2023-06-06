# $NetBSD: Makefile,v 1.10 2023/06/06 08:02:12 wiz Exp $

DISTNAME=	nvidia-texture-tools-2.1.0
PKGREVISION=	7
CATEGORIES=	graphics
# NOTE: abandoned upstream, archived.
MASTER_SITES=	${MASTER_SITE_GITHUB:=castano/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/castano/nvidia-texture-tools/wiki
COMMENT=	Texture processing tools with support for Direct3D 10 and 11 formats
LICENSE=	mit

HAS_CONFIGURE=	yes
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DNVTT_SHARED=ON

.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
