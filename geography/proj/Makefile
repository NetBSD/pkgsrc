# $NetBSD: Makefile,v 1.13 2019/02/20 17:33:59 gdt Exp $

VERSION_BASE=	5.2.0
VERSION_RC=	
VERSION=	${VERSION_BASE}${VERSION_RC}
PKGREVISION=	1
# proj RCs have names like 5.1.0RC1 but unpack to 5.1.0
WRKSRC=		${WRKDIR}/proj-${VERSION_BASE}
DISTNAME=	proj-${VERSION}
CATEGORIES=	geography
MASTER_SITES=	https://download.osgeo.org/proj/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		proj-datumgrid-1.8${EXTRACT_SUFX} \
		proj-datumgrid-north-america-1.1${EXTRACT_SUFX}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://proj4.org/
COMMENT=	Cartographic projection software

LICENSE=	mit

PREV_PKGPATH=		misc/proj

USE_LANGUAGES=		c99 c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

TEST_TARGET=		check

# \todo Ideally, the files would be unpacked directly in nad.
# The file lists are grouped in the same way as the datumgrid files
# appear in DISTFILES.
DATUMGRID_FILES= 							\
	BETA2007.gsb FL MD README.DATUMGRID TN WI WO alaska conus \
	egm96_15.gtx hawaii ntf_r93.gsb ntv1_can.dat null \
	nzgd2kgrid0005.gsb prvi stgeorge stlrnc stpaul \
	\
	vertconc.gtx vertconw.gtx gvr2016.gtx vertcone.gtx gvr2000.gtx \
	GL README.NORTHAMERICA

post-extract:
	cd ${WRKDIR} &&	${LN} ${DATUMGRID_FILES} ${WRKSRC}/nad

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
