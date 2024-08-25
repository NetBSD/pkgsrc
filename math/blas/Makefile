# $NetBSD: Makefile,v 1.41 2024/08/25 06:18:59 wiz Exp $

MAINTAINER=	thomas.orgis@uni-hamburg.de
COMMENT=	Basic Linear Algebra System (Netlib reference implementation)

LAPACK_COMPONENT=	blas
LAPACK_COMPONENT_CMAKE_CONFIGURE_ARGS=	\
	-DUSE_OPTIMIZED_BLAS=OFF \
	-DCBLAS=OFF -DLAPACKE=OFF -DLAPACK=OFF

.include "../../math/lapack/Makefile.common"
.include "../../mk/bsd.pkg.mk"
