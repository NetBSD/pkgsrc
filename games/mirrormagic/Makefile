# $NetBSD: Makefile,v 1.33 2020/03/08 16:49:45 wiz Exp $

DISTNAME=	mirrormagic-3.0.0

COMMENT=	Nice little puzzle game with color graphics and sound
PKGREVISION=	1

CONFLICTS=	mirrormagic-sdl-[1-9]*

LEVEL_NAMES=	classic_deflektor classic_mindbender

.include "../../games/rocksndiamonds/Makefile.common"

# bug in src/Makefile
MAKE_FLAGS+=	PROGBASE=${PKGBASE}

.include "../../mk/bsd.pkg.mk"
