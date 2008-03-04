# $NetBSD: Makefile,v 1.24 2008/03/04 18:12:59 jlam Exp $

DISTNAME=	lapack-lite-3.1.1
PKGNAME=	lapack-3.1.1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.netlib.org/lapack/			\
		ftp://netlib.no/netlib/lapack/			\
		ftp://ftp.zib.de/netlib/lapack/
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.netlib.org/lapack/index.html
COMMENT=	Linear Algebra PACKage

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c fortran
USE_LIBTOOL=		YES
BUILD_TARGET=		lapacklib

INSTALLATION_DIRS=	lib

do-install:
	${LIBTOOL} --mode=install ${INSTALL_DATA} ${WRKSRC}/liblapack.la \
		${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
