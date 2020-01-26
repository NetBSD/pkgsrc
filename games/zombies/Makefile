# $NetBSD: Makefile,v 1.21 2020/01/26 17:31:18 rillig Exp $

DISTNAME=	zombies-1.0
PKGREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://www.thistledown.com.au/software/

MAINTAINER=	simonb@NetBSD.org
HOMEPAGE=	https://www.thistledown.com.au/software/
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
