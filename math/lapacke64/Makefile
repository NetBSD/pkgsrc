# $NetBSD: Makefile,v 1.1 2021/06/15 04:41:52 thor Exp $

MAINTAINER=	thomas.orgis@uni-hamburg.de
COMMENT=	C interface to the reference LAPACK with 64 bit indices

LAPACK_COMPONENT=	lapacke64
LAPACK_COMPONENT_CMAKE_ARGS=	\
	-DBUILD_INDEX64=ON \
	-DUSE_OPTIMIZED_BLAS=ON \
	-DBLAS_LIBRARIES=-lblas64 \
	-DUSE_OPTIMIZED_LAPACK=ON \
	-DLAPACK_LIBRARIES=-llapack64 \
	-DCBLAS=OFF -DLAPACKE=ON

.include "../../math/lapack64/buildlink3.mk"

.include "../../math/lapack/Makefile.common"
.include "../../mk/bsd.pkg.mk"
