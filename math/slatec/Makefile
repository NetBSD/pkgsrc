# $NetBSD: Makefile,v 1.15 2005/01/12 15:32:01 jlam Exp $
#

DISTNAME=	slatec_src
PKGNAME=	slatec-4.1
PKGREVISION=	2
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

WRKSRC=			${WRKDIR}/src
USE_BUILDLINK3=		YES
USE_LANGUAGES=		fortran
USE_LIBTOOL=		YES

post-extract:
	cd ${FILESDIR} && ${CP} d1mach.f i1mach.f r1mach.f ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
