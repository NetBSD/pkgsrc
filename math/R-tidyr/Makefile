# $NetBSD: Makefile,v 1.7 2023/06/13 11:26:27 mef Exp $

R_PKGNAME=	tidyr
R_PKGVER=	1.3.0

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Easily tidy data with 'spread()' and 'gather()' functions
LICENSE=	mit

DEPENDS+=	R-cli>=3.4.1:../../math/R-dplyr
DEPENDS+=	R-dplyr>=1.0.10:../../math/R-dplyr
DEPENDS+=	R-ellipsis>=0.1.0:../../math/R-ellipsis
DEPENDS+=	R-glue>=1.3.1:../../devel/R-glue
DEPENDS+=	R-lifecycle>=1.0.3:../../devel/R-lifecycle
DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-purrr>=1.0.1:../../devel/R-purrr
DEPENDS+=	R-rlang>=1.0.4:../../devel/R-rlang
DEPENDS+=	R-stringi>=1.5.0:../../textproc/R-stringi
DEPENDS+=	R-stringr>=1.5.0:../../textproc/R-stringr
DEPENDS+=	R-tibble>=2.1.1:../../math/R-tibble
DEPENDS+=	R-tidyselect>=1.2.0:../../devel/R-tidyselect
DEPENDS+=	R-vctrs>=0.5.2:../../math/R-vctrs

# Package suggested but not available: 'repurrrsive'
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-data.table-[0-9]*:../../textproc/R-data.table
TEST_DEPENDS+=	R-jsonlite-[0-9]*:../../textproc/R-jsonlite
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-readr-[0-9]*:../../textproc/R-readr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-dplyr-[0-9]*:../../math/R-dplyr
TEST_DEPENDS+=	R-purrr-[0-9]*:../../devel/R-purrr
TEST_DEPENDS+=	R-tidyselect-[0-9]*:../../devel/R-tidyselect

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../lang/R-cpp11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
