# $NetBSD: Makefile,v 1.10 2003/08/14 09:31:39 agc Exp $
#

DISTNAME=	swarm-0.61
CATEGORIES=	emulators
MASTER_SITES=	http://www.dcs.gla.ac.uk/~michael/phd/bin/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.dcs.gla.ac.uk/~michael/phd/swarm.html
COMMENT=	Software arm7M core emulator

WRKSRC=		${WRKDIR}/swarm/src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/swarm ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/swarm
	${INSTALL_DATA} ${WRKSRC}/../doc/swarm.pdf ${PREFIX}/share/doc/swarm

.include "../../mk/bsd.pkg.mk"
