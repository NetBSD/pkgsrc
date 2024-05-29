# $NetBSD: Makefile,v 1.20 2024/05/29 16:33:26 adam Exp $

R_PKGNAME=	igraph
R_PKGVER=	1.6.0
CATEGORIES+=	graphics

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Network analysis and visualization
PKGREVISION=	1
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-cli-[0-9]*:../../devel/R-cli
DEPENDS+=	R-lifecycle-[0-9]*:../../devel/R-lifecycle
DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-pkgconfig>=2.0.0:../../devel/R-pkgconfig
DEPENDS+=	R-rlang-[0-9]*:../../devel/R-rlang

# Packages suggested but not available:
#  'ape', 'decor', 'graph', 'igraphdata', 'vdiffr'

TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rgl-[0-9]*:../../graphics/R-rgl
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-scales-[0-9]*:../../graphics/R-scales
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-withr-[0-9]*:../../devel/R-withr


USE_LANGUAGES=	c c++ fortran

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../lang/R-cpp11/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
