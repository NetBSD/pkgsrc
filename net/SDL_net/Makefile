# $NetBSD: Makefile,v 1.2 2002/02/11 20:57:36 zuntum Exp $
#

DISTNAME=	SDL_net-1.2.0
CATEGORIES=	net
MASTER_SITES=	http://www.libsdl.org/projects/SDL_net/release/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.libsdl.org/projects/SDL_net/
COMMENT=	small sample cross-platform networking library for SDL

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=            YES
LTCONFIG_OVERRIDE=      ${WRKSRC}/ltconfig

.include "../../devel/SDL/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
