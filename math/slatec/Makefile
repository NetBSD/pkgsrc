# $NetBSD: Makefile,v 1.11 2003/12/04 15:10:48 adam Exp $
#

DISTNAME=	slatec_src
PKGNAME=	slatec-4.1
PKGREVISION=	1
WRKSRC=		${WRKDIR}/src
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.netlib.org/slatec/ \
		ftp://netlib.bell-labs.com/netlib/slatec/ \
		ftp://www.hensa.ac.uk/mirrors/netlib/slatec/ \
		ftp://netlib.no/netlib/slatec/ \
		ftp://ftp.zib.de/netlib/slatec/
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.netlib.org/slatec/
COMMENT=	Library of mathematical and statistical Fortran 77 subroutines

USE_BUILDLINK2=		YES
USE_FORTRAN=		YES
USE_LIBTOOL=		YES

post-extract:
	cd ${FILESDIR} && ${CP} d1mach.f i1mach.f r1mach.f ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
