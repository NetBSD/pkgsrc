# $NetBSD: Makefile,v 1.11 2003/12/04 10:32:30 adam Exp $
#

DISTNAME=	lapack
PKGNAME=	lapack-20010201
PKGREVISION=	1
WRKSRC=		${WRKDIR}/LAPACK
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.netlib.org/lapack/			\
		ftp://netlib.bell-labs.com/netlib/lapack/	\
		ftp://www.hensa.ac.uk/mirrors/netlib/lapack/	\
		ftp://netlib.no/netlib/lapack/			\
		ftp://ftp.zib.de/netlib/lapack/
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.netlib.org/lapack/index.html
COMMENT=	Linear Algebra PACKage

DIST_SUBDIR=		lapack-20010201
USE_BUILDLINK2=		YES
USE_FORTRAN=		YES
USE_LIBTOOL=		YES
ALL_TARGET=		lapacklib

do-install:
	${LIBTOOL} --mode=install ${INSTALL_DATA} ${WRKSRC}/liblapack.la \
		${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
