# $NetBSD: Makefile,v 1.2 2024/08/25 06:18:22 wiz Exp $

DISTNAME=	dumb-2.0.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=kode54/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kode54/dumb
COMMENT=	Module/tracker based music format parser and player library
LICENSE=	zlib

USE_CMAKE=	yes

CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_CONFIGURE_ARGS+=	-DBUILD_ALLEGRO4=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_EXAMPLES=OFF

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} != "i386" && ${MACHINE_ARCH} != "amd64"
CMAKE_CONFIGURE_ARGS+=	-DUSE_SSE=OFF
.endif

PKGCONFIG_OVERRIDE+=	pkg-config.pc.in

.include "../../mk/bsd.pkg.mk"
