# $NetBSD: Makefile,v 1.47 2020/11/05 09:06:45 ryoon Exp $

DISTNAME=	mongo-c-driver-1.16.2
PKGREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=mongodb/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mongodb/mongo-c-driver
COMMENT=	MongoDB client library written in C
LICENSE=	apache-2.0

# Requires shm_open()
NOT_FOR_PLATFORM+=	OpenBSD-*-*

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
TEST_TARGET=	check

CMAKE_ARGS+=	-DENABLE_ICU=ON
#CMAKE_ARGS+=	-DENABLE_MAN_PAGES=ON
CMAKE_ARGS+=	-DENABLE_SNAPPY=SYSTEM
CMAKE_ARGS+=	-DENABLE_UNINSTALL=OFF
CMAKE_ARGS+=	-DENABLE_ZLIB=SYSTEM

PKGCONFIG_OVERRIDE+=	src/libbson/src/libbson-1.0.pc.in
PKGCONFIG_OVERRIDE+=	src/libbson/src/libbson-static-1.0.pc.in
PKGCONFIG_OVERRIDE+=	src/libmongoc/src/libmongoc-1.0.pc.in
PKGCONFIG_OVERRIDE+=	src/libmongoc/src/libmongoc-ssl-1.0.pc.in
PKGCONFIG_OVERRIDE+=	src/libmongoc/src/libmongoc-static-1.0.pc.in

INSTALLATION_DIRS+=	${PKGMANDIR}/man3

LDFLAGS.SunOS+=	-lsocket

PLIST_VARS+=	unix

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Darwin"
PLIST.unix=	yes
.endif

.include "options.mk"

post-install:
.for lib in libbson libmongoc
	${INSTALL_MAN} ${WRKSRC}/src/${lib}/doc/man/*.3 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man3
.endfor

.include "../../devel/snappy/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
