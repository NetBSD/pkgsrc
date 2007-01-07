# $NetBSD: Makefile,v 1.28 2007/01/07 12:06:35 adam Exp $

DISTNAME=	SDL_gfx-2.0.15
CATEGORIES=	devel
MASTER_SITES=	http://www.ferzkopp.net/Software/SDL_gfx-2.0/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ferzkopp.net/Software/SDL_gfx-2.0/
COMMENT=	Basic drawing routines for SDL

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
.if (${MACHINE_ARCH} != "i386")
CONFIGURE_ARGS+=	--disable-mmx
.endif

INSTALLATION_DIRS+=	share/doc/SDL_gfx
INSTALLATION_DIRS+=	share/doc/SDL_gfx/Screenshots

post-install:
	${INSTALL_DATA} ${WRKSRC}/Docs/*.* ${PREFIX}/share/doc/SDL_gfx/
	${INSTALL_DATA} ${WRKSRC}/Docs/Screenshots/* \
		${PREFIX}/share/doc/SDL_gfx/Screenshots

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
