# $NetBSD: Makefile,v 1.11 2004/03/06 17:28:59 xtraeme Exp $
#

DISTNAME=	SDL_net-1.2.5
PKGREVISION=	1
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
