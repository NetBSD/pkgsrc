# $NetBSD: Makefile,v 1.33 2014/08/19 13:37:14 joerg Exp $

.include "../../math/lapack/Makefile.common"

PKGNAME=	${DISTNAME:S/lapack/blas/}
PKGREVISION=	1

COMMENT=	Basic Linear Algebra Subprograms (Fortran)

PATCHDIR=	${.CURDIR}/../../math/lapack/patches

BUILD_TARGET=	blaslib

do-install:
	${LIBTOOL} --mode=install ${INSTALL_DATA} ${WRKSRC}/BLAS/SRC/libblas.la \
		${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
