# $NetBSD: Makefile,v 1.15 2026/06/23 09:35:24 wiz Exp $
#
# Note: every non-micro update currently incurs a recursive bump
# https://github.com/aous72/OpenJPH/issues/304

DISTNAME=	OpenJPH-0.30.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=aous72/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aous72/OpenJPH/
COMMENT=	Open-source implementation of JPEG2000 Part-15
LICENSE=	2-clause-bsd

USE_CC_FEATURES=	c11
USE_CXX_FEATURES=	c++14
USE_LANGUAGES=		c c++

PKGCONFIG_OVERRIDE+=		${CMAKE_BUILD_DIR}/openjph.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

.include "../../mk/bsd.prefs.mk"
.if ${MACHINE_ARCH} != "x86_64"
CMAKE_CONFIGURE_ARGS+=	-DOJPH_DISABLE_INTEL_SIMD=ON
CMAKE_CONFIGURE_ARGS+=	-DOJPH_ENABLE_INTEL_AVX512=OFF
.endif

.include "../../devel/cmake/build.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
