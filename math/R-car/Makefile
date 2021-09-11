# $NetBSD: Makefile,v 1.10 2021/09/11 12:31:42 mef Exp $

R_PKGNAME=	car
R_PKGVER=	3.0-11

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Companion to 'Applied Regression'
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-rio>=0.5.16:../../devel/R-rio
DEPENDS+=	R-maptools>=0.9.5:../../geography/R-maptools
DEPENDS+=	R-abind>=1.4.5:../../math/R-abind
DEPENDS+=	R-carData>=3.0.0:../../math/R-carData
DEPENDS+=	R-lme4>=1.1.21:../../math/R-lme4
DEPENDS+=	R-pbkrtest>=0.4.4:../../math/R-pbkrtest
DEPENDS+=	R-quantreg>=5.42.1:../../math/R-quantreg

# Packages suggested but not available:
#   'alr4', 'coxme', 'leaps', 'lmtest'
TEST_DEPENDS+=	R-lmtest-[0-9]*:../../math/R-lmtest
TEST_DEPENDS+=	R-effects-[0-9]*:../../graphics/R-effects
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rgl-[0-9]*:../../graphics/R-rgl
TEST_DEPENDS+=	R-sandwich-[0-9]*:../../math/R-sandwich
TEST_DEPENDS+=	R-lme4-[0-9]*:../../math/R-lme4

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
