# $NetBSD: Makefile,v 1.14 2009/12/10 20:59:22 abs Exp $

DISTNAME=	zombies-1.0
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.thistledown.com.au/software/

MAINTAINER=	simonb@NetBSD.org
HOMEPAGE=	http://www.thistledown.com.au/software/
COMMENT=	Simple robots-like game where you destroy the zombies

# For removing setting SETGIDGAME from here pkgsrc should be fixed
SETGIDGAME=		yes

SAVEPATH=		${VARBASE}/games/zombies
SCOREFILE=		${SAVEPATH}/scores

SPECIAL_PERMS=		bin/zombies ${SETGID_GAMES_PERMS}
OWN_DIRS_PERMS+=	${SAVEPATH} ${GAMEOWN} ${GAMEGRP} ${GAMEDIRMODE}

AUTO_MKDIRS=	yes
BUILD_DEFS+=	VARBASE SCOREFILE
MAKE_ENV+=	SCOREFILE=${SCOREFILE}

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
