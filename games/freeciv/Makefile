# $NetBSD: Makefile,v 1.7 1999/02/20 22:48:29 hubertf Exp $
#

DISTNAME=		freeciv-1.7.2
CATEGORIES=		games x11
MASTER_SITES=		ftp://www.freeciv.org/pub/freeciv/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.freeciv.org/index.html

DEPENDS+=		xpm-3.4k:../../graphics/xpm

USE_IMAKE=		YES
NO_INSTALL_MANPAGES=	YES

pre-patch:
	${TOUCH} ${WRKSRC}/civclient.man
	${TOUCH} ${WRKSRC}/civserver.man

post-patch:
	${MV} ${WRKSRC}/client/climisc.c ${WRKSRC}/client/climisc.c.bak
	${SED} -e 's|@X11BASE@|${X11BASE}|g' < ${WRKSRC}/client/climisc.c.bak \
		> ${WRKSRC}/client/climisc.c

post-install:
	${MKDIR} ${X11BASE}/share/freeciv/data
	${INSTALL_DATA} ${WRKSRC}/data/*.txt ${X11BASE}/share/freeciv/data
	${INSTALL_DATA} ${WRKSRC}/data/*.xpm ${X11BASE}/share/freeciv/data
	${INSTALL_DATA} ${WRKSRC}/data/Freeciv ${X11BASE}/lib/X11/app-defaults

.include "../../mk/bsd.pkg.mk"
