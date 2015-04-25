# $NetBSD: Makefile,v 1.40 2015/04/25 14:20:31 tnn Exp $

DISTNAME=	SDL_gfx-2.0.24
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sdlgfx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ferzkopp.net/joomla/content/view/19/14/
COMMENT=	Basic drawing routines for SDL
LICENSE=	zlib

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
