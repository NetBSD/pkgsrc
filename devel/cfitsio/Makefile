# $NetBSD: Makefile,v 1.7 2003/06/18 09:22:17 agc Exp $

DISTNAME=	cfitsio2037
PKGNAME=	cfitsio-2.0.37
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV:C/-.*//}
CATEGORIES=	devel
MASTER_SITES=	ftp://heasarc.gsfc.nasa.gov/software/fitsio/c/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://legacy.gsfc.nasa.gov/docs/software/fitsio/fitsio.html
COMMENT=	FITS (flexible image transport system) file input and output

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
