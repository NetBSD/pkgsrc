# $NetBSD: Makefile,v 1.1.1.1 2000/11/06 17:55:12 wennmach Exp $
#

DISTNAME=	blas
PKGNAME=	blas-1.0
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.netlib.org/blas/ \
		ftp://netlib.bell-labs.com/netlib/blas/ \
		ftp://www.hensa.ac.uk/mirrors/netlib/blas/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jasontd@indigo.ie

WRKSRC=		${WRKDIR}
NO_WRKSUBDIR=	YES
USE_LIBTOOL=	YES
USE_FORTRAN=	YES

FFLAGS=	-O3

.include "../../mk/bsd.prefs.mk"

pre-build:
	${SED} -e 's:%%FORTRAN%%:'${FC}':g;s:%%FFLAGS%%:'${FFLAGS}':g' \
	< ${FILESDIR}/Makefile > ${WRKSRC}/Makefile

.include "../../mk/bsd.pkg.mk"
