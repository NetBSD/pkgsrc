# $NetBSD: Makefile,v 1.2 2025/01/02 11:14:07 mef Exp $

R_PKGNAME=	dtplyr
R_PKGVER=	1.3.1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Data Table Back-End for 'dplyr'
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-glue>=1.6.2:../../devel/R-glue
DEPENDS+=	R-lifecycle>=1.0.1:../../devel/R-lifecycle
DEPENDS+=	R-rlang>=0.4.11:../../devel/R-rlang
DEPENDS+=	R-tidyselect>=1.1.1:../../devel/R-tidyselect
DEPENDS+=	R-dplyr>=1.0.3:../../math/R-dplyr
DEPENDS+=	R-ellipsis>=0.3.2:../../math/R-ellipsis
DEPENDS+=	R-tibble>=3.1.4:../../math/R-tibble
DEPENDS+=	R-vctrs>=0.3.8:../../math/R-vctrs
DEPENDS+=	R-data.table>=1.13.0:../../textproc/R-data.table

TEST_DEPENDS+=	R-bench-[0-9]*:../../benchmarks/R-bench
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-tidyr-[0-9]*:../../math/R-tidyr

# !pdfTeX error: pdflatex (file tctt0900): Font tctt0900 at 600 not found
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
