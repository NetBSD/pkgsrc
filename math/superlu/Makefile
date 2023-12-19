# $NetBSD: Makefile,v 1.34 2023/12/19 10:34:09 thor Exp $

DISTNAME=		superlu-6.0.1
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_GITHUB:=xiaoyeli/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://portal.nersc.gov/project/sparse/superlu/
COMMENT=		Library for solving large, sparse, nonsymmetric systems of linear equations

USE_CMAKE=		yes
USE_LANGUAGES=		c fortran
TEST_TARGET=		test

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON
# Does not use C interface, also somehow has broken FindBLAS usage.
CMAKE_ARGS+=	-DTPL_ENABLE_INTERNAL_BLASLIB=OFF
CMAKE_ARGS+=	-DTPL_BLAS_LIBRARIES=${BLAS_LIBS:Q}
# Keeping those here. In future, that should work and replace the
# above. Need upstream bug report.
#CMAKE_ARGS+=	-DBLA_PREFER_PKGCONFIG=ON
#CMAKE_ARGS+=	-DBLA_PKGCONFIG_BLAS=${BLAS_PC}

.include "../../mk/blas.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
