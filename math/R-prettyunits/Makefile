# $NetBSD: Makefile,v 1.4 2021/06/05 06:11:08 mef Exp $

R_PKGNAME=	prettyunits
R_PKGVER=	1.1.1
CATEGORIES=	math

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Pretty, human readable formatting of quantities
LICENSE=	mit

DEPENDS+=	R-assertthat>=0.2.1:../../devel/R-assertthat
DEPENDS+=	R-magrittr>=1.5:../../devel/R-magrittr

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
