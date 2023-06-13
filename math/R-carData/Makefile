# $NetBSD: Makefile,v 1.5 2023/06/13 14:16:36 mef Exp $

R_PKGNAME=	carData
R_PKGVER=	3.0-5

MAINTAINER=	wen@NetBSD.org
COMMENT=	Companion to 'Applied Regression' data sets
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

TEST_DEPENDS+=	R-car-[0-9]*:../../math/R-car

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
