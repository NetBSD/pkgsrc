# $NetBSD: Makefile,v 1.1.1.1 2000/07/31 16:47:04 tron Exp $

DISTNAME=	cfitsio2037
PKGNAME=	cfitsio-2.0.37
CATEGORIES=	cfitsio
MASTER_SITES=	ftp://heasarc.gsfc.nasa.gov/software/fitsio/c/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://fits.nrao.edu/FITS.html

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

ALL_TARGET=	all testprog
WRKSRC=		${WRKDIR}/${PKGNAME:C/-.*//}

post-build:
	cd ${WRKSRC}; \
	testprog | diff - testprog.out; \
	cmp testprog.fit testprog.std

do-install:
	${MKDIR} ${PREFIX}/share/doc/cfitsio
	cd ${WRKSRC}; \
	${LIBTOOL} ${INSTALL_DATA} libcfitsio.la ${PREFIX}/lib; \
	${INSTALL_DATA} *.h ${PREFIX}/include; \
	${INSTALL_DATA} fitsio.doc ${PREFIX}/share/doc/cfitsio

.include "../../mk/bsd.pkg.mk"
