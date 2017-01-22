# $NetBSD: Makefile,v 1.29 2017/01/22 23:44:47 gdt Exp $

# Do not update to 3.6, because there is serious ABI breakage which
# prevents osm2pgsql from working, and may well cause other programs
# to have issues.  osm2pgsql plans to stop using geos, and it seems
# better to have slightly old geos in pkgsrc then to have a bunch of
# broken other programs.  Please email me if you have a problem with
# this.  -- gdt, 20170122
DISTNAME=	geos-3.5.1
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

# The following packages either incorrectly (from the geos
# READMEviewpoint) or suboptimally (from some comments ont he list)
# link directly against -lgeos and should be revbumped on every update
# (and perhaps fixed not to use -lgeos):
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
