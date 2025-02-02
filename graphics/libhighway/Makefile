# $NetBSD: Makefile,v 1.7 2025/02/02 15:48:17 wiz Exp $

DISTNAME=	highway-1.2.0
PKGNAME=	lib${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_PROJECT=	highway

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/highway/
COMMENT=	C++ library for SIMD
LICENSE=	apache-2.0

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
GCC_REQD+=	8 # -latomic and gcc 7 gives internal compiler error

CMAKE_CONFIGURE_ARGS+=	-DHWY_SYSTEM_GTEST:BOOL=TRUE
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=TRUE

PKGCONFIG_OVERRIDE+=	libhwy-contrib.pc.in
PKGCONFIG_OVERRIDE+=	libhwy-test.pc.in
PKGCONFIG_OVERRIDE+=	libhwy.pc.in

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=${WRKSRC}/hwy/hwy.version

# libhighway run executables during build and
# they need to find its own shared libs
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}
TEST_TARGET=	test

.include "../../devel/cmake/build.mk"
.include "options.mk"
.include "../../devel/libatomic/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
