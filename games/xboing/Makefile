# $NetBSD: Makefile,v 1.14 2004/03/08 01:29:25 snj Exp $
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
	${CHOWN} bin:games ${X11PREFIX}/bin/xboing
	${CHMOD} 2755 ${X11PREFIX}/bin/xboing
	${INSTALL_MAN} ${WRKSRC}/xboing.man ${X11PREFIX}/man/man6/xboing.6

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
