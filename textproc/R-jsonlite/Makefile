# $NetBSD: Makefile,v 1.9 2023/08/14 21:39:10 mef Exp $

R_PKGNAME=	jsonlite
R_PKGVER=	1.8.7
CATEGORIES=	textproc

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Robust, high performance JSON parser and generator for R
LICENSE=	mit

# Package suggested but not available: 'R.rsp'
TEST_DEPENDS+=	R-sf-[0-9]*:../../geography/R-sf
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
