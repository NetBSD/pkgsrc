# $NetBSD: Makefile,v 1.3 2024/12/07 03:22:45 mef Exp $

R_PKGNAME=	latex2exp
R_PKGVER=	0.9.6
CATEGORIES=	graphics textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Use LaTeX expressions in plots
LICENSE=	mit

DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-stringr>=1.4.0:../../textproc/R-stringr

# Package suggested but not available: 'reactable'

TEST_DEPENDS+=	R-RCurl-[0-9]*:../../www/R-RCurl
TEST_DEPENDS+=	R-dplyr-[0-9]*:../../math/R-dplyr
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
TEST_DEPENDS+=	R-htmltools-[0-9]*:../../textproc/R-htmltools
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-purrr-[0-9]*:../../devel/R-purrr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-tibble-[0-9]*:../../math/R-tibble
TEST_DEPENDS+=	R-waldo-[0-9]*:../../devel/R-waldo

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
