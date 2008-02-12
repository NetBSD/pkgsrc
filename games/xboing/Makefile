# $NetBSD: Makefile,v 1.26 2008/02/12 08:03:49 rillig Exp $
#

DISTNAME=		xboing2.4
PKGNAME=		xboing-2.4
PKGREVISION=		3
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=games/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.techrescue.org/xboing/
COMMENT=		Breakout style game for X11

WRKSRC=			${WRKDIR}/xboing
USE_IMAKE=		YES

NO_INSTALL_MANPAGES=	YES
AUTO_MKDIRS=		yes
MAKE_DIRS=		${VARBASE}/games

MAKE_ENV+=		VARBASE=${VARBASE}
BUILD_DEFS+=		VARBASE GAMEMODE

post-install:
	${CHOWN} ${GAMEOWN}:${GAMEGRP} ${PREFIX}/bin/xboing
	${CHMOD} ${GAMEMODE} ${PREFIX}/bin/xboing
	${INSTALL_MAN} ${WRKSRC}/xboing.man ${PREFIX}/${PKGMANDIR}/man6/xboing.6

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
