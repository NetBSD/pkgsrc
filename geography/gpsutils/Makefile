# $NetBSD: Makefile,v 1.1.1.1 2003/10/04 20:57:47 jschauma Exp $
#

DISTNAME=		gpsutils-0.4.0
WRKSRC=			${WRKDIR}/gpsutils-0.4.0/src
CATEGORIES=		gis
MASTER_SITES=		http://www.wombat.ie/gps/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://www.wombat.ie/gps/
COMMENT=		Capture and convert data from a Garmin GPS receiver

USE_BUILDLINK2=		yes

do-install:
.for PROGRAM in capture switchmode gbindiff
	${INSTALL_PROGRAM} ${WRKSRC}/${PROGRAM} ${PREFIX}/bin
.endfor

.include "../../mk/bsd.pkg.mk"
