# $NetBSD: Makefile,v 1.6 2001/09/09 20:36:35 agc Exp $
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

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
