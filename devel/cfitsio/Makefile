# $NetBSD: Makefile,v 1.15 2005/10/23 14:02:17 rillig Exp $

DISTNAME=	cfitsio2500
PKGNAME=	cfitsio-2.500
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://heasarc.gsfc.nasa.gov/software/fitsio/c/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://heasarc.gsfc.nasa.gov/docs/software/fitsio/fitsio.html
COMMENT=	FITS (flexible image transport system) file input and output

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV:C/-.*//}
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

BUILD_TARGET=	all testprog

INSTALLATION_DIRS=	include lib

post-build:
	cd ${WRKSRC}; \
	./testprog | diff - testprog.out; \
	${CMP} testprog.fit testprog.std

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cfitsio
	cd ${WRKSRC}; \
	${LIBTOOL} ${INSTALL_DATA} libcfitsio.la ${PREFIX}/lib; \
	${INSTALL_DATA} *.h ${PREFIX}/include; \
	${INSTALL_DATA} fitsio.doc ${PREFIX}/share/doc/cfitsio

.include "../../mk/bsd.pkg.mk"
