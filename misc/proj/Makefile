# $NetBSD: Makefile,v 1.20 2006/12/10 01:27:55 gdt Exp $

DISTNAME=		proj-4.5.0
CATEGORIES=		misc geography
MASTER_SITES=		ftp://ftp.remotesensing.org/pub/proj/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} proj-nad27-1.2.tar.gz

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://www.remotesensing.org/proj/
COMMENT=		Cartographic projection software

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes

NAD27_FILES=FL.lla MD.lla README.NADUS TN.lla WI.lla WO.lla alaska.lla	\
	conus.lla hawaii.lla ntv1_can.dat prvi.lla stgeorge.lla		\
	stlrnc.lla stpaul.lla

post-extract:
	cd ${WRKDIR} &&	${LN} ${NAD27_FILES} ${WRKDIR}/${DISTNAME}/nad

.include "../../mk/bsd.pkg.mk"
