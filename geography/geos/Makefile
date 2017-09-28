# $NetBSD: Makefile,v 1.30 2017/09/28 00:24:41 gdt Exp $

DISTNAME=	geos-3.6.2
CATEGORIES=	geography
MASTER_SITES=	http://download.osgeo.org/geos/
EXTRACT_SUFX=	.tar.bz2

# geos has two libraries:
#   geos_c (C), which follows normal versioning rules
#   geos (C++), which uses -release, and changes on every release

# According to the geos project (as documented in README), the C++
# interface should not be directly used and other packages should not
# link against it.  Therefore, pkgsrc will perform a recursive revbump
# when the geos_c shlib version changes, and will generally ignore
# geos shlib name changes.  However, people on the geos list dispute
# this characterization.

# The following packages either incorrectly (from the geos README
# viewpoint) or suboptimally (from some comments on the list) link
# directly against -lgeos and should be revbumped on every update (and
# perhaps fixed not to use -lgeos):
#   geography/gdal-lib
#   geoggraph/osm2pgsql
#     https://github.com/openstreetmap/osm2pgsql/issues/634

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://trac.osgeo.org/geos
COMMENT=	C++ port of the Java Topology Suite (JTS)
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
