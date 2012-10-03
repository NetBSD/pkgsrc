# $NetBSD: Makefile,v 1.16 2012/10/03 12:55:19 asau Exp $
#

DISTNAME=	swarm-0.61
CATEGORIES=	emulators
MASTER_SITES=	http://www.cl.cam.ac.uk/~mwd24/phd/bin/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.cl.cam.ac.uk/~mwd24/phd/swarm.html
COMMENT=	Software arm7M core emulator

WRKSRC=		${WRKDIR}/swarm
BUILD_DIRS=	src

USE_LANGUAGES=	c++

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/swarm ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/swarm
	${INSTALL_DATA} ${WRKSRC}/doc/swarm.pdf \
		${DESTDIR}${PREFIX}/share/doc/swarm

.include "../../mk/bsd.pkg.mk"
