# $NetBSD: Makefile,v 1.4 2001/05/03 22:16:51 jtb Exp $

DISTNAME=		lapack-20010201
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netlib.org/lapack/index.html
COMMENT=		Linear Algebra PACKage

DEPENDS+=		blas-[0-9]*:../../math/blas

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
WRKSRC=			${WRKDIR}/LAPACK
USE_FORTRAN=		YES

BLAS_PREFIX_DEFAULT=	${LOCALBASE}
EVAL_PREFIX+=		BLAS_PREFIX=blas

do-install:
	${INSTALL_DATA} ${WRKSRC}/liblapack.a ${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
