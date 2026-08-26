# $NetBSD: Makefile,v 1.4 2026/08/26 10:19:04 adam Exp $

DISTNAME=	clickhouse-cpp-2.6.2
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=ClickHouse/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ClickHouse/clickhouse-cpp
COMMENT=	C++ client for ClickHouse
LICENSE=	apache-2.0

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++

CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_OPENSSL=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_SYSTEM_ABSEIL=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_SYSTEM_LZ4=ON
CMAKE_CONFIGURE_ARGS+=	-DWITH_SYSTEM_ZSTD=ON

.include "../../archivers/lz4/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/abseil/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
