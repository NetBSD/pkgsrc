# $NetBSD: Makefile,v 1.20 2005/03/27 15:43:33 wiz Exp $

DISTNAME=	SDL_gfx-2.0.13
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.ferzkopp.net/~aschiffler/Software/SDL_gfx-2.0/

MAINTAINER=	ben@NetBSD.org
HOMEPAGE=	http://www.ferzkopp.net/~aschiffler/Software/SDL_gfx-2.0/
COMMENT=	Basic drawing routines for SDL

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES

.if (${MACHINE_ARCH} != "i386")
CONFIGURE_ARGS+=	--disable-mmx
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/SDL_gfx/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/SDL_gfx/Screenshots
	${INSTALL_DATA} ${WRKSRC}/Docs/*.* ${PREFIX}/share/doc/SDL_gfx/
	${INSTALL_DATA} ${WRKSRC}/Docs/Screenshots/* \
		${PREFIX}/share/doc/SDL_gfx/Screenshots

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
