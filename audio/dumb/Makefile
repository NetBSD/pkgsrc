# $NetBSD: Makefile,v 1.4 2026/03/23 13:08:18 nia Exp $

DISTNAME=	dumb-2.0.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=kode54/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kode54/dumb
COMMENT=	Module/tracker based music format parser and player library
LICENSE=	zlib

USE_CMAKE=	yes

CFLAGS.SunOS+=	-Dalloca=__builtin_alloca

CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_CONFIGURE_ARGS+=	-DBUILD_ALLEGRO4=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_EXAMPLES=OFF
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} != "i386" && ${MACHINE_ARCH} != "amd64"
CMAKE_CONFIGURE_ARGS+=	-DUSE_SSE=OFF
.endif

PKGCONFIG_OVERRIDE+=	pkg-config.pc.in

.include "../../mk/bsd.pkg.mk"
