# $NetBSD: Makefile,v 1.6 2026/07/13 04:36:01 wiz Exp $

DISTNAME=	SDL3_image-3.4.0
PKGREVISION=	1
CATEGORIES=	graphics devel
MASTER_SITES=	http://www.libsdl.org/projects/SDL_image/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libsdl-org/SDL_image
COMMENT=	Load images as SDL surfaces
LICENSE=	zlib

USE_TOOLS+=	pkg-config

.include "../../devel/cmake/build.mk"
.include "../../devel/SDL3/buildlink3.mk"
.include "../../graphics/libavif/buildlink3.mk"
.include "../../graphics/libjxl/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
