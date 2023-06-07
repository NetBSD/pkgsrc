# $NetBSD: Makefile,v 1.16 2023/06/07 12:30:08 mef Exp $

R_PKGNAME=	gstat
R_PKGVER=	2.1-1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Spatial & spatio-temporal modelling, prediction and simulation
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-FNN>=1.1.3:../../math/R-FNN
DEPENDS+=	R-sp>=0.9.98:../../math/R-sp
DEPENDS+=	R-spacetime>=1.0.0:../../math/R-spacetime
DEPENDS+=	R-zoo>=1.8.3:../../math/R-zoo
DEPENDS+=	R-sf-[0-9]*:../../geography/R-sf
DEPENDS+=	R-sftime-[0-9]*:../../time/R-sftime
DEPENDS+=	R-stars-[0-9]*:../../geography/R-stars

# Package required but not available: 'sftime'
# Packages suggested but not available: 'fields', 'future', 'future.apply'

TEST_DEPENDS+=	R-mapdata-[0-9]*:../../geography/R-mapdata
TEST_DEPENDS+=	R-maps-[0-9]*:../../geography/R-maps
TEST_DEPENDS+=	R-maptools-[0-9]*:../../geography/R-maptools
TEST_DEPENDS+=	R-raster-[0-9]*:../../geography/R-raster
TEST_DEPENDS+=	R-rgdal-[0-9]*:../../geography/R-rgdal
TEST_DEPENDS+=	R-rgeos-[0-9]*:../../geography/R-rgeos
TEST_DEPENDS+=	R-sf-[0-9]*:../../geography/R-sf
TEST_DEPENDS+=	R-stars-[0-9]*:../../geography/R-stars

USE_LANGUAGES+=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/blas.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
