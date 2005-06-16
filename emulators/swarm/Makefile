# $NetBSD: Makefile,v 1.12 2005/06/16 06:57:51 jlam Exp $
#

DISTNAME=	swarm-0.61
CATEGORIES=	emulators
MASTER_SITES=	http://www.cl.cam.ac.uk/~mwd24/phd/bin/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.cl.cam.ac.uk/~mwd24/phd/swarm.html
COMMENT=	Software arm7M core emulator

WRKSRC=		${WRKDIR}/swarm/src

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/swarm ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/swarm
	${INSTALL_DATA} ${WRKSRC}/../doc/swarm.pdf ${PREFIX}/share/doc/swarm

.include "../../mk/bsd.pkg.mk"
