# $NetBSD: Makefile,v 1.13 2005/03/27 15:43:38 wiz Exp $
#

DISTNAME=	SDL_net-1.2.5
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://www.libsdl.org/projects/SDL_net/release/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/SDL_net/
COMMENT=	Small sample cross-platform networking library for SDL

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=            YES

CONFIGURE_ARGS+=	--disable-gui

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
