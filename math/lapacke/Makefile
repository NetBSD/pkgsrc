# $NetBSD: Makefile,v 1.3 2021/06/15 04:41:52 thor Exp $

MAINTAINER=	thomas.orgis@uni-hamburg.de
COMMENT=	C interface to the reference LAPACK library
PKGREVISION=	2

LAPACK_COMPONENT=	lapacke
LAPACK_COMPONENT_CMAKE_ARGS=	\
	-DUSE_OPTIMIZED_BLAS=ON \
	-DBLAS_LIBRARIES=-lblas \
	-DUSE_OPTIMIZED_LAPACK=ON \
	-DLAPACK_LIBRARIES=-llapack \
	-DCBLAS=OFF -DLAPACKE=ON

.include "../../math/lapack/buildlink3.mk"

.include "../../math/lapack/Makefile.common"
.include "../../mk/bsd.pkg.mk"
