# $NetBSD: Makefile,v 1.4 2025/02/08 10:04:45 mef Exp $

R_PKGNAME=	rgl
R_PKGVER=	1.3.17
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	3D Visualization Using OpenGL
LICENSE=	gnu-gpl-v1 OR gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-crosstalk>=1.0.0:../../textproc/R-crosstalk
DEPENDS+=	R-htmltools>=0.3.6:../../textproc/R-htmltools
DEPENDS+=	R-htmlwidgets>=1.3:../../www/R-htmlwidgets
DEPENDS+=	R-jsonlite>=0.9.20:../../textproc/R-jsonlite
DEPENDS+=	R-knitr>=1.23:../../print/R-knitr
DEPENDS+=	R-magrittr>=2.0.1:../../devel/R-magrittr
DEPENDS+=	R-manipulateWidget-[0-9]*:../../graphics/R-manipulateWidget
DEPENDS+=	R-mathjaxr-[0-9]*:../../www/R-mathjaxr
DEPENDS+=	R-shiny>=1.3.2:../../www/R-shiny

# Packages suggested but not available:
#   'orientlib', 'misc3d', 'plotrix', 'tripack', 'alphashape3d', 'js',
#   'webshot2', 'extrafont', 'V8', 'chromote'

TEST_DEPENDS+=	R-akima-[0-9]*:../../math/R-akima
TEST_DEPENDS+=	R-deldir-[0-9]*:../../geography/R-deldir
TEST_DEPENDS+=	R-downlit-[0-9]*:../../www/R-downlit
TEST_DEPENDS+=	R-interp-[0-9]*:../../graphics/R-interp
TEST_DEPENDS+=	R-jpeg-[0-9]*:../../graphics/R-jpeg
TEST_DEPENDS+=	R-magick-[0-9]*:../../graphics/R-magick
TEST_DEPENDS+=	R-markdown-[0-9]*:../../textproc/R-markdown
TEST_DEPENDS+=	R-pkgdown-[0-9]*:../../www/R-pkgdown
TEST_DEPENDS+=	R-png-[0-9]*:../../graphics/R-png
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat


USE_LANGUAGES=	c c++

.include "../../graphics/png/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
