# $NetBSD: Makefile,v 1.9 2003/07/25 17:13:06 jmmv Exp $
#

DISTNAME=	SDL_net-1.2.5
CATEGORIES=	net
MASTER_SITES=	http://www.libsdl.org/projects/SDL_net/release/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/SDL_net/
COMMENT=	Small sample cross-platform networking library for SDL

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=            YES
LTCONFIG_OVERRIDE=      ${WRKSRC}/ltconfig

CONFIGURE_ARGS+=	--disable-gui

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
