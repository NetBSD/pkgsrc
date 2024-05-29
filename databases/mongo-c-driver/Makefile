# $NetBSD: Makefile,v 1.66 2024/05/29 16:31:43 adam Exp $

DISTNAME=	mongo-c-driver-1.26.0
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=mongodb/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mongodb/mongo-c-driver
COMMENT=	MongoDB client library written in C
LICENSE=	apache-2.0

# Requires shm_open()
NOT_FOR_PLATFORM+=	OpenBSD-*-*

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
TEST_TARGET=	check

# u_int for sys/sysctl.h
CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

# Set version here, so Python and Git are not needed.
CMAKE_ARGS+=	-DBUILD_VERSION=${PKGVERSION_NOREV}
CMAKE_ARGS+=	-DENABLE_ICU=ON
CMAKE_ARGS+=	-DENABLE_SNAPPY=ON
CMAKE_ARGS+=	-DENABLE_UNINSTALL=OFF
CMAKE_ARGS+=	-DENABLE_ZLIB=SYSTEM
CMAKE_ARGS+=	-DENABLE_ZSTD=ON
CMAKE_ARGS+=	-DENABLE_SHM_COUNTERS=OFF # ON is only supported on Linux or ARM Darwin
CMAKE_ARGS+=	-DMONGO_USE_CCACHE=OFF

PKGCONFIG_OVERRIDE+=	src/libbson/src/libbson-1.0.pc.in
PKGCONFIG_OVERRIDE+=	src/libbson/src/libbson-static-1.0.pc.in
PKGCONFIG_OVERRIDE+=	src/libmongoc/src/libmongoc-1.0.pc.in
PKGCONFIG_OVERRIDE+=	src/libmongoc/src/libmongoc-ssl-1.0.pc.in
PKGCONFIG_OVERRIDE+=	src/libmongoc/src/libmongoc-static-1.0.pc.in

INSTALLATION_DIRS+=	${PKGMANDIR}/man3

LDFLAGS.SunOS+=			-lsocket
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=${WRKSRC}/src/libmongoc/../../build/cmake/libmongoc-hidden-symbols.map

.include "options.mk"

.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/snappy/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
