# $NetBSD: Makefile,v 1.8 2006/06/08 15:50:14 joerg Exp $

DISTNAME=	xbomb-2.1a
PKGREVISION=	2
CATEGORIES=	games x11
MASTER_SITES=	http://www.gedanken.demon.co.uk/download-xbomb/ \
		ftp://ftp.demon.co.uk/pub/unix/xwindows/games/ \
		ftp://ftp.ibiblio.org/pub/Linux/games/strategy/
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.gedanken.demon.co.uk/xbomb/
COMMENT=	Square, hexagonal, and triangual minesweeper clone

USE_TOOLS+=		gmake
BUILD_TARGET=		xbomb
MAKE_ENV+=		SCORE_PATH=${SCORE_PATH:Q}

SCORE_PATH=	${VARBASE}/games/xbomb
SCORE_USER=	games
SCORE_GROUP=	games
PKG_USERS=	${SCORE_USER}:${SCORE_GROUP}
PKG_GROUPS=	${SCORE_GROUP}

INSTALLATION_DIRS=	bin man/man6 lib/X11/app-defaults
CONF_FILES_PERMS+=	/dev/null ${SCORE_PATH}/xbomb3.hi ${GAMEOWN} ${GAMEGRP} ${GAMEDATAMODE}
CONF_FILES_PERMS+=	/dev/null ${SCORE_PATH}/xbomb4.hi ${GAMEOWN} ${GAMEGRP} ${GAMEDATAMODE}
CONF_FILES_PERMS+=	/dev/null ${SCORE_PATH}/xbomb6.hi ${GAMEOWN} ${GAMEGRP} ${GAMEDATAMODE}


.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
