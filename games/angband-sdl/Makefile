# $NetBSD: Makefile,v 1.3 2023/01/29 21:16:06 ryoon Exp $

PKGREVISION= 1
.include "../../games/angband/Makefile.common"

PKGNAME=	${DISTNAME:S/angband-/angband-sdl-/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Single-player dungeon exploration game (version with graphics/sound)

CONFLICTS+=	angband-[0-9]*
CONFLICTS+=	angband-tty-[0-9]*
CONFLICTS+=	angband-x11-[0-9]*
SUPERSEDES=	angband-x11-[0-9]*

ICON_SIZES=	16 32 128 256 512

# XXX the SDL2 frontend doesn't seem particularly ready yet
# e.g. selecting fonts, a tileset, or windowed mode doesn't seem to work
# please switch this when it's ready.
#CONFIGURE_ARGS+=	--enable-sdl2
CONFIGURE_ARGS+=	--enable-sdl

INSTALLATION_DIRS+=	share/applications
.for s in ${ICON_SIZES}
INSTALLATION_DIRS+=	share/icons/hicolor/${s}x${s}/apps
.endfor

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/share/angband/icons/angband-x11.desktop
	${MV} ${DESTDIR}${PREFIX}/share/angband/icons/angband-sdl.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
.for s in ${ICON_SIZES}
	${INSTALL_DATA} ${WRKSRC}/lib/icons/att-${s}.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/angband.png
.endfor

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
#.include "../../audio/SDL2_mixer/buildlink3.mk"
#.include "../../devel/SDL2/buildlink3.mk"
#.include "../../graphics/SDL2_image/buildlink3.mk"
#.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
