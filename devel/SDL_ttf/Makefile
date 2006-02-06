# $NetBSD: Makefile,v 1.23 2006/02/06 23:16:07 rillig Exp $

DISTNAME=	SDL_ttf-2.0.7
PKGREVISION=	4
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
