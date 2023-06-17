# $NetBSD: Makefile,v 1.3 2023/06/17 14:00:31 mef Exp $

R_PKGNAME=	vroom
R_PKGVER=	1.6.3
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Read and Write Rectangular Text Data Quickly
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-bit64>=4.0.5:../../devel/R-bit64
DEPENDS+=	R-cli>=2.5.0:../../devel/R-cli
DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon
DEPENDS+=	R-glue>=1.4.2:../../devel/R-glue
DEPENDS+=	R-lifecycle>=1.0.0:../../devel/R-lifecycle
DEPENDS+=	R-rlang>=0.4.2:../../devel/R-rlang
DEPENDS+=	R-tidyselect>=1.1.1:../../devel/R-tidyselect
DEPENDS+=	R-withr>=2.4.2:../../devel/R-withr
DEPENDS+=	R-tibble>=2.0.0:../../math/R-tibble
DEPENDS+=	R-vctrs>=0.2.0:../../math/R-vctrs
DEPENDS+=	R-hms>=1.1.0:../../time/R-hms
DEPENDS+=	R-progress-[0-9]*:../../sysutils/R-progress
DEPENDS+=	R-tzdb-[0-9]*:../../time/R-tzdb

#EST_DEPENDS+=	R-archive-[0-9]*:
TEST_DEPENDS+=	R-bench-[0-9]*:../../benchmarks/R-bench
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-curl-[0-9]*:../../www/R-curl
TEST_DEPENDS+=	R-dplyr-[0-9]*:../../math/R-dplyr
TEST_DEPENDS+=	R-forcats-[0-9]*:../../math/R-forcats
TEST_DEPENDS+=	R-fs-[0-9]*:../../devel/R-fs
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
#EST_DEPENDS+=	R-patchwork-[0-9]*:
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-rstudioapi-[0-9]*:../../math/R-rstudioapi
TEST_DEPENDS+=	R-scales-[0-9]*:../../graphics/R-scales
TEST_DEPENDS+=	R-spelling-[0-9]*:../../textproc/R-spelling
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-tidyr-[0-9]*:../../math/R-tidyr
TEST_DEPENDS+=	R-waldo-[0-9]*:../../devel/R-waldo
TEST_DEPENDS+=	R-xml2-[0-9]*:../../textproc/R-xml2

USE_LANGUAGES=	c c++11

REPLACE_BASH+=	inst/bench/download-data.sh inst/bench/script.sh
REPLACE_R+=	inst/bench/session_info.R inst/bench/run-bench.R inst/bench/run-bench-fwf.R

.include "../../lang/R-cpp11/buildlink3.mk"
.include "../../time/R-tzdb/buildlink3.mk"
.include "../../sysutils/R-progress/buildlink3.mk"

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
