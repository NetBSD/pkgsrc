# $NetBSD: Makefile,v 1.10 2003/07/17 21:48:09 grant Exp $

DISTNAME=	slatec_src
PKGNAME=	slatec-4.1
WRKSRC=		${WRKDIR}/src
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.netlib.org/slatec/ \
		ftp://netlib.bell-labs.com/netlib/slatec/ \
		ftp://www.hensa.ac.uk/mirrors/netlib/slatec/ \
		ftp://netlib.no/netlib/slatec/ \
		ftp://ftp.zib.de/netlib/slatec/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Library of mathematical and statistical Fortran 77 subroutines

USE_FORTRAN=	YES

post-extract:
	cd ${FILESDIR} && ${CP} d1mach.f i1mach.f r1mach.f Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
