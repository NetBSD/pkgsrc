# $NetBSD: Makefile,v 1.28 2023/08/02 19:30:57 nia Exp $

DISTNAME=	xkobo-1.11
PKGREVISION=	5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=games/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://seki.math.hokudai.ac.jp:20080/xkobo-current.html
COMMENT=	Multi-way scrolling shoot 'em up game for X.  Strangely addictive

LICENSE=	gnu-gpl-v2

SETGIDGAME=		yes
SPECIAL_PERMS+=		bin/xoko ${SETGID_GAMES_PERMS}
OWN_DIRS_PERMS+=	${VARBASE}/games/xkobo ${GAMES_USER} ${GAMES_GROUP} \
			${GAMEDIRMODE}

MAKE_ENV+=	VARBASE=${VARBASE}

USE_IMAKE=	yes
USE_LANGUAGES=	c c++
BUILD_TARGET+=	xkobo all

# Fails with C++14 default language.
FORCE_CXX_STD=	c++03

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
