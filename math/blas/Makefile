# $NetBSD: Makefile,v 1.10 2003/03/29 12:41:39 jmmv Exp $
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

MAINTAINER=		packages@netbsd.org
COMMENT=		Basic Linear Algebra Subprograms (Fortran)

USE_FORTRAN=		YES
USE_BUILDLINK2=		YES

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
