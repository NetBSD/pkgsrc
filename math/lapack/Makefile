# $NetBSD: Makefile,v 1.47 2024/08/25 06:19:00 wiz Exp $

MAINTAINER=	thomas.orgis@uni-hamburg.de
COMMENT=	Linear Algebra PACKage (Netlib reference implementation)

LAPACK_COMPONENT=	lapack
LAPACK_COMPONENT_CMAKE_CONFIGURE_ARGS= \
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
