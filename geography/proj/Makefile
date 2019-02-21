# $NetBSD: Makefile,v 1.16 2019/02/21 00:55:04 gdt Exp $

VERSION_BASE=	5.2.0
VERSION_RC=	
VERSION=	${VERSION_BASE}${VERSION_RC}
PKGREVISION=	3
# proj RCs have names like 5.1.0RC1 but unpack to 5.1.0
WRKFINAL=	proj-${VERSION_BASE}
WRKSRC=		${WRKDIR}/${WRKFINAL}
DISTNAME=	proj-${VERSION}
CATEGORIES=	geography
MASTER_SITES=	https://download.osgeo.org/proj/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		proj-datumgrid-1.8${EXTRACT_SUFX} \
		proj-datumgrid-europe-1.1${EXTRACT_SUFX} \
		proj-datumgrid-north-america-1.1${EXTRACT_SUFX} \
		proj-datumgrid-oceania-1.0${EXTRACT_SUFX}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://proj4.org/
COMMENT=	Cartographic projection software

# Grid files also have the following "cc-by ish" licenses:
# cc-by, 2-clause-bsd,  License Ouverte, cc0 (eu)
# open-government, cc-by, public-domain (na)
# cc-by (oceania)
LICENSE=	mit

PREV_PKGPATH=		misc/proj

USE_LANGUAGES=		c99 c++11
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

TEST_TARGET=		check

# \todo Ideally, the files would be unpacked directly in nad.
# Assume that all of the stray files in ${WRKDIR} came from datumgrids.
post-extract:
	cd ${WRKDIR} &&	for f in *; do if [ $$f != ${WRKFINAL} ]; then mv $$f ${WRKFINAL}/nad; fi; done

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
