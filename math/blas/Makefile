# $NetBSD: Makefile,v 1.13 2003/11/19 16:16:47 adam Exp $
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
HOMEPAGE=		http://www.netlib.org/blas/
COMMENT=		Basic Linear Algebra Subprograms (Fortran)

USE_FORTRAN=		YES
USE_BUILDLINK2=		YES

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
