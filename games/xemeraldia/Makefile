# $NetBSD: Makefile,v 1.2 1999/12/14 01:49:32 sakamoto Exp $
# FreeBSD Id: ports/games/xemeraldia/Makefile,v 1.17 1999/12/10 19:24:55 steve Exp

DISTNAME=	xemeraldia-0.3
PKGNAME=	xemeraldia-0.31
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.lab.kdd.co.jp/Usenet/fj.sources/1995/mar/

PATCH_SITES=	ftp://ftp.lab.kdd.co.jp/Usenet/fj.sources/1995/apr/
PATCHFILES=	xemeraldia-0.3to0.31.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	sakamoto@netbsd.org

USE_IMAKE=	yes
ALL_TARGET=	xemeraldia

GAMES_DIR=	share/games
MAKE_ENV+=	GAMES_DIR="${GAMES_DIR}"
PLIST_SUBST=	GAMES_DIR="${GAMES_DIR}"

post-install:
	@${MKDIR} ${PREFIX}/${GAMES_DIR}/xemeraldia
	@${TOUCH} ${PREFIX}/${GAMES_DIR}/xemeraldia/xemeraldia.scores
	@${CHMOD} 666 ${PREFIX}/${GAMES_DIR}/xemeraldia/xemeraldia.scores

.include "../../mk/bsd.pkg.mk"
