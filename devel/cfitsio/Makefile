# $NetBSD: Makefile,v 1.39 2020/05/22 10:56:03 adam Exp $

DISTNAME=	cfitsio-3.47
PKGNAME=	${DISTNAME}0
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	http://heasarc.gsfc.nasa.gov/FTP/software/fitsio/c/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://heasarc.gsfc.nasa.gov/docs/software/fitsio/fitsio.html
COMMENT=	FITS (flexible image transport system) file input and output
# similar; no copyright claim.
LICENSE=	isc

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c # fortran
USE_LIBTOOL=	YES

MAKE_JOBS_SAFE=	NO

PKGCONFIG_OVERRIDE+=	cfitsio.pc.in

BUILD_TARGET=	all testprog

INSTALLATION_DIRS=	include lib lib/pkgconfig share/doc/cfitsio

CFITSIO_DOCS=	cfitsio.pdf cfortran.doc fitsio.pdf fitsio.doc \
		fpackguide.pdf quick.pdf

post-build:
	cd ${WRKSRC}; \
	./testprog > /dev/null; \
	${CMP} testprog.fit testprog.std

pre-install:
	rm ${WRKSRC}/testprog

post-install:
	cd ${WRKSRC}/docs; \
	${INSTALL_DATA} ${CFITSIO_DOCS} ${DESTDIR}${PREFIX}/share/doc/cfitsio

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
