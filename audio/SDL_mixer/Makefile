# $NetBSD: Makefile,v 1.26 2006/02/05 23:08:05 joerg Exp $

DISTNAME=	SDL_mixer-1.2.6
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://www.libsdl.org/projects/SDL_mixer/release/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/SDL_mixer/
COMMENT=	Multi-channel audio mixer library

CONFLICTS=		SDL-mixer-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

.include "../../mk/bsd.prefs.mk"

CPPFLAGS+=		-Dunix=1
CFLAGS+=		-DSYSCONFDIR="\"${PKG_SYSCONFDIR}\""

INSTALLATION_DIRS=	bin

post-install:
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/playmus ${PREFIX}/bin
	${LIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/playwave ${PREFIX}/bin

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
