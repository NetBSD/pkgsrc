# $NetBSD: Makefile,v 1.9 2021/09/18 12:20:06 mef Exp $

R_PKGNAME=	spacetime
R_PKGVER=	1.2-5

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Classes and methods for spatio-temporal data
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-intervals>=0.15.1:../../math/R-intervals
DEPENDS+=	R-sp>=1.1.0:../../math/R-sp
DEPENDS+=	R-xts>=0.8.8:../../math/R-xts
DEPENDS+=	R-zoo>=1.7.9:../../math/R-zoo

# Packages suggested but not available:
#   'adehabitatLT', 'cshapes', 'gstat', 'maps', 'mapdata', 'maptools',
#   'plm', 'raster', 'RColorBrewer', 'rgdal', 'rgeos', 'RPostgreSQL',
#   'knitr', 'googleVis', 'ISOcodes', 'markdown', 'sf'
TEST_DEPENDS+=	R-gstat-[0-9]*:../../math/R-gstat
TEST_DEPENDS+=	R-mapdata-[0-9]*:../../geography/R-mapdata
TEST_DEPENDS+=	R-maptools-[0-9]*:../../geography/R-maptools
TEST_DEPENDS+=	R-raster-[0-9]*:../../geography/R-raster
TEST_DEPENDS+=	R-RColorBrewer-[0-9]*:../../math/R-RColorBrewer
TEST_DEPENDS+=	R-rgdal-[0-9]*:../../geography/R-rgdal
TEST_DEPENDS+=	R-rgeos-[0-9]*:../../geography/R-rgeos
TEST_DEPENDS+=	R-RPostgreSQL-[0-9]*:../../math/R-RPostgreSQL
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-markdown-[0-9]*:../../textproc/R-markdown
TEST_DEPENDS+=	R-sf-[0-9]*:../../geography/R-sf

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../math/R-xts/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
