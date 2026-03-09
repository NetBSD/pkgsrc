# $NetBSD: Makefile,v 1.1 2026/03/09 11:38:16 adam Exp $

DISTNAME=	SDL3_ttf-3.2.2
CATEGORIES=	fonts devel
MASTER_SITES=	https://www.libsdl.org/projects/SDL_ttf/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.libsdl.org/projects/SDL_ttf/
COMMENT=	Use TrueType fonts in your SDL2 applications
LICENSE=	zlib

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

.include "../../devel/SDL3/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
