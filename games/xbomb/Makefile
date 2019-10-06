# $NetBSD: Makefile,v 1.17 2019/10/06 14:44:35 jakllsch Exp $

DISTNAME=	xbomb-2.2
PKGREVISION=	1
CATEGORIES=	games x11
MASTER_SITES=	http://www.gedanken.demon.co.uk/download-xbomb/
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.gedanken.demon.co.uk/xbomb/
COMMENT=	Square, hexagonal, and triangual minesweeper clone

USE_TOOLS+=		gmake
BUILD_TARGET=		xbomb
MAKE_ENV+=		SCORE_PATH=${SCORE_PATH:Q}
INSTALL_MAKE_FLAGS+=	INSTDIR=${DESTDIR}${PREFIX}

SETGIDGAME=	yes
SCORE_PATH=	${VARBASE}/games/xbomb

SPECIAL_PERMS+=	bin/xbomb ${SETGID_GAMES_PERMS}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6 lib/X11/app-defaults
CONF_FILES_PERMS+=	/dev/null ${SCORE_PATH:Q}/xbomb3.hi ${GAMES_USER} ${GAMES_GROUP} ${GAMEDATAMODE}
CONF_FILES_PERMS+=	/dev/null ${SCORE_PATH:Q}/xbomb4.hi ${GAMES_USER} ${GAMES_GROUP} ${GAMEDATAMODE}
CONF_FILES_PERMS+=	/dev/null ${SCORE_PATH:Q}/xbomb6.hi ${GAMES_USER} ${GAMES_GROUP} ${GAMEDATAMODE}

.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
