# $NetBSD: Makefile,v 1.2 2001/02/17 18:22:44 wiz Exp $

DISTNAME=		superlu_2.0
PKGNAME=		superlu-2.0
CATEGORIES=		math
MASTER_SITES=		http://www.nersc.gov/~xiaoye/SuperLU/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://www.nersc.gov/~xiaoye/SuperLU/
COMMENT=		ANSI C routine library for the solution of sparse linear systems

DEPENDS+=		blas-[0-9]*:../../math/blas

WRKSRC=			${WRKDIR}/SuperLU
EVAL_PREFIX+=		BLAS_PREFIX=blas
ALL_TARGET=		superlulib

do-install:
	${INSTALL_DATA} ${WRKSRC}/libsuperlu.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/SRC/supermatrix.h ${PREFIX}/include
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/superlu
	${INSTALL_DATA} ${WRKSRC}/INSTALL/ug.ps ${PREFIX}/share/doc/superlu

.include "../../mk/bsd.pkg.mk"
