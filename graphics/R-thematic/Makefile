# $NetBSD: Makefile,v 1.1 2021/06/08 01:40:35 mef Exp $

R_PKGNAME=	thematic
R_PKGVER=	0.1.2
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
#   'sysfonts', 'showtext', 'Cairo', 'systemfonts', 'ragg',
#   'gganimate', 'vdiffr', 'svglite'
TEST_DEPENDS+=	R-bslib-[0-9]*:../../www/R-bslib
TEST_DEPENDS+=	R-shiny-[0-9]*:../../www/R-shiny
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat


USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
