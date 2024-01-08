# $NetBSD: Makefile,v 1.46 2024/01/08 21:28:55 thor Exp $

MAINTAINER=	thomas.orgis@uni-hamburg.de
COMMENT=	Linear Algebra PACKage (Netlib reference implementation)

LAPACK_COMPONENT=	lapack
LAPACK_COMPONENT_CMAKE_ARGS= \
	-DUSE_OPTIMIZED_BLAS=ON \
	-DBLAS_LIBRARIES=-lblas \
	-DUSE_OPTIMIZED_LAPACK=OFF \
	-DCBLAS=OFF -DLAPACKE=OFF -DLAPACK=ON

# This always uses Netlib BLAS. Other optimized BLAS packages bring
# their own LAPACK, hence cblas and lapacke packages use
# mk/blas.buildlink3.mk instead.
.include "../../math/blas/buildlink3.mk"
# Always require the same current version of all netlib packages.
BUILDLINK_API_DEPENDS.blas +=	blas>=${PKGVERSION_NOREV}
.include "../../math/lapack/Makefile.common"
.include "../../mk/bsd.pkg.mk"
