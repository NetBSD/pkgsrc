# $NetBSD: Makefile,v 1.35 2023/12/19 11:53:01 thor Exp $

DISTNAME=		superlu-6.0.1
PKGREVISION=		1
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_GITHUB:=xiaoyeli/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://portal.nersc.gov/project/sparse/superlu/
COMMENT=		Library for solving large, sparse, nonsymmetric systems of linear equations

USE_TOOLS=		cmake pkg-config
USE_CMAKE=		yes
USE_LANGUAGES=		c fortran
TEST_TARGET=		test

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON
CMAKE_ARGS+=	-DTPL_ENABLE_INTERNAL_BLASLIB=OFF
CMAKE_ARGS+=	-DBLA_PREFER_PKGCONFIG=ON
CMAKE_ARGS+=	-DBLA_PKGCONFIG_BLAS=${BLAS_PC}

.include "../../mk/blas.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
