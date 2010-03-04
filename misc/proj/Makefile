# $NetBSD: Makefile,v 1.28 2010/03/04 01:42:18 gdt Exp $

DISTNAME=	proj-4.7.0
CATEGORIES=	misc geography
MASTER_SITES=	http://download.osgeo.org/proj/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} proj-datumgrid-1.4${EXTRACT_SUFX}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://trac.osgeo.org/proj/
COMMENT=	Cartographic projection software

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

DATUMGRID_FILES= 							\
	FL.lla MD.lla README.NADUS TN.lla WI.lla WO.lla alaska.lla	\
	conus.lla hawaii.lla ntv1_can.dat null.lla nzgd2kgrid0005.gsb	\
	prvi.lla stgeorge.lla stlrnc.lla stpaul.lla

post-extract:
	cd ${WRKDIR} &&	${LN} ${DATUMGRID_FILES} ${WRKDIR}/${DISTNAME}/nad

.include "../../mk/bsd.pkg.mk"
