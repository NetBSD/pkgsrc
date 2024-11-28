# $NetBSD: Makefile,v 1.2 2024/11/28 13:49:29 mef Exp $

R_PKGNAME=	rnaturalearth
R_PKGVER=	1.0.1
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	World Map Data from Natural Earth
LICENSE=	mit

DEPENDS+=	R-jsonlite-[0-9]*:../../textproc/R-jsonlite
DEPENDS+=	R-httr-[0-9]*:../../www/R-httr
DEPENDS+=	R-sf>=0.3.4:../../geography/R-sf
DEPENDS+=	R-terra-[0-9]*:../../geography/R-terra

# Packages suggested but not available: 'ggrepel', 'pbapply', 'tmap'
TEST_DEPENDS+=	R-devtools-[0-9]*:../../devel/R-devtools
TEST_DEPENDS+=	R-dplyr-[0-9]*:../../math/R-dplyr
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-lifecycle-[0-9]*:../../devel/R-lifecycle
TEST_DEPENDS+=	R-purrr-[0-9]*:../../devel/R-purrr
TEST_DEPENDS+=	R-rlang-[0-9]*:../../devel/R-rlang
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-rnaturalearthdata-[0-9]*:../../geography/R-rnaturalearthdata
TEST_DEPENDS+=	R-rnaturalearthhires-[0-9]*:../../geography/R-rnaturalearthhires
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../math/R-sp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
