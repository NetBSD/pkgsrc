# $NetBSD: Makefile,v 1.6 2001/04/14 21:43:56 jtb Exp $

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
	${CP} ${FILESDIR}/d1mach.f ${FILESDIR}/i1mach.f ${FILESDIR}/r1mach.f \
	${FILESDIR}/Makefile ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
