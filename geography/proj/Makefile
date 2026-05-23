# $NetBSD: Makefile,v 1.69 2026/05/23 14:01:31 gdt Exp $

# Note that 9.8.0 caused problems with ETRF due to the EPSG database
# adding an ensemble, and this release reverts the EPSG database
# upgrade.
VERSION_BASE=	9.8.1
# Accommodate testing RCs (names like 9.0RC1, unpacking to 9.0).
#VERSION_RC=	RC1
VERSION=	${VERSION_BASE}${VERSION_RC}
WRKFINAL=	proj-${VERSION_BASE}
WRKSRC=		${WRKDIR}/${WRKFINAL}
DISTNAME=	proj-${VERSION}
#PKGREVISION=	0
PKGREVISION=	1
CATEGORIES=	geography
MASTER_SITES=	https://download.osgeo.org/proj/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://proj.org/
COMMENT=	Cartographic projection software
LICENSE=	mit

.include "../../mk/bsd.prefs.mk"

PREV_PKGPATH=		misc/proj

USE_LANGUAGES=		c c++
USE_CC_FEATURES=	c99
USE_CXX_FEATURES=	c++17

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config

TOOL_DEPENDS+=		sqlite3>=3.10.0:../../databases/sqlite3

CMAKE_CONFIGURE_ARGS+=	-DNLOHMANN_JSON_ORIGIN=EXTERNAL

# This define does two unrelated things.  One is to not use the
# network when running tests; that aligns with pkgsrc norms, but could
# be useful to enable as proj's use of the network is part of intended
# functionality.   The second is to avoid downloading code at build time.
# \todo Address with upstream.
CMAKE_CONFIGURE_ARGS+=	-DRUN_NETWORK_DEPENDENT_TESTS=OFF
# Probably default, but hang back until everyone else deals with the
# difficulties.
CMAKE_CONFIGURE_ARGS+=	-DEMBED_RESOURCE_FILES=OFF

.include "../../devel/cmake/build.mk"

# \todo Document, file upstream, and add uptream bug report URL.
CXXFLAGS.SunOS+=	-fpermissive

# proj has tests that rely on precise IEEE754 double results, and fail
# if run on i386 and allowing extended precision.  Take this as a clue
# that proj really wants exactly IEEE754, and instruct the compiler.
# Guess that this is true for i386 in general, not just NetBSD.
# Note that "-fexcess-precision=standard" fails with a complaint of not
# being supported in c++; this doesn't make sense, but use float-store
# to avoid having to figure it out.
.include "../../mk/bsd.prefs.mk"
.if ${MACHINE_ARCH} == "i386"
CFLAGS+=		-ffloat-store
.endif

# Remove outdated vendored code to guard against use.
# On hold pending upstream fixes to using outdated code when it should
# not be used!
#   https://github.com/OSGeo/PROJ/issues/4781
#   https://github.com/OSGeo/PROJ/pull/4782
pre-build-notyet:
	${RM} -f ${WRKSRC}/include/proj/internal/vendor/nlohmann/json.hpp

PLIST_SUBST+=		VERSION=${VERSION_BASE}
PRINT_PLIST_AWK+=	{ gsub(/${VERSION_BASE}/, "$${VERSION}") }

# Tests are enabled by default at build time.  They must be left on so
# that running them later works.
TEST_TARGET=		test
# Tests fail on NetBSD 9 earmv7hf-el, but this is apparently a bug in
# GNU ld < 2.33:
#   https://sourceware.org/git/?p=binutils-gdb.git;a=commit;h=baf46cd78048e1b959462567556e1de1ef6b9039

# Dependencies are documented in docs/source/install.rst but do not appear in releases.
#   https://github.com/OSGeo/PROJ/issues/4783

# Build dependencies:
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../textproc/nlohmann-json/buildlink3.mk"
# Upstream does not require pthreads or document it, but spelunking
# shows that there are hooks to make threaded sqlite3 work better if
# proj is built threaded.  In 2026, pthreads are normal, so just use
# them.
.include "../../mk/pthread.buildlink3.mk"

# Test dependencies:
# Arugably these could be build deps only.
.include "../../devel/googletest/buildlink3.mk"
# \todo python >= 3.8 (we ignore 3.7 and importlib_metadata because
# pkgsrc has only >= 3.10)
# \todo py-yaml or py-ruamel
# \todo py-test is looked for but is not documented

.include "../../mk/bsd.pkg.mk"
