# $NetBSD: Makefile,v 1.4 2002/08/27 19:01:41 jlam Exp $
#

DISTNAME=	SDL_net-1.2.3
CATEGORIES=	net
MASTER_SITES=	http://www.libsdl.org/projects/SDL_net/release/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.libsdl.org/projects/SDL_net/
COMMENT=	small sample cross-platform networking library for SDL

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=            YES
LTCONFIG_OVERRIDE=      ${WRKSRC}/ltconfig

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
