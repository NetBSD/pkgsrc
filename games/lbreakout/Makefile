# $NetBSD: Makefile,v 1.30 2007/12/13 11:17:19 rillig Exp $

DISTNAME=	lbreakout-010315
PKGREVISION=	10
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://lgames.sourceforge.net/
COMMENT=	Breakout-style arcade game

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		VARBASE=${VARBASE:Q}
CONFIGURE_ARGS+=	--disable-sound

USE_LANGUAGES=	c c++

REQD_DIRS=	${VARBASE}/games
REQD_FILES_PERMS= ${PREFIX}/share/games/lbreakout/lbreakout.hscr ${VARBASE}/games/lbreakout.hscr ${GAMEOWN} ${GAMEGRP} ${GAMEDATAMODE}

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
