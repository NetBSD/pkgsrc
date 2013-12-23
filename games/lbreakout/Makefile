# $NetBSD: Makefile,v 1.34 2013/12/23 11:57:03 wiz Exp $

DISTNAME=	lbreakout-010315
PKGREVISION=	11
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lgames.sourceforge.net/
COMMENT=	Breakout-style arcade game

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		VARBASE=${VARBASE:Q}
CONFIGURE_ARGS+=	--disable-sound

USE_LANGUAGES=	c c++

SETGIDGAME=	yes

REQD_DIRS=	${VARBASE}/games
REQD_FILES_PERMS= ${PREFIX}/share/games/lbreakout/lbreakout.hscr ${VARBASE}/games/lbreakout.hscr ${GAMES_USER} ${GAMES_GROUP} ${GAMEDATAMODE}
SPECIAL_PERMS+=	bin/lbreakout ${SETGID_GAMES_PERMS}

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
