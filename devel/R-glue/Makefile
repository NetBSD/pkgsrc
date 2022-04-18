# $NetBSD: Makefile,v 1.7 2022/04/18 14:05:03 mef Exp $

R_PKGNAME=	glue
R_PKGVER=	1.6.2
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Interpreted string literals
LICENSE=	mit

# Packages suggested but not available:
#   'rprintf'
TEST_DEPENDS+=	R-microbenchmark-[0-9]*:../../benchmarks/R-microbenchmark
TEST_DEPENDS+=	R-dplyr-[0-9]*:../../math/R-dplyr
TEST_DEPENDS+=	R-DBI-[0-9]*:../../math/R-DBI
TEST_DEPENDS+=	R-forcats-[0-9]*:../../math/R-forcats
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
TEST_DEPENDS+=	R-R.utils-[0-9]*:../../devel/R-R.utils
TEST_DEPENDS+=	R-RSQLite-[0-9]*:../../databases/R-RSQLite
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-waldo-[0-9]*:../../devel/R-waldo

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
