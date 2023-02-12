# $NetBSD: Makefile,v 1.8 2023/02/12 04:09:37 mef Exp $

R_PKGNAME=	dplyr
R_PKGVER=	1.1.0

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Grammar of data manipulation
LICENSE=	mit

DEPENDS+=	R-BH>=1.69.0.1:../../devel/R-BH
DEPENDS+=	R-R6>=2.4.0:../../devel/R-R6
DEPENDS+=	R-assertthat>=0.2.0:../../devel/R-assertthat
DEPENDS+=	R-glue>=1.3.2:../../devel/R-glue
DEPENDS+=	R-lifecycle>=0.2.0:../../devel/R-lifecycle
DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-pkgconfig>=2.0.2:../../devel/R-pkgconfig
DEPENDS+=	R-rlang>=0.4.6:../../devel/R-rlang
DEPENDS+=	R-tidyselect>=1.1.0:../../devel/R-tidyselect
DEPENDS+=	R-ellipsis>=0.3.0:../../math/R-ellipsis
DEPENDS+=	R-generics>=0.0.2:../../math/R-generics
DEPENDS+=	R-tibble>=2.1.3:../../math/R-tibble
DEPENDS+=	R-vctrs>=0.4.1:../../math/R-vctrs

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
