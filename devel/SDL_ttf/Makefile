# $NetBSD: Makefile,v 1.1.1.1 2001/05/14 12:46:28 zuntum Exp $
#

DISTNAME=	SDL_ttf-1.2.2
CATEGORIES=	devel
MASTER_SITES=	http://www.libsdl.org/projects/SDL_ttf/src/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.libsdl.org/projects/SDL_ttf/
COMMENT=	use TrueType fonts in your SDL applications

DEPENDS+=	freetype-lib-*:../../graphics/freetype-lib
DEPENDS+=	SDL>=1.0.1:../../devel/SDL

GNU_CONFIGURE=	YES

CONFIGURE_ENV+=	CFLAGS="-DFREETYPE_HDR_DIRECTORY"

.include "../../mk/bsd.pkg.mk"
