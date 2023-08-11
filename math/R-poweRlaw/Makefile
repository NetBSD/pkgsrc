# $NetBSD: Makefile,v 1.5 2023/08/11 07:42:43 mef Exp $

R_PKGNAME=	poweRlaw
R_PKGVER=	0.70.6

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Analysis of heavy tailed distributions
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-VGAM>=1.1.1:../../math/R-VGAM
DEPENDS+=	R-pracma-[0-9]*:../../math/R-pracma

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
