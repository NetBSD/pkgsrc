# $NetBSD: Makefile,v 1.10 2003/11/11 11:53:56 wiz Exp $

DISTNAME=		superlu_3.0
PKGNAME=		superlu-3.0
WRKSRC=			${WRKDIR}/SuperLU_3.0
CATEGORIES=		math
MASTER_SITES=		http://www.nersc.gov/~xiaoye/SuperLU/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.nersc.gov/~xiaoye/SuperLU/
COMMENT=		ANSI C routine library for the solution of sparse linear systems

DEPENDS+=		blas-[0-9]*:../../math/blas

BLAS_PREFIX_DEFAULT=	${LOCALBASE}
EVAL_PREFIX+=		BLAS_PREFIX=blas

ALL_TARGET=		superlulib
TEST_DIRS=		${WRKSRC}/TESTING/MATGEN ${WRKSRC}/TESTING
TEST_TARGET=		all

do-install:
	${INSTALL_DATA} ${WRKSRC}/libsuperlu.a ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${PREFIX}/include/superlu
	${INSTALL_DATA} ${WRKSRC}/SRC/*.h ${PREFIX}/include/superlu
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/superlu
	${INSTALL_DATA} ${WRKSRC}/INSTALL/ug.ps ${PREFIX}/share/doc/superlu

.include "../../mk/bsd.pkg.mk"
