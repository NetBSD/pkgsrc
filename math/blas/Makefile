# $NetBSD: Makefile,v 1.39 2021/05/12 14:32:52 thor Exp $

.include "../../math/lapack/Makefile.common"

COMMENT=	Basic Linear Algebra System (Netlib reference implementation)

LAPACK_COMPONENT=	blas
LAPACK_COMPONENT_CMAKE_ARGS=	\
	-DUSE_OPTIMIZED_BLAS=OFF \
	-DCBLAS=OFF -DLAPACKE=OFF -DLAPACK=OFF

.include "../../mk/bsd.pkg.mk"
