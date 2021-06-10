# $NetBSD: Makefile,v 1.2 2021/06/10 00:18:52 thor Exp $

COMMENT=	C interface to a LAPACK library
PKGREVISION=	1

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
