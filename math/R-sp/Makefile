# $NetBSD: Makefile,v 1.19 2023/06/07 12:43:16 mef Exp $

R_PKGNAME=	sp
R_PKGVER=	1.6-1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Classes and methods for spatial data
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

# Package suggested but not available: 'terra'
#
TEST_DEPENDS+=	R-deldir-[0-9]*:../../geography/R-deldir
TEST_DEPENDS+=	R-gstat-[0-9]*:../../math/R-gstat
TEST_DEPENDS+=	R-maptools-[0-9]*:../../geography/R-maptools
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-raster-[0-9]*:../../geography/R-raster
TEST_DEPENDS+=	R-RColorBrewer-[0-9]*:../../math/R-RColorBrewer
TEST_DEPENDS+=	R-rgdal-[0-9]*:../../geography/R-rgdal
TEST_DEPENDS+=	R-rgeos-[0-9]*:../../geography/R-rgeos
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-sf-[0-9]*:../../geography/R-sf


USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
