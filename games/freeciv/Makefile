# $NetBSD: Makefile,v 1.4 1998/08/04 14:05:48 frueauf Exp $
#

DISTNAME=		freeciv-1.6.6
CATEGORIES=		games x11
MASTER_SITES=		freeciv.ultraviolet.org:/pub/freeciv/

MAINTAINER=		root@garbled.net

DEPENDS=		xpm-3.4k:../../graphics/xpm

CONFLICTS=		freeciv-1.6.3 freeciv-1.6.5

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
