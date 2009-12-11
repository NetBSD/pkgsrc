# $NetBSD: Makefile,v 1.22 2009/12/11 17:32:41 asau Exp $
#

DISTNAME=	slatec_src
PKGNAME=	slatec-4.1
PKGREVISION=	3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_NETLIB:=slatec/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.netlib.org/slatec/
COMMENT=	Library of mathematical and statistical Fortran 77 subroutines

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/src
USE_LANGUAGES=		fortran
USE_LIBTOOL=		YES

INSTALLATION_DIRS=	lib

post-extract:
	cd ${FILESDIR} && cp d1mach.f i1mach.f r1mach.f ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
