# $NetBSD: Makefile,v 1.1.1.1 2001/02/01 23:30:56 jtb Exp $

DISTNAME=		lapack-20010201
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://www.netlib.org/lapack/index.html

DEPENDS+=		blas-[0-9]*:../../math/blas

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
WRKSRC=			${WRKDIR}/LAPACK
USE_FORTRAN=		YES
EVAL_PREFIX+=		BLAS_PREFIX=blas

do-install:
	${INSTALL_DATA} ${WRKSRC}/liblapack.a ${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
