# $NetBSD: Makefile,v 1.6 2026/05/20 03:48:06 mef Exp $

R_PKGNAME=	lazyeval
R_PKGVER=	0.2.3
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Lazy (non-standard) evaluation
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-rlang-[0-9]*:../../devel/R-rlang

TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
