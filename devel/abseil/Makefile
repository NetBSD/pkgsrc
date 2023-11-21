# $NetBSD: Makefile,v 1.21 2023/11/21 17:57:18 nros Exp $

DISTNAME=	abseil-20230802.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=abseil/}
GITHUB_PROJECT=	abseil-cpp
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/abseil/abseil-cpp
COMMENT=	C++ Common Libraries
LICENSE=	apache-2.0

USE_CXX_FEATURES=	c++14
USE_LANGUAGES=		c++14
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

ABSLPC_DIR=			${WRKSRC}/${CMAKE_BUILD_DIR}/lib/pkgconfig
PKGCONFIG_OVERRIDE_STAGE=	post-build

.include "pkgconfig-overrides.mk"


# abseil installs a lot of pkg-config files so maintaining a list of
# pkgconfig overrides whould take a lot of time. Below is a target to
# ease this work.
# The target can be run when updating the package to update the list of
# pkgconfig files that need an override.
.PHONY: update-pkgconfig-overrides
update-pkgconfig-overrides: all
	${RUN} ${HEAD} -n 1 pkgconfig-overrides.mk > pkgconfig-overrides.mk.tmp
	${RUN} ${MV} pkgconfig-overrides.mk.tmp pkgconfig-overrides.mk
	${RUN} cd ${ABSLPC_DIR} && \
		${GREP} "\-l[ 	]*absl" * | ${SED} 's/:[ 	]*Libs:.*//g' | \
		${SED} 's,^,PKGCONFIG_OVERRIDE+=\	\$$\{ABSLPC_DIR\}/,g' \
		>> ${.CURDIR}/pkgconfig-overrides.mk


.include "../../devel/cmake/build.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
