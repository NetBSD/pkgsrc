# $NetBSD: Makefile,v 1.1 2025/04/10 16:47:52 nia Exp $

DISTNAME=	SDL3-3.2.10
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libsdl-org/}
GITHUB_PROJECT=	SDL
GITHUB_RELEASE=	release-${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://www.libsdl.org/
COMMENT=	Simple DirectMedia Layer - cross-platform multimedia library
LICENSE=	zlib

USE_TOOLS+=	pkg-config

# do not load dependencies with dlopen
CMAKE_CONFIGURE_ARGS+=	-DSDL_DEPS_SHARED=OFF

# potential future options, not supported currently
CMAKE_CONFIGURE_ARGS+=	-DSDL_IBUS=OFF
CMAKE_CONFIGURE_ARGS+=	-DSDL_PIPEWIRE=OFF
CMAKE_CONFIGURE_ARGS+=	-DSDL_SNDIO=OFF
CMAKE_CONFIGURE_ARGS+=	-DSDL_LIBUDEV=OFF
CMAKE_CONFIGURE_ARGS+=	-DSDL_LIBURING=OFF

.include "../../mk/oss.buildlink3.mk"

# use native driver on NetBSD
.if ${OSS_TYPE} != "none" && ${OPSYS} != "NetBSD"
CMAKE_CONFIGURE_ARGS+=	-DSDL_OSS=ON
.else
CMAKE_CONFIGURE_ARGS+=	-DSDL_OSS=OFF
.endif

.include "options.mk"
.include "../../devel/cmake/build.mk"
.include "../../converters/libiconv/buildlink3.mk"
PTHREAD_OPTS?=	require
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
