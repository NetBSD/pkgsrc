# $NetBSD: Makefile,v 1.4 2024/01/24 23:17:12 mef Exp $

R_PKGNAME=	spData
R_PKGVER=	2.3.0
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Datasets for Spatial Analysis
LICENSE=	cc0-1.0-universal

DEPENDS+=	R-raster>=3.0.12:../../geography/R-raster

# Packages suggested but not available:
#   'sf', 'spDataLarge', 'spdep', 'spatialreg'
TEST_DEPENDS+=	R-sf-[0-9]*:../../geography/R-sf

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../math/R-sp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
