# $NetBSD: Makefile,v 1.36 2025/09/24 12:06:24 adam Exp $

DISTNAME=	abseil-20250814.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=abseil/}
GITHUB_PROJECT=	abseil-cpp
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/abseil/abseil-cpp
COMMENT=	C++ Common Libraries
LICENSE=	apache-2.0

USE_LANGUAGES=		c++
USE_CXX_FEATURES=	c++17
FORCE_CXX_STD=		c++17
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
.  if exists(${OSX_SDK_PATH}/usr/include/execinfo.h)
BUILDLINK_TRANSFORM+=	rm:-lexecinfo
.  endif
.endif

PKGCONFIG_OVERRIDE_STAGE=	post-build
PKGCONFIG_OVERRIDE=		${CMAKE_BUILD_DIR}/lib/pkgconfig/*.pc

.include "../../devel/cmake/build.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
