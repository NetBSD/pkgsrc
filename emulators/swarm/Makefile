# $NetBSD: Makefile,v 1.7 2002/02/06 16:58:14 jlam Exp $
#

DISTNAME=	swarm-0.57
CATEGORIES=	emulators
MASTER_SITES=	http://www.dcs.gla.ac.uk/~michael/phd/bin/

MAINTAINER=	agc@netbsd.org
HOMEPAGE=	http://www.dcs.gla.ac.uk/~michael/phd/swarm.html
COMMENT=	Software arm6 core emulator

WRKSRC=		${WRKDIR}/swarm/src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/swarm ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/swarm
	${INSTALL_DATA} ${WRKSRC}/../doc/swarm.pdf ${PREFIX}/share/doc/swarm

.include "../../mk/bsd.pkg.mk"
