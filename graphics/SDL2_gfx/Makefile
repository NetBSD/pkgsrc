# $NetBSD: Makefile,v 1.7 2022/08/11 05:08:39 gutteridge Exp $

DISTNAME=	SDL2_gfx-1.0.4
PKGREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	https://www.ferzkopp.net/Software/SDL2_gfx/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ferzkopp.net/wordpress/2016/01/02/sdl_gfx-sdl2_gfx/
COMMENT=	Graphics drawing primitives library for SDL2
LICENSE=	zlib

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--disable-sdltest

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} != "i386" && ${MACHINE_ARCH} != "x86_64"
CONFIGURE_ARGS+=	--disable-mmx
.endif

PKGCONFIG_OVERRIDE+=	SDL2_gfx.pc.in

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
