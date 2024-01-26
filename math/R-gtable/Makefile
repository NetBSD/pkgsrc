# $NetBSD: Makefile,v 1.6 2024/01/26 14:00:12 mef Exp $

R_PKGNAME=	gtable
R_PKGVER=	0.3.4

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Arrange 'Grobs' in tables
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-cli-[0-9]*:../../devel/R-cli
DEPENDS+=	R-glue-[0-9]*:../../devel/R-glue
DEPENDS+=	R-lifecycle-[0-9]*:../../devel/R-lifecycle
DEPENDS+=	R-rlang>=1.0.0:../../devel/R-rlang

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-profvis-[0-9]*:../../benchmarks/R-profvis
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

# !pdfTeX error: pdflatex (file tcrm1000): Font tcrm1000 at 600 not found
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
