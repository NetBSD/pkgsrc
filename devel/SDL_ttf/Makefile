# $NetBSD: Makefile,v 1.4 2001/06/26 09:54:07 zuntum Exp $
#

DISTNAME=	SDL_ttf-1.2.2
CATEGORIES=	devel
MASTER_SITES=	http://www.libsdl.org/projects/SDL_ttf/src/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.libsdl.org/projects/SDL_ttf/
COMMENT=	use TrueType fonts in your SDL applications

USE_BUILDLINK_ONLY=	YES
USE_CONFIG_WRAPPER=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

CONFIGURE_ENV+=		CFLAGS="-DFREETYPE_HDR_DIRECTORY"

.include "../../devel/SDL/buildlink.mk"
.include "../../graphics/freetype-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
