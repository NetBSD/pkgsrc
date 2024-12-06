# $NetBSD: Makefile,v 1.6 2024/12/06 22:55:26 mef Exp $

R_PKGNAME=	colorspace
R_PKGVER=	2.1-1
CATEGORIES=	graphics

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Toolbox for manipulating and assessing colors and palettes
LICENSE=	modified-bsd

# Packages suggested but not available:
#   'kernlab', 'vcd', 'rcartocolor', 'scico', 'wesanderson'

TEST_DEPENDS+=	R-dplyr-[0-9]*:../../math/R-dplyr
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
TEST_DEPENDS+=	R-jpeg-[0-9]*:../../graphics/R-jpeg
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-mvtnorm-[0-9]*:../../math/R-mvtnorm
TEST_DEPENDS+=	R-png-[0-9]*:../../graphics/R-png
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-RColorBrewer-[0-9]*:../../math/R-RColorBrewer
TEST_DEPENDS+=	R-scales-[0-9]*:../../graphics/R-scales
TEST_DEPENDS+=	R-shiny-[0-9]*:../../www/R-shiny
TEST_DEPENDS+=	R-shinyjs-[0-9]*:../../www/R-shinyjs
TEST_DEPENDS+=	R-viridis-[0-9]*:../../graphics/R-viridis

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
