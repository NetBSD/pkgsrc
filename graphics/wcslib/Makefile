# $NetBSD: Makefile,v 1.3 2026/02/14 18:31:50 adam Exp $

# On update, change the version in buildlink3.mk.
DISTNAME=	wcslib-8.5
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.atnf.csiro.au/pub/software/wcslib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	thomas.orgis@uni-hamburg.de
HOMEPAGE=	https://www.atnf.csiro.au/computing/software/wcs/wcslib/index.html
COMMENT=	FITS World Coordinate Systems library
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=		c
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-fortran
USE_TOOLS+=		gmake flex
MAKE_FILE=		GNUmakefile

PKGCONFIG_OVERRIDE+=	wcslib.pc.in

# We could use pgplot, but it is not legally
# mirror-able and also really, really old.
CONFIGURE_ARGS+=	--without-pgplot
CONFIGURE_ARGS+=	--with-cfitsiolib=${BUILDLINK_PREFIX.cfitsio}/lib
CONFIGURE_ARGS+=	--with-cfitsioinc=${BUILDLINK_PREFIX.cfitsio}/include

.include "../../devel/cfitsio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
