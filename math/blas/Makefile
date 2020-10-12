# $NetBSD: Makefile,v 1.38 2020/10/12 21:51:57 bacon Exp $

.include "../../math/lapack/Makefile.common"

PKGREVISION=	1

COMMENT=	Basic Linear Algebra System (Netlib reference implementation)

LAPACK_COMPONENT=	blas
LAPACK_COMPONENT_CMAKE_ARGS=	\
	-DUSE_OPTIMIZED_BLAS=OFF \
	-DCBLAS=OFF -DLAPACKE=OFF -DLAPACK=OFF

.include "../../mk/bsd.pkg.mk"
