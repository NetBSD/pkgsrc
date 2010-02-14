# $NetBSD: Makefile,v 1.27 2010/02/14 21:52:53 joerg Exp $
#

DISTNAME=		xboing2.4
PKGNAME=		xboing-2.4
PKGREVISION=		4
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=games/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.techrescue.org/xboing/
COMMENT=		Breakout style game for X11

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/xboing
USE_IMAKE=		YES

NO_INSTALL_MANPAGES=	YES
AUTO_MKDIRS=		yes
MAKE_DIRS=		${VARBASE}/games

MAKE_ENV+=		VARBASE=${VARBASE}
BUILD_DEFS+=		VARBASE

SETGIDGAME=		yes
SPECIAL_PERMS+=		bin/xboing ${SETGID_GAMES_PERMS}

CONF_FILES_PERMS+=		/dev/null ${VARBASE}/games/xboing.scr \
			${GAMES_USER} ${GAMES_GROUP} ${GAMEDATAMODE}

post-install:
	${INSTALL_MAN} ${WRKSRC}/xboing.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/xboing.6

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
