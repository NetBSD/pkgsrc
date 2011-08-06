# $NetBSD: Makefile,v 1.26 2011/08/06 15:44:20 wiz Exp $

DISTNAME=	cfitsio3280
PKGNAME=	cfitsio-3.280
CATEGORIES=	devel
MASTER_SITES=	http://heasarc.gsfc.nasa.gov/FTP/software/fitsio/c/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://heasarc.gsfc.nasa.gov/docs/software/fitsio/fitsio.html
COMMENT=	FITS (flexible image transport system) file input and output
# similar; no copyright claim.
LICENSE=	isc

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV:C/-.*//}
GNU_CONFIGURE=	YES
USE_LANGUAGES=	c # fortran
USE_LIBTOOL=	YES

MAKE_JOBS_SAFE=	NO

PKGCONFIG_OVERRIDE+=	cfitsio.pc.in

BUILD_TARGET=	all testprog

INSTALLATION_DIRS=	include lib lib/pkgconfig share/doc/cfitsio

post-build:
	cd ${WRKSRC}; \
	./testprog > /dev/null; \
	${CMP} testprog.fit testprog.std

do-install:
	cd ${WRKSRC}; \
	${LIBTOOL} --mode=install ${INSTALL_DATA} libcfitsio.la ${DESTDIR}${PREFIX}/lib; \
	${INSTALL_DATA} fitsio.h fitsio2.h longnam.h drvrsmem.h ${DESTDIR}${PREFIX}/include; \
	${INSTALL_DATA} cfitsio.pc ${DESTDIR}${PREFIX}/lib/pkgconfig; \
	${INSTALL_DATA} fitsio.doc ${DESTDIR}${PREFIX}/share/doc/cfitsio

.include "../../mk/bsd.pkg.mk"
