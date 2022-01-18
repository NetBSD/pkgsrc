# $NetBSD: Makefile,v 1.11 2022/01/18 17:42:26 gdt Exp $

R_PKGNAME=	sf
R_PKGVER=	1.0-2
PKGREVISION=	3
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
DEPENDS+=	R-s2-[0-9]*:../../geography/R-s2

# Packages suggested but not available:
#   'mapview', 'odbc', 'pool', 'RPostgres', 'RSQLite', 'spatstat.geom',
#   'spatstat.core', 'spatstat.linnet', 'terra', 'tmap'

TEST_DEPENDS+=	R-blob-[0-9]*:../../devel/R-blob
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
TEST_DEPENDS+=	R-microbenchmark-[0-9]*:../../benchmarks/R-microbenchmark
TEST_DEPENDS+=	R-RPostgreSQL-[0-9]*:../../math/R-RPostgreSQL
TEST_DEPENDS+=	R-raster-[0-9]*:../../geography/R-raster
TEST_DEPENDS+=	R-rgdal-[0-9]*:../../geography/R-rgdal
TEST_DEPENDS+=	R-stars-[0-9]*:../../geography/R-stars
TEST_DEPENDS+=	R-spatstat-[0-9]*:../../geography/R-spatstat
TEST_DEPENDS+=	R-tidyr-[0-9]*:../../math/R-tidyr

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
