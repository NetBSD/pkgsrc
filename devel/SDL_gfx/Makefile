# $NetBSD: Makefile,v 1.13 2004/02/14 17:21:36 jlam Exp $
#

DISTNAME=	SDL_gfx-2.0.3
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.ferzkopp.net/Software/SDL_gfx-2.0/

MAINTAINER=	ben@NetBSD.org
HOMEPAGE=	http://www.ferzkopp.net/Software/SDL_gfx-2.0/
COMMENT=	Basic drawing routines for SDL

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES

.if (${MACHINE_ARCH} != "i386")
CONFIGURE_ARGS+=	--disable-mmx
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/SDL_gfx/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/SDL_gfx/Screenshots
	${INSTALL_DATA} ${WRKSRC}/Docs/*.* ${PREFIX}/share/doc/SDL_gfx/
	${INSTALL_DATA} ${WRKSRC}/Docs/Screenshots/* \
		${PREFIX}/share/doc/SDL_gfx/Screenshots

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
