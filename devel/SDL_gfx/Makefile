# $NetBSD: Makefile,v 1.8 2003/07/21 16:43:14 martti Exp $
#

DISTNAME=	SDL_gfx-2.0.3
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.ferzkopp.net/Software/SDL_gfx-2.0/

MAINTAINER=	collver1@comcast.net
HOMEPAGE=	http://www.ferzkopp.net/Software/SDL_gfx-2.0/
COMMENT=	Basic drawing routines for SDL

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

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
