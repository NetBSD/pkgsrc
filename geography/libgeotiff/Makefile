# $NetBSD: Makefile,v 1.5 2015/03/14 18:46:12 gdt Exp $

DISTNAME=	libgeotiff-1.4.1
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://download.osgeo.org/geotiff/libgeotiff/

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
