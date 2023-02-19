# $NetBSD: Makefile,v 1.3 2023/02/19 12:15:54 mef Exp $

R_PKGNAME=	dbplyr
R_PKGVER=	2.3.0

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Database backend for dplyr
LICENSE=	mit

DEPENDS+=	R-assertthat-[0-9]*:../../devel/R-assertthat
DEPENDS+=	R-blob-[0-9]*:../../devel/R-blob
DEPENDS+=	R-DBI-[0-9]*:../../math/R-DBI
DEPENDS+=	R-dplyr-[0-9]*:../../math/R-dplyr
DEPENDS+=	R-ellipsis-[0-9]*:../../math/R-ellipsis
DEPENDS+=	R-glue-[0-9]*:../../devel/R-glue
DEPENDS+=	R-lifecycle-[0-9]*:../../devel/R-lifecycle
DEPENDS+=	R-magrittr-[0-9]*:../../devel/R-magrittr
DEPENDS+=	R-purrr-[0-9]*:../../devel/R-purrr
DEPENDS+=	R-R6-[0-9]*:../../devel/R-R6
DEPENDS+=	R-rlang-[0-9]*:../../devel/R-rlang
DEPENDS+=	R-tibble-[0-9]*:../../math/R-tibble
DEPENDS+=	R-tidyselect-[0-9]*:../../devel/R-tidyselect
DEPENDS+=	R-vctrs-[0-9]*:../../math/R-vctrs
DEPENDS+=	R-withr-[0-9]*:../../devel/R-withr

# Packages suggested but not available for checking:
#   'Lahman', 'nycflights13', 'odbc', 'RMariaDB', 'RPostgres',
#   'RPostgreSQL'
TEST_DEPENDS+=	R-bit64-[0-9]*:../../devel/R-bit64
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-RSQLite-[0-9]*:../../databases/R-RSQLite
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-tidyr-[0-9]*:../../math/R-tidyr
TEST_DEPENDS+=	tex-texlive.infra-[0-9]*:../../print/tex-texlive.infra

USE_LANGUAGES=	c c++

# Packages suggested but not available:
# 'bit64', 'covr', 'Lahman', 'nycflights13', 'odbc',
# 'RMariaDB', 'rmarkdown', 'RPostgres', 'RPostgreSQL', 'RSQLite',
# 'testthat', 'tidyr'
TEST_ENV+=	_R_CHECK_FORCE_SUGGESTS_=0

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
