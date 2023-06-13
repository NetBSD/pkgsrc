# $NetBSD: Makefile,v 1.4 2023/06/13 14:03:02 mef Exp $

R_PKGNAME=	broom
R_PKGVER=	1.0.5

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
DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2

#EST_DEPENDS+=	R-AER-[0-9]*:
TEST_DEPENDS+=	R-akima-[0-9]*:../../math/R-akima
#EST_DEPENDS+=	R-AUC-[0-9]*:
TEST_DEPENDS+=	R-bbmle-[0-9]*:../../math/R-bbmle
#EST_DEPENDS+=	R-betareg-[0-9]*:
#EST_DEPENDS+=	R-biglm-[0-9]*:
#EST_DEPENDS+=	R-binGroup-[0-9]*:
#EST_DEPENDS+=	R-btergm-[0-9]*:
TEST_DEPENDS+=	R-car-[0-9]*:../../math/R-car
#EST_DEPENDS+=	R-caret-[0-9]*:
#EST_DEPENDS+=	R-cmprsk-[0-9]*:
TEST_DEPENDS+=	R-coda-[0-9]*:../../math/R-coda
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
#EST_DEPENDS+=	R-drc-[0-9]*:
TEST_DEPENDS+=	R-e1071-[0-9]*:../../math/R-e1071
#EST_DEPENDS+=	R-emmeans-[0-9]*:
#EST_DEPENDS+=	R-epiR-[0-9]*:
#EST_DEPENDS+=	R-ergm-[0-9]*:
#EST_DEPENDS+=	R-fixest-[0-9]*:
#EST_DEPENDS+=	R-gam-[0-9]*:
#EST_DEPENDS+=	R-gee-[0-9]*:
#EST_DEPENDS+=	R-geepack-[0-9]*:
#EST_DEPENDS+=	R-glmnet-[0-9]*:
#EST_DEPENDS+=	R-glmnetUtils-[0-9]*:
#EST_DEPENDS+=	R-gmm-[0-9]*:
TEST_DEPENDS+=	R-Hmisc-[0-9]*:../../misc/R-Hmisc
#EST_DEPENDS+=	R-irlba-[0-9]*:
#EST_DEPENDS+=	R-joineRML-[0-9]*:
#EST_DEPENDS+=	R-Kendall-[0-9]*:
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
#EST_DEPENDS+=	R-ks-[0-9]*:
#EST_DEPENDS+=	R-Lahman-[0-9]*:
#EST_DEPENDS+=	R-lavaan-[0-9]*:
#EST_DEPENDS+=	R-leaps-[0-9]*:
#EST_DEPENDS+=	R-lfe-[0-9]*:
#EST_DEPENDS+=	R-lm.beta-[0-9]*:
TEST_DEPENDS+=	R-lme4-[0-9]*:../../math/R-lme4
#EST_DEPENDS+=	R-lmodel2-[0-9]*:
TEST_DEPENDS+=	R-lmtest-[0-9]*:../../math/R-lmtest
#EST_DEPENDS+=	R-lsmeans-[0-9]*:
TEST_DEPENDS+=	R-maptools-[0-9]*:../../geography/R-maptools
#EST_DEPENDS+=	R-margins-[0-9]*:
#EST_DEPENDS+=	R-mclust-[0-9]*:../../wip/R-mclust
#EST_DEPENDS+=	R-mediation-[0-9]*:
#EST_DEPENDS+=	R-metafor-[0-9]*:
#EST_DEPENDS+=	R-mfx-[0-9]*:
#EST_DEPENDS+=	R-mlogit-[0-9]*:
#EST_DEPENDS+=	R-modeldata-[0-9]*:
#EST_DEPENDS+=	R-modeltests-[0-9]*:
#EST_DEPENDS+=	R-muhaz-[0-9]*:
#EST_DEPENDS+=	R-multcomp-[0-9]*:
#EST_DEPENDS+=	R-network-[0-9]*:
#EST_DEPENDS+=	R-orcutt-[0-9]*:
#EST_DEPENDS+=	R-ordinal-[0-9]*:
#EST_DEPENDS+=	R-plm-[0-9]*:
#EST_DEPENDS+=	R-poLCA-[0-9]*:
TEST_DEPENDS+=	R-psych-[0-9]*:../../math/R-psych
TEST_DEPENDS+=	R-quantreg-[0-9]*:../../math/R-quantreg
TEST_DEPENDS+=	R-rgeos-[0-9]*:../../geography/R-rgeos
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
#EST_DEPENDS+=	R-robust-[0-9]*:
TEST_DEPENDS+=	R-robustbase-[0-9]*:../../math/R-robustbase
#EST_DEPENDS+=	R-rsample-[0-9]*:
TEST_DEPENDS+=	R-sandwich-[0-9]*:../../math/R-sandwich
TEST_DEPENDS+=	R-sp-[0-9]*:../../math/R-sp
#EST_DEPENDS+=	R-spdep-[0-9]*:
#EST_DEPENDS+=	R-spatialreg-[0-9]*:
#EST_DEPENDS+=	R-speedglm-[0-9]*:
TEST_DEPENDS+=	R-spelling-[0-9]*:../../textproc/R-spelling
TEST_DEPENDS+=	R-survey-[0-9]*:../../math/R-survey
#EST_DEPENDS+=	R-systemfit-[0-9]*:
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-tseries-[0-9]*:../../finance/R-tseries
#EST_DEPENDS+=	R-vars-[0-9]*:
TEST_DEPENDS+=	R-zoo-[0-9]*:../../math/R-zoo

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
