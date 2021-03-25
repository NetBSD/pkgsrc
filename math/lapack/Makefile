# $NetBSD: Makefile,v 1.42 2021/03/25 08:32:48 thor Exp $

MAINTAINER=	thomas.orgis@uni-hamburg.de
COMMENT=	Linear Algebra PACKage (Netlib reference implementation)
PKGREVISION=	2

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
.include "../../math/lapack/Makefile.common"
.include "../../mk/bsd.pkg.mk"
