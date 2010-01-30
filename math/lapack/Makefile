# $NetBSD: Makefile,v 1.30 2010/01/30 16:28:00 heinz Exp $

DISTNAME=	lapack-lite-3.1.1
PKGNAME=	lapack-3.1.1
PKGREVISION=	3
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_NETLIB:=lapack/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.netlib.org/lapack/index.html
COMMENT=	Linear Algebra PACKage
LICENSE=	modified-bsd

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
