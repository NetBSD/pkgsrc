# $NetBSD: Makefile,v 1.15 2004/04/27 15:13:30 adam Exp $
#

DISTNAME=	SDL_ttf-2.0.6
CATEGORIES=	devel
MASTER_SITES=	http://www.libsdl.org/projects/SDL_ttf/release/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/SDL_ttf/
COMMENT=	Use TrueType fonts in your SDL applications

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
