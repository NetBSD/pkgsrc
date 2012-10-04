# $NetBSD: Makefile,v 1.3 2012/10/04 09:19:20 asau Exp $

VERSION=	4.8.0
DISTNAME=	proj-${VERSION}
CATEGORIES=	geography
MASTER_SITES=	http://download.osgeo.org/proj/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} proj-datumgrid-1.5${EXTRACT_SUFX}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://trac.osgeo.org/proj/
COMMENT=	Cartographic projection software

LICENSE=	mit

PREV_PKGPATH=		misc/proj

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

TEST_TARGET=		check

# The last file is out of order to avoid reordering the whole list
# from datumgrid-1.4 to datumgrid-1.5
DATUMGRID_FILES= 							\
	FL.lla MD.lla README.NADUS TN.lla WI.lla WO.lla alaska.lla	\
	conus.lla hawaii.lla ntv1_can.dat null.lla nzgd2kgrid0005.gsb	\
	prvi.lla stgeorge.lla stlrnc.lla stpaul.lla ntf_r93.gsb

post-extract:
	cd ${WRKDIR} &&	${LN} ${DATUMGRID_FILES} ${WRKDIR}/${PKGNAME}/nad

.include "../../mk/bsd.pkg.mk"
