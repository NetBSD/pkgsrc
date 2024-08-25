# $NetBSD: Makefile,v 1.3 2024/08/25 06:19:00 wiz Exp $

MAINTAINER=	thomas.orgis@uni-hamburg.de
COMMENT=	Reference Linear Algebra PACKage with 64 bit indices

LAPACK_COMPONENT=	lapack64
LAPACK_COMPONENT_CMAKE_CONFIGURE_ARGS= \
	-DBUILD_INDEX64=ON \
	-DUSE_OPTIMIZED_BLAS=ON \
	-DBLAS_LIBRARIES=-lblas64 \
	-DUSE_OPTIMIZED_LAPACK=OFF \
	-DCBLAS=OFF -DLAPACKE=OFF -DLAPACK=ON

.include "../../math/blas64/buildlink3.mk"
BUILDLINK_API_DEPENDS.blas64 +=	blas64>=${PKGVERSION_NOREV}

.include "../../math/lapack/Makefile.common"
.include "../../mk/bsd.pkg.mk"
