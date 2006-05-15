# $NetBSD: Makefile,v 1.23 2006/05/15 21:01:56 joerg Exp $
#

DISTNAME=		xbill-2.0
PKGREVISION=		3
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=games/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.xbill.org/
COMMENT=		Stop the dreaded Windows virus from infecting computers

CONFLICTS+=		gnome-games-[0-9]*

USE_LANGUAGES=		c c++
USE_IMAKE=		YES
NO_INSTALL_MANPAGES=	YES

CPPFLAGS+=		-DVARBASE=\"${VARBASE}\"
PKG_USERS=		${GAMEOWN}:${GAMEGRP}
PKG_GROUPS=		${GAMEGRP}
MAKE_DIRS_PERMS+=	${VARBASE}/games ${GAMEOWN} ${GAMEGRP} 0775
MAKE_ENV+=		GAMEOWN=${GAMEOWN:Q}
MAKE_ENV+=		GAMEGRP=${GAMEGRP:Q}
MAKE_ENV+=		GAMEMODE=${GAMEMODE:Q}
CONF_FILES_PERMS+=	${PREFIX}/share/examples/xbill.scores ${VARBASE}/games/xbill.scores ${GAMEOWN} ${GAMEGRP} ${GAMEDATAMODE}

post-install:
	${INSTALL_MAN} ${WRKSRC}/xbill.man ${PREFIX}/man/man6/xbill.6
	${INSTALL_DATA} ${WRKSRC}/scores ${PREFIX}/share/examples/xbill.scores

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
