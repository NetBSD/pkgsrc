# $NetBSD: Makefile,v 1.61 2026/02/14 18:27:35 adam Exp $

DISTNAME=	cfitsio-4.6.3
CATEGORIES=	devel
MASTER_SITES=	https://heasarc.gsfc.nasa.gov/FTP/software/fitsio/c/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://heasarc.gsfc.nasa.gov/docs/software/fitsio/fitsio.html
COMMENT=	FITS (flexible image transport system) file input and output
# similar; no copyright claim.
LICENSE=	isc

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-bzip2
CONFIGURE_ARGS+=	--without-fortran
# Does not detect pkgsrc zlib correctly.
CONFIGURE_ARGS+=	--without-zlib-check
PKGCONFIG_OVERRIDE+=	cfitsio.pc.in

INSTALLATION_DIRS=	include lib lib/pkgconfig share/doc/cfitsio

CFITSIO_DOCS=	cfitsio.pdf fitsio.pdf fpackguide.pdf quick.pdf

post-install:
	cd ${WRKSRC}/docs && \
	${INSTALL_DATA} ${CFITSIO_DOCS} ${DESTDIR}${PREFIX}/share/doc/cfitsio

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
