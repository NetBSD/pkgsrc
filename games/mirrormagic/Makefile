# $NetBSD: Makefile,v 1.39 2022/08/11 05:08:33 gutteridge Exp $

DISTNAME=	mirrormagic-3.0.0

COMMENT=	Nice little puzzle game with color graphics and sound
PKGREVISION=	6

CONFLICTS=	mirrormagic-sdl-[1-9]*

LEVEL_NAMES=	classic_deflektor classic_mindbender

.include "../../games/rocksndiamonds/Makefile.common"

# bug in src/Makefile
MAKE_FLAGS+=	PROGBASE=${PKGBASE}
MAKE_FLAGS+=	RO_GAME_DIR=${PREFIX}/share/${PKGBASE}
MAKE_FLAGS+=	RW_GAME_DIR=${SCORE_PATH:Q}

.include "../../mk/bsd.pkg.mk"
