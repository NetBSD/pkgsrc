# $NetBSD: Makefile,v 1.24 2023/11/08 13:20:00 wiz Exp $

R_PKGNAME=	RNetCDF
R_PKGVER=	2.6-2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Interface to NetCDF datasets
PKGREVISION=	2
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3	# OR file LICENSE

TEST_DEPENDS+=	R-bit64-[0-9]*:../../devel/R-bit64

.include "../../math/R/Makefile.extension"
.include "../../devel/netcdf/buildlink3.mk"
.include "../../math/udunits/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
