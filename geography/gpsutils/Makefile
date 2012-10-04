# $NetBSD: Makefile,v 1.10 2012/10/04 09:19:18 asau Exp $
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
	${INSTALL_PROGRAM} ${WRKSRC}/${f:Q} ${DESTDIR}${PREFIX}/bin
.endfor

.include "../../mk/bsd.pkg.mk"
