# $NetBSD: Makefile,v 1.42 2023/10/20 09:53:38 adam Exp $

DISTNAME=	mirrormagic-3.3.0-linux

COMMENT=	Nice little puzzle game with color graphics and sound

CONFLICTS=	mirrormagic-sdl-[1-9]*

LEVEL_NAMES=	classic_deflektor classic_mindbender

.include "../../games/rocksndiamonds/Makefile.common"

# bug in src/Makefile
MAKE_FLAGS+=	PROGBASE=${PKGBASE}

.include "../../mk/bsd.pkg.mk"
