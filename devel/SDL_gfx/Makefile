# $NetBSD: Makefile,v 1.37 2012/01/28 13:58:25 wiz Exp $

DISTNAME=	SDL_gfx-2.0.23
CATEGORIES=	devel
MASTER_SITES=	http://www.ferzkopp.net/Software/SDL_gfx-2.0/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ferzkopp.net/Software/SDL_gfx-2.0/
COMMENT=	Basic drawing routines for SDL
LICENSE=	zlib

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	SDL_gfx.pc.in

.if (${MACHINE_ARCH} != "i386")
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
