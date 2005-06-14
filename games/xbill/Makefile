# $NetBSD: Makefile,v 1.18 2005/06/14 17:23:24 minskim Exp $
#

DISTNAME=		xbill-2.0
PKGREVISION=		1
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=games/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.xbill.org/
COMMENT=		Stop the dreaded Windows virus from infecting computers

CONFLICT=		gnome-games-[0-9]*

USE_IMAKE=		YES
USE_PKGINSTALL=		YES
NO_INSTALL_MANPAGES=	YES

CPPFLAGS+=		-DVARBASE=\"${VARBASE}\"
PKG_GROUPS=		${GAMEGRP}
MAKE_DIRS_PERMS+=	${VARBASE}/games ${BINOWN} ${GAMEGRP} 0775
MAKE_ENV+=		GAMEGRP=${GAMEGRP} GAMEMODE=${GAMEMODE}
SUPPORT_FILES_PERMS+=	${PREFIX}/share/examples/xbill.scores ${VARBASE}/games/xbill.scores ${BINOWN} ${GAMEGRP} ${GAMEDATAMODE}

post-install:
	${INSTALL_MAN} ${WRKSRC}/xbill.man ${PREFIX}/man/man6/xbill.6
	${INSTALL_DATA} ${WRKSRC}/scores ${PREFIX}/share/examples/xbill.scores

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
