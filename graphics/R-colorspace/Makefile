# $NetBSD: Makefile,v 1.5 2021/06/06 06:19:31 mef Exp $

R_PKGNAME=	colorspace
R_PKGVER=	2.0-1
CATEGORIES=	graphics

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Toolbox for manipulating and assessing colors and palettes
LICENSE=	modified-bsd

# Packages suggested but not available:
#  'kernlab', 'mvtnorm', 'vcd', 'shinyjs', 'ggplot2', 'dplyr',
#  'scales', 'png', 'jpeg', 'rcartocolor', 'scico', 'viridis',
#  'wesanderson'
TEST_DEPENDS+=	R-shiny-[0-9]*:../../www/R-shiny

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
