# $NetBSD: Makefile,v 1.2 2024/12/07 02:51:45 mef Exp $

R_PKGNAME=	isoband
R_PKGVER=	0.2.7
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Generate Isolines and Isobands from Regularly Spaced Elevation Grids
LICENSE=	mit	# + file LICENSE

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
TEST_DEPENDS+=	R-magick-[0-9]*:../../graphics/R-magick
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-microbenchmark-[0-9]*:../../benchmarks/R-microbenchmark
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-sf-[0-9]*:../../geography/R-sf
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-xml2-[0-9]*:../../textproc/R-xml2

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	c++

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
