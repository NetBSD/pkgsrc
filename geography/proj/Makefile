# $NetBSD: Makefile,v 1.8 2018/03/02 00:53:24 gdt Exp $

VERSION_BASE=	5.0.0
VERSION=	${VERSION_BASE}
WRKSRC=		${WRKDIR}/proj-${VERSION_BASE}
DISTNAME=	proj-${VERSION}
CATEGORIES=	geography
MASTER_SITES=	https://download.osgeo.org/proj/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} proj-datumgrid-1.7${EXTRACT_SUFX}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://proj4.org/
COMMENT=	Cartographic projection software

LICENSE=	mit

PREV_PKGPATH=		misc/proj

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

TEST_TARGET=		check

# \todo Ideally, the files would be unpacked directly in nad.
DATUMGRID_FILES= 							\
	BETA2007.gsb FL MD README.DATUMGRID TN WI WO alaska conus \
	egm96_15.gtx hawaii ntf_r93.gsb ntv1_can.dat null \
	nzgd2kgrid0005.gsb prvi stgeorge stlrnc stpaul

post-extract:
	cd ${WRKDIR} &&	${LN} ${DATUMGRID_FILES} ${WRKSRC}/nad

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
