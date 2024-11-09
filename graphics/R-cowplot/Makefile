# $NetBSD: Makefile,v 1.1 2024/11/09 13:09:42 mef Exp $

R_PKGNAME=	cowplot
R_PKGVER=	1.1.3
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Streamlined Plot Theme and Plot Annotations for 'ggplot2'
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-rlang>=1.1.4:../../devel/R-rlang
DEPENDS+=	R-ggplot2>=3.4.0:../../graphics/R-ggplot2
DEPENDS+=	R-scales>=1.3.0:../../graphics/R-scales
DEPENDS+=	R-gtable>=0.3.6:../../math/R-gtable

# Packages suggested but not available:
#   'gridGraphics', 'PASWR', 'patchwork', 'vdiffr', 'VennDiagram'

TEST_DEPENDS+=	R-Cairo-[0-9]*:../../graphics/R-Cairo
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-forcats-[0-9]*:../../math/R-forcats
TEST_DEPENDS+=	R-magick-[0-9]*:../../graphics/R-magick
TEST_DEPENDS+=	R-maps-[0-9]*:../../geography/R-maps
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-ragg-[0-9]*:../../graphics/R-ragg

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
