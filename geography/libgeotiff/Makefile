# $NetBSD: Makefile,v 1.35 2024/11/01 12:52:46 wiz Exp $

VERSION=	1.7.3
DISTNAME=	libgeotiff-${VERSION}${RC}
PKGREVISION=	4
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
