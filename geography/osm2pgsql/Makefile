# $NetBSD: Makefile,v 1.66 2025/10/05 19:26:00 js Exp $

DISTNAME=	osm2pgsql-1.11.0
PKGREVISION=	6
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=openstreetmap/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/openstreetmap/osm2pgsql/
COMMENT=	OpenStreetMap data to PostgreSQL converter
LICENSE=	gnu-gpl-v2

# Upstream checks for 64-bit:
# Make Error at CMakeLists.txt:20 (message):
#    osm2pgsql needs a 64 bit architecture
# Surely this is because the primary use of this package is loading
# the entire OpenStreetMap database, which can't fit in 4 GB, but it
# needlessly prevents use on 32-bit machines with smaller extracts.
BROKEN_ON_PLATFORM=	${LP32PLATFORMS}

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++

.include "../../devel/cmake/build.mk"

# Added without understanding, after a complaint of undefined.
CMAKE_CONFIGURE_ARGS+=	-DBoost_INCLUDE_DIR=${BUILDLINK_PREFIX.boost-headers}/include

REPLACE_PYTHON+=	scripts/osm2pgsql-replication

# To rebuid man page (which we don't), pandoc is required.

# Test dependencies.
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTS=ON
TEST_TARGET=		test
# python, psycopg2

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/nlohmann-json/buildlink3.mk"

# vendored libs which could be provided:
#   CLI11
#   fmt
#   libosmium
#   protozero

# optional for generalization:
#   cimg
#   opencv
#   potrace

.include "../../mk/bsd.pkg.mk"
