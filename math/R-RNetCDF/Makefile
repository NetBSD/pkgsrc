# $NetBSD: Makefile,v 1.14 2021/04/21 13:24:59 adam Exp $

R_PKGNAME=	RNetCDF
R_PKGVER=	2.4-2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Interface to NetCDF datasets
PKGREVISION=	1
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3	# OR file LICENSE

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../devel/netcdf/buildlink3.mk"
.include "../../math/udunits/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
