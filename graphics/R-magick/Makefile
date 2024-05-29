# $NetBSD: Makefile,v 1.4 2024/05/29 16:32:49 adam Exp $

R_PKGNAME=	magick
R_PKGVER=	2.8.3
PKGREVISION=	3
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Advanced Graphics and Image-Processing in R
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-magrittr>=2.0.3:../../devel/R-magrittr
DEPENDS+=	R-curl>=5.0.0nb2:../../www/R-curl

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

# Packages suggested but not available:
#   'av', 'rsvg', 'webp', 'pdftools', 'gapminder', 'IRdisplay',
#   'tesseract', 'gifski'

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
