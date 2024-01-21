# $NetBSD: Makefile,v 1.10 2024/01/21 04:11:36 mef Exp $

R_PKGNAME=	dplyr
R_PKGVER=	1.1.4

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Grammar of data manipulation
LICENSE=	mit

DEPENDS+=	R-BH>=1.69.0.1:../../devel/R-BH
DEPENDS+=	R-R6>=2.4.0:../../devel/R-R6
DEPENDS+=	R-assertthat>=0.2.0:../../devel/R-assertthat
DEPENDS+=	R-cli>=3.4.0:../../devel/R-cli
#EPENDS+=	R-ellipsis>=0.3.0:../../math/R-ellipsis
DEPENDS+=	R-generics-[0-9]*:../../math/R-generics
DEPENDS+=	R-glue>=1.3.2:../../devel/R-glue
DEPENDS+=	R-lifecycle>=1.0.3:../../devel/R-lifecycle
DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
#EPENDS+=	R-methods-[0-9]*:../../devel/R-methods
DEPENDS+=	R-pillar>=1.9.0:../../misc/R-pillar
DEPENDS+=	R-pkgconfig>=2.0.2:../../devel/R-pkgconfig
DEPENDS+=	R-rlang>=1.1.0:../../devel/R-rlang
DEPENDS+=	R-tibble>=3.2.0:../../math/R-tibble
DEPENDS+=	R-tidyselect>=1.2.0:../../devel/R-tidyselect
DEPENDS+=	R-vctrs>=0.6.0:../../math/R-vctrs
DEPENDS+=	R-generics>=0.0.2:../../math/R-generics
DEPENDS+=	R-generics>=0.0.2:../../math/R-generics

# Packages suggested but not available:
#   'Lahman', 'lobstr', 'nycflights13', 'RMySQL'

TEST_DEPENDS+=	R-bench-[0-9]*:../../benchmarks/R-bench
TEST_DEPENDS+=	R-broom-[0-9]*:../../math/R-broom
TEST_DEPENDS+=	R-callr-[0-9]*:../../devel/R-callr
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-dbplyr-[0-9]*:../../databases/R-dbplyr
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
#TEST_DEPENDS+=	R-Lahman-[0-9]*:
#TEST_DEPENDS+=	R-lobstr-[0-9]*:
TEST_DEPENDS+=	R-microbenchmark-[0-9]*:../../benchmarks/R-microbenchmark
#TEST_DEPENDS+=	R-nycflights13-[0-9]*:
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
#TEST_DEPENDS+=	R-RMySQL-[0-9]*:
TEST_DEPENDS+=	R-RPostgreSQL-[0-9]*:../../math/R-RPostgreSQL
TEST_DEPENDS+=	R-RSQLite-[0-9]*:../../databases/R-RSQLite
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-tidyr-[0-9]*:../../math/R-tidyr
TEST_DEPENDS+=	R-withr-[0-9]*:../../devel/R-withr

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../devel/R-plogr/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
