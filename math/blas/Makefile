# $NetBSD: Makefile,v 1.20 2005/01/12 15:32:00 jlam Exp $
#

DISTNAME=	blas
PKGNAME=	blas-1.0
PKGREVISION=	3
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.netlib.org/blas/ \
		ftp://netlib.bell-labs.com/netlib/blas/ \
		ftp://www.hensa.ac.uk/mirrors/netlib/blas/
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.netlib.org/blas/
COMMENT=	Basic Linear Algebra Subprograms (Fortran)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}
USE_LANGUAGES=		fortran
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES

INSTALLATION_DIRS=	lib

.include "../../mk/bsd.pkg.mk"
