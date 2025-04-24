# $NetBSD: Makefile,v 1.40 2025/04/24 14:14:08 wiz Exp $

VERSION=	1.7.4
#RC=		rc1
DISTNAME=	libgeotiff-${VERSION}${RC}
PKGREVISION=	3
CATEGORIES=	geography
MASTER_SITES=	https://download.osgeo.org/geotiff/libgeotiff/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/OSGeo/libgeotiff
COMMENT=	Library and tools for reading and writing GeoTIFF data
LICENSE=	mit

WRKSRC=		${WRKDIR}/libgeotiff-${VERSION}

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

TEST_TARGET=	check

# TODO: add options for zlib and jpeg support

.include "../../geography/proj/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
