# $NetBSD: Makefile,v 1.2 2021/09/20 01:36:24 mef Exp $

R_PKGNAME=	ggExtra
R_PKGVER=	0.9
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Add marginal histograms to 'ggplot2', and more 'ggplot2' enhancements
LICENSE=	mit

DEPENDS+=	R-colourpicker>=1.0:../../graphics/R-colourpicker
DEPENDS+=	R-ggplot2>=2.2.0:../../graphics/R-ggplot2
DEPENDS+=	R-scales>=0.2.0:../../graphics/R-scales
DEPENDS+=	R-gtable>=0.2.0:../../math/R-gtable
DEPENDS+=	R-miniUI>=0.1.1:../../www/R-miniUI
DEPENDS+=	R-shiny>=0.13.0:../../www/R-shiny
DEPENDS+=	R-shinyjs>=0.5.2:../../www/R-shinyjs

#Packages suggested but not available:
#  'vdiffr','fontquiver', 'svglite'
TEST_DEPENDS+=	R-devtools-[0-9]*:../../devel/R-devtools
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-rstudioapi-[0-9]*:../../math/R-rstudioapi
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat


USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
