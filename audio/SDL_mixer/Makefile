# $NetBSD: Makefile,v 1.46 2012/09/11 23:59:21 asau Exp $

DISTNAME=	SDL_mixer-1.2.12
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://www.libsdl.org/projects/SDL_mixer/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/SDL_mixer/
COMMENT=	Multi-channel audio mixer library
LICENSE=	zlib

CONFLICTS=		SDL-mixer-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	SDL_mixer.pc.in

.include "../../mk/bsd.prefs.mk"

CPPFLAGS+=		-Dunix=1
CFLAGS+=		-DSYSCONFDIR="\"${PKG_SYSCONFDIR}\""

INSTALLATION_DIRS=	bin

post-install:
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/build/playmus ${DESTDIR:Q}${PREFIX:Q}/bin
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/build/playwave ${DESTDIR:Q}${PREFIX:Q}/bin

BUILDLINK_API_DEPENDS.SDL+=	SDL>=1.2.10

.include "../../audio/flac/buildlink3.mk"
# needs fluid_player_add_mem support, which is not yet
# mainstream, it seems (at least in fluidsynth 1.1.5)
# (patchset is from 2010)
#.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../audio/libmikmod/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
