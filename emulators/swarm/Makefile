# $NetBSD: Makefile,v 1.8 2003/03/29 12:40:51 jmmv Exp $
#

DISTNAME=	swarm-0.57
WRKSRC=		${WRKDIR}/swarm/src
CATEGORIES=	emulators
MASTER_SITES=	http://www.dcs.gla.ac.uk/~michael/phd/bin/

MAINTAINER=	agc@netbsd.org
HOMEPAGE=	http://www.dcs.gla.ac.uk/~michael/phd/swarm.html
COMMENT=	Software arm6 core emulator

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/swarm ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/swarm
	${INSTALL_DATA} ${WRKSRC}/../doc/swarm.pdf ${PREFIX}/share/doc/swarm

.include "../../mk/bsd.pkg.mk"
