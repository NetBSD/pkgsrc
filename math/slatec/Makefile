# $NetBSD: Makefile,v 1.7 2001/04/28 23:59:21 jtb Exp $

DISTNAME=	slatec_src
PKGNAME=	slatec-4.1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.netlib.org/slatec/ \
		ftp://netlib.bell-labs.com/netlib/slatec/ \
		ftp://www.hensa.ac.uk/mirrors/netlib/slatec/ \
		ftp://netlib.no/netlib/slatec/ \
		ftp://ftp.zib.de/netlib/slatec/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
COMMENT=	Library of mathematical and statistical Fortran 77 subroutines

WRKSRC=		${WRKDIR}/src
USE_FORTRAN=	YES

post-extract:
	cd ${FILESDIR} && ${CP} d1mach.f i1mach.f r1mach.f Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
