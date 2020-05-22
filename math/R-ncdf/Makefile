# $NetBSD: Makefile,v 1.26 2020/05/22 10:56:20 adam Exp $

R_PKGNAME=	ncdf
R_PKGVER=	1.6.6
PKGREVISION=	19
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	High-level R interface to Unidata's netCDF data files
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c

CONFIGURE_ARGS+=	--with-netcdf_incdir=${BUILDLINK_PREFIX.netcdf}/include
CONFIGURE_ARGS+=	--with-netcdf_libdir=${BUILDLINK_PREFIX.netcdf}/lib

.include "../../math/R/Makefile.extension"
.include "../../devel/netcdf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
