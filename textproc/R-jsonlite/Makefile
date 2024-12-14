# $NetBSD: Makefile,v 1.10 2024/12/14 09:58:50 mef Exp $

R_PKGNAME=	jsonlite
R_PKGVER=	1.8.9
CATEGORIES=	textproc

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Robust, high performance JSON parser and generator for R
LICENSE=	mit

# Package suggested but not available: 'R.rsp'
TEST_DEPENDS+=	R-httr-[0-9]*:../../www/R-httr
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-sf-[0-9]*:../../geography/R-sf
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
