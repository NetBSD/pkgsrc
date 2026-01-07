# $NetBSD: Makefile,v 1.11 2026/01/07 08:46:08 wiz Exp $

PKGREVISION= 1
.include "../../databases/duckdb/Makefile.common"

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://duckdb.org/
COMMENT=	In-process SQL OLAP database management system
LICENSE=	mit

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

# for alloca(3)
FORCE_CXX_STD+=	gnu++11

CMAKE_CONFIGURE_ARGS+=	-DBUILD_EXTENSIONS='autocomplete;core_functions;icu;jemalloc;json;parquet;tpcds;tpch'
CMAKE_CONFIGURE_ARGS+=	-DBUILD_BENCHMARKS=ON
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TPCE=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_INTERNAL_ICU=True
CMAKE_CONFIGURE_ARGS+=	-DDUCKDB_EXPLICIT_VERSION=${PKGVERSION_NOREV}

.include "../../devel/cmake/build.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
