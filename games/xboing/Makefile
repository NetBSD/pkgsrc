# $NetBSD: Makefile,v 1.7 2001/01/12 12:35:14 dent Exp $
#

DISTNAME=		xboing2.4
PKGNAME=		xboing-2.4
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=games/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.techrescue.org/xboing/

USE_IMAKE=		YES
USE_XPM=		YES

NO_INSTALL_MANPAGES=	YES
WRKSRC=			${WRKDIR}/xboing

post-install:
	${CHOWN} bin:games ${X11PREFIX}/bin/xboing
	${CHMOD} 2755 ${X11PREFIX}/bin/xboing
	${INSTALL_MAN} ${WRKSRC}/xboing.man ${X11PREFIX}/man/man6/xboing.6

.include "../../mk/bsd.pkg.mk"
