# $NetBSD: Makefile,v 1.4 2024/12/06 23:10:19 mef Exp $

R_PKGNAME=	effects
R_PKGVER=	4.2-2
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Effect displays for linear, generalized linear, and other models
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-colorspace>=1.4.1:../../graphics/R-colorspace
DEPENDS+=	R-carData>=3.0.2:../../math/R-carData
DEPENDS+=	R-estimability>=1.3:../../math/R-estimability
DEPENDS+=	R-insight-[0-9]*:../../math/R-insight
DEPENDS+=	R-lme4>=1.1.21:../../math/R-lme4
DEPENDS+=	R-survey>=3.36:../../math/R-survey

# Packages suggested but not available:
#   'poLCA', 'heplots', 'ordinal', 'betareg', 'alr4', 'robustlmm'

TEST_DEPENDS+=	R-pbkrtest-[0-9]*:../../math/R-pbkrtest
TEST_DEPENDS+=	R-car-[0-9]*:../../math/R-car
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
