# $NetBSD: Makefile,v 1.14 2003/12/04 09:13:58 adam Exp $
#

DISTNAME=	blas
PKGNAME=	blas-1.0
PKGREVISION=	2
WRKSRC=		${WRKDIR}
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.netlib.org/blas/ \
		ftp://netlib.bell-labs.com/netlib/blas/ \
		ftp://www.hensa.ac.uk/mirrors/netlib/blas/
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.netlib.org/blas/
COMMENT=	Basic Linear Algebra Subprograms (Fortran)

USE_BUILDLINK2=		YES
USE_FORTRAN=		YES
USE_LIBTOOL=		YES

.include "../../mk/bsd.pkg.mk"
