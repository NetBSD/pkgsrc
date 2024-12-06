# $NetBSD: Makefile,v 1.3 2024/12/06 23:41:11 mef Exp $

R_PKGNAME=	ggthemes
R_PKGVER=	5.1.0
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extra Themes, Scales and Geoms for 'ggplot2'
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-purrr>=0.3.3:../../devel/R-purrr
DEPENDS+=	R-ggplot2>=3.0.0:../../graphics/R-ggplot2
DEPENDS+=	R-scales>=1.1.0:../../graphics/R-scales
DEPENDS+=	R-tibble>=2.1.3:../../math/R-tibble
DEPENDS+=	R-stringr>=1.4.0:../../textproc/R-stringr

# Packages suggested but not available:
#   'extrafont', 'pander', 'vdiffr'

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-dplyr-[0-9]*:../../math/R-dplyr
TEST_DEPENDS+=	R-lintr-[0-9]*:../../devel/R-lintr
TEST_DEPENDS+=	R-maps-[0-9]*:../../geography/R-maps
TEST_DEPENDS+=	R-mapproj-[0-9]*:../../math/R-mapproj
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-quantreg-[0-9]*:../../math/R-quantreg
TEST_DEPENDS+=	R-spelling-[0-9]*:../../textproc/R-spelling
TEST_DEPENDS+=	R-tidyr-[0-9]*:../../math/R-tidyr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
