# $NetBSD: Makefile,v 1.2 2024/12/07 06:16:52 mef Exp $

R_PKGNAME=	thematic
R_PKGVER=	0.1.6
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Unified & Automatic 'Theming' of 'ggplot2 / lattice / base' R Graphics
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-rappdirs>=0.3.1:../../devel/R-rappdirs
DEPENDS+=	R-rlang>=0.4.11:../../devel/R-rlang
DEPENDS+=	R-farver>=2.0.3:../../graphics/R-farver
DEPENDS+=	R-ggplot2>=3.3.0:../../graphics/R-ggplot2
DEPENDS+=	R-scales>=1.1.0:../../graphics/R-scales
DEPENDS+=	R-rstudioapi>=0.8:../../math/R-rstudioapi

# Packages suggested but not available:
#   'gganimate', 'ggiraph', 'showtext', 'svglite', 'sysfonts', 'vdiffr'

TEST_DEPENDS+=	R-Cairo-[0-9]*:../../graphics/R-Cairo
TEST_DEPENDS+=	R-bslib-[0-9]*:../../www/R-bslib
TEST_DEPENDS+=	R-curl-[0-9]*:../../www/R-curl
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-ragg-[0-9]*:../../graphics/R-ragg
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-shiny-[0-9]*:../../www/R-shiny
TEST_DEPENDS+=	R-systemfonts-[0-9]*:../../fonts/R-systemfonts
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat


USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
