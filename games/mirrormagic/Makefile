# $NetBSD: Makefile,v 1.11 2001/02/25 04:17:49 hubertf Exp $
#

DISTNAME=		mirrormagic-1.3
CATEGORIES=		games x11
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=games/} \
			http://www.artsoft.org/mirrormagic/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.artsoft.org/mirrormagic/
COMMENT=		Nice little puzzle game with color graphics and sound

USE_X11BASE=		YES
USE_XPM=		YES

do-install:
	${INSTALL_PROGRAM} -o bin -g games -m 2755 ${WRKSRC}/mirrormagic ${X11PREFIX}/bin
	${INSTALL_DATA_DIR} ${X11PREFIX}/share/mirrormagic/sounds
	${INSTALL_DATA_DIR} ${X11PREFIX}/share/mirrormagic/graphics
	${CHOWN} bin:games ${X11PREFIX}/share/mirrormagic
	${CHMOD} 775 ${X11PREFIX}/share/mirrormagic
	${INSTALL_DATA} ${WRKSRC}/sounds/* ${X11PREFIX}/share/mirrormagic/sounds
	${INSTALL_DATA} ${WRKSRC}/graphics/* ${X11PREFIX}/share/mirrormagic/graphics
	${INSTALL_DATA} ${WRKSRC}/RAY.* ${X11PREFIX}/share/mirrormagic
	${GUNZIP_CMD} ${X11PREFIX}/share/mirrormagic/graphics/*.gz
	${TOUCH} ${X11PREFIX}/share/mirrormagic/RAY.score
	${CHOWN} bin:games ${X11PREFIX}/share/mirrormagic/RAY.score
	${CHMOD} 664 ${X11PREFIX}/share/mirrormagic/RAY.score

.include "../../mk/bsd.pkg.mk"
