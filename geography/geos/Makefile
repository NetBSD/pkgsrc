# $NetBSD: Makefile,v 1.34 2019/10/08 23:42:55 gdt Exp $

DISTNAME=	geos-3.7.3
CATEGORIES=	geography
MASTER_SITES=	http://download.osgeo.org/geos/
EXTRACT_SUFX=	.tar.bz2

# geos has two libraries:
#   geos_c (C), which follows normal versioning rules
#   geos (C++), which uses -release, and changes on every release

# According to the geos project (as documented in README), the C++
# interface should not be directly used and other packages should not
# link against it.  Therefore, in theory pkgsrc would perform a
# recursive revbump when the libgeos_c.so version changes, and would
# generally ignore libgeos.so shlib name changes.
#
# However, libtool explicitly adds dependency_libs, so packages that
# intend to only depend on the C library end up being linked directly
# to the C++ library also.  Thus, they need revbumping because of
# libtools {bug or feature}.
#
# Packages that need revbumping because of libtool's behavior:
#   geography/gdal-lib
#   geography/py-gdal
#   databases/postgresql-postgis2
# Packages that need revbumping because of direct use of the C++ lib:
#   (none known)

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://trac.osgeo.org/geos
COMMENT=	C++ port of the Java Topology Suite (JTS)
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++11
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
