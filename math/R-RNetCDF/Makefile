# $NetBSD: Makefile,v 1.5 2019/07/31 18:23:57 brook Exp $

PKGREVISION=	3
CATEGORIES=	math R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/ncdf/
COMMENT=	Interface to NetCDF datasets
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3	# OR file LICENSE

R_PKGNAME=	RNetCDF
R_PKGVER=	1.9-1

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../devel/netcdf/buildlink3.mk"
.include "../../math/udunits/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
