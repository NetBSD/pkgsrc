# $NetBSD: Makefile,v 1.62 2023/10/24 22:08:28 wiz Exp $

DISTNAME=	mongo-c-driver-1.24.4
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=mongodb/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

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

CMAKE_ARGS+=	-DENABLE_ICU=ON
CMAKE_ARGS+=	-DENABLE_SNAPPY=ON
CMAKE_ARGS+=	-DENABLE_UNINSTALL=OFF
CMAKE_ARGS+=	-DENABLE_ZLIB=SYSTEM
CMAKE_ARGS+=	-DENABLE_ZSTD=ON
CMAKE_ARGS+=	-DENABLE_SHM_COUNTERS=OFF # ON is only supported on Linux or ARM Darwin

PKGCONFIG_OVERRIDE+=	src/libbson/src/libbson-1.0.pc.in
PKGCONFIG_OVERRIDE+=	src/libbson/src/libbson-static-1.0.pc.in
PKGCONFIG_OVERRIDE+=	src/libmongoc/src/libmongoc-1.0.pc.in
PKGCONFIG_OVERRIDE+=	src/libmongoc/src/libmongoc-ssl-1.0.pc.in
PKGCONFIG_OVERRIDE+=	src/libmongoc/src/libmongoc-static-1.0.pc.in

INSTALLATION_DIRS+=	${PKGMANDIR}/man3

LDFLAGS.SunOS+=			-lsocket
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=${WRKSRC}/src/libmongoc/../../build/cmake/libmongoc-hidden-symbols.map

.include "options.mk"

post-install:
.for lib in libbson libmongoc
	${INSTALL_MAN} ${WRKSRC}/src/${lib}/doc/man/*.3 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man3
.endfor

.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/snappy/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
