# $NetBSD: Makefile,v 1.16 2020/09/20 21:58:36 mef Exp $

R_PKGNAME=	DAAG
R_PKGVER=	1.24
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Data analysis and graphics data and functions
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-latticeExtra>=0.6.26:../../graphics/R-latticeExtra

# Packages suggested but not available:
# 'leaps', 'oz'
TEST_DEPENDS+=	R-lme4-[0-9]*:../../math/R-lme4
TEST_DEPENDS+=	R-quantreg-[0-9]*:../../math/R-quantreg
TEST_DEPENDS+=	R-randomForest-[0-9]*:../../math/R-randomForest

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
