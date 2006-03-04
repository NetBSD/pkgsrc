# $NetBSD: Makefile,v 1.27 2006/03/04 21:28:54 jlam Exp $

DISTNAME=	SDL_mixer-1.2.6
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://www.libsdl.org/projects/SDL_mixer/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
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
