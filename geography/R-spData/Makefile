# $NetBSD: Makefile,v 1.3 2021/09/20 11:11:00 mef Exp $

R_PKGNAME=	spData
R_PKGVER=	0.3.10
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Datasets for Spatial Analysis
LICENSE=	cc0-1.0-universal

DEPENDS+=	R-raster>=3.0.12:../../geography/R-raster

# Packages suggested but not available:
#  'maptools', 'rgdal', 'sf', 'spDataLarge', 'spdep', 'spatialreg'


USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../math/R-sp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
