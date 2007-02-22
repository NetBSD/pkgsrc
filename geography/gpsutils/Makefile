# $NetBSD: Makefile,v 1.8 2007/02/22 19:01:19 wiz Exp $
#

DISTNAME=		gpsutils-0.4.0
CATEGORIES=		geography
MASTER_SITES=		http://wombat.ie/gps/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://wombat.ie/gps/
COMMENT=		Capture and convert data from a Garmin GPS receiver

WRKSRC=			${WRKDIR}/gpsutils-0.4.0/src
INSTALLATION_DIRS=	bin

do-install:
.for f in capture switchmode gbindiff
	${INSTALL_PROGRAM} ${WRKSRC}/${f:Q} ${PREFIX}/bin
.endfor

.include "../../mk/bsd.pkg.mk"
