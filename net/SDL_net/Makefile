# $NetBSD: Makefile,v 1.12 2004/10/03 00:17:48 tv Exp $
#

DISTNAME=	SDL_net-1.2.5
PKGREVISION=	2
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
