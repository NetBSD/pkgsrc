# $NetBSD: Makefile,v 1.12 2003/07/17 21:47:21 grant Exp $
#

DISTNAME=		blas
PKGNAME=		blas-1.0
PKGREVISION=		1
WRKSRC=			${WRKDIR}
CATEGORIES=		math
MASTER_SITES=		ftp://ftp.netlib.org/blas/ \
			ftp://netlib.bell-labs.com/netlib/blas/ \
			ftp://www.hensa.ac.uk/mirrors/netlib/blas/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Basic Linear Algebra Subprograms (Fortran)

USE_FORTRAN=		YES
USE_BUILDLINK2=		YES

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
