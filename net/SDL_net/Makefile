# $NetBSD: Makefile,v 1.16 2006/02/05 23:10:22 joerg Exp $
#

DISTNAME=	SDL_net-1.2.5
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	http://www.libsdl.org/projects/SDL_net/release/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/SDL_net/
COMMENT=	Small sample cross-platform networking library for SDL

GNU_CONFIGURE=		YES
USE_LIBTOOL=            YES

CONFIGURE_ARGS+=	--disable-gui

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
