# $NetBSD: Makefile,v 1.41 2023/05/06 19:09:26 ryoon Exp $

DISTNAME=	mirrormagic-3.0.0

COMMENT=	Nice little puzzle game with color graphics and sound
PKGREVISION=	8

CONFLICTS=	mirrormagic-sdl-[1-9]*

LEVEL_NAMES=	classic_deflektor classic_mindbender

.include "../../games/rocksndiamonds/Makefile.common"

# bug in src/Makefile
MAKE_FLAGS+=	PROGBASE=${PKGBASE}
MAKE_FLAGS+=	RO_GAME_DIR=${PREFIX}/share/${PKGBASE}
MAKE_FLAGS+=	RW_GAME_DIR=${SCORE_PATH:Q}

.include "../../mk/bsd.pkg.mk"
