# $NetBSD: Makefile,v 1.4 2001/02/17 18:22:15 wiz Exp $
#

DISTNAME=		blas
PKGNAME=		blas-1.0
CATEGORIES=		math
MASTER_SITES=		ftp://ftp.netlib.org/blas/ \
			ftp://netlib.bell-labs.com/netlib/blas/ \
			ftp://www.hensa.ac.uk/mirrors/netlib/blas/
EXTRACT_SUFX=		.tgz

MAINTAINER=		jtb@netbsd.org
COMMENT=		Basic Linear Algebra Subprograms (Fortran)

WRKSRC=			${WRKDIR}
NO_WRKSUBDIR=		YES
USE_FORTRAN=		YES

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
