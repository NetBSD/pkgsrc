# $NetBSD: Makefile,v 1.24 2006/06/12 16:24:44 wiz Exp $

DISTNAME=	SDL_ttf-2.0.8
CATEGORIES=	devel
MASTER_SITES=	http://www.libsdl.org/projects/SDL_ttf/release/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/SDL_ttf/
COMMENT=	Use TrueType fonts in your SDL applications

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
