# $NetBSD: Makefile,v 1.2 2024/01/08 21:28:57 thor Exp $

MAINTAINER=	thomas.orgis@uni-hamburg.de
COMMENT=	C interface to the reference BLAS with 64 bit indices

LAPACK_COMPONENT=	cblas64
LAPACK_COMPONENT_CMAKE_ARGS=	\
	-DBUILD_INDEX64=ON \
	-DUSE_OPTIMIZED_BLAS=ON \
	-DBLAS_LIBRARIES=-lblas64 \
	-DCBLAS=ON -DLAPACKE=OFF -DLAPACK=OFF \
	-DCMAKE_VERBOSE=ON

.include "../../math/blas64/buildlink3.mk"
BUILDLINK_API_DEPENDS.blas64	+=	blas64>=${PKGVERSION_NOREV}

.include "../../math/lapack/Makefile.common"
.include "../../mk/bsd.pkg.mk"
