# $NetBSD: Makefile,v 1.5 2001/05/05 20:53:02 jtb Exp $

DISTNAME=		lapack
PKGNAME=		lapack-20010201
CATEGORIES=		math
MASTER_SITES=		ftp://ftp.netlib.org/lapack/			\
			ftp://netlib.bell-labs.com/netlib/lapack/	\
			ftp://www.hensa.ac.uk/mirrors/netlib/lapack/	\
			ftp://netlib.no/netlib/lapack/			\
			ftp://ftp.zib.de/netlib/lapack/
EXTRACT_SUFX=		.tgz

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netlib.org/lapack/index.html
COMMENT=		Linear Algebra PACKage

DEPENDS+=		blas-[0-9]*:../../math/blas

DIST_SUBDIR=		lapack-20010201
WRKSRC=			${WRKDIR}/LAPACK
USE_FORTRAN=		yes

BLAS_PREFIX_DEFAULT=	${LOCALBASE}
EVAL_PREFIX+=		BLAS_PREFIX=blas

do-install:
	${INSTALL_DATA} ${WRKSRC}/liblapack.a ${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
