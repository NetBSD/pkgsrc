# $NetBSD: Makefile,v 1.10 2003/07/17 21:47:43 grant Exp $

DISTNAME=		lapack
PKGNAME=		lapack-20010201
WRKSRC=			${WRKDIR}/LAPACK
CATEGORIES=		math
MASTER_SITES=		ftp://ftp.netlib.org/lapack/			\
			ftp://netlib.bell-labs.com/netlib/lapack/	\
			ftp://www.hensa.ac.uk/mirrors/netlib/lapack/	\
			ftp://netlib.no/netlib/lapack/			\
			ftp://ftp.zib.de/netlib/lapack/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.netlib.org/lapack/index.html
COMMENT=		Linear Algebra PACKage

DIST_SUBDIR=		lapack-20010201
USE_FORTRAN=		yes
USE_BUILDLINK2=		yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/liblapack.a ${PREFIX}/lib

.include "../../math/blas/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
