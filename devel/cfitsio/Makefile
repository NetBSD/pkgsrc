# $NetBSD: Makefile,v 1.10 2004/09/08 13:32:31 wiz Exp $

DISTNAME=	cfitsio2500
PKGNAME=	cfitsio-2.500
CATEGORIES=	devel
MASTER_SITES=	ftp://heasarc.gsfc.nasa.gov/software/fitsio/c/

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://heasarc.gsfc.nasa.gov/docs/software/fitsio/fitsio.html
COMMENT=	FITS (flexible image transport system) file input and output

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV:C/-.*//}
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

ALL_TARGET=	all testprog

post-build:
	cd ${WRKSRC}; \
	./testprog | diff - testprog.out; \
	cmp testprog.fit testprog.std

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cfitsio
	cd ${WRKSRC}; \
	${LIBTOOL} ${INSTALL_DATA} libcfitsio.la ${PREFIX}/lib; \
	${INSTALL_DATA} *.h ${PREFIX}/include; \
	${INSTALL_DATA} fitsio.doc ${PREFIX}/share/doc/cfitsio

.include "../../mk/bsd.pkg.mk"
