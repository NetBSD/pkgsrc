# $NetBSD: Makefile,v 1.5 2024/08/25 06:18:28 wiz Exp $

DISTNAME=	leveldb-1.23
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	https://github.com/google/leveldb
COMMENT=	Fast and lightweight key/value database library by Google
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_LANGUAGES=	c c++11
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_CONFIGURE_ARGS+=	-DLEVELDB_BUILD_BENCHMARKS=OFF
CMAKE_CONFIGURE_ARGS+=	-DLEVELDB_BUILD_TESTS=OFF

CFLAGS+=	-fPIC

.include "../../devel/snappy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
