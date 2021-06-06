# $NetBSD: Makefile,v 1.7 2021/06/06 14:45:22 mef Exp $

R_PKGNAME=	sf
R_PKGVER=	0.9-8
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Simple Features for R
LICENSE=	mit OR gnu-gpl-v2

USE_LANGUAGES+=	c c++11

DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-rgeos>=0.5.2:../../geography/R-rgeos
DEPENDS+=	R-DBI>=0.8:../../math/R-DBI
DEPENDS+=	R-classInt>=0.4.1:../../math/R-classInt
DEPENDS+=	R-units>=0.6.0:../../math/R-units

# Packages suggested but not available:
#   'lwgeom', 'mapview', 'odbc', 'pool', 'rgdal', 'RPostgres',
#   'RPostgreSQL', 'RSQLite', 's2', 'spatstat', 'spatstat.geom',
#   'spatstat.core', 'spatstat.linnet', 'spatstat.utils', 'stars',
#   'terra', 'tidyr', 'tmap'

TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
TEST_DEPENDS+=	R-blob-[0-9]*:../../devel/R-blob
TEST_DEPENDS+=	R-raster-[0-9]*:../../geography/R-raster
TEST_DEPENDS+=	R-microbenchmark-[0-9]*:../../benchmarks/R-microbenchmark

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
