# $NetBSD: Makefile,v 1.1 1998/06/12 13:43:17 frueauf Exp $
#

DISTNAME=		mirrormagic-1.3
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games

MAINTAINER=		root@garbled.net

DEPENDS=		xpm-3.4j:../../graphics/xpm

USE_X11=		YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mirrormagic ${X11BASE}/bin
	${MKDIR} ${X11BASE}/share/mirrormagic/sounds
	${MKDIR} ${X11BASE}/share/mirrormagic/graphics
	${INSTALL_DATA} ${WRKSRC}/sounds/* ${X11BASE}/share/mirrormagic/sounds
	${INSTALL_DATA} ${WRKSRC}/graphics/* ${X11BASE}/share/mirrormagic/graphics
	${INSTALL_DATA} ${WRKSRC}/RAY.* ${X11BASE}/share/mirrormagic
	${GUNZIP_CMD} ${X11BASE}/share/mirrormagic/graphics/*.gz
	${TOUCH} ${X11BASE}/share/mirrormagic/RAY.score ${X11BASE}/share/mirrormagic/RAY.names
	chmod 666 ${X11BASE}/share/mirrormagic/RAY.score ${X11BASE}/share/mirrormagic/RAY.names

.include "../../mk/bsd.pkg.mk"
