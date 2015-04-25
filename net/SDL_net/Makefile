# $NetBSD: Makefile,v 1.24 2015/04/25 14:23:42 tnn Exp $

DISTNAME=	SDL_net-1.2.8
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.libsdl.org/projects/SDL_net/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/SDL_net/
COMMENT=	Small sample cross-platform networking library for SDL
LICENSE=	zlib

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-gui
PKGCONFIG_OVERRIDE=	SDL_net.pc.in

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
