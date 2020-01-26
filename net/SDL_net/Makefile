# $NetBSD: Makefile,v 1.25 2020/01/26 17:31:48 rillig Exp $

DISTNAME=	SDL_net-1.2.8
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.libsdl.org/projects/SDL_net/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.libsdl.org/projects/SDL_net/
COMMENT=	Small sample cross-platform networking library for SDL
LICENSE=	zlib

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-gui
PKGCONFIG_OVERRIDE=	SDL_net.pc.in

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
