# $NetBSD: Makefile,v 1.29 2006/07/07 06:52:46 adam Exp $

DISTNAME=	SDL_mixer-1.2.7
CATEGORIES=	audio
MASTER_SITES=	http://www.libsdl.org/projects/SDL_mixer/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/SDL_mixer/
COMMENT=	Multi-channel audio mixer library

CONFLICTS=		SDL-mixer-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

CPPFLAGS+=		-Dunix=1
CFLAGS+=		-DSYSCONFDIR="\"${PKG_SYSCONFDIR}\""

INSTALLATION_DIRS=	bin

post-install:
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/build/playmus ${PREFIX}/bin
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/build/playwave ${PREFIX}/bin

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
