# $NetBSD: Makefile,v 1.38 2022/04/10 12:18:20 adam Exp $

DISTNAME=	mirrormagic-3.0.0

COMMENT=	Nice little puzzle game with color graphics and sound
PKGREVISION=	5

CONFLICTS=	mirrormagic-sdl-[1-9]*

LEVEL_NAMES=	classic_deflektor classic_mindbender

.include "../../games/rocksndiamonds/Makefile.common"

# bug in src/Makefile
MAKE_FLAGS+=	PROGBASE=${PKGBASE}
MAKE_FLAGS+=	RO_GAME_DIR=${PREFIX}/share/${PKGBASE}
MAKE_FLAGS+=	RW_GAME_DIR=${SCORE_PATH:Q}

.include "../../mk/bsd.pkg.mk"
