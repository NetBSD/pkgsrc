# $NetBSD: Makefile,v 1.2 2021/09/20 13:01:32 mef Exp $

R_PKGNAME=	stars
R_PKGVER=	0.5-3
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Spatiotemporal Arrays, Raster and Vector Data Cubes
LICENSE=	apache-2.0

DEPENDS+=	R-rlang>=0.4.5:../../devel/R-rlang
DEPENDS+=	R-lwgeom>=0.2.5:../../geography/R-lwgeom
DEPENDS+=	R-sf>=0.9.0:../../geography/R-sf
DEPENDS+=	R-abind>=1.4.5:../../math/R-abind
DEPENDS+=	R-units>=0.6.5:../../math/R-units

# Packages suggested but not available:
#   'PCICt', 'clue', 'cubelyr', 'exactextractr', 'future.apply',
#   'ggforce', 'ncdfgeom', 'ncmeta', 'pbapply', 'plm', 'starsdata',
#   'terra'

TEST_DEPENDS+=	R-RNetCDF-[0-9]*:../../math/R-RNetCDF
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-digest-[0-9]*:../../security/R-digest
TEST_DEPENDS+=	R-dplyr-[0-9]*:../../math/R-dplyr
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
TEST_DEPENDS+=	R-ggthemes-[0-9]*:../../graphics/R-ggthemes
TEST_DEPENDS+=	R-gstat-[0-9]*:../../math/R-gstat
TEST_DEPENDS+=	R-httr-[0-9]*:../../www/R-httr
TEST_DEPENDS+=	R-jsonlite-[0-9]*:../../textproc/R-jsonlite
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-maps-[0-9]*:../../geography/R-maps
TEST_DEPENDS+=	R-mapdata-[0-9]*:../../geography/R-mapdata
TEST_DEPENDS+=	R-randomForest-[0-9]*:../../math/R-randomForest
TEST_DEPENDS+=	R-raster-[0-9]*:../../geography/R-raster
TEST_DEPENDS+=	R-rgdal-[0-9]*:../../geography/R-rgdal
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-spacetime-[0-9]*:../../math/R-spacetime
TEST_DEPENDS+=	R-spatstat-[0-9]*:../../geography/R-spatstat
TEST_DEPENDS+=	R-spatstat.geom-[0-9]*:../../geography/R-spatstat.geom
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-tidyr-[0-9]*:../../math/R-tidyr
TEST_DEPENDS+=	R-viridis-[0-9]*:../../graphics/R-viridis
TEST_DEPENDS+=	R-xts-[0-9]*:../../math/R-xts
TEST_DEPENDS+=	R-zoo-[0-9]*:../../math/R-zoo

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
