# $NetBSD: Makefile,v 1.16 2004/02/26 15:26:05 adam Exp $
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
USE_BUILDLINK3=		YES
USE_FORTRAN=		YES
USE_LIBTOOL=		YES

.include "../../mk/bsd.pkg.mk"
