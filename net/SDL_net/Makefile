# $NetBSD: Makefile,v 1.27 2025/02/09 00:28:20 rillig Exp $

DISTNAME=	SDL_net-1.2.8
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.libsdl.org/projects/SDL_net/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.libsdl.org/projects/SDL_net/
COMMENT=	Small sample cross-platform networking library for SDL
LICENSE=	zlib

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
GNU_CONFIGURE_ICONV=	no
CONFIGURE_ARGS+=	--disable-gui
PKGCONFIG_OVERRIDE=	SDL_net.pc.in

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
