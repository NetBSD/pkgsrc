# $NetBSD: Makefile,v 1.5 2024/12/07 06:28:42 mef Exp $

R_PKGNAME=	viridis
R_PKGVER=	0.6.5
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Default color maps from 'matplotlib'
LICENSE=	mit

DEPENDS+=	R-ggplot2>=1.0.1:../../graphics/R-ggplot2
DEPENDS+=	R-gridExtra>=2.3:../../graphics/R-gridExtra
DEPENDS+=	R-viridisLite>=0.4.0:../../graphics/R-viridisLite

# Packages suggested but not available: 'vdiffr', 'svglite'

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-hexbin-[0-9]*:../../math/R-hexbin
TEST_DEPENDS+=	R-httr-[0-9]*:../../www/R-httr
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-mapproj-[0-9]*:../../math/R-mapproj
TEST_DEPENDS+=	R-maps-[0-9]*:../../geography/R-maps
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-terra-[0-9]*:../../geography/R-terra
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
