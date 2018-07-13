# $NetBSD: Makefile,v 1.32 2018/07/13 17:28:46 adam Exp $

DISTNAME=	mirrormagic-3.0.0

COMMENT=	Nice little puzzle game with color graphics and sound

CONFLICTS=	mirrormagic-sdl-[1-9]*

LEVEL_NAMES=	classic_deflektor classic_mindbender

.include "../../games/rocksndiamonds/Makefile.common"

# bug in src/Makefile
MAKE_FLAGS+=	PROGBASE=${PKGBASE}

.include "../../mk/bsd.pkg.mk"
