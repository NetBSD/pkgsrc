# $NetBSD: Makefile,v 1.5 2023/02/18 09:21:40 mef Exp $

R_PKGNAME=	cpp11
R_PKGVER=	0.4.3
CATEGORIES=	lang

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	C++11 Interface for R's C Interface
LICENSE=	mit	# + file LICENSE

# Packages suggested but not available: 'decor', 'lobstr'

TEST_DEPENDS+=	R-progress-[0-9]*:../../sysutils/R-progress
TEST_DEPENDS+=	R-bench-[0-9]*:../../benchmarks/R-bench
TEST_DEPENDS+=	R-brio-[0-9]*:../../devel/R-brio
TEST_DEPENDS+=	R-callr-[0-9]*:../../devel/R-callr
TEST_DEPENDS+=	R-cli-[0-9]*:../../devel/R-cli
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-desc-[0-9]*:../../devel/R-desc
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-mockery-[0-9]*:../../devel/R-mockery
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-scales-[0-9]*:../../graphics/R-scales
TEST_DEPENDS+=	R-Rcpp-[0-9]*:../../devel/R-Rcpp
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-tibble-[0-9]*:../../math/R-tibble
TEST_DEPENDS+=	R-withr-[0-9]*:../../devel/R-withr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
