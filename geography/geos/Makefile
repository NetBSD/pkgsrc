# $NetBSD: Makefile,v 1.50 2024/06/05 22:33:56 gdt Exp $

VERSION_BASE=	3.12.2
# Accomodate testing unreleased versions.
#VERSION_RC=	beta2
VERSION=	${VERSION_BASE}${VERSION_RC}
DISTNAME=	geos-${VERSION}
EXTRACT_SUFX=	.tar.bz2
CATEGORIES=	geography
MASTER_SITES=	http://download.osgeo.org/geos/

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
# Packages that need revbumping because of direct use of the C++ lib:
#   (none known)

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://trac.osgeo.org/geos
COMMENT=	C++ port of the Java Topology Suite (JTS)
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++

USE_CXX_FEATURES+=	c++14

USE_CMAKE=		yes
#PKG_DEBUG_LEVEL?=	1
# cmake hides what it is doing; ask it to be like traditional builds.
MAKE_FLAGS+=		VERBOSE=1

# Note that the new geos cmake build system is broken and misorders
# RPATH for tests, leading to testing the installed geos instead of
# the built geos.  Reported upstream via email 202110, and probably
# it's a cmake bug.
TEST_TARGET=		check
# pthreads are used in tests only, to validate that the thread-safe
# API to geos, which is not threaded, works.  In that API, callers
# provide context so that the library does not use internal state.
# For now, leave it out on the theory that it's found anyway,
# optimizing for the package not the tests.
#.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
