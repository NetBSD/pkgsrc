# $NetBSD: Makefile,v 1.15 2004/08/04 03:06:55 jschauma Exp $
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
USE_BUILDLINK3=		YES
USE_IMAKE=		YES

NO_INSTALL_MANPAGES=	YES

post-install:
	${CHOWN} ${GAMEOWN}:${GAMEGRP} ${X11PREFIX}/bin/xboing
	${CHMOD} ${GAMEMODE} ${X11PREFIX}/bin/xboing
	${INSTALL_MAN} ${WRKSRC}/xboing.man ${X11PREFIX}/man/man6/xboing.6

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
