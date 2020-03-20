# $NetBSD: Makefile,v 1.1 2020/03/20 11:05:03 wiz Exp $

DISTNAME=	wcslib-7.2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.atnf.csiro.au/pub/software/wcslib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	thomas.orgis@uni-hamburg.de
HOMEPAGE=	https://www.atnf.csiro.au/people/mcalabre/WCS/
COMMENT=	FITS World Coordinate Systems library
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	c fortran
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake flex
MAKE_FILE=	GNUmakefile
MAKE_JOBS_SAFE=	NO

PKGCONFIG_OVERRIDE+=	wcslib.pc.in

# We could use pgplot, but it is not legally
# mirror-able and also really, really old.
CONFIGURE_ARGS+=	--without-pgplot
CONFIGURE_ARGS+=	--with-cfitsiolib=${BUILDLINK_PREFIX.cfitsio:Q}/lib
CONFIGURE_ARGS+=	--with-cfitsioinc=${BUILDLINK_PREFIX.cfitsio:Q}/include

.include "../../devel/cfitsio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
