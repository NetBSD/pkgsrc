# $NetBSD: Makefile,v 1.9 2025/05/20 16:03:33 ryoon Exp $

DISTNAME=	duckdb-1.2.2
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

CMAKE_CONFIGURE_ARGS+=	-DBUILD_EXTENSIONS='autocomplete;core_functions;icu;jemalloc;json;parquet;tpcds;tpch'
CMAKE_CONFIGURE_ARGS+=	-DBUILD_BENCHMARKS=ON
CMAKE_CONFIGURE_ARGS+=	-DBUILD_TPCE=ON

.include "../../devel/cmake/build.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
