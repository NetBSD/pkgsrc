# $NetBSD: Makefile,v 1.6 2023/08/11 02:21:22 mef Exp $

R_PKGNAME=	rstudioapi
R_PKGVER=	0.15.0

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Safely access the RStudio API
LICENSE=	mit

TEST_DEPENDS+=	R-clipr-[0-9]*:../../devel/R-clipr
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
