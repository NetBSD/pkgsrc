# $NetBSD: Makefile,v 1.3 2001/06/25 22:47:18 zuntum Exp $
#

DISTNAME=	SDL_ttf-1.2.2
CATEGORIES=	devel
MASTER_SITES=	http://www.libsdl.org/projects/SDL_ttf/src/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.libsdl.org/projects/SDL_ttf/
COMMENT=	use TrueType fonts in your SDL applications

DEPENDS+=	SDL>=1.0.1:../../devel/SDL

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

CONFIGURE_ENV+=	CFLAGS="-DFREETYPE_HDR_DIRECTORY"

.include "../../graphics/freetype-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
