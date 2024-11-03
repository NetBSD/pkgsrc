# $NetBSD: Makefile,v 1.6 2024/11/03 13:25:17 mef Exp $

R_PKGNAME=	insight
R_PKGVER=	0.20.5

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Easy Access to Model Information for Various Model Objects
LICENSE=	gnu-gpl-v3

# Packages suggested but not available:
#   'AER', 'afex', 'aod', 'BayesFactor', 'bayestestR', 'betareg', 'bife',
#   'blavaan', 'blme', 'brms', 'censReg', 'cgam', 'clubSandwich',
#   'cobalt', 'coxme', 'cplm', 'crch', 'datawizard', 'effectsize',
#   'emmeans', 'epiR', 'estimatr', 'feisr', 'fixest', 'fungible', 'fwb',
#   'gam', 'gamlss', 'gamlss.data', 'gamm4', 'gbm', 'gee', 'geepack',
#   'ggeffects', 'GLMMadaptive', 'glmmTMB', 'glmtoolbox', 'gmnl', 'gt',
#   'httptest2', 'httr2', 'ivreg', 'JM', 'lavaan', 'lavaSearch2', 'lfe',
#   'lmerTest', 'logistf', 'logitr', 'marginaleffects', 'mclogit',
#   'MCMCglmm', 'merTools', 'metaBMA', 'metadat', 'metafor', 'metaplus',
#   'mice', 'mlogit', 'mmrm', 'modelbased', 'multgee', 'MuMIn',
#   'nestedLogit', 'nonnest2', 'ordinal', 'panelr', 'parameters',
#   'parsnip', 'performance', 'plm', 'poorman', 'PROreg', 'pscl', 'rms',
#   'robustlmm', 'rstanarm', 'rstantools', 'serp', 'speedglm', 'svylme',
#   'tinytable', 'TMB', 'truncreg', 'tweedie', 'WeightIt'

TEST_DEPENDS+=	R-VGAM-[0-9]*:../../math/R-VGAM
TEST_DEPENDS+=	R-biglm-[0-9]*:../../sysutils/R-biglm
TEST_DEPENDS+=	R-broom-[0-9]*:../../math/R-broom
TEST_DEPENDS+=	R-car-[0-9]*:../../math/R-car
TEST_DEPENDS+=	R-carData-[0-9]*:../../math/R-carData
TEST_DEPENDS+=	R-dplyr-[0-9]*:../../math/R-dplyr
TEST_DEPENDS+=	R-geoR-[0-9]*:../../math/R-geoR
TEST_DEPENDS+=	R-httr-[0-9]*:../../www/R-httr
TEST_DEPENDS+=	R-interp-[0-9]*:../../graphics/R-interp
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-lme4-[0-9]*:../../math/R-lme4
TEST_DEPENDS+=	R-lmtest-[0-9]*:../../math/R-lmtest
TEST_DEPENDS+=	R-mclust-[0-9]*:../../math/R-mclust
TEST_DEPENDS+=	R-pbkrtest-[0-9]*:../../math/R-pbkrtest
TEST_DEPENDS+=	R-psych-[0-9]*:../../math/R-psych
TEST_DEPENDS+=	R-quantreg-[0-9]*:../../math/R-quantreg
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-robustbase-[0-9]*:../../math/R-robustbase
TEST_DEPENDS+=	R-rstudioapi-[0-9]*:../../math/R-rstudioapi
TEST_DEPENDS+=	R-sandwich-[0-9]*:../../math/R-sandwich
TEST_DEPENDS+=	R-spelling-[0-9]*:../../textproc/R-spelling
TEST_DEPENDS+=	R-statmod-[0-9]*:../../math/R-statmod
TEST_DEPENDS+=	R-survey-[0-9]*:../../math/R-survey
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat


USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
