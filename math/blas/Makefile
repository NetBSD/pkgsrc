# $NetBSD: Makefile,v 1.8 2002/08/29 17:15:15 jlam Exp $
#

DISTNAME=		blas
PKGNAME=		blas-1.0
CATEGORIES=		math
MASTER_SITES=		ftp://ftp.netlib.org/blas/ \
			ftp://netlib.bell-labs.com/netlib/blas/ \
			ftp://www.hensa.ac.uk/mirrors/netlib/blas/
EXTRACT_SUFX=		.tgz

MAINTAINER=		packages@netbsd.org
COMMENT=		Basic Linear Algebra Subprograms (Fortran)

WRKSRC=			${WRKDIR}
USE_FORTRAN=		YES
USE_BUILDLINK2=		YES

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
