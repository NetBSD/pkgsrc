# $NetBSD: Makefile,v 1.15 2026/08/12 03:51:56 ryoon Exp $

DISTNAME=	duckdb-1.5.5
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=duckdb/}
GITHUB_PROJECT=	duckdb
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://duckdb.org/
COMMENT=	In-process SQL OLAP database management system
LICENSE=	mit

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

# for alloca(3)
FORCE_CXX_STD+=	gnu++11

CMAKE_CONFIGURE_ARGS+=	-DBUILD_EXTENSIONS='autocomplete;core_functions;icu;json;parquet;tpcds;tpch'
CMAKE_CONFIGURE_ARGS+=	-DBUILD_BENCHMARKS=ON
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TPCE=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_INTERNAL_ICU=True
CMAKE_CONFIGURE_ARGS+=	-DDUCKDB_EXPLICIT_VERSION=${PKGVERSION_NOREV}

.include "../../devel/cmake/build.mk"
.include "../../security/openssl/buildlink3.mk"
#.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
