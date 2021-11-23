# $NetBSD: Makefile,v 1.4 2021/11/23 22:45:01 wiz Exp $

MAINTAINER=	thomas.orgis@uni-hamburg.de
COMMENT=	C interface to the reference BLAS library

LAPACK_COMPONENT=	cblas
LAPACK_COMPONENT_CMAKE_ARGS=	\
	-DUSE_OPTIMIZED_BLAS=ON \
	-DBLAS_LIBRARIES=-lblas \
	-DCBLAS=ON -DLAPACKE=OFF -DLAPACK=OFF \
	-DCMAKE_VERBOSE=ON

.include "../../math/blas/buildlink3.mk"

.include "../../math/lapack/Makefile.common"
.include "../../mk/bsd.pkg.mk"
