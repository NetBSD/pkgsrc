# $NetBSD: Makefile,v 1.42 2019/10/06 13:02:08 nia Exp $

DISTNAME=	SDL_gfx-2.0.26
CATEGORIES=	devel
MASTER_SITES=	http://www.ferzkopp.net/Software/SDL_gfx-2.0/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ferzkopp.net/wordpress/2016/01/02/sdl_gfx-sdl2_gfx/
COMMENT=	Basic drawing routines for SDL
LICENSE=	zlib

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	SDL_gfx.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} != "i386"
CONFIGURE_ARGS+=	--disable-mmx
.endif

INSTALLATION_DIRS+=	share/doc/SDL_gfx
INSTALLATION_DIRS+=	share/doc/SDL_gfx/Screenshots

post-install:
	${INSTALL_DATA} ${WRKSRC}/Docs/*.* \
		${DESTDIR}${PREFIX}/share/doc/SDL_gfx/
	${INSTALL_DATA} ${WRKSRC}/Docs/Screenshots/* \
		${DESTDIR}${PREFIX}/share/doc/SDL_gfx/Screenshots

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
