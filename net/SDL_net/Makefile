# $NetBSD: Makefile,v 1.1.1.1 2001/07/10 09:05:28 zuntum Exp $
#

DISTNAME=	SDL_net-1.2.0
CATEGORIES=	net
MASTER_SITES=	http://www.libsdl.org/projects/SDL_net/release/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.libsdl.org/projects/SDL_net/
COMMENT=	small sample cross-platform networking library

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=            YES
LTCONFIG_OVERRIDE=      ${WRKSRC}/ltconfig

.include "../../devel/SDL/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
