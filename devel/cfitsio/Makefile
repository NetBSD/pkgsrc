# $NetBSD: Makefile,v 1.52 2024/08/05 14:50:55 adam Exp $

DISTNAME=	cfitsio-4.4.1
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
# Does not detect pkgsrc zlib correctly.
CONFIGURE_ARGS+=	--without-zlib-check
PKGCONFIG_OVERRIDE+=	cfitsio.pc.in

INSTALLATION_DIRS=	include lib lib/pkgconfig share/doc/cfitsio

CFITSIO_DOCS=	cfitsio.pdf fitsio.pdf fpackguide.pdf quick.pdf

post-install:
	cd ${WRKSRC}/docs && \
	${INSTALL_DATA} ${CFITSIO_DOCS} ${DESTDIR}${PREFIX}/share/doc/cfitsio

.include "../../devel/zlib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
