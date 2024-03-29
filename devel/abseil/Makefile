# $NetBSD: Makefile,v 1.24 2024/02/14 21:45:28 adam Exp $

DISTNAME=	abseil-20240116.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=abseil/}
GITHUB_PROJECT=	abseil-cpp
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/abseil/abseil-cpp
COMMENT=	C++ Common Libraries
LICENSE=	apache-2.0

USE_CXX_FEATURES=	c++14
USE_LANGUAGES=		c++
FORCE_CXX_STD=		c++14
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON

# .buildlink/include/absl/base/policy_checks.h:57:2: error:
# #error "This package requires GCC 7 or higher."
GCC_REQD+=	7

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
