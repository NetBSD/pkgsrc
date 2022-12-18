# $NetBSD: Makefile,v 1.19 2022/12/18 07:51:37 mef Exp $

R_PKGNAME=	RNetCDF
R_PKGVER=	2.6-1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Interface to NetCDF datasets
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3	# OR file LICENSE

TEST_DEPENDS+=	R-bit64-[0-9]*:../../devel/R-bit64

.include "../../math/R/Makefile.extension"
.include "../../devel/netcdf/buildlink3.mk"
.include "../../math/udunits/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
