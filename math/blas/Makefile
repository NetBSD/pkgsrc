# $NetBSD: Makefile,v 1.35 2016/12/03 03:42:44 marino Exp $

.include "../../math/lapack/Makefile.common"

PKGNAME=	${DISTNAME:S/lapack/blas/}

COMMENT=	Basic Linear Algebra Subprograms (Fortran)

PATCHDIR=	${.CURDIR}/../../math/lapack/patches

BUILD_TARGET=	blaslib

# blas fails using the gold linker with:
# fatal error: --sysroot=: must take a non-empty argument
# Work around it on DragonFly by specifying the classic gnu linker

MAKE_ENV+=	LDVER=ld.bfd

do-install:
	${LIBTOOL} --mode=install ${INSTALL_DATA} ${WRKSRC}/BLAS/SRC/libblas.la \
		${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
