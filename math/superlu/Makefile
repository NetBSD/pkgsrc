# $NetBSD: Makefile,v 1.9 2003/07/17 21:48:12 grant Exp $

DISTNAME=		superlu_2.0
PKGNAME=		superlu-2.0
PKGREVISION=		2
WRKSRC=			${WRKDIR}/SuperLU
CATEGORIES=		math
MASTER_SITES=		http://www.nersc.gov/~xiaoye/SuperLU/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.nersc.gov/~xiaoye/SuperLU/
COMMENT=		ANSI C routine library for the solution of sparse linear systems

DEPENDS+=		blas-[0-9]*:../../math/blas

BLAS_PREFIX_DEFAULT=	${LOCALBASE}
EVAL_PREFIX+=		BLAS_PREFIX=blas

ALL_TARGET=		superlulib

do-install:
	${INSTALL_DATA} ${WRKSRC}/libsuperlu.a ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${PREFIX}/include/superlu
	${INSTALL_DATA} ${WRKSRC}/SRC/*.h ${PREFIX}/include/superlu
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/superlu
	${INSTALL_DATA} ${WRKSRC}/INSTALL/ug.ps ${PREFIX}/share/doc/superlu

.include "../../mk/bsd.pkg.mk"
