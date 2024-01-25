# $NetBSD: Makefile,v 1.6 2024/01/25 22:10:00 mef Exp $

R_PKGNAME=	compositions
R_PKGVER=	2.0-7

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Compositional data analysis
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-bayesm>=3.1.3:../../finance/R-bayesm
DEPENDS+=	R-energy>=1.7.6:../../math/R-energy
DEPENDS+=	R-robustbase>=0.93.5:../../math/R-robustbase
DEPENDS+=	R-tensorA>=0.36.1:../../math/R-tensorA

# Packages suggested but not available: 'rgl'
TEST_DEPENDS+=	R-rgl-[0-9]*:../../graphics/R-rgl
TEST_DEPENDS+=	R-combinat-[0-9]*:../../math/R-combinat
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rgl-[0-9]*:../../graphics/R-rgl
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown

# !pdfTeX error: pdflatex (file ecbx1200): Font ecbx1200 at 600 not found
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-ntgclass-[0-9]*:../../print/tex-ntgclass
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
