# $NetBSD: Makefile,v 1.12 2024/12/07 03:34:25 mef Exp $

R_PKGNAME=	magick
R_PKGVER=	2.8.5
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Advanced Graphics and Image-Processing in R
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-magrittr>=2.0.3:../../devel/R-magrittr
DEPENDS+=	R-curl>=5.0.0nb2:../../www/R-curl

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

# Packages suggested but not available:
#   'av', 'rsvg', 'webp', 'pdftools', 'gapminder', 'tesseract', 'gifski'

TEST_DEPENDS+=	R-IRdisplay-[0-9]*:../../devel/R-IRdisplay
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
TEST_DEPENDS+=	R-jsonlite-[0-9]*:../../textproc/R-jsonlite
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-spelling-[0-9]*:../../textproc/R-spelling

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
