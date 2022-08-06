# $NetBSD: Makefile,v 1.6 2022/08/06 17:24:46 he Exp $

R_PKGNAME=	later
R_PKGVER=	1.3.0
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Utilities for delaying function execution
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-rlang>=0.4.0:../../devel/R-rlang

TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../devel/R-BH/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
