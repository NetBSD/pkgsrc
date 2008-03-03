# $NetBSD: Makefile,v 1.18 2008/03/03 17:45:34 jlam Exp $

DISTNAME=	cfitsio2500
PKGNAME=	cfitsio-2.500
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://heasarc.gsfc.nasa.gov/software/fitsio/c/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://heasarc.gsfc.nasa.gov/docs/software/fitsio/fitsio.html
COMMENT=	FITS (flexible image transport system) file input and output

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV:C/-.*//}
GNU_CONFIGURE=	YES
USE_LANGUAGES=	c fortran
USE_LIBTOOL=	YES

BUILD_TARGET=	all testprog

INSTALLATION_DIRS=	include lib

post-build:
	cd ${WRKSRC}; \
	./testprog | diff - testprog.out; \
	${CMP} testprog.fit testprog.std

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/cfitsio
	cd ${WRKSRC}; \
	${LIBTOOL} ${INSTALL_DATA} libcfitsio.la ${DESTDIR}${PREFIX}/lib; \
	${INSTALL_DATA} *.h ${DESTDIR}${PREFIX}/include; \
	${INSTALL_DATA} fitsio.doc ${DESTDIR}${PREFIX}/share/doc/cfitsio

.include "../../mk/bsd.pkg.mk"
