# $NetBSD: Makefile,v 1.1 2022/04/23 05:09:51 mef Exp $

R_PKGNAME=	dtplyr
R_PKGVER=	1.2.1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Data Table Back-End for 'dplyr'
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-crayon>=1.3.4:../../devel/R-crayon
DEPENDS+=	R-glue>=1.6.2:../../devel/R-glue
DEPENDS+=	R-lifecycle>=1.0.1:../../devel/R-lifecycle
DEPENDS+=	R-rlang>=0.4.11:../../devel/R-rlang
DEPENDS+=	R-tidyselect>=1.1.1:../../devel/R-tidyselect
DEPENDS+=	R-dplyr>=1.0.3:../../math/R-dplyr
DEPENDS+=	R-ellipsis>=0.3.2:../../math/R-ellipsis
DEPENDS+=	R-tibble>=3.1.4:../../math/R-tibble
DEPENDS+=	R-vctrs>=0.3.8:../../math/R-vctrs
DEPENDS+=	R-data.table>=1.13.0:../../textproc/R-data.table

# Package suggested but not available: 'bench'
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
