# $NetBSD: Makefile,v 1.1 2021/06/15 04:41:51 thor Exp $


MAINTAINER=	thomas.orgis@uni-hamburg.de
COMMENT=	Reference Basic Linear Algebra System with 64 bit indices

LAPACK_COMPONENT=	blas64
LAPACK_COMPONENT_CMAKE_ARGS=	\
	-DBUILD_INDEX64=ON \
	-DUSE_OPTIMIZED_BLAS=OFF \
	-DCBLAS=OFF -DLAPACKE=OFF -DLAPACK=OFF

.include "../../math/lapack/Makefile.common"
.include "../../mk/bsd.pkg.mk"
