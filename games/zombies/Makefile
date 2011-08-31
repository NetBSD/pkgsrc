# $NetBSD: Makefile,v 1.18 2011/08/31 12:14:33 obache Exp $

DISTNAME=	zombies-1.0
PKGREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://www.thistledown.com.au/software/

MAINTAINER=	simonb@NetBSD.org
HOMEPAGE=	http://www.thistledown.com.au/software/
COMMENT=	Simple robots-like game where you destroy the zombies
LICENSE=	2-clause-bsd

USE_GAMESGROUP=		yes

SAVEPATH=		${VARBASE}/games/zombies
SCOREFILE=		${SAVEPATH}/scores

SPECIAL_PERMS=		bin/zombies ${SETGID_GAMES_PERMS}
OWN_DIRS_PERMS+=	${SAVEPATH} ${GAMES_USER} ${GAMES_GROUP} ${GAMEDIRMODE}

AUTO_MKDIRS=	yes
BUILD_DEFS+=	VARBASE SCOREFILE
MAKE_ENV+=	INSTALL_SCORE=echo SCOREFILE=${SCOREFILE}

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
