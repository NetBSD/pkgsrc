# $NetBSD: Makefile,v 1.5 2000/07/11 08:43:53 agc Exp $
#

DISTNAME=		xboing2.4
PKGNAME=		xboing-2.4
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=games/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.catt.rmit.edu.au/xboing/xboing.html

DEPENDS+=		xpm-3.4k:../../graphics/xpm

WRKSRC=			${WRKDIR}/xboing
NO_INSTALL_MANPAGES=	yes
USE_IMAKE=		yes

post-install:
	${CHOWN} bin:games ${X11PREFIX}/bin/xboing
	${CHMOD} 2755 ${X11PREFIX}/bin/xboing
	${INSTALL_MAN} ${WRKSRC}/xboing.man ${X11PREFIX}/man/man6/xboing.6

.include "../../mk/bsd.pkg.mk"
