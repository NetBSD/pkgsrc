# $NetBSD: Makefile,v 1.1.1.1 2004/10/14 12:28:02 adam Exp $

DISTNAME=	xbomb-2.1a
CATEGORIES=	games x11
MASTER_SITES=	http://www.gedanken.demon.co.uk/download-xbomb/ \
		ftp://ftp.demon.co.uk/pub/unix/xwindows/games/ \
		ftp://ftp.ibiblio.org/pub/Linux/games/strategy/
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.gedanken.demon.co.uk/xbomb/
COMMENT=	Square, hexagonal, and triangual minesweeper clone

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes
ALL_TARGET=		xbomb
MAKE_ENV+=		SCORE_PATH="${SCORE_PATH}"

SCORE_PATH=	${VARBASE}/games/xbomb
SCORE_USER=	games
SCORE_GROUP=	games
PKG_USERS=	${SCORE_USER}:${SCORE_GROUP}
PKG_GROUPS=	${SCORE_GROUP}

PLIST_SUBST+=	SCORE_PATH=${SCORE_PATH}
PLIST_SUBST+=	GAME_DIR="${INSTALL} -d -o ${SCORE_USER} -g ${SCORE_GROUP} -m 775"

post-install:
	${INSTALL_DATA_DIR} ${SCORE_PATH}
.for score in . xbomb3.hi xbomb4.hi xbomb6.hi
	${TOUCH} ${SCORE_PATH}/${score}
.endfor
	${CHMOD} -R 775 ${SCORE_PATH}
	${CHOWN} -R ${SCORE_USER}:${SCORE_GROUP} ${SCORE_PATH}

.include "../../mk/bsd.pkg.mk"
