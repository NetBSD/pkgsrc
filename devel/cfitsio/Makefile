# $NetBSD: Makefile,v 1.32 2017/08/01 14:58:54 wiz Exp $

DISTNAME=	cfitsio3390
PKGNAME=	${DISTNAME:S/o3/o-3./}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://heasarc.gsfc.nasa.gov/FTP/software/fitsio/c/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://heasarc.gsfc.nasa.gov/docs/software/fitsio/fitsio.html
COMMENT=	FITS (flexible image transport system) file input and output
# similar; no copyright claim.
LICENSE=	isc

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV:C/-.*//}
GNU_CONFIGURE=	YES
USE_LANGUAGES=	c # fortran
USE_LIBTOOL=	YES

MAKE_JOBS_SAFE=	NO

PKGCONFIG_OVERRIDE+=	cfitsio.pc.in

BUILD_TARGET=	all testprog

INSTALLATION_DIRS=	include lib lib/pkgconfig share/doc/cfitsio

CFITSIO_DOCS=	cfitsio.pdf cfitsio.doc cfortran.doc fitsio.pdf fitsio.doc \
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

.include "../../mk/bsd.pkg.mk"
