# $NetBSD: Makefile,v 1.6 2024/08/25 06:19:01 wiz Exp $

MAINTAINER=	thomas.orgis@uni-hamburg.de
COMMENT=	C interface to the reference LAPACK library

LAPACK_COMPONENT=	lapacke
LAPACK_COMPONENT_CMAKE_CONFIGURE_ARGS=	\
	-DUSE_OPTIMIZED_BLAS=ON \
	-DBLAS_LIBRARIES=-lblas \
	-DUSE_OPTIMIZED_LAPACK=ON \
	-DLAPACK_LIBRARIES=-llapack \
	-DCBLAS=OFF -DLAPACKE=ON

.include "../../math/lapack/buildlink3.mk"
BUILDLINK_API_DEPENDS.blas	+=	blas>=${PKGVERSION_NOREV}
BUILDLINK_API_DEPENDS.lapack	+=	lapack>=${PKGVERSION_NOREV}

.include "../../math/lapack/Makefile.common"
.include "../../mk/bsd.pkg.mk"
