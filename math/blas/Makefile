# $NetBSD: Makefile,v 1.34 2016/10/18 14:08:48 wiz Exp $

.include "../../math/lapack/Makefile.common"

PKGNAME=	${DISTNAME:S/lapack/blas/}

COMMENT=	Basic Linear Algebra Subprograms (Fortran)

PATCHDIR=	${.CURDIR}/../../math/lapack/patches

BUILD_TARGET=	blaslib

do-install:
	${LIBTOOL} --mode=install ${INSTALL_DATA} ${WRKSRC}/BLAS/SRC/libblas.la \
		${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
