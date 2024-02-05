# $NetBSD: Makefile,v 1.6 2024/02/05 20:37:59 mef Exp $

R_PKGNAME=	poweRlaw
R_PKGVER=	0.80.0

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Analysis of heavy tailed distributions
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-VGAM>=1.1.1:../../math/R-VGAM
DEPENDS+=	R-pracma-[0-9]*:../../math/R-pracma

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

# !pdfTeX error: pdflatex (file tcrm1095): Font tcrm1095 at 600 not found
TEST_DEPENDS+=	tex-bookmark-[0-9]*:../../print/tex-bookmark
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-framed-[0-9]*:../../print/tex-framed
TEST_DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-koma-script-[0-9]*:../../print/tex-koma-script
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-natbib-[0-9]*:../../print/tex-natbib
TEST_DEPENDS+=	tex-thumbpdf-[0-9]*:../../print/tex-thumbpdf
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
