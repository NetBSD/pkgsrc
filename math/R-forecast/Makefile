# $NetBSD: Makefile,v 1.9 2026/06/15 14:43:47 mef Exp $

R_PKGNAME=	forecast
R_PKGVER=	9.0.2

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Forecasting functions for time series and linear models
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr
DEPENDS+=	R-tseries>=0.10.47:../../finance/R-tseries
DEPENDS+=	R-colorspace>=1.4.1:../../graphics/R-colorspace
DEPENDS+=	R-ggplot2>=2.2.1:../../graphics/R-ggplot2
DEPENDS+=	R-fracdiff>=1.4.2:../../math/R-fracdiff
DEPENDS+=	R-lmtest>=0.9.37:../../math/R-lmtest
DEPENDS+=	R-urca>=1.3.0:../../math/R-urca
DEPENDS+=	R-zoo>=1.8.6:../../math/R-zoo
DEPENDS+=	R-timeDate>=3043.102:../../time/R-timeDate
DEPENDS+=	R-generics>=0.1.2:../../math/R-generics

# Packages suggested but not available:
#   'forecTheta', 'rticles', 'seasonal', 'uroot'
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	c c++ fortran
GCC_REQD+=	8

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		pkglibs
SUBST_STAGE.pkglibs=	pre-configure
SUBST_FILES.pkglibs=	src/Makevars
SUBST_MESSAGE.pkglibs=	Add -lexecinfo for *BSD
.if ${OPSYS} != SunOS && ${OPSYS} != Linux
SUBST_SED.pkglibs=	-e s,@@PKG_LIBS@@,PKG_LIBS+=-lexecinfo,
.else
SUBST_SED.pkglibs=	-e s,@@PKG_LIBS@@,,
.endif

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../math/R-RcppArmadillo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
