# $NetBSD: Makefile,v 1.4 2000/01/02 03:20:14 wiz Exp $
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
	${CHOWN} bin:games ${X11BASE}/bin/xboing
	${CHMOD} 2755 ${X11BASE}/bin/xboing
	${INSTALL_MAN} ${WRKSRC}/xboing.man ${X11BASE}/man/man6/xboing.6

.include "../../mk/bsd.pkg.mk"
