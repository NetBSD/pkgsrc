# $NetBSD: Makefile,v 1.6 2002/05/03 22:44:04 jtb Exp $

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

DIST_SUBDIR=		lapack-20010201
WRKSRC=			${WRKDIR}/LAPACK
USE_FORTRAN=		yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/liblapack.a ${PREFIX}/lib

.include "../../math/blas/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
