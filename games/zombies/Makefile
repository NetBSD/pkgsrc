# $NetBSD: Makefile,v 1.20 2015/08/18 07:31:09 wiz Exp $

DISTNAME=	zombies-1.0
PKGREVISION=	6
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

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
