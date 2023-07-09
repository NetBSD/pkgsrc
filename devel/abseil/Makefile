# $NetBSD: Makefile,v 1.18 2023/07/09 08:16:47 nia Exp $

DISTNAME=	abseil-20230125.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=abseil/}
GITHUB_PROJECT=	abseil-cpp
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/abseil/abseil-cpp
COMMENT=	C++ Common Libraries
LICENSE=	apache-2.0

USE_LANGUAGES=	c++14
CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON

# .buildlink/include/absl/base/policy_checks.h:57:2: error:
# #error "This package requires GCC 7 or higher."
GCC_REQD+=	7

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
.  if exists(${OSX_SDK_PATH}/usr/include/execinfo.h)
BUILDLINK_TRANSFORM+=	rm:-lexecinfo
.  endif
.endif

.include "../../devel/cmake/build.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
