# $NetBSD: Makefile,v 1.3 2000/07/07 23:35:56 wiz Exp $

DISTNAME=	swarm-0.26
CATEGORIES=	emulators
MASTER_SITES=	http://www.dcs.gla.ac.uk/~michael/phd/bin/

MAINTAINER=	agc@netbsd.org
HOMEPAGE=	http://www.dcs.gla.ac.uk/~michael/phd/swarm.html

WRKSRC=		${WRKDIR}/swarm/src

do-install:
	${BSD_INSTALL_PROGRAM} ${WRKSRC}/swarm ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/swarm
	${BSD_INSTALL_DATA} ${WRKSRC}/../doc/swarm.pdf ${PREFIX}/share/doc/swarm

.include "../../mk/bsd.pkg.mk"
