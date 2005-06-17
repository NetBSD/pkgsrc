# $NetBSD: Makefile,v 1.18 2005/06/17 04:49:46 jlam Exp $
#

DISTNAME=		xboing2.4
PKGNAME=		xboing-2.4
PKGREVISION=		2
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=games/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.techrescue.org/xboing/
COMMENT=		Breakout style game for X11

WRKSRC=			${WRKDIR}/xboing
USE_IMAKE=		YES

NO_INSTALL_MANPAGES=	YES

MAKE_ENV+=		VARBASE=${VARBASE:Q}

post-install:
	${CHOWN} ${GAMEOWN}:${GAMEGRP} ${PREFIX}/bin/xboing
	${CHMOD} ${GAMEMODE} ${PREFIX}/bin/xboing
	${INSTALL_MAN} ${WRKSRC}/xboing.man ${PREFIX}/man/man6/xboing.6

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
