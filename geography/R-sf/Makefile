# $NetBSD: Makefile,v 1.32 2024/11/27 23:26:16 mef Exp $

R_PKGNAME=	sf
R_PKGVER=	1.0-19
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Simple Features for R
LICENSE=	mit OR gnu-gpl-v2

USE_LANGUAGES+=		c
USE_CXX_FEATURES+=	c++11

DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-rgeos>=0.5.2:../../geography/R-rgeos
DEPENDS+=	R-DBI>=0.8:../../math/R-DBI
DEPENDS+=	R-classInt>=0.4.1:../../math/R-classInt
DEPENDS+=	R-units>=0.6.0:../../math/R-units
DEPENDS+=	R-s2-[0-9]*:../../geography/R-s2

# Packages suggested but not available:
#  'nanoarrow', 'mapview', 'odbc', 'pbapply', 'pool', 'RPostgres',
#  'tmap'

# Packages required and available but unsuitable versions:
#   's2', 'lwgeom', 'wk'

TEST_DEPENDS+=	R-RPostgreSQL-[0-9]*:../../math/R-RPostgreSQL
TEST_DEPENDS+=	R-RSQLite-[0-9]*:../../databases/R-RSQLite
TEST_DEPENDS+=	R-blob-[0-9]*:../../devel/R-blob
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-maps-[0-9]*:../../geography/R-maps
TEST_DEPENDS+=	R-microbenchmark-[0-9]*:../../benchmarks/R-microbenchmark
TEST_DEPENDS+=	R-raster-[0-9]*:../../geography/R-raster
TEST_DEPENDS+=	R-rgdal-[0-9]*:../../geography/R-rgdal
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-stars-[0-9]*:../../geography/R-stars
TEST_DEPENDS+=	R-spatstat-[0-9]*:../../geography/R-spatstat
TEST_DEPENDS+=	R-terra-[0-9]*:../../geography/R-terra
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-tidyr-[0-9]*:../../math/R-tidyr
TEST_DEPENDS+=	R-wk-[0-9]*:../../geography/R-wk

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
