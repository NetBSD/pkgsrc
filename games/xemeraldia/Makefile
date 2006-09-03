# $NetBSD: Makefile,v 1.11 2006/09/03 00:56:29 wiz Exp $

DISTNAME=	xemeraldia-0.3
PKGNAME=	xemeraldia-0.31
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.lab.kdd.co.jp/Usenet/fj.sources/1995/mar/

PATCH_SITES=	ftp://ftp.lab.kdd.co.jp/Usenet/fj.sources/1995/apr/
PATCHFILES=	xemeraldia-0.3to0.31.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Game of breaking blocks

USE_IMAKE=	yes
BUILD_TARGET=	xemeraldia

GAMES_DIR=	share/games
MAKE_ENV+=	GAMES_DIR=${GAMES_DIR:Q}
PLIST_SUBST=	GAMES_DIR=${GAMES_DIR:Q}

CONF_FILES_PERMS+=	/dev/null ${PREFIX}/${GAMES_DIR}/xemeraldia/xemeraldia.scores \
			${ROOT_USER} games 664

.include "../../mk/bsd.pkg.mk"
