# $NetBSD: Makefile,v 1.1 2021/09/18 23:05:34 mef Exp $

R_PKGNAME=	broom
R_PKGVER=	0.7.9

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Convert Statistical Objects into Tidy Tibbles
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-glue>=1.4.2:../../devel/R-glue
DEPENDS+=	R-purrr>=0.3.4:../../devel/R-purrr
DEPENDS+=	R-rlang>=0.4.11:../../devel/R-rlang
DEPENDS+=	R-backports>=1.2.1:../../math/R-backports
DEPENDS+=	R-dplyr>=1.0.0:../../math/R-dplyr
DEPENDS+=	R-ellipsis>=0.3.2:../../math/R-ellipsis
DEPENDS+=	R-generics>=0.0.2:../../math/R-generics
DEPENDS+=	R-tibble>=3.0.0:../../math/R-tibble
DEPENDS+=	R-tidyr>=1.1.3:../../math/R-tidyr
DEPENDS+=	R-stringr>=1.4.0:../../textproc/R-stringr

# Packages suggested but not available:
#   'AER', 'AUC', 'bbmle', 'betareg', 'biglm', 'binGroup', 'btergm',
#   'caret', 'cmprsk', 'coda', 'drc', 'emmeans', 'epiR', 'ergm',
#   'fixest', 'gam', 'gee', 'geepack', 'glmnet', 'glmnetUtils', 'gmm',
#   'irlba', 'joineRML', 'Kendall', 'ks', 'Lahman', 'lavaan', 'leaps',
#   'lfe', 'lm.beta', 'lmodel2',  'lsmeans', 'margins',
#   'mclust', 'mediation', 'metafor', 'mfx', 'mlogit', 'modeldata',
#   'modeltests', 'muhaz', 'multcomp', 'network', 'orcutt', 'ordinal',
#   'plm', 'poLCA', 'psych', 'quantreg', 'robust', 'robustbase',
#   'rsample', 'spdep', 'spatialreg', 'speedglm', 'systemfit',
#   'tseries', 'vars'


TEST_DEPENDS+=	R-maps-[0-9]*:../../geography/R-maps
TEST_DEPENDS+=	R-maptools-[0-9]*:../../geography/R-maptools
TEST_DEPENDS+=	R-rgeos-[0-9]*:../../geography/R-rgeos
TEST_DEPENDS+=	R-akima-[0-9]*:../../math/R-akima
TEST_DEPENDS+=	R-lmtest-[0-9]*:../../math/R-lmtest
TEST_DEPENDS+=	R-car-[0-9]*:../../math/R-car
TEST_DEPENDS+=	R-survey-[0-9]*:../../math/R-survey
TEST_DEPENDS+=	R-sandwich-[0-9]*:../../math/R-sandwich
TEST_DEPENDS+=	R-zoo-[0-9]*:../../math/R-zoo
TEST_DEPENDS+=	R-Hmisc-[0-9]*:../../misc/R-Hmisc
TEST_DEPENDS+=	R-spelling-[0-9]*:../../textproc/R-spelling

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
