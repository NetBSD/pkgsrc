# $NetBSD: Makefile,v 1.9 2003/07/17 21:35:56 grant Exp $
#

DISTNAME=	swarm-0.57
WRKSRC=		${WRKDIR}/swarm/src
CATEGORIES=	emulators
MASTER_SITES=	http://www.dcs.gla.ac.uk/~michael/phd/bin/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.dcs.gla.ac.uk/~michael/phd/swarm.html
COMMENT=	Software arm6 core emulator

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/swarm ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/swarm
	${INSTALL_DATA} ${WRKSRC}/../doc/swarm.pdf ${PREFIX}/share/doc/swarm

.include "../../mk/bsd.pkg.mk"
