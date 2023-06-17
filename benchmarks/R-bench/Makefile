# $NetBSD: Makefile,v 1.3 2023/06/17 13:53:52 mef Exp $

R_PKGNAME=	bench
R_PKGVER=	1.1.3
CATEGORIES=	benchmarks

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	High Precision Timing of R Expressions
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-glue>=1.6.2:../../devel/R-glue
DEPENDS+=	R-profmem-[0-9]*:../../benchmarks/R-profmem
DEPENDS+=	R-rlang>=0.2.0:../../devel/R-rlang
DEPENDS+=	R-tibble>=3.0.1:../../math/R-tibble
DEPENDS+=	R-pillar>=1.6.2:../../misc/R-pillar

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-dplyr-[0-9]*:../../math/R-dplyr
TEST_DEPENDS+=	R-forcats-[0-9]*:../../math/R-forcats
#EST_DEPENDS+=	R-ggbeeswarm-[0-9]*:
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2
#EST_DEPENDS+=	R-ggridgesjsonlite-[0-9]*:
TEST_DEPENDS+=	R-scales-[0-9]*:../../graphics/R-scales
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-tidyr-[0-9]*:../../math/R-tidyr
TEST_DEPENDS+=	R-withr-[0-9]*:../../devel/R-withr

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
