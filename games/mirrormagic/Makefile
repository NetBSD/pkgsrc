# $NetBSD: Makefile,v 1.51 2026/09/29 06:05:19 wiz Exp $

DISTNAME=	mirrormagic-3.3.1-linux

COMMENT=	Nice little puzzle game with color graphics and sound
PKGREVISION=	8

CONFLICTS=	mirrormagic-sdl-[1-9]*

LEVEL_NAMES=	classic_deflektor classic_mindbender

.include "../../games/rocksndiamonds/Makefile.common"

# bug in src/Makefile
MAKE_FLAGS+=	PROGBASE=${PKGBASE}

.include "../../mk/bsd.pkg.mk"
