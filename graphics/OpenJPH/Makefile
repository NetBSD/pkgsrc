# $NetBSD: Makefile,v 1.11 2026/05/10 12:01:23 wiz Exp $

DISTNAME=	OpenJPH-0.27.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=aous72/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aous72/OpenJPH/
COMMENT=	Open-source implementation of JPEG2000 Part-15
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c c++

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
