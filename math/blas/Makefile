# $NetBSD: Makefile,v 1.40 2021/06/15 04:41:51 thor Exp $

MAINTAINER=	thomas.orgis@uni-hamburg.de
COMMENT=	Basic Linear Algebra System (Netlib reference implementation)

LAPACK_COMPONENT=	blas
LAPACK_COMPONENT_CMAKE_ARGS=	\
	-DUSE_OPTIMIZED_BLAS=OFF \
	-DCBLAS=OFF -DLAPACKE=OFF -DLAPACK=OFF

.include "../../math/lapack/Makefile.common"
.include "../../mk/bsd.pkg.mk"
