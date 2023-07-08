# $NetBSD: Makefile,v 1.4 2023/07/08 04:31:42 mef Exp $

R_PKGNAME=	insight
R_PKGVER=	0.19.3

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Easy Access to Model Information for Various Model Objects
LICENSE=	gnu-gpl-v3

# Packages suggested but not available:
#   'AER', 'afex', 'aod', 'BayesFactor', 'bayestestR', 'betareg', 'bife',
#   'biglm', 'blavaan', 'blme', 'brms', 'broom', 'car', 'carData',
#   'censReg', 'cgam', 'clubSandwich', 'coxme', 'cplm', 'crch',
#   'datawizard', 'effectsize', 'emmeans', 'epiR', 'estimatr', 'feisr',
#   'fixest', 'fungible', 'gam', 'gamlss', 'gamlss.data', 'gamm4', 'gbm',
#   'gee', 'geepack', 'geoR', 'GLMMadaptive', 'glmmTMB', 'gmnl', 'gt',
#   'interp', 'ivreg', 'JM', 'lavaan', 'lavaSearch2', 'lfe', 'lmerTest',
#   'MCMCglmm', 'merTools', 'metaBMA', 'metadat', 'metafor', 'metaplus',
#   'mice', 'mlogit', 'mhurdle', 'mmrm', 'multgee', 'nestedLogit',
#   'nonnest2', 'ordinal', 'parameters', 'parsnip', 'pbkrtest',
#   'performance', 'plm', 'poorman', 'pscl', 'rms', 'robustlmm',
#   'rstanarm', 'rstantools', 'speedglm', 'truncreg', 'tweedie', 'TMB'


TEST_DEPENDS+=	R-VGAM-[0-9]*:../../math/R-VGAM
TEST_DEPENDS+=	R-bbmle-[0-9]*:../../math/R-bbmle
TEST_DEPENDS+=	R-dplyr-[0-9]*:../../math/R-dplyr
TEST_DEPENDS+=	R-httr-[0-9]*:../../www/R-httr
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-lme4-[0-9]*:../../math/R-lme4
TEST_DEPENDS+=	R-lmtest-[0-9]*:../../math/R-lmtest
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
