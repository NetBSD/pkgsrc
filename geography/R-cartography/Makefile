# $NetBSD: Makefile,v 1.2 2024/11/26 12:53:30 mef Exp $

R_PKGNAME=	cartography
R_PKGVER=	3.1.4
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Thematic Cartography
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-raster>=3.4.13:../../geography/R-raster
DEPENDS+=	R-png>=0.1.8:../../graphics/R-png
DEPENDS+=	R-curl>=5.0.0:../../www/R-curl

# Package suggested but not available: 'SpatialPosition'
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-tinytest-[0-9]*:../../devel/R-tinytest
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-lwgeom-[0-9]*:../../geography/R-lwgeom

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../geography/R-sf/buildlink3.mk"
.include "../../math/R-sp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
