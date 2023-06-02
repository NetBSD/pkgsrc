# $NetBSD: Makefile,v 1.12 2023/06/02 12:49:09 mef Exp $

R_PKGNAME=	tibble
R_PKGVER=	3.2.1

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Simple data frames
LICENSE=	mit

DEPENDS+=	R-cli>=1.1.0:../../devel/R-cli
DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon
DEPENDS+=	R-fansi>=0.4.0:../../devel/R-fansi
DEPENDS+=	R-pkgconfig>=2.0.2:../../devel/R-pkgconfig
DEPENDS+=	R-rlang>=0.3.0:../../devel/R-rlang
DEPENDS+=	R-pillar>=1.7.0:../../misc/R-pillar
DEPENDS+=	R-lifecycle-[0-9]*:../../devel/R-lifecycle
DEPENDS+=	R-magrittr-[0-9]*:../../devel/R-magrittr

# Packages suggested but not available:
#   'DiagrammeR', 'formattable', 'nycflights13'

TEST_DEPENDS+=	R-bench-[0-9]*:../../benchmarks/R-bench
TEST_DEPENDS+=	R-bit64-[0-9]*:../../devel/R-bit64
TEST_DEPENDS+=	R-blob-[0-9]*:../../devel/R-blob
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-dplyr-[0-9]*:../../math/R-dplyr
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
TEST_DEPENDS+=	R-hms-[0-9]*:../../time/R-hms
TEST_DEPENDS+=	R-htmltools-[0-9]*:../../textproc/R-htmltools
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-lubridate-[0-9]*:../../time/R-lubridate
TEST_DEPENDS+=	R-mockr-[0-9]*:../../devel/R-mockr
TEST_DEPENDS+=	R-purrr-[0-9]*:../../devel/R-purrr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-tidyr-[0-9]*:../../math/R-tidyr

.include "../../lang/R-cpp11/buildlink3.mk"
.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
