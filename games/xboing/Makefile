# $NetBSD: Makefile,v 1.9 2002/07/15 09:01:42 wiz Exp $
#

DISTNAME=		xboing2.4
PKGNAME=		xboing-2.4
PKGREVISION=		1
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=games/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.techrescue.org/xboing/
COMMENT=		Breakout style game for X11

USE_IMAKE=		YES

NO_INSTALL_MANPAGES=	YES
WRKSRC=			${WRKDIR}/xboing

post-install:
	${CHOWN} bin:games ${X11PREFIX}/bin/xboing
	${CHMOD} 2755 ${X11PREFIX}/bin/xboing
	${INSTALL_MAN} ${WRKSRC}/xboing.man ${X11PREFIX}/man/man6/xboing.6

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
