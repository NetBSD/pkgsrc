# $NetBSD: Makefile,v 1.3 2021/09/18 11:43:01 mef Exp $

R_PKGNAME=	sandwich
R_PKGVER=	3.0-1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Robust covariance matrix estimators
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-zoo>=1.8.6:../../math/R-zoo

# Packages suggested but not available:
#   'AER', 'geepack', 'multiwayvcov', 'pcse', 'plm', 'pscl',
#   'scatterplot3d', 'strucchange'
TEST_DEPENDS+=	R-car-[0-9]*:../../math/R-car
TEST_DEPENDS+=	R-lmtest-[0-9]*:../../math/R-lmtest

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
