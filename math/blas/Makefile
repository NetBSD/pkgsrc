# $NetBSD: Makefile,v 1.15 2004/01/20 12:20:04 agc Exp $
#

DISTNAME=	blas
PKGNAME=	blas-1.0
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.netlib.org/blas/ \
		ftp://netlib.bell-labs.com/netlib/blas/ \
		ftp://www.hensa.ac.uk/mirrors/netlib/blas/
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.netlib.org/blas/
COMMENT=	Basic Linear Algebra Subprograms (Fortran)

WRKSRC=			${WRKDIR}
USE_BUILDLINK2=		YES
USE_FORTRAN=		YES
USE_LIBTOOL=		YES

.include "../../mk/bsd.pkg.mk"
