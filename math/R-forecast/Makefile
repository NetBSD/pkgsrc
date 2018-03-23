# $NetBSD: Makefile,v 1.1 2018/03/23 16:43:28 minskim Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://pkg.robjhyndman.com/forecast/
COMMENT=	Forecasting functions for time series and linear models
LICENSE=	gnu-gpl-v3

R_PKGNAME=	forecast
R_PKGVER=	8.2

DEPENDS+=	R-colorspace-[0-9]*:../../graphics/R-colorspace
DEPENDS+=	R-fracdiff-[0-9]*:../../math/R-fracdiff
DEPENDS+=	R-ggplot2>=2.0.0:../../graphics/R-ggplot2
DEPENDS+=	R-lmtest-[0-9]*:../../math/R-lmtest
DEPENDS+=	R-magrittr-[0-9]*:../../devel/R-magrittr
DEPENDS+=	R-timeDate-[0-9]*:../../time/R-timeDate
DEPENDS+=	R-tseries-[0-9]*:../../finance/R-tseries
DEPENDS+=	R-zoo-[0-9]*:../../math/R-zoo

USE_LANGUAGES=	c c++ fortran

.include "../../devel/R-Rcpp/buildlink3.mk"
BUILDLINK_ABI_DEPENDS.R+=	R>=3.0.2
.include "../../math/R/Makefile.extension"
.include "../../math/R-RcppArmadillo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
