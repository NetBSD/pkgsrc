# $NetBSD: Makefile,v 1.56 2025/01/06 19:18:00 gdt Exp $

DISTNAME=	osm2pgsql-1.9.2
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=openstreetmap/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/openstreetmap/osm2pgsql/
COMMENT=	OpenStreetMap data to PostgreSQL converter
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++17

.include "../../devel/cmake/build.mk"

# Added without understanding, after a complaint of undefined.
CMAKE_CONFIGURE_ARGS+=	-DBoost_INCLUDE_DIR=${BUILDLINK_PREFIX.boost-headers}/include

REPLACE_PYTHON+=	scripts/osm2pgsql-replication

# To rebuid man page (which we don't), pandoc is required.

# Test dependencies.
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTS=ON
TEST_TARGET=	test
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
#   fmt
#   libosmium
#   protozero

# optional for generalization:
#   cimg
#   potrace

.include "../../mk/bsd.pkg.mk"
