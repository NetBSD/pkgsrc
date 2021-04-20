# $NetBSD: Makefile,v 1.1 2021/04/20 20:40:47 thor Exp $

COMMENT=		C interface to a LAPACK library
LAPACK_COMPONENT=	lapacke
LAPACK_COMPONENT_CMAKE_ARGS=	\
	-DUSE_OPTIMIZED_BLAS=ON \
	-DBLAS_LIBRARIES=${BLAS_LIBS:Q} \
	-DUSE_OPTIMIZED_LAPACK=ON \
	-DLAPACK_LIBRARIES=${LAPACK_LIBS:Q} \
	-DCBLAS=OFF -DLAPACKE=ON

.include "../../mk/blas.buildlink3.mk"
.include "../../math/lapack/Makefile.common"
.include "../../mk/bsd.pkg.mk"
