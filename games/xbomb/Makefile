# $NetBSD: Makefile,v 1.12 2008/09/25 14:02:09 wiz Exp $

DISTNAME=	xbomb-2.1a
PKGREVISION=	3
CATEGORIES=	games x11
MASTER_SITES=	http://www.gedanken.demon.co.uk/download-xbomb/
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

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6 lib/X11/app-defaults
CONF_FILES_PERMS+=	/dev/null ${SCORE_PATH}/xbomb3.hi ${GAMEOWN} ${GAMEGRP} ${GAMEDATAMODE}
CONF_FILES_PERMS+=	/dev/null ${SCORE_PATH}/xbomb4.hi ${GAMEOWN} ${GAMEGRP} ${GAMEDATAMODE}
CONF_FILES_PERMS+=	/dev/null ${SCORE_PATH}/xbomb6.hi ${GAMEOWN} ${GAMEGRP} ${GAMEDATAMODE}


.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
