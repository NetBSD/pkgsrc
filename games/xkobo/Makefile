# $NetBSD: Makefile,v 1.22 2012/05/27 18:16:31 abs Exp $

DISTNAME=	xkobo-1.11
PKGREVISION=	5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=games/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://seki.math.hokudai.ac.jp:20080/xkobo-current.html
COMMENT=	Multi-way scrolling shoot 'em up game for X.  Strangely addictive

PKG_DESTDIR_SUPPORT=	user-destdir
LICENSE=	gnu-gpl-v2

SETGIDGAME=	yes
SPECIAL_PERMS+=	bin/xoko ${SETGID_GAMES_PERMS}
OWN_DIRS_PERMS+=	${VARBASE}/games/xkobo ${GAMES_USER} ${GAMES_GROUP} \
			${GAMEDIRMODE}

MAKE_ENV+=	VARBASE=${VARBASE:Q}

USE_IMAKE=	yes
USE_LANGUAGES=	c c++
BUILD_TARGET+=	xkobo all

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
