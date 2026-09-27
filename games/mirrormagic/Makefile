# $NetBSD: Makefile,v 1.50 2026/09/27 11:36:24 tnn Exp $

DISTNAME=	mirrormagic-3.3.1-linux

COMMENT=	Nice little puzzle game with color graphics and sound
PKGREVISION=	7

CONFLICTS=	mirrormagic-sdl-[1-9]*

LEVEL_NAMES=	classic_deflektor classic_mindbender

.include "../../games/rocksndiamonds/Makefile.common"

# bug in src/Makefile
MAKE_FLAGS+=	PROGBASE=${PKGBASE}

.include "../../mk/bsd.pkg.mk"
