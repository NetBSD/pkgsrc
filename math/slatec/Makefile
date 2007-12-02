# $NetBSD: Makefile,v 1.19 2007/12/02 11:21:54 wiz Exp $
#

DISTNAME=	slatec_src
PKGNAME=	slatec-4.1
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.netlib.org/slatec/ \
		ftp://netlib.no/netlib/slatec/ \
		ftp://ftp.zib.de/netlib/slatec/
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.netlib.org/slatec/
COMMENT=	Library of mathematical and statistical Fortran 77 subroutines

WRKSRC=			${WRKDIR}/src
USE_LANGUAGES=		fortran
USE_LIBTOOL=		YES

INSTALLATION_DIRS=	lib

post-extract:
	cd ${FILESDIR} && cp d1mach.f i1mach.f r1mach.f ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
