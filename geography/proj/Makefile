# $NetBSD: Makefile,v 1.52 2025/05/03 13:16:21 gdt Exp $

VERSION_BASE=	9.6.0
# Accommodate testing RCs (names like 9.0RC1, unpacking to 9.0).
#VERSION_RC=	RC1
VERSION=	${VERSION_BASE}${VERSION_RC}
WRKFINAL=	proj-${VERSION_BASE}
WRKSRC=		${WRKDIR}/${WRKFINAL}
DISTNAME=	proj-${VERSION}
PKGREVISION=	1
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
USE_CXX_FEATURES=	c++11

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config

TOOL_DEPENDS+=		sqlite3>=3.10.0:../../databases/sqlite3

CMAKE_CONFIGURE_ARGS+=	-DRUN_NETWORK_DEPENDENT_TESTS=OFF
# Probably default, but hang back until everyone else deals with the
# difficulties.
CMAKE_CONFIGURE_ARGS+=	-DEMBED_RESOURCE_FILES=OFF

.include "../../devel/cmake/build.mk"

# \todo GC this after resolving test issues.
#.if ${OPSYS} == "NetBSD"
#CFLAGS+=		-DHAVE_C99_MATH=0
#.endif

# \todo Document, file uprsteam, and add uptream bug report URL.
CXXFLAGS.SunOS+=	-fpermissive

# \todo Debug geodtest failure, after we are up to date.
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
