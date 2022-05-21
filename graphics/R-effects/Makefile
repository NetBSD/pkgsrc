# $NetBSD: Makefile,v 1.3 2022/05/21 15:33:51 mef Exp $

R_PKGNAME=	effects
R_PKGVER=	4.2-1
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
#   'pbkrtest', 'poLCA', 'heplots', 'ordinal', 'car', 'knitr', 'betareg',
#   'alr4', 'robustlmm'

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
