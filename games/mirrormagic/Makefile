# $NetBSD: Makefile,v 1.6 2000/01/02 03:20:12 wiz Exp $
#

DISTNAME=		mirrormagic-1.3
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=games/}

MAINTAINER=		root@garbled.net

DEPENDS=		xpm-3.4k:../../graphics/xpm

USE_X11BASE=		YES

do-install:
	${INSTALL_PROGRAM} -o bin -g games -m 2755 ${WRKSRC}/mirrormagic ${X11BASE}/bin
	${MKDIR} ${X11BASE}/share/mirrormagic/sounds
	${MKDIR} ${X11BASE}/share/mirrormagic/graphics
	${CHOWN} bin:games ${X11BASE}/share/mirrormagic
	${CHMOD} 775 ${X11BASE}/share/mirrormagic
	${INSTALL_DATA} ${WRKSRC}/sounds/* ${X11BASE}/share/mirrormagic/sounds
	${INSTALL_DATA} ${WRKSRC}/graphics/* ${X11BASE}/share/mirrormagic/graphics
	${INSTALL_DATA} ${WRKSRC}/RAY.* ${X11BASE}/share/mirrormagic
	${GUNZIP_CMD} ${X11BASE}/share/mirrormagic/graphics/*.gz
	${TOUCH} ${X11BASE}/share/mirrormagic/RAY.score
	${CHOWN} bin:games ${X11BASE}/share/mirrormagic/RAY.score
	${CHMOD} 664 ${X11BASE}/share/mirrormagic/RAY.score

.include "../../mk/bsd.pkg.mk"
