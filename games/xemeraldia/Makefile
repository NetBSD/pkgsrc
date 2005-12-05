# $NetBSD: Makefile,v 1.8 2005/12/05 20:50:18 rillig Exp $

DISTNAME=	xemeraldia-0.3
PKGNAME=	xemeraldia-0.31
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.lab.kdd.co.jp/Usenet/fj.sources/1995/mar/

PATCH_SITES=	ftp://ftp.lab.kdd.co.jp/Usenet/fj.sources/1995/apr/
PATCHFILES=	xemeraldia-0.3to0.31.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	sakamoto@NetBSD.org
COMMENT=	Game of breaking blocks

USE_IMAKE=	yes
BUILD_TARGET=	xemeraldia

GAMES_DIR=	share/games
MAKE_ENV+=	GAMES_DIR=${GAMES_DIR:Q}
PLIST_SUBST=	GAMES_DIR=${GAMES_DIR:Q}

post-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/${GAMES_DIR}/xemeraldia
	@${TOUCH} ${PREFIX}/${GAMES_DIR}/xemeraldia/xemeraldia.scores
	@${CHMOD} 666 ${PREFIX}/${GAMES_DIR}/xemeraldia/xemeraldia.scores

.include "../../mk/bsd.pkg.mk"
