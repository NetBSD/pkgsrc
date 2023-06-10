# $NetBSD: Makefile,v 1.2 2023/06/10 12:43:39 mef Exp $

R_PKGNAME=	rosm
R_PKGVER=	0.2.6
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Plot Raster Map Tiles from Open Street Map and Other Sources
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-prettymapr>=0.2.2:../../geography/R-prettymapr
DEPENDS+=	R-rgdal>=1.4.8:../../geography/R-rgdal
DEPENDS+=	R-jpeg>=0.1.8.1:../../graphics/R-jpeg
DEPENDS+=	R-png>=0.1.7:../../graphics/R-png
DEPENDS+=	R-abind>=1.4.5:../../math/R-abind
DEPENDS+=	R-plyr>=1.8.6:../../math/R-plyr
DEPENDS+=	R-rjson>=0.2.20:../../textproc/R-rjson
DEPENDS+=	R-curl>=4.3:../../www/R-curl

# Package suggested but not available: 'cartography'

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-withr-[0-9]*:../../devel/R-withr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../math/R-sp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
