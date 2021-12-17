# $NetBSD: Makefile,v 1.1 2021/12/17 10:07:56 wiz Exp $

R_PKGNAME=	dbplyr
R_PKGVER=	2.1.1

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
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr

USE_LANGUAGES=	c c++

# Packages suggested but not available:
# 'bit64', 'covr', 'Lahman', 'nycflights13', 'odbc',
# 'RMariaDB', 'rmarkdown', 'RPostgres', 'RPostgreSQL', 'RSQLite',
# 'testthat', 'tidyr'
TEST_ENV+=	_R_CHECK_FORCE_SUGGESTS_=0

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
