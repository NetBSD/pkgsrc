# $NetBSD: Makefile,v 1.51 2024/09/08 00:51:56 gdt Exp $

VERSION_BASE=	3.13.0
# Accomodate testing unreleased versions.
VERSION_RC=
VERSION=	${VERSION_BASE}${VERSION_RC}
DISTNAME=	geos-${VERSION}
EXTRACT_SUFX=	.tar.bz2
CATEGORIES=	geography
MASTER_SITES=	http://download.osgeo.org/geos/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://libgeos.org/
COMMENT=	C++ port of the Java Topology Suite (JTS)
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++14

.include "../../devel/cmake/build.mk"
# cmake hides what it is doing; ask it to be like traditional builds.
MAKE_FLAGS+=		VERBOSE=1

# Note that the new geos cmake build system is broken and misorders
# RPATH for tests, leading to testing the installed geos instead of
# the built geos.  Reported upstream via email 202110, and probably
# it's a cmake bug.
TEST_TARGET=		test
# pthreads are used in tests only, to validate that the thread-safe
# API to geos, which is not threaded, works.  In that API, callers
# provide context so that the library does not use internal state.
# For now, leave it out on the theory that it's found anyway,
# optimizing for the package not the tests.
#.include "../../mk/pthread.buildlink3.mk"

# geos has two libraries:
#   geos_c (C), which follows normal versioning rules
#   geos (C++), which uses -release, and changes on every release

# According to the geos project (as documented in README), the C++
# interface should not be directly used and other packages should not
# link against it.  Therefore, in theory pkgsrc would perform a
# recursive revbump when the libgeos_c.so version changes, and no
# bumping is needed because the libgeos.so shlib version changes.
#
# As of 2024-09, the theory holds and no library is known to link
# against libgeos.
find_cxx_users:
	for p in /usr/pkg/bin/*; do g=`objdump -x $$p 2>/dev/null | egrep NEEDED | egrep geos`; if [ "$$g" != "" ]; then echo $$p $$g; fi; done
	find /usr/pkg/lib -type f | egrep /lib*.so | while read p; do g=`objdump -x $$p 2>/dev/null | egrep NEEDED | egrep geos`; if [ "$$g" != "" ]; then echo $$p $$g; fi; done
	find /usr/pkg/libexec -type f | while read p; do g=`objdump -x $$p 2>/dev/null | egrep NEEDED | egrep geos`; if [ "$$g" != "" ]; then echo $$p $$g; fi; done

.include "../../mk/bsd.pkg.mk"
