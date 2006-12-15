# $NetBSD: Makefile,v 1.23 2006/12/15 18:15:00 dsainty Exp $

DISTNAME=		proj-4.5.0
PKGREVISION=		1
CATEGORIES=		misc geography
MASTER_SITES=		ftp://ftp.remotesensing.org/pub/proj/ \
			http://dl.maptools.org/dl/proj/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} proj-datumgrid-1.3${EXTRACT_SUFX}

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://www.remotesensing.org/proj/
COMMENT=		Cartographic projection software

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes

DATUMGRID_FILES= 							\
	FL.lla MD.lla README.NADUS TN.lla WI.lla WO.lla alaska.lla	\
	conus.lla hawaii.lla ntv1_can.dat null.lla nzgd2kgrid0005.gsb	\
	prvi.lla stgeorge.lla stlrnc.lla stpaul.lla

post-extract:
	cd ${WRKDIR} &&	${LN} ${DATUMGRID_FILES} ${WRKDIR}/${DISTNAME}/nad

.include "../../mk/bsd.pkg.mk"
