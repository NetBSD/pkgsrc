# $NetBSD: Makefile,v 1.7 2019/08/22 12:23:29 ryoon Exp $

R_PKGNAME=	RNetCDF
R_PKGVER=	1.9-1
PKGREVISION=	4
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Interface to NetCDF datasets
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3	# OR file LICENSE

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../devel/netcdf/buildlink3.mk"
.include "../../math/udunits/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
