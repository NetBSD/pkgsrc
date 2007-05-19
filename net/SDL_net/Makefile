# $NetBSD: Makefile,v 1.19 2007/05/19 22:12:53 heinz Exp $

DISTNAME=	SDL_net-1.2.6
CATEGORIES=	net
MASTER_SITES=	http://www.libsdl.org/projects/SDL_net/release/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/SDL_net/
COMMENT=	Small sample cross-platform networking library for SDL

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-gui

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
