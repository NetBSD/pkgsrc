# $NetBSD: Makefile,v 1.1 2024/11/09 13:42:19 mef Exp $

R_PKGNAME=	doBy
R_PKGVER=	4.6.24

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Groupwise Statistics, LSmeans, Linear Estimates, Utilities
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-microbenchmark>=1.4.9:../../benchmarks/R-microbenchmark
DEPENDS+=	R-rlang>=1.1.4:../../devel/R-rlang
DEPENDS+=	R-cowplot>=1.1.3:../../graphics/R-cowplot
DEPENDS+=	R-ggplot2>=3.5.1:../../graphics/R-ggplot2
DEPENDS+=	R-Deriv>=4.1.6:../../math/R-Deriv
DEPENDS+=	R-broom>=1.0.7:../../math/R-broom
DEPENDS+=	R-dplyr>=1.1.4:../../math/R-dplyr
DEPENDS+=	R-modelr>=0.1.11:../../math/R-modelr
DEPENDS+=	R-tibble>=3.2.1:../../math/R-tibble
DEPENDS+=	R-tidyr>=1.3.1:../../math/R-tidyr

# Packages suggested but not available:
#  'geepack', 'multcomp'
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-lme4-[0-9]*:../../math/R-lme4
TEST_DEPENDS+=	R-markdown-[0-9]*:../../textproc/R-markdown
TEST_DEPENDS+=	R-pbkrtest-[0-9]*:../../math/R-pbkrtest

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
