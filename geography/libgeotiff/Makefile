# $NetBSD: Makefile,v 1.10 2020/03/12 00:17:20 gdt Exp $

# Upgrade to 1.5.1 is on hold because it requires proj 6
DISTNAME=	libgeotiff-1.5.1
CATEGORIES=	graphics
MASTER_SITES=	https://download.osgeo.org/geotiff/libgeotiff/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/OSGeo/libgeotiff
COMMENT=	Library and tools for reading and writing GeoTIFF data
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

# TODO: add options for zlib and jpeg support

.include "../../geography/proj/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
