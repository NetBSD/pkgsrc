# $NetBSD: Makefile,v 1.55 2025/01/05 14:14:13 gdt Exp $

DISTNAME=	osm2pgsql-1.3.0
PKGREVISION=	24
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=openstreetmap/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	wiedi@frubar.net
HOMEPAGE=	https://github.com/openstreetmap/osm2pgsql/
COMMENT=	OpenStreetMap data to PostgreSQL converter
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

.include "../../devel/cmake/build.mk"

# Test dependencies.
USE_TOOLS+=	python
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTS=ON
TEST_TARGET=	test

.include "../../geography/proj/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
# Per README, not needed, as python is for running tests, but
# without it cmake finds 2.7 and errors out.
.include "../../lang/python/application.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
