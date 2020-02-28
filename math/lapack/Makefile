# $NetBSD: Makefile,v 1.40 2020/02/28 21:48:53 plunky Exp $

.include "Makefile.common"

COMMENT=	Linear Algebra PACKage

# use external blas
CMAKE_ARGS+=	-DBLAS_LIBRARIES:STRING=${BLAS_LIBS}

BUILD_TARGET=	lapack

.include "../../math/blas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
