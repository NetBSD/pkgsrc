# $NetBSD: Makefile,v 1.3 2021/09/18 14:01:44 mef Exp $

R_PKGNAME=	tidyr
R_PKGVER=	1.1.3

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Easily tidy data with 'spread()' and 'gather()' functions
LICENSE=	mit

DEPENDS+=	R-glue>=1.3.1:../../devel/R-glue
DEPENDS+=	R-lifecycle>=0.1.0:../../devel/R-lifecycle
DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-purrr>=0.3.3:../../devel/R-purrr
DEPENDS+=	R-rlang>=0.4.5:../../devel/R-rlang
DEPENDS+=	R-tidyselect>=0.2.5:../../devel/R-tidyselect
DEPENDS+=	R-dplyr>=0.8.2:../../math/R-dplyr
DEPENDS+=	R-ellipsis>=0.1.0:../../math/R-ellipsis
DEPENDS+=	R-tibble>=2.1.3:../../math/R-tibble
DEPENDS+=	R-vctrs>=0.2.0:../../math/R-vctrs
DEPENDS+=	R-stringi>=1.4.6:../../textproc/R-stringi

# Package suggested but not available: 'repurrrsive'
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-data.table-[0-9]*:../../textproc/R-data.table
TEST_DEPENDS+=	R-jsonlite-[0-9]*:../../textproc/R-jsonlite
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-readr-[0-9]*:../../textproc/R-readr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../lang/R-cpp11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
