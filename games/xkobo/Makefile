# $NetBSD: Makefile,v 1.26 2018/07/18 00:06:17 joerg Exp $

DISTNAME=	xkobo-1.11
PKGREVISION=	5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=games/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://seki.math.hokudai.ac.jp:20080/xkobo-current.html
COMMENT=	Multi-way scrolling shoot 'em up game for X.  Strangely addictive

LICENSE=	gnu-gpl-v2

SETGIDGAME=	yes
SPECIAL_PERMS+=	bin/xoko ${SETGID_GAMES_PERMS}
OWN_DIRS_PERMS+=	${VARBASE}/games/xkobo ${GAMES_USER} ${GAMES_GROUP} \
			${GAMEDIRMODE}

MAKE_ENV+=	VARBASE=${VARBASE}

USE_IMAKE=	yes
USE_LANGUAGES=	c c++03
BUILD_TARGET+=	xkobo all

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
