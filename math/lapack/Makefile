# $NetBSD: Makefile,v 1.18 2005/01/03 15:33:55 wennmach Exp $
#

DISTNAME=	lapack
PKGNAME=	lapack-20010201
PKGREVISION=	4
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

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/LAPACK
DIST_SUBDIR=		lapack-20010201
USE_BUILDLINK3=		YES
USE_FORTRAN=		YES
USE_LIBTOOL=		YES
BUILD_TARGET=		lapacklib

INSTALLATION_DIRS=	lib

do-install:
	${LIBTOOL} --mode=install ${INSTALL_DATA} ${WRKSRC}/liblapack.la \
		${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
