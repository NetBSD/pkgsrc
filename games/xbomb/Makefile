# $NetBSD: Makefile,v 1.14 2008/11/21 16:48:33 adam Exp $

DISTNAME=	xbomb-2.2
CATEGORIES=	games x11
MASTER_SITES=	http://www.gedanken.demon.co.uk/download-xbomb/
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.gedanken.demon.co.uk/xbomb/
COMMENT=	Square, hexagonal, and triangual minesweeper clone

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
BUILD_TARGET=		xbomb
MAKE_ENV+=		SCORE_PATH=${SCORE_PATH:Q}
INSTALL_MAKE_FLAGS+=	INSTDIR=${DESTDIR}${PREFIX}

SCORE_PATH=	${VARBASE}/games/xbomb
SCORE_USER=	games
SCORE_GROUP=	games
PKG_USERS=	${SCORE_USER}:${SCORE_GROUP}
PKG_GROUPS=	${SCORE_GROUP}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6 lib/X11/app-defaults
CONF_FILES_PERMS+=	/dev/null ${SCORE_PATH:Q}/xbomb3.hi ${GAMEOWN} ${GAMEGRP} ${GAMEDATAMODE}
CONF_FILES_PERMS+=	/dev/null ${SCORE_PATH:Q}/xbomb4.hi ${GAMEOWN} ${GAMEGRP} ${GAMEDATAMODE}
CONF_FILES_PERMS+=	/dev/null ${SCORE_PATH:Q}/xbomb6.hi ${GAMEOWN} ${GAMEGRP} ${GAMEDATAMODE}

.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
