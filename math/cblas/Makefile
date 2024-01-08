# $NetBSD: Makefile,v 1.5 2024/01/08 21:28:57 thor Exp $

MAINTAINER=	thomas.orgis@uni-hamburg.de
COMMENT=	C interface to the reference BLAS library

LAPACK_COMPONENT=	cblas
LAPACK_COMPONENT_CMAKE_ARGS=	\
	-DUSE_OPTIMIZED_BLAS=ON \
	-DBLAS_LIBRARIES=-lblas \
	-DCBLAS=ON -DLAPACKE=OFF -DLAPACK=OFF \
	-DCMAKE_VERBOSE=ON

.include "../../math/blas/buildlink3.mk"
BUILDLINK_API_DEPENDS.blas +=	blas>=${PKGVERSION_NOREV}

.include "../../math/lapack/Makefile.common"
.include "../../mk/bsd.pkg.mk"
