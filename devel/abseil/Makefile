# $NetBSD: Makefile,v 1.40 2026/02/11 20:26:46 adam Exp $

DISTNAME=	abseil-20260107.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=abseil/}
GITHUB_PROJECT=	abseil-cpp
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/abseil/abseil-cpp
COMMENT=	C++ Common Libraries
LICENSE=	apache-2.0

USE_LANGUAGES=		c++
# Upstream documents "collection of C++ code (compliant to C++17)"
USE_CXX_FEATURES=	c++17
# Upstream's cmakery checks if c++20 is supported and if so enables
# additional features.  pkgsrc norms are to have packages build the
# same regardless of environment (other than the required environment
# which is forced by the pkgsrc build).  Thus, try to make the
# compiler be c++17 only, and not accept c++20.
FORCE_CXX_STD=		c++17
# gcc7 fails "expression '<lambda>' is not a constant expression"
GCC_REQD+=		10

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
