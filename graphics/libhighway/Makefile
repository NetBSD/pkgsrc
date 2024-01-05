# $NetBSD: Makefile,v 1.5 2024/01/05 11:09:53 nros Exp $

DISTNAME=	highway-1.0.7
PKGNAME=	lib${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_PROJECT=	highway

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/highway/
COMMENT=	C++ library for SIMD
LICENSE=	apache-2.0

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
GCC_REQD+=	8 # -latomic and gcc 7 gives internal compiler error

CMAKE_ARGS+=	-DHWY_SYSTEM_GTEST:BOOL=TRUE
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=TRUE

PKGCONFIG_OVERRIDE+=	libhwy-contrib.pc.in
PKGCONFIG_OVERRIDE+=	libhwy-test.pc.in
PKGCONFIG_OVERRIDE+=	libhwy.pc.in

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script=${WRKSRC}/hwy/hwy.version

# libhighway run executables during build and
# they need to find its own shared libs
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}
TEST_TARGET=	test

.include "options.mk"
.include "../../devel/libatomic/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
