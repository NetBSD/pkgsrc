# $NetBSD: Makefile,v 1.6 2005/06/16 06:57:56 jlam Exp $
#

DISTNAME=		gpsutils-0.4.0
CATEGORIES=		geography
MASTER_SITES=		http://www.wombat.ie/gps/

MAINTAINER=		hdp@cs.nmsu.edu
HOMEPAGE=		http://www.wombat.ie/gps/
COMMENT=		Capture and convert data from a Garmin GPS receiver

WRKSRC=			${WRKDIR}/gpsutils-0.4.0/src
INSTALLATION_DIRS=	bin

do-install:
.for PROGRAM in capture switchmode gbindiff
	${INSTALL_PROGRAM} ${WRKSRC}/${PROGRAM} ${PREFIX}/bin
.endfor

.include "../../mk/bsd.pkg.mk"
