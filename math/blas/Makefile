# $NetBSD: Makefile,v 1.37 2020/02/28 21:48:53 plunky Exp $

.include "../../math/lapack/Makefile.common"

PKGNAME=	${DISTNAME:S/lapack/blas/}

COMMENT=	Basic Linear Algebra Subprograms (Fortran)

# not actually true but pretend as we package it separately
CMAKE_ARGS+=	-DLATESTLAPACK_FOUND:BOOL=TRUE

BUILD_TARGET=	blas

TEST_DIRS=	${WRKSRC}/${OBJDIR}/BLAS

.include "../../mk/bsd.pkg.mk"
