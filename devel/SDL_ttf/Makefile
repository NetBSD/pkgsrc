# $NetBSD: Makefile,v 1.2 2001/06/16 11:50:47 wiz Exp $
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
USE_LIBTOOL=	YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

CONFIGURE_ENV+=	CFLAGS="-DFREETYPE_HDR_DIRECTORY"

.include "../../mk/bsd.pkg.mk"
