# $NetBSD: Makefile,v 1.8 2019/04/08 19:46:45 gdt Exp $

# Upgrade to 1.5.1 is on hold because it requires proj 6
#DISTNAME=	libgeotiff-1.5.1
DISTNAME=	libgeotiff-1.4.3
CATEGORIES=	graphics
MASTER_SITES=	https://download.osgeo.org/geotiff/libgeotiff/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://trac.osgeo.org/geotiff/
COMMENT=	Library and tools for reading and writing GeoTIFF data
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

# TODO: add options for zlib and jpeg support

.include "../../geography/proj/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
