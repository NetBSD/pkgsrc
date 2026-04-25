# $NetBSD: Makefile,v 1.66 2026/04/25 22:45:50 gdt Exp $

VERSION_BASE=	9.8.1
# Accommodate testing RCs (names like 9.0RC1, unpacking to 9.0).
#VERSION_RC=	RC1
VERSION=	${VERSION_BASE}${VERSION_RC}
WRKFINAL=	proj-${VERSION_BASE}
WRKSRC=		${WRKDIR}/${WRKFINAL}
DISTNAME=	proj-${VERSION}
#PKGREVISION=	0
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

CMAKE_CONFIGURE_ARGS+=	-DRUN_NETWORK_DEPENDENT_TESTS=OFF
# Probably default, but hang back until everyone else deals with the
# difficulties.
CMAKE_CONFIGURE_ARGS+=	-DEMBED_RESOURCE_FILES=OFF

.include "../../devel/cmake/build.mk"

# \todo GC this.  Not needed on
#   9.7.0RC1	NetBSD 10 amd64
#.if ${OPSYS} == "NetBSD"
#CFLAGS+=		-DHAVE_C99_MATH=0
#.endif

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

PLIST_SUBST+=		VERSION=${VERSION_BASE}
PRINT_PLIST_AWK+=	{ gsub(/${VERSION_BASE}/, "$${VERSION}") }

# Tests fail on NetBSD 9 earmv7hf-el, but this is apparently a bug in
# GNU ld < 2.33:
#   https://sourceware.org/git/?p=binutils-gdb.git;a=commit;h=baf46cd78048e1b959462567556e1de1ef6b9039

TEST_TARGET=		test

# Dependencies documented by upstream
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

# Dependencies not documented by upstream
#  reported 20240527
.include "../../devel/googletest/buildlink3.mk"
#  reported 20240527
.include "../../textproc/nlohmann-json/buildlink3.mk"
#  not yet reported
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
