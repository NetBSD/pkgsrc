# $NetBSD: Makefile,v 1.4 2021/06/12 22:36:14 mef Exp $

R_PKGNAME=	dplyr
R_PKGVER=	1.0.6

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
DEPENDS+=	R-vctrs>=0.3.0:../../math/R-vctrs

# Packages suggested but not available:
#   'bench', 'broom', 'dbplyr', 'Lahman', 'lobstr', 'microbenchmark',
#   'nycflights13', 'RMySQL', 'RPostgreSQL', 'RSQLite', 'tidyr'
TEST_DEPENDS+=	R-RSQLite-[0-9]*:../../databases/R-RSQLite
TEST_DEPENDS+=	R-dplyr-[0-9]*:../../math/R-dplyr
TEST_DEPENDS+=	R-microbenchmark-[0-9]*:../../benchmarks/R-microbenchmark
TEST_DEPENDS+=	R-tidyr-[0-9]*:../../math/R-tidyr

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../devel/R-plogr/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
