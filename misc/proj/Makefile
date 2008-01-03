# $NetBSD: Makefile,v 1.25 2008/01/03 13:37:04 gdt Exp $

DISTNAME=		proj-4.6.0
CATEGORIES=		misc geography
MASTER_SITES=		http://download.osgeo.org/proj/
#MASTER_SITES=		ftp://ftp.remotesensing.org/pub/proj/ \
#			http://dl.maptools.org/dl/proj/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} proj-datumgrid-1.3${EXTRACT_SUFX}

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://www.remotesensing.org/proj/
COMMENT=		Cartographic projection software

PKG_DESTDIR_SUPPORT=	user-destdir

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
